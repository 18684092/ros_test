#include "ros/ros.h"
#include "ros_test/AddTwoInts2.h"

bool add(ros_test::AddTwoInts2::Request  &req,
         ros_test::AddTwoInts2::Response &res)
{
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "andy_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("add_two_ints2", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}
