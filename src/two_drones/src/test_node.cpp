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
#include "two_drones/hover_node.h"
#include <geometry_msgs/Vector3.h>
#include <tf/transform_datatypes.h>

Drone_Mission drone1("drone1");

geometry_msgs::Vector3 alt_output1;
ros::Publisher altitude1;

geometry_msgs::Vector3 waypoint;


int main(int argc, char **argv)
{
  waypoint.x = -102894.25;
  waypoint.y = -4562699.25;
  waypoint.z = 0.0;

// %Tag(INIT)%
  ros::init(argc, argv, "hover_node");
// %EndTag(INIT)%

// %Tag(NODEHANDLE)%
  ros::NodeHandle n;
// %EndTag(NODEHANDLE)%

drone1.fix = n.subscribe("drone1/fix", 10, &drone1_gps_callback);

drone1.magnetic = n.subscribe("drone1/magnetic", 10, &Drone_Mission::magnetic_callback, &drone1);

drone1.imu = n.subscribe("drone1/raw_imu", 10, &Drone_Mission::imuCallback, &drone1);

drone1.odom = n.subscribe("drone1/geonav_odom", 10, &Drone_Mission::odomCallback, &drone1);

drone1.motor_on = n.serviceClient<hector_uav_msgs::EnableMotors>("drone1/enable_motors");

// %Tag(PUBLISHER)%
drone1.move_drone = n.advertise<geometry_msgs::Twist>("drone1/cmd_vel", 1);

altitude1 = n.advertise<geometry_msgs::Vector3>("drone1/altitude", 1);

drone1.tester = n.advertise<geometry_msgs::Vector3>("drone1/yaw_vector", 1);

drone1.enableMotors(true);

// %Tag(LOOP_RATE)%
  ros::Rate loop_rate(10);
// %EndTag(LOOP_RATE)%


// %Tag(ROS_OK)%
  static int count = 0;
  while (ros::ok())
  {

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


void doneCb(const actionlib::SimpleClientGoalState& state,
            const hector_uav_msgs::PoseResultConstPtr& result)
{
  ROS_INFO("Finished in state [%s]", state.toString().c_str());
//   ROS_INFO("Answer: %s", result->status);
}

// Called once when the goal becomes active
void activeCb()
{
  ROS_INFO("Goal just went active");
}

// Called every time feedback is received for the goal
void feedbackCb(const hector_uav_msgs::PoseFeedbackConstPtr& feedback)
{
  ROS_INFO("Got Feedback of action %f %f %f", feedback->current_pose.pose.position.x, feedback->current_pose.pose.position.y, feedback->current_pose.pose.position.z);
}

void drone1_maintain_altitude(float height1, Pose &pose1_) {
  ROS_INFO("Waiting for action server to start.");
  // wait for the action server to start
  pose1_.waitForServer();
  ROS_INFO("Action server started, sending goal.");
  drone1.pose_goal.target_pose = drone1.pose_feedback.feedback.current_pose;
  drone1.pose_goal.target_pose.pose.position.x = -5;
  drone1.pose_goal.target_pose.pose.position.y = -20;
  drone1.pose_goal.target_pose.pose.position.z = height1;
  ROS_INFO("Goal prepared");
  drone1.pose_goal.target_pose.header.frame_id = "drone1/world";
  pose1_.sendGoal(drone1.pose_goal, &doneCb, &activeCb, &feedbackCb);
  ROS_INFO("Goal Sent");
  // pose1_.waitForResult(ros::Duration(30.0));

  if (pose1_.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
      actionlib::SimpleClientGoalState state = pose1_.getState();
      ROS_INFO("Action finished: %s",state.toString().c_str());
  }
  else
      ROS_INFO("Action did not finish before the time out."); 
}

void drone1_go_to_position(float x, float y, float z, Pose &pose1_) {
  ROS_INFO("Waiting for action server to start.");
  // wait for the action server to start
  pose1_.waitForServer();
  ROS_INFO("Action server started, sending goal.");
  drone1.pose_goal.target_pose = drone1.pose_feedback.feedback.current_pose;
  drone1.pose_goal.target_pose.pose.position.x = x;
  drone1.pose_goal.target_pose.pose.position.y = y;
  drone1.pose_goal.target_pose.pose.position.z = z;
  ROS_INFO("Goal prepared");
  drone1.pose_goal.target_pose.header.frame_id = "drone1/world";
  pose1_.sendGoal(drone1.pose_goal, &doneCb, &activeCb, &feedbackCb);
  ROS_INFO("Goal Sent");
  // pose1_.waitForResult(ros::Duration(30.0));

  if (pose1_.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
      actionlib::SimpleClientGoalState state = pose1_.getState();
      ROS_INFO("Action finished: %s",state.toString().c_str());
  }
  else
      ROS_INFO("Action did not finish before the time out."); 
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

void Drone_Mission::imuCallback(const sensor_msgs::ImuConstPtr& msg) {
  sensor_msgs::Imu imu = *msg;
  tf::Quaternion q(imu.orientation.x, imu.orientation.y, imu.orientation.z, imu.orientation.w);
  tf::Matrix3x3 m(q);
  m.getRPY(roll, pitch, yaw);
  // ROS_INFO("%s: Roll: %f, Pitch: %f, Yaw: %f", name.c_str(), roll, pitch, yaw);
  test.x = yaw;
  tester.publish(test);
}


void drone1_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg) {
  drone1.current_gps = *msg;
  geodesy::convert(drone1.current_gps, drone1.gp);
  geodesy::fromMsg(drone1.gp, drone1.current_utm);
  // utm_drone1.publish(current_drone1_utm);
  static int count_1 = 0;
  static double start_alt_1 = 0;
  static double start_magx = 0;
  if(ros::Time::now().toSec() < 20) {
    count_1 += 1;
    start_alt_1 += drone1.current_gps.altitude;
    start_magx += drone1.current_magnetic.vector.x;
    drone1.mean_start_gps = start_alt_1/count_1;
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
        drone1.state = 5;
        drone1.direction = 0.3;
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
    case 3:
      if(drone1.finished == false) {
        step(drone1);
      } else {
        drone1.state = 7;
        drone1.direction = -0.2;
        drone1.finished = false;
        ROS_INFO("Done Rotating");
      }
      break;
    case 5:
      if(drone1.finished == false) {
        step(drone1);
      } else {
        drone1.state = 3;
        drone1.target.x = waypoint.x;
        drone1.target.y = waypoint.y;
        drone1.finished = false;
        ROS_INFO("Done Reaching");
      }
      break;
    case 6:
      if(drone1.finished == false) {
        step(drone1);
      } else {
        drone1.state = 4;
        drone1.finished =false;
        ROS_INFO("Done Hovering");
      }
      break;
    case 7:
      if(drone1.finished == false) {
        drone1.sign = 1;
        step(drone1);
      } else {
        drone1.state = 6;
        drone1.finished = false;
        ROS_INFO("Done Turning to yaw");
      }
      break;
    case 8:
      if(drone1.finished == false) {
        drone1.sign = 1;
        step(drone1);
      } else {
        drone1.state = 7;
        drone1.finished = false;
        ROS_INFO("Done reaching with gps");
      }
      break;
    default:
      ROS_INFO("Invalid State");
      break;
  }
}