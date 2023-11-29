#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "badgerscontroller2";

// For Block badgerscontroller2/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_badgerscontroller2_std_msgs_Float64> Sub_badgerscontroller2_34;

// For Block badgerscontroller2/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_badgerscontroller2_std_msgs_Float64> Sub_badgerscontroller2_47;

// For Block badgerscontroller2/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_badgerscontroller2_std_msgs_Float64> Pub_badgerscontroller2_35;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

