#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/Twist.h>
#include <geodesy/utm.h>
#include <hector_uav_msgs/EnableMotors.h>
#include <actionlib/client/simple_action_client.h>
#include <cmath>
#include "two_drones/hover_node.h"
#include <hector_uav_msgs/PoseAction.h>

std::string POSE_NAME = "action/pose";
// Called once when the goal completes
void doneCb(const actionlib::SimpleClientGoalState& state,
            const hector_uav_msgs::PoseResultConstPtr& result)
{
  ROS_INFO("Finished in state [%s]", state.toString().c_str());
//   ROS_INFO("Answer: %s", result->status);
  ros::shutdown();
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

int main(int argc, char **argv)
{
    // %Tag(INIT)%
    ros::init(argc, argv, "takeoff_node");
    // %EndTag(INIT)%

    std::string ns = ros::this_node::getNamespace();
    ns = ns.substr(2, ns.length());
    ROS_INFO("%s", ns.c_str());
    if(ns.length() > 1) {
        ns += "/";
    }
    ROS_INFO("Pose name: %s", (ns + POSE_NAME).c_str());
    float Y_POS = 1.0;
    if(argc > 1) {
        Y_POS = atof(argv[1]);
    }

    // %Tag(NODEHANDLE)%
    ros::NodeHandle n;
    // %EndTag(NODEHANDLE)%

    // create the action client
    // true causes the client to spin its own thread
    // actionlib::SimpleActionClient<hector_uav_msgs::TakeoffAction> takeoff_drone1_("action/takeoff", true);
    actionlib::SimpleActionClient<hector_uav_msgs::PoseAction> pose_("/" + ns + POSE_NAME, true);

    hector_uav_msgs::PoseActionFeedback pose_feedback;
    ROS_INFO("Waiting for action server to start.");
    // wait for the action server to start
    pose_.waitForServer();
    ROS_INFO("Action server started, sending goal.");
    // send a goal to the action
    hector_uav_msgs::PoseGoal pose_goal;
    ROS_INFO("Current pose %f", pose_feedback.feedback.current_pose.pose.position.z);
    pose_goal.target_pose = pose_feedback.feedback.current_pose;
    pose_goal.target_pose.pose.position.z = 3.0;
    pose_goal.target_pose.pose.position.y = Y_POS;
    ROS_INFO("%s", (ns + std::string("world")).c_str());
    pose_goal.target_pose.header.frame_id = ns + "world";
    pose_.sendGoal(pose_goal, &doneCb, &activeCb, &feedbackCb);
    pose_.waitForResult(ros::Duration(30.0));

    if (pose_.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
        actionlib::SimpleClientGoalState state = pose_.getState();
        ROS_INFO("Action finished: %s",state.toString().c_str());
    }
    else
        ROS_INFO("Action did not finish before the time out."); 
    return 0;
}
