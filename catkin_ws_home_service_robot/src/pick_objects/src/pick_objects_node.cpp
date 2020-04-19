#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "simple_navigation_goals");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goals[2];

  // Define a position and orientation for the robot to reach
  goals[0].target_pose.pose.position.x = -5.68023967743;
  goals[0].target_pose.pose.position.y = 3.39695715904;
  goals[0].target_pose.pose.orientation.w = 0.969301810522;
  goals[0].target_pose.pose.orientation.z = -0.245873951689;

  goals[1].target_pose.pose.position.x = -4.27964115143;
  goals[1].target_pose.pose.position.y = -3.69061994553;
  goals[1].target_pose.pose.orientation.w = 0.896274211669;
  goals[1].target_pose.pose.orientation.z = 0.443500324123;


  for (int idx = 0 ; idx < 2 ; idx++)
  {
    goals[idx].target_pose.header.frame_id = "map";
    goals[idx].target_pose.header.stamp = ros::Time::now();

    // Send the goal position and orientation for the robot to reach
    ROS_INFO("Sending goal");
    ac.sendGoal(goals[idx]);

    // Wait an infinite time for the results
    ac.waitForResult();

    // Check if the robot reached its goal
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
      ROS_INFO("Hooray, reached the goal");
    else
      ROS_INFO("The base failed to move forward 1 meter for some reason");
    
    // wait 5 seconds
    ros::Duration(5).sleep();
  }

  return 0;
}