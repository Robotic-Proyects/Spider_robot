// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from i2c_pwm_board_msgs:msg/PositionArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "i2c_pwm_board_msgs/msg/detail/position_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace i2c_pwm_board_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void PositionArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) i2c_pwm_board_msgs::msg::PositionArray(_init);
}

void PositionArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<i2c_pwm_board_msgs::msg::PositionArray *>(message_memory);
  typed_message->~PositionArray();
}

size_t size_function__PositionArray__servos(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<i2c_pwm_board_msgs::msg::Position> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PositionArray__servos(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<i2c_pwm_board_msgs::msg::Position> *>(untyped_member);
  return &member[index];
}

void * get_function__PositionArray__servos(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<i2c_pwm_board_msgs::msg::Position> *>(untyped_member);
  return &member[index];
}

void fetch_function__PositionArray__servos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const i2c_pwm_board_msgs::msg::Position *>(
    get_const_function__PositionArray__servos(untyped_member, index));
  auto & value = *reinterpret_cast<i2c_pwm_board_msgs::msg::Position *>(untyped_value);
  value = item;
}

void assign_function__PositionArray__servos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<i2c_pwm_board_msgs::msg::Position *>(
    get_function__PositionArray__servos(untyped_member, index));
  const auto & value = *reinterpret_cast<const i2c_pwm_board_msgs::msg::Position *>(untyped_value);
  item = value;
}

void resize_function__PositionArray__servos(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<i2c_pwm_board_msgs::msg::Position> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PositionArray_message_member_array[1] = {
  {
    "servos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<i2c_pwm_board_msgs::msg::Position>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i2c_pwm_board_msgs::msg::PositionArray, servos),  // bytes offset in struct
    nullptr,  // default value
    size_function__PositionArray__servos,  // size() function pointer
    get_const_function__PositionArray__servos,  // get_const(index) function pointer
    get_function__PositionArray__servos,  // get(index) function pointer
    fetch_function__PositionArray__servos,  // fetch(index, &value) function pointer
    assign_function__PositionArray__servos,  // assign(index, value) function pointer
    resize_function__PositionArray__servos  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PositionArray_message_members = {
  "i2c_pwm_board_msgs::msg",  // message namespace
  "PositionArray",  // message name
  1,  // number of fields
  sizeof(i2c_pwm_board_msgs::msg::PositionArray),
  PositionArray_message_member_array,  // message members
  PositionArray_init_function,  // function to initialize message memory (memory has to be allocated)
  PositionArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PositionArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PositionArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace i2c_pwm_board_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<i2c_pwm_board_msgs::msg::PositionArray>()
{
  return &::i2c_pwm_board_msgs::msg::rosidl_typesupport_introspection_cpp::PositionArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, i2c_pwm_board_msgs, msg, PositionArray)() {
  return &::i2c_pwm_board_msgs::msg::rosidl_typesupport_introspection_cpp::PositionArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
