// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from i2c_pwm_board_msgs:msg/PositionArray.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__MSG__DETAIL__POSITION_ARRAY__BUILDER_HPP_
#define I2C_PWM_BOARD_MSGS__MSG__DETAIL__POSITION_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "i2c_pwm_board_msgs/msg/detail/position_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace i2c_pwm_board_msgs
{

namespace msg
{

namespace builder
{

class Init_PositionArray_servos
{
public:
  Init_PositionArray_servos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::i2c_pwm_board_msgs::msg::PositionArray servos(::i2c_pwm_board_msgs::msg::PositionArray::_servos_type arg)
  {
    msg_.servos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i2c_pwm_board_msgs::msg::PositionArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::i2c_pwm_board_msgs::msg::PositionArray>()
{
  return i2c_pwm_board_msgs::msg::builder::Init_PositionArray_servos();
}

}  // namespace i2c_pwm_board_msgs

#endif  // I2C_PWM_BOARD_MSGS__MSG__DETAIL__POSITION_ARRAY__BUILDER_HPP_
