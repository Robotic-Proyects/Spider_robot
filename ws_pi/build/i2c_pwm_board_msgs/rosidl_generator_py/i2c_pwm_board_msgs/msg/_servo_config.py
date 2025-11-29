# generated from rosidl_generator_py/resource/_idl.py.em
# with input from i2c_pwm_board_msgs:msg/ServoConfig.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ServoConfig(type):
    """Metaclass of message 'ServoConfig'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('i2c_pwm_board_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'i2c_pwm_board_msgs.msg.ServoConfig')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__servo_config
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__servo_config
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__servo_config
            cls._TYPE_SUPPORT = module.type_support_msg__msg__servo_config
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__servo_config

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ServoConfig(metaclass=Metaclass_ServoConfig):
    """Message class 'ServoConfig'."""

    __slots__ = [
        '_servo',
        '_center',
        '_range',
        '_direction',
    ]

    _fields_and_field_types = {
        'servo': 'int16',
        'center': 'int16',
        'range': 'int16',
        'direction': 'int16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.servo = kwargs.get('servo', int())
        self.center = kwargs.get('center', int())
        self.range = kwargs.get('range', int())
        self.direction = kwargs.get('direction', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.servo != other.servo:
            return False
        if self.center != other.center:
            return False
        if self.range != other.range:
            return False
        if self.direction != other.direction:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def servo(self):
        """Message field 'servo'."""
        return self._servo

    @servo.setter
    def servo(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'servo' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'servo' field must be an integer in [-32768, 32767]"
        self._servo = value

    @builtins.property
    def center(self):
        """Message field 'center'."""
        return self._center

    @center.setter
    def center(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'center' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'center' field must be an integer in [-32768, 32767]"
        self._center = value

    @builtins.property  # noqa: A003
    def range(self):  # noqa: A003
        """Message field 'range'."""
        return self._range

    @range.setter  # noqa: A003
    def range(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'range' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'range' field must be an integer in [-32768, 32767]"
        self._range = value

    @builtins.property
    def direction(self):
        """Message field 'direction'."""
        return self._direction

    @direction.setter
    def direction(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'direction' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'direction' field must be an integer in [-32768, 32767]"
        self._direction = value
