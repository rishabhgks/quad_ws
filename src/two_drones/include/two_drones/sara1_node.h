
#ifndef SARA1_NODE_H
#define SARA1_NODE_H

// ROS includes
#include <ros/ros.h>
#include <geometry_msgs/QuaternionStamped.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/Imu.h>
#include <std_msgs/UInt8.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Vector3.h>


#include <tf/tf.h>
#include <sensor_msgs/Joy.h>

#define C_EARTH (double)6378137.0
#define C_PI (double)3.141592653589793
#define DEG2RAD(DEG) ((DEG) * ((C_PI) / (180.0)))

class Drone_Mission{
// private:
//     Pose pose_;
public:
    std::string name;
    int state;
    int substate;
    int sign;
    bool rotateToHeading;
    bool finished;
    float mean_start_gps;
    float Y_POS;
    float X_POS;
    float theta_yaw_diff;
    float mean_start_mag_x;
    float mean_start_eas;
    float mean_start_nor;
    float direction;
    geometry_msgs::Vector3 target;
    geometry_msgs::Vector3 test;

    Drone_Mission(std::string n) : name(n), state(0), substate(0), finished(false), mean_start_gps(0.0), Y_POS(1.0)
    {
        target.x = 0.0;
        target.y = 0.0;
        target.z = 0.0;
    }

    ros::Subscriber fix;

    ros::Subscriber magnetic;

    geometry_msgs::Twist motor_msg;

    sensor_msgs::NavSatFix current_gps;

    geometry_msgs::Vector3Stamped current_magnetic;

    geodesy::UTMPoint current_utm;

    geographic_msgs::GeoPoint gp;

    ros::Publisher move_drone;

    ros::ServiceClient motor_on;

    double roll, pitch, yaw, dist_x, dist_y, theta;

    // void gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg);

    bool enableMotors(bool enable);

    void magnetic_callback(const geometry_msgs::Vector3Stamped::ConstPtr& msg);
};

void step(Drone_Mission &drone);

void drone1_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg);

void drone2_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg);

#endif // SARA1_NODE_H