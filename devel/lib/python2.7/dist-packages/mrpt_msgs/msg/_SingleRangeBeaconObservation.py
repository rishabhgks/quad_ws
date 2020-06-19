# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from mrpt_msgs/SingleRangeBeaconObservation.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class SingleRangeBeaconObservation(genpy.Message):
  _md5sum = "1a4ad6d0080f2888716c1b8c7a297f62"
  _type = "mrpt_msgs/SingleRangeBeaconObservation"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """#int32 INVALID_LANDMARK_ID = -1


float64  range    # Distance, in meters.
int32    id       # Landmark ID (or INVALID_LANDMARK_ID if landmarks are not identified)

"""
  __slots__ = ['range','id']
  _slot_types = ['float64','int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       range,id

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SingleRangeBeaconObservation, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.range is None:
        self.range = 0.
      if self.id is None:
        self.id = 0
    else:
      self.range = 0.
      self.id = 0

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
      buff.write(_get_struct_di().pack(_x.range, _x.id))
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
      end += 12
      (_x.range, _x.id,) = _get_struct_di().unpack(str[start:end])
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
      buff.write(_get_struct_di().pack(_x.range, _x.id))
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
      end += 12
      (_x.range, _x.id,) = _get_struct_di().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_di = None
def _get_struct_di():
    global _struct_di
    if _struct_di is None:
        _struct_di = struct.Struct("<di")
    return _struct_di
