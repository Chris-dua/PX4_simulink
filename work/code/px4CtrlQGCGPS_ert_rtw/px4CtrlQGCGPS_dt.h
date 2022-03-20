//
//  px4CtrlQGCGPS_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "px4CtrlQGCGPS".
//
//  Model version              : 5.30
//  Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
//  C++ source code generated on : Fri Mar 18 18:41:57 2022
//
//  Target selection: ert.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex
//  Code generation objectives: Unspecified
//  Validation result: Not run


#include "ext_types.h"

// data type size table
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(int64_T),
  sizeof(uint64_T),
  sizeof(px4_Bus_actuator_outputs),
  sizeof(px4_Bus_vehicle_odometry),
  sizeof(px4_internal_block_PWM_px4Ctr_T),
  sizeof(px4_internal_block_Subscriber_T),
  sizeof(uint64_T),
  sizeof(int64_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

// data type name table
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "int64_T",
  "uint64_T",
  "px4_Bus_actuator_outputs",
  "px4_Bus_vehicle_odometry",
  "px4_internal_block_PWM_px4Ctr_T",
  "px4_internal_block_Subscriber_T",
  "uint64_T",
  "int64_T",
  "char_T",
  "uchar_T",
  "time_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&px4CtrlQGCGPS_B.In1), 18, 0, 1 },

  { (char_T *)(&px4CtrlQGCGPS_B.In1_a), 17, 0, 1 },

  { (char_T *)(&px4CtrlQGCGPS_B.Gain2), 0, 0, 44 },

  { (char_T *)(&px4CtrlQGCGPS_B.output[0]), 1, 0, 16 },

  { (char_T *)(&px4CtrlQGCGPS_B.NOT), 8, 0, 2 }
  ,

  { (char_T *)(&px4CtrlQGCGPS_DW.obj), 19, 0, 1 },

  { (char_T *)(&px4CtrlQGCGPS_DW.obj_n), 20, 0, 2 },

  { (char_T *)(&px4CtrlQGCGPS_DW.UD_DSTATE), 0, 0, 40 },

  { (char_T *)(&px4CtrlQGCGPS_DW.Scope_PWORK.LoggedData), 11, 0, 17 },

  { (char_T *)(&px4CtrlQGCGPS_DW.systemEnable), 6, 0, 1 },

  { (char_T *)(&px4CtrlQGCGPS_DW.Subsystem1_SubsysRanBC), 2, 0, 9 },

  { (char_T *)(&px4CtrlQGCGPS_DW.attitude_flag), 8, 0, 3 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  12U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&px4CtrlQGCGPS_P.DiscreteDerivative1_ICPrevScale), 0, 0, 12 },

  { (char_T *)(&px4CtrlQGCGPS_P.Out1_Y0), 18, 0, 1 },

  { (char_T *)(&px4CtrlQGCGPS_P.Constant_Value), 18, 0, 1 },

  { (char_T *)(&px4CtrlQGCGPS_P.Out1_Y0_k), 17, 0, 1 },

  { (char_T *)(&px4CtrlQGCGPS_P.Constant_Value_c), 17, 0, 1 },

  { (char_T *)(&px4CtrlQGCGPS_P.Constant1_Value), 0, 0, 316 },

  { (char_T *)(&px4CtrlQGCGPS_P.attitude_flag_Value), 8, 0, 8 },

  { (char_T *)(&px4CtrlQGCGPS_P.ManualSwitch_CurrentSetting), 3, 0, 2 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  8U,
  rtPTransitions
};

// [EOF] px4CtrlQGCGPS_dt.h
