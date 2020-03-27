
"use strict";

let Compass = require('./Compass.js');
let ThrustCommand = require('./ThrustCommand.js');
let YawrateCommand = require('./YawrateCommand.js');
let RawRC = require('./RawRC.js');
let RC = require('./RC.js');
let MotorCommand = require('./MotorCommand.js');
let MotorPWM = require('./MotorPWM.js');
let VelocityZCommand = require('./VelocityZCommand.js');
let ServoCommand = require('./ServoCommand.js');
let HeightCommand = require('./HeightCommand.js');
let RawMagnetic = require('./RawMagnetic.js');
let RawImu = require('./RawImu.js');
let MotorStatus = require('./MotorStatus.js');
let Altimeter = require('./Altimeter.js');
let VelocityXYCommand = require('./VelocityXYCommand.js');
let AttitudeCommand = require('./AttitudeCommand.js');
let PositionXYCommand = require('./PositionXYCommand.js');
let RuddersCommand = require('./RuddersCommand.js');
let HeadingCommand = require('./HeadingCommand.js');
let ControllerState = require('./ControllerState.js');
let Supply = require('./Supply.js');
let LandingGoal = require('./LandingGoal.js');
let LandingAction = require('./LandingAction.js');
let PoseFeedback = require('./PoseFeedback.js');
let TakeoffFeedback = require('./TakeoffFeedback.js');
let LandingFeedback = require('./LandingFeedback.js');
let LandingActionFeedback = require('./LandingActionFeedback.js');
let TakeoffActionFeedback = require('./TakeoffActionFeedback.js');
let LandingActionResult = require('./LandingActionResult.js');
let TakeoffAction = require('./TakeoffAction.js');
let TakeoffActionGoal = require('./TakeoffActionGoal.js');
let PoseAction = require('./PoseAction.js');
let PoseActionResult = require('./PoseActionResult.js');
let TakeoffResult = require('./TakeoffResult.js');
let PoseActionGoal = require('./PoseActionGoal.js');
let PoseGoal = require('./PoseGoal.js');
let PoseResult = require('./PoseResult.js');
let LandingActionGoal = require('./LandingActionGoal.js');
let LandingResult = require('./LandingResult.js');
let TakeoffGoal = require('./TakeoffGoal.js');
let PoseActionFeedback = require('./PoseActionFeedback.js');
let TakeoffActionResult = require('./TakeoffActionResult.js');

module.exports = {
  Compass: Compass,
  ThrustCommand: ThrustCommand,
  YawrateCommand: YawrateCommand,
  RawRC: RawRC,
  RC: RC,
  MotorCommand: MotorCommand,
  MotorPWM: MotorPWM,
  VelocityZCommand: VelocityZCommand,
  ServoCommand: ServoCommand,
  HeightCommand: HeightCommand,
  RawMagnetic: RawMagnetic,
  RawImu: RawImu,
  MotorStatus: MotorStatus,
  Altimeter: Altimeter,
  VelocityXYCommand: VelocityXYCommand,
  AttitudeCommand: AttitudeCommand,
  PositionXYCommand: PositionXYCommand,
  RuddersCommand: RuddersCommand,
  HeadingCommand: HeadingCommand,
  ControllerState: ControllerState,
  Supply: Supply,
  LandingGoal: LandingGoal,
  LandingAction: LandingAction,
  PoseFeedback: PoseFeedback,
  TakeoffFeedback: TakeoffFeedback,
  LandingFeedback: LandingFeedback,
  LandingActionFeedback: LandingActionFeedback,
  TakeoffActionFeedback: TakeoffActionFeedback,
  LandingActionResult: LandingActionResult,
  TakeoffAction: TakeoffAction,
  TakeoffActionGoal: TakeoffActionGoal,
  PoseAction: PoseAction,
  PoseActionResult: PoseActionResult,
  TakeoffResult: TakeoffResult,
  PoseActionGoal: PoseActionGoal,
  PoseGoal: PoseGoal,
  PoseResult: PoseResult,
  LandingActionGoal: LandingActionGoal,
  LandingResult: LandingResult,
  TakeoffGoal: TakeoffGoal,
  PoseActionFeedback: PoseActionFeedback,
  TakeoffActionResult: TakeoffActionResult,
};
