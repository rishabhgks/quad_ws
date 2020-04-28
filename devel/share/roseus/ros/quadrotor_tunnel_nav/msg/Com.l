;; Auto-generated. Do not edit!


(when (boundp 'quadrotor_tunnel_nav::Com)
  (if (not (find-package "QUADROTOR_TUNNEL_NAV"))
    (make-package "QUADROTOR_TUNNEL_NAV"))
  (shadow 'Com (find-package "QUADROTOR_TUNNEL_NAV")))
(unless (find-package "QUADROTOR_TUNNEL_NAV::COM")
  (make-package "QUADROTOR_TUNNEL_NAV::COM"))

(in-package "ROS")
;;//! \htmlinclude Com.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass quadrotor_tunnel_nav::Com
  :super ros::object
  :slots (_message _vel ))

(defmethod quadrotor_tunnel_nav::Com
  (:init
   (&key
    ((:message __message) "")
    ((:vel __vel) (instance geometry_msgs::Twist :init))
    )
   (send-super :init)
   (setq _message (string __message))
   (setq _vel __vel)
   self)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:vel
   (&rest __vel)
   (if (keywordp (car __vel))
       (send* _vel __vel)
     (progn
       (if __vel (setq _vel (car __vel)))
       _vel)))
  (:serialization-length
   ()
   (+
    ;; string _message
    4 (length _message)
    ;; geometry_msgs/Twist _vel
    (send _vel :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _message
       (write-long (length _message) s) (princ _message s)
     ;; geometry_msgs/Twist _vel
       (send _vel :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; geometry_msgs/Twist _vel
     (send _vel :deserialize buf ptr-) (incf ptr- (send _vel :serialization-length))
   ;;
   self)
  )

(setf (get quadrotor_tunnel_nav::Com :md5sum-) "6a6a2fdbdfea337c6d5c872e8c0b98e2")
(setf (get quadrotor_tunnel_nav::Com :datatype-) "quadrotor_tunnel_nav/Com")
(setf (get quadrotor_tunnel_nav::Com :definition-)
      "string message
geometry_msgs/Twist vel


================================================================================
MSG: geometry_msgs/Twist
# This expresses velocity in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
")



(provide :quadrotor_tunnel_nav/Com "6a6a2fdbdfea337c6d5c872e8c0b98e2")


