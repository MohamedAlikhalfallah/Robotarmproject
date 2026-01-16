# generated from rosidl_generator_py/resource/_idl.py.em
# with input from scene_graph_interfaces:msg/FunObject3DBoundingBox.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FunObject3DBoundingBox(type):
    """Metaclass of message 'FunObject3DBoundingBox'."""

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
            module = import_type_support('scene_graph_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'scene_graph_interfaces.msg.FunObject3DBoundingBox')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__fun_object3_d_bounding_box
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__fun_object3_d_bounding_box
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__fun_object3_d_bounding_box
            cls._TYPE_SUPPORT = module.type_support_msg__msg__fun_object3_d_bounding_box
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__fun_object3_d_bounding_box

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from std_msgs.msg import String
            if String.__class__._TYPE_SUPPORT is None:
                String.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FunObject3DBoundingBox(metaclass=Metaclass_FunObject3DBoundingBox):
    """Message class 'FunObject3DBoundingBox'."""

    __slots__ = [
        '_name',
        '_bounding_box',
        '_graspable',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'name': 'std_msgs/String',
        'bounding_box': 'geometry_msgs/Point[2]',
        'graspable': 'boolean',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'String'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'), 2),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import String
        self.name = kwargs.get('name', String())
        from geometry_msgs.msg import Point
        self.bounding_box = kwargs.get(
            'bounding_box',
            [Point() for x in range(2)]
        )
        self.graspable = kwargs.get('graspable', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
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
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.name != other.name:
            return False
        if self.bounding_box != other.bounding_box:
            return False
        if self.graspable != other.graspable:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if self._check_fields:
            from std_msgs.msg import String
            assert \
                isinstance(value, String), \
                "The 'name' field must be a sub message of type 'String'"
        self._name = value

    @builtins.property
    def bounding_box(self):
        """Message field 'bounding_box'."""
        return self._bounding_box

    @bounding_box.setter
    def bounding_box(self, value):
        if self._check_fields:
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
                 len(value) == 2 and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'bounding_box' field must be a set or sequence with length 2 and each value of type 'Point'"
        self._bounding_box = value

    @builtins.property
    def graspable(self):
        """Message field 'graspable'."""
        return self._graspable

    @graspable.setter
    def graspable(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'graspable' field must be of type 'bool'"
        self._graspable = value
