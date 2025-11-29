// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from i2c_pwm_board_msgs:msg/ServoConfig.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG__TRAITS_HPP_
#define I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "i2c_pwm_board_msgs/msg/detail/servo_config__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace i2c_pwm_board_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ServoConfig & msg,
  std::ostream & out)
{
  out << "{";
  // member: servo
  {
    out << "servo: ";
    rosidl_generator_traits::value_to_yaml(msg.servo, out);
    out << ", ";
  }

  // member: center
  {
    out << "center: ";
    rosidl_generator_traits::value_to_yaml(msg.center, out);
    out << ", ";
  }

  // member: range
  {
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
    out << ", ";
  }

  // member: direction
  {
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ServoConfig & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: servo
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "servo: ";
    rosidl_generator_traits::value_to_yaml(msg.servo, out);
    out << "\n";
  }

  // member: center
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center: ";
    rosidl_generator_traits::value_to_yaml(msg.center, out);
    out << "\n";
  }

  // member: range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
    out << "\n";
  }

  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ServoConfig & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace i2c_pwm_board_msgs

namespace rosidl_generator_traits
{

[[deprecated("use i2c_pwm_board_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const i2c_pwm_board_msgs::msg::ServoConfig & msg,
  std::ostream & out, size_t indentation = 0)
{
  i2c_pwm_board_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i2c_pwm_board_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const i2c_pwm_board_msgs::msg::ServoConfig & msg)
{
  return i2c_pwm_board_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<i2c_pwm_board_msgs::msg::ServoConfig>()
{
  return "i2c_pwm_board_msgs::msg::ServoConfig";
}

template<>
inline const char * name<i2c_pwm_board_msgs::msg::ServoConfig>()
{
  return "i2c_pwm_board_msgs/msg/ServoConfig";
}

template<>
struct has_fixed_size<i2c_pwm_board_msgs::msg::ServoConfig>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<i2c_pwm_board_msgs::msg::ServoConfig>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<i2c_pwm_board_msgs::msg::ServoConfig>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // I2C_PWM_BOARD_MSGS__MSG__DETAIL__SERVO_CONFIG__TRAITS_HPP_
