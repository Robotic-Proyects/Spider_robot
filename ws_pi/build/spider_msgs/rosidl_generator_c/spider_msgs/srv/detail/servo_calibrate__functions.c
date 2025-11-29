// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from spider_msgs:srv/ServoCalibrate.idl
// generated code does not contain a copyright notice
#include "spider_msgs/srv/detail/servo_calibrate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
spider_msgs__srv__ServoCalibrate_Request__init(spider_msgs__srv__ServoCalibrate_Request * msg)
{
  if (!msg) {
    return false;
  }
  // channel
  // pwm
  return true;
}

void
spider_msgs__srv__ServoCalibrate_Request__fini(spider_msgs__srv__ServoCalibrate_Request * msg)
{
  if (!msg) {
    return;
  }
  // channel
  // pwm
}

bool
spider_msgs__srv__ServoCalibrate_Request__are_equal(const spider_msgs__srv__ServoCalibrate_Request * lhs, const spider_msgs__srv__ServoCalibrate_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // channel
  if (lhs->channel != rhs->channel) {
    return false;
  }
  // pwm
  if (lhs->pwm != rhs->pwm) {
    return false;
  }
  return true;
}

bool
spider_msgs__srv__ServoCalibrate_Request__copy(
  const spider_msgs__srv__ServoCalibrate_Request * input,
  spider_msgs__srv__ServoCalibrate_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // channel
  output->channel = input->channel;
  // pwm
  output->pwm = input->pwm;
  return true;
}

spider_msgs__srv__ServoCalibrate_Request *
spider_msgs__srv__ServoCalibrate_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__srv__ServoCalibrate_Request * msg = (spider_msgs__srv__ServoCalibrate_Request *)allocator.allocate(sizeof(spider_msgs__srv__ServoCalibrate_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(spider_msgs__srv__ServoCalibrate_Request));
  bool success = spider_msgs__srv__ServoCalibrate_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
spider_msgs__srv__ServoCalibrate_Request__destroy(spider_msgs__srv__ServoCalibrate_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    spider_msgs__srv__ServoCalibrate_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
spider_msgs__srv__ServoCalibrate_Request__Sequence__init(spider_msgs__srv__ServoCalibrate_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__srv__ServoCalibrate_Request * data = NULL;

  if (size) {
    data = (spider_msgs__srv__ServoCalibrate_Request *)allocator.zero_allocate(size, sizeof(spider_msgs__srv__ServoCalibrate_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = spider_msgs__srv__ServoCalibrate_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        spider_msgs__srv__ServoCalibrate_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
spider_msgs__srv__ServoCalibrate_Request__Sequence__fini(spider_msgs__srv__ServoCalibrate_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      spider_msgs__srv__ServoCalibrate_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

spider_msgs__srv__ServoCalibrate_Request__Sequence *
spider_msgs__srv__ServoCalibrate_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__srv__ServoCalibrate_Request__Sequence * array = (spider_msgs__srv__ServoCalibrate_Request__Sequence *)allocator.allocate(sizeof(spider_msgs__srv__ServoCalibrate_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = spider_msgs__srv__ServoCalibrate_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
spider_msgs__srv__ServoCalibrate_Request__Sequence__destroy(spider_msgs__srv__ServoCalibrate_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    spider_msgs__srv__ServoCalibrate_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
spider_msgs__srv__ServoCalibrate_Request__Sequence__are_equal(const spider_msgs__srv__ServoCalibrate_Request__Sequence * lhs, const spider_msgs__srv__ServoCalibrate_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!spider_msgs__srv__ServoCalibrate_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
spider_msgs__srv__ServoCalibrate_Request__Sequence__copy(
  const spider_msgs__srv__ServoCalibrate_Request__Sequence * input,
  spider_msgs__srv__ServoCalibrate_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(spider_msgs__srv__ServoCalibrate_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    spider_msgs__srv__ServoCalibrate_Request * data =
      (spider_msgs__srv__ServoCalibrate_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!spider_msgs__srv__ServoCalibrate_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          spider_msgs__srv__ServoCalibrate_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!spider_msgs__srv__ServoCalibrate_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `status`
#include "rosidl_runtime_c/string_functions.h"

bool
spider_msgs__srv__ServoCalibrate_Response__init(spider_msgs__srv__ServoCalibrate_Response * msg)
{
  if (!msg) {
    return false;
  }
  // pwm_value
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    spider_msgs__srv__ServoCalibrate_Response__fini(msg);
    return false;
  }
  return true;
}

void
spider_msgs__srv__ServoCalibrate_Response__fini(spider_msgs__srv__ServoCalibrate_Response * msg)
{
  if (!msg) {
    return;
  }
  // pwm_value
  // status
  rosidl_runtime_c__String__fini(&msg->status);
}

bool
spider_msgs__srv__ServoCalibrate_Response__are_equal(const spider_msgs__srv__ServoCalibrate_Response * lhs, const spider_msgs__srv__ServoCalibrate_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pwm_value
  if (lhs->pwm_value != rhs->pwm_value) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  return true;
}

bool
spider_msgs__srv__ServoCalibrate_Response__copy(
  const spider_msgs__srv__ServoCalibrate_Response * input,
  spider_msgs__srv__ServoCalibrate_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // pwm_value
  output->pwm_value = input->pwm_value;
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  return true;
}

spider_msgs__srv__ServoCalibrate_Response *
spider_msgs__srv__ServoCalibrate_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__srv__ServoCalibrate_Response * msg = (spider_msgs__srv__ServoCalibrate_Response *)allocator.allocate(sizeof(spider_msgs__srv__ServoCalibrate_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(spider_msgs__srv__ServoCalibrate_Response));
  bool success = spider_msgs__srv__ServoCalibrate_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
spider_msgs__srv__ServoCalibrate_Response__destroy(spider_msgs__srv__ServoCalibrate_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    spider_msgs__srv__ServoCalibrate_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
spider_msgs__srv__ServoCalibrate_Response__Sequence__init(spider_msgs__srv__ServoCalibrate_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__srv__ServoCalibrate_Response * data = NULL;

  if (size) {
    data = (spider_msgs__srv__ServoCalibrate_Response *)allocator.zero_allocate(size, sizeof(spider_msgs__srv__ServoCalibrate_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = spider_msgs__srv__ServoCalibrate_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        spider_msgs__srv__ServoCalibrate_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
spider_msgs__srv__ServoCalibrate_Response__Sequence__fini(spider_msgs__srv__ServoCalibrate_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      spider_msgs__srv__ServoCalibrate_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

spider_msgs__srv__ServoCalibrate_Response__Sequence *
spider_msgs__srv__ServoCalibrate_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__srv__ServoCalibrate_Response__Sequence * array = (spider_msgs__srv__ServoCalibrate_Response__Sequence *)allocator.allocate(sizeof(spider_msgs__srv__ServoCalibrate_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = spider_msgs__srv__ServoCalibrate_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
spider_msgs__srv__ServoCalibrate_Response__Sequence__destroy(spider_msgs__srv__ServoCalibrate_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    spider_msgs__srv__ServoCalibrate_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
spider_msgs__srv__ServoCalibrate_Response__Sequence__are_equal(const spider_msgs__srv__ServoCalibrate_Response__Sequence * lhs, const spider_msgs__srv__ServoCalibrate_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!spider_msgs__srv__ServoCalibrate_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
spider_msgs__srv__ServoCalibrate_Response__Sequence__copy(
  const spider_msgs__srv__ServoCalibrate_Response__Sequence * input,
  spider_msgs__srv__ServoCalibrate_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(spider_msgs__srv__ServoCalibrate_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    spider_msgs__srv__ServoCalibrate_Response * data =
      (spider_msgs__srv__ServoCalibrate_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!spider_msgs__srv__ServoCalibrate_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          spider_msgs__srv__ServoCalibrate_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!spider_msgs__srv__ServoCalibrate_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
