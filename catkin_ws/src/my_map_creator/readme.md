```
# export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}
gzserver src/my_map_creator/world/myWorld.world
roslaunch my_map_creator request_publisher.launch
```