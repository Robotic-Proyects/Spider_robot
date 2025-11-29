// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from spider_msgs:msg/SpiderLeg.idl
// generated code does not contain a copyright notice
#include "spider_msgs/msg/detail/spider_leg__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "spider_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "spider_msgs/msg/detail/spider_leg__struct.h"
#include "spider_msgs/msg/detail/spider_leg__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _SpiderLeg__ros_msg_type = spider_msgs__msg__SpiderLeg;

static bool _SpiderLeg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SpiderLeg__ros_msg_type * ros_message = static_cast<const _SpiderLeg__ros_msg_type *>(untyped_ros_message);
  // Field name: hip
  {
    cdr << ros_message->hip;
  }

  // Field name: leg
  {
    cdr << ros_message->leg;
  }

  // Field name: foot
  {
    cdr << ros_message->foot;
  }

  // Field name: smooth_value
  {
    cdr << ros_message->smooth_value;
  }

  return true;
}

static bool _SpiderLeg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SpiderLeg__ros_msg_type * ros_message = static_cast<_SpiderLeg__ros_msg_type *>(untyped_ros_message);
  // Field name: hip
  {
    cdr >> ros_message->hip;
  }

  // Field name: leg
  {
    cdr >> ros_message->leg;
  }

  // Field name: foot
  {
    cdr >> ros_message->foot;
  }

  // Field name: smooth_value
  {
    cdr >> ros_message->smooth_value;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_spider_msgs
size_t get_serialized_size_spider_msgs__msg__SpiderLeg(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SpiderLeg__ros_msg_type * ros_message = static_cast<const _SpiderLeg__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name hip
  {
    size_t item_size = sizeof(ros_message->hip);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg
  {
    size_t item_size = sizeof(ros_message->leg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name foot
  {
    size_t item_size = sizeof(ros_message->foot);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name smooth_value
  {
    size_t item_size = sizeof(ros_message->smooth_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SpiderLeg__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_spider_msgs__msg__SpiderLeg(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_spider_msgs
size_t max_serialized_size_spider_msgs__msg__SpiderLeg(
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

  // member: hip
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leg
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: foot
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: smooth_value
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
    using DataType = spider_msgs__msg__SpiderLeg;
    is_plain =
      (
      offsetof(DataType, smooth_value) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SpiderLeg__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_spider_msgs__msg__SpiderLeg(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SpiderLeg = {
  "spider_msgs::msg",
  "SpiderLeg",
  _SpiderLeg__cdr_serialize,
  _SpiderLeg__cdr_deserialize,
  _SpiderLeg__get_serialized_size,
  _SpiderLeg__max_serialized_size
};

static rosidl_message_type_support_t _SpiderLeg__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SpiderLeg,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, spider_msgs, msg, SpiderLeg)() {
  return &_SpiderLeg__type_support;
}

#if defined(__cplusplus)
}
#endif
