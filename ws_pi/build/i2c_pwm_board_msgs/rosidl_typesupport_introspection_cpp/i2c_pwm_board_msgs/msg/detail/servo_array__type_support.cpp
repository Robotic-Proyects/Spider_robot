// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from i2c_pwm_board_msgs:msg/ServoArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "i2c_pwm_board_msgs/msg/detail/servo_array__struct.hpp"
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

void ServoArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) i2c_pwm_board_msgs::msg::ServoArray(_init);
}

void ServoArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<i2c_pwm_board_msgs::msg::ServoArray *>(message_memory);
  typed_message->~ServoArray();
}

size_t size_function__ServoArray__servos(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<i2c_pwm_board_msgs::msg::Servo> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ServoArray__servos(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<i2c_pwm_board_msgs::msg::Servo> *>(untyped_member);
  return &member[index];
}

void * get_function__ServoArray__servos(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<i2c_pwm_board_msgs::msg::Servo> *>(untyped_member);
  return &member[index];
}

void fetch_function__ServoArray__servos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const i2c_pwm_board_msgs::msg::Servo *>(
    get_const_function__ServoArray__servos(untyped_member, index));
  auto & value = *reinterpret_cast<i2c_pwm_board_msgs::msg::Servo *>(untyped_value);
  value = item;
}

void assign_function__ServoArray__servos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<i2c_pwm_board_msgs::msg::Servo *>(
    get_function__ServoArray__servos(untyped_member, index));
  const auto & value = *reinterpret_cast<const i2c_pwm_board_msgs::msg::Servo *>(untyped_value);
  item = value;
}

void resize_function__ServoArray__servos(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<i2c_pwm_board_msgs::msg::Servo> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ServoArray_message_member_array[1] = {
  {
    "servos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<i2c_pwm_board_msgs::msg::Servo>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i2c_pwm_board_msgs::msg::ServoArray, servos),  // bytes offset in struct
    nullptr,  // default value
    size_function__ServoArray__servos,  // size() function pointer
    get_const_function__ServoArray__servos,  // get_const(index) function pointer
    get_function__ServoArray__servos,  // get(index) function pointer
    fetch_function__ServoArray__servos,  // fetch(index, &value) function pointer
    assign_function__ServoArray__servos,  // assign(index, value) function pointer
    resize_function__ServoArray__servos  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ServoArray_message_members = {
  "i2c_pwm_board_msgs::msg",  // message namespace
  "ServoArray",  // message name
  1,  // number of fields
  sizeof(i2c_pwm_board_msgs::msg::ServoArray),
  ServoArray_message_member_array,  // message members
  ServoArray_init_function,  // function to initialize message memory (memory has to be allocated)
  ServoArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ServoArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ServoArray_message_members,
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
get_message_type_support_handle<i2c_pwm_board_msgs::msg::ServoArray>()
{
  return &::i2c_pwm_board_msgs::msg::rosidl_typesupport_introspection_cpp::ServoArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, i2c_pwm_board_msgs, msg, ServoArray)() {
  return &::i2c_pwm_board_msgs::msg::rosidl_typesupport_introspection_cpp::ServoArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
