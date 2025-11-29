// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from i2c_pwm_board_msgs:srv/DriveMode.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__SRV__DETAIL__DRIVE_MODE__BUILDER_HPP_
#define I2C_PWM_BOARD_MSGS__SRV__DETAIL__DRIVE_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "i2c_pwm_board_msgs/srv/detail/drive_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace i2c_pwm_board_msgs
{

namespace srv
{

namespace builder
{

class Init_DriveMode_Request_servos
{
public:
  explicit Init_DriveMode_Request_servos(::i2c_pwm_board_msgs::srv::DriveMode_Request & msg)
  : msg_(msg)
  {}
  ::i2c_pwm_board_msgs::srv::DriveMode_Request servos(::i2c_pwm_board_msgs::srv::DriveMode_Request::_servos_type arg)
  {
    msg_.servos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i2c_pwm_board_msgs::srv::DriveMode_Request msg_;
};

class Init_DriveMode_Request_scale
{
public:
  explicit Init_DriveMode_Request_scale(::i2c_pwm_board_msgs::srv::DriveMode_Request & msg)
  : msg_(msg)
  {}
  Init_DriveMode_Request_servos scale(::i2c_pwm_board_msgs::srv::DriveMode_Request::_scale_type arg)
  {
    msg_.scale = std::move(arg);
    return Init_DriveMode_Request_servos(msg_);
  }

private:
  ::i2c_pwm_board_msgs::srv::DriveMode_Request msg_;
};

class Init_DriveMode_Request_track
{
public:
  explicit Init_DriveMode_Request_track(::i2c_pwm_board_msgs::srv::DriveMode_Request & msg)
  : msg_(msg)
  {}
  Init_DriveMode_Request_scale track(::i2c_pwm_board_msgs::srv::DriveMode_Request::_track_type arg)
  {
    msg_.track = std::move(arg);
    return Init_DriveMode_Request_scale(msg_);
  }

private:
  ::i2c_pwm_board_msgs::srv::DriveMode_Request msg_;
};

class Init_DriveMode_Request_radius
{
public:
  explicit Init_DriveMode_Request_radius(::i2c_pwm_board_msgs::srv::DriveMode_Request & msg)
  : msg_(msg)
  {}
  Init_DriveMode_Request_track radius(::i2c_pwm_board_msgs::srv::DriveMode_Request::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return Init_DriveMode_Request_track(msg_);
  }

private:
  ::i2c_pwm_board_msgs::srv::DriveMode_Request msg_;
};

class Init_DriveMode_Request_rpm
{
public:
  explicit Init_DriveMode_Request_rpm(::i2c_pwm_board_msgs::srv::DriveMode_Request & msg)
  : msg_(msg)
  {}
  Init_DriveMode_Request_radius rpm(::i2c_pwm_board_msgs::srv::DriveMode_Request::_rpm_type arg)
  {
    msg_.rpm = std::move(arg);
    return Init_DriveMode_Request_radius(msg_);
  }

private:
  ::i2c_pwm_board_msgs::srv::DriveMode_Request msg_;
};

class Init_DriveMode_Request_mode
{
public:
  Init_DriveMode_Request_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DriveMode_Request_rpm mode(::i2c_pwm_board_msgs::srv::DriveMode_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_DriveMode_Request_rpm(msg_);
  }

private:
  ::i2c_pwm_board_msgs::srv::DriveMode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::i2c_pwm_board_msgs::srv::DriveMode_Request>()
{
  return i2c_pwm_board_msgs::srv::builder::Init_DriveMode_Request_mode();
}

}  // namespace i2c_pwm_board_msgs


namespace i2c_pwm_board_msgs
{

namespace srv
{

namespace builder
{

class Init_DriveMode_Response_error
{
public:
  Init_DriveMode_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::i2c_pwm_board_msgs::srv::DriveMode_Response error(::i2c_pwm_board_msgs::srv::DriveMode_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i2c_pwm_board_msgs::srv::DriveMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::i2c_pwm_board_msgs::srv::DriveMode_Response>()
{
  return i2c_pwm_board_msgs::srv::builder::Init_DriveMode_Response_error();
}

}  // namespace i2c_pwm_board_msgs

#endif  // I2C_PWM_BOARD_MSGS__SRV__DETAIL__DRIVE_MODE__BUILDER_HPP_
