// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from i2c_pwm_board_msgs:srv/DriveMode.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "i2c_pwm_board_msgs/srv/detail/drive_mode__struct.h"
#include "i2c_pwm_board_msgs/srv/detail/drive_mode__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "i2c_pwm_board_msgs/msg/detail/position__functions.h"
// end nested array functions include
bool i2c_pwm_board_msgs__msg__position__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * i2c_pwm_board_msgs__msg__position__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool i2c_pwm_board_msgs__srv__drive_mode__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[53];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("i2c_pwm_board_msgs.srv._drive_mode.DriveMode_Request", full_classname_dest, 52) == 0);
  }
  i2c_pwm_board_msgs__srv__DriveMode_Request * ros_message = _ros_message;
  {  // mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->mode, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // rpm
    PyObject * field = PyObject_GetAttrString(_pymsg, "rpm");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rpm = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // radius
    PyObject * field = PyObject_GetAttrString(_pymsg, "radius");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->radius = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // track
    PyObject * field = PyObject_GetAttrString(_pymsg, "track");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->track = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // scale
    PyObject * field = PyObject_GetAttrString(_pymsg, "scale");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->scale = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // servos
    PyObject * field = PyObject_GetAttrString(_pymsg, "servos");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'servos'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!i2c_pwm_board_msgs__msg__Position__Sequence__init(&(ros_message->servos), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create i2c_pwm_board_msgs__msg__Position__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    i2c_pwm_board_msgs__msg__Position * dest = ros_message->servos.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!i2c_pwm_board_msgs__msg__position__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * i2c_pwm_board_msgs__srv__drive_mode__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DriveMode_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("i2c_pwm_board_msgs.srv._drive_mode");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DriveMode_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  i2c_pwm_board_msgs__srv__DriveMode_Request * ros_message = (i2c_pwm_board_msgs__srv__DriveMode_Request *)raw_ros_message;
  {  // mode
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->mode.data,
      strlen(ros_message->mode.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rpm
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rpm);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rpm", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // radius
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->radius);
    {
      int rc = PyObject_SetAttrString(_pymessage, "radius", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // track
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->track);
    {
      int rc = PyObject_SetAttrString(_pymessage, "track", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // scale
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->scale);
    {
      int rc = PyObject_SetAttrString(_pymessage, "scale", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // servos
    PyObject * field = NULL;
    size_t size = ros_message->servos.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    i2c_pwm_board_msgs__msg__Position * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->servos.data[i]);
      PyObject * pyitem = i2c_pwm_board_msgs__msg__position__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "servos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "i2c_pwm_board_msgs/srv/detail/drive_mode__struct.h"
// already included above
// #include "i2c_pwm_board_msgs/srv/detail/drive_mode__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool i2c_pwm_board_msgs__srv__drive_mode__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[54];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("i2c_pwm_board_msgs.srv._drive_mode.DriveMode_Response", full_classname_dest, 53) == 0);
  }
  i2c_pwm_board_msgs__srv__DriveMode_Response * ros_message = _ros_message;
  {  // error
    PyObject * field = PyObject_GetAttrString(_pymsg, "error");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->error = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * i2c_pwm_board_msgs__srv__drive_mode__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DriveMode_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("i2c_pwm_board_msgs.srv._drive_mode");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DriveMode_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  i2c_pwm_board_msgs__srv__DriveMode_Response * ros_message = (i2c_pwm_board_msgs__srv__DriveMode_Response *)raw_ros_message;
  {  // error
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
