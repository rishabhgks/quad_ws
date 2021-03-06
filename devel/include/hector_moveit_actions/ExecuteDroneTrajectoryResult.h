// Generated by gencpp from file hector_moveit_actions/ExecuteDroneTrajectoryResult.msg
// DO NOT EDIT!


#ifndef HECTOR_MOVEIT_ACTIONS_MESSAGE_EXECUTEDRONETRAJECTORYRESULT_H
#define HECTOR_MOVEIT_ACTIONS_MESSAGE_EXECUTEDRONETRAJECTORYRESULT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace hector_moveit_actions
{
template <class ContainerAllocator>
struct ExecuteDroneTrajectoryResult_
{
  typedef ExecuteDroneTrajectoryResult_<ContainerAllocator> Type;

  ExecuteDroneTrajectoryResult_()
    : result_code(0)  {
    }
  ExecuteDroneTrajectoryResult_(const ContainerAllocator& _alloc)
    : result_code(0)  {
  (void)_alloc;
    }



   typedef int32_t _result_code_type;
  _result_code_type result_code;



  enum {
    SUCCESSFUL = 0,
    INVALID_GOAL = -1,
    PATH_TOLERANCE_VIOLATED = -2,
    COLLISION_IN_FRONT = 3,
  };


  typedef boost::shared_ptr< ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator> const> ConstPtr;

}; // struct ExecuteDroneTrajectoryResult_

typedef ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<std::allocator<void> > ExecuteDroneTrajectoryResult;

typedef boost::shared_ptr< ::hector_moveit_actions::ExecuteDroneTrajectoryResult > ExecuteDroneTrajectoryResultPtr;
typedef boost::shared_ptr< ::hector_moveit_actions::ExecuteDroneTrajectoryResult const> ExecuteDroneTrajectoryResultConstPtr;

// constants requiring out of line definition

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace hector_moveit_actions

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'hector_moveit_actions': ['/home/rishabh/quad_ws/devel/share/hector_moveit_actions/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "264ca3d6aad1463d76554dc6f52d4444";
  }

  static const char* value(const ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x264ca3d6aad1463dULL;
  static const uint64_t static_value2 = 0x76554dc6f52d4444ULL;
};

template<class ContainerAllocator>
struct DataType< ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "hector_moveit_actions/ExecuteDroneTrajectoryResult";
  }

  static const char* value(const ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# Result definition\n\
int32 result_code\n\
int32 SUCCESSFUL = 0\n\
int32 INVALID_GOAL = -1\n\
int32 PATH_TOLERANCE_VIOLATED = -2\n\
int32 COLLISION_IN_FRONT = 3\n\
";
  }

  static const char* value(const ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result_code);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ExecuteDroneTrajectoryResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::hector_moveit_actions::ExecuteDroneTrajectoryResult_<ContainerAllocator>& v)
  {
    s << indent << "result_code: ";
    Printer<int32_t>::stream(s, indent + "  ", v.result_code);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HECTOR_MOVEIT_ACTIONS_MESSAGE_EXECUTEDRONETRAJECTORYRESULT_H
