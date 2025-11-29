// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from spider_msgs:msg/SpiderSwitch.idl
// generated code does not contain a copyright notice
#include "spider_msgs/msg/detail/spider_switch__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
spider_msgs__msg__SpiderSwitch__init(spider_msgs__msg__SpiderSwitch * msg)
{
  if (!msg) {
    return false;
  }
  // oe_value
  return true;
}

void
spider_msgs__msg__SpiderSwitch__fini(spider_msgs__msg__SpiderSwitch * msg)
{
  if (!msg) {
    return;
  }
  // oe_value
}

bool
spider_msgs__msg__SpiderSwitch__are_equal(const spider_msgs__msg__SpiderSwitch * lhs, const spider_msgs__msg__SpiderSwitch * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // oe_value
  if (lhs->oe_value != rhs->oe_value) {
    return false;
  }
  return true;
}

bool
spider_msgs__msg__SpiderSwitch__copy(
  const spider_msgs__msg__SpiderSwitch * input,
  spider_msgs__msg__SpiderSwitch * output)
{
  if (!input || !output) {
    return false;
  }
  // oe_value
  output->oe_value = input->oe_value;
  return true;
}

spider_msgs__msg__SpiderSwitch *
spider_msgs__msg__SpiderSwitch__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__msg__SpiderSwitch * msg = (spider_msgs__msg__SpiderSwitch *)allocator.allocate(sizeof(spider_msgs__msg__SpiderSwitch), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(spider_msgs__msg__SpiderSwitch));
  bool success = spider_msgs__msg__SpiderSwitch__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
spider_msgs__msg__SpiderSwitch__destroy(spider_msgs__msg__SpiderSwitch * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    spider_msgs__msg__SpiderSwitch__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
spider_msgs__msg__SpiderSwitch__Sequence__init(spider_msgs__msg__SpiderSwitch__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__msg__SpiderSwitch * data = NULL;

  if (size) {
    data = (spider_msgs__msg__SpiderSwitch *)allocator.zero_allocate(size, sizeof(spider_msgs__msg__SpiderSwitch), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = spider_msgs__msg__SpiderSwitch__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        spider_msgs__msg__SpiderSwitch__fini(&data[i - 1]);
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
spider_msgs__msg__SpiderSwitch__Sequence__fini(spider_msgs__msg__SpiderSwitch__Sequence * array)
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
      spider_msgs__msg__SpiderSwitch__fini(&array->data[i]);
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

spider_msgs__msg__SpiderSwitch__Sequence *
spider_msgs__msg__SpiderSwitch__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spider_msgs__msg__SpiderSwitch__Sequence * array = (spider_msgs__msg__SpiderSwitch__Sequence *)allocator.allocate(sizeof(spider_msgs__msg__SpiderSwitch__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = spider_msgs__msg__SpiderSwitch__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
spider_msgs__msg__SpiderSwitch__Sequence__destroy(spider_msgs__msg__SpiderSwitch__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    spider_msgs__msg__SpiderSwitch__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
spider_msgs__msg__SpiderSwitch__Sequence__are_equal(const spider_msgs__msg__SpiderSwitch__Sequence * lhs, const spider_msgs__msg__SpiderSwitch__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!spider_msgs__msg__SpiderSwitch__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
spider_msgs__msg__SpiderSwitch__Sequence__copy(
  const spider_msgs__msg__SpiderSwitch__Sequence * input,
  spider_msgs__msg__SpiderSwitch__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(spider_msgs__msg__SpiderSwitch);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    spider_msgs__msg__SpiderSwitch * data =
      (spider_msgs__msg__SpiderSwitch *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!spider_msgs__msg__SpiderSwitch__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          spider_msgs__msg__SpiderSwitch__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!spider_msgs__msg__SpiderSwitch__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
