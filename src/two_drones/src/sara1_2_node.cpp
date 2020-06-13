#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Twist.h>
#include <sstream>
#include <geodesy/utm.h>
#include <hector_uav_msgs/EnableMotors.h>
#include <geographic_msgs/GeoPoint.h>
#include <geographic_msgs/GeoPose.h>
#include <cmath>
#include "two_drones/sara1_node.h"
#include <geometry_msgs/Vector3.h>
#include <tf/transform_datatypes.h>

Drone_Mission drone1("drone1");
Drone_Mission drone2("drone2");

geometry_msgs::Vector3 alt_output1;
geometry_msgs::Vector3 alt_output2;
ros::Publisher altitude1;
ros::Publisher altitude2;

geometry_msgs::Vector3 waypoint;

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

drone1.magnetic = n.subscribe("drone1/magnetic", 10, &Drone_Mission::magnetic_callback, &drone1);
drone2.magnetic = n.subscribe("drone2/magnetic", 10, &Drone_Mission::magnetic_callback, &drone2);

drone1.motor_on = n.serviceClient<hector_uav_msgs::EnableMotors>("drone1/enable_motors");
drone2.motor_on = n.serviceClient<hector_uav_msgs::EnableMotors>("drone2/enable_motors");

// %Tag(PUBLISHER)%
drone1.move_drone = n.advertise<geometry_msgs::Twist>("drone1/cmd_vel", 1);
drone2.move_drone = n.advertise<geometry_msgs::Twist>("drone2/cmd_vel", 1);

altitude1 = n.advertise<geometry_msgs::Vector3>("drone1/altitude", 1);
altitude2 = n.advertise<geometry_msgs::Vector3>("drone2/altitude", 1);

drone1.enableMotors(true);
drone2.enableMotors(true);

// %Tag(LOOP_RATE)%
  ros::Rate loop_rate(10);
// %EndTag(LOOP_RATE)%


// %Tag(ROS_OK)%
  static int count = 0;
  while (ros::ok())
  {
    drone1.motor_msg.linear.z = 0.3;
    drone2.motor_msg.linear.z = 0.3;

    if(ros::Time::now().toSec() > 20 && ros::Time::now().toSec() < 50 && count < 2) {
      drone1.state = 1;
      drone2.state = 1;
      ++count;
    }  

// %Tag(SPINONCE)%
    ros::spinOnce();
// %EndTag(SPINONCE)%

// %Tag(RATE_SLEEP)%
    loop_rate.sleep();
// %EndTag(RATE_SLEEP)%
  }


  return 0;
}
// %EndTag(FULLTEXT)%

void step(Drone_Mission &drone) {
  // ros::Rate r(0.2);
    // r.sleep();
  if(drone.state == 1 && drone.finished != true) {
    if(drone.current_gps.altitude - drone.mean_start_gps < 3.95) {
      drone.motor_msg.linear.z = 0.3;
      drone.motor_msg.angular.z = 0.0;
      drone.move_drone.publish(drone.motor_msg);
    } else if(drone.current_gps.altitude - drone.mean_start_gps > 4.05){
      drone.motor_msg.linear.z = -0.2;
      drone.motor_msg.angular.z = 0.0;
      drone.move_drone.publish(drone.motor_msg);  
    }
    if(drone.current_utm.easting - drone.mean_start_eas < drone.target.x)
      drone.motor_msg.linear.x = 0.1;
    else
      drone.motor_msg.linear.x = -0.1;
    if(drone.current_utm.northing - drone.mean_start_nor < drone.target.y)
      drone.motor_msg.linear.y = 0.1;
    else
      drone.motor_msg.linear.y = -0.1;  
    if(ros::Time::now().toSec() > 50) {
      drone.finished = true;
    }
    ROS_INFO("Orig: %f  Modified: %f", drone.current_gps.altitude, drone.current_gps.altitude - drone.mean_start_gps);
  }
  if(drone.state == 2 && drone.finished != true) {
    if(drone.current_gps.altitude - drone.mean_start_gps > 0.05){
      drone.motor_msg.linear.x = 0.0;
      drone.motor_msg.linear.z = -0.15;
      drone.motor_msg.angular.z = 0.0;
      drone.move_drone.publish(drone.motor_msg);  
    } else {
      drone.finished = true;
    }
    // if(ros::Time::now().toSec() > 90) {
    //   drone.finished = true;
    // }
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

void Drone_Mission::magnetic_callback(const geometry_msgs::Vector3Stamped::ConstPtr& msg) {
  current_magnetic = *msg;
}

void drone1_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg) {
  drone1.current_gps = *msg;
  geodesy::convert(drone1.current_gps, drone1.gp);
  geodesy::fromMsg(drone1.gp, drone1.current_utm);
  // utm_drone1.publish(current_drone1_utm);
  static int count_1 = 0;
  static double start_alt_1 = 0;
  static double start_eas_1 = 0;
  static double start_nor_1 = 0;
  static double start_magx = 0;
  if(ros::Time::now().toSec() < 20) {
    count_1 += 1;
    start_alt_1 += drone1.current_gps.altitude;
    start_eas_1 += drone1.current_utm.easting;
    start_nor_1 += drone1.current_utm.northing;
    start_magx += drone1.current_magnetic.vector.x;
    drone1.mean_start_gps = start_alt_1/count_1;
    drone1.mean_start_eas = start_eas_1/count_1;
    drone1.mean_start_nor = start_nor_1/count_1;
    drone1.mean_start_mag_x = start_magx/count_1;
    ROS_INFO("Mean drone1 altitude %f %f %d", drone1.mean_start_gps, start_alt_1, count_1);
  }
  alt_output1.x = drone1.current_gps.altitude;
  alt_output1.y = drone1.current_gps.altitude - drone1.mean_start_gps;
  altitude1.publish(alt_output1);
  switch(drone1.state) {
    case 0: 
      break;
    case 1:
      if(drone1.finished == false) {
        step(drone1);
      } else {
        drone1.state = 2;
        drone1.direction = 0.3;
        drone1.target.x = 477508.78366;
        drone1.target.y = 5523135.35727;
        drone1.target.z = 4;
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
  static double start_eas_2 = 0;
  static double start_nor_2 = 0;
  static double start_magx = 0;
  if(ros::Time::now().toSec() < 20) {
    count_2 += 1;
    start_alt_2 += drone2.current_gps.altitude;
    start_eas_2 += drone2.current_utm.easting;
    start_nor_2 += drone2.current_utm.northing;
    start_magx += drone2.current_magnetic.vector.x;
    drone2.mean_start_gps = start_alt_2/count_2;
    drone2.mean_start_eas = start_eas_2/count_2;
    drone2.mean_start_nor = start_nor_2/count_2;
    drone2.mean_start_mag_x = start_magx/count_2;
    ROS_INFO("Mean drone2 altitude %f %f %d", drone2.mean_start_gps, start_alt_2, count_2);
  }
  alt_output2.x = drone2.current_gps.altitude;
  alt_output2.y = drone2.current_gps.altitude - drone2.mean_start_gps;
  switch(drone2.state) {
    case 0: 
      break;
    case 1:
      if(drone2.finished == false) {
        step(drone2);
      } else {
        drone2.state = 2;
        drone2.direction = -0.3;
        drone2.target.x = 477508.816984;
        drone2.target.y = 5523143.35422;
        drone2.target.z = 4;
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