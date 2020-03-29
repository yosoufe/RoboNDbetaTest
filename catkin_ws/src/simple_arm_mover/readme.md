# Arm Mover
The goal of the arm_mover node is to command each joint in the simple arm and make it swing between -pi/2 to pi/2 over time. Here’s a demonstration of this node in action

To do so, it must publish joint angle command messages to the following topics:

Topic Name:	/simple_arm/joint_1_position_controller/command
Message Type:	std_msgs/Float64
Description:	Commands joint 1 to move counter-clockwise, units in radians

Topic Name:	/simple_arm/joint_2_position_controller/command
Message Type:	std_msgs/Float64
Description:	Commands joint 2 to move counter-clockwise, units in radians
