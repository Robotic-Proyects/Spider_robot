// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from spider_msgs:msg/SpiderSwitch.idl
// generated code does not contain a copyright notice

#ifndef SPIDER_MSGS__MSG__DETAIL__SPIDER_SWITCH__TRAITS_HPP_
#define SPIDER_MSGS__MSG__DETAIL__SPIDER_SWITCH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "spider_msgs/msg/detail/spider_switch__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace spider_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SpiderSwitch & msg,
  std::ostream & out)
{
  out << "{";
  // member: oe_value
  {
    out << "oe_value: ";
    rosidl_generator_traits::value_to_yaml(msg.oe_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SpiderSwitch & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: oe_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "oe_value: ";
    rosidl_generator_traits::value_to_yaml(msg.oe_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SpiderSwitch & msg, bool use_flow_style = false)
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
  const spider_msgs::msg::SpiderSwitch & msg,
  std::ostream & out, size_t indentation = 0)
{
  spider_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spider_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const spider_msgs::msg::SpiderSwitch & msg)
{
  return spider_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<spider_msgs::msg::SpiderSwitch>()
{
  return "spider_msgs::msg::SpiderSwitch";
}

template<>
inline const char * name<spider_msgs::msg::SpiderSwitch>()
{
  return "spider_msgs/msg/SpiderSwitch";
}

template<>
struct has_fixed_size<spider_msgs::msg::SpiderSwitch>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<spider_msgs::msg::SpiderSwitch>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<spider_msgs::msg::SpiderSwitch>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SPIDER_MSGS__MSG__DETAIL__SPIDER_SWITCH__TRAITS_HPP_
