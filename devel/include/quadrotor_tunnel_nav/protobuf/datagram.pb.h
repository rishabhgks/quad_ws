// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: datagram.proto

#ifndef PROTOBUF_datagram_2eproto__INCLUDED
#define PROTOBUF_datagram_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "vector3d.pb.h"
// @@protoc_insertion_point(includes)

namespace adhoc {
namespace msgs {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_datagram_2eproto();
void protobuf_AssignDesc_datagram_2eproto();
void protobuf_ShutdownFile_datagram_2eproto();

class Datagram;

// ===================================================================

class Datagram : public ::google::protobuf::Message {
 public:
  Datagram();
  virtual ~Datagram();

  Datagram(const Datagram& from);

  inline Datagram& operator=(const Datagram& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Datagram& default_instance();

  void Swap(Datagram* other);

  // implements Message ----------------------------------------------

  Datagram* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Datagram& from);
  void MergeFrom(const Datagram& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string robot_name = 1;
  inline bool has_robot_name() const;
  inline void clear_robot_name();
  static const int kRobotNameFieldNumber = 1;
  inline const ::std::string& robot_name() const;
  inline void set_robot_name(const ::std::string& value);
  inline void set_robot_name(const char* value);
  inline void set_robot_name(const char* value, size_t size);
  inline ::std::string* mutable_robot_name();
  inline ::std::string* release_robot_name();
  inline void set_allocated_robot_name(::std::string* robot_name);

  // required uint32 src_address = 2;
  inline bool has_src_address() const;
  inline void clear_src_address();
  static const int kSrcAddressFieldNumber = 2;
  inline ::google::protobuf::uint32 src_address() const;
  inline void set_src_address(::google::protobuf::uint32 value);

  // required uint32 dst_address = 3;
  inline bool has_dst_address() const;
  inline void clear_dst_address();
  static const int kDstAddressFieldNumber = 3;
  inline ::google::protobuf::uint32 dst_address() const;
  inline void set_dst_address(::google::protobuf::uint32 value);

  // required uint32 hops = 4;
  inline bool has_hops() const;
  inline void clear_hops();
  static const int kHopsFieldNumber = 4;
  inline ::google::protobuf::uint32 hops() const;
  inline void set_hops(::google::protobuf::uint32 value);

  // required uint32 index = 5;
  inline bool has_index() const;
  inline void clear_index();
  static const int kIndexFieldNumber = 5;
  inline ::google::protobuf::uint32 index() const;
  inline void set_index(::google::protobuf::uint32 value);

  // required double time = 6;
  inline bool has_time() const;
  inline void clear_time();
  static const int kTimeFieldNumber = 6;
  inline double time() const;
  inline void set_time(double value);

  // required string data = 7;
  inline bool has_data() const;
  inline void clear_data();
  static const int kDataFieldNumber = 7;
  inline const ::std::string& data() const;
  inline void set_data(const ::std::string& value);
  inline void set_data(const char* value);
  inline void set_data(const char* value, size_t size);
  inline ::std::string* mutable_data();
  inline ::std::string* release_data();
  inline void set_allocated_data(::std::string* data);

  // required double dist_comm = 8;
  inline bool has_dist_comm() const;
  inline void clear_dist_comm();
  static const int kDistCommFieldNumber = 8;
  inline double dist_comm() const;
  inline void set_dist_comm(double value);

  // required double dist_motion = 9;
  inline bool has_dist_motion() const;
  inline void clear_dist_motion();
  static const int kDistMotionFieldNumber = 9;
  inline double dist_motion() const;
  inline void set_dist_motion(double value);

  // required .gazebo.msgs.Vector3d prev_loc = 10;
  inline bool has_prev_loc() const;
  inline void clear_prev_loc();
  static const int kPrevLocFieldNumber = 10;
  inline const ::gazebo::msgs::Vector3d& prev_loc() const;
  inline ::gazebo::msgs::Vector3d* mutable_prev_loc();
  inline ::gazebo::msgs::Vector3d* release_prev_loc();
  inline void set_allocated_prev_loc(::gazebo::msgs::Vector3d* prev_loc);

  // @@protoc_insertion_point(class_scope:adhoc.msgs.Datagram)
 private:
  inline void set_has_robot_name();
  inline void clear_has_robot_name();
  inline void set_has_src_address();
  inline void clear_has_src_address();
  inline void set_has_dst_address();
  inline void clear_has_dst_address();
  inline void set_has_hops();
  inline void clear_has_hops();
  inline void set_has_index();
  inline void clear_has_index();
  inline void set_has_time();
  inline void clear_has_time();
  inline void set_has_data();
  inline void clear_has_data();
  inline void set_has_dist_comm();
  inline void clear_has_dist_comm();
  inline void set_has_dist_motion();
  inline void clear_has_dist_motion();
  inline void set_has_prev_loc();
  inline void clear_has_prev_loc();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* robot_name_;
  ::google::protobuf::uint32 src_address_;
  ::google::protobuf::uint32 dst_address_;
  ::google::protobuf::uint32 hops_;
  ::google::protobuf::uint32 index_;
  double time_;
  ::std::string* data_;
  double dist_comm_;
  double dist_motion_;
  ::gazebo::msgs::Vector3d* prev_loc_;
  friend void  protobuf_AddDesc_datagram_2eproto();
  friend void protobuf_AssignDesc_datagram_2eproto();
  friend void protobuf_ShutdownFile_datagram_2eproto();

  void InitAsDefaultInstance();
  static Datagram* default_instance_;
};
// ===================================================================


// ===================================================================

// Datagram

// required string robot_name = 1;
inline bool Datagram::has_robot_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Datagram::set_has_robot_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Datagram::clear_has_robot_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Datagram::clear_robot_name() {
  if (robot_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    robot_name_->clear();
  }
  clear_has_robot_name();
}
inline const ::std::string& Datagram::robot_name() const {
  // @@protoc_insertion_point(field_get:adhoc.msgs.Datagram.robot_name)
  return *robot_name_;
}
inline void Datagram::set_robot_name(const ::std::string& value) {
  set_has_robot_name();
  if (robot_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    robot_name_ = new ::std::string;
  }
  robot_name_->assign(value);
  // @@protoc_insertion_point(field_set:adhoc.msgs.Datagram.robot_name)
}
inline void Datagram::set_robot_name(const char* value) {
  set_has_robot_name();
  if (robot_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    robot_name_ = new ::std::string;
  }
  robot_name_->assign(value);
  // @@protoc_insertion_point(field_set_char:adhoc.msgs.Datagram.robot_name)
}
inline void Datagram::set_robot_name(const char* value, size_t size) {
  set_has_robot_name();
  if (robot_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    robot_name_ = new ::std::string;
  }
  robot_name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:adhoc.msgs.Datagram.robot_name)
}
inline ::std::string* Datagram::mutable_robot_name() {
  set_has_robot_name();
  if (robot_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    robot_name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:adhoc.msgs.Datagram.robot_name)
  return robot_name_;
}
inline ::std::string* Datagram::release_robot_name() {
  clear_has_robot_name();
  if (robot_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = robot_name_;
    robot_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Datagram::set_allocated_robot_name(::std::string* robot_name) {
  if (robot_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete robot_name_;
  }
  if (robot_name) {
    set_has_robot_name();
    robot_name_ = robot_name;
  } else {
    clear_has_robot_name();
    robot_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:adhoc.msgs.Datagram.robot_name)
}

// required uint32 src_address = 2;
inline bool Datagram::has_src_address() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Datagram::set_has_src_address() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Datagram::clear_has_src_address() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Datagram::clear_src_address() {
  src_address_ = 0u;
  clear_has_src_address();
}
inline ::google::protobuf::uint32 Datagram::src_address() const {
  // @@protoc_insertion_point(field_get:adhoc.msgs.Datagram.src_address)
  return src_address_;
}
inline void Datagram::set_src_address(::google::protobuf::uint32 value) {
  set_has_src_address();
  src_address_ = value;
  // @@protoc_insertion_point(field_set:adhoc.msgs.Datagram.src_address)
}

// required uint32 dst_address = 3;
inline bool Datagram::has_dst_address() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Datagram::set_has_dst_address() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Datagram::clear_has_dst_address() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Datagram::clear_dst_address() {
  dst_address_ = 0u;
  clear_has_dst_address();
}
inline ::google::protobuf::uint32 Datagram::dst_address() const {
  // @@protoc_insertion_point(field_get:adhoc.msgs.Datagram.dst_address)
  return dst_address_;
}
inline void Datagram::set_dst_address(::google::protobuf::uint32 value) {
  set_has_dst_address();
  dst_address_ = value;
  // @@protoc_insertion_point(field_set:adhoc.msgs.Datagram.dst_address)
}

// required uint32 hops = 4;
inline bool Datagram::has_hops() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Datagram::set_has_hops() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Datagram::clear_has_hops() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Datagram::clear_hops() {
  hops_ = 0u;
  clear_has_hops();
}
inline ::google::protobuf::uint32 Datagram::hops() const {
  // @@protoc_insertion_point(field_get:adhoc.msgs.Datagram.hops)
  return hops_;
}
inline void Datagram::set_hops(::google::protobuf::uint32 value) {
  set_has_hops();
  hops_ = value;
  // @@protoc_insertion_point(field_set:adhoc.msgs.Datagram.hops)
}

// required uint32 index = 5;
inline bool Datagram::has_index() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Datagram::set_has_index() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Datagram::clear_has_index() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Datagram::clear_index() {
  index_ = 0u;
  clear_has_index();
}
inline ::google::protobuf::uint32 Datagram::index() const {
  // @@protoc_insertion_point(field_get:adhoc.msgs.Datagram.index)
  return index_;
}
inline void Datagram::set_index(::google::protobuf::uint32 value) {
  set_has_index();
  index_ = value;
  // @@protoc_insertion_point(field_set:adhoc.msgs.Datagram.index)
}

// required double time = 6;
inline bool Datagram::has_time() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Datagram::set_has_time() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Datagram::clear_has_time() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Datagram::clear_time() {
  time_ = 0;
  clear_has_time();
}
inline double Datagram::time() const {
  // @@protoc_insertion_point(field_get:adhoc.msgs.Datagram.time)
  return time_;
}
inline void Datagram::set_time(double value) {
  set_has_time();
  time_ = value;
  // @@protoc_insertion_point(field_set:adhoc.msgs.Datagram.time)
}

// required string data = 7;
inline bool Datagram::has_data() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Datagram::set_has_data() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Datagram::clear_has_data() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Datagram::clear_data() {
  if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    data_->clear();
  }
  clear_has_data();
}
inline const ::std::string& Datagram::data() const {
  // @@protoc_insertion_point(field_get:adhoc.msgs.Datagram.data)
  return *data_;
}
inline void Datagram::set_data(const ::std::string& value) {
  set_has_data();
  if (data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    data_ = new ::std::string;
  }
  data_->assign(value);
  // @@protoc_insertion_point(field_set:adhoc.msgs.Datagram.data)
}
inline void Datagram::set_data(const char* value) {
  set_has_data();
  if (data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    data_ = new ::std::string;
  }
  data_->assign(value);
  // @@protoc_insertion_point(field_set_char:adhoc.msgs.Datagram.data)
}
inline void Datagram::set_data(const char* value, size_t size) {
  set_has_data();
  if (data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    data_ = new ::std::string;
  }
  data_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:adhoc.msgs.Datagram.data)
}
inline ::std::string* Datagram::mutable_data() {
  set_has_data();
  if (data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    data_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:adhoc.msgs.Datagram.data)
  return data_;
}
inline ::std::string* Datagram::release_data() {
  clear_has_data();
  if (data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = data_;
    data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Datagram::set_allocated_data(::std::string* data) {
  if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete data_;
  }
  if (data) {
    set_has_data();
    data_ = data;
  } else {
    clear_has_data();
    data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:adhoc.msgs.Datagram.data)
}

// required double dist_comm = 8;
inline bool Datagram::has_dist_comm() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void Datagram::set_has_dist_comm() {
  _has_bits_[0] |= 0x00000080u;
}
inline void Datagram::clear_has_dist_comm() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void Datagram::clear_dist_comm() {
  dist_comm_ = 0;
  clear_has_dist_comm();
}
inline double Datagram::dist_comm() const {
  // @@protoc_insertion_point(field_get:adhoc.msgs.Datagram.dist_comm)
  return dist_comm_;
}
inline void Datagram::set_dist_comm(double value) {
  set_has_dist_comm();
  dist_comm_ = value;
  // @@protoc_insertion_point(field_set:adhoc.msgs.Datagram.dist_comm)
}

// required double dist_motion = 9;
inline bool Datagram::has_dist_motion() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void Datagram::set_has_dist_motion() {
  _has_bits_[0] |= 0x00000100u;
}
inline void Datagram::clear_has_dist_motion() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void Datagram::clear_dist_motion() {
  dist_motion_ = 0;
  clear_has_dist_motion();
}
inline double Datagram::dist_motion() const {
  // @@protoc_insertion_point(field_get:adhoc.msgs.Datagram.dist_motion)
  return dist_motion_;
}
inline void Datagram::set_dist_motion(double value) {
  set_has_dist_motion();
  dist_motion_ = value;
  // @@protoc_insertion_point(field_set:adhoc.msgs.Datagram.dist_motion)
}

// required .gazebo.msgs.Vector3d prev_loc = 10;
inline bool Datagram::has_prev_loc() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void Datagram::set_has_prev_loc() {
  _has_bits_[0] |= 0x00000200u;
}
inline void Datagram::clear_has_prev_loc() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void Datagram::clear_prev_loc() {
  if (prev_loc_ != NULL) prev_loc_->::gazebo::msgs::Vector3d::Clear();
  clear_has_prev_loc();
}
inline const ::gazebo::msgs::Vector3d& Datagram::prev_loc() const {
  // @@protoc_insertion_point(field_get:adhoc.msgs.Datagram.prev_loc)
  return prev_loc_ != NULL ? *prev_loc_ : *default_instance_->prev_loc_;
}
inline ::gazebo::msgs::Vector3d* Datagram::mutable_prev_loc() {
  set_has_prev_loc();
  if (prev_loc_ == NULL) prev_loc_ = new ::gazebo::msgs::Vector3d;
  // @@protoc_insertion_point(field_mutable:adhoc.msgs.Datagram.prev_loc)
  return prev_loc_;
}
inline ::gazebo::msgs::Vector3d* Datagram::release_prev_loc() {
  clear_has_prev_loc();
  ::gazebo::msgs::Vector3d* temp = prev_loc_;
  prev_loc_ = NULL;
  return temp;
}
inline void Datagram::set_allocated_prev_loc(::gazebo::msgs::Vector3d* prev_loc) {
  delete prev_loc_;
  prev_loc_ = prev_loc;
  if (prev_loc) {
    set_has_prev_loc();
  } else {
    clear_has_prev_loc();
  }
  // @@protoc_insertion_point(field_set_allocated:adhoc.msgs.Datagram.prev_loc)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace msgs
}  // namespace adhoc

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_datagram_2eproto__INCLUDED
