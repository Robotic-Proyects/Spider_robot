// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from spider_msgs:msg/SpiderSwitch.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "spider_msgs/msg/detail/spider_switch__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace spider_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SpiderSwitch_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) spider_msgs::msg::SpiderSwitch(_init);
}

void SpiderSwitch_fini_function(void * message_memory)
{
  auto typed_message = static_cast<spider_msgs::msg::SpiderSwitch *>(message_memory);
  typed_message->~SpiderSwitch();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SpiderSwitch_message_member_array[1] = {
  {
    "oe_value",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(spider_msgs::msg::SpiderSwitch, oe_value),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SpiderSwitch_message_members = {
  "spider_msgs::msg",  // message namespace
  "SpiderSwitch",  // message name
  1,  // number of fields
  sizeof(spider_msgs::msg::SpiderSwitch),
  SpiderSwitch_message_member_array,  // message members
  SpiderSwitch_init_function,  // function to initialize message memory (memory has to be allocated)
  SpiderSwitch_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SpiderSwitch_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SpiderSwitch_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace spider_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<spider_msgs::msg::SpiderSwitch>()
{
  return &::spider_msgs::msg::rosidl_typesupport_introspection_cpp::SpiderSwitch_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, spider_msgs, msg, SpiderSwitch)() {
  return &::spider_msgs::msg::rosidl_typesupport_introspection_cpp::SpiderSwitch_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
