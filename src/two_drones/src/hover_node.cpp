#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Twist.h>
#include <sstream>
#include <geodesy/utm.h>
#include <hector_uav_msgs/EnableMotors.h>
#include <geographic_msgs/GeoPoint.h>
#include <geographic_msgs/GeoPose.h>
#include "two_drones/hover_node.h"

Drone_Mission drone1;
Drone_Mission drone2;

int main(int argc, char **argv)
{

// %Tag(INIT)%
  ros::init(argc, argv, "hover_node");
// %EndTag(INIT)%

// %Tag(NODEHANDLE)%
  ros::NodeHandle n;
// %EndTag(NODEHANDLE)%

drone1.fix = n.subscribe("drone1/fix", 10, &drone1_gps_callback);
drone2.fix = n.subscribe("drone2/fix", 10, &drone2_gps_callback);

drone1.motor_on = n.serviceClient<hector_uav_msgs::EnableMotors>("drone1/enable_motors");
drone2.motor_on = n.serviceClient<hector_uav_msgs::EnableMotors>("drone2/enable_motors");


// %Tag(PUBLISHER)%
  // ros::Publisher chatter_pub = n.advertise<sensor_msgs::Joy>("drone2/joy", 1);
drone1.move_drone = n.advertise<geometry_msgs::Twist>("drone1/cmd_vel", 1);
drone2.move_drone = n.advertise<geometry_msgs::Twist>("drone2/cmd_vel", 1);

drone1.enableMotors(true);
drone2.enableMotors(true);

// %EndTag(PUBLISHER)%

// %Tag(LOOP_RATE)%
  ros::Rate loop_rate(10);
// %EndTag(LOOP_RATE)%


// %Tag(ROS_OK)%
  int count = 0;
  while (ros::ok())
  {
// %Tag(FILL_MESSAGE)%
 
    drone1.motor_msg.linear.z = 0.3;
    drone2.motor_msg.linear.z = 0.3;

    if(ros::Time::now().toSec() > 30 && ros::Time::now().toSec() < 60) {
      drone1.state = 1;
      drone2.state = 1;
    }    


// %EndTag(FILL_MESSAGE)%

// %Tag(ROSCONSOLE)%
    // ROS_INFO("%f %f %f %f", drone1.current_utm.easting, drone2.current_utm.easting, drone1.current_utm.northing, drone2.current_utm.northing);
    // ROS_INFO("%s", msg.data.c_str());
    // ROS_INFO("%f %f", (current_drone1_gps.latitude - current_drone2_gps.latitude), (current_drone1_gps.longitude - current_drone2_gps.longitude));

// %EndTag(ROSCONSOLE)%

// %Tag(SPINONCE)%
    ros::spinOnce();
// %EndTag(SPINONCE)%

// %Tag(RATE_SLEEP)%
    loop_rate.sleep();
// %EndTag(RATE_SLEEP)%
    ++count;
  }


  return 0;
}
// %EndTag(FULLTEXT)%

void step(Drone_Mission &drone) {
  if(drone.state == 1 && drone.finished != true) {
    if(drone.current_gps.altitude - drone.mean_start_gps <= 3.95) {
      drone.move_drone.publish(drone.motor_msg);
    } else if(drone.current_gps.altitude - drone.mean_start_gps > 4.05){
      drone.motor_msg.linear.z = -0.2;
      drone.move_drone.publish(drone.motor_msg);  
    }
    if(ros::Time::now().toSec() > 60) {
      drone.finished = true;
    }
  }
  if(drone.state == 2 && drone.finished != true) {
    if(drone.current_gps.altitude - drone.mean_start_gps > 0.05){
      drone.motor_msg.linear.z = -0.2;
      drone.move_drone.publish(drone.motor_msg);  
    } else {
      drone.finished = true;
    }
    if(ros::Time::now().toSec() > 90) {
      drone.finished = true;
    }
  }
}

bool Drone_Mission::enableMotors(bool enable)
{
  if (!Drone_Mission::motor_on.waitForExistence(ros::Duration(5.0)))
  {
    ROS_WARN("Motor enable service not found");
    return false;
  }

  hector_uav_msgs::EnableMotors srv;
  srv.request.enable = enable;
  return Drone_Mission::motor_on.call(srv);
}

void drone1_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg) {
  drone1.current_gps = *msg;
  geodesy::convert(drone1.current_gps, drone1.gp);
  geodesy::fromMsg(drone1.gp, drone1.current_utm);
  // utm_drone1.publish(current_drone1_utm);
  static int count_1 = 0;
  static double start_alt_1 = 0;
  if(ros::Time::now().toSec() < 15) {
    count_1 += 1;
    start_alt_1 += drone1.current_gps.altitude; 
    drone1.mean_start_gps = start_alt_1/count_1;
    ROS_INFO("Mean drone1 altitude %f %f %d", drone1.mean_start_gps, start_alt_1, count_1);
  }
  switch(drone1.state) {
    case 0: 
      break;
    case 1:
      if(drone1.finished == false) {
        step(drone1);
      } else {
        drone1.state = 2;
        drone1.finished = false;
        ROS_INFO("Done Hovering");
      }
      break;
    case 2:
      if(drone1.finished == false) {
        step(drone1);
      } else {
        drone1.state = 0;
        drone1.finished = false;
        ROS_INFO("Done Landing");
      }
      break;
    default:
      ROS_INFO("Invalid State");
      break;
  }
}

void drone2_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg) {
  drone2.current_gps = *msg;
  geodesy::convert(drone2.current_gps, drone2.gp);
  geodesy::fromMsg(drone2.gp, drone2.current_utm);
  // utm_drone2.publish(current_drone2_utm);
  static int count_2 = 0;
  static double start_alt_2 = 0;
  // ROS_INFO("%d", count);
  if(ros::Time::now().toSec() < 15) {
    count_2 += 1;
    start_alt_2 += drone2.current_gps.altitude; 
    drone2.mean_start_gps = start_alt_2/count_2;
    ROS_INFO("Mean drone2 altitude %f %f %d", drone2.mean_start_gps, start_alt_2, count_2);
  }
  switch(drone2.state) {
    case 0: 
      break;
    case 1:
      if(drone2.finished == false) {
        step(drone2);
      } else {
        drone2.state = 2;
        drone2.finished = false;
        ROS_INFO("Done Hovering");
      }
      break;
    case 2:
      if(drone2.finished == false) {
        step(drone2);
      } else {
        drone2.state = 0;
        drone2.finished = false;
        ROS_INFO("Done Landing");
      }
      break;
    default:
      ROS_INFO("Invalid State");
      break;
  }
}
