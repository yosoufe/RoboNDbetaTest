# My Workspace for Robotics Software Engineer ND, Udacity

# Projects:

## Introduction to Gazebo
https://github.com/yosoufe/RoboNDbetaTest/tree/master/P1

## Localization using ROS
https://github.com/yosoufe/RoboNDbetaTest/tree/master/catkin_ws/src/project3

![](https://github.com/yosoufe/RoboNDbetaTest/blob/master/vids_pics/p3_amcl.png?raw=true)

## Mapping and SLAM using ROS
https://github.com/yosoufe/RoboNDbetaTest/tree/master/catkin_ws_p4
![](https://github.com/yosoufe/RoboNDbetaTest/raw/master/catkin_ws_p4/LoopClosure65.png)

## Planning and Navigation using ROS
https://github.com/yosoufe/RoboNDbetaTest/tree/master/catkin_ws_home_service_robot
![](https://github.com/yosoufe/RoboNDbetaTest/raw/master/catkin_ws_home_service_robot/test_navigation.gif)


# Certificate

https://confirm.udacity.com/T4FKNM4E

# Extra Resources:
* [F1/10 Autonomous Racing](https://www.youtube.com/playlist?list=PL868twsx7OjddCq3az74hu6pVsuJJzXvP)
    * [Github Page](https://github.com/linklab-uva)
    * [Website](https://linklab-uva.github.io/autonomousracing/index.html#header2-1)
* [Cyrill Stachniss YouTube Page](https://www.youtube.com/channel/UCi1TC2fLRvgBQNe-T4dp8Eg)
    * [Sensors and State Estimation Course 2020 - Lectures](https://www.youtube.com/playlist?list=PLgnQpQtFTOGQh_J16IMwDlji18SWQ2PZ6)
    * [Mobile Sensing and Robotics 2019 - Lectures](https://www.youtube.com/playlist?list=PLgnQpQtFTOGQJXx-x0t23RmRbjp_yMb4v)
    * Photogrammetry (No Playlist yet. Uploaded as videos)
    * [Github Page](https://github.com/PRBonn)
    * [Institute Website](http://www.ipb.uni-bonn.de/)
* Path Planning:
    * https://www.cs.cmu.edu/~maxim/files/pathplanforMAV_icra13.pdf
    * http://www.staff.science.uu.nl/~gerae101/pdf/compare.pdf
    * 


# Some VM Commands
A command to mount manually the shared folder in Guest from Host after setting it up in
the vm manager:

```
# in guest:
sudo vmhgfs-fuse .host:/ /mnt/hgfs -o allow_other
```