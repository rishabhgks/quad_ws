
(cl:in-package :asdf)

(defsystem "voyager-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "explore" :depends-on ("_package_explore"))
    (:file "_package_explore" :depends-on ("_package"))
  ))