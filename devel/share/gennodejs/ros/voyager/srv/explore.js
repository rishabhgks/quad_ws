// Auto-generated. Do not edit!

// (in-package voyager.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class exploreRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.explore_flag = null;
    }
    else {
      if (initObj.hasOwnProperty('explore_flag')) {
        this.explore_flag = initObj.explore_flag
      }
      else {
        this.explore_flag = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type exploreRequest
    // Serialize message field [explore_flag]
    bufferOffset = _serializer.bool(obj.explore_flag, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type exploreRequest
    let len;
    let data = new exploreRequest(null);
    // Deserialize message field [explore_flag]
    data.explore_flag = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'voyager/exploreRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5d83e813143e1861cd89e2b2b45c22d8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    bool explore_flag
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new exploreRequest(null);
    if (msg.explore_flag !== undefined) {
      resolved.explore_flag = msg.explore_flag;
    }
    else {
      resolved.explore_flag = false
    }

    return resolved;
    }
};

class exploreResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.response = null;
    }
    else {
      if (initObj.hasOwnProperty('response')) {
        this.response = initObj.response
      }
      else {
        this.response = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type exploreResponse
    // Serialize message field [response]
    bufferOffset = _serializer.bool(obj.response, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type exploreResponse
    let len;
    let data = new exploreResponse(null);
    // Deserialize message field [response]
    data.response = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'voyager/exploreResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '003b81baa95ab323fc1ddf3c7d0bee81';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    bool response
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new exploreResponse(null);
    if (msg.response !== undefined) {
      resolved.response = msg.response;
    }
    else {
      resolved.response = false
    }

    return resolved;
    }
};

module.exports = {
  Request: exploreRequest,
  Response: exploreResponse,
  md5sum() { return '3561b7bcb5cf46f8618ac263475af545'; },
  datatype() { return 'voyager/explore'; }
};
