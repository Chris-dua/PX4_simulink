//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4_noGPS3.cpp
//
// Code generated for Simulink model 'px4_noGPS3'.
//
// Model version                  : 5.151
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Mar 23 19:19:54 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "px4_noGPS3.h"
#include "px4_noGPS3_types.h"
#include "rtwtypes.h"
#include <math.h>
#include "px4_noGPS3_private.h"

extern "C" {

#include "rt_nonfinite.h"

}
#include "rt_defines.h"

// Block signals (default storage)
B_px4_noGPS3_T px4_noGPS3_B;

// Block states (default storage)
DW_px4_noGPS3_T px4_noGPS3_DW;

// Real-time model
RT_MODEL_px4_noGPS3_T px4_noGPS3_M_ = RT_MODEL_px4_noGPS3_T();
RT_MODEL_px4_noGPS3_T *const px4_noGPS3_M = &px4_noGPS3_M_;

// Forward declaration for local functions
static void px4_noGPS3_SystemCore_setup(px4_internal_block_PWM_px4_no_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void px4_noGPS3_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(px4_noGPS3_M, 1));
}

//
//         This function updates active task flag for each subrate
//         and rate transition flags for tasks that exchange data.
//         The function assumes rate-monotonic multitasking scheduler.
//         The function must be called at model base rate so that
//         the generated code self-manages all its subrates and rate
//         transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (px4_noGPS3_M->Timing.TaskCounters.TID[1])++;
  if ((px4_noGPS3_M->Timing.TaskCounters.TID[1]) > 1) {// Sample time: [0.01s, 0.0s] 
    px4_noGPS3_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T u0_0;
    int32_T u1_0;
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void px4_noGPS3_SystemCore_setup(px4_internal_block_PWM_px4_no_T *obj,
  boolean_T varargin_1, boolean_T varargin_2)
{
  uint16_T status;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->isMain = true;
  obj->pwmDevObj = MW_PWM_OUTPUT_MAIN_DEVICE_PATH;
  status = pwm_open(&obj->pwmDevHandler, obj->pwmDevObj,
                    &obj->actuatorAdvertiseObj, &obj->armAdvertiseObj);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  obj->servoCount = 0;
  status = pwm_getServoCount(&obj->pwmDevHandler, &obj->servoCount);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  if (varargin_1) {
    status = pwm_arm(&obj->pwmDevHandler, &obj->armAdvertiseObj);
    obj->isArmed = true;
  } else {
    status = pwm_disarm(&obj->pwmDevHandler, &obj->armAdvertiseObj);
    obj->isArmed = false;
  }

  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  status = pwm_setPWMRate(&obj->pwmDevHandler, obj->isMain);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  obj->channelMask = 15;
  status = pwm_setChannelMask(&obj->pwmDevHandler, obj->channelMask);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  status = pwm_setFailsafePWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  status = pwm_setDisarmedPWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain, &obj->actuatorAdvertiseObj);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  if (obj->isMain) {
    status = pwm_forceFailsafe(&obj->pwmDevHandler, static_cast<int32_T>
      (varargin_2));
    obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
    status = pwm_forceTerminateFailsafe(&obj->pwmDevHandler, 0);
    obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  }

  obj->isSetupComplete = true;
}

// Model step function for TID0
void px4_noGPS3_step0(void)            // Sample time: [0.005s, 0.0s]
{
  real_T pitch_thrust;
  real_T roll_thrust;
  real_T rtb_DataTypeConversion3_idx_1;
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  real_T yaw_thrust;
  uint16_T status;
  boolean_T b_varargout_1;

  {                                    // Sample time: [0.005s, 0.0s]
    rate_monotonic_scheduler();
  }

  // Switch: '<S15>/Switch1' incorporates:
  //   Constant: '<S15>/Constant2'
  //   DataStoreRead: '<S15>/Data Store Read2'

  if (px4_noGPS3_DW.attitude_flag) {
    rtb_DataTypeConversion3_idx_1 = 0.0;
  } else {
    // Trigonometry: '<S30>/Trigonometric Function1' incorporates:
    //   Constant: '<S15>/Constant2'

    px4_noGPS3_DW.yaw = px4_noGPS3_P.Constant2_Value_i;
    rtb_DataTypeConversion3_idx_1 = px4_noGPS3_P.Constant2_Value_i;
    px4_noGPS3_DW.yaw_speed = px4_noGPS3_P.Constant2_Value_i;
  }

  // ZeroOrderHold: '<S15>/Zero-Order Hold1'
  px4_noGPS3_B.fcn3 = rtb_DataTypeConversion3_idx_1;

  // Sum: '<S15>/Add3' incorporates:
  //   ZeroOrderHold: '<S15>/Zero-Order Hold'

  px4_noGPS3_B.Add3 = px4_noGPS3_DW.yaw - px4_noGPS3_B.fcn3;

  // SampleTimeMath: '<S20>/TSamp'
  //
  //  About '<S20>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS3_B.TSamp = rtb_DataTypeConversion3_idx_1 * px4_noGPS3_P.TSamp_WtEt;

  // ZeroOrderHold: '<S15>/Zero-Order Hold2' incorporates:
  //   Sum: '<S20>/Diff'
  //   UnitDelay: '<S20>/UD'
  //
  //  Block description for '<S20>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S20>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_B.fcn3 = px4_noGPS3_B.TSamp - px4_noGPS3_DW.UD_DSTATE;

  // Sum: '<S15>/Add4' incorporates:
  //   ZeroOrderHold: '<S15>/Zero-Order Hold3'

  px4_noGPS3_B.Add4 = px4_noGPS3_DW.yaw_speed - px4_noGPS3_B.fcn3;

  // SampleTimeMath: '<S21>/TSamp' incorporates:
  //   ZeroOrderHold: '<S15>/Zero-Order Hold3'
  //
  //  About '<S21>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS3_B.TSamp_p = px4_noGPS3_DW.yaw_speed * px4_noGPS3_P.TSamp_WtEt_p;

  // ManualSwitch: '<S1>/Manual Switch' incorporates:
  //   Constant: '<S1>/Constant'
  //   DataStoreWrite: '<Root>/Data Store Write11'

  if (px4_noGPS3_P.ManualSwitch_CurrentSetting == 1) {
    // Switch: '<S15>/Switch2' incorporates:
    //   Constant: '<S15>/Constant3'
    //   DataStoreRead: '<S15>/Data Store Read5'

    if (px4_noGPS3_DW.s6_yaw > px4_noGPS3_P.Switch2_Threshold) {
      rtb_DataTypeConversion3_idx_1 = px4_noGPS3_P.Constant3_Value_o;
    } else {
      rtb_DataTypeConversion3_idx_1 = 0.0;
    }

    // End of Switch: '<S15>/Switch2'

    // Sum: '<S15>/Add6' incorporates:
    //   Constant: '<S15>/Constant'
    //   Gain: '<S15>/Gain2'
    //   Gain: '<S15>/Gain3'
    //   Gain: '<S15>/Gain4'
    //   Gain: '<S15>/Gain5'
    //   Gain: '<S15>/Gain6'
    //   Gain: '<S15>/Gain8'
    //   Product: '<S15>/Divide'
    //   Sum: '<S15>/Add5'
    //   Sum: '<S21>/Diff'
    //   UnitDelay: '<S21>/UD'
    //   ZeroOrderHold: '<S15>/Zero-Order Hold3'
    //
    //  Block description for '<S21>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S21>/UD':
    //
    //   Store in Global RAM

    yaw_thrust = ((((px4_noGPS3_P.Gain3_Gain * px4_noGPS3_B.Add3 +
                     px4_noGPS3_B.Add4) * px4_noGPS3_P.Gain2_Gain +
                    px4_noGPS3_P.Gain4_Gain * px4_noGPS3_B.Add4) +
                   px4_noGPS3_P.Gain5_Gain * px4_noGPS3_DW.yaw_speed *
                   px4_noGPS3_P.Gain6_Gain / px4_noGPS3_P.Constant_Value_l) +
                  (px4_noGPS3_B.TSamp_p - px4_noGPS3_DW.UD_DSTATE_j)) +
      px4_noGPS3_P.Gain8_Gain * rtb_DataTypeConversion3_idx_1;

    // Saturate: '<S1>/Saturation'
    if (yaw_thrust > px4_noGPS3_P.Saturation_UpperSat) {
      yaw_thrust = px4_noGPS3_P.Saturation_UpperSat;
    } else if (yaw_thrust < px4_noGPS3_P.Saturation_LowerSat) {
      yaw_thrust = px4_noGPS3_P.Saturation_LowerSat;
    }

    // End of Saturate: '<S1>/Saturation'
  } else {
    yaw_thrust = px4_noGPS3_P.Constant_Value_b;
  }

  // End of ManualSwitch: '<S1>/Manual Switch'

  // Switch: '<S13>/Switch1' incorporates:
  //   Constant: '<S13>/Constant2'
  //   DataStoreRead: '<Root>/Data Store Read69'
  //   DataStoreRead: '<S13>/Data Store Read2'

  if (px4_noGPS3_DW.attitude_flag) {
    // ZeroOrderHold: '<S13>/Zero-Order Hold' incorporates:
    //   DataStoreRead: '<Root>/Data Store Read14'

    px4_noGPS3_B.fcn3 = px4_noGPS3_DW.pitch;
    rtb_DataTypeConversion3_idx_1 = px4_noGPS3_DW.pitch_desire;

    // Switch: '<S15>/Switch1' incorporates:
    //   DataStoreRead: '<Root>/Data Store Read69'
    //   DataStoreRead: '<S13>/Data Store Read3'

    px4_noGPS3_DW.yaw_speed = px4_noGPS3_DW.pitch_speed;
  } else {
    // ZeroOrderHold: '<S13>/Zero-Order Hold' incorporates:
    //   Constant: '<S13>/Constant2'

    px4_noGPS3_B.fcn3 = px4_noGPS3_P.Constant2_Value;
    rtb_DataTypeConversion3_idx_1 = px4_noGPS3_P.Constant2_Value;

    // Switch: '<S15>/Switch1' incorporates:
    //   Constant: '<S13>/Constant2'

    px4_noGPS3_DW.yaw_speed = px4_noGPS3_P.Constant2_Value;
  }

  // End of Switch: '<S13>/Switch1'

  // Sum: '<S13>/Add3' incorporates:
  //   ZeroOrderHold: '<S13>/Zero-Order Hold1'

  px4_noGPS3_B.fcn3 -= rtb_DataTypeConversion3_idx_1;

  // SampleTimeMath: '<S16>/TSamp'
  //
  //  About '<S16>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS3_B.TSamp_e = rtb_DataTypeConversion3_idx_1 *
    px4_noGPS3_P.TSamp_WtEt_j;

  // ZeroOrderHold: '<S13>/Zero-Order Hold2' incorporates:
  //   Sum: '<S16>/Diff'
  //   UnitDelay: '<S16>/UD'
  //
  //  Block description for '<S16>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S16>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_B.roll_desire = px4_noGPS3_B.TSamp_e - px4_noGPS3_DW.UD_DSTATE_d;

  // Sum: '<S13>/Add4' incorporates:
  //   ZeroOrderHold: '<S13>/Zero-Order Hold3'

  px4_noGPS3_B.roll_desire = px4_noGPS3_DW.yaw_speed - px4_noGPS3_B.roll_desire;

  // SampleTimeMath: '<S17>/TSamp' incorporates:
  //   ZeroOrderHold: '<S13>/Zero-Order Hold3'
  //
  //  About '<S17>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS3_B.TSamp_pa = px4_noGPS3_DW.yaw_speed * px4_noGPS3_P.TSamp_WtEt_k;

  // Switch: '<S13>/Switch2' incorporates:
  //   Constant: '<S13>/Constant3'
  //   Constant: '<S13>/Constant4'
  //   DataStoreRead: '<S13>/Data Store Read4'

  if (px4_noGPS3_DW.s4_pitch > px4_noGPS3_P.Switch2_Threshold_g) {
    px4_noGPS3_B.roll = px4_noGPS3_P.Constant3_Value;
  } else {
    px4_noGPS3_B.roll = px4_noGPS3_P.Constant4_Value;
  }

  // End of Switch: '<S13>/Switch2'

  // Sum: '<S13>/Add6' incorporates:
  //   Constant: '<S13>/Constant'
  //   DataStoreWrite: '<Root>/Data Store Write12'
  //   Gain: '<S13>/Gain2'
  //   Gain: '<S13>/Gain3'
  //   Gain: '<S13>/Gain4'
  //   Gain: '<S13>/Gain5'
  //   Gain: '<S13>/Gain6'
  //   Gain: '<S13>/Gain8'
  //   Product: '<S13>/Divide'
  //   Sum: '<S13>/Add5'
  //   Sum: '<S17>/Diff'
  //   UnitDelay: '<S17>/UD'
  //   ZeroOrderHold: '<S13>/Zero-Order Hold3'
  //
  //  Block description for '<S17>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S17>/UD':
  //
  //   Store in Global RAM

  pitch_thrust = ((((px4_noGPS3_P.Gain3_Gain_g * px4_noGPS3_B.fcn3 +
                     px4_noGPS3_B.roll_desire) * px4_noGPS3_P.Gain2_Gain_c +
                    px4_noGPS3_P.Gain4_Gain_n * px4_noGPS3_B.roll_desire) +
                   px4_noGPS3_P.Gain5_Gain_i * px4_noGPS3_DW.yaw_speed *
                   px4_noGPS3_P.Gain6_Gain_j / px4_noGPS3_P.Constant_Value_i) +
                  (px4_noGPS3_B.TSamp_pa - px4_noGPS3_DW.UD_DSTATE_dv)) +
    px4_noGPS3_P.Gain8_Gain_g * px4_noGPS3_B.roll;

  // Switch: '<S14>/Switch1' incorporates:
  //   Constant: '<S14>/Constant2'
  //   DataStoreRead: '<Root>/Data Store Read68'
  //   DataStoreRead: '<S14>/Data Store Read2'

  if (px4_noGPS3_DW.attitude_flag) {
    // ZeroOrderHold: '<S14>/Zero-Order Hold' incorporates:
    //   DataStoreRead: '<Root>/Data Store Read18'

    px4_noGPS3_B.roll = px4_noGPS3_DW.roll;
    rtb_DataTypeConversion3_idx_1 = px4_noGPS3_DW.roll_desire;

    // Switch: '<S15>/Switch1' incorporates:
    //   DataStoreRead: '<Root>/Data Store Read68'
    //   DataStoreRead: '<S14>/Data Store Read3'

    px4_noGPS3_DW.yaw_speed = px4_noGPS3_DW.roll_speed;
  } else {
    // ZeroOrderHold: '<S14>/Zero-Order Hold' incorporates:
    //   Constant: '<S14>/Constant2'

    px4_noGPS3_B.roll = px4_noGPS3_P.Constant2_Value_f;
    rtb_DataTypeConversion3_idx_1 = px4_noGPS3_P.Constant2_Value_f;

    // Switch: '<S15>/Switch1' incorporates:
    //   Constant: '<S14>/Constant2'

    px4_noGPS3_DW.yaw_speed = px4_noGPS3_P.Constant2_Value_f;
  }

  // End of Switch: '<S14>/Switch1'

  // Sum: '<S14>/Add3' incorporates:
  //   ZeroOrderHold: '<S14>/Zero-Order Hold1'

  px4_noGPS3_B.roll -= rtb_DataTypeConversion3_idx_1;

  // SampleTimeMath: '<S18>/TSamp'
  //
  //  About '<S18>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS3_B.TSamp_k = rtb_DataTypeConversion3_idx_1 *
    px4_noGPS3_P.TSamp_WtEt_e;

  // ZeroOrderHold: '<S14>/Zero-Order Hold2' incorporates:
  //   Sum: '<S18>/Diff'
  //   UnitDelay: '<S18>/UD'
  //
  //  Block description for '<S18>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S18>/UD':
  //
  //   Store in Global RAM

  rtb_DataTypeConversion3_idx_1 = px4_noGPS3_B.TSamp_k -
    px4_noGPS3_DW.UD_DSTATE_a;

  // Sum: '<S14>/Add4' incorporates:
  //   ZeroOrderHold: '<S14>/Zero-Order Hold3'

  rtb_DataTypeConversion3_idx_1 = px4_noGPS3_DW.yaw_speed -
    rtb_DataTypeConversion3_idx_1;

  // SampleTimeMath: '<S19>/TSamp' incorporates:
  //   ZeroOrderHold: '<S14>/Zero-Order Hold3'
  //
  //  About '<S19>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS3_B.TSamp_d = px4_noGPS3_DW.yaw_speed * px4_noGPS3_P.TSamp_WtEt_m;

  // Switch: '<S14>/Switch2' incorporates:
  //   Constant: '<S14>/Constant3'
  //   Constant: '<S14>/Constant4'
  //   DataStoreRead: '<S14>/Data Store Read4'

  if (px4_noGPS3_DW.s5_roll > px4_noGPS3_P.Switch2_Threshold_m) {
    px4_noGPS3_B.DataStoreRead48 = px4_noGPS3_P.Constant3_Value_j;
  } else {
    px4_noGPS3_B.DataStoreRead48 = px4_noGPS3_P.Constant4_Value_b;
  }

  // End of Switch: '<S14>/Switch2'

  // Sum: '<S14>/Add6' incorporates:
  //   Constant: '<S14>/Constant'
  //   DataStoreWrite: '<Root>/Data Store Write13'
  //   Gain: '<S14>/Gain2'
  //   Gain: '<S14>/Gain3'
  //   Gain: '<S14>/Gain4'
  //   Gain: '<S14>/Gain5'
  //   Gain: '<S14>/Gain6'
  //   Gain: '<S14>/Gain8'
  //   Product: '<S14>/Divide'
  //   Sum: '<S14>/Add5'
  //   Sum: '<S19>/Diff'
  //   UnitDelay: '<S19>/UD'
  //   ZeroOrderHold: '<S14>/Zero-Order Hold3'
  //
  //  Block description for '<S19>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S19>/UD':
  //
  //   Store in Global RAM

  roll_thrust = ((((px4_noGPS3_P.Gain3_Gain_e * px4_noGPS3_B.roll +
                    rtb_DataTypeConversion3_idx_1) * px4_noGPS3_P.Gain2_Gain_cm
                   + px4_noGPS3_P.Gain4_Gain_a * rtb_DataTypeConversion3_idx_1)
                  + px4_noGPS3_P.Gain5_Gain_m * px4_noGPS3_DW.yaw_speed *
                  px4_noGPS3_P.Gain6_Gain_c / px4_noGPS3_P.Constant_Value_m) +
                 (px4_noGPS3_B.TSamp_d - px4_noGPS3_DW.UD_DSTATE_n)) +
    px4_noGPS3_P.Gain8_Gain_j * px4_noGPS3_B.DataStoreRead48;

  // Sum: '<S15>/Add7' incorporates:
  //   DataStoreWrite: '<S15>/Data Store Write1'
  //   Gain: '<S15>/Gain7'

  px4_noGPS3_DW.s6_yaw = px4_noGPS3_P.Gain7_Gain * px4_noGPS3_B.Add3 +
    px4_noGPS3_B.Add4;

  // Sum: '<S13>/Add7' incorporates:
  //   DataStoreWrite: '<S13>/Data Store Write1'
  //   Gain: '<S13>/Gain7'

  px4_noGPS3_DW.s4_pitch = px4_noGPS3_P.Gain7_Gain_d * px4_noGPS3_B.fcn3 +
    px4_noGPS3_B.roll_desire;

  // Sum: '<S14>/Add7' incorporates:
  //   DataStoreWrite: '<S14>/Data Store Write1'
  //   Gain: '<S14>/Gain7'

  px4_noGPS3_DW.s5_roll = px4_noGPS3_P.Gain7_Gain_k * px4_noGPS3_B.roll +
    rtb_DataTypeConversion3_idx_1;

  // MATLABSystem: '<S6>/SourceBlock'
  b_varargout_1 = uORB_read_step(px4_noGPS3_DW.obj_n.orbMetadataObj,
    &px4_noGPS3_DW.obj_n.eventStructObj, &px4_noGPS3_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S23>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S23>/In1'
    px4_noGPS3_B.In1 = px4_noGPS3_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // Product: '<S37>/Product' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4_noGPS3_B.DataStoreRead48 = static_cast<real_T>(px4_noGPS3_B.In1.q[0]) *
    px4_noGPS3_B.In1.q[0];

  // Product: '<S37>/Product1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  rtb_DataTypeConversion3_idx_1 = static_cast<real_T>(px4_noGPS3_B.In1.q[1]) *
    px4_noGPS3_B.In1.q[1];

  // Product: '<S37>/Product2' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4_noGPS3_B.roll = static_cast<real_T>(px4_noGPS3_B.In1.q[2]) *
    px4_noGPS3_B.In1.q[2];

  // Product: '<S37>/Product3' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4_noGPS3_B.roll_desire = static_cast<real_T>(px4_noGPS3_B.In1.q[3]) *
    px4_noGPS3_B.In1.q[3];

  // Sqrt: '<S36>/sqrt' incorporates:
  //   Sum: '<S37>/Sum'

  px4_noGPS3_B.DataStoreRead48 = sqrt(((px4_noGPS3_B.DataStoreRead48 +
    rtb_DataTypeConversion3_idx_1) + px4_noGPS3_B.roll) +
    px4_noGPS3_B.roll_desire);

  // Product: '<S31>/Product' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  rtb_DataTypeConversion3_idx_1 = px4_noGPS3_B.In1.q[0] /
    px4_noGPS3_B.DataStoreRead48;

  // Product: '<S31>/Product1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4_noGPS3_B.roll = px4_noGPS3_B.In1.q[1] / px4_noGPS3_B.DataStoreRead48;

  // Product: '<S31>/Product2' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4_noGPS3_B.roll_desire = px4_noGPS3_B.In1.q[2] /
    px4_noGPS3_B.DataStoreRead48;

  // Product: '<S31>/Product3' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4_noGPS3_B.DataStoreRead48 = px4_noGPS3_B.In1.q[3] /
    px4_noGPS3_B.DataStoreRead48;

  // Fcn: '<S8>/fcn1'
  px4_noGPS3_B.fcn3 = (px4_noGPS3_B.roll * px4_noGPS3_B.roll_desire +
                       rtb_DataTypeConversion3_idx_1 *
                       px4_noGPS3_B.DataStoreRead48) * 2.0;

  // Fcn: '<S8>/fcn2' incorporates:
  //   Fcn: '<S8>/fcn5'

  px4_noGPS3_B.Add4 = rtb_DataTypeConversion3_idx_1 *
    rtb_DataTypeConversion3_idx_1;
  px4_noGPS3_B.Subtract3 = px4_noGPS3_B.roll * px4_noGPS3_B.roll;
  rtb_Switch_idx_0 = px4_noGPS3_B.roll_desire * px4_noGPS3_B.roll_desire;
  px4_noGPS3_B.Diff_fb = px4_noGPS3_B.DataStoreRead48 *
    px4_noGPS3_B.DataStoreRead48;

  // Trigonometry: '<S30>/Trigonometric Function1' incorporates:
  //   DataStoreWrite: '<Root>/Data Store Write10'
  //   Fcn: '<S8>/fcn2'

  px4_noGPS3_DW.yaw = rt_atan2d_snf(px4_noGPS3_B.fcn3, ((px4_noGPS3_B.Add4 +
    px4_noGPS3_B.Subtract3) - rtb_Switch_idx_0) - px4_noGPS3_B.Diff_fb);

  // Fcn: '<S8>/fcn3'
  px4_noGPS3_B.fcn3 = (px4_noGPS3_B.roll * px4_noGPS3_B.DataStoreRead48 -
                       rtb_DataTypeConversion3_idx_1 * px4_noGPS3_B.roll_desire)
    * -2.0;

  // If: '<S32>/If' incorporates:
  //   Constant: '<S33>/Constant'
  //   Constant: '<S34>/Constant'

  if (px4_noGPS3_B.fcn3 > 1.0) {
    // Outputs for IfAction SubSystem: '<S32>/If Action Subsystem' incorporates:
    //   ActionPort: '<S33>/Action Port'

    px4_noGPS3_B.fcn3 = px4_noGPS3_P.Constant_Value_e;

    // End of Outputs for SubSystem: '<S32>/If Action Subsystem'
  } else if (px4_noGPS3_B.fcn3 < -1.0) {
    // Outputs for IfAction SubSystem: '<S32>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S34>/Action Port'

    px4_noGPS3_B.fcn3 = px4_noGPS3_P.Constant_Value_b1;

    // End of Outputs for SubSystem: '<S32>/If Action Subsystem1'
  }

  // End of If: '<S32>/If'

  // Trigonometry: '<S30>/trigFcn'
  if (px4_noGPS3_B.fcn3 > 1.0) {
    px4_noGPS3_B.Add3 = 1.0;
  } else if (px4_noGPS3_B.fcn3 < -1.0) {
    px4_noGPS3_B.Add3 = -1.0;
  } else {
    px4_noGPS3_B.Add3 = px4_noGPS3_B.fcn3;
  }

  // Fcn: '<S8>/fcn4'
  px4_noGPS3_B.fcn3 = (px4_noGPS3_B.roll_desire * px4_noGPS3_B.DataStoreRead48 +
                       rtb_DataTypeConversion3_idx_1 * px4_noGPS3_B.roll) * 2.0;

  // DataStoreWrite: '<Root>/Data Store Write' incorporates:
  //   Fcn: '<S8>/fcn5'
  //   Trigonometry: '<S30>/Trigonometric Function3'

  px4_noGPS3_DW.roll = rt_atan2d_snf(px4_noGPS3_B.fcn3, ((px4_noGPS3_B.Add4 -
    px4_noGPS3_B.Subtract3) - rtb_Switch_idx_0) + px4_noGPS3_B.Diff_fb);

  // DataStoreWrite: '<Root>/Data Store Write1' incorporates:
  //   Trigonometry: '<S30>/trigFcn'

  px4_noGPS3_DW.pitch = asin(px4_noGPS3_B.Add3);

  // Switch: '<S15>/Switch1' incorporates:
  //   DataStoreWrite: '<Root>/Data Store Write20'
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px4_noGPS3_DW.yaw_speed = px4_noGPS3_B.In1.yawspeed;

  // DataStoreWrite: '<Root>/Data Store Write21' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px4_noGPS3_DW.pitch_speed = px4_noGPS3_B.In1.pitchspeed;

  // DataStoreWrite: '<Root>/Data Store Write22' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px4_noGPS3_DW.roll_speed = px4_noGPS3_B.In1.rollspeed;

  // MATLAB Function: '<Root>/MATLAB Function3' incorporates:
  //   Constant: '<Root>/Constant6'
  //   DataStoreRead: '<Root>/Data Store Read45'
  //   DataStoreRead: '<Root>/Data Store Read52'
  //   DataStoreRead: '<Root>/Data Store Read56'
  //   DataStoreRead: '<Root>/Data Store Read71'

  rtb_DataTypeConversion3_idx_1 = cos(px4_noGPS3_P.Constant6_Value);
  px4_noGPS3_B.Add3 = sin(px4_noGPS3_P.Constant6_Value);
  px4_noGPS3_DW.roll_desire = asin((px4_noGPS3_DW.q_x * px4_noGPS3_B.Add3 -
    px4_noGPS3_DW.q_y * rtb_DataTypeConversion3_idx_1) / px4_noGPS3_DW.U1);
  px4_noGPS3_DW.pitch_desire = atan((px4_noGPS3_DW.q_x *
    rtb_DataTypeConversion3_idx_1 + px4_noGPS3_DW.q_y * px4_noGPS3_B.Add3) /
    (px4_noGPS3_DW.q_z + 9.8));
  if (px4_noGPS3_DW.roll_desire > 0.17453292519943295) {
    px4_noGPS3_DW.roll_desire = 0.17453292519943295;
  } else if (px4_noGPS3_DW.roll_desire < -0.17453292519943295) {
    px4_noGPS3_DW.roll_desire = -0.17453292519943295;
  }

  if (px4_noGPS3_DW.pitch_desire > 0.17453292519943295) {
    px4_noGPS3_DW.pitch_desire = 0.17453292519943295;
  } else if (px4_noGPS3_DW.pitch_desire < -0.17453292519943295) {
    px4_noGPS3_DW.pitch_desire = -0.17453292519943295;
  }

  // End of MATLAB Function: '<Root>/MATLAB Function3'

  // Switch: '<Root>/Switch' incorporates:
  //   Constant: '<Root>/Constant7'
  //   Constant: '<Root>/Constant8'
  //   Constant: '<S24>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read57'
  //   Switch: '<S24>/Switch'

  if (px4_noGPS3_DW.position_flag) {
    rtb_Switch_idx_0 = px4_noGPS3_P.Constant7_Value;

    // ZeroOrderHold: '<S24>/Zero-Order Hold1' incorporates:
    //   Constant: '<Root>/Constant7'
    //   DiscreteIntegrator: '<Root>/Intgrt_dY'

    px4_noGPS3_B.DataStoreRead48 = px4_noGPS3_DW.Intgrt_dY_DSTATE;
    rtb_DataTypeConversion3_idx_1 = px4_noGPS3_P.Constant7_Value;

    // ZeroOrderHold: '<S24>/Zero-Order Hold5' incorporates:
    //   Constant: '<Root>/Constant7'
    //   DiscreteIntegrator: '<Root>/Intgrt_ddY'

    px4_noGPS3_B.roll = px4_noGPS3_DW.Intgrt_ddY_DSTATE;
  } else {
    rtb_Switch_idx_0 = px4_noGPS3_P.Constant8_Value;

    // ZeroOrderHold: '<S24>/Zero-Order Hold1' incorporates:
    //   Constant: '<Root>/Constant8'
    //   Constant: '<S24>/Constant1'

    px4_noGPS3_B.DataStoreRead48 = px4_noGPS3_P.Constant1_Value;
    rtb_DataTypeConversion3_idx_1 = px4_noGPS3_P.Constant1_Value;

    // ZeroOrderHold: '<S24>/Zero-Order Hold5' incorporates:
    //   Constant: '<S24>/Constant1'

    px4_noGPS3_B.roll = px4_noGPS3_P.Constant1_Value;
  }

  // End of Switch: '<Root>/Switch'

  // Sum: '<S24>/Subtract'
  px4_noGPS3_B.DataStoreRead48 -= rtb_DataTypeConversion3_idx_1;

  // SampleTimeMath: '<S26>/TSamp'
  //
  //  About '<S26>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS3_B.Add3 = rtb_DataTypeConversion3_idx_1 * px4_noGPS3_P.TSamp_WtEt_c;

  // Sum: '<S26>/Diff' incorporates:
  //   UnitDelay: '<S26>/UD'
  //
  //  Block description for '<S26>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S26>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_B.Add4 = px4_noGPS3_B.Add3 - px4_noGPS3_DW.UD_DSTATE_g;

  // ZeroOrderHold: '<S24>/Zero-Order Hold6'
  rtb_DataTypeConversion3_idx_1 = px4_noGPS3_B.Add4;

  // Sum: '<S24>/Subtract1'
  rtb_DataTypeConversion3_idx_1 = px4_noGPS3_B.roll -
    rtb_DataTypeConversion3_idx_1;

  // Sum: '<S24>/Subtract3' incorporates:
  //   Gain: '<S24>/K1'

  px4_noGPS3_B.Subtract3 = px4_noGPS3_P.K1_Gain * px4_noGPS3_B.DataStoreRead48 +
    rtb_DataTypeConversion3_idx_1;

  // Switch: '<S24>/Switch1' incorporates:
  //   Constant: '<S24>/Constant'
  //   Constant: '<S24>/Constant2'
  //   Gain: '<S24>/C4'
  //   Sum: '<S24>/Subtract4'

  if (px4_noGPS3_P.C4_Gain * px4_noGPS3_B.DataStoreRead48 +
      rtb_DataTypeConversion3_idx_1 > px4_noGPS3_P.Switch1_Threshold) {
    px4_noGPS3_B.fcn3 = px4_noGPS3_P.Constant_Value_p;
  } else {
    px4_noGPS3_B.fcn3 = px4_noGPS3_P.Constant2_Value_o;
  }

  // End of Switch: '<S24>/Switch1'

  // SampleTimeMath: '<S27>/TSamp'
  //
  //  About '<S27>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS3_B.Add4 *= px4_noGPS3_P.TSamp_WtEt_l;

  // ZeroOrderHold: '<S24>/Zero-Order Hold3' incorporates:
  //   Sum: '<S27>/Diff'
  //   UnitDelay: '<S27>/UD'
  //
  //  Block description for '<S27>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S27>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_B.DataStoreRead48 = px4_noGPS3_B.Add4 - px4_noGPS3_DW.UD_DSTATE_c;

  // Gain: '<S7>/Gain2' incorporates:
  //   Constant: '<S24>/Constant3'
  //   Gain: '<S24>/C1'
  //   Gain: '<S24>/C3'
  //   Gain: '<S24>/Gain'
  //   Gain: '<S24>/k3'
  //   Product: '<S24>/Divide'
  //   Sum: '<S24>/Subtract2'
  //   Sum: '<S24>/Subtract5'
  //   Sum: '<S24>/Subtract6'

  px4_noGPS3_DW.q_y = (((px4_noGPS3_P.C1_Gain * px4_noGPS3_B.Subtract3 +
    px4_noGPS3_P.C3_Gain * rtb_DataTypeConversion3_idx_1) +
                        px4_noGPS3_P.Gain_Gain * px4_noGPS3_B.fcn3) +
                       (px4_noGPS3_P.k3_Gain * px4_noGPS3_B.roll /
                        px4_noGPS3_P.Constant3_Value_h +
                        px4_noGPS3_B.DataStoreRead48)) *
    px4_noGPS3_P.Gain2_Gain_o;

  // Saturate: '<S7>/Saturation1'
  if (px4_noGPS3_DW.q_y > px4_noGPS3_P.Saturation1_UpperSat) {
    // Gain: '<S7>/Gain2'
    px4_noGPS3_DW.q_y = px4_noGPS3_P.Saturation1_UpperSat;
  } else if (px4_noGPS3_DW.q_y < px4_noGPS3_P.Saturation1_LowerSat) {
    // Gain: '<S7>/Gain2'
    px4_noGPS3_DW.q_y = px4_noGPS3_P.Saturation1_LowerSat;
  }

  // End of Saturate: '<S7>/Saturation1'

  // DataStoreWrite: '<Root>/Data Store Write18' incorporates:
  //   Constant: '<S7>/Constant'

  px4_noGPS3_DW.q_z = px4_noGPS3_P.Constant_Value_i2;

  // Switch: '<S25>/Switch' incorporates:
  //   Constant: '<S25>/Constant1'
  //   DataStoreRead: '<S25>/Data Store Read'

  if (px4_noGPS3_DW.position_flag) {
    // ZeroOrderHold: '<S25>/Zero-Order Hold1' incorporates:
    //   DiscreteIntegrator: '<Root>/Intgrt_dX'

    px4_noGPS3_B.DataStoreRead48 = px4_noGPS3_DW.Intgrt_dX_DSTATE;
    rtb_DataTypeConversion3_idx_1 = rtb_Switch_idx_0;

    // ZeroOrderHold: '<S25>/Zero-Order Hold5' incorporates:
    //   DiscreteIntegrator: '<Root>/Intgrt_ddX'

    px4_noGPS3_B.roll = px4_noGPS3_DW.Intgrt_ddX_DSTATE;
  } else {
    // ZeroOrderHold: '<S25>/Zero-Order Hold1' incorporates:
    //   Constant: '<S25>/Constant1'

    px4_noGPS3_B.DataStoreRead48 = px4_noGPS3_P.Constant1_Value_d;
    rtb_DataTypeConversion3_idx_1 = px4_noGPS3_P.Constant1_Value_d;

    // ZeroOrderHold: '<S25>/Zero-Order Hold5' incorporates:
    //   Constant: '<S25>/Constant1'

    px4_noGPS3_B.roll = px4_noGPS3_P.Constant1_Value_d;
  }

  // End of Switch: '<S25>/Switch'

  // Sum: '<S25>/Subtract'
  px4_noGPS3_B.DataStoreRead48 -= rtb_DataTypeConversion3_idx_1;

  // SampleTimeMath: '<S28>/TSamp'
  //
  //  About '<S28>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS3_B.Subtract3 = rtb_DataTypeConversion3_idx_1 *
    px4_noGPS3_P.TSamp_WtEt_pq;

  // Sum: '<S28>/Diff' incorporates:
  //   UnitDelay: '<S28>/UD'
  //
  //  Block description for '<S28>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S28>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_B.Diff_fb = px4_noGPS3_B.Subtract3 - px4_noGPS3_DW.UD_DSTATE_n3;

  // ZeroOrderHold: '<S25>/Zero-Order Hold6'
  rtb_DataTypeConversion3_idx_1 = px4_noGPS3_B.Diff_fb;

  // Sum: '<S25>/Subtract1'
  rtb_DataTypeConversion3_idx_1 = px4_noGPS3_B.roll -
    rtb_DataTypeConversion3_idx_1;

  // Sum: '<S25>/Subtract3' incorporates:
  //   Gain: '<S25>/k2'

  rtb_Switch_idx_0 = px4_noGPS3_P.k2_Gain * px4_noGPS3_B.DataStoreRead48 +
    rtb_DataTypeConversion3_idx_1;

  // Switch: '<S25>/Switch1' incorporates:
  //   Constant: '<S25>/Constant'
  //   Constant: '<S25>/Constant2'
  //   Gain: '<S25>/C2'
  //   Sum: '<S25>/Subtract4'

  if (px4_noGPS3_P.C2_Gain * px4_noGPS3_B.DataStoreRead48 +
      rtb_DataTypeConversion3_idx_1 > px4_noGPS3_P.Switch1_Threshold_k) {
    px4_noGPS3_B.fcn3 = px4_noGPS3_P.Constant_Value_j;
  } else {
    px4_noGPS3_B.fcn3 = px4_noGPS3_P.Constant2_Value_e;
  }

  // End of Switch: '<S25>/Switch1'

  // SampleTimeMath: '<S29>/TSamp'
  //
  //  About '<S29>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS3_B.Diff_fb *= px4_noGPS3_P.TSamp_WtEt_i;

  // ZeroOrderHold: '<S25>/Zero-Order Hold3' incorporates:
  //   Sum: '<S29>/Diff'
  //   UnitDelay: '<S29>/UD'
  //
  //  Block description for '<S29>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S29>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_B.DataStoreRead48 = px4_noGPS3_B.Diff_fb -
    px4_noGPS3_DW.UD_DSTATE_nw;

  // Gain: '<S7>/Gain4' incorporates:
  //   Constant: '<S25>/Constant3'
  //   Gain: '<S25>/C1'
  //   Gain: '<S25>/Gain'
  //   Gain: '<S25>/k1'
  //   Gain: '<S25>/k3'
  //   Product: '<S25>/Divide'
  //   Sum: '<S25>/Subtract2'
  //   Sum: '<S25>/Subtract5'
  //   Sum: '<S25>/Subtract6'

  px4_noGPS3_DW.q_x = (((px4_noGPS3_P.C1_Gain_j * rtb_Switch_idx_0 +
    px4_noGPS3_P.k1_Gain * rtb_DataTypeConversion3_idx_1) +
                        px4_noGPS3_P.Gain_Gain_a * px4_noGPS3_B.fcn3) +
                       (px4_noGPS3_P.k3_Gain_f * px4_noGPS3_B.roll /
                        px4_noGPS3_P.Constant3_Value_f +
                        px4_noGPS3_B.DataStoreRead48)) *
    px4_noGPS3_P.Gain4_Gain_c;

  // Saturate: '<S7>/Saturation2'
  if (px4_noGPS3_DW.q_x > px4_noGPS3_P.Saturation2_UpperSat) {
    // Gain: '<S7>/Gain4'
    px4_noGPS3_DW.q_x = px4_noGPS3_P.Saturation2_UpperSat;
  } else if (px4_noGPS3_DW.q_x < px4_noGPS3_P.Saturation2_LowerSat) {
    // Gain: '<S7>/Gain4'
    px4_noGPS3_DW.q_x = px4_noGPS3_P.Saturation2_LowerSat;
  }

  // End of Saturate: '<S7>/Saturation2'

  // MATLAB Function: '<Root>/MATLAB Function1' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read'
  //   DataStoreRead: '<Root>/Data Store Read7'
  //   DataStoreRead: '<Root>/Data Store Read75'

  px4_noGPS3_DW.U1 = sqrt((px4_noGPS3_DW.q_x * px4_noGPS3_DW.q_x +
    px4_noGPS3_DW.q_y * px4_noGPS3_DW.q_y) + (px4_noGPS3_DW.q_z + 9.8) *
    (px4_noGPS3_DW.q_z + 9.8));

  // Saturate: '<Root>/Saturation2'
  if (px4_noGPS3_DW.U1 > px4_noGPS3_P.Saturation2_UpperSat_b) {
    // MATLAB Function: '<Root>/MATLAB Function1'
    px4_noGPS3_DW.U1 = px4_noGPS3_P.Saturation2_UpperSat_b;
  } else if (px4_noGPS3_DW.U1 < px4_noGPS3_P.Saturation2_LowerSat_m) {
    // MATLAB Function: '<Root>/MATLAB Function1'
    px4_noGPS3_DW.U1 = px4_noGPS3_P.Saturation2_LowerSat_m;
  }

  // End of Saturate: '<Root>/Saturation2'

  // DataStoreWrite: '<S10>/Data Store Write28' incorporates:
  //   Constant: '<S10>/attitude_flag'

  px4_noGPS3_DW.attitude_flag = px4_noGPS3_P.attitude_flag_Value;

  // DataStoreWrite: '<S12>/Data Store Write28' incorporates:
  //   Constant: '<S12>/position_flag'

  px4_noGPS3_DW.position_flag = px4_noGPS3_P.position_flag_Value;
  for (int32_T i = 0; i < 4; i++) {
    // Gain: '<Root>/Gain4' incorporates:
    //   Constant: '<Root>/Mixer matrix1'
    //   DataStoreRead: '<Root>/Data Store Read21'
    //   DataStoreRead: '<Root>/Data Store Read22'
    //   DataStoreRead: '<Root>/Data Store Read23'
    //   DataStoreRead: '<Root>/Data Store Read70'
    //   DataStoreWrite: '<Root>/Data Store Write9'
    //   Product: '<Root>/Product2'
    //   SignalConversion generated from: '<Root>/Product2'

    rtb_DataTypeConversion3_idx_1 = floor((((px4_noGPS3_P.Mixermatrix1_Value[i +
      4] * pitch_thrust + px4_noGPS3_P.Mixermatrix1_Value[i] * px4_noGPS3_DW.U1)
      + px4_noGPS3_P.Mixermatrix1_Value[i + 8] * roll_thrust) +
      px4_noGPS3_P.Mixermatrix1_Value[i + 12] * yaw_thrust) *
      px4_noGPS3_P.Gain4_Gain_f);
    if (rtIsNaN(rtb_DataTypeConversion3_idx_1) || rtIsInf
        (rtb_DataTypeConversion3_idx_1)) {
      rtb_DataTypeConversion3_idx_1 = 0.0;
    } else {
      rtb_DataTypeConversion3_idx_1 = fmod(rtb_DataTypeConversion3_idx_1,
        65536.0);
    }

    px4_noGPS3_B.Gain4_f[i] = static_cast<uint16_T>
      (rtb_DataTypeConversion3_idx_1 < 0.0 ? static_cast<int32_T>
       (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
          (-rtb_DataTypeConversion3_idx_1)))) : static_cast<int32_T>(
        static_cast<uint16_T>(rtb_DataTypeConversion3_idx_1)));

    // End of Gain: '<Root>/Gain4'
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1'
  for (int32_T i = 0; i < 8; i++) {
    px4_noGPS3_B.pwmValue[i] = 0U;
  }

  // Sum: '<Root>/Add' incorporates:
  //   Constant: '<Root>/fault_1'

  rtb_DataTypeConversion3_idx_1 = floor(static_cast<real_T>
    (px4_noGPS3_B.Gain4_f[0]) - px4_noGPS3_P.fault_1_Value);
  if (rtIsNaN(rtb_DataTypeConversion3_idx_1) || rtIsInf
      (rtb_DataTypeConversion3_idx_1)) {
    rtb_DataTypeConversion3_idx_1 = 0.0;
  } else {
    rtb_DataTypeConversion3_idx_1 = fmod(rtb_DataTypeConversion3_idx_1, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Sum: '<Root>/Add'

  px4_noGPS3_B.pwmValue[0] = static_cast<uint16_T>(rtb_DataTypeConversion3_idx_1
    < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-rtb_DataTypeConversion3_idx_1)))) :
    static_cast<int32_T>(static_cast<uint16_T>(rtb_DataTypeConversion3_idx_1)));

  // Sum: '<Root>/Add1' incorporates:
  //   Constant: '<Root>/fault_2'

  rtb_DataTypeConversion3_idx_1 = floor(static_cast<real_T>
    (px4_noGPS3_B.Gain4_f[1]) - px4_noGPS3_P.fault_2_Value);
  if (rtIsNaN(rtb_DataTypeConversion3_idx_1) || rtIsInf
      (rtb_DataTypeConversion3_idx_1)) {
    rtb_DataTypeConversion3_idx_1 = 0.0;
  } else {
    rtb_DataTypeConversion3_idx_1 = fmod(rtb_DataTypeConversion3_idx_1, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Sum: '<Root>/Add1'

  px4_noGPS3_B.pwmValue[1] = static_cast<uint16_T>(rtb_DataTypeConversion3_idx_1
    < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-rtb_DataTypeConversion3_idx_1)))) :
    static_cast<int32_T>(static_cast<uint16_T>(rtb_DataTypeConversion3_idx_1)));

  // Sum: '<Root>/Add2' incorporates:
  //   Constant: '<Root>/fault_3'

  rtb_DataTypeConversion3_idx_1 = floor(static_cast<real_T>
    (px4_noGPS3_B.Gain4_f[2]) - px4_noGPS3_P.fault_3_Value);
  if (rtIsNaN(rtb_DataTypeConversion3_idx_1) || rtIsInf
      (rtb_DataTypeConversion3_idx_1)) {
    rtb_DataTypeConversion3_idx_1 = 0.0;
  } else {
    rtb_DataTypeConversion3_idx_1 = fmod(rtb_DataTypeConversion3_idx_1, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Sum: '<Root>/Add2'

  px4_noGPS3_B.pwmValue[2] = static_cast<uint16_T>(rtb_DataTypeConversion3_idx_1
    < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-rtb_DataTypeConversion3_idx_1)))) :
    static_cast<int32_T>(static_cast<uint16_T>(rtb_DataTypeConversion3_idx_1)));

  // Sum: '<Root>/Add3' incorporates:
  //   Constant: '<Root>/fault_4'

  rtb_DataTypeConversion3_idx_1 = floor(static_cast<real_T>
    (px4_noGPS3_B.Gain4_f[3]) - px4_noGPS3_P.fault_4_Value);
  if (rtIsNaN(rtb_DataTypeConversion3_idx_1) || rtIsInf
      (rtb_DataTypeConversion3_idx_1)) {
    rtb_DataTypeConversion3_idx_1 = 0.0;
  } else {
    rtb_DataTypeConversion3_idx_1 = fmod(rtb_DataTypeConversion3_idx_1, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Reset'
  //   Sum: '<Root>/Add3'

  px4_noGPS3_B.pwmValue[3] = static_cast<uint16_T>(rtb_DataTypeConversion3_idx_1
    < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-rtb_DataTypeConversion3_idx_1)))) :
    static_cast<int32_T>(static_cast<uint16_T>(rtb_DataTypeConversion3_idx_1)));
  if (px4_noGPS3_P.Reset_Value) {
    if (!px4_noGPS3_DW.obj.isArmed) {
      px4_noGPS3_DW.obj.isArmed = true;
      status = pwm_arm(&px4_noGPS3_DW.obj.pwmDevHandler,
                       &px4_noGPS3_DW.obj.armAdvertiseObj);
      px4_noGPS3_DW.obj.errorStatus = static_cast<uint16_T>
        (px4_noGPS3_DW.obj.errorStatus | status);
    }

    status = pwm_setServo(&px4_noGPS3_DW.obj.pwmDevHandler,
                          px4_noGPS3_DW.obj.servoCount,
                          px4_noGPS3_DW.obj.channelMask, &px4_noGPS3_B.pwmValue
                          [0], px4_noGPS3_DW.obj.isMain,
                          &px4_noGPS3_DW.obj.actuatorAdvertiseObj);
    px4_noGPS3_DW.obj.errorStatus = static_cast<uint16_T>
      (px4_noGPS3_DW.obj.errorStatus | status);
  } else {
    status = pwm_disarm(&px4_noGPS3_DW.obj.pwmDevHandler,
                        &px4_noGPS3_DW.obj.armAdvertiseObj);
    px4_noGPS3_DW.obj.errorStatus = static_cast<uint16_T>
      (px4_noGPS3_DW.obj.errorStatus | status);
    px4_noGPS3_DW.obj.isArmed = false;
    status = pwm_resetServo(&px4_noGPS3_DW.obj.pwmDevHandler,
      px4_noGPS3_DW.obj.servoCount, px4_noGPS3_DW.obj.channelMask,
      px4_noGPS3_DW.obj.isMain, &px4_noGPS3_DW.obj.actuatorAdvertiseObj);
    px4_noGPS3_DW.obj.errorStatus = static_cast<uint16_T>
      (px4_noGPS3_DW.obj.errorStatus | status);
  }

  if (px4_noGPS3_DW.obj.isMain) {
    status = pwm_forceFailsafe(&px4_noGPS3_DW.obj.pwmDevHandler,
      static_cast<int32_T>(px4_noGPS3_P.Constant2_Value_k));
    px4_noGPS3_DW.obj.errorStatus = static_cast<uint16_T>
      (px4_noGPS3_DW.obj.errorStatus | status);
  }

  // Switch: '<Root>/Switch1' incorporates:
  //   Constant: '<Root>/Constant5'
  //   DataStoreRead: '<Root>/Data Store Read53'
  //   DataStoreRead: '<Root>/Data Store Read63'
  //   MATLAB Function: '<Root>/MATLAB Function5'

  if (px4_noGPS3_DW.position_flag) {
    // MATLAB Function: '<Root>/MATLAB Function5' incorporates:
    //   DataStoreRead: '<Root>/Data Store Read58'
    //   DataStoreRead: '<Root>/Data Store Read66'
    //   DataStoreRead: '<Root>/Data Store Read67'

    rtb_DataTypeConversion3_idx_1 = sin(px4_noGPS3_DW.yaw);
    px4_noGPS3_B.roll = sin(px4_noGPS3_DW.pitch);
    px4_noGPS3_B.DataStoreRead48 = cos(px4_noGPS3_DW.yaw);
    px4_noGPS3_B.fcn3 = cos(px4_noGPS3_DW.pitch) * sin(px4_noGPS3_DW.roll);
    rtb_Switch_idx_0 = (px4_noGPS3_B.fcn3 * px4_noGPS3_B.DataStoreRead48 +
                        px4_noGPS3_B.roll * rtb_DataTypeConversion3_idx_1) *
      -px4_noGPS3_DW.U1;
    rtb_Switch_idx_1 = (px4_noGPS3_B.fcn3 * rtb_DataTypeConversion3_idx_1 -
                        px4_noGPS3_B.roll * px4_noGPS3_B.DataStoreRead48) *
      -px4_noGPS3_DW.U1;
  } else {
    rtb_Switch_idx_0 = px4_noGPS3_P.Constant5_Value;
    rtb_Switch_idx_1 = px4_noGPS3_P.Constant5_Value;
  }

  // End of Switch: '<Root>/Switch1'

  // DataStoreRead: '<Root>/Data Store Read28'
  px4_noGPS3_B.DataStoreRead48 = pitch_thrust;

  // DataStoreRead: '<Root>/Data Store Read29'
  rtb_DataTypeConversion3_idx_1 = roll_thrust;

  // DataStoreRead: '<Root>/Data Store Read32'
  px4_noGPS3_B.roll = yaw_thrust;

  // DataStoreRead: '<Root>/Data Store Read73' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read70'
  //   DataStoreWrite: '<Root>/Data Store Write9'

  px4_noGPS3_B.roll_desire = px4_noGPS3_DW.U1;

  // Gain: '<Root>/Gain8' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read31'

  px4_noGPS3_B.DataStoreRead48 = px4_noGPS3_P.Gain8_Gain_o * px4_noGPS3_DW.pitch;

  // Gain: '<Root>/Gain10' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read74'

  rtb_DataTypeConversion3_idx_1 = px4_noGPS3_P.Gain10_Gain *
    px4_noGPS3_DW.pitch_desire;

  // Gain: '<Root>/Gain7' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read30'

  px4_noGPS3_B.roll = px4_noGPS3_P.Gain7_Gain_a * px4_noGPS3_DW.roll;

  // Gain: '<Root>/Gain11' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read41'

  px4_noGPS3_B.roll_desire = px4_noGPS3_P.Gain11_Gain *
    px4_noGPS3_DW.roll_desire;

  // Gain: '<Root>/Gain9' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read33'

  px4_noGPS3_B.fcn3 = px4_noGPS3_P.Gain9_Gain * px4_noGPS3_DW.yaw;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_dX'

  px4_noGPS3_B.DataStoreRead48 = px4_noGPS3_DW.Intgrt_dX_DSTATE;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_dY'

  rtb_DataTypeConversion3_idx_1 = px4_noGPS3_DW.Intgrt_dY_DSTATE;

  // Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
  //   EnablePort: '<S9>/Enable'

  // DataStoreRead: '<Root>/Data Store Read54'
  if (px4_noGPS3_DW.attitude_flag) {
    // Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S9>/Constant9'

    px4_noGPS3_DW.DiscreteTimeIntegrator_DSTATE +=
      px4_noGPS3_P.DiscreteTimeIntegrator_gainval * px4_noGPS3_P.Constant9_Value;
  }

  // End of DataStoreRead: '<Root>/Data Store Read54'
  // End of Outputs for SubSystem: '<Root>/Subsystem1'

  // Update for UnitDelay: '<S20>/UD'
  //
  //  Block description for '<S20>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_DW.UD_DSTATE = px4_noGPS3_B.TSamp;

  // Update for UnitDelay: '<S21>/UD'
  //
  //  Block description for '<S21>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_DW.UD_DSTATE_j = px4_noGPS3_B.TSamp_p;

  // Update for UnitDelay: '<S16>/UD'
  //
  //  Block description for '<S16>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_DW.UD_DSTATE_d = px4_noGPS3_B.TSamp_e;

  // Update for UnitDelay: '<S17>/UD'
  //
  //  Block description for '<S17>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_DW.UD_DSTATE_dv = px4_noGPS3_B.TSamp_pa;

  // Update for UnitDelay: '<S18>/UD'
  //
  //  Block description for '<S18>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_DW.UD_DSTATE_a = px4_noGPS3_B.TSamp_k;

  // Update for UnitDelay: '<S19>/UD'
  //
  //  Block description for '<S19>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_DW.UD_DSTATE_n = px4_noGPS3_B.TSamp_d;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_dX' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddX'

  px4_noGPS3_DW.Intgrt_dX_DSTATE += px4_noGPS3_P.Intgrt_dX_gainval *
    px4_noGPS3_DW.Intgrt_ddX_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_dY' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddY'

  px4_noGPS3_DW.Intgrt_dY_DSTATE += px4_noGPS3_P.Intgrt_dY_gainval *
    px4_noGPS3_DW.Intgrt_ddY_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_ddY' incorporates:
  //   Gain: '<Root>/slower4'

  px4_noGPS3_DW.Intgrt_ddY_DSTATE += px4_noGPS3_P.slower4_Gain *
    rtb_Switch_idx_1 * px4_noGPS3_P.Intgrt_ddY_gainval;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_ddX' incorporates:
  //   Gain: '<Root>/slower3'

  px4_noGPS3_DW.Intgrt_ddX_DSTATE += px4_noGPS3_P.slower3_Gain *
    rtb_Switch_idx_0 * px4_noGPS3_P.Intgrt_ddX_gainval;

  // Update for UnitDelay: '<S26>/UD'
  //
  //  Block description for '<S26>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_DW.UD_DSTATE_g = px4_noGPS3_B.Add3;

  // Update for UnitDelay: '<S27>/UD'
  //
  //  Block description for '<S27>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_DW.UD_DSTATE_c = px4_noGPS3_B.Add4;

  // Update for UnitDelay: '<S28>/UD'
  //
  //  Block description for '<S28>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_DW.UD_DSTATE_n3 = px4_noGPS3_B.Subtract3;

  // Update for UnitDelay: '<S29>/UD'
  //
  //  Block description for '<S29>/UD':
  //
  //   Store in Global RAM

  px4_noGPS3_DW.UD_DSTATE_nw = px4_noGPS3_B.Diff_fb;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_dZ' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddZ'

  px4_noGPS3_DW.Intgrt_dZ_DSTATE += px4_noGPS3_P.Intgrt_dZ_gainval *
    px4_noGPS3_DW.Intgrt_ddZ_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_ddZ' incorporates:
  //   Gain: '<Root>/slower5'

  px4_noGPS3_DW.Intgrt_ddZ_DSTATE += px4_noGPS3_P.slower5_Gain * 0.0 *
    px4_noGPS3_P.Intgrt_ddZ_gainval;
}

// Model step function for TID1
void px4_noGPS3_step1(void)            // Sample time: [0.01s, 0.0s]
{
  uint64_T rtb_timestamp;
  uint32_T rtb_noutputs;
  uint8_T rtb__padding0[4];
  boolean_T b_varargout_1;
  boolean_T rtb_NOT;

  // MATLABSystem: '<S5>/SourceBlock'
  b_varargout_1 = uORB_read_step(px4_noGPS3_DW.obj_l.orbMetadataObj,
    &px4_noGPS3_DW.obj_l.eventStructObj, &px4_noGPS3_B.b_varargout_2_m, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S22>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S22>/In1'
    px4_noGPS3_B.In1_a = px4_noGPS3_B.b_varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb_timestamp = px4_noGPS3_B.In1_a.timestamp;

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb_noutputs = px4_noGPS3_B.In1_a.noutputs;

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb__padding0[0] = px4_noGPS3_B.In1_a._padding0[0];
  rtb__padding0[1] = px4_noGPS3_B.In1_a._padding0[1];
  rtb__padding0[2] = px4_noGPS3_B.In1_a._padding0[2];
  rtb__padding0[3] = px4_noGPS3_B.In1_a._padding0[3];

  // Logic: '<S5>/NOT' incorporates:
  //   MATLABSystem: '<S5>/SourceBlock'

  rtb_NOT = !b_varargout_1;
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void px4_noGPS3_step(int_T tid)
{
  switch (tid) {
   case 0 :
    px4_noGPS3_step0();
    break;

   case 1 :
    px4_noGPS3_step1();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void px4_noGPS3_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  px4_noGPS3_P.Saturation1_UpperSat_k = rtInf;

  // block I/O
  (void) memset((static_cast<void *>(&px4_noGPS3_B)), 0,
                sizeof(B_px4_noGPS3_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&px4_noGPS3_DW), 0,
                sizeof(DW_px4_noGPS3_T));

  {
    boolean_T rtb_DataStoreRead6;

    // Start for DataStoreMemory: '<S15>/Data Store Memory'
    px4_noGPS3_DW.s6_yaw = px4_noGPS3_P.DataStoreMemory_InitialValue;

    // Start for DataStoreMemory: '<S13>/Data Store Memory'
    px4_noGPS3_DW.s4_pitch = px4_noGPS3_P.DataStoreMemory_InitialValue_i;

    // Start for DataStoreMemory: '<S14>/Data Store Memory'
    px4_noGPS3_DW.s5_roll = px4_noGPS3_P.DataStoreMemory_InitialValue_e;

    // Start for DataStoreMemory: '<Root>/Data Store Memory'
    px4_noGPS3_DW.attitude_flag = px4_noGPS3_P.DataStoreMemory_InitialValue_j;

    // Start for Switch: '<S15>/Switch1' incorporates:
    //   DataStoreMemory: '<Root>/Data Store Memory16'

    px4_noGPS3_DW.yaw_speed = px4_noGPS3_P.DataStoreMemory16_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory17'
    px4_noGPS3_DW.roll_speed = px4_noGPS3_P.DataStoreMemory17_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory18'
    px4_noGPS3_DW.pitch_speed = px4_noGPS3_P.DataStoreMemory18_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory22'
    px4_noGPS3_DW.roll_desire = px4_noGPS3_P.DataStoreMemory22_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory23'
    px4_noGPS3_DW.pitch_desire = px4_noGPS3_P.DataStoreMemory23_InitialValue;

    // Start for Gain: '<S7>/Gain4' incorporates:
    //   DataStoreMemory: '<Root>/Data Store Memory24'

    px4_noGPS3_DW.q_x = px4_noGPS3_P.DataStoreMemory24_InitialValue;

    // Start for Gain: '<S7>/Gain2' incorporates:
    //   DataStoreMemory: '<Root>/Data Store Memory25'

    px4_noGPS3_DW.q_y = px4_noGPS3_P.DataStoreMemory25_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory26'
    px4_noGPS3_DW.q_z = px4_noGPS3_P.DataStoreMemory26_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory27'
    px4_noGPS3_DW.position_flag = px4_noGPS3_P.DataStoreMemory27_InitialValue;

    // Start for MATLAB Function: '<Root>/MATLAB Function1' incorporates:
    //   DataStoreMemory: '<Root>/Data Store Memory36'

    px4_noGPS3_DW.U1 = px4_noGPS3_P.DataStoreMemory36_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory4'
    px4_noGPS3_DW.pitch = px4_noGPS3_P.DataStoreMemory4_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory6'
    px4_noGPS3_DW.roll = px4_noGPS3_P.DataStoreMemory6_InitialValue;

    // Start for Trigonometry: '<S30>/Trigonometric Function1' incorporates:
    //   DataStoreMemory: '<Root>/Data Store Memory8'

    px4_noGPS3_DW.yaw = px4_noGPS3_P.DataStoreMemory8_InitialValue;

    // InitializeConditions for UnitDelay: '<S20>/UD'
    //
    //  Block description for '<S20>/UD':
    //
    //   Store in Global RAM

    px4_noGPS3_DW.UD_DSTATE = px4_noGPS3_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for UnitDelay: '<S21>/UD'
    //
    //  Block description for '<S21>/UD':
    //
    //   Store in Global RAM

    px4_noGPS3_DW.UD_DSTATE_j = px4_noGPS3_P.DiscreteDerivative2_ICPrevScale;

    // InitializeConditions for UnitDelay: '<S16>/UD'
    //
    //  Block description for '<S16>/UD':
    //
    //   Store in Global RAM

    px4_noGPS3_DW.UD_DSTATE_d = px4_noGPS3_P.DiscreteDerivative_ICPrevScal_a;

    // InitializeConditions for UnitDelay: '<S17>/UD'
    //
    //  Block description for '<S17>/UD':
    //
    //   Store in Global RAM

    px4_noGPS3_DW.UD_DSTATE_dv = px4_noGPS3_P.DiscreteDerivative2_ICPrevSca_e;

    // InitializeConditions for UnitDelay: '<S18>/UD'
    //
    //  Block description for '<S18>/UD':
    //
    //   Store in Global RAM

    px4_noGPS3_DW.UD_DSTATE_a = px4_noGPS3_P.DiscreteDerivative_ICPrevSca_ay;

    // InitializeConditions for UnitDelay: '<S19>/UD'
    //
    //  Block description for '<S19>/UD':
    //
    //   Store in Global RAM

    px4_noGPS3_DW.UD_DSTATE_n = px4_noGPS3_P.DiscreteDerivative2_ICPrevSca_i;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_dX'
    px4_noGPS3_DW.Intgrt_dX_DSTATE = px4_noGPS3_P.Intgrt_dX_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_dY'
    px4_noGPS3_DW.Intgrt_dY_DSTATE = px4_noGPS3_P.Intgrt_dY_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_ddY'
    px4_noGPS3_DW.Intgrt_ddY_DSTATE = px4_noGPS3_P.Intgrt_ddY_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_ddX'
    px4_noGPS3_DW.Intgrt_ddX_DSTATE = px4_noGPS3_P.Intgrt_ddX_IC;

    // InitializeConditions for UnitDelay: '<S26>/UD'
    //
    //  Block description for '<S26>/UD':
    //
    //   Store in Global RAM

    px4_noGPS3_DW.UD_DSTATE_g = px4_noGPS3_P.DiscreteDerivative_ICPrevScal_f;

    // InitializeConditions for UnitDelay: '<S27>/UD'
    //
    //  Block description for '<S27>/UD':
    //
    //   Store in Global RAM

    px4_noGPS3_DW.UD_DSTATE_c = px4_noGPS3_P.DiscreteDerivative1_ICPrevScale;

    // InitializeConditions for UnitDelay: '<S28>/UD'
    //
    //  Block description for '<S28>/UD':
    //
    //   Store in Global RAM

    px4_noGPS3_DW.UD_DSTATE_n3 = px4_noGPS3_P.DiscreteDerivative_ICPrevScal_e;

    // InitializeConditions for UnitDelay: '<S29>/UD'
    //
    //  Block description for '<S29>/UD':
    //
    //   Store in Global RAM

    px4_noGPS3_DW.UD_DSTATE_nw = px4_noGPS3_P.DiscreteDerivative1_ICPrevSca_k;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_dZ'
    px4_noGPS3_DW.Intgrt_dZ_DSTATE = px4_noGPS3_P.Intgrt_dZ_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_ddZ'
    px4_noGPS3_DW.Intgrt_ddZ_DSTATE = px4_noGPS3_P.Intgrt_ddZ_IC;

    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S22>/In1' incorporates:
    //   Outport: '<S22>/Out1'

    px4_noGPS3_B.In1_a = px4_noGPS3_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S23>/In1' incorporates:
    //   Outport: '<S23>/Out1'

    px4_noGPS3_B.In1 = px4_noGPS3_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1'
    // InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' 
    px4_noGPS3_DW.DiscreteTimeIntegrator_DSTATE =
      px4_noGPS3_P.DiscreteTimeIntegrator_IC;

    // End of SystemInitialize for SubSystem: '<Root>/Subsystem1'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    px4_noGPS3_DW.obj_n.matlabCodegenIsDeleted = false;
    px4_noGPS3_DW.obj_n.isSetupComplete = false;
    px4_noGPS3_DW.obj_n.isInitialized = 1;
    px4_noGPS3_DW.obj_n.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(px4_noGPS3_DW.obj_n.orbMetadataObj,
                         &px4_noGPS3_DW.obj_n.eventStructObj);
    px4_noGPS3_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
    //   Constant: '<Root>/Constant2'

    px4_noGPS3_DW.obj.errorStatus = 0U;
    px4_noGPS3_DW.obj.isInitialized = 0;
    px4_noGPS3_DW.obj.matlabCodegenIsDeleted = false;
    px4_noGPS3_SystemCore_setup(&px4_noGPS3_DW.obj, rtb_DataStoreRead6,
      px4_noGPS3_P.Constant2_Value_k);

    // Start for MATLABSystem: '<S5>/SourceBlock'
    px4_noGPS3_DW.obj_l.matlabCodegenIsDeleted = false;
    px4_noGPS3_DW.obj_l.isSetupComplete = false;
    px4_noGPS3_DW.obj_l.isInitialized = 1;
    px4_noGPS3_DW.obj_l.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_read_initialize(px4_noGPS3_DW.obj_l.orbMetadataObj,
                         &px4_noGPS3_DW.obj_l.eventStructObj);
    px4_noGPS3_DW.obj_l.isSetupComplete = true;
  }
}

// Model terminate function
void px4_noGPS3_terminate(void)
{
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!px4_noGPS3_DW.obj_n.matlabCodegenIsDeleted) {
    px4_noGPS3_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((px4_noGPS3_DW.obj_n.isInitialized == 1) &&
        px4_noGPS3_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&px4_noGPS3_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for MATLABSystem: '<Root>/PX4 PWM Output1'
  if (!px4_noGPS3_DW.obj.matlabCodegenIsDeleted) {
    px4_noGPS3_DW.obj.matlabCodegenIsDeleted = true;
    if ((px4_noGPS3_DW.obj.isInitialized == 1) &&
        px4_noGPS3_DW.obj.isSetupComplete) {
      uint16_T status;
      status = pwm_disarm(&px4_noGPS3_DW.obj.pwmDevHandler,
                          &px4_noGPS3_DW.obj.armAdvertiseObj);
      px4_noGPS3_DW.obj.errorStatus = static_cast<uint16_T>
        (px4_noGPS3_DW.obj.errorStatus | status);
      status = pwm_resetServo(&px4_noGPS3_DW.obj.pwmDevHandler,
        px4_noGPS3_DW.obj.servoCount, px4_noGPS3_DW.obj.channelMask,
        px4_noGPS3_DW.obj.isMain, &px4_noGPS3_DW.obj.actuatorAdvertiseObj);
      px4_noGPS3_DW.obj.errorStatus = static_cast<uint16_T>
        (px4_noGPS3_DW.obj.errorStatus | status);
      status = pwm_close(&px4_noGPS3_DW.obj.pwmDevHandler,
                         &px4_noGPS3_DW.obj.actuatorAdvertiseObj,
                         &px4_noGPS3_DW.obj.armAdvertiseObj);
      px4_noGPS3_DW.obj.errorStatus = static_cast<uint16_T>
        (px4_noGPS3_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 PWM Output1'

  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!px4_noGPS3_DW.obj_l.matlabCodegenIsDeleted) {
    px4_noGPS3_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((px4_noGPS3_DW.obj_l.isInitialized == 1) &&
        px4_noGPS3_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&px4_noGPS3_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
