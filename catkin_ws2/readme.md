```
source devel/setup.bash
rosdep -i install turtlebot_gazebo # if error happened follow [this](https://answers.ros.org/question/325039/apt-update-fails-cannot-install-pkgs-key-not-working/)
catkin_make
source devel/setup.sh

rosdep -i install turtlebot_gazebo
rosdep -i install turtlebot_teleop

roslaunch turtlebot_gazebo turtlebot_world.launch
roslaunch practice_pkg my_robot_pose_ekf.launch
roslaunch odom_to_trajectory create_trajectory.launch 
roslaunch turtlebot_teleop keyboard_teleop.launch
# rviz -d src/practicekg/rviz/rviz_config.rviz
```


