// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from spider_msgs:srv/ServoCalibrate.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_MSGS__SRV__DETAIL__SERVO_CALIBRATE__BUILDER_HPP_
#define SPIDER_MSGS__SRV__DETAIL__SERVO_CALIBRATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "spider_msgs/srv/detail/servo_calibrate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace spider_msgs
{

namespace srv
{

namespace builder
{

class Init_ServoCalibrate_Request_pwm
{
public:
  explicit Init_ServoCalibrate_Request_pwm(::spider_msgs::srv::ServoCalibrate_Request & msg)
  : msg_(msg)
  {}
  ::spider_msgs::srv::ServoCalibrate_Request pwm(::spider_msgs::srv::ServoCalibrate_Request::_pwm_type arg)
  {
    msg_.pwm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_msgs::srv::ServoCalibrate_Request msg_;
};

class Init_ServoCalibrate_Request_channel
{
public:
  Init_ServoCalibrate_Request_channel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ServoCalibrate_Request_pwm channel(::spider_msgs::srv::ServoCalibrate_Request::_channel_type arg)
  {
    msg_.channel = std::move(arg);
    return Init_ServoCalibrate_Request_pwm(msg_);
  }

private:
  ::spider_msgs::srv::ServoCalibrate_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_msgs::srv::ServoCalibrate_Request>()
{
  return spider_msgs::srv::builder::Init_ServoCalibrate_Request_channel();
}

}  // namespace spider_msgs


namespace spider_msgs
{

namespace srv
{

namespace builder
{

class Init_ServoCalibrate_Response_status
{
public:
  explicit Init_ServoCalibrate_Response_status(::spider_msgs::srv::ServoCalibrate_Response & msg)
  : msg_(msg)
  {}
  ::spider_msgs::srv::ServoCalibrate_Response status(::spider_msgs::srv::ServoCalibrate_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spider_msgs::srv::ServoCalibrate_Response msg_;
};

class Init_ServoCalibrate_Response_pwm_value
{
public:
  Init_ServoCalibrate_Response_pwm_value()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ServoCalibrate_Response_status pwm_value(::spider_msgs::srv::ServoCalibrate_Response::_pwm_value_type arg)
  {
    msg_.pwm_value = std::move(arg);
    return Init_ServoCalibrate_Response_status(msg_);
  }

private:
  ::spider_msgs::srv::ServoCalibrate_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::spider_msgs::srv::ServoCalibrate_Response>()
{
  return spider_msgs::srv::builder::Init_ServoCalibrate_Response_pwm_value();
}

}  // namespace spider_msgs

#endif  // SPIDER_MSGS__SRV__DETAIL__SERVO_CALIBRATE__BUILDER_HPP_
