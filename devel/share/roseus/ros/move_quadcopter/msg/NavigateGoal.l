;; Auto-generated. Do not edit!


(when (boundp 'move_quadcopter::NavigateGoal)
  (if (not (find-package "MOVE_QUADCOPTER"))
    (make-package "MOVE_QUADCOPTER"))
  (shadow 'NavigateGoal (find-package "MOVE_QUADCOPTER")))
(unless (find-package "MOVE_QUADCOPTER::NAVIGATEGOAL")
  (make-package "MOVE_QUADCOPTER::NAVIGATEGOAL"))

(in-package "ROS")
;;//! \htmlinclude NavigateGoal.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass move_quadcopter::NavigateGoal
  :super ros::object
  :slots (_target_pos ))

(defmethod move_quadcopter::NavigateGoal
  (:init
   (&key
    ((:target_pos __target_pos) (instance geometry_msgs::Point :init))
    )
   (send-super :init)
   (setq _target_pos __target_pos)
   self)
  (:target_pos
   (&rest __target_pos)
   (if (keywordp (car __target_pos))
       (send* _target_pos __target_pos)
     (progn
       (if __target_pos (setq _target_pos (car __target_pos)))
       _target_pos)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point _target_pos
    (send _target_pos :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point _target_pos
       (send _target_pos :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point _target_pos
     (send _target_pos :deserialize buf ptr-) (incf ptr- (send _target_pos :serialization-length))
   ;;
   self)
  )

(setf (get move_quadcopter::NavigateGoal :md5sum-) "332449a2fcdc11c82bafadb9df2b64d8")
(setf (get move_quadcopter::NavigateGoal :datatype-) "move_quadcopter/NavigateGoal")
(setf (get move_quadcopter::NavigateGoal :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
# goal point for navigation action
geometry_msgs/Point target_pos

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :move_quadcopter/NavigateGoal "332449a2fcdc11c82bafadb9df2b64d8")


