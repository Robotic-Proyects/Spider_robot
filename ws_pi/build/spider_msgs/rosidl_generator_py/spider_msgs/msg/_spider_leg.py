# generated from rosidl_generator_py/resource/_idl.py.em
# with input from spider_msgs:msg/SpiderLeg.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SpiderLeg(type):
    """Metaclass of message 'SpiderLeg'."""

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
            module = import_type_support('spider_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'spider_msgs.msg.SpiderLeg')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__spider_leg
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__spider_leg
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__spider_leg
            cls._TYPE_SUPPORT = module.type_support_msg__msg__spider_leg
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__spider_leg

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SpiderLeg(metaclass=Metaclass_SpiderLeg):
    """Message class 'SpiderLeg'."""

    __slots__ = [
        '_hip',
        '_leg',
        '_foot',
        '_smooth_value',
    ]

    _fields_and_field_types = {
        'hip': 'float',
        'leg': 'float',
        'foot': 'float',
        'smooth_value': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.hip = kwargs.get('hip', float())
        self.leg = kwargs.get('leg', float())
        self.foot = kwargs.get('foot', float())
        self.smooth_value = kwargs.get('smooth_value', float())

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
        if self.hip != other.hip:
            return False
        if self.leg != other.leg:
            return False
        if self.foot != other.foot:
            return False
        if self.smooth_value != other.smooth_value:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def hip(self):
        """Message field 'hip'."""
        return self._hip

    @hip.setter
    def hip(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'hip' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'hip' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._hip = value

    @builtins.property
    def leg(self):
        """Message field 'leg'."""
        return self._leg

    @leg.setter
    def leg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'leg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'leg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._leg = value

    @builtins.property
    def foot(self):
        """Message field 'foot'."""
        return self._foot

    @foot.setter
    def foot(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'foot' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'foot' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._foot = value

    @builtins.property
    def smooth_value(self):
        """Message field 'smooth_value'."""
        return self._smooth_value

    @smooth_value.setter
    def smooth_value(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'smooth_value' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'smooth_value' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._smooth_value = value
