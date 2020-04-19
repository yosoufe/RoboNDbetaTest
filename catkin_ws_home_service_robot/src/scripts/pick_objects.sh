#!/bin/sh
xterm  -e  " source /opt/ros/kinetic/setup.bash; roscore ;bash" & 
sleep 3
xterm  -e  " source ../../devel/setup.sh; roslaunch integration turtlebot_world.launch ;bash" & 
xterm  -e  " source ../../devel/setup.sh; roslaunch integration amcl_demo.launch ;bash" & 
xterm  -e  " source ../../devel/setup.sh; roslaunch turtlebot_rviz_launchers view_navigation.launch ;bash" & 
sleep 5
xterm  -e  " source ../../devel/setup.sh; rosrun pick_objects pick_objects_node ;bash" 