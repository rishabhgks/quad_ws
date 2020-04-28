// Generated by gencpp from file move_quadcopter/NavigateResult.msg
// DO NOT EDIT!


#ifndef MOVE_QUADCOPTER_MESSAGE_NAVIGATERESULT_H
#define MOVE_QUADCOPTER_MESSAGE_NAVIGATERESULT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Point.h>

namespace move_quadcopter
{
template <class ContainerAllocator>
struct NavigateResult_
{
  typedef NavigateResult_<ContainerAllocator> Type;

  NavigateResult_()
    : reached_pos()  {
    }
  NavigateResult_(const ContainerAllocator& _alloc)
    : reached_pos(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Point_<ContainerAllocator>  _reached_pos_type;
  _reached_pos_type reached_pos;





  typedef boost::shared_ptr< ::move_quadcopter::NavigateResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::move_quadcopter::NavigateResult_<ContainerAllocator> const> ConstPtr;

}; // struct NavigateResult_

typedef ::move_quadcopter::NavigateResult_<std::allocator<void> > NavigateResult;

typedef boost::shared_ptr< ::move_quadcopter::NavigateResult > NavigateResultPtr;
typedef boost::shared_ptr< ::move_quadcopter::NavigateResult const> NavigateResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::move_quadcopter::NavigateResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::move_quadcopter::NavigateResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace move_quadcopter

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'move_quadcopter': ['/home/rishabh/quad_ws/devel/share/move_quadcopter/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::move_quadcopter::NavigateResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::move_quadcopter::NavigateResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::move_quadcopter::NavigateResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::move_quadcopter::NavigateResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::move_quadcopter::NavigateResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::move_quadcopter::NavigateResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::move_quadcopter::NavigateResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "87b3721d96e4977c0d52e0b467b8784f";
  }

  static const char* value(const ::move_quadcopter::NavigateResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x87b3721d96e4977cULL;
  static const uint64_t static_value2 = 0x0d52e0b467b8784fULL;
};

template<class ContainerAllocator>
struct DataType< ::move_quadcopter::NavigateResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "move_quadcopter/NavigateResult";
  }

  static const char* value(const ::move_quadcopter::NavigateResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::move_quadcopter::NavigateResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# position reached by navigation after the action is finished\n\
geometry_msgs/Point reached_pos\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::move_quadcopter::NavigateResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::move_quadcopter::NavigateResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.reached_pos);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct NavigateResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::move_quadcopter::NavigateResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::move_quadcopter::NavigateResult_<ContainerAllocator>& v)
  {
    s << indent << "reached_pos: ";
    s << std::endl;
    Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "  ", v.reached_pos);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MOVE_QUADCOPTER_MESSAGE_NAVIGATERESULT_H