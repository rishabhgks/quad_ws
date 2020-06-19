; Auto-generated. Do not edit!


(cl:in-package quadrotor_tunnel_nav-msg)


;//! \htmlinclude Com.msg.html

(cl:defclass <Com> (roslisp-msg-protocol:ros-message)
  ((message
    :reader message
    :initarg :message
    :type cl:string
    :initform "")
   (vel
    :reader vel
    :initarg :vel
    :type geometry_msgs-msg:Twist
    :initform (cl:make-instance 'geometry_msgs-msg:Twist)))
)

(cl:defclass Com (<Com>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Com>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Com)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name quadrotor_tunnel_nav-msg:<Com> is deprecated: use quadrotor_tunnel_nav-msg:Com instead.")))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <Com>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quadrotor_tunnel_nav-msg:message-val is deprecated.  Use quadrotor_tunnel_nav-msg:message instead.")
  (message m))

(cl:ensure-generic-function 'vel-val :lambda-list '(m))
(cl:defmethod vel-val ((m <Com>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quadrotor_tunnel_nav-msg:vel-val is deprecated.  Use quadrotor_tunnel_nav-msg:vel instead.")
  (vel m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Com>) ostream)
  "Serializes a message object of type '<Com>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'vel) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Com>) istream)
  "Deserializes a message object of type '<Com>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'message) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'message) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'vel) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Com>)))
  "Returns string type for a message object of type '<Com>"
  "quadrotor_tunnel_nav/Com")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Com)))
  "Returns string type for a message object of type 'Com"
  "quadrotor_tunnel_nav/Com")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Com>)))
  "Returns md5sum for a message object of type '<Com>"
  "6a6a2fdbdfea337c6d5c872e8c0b98e2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Com)))
  "Returns md5sum for a message object of type 'Com"
  "6a6a2fdbdfea337c6d5c872e8c0b98e2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Com>)))
  "Returns full string definition for message of type '<Com>"
  (cl:format cl:nil "string message~%geometry_msgs/Twist vel~%~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Com)))
  "Returns full string definition for message of type 'Com"
  (cl:format cl:nil "string message~%geometry_msgs/Twist vel~%~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Com>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'message))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'vel))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Com>))
  "Converts a ROS message object to a list"
  (cl:list 'Com
    (cl:cons ':message (message msg))
    (cl:cons ':vel (vel msg))
))
