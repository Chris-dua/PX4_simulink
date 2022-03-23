//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4_noGPS2.cpp
//
// Code generated for Simulink model 'px4_noGPS2'.
//
// Model version                  : 5.152
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Mar 23 12:27:40 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "px4_noGPS2.h"
#include "rtwtypes.h"
#include "px4_noGPS2_types.h"
#include "px4_noGPS2_private.h"
#include <math.h>

extern "C" {

#include "rt_nonfinite.h"

}
#include "rt_defines.h"
#include "zero_crossing_types.h"

// Block signals (default storage)
B_px4_noGPS2_T px4_noGPS2_B;

// Block states (default storage)
DW_px4_noGPS2_T px4_noGPS2_DW;

// Previous zero-crossings (trigger) states
PrevZCX_px4_noGPS2_T px4_noGPS2_PrevZCX;

// Real-time model
RT_MODEL_px4_noGPS2_T px4_noGPS2_M_ = RT_MODEL_px4_noGPS2_T();
RT_MODEL_px4_noGPS2_T *const px4_noGPS2_M = &px4_noGPS2_M_;

// Forward declaration for local functions
static void px4_noGPS2_SystemCore_setup(px4_internal_block_PWM_px4_no_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void px4_noGPS2_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(px4_noGPS2_M, 1));
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

  (px4_noGPS2_M->Timing.TaskCounters.TID[1])++;
  if ((px4_noGPS2_M->Timing.TaskCounters.TID[1]) > 1) {// Sample time: [0.01s, 0.0s] 
    px4_noGPS2_M->Timing.TaskCounters.TID[1] = 0;
  }
}

//
// Output and update for atomic system:
//    '<S21>/MATLAB Function'
//    '<S30>/MATLAB Function'
//    '<S39>/MATLAB Function'
//
void px4_noGPS2_MATLABFunction(boolean_T rtu_e, real_T rtu_t, real_T rtu_s_t,
  real_T rtu_y1, real_T rtu_y2, real_T *rty_y)
{
  if (rtu_t < 4.6) {
    *rty_y = rtu_y2;
  } else {
    real_T tmp;
    tmp = rtu_t - rtu_s_t;
    if (rtu_e && (tmp <= 4.6) && (rtu_t > 4.6)) {
      *rty_y = rtu_y1;
    } else if (rtu_e && (tmp > 4.6)) {
      *rty_y = rtu_y2;
    } else if ((!rtu_e) && (tmp <= 4.6) && (rtu_t > 4.6)) {
      *rty_y = rtu_y1;
    } else {
      *rty_y = rtu_y2;
    }
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
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

static void px4_noGPS2_SystemCore_setup(px4_internal_block_PWM_px4_no_T *obj,
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
void px4_noGPS2_step0(void)            // Sample time: [0.005s, 0.0s]
{
  real_T rtb_Fcn_tmp;
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  uint16_T status;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_g2;
  boolean_T rtb_Compare_i;
  boolean_T rtb_LogicalOperator;

  {                                    // Sample time: [0.005s, 0.0s]
    rate_monotonic_scheduler();
  }

  // Switch: '<S15>/Switch' incorporates:
  //   Constant: '<S15>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read20'
  //   DataStoreRead: '<S15>/Data Store Read'
  //   DataStoreRead: '<S15>/Data Store Read1'

  if (px4_noGPS2_DW.attitude_flag) {
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS2_DW.yaw;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = 0.0;
    px4_noGPS2_B.e_l = px4_noGPS2_DW.yaw_speed;
  } else {
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS2_P.Constant1_Value_a;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_P.Constant1_Value_a;
    px4_noGPS2_B.e_l = px4_noGPS2_P.Constant1_Value_a;
  }

  // End of Switch: '<S15>/Switch'

  // Sum: '<S38>/Add' incorporates:
  //   Sum: '<S15>/Add2'

  px4_noGPS2_B.Product_c = px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 -
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1;
  px4_noGPS2_B.z1_i = px4_noGPS2_B.Product_c;

  // RelationalOperator: '<S40>/Compare' incorporates:
  //   Abs: '<S39>/Abs'
  //   Constant: '<S40>/Constant'
  //   DataStoreRead: '<S39>/Data Store Read1'

  rtb_Compare = (fabs(px4_noGPS2_DW.e_pitch_yaw) >=
                 px4_noGPS2_P.CompareToConstant1_const);

  // Sum: '<S39>/Add' incorporates:
  //   DataStoreRead: '<S39>/Data Store Read'
  //   DataStoreRead: '<S39>/Data Store Read3'
  //   Sum: '<S42>/Add'

  rtb_Fcn_tmp = px4_noGPS2_DW.t - px4_noGPS2_DW.start_time_yaw;

  // Fcn: '<S39>/Fcn' incorporates:
  //   Constant: '<S39>/T'
  //   Constant: '<S39>/ch'
  //   Sum: '<S39>/Add'

  px4_noGPS2_B.rtb_Fcn_c = px4_noGPS2_P.ch_Value / (px4_noGPS2_P.T_Value -
    rtb_Fcn_tmp);

  // MATLAB Function: '<S39>/MATLAB Function' incorporates:
  //   Constant: '<S39>/t'
  //   DataStoreRead: '<S39>/Data Store Read'
  //   DataStoreRead: '<S39>/Data Store Read3'

  px4_noGPS2_MATLABFunction(rtb_Compare, px4_noGPS2_DW.t,
    px4_noGPS2_DW.start_time_yaw, px4_noGPS2_B.rtb_Fcn_c, px4_noGPS2_P.t_Value,
    &px4_noGPS2_B.rtb_DataStoreRead48_p);

  // Sum: '<S39>/Add1' incorporates:
  //   Constant: '<S39>/r'

  px4_noGPS2_B.z2 = px4_noGPS2_P.r_Value + px4_noGPS2_B.rtb_DataStoreRead48_p;

  // Gain: '<S38>/Gain4' incorporates:
  //   Constant: '<S15>/b'
  //   Product: '<S38>/Product'

  px4_noGPS2_B.z1_i = px4_noGPS2_B.z1_i * px4_noGPS2_B.z2 * px4_noGPS2_P.b_Value
    * px4_noGPS2_P.Gain4_Gain;

  // SampleTimeMath: '<S37>/TSamp'
  //
  //  About '<S37>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS2_B.TSamp = px4_noGPS2_B.z1_i * px4_noGPS2_P.TSamp_WtEt;

  // Sum: '<S15>/Add2' incorporates:
  //   DataStoreWrite: '<S15>/Data Store Write'

  px4_noGPS2_DW.e_pitch_yaw = px4_noGPS2_B.Product_c;

  // Sum: '<S15>/Add1'
  px4_noGPS2_B.z1_i = px4_noGPS2_B.e_l - px4_noGPS2_B.z1_i;

  // Product: '<S15>/Product' incorporates:
  //   Constant: '<S15>/b'

  px4_noGPS2_B.z2 = px4_noGPS2_B.z1_i * px4_noGPS2_B.z2 * px4_noGPS2_P.b_Value;

  // Signum: '<S15>/Sign'
  px4_noGPS2_B.z2_l = px4_noGPS2_B.z1_i;

  // Gain: '<S1>/Gain1' incorporates:
  //   DiscreteIntegrator: '<S18>/Discrete-Time Integrator3'

  px4_noGPS2_B.z1_i = px4_noGPS2_P.Gain1_Gain_o *
    px4_noGPS2_DW.DiscreteTimeIntegrator3_DSTATE;

  // Signum: '<S15>/Sign'
  if (!rtIsNaN(px4_noGPS2_B.z2_l)) {
    if (px4_noGPS2_B.z2_l < 0.0) {
      px4_noGPS2_B.z2_l = -1.0;
    } else {
      px4_noGPS2_B.z2_l = (px4_noGPS2_B.z2_l > 0.0);
    }
  }

  // Saturate: '<S1>/Saturation4'
  if (px4_noGPS2_B.z1_i > px4_noGPS2_P.Saturation4_UpperSat) {
    px4_noGPS2_B.z1_i = px4_noGPS2_P.Saturation4_UpperSat;
  } else if (px4_noGPS2_B.z1_i < px4_noGPS2_P.Saturation4_LowerSat) {
    px4_noGPS2_B.z1_i = px4_noGPS2_P.Saturation4_LowerSat;
  }

  // End of Saturate: '<S1>/Saturation4'

  // Sum: '<S1>/Add3' incorporates:
  //   Constant: '<S15>/l'
  //   DataStoreWrite: '<S15>/Data Store Write'
  //   Gain: '<S15>/Gain'
  //   Gain: '<S15>/Gain1'
  //   Product: '<S15>/Product1'
  //   Sum: '<S15>/Add'
  //   Sum: '<S37>/Diff'
  //   UnitDelay: '<S37>/UD'
  //
  //  Block description for '<S37>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S37>/UD':
  //
  //   Store in Global RAM

  px4_noGPS2_B.Add3 = (((((px4_noGPS2_B.TSamp - px4_noGPS2_DW.UD_DSTATE) -
    px4_noGPS2_DW.e_pitch_yaw) - px4_noGPS2_B.z2) - px4_noGPS2_B.z2_l *
                        px4_noGPS2_P.l_Value) - px4_noGPS2_P.Gain_Gain *
                       px4_noGPS2_B.e_l) * px4_noGPS2_P.Gain1_Gain -
    px4_noGPS2_B.z1_i;

  // ManualSwitch: '<S1>/Manual Switch' incorporates:
  //   Constant: '<S1>/Constant'
  //   DataStoreWrite: '<Root>/Data Store Write11'

  if (px4_noGPS2_P.ManualSwitch_CurrentSetting == 1) {
    // Saturate: '<S1>/Saturation'
    if (px4_noGPS2_B.Add3 > px4_noGPS2_P.Saturation_UpperSat) {
      px4_noGPS2_B.yaw_thrust = px4_noGPS2_P.Saturation_UpperSat;
    } else if (px4_noGPS2_B.Add3 < px4_noGPS2_P.Saturation_LowerSat) {
      px4_noGPS2_B.yaw_thrust = px4_noGPS2_P.Saturation_LowerSat;
    } else {
      px4_noGPS2_B.yaw_thrust = px4_noGPS2_B.Add3;
    }

    // End of Saturate: '<S1>/Saturation'
  } else {
    px4_noGPS2_B.yaw_thrust = px4_noGPS2_P.Constant_Value_b;
  }

  // End of ManualSwitch: '<S1>/Manual Switch'

  // Switch: '<S13>/Switch' incorporates:
  //   Constant: '<S13>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read14'
  //   DataStoreRead: '<Root>/Data Store Read69'
  //   DataStoreRead: '<S13>/Data Store Read'
  //   DataStoreRead: '<S13>/Data Store Read1'

  if (px4_noGPS2_DW.attitude_flag) {
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS2_DW.pitch;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_DW.pitch_desire;
    px4_noGPS2_B.e_l = px4_noGPS2_DW.pitch_speed;
  } else {
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS2_P.Constant1_Value;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_P.Constant1_Value;
    px4_noGPS2_B.e_l = px4_noGPS2_P.Constant1_Value;
  }

  // End of Switch: '<S13>/Switch'

  // Sum: '<S20>/Add' incorporates:
  //   Sum: '<S13>/Add2'

  px4_noGPS2_B.Product_c = px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 -
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1;
  px4_noGPS2_B.z1_i = px4_noGPS2_B.Product_c;

  // RelationalOperator: '<S22>/Compare' incorporates:
  //   Abs: '<S21>/Abs'
  //   Constant: '<S22>/Constant'
  //   DataStoreRead: '<S21>/Data Store Read1'

  rtb_Compare_i = (fabs(px4_noGPS2_DW.e_pitch) >=
                   px4_noGPS2_P.CompareToConstant1_const_b);

  // Sum: '<S21>/Add' incorporates:
  //   DataStoreRead: '<S21>/Data Store Read'
  //   DataStoreRead: '<S21>/Data Store Read3'
  //   Sum: '<S24>/Add'

  px4_noGPS2_B.Product3 = px4_noGPS2_DW.t - px4_noGPS2_DW.start_time;

  // Fcn: '<S21>/Fcn' incorporates:
  //   Constant: '<S21>/T'
  //   Constant: '<S21>/ch'
  //   Sum: '<S21>/Add'

  px4_noGPS2_B.rtb_Fcn_b_b = px4_noGPS2_P.ch_Value_j / (px4_noGPS2_P.T_Value_p -
    px4_noGPS2_B.Product3);

  // MATLAB Function: '<S21>/MATLAB Function' incorporates:
  //   Constant: '<S21>/t'
  //   DataStoreRead: '<S21>/Data Store Read'
  //   DataStoreRead: '<S21>/Data Store Read3'

  px4_noGPS2_MATLABFunction(rtb_Compare_i, px4_noGPS2_DW.t,
    px4_noGPS2_DW.start_time, px4_noGPS2_B.rtb_Fcn_b_b, px4_noGPS2_P.t_Value_n,
    &px4_noGPS2_B.rtb_roll_hat_e_c);

  // Sum: '<S21>/Add1' incorporates:
  //   Constant: '<S21>/r'

  px4_noGPS2_B.z2_e = px4_noGPS2_P.r_Value_g + px4_noGPS2_B.rtb_roll_hat_e_c;

  // Gain: '<S20>/Gain4' incorporates:
  //   Constant: '<S13>/b'
  //   Product: '<S20>/Product'

  px4_noGPS2_B.z1_i = px4_noGPS2_B.z1_i * px4_noGPS2_B.z2_e *
    px4_noGPS2_P.b_Value_l * px4_noGPS2_P.Gain4_Gain_b;

  // SampleTimeMath: '<S19>/TSamp'
  //
  //  About '<S19>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS2_B.z2 = px4_noGPS2_B.z1_i * px4_noGPS2_P.TSamp_WtEt_p;

  // Sum: '<S13>/Add2' incorporates:
  //   DataStoreWrite: '<S13>/Data Store Write'

  px4_noGPS2_DW.e_pitch = px4_noGPS2_B.Product_c;

  // Sum: '<S13>/Add1'
  px4_noGPS2_B.z1_i = px4_noGPS2_B.e_l - px4_noGPS2_B.z1_i;

  // Product: '<S13>/Product' incorporates:
  //   Constant: '<S13>/b'

  px4_noGPS2_B.Product_c = px4_noGPS2_B.z1_i * px4_noGPS2_B.z2_e *
    px4_noGPS2_P.b_Value_l;

  // Signum: '<S13>/Sign'
  px4_noGPS2_B.z2_l = px4_noGPS2_B.z1_i;

  // Gain: '<S1>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S16>/Discrete-Time Integrator3'

  px4_noGPS2_B.z1_i = px4_noGPS2_P.Gain2_Gain *
    px4_noGPS2_DW.DiscreteTimeIntegrator3_DSTAT_a;

  // Signum: '<S13>/Sign'
  if (!rtIsNaN(px4_noGPS2_B.z2_l)) {
    if (px4_noGPS2_B.z2_l < 0.0) {
      px4_noGPS2_B.z2_l = -1.0;
    } else {
      px4_noGPS2_B.z2_l = (px4_noGPS2_B.z2_l > 0.0);
    }
  }

  // Sum: '<S1>/Add2' incorporates:
  //   Constant: '<S13>/l'
  //   DataStoreWrite: '<Root>/Data Store Write12'
  //   DataStoreWrite: '<S13>/Data Store Write'
  //   Gain: '<S13>/Gain'
  //   Gain: '<S13>/Gain1'
  //   Product: '<S13>/Product1'
  //   Sum: '<S13>/Add'
  //   Sum: '<S19>/Diff'
  //   UnitDelay: '<S19>/UD'
  //
  //  Block description for '<S19>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S19>/UD':
  //
  //   Store in Global RAM

  px4_noGPS2_B.z2_e = (((((px4_noGPS2_B.z2 - px4_noGPS2_DW.UD_DSTATE_b) -
    px4_noGPS2_DW.e_pitch) - px4_noGPS2_B.Product_c) - px4_noGPS2_B.z2_l *
                        px4_noGPS2_P.l_Value_b) - px4_noGPS2_P.Gain_Gain_o *
                       px4_noGPS2_B.e_l) * px4_noGPS2_P.Gain1_Gain_b -
    px4_noGPS2_B.z1_i;

  // Switch: '<S14>/Switch' incorporates:
  //   Constant: '<S14>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read18'
  //   DataStoreRead: '<Root>/Data Store Read68'
  //   DataStoreRead: '<S14>/Data Store Read'
  //   DataStoreRead: '<S14>/Data Store Read1'

  if (px4_noGPS2_DW.attitude_flag) {
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS2_DW.roll;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_DW.roll_desire;
    px4_noGPS2_B.e_l = px4_noGPS2_DW.roll_speed;
  } else {
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS2_P.Constant1_Value_n;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_P.Constant1_Value_n;
    px4_noGPS2_B.e_l = px4_noGPS2_P.Constant1_Value_n;
  }

  // End of Switch: '<S14>/Switch'

  // Sum: '<S29>/Add' incorporates:
  //   Sum: '<S14>/Add2'

  px4_noGPS2_B.l2_j = px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 -
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1;
  px4_noGPS2_B.Abs6 = px4_noGPS2_B.l2_j;

  // RelationalOperator: '<S31>/Compare' incorporates:
  //   Abs: '<S30>/Abs'
  //   Constant: '<S31>/Constant'
  //   DataStoreRead: '<S30>/Data Store Read1'

  rtb_Compare_g2 = (fabs(px4_noGPS2_DW.e_pitch_roll) >=
                    px4_noGPS2_P.CompareToConstant1_const_h);

  // Sum: '<S30>/Add' incorporates:
  //   DataStoreRead: '<S30>/Data Store Read'
  //   DataStoreRead: '<S30>/Data Store Read3'
  //   Sum: '<S33>/Add'

  px4_noGPS2_B.Product4 = px4_noGPS2_DW.t - px4_noGPS2_DW.start_time_roll;

  // Fcn: '<S30>/Fcn' incorporates:
  //   Constant: '<S30>/T'
  //   Constant: '<S30>/ch'
  //   Sum: '<S30>/Add'

  px4_noGPS2_B.rtb_Fcn_a_k = px4_noGPS2_P.ch_Value_e / (px4_noGPS2_P.T_Value_c -
    px4_noGPS2_B.Product4);

  // MATLAB Function: '<S30>/MATLAB Function' incorporates:
  //   Constant: '<S30>/t'
  //   DataStoreRead: '<S30>/Data Store Read'
  //   DataStoreRead: '<S30>/Data Store Read3'

  px4_noGPS2_MATLABFunction(rtb_Compare_g2, px4_noGPS2_DW.t,
    px4_noGPS2_DW.start_time_roll, px4_noGPS2_B.rtb_Fcn_a_k,
    px4_noGPS2_P.t_Value_m, &px4_noGPS2_B.rtb_DataStoreRead49_c);

  // Sum: '<S30>/Add1' incorporates:
  //   Constant: '<S30>/r'

  px4_noGPS2_B.z2_l = px4_noGPS2_P.r_Value_p +
    px4_noGPS2_B.rtb_DataStoreRead49_c;

  // Gain: '<S29>/Gain4' incorporates:
  //   Constant: '<S14>/b'
  //   Product: '<S29>/Product'

  px4_noGPS2_B.Abs6 = px4_noGPS2_B.Abs6 * px4_noGPS2_B.z2_l *
    px4_noGPS2_P.b_Value_h * px4_noGPS2_P.Gain4_Gain_o;

  // SampleTimeMath: '<S28>/TSamp'
  //
  //  About '<S28>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS2_B.Product_c = px4_noGPS2_B.Abs6 * px4_noGPS2_P.TSamp_WtEt_o;

  // Sum: '<S14>/Add2' incorporates:
  //   DataStoreWrite: '<S14>/Data Store Write'

  px4_noGPS2_DW.e_pitch_roll = px4_noGPS2_B.l2_j;

  // Sum: '<S14>/Add1'
  px4_noGPS2_B.Abs6 = px4_noGPS2_B.e_l - px4_noGPS2_B.Abs6;

  // Product: '<S14>/Product' incorporates:
  //   Constant: '<S14>/b'

  px4_noGPS2_B.Product_cm = px4_noGPS2_B.Abs6 * px4_noGPS2_B.z2_l *
    px4_noGPS2_P.b_Value_h;

  // Signum: '<S14>/Sign'
  px4_noGPS2_B.z2_l = px4_noGPS2_B.Abs6;

  // Gain: '<S1>/J' incorporates:
  //   DiscreteIntegrator: '<S17>/Discrete-Time Integrator3'

  px4_noGPS2_B.Abs6 = px4_noGPS2_P.J_Gain_b *
    px4_noGPS2_DW.DiscreteTimeIntegrator3_DSTAT_m;

  // Signum: '<S14>/Sign'
  if (!rtIsNaN(px4_noGPS2_B.z2_l)) {
    if (px4_noGPS2_B.z2_l < 0.0) {
      px4_noGPS2_B.z2_l = -1.0;
    } else {
      px4_noGPS2_B.z2_l = (px4_noGPS2_B.z2_l > 0.0);
    }
  }

  // Sum: '<S1>/Add1' incorporates:
  //   Constant: '<S14>/l'
  //   DataStoreWrite: '<Root>/Data Store Write13'
  //   DataStoreWrite: '<S14>/Data Store Write'
  //   Gain: '<S14>/Gain'
  //   Gain: '<S14>/J'
  //   Product: '<S14>/Product1'
  //   Sum: '<S14>/Add'
  //   Sum: '<S28>/Diff'
  //   UnitDelay: '<S28>/UD'
  //
  //  Block description for '<S28>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S28>/UD':
  //
  //   Store in Global RAM

  px4_noGPS2_B.z2_l = (((((px4_noGPS2_B.Product_c - px4_noGPS2_DW.UD_DSTATE_n) -
    px4_noGPS2_DW.e_pitch_roll) - px4_noGPS2_B.Product_cm) - px4_noGPS2_B.z2_l *
                        px4_noGPS2_P.l_Value_n) - px4_noGPS2_P.Gain_Gain_m *
                       px4_noGPS2_B.e_l) * px4_noGPS2_P.J_Gain -
    px4_noGPS2_B.Abs6;

  // Logic: '<S42>/Logical Operator' incorporates:
  //   Abs: '<S42>/Abs1'
  //   Constant: '<S43>/Constant'
  //   Constant: '<S44>/Constant'
  //   DataStoreRead: '<S42>/Data Store Read2'
  //   RelationalOperator: '<S43>/Compare'
  //   RelationalOperator: '<S44>/Compare'

  rtb_LogicalOperator = ((fabs(px4_noGPS2_DW.e_pitch_yaw) >=
    px4_noGPS2_P.CompareToConstant2_const) && (rtb_Fcn_tmp >=
    px4_noGPS2_P.CompareToConstant1_const_hq));

  // Outputs for Triggered SubSystem: '<S42>/Subsystem' incorporates:
  //   TriggerPort: '<S45>/Trigger'

  if (rtb_LogicalOperator && (px4_noGPS2_PrevZCX.Subsystem_Trig_ZCE != POS_ZCSIG))
  {
    // DataStoreWrite: '<S45>/Data Store Write' incorporates:
    //   DataStoreRead: '<S45>/Data Store Read2'

    px4_noGPS2_DW.start_time_yaw = px4_noGPS2_DW.t;
  }

  px4_noGPS2_PrevZCX.Subsystem_Trig_ZCE = rtb_LogicalOperator;

  // End of Outputs for SubSystem: '<S42>/Subsystem'
  // Logic: '<S24>/Logical Operator' incorporates:
  //   Abs: '<S24>/Abs1'
  //   Constant: '<S25>/Constant'
  //   Constant: '<S26>/Constant'
  //   DataStoreRead: '<S24>/Data Store Read2'
  //   RelationalOperator: '<S25>/Compare'
  //   RelationalOperator: '<S26>/Compare'

  rtb_LogicalOperator = ((fabs(px4_noGPS2_DW.e_pitch) >=
    px4_noGPS2_P.CompareToConstant2_const_o) && (px4_noGPS2_B.Product3 >=
    px4_noGPS2_P.CompareToConstant1_const_p));

  // Outputs for Triggered SubSystem: '<S24>/Subsystem' incorporates:
  //   TriggerPort: '<S27>/Trigger'

  if (rtb_LogicalOperator && (px4_noGPS2_PrevZCX.Subsystem_Trig_ZCE_e !=
       POS_ZCSIG)) {
    // DataStoreWrite: '<S27>/Data Store Write' incorporates:
    //   DataStoreRead: '<S27>/Data Store Read2'

    px4_noGPS2_DW.start_time = px4_noGPS2_DW.t;
  }

  px4_noGPS2_PrevZCX.Subsystem_Trig_ZCE_e = rtb_LogicalOperator;

  // End of Outputs for SubSystem: '<S24>/Subsystem'
  // Logic: '<S33>/Logical Operator' incorporates:
  //   Abs: '<S33>/Abs1'
  //   Constant: '<S34>/Constant'
  //   Constant: '<S35>/Constant'
  //   DataStoreRead: '<S33>/Data Store Read2'
  //   RelationalOperator: '<S34>/Compare'
  //   RelationalOperator: '<S35>/Compare'

  rtb_LogicalOperator = ((fabs(px4_noGPS2_DW.e_pitch_roll) >=
    px4_noGPS2_P.CompareToConstant2_const_a) && (px4_noGPS2_B.Product4 >=
    px4_noGPS2_P.CompareToConstant1_const_a));

  // Outputs for Triggered SubSystem: '<S33>/Subsystem' incorporates:
  //   TriggerPort: '<S36>/Trigger'

  if (rtb_LogicalOperator && (px4_noGPS2_PrevZCX.Subsystem_Trig_ZCE_j !=
       POS_ZCSIG)) {
    // DataStoreWrite: '<S36>/Data Store Write' incorporates:
    //   DataStoreRead: '<S36>/Data Store Read2'

    px4_noGPS2_DW.start_time_roll = px4_noGPS2_DW.t;
  }

  px4_noGPS2_PrevZCX.Subsystem_Trig_ZCE_j = rtb_LogicalOperator;

  // End of Outputs for SubSystem: '<S33>/Subsystem'

  // Gain: '<S18>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S18>/Discrete-Time Integrator'

  px4_noGPS2_B.Product_cm = px4_noGPS2_P.Gain2_Gain_c *
    px4_noGPS2_DW.DiscreteTimeIntegrator_DSTATE;

  // ZeroOrderHold: '<S18>/Zero-Order Hold3' incorporates:
  //   Gain: '<S18>/1//J'

  px4_noGPS2_B.Product_cm = px4_noGPS2_P.uJ_Gain * px4_noGPS2_B.Add3;

  // ZeroOrderHold: '<S18>/Zero-Order Hold1' incorporates:
  //   DataStoreRead: '<S18>/Data Store Read'

  px4_noGPS2_B.e_l = px4_noGPS2_DW.yaw;

  // Switch: '<S18>/Switch' incorporates:
  //   Constant: '<S18>/Constant3'
  //   DataStoreRead: '<S18>/Data Store Read1'
  //   DataStoreRead: '<S18>/Data Store Read2'
  //   Gain: '<S18>/k//J'

  if (px4_noGPS2_DW.observer_flag) {
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS2_B.Product_cm;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_P.kJ_Gain *
      px4_noGPS2_DW.yaw_speed;
  } else {
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS2_P.Constant3_Value_d;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_P.Constant3_Value_d;
    px4_noGPS2_B.e_l = px4_noGPS2_P.Constant3_Value_d;
  }

  // End of Switch: '<S18>/Switch'

  // Sum: '<S18>/Add1' incorporates:
  //   DiscreteIntegrator: '<S18>/Discrete-Time Integrator'

  px4_noGPS2_B.e_l -= px4_noGPS2_DW.DiscreteTimeIntegrator_DSTATE;

  // Abs: '<S18>/Abs3' incorporates:
  //   Abs: '<S18>/Abs4'
  //   Abs: '<S18>/Abs5'
  //   Abs: '<S18>/Abs6'

  px4_noGPS2_B.Product_cm = fabs(px4_noGPS2_B.e_l);

  // Abs: '<S18>/Abs5'
  px4_noGPS2_B.roll_desire = px4_noGPS2_B.Product_cm;

  // Saturate: '<S18>/Saturation'
  if (px4_noGPS2_B.e_l > px4_noGPS2_P.Saturation_UpperSat_b) {
    rtb_Fcn_tmp = px4_noGPS2_P.Saturation_UpperSat_b;
  } else if (px4_noGPS2_B.e_l < px4_noGPS2_P.Saturation_LowerSat_k) {
    rtb_Fcn_tmp = px4_noGPS2_P.Saturation_LowerSat_k;
  } else {
    rtb_Fcn_tmp = px4_noGPS2_B.e_l;
  }

  // End of Saturate: '<S18>/Saturation'

  // Gain: '<S18>/lambda1'
  px4_noGPS2_B.Add3 = px4_noGPS2_P.lambda1_Gain * px4_noGPS2_B.e_l;

  // Sum: '<S18>/Add7' incorporates:
  //   Constant: '<S18>/Constant1'
  //   Sum: '<S18>/Add13'
  //   Sum: '<S18>/Add18'

  px4_noGPS2_B.l2 = px4_noGPS2_P.Constant1_Value_f + px4_noGPS2_B.e_l;
  px4_noGPS2_B.roll_hat_k = px4_noGPS2_B.l2;

  // Sum: '<S18>/Add6' incorporates:
  //   Constant: '<S18>/Constant1'
  //   Sum: '<S18>/Add12'
  //   Sum: '<S18>/Add17'

  px4_noGPS2_B.Product7 = px4_noGPS2_B.e_l - px4_noGPS2_P.Constant1_Value_f;

  // DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
  //   Sum: '<S18>/Add6'

  px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_B.Product7;

  // Saturate: '<S18>/Saturation10'
  if (px4_noGPS2_B.roll_hat_k > px4_noGPS2_P.Saturation10_UpperSat) {
    px4_noGPS2_B.roll_hat_k = px4_noGPS2_P.Saturation10_UpperSat;
  } else if (px4_noGPS2_B.roll_hat_k < px4_noGPS2_P.Saturation10_LowerSat) {
    px4_noGPS2_B.roll_hat_k = px4_noGPS2_P.Saturation10_LowerSat;
  }

  // End of Saturate: '<S18>/Saturation10'

  // Saturate: '<S18>/Saturation11'
  if (px4_noGPS2_B.rtb_roll_hat_e_c > px4_noGPS2_P.Saturation11_UpperSat) {
    px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_P.Saturation11_UpperSat;
  } else if (px4_noGPS2_B.rtb_roll_hat_e_c < px4_noGPS2_P.Saturation11_LowerSat)
  {
    px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_P.Saturation11_LowerSat;
  }

  // End of Saturate: '<S18>/Saturation11'

  // DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S18>/Gain'
  //   Sum: '<S18>/Add8'

  px4_noGPS2_B.rtb_roll_hat_e_c = (px4_noGPS2_B.roll_hat_k -
    px4_noGPS2_B.rtb_roll_hat_e_c) * px4_noGPS2_P.Gain_Gain_ml;

  // Fcn: '<S18>/Fcn3' incorporates:
  //   Constant: '<S18>/Constant1'

  if (px4_noGPS2_P.Constant1_Value_f < 0.0) {
    rtb_Switch_idx_0 = -rt_powd_snf(-px4_noGPS2_P.Constant1_Value_f, -0.5);
  } else {
    rtb_Switch_idx_0 = rt_powd_snf(px4_noGPS2_P.Constant1_Value_f, -0.5);
  }

  // End of Fcn: '<S18>/Fcn3'

  // Product: '<S18>/Product3'
  px4_noGPS2_B.Product3 = rtb_Switch_idx_0 * px4_noGPS2_B.rtb_roll_hat_e_c *
    px4_noGPS2_B.e_l;

  // Saturate: '<S18>/Saturation8'
  if (px4_noGPS2_B.e_l > px4_noGPS2_P.Saturation8_UpperSat) {
    px4_noGPS2_B.roll_hat_k = px4_noGPS2_P.Saturation8_UpperSat;
  } else if (px4_noGPS2_B.e_l < px4_noGPS2_P.Saturation8_LowerSat) {
    px4_noGPS2_B.roll_hat_k = px4_noGPS2_P.Saturation8_LowerSat;
  } else {
    px4_noGPS2_B.roll_hat_k = px4_noGPS2_B.e_l;
  }

  // End of Saturate: '<S18>/Saturation8'

  // Product: '<S18>/Product4' incorporates:
  //   Abs: '<S18>/Abs3'
  //   Constant: '<S18>/Constant2'
  //   Fcn: '<S18>/Fcn4'
  //   Sum: '<S18>/Add10'

  px4_noGPS2_B.Product4 = rt_powd_snf(px4_noGPS2_B.Product_cm, 0.5) *
    px4_noGPS2_B.roll_hat_k * (px4_noGPS2_P.Constant2_Value_g -
    px4_noGPS2_B.rtb_roll_hat_e_c);

  // DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
  //   Sum: '<S18>/Add13'

  px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_B.l2;

  // Sum: '<S18>/Add12'
  px4_noGPS2_B.roll_hat_k = px4_noGPS2_B.Product7;

  // Saturate: '<S18>/Saturation13'
  if (px4_noGPS2_B.rtb_roll_hat_e_c > px4_noGPS2_P.Saturation13_UpperSat) {
    px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_P.Saturation13_UpperSat;
  } else if (px4_noGPS2_B.rtb_roll_hat_e_c < px4_noGPS2_P.Saturation13_LowerSat)
  {
    px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_P.Saturation13_LowerSat;
  }

  // End of Saturate: '<S18>/Saturation13'

  // Saturate: '<S18>/Saturation9'
  if (px4_noGPS2_B.roll_hat_k > px4_noGPS2_P.Saturation9_UpperSat) {
    px4_noGPS2_B.roll_hat_k = px4_noGPS2_P.Saturation9_UpperSat;
  } else if (px4_noGPS2_B.roll_hat_k < px4_noGPS2_P.Saturation9_LowerSat) {
    px4_noGPS2_B.roll_hat_k = px4_noGPS2_P.Saturation9_LowerSat;
  }

  // End of Saturate: '<S18>/Saturation9'

  // DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S18>/Gain1'
  //   Sum: '<S18>/Add14'

  px4_noGPS2_B.rtb_roll_hat_e_c = (px4_noGPS2_B.rtb_roll_hat_e_c -
    px4_noGPS2_B.roll_hat_k) * px4_noGPS2_P.Gain1_Gain_a;

  // Sum: '<S18>/Add11' incorporates:
  //   Constant: '<S18>/Constant4'

  px4_noGPS2_B.e_g = px4_noGPS2_P.Constant4_Value -
    px4_noGPS2_B.rtb_roll_hat_e_c;

  // Fcn: '<S18>/Fcn6' incorporates:
  //   Constant: '<S18>/Constant1'

  if (px4_noGPS2_P.Constant1_Value_f < 0.0) {
    rtb_Switch_idx_0 = -rt_powd_snf(-px4_noGPS2_P.Constant1_Value_f, -0.9375);
  } else {
    rtb_Switch_idx_0 = rt_powd_snf(px4_noGPS2_P.Constant1_Value_f, -0.9375);
  }

  // End of Fcn: '<S18>/Fcn6'

  // Product: '<S18>/Product6'
  px4_noGPS2_B.Product6 = rtb_Switch_idx_0 * px4_noGPS2_B.rtb_roll_hat_e_c *
    px4_noGPS2_B.e_l;

  // Saturate: '<S18>/Saturation12'
  if (px4_noGPS2_B.e_l > px4_noGPS2_P.Saturation12_UpperSat) {
    // DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
    px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_P.Saturation12_UpperSat;
  } else if (px4_noGPS2_B.e_l < px4_noGPS2_P.Saturation12_LowerSat) {
    // DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
    px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_P.Saturation12_LowerSat;
  } else {
    // DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
    px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_B.e_l;
  }

  // End of Saturate: '<S18>/Saturation12'

  // Product: '<S18>/Product5' incorporates:
  //   Fcn: '<S18>/Fcn5'

  px4_noGPS2_B.e_g *= rt_powd_snf(px4_noGPS2_B.Product_cm, 0.0625) *
    px4_noGPS2_B.rtb_roll_hat_e_c;

  // DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
  //   Sum: '<S18>/Add18'

  px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_B.l2;

  // Sum: '<S18>/Add17'
  px4_noGPS2_B.roll_hat_k = px4_noGPS2_B.Product7;

  // Saturate: '<S18>/Saturation16'
  if (px4_noGPS2_B.rtb_roll_hat_e_c > px4_noGPS2_P.Saturation16_UpperSat) {
    px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_P.Saturation16_UpperSat;
  } else if (px4_noGPS2_B.rtb_roll_hat_e_c < px4_noGPS2_P.Saturation16_LowerSat)
  {
    px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_P.Saturation16_LowerSat;
  }

  // End of Saturate: '<S18>/Saturation16'

  // Saturate: '<S18>/Saturation14'
  if (px4_noGPS2_B.roll_hat_k > px4_noGPS2_P.Saturation14_UpperSat) {
    px4_noGPS2_B.roll_hat_k = px4_noGPS2_P.Saturation14_UpperSat;
  } else if (px4_noGPS2_B.roll_hat_k < px4_noGPS2_P.Saturation14_LowerSat) {
    px4_noGPS2_B.roll_hat_k = px4_noGPS2_P.Saturation14_LowerSat;
  }

  // End of Saturate: '<S18>/Saturation14'

  // DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S18>/Gain3'
  //   Sum: '<S18>/Add19'

  px4_noGPS2_B.rtb_roll_hat_e_c = (px4_noGPS2_B.rtb_roll_hat_e_c -
    px4_noGPS2_B.roll_hat_k) * px4_noGPS2_P.Gain3_Gain;

  // Sum: '<S18>/Add16' incorporates:
  //   Constant: '<S18>/Constant6'

  px4_noGPS2_B.Product_cm = px4_noGPS2_P.Constant6_Value -
    px4_noGPS2_B.rtb_roll_hat_e_c;

  // Saturate: '<S18>/Saturation1'
  if (px4_noGPS2_B.e_l > px4_noGPS2_P.Saturation1_UpperSat) {
    px4_noGPS2_B.roll_hat_k = px4_noGPS2_P.Saturation1_UpperSat;
  } else if (px4_noGPS2_B.e_l < px4_noGPS2_P.Saturation1_LowerSat) {
    px4_noGPS2_B.roll_hat_k = px4_noGPS2_P.Saturation1_LowerSat;
  } else {
    px4_noGPS2_B.roll_hat_k = px4_noGPS2_B.e_l;
  }

  // End of Saturate: '<S18>/Saturation1'

  // Gain: '<S18>/l2'
  px4_noGPS2_B.l2 = px4_noGPS2_P.l2_Gain * px4_noGPS2_B.roll_hat_k;

  // Sum: '<S18>/Add3'
  px4_noGPS2_B.roll_hat_k = px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 -
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1;

  // Fcn: '<S18>/Fcn7' incorporates:
  //   Constant: '<S18>/Constant1'

  if (px4_noGPS2_P.Constant1_Value_f < 0.0) {
    rtb_Switch_idx_0 = -rt_powd_snf(-px4_noGPS2_P.Constant1_Value_f, -0.75);
  } else {
    rtb_Switch_idx_0 = rt_powd_snf(px4_noGPS2_P.Constant1_Value_f, -0.75);
  }

  // End of Fcn: '<S18>/Fcn7'

  // Product: '<S18>/Product7'
  px4_noGPS2_B.Product7 = rtb_Switch_idx_0 * px4_noGPS2_B.rtb_roll_hat_e_c *
    px4_noGPS2_B.e_l;

  // Saturate: '<S18>/Saturation15'
  if (px4_noGPS2_B.e_l > px4_noGPS2_P.Saturation15_UpperSat) {
    // DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
    px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_P.Saturation15_UpperSat;
  } else if (px4_noGPS2_B.e_l < px4_noGPS2_P.Saturation15_LowerSat) {
    // DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
    px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_P.Saturation15_LowerSat;
  } else {
    // DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
    px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_B.e_l;
  }

  // End of Saturate: '<S18>/Saturation15'

  // Sum: '<S18>/Add2' incorporates:
  //   DiscreteIntegrator: '<S18>/Discrete-Time Integrator3'
  //   Fcn: '<S18>/Fcn8'
  //   Gain: '<S18>/Gain6'
  //   Gain: '<S18>/lambda2'
  //   Product: '<S18>/Product8'
  //   Sum: '<S18>/Add20'

  px4_noGPS2_B.l2 = (((px4_noGPS2_P.lambda2_Gain * px4_noGPS2_B.e_l +
                       px4_noGPS2_B.l2) + px4_noGPS2_B.roll_hat_k) +
                     px4_noGPS2_DW.DiscreteTimeIntegrator3_DSTATE) +
    (rt_powd_snf(px4_noGPS2_B.roll_desire, 0.25) * px4_noGPS2_B.rtb_roll_hat_e_c
     * px4_noGPS2_B.Product_cm + px4_noGPS2_B.Product7) *
    px4_noGPS2_P.Gain6_Gain;

  // Saturate: '<S18>/Saturation3'
  if (px4_noGPS2_B.e_l > px4_noGPS2_P.Saturation3_UpperSat) {
    // DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
    px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_P.Saturation3_UpperSat;
  } else if (px4_noGPS2_B.e_l < px4_noGPS2_P.Saturation3_LowerSat) {
    // DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
    px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_P.Saturation3_LowerSat;
  } else {
    // DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
    px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_B.e_l;
  }

  // End of Saturate: '<S18>/Saturation3'

  // Gain: '<S18>/l4'
  px4_noGPS2_B.l4 = px4_noGPS2_P.l4_Gain * px4_noGPS2_B.rtb_roll_hat_e_c;

  // Gain: '<S18>/lambda4'
  px4_noGPS2_B.lambda4 = px4_noGPS2_P.lambda4_Gain * px4_noGPS2_B.e_l;

  // DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
  px4_noGPS2_B.rtb_roll_hat_e_c = px4_noGPS2_DW.DiscreteTimeIntegrator_DSTATE_p;

  // Gain: '<S16>/Gain2'
  px4_noGPS2_B.roll_hat_k = px4_noGPS2_P.Gain2_Gain_g *
    px4_noGPS2_B.rtb_roll_hat_e_c;

  // ZeroOrderHold: '<S16>/Zero-Order Hold3' incorporates:
  //   DataStoreWrite: '<Root>/Data Store Write12'
  //   Gain: '<S16>/1//J'

  px4_noGPS2_B.roll_hat_k = px4_noGPS2_P.uJ_Gain_p * px4_noGPS2_B.z2_e;

  // ZeroOrderHold: '<S16>/Zero-Order Hold2' incorporates:
  //   DataStoreRead: '<S16>/Data Store Read1'
  //   Gain: '<S16>/k//J'

  px4_noGPS2_B.roll = px4_noGPS2_P.kJ_Gain_c * px4_noGPS2_DW.pitch_speed;

  // ZeroOrderHold: '<S16>/Zero-Order Hold1' incorporates:
  //   DataStoreRead: '<S16>/Data Store Read'

  px4_noGPS2_B.roll_desire = px4_noGPS2_DW.pitch;

  // Switch: '<S16>/Switch' incorporates:
  //   Constant: '<S16>/Constant3'
  //   DataStoreRead: '<S16>/Data Store Read2'

  if (px4_noGPS2_DW.observer_flag) {
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS2_B.roll_hat_k;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_B.roll;
    px4_noGPS2_B.e_l = px4_noGPS2_B.roll_desire;
  } else {
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS2_P.Constant3_Value;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_P.Constant3_Value;
    px4_noGPS2_B.e_l = px4_noGPS2_P.Constant3_Value;
  }

  // End of Switch: '<S16>/Switch'

  // Sum: '<S16>/Add1'
  px4_noGPS2_B.roll_hat_k = px4_noGPS2_B.e_l - px4_noGPS2_B.rtb_roll_hat_e_c;

  // Abs: '<S16>/Abs3' incorporates:
  //   Abs: '<S16>/Abs4'
  //   Abs: '<S16>/Abs5'
  //   Abs: '<S16>/Abs6'

  px4_noGPS2_B.roll = fabs(px4_noGPS2_B.roll_hat_k);

  // Abs: '<S16>/Abs4'
  px4_noGPS2_B.roll_desire = px4_noGPS2_B.roll;

  // Abs: '<S16>/Abs5'
  px4_noGPS2_B.e_l = px4_noGPS2_B.roll;

  // Saturate: '<S16>/Saturation'
  if (px4_noGPS2_B.roll_hat_k > px4_noGPS2_P.Saturation_UpperSat_n) {
    px4_noGPS2_B.Product_cm = px4_noGPS2_P.Saturation_UpperSat_n;
  } else if (px4_noGPS2_B.roll_hat_k < px4_noGPS2_P.Saturation_LowerSat_g) {
    px4_noGPS2_B.Product_cm = px4_noGPS2_P.Saturation_LowerSat_g;
  } else {
    px4_noGPS2_B.Product_cm = px4_noGPS2_B.roll_hat_k;
  }

  // End of Saturate: '<S16>/Saturation'

  // Gain: '<S16>/l1'
  px4_noGPS2_B.Product7 = px4_noGPS2_P.l1_Gain_p * px4_noGPS2_B.Product_cm;

  // Gain: '<S16>/lambda1'
  px4_noGPS2_B.lambda1_a = px4_noGPS2_P.lambda1_Gain_a * px4_noGPS2_B.roll_hat_k;

  // DiscreteIntegrator: '<S16>/Discrete-Time Integrator1'
  px4_noGPS2_B.Product_cm = px4_noGPS2_DW.DiscreteTimeIntegrator1_DSTAT_i;

  // Sum: '<S16>/Add7' incorporates:
  //   Constant: '<S16>/Constant1'
  //   Sum: '<S16>/Add13'
  //   Sum: '<S16>/Add18'

  px4_noGPS2_B.l2_j = px4_noGPS2_P.Constant1_Value_j + px4_noGPS2_B.roll_hat_k;
  px4_noGPS2_B.Abs6 = px4_noGPS2_B.l2_j;

  // Sum: '<S16>/Add6' incorporates:
  //   Constant: '<S16>/Constant1'
  //   Sum: '<S16>/Add12'
  //   Sum: '<S16>/Add17'

  px4_noGPS2_B.z1_i = px4_noGPS2_B.roll_hat_k - px4_noGPS2_P.Constant1_Value_j;

  // Saturate: '<S16>/Saturation10'
  if (px4_noGPS2_B.Abs6 > px4_noGPS2_P.Saturation10_UpperSat_o) {
    px4_noGPS2_B.Abs6 = px4_noGPS2_P.Saturation10_UpperSat_o;
  } else if (px4_noGPS2_B.Abs6 < px4_noGPS2_P.Saturation10_LowerSat_b) {
    px4_noGPS2_B.Abs6 = px4_noGPS2_P.Saturation10_LowerSat_b;
  }

  // End of Saturate: '<S16>/Saturation10'

  // Saturate: '<S16>/Saturation11'
  if (px4_noGPS2_B.z1_i > px4_noGPS2_P.Saturation11_UpperSat_p) {
    px4_noGPS2_B.Product3_a = px4_noGPS2_P.Saturation11_UpperSat_p;
  } else if (px4_noGPS2_B.z1_i < px4_noGPS2_P.Saturation11_LowerSat_i) {
    px4_noGPS2_B.Product3_a = px4_noGPS2_P.Saturation11_LowerSat_i;
  } else {
    px4_noGPS2_B.Product3_a = px4_noGPS2_B.z1_i;
  }

  // End of Saturate: '<S16>/Saturation11'

  // Gain: '<S16>/Gain' incorporates:
  //   Sum: '<S16>/Add8'

  px4_noGPS2_B.Abs6 = (px4_noGPS2_B.Abs6 - px4_noGPS2_B.Product3_a) *
    px4_noGPS2_P.Gain_Gain_g;

  // Fcn: '<S16>/Fcn3' incorporates:
  //   Constant: '<S16>/Constant1'

  if (px4_noGPS2_P.Constant1_Value_j < 0.0) {
    rtb_Switch_idx_0 = -rt_powd_snf(-px4_noGPS2_P.Constant1_Value_j, -0.5);
  } else {
    rtb_Switch_idx_0 = rt_powd_snf(px4_noGPS2_P.Constant1_Value_j, -0.5);
  }

  // End of Fcn: '<S16>/Fcn3'

  // Product: '<S16>/Product3'
  px4_noGPS2_B.Product3_a = rtb_Switch_idx_0 * px4_noGPS2_B.Abs6 *
    px4_noGPS2_B.roll_hat_k;

  // Fcn: '<S16>/Fcn4'
  rtb_Switch_idx_0 = rt_powd_snf(px4_noGPS2_B.roll, 0.5);

  // Saturate: '<S16>/Saturation8'
  if (px4_noGPS2_B.roll_hat_k > px4_noGPS2_P.Saturation8_UpperSat_g) {
    px4_noGPS2_B.roll = px4_noGPS2_P.Saturation8_UpperSat_g;
  } else if (px4_noGPS2_B.roll_hat_k < px4_noGPS2_P.Saturation8_LowerSat_g) {
    px4_noGPS2_B.roll = px4_noGPS2_P.Saturation8_LowerSat_g;
  } else {
    px4_noGPS2_B.roll = px4_noGPS2_B.roll_hat_k;
  }

  // End of Saturate: '<S16>/Saturation8'

  // Product: '<S16>/Product4' incorporates:
  //   Constant: '<S16>/Constant2'
  //   Fcn: '<S16>/Fcn4'
  //   Sum: '<S16>/Add10'

  px4_noGPS2_B.Product4_k = rtb_Switch_idx_0 * px4_noGPS2_B.roll *
    (px4_noGPS2_P.Constant2_Value_h - px4_noGPS2_B.Abs6);

  // Sum: '<S16>/Add13'
  px4_noGPS2_B.roll = px4_noGPS2_B.l2_j;

  // Sum: '<S16>/Add12'
  px4_noGPS2_B.Abs6 = px4_noGPS2_B.z1_i;

  // Saturate: '<S16>/Saturation13'
  if (px4_noGPS2_B.roll > px4_noGPS2_P.Saturation13_UpperSat_i) {
    px4_noGPS2_B.roll = px4_noGPS2_P.Saturation13_UpperSat_i;
  } else if (px4_noGPS2_B.roll < px4_noGPS2_P.Saturation13_LowerSat_c) {
    px4_noGPS2_B.roll = px4_noGPS2_P.Saturation13_LowerSat_c;
  }

  // End of Saturate: '<S16>/Saturation13'

  // Saturate: '<S16>/Saturation9'
  if (px4_noGPS2_B.Abs6 > px4_noGPS2_P.Saturation9_UpperSat_i) {
    px4_noGPS2_B.Abs6 = px4_noGPS2_P.Saturation9_UpperSat_i;
  } else if (px4_noGPS2_B.Abs6 < px4_noGPS2_P.Saturation9_LowerSat_c) {
    px4_noGPS2_B.Abs6 = px4_noGPS2_P.Saturation9_LowerSat_c;
  }

  // End of Saturate: '<S16>/Saturation9'

  // Gain: '<S16>/Gain1' incorporates:
  //   Sum: '<S16>/Add14'

  px4_noGPS2_B.roll = (px4_noGPS2_B.roll - px4_noGPS2_B.Abs6) *
    px4_noGPS2_P.Gain1_Gain_d;

  // Sum: '<S16>/Add11' incorporates:
  //   Constant: '<S16>/Constant4'

  px4_noGPS2_B.e_gq = px4_noGPS2_P.Constant4_Value_n - px4_noGPS2_B.roll;

  // Fcn: '<S16>/Fcn6' incorporates:
  //   Constant: '<S16>/Constant1'

  if (px4_noGPS2_P.Constant1_Value_j < 0.0) {
    rtb_Switch_idx_0 = -rt_powd_snf(-px4_noGPS2_P.Constant1_Value_j, -0.9375);
  } else {
    rtb_Switch_idx_0 = rt_powd_snf(px4_noGPS2_P.Constant1_Value_j, -0.9375);
  }

  // End of Fcn: '<S16>/Fcn6'

  // Product: '<S16>/Product6'
  px4_noGPS2_B.Abs6 = rtb_Switch_idx_0 * px4_noGPS2_B.roll *
    px4_noGPS2_B.roll_hat_k;

  // Saturate: '<S16>/Saturation12'
  if (px4_noGPS2_B.roll_hat_k > px4_noGPS2_P.Saturation12_UpperSat_c) {
    px4_noGPS2_B.roll = px4_noGPS2_P.Saturation12_UpperSat_c;
  } else if (px4_noGPS2_B.roll_hat_k < px4_noGPS2_P.Saturation12_LowerSat_b) {
    px4_noGPS2_B.roll = px4_noGPS2_P.Saturation12_LowerSat_b;
  } else {
    px4_noGPS2_B.roll = px4_noGPS2_B.roll_hat_k;
  }

  // End of Saturate: '<S16>/Saturation12'

  // Product: '<S16>/Product5' incorporates:
  //   Fcn: '<S16>/Fcn5'

  px4_noGPS2_B.e_gq *= rt_powd_snf(px4_noGPS2_B.roll_desire, 0.0625) *
    px4_noGPS2_B.roll;

  // Sum: '<S16>/Add18'
  px4_noGPS2_B.roll = px4_noGPS2_B.l2_j;

  // Sum: '<S16>/Add17'
  px4_noGPS2_B.roll_desire = px4_noGPS2_B.z1_i;

  // Saturate: '<S16>/Saturation16'
  if (px4_noGPS2_B.roll > px4_noGPS2_P.Saturation16_UpperSat_l) {
    px4_noGPS2_B.roll = px4_noGPS2_P.Saturation16_UpperSat_l;
  } else if (px4_noGPS2_B.roll < px4_noGPS2_P.Saturation16_LowerSat_g) {
    px4_noGPS2_B.roll = px4_noGPS2_P.Saturation16_LowerSat_g;
  }

  // End of Saturate: '<S16>/Saturation16'

  // Saturate: '<S16>/Saturation14'
  if (px4_noGPS2_B.roll_desire > px4_noGPS2_P.Saturation14_UpperSat_l) {
    px4_noGPS2_B.roll_desire = px4_noGPS2_P.Saturation14_UpperSat_l;
  } else if (px4_noGPS2_B.roll_desire < px4_noGPS2_P.Saturation14_LowerSat_b) {
    px4_noGPS2_B.roll_desire = px4_noGPS2_P.Saturation14_LowerSat_b;
  }

  // End of Saturate: '<S16>/Saturation14'

  // Gain: '<S16>/Gain3' incorporates:
  //   Sum: '<S16>/Add19'

  px4_noGPS2_B.roll = (px4_noGPS2_B.roll - px4_noGPS2_B.roll_desire) *
    px4_noGPS2_P.Gain3_Gain_l;

  // Sum: '<S16>/Add16' incorporates:
  //   Constant: '<S16>/Constant6'

  px4_noGPS2_B.z1_i = px4_noGPS2_P.Constant6_Value_o - px4_noGPS2_B.roll;

  // Saturate: '<S16>/Saturation1'
  if (px4_noGPS2_B.roll_hat_k > px4_noGPS2_P.Saturation1_UpperSat_a) {
    px4_noGPS2_B.roll_desire = px4_noGPS2_P.Saturation1_UpperSat_a;
  } else if (px4_noGPS2_B.roll_hat_k < px4_noGPS2_P.Saturation1_LowerSat_i) {
    px4_noGPS2_B.roll_desire = px4_noGPS2_P.Saturation1_LowerSat_i;
  } else {
    px4_noGPS2_B.roll_desire = px4_noGPS2_B.roll_hat_k;
  }

  // End of Saturate: '<S16>/Saturation1'

  // Gain: '<S16>/l2'
  px4_noGPS2_B.l2_j = px4_noGPS2_P.l2_Gain_l * px4_noGPS2_B.roll_desire;

  // Sum: '<S16>/Add3'
  px4_noGPS2_B.roll_desire = px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 -
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1;

  // Fcn: '<S16>/Fcn7' incorporates:
  //   Constant: '<S16>/Constant1'

  if (px4_noGPS2_P.Constant1_Value_j < 0.0) {
    rtb_Switch_idx_0 = -rt_powd_snf(-px4_noGPS2_P.Constant1_Value_j, -0.75);
  } else {
    rtb_Switch_idx_0 = rt_powd_snf(px4_noGPS2_P.Constant1_Value_j, -0.75);
  }

  // End of Fcn: '<S16>/Fcn7'

  // Product: '<S16>/Product7'
  px4_noGPS2_B.Product7_e = rtb_Switch_idx_0 * px4_noGPS2_B.roll *
    px4_noGPS2_B.roll_hat_k;

  // Saturate: '<S16>/Saturation15'
  if (px4_noGPS2_B.roll_hat_k > px4_noGPS2_P.Saturation15_UpperSat_j) {
    px4_noGPS2_B.roll = px4_noGPS2_P.Saturation15_UpperSat_j;
  } else if (px4_noGPS2_B.roll_hat_k < px4_noGPS2_P.Saturation15_LowerSat_k) {
    px4_noGPS2_B.roll = px4_noGPS2_P.Saturation15_LowerSat_k;
  } else {
    px4_noGPS2_B.roll = px4_noGPS2_B.roll_hat_k;
  }

  // End of Saturate: '<S16>/Saturation15'

  // Sum: '<S16>/Add2' incorporates:
  //   DiscreteIntegrator: '<S16>/Discrete-Time Integrator3'
  //   Fcn: '<S16>/Fcn8'
  //   Gain: '<S16>/Gain6'
  //   Gain: '<S16>/lambda2'
  //   Product: '<S16>/Product8'
  //   Sum: '<S16>/Add20'

  px4_noGPS2_B.l2_j = (((px4_noGPS2_P.lambda2_Gain_j * px4_noGPS2_B.roll_hat_k +
    px4_noGPS2_B.l2_j) + px4_noGPS2_B.roll_desire) +
                       px4_noGPS2_DW.DiscreteTimeIntegrator3_DSTAT_a) +
    (rt_powd_snf(px4_noGPS2_B.e_l, 0.25) * px4_noGPS2_B.roll * px4_noGPS2_B.z1_i
     + px4_noGPS2_B.Product7_e) * px4_noGPS2_P.Gain6_Gain_e;

  // Saturate: '<S16>/Saturation3'
  if (px4_noGPS2_B.roll_hat_k > px4_noGPS2_P.Saturation3_UpperSat_m) {
    px4_noGPS2_B.roll = px4_noGPS2_P.Saturation3_UpperSat_m;
  } else if (px4_noGPS2_B.roll_hat_k < px4_noGPS2_P.Saturation3_LowerSat_i) {
    px4_noGPS2_B.roll = px4_noGPS2_P.Saturation3_LowerSat_i;
  } else {
    px4_noGPS2_B.roll = px4_noGPS2_B.roll_hat_k;
  }

  // End of Saturate: '<S16>/Saturation3'

  // Gain: '<S16>/l4'
  px4_noGPS2_B.Product7_e = px4_noGPS2_P.l4_Gain_p * px4_noGPS2_B.roll;

  // Gain: '<S16>/lambda4'
  px4_noGPS2_B.lambda4_n = px4_noGPS2_P.lambda4_Gain_a * px4_noGPS2_B.roll_hat_k;

  // DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
  px4_noGPS2_B.roll_hat_k = px4_noGPS2_DW.DiscreteTimeIntegrator_DSTATE_f;

  // Gain: '<S17>/Gain2'
  px4_noGPS2_B.roll = px4_noGPS2_P.Gain2_Gain_p * px4_noGPS2_B.roll_hat_k;

  // ZeroOrderHold: '<S17>/Zero-Order Hold3' incorporates:
  //   DataStoreWrite: '<Root>/Data Store Write13'
  //   Gain: '<S17>/1//J'

  px4_noGPS2_B.roll = px4_noGPS2_P.uJ_Gain_g * px4_noGPS2_B.z2_l;

  // ZeroOrderHold: '<S17>/Zero-Order Hold2' incorporates:
  //   DataStoreRead: '<S17>/Data Store Read1'
  //   Gain: '<S17>/k//J'

  px4_noGPS2_B.roll_desire = px4_noGPS2_P.kJ_Gain_p * px4_noGPS2_DW.roll_speed;

  // ZeroOrderHold: '<S17>/Zero-Order Hold1' incorporates:
  //   DataStoreRead: '<S17>/Data Store Read'

  px4_noGPS2_B.e_l = px4_noGPS2_DW.roll;

  // Switch: '<S17>/Switch' incorporates:
  //   Constant: '<S17>/Constant3'
  //   DataStoreRead: '<S17>/Data Store Read2'

  if (px4_noGPS2_DW.observer_flag) {
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS2_B.roll;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_B.roll_desire;
  } else {
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS2_P.Constant3_Value_a;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_P.Constant3_Value_a;
    px4_noGPS2_B.e_l = px4_noGPS2_P.Constant3_Value_a;
  }

  // End of Switch: '<S17>/Switch'

  // Sum: '<S17>/Add1'
  px4_noGPS2_B.roll = px4_noGPS2_B.e_l - px4_noGPS2_B.roll_hat_k;

  // Abs: '<S17>/Abs3' incorporates:
  //   Abs: '<S17>/Abs4'
  //   Abs: '<S17>/Abs5'
  //   Abs: '<S17>/Abs6'

  px4_noGPS2_B.roll_desire = fabs(px4_noGPS2_B.roll);

  // Abs: '<S17>/Abs4'
  px4_noGPS2_B.e_l = px4_noGPS2_B.roll_desire;

  // Saturate: '<S17>/Saturation'
  if (px4_noGPS2_B.roll > px4_noGPS2_P.Saturation_UpperSat_n1) {
    px4_noGPS2_B.z1_i = px4_noGPS2_P.Saturation_UpperSat_n1;
  } else if (px4_noGPS2_B.roll < px4_noGPS2_P.Saturation_LowerSat_c) {
    px4_noGPS2_B.z1_i = px4_noGPS2_P.Saturation_LowerSat_c;
  } else {
    px4_noGPS2_B.z1_i = px4_noGPS2_B.roll;
  }

  // End of Saturate: '<S17>/Saturation'

  // Gain: '<S17>/l1'
  px4_noGPS2_B.roll_hat_k = px4_noGPS2_P.l1_Gain_d * px4_noGPS2_B.z1_i;

  // Gain: '<S17>/lambda1'
  px4_noGPS2_B.lambda1_e = px4_noGPS2_P.lambda1_Gain_g * px4_noGPS2_B.roll;

  // DiscreteIntegrator: '<S17>/Discrete-Time Integrator1'
  px4_noGPS2_B.z1_i = px4_noGPS2_DW.DiscreteTimeIntegrator1_DSTAT_g;

  // Sum: '<S17>/Add7' incorporates:
  //   Constant: '<S17>/Constant1'
  //   Sum: '<S17>/Add13'
  //   Sum: '<S17>/Add18'

  px4_noGPS2_B.l2_h = px4_noGPS2_P.Constant1_Value_ac + px4_noGPS2_B.roll;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   Sum: '<S17>/Add7'

  px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_B.l2_h;

  // Sum: '<S17>/Add6' incorporates:
  //   Constant: '<S17>/Constant1'
  //   Sum: '<S17>/Add12'
  //   Sum: '<S17>/Add17'

  px4_noGPS2_B.lambda4_h = px4_noGPS2_B.roll - px4_noGPS2_P.Constant1_Value_ac;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Sum: '<S17>/Add6'

  px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_B.lambda4_h;

  // Saturate: '<S17>/Saturation10'
  if (px4_noGPS2_B.rtb_DataStoreRead49_c > px4_noGPS2_P.Saturation10_UpperSat_a)
  {
    px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_P.Saturation10_UpperSat_a;
  } else if (px4_noGPS2_B.rtb_DataStoreRead49_c <
             px4_noGPS2_P.Saturation10_LowerSat_l) {
    px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_P.Saturation10_LowerSat_l;
  }

  // End of Saturate: '<S17>/Saturation10'

  // Saturate: '<S17>/Saturation11'
  if (px4_noGPS2_B.rtb_DataStoreRead48_p > px4_noGPS2_P.Saturation11_UpperSat_a)
  {
    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_P.Saturation11_UpperSat_a;
  } else if (px4_noGPS2_B.rtb_DataStoreRead48_p <
             px4_noGPS2_P.Saturation11_LowerSat_a) {
    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_P.Saturation11_LowerSat_a;
  }

  // End of Saturate: '<S17>/Saturation11'

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Gain: '<S17>/Gain'
  //   Sum: '<S17>/Add8'

  px4_noGPS2_B.rtb_DataStoreRead48_p = (px4_noGPS2_B.rtb_DataStoreRead49_c -
    px4_noGPS2_B.rtb_DataStoreRead48_p) * px4_noGPS2_P.Gain_Gain_h;

  // Fcn: '<S17>/Fcn3' incorporates:
  //   Constant: '<S17>/Constant1'

  if (px4_noGPS2_P.Constant1_Value_ac < 0.0) {
    rtb_Switch_idx_0 = -rt_powd_snf(-px4_noGPS2_P.Constant1_Value_ac, -0.5);
  } else {
    rtb_Switch_idx_0 = rt_powd_snf(px4_noGPS2_P.Constant1_Value_ac, -0.5);
  }

  // End of Fcn: '<S17>/Fcn3'

  // Product: '<S17>/Product3'
  px4_noGPS2_B.Product3_c = rtb_Switch_idx_0 *
    px4_noGPS2_B.rtb_DataStoreRead48_p * px4_noGPS2_B.roll;

  // Saturate: '<S17>/Saturation8'
  if (px4_noGPS2_B.roll > px4_noGPS2_P.Saturation8_UpperSat_c) {
    // DataStoreRead: '<Root>/Data Store Read49'
    px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_P.Saturation8_UpperSat_c;
  } else if (px4_noGPS2_B.roll < px4_noGPS2_P.Saturation8_LowerSat_c) {
    // DataStoreRead: '<Root>/Data Store Read49'
    px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_P.Saturation8_LowerSat_c;
  } else {
    // DataStoreRead: '<Root>/Data Store Read49'
    px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_B.roll;
  }

  // End of Saturate: '<S17>/Saturation8'

  // Product: '<S17>/Product4' incorporates:
  //   Constant: '<S17>/Constant2'
  //   Fcn: '<S17>/Fcn4'
  //   Sum: '<S17>/Add10'

  px4_noGPS2_B.Product4_g = rt_powd_snf(px4_noGPS2_B.roll_desire, 0.5) *
    px4_noGPS2_B.rtb_DataStoreRead49_c * (px4_noGPS2_P.Constant2_Value_k -
    px4_noGPS2_B.rtb_DataStoreRead48_p);

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Sum: '<S17>/Add13'

  px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_B.l2_h;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   Sum: '<S17>/Add12'

  px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_B.lambda4_h;

  // Saturate: '<S17>/Saturation13'
  if (px4_noGPS2_B.rtb_DataStoreRead48_p > px4_noGPS2_P.Saturation13_UpperSat_p)
  {
    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_P.Saturation13_UpperSat_p;
  } else if (px4_noGPS2_B.rtb_DataStoreRead48_p <
             px4_noGPS2_P.Saturation13_LowerSat_j) {
    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_P.Saturation13_LowerSat_j;
  }

  // End of Saturate: '<S17>/Saturation13'

  // Saturate: '<S17>/Saturation9'
  if (px4_noGPS2_B.rtb_DataStoreRead49_c > px4_noGPS2_P.Saturation9_UpperSat_d)
  {
    px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_P.Saturation9_UpperSat_d;
  } else if (px4_noGPS2_B.rtb_DataStoreRead49_c <
             px4_noGPS2_P.Saturation9_LowerSat_c4) {
    px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_P.Saturation9_LowerSat_c4;
  }

  // End of Saturate: '<S17>/Saturation9'

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Gain: '<S17>/Gain1'
  //   Sum: '<S17>/Add14'

  px4_noGPS2_B.rtb_DataStoreRead48_p = (px4_noGPS2_B.rtb_DataStoreRead48_p -
    px4_noGPS2_B.rtb_DataStoreRead49_c) * px4_noGPS2_P.Gain1_Gain_e;

  // Sum: '<S17>/Add11' incorporates:
  //   Constant: '<S17>/Constant4'

  px4_noGPS2_B.e_e1 = px4_noGPS2_P.Constant4_Value_l -
    px4_noGPS2_B.rtb_DataStoreRead48_p;

  // Fcn: '<S17>/Fcn6' incorporates:
  //   Constant: '<S17>/Constant1'

  if (px4_noGPS2_P.Constant1_Value_ac < 0.0) {
    rtb_Switch_idx_0 = -rt_powd_snf(-px4_noGPS2_P.Constant1_Value_ac, -0.9375);
  } else {
    rtb_Switch_idx_0 = rt_powd_snf(px4_noGPS2_P.Constant1_Value_ac, -0.9375);
  }

  // End of Fcn: '<S17>/Fcn6'

  // Product: '<S17>/Product6'
  px4_noGPS2_B.Product6_a = rtb_Switch_idx_0 *
    px4_noGPS2_B.rtb_DataStoreRead48_p * px4_noGPS2_B.roll;

  // Saturate: '<S17>/Saturation12'
  if (px4_noGPS2_B.roll > px4_noGPS2_P.Saturation12_UpperSat_d) {
    // DataStoreRead: '<Root>/Data Store Read48'
    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_P.Saturation12_UpperSat_d;
  } else if (px4_noGPS2_B.roll < px4_noGPS2_P.Saturation12_LowerSat_j) {
    // DataStoreRead: '<Root>/Data Store Read48'
    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_P.Saturation12_LowerSat_j;
  } else {
    // DataStoreRead: '<Root>/Data Store Read48'
    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_B.roll;
  }

  // End of Saturate: '<S17>/Saturation12'

  // Product: '<S17>/Product5' incorporates:
  //   Fcn: '<S17>/Fcn5'

  px4_noGPS2_B.e_e1 *= rt_powd_snf(px4_noGPS2_B.e_l, 0.0625) *
    px4_noGPS2_B.rtb_DataStoreRead48_p;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Sum: '<S17>/Add18'

  px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_B.l2_h;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   Sum: '<S17>/Add17'

  px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_B.lambda4_h;

  // Saturate: '<S17>/Saturation16'
  if (px4_noGPS2_B.rtb_DataStoreRead48_p > px4_noGPS2_P.Saturation16_UpperSat_p)
  {
    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_P.Saturation16_UpperSat_p;
  } else if (px4_noGPS2_B.rtb_DataStoreRead48_p <
             px4_noGPS2_P.Saturation16_LowerSat_i) {
    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_P.Saturation16_LowerSat_i;
  }

  // End of Saturate: '<S17>/Saturation16'

  // Saturate: '<S17>/Saturation14'
  if (px4_noGPS2_B.rtb_DataStoreRead49_c > px4_noGPS2_P.Saturation14_UpperSat_n)
  {
    px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_P.Saturation14_UpperSat_n;
  } else if (px4_noGPS2_B.rtb_DataStoreRead49_c <
             px4_noGPS2_P.Saturation14_LowerSat_a) {
    px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_P.Saturation14_LowerSat_a;
  }

  // End of Saturate: '<S17>/Saturation14'

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Gain: '<S17>/Gain3'
  //   Sum: '<S17>/Add19'

  px4_noGPS2_B.rtb_DataStoreRead48_p = (px4_noGPS2_B.rtb_DataStoreRead48_p -
    px4_noGPS2_B.rtb_DataStoreRead49_c) * px4_noGPS2_P.Gain3_Gain_p;

  // Sum: '<S17>/Add16' incorporates:
  //   Constant: '<S17>/Constant6'

  px4_noGPS2_B.e_l = px4_noGPS2_P.Constant6_Value_g -
    px4_noGPS2_B.rtb_DataStoreRead48_p;

  // Saturate: '<S17>/Saturation1'
  if (px4_noGPS2_B.roll > px4_noGPS2_P.Saturation1_UpperSat_d) {
    // DataStoreRead: '<Root>/Data Store Read49'
    px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_P.Saturation1_UpperSat_d;
  } else if (px4_noGPS2_B.roll < px4_noGPS2_P.Saturation1_LowerSat_g) {
    // DataStoreRead: '<Root>/Data Store Read49'
    px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_P.Saturation1_LowerSat_g;
  } else {
    // DataStoreRead: '<Root>/Data Store Read49'
    px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_B.roll;
  }

  // End of Saturate: '<S17>/Saturation1'

  // Gain: '<S17>/l2'
  px4_noGPS2_B.l2_h = px4_noGPS2_P.l2_Gain_i *
    px4_noGPS2_B.rtb_DataStoreRead49_c;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   Sum: '<S17>/Add3'

  px4_noGPS2_B.rtb_DataStoreRead49_c =
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 -
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1;

  // Fcn: '<S17>/Fcn7' incorporates:
  //   Constant: '<S17>/Constant1'

  if (px4_noGPS2_P.Constant1_Value_ac < 0.0) {
    rtb_Switch_idx_0 = -rt_powd_snf(-px4_noGPS2_P.Constant1_Value_ac, -0.75);
  } else {
    rtb_Switch_idx_0 = rt_powd_snf(px4_noGPS2_P.Constant1_Value_ac, -0.75);
  }

  // End of Fcn: '<S17>/Fcn7'

  // Product: '<S17>/Product7'
  px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = rtb_Switch_idx_0 *
    px4_noGPS2_B.rtb_DataStoreRead48_p * px4_noGPS2_B.roll;

  // Saturate: '<S17>/Saturation15'
  if (px4_noGPS2_B.roll > px4_noGPS2_P.Saturation15_UpperSat_k) {
    // DataStoreRead: '<Root>/Data Store Read48'
    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_P.Saturation15_UpperSat_k;
  } else if (px4_noGPS2_B.roll < px4_noGPS2_P.Saturation15_LowerSat_h) {
    // DataStoreRead: '<Root>/Data Store Read48'
    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_P.Saturation15_LowerSat_h;
  } else {
    // DataStoreRead: '<Root>/Data Store Read48'
    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_B.roll;
  }

  // End of Saturate: '<S17>/Saturation15'

  // Sum: '<S17>/Add2' incorporates:
  //   DiscreteIntegrator: '<S17>/Discrete-Time Integrator3'
  //   Fcn: '<S17>/Fcn8'
  //   Gain: '<S17>/Gain6'
  //   Gain: '<S17>/lambda2'
  //   Product: '<S17>/Product8'
  //   Sum: '<S17>/Add20'

  px4_noGPS2_B.rtb_DataTypeConversion3_idx_0 = (((px4_noGPS2_P.lambda2_Gain_d *
    px4_noGPS2_B.roll + px4_noGPS2_B.l2_h) + px4_noGPS2_B.rtb_DataStoreRead49_c)
    + px4_noGPS2_DW.DiscreteTimeIntegrator3_DSTAT_m) + (rt_powd_snf
    (px4_noGPS2_B.roll_desire, 0.25) * px4_noGPS2_B.rtb_DataStoreRead48_p *
    px4_noGPS2_B.e_l + px4_noGPS2_B.rtb_DataTypeConversion3_idx_1) *
    px4_noGPS2_P.Gain6_Gain_f;

  // Saturate: '<S17>/Saturation3'
  if (px4_noGPS2_B.roll > px4_noGPS2_P.Saturation3_UpperSat_i) {
    // DataStoreRead: '<Root>/Data Store Read48'
    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_P.Saturation3_UpperSat_i;
  } else if (px4_noGPS2_B.roll < px4_noGPS2_P.Saturation3_LowerSat_g) {
    // DataStoreRead: '<Root>/Data Store Read48'
    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_P.Saturation3_LowerSat_g;
  } else {
    // DataStoreRead: '<Root>/Data Store Read48'
    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_B.roll;
  }

  // End of Saturate: '<S17>/Saturation3'

  // Gain: '<S17>/l4'
  px4_noGPS2_B.l2_h = px4_noGPS2_P.l4_Gain_o *
    px4_noGPS2_B.rtb_DataStoreRead48_p;

  // Gain: '<S17>/lambda4'
  px4_noGPS2_B.lambda4_h = px4_noGPS2_P.lambda4_Gain_b * px4_noGPS2_B.roll;

  // MATLABSystem: '<S6>/SourceBlock'
  rtb_LogicalOperator = uORB_read_step(px4_noGPS2_DW.obj_n.orbMetadataObj,
    &px4_noGPS2_DW.obj_n.eventStructObj, &px4_noGPS2_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S47>/Enable'

  if (rtb_LogicalOperator) {
    // SignalConversion generated from: '<S47>/In1'
    px4_noGPS2_B.In1 = px4_noGPS2_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   Product: '<S61>/Product'

  px4_noGPS2_B.rtb_DataStoreRead48_p = static_cast<real_T>(px4_noGPS2_B.In1.q[0])
    * px4_noGPS2_B.In1.q[0];

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   Product: '<S61>/Product1'

  px4_noGPS2_B.rtb_DataStoreRead49_c = static_cast<real_T>(px4_noGPS2_B.In1.q[1])
    * px4_noGPS2_B.In1.q[1];

  // Product: '<S61>/Product2' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4_noGPS2_B.roll = static_cast<real_T>(px4_noGPS2_B.In1.q[2]) *
    px4_noGPS2_B.In1.q[2];

  // Product: '<S61>/Product3' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4_noGPS2_B.roll_desire = static_cast<real_T>(px4_noGPS2_B.In1.q[3]) *
    px4_noGPS2_B.In1.q[3];

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Sqrt: '<S60>/sqrt'
  //   Sum: '<S61>/Sum'

  px4_noGPS2_B.rtb_DataStoreRead48_p = sqrt(((px4_noGPS2_B.rtb_DataStoreRead48_p
    + px4_noGPS2_B.rtb_DataStoreRead49_c) + px4_noGPS2_B.roll) +
    px4_noGPS2_B.roll_desire);

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   Product: '<S55>/Product'

  px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_B.In1.q[0] /
    px4_noGPS2_B.rtb_DataStoreRead48_p;

  // Product: '<S55>/Product1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4_noGPS2_B.roll = px4_noGPS2_B.In1.q[1] / px4_noGPS2_B.rtb_DataStoreRead48_p;

  // Product: '<S55>/Product2' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4_noGPS2_B.roll_desire = px4_noGPS2_B.In1.q[2] /
    px4_noGPS2_B.rtb_DataStoreRead48_p;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   Product: '<S55>/Product3'

  px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_B.In1.q[3] /
    px4_noGPS2_B.rtb_DataStoreRead48_p;

  // Fcn: '<S8>/fcn1'
  px4_noGPS2_B.e_l = (px4_noGPS2_B.roll * px4_noGPS2_B.roll_desire +
                      px4_noGPS2_B.rtb_DataStoreRead49_c *
                      px4_noGPS2_B.rtb_DataStoreRead48_p) * 2.0;

  // Fcn: '<S8>/fcn2' incorporates:
  //   Fcn: '<S8>/fcn5'

  rtb_Switch_idx_0 = px4_noGPS2_B.rtb_DataStoreRead49_c *
    px4_noGPS2_B.rtb_DataStoreRead49_c;
  px4_noGPS2_B.TSamp_k = px4_noGPS2_B.roll * px4_noGPS2_B.roll;
  px4_noGPS2_B.TSamp_f = px4_noGPS2_B.roll_desire * px4_noGPS2_B.roll_desire;
  px4_noGPS2_B.TSamp_e = px4_noGPS2_B.rtb_DataStoreRead48_p *
    px4_noGPS2_B.rtb_DataStoreRead48_p;

  // DataStoreWrite: '<Root>/Data Store Write10' incorporates:
  //   Fcn: '<S8>/fcn2'
  //   Trigonometry: '<S54>/Trigonometric Function1'

  px4_noGPS2_DW.yaw = rt_atan2d_snf(px4_noGPS2_B.e_l, ((rtb_Switch_idx_0 +
    px4_noGPS2_B.TSamp_k) - px4_noGPS2_B.TSamp_f) - px4_noGPS2_B.TSamp_e);

  // Fcn: '<S8>/fcn3'
  px4_noGPS2_B.e_l = (px4_noGPS2_B.roll * px4_noGPS2_B.rtb_DataStoreRead48_p -
                      px4_noGPS2_B.rtb_DataStoreRead49_c *
                      px4_noGPS2_B.roll_desire) * -2.0;

  // If: '<S56>/If' incorporates:
  //   Constant: '<S57>/Constant'
  //   Constant: '<S58>/Constant'

  if (px4_noGPS2_B.e_l > 1.0) {
    // Outputs for IfAction SubSystem: '<S56>/If Action Subsystem' incorporates:
    //   ActionPort: '<S57>/Action Port'

    px4_noGPS2_B.e_l = px4_noGPS2_P.Constant_Value_e;

    // End of Outputs for SubSystem: '<S56>/If Action Subsystem'
  } else if (px4_noGPS2_B.e_l < -1.0) {
    // Outputs for IfAction SubSystem: '<S56>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S58>/Action Port'

    px4_noGPS2_B.e_l = px4_noGPS2_P.Constant_Value_b1;

    // End of Outputs for SubSystem: '<S56>/If Action Subsystem1'
  }

  // End of If: '<S56>/If'

  // Trigonometry: '<S54>/trigFcn'
  if (px4_noGPS2_B.e_l > 1.0) {
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = 1.0;
  } else if (px4_noGPS2_B.e_l < -1.0) {
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = -1.0;
  } else {
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_B.e_l;
  }

  // Fcn: '<S8>/fcn4'
  px4_noGPS2_B.e_l = (px4_noGPS2_B.roll_desire *
                      px4_noGPS2_B.rtb_DataStoreRead48_p +
                      px4_noGPS2_B.rtb_DataStoreRead49_c * px4_noGPS2_B.roll) *
    2.0;

  // DataStoreWrite: '<Root>/Data Store Write' incorporates:
  //   Fcn: '<S8>/fcn5'
  //   Trigonometry: '<S54>/Trigonometric Function3'

  px4_noGPS2_DW.roll = rt_atan2d_snf(px4_noGPS2_B.e_l, ((rtb_Switch_idx_0 -
    px4_noGPS2_B.TSamp_k) - px4_noGPS2_B.TSamp_f) + px4_noGPS2_B.TSamp_e);

  // DataStoreWrite: '<Root>/Data Store Write1' incorporates:
  //   Trigonometry: '<S54>/trigFcn'

  px4_noGPS2_DW.pitch = asin(px4_noGPS2_B.rtb_DataTypeConversion3_idx_1);

  // DataStoreWrite: '<Root>/Data Store Write20' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px4_noGPS2_DW.yaw_speed = px4_noGPS2_B.In1.yawspeed;

  // DataStoreWrite: '<Root>/Data Store Write21' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px4_noGPS2_DW.pitch_speed = px4_noGPS2_B.In1.pitchspeed;

  // DataStoreWrite: '<Root>/Data Store Write22' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px4_noGPS2_DW.roll_speed = px4_noGPS2_B.In1.rollspeed;

  // MATLAB Function: '<Root>/MATLAB Function3' incorporates:
  //   Constant: '<Root>/Constant6'
  //   DataStoreRead: '<Root>/Data Store Read45'
  //   DataStoreRead: '<Root>/Data Store Read52'
  //   DataStoreRead: '<Root>/Data Store Read56'
  //   DataStoreRead: '<Root>/Data Store Read71'

  px4_noGPS2_B.e_l = cos(px4_noGPS2_P.Constant6_Value_p);
  px4_noGPS2_B.roll_desire = sin(px4_noGPS2_P.Constant6_Value_p);
  px4_noGPS2_DW.roll_desire = asin((px4_noGPS2_DW.q_x * px4_noGPS2_B.roll_desire
    - px4_noGPS2_DW.q_y * px4_noGPS2_B.e_l) / px4_noGPS2_DW.U1);
  px4_noGPS2_DW.pitch_desire = atan((px4_noGPS2_DW.q_x * px4_noGPS2_B.e_l +
    px4_noGPS2_DW.q_y * px4_noGPS2_B.roll_desire) / (px4_noGPS2_DW.q_z + 9.8));
  if (px4_noGPS2_DW.roll_desire > 0.17453292519943295) {
    px4_noGPS2_DW.roll_desire = 0.17453292519943295;
  } else if (px4_noGPS2_DW.roll_desire < -0.17453292519943295) {
    px4_noGPS2_DW.roll_desire = -0.17453292519943295;
  }

  if (px4_noGPS2_DW.pitch_desire > 0.17453292519943295) {
    px4_noGPS2_DW.pitch_desire = 0.17453292519943295;
  } else if (px4_noGPS2_DW.pitch_desire < -0.17453292519943295) {
    px4_noGPS2_DW.pitch_desire = -0.17453292519943295;
  }

  // End of MATLAB Function: '<Root>/MATLAB Function3'

  // Switch: '<Root>/Switch' incorporates:
  //   Constant: '<Root>/Constant7'
  //   Constant: '<Root>/Constant8'
  //   Constant: '<S48>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read57'
  //   Switch: '<S48>/Switch'

  if (px4_noGPS2_DW.position_flag) {
    rtb_Switch_idx_0 = px4_noGPS2_P.Constant7_Value;

    // DataStoreRead: '<Root>/Data Store Read48' incorporates:
    //   Constant: '<Root>/Constant7'
    //   DiscreteIntegrator: '<Root>/Intgrt_dY'

    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_DW.Intgrt_dY_DSTATE;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_P.Constant7_Value;

    // ZeroOrderHold: '<S48>/Zero-Order Hold5' incorporates:
    //   Constant: '<Root>/Constant7'
    //   DiscreteIntegrator: '<Root>/Intgrt_ddY'

    px4_noGPS2_B.roll = px4_noGPS2_DW.Intgrt_ddY_DSTATE;
  } else {
    rtb_Switch_idx_0 = px4_noGPS2_P.Constant8_Value;

    // DataStoreRead: '<Root>/Data Store Read48' incorporates:
    //   Constant: '<Root>/Constant8'
    //   Constant: '<S48>/Constant1'

    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_P.Constant1_Value_g;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_P.Constant1_Value_g;

    // ZeroOrderHold: '<S48>/Zero-Order Hold5' incorporates:
    //   Constant: '<S48>/Constant1'

    px4_noGPS2_B.roll = px4_noGPS2_P.Constant1_Value_g;
  }

  // End of Switch: '<Root>/Switch'

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   ZeroOrderHold: '<S48>/Zero-Order Hold2'

  px4_noGPS2_B.rtb_DataStoreRead49_c =
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Sum: '<S48>/Subtract'

  px4_noGPS2_B.rtb_DataStoreRead48_p -= px4_noGPS2_B.rtb_DataStoreRead49_c;

  // SampleTimeMath: '<S50>/TSamp'
  //
  //  About '<S50>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS2_B.TSamp_k = px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 *
    px4_noGPS2_P.TSamp_WtEt_d;

  // Sum: '<S50>/Diff' incorporates:
  //   UnitDelay: '<S50>/UD'
  //
  //  Block description for '<S50>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S50>/UD':
  //
  //   Store in Global RAM

  px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_B.TSamp_k -
    px4_noGPS2_DW.UD_DSTATE_n2;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   Sum: '<S48>/Subtract1'
  //   ZeroOrderHold: '<S48>/Zero-Order Hold6'

  px4_noGPS2_B.rtb_DataStoreRead49_c =
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1;
  px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_B.roll -
    px4_noGPS2_B.rtb_DataStoreRead49_c;

  // Sum: '<S48>/Subtract3' incorporates:
  //   Gain: '<S48>/K1'

  px4_noGPS2_B.roll_desire = px4_noGPS2_P.K1_Gain *
    px4_noGPS2_B.rtb_DataStoreRead48_p + px4_noGPS2_B.rtb_DataStoreRead49_c;

  // Switch: '<S48>/Switch1' incorporates:
  //   Constant: '<S48>/Constant'
  //   Constant: '<S48>/Constant2'
  //   Gain: '<S48>/C4'
  //   Sum: '<S48>/Subtract4'

  if (px4_noGPS2_P.C4_Gain * px4_noGPS2_B.rtb_DataStoreRead48_p +
      px4_noGPS2_B.rtb_DataStoreRead49_c > px4_noGPS2_P.Switch1_Threshold) {
    px4_noGPS2_B.e_l = px4_noGPS2_P.Constant_Value_h;
  } else {
    px4_noGPS2_B.e_l = px4_noGPS2_P.Constant2_Value;
  }

  // End of Switch: '<S48>/Switch1'

  // SampleTimeMath: '<S51>/TSamp'
  //
  //  About '<S51>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS2_B.TSamp_f = px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 *
    px4_noGPS2_P.TSamp_WtEt_dd;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Sum: '<S51>/Diff'
  //   UnitDelay: '<S51>/UD'
  //   ZeroOrderHold: '<S48>/Zero-Order Hold3'
  //
  //  Block description for '<S51>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S51>/UD':
  //
  //   Store in Global RAM

  px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_B.TSamp_f -
    px4_noGPS2_DW.UD_DSTATE_f;

  // Gain: '<S7>/Gain2' incorporates:
  //   Constant: '<S48>/Constant3'
  //   Gain: '<S48>/C1'
  //   Gain: '<S48>/C3'
  //   Gain: '<S48>/Gain'
  //   Gain: '<S48>/k3'
  //   Product: '<S48>/Divide'
  //   Sum: '<S48>/Subtract2'
  //   Sum: '<S48>/Subtract5'
  //   Sum: '<S48>/Subtract6'

  px4_noGPS2_DW.q_y = (((px4_noGPS2_P.C1_Gain * px4_noGPS2_B.roll_desire +
    px4_noGPS2_P.C3_Gain * px4_noGPS2_B.rtb_DataStoreRead49_c) +
                        px4_noGPS2_P.Gain_Gain_f * px4_noGPS2_B.e_l) +
                       (px4_noGPS2_P.k3_Gain * px4_noGPS2_B.roll /
                        px4_noGPS2_P.Constant3_Value_e +
                        px4_noGPS2_B.rtb_DataStoreRead48_p)) *
    px4_noGPS2_P.Gain2_Gain_d;

  // Saturate: '<S7>/Saturation1'
  if (px4_noGPS2_DW.q_y > px4_noGPS2_P.Saturation1_UpperSat_h) {
    // Gain: '<S7>/Gain2'
    px4_noGPS2_DW.q_y = px4_noGPS2_P.Saturation1_UpperSat_h;
  } else if (px4_noGPS2_DW.q_y < px4_noGPS2_P.Saturation1_LowerSat_o) {
    // Gain: '<S7>/Gain2'
    px4_noGPS2_DW.q_y = px4_noGPS2_P.Saturation1_LowerSat_o;
  }

  // End of Saturate: '<S7>/Saturation1'

  // DataStoreWrite: '<Root>/Data Store Write18' incorporates:
  //   Constant: '<S7>/Constant'

  px4_noGPS2_DW.q_z = px4_noGPS2_P.Constant_Value_i;

  // Switch: '<S49>/Switch' incorporates:
  //   Constant: '<S49>/Constant1'
  //   DataStoreRead: '<S49>/Data Store Read'

  if (px4_noGPS2_DW.position_flag) {
    // DataStoreRead: '<Root>/Data Store Read48' incorporates:
    //   DiscreteIntegrator: '<Root>/Intgrt_dX'

    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_DW.Intgrt_dX_DSTATE;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = rtb_Switch_idx_0;

    // ZeroOrderHold: '<S49>/Zero-Order Hold5' incorporates:
    //   DiscreteIntegrator: '<Root>/Intgrt_ddX'

    px4_noGPS2_B.roll = px4_noGPS2_DW.Intgrt_ddX_DSTATE;
  } else {
    // DataStoreRead: '<Root>/Data Store Read48' incorporates:
    //   Constant: '<S49>/Constant1'

    px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_P.Constant1_Value_nr;
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS2_P.Constant1_Value_nr;

    // ZeroOrderHold: '<S49>/Zero-Order Hold5' incorporates:
    //   Constant: '<S49>/Constant1'

    px4_noGPS2_B.roll = px4_noGPS2_P.Constant1_Value_nr;
  }

  // End of Switch: '<S49>/Switch'

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   ZeroOrderHold: '<S49>/Zero-Order Hold2'

  px4_noGPS2_B.rtb_DataStoreRead49_c =
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_1;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Sum: '<S49>/Subtract'

  px4_noGPS2_B.rtb_DataStoreRead48_p -= px4_noGPS2_B.rtb_DataStoreRead49_c;

  // SampleTimeMath: '<S52>/TSamp'
  //
  //  About '<S52>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 *= px4_noGPS2_P.TSamp_WtEt_e;

  // Sum: '<S52>/Diff' incorporates:
  //   UnitDelay: '<S52>/UD'
  //
  //  Block description for '<S52>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S52>/UD':
  //
  //   Store in Global RAM

  rtb_Switch_idx_0 = px4_noGPS2_B.rtb_DataTypeConversion3_idx_1 -
    px4_noGPS2_DW.UD_DSTATE_m;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   Sum: '<S49>/Subtract1'
  //   ZeroOrderHold: '<S49>/Zero-Order Hold6'

  px4_noGPS2_B.rtb_DataStoreRead49_c = rtb_Switch_idx_0;
  px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_B.roll -
    px4_noGPS2_B.rtb_DataStoreRead49_c;

  // Sum: '<S49>/Subtract3' incorporates:
  //   Gain: '<S49>/k2'

  px4_noGPS2_B.roll_desire = px4_noGPS2_P.k2_Gain *
    px4_noGPS2_B.rtb_DataStoreRead48_p + px4_noGPS2_B.rtb_DataStoreRead49_c;

  // Switch: '<S49>/Switch1' incorporates:
  //   Constant: '<S49>/Constant'
  //   Constant: '<S49>/Constant2'
  //   Gain: '<S49>/C2'
  //   Sum: '<S49>/Subtract4'

  if (px4_noGPS2_P.C2_Gain * px4_noGPS2_B.rtb_DataStoreRead48_p +
      px4_noGPS2_B.rtb_DataStoreRead49_c > px4_noGPS2_P.Switch1_Threshold_d) {
    px4_noGPS2_B.e_l = px4_noGPS2_P.Constant_Value_d;
  } else {
    px4_noGPS2_B.e_l = px4_noGPS2_P.Constant2_Value_i;
  }

  // End of Switch: '<S49>/Switch1'

  // SampleTimeMath: '<S53>/TSamp'
  //
  //  About '<S53>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS2_B.TSamp_e = rtb_Switch_idx_0 * px4_noGPS2_P.TSamp_WtEt_l;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Sum: '<S53>/Diff'
  //   UnitDelay: '<S53>/UD'
  //   ZeroOrderHold: '<S49>/Zero-Order Hold3'
  //
  //  Block description for '<S53>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S53>/UD':
  //
  //   Store in Global RAM

  px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_B.TSamp_e -
    px4_noGPS2_DW.UD_DSTATE_fi;

  // Gain: '<S7>/Gain4' incorporates:
  //   Constant: '<S49>/Constant3'
  //   Gain: '<S49>/C1'
  //   Gain: '<S49>/Gain'
  //   Gain: '<S49>/k1'
  //   Gain: '<S49>/k3'
  //   Product: '<S49>/Divide'
  //   Sum: '<S49>/Subtract2'
  //   Sum: '<S49>/Subtract5'
  //   Sum: '<S49>/Subtract6'

  px4_noGPS2_DW.q_x = (((px4_noGPS2_P.C1_Gain_b * px4_noGPS2_B.roll_desire +
    px4_noGPS2_P.k1_Gain * px4_noGPS2_B.rtb_DataStoreRead49_c) +
                        px4_noGPS2_P.Gain_Gain_c * px4_noGPS2_B.e_l) +
                       (px4_noGPS2_P.k3_Gain_m * px4_noGPS2_B.roll /
                        px4_noGPS2_P.Constant3_Value_b +
                        px4_noGPS2_B.rtb_DataStoreRead48_p)) *
    px4_noGPS2_P.Gain4_Gain_ff;

  // Saturate: '<S7>/Saturation2'
  if (px4_noGPS2_DW.q_x > px4_noGPS2_P.Saturation2_UpperSat_c) {
    // Gain: '<S7>/Gain4'
    px4_noGPS2_DW.q_x = px4_noGPS2_P.Saturation2_UpperSat_c;
  } else if (px4_noGPS2_DW.q_x < px4_noGPS2_P.Saturation2_LowerSat_f) {
    // Gain: '<S7>/Gain4'
    px4_noGPS2_DW.q_x = px4_noGPS2_P.Saturation2_LowerSat_f;
  }

  // End of Saturate: '<S7>/Saturation2'

  // MATLAB Function: '<Root>/MATLAB Function1' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read'
  //   DataStoreRead: '<Root>/Data Store Read7'
  //   DataStoreRead: '<Root>/Data Store Read75'

  px4_noGPS2_DW.U1 = sqrt((px4_noGPS2_DW.q_x * px4_noGPS2_DW.q_x +
    px4_noGPS2_DW.q_y * px4_noGPS2_DW.q_y) + (px4_noGPS2_DW.q_z + 9.8) *
    (px4_noGPS2_DW.q_z + 9.8));

  // Saturate: '<Root>/Saturation2'
  if (px4_noGPS2_DW.U1 > px4_noGPS2_P.Saturation2_UpperSat_o) {
    // MATLAB Function: '<Root>/MATLAB Function1'
    px4_noGPS2_DW.U1 = px4_noGPS2_P.Saturation2_UpperSat_o;
  } else if (px4_noGPS2_DW.U1 < px4_noGPS2_P.Saturation2_LowerSat_b) {
    // MATLAB Function: '<Root>/MATLAB Function1'
    px4_noGPS2_DW.U1 = px4_noGPS2_P.Saturation2_LowerSat_b;
  }

  // End of Saturate: '<Root>/Saturation2'

  // DataStoreWrite: '<S10>/Data Store Write28' incorporates:
  //   Constant: '<S10>/attitude_flag'

  px4_noGPS2_DW.attitude_flag = px4_noGPS2_P.attitude_flag_Value;

  // DataStoreWrite: '<S11>/Data Store Write28' incorporates:
  //   Constant: '<S11>/observer_flag'

  px4_noGPS2_DW.observer_flag = px4_noGPS2_P.observer_flag_Value;

  // DataStoreWrite: '<S12>/Data Store Write28' incorporates:
  //   Constant: '<S12>/position_flag'

  px4_noGPS2_DW.position_flag = px4_noGPS2_P.position_flag_Value;
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

    rtb_Switch_idx_0 = floor((((px4_noGPS2_P.Mixermatrix1_Value[i + 4] *
      px4_noGPS2_B.z2_e + px4_noGPS2_P.Mixermatrix1_Value[i] * px4_noGPS2_DW.U1)
      + px4_noGPS2_P.Mixermatrix1_Value[i + 8] * px4_noGPS2_B.z2_l) +
      px4_noGPS2_P.Mixermatrix1_Value[i + 12] * px4_noGPS2_B.yaw_thrust) *
      px4_noGPS2_P.Gain4_Gain_fc);
    if (rtIsNaN(rtb_Switch_idx_0) || rtIsInf(rtb_Switch_idx_0)) {
      rtb_Switch_idx_0 = 0.0;
    } else {
      rtb_Switch_idx_0 = fmod(rtb_Switch_idx_0, 65536.0);
    }

    px4_noGPS2_B.Gain4[i] = static_cast<uint16_T>(rtb_Switch_idx_0 < 0.0 ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-rtb_Switch_idx_0)))) : static_cast<int32_T>(
      static_cast<uint16_T>(rtb_Switch_idx_0)));

    // End of Gain: '<Root>/Gain4'
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1'
  for (int32_T i = 0; i < 8; i++) {
    px4_noGPS2_B.pwmValue[i] = 0U;
  }

  // Sum: '<Root>/Add' incorporates:
  //   Constant: '<Root>/fault_1'

  rtb_Switch_idx_0 = floor(static_cast<real_T>(px4_noGPS2_B.Gain4[0]) -
    px4_noGPS2_P.fault_1_Value);
  if (rtIsNaN(rtb_Switch_idx_0) || rtIsInf(rtb_Switch_idx_0)) {
    rtb_Switch_idx_0 = 0.0;
  } else {
    rtb_Switch_idx_0 = fmod(rtb_Switch_idx_0, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Sum: '<Root>/Add'

  px4_noGPS2_B.pwmValue[0] = static_cast<uint16_T>(rtb_Switch_idx_0 < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-rtb_Switch_idx_0)))) : static_cast<int32_T>(
    static_cast<uint16_T>(rtb_Switch_idx_0)));

  // Sum: '<Root>/Add1' incorporates:
  //   Constant: '<Root>/fault_2'

  rtb_Switch_idx_0 = floor(static_cast<real_T>(px4_noGPS2_B.Gain4[1]) -
    px4_noGPS2_P.fault_2_Value);
  if (rtIsNaN(rtb_Switch_idx_0) || rtIsInf(rtb_Switch_idx_0)) {
    rtb_Switch_idx_0 = 0.0;
  } else {
    rtb_Switch_idx_0 = fmod(rtb_Switch_idx_0, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Sum: '<Root>/Add1'

  px4_noGPS2_B.pwmValue[1] = static_cast<uint16_T>(rtb_Switch_idx_0 < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-rtb_Switch_idx_0)))) : static_cast<int32_T>(
    static_cast<uint16_T>(rtb_Switch_idx_0)));

  // Sum: '<Root>/Add2' incorporates:
  //   Constant: '<Root>/fault_3'

  rtb_Switch_idx_0 = floor(static_cast<real_T>(px4_noGPS2_B.Gain4[2]) -
    px4_noGPS2_P.fault_3_Value);
  if (rtIsNaN(rtb_Switch_idx_0) || rtIsInf(rtb_Switch_idx_0)) {
    rtb_Switch_idx_0 = 0.0;
  } else {
    rtb_Switch_idx_0 = fmod(rtb_Switch_idx_0, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Sum: '<Root>/Add2'

  px4_noGPS2_B.pwmValue[2] = static_cast<uint16_T>(rtb_Switch_idx_0 < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-rtb_Switch_idx_0)))) : static_cast<int32_T>(
    static_cast<uint16_T>(rtb_Switch_idx_0)));

  // Sum: '<Root>/Add3' incorporates:
  //   Constant: '<Root>/fault_4'

  rtb_Switch_idx_0 = floor(static_cast<real_T>(px4_noGPS2_B.Gain4[3]) -
    px4_noGPS2_P.fault_4_Value);
  if (rtIsNaN(rtb_Switch_idx_0) || rtIsInf(rtb_Switch_idx_0)) {
    rtb_Switch_idx_0 = 0.0;
  } else {
    rtb_Switch_idx_0 = fmod(rtb_Switch_idx_0, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Reset'
  //   Sum: '<Root>/Add3'

  px4_noGPS2_B.pwmValue[3] = static_cast<uint16_T>(rtb_Switch_idx_0 < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-rtb_Switch_idx_0)))) : static_cast<int32_T>(
    static_cast<uint16_T>(rtb_Switch_idx_0)));
  if (px4_noGPS2_P.Reset_Value) {
    if (!px4_noGPS2_DW.obj.isArmed) {
      px4_noGPS2_DW.obj.isArmed = true;
      status = pwm_arm(&px4_noGPS2_DW.obj.pwmDevHandler,
                       &px4_noGPS2_DW.obj.armAdvertiseObj);
      px4_noGPS2_DW.obj.errorStatus = static_cast<uint16_T>
        (px4_noGPS2_DW.obj.errorStatus | status);
    }

    status = pwm_setServo(&px4_noGPS2_DW.obj.pwmDevHandler,
                          px4_noGPS2_DW.obj.servoCount,
                          px4_noGPS2_DW.obj.channelMask, &px4_noGPS2_B.pwmValue
                          [0], px4_noGPS2_DW.obj.isMain,
                          &px4_noGPS2_DW.obj.actuatorAdvertiseObj);
    px4_noGPS2_DW.obj.errorStatus = static_cast<uint16_T>
      (px4_noGPS2_DW.obj.errorStatus | status);
  } else {
    status = pwm_disarm(&px4_noGPS2_DW.obj.pwmDevHandler,
                        &px4_noGPS2_DW.obj.armAdvertiseObj);
    px4_noGPS2_DW.obj.errorStatus = static_cast<uint16_T>
      (px4_noGPS2_DW.obj.errorStatus | status);
    px4_noGPS2_DW.obj.isArmed = false;
    status = pwm_resetServo(&px4_noGPS2_DW.obj.pwmDevHandler,
      px4_noGPS2_DW.obj.servoCount, px4_noGPS2_DW.obj.channelMask,
      px4_noGPS2_DW.obj.isMain, &px4_noGPS2_DW.obj.actuatorAdvertiseObj);
    px4_noGPS2_DW.obj.errorStatus = static_cast<uint16_T>
      (px4_noGPS2_DW.obj.errorStatus | status);
  }

  if (px4_noGPS2_DW.obj.isMain) {
    status = pwm_forceFailsafe(&px4_noGPS2_DW.obj.pwmDevHandler,
      static_cast<int32_T>(px4_noGPS2_P.Constant2_Value_kf));
    px4_noGPS2_DW.obj.errorStatus = static_cast<uint16_T>
      (px4_noGPS2_DW.obj.errorStatus | status);
  }

  // Switch: '<Root>/Switch1' incorporates:
  //   Constant: '<Root>/Constant5'
  //   DataStoreRead: '<Root>/Data Store Read53'
  //   DataStoreRead: '<Root>/Data Store Read63'
  //   MATLAB Function: '<Root>/MATLAB Function5'

  if (px4_noGPS2_DW.position_flag) {
    // MATLAB Function: '<Root>/MATLAB Function5' incorporates:
    //   DataStoreRead: '<Root>/Data Store Read58'
    //   DataStoreRead: '<Root>/Data Store Read66'
    //   DataStoreRead: '<Root>/Data Store Read67'

    px4_noGPS2_B.e_l = sin(px4_noGPS2_DW.yaw);
    px4_noGPS2_B.roll_desire = sin(px4_noGPS2_DW.pitch);
    px4_noGPS2_B.roll = cos(px4_noGPS2_DW.yaw);
    rtb_Switch_idx_1 = cos(px4_noGPS2_DW.pitch) * sin(px4_noGPS2_DW.roll);
    rtb_Switch_idx_0 = (rtb_Switch_idx_1 * px4_noGPS2_B.roll +
                        px4_noGPS2_B.roll_desire * px4_noGPS2_B.e_l) *
      -px4_noGPS2_DW.U1;
    rtb_Switch_idx_1 = (rtb_Switch_idx_1 * px4_noGPS2_B.e_l -
                        px4_noGPS2_B.roll_desire * px4_noGPS2_B.roll) *
      -px4_noGPS2_DW.U1;
  } else {
    rtb_Switch_idx_0 = px4_noGPS2_P.Constant5_Value;
    rtb_Switch_idx_1 = px4_noGPS2_P.Constant5_Value;
  }

  // End of Switch: '<Root>/Switch1'

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read28'

  px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_B.z2_e;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read29'

  px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_B.z2_l;

  // DataStoreRead: '<Root>/Data Store Read32'
  px4_noGPS2_B.roll = px4_noGPS2_B.yaw_thrust;

  // DataStoreRead: '<Root>/Data Store Read73' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read70'
  //   DataStoreWrite: '<Root>/Data Store Write9'

  px4_noGPS2_B.roll_desire = px4_noGPS2_DW.U1;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read31'
  //   Gain: '<Root>/Gain8'

  px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_P.Gain8_Gain_o1 *
    px4_noGPS2_DW.pitch;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read74'
  //   Gain: '<Root>/Gain10'

  px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_P.Gain10_Gain *
    px4_noGPS2_DW.pitch_desire;

  // Gain: '<Root>/Gain7' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read30'

  px4_noGPS2_B.roll = px4_noGPS2_P.Gain7_Gain_a * px4_noGPS2_DW.roll;

  // Gain: '<Root>/Gain11' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read41'

  px4_noGPS2_B.roll_desire = px4_noGPS2_P.Gain11_Gain *
    px4_noGPS2_DW.roll_desire;

  // Gain: '<Root>/Gain9' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read33'

  px4_noGPS2_B.e_l = px4_noGPS2_P.Gain9_Gain * px4_noGPS2_DW.yaw;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_dX'

  px4_noGPS2_B.rtb_DataStoreRead48_p = px4_noGPS2_DW.Intgrt_dX_DSTATE;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_dY'

  px4_noGPS2_B.rtb_DataStoreRead49_c = px4_noGPS2_DW.Intgrt_dY_DSTATE;

  // Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
  //   EnablePort: '<S9>/Enable'

  // DataStoreRead: '<Root>/Data Store Read54'
  if (px4_noGPS2_DW.attitude_flag) {
    // DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
    //   DataStoreWrite: '<S9>/Data Store Write27'

    px4_noGPS2_DW.t = px4_noGPS2_DW.DiscreteTimeIntegrator_DSTAT_fj;

    // Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S9>/Constant9'

    px4_noGPS2_DW.DiscreteTimeIntegrator_DSTAT_fj +=
      px4_noGPS2_P.DiscreteTimeIntegrator_gainval * px4_noGPS2_P.Constant9_Value;
  }

  // End of DataStoreRead: '<Root>/Data Store Read54'
  // End of Outputs for SubSystem: '<Root>/Subsystem1'

  // Update for UnitDelay: '<S37>/UD'
  //
  //  Block description for '<S37>/UD':
  //
  //   Store in Global RAM

  px4_noGPS2_DW.UD_DSTATE = px4_noGPS2_B.TSamp;

  // Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator3' incorporates:
  //   Gain: '<S18>/Gain7'
  //   Sum: '<S18>/Add15'
  //   Sum: '<S18>/Add5'

  px4_noGPS2_DW.DiscreteTimeIntegrator3_DSTATE += ((px4_noGPS2_B.Product6 +
    px4_noGPS2_B.e_g) * px4_noGPS2_P.Gain7_Gain + (px4_noGPS2_B.l4 +
    px4_noGPS2_B.lambda4)) * px4_noGPS2_P.DiscreteTimeIntegrator3_gainval;

  // Update for UnitDelay: '<S19>/UD'
  //
  //  Block description for '<S19>/UD':
  //
  //   Store in Global RAM

  px4_noGPS2_DW.UD_DSTATE_b = px4_noGPS2_B.z2;

  // Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator3' incorporates:
  //   Gain: '<S16>/Gain7'
  //   Sum: '<S16>/Add15'
  //   Sum: '<S16>/Add5'

  px4_noGPS2_DW.DiscreteTimeIntegrator3_DSTAT_a += ((px4_noGPS2_B.Abs6 +
    px4_noGPS2_B.e_gq) * px4_noGPS2_P.Gain7_Gain_d + (px4_noGPS2_B.Product7_e +
    px4_noGPS2_B.lambda4_n)) * px4_noGPS2_P.DiscreteTimeIntegrator3_gainv_m;

  // Update for UnitDelay: '<S28>/UD'
  //
  //  Block description for '<S28>/UD':
  //
  //   Store in Global RAM

  px4_noGPS2_DW.UD_DSTATE_n = px4_noGPS2_B.Product_c;

  // Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator3' incorporates:
  //   Gain: '<S17>/Gain7'
  //   Sum: '<S17>/Add15'
  //   Sum: '<S17>/Add5'

  px4_noGPS2_DW.DiscreteTimeIntegrator3_DSTAT_m += ((px4_noGPS2_B.Product6_a +
    px4_noGPS2_B.e_e1) * px4_noGPS2_P.Gain7_Gain_l + (px4_noGPS2_B.l2_h +
    px4_noGPS2_B.lambda4_h)) * px4_noGPS2_P.DiscreteTimeIntegrator3_gainv_e;

  // Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S18>/Discrete-Time Integrator1'
  //   Gain: '<S18>/Gain5'
  //   Gain: '<S18>/l1'
  //   Sum: '<S18>/Add'
  //   Sum: '<S18>/Add9'

  px4_noGPS2_DW.DiscreteTimeIntegrator_DSTATE += (((px4_noGPS2_P.l1_Gain *
    rtb_Fcn_tmp + px4_noGPS2_B.Add3) +
    px4_noGPS2_DW.DiscreteTimeIntegrator1_DSTATE) + (px4_noGPS2_B.Product3 +
    px4_noGPS2_B.Product4) * px4_noGPS2_P.Gain5_Gain) *
    px4_noGPS2_P.DiscreteTimeIntegrator_gainva_n;

  // Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator1'
  px4_noGPS2_DW.DiscreteTimeIntegrator1_DSTATE +=
    px4_noGPS2_P.DiscreteTimeIntegrator1_gainval * px4_noGPS2_B.l2;

  // Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S16>/Gain5'
  //   Sum: '<S16>/Add'
  //   Sum: '<S16>/Add9'

  px4_noGPS2_DW.DiscreteTimeIntegrator_DSTATE_p += (((px4_noGPS2_B.Product7 +
    px4_noGPS2_B.lambda1_a) + px4_noGPS2_B.Product_cm) +
    (px4_noGPS2_B.Product3_a + px4_noGPS2_B.Product4_k) *
    px4_noGPS2_P.Gain5_Gain_o) * px4_noGPS2_P.DiscreteTimeIntegrator_gainva_e;

  // Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator1'
  px4_noGPS2_DW.DiscreteTimeIntegrator1_DSTAT_i +=
    px4_noGPS2_P.DiscreteTimeIntegrator1_gainv_n * px4_noGPS2_B.l2_j;

  // Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S17>/Gain5'
  //   Sum: '<S17>/Add'
  //   Sum: '<S17>/Add9'

  px4_noGPS2_DW.DiscreteTimeIntegrator_DSTATE_f += (((px4_noGPS2_B.roll_hat_k +
    px4_noGPS2_B.lambda1_e) + px4_noGPS2_B.z1_i) + (px4_noGPS2_B.Product3_c +
    px4_noGPS2_B.Product4_g) * px4_noGPS2_P.Gain5_Gain_l) *
    px4_noGPS2_P.DiscreteTimeIntegrator_gainv_nv;

  // Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1'
  px4_noGPS2_DW.DiscreteTimeIntegrator1_DSTAT_g +=
    px4_noGPS2_P.DiscreteTimeIntegrator1_gainv_g *
    px4_noGPS2_B.rtb_DataTypeConversion3_idx_0;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_dX' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddX'

  px4_noGPS2_DW.Intgrt_dX_DSTATE += px4_noGPS2_P.Intgrt_dX_gainval *
    px4_noGPS2_DW.Intgrt_ddX_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_dY' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddY'

  px4_noGPS2_DW.Intgrt_dY_DSTATE += px4_noGPS2_P.Intgrt_dY_gainval *
    px4_noGPS2_DW.Intgrt_ddY_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_ddY' incorporates:
  //   Gain: '<Root>/slower4'

  px4_noGPS2_DW.Intgrt_ddY_DSTATE += px4_noGPS2_P.slower4_Gain *
    rtb_Switch_idx_1 * px4_noGPS2_P.Intgrt_ddY_gainval;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_ddX' incorporates:
  //   Gain: '<Root>/slower3'

  px4_noGPS2_DW.Intgrt_ddX_DSTATE += px4_noGPS2_P.slower3_Gain *
    rtb_Switch_idx_0 * px4_noGPS2_P.Intgrt_ddX_gainval;

  // Update for UnitDelay: '<S50>/UD'
  //
  //  Block description for '<S50>/UD':
  //
  //   Store in Global RAM

  px4_noGPS2_DW.UD_DSTATE_n2 = px4_noGPS2_B.TSamp_k;

  // Update for UnitDelay: '<S51>/UD'
  //
  //  Block description for '<S51>/UD':
  //
  //   Store in Global RAM

  px4_noGPS2_DW.UD_DSTATE_f = px4_noGPS2_B.TSamp_f;

  // Update for UnitDelay: '<S52>/UD'
  //
  //  Block description for '<S52>/UD':
  //
  //   Store in Global RAM

  px4_noGPS2_DW.UD_DSTATE_m = px4_noGPS2_B.rtb_DataTypeConversion3_idx_1;

  // Update for UnitDelay: '<S53>/UD'
  //
  //  Block description for '<S53>/UD':
  //
  //   Store in Global RAM

  px4_noGPS2_DW.UD_DSTATE_fi = px4_noGPS2_B.TSamp_e;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_dZ' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddZ'

  px4_noGPS2_DW.Intgrt_dZ_DSTATE += px4_noGPS2_P.Intgrt_dZ_gainval *
    px4_noGPS2_DW.Intgrt_ddZ_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_ddZ' incorporates:
  //   Gain: '<Root>/slower5'

  px4_noGPS2_DW.Intgrt_ddZ_DSTATE += px4_noGPS2_P.slower5_Gain * 0.0 *
    px4_noGPS2_P.Intgrt_ddZ_gainval;
}

// Model step function for TID1
void px4_noGPS2_step1(void)            // Sample time: [0.01s, 0.0s]
{
  uint64_T rtb_timestamp;
  uint32_T rtb_noutputs;
  uint8_T rtb__padding0[4];
  boolean_T b_varargout_1;
  boolean_T rtb_NOT;

  // MATLABSystem: '<S5>/SourceBlock'
  b_varargout_1 = uORB_read_step(px4_noGPS2_DW.obj_l.orbMetadataObj,
    &px4_noGPS2_DW.obj_l.eventStructObj, &px4_noGPS2_B.b_varargout_2_m, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S46>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S46>/In1'
    px4_noGPS2_B.In1_a = px4_noGPS2_B.b_varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb_timestamp = px4_noGPS2_B.In1_a.timestamp;

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb_noutputs = px4_noGPS2_B.In1_a.noutputs;

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb__padding0[0] = px4_noGPS2_B.In1_a._padding0[0];
  rtb__padding0[1] = px4_noGPS2_B.In1_a._padding0[1];
  rtb__padding0[2] = px4_noGPS2_B.In1_a._padding0[2];
  rtb__padding0[3] = px4_noGPS2_B.In1_a._padding0[3];

  // Logic: '<S5>/NOT' incorporates:
  //   MATLABSystem: '<S5>/SourceBlock'

  rtb_NOT = !b_varargout_1;
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void px4_noGPS2_step(int_T tid)
{
  switch (tid) {
   case 0 :
    px4_noGPS2_step0();
    break;

   case 1 :
    px4_noGPS2_step1();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void px4_noGPS2_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  px4_noGPS2_P.Saturation1_UpperSat_k = rtInf;

  // block I/O
  (void) memset((static_cast<void *>(&px4_noGPS2_B)), 0,
                sizeof(B_px4_noGPS2_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&px4_noGPS2_DW), 0,
                sizeof(DW_px4_noGPS2_T));

  {
    boolean_T rtb_DataStoreRead6;

    // Start for DataStoreMemory: '<S39>/Data Store Memory'
    px4_noGPS2_DW.start_time_yaw = px4_noGPS2_P.DataStoreMemory_InitialValue;

    // Start for DataStoreMemory: '<S21>/Data Store Memory'
    px4_noGPS2_DW.start_time = px4_noGPS2_P.DataStoreMemory_InitialValue_l;

    // Start for DataStoreMemory: '<S30>/Data Store Memory'
    px4_noGPS2_DW.start_time_roll = px4_noGPS2_P.DataStoreMemory_InitialValue_b;

    // Start for DataStoreMemory: '<S1>/e_pitch'
    px4_noGPS2_DW.e_pitch = px4_noGPS2_P.e_pitch_InitialValue;

    // Start for DataStoreMemory: '<S1>/e_pitch1'
    px4_noGPS2_DW.e_pitch_roll = px4_noGPS2_P.e_pitch1_InitialValue;

    // Start for DataStoreMemory: '<S1>/e_pitch2'
    px4_noGPS2_DW.e_pitch_yaw = px4_noGPS2_P.e_pitch2_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory'
    px4_noGPS2_DW.attitude_flag = px4_noGPS2_P.DataStoreMemory_InitialValue_j;

    // Start for DataStoreMemory: '<Root>/Data Store Memory16'
    px4_noGPS2_DW.yaw_speed = px4_noGPS2_P.DataStoreMemory16_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory17'
    px4_noGPS2_DW.roll_speed = px4_noGPS2_P.DataStoreMemory17_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory18'
    px4_noGPS2_DW.pitch_speed = px4_noGPS2_P.DataStoreMemory18_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory22'
    px4_noGPS2_DW.roll_desire = px4_noGPS2_P.DataStoreMemory22_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory23'
    px4_noGPS2_DW.pitch_desire = px4_noGPS2_P.DataStoreMemory23_InitialValue;

    // Start for Gain: '<S7>/Gain4' incorporates:
    //   DataStoreMemory: '<Root>/Data Store Memory24'

    px4_noGPS2_DW.q_x = px4_noGPS2_P.DataStoreMemory24_InitialValue;

    // Start for Gain: '<S7>/Gain2' incorporates:
    //   DataStoreMemory: '<Root>/Data Store Memory25'

    px4_noGPS2_DW.q_y = px4_noGPS2_P.DataStoreMemory25_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory26'
    px4_noGPS2_DW.q_z = px4_noGPS2_P.DataStoreMemory26_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory27'
    px4_noGPS2_DW.position_flag = px4_noGPS2_P.DataStoreMemory27_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory29'
    px4_noGPS2_DW.t = px4_noGPS2_P.DataStoreMemory29_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory30'
    px4_noGPS2_DW.observer_flag = px4_noGPS2_P.DataStoreMemory30_InitialValue;

    // Start for MATLAB Function: '<Root>/MATLAB Function1' incorporates:
    //   DataStoreMemory: '<Root>/Data Store Memory36'

    px4_noGPS2_DW.U1 = px4_noGPS2_P.DataStoreMemory36_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory4'
    px4_noGPS2_DW.pitch = px4_noGPS2_P.DataStoreMemory4_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory6'
    px4_noGPS2_DW.roll = px4_noGPS2_P.DataStoreMemory6_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory8'
    px4_noGPS2_DW.yaw = px4_noGPS2_P.DataStoreMemory8_InitialValue;
    px4_noGPS2_PrevZCX.Subsystem_Trig_ZCE_e = POS_ZCSIG;
    px4_noGPS2_PrevZCX.Subsystem_Trig_ZCE_j = POS_ZCSIG;
    px4_noGPS2_PrevZCX.Subsystem_Trig_ZCE = POS_ZCSIG;

    // InitializeConditions for UnitDelay: '<S37>/UD'
    //
    //  Block description for '<S37>/UD':
    //
    //   Store in Global RAM

    px4_noGPS2_DW.UD_DSTATE = px4_noGPS2_P.DiscreteDerivative1_ICPrevScale;

    // InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator3' 
    px4_noGPS2_DW.DiscreteTimeIntegrator3_DSTATE =
      px4_noGPS2_P.DiscreteTimeIntegrator3_IC;

    // InitializeConditions for UnitDelay: '<S19>/UD'
    //
    //  Block description for '<S19>/UD':
    //
    //   Store in Global RAM

    px4_noGPS2_DW.UD_DSTATE_b = px4_noGPS2_P.DiscreteDerivative1_ICPrevSca_o;

    // InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator3' 
    px4_noGPS2_DW.DiscreteTimeIntegrator3_DSTAT_a =
      px4_noGPS2_P.DiscreteTimeIntegrator3_IC_k;

    // InitializeConditions for UnitDelay: '<S28>/UD'
    //
    //  Block description for '<S28>/UD':
    //
    //   Store in Global RAM

    px4_noGPS2_DW.UD_DSTATE_n = px4_noGPS2_P.DiscreteDerivative1_ICPrevSca_d;

    // InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator3' 
    px4_noGPS2_DW.DiscreteTimeIntegrator3_DSTAT_m =
      px4_noGPS2_P.DiscreteTimeIntegrator3_IC_l;

    // InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' 
    px4_noGPS2_DW.DiscreteTimeIntegrator_DSTATE =
      px4_noGPS2_P.DiscreteTimeIntegrator_IC_l;

    // InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator1' 
    px4_noGPS2_DW.DiscreteTimeIntegrator1_DSTATE =
      px4_noGPS2_P.DiscreteTimeIntegrator1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' 
    px4_noGPS2_DW.DiscreteTimeIntegrator_DSTATE_p =
      px4_noGPS2_P.DiscreteTimeIntegrator_IC_h;

    // InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator1' 
    px4_noGPS2_DW.DiscreteTimeIntegrator1_DSTAT_i =
      px4_noGPS2_P.DiscreteTimeIntegrator1_IC_j;

    // InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' 
    px4_noGPS2_DW.DiscreteTimeIntegrator_DSTATE_f =
      px4_noGPS2_P.DiscreteTimeIntegrator_IC_o;

    // InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' 
    px4_noGPS2_DW.DiscreteTimeIntegrator1_DSTAT_g =
      px4_noGPS2_P.DiscreteTimeIntegrator1_IC_c;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_dX'
    px4_noGPS2_DW.Intgrt_dX_DSTATE = px4_noGPS2_P.Intgrt_dX_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_dY'
    px4_noGPS2_DW.Intgrt_dY_DSTATE = px4_noGPS2_P.Intgrt_dY_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_ddY'
    px4_noGPS2_DW.Intgrt_ddY_DSTATE = px4_noGPS2_P.Intgrt_ddY_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_ddX'
    px4_noGPS2_DW.Intgrt_ddX_DSTATE = px4_noGPS2_P.Intgrt_ddX_IC;

    // InitializeConditions for UnitDelay: '<S50>/UD'
    //
    //  Block description for '<S50>/UD':
    //
    //   Store in Global RAM

    px4_noGPS2_DW.UD_DSTATE_n2 = px4_noGPS2_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for UnitDelay: '<S51>/UD'
    //
    //  Block description for '<S51>/UD':
    //
    //   Store in Global RAM

    px4_noGPS2_DW.UD_DSTATE_f = px4_noGPS2_P.DiscreteDerivative1_ICPrevSc_dk;

    // InitializeConditions for UnitDelay: '<S52>/UD'
    //
    //  Block description for '<S52>/UD':
    //
    //   Store in Global RAM

    px4_noGPS2_DW.UD_DSTATE_m = px4_noGPS2_P.DiscreteDerivative_ICPrevScal_g;

    // InitializeConditions for UnitDelay: '<S53>/UD'
    //
    //  Block description for '<S53>/UD':
    //
    //   Store in Global RAM

    px4_noGPS2_DW.UD_DSTATE_fi = px4_noGPS2_P.DiscreteDerivative1_ICPrevSca_c;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_dZ'
    px4_noGPS2_DW.Intgrt_dZ_DSTATE = px4_noGPS2_P.Intgrt_dZ_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_ddZ'
    px4_noGPS2_DW.Intgrt_ddZ_DSTATE = px4_noGPS2_P.Intgrt_ddZ_IC;

    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S46>/In1' incorporates:
    //   Outport: '<S46>/Out1'

    px4_noGPS2_B.In1_a = px4_noGPS2_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S47>/In1' incorporates:
    //   Outport: '<S47>/Out1'

    px4_noGPS2_B.In1 = px4_noGPS2_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1'
    // InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' 
    px4_noGPS2_DW.DiscreteTimeIntegrator_DSTAT_fj =
      px4_noGPS2_P.DiscreteTimeIntegrator_IC;

    // End of SystemInitialize for SubSystem: '<Root>/Subsystem1'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    px4_noGPS2_DW.obj_n.matlabCodegenIsDeleted = false;
    px4_noGPS2_DW.obj_n.isSetupComplete = false;
    px4_noGPS2_DW.obj_n.isInitialized = 1;
    px4_noGPS2_DW.obj_n.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(px4_noGPS2_DW.obj_n.orbMetadataObj,
                         &px4_noGPS2_DW.obj_n.eventStructObj);
    px4_noGPS2_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
    //   Constant: '<Root>/Constant2'

    px4_noGPS2_DW.obj.errorStatus = 0U;
    px4_noGPS2_DW.obj.isInitialized = 0;
    px4_noGPS2_DW.obj.matlabCodegenIsDeleted = false;
    px4_noGPS2_SystemCore_setup(&px4_noGPS2_DW.obj, rtb_DataStoreRead6,
      px4_noGPS2_P.Constant2_Value_kf);

    // Start for MATLABSystem: '<S5>/SourceBlock'
    px4_noGPS2_DW.obj_l.matlabCodegenIsDeleted = false;
    px4_noGPS2_DW.obj_l.isSetupComplete = false;
    px4_noGPS2_DW.obj_l.isInitialized = 1;
    px4_noGPS2_DW.obj_l.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_read_initialize(px4_noGPS2_DW.obj_l.orbMetadataObj,
                         &px4_noGPS2_DW.obj_l.eventStructObj);
    px4_noGPS2_DW.obj_l.isSetupComplete = true;
  }
}

// Model terminate function
void px4_noGPS2_terminate(void)
{
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!px4_noGPS2_DW.obj_n.matlabCodegenIsDeleted) {
    px4_noGPS2_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((px4_noGPS2_DW.obj_n.isInitialized == 1) &&
        px4_noGPS2_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&px4_noGPS2_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for MATLABSystem: '<Root>/PX4 PWM Output1'
  if (!px4_noGPS2_DW.obj.matlabCodegenIsDeleted) {
    px4_noGPS2_DW.obj.matlabCodegenIsDeleted = true;
    if ((px4_noGPS2_DW.obj.isInitialized == 1) &&
        px4_noGPS2_DW.obj.isSetupComplete) {
      uint16_T status;
      status = pwm_disarm(&px4_noGPS2_DW.obj.pwmDevHandler,
                          &px4_noGPS2_DW.obj.armAdvertiseObj);
      px4_noGPS2_DW.obj.errorStatus = static_cast<uint16_T>
        (px4_noGPS2_DW.obj.errorStatus | status);
      status = pwm_resetServo(&px4_noGPS2_DW.obj.pwmDevHandler,
        px4_noGPS2_DW.obj.servoCount, px4_noGPS2_DW.obj.channelMask,
        px4_noGPS2_DW.obj.isMain, &px4_noGPS2_DW.obj.actuatorAdvertiseObj);
      px4_noGPS2_DW.obj.errorStatus = static_cast<uint16_T>
        (px4_noGPS2_DW.obj.errorStatus | status);
      status = pwm_close(&px4_noGPS2_DW.obj.pwmDevHandler,
                         &px4_noGPS2_DW.obj.actuatorAdvertiseObj,
                         &px4_noGPS2_DW.obj.armAdvertiseObj);
      px4_noGPS2_DW.obj.errorStatus = static_cast<uint16_T>
        (px4_noGPS2_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 PWM Output1'

  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!px4_noGPS2_DW.obj_l.matlabCodegenIsDeleted) {
    px4_noGPS2_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((px4_noGPS2_DW.obj_l.isInitialized == 1) &&
        px4_noGPS2_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&px4_noGPS2_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
