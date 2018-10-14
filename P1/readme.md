```
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/workspace/myrobot/build
gazebo world/UdacityWorld
```

```
gedit world/UdacityWorld
```

```
<world name="default">
<plugin name="hello" filename="libhello.so"/>
```
