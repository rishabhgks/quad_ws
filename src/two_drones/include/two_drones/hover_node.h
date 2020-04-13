
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
#include <std_msgs/UInt8.h>
#include <nav_msgs/OccupancyGrid.h>
#include <actionlib/client/simple_action_client.h>
#include <hector_uav_msgs/PoseAction.h>
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
    bool finished;
    float mean_start_gps;
    float Y_POS;
    float mean_start_mag_x;
    float direction;

    Drone_Mission(std::string n) : name(n), state(0), finished(false), mean_start_gps(0.0), Y_POS(1.0)
    {
    }
    hector_uav_msgs::PoseActionFeedback pose_feedback;
    hector_uav_msgs::PoseGoal pose_goal;

    ros::Subscriber fix;

    ros::Subscriber magnetic;

    geometry_msgs::Twist motor_msg;

    sensor_msgs::NavSatFix current_gps;

    nav_msgs::OccupancyGrid map_data;

    geometry_msgs::Vector3Stamped current_magnetic;

    geodesy::UTMPoint current_utm;

    geographic_msgs::GeoPoint gp;

    ros::Publisher move_drone;

    ros::Publisher map;

    ros::ServiceClient motor_on;

    // void gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg);

    bool enableMotors(bool enable);
};

void step(Drone_Mission &drone);

void drone1_maintain_altitude(float height1, Pose &pose1_);

void drone2_maintain_altitude(float height2, Pose &pose2_);

void drone1_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg);

void drone2_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg);

void drone1_magnetic_callback(const geometry_msgs::Vector3Stamped::ConstPtr& msg);

void drone2_magnetic_callback(const geometry_msgs::Vector3Stamped::ConstPtr& msg);

void drone1_map_callback(const nav_msgs::OccupancyGrid::ConstPtr& msg);

void drone2_map_callback(const nav_msgs::OccupancyGrid::ConstPtr& msg);

bool drone1_enableMotors(bool enable);

bool drone2_enableMotors(bool enable);

void doneCb(const actionlib::SimpleClientGoalState& state, const hector_uav_msgs::PoseResultConstPtr& result);

void activeCb();

void feedbackCb(const hector_uav_msgs::PoseFeedbackConstPtr& feedback);


#endif // HOVER_NODE_H