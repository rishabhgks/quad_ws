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

// int drone1_state = 0;
// int drone2_state = 0;

// sensor_msgs::NavSatFix current_drone1_gps;
// sensor_msgs::NavSatFix current_drone2_gps;

// geodesy::UTMPoint current_drone1_utm;
// geodesy::UTMPoint current_drone2_utm;

// geographic_msgs::GeoPoint d1_gp;
// geographic_msgs::GeoPoint d2_gp;

// ros::Publisher move_drone1;
// ros::Publisher move_drone2;

// ros::ServiceClient motor_on_1;
// ros::ServiceClient motor_on_2;

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
// %EndTag(ROS_OK)%
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
// %Tag(FILL_MESSAGE)%
    std_msgs::String msg;
    sensor_msgs::Joy msg2;
    geometry_msgs::Twist msg3;
    geometry_msgs::Twist msg4;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    // msg2.axes.push_back(0);
    // msg2.axes.push_back(0.5);
    // msg2.axes.push_back(0);
    // msg2.axes.push_back(0);
    // chatter_pub.publish(msg2);

    msg3.linear.x = 0.0;
    msg3.linear.y = 0.0;
    msg3.linear.z = 0.5;
    msg3.angular.z = 0.0;
    msg3.angular.z = 0.0;
    msg3.angular.z = 0.0;
    
    msg4.linear.x = 0.0;
    msg4.linear.y = 0.0;
    msg4.linear.z = 0.5;
    msg4.angular.z = 0.0;
    msg4.angular.z = 0.0;
    msg4.angular.z = 0.0;

    if(ros::Time::now().toSec() < 30) {
      if(drone1.current_gps.altitude <= 4.95) {
        drone1.move_drone.publish(msg3);
      } else if(drone1.current_gps.altitude > 5.05){
        msg3.linear.z = -0.2;
        drone1.move_drone.publish(msg3);  
      }

      if(drone2.current_gps.altitude <= 4.95) {
        drone2.move_drone.publish(msg4);
      } else if(drone2.current_gps.altitude > 5.05){
        msg4.linear.z = -0.2;
        drone2.move_drone.publish(msg4);  
      } 
    } else {
      if(drone1.current_gps.altitude > 0.05){
        msg3.linear.z = -0.1;
        drone1.move_drone.publish(msg3);  
      }
      if(drone2.current_gps.altitude > 0.05){
        msg4.linear.z = -0.1;
        drone2.move_drone.publish(msg4);  
      }
    }


// %EndTag(FILL_MESSAGE)%

// %Tag(ROSCONSOLE)%
    ROS_INFO("%f %f %f %f", drone1.current_utm.easting, drone2.current_utm.easting, drone1.current_utm.northing, drone2.current_utm.northing);
    // ROS_INFO("%s", msg.data.c_str());
    // ROS_INFO("%f %f", (current_drone1_gps.latitude - current_drone2_gps.latitude), (current_drone1_gps.longitude - current_drone2_gps.longitude));

// %EndTag(ROSCONSOLE)%


// %Tag(PUBLISH)%
    // chatter_pub.publish(msg);

// %EndTag(PUBLISH)%

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
// void Drone_Mission::gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg) {
//   Drone_Mission::current_gps = *msg;
//   geodesy::convert(Drone_Mission::current_gps, Drone_Mission::gp);
//   geodesy::fromMsg(Drone_Mission::gp, Drone_Mission::current_utm);
//   // utm_drone1.publish(current_drone1_utm);
// }

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
}

void drone2_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg) {
  drone2.current_gps = *msg;
  geodesy::convert(drone2.current_gps, drone2.gp);
  geodesy::fromMsg(drone2.gp, drone2.current_utm);
  // utm_drone2.publish(current_drone2_utm);
}

// bool drone1_enableMotors(bool enable)
// {
//   if (!motor_on_1.waitForExistence(ros::Duration(5.0)))
//   {
//     ROS_WARN("Motor enable service not found");
//     return false;
//   }

//   hector_uav_msgs::EnableMotors srv;
//   srv.request.enable = enable;
//   return motor_on_1.call(srv);
// }

// bool drone2_enableMotors(bool enable)
// {
//   if (!motor_on_2.waitForExistence(ros::Duration(5.0)))
//   {
//     ROS_WARN("Motor enable service not found");
//     return false;
//   }

//   hector_uav_msgs::EnableMotors srv;
//   srv.request.enable = enable;
//   return motor_on_2.call(srv);
// }
