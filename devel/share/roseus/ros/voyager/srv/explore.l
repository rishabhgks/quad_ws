;; Auto-generated. Do not edit!


(when (boundp 'voyager::explore)
  (if (not (find-package "VOYAGER"))
    (make-package "VOYAGER"))
  (shadow 'explore (find-package "VOYAGER")))
(unless (find-package "VOYAGER::EXPLORE")
  (make-package "VOYAGER::EXPLORE"))
(unless (find-package "VOYAGER::EXPLOREREQUEST")
  (make-package "VOYAGER::EXPLOREREQUEST"))
(unless (find-package "VOYAGER::EXPLORERESPONSE")
  (make-package "VOYAGER::EXPLORERESPONSE"))

(in-package "ROS")





(defclass voyager::exploreRequest
  :super ros::object
  :slots (_explore_flag ))

(defmethod voyager::exploreRequest
  (:init
   (&key
    ((:explore_flag __explore_flag) nil)
    )
   (send-super :init)
   (setq _explore_flag __explore_flag)
   self)
  (:explore_flag
   (&optional __explore_flag)
   (if __explore_flag (setq _explore_flag __explore_flag)) _explore_flag)
  (:serialization-length
   ()
   (+
    ;; bool _explore_flag
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _explore_flag
       (if _explore_flag (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _explore_flag
     (setq _explore_flag (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass voyager::exploreResponse
  :super ros::object
  :slots (_response ))

(defmethod voyager::exploreResponse
  (:init
   (&key
    ((:response __response) nil)
    )
   (send-super :init)
   (setq _response __response)
   self)
  (:response
   (&optional __response)
   (if __response (setq _response __response)) _response)
  (:serialization-length
   ()
   (+
    ;; bool _response
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _response
       (if _response (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _response
     (setq _response (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass voyager::explore
  :super ros::object
  :slots ())

(setf (get voyager::explore :md5sum-) "3561b7bcb5cf46f8618ac263475af545")
(setf (get voyager::explore :datatype-) "voyager/explore")
(setf (get voyager::explore :request) voyager::exploreRequest)
(setf (get voyager::explore :response) voyager::exploreResponse)

(defmethod voyager::exploreRequest
  (:response () (instance voyager::exploreResponse :init)))

(setf (get voyager::exploreRequest :md5sum-) "3561b7bcb5cf46f8618ac263475af545")
(setf (get voyager::exploreRequest :datatype-) "voyager/exploreRequest")
(setf (get voyager::exploreRequest :definition-)
      "
bool explore_flag
---

bool response
")

(setf (get voyager::exploreResponse :md5sum-) "3561b7bcb5cf46f8618ac263475af545")
(setf (get voyager::exploreResponse :datatype-) "voyager/exploreResponse")
(setf (get voyager::exploreResponse :definition-)
      "
bool explore_flag
---

bool response
")



(provide :voyager/explore "3561b7bcb5cf46f8618ac263475af545")


