```
# export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}
gzserver src/project3/world/project3.world
roslaunch project3 request_publisher.launch

roslaunch project3 amcl.launch
rosrun teleop_twist_keyboard teleop_twist_keyboard.py

```