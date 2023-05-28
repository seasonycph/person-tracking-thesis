# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_interfaces:msg/Associations.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'yolo_ids'
# Member 'drspaam_ids'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Associations(type):
    """Metaclass of message 'Associations'."""

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
            module = import_type_support('custom_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interfaces.msg.Associations')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__associations
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__associations
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__associations
            cls._TYPE_SUPPORT = module.type_support_msg__msg__associations
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__associations

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Associations(metaclass=Metaclass_Associations):
    """Message class 'Associations'."""

    __slots__ = [
        '_header',
        '_yolo_ids',
        '_drspaam_ids',
        '_yolo_positions',
        '_drspaam_positions',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'yolo_ids': 'sequence<int32>',
        'drspaam_ids': 'sequence<int32>',
        'yolo_positions': 'sequence<geometry_msgs/Point>',
        'drspaam_positions': 'sequence<geometry_msgs/Point>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.yolo_ids = array.array('i', kwargs.get('yolo_ids', []))
        self.drspaam_ids = array.array('i', kwargs.get('drspaam_ids', []))
        self.yolo_positions = kwargs.get('yolo_positions', [])
        self.drspaam_positions = kwargs.get('drspaam_positions', [])

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
        if self.header != other.header:
            return False
        if self.yolo_ids != other.yolo_ids:
            return False
        if self.drspaam_ids != other.drspaam_ids:
            return False
        if self.yolo_positions != other.yolo_positions:
            return False
        if self.drspaam_positions != other.drspaam_positions:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def yolo_ids(self):
        """Message field 'yolo_ids'."""
        return self._yolo_ids

    @yolo_ids.setter
    def yolo_ids(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'yolo_ids' array.array() must have the type code of 'i'"
            self._yolo_ids = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'yolo_ids' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._yolo_ids = array.array('i', value)

    @builtins.property
    def drspaam_ids(self):
        """Message field 'drspaam_ids'."""
        return self._drspaam_ids

    @drspaam_ids.setter
    def drspaam_ids(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'drspaam_ids' array.array() must have the type code of 'i'"
            self._drspaam_ids = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'drspaam_ids' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._drspaam_ids = array.array('i', value)

    @builtins.property
    def yolo_positions(self):
        """Message field 'yolo_positions'."""
        return self._yolo_positions

    @yolo_positions.setter
    def yolo_positions(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'yolo_positions' field must be a set or sequence and each value of type 'Point'"
        self._yolo_positions = value

    @builtins.property
    def drspaam_positions(self):
        """Message field 'drspaam_positions'."""
        return self._drspaam_positions

    @drspaam_positions.setter
    def drspaam_positions(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'drspaam_positions' field must be a set or sequence and each value of type 'Point'"
        self._drspaam_positions = value
