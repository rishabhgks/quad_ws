// Generated by gencpp from file planning_msgs/WaypointType.msg
// DO NOT EDIT!


#ifndef PLANNING_MSGS_MESSAGE_WAYPOINTTYPE_H
#define PLANNING_MSGS_MESSAGE_WAYPOINTTYPE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace planning_msgs
{
template <class ContainerAllocator>
struct WaypointType_
{
  typedef WaypointType_<ContainerAllocator> Type;

  WaypointType_()
    {
    }
  WaypointType_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }





  enum {
    POSE = 1,
    POLYNOMIAL = 2,
    POLYNOMIAL_10 = 210,
    POLYNOMIAL_12 = 212,
  };


  typedef boost::shared_ptr< ::planning_msgs::WaypointType_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::planning_msgs::WaypointType_<ContainerAllocator> const> ConstPtr;

}; // struct WaypointType_

typedef ::planning_msgs::WaypointType_<std::allocator<void> > WaypointType;

typedef boost::shared_ptr< ::planning_msgs::WaypointType > WaypointTypePtr;
typedef boost::shared_ptr< ::planning_msgs::WaypointType const> WaypointTypeConstPtr;

// constants requiring out of line definition

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::planning_msgs::WaypointType_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::planning_msgs::WaypointType_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace planning_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'planning_msgs': ['/home/rishabh/quad_ws/src/mav_comm/planning_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'octomap_msgs': ['/opt/ros/kinetic/share/octomap_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::planning_msgs::WaypointType_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::planning_msgs::WaypointType_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::planning_msgs::WaypointType_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::planning_msgs::WaypointType_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::planning_msgs::WaypointType_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::planning_msgs::WaypointType_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::planning_msgs::WaypointType_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ab2317fe7228faf4b4c92459f5353963";
  }

  static const char* value(const ::planning_msgs::WaypointType_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xab2317fe7228faf4ULL;
  static const uint64_t static_value2 = 0xb4c92459f5353963ULL;
};

template<class ContainerAllocator>
struct DataType< ::planning_msgs::WaypointType_<ContainerAllocator> >
{
  static const char* value()
  {
    return "planning_msgs/WaypointType";
  }

  static const char* value(const ::planning_msgs::WaypointType_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::planning_msgs::WaypointType_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 POSE=1\n\
int32 POLYNOMIAL=2 # stores the coefficients of a polynomial in the waypoint fields. Coefficients are stored in increasing order, i.e. c0 + c1*t + c2*t^2 ...\n\
int32 POLYNOMIAL_10=210 # polynomial with 10 coefficients, i.e. 9th order\n\
int32 POLYNOMIAL_12=212 # polynomial with 12 coefficients, i.e. 11th order\n\
";
  }

  static const char* value(const ::planning_msgs::WaypointType_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::planning_msgs::WaypointType_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct WaypointType_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::planning_msgs::WaypointType_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::planning_msgs::WaypointType_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // PLANNING_MSGS_MESSAGE_WAYPOINTTYPE_H
