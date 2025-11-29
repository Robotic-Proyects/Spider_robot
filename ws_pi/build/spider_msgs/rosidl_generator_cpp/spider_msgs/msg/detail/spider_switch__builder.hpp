// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from spider_msgs:msg/SpiderSwitch.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_MSGS__MSG__DETAIL__SPIDER_SWITCH__BUILDER_HPP_
#define SPIDER_MSGS__MSG__DETAIL__SPIDER_SWITCH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "spider_msgs/msg/detail/spider_switch__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace spider_msgs
{

namespace msg
{

namespace builder
{

class Init_SpiderSwitch_oe_value
{
public:
  Init_SpiderSwitch_oe_value()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::spider_msgs::msg::SpiderSwitch oe_value(::spider_msgs::msg::SpiderSwitch::_oe_value_type arg)
  {
    msg_.oe_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_msgs::msg::SpiderSwitch msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_msgs::msg::SpiderSwitch>()
{
  return spider_msgs::msg::builder::Init_SpiderSwitch_oe_value();
}

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__MSG__DETAIL__SPIDER_SWITCH__BUILDER_HPP_
