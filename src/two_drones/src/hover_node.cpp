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


int drone1_state = 0;
int drone2_state = 0;

sensor_msgs::NavSatFix current_drone1_gps;
sensor_msgs::NavSatFix current_drone2_gps;

geodesy::UTMPoint current_drone1_utm;
geodesy::UTMPoint current_drone2_utm;

geographic_msgs::GeoPoint d1_gp;
geographic_msgs::GeoPoint d2_gp;

ros::Publisher move_drone1;
ros::Publisher move_drone2;

ros::ServiceClient motor_on_1;
ros::ServiceClient motor_on_2;

int main(int argc, char **argv)
{

// %Tag(INIT)%
  ros::init(argc, argv, "hover_node");
// %EndTag(INIT)%

// %Tag(NODEHANDLE)%
  ros::NodeHandle n;
// %EndTag(NODEHANDLE)%

ros::Subscriber drone1_fix = n.subscribe("drone1/fix", 10, &drone1_gps_callback);
ros::Subscriber drone2_fix = n.subscribe("drone2/fix", 10, &drone2_gps_callback);


motor_on_1 = n.serviceClient<hector_uav_msgs::EnableMotors>("drone1/enable_motors");
motor_on_2 = n.serviceClient<hector_uav_msgs::EnableMotors>("drone2/enable_motors");


// %Tag(PUBLISHER)%
  // ros::Publisher chatter_pub = n.advertise<sensor_msgs::Joy>("drone2/joy", 1);
move_drone1 = n.advertise<geometry_msgs::Twist>("drone1/cmd_vel", 1);
move_drone2 = n.advertise<geometry_msgs::Twist>("drone2/cmd_vel", 1);

drone1_enableMotors(true);
drone2_enableMotors(true);

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
      if(current_drone1_gps.altitude <= 4.95) {
        move_drone1.publish(msg3);
      } else if(current_drone1_gps.altitude > 5.05){
        msg3.linear.z = -0.2;
        move_drone1.publish(msg3);  
      } else {
        msg3.linear.z = 0;
        move_drone1.publish(msg3);      
      }

      if(current_drone2_gps.altitude <= 4.95) {
        move_drone2.publish(msg4);
      } else if(current_drone2_gps.altitude > 5.05){
        msg4.linear.z = -0.2;
        move_drone2.publish(msg4);  
      } else {
        msg4.linear.z= 0;
        move_drone2.publish(msg4);
      }
    } else {
      if(current_drone1_gps.altitude > 0.05){
        msg3.linear.z = -0.2;
        move_drone1.publish(msg3);  
      }
      if(current_drone2_gps.altitude > 0.05){
        msg4.linear.z = -0.1;
        move_drone2.publish(msg4);  
      }
    }


// %EndTag(FILL_MESSAGE)%

// %Tag(ROSCONSOLE)%
    ROS_INFO("%f %f %f %f", current_drone1_utm.easting, current_drone2_utm.easting, current_drone1_utm.northing, current_drone2_utm.northing);
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

void drone1_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg) {
  current_drone1_gps = *msg;
  geodesy::convert(current_drone1_gps, d1_gp);
  geodesy::fromMsg(d1_gp, current_drone1_utm);
  // utm_drone1.publish(current_drone1_utm);
}

void drone2_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg) {
  current_drone2_gps = *msg;
  geodesy::convert(current_drone2_gps, d2_gp);
  geodesy::fromMsg(d2_gp, current_drone2_utm);
  // utm_drone2.publish(current_drone2_utm);
}

bool drone1_enableMotors(bool enable)
{
  if (!motor_on_1.waitForExistence(ros::Duration(5.0)))
  {
    ROS_WARN("Motor enable service not found");
    return false;
  }

  hector_uav_msgs::EnableMotors srv;
  srv.request.enable = enable;
  return motor_on_1.call(srv);
}

bool drone2_enableMotors(bool enable)
{
  if (!motor_on_2.waitForExistence(ros::Duration(5.0)))
  {
    ROS_WARN("Motor enable service not found");
    return false;
  }

  hector_uav_msgs::EnableMotors srv;
  srv.request.enable = enable;
  return motor_on_2.call(srv);
}
