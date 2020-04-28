# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from mrpt_msgs/NodeIDWithPose.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg
import std_msgs.msg

class NodeIDWithPose(genpy.Message):
  _md5sum = "87c8db37a689c10a5c5dc1aa39838320"
  _type = "mrpt_msgs/NodeIDWithPose"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# NodeID along with its corresponding 2D/3D pose estimation.
# Message also contains the following optional fields:
# - str_ID: string identifier of the robot agent that initially registered this node in
# its graph
# - nodeID_loc: ID of the current node in the graph it was initially registered in.
#
# note: Additional fields correspond to the fields of the
# mrpt::graphs::detail::TMRSlamNodeAnnotations struct
#
# Currently used in the mrpt_graphslam_2d ROS application.

uint64 nodeID
geometry_msgs/Pose pose

std_msgs/String str_ID
uint64 nodeID_loc

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: std_msgs/String
string data
"""
  __slots__ = ['nodeID','pose','str_ID','nodeID_loc']
  _slot_types = ['uint64','geometry_msgs/Pose','std_msgs/String','uint64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       nodeID,pose,str_ID,nodeID_loc

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(NodeIDWithPose, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.nodeID is None:
        self.nodeID = 0
      if self.pose is None:
        self.pose = geometry_msgs.msg.Pose()
      if self.str_ID is None:
        self.str_ID = std_msgs.msg.String()
      if self.nodeID_loc is None:
        self.nodeID_loc = 0
    else:
      self.nodeID = 0
      self.pose = geometry_msgs.msg.Pose()
      self.str_ID = std_msgs.msg.String()
      self.nodeID_loc = 0

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
      buff.write(_get_struct_Q7d().pack(_x.nodeID, _x.pose.position.x, _x.pose.position.y, _x.pose.position.z, _x.pose.orientation.x, _x.pose.orientation.y, _x.pose.orientation.z, _x.pose.orientation.w))
      _x = self.str_ID.data
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_get_struct_Q().pack(self.nodeID_loc))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.pose is None:
        self.pose = geometry_msgs.msg.Pose()
      if self.str_ID is None:
        self.str_ID = std_msgs.msg.String()
      end = 0
      _x = self
      start = end
      end += 64
      (_x.nodeID, _x.pose.position.x, _x.pose.position.y, _x.pose.position.z, _x.pose.orientation.x, _x.pose.orientation.y, _x.pose.orientation.z, _x.pose.orientation.w,) = _get_struct_Q7d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.str_ID.data = str[start:end].decode('utf-8')
      else:
        self.str_ID.data = str[start:end]
      start = end
      end += 8
      (self.nodeID_loc,) = _get_struct_Q().unpack(str[start:end])
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
      buff.write(_get_struct_Q7d().pack(_x.nodeID, _x.pose.position.x, _x.pose.position.y, _x.pose.position.z, _x.pose.orientation.x, _x.pose.orientation.y, _x.pose.orientation.z, _x.pose.orientation.w))
      _x = self.str_ID.data
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_get_struct_Q().pack(self.nodeID_loc))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.pose is None:
        self.pose = geometry_msgs.msg.Pose()
      if self.str_ID is None:
        self.str_ID = std_msgs.msg.String()
      end = 0
      _x = self
      start = end
      end += 64
      (_x.nodeID, _x.pose.position.x, _x.pose.position.y, _x.pose.position.z, _x.pose.orientation.x, _x.pose.orientation.y, _x.pose.orientation.z, _x.pose.orientation.w,) = _get_struct_Q7d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.str_ID.data = str[start:end].decode('utf-8')
      else:
        self.str_ID.data = str[start:end]
      start = end
      end += 8
      (self.nodeID_loc,) = _get_struct_Q().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_Q = None
def _get_struct_Q():
    global _struct_Q
    if _struct_Q is None:
        _struct_Q = struct.Struct("<Q")
    return _struct_Q
_struct_Q7d = None
def _get_struct_Q7d():
    global _struct_Q7d
    if _struct_Q7d is None:
        _struct_Q7d = struct.Struct("<Q7d")
    return _struct_Q7d