// Generated by gencpp from file pose_graph_msgs/KeyedScan.msg
// DO NOT EDIT!


#ifndef POSE_GRAPH_MSGS_MESSAGE_KEYEDSCAN_H
#define POSE_GRAPH_MSGS_MESSAGE_KEYEDSCAN_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <sensor_msgs/PointCloud2.h>

namespace pose_graph_msgs
{
template <class ContainerAllocator>
struct KeyedScan_
{
  typedef KeyedScan_<ContainerAllocator> Type;

  KeyedScan_()
    : key(0)
    , scan()  {
    }
  KeyedScan_(const ContainerAllocator& _alloc)
    : key(0)
    , scan(_alloc)  {
  (void)_alloc;
    }



   typedef uint64_t _key_type;
  _key_type key;

   typedef  ::sensor_msgs::PointCloud2_<ContainerAllocator>  _scan_type;
  _scan_type scan;





  typedef boost::shared_ptr< ::pose_graph_msgs::KeyedScan_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pose_graph_msgs::KeyedScan_<ContainerAllocator> const> ConstPtr;

}; // struct KeyedScan_

typedef ::pose_graph_msgs::KeyedScan_<std::allocator<void> > KeyedScan;

typedef boost::shared_ptr< ::pose_graph_msgs::KeyedScan > KeyedScanPtr;
typedef boost::shared_ptr< ::pose_graph_msgs::KeyedScan const> KeyedScanConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pose_graph_msgs::KeyedScan_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pose_graph_msgs::KeyedScan_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace pose_graph_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'pose_graph_msgs': ['/home/rishabh/quad_ws/src/blam/pose_graph_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::pose_graph_msgs::KeyedScan_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pose_graph_msgs::KeyedScan_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pose_graph_msgs::KeyedScan_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pose_graph_msgs::KeyedScan_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pose_graph_msgs::KeyedScan_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pose_graph_msgs::KeyedScan_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pose_graph_msgs::KeyedScan_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4038d31be231d130b6ea4e485e3d4e6a";
  }

  static const char* value(const ::pose_graph_msgs::KeyedScan_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4038d31be231d130ULL;
  static const uint64_t static_value2 = 0xb6ea4e485e3d4e6aULL;
};

template<class ContainerAllocator>
struct DataType< ::pose_graph_msgs::KeyedScan_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pose_graph_msgs/KeyedScan";
  }

  static const char* value(const ::pose_graph_msgs::KeyedScan_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pose_graph_msgs::KeyedScan_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Each keyed scan corresponds to a keyed pose in broadcasted PoseGraph\n\
# messages.\n\
uint64 key\n\
sensor_msgs/PointCloud2 scan\n\
\n\
================================================================================\n\
MSG: sensor_msgs/PointCloud2\n\
# This message holds a collection of N-dimensional points, which may\n\
# contain additional information such as normals, intensity, etc. The\n\
# point data is stored as a binary blob, its layout described by the\n\
# contents of the \"fields\" array.\n\
\n\
# The point cloud data may be organized 2d (image-like) or 1d\n\
# (unordered). Point clouds organized as 2d images may be produced by\n\
# camera depth sensors such as stereo or time-of-flight.\n\
\n\
# Time of sensor data acquisition, and the coordinate frame ID (for 3d\n\
# points).\n\
Header header\n\
\n\
# 2D structure of the point cloud. If the cloud is unordered, height is\n\
# 1 and width is the length of the point cloud.\n\
uint32 height\n\
uint32 width\n\
\n\
# Describes the channels and their layout in the binary data blob.\n\
PointField[] fields\n\
\n\
bool    is_bigendian # Is this data bigendian?\n\
uint32  point_step   # Length of a point in bytes\n\
uint32  row_step     # Length of a row in bytes\n\
uint8[] data         # Actual point data, size is (row_step*height)\n\
\n\
bool is_dense        # True if there are no invalid points\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: sensor_msgs/PointField\n\
# This message holds the description of one point entry in the\n\
# PointCloud2 message format.\n\
uint8 INT8    = 1\n\
uint8 UINT8   = 2\n\
uint8 INT16   = 3\n\
uint8 UINT16  = 4\n\
uint8 INT32   = 5\n\
uint8 UINT32  = 6\n\
uint8 FLOAT32 = 7\n\
uint8 FLOAT64 = 8\n\
\n\
string name      # Name of field\n\
uint32 offset    # Offset from start of point struct\n\
uint8  datatype  # Datatype enumeration, see above\n\
uint32 count     # How many elements in the field\n\
";
  }

  static const char* value(const ::pose_graph_msgs::KeyedScan_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pose_graph_msgs::KeyedScan_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.key);
      stream.next(m.scan);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct KeyedScan_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pose_graph_msgs::KeyedScan_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pose_graph_msgs::KeyedScan_<ContainerAllocator>& v)
  {
    s << indent << "key: ";
    Printer<uint64_t>::stream(s, indent + "  ", v.key);
    s << indent << "scan: ";
    s << std::endl;
    Printer< ::sensor_msgs::PointCloud2_<ContainerAllocator> >::stream(s, indent + "  ", v.scan);
  }
};

} // namespace message_operations
} // namespace ros

#endif // POSE_GRAPH_MSGS_MESSAGE_KEYEDSCAN_H
