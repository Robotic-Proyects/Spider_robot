// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from spider_msgs:srv/ServoCalibrate.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_MSGS__SRV__DETAIL__SERVO_CALIBRATE__TRAITS_HPP_
#define SPIDER_MSGS__SRV__DETAIL__SERVO_CALIBRATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "spider_msgs/srv/detail/servo_calibrate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace spider_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ServoCalibrate_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: channel
  {
    out << "channel: ";
    rosidl_generator_traits::value_to_yaml(msg.channel, out);
    out << ", ";
  }

  // member: pwm
  {
    out << "pwm: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ServoCalibrate_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: channel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "channel: ";
    rosidl_generator_traits::value_to_yaml(msg.channel, out);
    out << "\n";
  }

  // member: pwm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pwm: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ServoCalibrate_Request & msg, bool use_flow_style = false)
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

}  // namespace spider_msgs

namespace rosidl_generator_traits
{

[[deprecated("use spider_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const spider_msgs::srv::ServoCalibrate_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  spider_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spider_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const spider_msgs::srv::ServoCalibrate_Request & msg)
{
  return spider_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<spider_msgs::srv::ServoCalibrate_Request>()
{
  return "spider_msgs::srv::ServoCalibrate_Request";
}

template<>
inline const char * name<spider_msgs::srv::ServoCalibrate_Request>()
{
  return "spider_msgs/srv/ServoCalibrate_Request";
}

template<>
struct has_fixed_size<spider_msgs::srv::ServoCalibrate_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<spider_msgs::srv::ServoCalibrate_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<spider_msgs::srv::ServoCalibrate_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace spider_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ServoCalibrate_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: pwm_value
  {
    out << "pwm_value: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm_value, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ServoCalibrate_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pwm_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pwm_value: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm_value, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ServoCalibrate_Response & msg, bool use_flow_style = false)
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

}  // namespace spider_msgs

namespace rosidl_generator_traits
{

[[deprecated("use spider_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const spider_msgs::srv::ServoCalibrate_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  spider_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spider_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const spider_msgs::srv::ServoCalibrate_Response & msg)
{
  return spider_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<spider_msgs::srv::ServoCalibrate_Response>()
{
  return "spider_msgs::srv::ServoCalibrate_Response";
}

template<>
inline const char * name<spider_msgs::srv::ServoCalibrate_Response>()
{
  return "spider_msgs/srv/ServoCalibrate_Response";
}

template<>
struct has_fixed_size<spider_msgs::srv::ServoCalibrate_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<spider_msgs::srv::ServoCalibrate_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<spider_msgs::srv::ServoCalibrate_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<spider_msgs::srv::ServoCalibrate>()
{
  return "spider_msgs::srv::ServoCalibrate";
}

template<>
inline const char * name<spider_msgs::srv::ServoCalibrate>()
{
  return "spider_msgs/srv/ServoCalibrate";
}

template<>
struct has_fixed_size<spider_msgs::srv::ServoCalibrate>
  : std::integral_constant<
    bool,
    has_fixed_size<spider_msgs::srv::ServoCalibrate_Request>::value &&
    has_fixed_size<spider_msgs::srv::ServoCalibrate_Response>::value
  >
{
};

template<>
struct has_bounded_size<spider_msgs::srv::ServoCalibrate>
  : std::integral_constant<
    bool,
    has_bounded_size<spider_msgs::srv::ServoCalibrate_Request>::value &&
    has_bounded_size<spider_msgs::srv::ServoCalibrate_Response>::value
  >
{
};

template<>
struct is_service<spider_msgs::srv::ServoCalibrate>
  : std::true_type
{
};

template<>
struct is_service_request<spider_msgs::srv::ServoCalibrate_Request>
  : std::true_type
{
};

template<>
struct is_service_response<spider_msgs::srv::ServoCalibrate_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SPIDER_MSGS__SRV__DETAIL__SERVO_CALIBRATE__TRAITS_HPP_
