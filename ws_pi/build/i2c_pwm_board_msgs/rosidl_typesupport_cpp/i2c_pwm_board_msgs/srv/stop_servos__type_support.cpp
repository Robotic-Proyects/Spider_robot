// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from i2c_pwm_board_msgs:srv/StopServos.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "i2c_pwm_board_msgs/srv/detail/stop_servos__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace i2c_pwm_board_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _StopServos_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StopServos_Request_type_support_ids_t;

static const _StopServos_Request_type_support_ids_t _StopServos_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _StopServos_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StopServos_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StopServos_Request_type_support_symbol_names_t _StopServos_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, i2c_pwm_board_msgs, srv, StopServos_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, i2c_pwm_board_msgs, srv, StopServos_Request)),
  }
};

typedef struct _StopServos_Request_type_support_data_t
{
  void * data[2];
} _StopServos_Request_type_support_data_t;

static _StopServos_Request_type_support_data_t _StopServos_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StopServos_Request_message_typesupport_map = {
  2,
  "i2c_pwm_board_msgs",
  &_StopServos_Request_message_typesupport_ids.typesupport_identifier[0],
  &_StopServos_Request_message_typesupport_symbol_names.symbol_name[0],
  &_StopServos_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StopServos_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StopServos_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace i2c_pwm_board_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<i2c_pwm_board_msgs::srv::StopServos_Request>()
{
  return &::i2c_pwm_board_msgs::srv::rosidl_typesupport_cpp::StopServos_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, i2c_pwm_board_msgs, srv, StopServos_Request)() {
  return get_message_type_support_handle<i2c_pwm_board_msgs::srv::StopServos_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "i2c_pwm_board_msgs/srv/detail/stop_servos__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace i2c_pwm_board_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _StopServos_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StopServos_Response_type_support_ids_t;

static const _StopServos_Response_type_support_ids_t _StopServos_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _StopServos_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StopServos_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StopServos_Response_type_support_symbol_names_t _StopServos_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, i2c_pwm_board_msgs, srv, StopServos_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, i2c_pwm_board_msgs, srv, StopServos_Response)),
  }
};

typedef struct _StopServos_Response_type_support_data_t
{
  void * data[2];
} _StopServos_Response_type_support_data_t;

static _StopServos_Response_type_support_data_t _StopServos_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StopServos_Response_message_typesupport_map = {
  2,
  "i2c_pwm_board_msgs",
  &_StopServos_Response_message_typesupport_ids.typesupport_identifier[0],
  &_StopServos_Response_message_typesupport_symbol_names.symbol_name[0],
  &_StopServos_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StopServos_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StopServos_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace i2c_pwm_board_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<i2c_pwm_board_msgs::srv::StopServos_Response>()
{
  return &::i2c_pwm_board_msgs::srv::rosidl_typesupport_cpp::StopServos_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, i2c_pwm_board_msgs, srv, StopServos_Response)() {
  return get_message_type_support_handle<i2c_pwm_board_msgs::srv::StopServos_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "i2c_pwm_board_msgs/srv/detail/stop_servos__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace i2c_pwm_board_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _StopServos_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StopServos_type_support_ids_t;

static const _StopServos_type_support_ids_t _StopServos_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _StopServos_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StopServos_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StopServos_type_support_symbol_names_t _StopServos_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, i2c_pwm_board_msgs, srv, StopServos)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, i2c_pwm_board_msgs, srv, StopServos)),
  }
};

typedef struct _StopServos_type_support_data_t
{
  void * data[2];
} _StopServos_type_support_data_t;

static _StopServos_type_support_data_t _StopServos_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StopServos_service_typesupport_map = {
  2,
  "i2c_pwm_board_msgs",
  &_StopServos_service_typesupport_ids.typesupport_identifier[0],
  &_StopServos_service_typesupport_symbol_names.symbol_name[0],
  &_StopServos_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t StopServos_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StopServos_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace i2c_pwm_board_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<i2c_pwm_board_msgs::srv::StopServos>()
{
  return &::i2c_pwm_board_msgs::srv::rosidl_typesupport_cpp::StopServos_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, i2c_pwm_board_msgs, srv, StopServos)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<i2c_pwm_board_msgs::srv::StopServos>();
}

#ifdef __cplusplus
}
#endif
