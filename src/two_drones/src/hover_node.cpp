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
Drone_Mission drone2("drone2");

geometry_msgs::Vector3 alt_output1;
geometry_msgs::Vector3 alt_output2;
ros::Publisher altitude1;
ros::Publisher altitude2;

geometry_msgs::Vector3 waypoint;

int main(int argc, char **argv)
{
  waypoint.x = 477511.763422;
  waypoint.y = 5523149.13698;
  waypoint.z = 0.0;

// %Tag(INIT)%
  ros::init(argc, argv, "hover_node");
// %EndTag(INIT)%

// %Tag(NODEHANDLE)%
  ros::NodeHandle n;
// %EndTag(NODEHANDLE)%

// Pose drone1_pose_("/drone1/action/pose", true);;
// Pose drone2_pose_("/drone2/action/pose", true);

drone1.fix = n.subscribe("drone1/fix", 10, &drone1_gps_callback);
drone2.fix = n.subscribe("drone2/fix", 10, &drone2_gps_callback);

drone1.magnetic = n.subscribe("drone1/magnetic", 10, &Drone_Mission::magnetic_callback, &drone1);
drone2.magnetic = n.subscribe("drone2/magnetic", 10, &Drone_Mission::magnetic_callback, &drone2);

drone1.imu = n.subscribe("drone1/raw_imu", 10, &Drone_Mission::imuCallback, &drone1);
drone2.imu = n.subscribe("drone2/raw_imu", 10, &Drone_Mission::imuCallback, &drone2);

drone1.odom = n.subscribe("drone1/odom", 10, &Drone_Mission::odomCallback, &drone1);
drone2.odom = n.subscribe("drone2/odom", 10, &Drone_Mission::odomCallback, &drone2);

drone1.motor_on = n.serviceClient<hector_uav_msgs::EnableMotors>("drone1/enable_motors");
drone2.motor_on = n.serviceClient<hector_uav_msgs::EnableMotors>("drone2/enable_motors");

// %Tag(PUBLISHER)%
drone1.move_drone = n.advertise<geometry_msgs::Twist>("drone1/cmd_vel", 1);
drone2.move_drone = n.advertise<geometry_msgs::Twist>("drone2/cmd_vel", 1);

altitude1 = n.advertise<geometry_msgs::Vector3>("drone1/altitude", 1);
altitude2 = n.advertise<geometry_msgs::Vector3>("drone2/altitude", 1);

drone1.tester = n.advertise<geometry_msgs::Vector3>("drone1/yaw_vector", 1);
drone2.tester = n.advertise<geometry_msgs::Vector3>("drone2/yaw_vector", 1);

// drone1.map = n.advertise<nav_msgs::OccupancyGrid>("drone1/map", 1);
// drone2.map = n.advertise<nav_msgs::OccupancyGrid>("drone2/map", 1);

drone1.target.x = 477511.763422;
drone1.target.y = 5523139.13698;

drone2.target.x = drone1.target.x - 6;
drone2.target.y = drone1.target.y;

drone1.enableMotors(true);
drone2.enableMotors(true);

// drone1_maintain_altitude(3, drone1_pose_);
// drone2_maintain_altitude(3, drone2_pose_);
// %EndTag(PUBLISHER)%

// %Tag(LOOP_RATE)%
  ros::Rate loop_rate(10);
// %EndTag(LOOP_RATE)%


// %Tag(ROS_OK)%
  static int count = 0;
  while (ros::ok())
  {
// %Tag(FILL_MESSAGE)%
 
    drone1.motor_msg.linear.z = 0.3;
    drone2.motor_msg.linear.z = 0.3;

    if(ros::Time::now().toSec() > 20 && ros::Time::now().toSec() < 50 && count < 2) {
      drone1.state = 1;
      drone2.state = 1;
      // ROS_INFO("Easting Difference: %f Northing Difference: %f Distance: %f", drone1.current_utm.easting - drone2.current_utm.easting, 
      // drone1.current_utm.northing - drone2.current_utm.northing, 
      // sqrt(pow(drone1.current_utm.easting - drone2.current_utm.easting, 2) + pow(drone1.current_utm.northing - drone2.current_utm.northing, 2)));
      ++count;
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
  }


  return 0;
}
// %EndTag(FULLTEXT)%

void step(Drone_Mission &drone) {
  // ros::Rate r(0.2);
    // r.sleep();
  if(drone.state == 1 && drone.finished != true) {
    if(drone.name == "drone1") {
      Pose pose_("drone1/action/pose", true);
      drone1_maintain_altitude(4, pose_);
    } else {  
      Pose pose_("drone2/action/pose", true);
      drone2_maintain_altitude(4, pose_);
    }
    if(ros::Time::now().toSec() > 25) {
      drone.finished = true;
    }
    ROS_INFO("Current state is %d", drone.state);
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
  if(drone.state == 3 && drone.finished != true) {
    // if(drone.current_gps.altitude - drone.mean_start_gps <= 3.95) {
    //   drone.motor_msg.linear.x = 0.0;
    //   drone.motor_msg.linear.z = 0.2;
    //   drone.motor_msg.angular.z = drone.direction;
    //   drone.move_drone.publish(drone.motor_msg);
    // } else if(drone.current_gps.altitude - drone.mean_start_gps > 4.05){
    //   drone.motor_msg.linear.x = 0.0;
    //   drone.motor_msg.linear.z = -0.2;
    //   drone.move_drone.publish(drone.motor_msg);  
    // }
    drone.motor_msg.linear.x = 0.0;
    drone.motor_msg.linear.z = 0.0;
    drone.motor_msg.angular.z = fabs(drone.direction);
    drone.move_drone.publish(drone.motor_msg);
    if(drone.yaw > -0.1 && drone.yaw < 0.1) {
      drone.motor_msg.angular.z = 0.0;
      ROS_INFO("Yaw value for %s is %f", drone.name.c_str(), drone.yaw);
      drone.finished = true;
    }
    ROS_INFO("Step 3 of drone1");
  }
  if(drone.state == 4 && drone.finished != true) {
    if(drone.current_gps.altitude - drone.mean_start_gps <= 3.95) {
      drone.motor_msg.linear.z = 0.1;
      drone.motor_msg.linear.y = 0.0;
      drone.motor_msg.linear.x = drone.direction;
      drone.motor_msg.angular.z = 0.0;
      drone.move_drone.publish(drone.motor_msg);
    } else if(drone.current_gps.altitude - drone.mean_start_gps > 4.05){
      drone.motor_msg.linear.x = 0.0;
      drone.motor_msg.linear.y = 0.0;
      drone.motor_msg.linear.z = -0.2;
      drone.motor_msg.angular.z = 0.0;
      drone.move_drone.publish(drone.motor_msg);  
    }
    if(sqrt(pow(drone1.current_utm.easting - drone2.current_utm.easting, 2) + pow(drone1.current_utm.northing - drone2.current_utm.northing, 2)) > 13.8) {
      drone.finished = true;
    }
    ROS_INFO("Easting Difference: %f Northing Difference: %f Distance: %f", drone1.current_utm.easting - drone2.current_utm.easting, 
    drone1.current_utm.northing - drone2.current_utm.northing, 
     sqrt(pow(drone1.current_utm.easting - drone2.current_utm.easting, 2) + pow(drone1.current_utm.northing - drone2.current_utm.northing, 2)));  
  }
  if(drone.state == 5 && drone.finished != true) {
    if(drone.name == "drone1"){
      Pose pose_("/drone1/action/pose", true);
      drone1_go_to_position(0, -3, 4, pose_);
    } else {
      Pose pose_("/drone2/action/pose", true);
      drone2_go_to_position(0, 3, 4, pose_);
    }
    drone.finished = true;
    // if(ros::Time::now().toSec() > 50) {
    // }
    ROS_INFO("State 1 for %s", drone.name.c_str());
    // ROS_INFO("Orig: %f  Modified: %f", drone.current_gps.altitude, drone.current_gps.altitude - drone.mean_start_gps);
  }
  if(drone.state == 6 && drone.finished != true) {
    if(drone.current_gps.altitude - drone.mean_start_gps <= 3.95) {
      drone.motor_msg.linear.x = 0.0;
      drone.motor_msg.linear.y = 0.0;
      drone.motor_msg.linear.z = 0.3;
      drone.motor_msg.angular.z = 0.0;
      drone.move_drone.publish(drone.motor_msg);
    } else if(drone.current_gps.altitude - drone.mean_start_gps > 4.05){
      drone.motor_msg.linear.x = 0.0;
      drone.motor_msg.linear.y = 0.0;
      drone.motor_msg.linear.z = -0.2;
      drone.motor_msg.angular.z = 0.0;
      drone.move_drone.publish(drone.motor_msg);  
    }
    if(ros::Time::now().toSec() > 50) {
      drone.finished = true;
    }
  }
  if(drone.state == 7 && drone.finished != true) {
    if(drone.theta_yaw_diff > C_PI)
      drone.theta_yaw_diff = drone.theta_yaw_diff - (2*C_PI);
    if(fabs(drone.theta_yaw_diff) > 1.56 && fabs(drone.theta_yaw_diff) < 1.58) {
      drone.rotateToHeading = true;
      if(drone1.rotateToHeading == true && drone2.rotateToHeading == true) {
          drone.motor_msg.linear.x = 0.0;
          drone.motor_msg.linear.y = drone.sign*0.7;
          drone.motor_msg.linear.z = 0.0;
          drone.motor_msg.angular.z = 0.0;
      } else {
        drone.motor_msg.linear.x = 0.0;
        drone.motor_msg.linear.y = 0.0;
        drone.motor_msg.linear.z = 0.0;
        drone.motor_msg.angular.z = 0.0;
      }
    } else {
      drone.rotateToHeading = false;
      drone.motor_msg.linear.x = 0.0;
      drone.motor_msg.linear.y = 0.0;
      drone.motor_msg.linear.z = 0.0;
      drone.motor_msg.angular.z = (drone.theta_yaw_diff - (1.57*drone.sign))*0.5;
      ROS_INFO("%s angle to Target: %f", drone.name.c_str(), drone.theta_yaw_diff*180/C_PI);
    }
    drone.move_drone.publish(drone.motor_msg);
    // ROS_INFO("%s: %f %f", drone.name.c_str(), drone.theta_yaw_diff, fabs(drone.theta - drone.yaw));
    if(drone.dist_x < 0.2 && drone.dist_y < 0.2) {
      drone.finished = true;
    }
  }
  if(drone.state == 8 && drone.finished != true) {
    if(drone.theta < 0.0)
      drone.sign = 1;
    else
      drone.sign = -1;
    if(fabs(drone.theta_yaw_diff) < 0.05) {
      drone.motor_msg.linear.x = 1.0;
      drone.motor_msg.linear.y = 0.0;
      drone.motor_msg.linear.z = 0.0;
      drone.motor_msg.angular.z = 0.0;
    } else {
      drone.motor_msg.linear.x = 0.0;
      drone.motor_msg.linear.y = 0.0;
      drone.motor_msg.linear.z = 0.0;
      drone.motor_msg.angular.z = (drone.theta_yaw_diff)*0.5;
    }
    drone.move_drone.publish(drone.motor_msg);
    ROS_INFO("%s yaw - theta: %f", drone.name.c_str(), fabs(drone.theta_yaw_diff));
    // ROS_INFO("%f %f %f %f %f %f %f", drone.subOdom.pose.pose.position.x, drone.target.x, drone.subOdom.pose.pose.position.y, drone.target.y, drone.dist_x, drone.dist_y, drone.theta);
    if(drone.dist_x < 0.1 && drone.dist_y < 0.1 && drone.dist_x > -0.1 && drone.dist_y > -0.1)
      drone.finished = true;
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

void Drone_Mission::imuCallback(const sensor_msgs::ImuConstPtr& msg) {
  sensor_msgs::Imu imu = *msg;
  // tf::Quaternion q(imu.orientation.x, imu.orientation.y, imu.orientation.z, imu.orientation.w);
  // tf::Matrix3x3 m(q);
  // m.getRPY(roll, pitch, yaw);
  // ROS_INFO("%s: Roll: %f, Pitch: %f, Yaw: %f", name.c_str(), roll, pitch, yaw);
  
}

void Drone_Mission::odomCallback(const nav_msgs::OdometryConstPtr& msg) {
  subOdom = *msg;
  tf::Quaternion q(subOdom.pose.pose.orientation.x, subOdom.pose.pose.orientation.y, subOdom.pose.pose.orientation.z, subOdom.pose.pose.orientation.w);
  tf::Matrix3x3 m(q);
  m.getRPY(roll, pitch, yaw);
  dist_x = target.x - subOdom.pose.pose.position.x;
  dist_y = target.y - subOdom.pose.pose.position.y;
  theta = atan2(dist_y, dist_x);
  test.x = dist_x;
  test.y = dist_y;
  test.z = theta;
  tester.publish(test);
  theta_yaw_diff = theta - yaw;
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

void drone2_maintain_altitude(float height2, Pose &pose2_) {
  ROS_INFO("Waiting for action server to start.");
  // wait for the action server to start
  pose2_.waitForServer();
  ROS_INFO("Action server started, sending goal.");
  drone2.pose_goal.target_pose = drone2.pose_feedback.feedback.current_pose;
  drone2.pose_goal.target_pose.pose.position.x = -9;
  drone2.pose_goal.target_pose.pose.position.y = 22;
  drone2.pose_goal.target_pose.pose.position.z = height2;
  ROS_INFO("Goal prepared");
  drone2.pose_goal.target_pose.header.frame_id = "drone2/world";
  ROS_INFO("Goal Sent");
  pose2_.sendGoal(drone2.pose_goal);
  // pose2_.waitForResult(ros::Duration(30.0));

  if (pose2_.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
      actionlib::SimpleClientGoalState state = pose2_.getState();
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

void drone2_go_to_position(float x, float y, float z, Pose &pose2_) {
  ROS_INFO("Waiting for action server to start.");
  // wait for the action server to start
  pose2_.waitForServer();
  ROS_INFO("Action server started, sending goal.");
  drone2.pose_goal.target_pose = drone2.pose_feedback.feedback.current_pose;
  drone2.pose_goal.target_pose.pose.position.x = x;
  drone2.pose_goal.target_pose.pose.position.y = y;
  drone2.pose_goal.target_pose.pose.position.z = z;
  ROS_INFO("Goal prepared");
  drone2.pose_goal.target_pose.header.frame_id = "drone2/world";
  ROS_INFO("Goal Sent");
  pose2_.sendGoal(drone2.pose_goal);
  // pose2_.waitForResult(ros::Duration(30.0));

  if (pose2_.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
      actionlib::SimpleClientGoalState state = pose2_.getState();
      ROS_INFO("Action finished: %s",state.toString().c_str());
  }
  else
      ROS_INFO("Action did not finish before the time out."); 
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
        drone1.state = 8;
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
    case 4:
      if(drone1.finished == false) {
        step(drone1);
      } else {
        drone1.state = 2;
        drone1.finished = false;
        ROS_INFO("Done Distancing");
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
        if(drone2.state == 7)
          drone1.substate == 1;
        step(drone1);
      } else {
        drone1.state = 2;
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
        drone1.target.x = waypoint.x;
        drone1.target.y = waypoint.y;
        drone1.finished = false;
        ROS_INFO("Done reaching with gps");
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
  static double start_magx = 0;
  // ROS_INFO("%d", count);
  if(ros::Time::now().toSec() < 20) {
    count_2 += 1;
    start_alt_2 += drone2.current_gps.altitude;
    start_magx += drone2.current_magnetic.vector.x;
    drone2.mean_start_gps = start_alt_2/count_2;
    drone2.mean_start_mag_x = start_magx/count_2;
    altitude2.publish(alt_output2);
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
        drone2.state = 8;
        drone2.direction = -0.3;
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
    case 3:
      if(drone2.finished == false) {
        step(drone2);
      } else {
        drone2.state = 7;
        drone2.direction = -0.2;
        drone2.finished = false;
        ROS_INFO("Done Rotating");
      }
      break;
    case 4:
      if(drone2.finished == false) {
        step(drone2);
      } else {
        drone2.state = 2;
        drone2.finished = false;
        ROS_INFO("Done Distancing");
      }
      break;
    case 5:
      if(drone2.finished == false) {
        step(drone2);
      } else {
        drone2.state = 3;
        drone2.target.x = waypoint.x;
        drone2.target.y = waypoint.y;
        drone2.finished = false;
        ROS_INFO("Done Reaching");
      }
      break;
    case 6:
      if(drone2.finished == false) {
        step(drone2);
      } else {
        drone2.state = 4;
        drone2.finished = false;
        ROS_INFO("Done Hovering");
      }
      break;
    case 7:
      if(drone2.finished == false) {
        drone2.sign = -1;
        if(drone1.state == 7)
          drone2.substate == 1;
        step(drone2);
      } else {
        drone2.state = 2;
        drone2.finished = false;
        ROS_INFO("Done turning to yaw State: %d", drone2.state);
      }
      break;
    case 8:
      if(drone2.finished == false) {
        drone2.sign = -1;
        step(drone2);
      } else {
        drone2.state = 7;
        drone2.target.x = waypoint.x - 6;
        drone2.target.y = waypoint.y;
        drone2.finished = false;
        ROS_INFO("Done reaching with gps");
      }
      break;
    default:
      ROS_INFO("Invalid State");
      break;
  }
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

