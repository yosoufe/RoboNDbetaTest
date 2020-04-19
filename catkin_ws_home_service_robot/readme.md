# Home Service Robot


![[YouTube Video](https://youtu.be/yLND5wDFcBc)](final_results.gif)

YouTube Link: https://youtu.be/yLND5wDFcBc


## SLAM Testing:
```
sudo apt install ros-kinetic-turtlebot-*
```
Sources:
* http://wiki.ros.org/turtlebot/Tutorials/indigo

to save the map:
```
rosrun map_server map_saver -f myMap
```

## Navigation testing:
```
cd src/scripts
./test_navigation.sh
```

## Some Goal Numbers
To echo the navigation goals that rviz is publishing:
```
rostopic echo /move_base/goal 
```

Some interesting goals:
1. Pickup Zone
```
goal: 
  target_pose: 
    header: 
      frame_id: "map"
    pose: 
      position: 
        x: -5.68023967743
        y: 3.39695715904
        z: 0.0
      orientation: 
        x: 0.0
        y: 0.0
        z: -0.245873951689
        w: 0.969301810522
```
2. Delivery Zone
```
goal: 
  target_pose: 
    header: 
      frame_id: "map"
    pose: 
      position: 
        x: -4.27964115143
        y: -3.69061994553
        z: 0.0
      orientation: 
        x: 0.0
        y: 0.0
        z: 0.443500324123
        w: 0.896274211669
```