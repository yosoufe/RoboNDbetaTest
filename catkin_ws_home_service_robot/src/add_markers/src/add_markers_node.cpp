#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <move_base_msgs/MoveBaseAction.h>


ros::Subscriber nav_result_sub;
ros::Publisher marker_pub;
int msg_counter = 0;
visualization_msgs::Marker marker;
uint32_t shape = visualization_msgs::Marker::CUBE;

void navigation_results_cb(const move_base_msgs::MoveBaseActionResult& msg)
{
  if (msg_counter == 0)
  {
    ROS_INFO("Hidding Pick-up zone");
    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);
    msg_counter++;
  } else if (msg_counter == 1)
  {
    ROS_INFO("Creating delivery zone");
    marker.pose.position.x = -4.27964115143;
    marker.pose.position.y = -3.69061994553;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.443500324123;
    marker.pose.orientation.w = 0.896274211669;
    marker.action = visualization_msgs::Marker::ADD;
    marker_pub.publish(marker);
    msg_counter++;
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_shapes");
  ros::NodeHandle n;
  ros::Rate r(1);
  marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  nav_result_sub = n.subscribe("/move_base/result", 10, navigation_results_cb);
  
  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  marker.header.frame_id = "map";
  marker.header.stamp = ros::Time::now();

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  marker.ns = "basic_shapes";
  marker.id = 0;

  // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  marker.type = shape;

  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = 0.40;
  marker.scale.y = 0.40;
  marker.scale.z = 0.40;

  // Set the color -- be sure to set alpha to something non-zero!
  marker.color.r = 0.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0;

  marker.lifetime = ros::Duration();

  // Publish the marker
  while ( marker_pub.getNumSubscribers() < 1)
  {
    if (!ros::ok())
    {
      return 0;
    }
    ROS_WARN_ONCE("Please create a subscriber to the marker");
    sleep(1);
  }
  // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
  marker.action = visualization_msgs::Marker::ADD;

  // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
  marker.pose.position.x = -5.68023967743;
  marker.pose.position.y = 3.39695715904;
  marker.pose.position.z = 0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = -0.245873951689;
  marker.pose.orientation.w = 0.969301810522;

  marker_pub.publish(marker);
  ROS_INFO("Creating Pick-up zone");

  ros::spin();
}