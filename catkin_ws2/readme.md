```
source devel/setup.bash
rosdep -i install turtlebot_gazebo # if error happened follow [this](https://answers.ros.org/question/325039/apt-update-fails-cannot-install-pkgs-key-not-working/)
catkin_make
source devel/setup.sh
roslaunch turtlebot_gazebo turtlebot_world.launch
```