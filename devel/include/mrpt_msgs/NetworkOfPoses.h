// Generated by gencpp from file mrpt_msgs/NetworkOfPoses.msg
// DO NOT EDIT!


#ifndef MRPT_MSGS_MESSAGE_NETWORKOFPOSES_H
#define MRPT_MSGS_MESSAGE_NETWORKOFPOSES_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <mrpt_msgs/NodeIDWithPose_vec.h>
#include <mrpt_msgs/GraphConstraint.h>

namespace mrpt_msgs
{
template <class ContainerAllocator>
struct NetworkOfPoses_
{
  typedef NetworkOfPoses_<ContainerAllocator> Type;

  NetworkOfPoses_()
    : root(0)
    , nodes()
    , constraints()  {
    }
  NetworkOfPoses_(const ContainerAllocator& _alloc)
    : root(0)
    , nodes(_alloc)
    , constraints(_alloc)  {
  (void)_alloc;
    }



   typedef uint64_t _root_type;
  _root_type root;

   typedef  ::mrpt_msgs::NodeIDWithPose_vec_<ContainerAllocator>  _nodes_type;
  _nodes_type nodes;

   typedef std::vector< ::mrpt_msgs::GraphConstraint_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::mrpt_msgs::GraphConstraint_<ContainerAllocator> >::other >  _constraints_type;
  _constraints_type constraints;





  typedef boost::shared_ptr< ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator> const> ConstPtr;

}; // struct NetworkOfPoses_

typedef ::mrpt_msgs::NetworkOfPoses_<std::allocator<void> > NetworkOfPoses;

typedef boost::shared_ptr< ::mrpt_msgs::NetworkOfPoses > NetworkOfPosesPtr;
typedef boost::shared_ptr< ::mrpt_msgs::NetworkOfPoses const> NetworkOfPosesConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mrpt_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'mrpt_msgs': ['/home/rishabh/quad_ws/src/mrpt_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2f7e17a78e81d376b3e999d635df4228";
  }

  static const char* value(const ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2f7e17a78e81d376ULL;
  static const uint64_t static_value2 = 0xb3e999d635df4228ULL;
};

template<class ContainerAllocator>
struct DataType< ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mrpt_msgs/NetworkOfPoses";
  }

  static const char* value(const ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Represents a 2D/3D Directed Graph of Constraints\n\
#\n\
# Graph consists of:\n\
# - NodeIDs with their corresponding poses\n\
# - Directed Constraints that connect 2 nodes with each other\n\
# - Root node marking the start of the graph\n\
\n\
uint64 root\n\
NodeIDWithPose_vec nodes\n\
GraphConstraint[] constraints\n\
\n\
================================================================================\n\
MSG: mrpt_msgs/NodeIDWithPose_vec\n\
# Vector of NodeIDWithPose msgs\n\
\n\
NodeIDWithPose[] vec\n\
\n\
\n\
================================================================================\n\
MSG: mrpt_msgs/NodeIDWithPose\n\
# NodeID along with its corresponding 2D/3D pose estimation.\n\
# Message also contains the following optional fields:\n\
# - str_ID: string identifier of the robot agent that initially registered this node in\n\
# its graph\n\
# - nodeID_loc: ID of the current node in the graph it was initially registered in.\n\
#\n\
# note: Additional fields correspond to the fields of the\n\
# mrpt::graphs::detail::TMRSlamNodeAnnotations struct\n\
#\n\
# Currently used in the mrpt_graphslam_2d ROS application.\n\
\n\
uint64 nodeID\n\
geometry_msgs/Pose pose\n\
\n\
std_msgs/String str_ID\n\
uint64 nodeID_loc\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
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
MSG: std_msgs/String\n\
string data\n\
\n\
================================================================================\n\
MSG: mrpt_msgs/GraphConstraint\n\
# Graph constraint that connects 2 nodes\n\
#\n\
# Currently used in the mrpt_graphslam_2d ROS application.\n\
\n\
uint64 nodeID_from\n\
uint64 nodeID_to\n\
geometry_msgs/PoseWithCovariance constraint\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseWithCovariance\n\
# This represents a pose in free space with uncertainty.\n\
\n\
Pose pose\n\
\n\
# Row-major representation of the 6x6 covariance matrix\n\
# The orientation parameters use a fixed-axis representation.\n\
# In order, the parameters are:\n\
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n\
float64[36] covariance\n\
";
  }

  static const char* value(const ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.root);
      stream.next(m.nodes);
      stream.next(m.constraints);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct NetworkOfPoses_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mrpt_msgs::NetworkOfPoses_<ContainerAllocator>& v)
  {
    s << indent << "root: ";
    Printer<uint64_t>::stream(s, indent + "  ", v.root);
    s << indent << "nodes: ";
    s << std::endl;
    Printer< ::mrpt_msgs::NodeIDWithPose_vec_<ContainerAllocator> >::stream(s, indent + "  ", v.nodes);
    s << indent << "constraints[]" << std::endl;
    for (size_t i = 0; i < v.constraints.size(); ++i)
    {
      s << indent << "  constraints[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::mrpt_msgs::GraphConstraint_<ContainerAllocator> >::stream(s, indent + "    ", v.constraints[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // MRPT_MSGS_MESSAGE_NETWORKOFPOSES_H