#include "std_msgs/String.h"
#include <sstream>
#include <geographic_msgs/GeoPoint.h>
#include <geographic_msgs/GeoPose.h>
#include "two_drones/hover_node.h"

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
    geometry_msgs::Twist drone1_motor_msg;
    geometry_msgs::Twist drone2_motor_msg;

    drone1_motor_msg.linear.z = 0.2;
    
    drone2_motor_msg.linear.z = 0.2;

    if(ros::Time::now().toSec() < 30) {
      if(drone1.current_gps.altitude <= 2.95) {
        drone1.move_drone.publish(drone1_motor_msg);
      } else if(drone1.current_gps.altitude > 3.05){
        drone1_motor_msg.linear.z = -0.2;
        drone1.move_drone.publish(drone1_motor_msg);  
      }

      if(drone2.current_gps.altitude <= 2.95) {
        drone2.move_drone.publish(drone2_motor_msg);
      } else if(drone2.current_gps.altitude > 3.05){
        drone2_motor_msg.linear.z = -0.2;
        drone2.move_drone.publish(drone2_motor_msg);  
      } 
    } else {
      if(drone1.current_gps.altitude > 0.05){
        drone1_motor_msg.linear.z = -0.1;
        drone1.move_drone.publish(drone1_motor_msg);  
      }
      if(drone2.current_gps.altitude > 0.05){
        drone2_motor_msg.linear.z = -0.1;
        drone2.move_drone.publish(drone2_motor_msg);  
      }
    }

    // if(ros::Time::now().toSec() > 30 && ros::Time::now().toSec() < 32) {
    //   drone1.state = 1;
    //   drone2.state = 1;
    //   ROS_INFO("Take Off Initiated");
    // }

// %Tag(ROSCONSOLE)%
    // ROS_INFO("%f %f %f %f", drone1.current_utm.easting, drone2.current_utm.easting, drone1.current_utm.northing, drone2.current_utm.northing);
    // ROS_INFO("%f %f", (current_drone1_gps.latitude - current_drone2_gps.latitude), (current_drone1_gps.longitude - current_drone2_gps.longitude));
    ROS_INFO("%f %f", drone1.current_gps.altitude , drone2.current_gps.altitude);

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

void step(Drone_Mission drone) {
  if(drone.state == 1 && drone.finished != true) {
    if(drone.current_gps.altitude - drone.mean_start_gps <= 2.95) {
      drone.move_drone.publish(drone.motor_msg);
    } else if(drone.current_gps.altitude - drone.mean_start_gps > 3.05){
      drone.motor_msg.linear.z = -0.2;
      drone.move_drone.publish(drone.motor_msg);  
    } else {
      drone.finished = true;
    }
  }
  if(drone.state == -1 && drone.finished != true) {
    if(drone.current_gps.altitude - drone.mean_start_gps > 0.05){
      drone.motor_msg.linear.z = -0.1;
      drone.move_drone.publish(drone.motor_msg);  
    } else {
      drone.finished = true;
    }
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

void drone1_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg) {
  // ROS_INFO("Loading gps");
  drone1.current_gps = *msg;
  geodesy::convert(drone1.current_gps, drone1.gp);
  geodesy::fromMsg(drone1.gp, drone1.current_utm);
  // utm_drone1.publish(current_drone1_utm);
  // static int count = 0;
  // static double start_alt = 0;
  // if(ros::Time::now().toSec() < 30) {
  //   count += 1;
  //   start_alt += drone1.current_gps.altitude; 
  //   drone1.mean_start_gps = start_alt/count;
  //   ROS_INFO("Mean drone1 altitude %f", drone1.mean_start_gps);
  // } else {
  //   switch(drone1.state) {
  //     case 0:
  //       break;
  //     case 1: {
  //       if(drone1.finished != true) {
  //         step(drone1);
  //       } else {
  //         drone1.state = -1;
  //         drone1.finished = false;
  //         ROS_INFO("Hovering achieved! Landing Begins");
  //       }
  //       break;
  //     }
  //     case -1: {
  //       if(drone1.finished != true) {
  //         step(drone1);
  //       } else {
  //         drone1.state = 0;
  //         drone1.finished = false;
  //         ROS_INFO("Landed Succesfully!");
  //       }
  //       break;
  //     }
  //   }
  // }
}

void drone2_gps_callback(const sensor_msgs::NavSatFix::ConstPtr& msg) {
  drone2.current_gps = *msg;
  geodesy::convert(drone2.current_gps, drone2.gp);
  geodesy::fromMsg(drone2.gp, drone2.current_utm);
  // utm_drone2.publish(current_drone2_utm);
  // static int count = 0;
  // static double start_alt = 0;
  // ROS_INFO("%f", ros::Time::now().toSec());
  // if(ros::Time::now().toSec() < 30) {
  //   count += 1;
  //   start_alt += drone1.current_gps.altitude; 
  //   drone2.mean_start_gps = start_alt/count;
  //   ROS_INFO("Mean drone1 altitude %f", drone2.mean_start_gps);
  // } else {
  //   switch(drone2.state) {
  //     case 0:
  //       break;
  //     case 1: {
  //       if(drone2.finished != true) {
  //         step(drone2);
  //       } else {
  //         drone2.state = -1;
  //         drone2.finished = false;
  //         ROS_INFO("Hovering achieved! Landing Begins");
  //       }
  //       break;
  //     }
  //     case -1: {
  //       if(drone2.finished != true) {
  //         step(drone2);
  //       } else {
  //         drone2.state = 0;
  //         drone2.finished = false;
  //         ROS_INFO("Landed Succesfully!");
  //       }
  //       break;
  //     }
  //   }
  // }
}

