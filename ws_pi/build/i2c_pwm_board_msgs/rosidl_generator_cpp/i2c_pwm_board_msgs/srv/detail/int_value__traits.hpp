// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from i2c_pwm_board_msgs:srv/IntValue.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__SRV__DETAIL__INT_VALUE__TRAITS_HPP_
#define I2C_PWM_BOARD_MSGS__SRV__DETAIL__INT_VALUE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "i2c_pwm_board_msgs/srv/detail/int_value__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace i2c_pwm_board_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const IntValue_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const IntValue_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const IntValue_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace i2c_pwm_board_msgs

namespace rosidl_generator_traits
{

[[deprecated("use i2c_pwm_board_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const i2c_pwm_board_msgs::srv::IntValue_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  i2c_pwm_board_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i2c_pwm_board_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const i2c_pwm_board_msgs::srv::IntValue_Request & msg)
{
  return i2c_pwm_board_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<i2c_pwm_board_msgs::srv::IntValue_Request>()
{
  return "i2c_pwm_board_msgs::srv::IntValue_Request";
}

template<>
inline const char * name<i2c_pwm_board_msgs::srv::IntValue_Request>()
{
  return "i2c_pwm_board_msgs/srv/IntValue_Request";
}

template<>
struct has_fixed_size<i2c_pwm_board_msgs::srv::IntValue_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<i2c_pwm_board_msgs::srv::IntValue_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<i2c_pwm_board_msgs::srv::IntValue_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace i2c_pwm_board_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const IntValue_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: error
  {
    out << "error: ";
    rosidl_generator_traits::value_to_yaml(msg.error, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const IntValue_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error: ";
    rosidl_generator_traits::value_to_yaml(msg.error, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const IntValue_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace i2c_pwm_board_msgs

namespace rosidl_generator_traits
{

[[deprecated("use i2c_pwm_board_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const i2c_pwm_board_msgs::srv::IntValue_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  i2c_pwm_board_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i2c_pwm_board_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const i2c_pwm_board_msgs::srv::IntValue_Response & msg)
{
  return i2c_pwm_board_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<i2c_pwm_board_msgs::srv::IntValue_Response>()
{
  return "i2c_pwm_board_msgs::srv::IntValue_Response";
}

template<>
inline const char * name<i2c_pwm_board_msgs::srv::IntValue_Response>()
{
  return "i2c_pwm_board_msgs/srv/IntValue_Response";
}

template<>
struct has_fixed_size<i2c_pwm_board_msgs::srv::IntValue_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<i2c_pwm_board_msgs::srv::IntValue_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<i2c_pwm_board_msgs::srv::IntValue_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<i2c_pwm_board_msgs::srv::IntValue>()
{
  return "i2c_pwm_board_msgs::srv::IntValue";
}

template<>
inline const char * name<i2c_pwm_board_msgs::srv::IntValue>()
{
  return "i2c_pwm_board_msgs/srv/IntValue";
}

template<>
struct has_fixed_size<i2c_pwm_board_msgs::srv::IntValue>
  : std::integral_constant<
    bool,
    has_fixed_size<i2c_pwm_board_msgs::srv::IntValue_Request>::value &&
    has_fixed_size<i2c_pwm_board_msgs::srv::IntValue_Response>::value
  >
{
};

template<>
struct has_bounded_size<i2c_pwm_board_msgs::srv::IntValue>
  : std::integral_constant<
    bool,
    has_bounded_size<i2c_pwm_board_msgs::srv::IntValue_Request>::value &&
    has_bounded_size<i2c_pwm_board_msgs::srv::IntValue_Response>::value
  >
{
};

template<>
struct is_service<i2c_pwm_board_msgs::srv::IntValue>
  : std::true_type
{
};

template<>
struct is_service_request<i2c_pwm_board_msgs::srv::IntValue_Request>
  : std::true_type
{
};

template<>
struct is_service_response<i2c_pwm_board_msgs::srv::IntValue_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // I2C_PWM_BOARD_MSGS__SRV__DETAIL__INT_VALUE__TRAITS_HPP_
