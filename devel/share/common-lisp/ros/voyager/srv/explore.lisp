; Auto-generated. Do not edit!


(cl:in-package voyager-srv)


;//! \htmlinclude explore-request.msg.html

(cl:defclass <explore-request> (roslisp-msg-protocol:ros-message)
  ((explore_flag
    :reader explore_flag
    :initarg :explore_flag
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass explore-request (<explore-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <explore-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'explore-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name voyager-srv:<explore-request> is deprecated: use voyager-srv:explore-request instead.")))

(cl:ensure-generic-function 'explore_flag-val :lambda-list '(m))
(cl:defmethod explore_flag-val ((m <explore-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader voyager-srv:explore_flag-val is deprecated.  Use voyager-srv:explore_flag instead.")
  (explore_flag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <explore-request>) ostream)
  "Serializes a message object of type '<explore-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'explore_flag) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <explore-request>) istream)
  "Deserializes a message object of type '<explore-request>"
    (cl:setf (cl:slot-value msg 'explore_flag) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<explore-request>)))
  "Returns string type for a service object of type '<explore-request>"
  "voyager/exploreRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'explore-request)))
  "Returns string type for a service object of type 'explore-request"
  "voyager/exploreRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<explore-request>)))
  "Returns md5sum for a message object of type '<explore-request>"
  "3561b7bcb5cf46f8618ac263475af545")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'explore-request)))
  "Returns md5sum for a message object of type 'explore-request"
  "3561b7bcb5cf46f8618ac263475af545")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<explore-request>)))
  "Returns full string definition for message of type '<explore-request>"
  (cl:format cl:nil "~%bool explore_flag~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'explore-request)))
  "Returns full string definition for message of type 'explore-request"
  (cl:format cl:nil "~%bool explore_flag~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <explore-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <explore-request>))
  "Converts a ROS message object to a list"
  (cl:list 'explore-request
    (cl:cons ':explore_flag (explore_flag msg))
))
;//! \htmlinclude explore-response.msg.html

(cl:defclass <explore-response> (roslisp-msg-protocol:ros-message)
  ((response
    :reader response
    :initarg :response
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass explore-response (<explore-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <explore-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'explore-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name voyager-srv:<explore-response> is deprecated: use voyager-srv:explore-response instead.")))

(cl:ensure-generic-function 'response-val :lambda-list '(m))
(cl:defmethod response-val ((m <explore-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader voyager-srv:response-val is deprecated.  Use voyager-srv:response instead.")
  (response m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <explore-response>) ostream)
  "Serializes a message object of type '<explore-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'response) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <explore-response>) istream)
  "Deserializes a message object of type '<explore-response>"
    (cl:setf (cl:slot-value msg 'response) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<explore-response>)))
  "Returns string type for a service object of type '<explore-response>"
  "voyager/exploreResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'explore-response)))
  "Returns string type for a service object of type 'explore-response"
  "voyager/exploreResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<explore-response>)))
  "Returns md5sum for a message object of type '<explore-response>"
  "3561b7bcb5cf46f8618ac263475af545")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'explore-response)))
  "Returns md5sum for a message object of type 'explore-response"
  "3561b7bcb5cf46f8618ac263475af545")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<explore-response>)))
  "Returns full string definition for message of type '<explore-response>"
  (cl:format cl:nil "~%bool response~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'explore-response)))
  "Returns full string definition for message of type 'explore-response"
  (cl:format cl:nil "~%bool response~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <explore-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <explore-response>))
  "Converts a ROS message object to a list"
  (cl:list 'explore-response
    (cl:cons ':response (response msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'explore)))
  'explore-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'explore)))
  'explore-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'explore)))
  "Returns string type for a service object of type '<explore>"
  "voyager/explore")