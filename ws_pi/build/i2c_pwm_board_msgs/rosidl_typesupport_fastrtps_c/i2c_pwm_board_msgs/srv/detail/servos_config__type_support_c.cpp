// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from i2c_pwm_board_msgs:srv/ServosConfig.idl
// generated code does not contain a copyright notice
#include "i2c_pwm_board_msgs/srv/detail/servos_config__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "i2c_pwm_board_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "i2c_pwm_board_msgs/srv/detail/servos_config__struct.h"
#include "i2c_pwm_board_msgs/srv/detail/servos_config__functions.h"
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

#include "i2c_pwm_board_msgs/msg/detail/servo_config__functions.h"  // servos

// forward declare type support functions
size_t get_serialized_size_i2c_pwm_board_msgs__msg__ServoConfig(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_i2c_pwm_board_msgs__msg__ServoConfig(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i2c_pwm_board_msgs, msg, ServoConfig)();


using _ServosConfig_Request__ros_msg_type = i2c_pwm_board_msgs__srv__ServosConfig_Request;

static bool _ServosConfig_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ServosConfig_Request__ros_msg_type * ros_message = static_cast<const _ServosConfig_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: servos
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, i2c_pwm_board_msgs, msg, ServoConfig
      )()->data);
    size_t size = ros_message->servos.size;
    auto array_ptr = ros_message->servos.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _ServosConfig_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ServosConfig_Request__ros_msg_type * ros_message = static_cast<_ServosConfig_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: servos
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, i2c_pwm_board_msgs, msg, ServoConfig
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->servos.data) {
      i2c_pwm_board_msgs__msg__ServoConfig__Sequence__fini(&ros_message->servos);
    }
    if (!i2c_pwm_board_msgs__msg__ServoConfig__Sequence__init(&ros_message->servos, size)) {
      fprintf(stderr, "failed to create array for field 'servos'");
      return false;
    }
    auto array_ptr = ros_message->servos.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_i2c_pwm_board_msgs
size_t get_serialized_size_i2c_pwm_board_msgs__srv__ServosConfig_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ServosConfig_Request__ros_msg_type * ros_message = static_cast<const _ServosConfig_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name servos
  {
    size_t array_size = ros_message->servos.size;
    auto array_ptr = ros_message->servos.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_i2c_pwm_board_msgs__msg__ServoConfig(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ServosConfig_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_i2c_pwm_board_msgs__srv__ServosConfig_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_i2c_pwm_board_msgs
size_t max_serialized_size_i2c_pwm_board_msgs__srv__ServosConfig_Request(
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

  // member: servos
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_i2c_pwm_board_msgs__msg__ServoConfig(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = i2c_pwm_board_msgs__srv__ServosConfig_Request;
    is_plain =
      (
      offsetof(DataType, servos) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ServosConfig_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_i2c_pwm_board_msgs__srv__ServosConfig_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ServosConfig_Request = {
  "i2c_pwm_board_msgs::srv",
  "ServosConfig_Request",
  _ServosConfig_Request__cdr_serialize,
  _ServosConfig_Request__cdr_deserialize,
  _ServosConfig_Request__get_serialized_size,
  _ServosConfig_Request__max_serialized_size
};

static rosidl_message_type_support_t _ServosConfig_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ServosConfig_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i2c_pwm_board_msgs, srv, ServosConfig_Request)() {
  return &_ServosConfig_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "i2c_pwm_board_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "i2c_pwm_board_msgs/srv/detail/servos_config__struct.h"
// already included above
// #include "i2c_pwm_board_msgs/srv/detail/servos_config__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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


using _ServosConfig_Response__ros_msg_type = i2c_pwm_board_msgs__srv__ServosConfig_Response;

static bool _ServosConfig_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ServosConfig_Response__ros_msg_type * ros_message = static_cast<const _ServosConfig_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: error
  {
    cdr << ros_message->error;
  }

  return true;
}

static bool _ServosConfig_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ServosConfig_Response__ros_msg_type * ros_message = static_cast<_ServosConfig_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: error
  {
    cdr >> ros_message->error;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_i2c_pwm_board_msgs
size_t get_serialized_size_i2c_pwm_board_msgs__srv__ServosConfig_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ServosConfig_Response__ros_msg_type * ros_message = static_cast<const _ServosConfig_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name error
  {
    size_t item_size = sizeof(ros_message->error);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ServosConfig_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_i2c_pwm_board_msgs__srv__ServosConfig_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_i2c_pwm_board_msgs
size_t max_serialized_size_i2c_pwm_board_msgs__srv__ServosConfig_Response(
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

  // member: error
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = i2c_pwm_board_msgs__srv__ServosConfig_Response;
    is_plain =
      (
      offsetof(DataType, error) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ServosConfig_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_i2c_pwm_board_msgs__srv__ServosConfig_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ServosConfig_Response = {
  "i2c_pwm_board_msgs::srv",
  "ServosConfig_Response",
  _ServosConfig_Response__cdr_serialize,
  _ServosConfig_Response__cdr_deserialize,
  _ServosConfig_Response__get_serialized_size,
  _ServosConfig_Response__max_serialized_size
};

static rosidl_message_type_support_t _ServosConfig_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ServosConfig_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i2c_pwm_board_msgs, srv, ServosConfig_Response)() {
  return &_ServosConfig_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "i2c_pwm_board_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "i2c_pwm_board_msgs/srv/servos_config.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ServosConfig__callbacks = {
  "i2c_pwm_board_msgs::srv",
  "ServosConfig",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i2c_pwm_board_msgs, srv, ServosConfig_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i2c_pwm_board_msgs, srv, ServosConfig_Response)(),
};

static rosidl_service_type_support_t ServosConfig__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &ServosConfig__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i2c_pwm_board_msgs, srv, ServosConfig)() {
  return &ServosConfig__handle;
}

#if defined(__cplusplus)
}
#endif
