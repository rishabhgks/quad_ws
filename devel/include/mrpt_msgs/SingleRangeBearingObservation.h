// Generated by gencpp from file mrpt_msgs/SingleRangeBearingObservation.msg
// DO NOT EDIT!


#ifndef MRPT_MSGS_MESSAGE_SINGLERANGEBEARINGOBSERVATION_H
#define MRPT_MSGS_MESSAGE_SINGLERANGEBEARINGOBSERVATION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace mrpt_msgs
{
template <class ContainerAllocator>
struct SingleRangeBearingObservation_
{
  typedef SingleRangeBearingObservation_<ContainerAllocator> Type;

  SingleRangeBearingObservation_()
    : range(0.0)
    , yaw(0.0)
    , pitch(0.0)
    , id(0)  {
    }
  SingleRangeBearingObservation_(const ContainerAllocator& _alloc)
    : range(0.0)
    , yaw(0.0)
    , pitch(0.0)
    , id(0)  {
  (void)_alloc;
    }



   typedef double _range_type;
  _range_type range;

   typedef double _yaw_type;
  _yaw_type yaw;

   typedef double _pitch_type;
  _pitch_type pitch;

   typedef int32_t _id_type;
  _id_type id;





  typedef boost::shared_ptr< ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator> const> ConstPtr;

}; // struct SingleRangeBearingObservation_

typedef ::mrpt_msgs::SingleRangeBearingObservation_<std::allocator<void> > SingleRangeBearingObservation;

typedef boost::shared_ptr< ::mrpt_msgs::SingleRangeBearingObservation > SingleRangeBearingObservationPtr;
typedef boost::shared_ptr< ::mrpt_msgs::SingleRangeBearingObservation const> SingleRangeBearingObservationConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mrpt_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'mrpt_msgs': ['/home/rishabh/quad_ws/src/mrpt_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator> >
{
  static const char* value()
  {
    return "76298eebeb670a2e009ca536cba1648b";
  }

  static const char* value(const ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x76298eebeb670a2eULL;
  static const uint64_t static_value2 = 0x009ca536cba1648bULL;
};

template<class ContainerAllocator>
struct DataType< ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mrpt_msgs/SingleRangeBearingObservation";
  }

  static const char* value(const ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#int32 INVALID_LANDMARK_ID = -1\n\
\n\
\n\
float64  range    # Distance, in meters.\n\
float64  yaw      # Angle wrt +Z (rads)\n\
float64  pitch    # Angle wrt +Y (rads)\n\
int32    id       # Landmark ID (or INVALID_LANDMARK_ID if landmarks are not identified)\n\
\n\
";
  }

  static const char* value(const ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.range);
      stream.next(m.yaw);
      stream.next(m.pitch);
      stream.next(m.id);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SingleRangeBearingObservation_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mrpt_msgs::SingleRangeBearingObservation_<ContainerAllocator>& v)
  {
    s << indent << "range: ";
    Printer<double>::stream(s, indent + "  ", v.range);
    s << indent << "yaw: ";
    Printer<double>::stream(s, indent + "  ", v.yaw);
    s << indent << "pitch: ";
    Printer<double>::stream(s, indent + "  ", v.pitch);
    s << indent << "id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.id);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MRPT_MSGS_MESSAGE_SINGLERANGEBEARINGOBSERVATION_H
