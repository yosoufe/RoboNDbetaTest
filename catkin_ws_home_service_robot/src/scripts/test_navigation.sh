#!/bin/sh
xterm  -e  " source /opt/ros/kinetic/setup.bash; roscore ;bash" & 
sleep 3
xterm  -e  " source ../../devel/setup.sh; roslaunch turtlebot_gazebo turtlebot_world.launch ;bash" & 
sleep 1
xterm  -e  " source ../../devel/setup.sh; roslaunch turtlebot_gazebo amcl_demo.launch ;bash" & 
sleep 1
xterm  -e  " source ../../devel/setup.sh; roslaunch turtlebot_rviz_launchers view_navigation.launch ;bash" 