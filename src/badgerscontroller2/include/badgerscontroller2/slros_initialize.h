#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "badgerscontroller2_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block badgerscontroller2/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_badgerscontroller2_std_msgs_Float64> Sub_badgerscontroller2_34;

// For Block badgerscontroller2/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_badgerscontroller2_std_msgs_Float64> Sub_badgerscontroller2_47;

// For Block badgerscontroller2/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_badgerscontroller2_std_msgs_Float64> Pub_badgerscontroller2_35;

void slros_node_init(int argc, char** argv);

#endif
