// Generated by gencpp from file geographic_msgs/GetGeoPathResponse.msg
// DO NOT EDIT!


#ifndef GEOGRAPHIC_MSGS_MESSAGE_GETGEOPATHRESPONSE_H
#define GEOGRAPHIC_MSGS_MESSAGE_GETGEOPATHRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geographic_msgs/GeoPath.h>
#include <uuid_msgs/UniqueID.h>
#include <uuid_msgs/UniqueID.h>
#include <uuid_msgs/UniqueID.h>

namespace geographic_msgs
{
template <class ContainerAllocator>
struct GetGeoPathResponse_
{
  typedef GetGeoPathResponse_<ContainerAllocator> Type;

  GetGeoPathResponse_()
    : success(false)
    , status()
    , plan()
    , network()
    , start_seg()
    , goal_seg()
    , distance(0.0)  {
    }
  GetGeoPathResponse_(const ContainerAllocator& _alloc)
    : success(false)
    , status(_alloc)
    , plan(_alloc)
    , network(_alloc)
    , start_seg(_alloc)
    , goal_seg(_alloc)
    , distance(0.0)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _status_type;
  _status_type status;

   typedef  ::geographic_msgs::GeoPath_<ContainerAllocator>  _plan_type;
  _plan_type plan;

   typedef  ::uuid_msgs::UniqueID_<ContainerAllocator>  _network_type;
  _network_type network;

   typedef  ::uuid_msgs::UniqueID_<ContainerAllocator>  _start_seg_type;
  _start_seg_type start_seg;

   typedef  ::uuid_msgs::UniqueID_<ContainerAllocator>  _goal_seg_type;
  _goal_seg_type goal_seg;

   typedef double _distance_type;
  _distance_type distance;





  typedef boost::shared_ptr< ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetGeoPathResponse_

typedef ::geographic_msgs::GetGeoPathResponse_<std::allocator<void> > GetGeoPathResponse;

typedef boost::shared_ptr< ::geographic_msgs::GetGeoPathResponse > GetGeoPathResponsePtr;
typedef boost::shared_ptr< ::geographic_msgs::GetGeoPathResponse const> GetGeoPathResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace geographic_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geographic_msgs': ['/home/rishabh/quad_ws/src/geographic_info/geographic_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'uuid_msgs': ['/opt/ros/kinetic/share/uuid_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0562f4b72e4d5b8e5fa142bd7363638c";
  }

  static const char* value(const ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0562f4b72e4d5b8eULL;
  static const uint64_t static_value2 = 0x5fa142bd7363638cULL;
};

template<class ContainerAllocator>
struct DataType< ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geographic_msgs/GetGeoPathResponse";
  }

  static const char* value(const ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
bool success\n\
string status\n\
\n\
geographic_msgs/GeoPath plan\n\
\n\
uuid_msgs/UniqueID network\n\
uuid_msgs/UniqueID start_seg\n\
uuid_msgs/UniqueID goal_seg\n\
float64 distance\n\
\n\
\n\
================================================================================\n\
MSG: geographic_msgs/GeoPath\n\
std_msgs/Header header\n\
geographic_msgs/GeoPoseStamped[] poses\n\
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
MSG: geographic_msgs/GeoPoseStamped\n\
Header header\n\
geographic_msgs/GeoPose pose\n\
\n\
================================================================================\n\
MSG: geographic_msgs/GeoPose\n\
# Geographic pose, using the WGS 84 reference ellipsoid.\n\
#\n\
# Orientation uses the East-North-Up (ENU) frame of reference.\n\
# (But, what about singularities at the poles?)\n\
\n\
GeoPoint position\n\
geometry_msgs/Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geographic_msgs/GeoPoint\n\
# Geographic point, using the WGS 84 reference ellipsoid.\n\
\n\
# Latitude [degrees]. Positive is north of equator; negative is south\n\
# (-90 <= latitude <= +90).\n\
float64 latitude\n\
\n\
# Longitude [degrees]. Positive is east of prime meridian; negative is\n\
# west (-180 <= longitude <= +180). At the poles, latitude is -90 or\n\
# +90, and longitude is irrelevant, but must be in range.\n\
float64 longitude\n\
\n\
# Altitude [m]. Positive is above the WGS 84 ellipsoid (NaN if unspecified).\n\
float64 altitude\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
================================================================================\n\
MSG: uuid_msgs/UniqueID\n\
# A universally unique identifier (UUID).\n\
#\n\
#  http://en.wikipedia.org/wiki/Universally_unique_identifier\n\
#  http://tools.ietf.org/html/rfc4122.html\n\
\n\
uint8[16] uuid\n\
";
  }

  static const char* value(const ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
      stream.next(m.status);
      stream.next(m.plan);
      stream.next(m.network);
      stream.next(m.start_seg);
      stream.next(m.goal_seg);
      stream.next(m.distance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetGeoPathResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::geographic_msgs::GetGeoPathResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    s << indent << "status: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.status);
    s << indent << "plan: ";
    s << std::endl;
    Printer< ::geographic_msgs::GeoPath_<ContainerAllocator> >::stream(s, indent + "  ", v.plan);
    s << indent << "network: ";
    s << std::endl;
    Printer< ::uuid_msgs::UniqueID_<ContainerAllocator> >::stream(s, indent + "  ", v.network);
    s << indent << "start_seg: ";
    s << std::endl;
    Printer< ::uuid_msgs::UniqueID_<ContainerAllocator> >::stream(s, indent + "  ", v.start_seg);
    s << indent << "goal_seg: ";
    s << std::endl;
    Printer< ::uuid_msgs::UniqueID_<ContainerAllocator> >::stream(s, indent + "  ", v.goal_seg);
    s << indent << "distance: ";
    Printer<double>::stream(s, indent + "  ", v.distance);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GEOGRAPHIC_MSGS_MESSAGE_GETGEOPATHRESPONSE_H
