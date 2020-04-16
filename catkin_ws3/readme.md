# GMapping in ROS

```
git submodule init --update --recursive

catkin_make -j8
source devel/setup.bash

rosdep -i install turtlebot_gazebo
rosdep -i install turtlebot_teleop
rosdep -i install gmapping

roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=worlds/willowgarage.world
roslaunch turtlebot_teleop keyboard_teleop.launch
rosrun gmapping slam_gmapping
rosrun rviz rviz
# rosparam set /turtlebot_teleop_keyboard/scale_linear 1.0
```

Edit the rviz configuration as follows:

* Change the **Fixed Frame** to `map`
* Keep **Reference Frame** as `default`
* Add a **RobotModel**
* Add a **camera** and select the `/camera/rgb/image_raw` topic
* Add a **map** and select the `/map` topic


```
# to save the map file
rosrun map_server map_saver -f myMap
```

# Some other resources:
* https://github.com/udacity/RoboND-SLAMLAb
* [A Tutorial on Graph-Based SLAM](http://www2.informatik.uni-freiburg.de/~stachnis/pdf/grisetti10titsmag.pdf)
* [The GraphSLAM Algorithm with Applications to Large-Scale Mapping of Urban Structures](http://robot.cc/papers/thrun.graphslam.pdf)
