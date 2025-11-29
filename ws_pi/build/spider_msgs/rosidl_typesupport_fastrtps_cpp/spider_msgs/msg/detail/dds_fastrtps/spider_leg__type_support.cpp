// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from spider_msgs:msg/SpiderLeg.idl
// generated code does not contain a copyright notice
#include "spider_msgs/msg/detail/spider_leg__rosidl_typesupport_fastrtps_cpp.hpp"
#include "spider_msgs/msg/detail/spider_leg__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace spider_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_spider_msgs
cdr_serialize(
  const spider_msgs::msg::SpiderLeg & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: hip
  cdr << ros_message.hip;
  // Member: leg
  cdr << ros_message.leg;
  // Member: foot
  cdr << ros_message.foot;
  // Member: smooth_value
  cdr << ros_message.smooth_value;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_spider_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  spider_msgs::msg::SpiderLeg & ros_message)
{
  // Member: hip
  cdr >> ros_message.hip;

  // Member: leg
  cdr >> ros_message.leg;

  // Member: foot
  cdr >> ros_message.foot;

  // Member: smooth_value
  cdr >> ros_message.smooth_value;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_spider_msgs
get_serialized_size(
  const spider_msgs::msg::SpiderLeg & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: hip
  {
    size_t item_size = sizeof(ros_message.hip);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: leg
  {
    size_t item_size = sizeof(ros_message.leg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: foot
  {
    size_t item_size = sizeof(ros_message.foot);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: smooth_value
  {
    size_t item_size = sizeof(ros_message.smooth_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_spider_msgs
max_serialized_size_SpiderLeg(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: hip
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: leg
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: foot
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: smooth_value
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = spider_msgs::msg::SpiderLeg;
    is_plain =
      (
      offsetof(DataType, smooth_value) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SpiderLeg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const spider_msgs::msg::SpiderLeg *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SpiderLeg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<spider_msgs::msg::SpiderLeg *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SpiderLeg__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const spider_msgs::msg::SpiderLeg *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SpiderLeg__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SpiderLeg(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SpiderLeg__callbacks = {
  "spider_msgs::msg",
  "SpiderLeg",
  _SpiderLeg__cdr_serialize,
  _SpiderLeg__cdr_deserialize,
  _SpiderLeg__get_serialized_size,
  _SpiderLeg__max_serialized_size
};

static rosidl_message_type_support_t _SpiderLeg__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SpiderLeg__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace spider_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_spider_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<spider_msgs::msg::SpiderLeg>()
{
  return &spider_msgs::msg::typesupport_fastrtps_cpp::_SpiderLeg__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, spider_msgs, msg, SpiderLeg)() {
  return &spider_msgs::msg::typesupport_fastrtps_cpp::_SpiderLeg__handle;
}

#ifdef __cplusplus
}
#endif
