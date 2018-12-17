#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
//Include the ball_chaser "DriveToTarget" header file
#include "ball_chaser/DriveToTarget.h"
#include <std_msgs/Float64.h>

// ROS::Publisher motor commands;
ros::Publisher motor_command_publisher;

// Create a handle_drive_request callback function that executes whenever a drive_bot service is requested
// This function should publish the requested linear x and angular velocities to the robot wheel joints
// After publishing the requested velocities, a message feedback should be returned with the requested wheel velocities
bool handle_drive_request(ball_chaser::DriveToTarget::Request& srv, 
	ball_chaser::DriveToTarget::Response& res)
{
	geometry_msgs::Twist msgToPub;
	msgToPub.linear.x = srv.linear_x;
	msgToPub.angular.z = srv.angular_z;
	motor_command_publisher.publish(msgToPub);
	res.msg_feedback = "Requested Linear Velocity: " + 
						std::to_string(srv.linear_x) +
						" Requested Angular Velocity: " + 
						std::to_string(srv.angular_z);
	return true;
}

int main(int argc, char** argv)
{
    // Initialize a ROS node
    ros::init(argc, argv, "drive_bot");

    // Create a ROS NodeHandle object
    ros::NodeHandle n;

    // Inform ROS master that we will be publishing a message of type geometry_msgs::Twist on the robot actuation topic with a publishing queue size of 10
    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    // Define a drive /ball_chaser/command_robot service with a handle_drive_request callback function
    ros::ServiceServer service = n.advertiseService("/ball_chaser/command_robot", handle_drive_request);
    ROS_INFO("Ready to Move the Robot");

    // Handle ROS communication events
    ros::spin();

    return 0;
}