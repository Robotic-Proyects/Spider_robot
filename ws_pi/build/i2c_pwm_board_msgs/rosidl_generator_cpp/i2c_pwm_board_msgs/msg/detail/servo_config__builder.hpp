// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from i2c_pwm_board_msgs:msg/ServoConfig.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG__BUILDER_HPP_
#define I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "i2c_pwm_board_msgs/msg/detail/servo_config__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace i2c_pwm_board_msgs
{

namespace msg
{

namespace builder
{

class Init_ServoConfig_direction
{
public:
  explicit Init_ServoConfig_direction(::i2c_pwm_board_msgs::msg::ServoConfig & msg)
  : msg_(msg)
  {}
  ::i2c_pwm_board_msgs::msg::ServoConfig direction(::i2c_pwm_board_msgs::msg::ServoConfig::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i2c_pwm_board_msgs::msg::ServoConfig msg_;
};

class Init_ServoConfig_range
{
public:
  explicit Init_ServoConfig_range(::i2c_pwm_board_msgs::msg::ServoConfig & msg)
  : msg_(msg)
  {}
  Init_ServoConfig_direction range(::i2c_pwm_board_msgs::msg::ServoConfig::_range_type arg)
  {
    msg_.range = std::move(arg);
    return Init_ServoConfig_direction(msg_);
  }

private:
  ::i2c_pwm_board_msgs::msg::ServoConfig msg_;
};

class Init_ServoConfig_center
{
public:
  explicit Init_ServoConfig_center(::i2c_pwm_board_msgs::msg::ServoConfig & msg)
  : msg_(msg)
  {}
  Init_ServoConfig_range center(::i2c_pwm_board_msgs::msg::ServoConfig::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_ServoConfig_range(msg_);
  }

private:
  ::i2c_pwm_board_msgs::msg::ServoConfig msg_;
};

class Init_ServoConfig_servo
{
public:
  Init_ServoConfig_servo()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ServoConfig_center servo(::i2c_pwm_board_msgs::msg::ServoConfig::_servo_type arg)
  {
    msg_.servo = std::move(arg);
    return Init_ServoConfig_center(msg_);
  }

private:
  ::i2c_pwm_board_msgs::msg::ServoConfig msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::i2c_pwm_board_msgs::msg::ServoConfig>()
{
  return i2c_pwm_board_msgs::msg::builder::Init_ServoConfig_servo();
}

}  // namespace i2c_pwm_board_msgs

#endif  // I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG__BUILDER_HPP_
