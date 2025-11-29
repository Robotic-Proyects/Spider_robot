// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from spider_msgs:msg/SpiderSwitch.idl
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
#include "spider_msgs/msg/detail/spider_switch__struct.h"
#include "spider_msgs/msg/detail/spider_switch__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool spider_msgs__msg__spider_switch__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
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
    assert(strncmp("spider_msgs.msg._spider_switch.SpiderSwitch", full_classname_dest, 43) == 0);
  }
  spider_msgs__msg__SpiderSwitch * ros_message = _ros_message;
  {  // oe_value
    PyObject * field = PyObject_GetAttrString(_pymsg, "oe_value");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->oe_value = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * spider_msgs__msg__spider_switch__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SpiderSwitch */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("spider_msgs.msg._spider_switch");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SpiderSwitch");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  spider_msgs__msg__SpiderSwitch * ros_message = (spider_msgs__msg__SpiderSwitch *)raw_ros_message;
  {  // oe_value
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->oe_value);
    {
      int rc = PyObject_SetAttrString(_pymessage, "oe_value", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
