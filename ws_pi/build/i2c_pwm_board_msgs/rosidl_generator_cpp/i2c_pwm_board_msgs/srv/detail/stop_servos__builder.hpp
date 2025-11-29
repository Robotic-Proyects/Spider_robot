// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from i2c_pwm_board_msgs:srv/StopServos.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__SRV__DETAIL__STOP_SERVOS__BUILDER_HPP_
#define I2C_PWM_BOARD_MSGS__SRV__DETAIL__STOP_SERVOS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "i2c_pwm_board_msgs/srv/detail/stop_servos__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace i2c_pwm_board_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::i2c_pwm_board_msgs::srv::StopServos_Request>()
{
  return ::i2c_pwm_board_msgs::srv::StopServos_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace i2c_pwm_board_msgs


namespace i2c_pwm_board_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::i2c_pwm_board_msgs::srv::StopServos_Response>()
{
  return ::i2c_pwm_board_msgs::srv::StopServos_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace i2c_pwm_board_msgs

#endif  // I2C_PWM_BOARD_MSGS__SRV__DETAIL__STOP_SERVOS__BUILDER_HPP_
