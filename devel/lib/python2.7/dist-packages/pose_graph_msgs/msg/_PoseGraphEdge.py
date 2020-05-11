# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from pose_graph_msgs/PoseGraphEdge.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class PoseGraphEdge(genpy.Message):
  _md5sum = "412ec4974717bfb14dd2482fb43c1f28"
  _type = "pose_graph_msgs/PoseGraphEdge"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """uint64 key_from
uint64 key_to
"""
  __slots__ = ['key_from','key_to']
  _slot_types = ['uint64','uint64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       key_from,key_to

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(PoseGraphEdge, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.key_from is None:
        self.key_from = 0
      if self.key_to is None:
        self.key_to = 0
    else:
      self.key_from = 0
      self.key_to = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_2Q().pack(_x.key_from, _x.key_to))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 16
      (_x.key_from, _x.key_to,) = _get_struct_2Q().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_2Q().pack(_x.key_from, _x.key_to))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 16
      (_x.key_from, _x.key_to,) = _get_struct_2Q().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2Q = None
def _get_struct_2Q():
    global _struct_2Q
    if _struct_2Q is None:
        _struct_2Q = struct.Struct("<2Q")
    return _struct_2Q
