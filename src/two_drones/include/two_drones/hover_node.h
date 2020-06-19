
#ifndef HOVER_NODE_H
#define HOVER_NODE_H

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
#include <actionlib/client/simple_action_client.h>
#include <hector_uav_msgs/PoseAction.h>
#include <geometry_msgs/Vector3.h>
// #include <hector_uav_msgs/EnableMotors.h>


#include <tf/tf.h>
#include <sensor_msgs/Joy.h>

#define C_EARTH (double)6378137.0
#define C_PI (double)3.141592653589793
#define DEG2RAD(DEG) ((DEG) * ((C_PI) / (180.0)))

typedef actionlib::SimpleActionClient<hector_uav_msgs::PoseAction> Pose;

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
    float direction;
    geometry_msgs::Vector3 target;
    nav_msgs::Odometry subOdom;
    geometry_msgs::Vector3 test;

    Drone_Mission(std::string n) : name(n), state(0), substate(0), finished(false), mean_start_gps(0.0), Y_POS(1.0)
    {
        target.x = 0.0;
        target.y = 0.0;
        target.z = 0.0;
    }
    hector_uav_msgs::PoseActionFeedback pose_feedback;

    hector_uav_msgs::PoseGoal pose_goal;

    ros::Subscriber fix;

    ros::Subscriber magnetic;

    ros::Subscriber imu;

    ros::Subscriber odom;

    geometry_msgs::Twist motor_msg;

    sensor_msgs::NavSatFix current_gps;

    geometry_msgs::Vector3Stamped current_magnetic;

    geodesy::UTMPoint current_utm;

    geographic_msgs::GeoPoint gp;

    ros::Publisher move_drone;

    ros::Publisher map;

    ros::Publisher tester;

    ros::ServiceClient motor_on;

    double roll, pitch, yaw, dist_x, dist_y, theta;

    // void gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg);

    bool enableMotors(bool enable);

    void magnetic_callback(const geometry_msgs::Vector3Stamped::ConstPtr& msg);

    void imuCallback(const sensor_msgs::ImuConstPtr& msg);

    void odomCallback(const nav_msgs::OdometryConstPtr& msg);
};

// void drone1_imuCallback(const sensor_msgs::ImuConstPtr& msg);

// void drone2_imuCallback(const sensor_msgs::ImuConstPtr& msg);

void step(Drone_Mission &drone);

void drone1_go_to_position(float x, float y, float z, Pose &pose1_);

void drone2_go_to_position(float x, float y, float z, Pose &pose2_);

void drone1_maintain_altitude(float height1, Pose &pose1_);

void drone2_maintain_altitude(float height2, Pose &pose2_);

void drone3_maintain_altitude(float height3, Pose &pose3_);

void drone1_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg);

void drone2_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg);

void drone3_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg);

void doneCb(const actionlib::SimpleClientGoalState& state, const hector_uav_msgs::PoseResultConstPtr& result);

void activeCb();

void feedbackCb(const hector_uav_msgs::PoseFeedbackConstPtr& feedback);


#endif // HOVER_NODE_H