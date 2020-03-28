// Generated by gencpp from file geographic_msgs/GetRoutePlanResponse.msg
// DO NOT EDIT!


#ifndef GEOGRAPHIC_MSGS_MESSAGE_GETROUTEPLANRESPONSE_H
#define GEOGRAPHIC_MSGS_MESSAGE_GETROUTEPLANRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geographic_msgs/RoutePath.h>

namespace geographic_msgs
{
template <class ContainerAllocator>
struct GetRoutePlanResponse_
{
  typedef GetRoutePlanResponse_<ContainerAllocator> Type;

  GetRoutePlanResponse_()
    : success(false)
    , status()
    , plan()  {
    }
  GetRoutePlanResponse_(const ContainerAllocator& _alloc)
    : success(false)
    , status(_alloc)
    , plan(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _status_type;
  _status_type status;

   typedef  ::geographic_msgs::RoutePath_<ContainerAllocator>  _plan_type;
  _plan_type plan;





  typedef boost::shared_ptr< ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetRoutePlanResponse_

typedef ::geographic_msgs::GetRoutePlanResponse_<std::allocator<void> > GetRoutePlanResponse;

typedef boost::shared_ptr< ::geographic_msgs::GetRoutePlanResponse > GetRoutePlanResponsePtr;
typedef boost::shared_ptr< ::geographic_msgs::GetRoutePlanResponse const> GetRoutePlanResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "28ee54f0ccb2ab28b46048ebc6fa5aff";
  }

  static const char* value(const ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x28ee54f0ccb2ab28ULL;
  static const uint64_t static_value2 = 0xb46048ebc6fa5affULL;
};

template<class ContainerAllocator>
struct DataType< ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geographic_msgs/GetRoutePlanResponse";
  }

  static const char* value(const ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
bool            success\n\
string          status\n\
\n\
RoutePath       plan\n\
\n\
\n\
================================================================================\n\
MSG: geographic_msgs/RoutePath\n\
# Path through a route network.\n\
#\n\
# A path is a sequence of RouteSegment edges.  This information is\n\
# extracted from a RouteNetwork graph.  A RoutePath lists the route\n\
# segments needed to reach some chosen goal.\n\
\n\
Header header\n\
\n\
uuid_msgs/UniqueID   network    # Route network containing this path\n\
uuid_msgs/UniqueID[] segments   # Sequence of RouteSegment IDs\n\
KeyValue[]           props      # Key/value properties\n\
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
MSG: uuid_msgs/UniqueID\n\
# A universally unique identifier (UUID).\n\
#\n\
#  http://en.wikipedia.org/wiki/Universally_unique_identifier\n\
#  http://tools.ietf.org/html/rfc4122.html\n\
\n\
uint8[16] uuid\n\
\n\
================================================================================\n\
MSG: geographic_msgs/KeyValue\n\
# Geographic map tag (key, value) pair\n\
#\n\
# This is equivalent to diagnostic_msgs/KeyValue, repeated here to\n\
# avoid introducing a trivial stack dependency.\n\
\n\
string key                     # tag label\n\
string value                   # corresponding value\n\
";
  }

  static const char* value(const ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
      stream.next(m.status);
      stream.next(m.plan);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetRoutePlanResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::geographic_msgs::GetRoutePlanResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    s << indent << "status: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.status);
    s << indent << "plan: ";
    s << std::endl;
    Printer< ::geographic_msgs::RoutePath_<ContainerAllocator> >::stream(s, indent + "  ", v.plan);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GEOGRAPHIC_MSGS_MESSAGE_GETROUTEPLANRESPONSE_H
