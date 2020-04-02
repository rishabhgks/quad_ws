
#ifndef HOVER_NODE_H
#define HOVER_NODE_H

// ROS includes
#include <ros/ros.h>
#include <geometry_msgs/QuaternionStamped.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/UInt8.h>
#include <geodesy/utm.h>
#include <geographic_msgs/GeoPoint.h>
#include <hector_uav_msgs/EnableMotors.h>


#include <tf/tf.h>
#include <sensor_msgs/Joy.h>

#define C_EARTH (double)6378137.0
#define C_PI (double)3.141592653589793
#define DEG2RAD(DEG) ((DEG) * ((C_PI) / (180.0)))

class Drone_Mission{
public:
    int state;
    bool finished;
    double mean_start_gps;

    Drone_Mission():state(0), finished(false), mean_start_gps(0.0) {}

    ros::Subscriber fix;

    sensor_msgs::NavSatFix current_gps;

    geometry_msgs::Twist motor_msg;

    geodesy::UTMPoint current_utm;

    geographic_msgs::GeoPoint gp;

    ros::Publisher move_drone;

    ros::ServiceClient motor_on;

    // void gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg);

    bool enableMotors(bool enable);
};

void step(Drone_Mission);

void drone1_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg);

void drone2_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg);

#endif // HOVER_NODE_H