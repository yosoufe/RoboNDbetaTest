#!/bin/sh
xterm  -e  " source /opt/ros/kinetic/setup.bash; roscore ;bash" & 
sleep 3
xterm  -e  " source ../../devel/setup.sh; roslaunch integration turtlebot_world.launch ;bash" & 
sleep 5
xterm  -e  " source ../../devel/setup.sh; roslaunch integration amcl_demo.launch ;bash" & 
sleep 5
xterm  -e  " source ../../devel/setup.sh; rosrun rviz rviz -d ../rvizConfigs/add_markers.rviz ;bash" & 
sleep 5
xterm  -e  " source ../../devel/setup.sh; rosrun add_markers add_markers_node ;bash" &
xterm  -e  " source ../../devel/setup.sh; rosrun pick_objects pick_objects_node ;bash"
