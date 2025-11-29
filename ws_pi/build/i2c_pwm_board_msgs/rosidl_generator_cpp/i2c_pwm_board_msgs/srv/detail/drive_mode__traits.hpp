// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from i2c_pwm_board_msgs:srv/DriveMode.idl
// generated code does not contain a copyright notice

#ifndef I2C_PWM_BOARD_MSGS__SRV__DETAIL__DRIVE_MODE__TRAITS_HPP_
#define I2C_PWM_BOARD_MSGS__SRV__DETAIL__DRIVE_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "i2c_pwm_board_msgs/srv/detail/drive_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'servos'
#include "i2c_pwm_board_msgs/msg/detail/position__traits.hpp"

namespace i2c_pwm_board_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const DriveMode_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: rpm
  {
    out << "rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.rpm, out);
    out << ", ";
  }

  // member: radius
  {
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
    out << ", ";
  }

  // member: track
  {
    out << "track: ";
    rosidl_generator_traits::value_to_yaml(msg.track, out);
    out << ", ";
  }

  // member: scale
  {
    out << "scale: ";
    rosidl_generator_traits::value_to_yaml(msg.scale, out);
    out << ", ";
  }

  // member: servos
  {
    if (msg.servos.size() == 0) {
      out << "servos: []";
    } else {
      out << "servos: [";
      size_t pending_items = msg.servos.size();
      for (auto item : msg.servos) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DriveMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: rpm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.rpm, out);
    out << "\n";
  }

  // member: radius
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
    out << "\n";
  }

  // member: track
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "track: ";
    rosidl_generator_traits::value_to_yaml(msg.track, out);
    out << "\n";
  }

  // member: scale
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "scale: ";
    rosidl_generator_traits::value_to_yaml(msg.scale, out);
    out << "\n";
  }

  // member: servos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.servos.size() == 0) {
      out << "servos: []\n";
    } else {
      out << "servos:\n";
      for (auto item : msg.servos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DriveMode_Request & msg, bool use_flow_style = false)
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
  const i2c_pwm_board_msgs::srv::DriveMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  i2c_pwm_board_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i2c_pwm_board_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const i2c_pwm_board_msgs::srv::DriveMode_Request & msg)
{
  return i2c_pwm_board_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<i2c_pwm_board_msgs::srv::DriveMode_Request>()
{
  return "i2c_pwm_board_msgs::srv::DriveMode_Request";
}

template<>
inline const char * name<i2c_pwm_board_msgs::srv::DriveMode_Request>()
{
  return "i2c_pwm_board_msgs/srv/DriveMode_Request";
}

template<>
struct has_fixed_size<i2c_pwm_board_msgs::srv::DriveMode_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<i2c_pwm_board_msgs::srv::DriveMode_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<i2c_pwm_board_msgs::srv::DriveMode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace i2c_pwm_board_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const DriveMode_Response & msg,
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
  const DriveMode_Response & msg,
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

inline std::string to_yaml(const DriveMode_Response & msg, bool use_flow_style = false)
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
  const i2c_pwm_board_msgs::srv::DriveMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  i2c_pwm_board_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i2c_pwm_board_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const i2c_pwm_board_msgs::srv::DriveMode_Response & msg)
{
  return i2c_pwm_board_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<i2c_pwm_board_msgs::srv::DriveMode_Response>()
{
  return "i2c_pwm_board_msgs::srv::DriveMode_Response";
}

template<>
inline const char * name<i2c_pwm_board_msgs::srv::DriveMode_Response>()
{
  return "i2c_pwm_board_msgs/srv/DriveMode_Response";
}

template<>
struct has_fixed_size<i2c_pwm_board_msgs::srv::DriveMode_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<i2c_pwm_board_msgs::srv::DriveMode_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<i2c_pwm_board_msgs::srv::DriveMode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<i2c_pwm_board_msgs::srv::DriveMode>()
{
  return "i2c_pwm_board_msgs::srv::DriveMode";
}

template<>
inline const char * name<i2c_pwm_board_msgs::srv::DriveMode>()
{
  return "i2c_pwm_board_msgs/srv/DriveMode";
}

template<>
struct has_fixed_size<i2c_pwm_board_msgs::srv::DriveMode>
  : std::integral_constant<
    bool,
    has_fixed_size<i2c_pwm_board_msgs::srv::DriveMode_Request>::value &&
    has_fixed_size<i2c_pwm_board_msgs::srv::DriveMode_Response>::value
  >
{
};

template<>
struct has_bounded_size<i2c_pwm_board_msgs::srv::DriveMode>
  : std::integral_constant<
    bool,
    has_bounded_size<i2c_pwm_board_msgs::srv::DriveMode_Request>::value &&
    has_bounded_size<i2c_pwm_board_msgs::srv::DriveMode_Response>::value
  >
{
};

template<>
struct is_service<i2c_pwm_board_msgs::srv::DriveMode>
  : std::true_type
{
};

template<>
struct is_service_request<i2c_pwm_board_msgs::srv::DriveMode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<i2c_pwm_board_msgs::srv::DriveMode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // I2C_PWM_BOARD_MSGS__SRV__DETAIL__DRIVE_MODE__TRAITS_HPP_
