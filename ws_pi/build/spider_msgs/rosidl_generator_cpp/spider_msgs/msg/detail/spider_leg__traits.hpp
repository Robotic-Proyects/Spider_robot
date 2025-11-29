// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from spider_msgs:msg/SpiderLeg.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_MSGS__MSG__DETAIL__SPIDER_LEG__TRAITS_HPP_
#define SPIDER_MSGS__MSG__DETAIL__SPIDER_LEG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "spider_msgs/msg/detail/spider_leg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace spider_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SpiderLeg & msg,
  std::ostream & out)
{
  out << "{";
  // member: hip
  {
    out << "hip: ";
    rosidl_generator_traits::value_to_yaml(msg.hip, out);
    out << ", ";
  }

  // member: leg
  {
    out << "leg: ";
    rosidl_generator_traits::value_to_yaml(msg.leg, out);
    out << ", ";
  }

  // member: foot
  {
    out << "foot: ";
    rosidl_generator_traits::value_to_yaml(msg.foot, out);
    out << ", ";
  }

  // member: smooth_value
  {
    out << "smooth_value: ";
    rosidl_generator_traits::value_to_yaml(msg.smooth_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SpiderLeg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: hip
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hip: ";
    rosidl_generator_traits::value_to_yaml(msg.hip, out);
    out << "\n";
  }

  // member: leg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "leg: ";
    rosidl_generator_traits::value_to_yaml(msg.leg, out);
    out << "\n";
  }

  // member: foot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "foot: ";
    rosidl_generator_traits::value_to_yaml(msg.foot, out);
    out << "\n";
  }

  // member: smooth_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "smooth_value: ";
    rosidl_generator_traits::value_to_yaml(msg.smooth_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SpiderLeg & msg, bool use_flow_style = false)
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

}  // namespace spider_msgs

namespace rosidl_generator_traits
{

[[deprecated("use spider_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const spider_msgs::msg::SpiderLeg & msg,
  std::ostream & out, size_t indentation = 0)
{
  spider_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spider_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const spider_msgs::msg::SpiderLeg & msg)
{
  return spider_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<spider_msgs::msg::SpiderLeg>()
{
  return "spider_msgs::msg::SpiderLeg";
}

template<>
inline const char * name<spider_msgs::msg::SpiderLeg>()
{
  return "spider_msgs/msg/SpiderLeg";
}

template<>
struct has_fixed_size<spider_msgs::msg::SpiderLeg>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<spider_msgs::msg::SpiderLeg>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<spider_msgs::msg::SpiderLeg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SPIDER_MSGS__MSG__DETAIL__SPIDER_LEG__TRAITS_HPP_
