// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from i2c_pwm_board_msgs:msg/Servo.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO__BUILDER_HPP_
#define I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "i2c_pwm_board_msgs/msg/detail/servo__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace i2c_pwm_board_msgs
{

namespace msg
{

namespace builder
{

class Init_Servo_value
{
public:
  explicit Init_Servo_value(::i2c_pwm_board_msgs::msg::Servo & msg)
  : msg_(msg)
  {}
  ::i2c_pwm_board_msgs::msg::Servo value(::i2c_pwm_board_msgs::msg::Servo::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i2c_pwm_board_msgs::msg::Servo msg_;
};

class Init_Servo_servo
{
public:
  Init_Servo_servo()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Servo_value servo(::i2c_pwm_board_msgs::msg::Servo::_servo_type arg)
  {
    msg_.servo = std::move(arg);
    return Init_Servo_value(msg_);
  }

private:
  ::i2c_pwm_board_msgs::msg::Servo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::i2c_pwm_board_msgs::msg::Servo>()
{
  return i2c_pwm_board_msgs::msg::builder::Init_Servo_servo();
}

}  // namespace i2c_pwm_board_msgs

#endif  // I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO__BUILDER_HPP_
