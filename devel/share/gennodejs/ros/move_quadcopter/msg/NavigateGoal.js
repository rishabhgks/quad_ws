// Auto-generated. Do not edit!

// (in-package move_quadcopter.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class NavigateGoal {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.target_pos = null;
    }
    else {
      if (initObj.hasOwnProperty('target_pos')) {
        this.target_pos = initObj.target_pos
      }
      else {
        this.target_pos = new geometry_msgs.msg.Point();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type NavigateGoal
    // Serialize message field [target_pos]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.target_pos, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type NavigateGoal
    let len;
    let data = new NavigateGoal(null);
    // Deserialize message field [target_pos]
    data.target_pos = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'move_quadcopter/NavigateGoal';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '332449a2fcdc11c82bafadb9df2b64d8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
    # goal point for navigation action
    geometry_msgs/Point target_pos
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new NavigateGoal(null);
    if (msg.target_pos !== undefined) {
      resolved.target_pos = geometry_msgs.msg.Point.Resolve(msg.target_pos)
    }
    else {
      resolved.target_pos = new geometry_msgs.msg.Point()
    }

    return resolved;
    }
};

module.exports = NavigateGoal;
