// Generated by gencpp from file planning_msgs/PlannerServiceResponse.msg
// DO NOT EDIT!


#ifndef PLANNING_MSGS_MESSAGE_PLANNERSERVICERESPONSE_H
#define PLANNING_MSGS_MESSAGE_PLANNERSERVICERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <planning_msgs/PlanningResponse.h>

namespace planning_msgs
{
template <class ContainerAllocator>
struct PlannerServiceResponse_
{
  typedef PlannerServiceResponse_<ContainerAllocator> Type;

  PlannerServiceResponse_()
    : status(0)
    , plan()  {
    }
  PlannerServiceResponse_(const ContainerAllocator& _alloc)
    : status(0)
    , plan(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _status_type;
  _status_type status;

   typedef  ::planning_msgs::PlanningResponse_<ContainerAllocator>  _plan_type;
  _plan_type plan;



  enum {
    PLANNINGSUCCESS = 1u,
    PLANNINGFAILED = 2u,
  };


  typedef boost::shared_ptr< ::planning_msgs::PlannerServiceResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::planning_msgs::PlannerServiceResponse_<ContainerAllocator> const> ConstPtr;

}; // struct PlannerServiceResponse_

typedef ::planning_msgs::PlannerServiceResponse_<std::allocator<void> > PlannerServiceResponse;

typedef boost::shared_ptr< ::planning_msgs::PlannerServiceResponse > PlannerServiceResponsePtr;
typedef boost::shared_ptr< ::planning_msgs::PlannerServiceResponse const> PlannerServiceResponseConstPtr;

// constants requiring out of line definition

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::planning_msgs::PlannerServiceResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::planning_msgs::PlannerServiceResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace planning_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'planning_msgs': ['/home/rishabh/quad_ws/src/mav_comm/planning_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'octomap_msgs': ['/opt/ros/kinetic/share/octomap_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::planning_msgs::PlannerServiceResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::planning_msgs::PlannerServiceResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::planning_msgs::PlannerServiceResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::planning_msgs::PlannerServiceResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::planning_msgs::PlannerServiceResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::planning_msgs::PlannerServiceResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::planning_msgs::PlannerServiceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6901798f4fe8af616256b39b5ffdd5e6";
  }

  static const char* value(const ::planning_msgs::PlannerServiceResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6901798f4fe8af61ULL;
  static const uint64_t static_value2 = 0x6256b39b5ffdd5e6ULL;
};

template<class ContainerAllocator>
struct DataType< ::planning_msgs::PlannerServiceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "planning_msgs/PlannerServiceResponse";
  }

  static const char* value(const ::planning_msgs::PlannerServiceResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::planning_msgs::PlannerServiceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
uint8 PLANNINGSUCCESS=1\n\
uint8 PLANNINGFAILED=2\n\
\n\
uint8 status\n\
PlanningResponse plan\n\
\n\
\n\
\n\
================================================================================\n\
MSG: planning_msgs/PlanningResponse\n\
float64[] path # m x n matrix\n\
float64[] time # n vector with times\n\
int32 number_primitives  # = n\n\
int32 waypoint_type #polynom, pose etc.\n\
";
  }

  static const char* value(const ::planning_msgs::PlannerServiceResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::planning_msgs::PlannerServiceResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.status);
      stream.next(m.plan);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PlannerServiceResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::planning_msgs::PlannerServiceResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::planning_msgs::PlannerServiceResponse_<ContainerAllocator>& v)
  {
    s << indent << "status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.status);
    s << indent << "plan: ";
    s << std::endl;
    Printer< ::planning_msgs::PlanningResponse_<ContainerAllocator> >::stream(s, indent + "  ", v.plan);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PLANNING_MSGS_MESSAGE_PLANNERSERVICERESPONSE_H
