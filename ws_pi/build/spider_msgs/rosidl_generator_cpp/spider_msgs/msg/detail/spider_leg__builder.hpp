// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from spider_msgs:msg/SpiderLeg.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_MSGS__MSG__DETAIL__SPIDER_LEG__BUILDER_HPP_
#define SPIDER_MSGS__MSG__DETAIL__SPIDER_LEG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "spider_msgs/msg/detail/spider_leg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace spider_msgs
{

namespace msg
{

namespace builder
{

class Init_SpiderLeg_smooth_value
{
public:
  explicit Init_SpiderLeg_smooth_value(::spider_msgs::msg::SpiderLeg & msg)
  : msg_(msg)
  {}
  ::spider_msgs::msg::SpiderLeg smooth_value(::spider_msgs::msg::SpiderLeg::_smooth_value_type arg)
  {
    msg_.smooth_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_msgs::msg::SpiderLeg msg_;
};

class Init_SpiderLeg_foot
{
public:
  explicit Init_SpiderLeg_foot(::spider_msgs::msg::SpiderLeg & msg)
  : msg_(msg)
  {}
  Init_SpiderLeg_smooth_value foot(::spider_msgs::msg::SpiderLeg::_foot_type arg)
  {
    msg_.foot = std::move(arg);
    return Init_SpiderLeg_smooth_value(msg_);
  }

private:
  ::spider_msgs::msg::SpiderLeg msg_;
};

class Init_SpiderLeg_leg
{
public:
  explicit Init_SpiderLeg_leg(::spider_msgs::msg::SpiderLeg & msg)
  : msg_(msg)
  {}
  Init_SpiderLeg_foot leg(::spider_msgs::msg::SpiderLeg::_leg_type arg)
  {
    msg_.leg = std::move(arg);
    return Init_SpiderLeg_foot(msg_);
  }

private:
  ::spider_msgs::msg::SpiderLeg msg_;
};

class Init_SpiderLeg_hip
{
public:
  Init_SpiderLeg_hip()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SpiderLeg_leg hip(::spider_msgs::msg::SpiderLeg::_hip_type arg)
  {
    msg_.hip = std::move(arg);
    return Init_SpiderLeg_leg(msg_);
  }

private:
  ::spider_msgs::msg::SpiderLeg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_msgs::msg::SpiderLeg>()
{
  return spider_msgs::msg::builder::Init_SpiderLeg_hip();
}

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__MSG__DETAIL__SPIDER_LEG__BUILDER_HPP_
