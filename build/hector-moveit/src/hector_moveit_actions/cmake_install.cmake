# Install script for directory: /home/rishabh/quad_ws/src/hector-moveit/src/hector_moveit_actions

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/rishabh/quad_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hector_moveit_actions/action" TYPE FILE FILES "/home/rishabh/quad_ws/src/hector-moveit/src/hector_moveit_actions/action/ExecuteDroneTrajectory.action")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hector_moveit_actions/msg" TYPE FILE FILES
    "/home/rishabh/quad_ws/devel/share/hector_moveit_actions/msg/ExecuteDroneTrajectoryAction.msg"
    "/home/rishabh/quad_ws/devel/share/hector_moveit_actions/msg/ExecuteDroneTrajectoryActionGoal.msg"
    "/home/rishabh/quad_ws/devel/share/hector_moveit_actions/msg/ExecuteDroneTrajectoryActionResult.msg"
    "/home/rishabh/quad_ws/devel/share/hector_moveit_actions/msg/ExecuteDroneTrajectoryActionFeedback.msg"
    "/home/rishabh/quad_ws/devel/share/hector_moveit_actions/msg/ExecuteDroneTrajectoryGoal.msg"
    "/home/rishabh/quad_ws/devel/share/hector_moveit_actions/msg/ExecuteDroneTrajectoryResult.msg"
    "/home/rishabh/quad_ws/devel/share/hector_moveit_actions/msg/ExecuteDroneTrajectoryFeedback.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hector_moveit_actions/cmake" TYPE FILE FILES "/home/rishabh/quad_ws/build/hector-moveit/src/hector_moveit_actions/catkin_generated/installspace/hector_moveit_actions-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/rishabh/quad_ws/devel/include/hector_moveit_actions")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/rishabh/quad_ws/devel/share/roseus/ros/hector_moveit_actions")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/rishabh/quad_ws/devel/share/common-lisp/ros/hector_moveit_actions")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/rishabh/quad_ws/devel/share/gennodejs/ros/hector_moveit_actions")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/rishabh/quad_ws/devel/lib/python2.7/dist-packages/hector_moveit_actions")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/rishabh/quad_ws/devel/lib/python2.7/dist-packages/hector_moveit_actions")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/rishabh/quad_ws/build/hector-moveit/src/hector_moveit_actions/catkin_generated/installspace/hector_moveit_actions.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hector_moveit_actions/cmake" TYPE FILE FILES "/home/rishabh/quad_ws/build/hector-moveit/src/hector_moveit_actions/catkin_generated/installspace/hector_moveit_actions-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hector_moveit_actions/cmake" TYPE FILE FILES
    "/home/rishabh/quad_ws/build/hector-moveit/src/hector_moveit_actions/catkin_generated/installspace/hector_moveit_actionsConfig.cmake"
    "/home/rishabh/quad_ws/build/hector-moveit/src/hector_moveit_actions/catkin_generated/installspace/hector_moveit_actionsConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hector_moveit_actions" TYPE FILE FILES "/home/rishabh/quad_ws/src/hector-moveit/src/hector_moveit_actions/package.xml")
endif()

