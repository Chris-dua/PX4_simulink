//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px42LoopCtrQGCGPS202203131707.cpp
//
// Code generated for Simulink model 'px42LoopCtrQGCGPS202203131707'.
//
// Model version                  : 5.38
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Mar 19 16:35:44 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "px42LoopCtrQGCGPS202203131707.h"
#include "rtwtypes.h"
#include "px42LoopCtrQGCGPS202203131707_types.h"
#include "px42LoopCtrQGCGPS202203131707_private.h"
#include <math.h>

extern "C" {

#include "rt_nonfinite.h"

}
#include "rt_defines.h"
#include "zero_crossing_types.h"

// Block signals (default storage)
B_px42LoopCtrQGCGPS2022031317_T px42LoopCtrQGCGPS202203131707_B;

// Block states (default storage)
DW_px42LoopCtrQGCGPS202203131_T px42LoopCtrQGCGPS20220313170_DW;

// Previous zero-crossings (trigger) states
PrevZCX_px42LoopCtrQGCGPS2022_T px42LoopCtrQGCGPS202203_PrevZCX;

// Real-time model
RT_MODEL_px42LoopCtrQGCGPS202_T px42LoopCtrQGCGPS20220313170_M_ =
  RT_MODEL_px42LoopCtrQGCGPS202_T();
RT_MODEL_px42LoopCtrQGCGPS202_T *const px42LoopCtrQGCGPS20220313170_M =
  &px42LoopCtrQGCGPS20220313170_M_;

// Forward declaration for local functions
static void px42LoopCtrQGC_SystemCore_setup(px4_internal_block_PWM_px42Lo_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void px42LoopCtrQGCGPS202203131707_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(px42LoopCtrQGCGPS20220313170_M, 1));
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

  (px42LoopCtrQGCGPS20220313170_M->Timing.TaskCounters.TID[1])++;
  if ((px42LoopCtrQGCGPS20220313170_M->Timing.TaskCounters.TID[1]) > 1) {// Sample time: [0.01s, 0.0s] 
    px42LoopCtrQGCGPS20220313170_M->Timing.TaskCounters.TID[1] = 0;
  }
}

//
// Output and update for atomic system:
//    '<S22>/MATLAB Function'
//    '<S31>/MATLAB Function'
//    '<S40>/MATLAB Function'
//
void px42LoopCtrQ_MATLABFunction(boolean_T rtu_e, real_T rtu_t, real_T rtu_s_t,
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

static void px42LoopCtrQGC_SystemCore_setup(px4_internal_block_PWM_px42Lo_T *obj,
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
void px42LoopCtrQGCGPS202203131707_step0(void) // Sample time: [0.005s, 0.0s]
{
  real_T rtb_Fcn_tmp;
  real_T yaw_tmp;
  uint16_T status;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_g2;
  boolean_T rtb_Compare_i;
  boolean_T rtb_LogicalOperator;

  {                                    // Sample time: [0.005s, 0.0s]
    rate_monotonic_scheduler();
  }

  // Switch: '<S16>/Switch' incorporates:
  //   Constant: '<Root>/Constant3'
  //   Constant: '<S16>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read20'
  //   DataStoreRead: '<S16>/Data Store Read'
  //   DataStoreRead: '<S16>/Data Store Read1'

  if (px42LoopCtrQGCGPS20220313170_DW.attitude_flag) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 =
      px42LoopCtrQGCGPS20220313170_DW.yaw;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS202203131707_P.Constant3_Value;
    px42LoopCtrQGCGPS202203131707_B.e_l =
      px42LoopCtrQGCGPS20220313170_DW.yaw_speed;
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 =
      px42LoopCtrQGCGPS202203131707_P.Constant1_Value_a;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS202203131707_P.Constant1_Value_a;
    px42LoopCtrQGCGPS202203131707_B.e_l =
      px42LoopCtrQGCGPS202203131707_P.Constant1_Value_a;
  }

  // End of Switch: '<S16>/Switch'

  // Sum: '<S39>/Add' incorporates:
  //   Sum: '<S16>/Add2'

  px42LoopCtrQGCGPS202203131707_B.Product_c =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 -
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1;
  px42LoopCtrQGCGPS202203131707_B.z1_i =
    px42LoopCtrQGCGPS202203131707_B.Product_c;

  // RelationalOperator: '<S41>/Compare' incorporates:
  //   Abs: '<S40>/Abs'
  //   Constant: '<S41>/Constant'
  //   DataStoreRead: '<S40>/Data Store Read1'

  rtb_Compare = (fabs(px42LoopCtrQGCGPS20220313170_DW.e_pitch_yaw) >=
                 px42LoopCtrQGCGPS202203131707_P.CompareToConstant1_const);

  // Sum: '<S40>/Add' incorporates:
  //   DataStoreRead: '<S40>/Data Store Read'
  //   DataStoreRead: '<S40>/Data Store Read3'
  //   Sum: '<S43>/Add'

  rtb_Fcn_tmp = px42LoopCtrQGCGPS20220313170_DW.t -
    px42LoopCtrQGCGPS20220313170_DW.start_time_yaw;

  // Fcn: '<S40>/Fcn' incorporates:
  //   Constant: '<S40>/T'
  //   Constant: '<S40>/ch'
  //   Sum: '<S40>/Add'

  px42LoopCtrQGCGPS202203131707_B.rtb_Fcn_c =
    px42LoopCtrQGCGPS202203131707_P.ch_Value /
    (px42LoopCtrQGCGPS202203131707_P.T_Value - rtb_Fcn_tmp);

  // MATLAB Function: '<S40>/MATLAB Function' incorporates:
  //   Constant: '<S40>/t'
  //   DataStoreRead: '<S40>/Data Store Read'
  //   DataStoreRead: '<S40>/Data Store Read3'

  px42LoopCtrQ_MATLABFunction(rtb_Compare, px42LoopCtrQGCGPS20220313170_DW.t,
    px42LoopCtrQGCGPS20220313170_DW.start_time_yaw,
    px42LoopCtrQGCGPS202203131707_B.rtb_Fcn_c,
    px42LoopCtrQGCGPS202203131707_P.t_Value,
    &px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p);

  // Sum: '<S40>/Add1' incorporates:
  //   Constant: '<S40>/r'

  px42LoopCtrQGCGPS202203131707_B.z2 = px42LoopCtrQGCGPS202203131707_P.r_Value +
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p;

  // Gain: '<S39>/Gain4' incorporates:
  //   Constant: '<S16>/b'
  //   Product: '<S39>/Product'

  px42LoopCtrQGCGPS202203131707_B.z1_i = px42LoopCtrQGCGPS202203131707_B.z1_i *
    px42LoopCtrQGCGPS202203131707_B.z2 * px42LoopCtrQGCGPS202203131707_P.b_Value
    * px42LoopCtrQGCGPS202203131707_P.Gain4_Gain;

  // SampleTimeMath: '<S38>/TSamp'
  //
  //  About '<S38>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px42LoopCtrQGCGPS202203131707_B.TSamp = px42LoopCtrQGCGPS202203131707_B.z1_i *
    px42LoopCtrQGCGPS202203131707_P.TSamp_WtEt;

  // Sum: '<S16>/Add2' incorporates:
  //   DataStoreWrite: '<S16>/Data Store Write'

  px42LoopCtrQGCGPS20220313170_DW.e_pitch_yaw =
    px42LoopCtrQGCGPS202203131707_B.Product_c;

  // Sum: '<S16>/Add1'
  px42LoopCtrQGCGPS202203131707_B.z1_i = px42LoopCtrQGCGPS202203131707_B.e_l -
    px42LoopCtrQGCGPS202203131707_B.z1_i;

  // Product: '<S16>/Product' incorporates:
  //   Constant: '<S16>/b'

  px42LoopCtrQGCGPS202203131707_B.z2 = px42LoopCtrQGCGPS202203131707_B.z1_i *
    px42LoopCtrQGCGPS202203131707_B.z2 * px42LoopCtrQGCGPS202203131707_P.b_Value;

  // Signum: '<S16>/Sign'
  px42LoopCtrQGCGPS202203131707_B.z2_l = px42LoopCtrQGCGPS202203131707_B.z1_i;

  // Gain: '<S1>/Gain1' incorporates:
  //   DiscreteIntegrator: '<S19>/Discrete-Time Integrator3'

  px42LoopCtrQGCGPS202203131707_B.z1_i =
    px42LoopCtrQGCGPS202203131707_P.Gain1_Gain_o *
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator3_DSTATE;

  // Signum: '<S16>/Sign'
  if (!rtIsNaN(px42LoopCtrQGCGPS202203131707_B.z2_l)) {
    if (px42LoopCtrQGCGPS202203131707_B.z2_l < 0.0) {
      px42LoopCtrQGCGPS202203131707_B.z2_l = -1.0;
    } else {
      px42LoopCtrQGCGPS202203131707_B.z2_l =
        (px42LoopCtrQGCGPS202203131707_B.z2_l > 0.0);
    }
  }

  // Saturate: '<S1>/Saturation4'
  if (px42LoopCtrQGCGPS202203131707_B.z1_i >
      px42LoopCtrQGCGPS202203131707_P.Saturation4_UpperSat) {
    px42LoopCtrQGCGPS202203131707_B.z1_i =
      px42LoopCtrQGCGPS202203131707_P.Saturation4_UpperSat;
  } else if (px42LoopCtrQGCGPS202203131707_B.z1_i <
             px42LoopCtrQGCGPS202203131707_P.Saturation4_LowerSat) {
    px42LoopCtrQGCGPS202203131707_B.z1_i =
      px42LoopCtrQGCGPS202203131707_P.Saturation4_LowerSat;
  }

  // End of Saturate: '<S1>/Saturation4'

  // Sum: '<S1>/Add3' incorporates:
  //   Constant: '<S16>/l'
  //   DataStoreWrite: '<S16>/Data Store Write'
  //   Gain: '<S16>/Gain'
  //   Gain: '<S16>/Gain1'
  //   Product: '<S16>/Product1'
  //   Sum: '<S16>/Add'
  //   Sum: '<S38>/Diff'
  //   UnitDelay: '<S38>/UD'
  //
  //  Block description for '<S38>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S38>/UD':
  //
  //   Store in Global RAM

  px42LoopCtrQGCGPS202203131707_B.Add3 =
    (((((px42LoopCtrQGCGPS202203131707_B.TSamp -
         px42LoopCtrQGCGPS20220313170_DW.UD_DSTATE) -
        px42LoopCtrQGCGPS20220313170_DW.e_pitch_yaw) -
       px42LoopCtrQGCGPS202203131707_B.z2) -
      px42LoopCtrQGCGPS202203131707_B.z2_l *
      px42LoopCtrQGCGPS202203131707_P.l_Value) -
     px42LoopCtrQGCGPS202203131707_P.Gain_Gain *
     px42LoopCtrQGCGPS202203131707_B.e_l) *
    px42LoopCtrQGCGPS202203131707_P.Gain1_Gain -
    px42LoopCtrQGCGPS202203131707_B.z1_i;

  // ManualSwitch: '<S1>/Manual Switch' incorporates:
  //   Constant: '<S1>/Constant'
  //   DataStoreWrite: '<Root>/Data Store Write11'

  if (px42LoopCtrQGCGPS202203131707_P.ManualSwitch_CurrentSetting == 1) {
    // Saturate: '<S1>/Saturation'
    if (px42LoopCtrQGCGPS202203131707_B.Add3 >
        px42LoopCtrQGCGPS202203131707_P.Saturation_UpperSat) {
      px42LoopCtrQGCGPS202203131707_B.yaw_thrust =
        px42LoopCtrQGCGPS202203131707_P.Saturation_UpperSat;
    } else if (px42LoopCtrQGCGPS202203131707_B.Add3 <
               px42LoopCtrQGCGPS202203131707_P.Saturation_LowerSat) {
      px42LoopCtrQGCGPS202203131707_B.yaw_thrust =
        px42LoopCtrQGCGPS202203131707_P.Saturation_LowerSat;
    } else {
      px42LoopCtrQGCGPS202203131707_B.yaw_thrust =
        px42LoopCtrQGCGPS202203131707_B.Add3;
    }

    // End of Saturate: '<S1>/Saturation'
  } else {
    px42LoopCtrQGCGPS202203131707_B.yaw_thrust =
      px42LoopCtrQGCGPS202203131707_P.Constant_Value_b;
  }

  // End of ManualSwitch: '<S1>/Manual Switch'

  // Switch: '<S14>/Switch' incorporates:
  //   Constant: '<S14>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read14'
  //   DataStoreRead: '<Root>/Data Store Read58'
  //   DataStoreRead: '<S14>/Data Store Read'
  //   DataStoreRead: '<S14>/Data Store Read1'

  if (px42LoopCtrQGCGPS20220313170_DW.attitude_flag) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 =
      px42LoopCtrQGCGPS20220313170_DW.pitch;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS20220313170_DW.pitch_desire;
    px42LoopCtrQGCGPS202203131707_B.e_l =
      px42LoopCtrQGCGPS20220313170_DW.pitch_speed;
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 =
      px42LoopCtrQGCGPS202203131707_P.Constant1_Value;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS202203131707_P.Constant1_Value;
    px42LoopCtrQGCGPS202203131707_B.e_l =
      px42LoopCtrQGCGPS202203131707_P.Constant1_Value;
  }

  // End of Switch: '<S14>/Switch'

  // Sum: '<S21>/Add' incorporates:
  //   Sum: '<S14>/Add2'

  px42LoopCtrQGCGPS202203131707_B.Product_c =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 -
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1;
  px42LoopCtrQGCGPS202203131707_B.z1_i =
    px42LoopCtrQGCGPS202203131707_B.Product_c;

  // RelationalOperator: '<S23>/Compare' incorporates:
  //   Abs: '<S22>/Abs'
  //   Constant: '<S23>/Constant'
  //   DataStoreRead: '<S22>/Data Store Read1'

  rtb_Compare_i = (fabs(px42LoopCtrQGCGPS20220313170_DW.e_pitch) >=
                   px42LoopCtrQGCGPS202203131707_P.CompareToConstant1_const_b);

  // Sum: '<S22>/Add' incorporates:
  //   DataStoreRead: '<S22>/Data Store Read'
  //   DataStoreRead: '<S22>/Data Store Read3'
  //   Sum: '<S25>/Add'

  px42LoopCtrQGCGPS202203131707_B.Product3 = px42LoopCtrQGCGPS20220313170_DW.t -
    px42LoopCtrQGCGPS20220313170_DW.start_time;

  // Fcn: '<S22>/Fcn' incorporates:
  //   Constant: '<S22>/T'
  //   Constant: '<S22>/ch'
  //   Sum: '<S22>/Add'

  px42LoopCtrQGCGPS202203131707_B.rtb_Fcn_b_b =
    px42LoopCtrQGCGPS202203131707_P.ch_Value_j /
    (px42LoopCtrQGCGPS202203131707_P.T_Value_p -
     px42LoopCtrQGCGPS202203131707_B.Product3);

  // MATLAB Function: '<S22>/MATLAB Function' incorporates:
  //   Constant: '<S22>/t'
  //   DataStoreRead: '<S22>/Data Store Read'
  //   DataStoreRead: '<S22>/Data Store Read3'

  px42LoopCtrQ_MATLABFunction(rtb_Compare_i, px42LoopCtrQGCGPS20220313170_DW.t,
    px42LoopCtrQGCGPS20220313170_DW.start_time,
    px42LoopCtrQGCGPS202203131707_B.rtb_Fcn_b_b,
    px42LoopCtrQGCGPS202203131707_P.t_Value_n,
    &px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c);

  // Sum: '<S22>/Add1' incorporates:
  //   Constant: '<S22>/r'

  px42LoopCtrQGCGPS202203131707_B.z2_e =
    px42LoopCtrQGCGPS202203131707_P.r_Value_g +
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c;

  // Gain: '<S21>/Gain4' incorporates:
  //   Constant: '<S14>/b'
  //   Product: '<S21>/Product'

  px42LoopCtrQGCGPS202203131707_B.z1_i = px42LoopCtrQGCGPS202203131707_B.z1_i *
    px42LoopCtrQGCGPS202203131707_B.z2_e *
    px42LoopCtrQGCGPS202203131707_P.b_Value_l *
    px42LoopCtrQGCGPS202203131707_P.Gain4_Gain_b;

  // SampleTimeMath: '<S20>/TSamp'
  //
  //  About '<S20>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px42LoopCtrQGCGPS202203131707_B.z2 = px42LoopCtrQGCGPS202203131707_B.z1_i *
    px42LoopCtrQGCGPS202203131707_P.TSamp_WtEt_p;

  // Sum: '<S14>/Add2' incorporates:
  //   DataStoreWrite: '<S14>/Data Store Write'

  px42LoopCtrQGCGPS20220313170_DW.e_pitch =
    px42LoopCtrQGCGPS202203131707_B.Product_c;

  // Sum: '<S14>/Add1'
  px42LoopCtrQGCGPS202203131707_B.z1_i = px42LoopCtrQGCGPS202203131707_B.e_l -
    px42LoopCtrQGCGPS202203131707_B.z1_i;

  // Product: '<S14>/Product' incorporates:
  //   Constant: '<S14>/b'

  px42LoopCtrQGCGPS202203131707_B.Product_c =
    px42LoopCtrQGCGPS202203131707_B.z1_i * px42LoopCtrQGCGPS202203131707_B.z2_e *
    px42LoopCtrQGCGPS202203131707_P.b_Value_l;

  // Signum: '<S14>/Sign'
  px42LoopCtrQGCGPS202203131707_B.z2_l = px42LoopCtrQGCGPS202203131707_B.z1_i;

  // Gain: '<S1>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S17>/Discrete-Time Integrator3'

  px42LoopCtrQGCGPS202203131707_B.z1_i =
    px42LoopCtrQGCGPS202203131707_P.Gain2_Gain *
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator3_DSTAT_a;

  // Signum: '<S14>/Sign'
  if (!rtIsNaN(px42LoopCtrQGCGPS202203131707_B.z2_l)) {
    if (px42LoopCtrQGCGPS202203131707_B.z2_l < 0.0) {
      px42LoopCtrQGCGPS202203131707_B.z2_l = -1.0;
    } else {
      px42LoopCtrQGCGPS202203131707_B.z2_l =
        (px42LoopCtrQGCGPS202203131707_B.z2_l > 0.0);
    }
  }

  // Sum: '<S1>/Add2' incorporates:
  //   Constant: '<S14>/l'
  //   DataStoreWrite: '<Root>/Data Store Write12'
  //   DataStoreWrite: '<S14>/Data Store Write'
  //   Gain: '<S14>/Gain'
  //   Gain: '<S14>/Gain1'
  //   Product: '<S14>/Product1'
  //   Sum: '<S14>/Add'
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

  px42LoopCtrQGCGPS202203131707_B.z2_e = (((((px42LoopCtrQGCGPS202203131707_B.z2
    - px42LoopCtrQGCGPS20220313170_DW.UD_DSTATE_b) -
    px42LoopCtrQGCGPS20220313170_DW.e_pitch) -
    px42LoopCtrQGCGPS202203131707_B.Product_c) -
    px42LoopCtrQGCGPS202203131707_B.z2_l *
    px42LoopCtrQGCGPS202203131707_P.l_Value_b) -
    px42LoopCtrQGCGPS202203131707_P.Gain_Gain_o *
    px42LoopCtrQGCGPS202203131707_B.e_l) *
    px42LoopCtrQGCGPS202203131707_P.Gain1_Gain_b -
    px42LoopCtrQGCGPS202203131707_B.z1_i;

  // Switch: '<S15>/Switch' incorporates:
  //   Constant: '<S15>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read18'
  //   DataStoreRead: '<Root>/Data Store Read57'
  //   DataStoreRead: '<S15>/Data Store Read'
  //   DataStoreRead: '<S15>/Data Store Read1'

  if (px42LoopCtrQGCGPS20220313170_DW.attitude_flag) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 =
      px42LoopCtrQGCGPS20220313170_DW.roll;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS20220313170_DW.roll_desire;
    px42LoopCtrQGCGPS202203131707_B.e_l =
      px42LoopCtrQGCGPS20220313170_DW.roll_speed;
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 =
      px42LoopCtrQGCGPS202203131707_P.Constant1_Value_n;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS202203131707_P.Constant1_Value_n;
    px42LoopCtrQGCGPS202203131707_B.e_l =
      px42LoopCtrQGCGPS202203131707_P.Constant1_Value_n;
  }

  // End of Switch: '<S15>/Switch'

  // Sum: '<S30>/Add' incorporates:
  //   Sum: '<S15>/Add2'

  px42LoopCtrQGCGPS202203131707_B.l2_j =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 -
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1;
  px42LoopCtrQGCGPS202203131707_B.yaw = px42LoopCtrQGCGPS202203131707_B.l2_j;

  // RelationalOperator: '<S32>/Compare' incorporates:
  //   Abs: '<S31>/Abs'
  //   Constant: '<S32>/Constant'
  //   DataStoreRead: '<S31>/Data Store Read1'

  rtb_Compare_g2 = (fabs(px42LoopCtrQGCGPS20220313170_DW.e_pitch_roll) >=
                    px42LoopCtrQGCGPS202203131707_P.CompareToConstant1_const_h);

  // Sum: '<S31>/Add' incorporates:
  //   DataStoreRead: '<S31>/Data Store Read'
  //   DataStoreRead: '<S31>/Data Store Read3'
  //   Sum: '<S34>/Add'

  px42LoopCtrQGCGPS202203131707_B.Product4 = px42LoopCtrQGCGPS20220313170_DW.t -
    px42LoopCtrQGCGPS20220313170_DW.start_time_roll;

  // Fcn: '<S31>/Fcn' incorporates:
  //   Constant: '<S31>/T'
  //   Constant: '<S31>/ch'
  //   Sum: '<S31>/Add'

  px42LoopCtrQGCGPS202203131707_B.rtb_Fcn_a_k =
    px42LoopCtrQGCGPS202203131707_P.ch_Value_e /
    (px42LoopCtrQGCGPS202203131707_P.T_Value_c -
     px42LoopCtrQGCGPS202203131707_B.Product4);

  // MATLAB Function: '<S31>/MATLAB Function' incorporates:
  //   Constant: '<S31>/t'
  //   DataStoreRead: '<S31>/Data Store Read'
  //   DataStoreRead: '<S31>/Data Store Read3'

  px42LoopCtrQ_MATLABFunction(rtb_Compare_g2, px42LoopCtrQGCGPS20220313170_DW.t,
    px42LoopCtrQGCGPS20220313170_DW.start_time_roll,
    px42LoopCtrQGCGPS202203131707_B.rtb_Fcn_a_k,
    px42LoopCtrQGCGPS202203131707_P.t_Value_m,
    &px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c);

  // Sum: '<S31>/Add1' incorporates:
  //   Constant: '<S31>/r'

  px42LoopCtrQGCGPS202203131707_B.z2_l =
    px42LoopCtrQGCGPS202203131707_P.r_Value_p +
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c;

  // Gain: '<S30>/Gain4' incorporates:
  //   Constant: '<S15>/b'
  //   Product: '<S30>/Product'

  px42LoopCtrQGCGPS202203131707_B.yaw = px42LoopCtrQGCGPS202203131707_B.yaw *
    px42LoopCtrQGCGPS202203131707_B.z2_l *
    px42LoopCtrQGCGPS202203131707_P.b_Value_h *
    px42LoopCtrQGCGPS202203131707_P.Gain4_Gain_o;

  // SampleTimeMath: '<S29>/TSamp'
  //
  //  About '<S29>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px42LoopCtrQGCGPS202203131707_B.Product_c =
    px42LoopCtrQGCGPS202203131707_B.yaw *
    px42LoopCtrQGCGPS202203131707_P.TSamp_WtEt_o;

  // Sum: '<S15>/Add2' incorporates:
  //   DataStoreWrite: '<S15>/Data Store Write'

  px42LoopCtrQGCGPS20220313170_DW.e_pitch_roll =
    px42LoopCtrQGCGPS202203131707_B.l2_j;

  // Sum: '<S15>/Add1'
  px42LoopCtrQGCGPS202203131707_B.yaw = px42LoopCtrQGCGPS202203131707_B.e_l -
    px42LoopCtrQGCGPS202203131707_B.yaw;

  // Product: '<S15>/Product' incorporates:
  //   Constant: '<S15>/b'

  px42LoopCtrQGCGPS202203131707_B.Product_cm =
    px42LoopCtrQGCGPS202203131707_B.yaw * px42LoopCtrQGCGPS202203131707_B.z2_l *
    px42LoopCtrQGCGPS202203131707_P.b_Value_h;

  // Signum: '<S15>/Sign'
  px42LoopCtrQGCGPS202203131707_B.z2_l = px42LoopCtrQGCGPS202203131707_B.yaw;

  // Gain: '<S1>/J' incorporates:
  //   DiscreteIntegrator: '<S18>/Discrete-Time Integrator3'

  px42LoopCtrQGCGPS202203131707_B.yaw = px42LoopCtrQGCGPS202203131707_P.J_Gain_b
    * px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator3_DSTAT_m;

  // Signum: '<S15>/Sign'
  if (!rtIsNaN(px42LoopCtrQGCGPS202203131707_B.z2_l)) {
    if (px42LoopCtrQGCGPS202203131707_B.z2_l < 0.0) {
      px42LoopCtrQGCGPS202203131707_B.z2_l = -1.0;
    } else {
      px42LoopCtrQGCGPS202203131707_B.z2_l =
        (px42LoopCtrQGCGPS202203131707_B.z2_l > 0.0);
    }
  }

  // Sum: '<S1>/Add1' incorporates:
  //   Constant: '<S15>/l'
  //   DataStoreWrite: '<Root>/Data Store Write13'
  //   DataStoreWrite: '<S15>/Data Store Write'
  //   Gain: '<S15>/Gain'
  //   Gain: '<S15>/J'
  //   Product: '<S15>/Product1'
  //   Sum: '<S15>/Add'
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

  px42LoopCtrQGCGPS202203131707_B.z2_l =
    (((((px42LoopCtrQGCGPS202203131707_B.Product_c -
         px42LoopCtrQGCGPS20220313170_DW.UD_DSTATE_n) -
        px42LoopCtrQGCGPS20220313170_DW.e_pitch_roll) -
       px42LoopCtrQGCGPS202203131707_B.Product_cm) -
      px42LoopCtrQGCGPS202203131707_B.z2_l *
      px42LoopCtrQGCGPS202203131707_P.l_Value_n) -
     px42LoopCtrQGCGPS202203131707_P.Gain_Gain_m *
     px42LoopCtrQGCGPS202203131707_B.e_l) *
    px42LoopCtrQGCGPS202203131707_P.J_Gain - px42LoopCtrQGCGPS202203131707_B.yaw;

  // Logic: '<S43>/Logical Operator' incorporates:
  //   Abs: '<S43>/Abs1'
  //   Constant: '<S44>/Constant'
  //   Constant: '<S45>/Constant'
  //   DataStoreRead: '<S43>/Data Store Read2'
  //   RelationalOperator: '<S44>/Compare'
  //   RelationalOperator: '<S45>/Compare'

  rtb_LogicalOperator = ((fabs(px42LoopCtrQGCGPS20220313170_DW.e_pitch_yaw) >=
    px42LoopCtrQGCGPS202203131707_P.CompareToConstant2_const) && (rtb_Fcn_tmp >=
    px42LoopCtrQGCGPS202203131707_P.CompareToConstant1_const_hq));

  // Outputs for Triggered SubSystem: '<S43>/Subsystem' incorporates:
  //   TriggerPort: '<S46>/Trigger'

  if (rtb_LogicalOperator && (px42LoopCtrQGCGPS202203_PrevZCX.Subsystem_Trig_ZCE
       != POS_ZCSIG)) {
    // DataStoreWrite: '<S46>/Data Store Write' incorporates:
    //   DataStoreRead: '<S46>/Data Store Read2'

    px42LoopCtrQGCGPS20220313170_DW.start_time_yaw =
      px42LoopCtrQGCGPS20220313170_DW.t;
  }

  px42LoopCtrQGCGPS202203_PrevZCX.Subsystem_Trig_ZCE = rtb_LogicalOperator;

  // End of Outputs for SubSystem: '<S43>/Subsystem'
  // Logic: '<S25>/Logical Operator' incorporates:
  //   Abs: '<S25>/Abs1'
  //   Constant: '<S26>/Constant'
  //   Constant: '<S27>/Constant'
  //   DataStoreRead: '<S25>/Data Store Read2'
  //   RelationalOperator: '<S26>/Compare'
  //   RelationalOperator: '<S27>/Compare'

  rtb_LogicalOperator = ((fabs(px42LoopCtrQGCGPS20220313170_DW.e_pitch) >=
    px42LoopCtrQGCGPS202203131707_P.CompareToConstant2_const_o) &&
    (px42LoopCtrQGCGPS202203131707_B.Product3 >=
     px42LoopCtrQGCGPS202203131707_P.CompareToConstant1_const_p));

  // Outputs for Triggered SubSystem: '<S25>/Subsystem' incorporates:
  //   TriggerPort: '<S28>/Trigger'

  if (rtb_LogicalOperator &&
      (px42LoopCtrQGCGPS202203_PrevZCX.Subsystem_Trig_ZCE_e != POS_ZCSIG)) {
    // DataStoreWrite: '<S28>/Data Store Write' incorporates:
    //   DataStoreRead: '<S28>/Data Store Read2'

    px42LoopCtrQGCGPS20220313170_DW.start_time =
      px42LoopCtrQGCGPS20220313170_DW.t;
  }

  px42LoopCtrQGCGPS202203_PrevZCX.Subsystem_Trig_ZCE_e = rtb_LogicalOperator;

  // End of Outputs for SubSystem: '<S25>/Subsystem'
  // Logic: '<S34>/Logical Operator' incorporates:
  //   Abs: '<S34>/Abs1'
  //   Constant: '<S35>/Constant'
  //   Constant: '<S36>/Constant'
  //   DataStoreRead: '<S34>/Data Store Read2'
  //   RelationalOperator: '<S35>/Compare'
  //   RelationalOperator: '<S36>/Compare'

  rtb_LogicalOperator = ((fabs(px42LoopCtrQGCGPS20220313170_DW.e_pitch_roll) >=
    px42LoopCtrQGCGPS202203131707_P.CompareToConstant2_const_a) &&
    (px42LoopCtrQGCGPS202203131707_B.Product4 >=
     px42LoopCtrQGCGPS202203131707_P.CompareToConstant1_const_a));

  // Outputs for Triggered SubSystem: '<S34>/Subsystem' incorporates:
  //   TriggerPort: '<S37>/Trigger'

  if (rtb_LogicalOperator &&
      (px42LoopCtrQGCGPS202203_PrevZCX.Subsystem_Trig_ZCE_j != POS_ZCSIG)) {
    // DataStoreWrite: '<S37>/Data Store Write' incorporates:
    //   DataStoreRead: '<S37>/Data Store Read2'

    px42LoopCtrQGCGPS20220313170_DW.start_time_roll =
      px42LoopCtrQGCGPS20220313170_DW.t;
  }

  px42LoopCtrQGCGPS202203_PrevZCX.Subsystem_Trig_ZCE_j = rtb_LogicalOperator;

  // End of Outputs for SubSystem: '<S34>/Subsystem'

  // Gain: '<S19>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S19>/Discrete-Time Integrator'

  px42LoopCtrQGCGPS202203131707_B.Product_cm =
    px42LoopCtrQGCGPS202203131707_P.Gain2_Gain_c *
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE;

  // ZeroOrderHold: '<S19>/Zero-Order Hold3' incorporates:
  //   Gain: '<S19>/1//J'

  px42LoopCtrQGCGPS202203131707_B.Product_cm =
    px42LoopCtrQGCGPS202203131707_P.uJ_Gain *
    px42LoopCtrQGCGPS202203131707_B.Add3;

  // ZeroOrderHold: '<S19>/Zero-Order Hold1' incorporates:
  //   DataStoreRead: '<S19>/Data Store Read'

  px42LoopCtrQGCGPS202203131707_B.e_l = px42LoopCtrQGCGPS20220313170_DW.yaw;

  // Switch: '<S19>/Switch' incorporates:
  //   Constant: '<S19>/Constant3'
  //   DataStoreRead: '<S19>/Data Store Read1'
  //   DataStoreRead: '<S19>/Data Store Read2'
  //   Gain: '<S19>/k//J'

  if (px42LoopCtrQGCGPS20220313170_DW.observer_flag) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 =
      px42LoopCtrQGCGPS202203131707_B.Product_cm;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS202203131707_P.kJ_Gain *
      px42LoopCtrQGCGPS20220313170_DW.yaw_speed;
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 =
      px42LoopCtrQGCGPS202203131707_P.Constant3_Value_d;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS202203131707_P.Constant3_Value_d;
    px42LoopCtrQGCGPS202203131707_B.e_l =
      px42LoopCtrQGCGPS202203131707_P.Constant3_Value_d;
  }

  // End of Switch: '<S19>/Switch'

  // Sum: '<S19>/Add1' incorporates:
  //   DiscreteIntegrator: '<S19>/Discrete-Time Integrator'

  px42LoopCtrQGCGPS202203131707_B.e_l -=
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE;

  // Abs: '<S19>/Abs3' incorporates:
  //   Abs: '<S19>/Abs4'
  //   Abs: '<S19>/Abs5'
  //   Abs: '<S19>/Abs6'

  px42LoopCtrQGCGPS202203131707_B.Product_cm = fabs
    (px42LoopCtrQGCGPS202203131707_B.e_l);

  // Abs: '<S19>/Abs5'
  px42LoopCtrQGCGPS202203131707_B.roll =
    px42LoopCtrQGCGPS202203131707_B.Product_cm;

  // Saturate: '<S19>/Saturation'
  if (px42LoopCtrQGCGPS202203131707_B.e_l >
      px42LoopCtrQGCGPS202203131707_P.Saturation_UpperSat_b) {
    rtb_Fcn_tmp = px42LoopCtrQGCGPS202203131707_P.Saturation_UpperSat_b;
  } else if (px42LoopCtrQGCGPS202203131707_B.e_l <
             px42LoopCtrQGCGPS202203131707_P.Saturation_LowerSat_k) {
    rtb_Fcn_tmp = px42LoopCtrQGCGPS202203131707_P.Saturation_LowerSat_k;
  } else {
    rtb_Fcn_tmp = px42LoopCtrQGCGPS202203131707_B.e_l;
  }

  // End of Saturate: '<S19>/Saturation'

  // Gain: '<S19>/lambda1'
  px42LoopCtrQGCGPS202203131707_B.Add3 =
    px42LoopCtrQGCGPS202203131707_P.lambda1_Gain *
    px42LoopCtrQGCGPS202203131707_B.e_l;

  // Sum: '<S19>/Add7' incorporates:
  //   Constant: '<S19>/Constant1'
  //   Sum: '<S19>/Add13'
  //   Sum: '<S19>/Add18'

  px42LoopCtrQGCGPS202203131707_B.l2 =
    px42LoopCtrQGCGPS202203131707_P.Constant1_Value_f +
    px42LoopCtrQGCGPS202203131707_B.e_l;
  px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
    px42LoopCtrQGCGPS202203131707_B.l2;

  // Sum: '<S19>/Add6' incorporates:
  //   Constant: '<S19>/Constant1'
  //   Sum: '<S19>/Add12'
  //   Sum: '<S19>/Add17'

  px42LoopCtrQGCGPS202203131707_B.Product7 = px42LoopCtrQGCGPS202203131707_B.e_l
    - px42LoopCtrQGCGPS202203131707_P.Constant1_Value_f;

  // DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
  //   Sum: '<S19>/Add6'

  px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
    px42LoopCtrQGCGPS202203131707_B.Product7;

  // Saturate: '<S19>/Saturation10'
  if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k >
      px42LoopCtrQGCGPS202203131707_P.Saturation10_UpperSat) {
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
      px42LoopCtrQGCGPS202203131707_P.Saturation10_UpperSat;
  } else if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k <
             px42LoopCtrQGCGPS202203131707_P.Saturation10_LowerSat) {
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
      px42LoopCtrQGCGPS202203131707_P.Saturation10_LowerSat;
  }

  // End of Saturate: '<S19>/Saturation10'

  // Saturate: '<S19>/Saturation11'
  if (px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c >
      px42LoopCtrQGCGPS202203131707_P.Saturation11_UpperSat) {
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation11_UpperSat;
  } else if (px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c <
             px42LoopCtrQGCGPS202203131707_P.Saturation11_LowerSat) {
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation11_LowerSat;
  }

  // End of Saturate: '<S19>/Saturation11'

  // DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S19>/Gain'
  //   Sum: '<S19>/Add8'

  px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
    (px42LoopCtrQGCGPS202203131707_B.roll_hat_k -
     px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c) *
    px42LoopCtrQGCGPS202203131707_P.Gain_Gain_ml;

  // Fcn: '<S19>/Fcn3' incorporates:
  //   Constant: '<S19>/Constant1'

  if (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_f < 0.0) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = -rt_powd_snf
      (-px42LoopCtrQGCGPS202203131707_P.Constant1_Value_f, -0.5);
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = rt_powd_snf
      (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_f, -0.5);
  }

  // End of Fcn: '<S19>/Fcn3'

  // Product: '<S19>/Product3'
  px42LoopCtrQGCGPS202203131707_B.Product3 =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 *
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c *
    px42LoopCtrQGCGPS202203131707_B.e_l;

  // Saturate: '<S19>/Saturation8'
  if (px42LoopCtrQGCGPS202203131707_B.e_l >
      px42LoopCtrQGCGPS202203131707_P.Saturation8_UpperSat) {
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
      px42LoopCtrQGCGPS202203131707_P.Saturation8_UpperSat;
  } else if (px42LoopCtrQGCGPS202203131707_B.e_l <
             px42LoopCtrQGCGPS202203131707_P.Saturation8_LowerSat) {
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
      px42LoopCtrQGCGPS202203131707_P.Saturation8_LowerSat;
  } else {
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
      px42LoopCtrQGCGPS202203131707_B.e_l;
  }

  // End of Saturate: '<S19>/Saturation8'

  // Product: '<S19>/Product4' incorporates:
  //   Abs: '<S19>/Abs3'
  //   Constant: '<S19>/Constant2'
  //   Fcn: '<S19>/Fcn4'
  //   Sum: '<S19>/Add10'

  px42LoopCtrQGCGPS202203131707_B.Product4 = rt_powd_snf
    (px42LoopCtrQGCGPS202203131707_B.Product_cm, 0.5) *
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k *
    (px42LoopCtrQGCGPS202203131707_P.Constant2_Value -
     px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c);

  // DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
  //   Sum: '<S19>/Add13'

  px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
    px42LoopCtrQGCGPS202203131707_B.l2;

  // Sum: '<S19>/Add12'
  px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
    px42LoopCtrQGCGPS202203131707_B.Product7;

  // Saturate: '<S19>/Saturation13'
  if (px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c >
      px42LoopCtrQGCGPS202203131707_P.Saturation13_UpperSat) {
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation13_UpperSat;
  } else if (px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c <
             px42LoopCtrQGCGPS202203131707_P.Saturation13_LowerSat) {
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation13_LowerSat;
  }

  // End of Saturate: '<S19>/Saturation13'

  // Saturate: '<S19>/Saturation9'
  if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k >
      px42LoopCtrQGCGPS202203131707_P.Saturation9_UpperSat) {
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
      px42LoopCtrQGCGPS202203131707_P.Saturation9_UpperSat;
  } else if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k <
             px42LoopCtrQGCGPS202203131707_P.Saturation9_LowerSat) {
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
      px42LoopCtrQGCGPS202203131707_P.Saturation9_LowerSat;
  }

  // End of Saturate: '<S19>/Saturation9'

  // DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S19>/Gain1'
  //   Sum: '<S19>/Add14'

  px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
    (px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c -
     px42LoopCtrQGCGPS202203131707_B.roll_hat_k) *
    px42LoopCtrQGCGPS202203131707_P.Gain1_Gain_a;

  // Sum: '<S19>/Add11' incorporates:
  //   Constant: '<S19>/Constant4'

  px42LoopCtrQGCGPS202203131707_B.e_g =
    px42LoopCtrQGCGPS202203131707_P.Constant4_Value -
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c;

  // Fcn: '<S19>/Fcn6' incorporates:
  //   Constant: '<S19>/Constant1'

  if (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_f < 0.0) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = -rt_powd_snf
      (-px42LoopCtrQGCGPS202203131707_P.Constant1_Value_f, -0.9375);
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = rt_powd_snf
      (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_f, -0.9375);
  }

  // End of Fcn: '<S19>/Fcn6'

  // Product: '<S19>/Product6'
  px42LoopCtrQGCGPS202203131707_B.Product6 =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 *
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c *
    px42LoopCtrQGCGPS202203131707_B.e_l;

  // Saturate: '<S19>/Saturation12'
  if (px42LoopCtrQGCGPS202203131707_B.e_l >
      px42LoopCtrQGCGPS202203131707_P.Saturation12_UpperSat) {
    // DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation12_UpperSat;
  } else if (px42LoopCtrQGCGPS202203131707_B.e_l <
             px42LoopCtrQGCGPS202203131707_P.Saturation12_LowerSat) {
    // DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation12_LowerSat;
  } else {
    // DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
      px42LoopCtrQGCGPS202203131707_B.e_l;
  }

  // End of Saturate: '<S19>/Saturation12'

  // Product: '<S19>/Product5' incorporates:
  //   Fcn: '<S19>/Fcn5'

  px42LoopCtrQGCGPS202203131707_B.e_g *= rt_powd_snf
    (px42LoopCtrQGCGPS202203131707_B.Product_cm, 0.0625) *
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c;

  // DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
  //   Sum: '<S19>/Add18'

  px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
    px42LoopCtrQGCGPS202203131707_B.l2;

  // Sum: '<S19>/Add17'
  px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
    px42LoopCtrQGCGPS202203131707_B.Product7;

  // Saturate: '<S19>/Saturation16'
  if (px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c >
      px42LoopCtrQGCGPS202203131707_P.Saturation16_UpperSat) {
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation16_UpperSat;
  } else if (px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c <
             px42LoopCtrQGCGPS202203131707_P.Saturation16_LowerSat) {
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation16_LowerSat;
  }

  // End of Saturate: '<S19>/Saturation16'

  // Saturate: '<S19>/Saturation14'
  if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k >
      px42LoopCtrQGCGPS202203131707_P.Saturation14_UpperSat) {
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
      px42LoopCtrQGCGPS202203131707_P.Saturation14_UpperSat;
  } else if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k <
             px42LoopCtrQGCGPS202203131707_P.Saturation14_LowerSat) {
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
      px42LoopCtrQGCGPS202203131707_P.Saturation14_LowerSat;
  }

  // End of Saturate: '<S19>/Saturation14'

  // DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S19>/Gain3'
  //   Sum: '<S19>/Add19'

  px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
    (px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c -
     px42LoopCtrQGCGPS202203131707_B.roll_hat_k) *
    px42LoopCtrQGCGPS202203131707_P.Gain3_Gain;

  // Sum: '<S19>/Add16' incorporates:
  //   Constant: '<S19>/Constant6'

  px42LoopCtrQGCGPS202203131707_B.Product_cm =
    px42LoopCtrQGCGPS202203131707_P.Constant6_Value -
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c;

  // Saturate: '<S19>/Saturation1'
  if (px42LoopCtrQGCGPS202203131707_B.e_l >
      px42LoopCtrQGCGPS202203131707_P.Saturation1_UpperSat) {
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
      px42LoopCtrQGCGPS202203131707_P.Saturation1_UpperSat;
  } else if (px42LoopCtrQGCGPS202203131707_B.e_l <
             px42LoopCtrQGCGPS202203131707_P.Saturation1_LowerSat) {
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
      px42LoopCtrQGCGPS202203131707_P.Saturation1_LowerSat;
  } else {
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
      px42LoopCtrQGCGPS202203131707_B.e_l;
  }

  // End of Saturate: '<S19>/Saturation1'

  // Gain: '<S19>/l2'
  px42LoopCtrQGCGPS202203131707_B.l2 = px42LoopCtrQGCGPS202203131707_P.l2_Gain *
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k;

  // Sum: '<S19>/Add3'
  px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 -
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1;

  // Fcn: '<S19>/Fcn7' incorporates:
  //   Constant: '<S19>/Constant1'

  if (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_f < 0.0) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = -rt_powd_snf
      (-px42LoopCtrQGCGPS202203131707_P.Constant1_Value_f, -0.75);
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = rt_powd_snf
      (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_f, -0.75);
  }

  // End of Fcn: '<S19>/Fcn7'

  // Product: '<S19>/Product7'
  px42LoopCtrQGCGPS202203131707_B.Product7 =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 *
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c *
    px42LoopCtrQGCGPS202203131707_B.e_l;

  // Saturate: '<S19>/Saturation15'
  if (px42LoopCtrQGCGPS202203131707_B.e_l >
      px42LoopCtrQGCGPS202203131707_P.Saturation15_UpperSat) {
    // DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation15_UpperSat;
  } else if (px42LoopCtrQGCGPS202203131707_B.e_l <
             px42LoopCtrQGCGPS202203131707_P.Saturation15_LowerSat) {
    // DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation15_LowerSat;
  } else {
    // DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
      px42LoopCtrQGCGPS202203131707_B.e_l;
  }

  // End of Saturate: '<S19>/Saturation15'

  // Sum: '<S19>/Add2' incorporates:
  //   DiscreteIntegrator: '<S19>/Discrete-Time Integrator3'
  //   Fcn: '<S19>/Fcn8'
  //   Gain: '<S19>/Gain6'
  //   Gain: '<S19>/lambda2'
  //   Product: '<S19>/Product8'
  //   Sum: '<S19>/Add20'

  px42LoopCtrQGCGPS202203131707_B.l2 =
    (((px42LoopCtrQGCGPS202203131707_P.lambda2_Gain *
       px42LoopCtrQGCGPS202203131707_B.e_l + px42LoopCtrQGCGPS202203131707_B.l2)
      + px42LoopCtrQGCGPS202203131707_B.roll_hat_k) +
     px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator3_DSTATE) +
    (rt_powd_snf(px42LoopCtrQGCGPS202203131707_B.roll, 0.25) *
     px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c *
     px42LoopCtrQGCGPS202203131707_B.Product_cm +
     px42LoopCtrQGCGPS202203131707_B.Product7) *
    px42LoopCtrQGCGPS202203131707_P.Gain6_Gain;

  // Saturate: '<S19>/Saturation3'
  if (px42LoopCtrQGCGPS202203131707_B.e_l >
      px42LoopCtrQGCGPS202203131707_P.Saturation3_UpperSat) {
    // DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation3_UpperSat;
  } else if (px42LoopCtrQGCGPS202203131707_B.e_l <
             px42LoopCtrQGCGPS202203131707_P.Saturation3_LowerSat) {
    // DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation3_LowerSat;
  } else {
    // DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
      px42LoopCtrQGCGPS202203131707_B.e_l;
  }

  // End of Saturate: '<S19>/Saturation3'

  // Gain: '<S19>/l4'
  px42LoopCtrQGCGPS202203131707_B.l4 = px42LoopCtrQGCGPS202203131707_P.l4_Gain *
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c;

  // Gain: '<S19>/lambda4'
  px42LoopCtrQGCGPS202203131707_B.lambda4 =
    px42LoopCtrQGCGPS202203131707_P.lambda4_Gain *
    px42LoopCtrQGCGPS202203131707_B.e_l;

  // DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
  px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c =
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE_p;

  // Gain: '<S17>/Gain2'
  px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
    px42LoopCtrQGCGPS202203131707_P.Gain2_Gain_g *
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c;

  // ZeroOrderHold: '<S17>/Zero-Order Hold3' incorporates:
  //   DataStoreWrite: '<Root>/Data Store Write12'
  //   Gain: '<S17>/1//J'

  px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
    px42LoopCtrQGCGPS202203131707_P.uJ_Gain_p *
    px42LoopCtrQGCGPS202203131707_B.z2_e;

  // ZeroOrderHold: '<S17>/Zero-Order Hold2' incorporates:
  //   DataStoreRead: '<S17>/Data Store Read1'
  //   Gain: '<S17>/k//J'

  px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
    px42LoopCtrQGCGPS202203131707_P.kJ_Gain_c *
    px42LoopCtrQGCGPS20220313170_DW.pitch_speed;

  // ZeroOrderHold: '<S17>/Zero-Order Hold1' incorporates:
  //   DataStoreRead: '<S17>/Data Store Read'

  px42LoopCtrQGCGPS202203131707_B.roll = px42LoopCtrQGCGPS20220313170_DW.pitch;

  // Switch: '<S17>/Switch' incorporates:
  //   Constant: '<S17>/Constant3'
  //   DataStoreRead: '<S17>/Data Store Read2'

  if (px42LoopCtrQGCGPS20220313170_DW.observer_flag) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 =
      px42LoopCtrQGCGPS202203131707_B.roll_hat_k;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;
    px42LoopCtrQGCGPS202203131707_B.e_l = px42LoopCtrQGCGPS202203131707_B.roll;
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 =
      px42LoopCtrQGCGPS202203131707_P.Constant3_Value_f;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS202203131707_P.Constant3_Value_f;
    px42LoopCtrQGCGPS202203131707_B.e_l =
      px42LoopCtrQGCGPS202203131707_P.Constant3_Value_f;
  }

  // End of Switch: '<S17>/Switch'

  // Sum: '<S17>/Add1'
  px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
    px42LoopCtrQGCGPS202203131707_B.e_l -
    px42LoopCtrQGCGPS202203131707_B.rtb_roll_hat_e_c;

  // Abs: '<S17>/Abs3' incorporates:
  //   Abs: '<S17>/Abs4'
  //   Abs: '<S17>/Abs5'
  //   Abs: '<S17>/Abs6'

  px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f = fabs
    (px42LoopCtrQGCGPS202203131707_B.roll_hat_k);

  // Abs: '<S17>/Abs4'
  px42LoopCtrQGCGPS202203131707_B.roll =
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;

  // Abs: '<S17>/Abs5'
  px42LoopCtrQGCGPS202203131707_B.e_l =
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;

  // Saturate: '<S17>/Saturation'
  if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k >
      px42LoopCtrQGCGPS202203131707_P.Saturation_UpperSat_n) {
    px42LoopCtrQGCGPS202203131707_B.Product_cm =
      px42LoopCtrQGCGPS202203131707_P.Saturation_UpperSat_n;
  } else if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k <
             px42LoopCtrQGCGPS202203131707_P.Saturation_LowerSat_g) {
    px42LoopCtrQGCGPS202203131707_B.Product_cm =
      px42LoopCtrQGCGPS202203131707_P.Saturation_LowerSat_g;
  } else {
    px42LoopCtrQGCGPS202203131707_B.Product_cm =
      px42LoopCtrQGCGPS202203131707_B.roll_hat_k;
  }

  // End of Saturate: '<S17>/Saturation'

  // Gain: '<S17>/l1'
  px42LoopCtrQGCGPS202203131707_B.Product7 =
    px42LoopCtrQGCGPS202203131707_P.l1_Gain_p *
    px42LoopCtrQGCGPS202203131707_B.Product_cm;

  // Gain: '<S17>/lambda1'
  px42LoopCtrQGCGPS202203131707_B.lambda1_a =
    px42LoopCtrQGCGPS202203131707_P.lambda1_Gain_a *
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k;

  // DiscreteIntegrator: '<S17>/Discrete-Time Integrator1'
  px42LoopCtrQGCGPS202203131707_B.Product_cm =
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator1_DSTAT_i;

  // Sum: '<S17>/Add7' incorporates:
  //   Constant: '<S17>/Constant1'
  //   Sum: '<S17>/Add13'
  //   Sum: '<S17>/Add18'

  px42LoopCtrQGCGPS202203131707_B.l2_j =
    px42LoopCtrQGCGPS202203131707_P.Constant1_Value_j +
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k;
  px42LoopCtrQGCGPS202203131707_B.yaw = px42LoopCtrQGCGPS202203131707_B.l2_j;

  // Sum: '<S17>/Add6' incorporates:
  //   Constant: '<S17>/Constant1'
  //   Sum: '<S17>/Add12'
  //   Sum: '<S17>/Add17'

  px42LoopCtrQGCGPS202203131707_B.z1_i =
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k -
    px42LoopCtrQGCGPS202203131707_P.Constant1_Value_j;

  // Saturate: '<S17>/Saturation10'
  if (px42LoopCtrQGCGPS202203131707_B.yaw >
      px42LoopCtrQGCGPS202203131707_P.Saturation10_UpperSat_o) {
    px42LoopCtrQGCGPS202203131707_B.yaw =
      px42LoopCtrQGCGPS202203131707_P.Saturation10_UpperSat_o;
  } else if (px42LoopCtrQGCGPS202203131707_B.yaw <
             px42LoopCtrQGCGPS202203131707_P.Saturation10_LowerSat_b) {
    px42LoopCtrQGCGPS202203131707_B.yaw =
      px42LoopCtrQGCGPS202203131707_P.Saturation10_LowerSat_b;
  }

  // End of Saturate: '<S17>/Saturation10'

  // Saturate: '<S17>/Saturation11'
  if (px42LoopCtrQGCGPS202203131707_B.z1_i >
      px42LoopCtrQGCGPS202203131707_P.Saturation11_UpperSat_p) {
    px42LoopCtrQGCGPS202203131707_B.Product3_a =
      px42LoopCtrQGCGPS202203131707_P.Saturation11_UpperSat_p;
  } else if (px42LoopCtrQGCGPS202203131707_B.z1_i <
             px42LoopCtrQGCGPS202203131707_P.Saturation11_LowerSat_i) {
    px42LoopCtrQGCGPS202203131707_B.Product3_a =
      px42LoopCtrQGCGPS202203131707_P.Saturation11_LowerSat_i;
  } else {
    px42LoopCtrQGCGPS202203131707_B.Product3_a =
      px42LoopCtrQGCGPS202203131707_B.z1_i;
  }

  // End of Saturate: '<S17>/Saturation11'

  // Gain: '<S17>/Gain' incorporates:
  //   Sum: '<S17>/Add8'

  px42LoopCtrQGCGPS202203131707_B.yaw = (px42LoopCtrQGCGPS202203131707_B.yaw -
    px42LoopCtrQGCGPS202203131707_B.Product3_a) *
    px42LoopCtrQGCGPS202203131707_P.Gain_Gain_g;

  // Fcn: '<S17>/Fcn3' incorporates:
  //   Constant: '<S17>/Constant1'

  if (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_j < 0.0) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = -rt_powd_snf
      (-px42LoopCtrQGCGPS202203131707_P.Constant1_Value_j, -0.5);
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = rt_powd_snf
      (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_j, -0.5);
  }

  // End of Fcn: '<S17>/Fcn3'

  // Product: '<S17>/Product3'
  px42LoopCtrQGCGPS202203131707_B.Product3_a =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 *
    px42LoopCtrQGCGPS202203131707_B.yaw *
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k;

  // Fcn: '<S17>/Fcn4'
  px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = rt_powd_snf
    (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f, 0.5);

  // Saturate: '<S17>/Saturation8'
  if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k >
      px42LoopCtrQGCGPS202203131707_P.Saturation8_UpperSat_g) {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_P.Saturation8_UpperSat_g;
  } else if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k <
             px42LoopCtrQGCGPS202203131707_P.Saturation8_LowerSat_g) {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_P.Saturation8_LowerSat_g;
  } else {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_B.roll_hat_k;
  }

  // End of Saturate: '<S17>/Saturation8'

  // Product: '<S17>/Product4' incorporates:
  //   Constant: '<S17>/Constant2'
  //   Fcn: '<S17>/Fcn4'
  //   Sum: '<S17>/Add10'

  px42LoopCtrQGCGPS202203131707_B.Product4_k =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 *
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f *
    (px42LoopCtrQGCGPS202203131707_P.Constant2_Value_h -
     px42LoopCtrQGCGPS202203131707_B.yaw);

  // Sum: '<S17>/Add13'
  px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
    px42LoopCtrQGCGPS202203131707_B.l2_j;

  // Sum: '<S17>/Add12'
  px42LoopCtrQGCGPS202203131707_B.yaw = px42LoopCtrQGCGPS202203131707_B.z1_i;

  // Saturate: '<S17>/Saturation13'
  if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f >
      px42LoopCtrQGCGPS202203131707_P.Saturation13_UpperSat_i) {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_P.Saturation13_UpperSat_i;
  } else if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f <
             px42LoopCtrQGCGPS202203131707_P.Saturation13_LowerSat_c) {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_P.Saturation13_LowerSat_c;
  }

  // End of Saturate: '<S17>/Saturation13'

  // Saturate: '<S17>/Saturation9'
  if (px42LoopCtrQGCGPS202203131707_B.yaw >
      px42LoopCtrQGCGPS202203131707_P.Saturation9_UpperSat_i) {
    px42LoopCtrQGCGPS202203131707_B.yaw =
      px42LoopCtrQGCGPS202203131707_P.Saturation9_UpperSat_i;
  } else if (px42LoopCtrQGCGPS202203131707_B.yaw <
             px42LoopCtrQGCGPS202203131707_P.Saturation9_LowerSat_c) {
    px42LoopCtrQGCGPS202203131707_B.yaw =
      px42LoopCtrQGCGPS202203131707_P.Saturation9_LowerSat_c;
  }

  // End of Saturate: '<S17>/Saturation9'

  // Gain: '<S17>/Gain1' incorporates:
  //   Sum: '<S17>/Add14'

  px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
    (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f -
     px42LoopCtrQGCGPS202203131707_B.yaw) *
    px42LoopCtrQGCGPS202203131707_P.Gain1_Gain_d;

  // Sum: '<S17>/Add11' incorporates:
  //   Constant: '<S17>/Constant4'

  px42LoopCtrQGCGPS202203131707_B.e_gq =
    px42LoopCtrQGCGPS202203131707_P.Constant4_Value_n -
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;

  // Fcn: '<S17>/Fcn6' incorporates:
  //   Constant: '<S17>/Constant1'

  if (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_j < 0.0) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = -rt_powd_snf
      (-px42LoopCtrQGCGPS202203131707_P.Constant1_Value_j, -0.9375);
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = rt_powd_snf
      (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_j, -0.9375);
  }

  // End of Fcn: '<S17>/Fcn6'

  // Product: '<S17>/Product6'
  px42LoopCtrQGCGPS202203131707_B.Product6_i =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 *
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f *
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k;

  // Saturate: '<S17>/Saturation12'
  if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k >
      px42LoopCtrQGCGPS202203131707_P.Saturation12_UpperSat_c) {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_P.Saturation12_UpperSat_c;
  } else if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k <
             px42LoopCtrQGCGPS202203131707_P.Saturation12_LowerSat_b) {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_P.Saturation12_LowerSat_b;
  } else {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_B.roll_hat_k;
  }

  // End of Saturate: '<S17>/Saturation12'

  // Product: '<S17>/Product5' incorporates:
  //   Fcn: '<S17>/Fcn5'

  px42LoopCtrQGCGPS202203131707_B.e_gq *= rt_powd_snf
    (px42LoopCtrQGCGPS202203131707_B.roll, 0.0625) *
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;

  // Sum: '<S17>/Add18'
  px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
    px42LoopCtrQGCGPS202203131707_B.l2_j;

  // Sum: '<S17>/Add17'
  px42LoopCtrQGCGPS202203131707_B.roll = px42LoopCtrQGCGPS202203131707_B.z1_i;

  // Saturate: '<S17>/Saturation16'
  if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f >
      px42LoopCtrQGCGPS202203131707_P.Saturation16_UpperSat_l) {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_P.Saturation16_UpperSat_l;
  } else if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f <
             px42LoopCtrQGCGPS202203131707_P.Saturation16_LowerSat_g) {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_P.Saturation16_LowerSat_g;
  }

  // End of Saturate: '<S17>/Saturation16'

  // Saturate: '<S17>/Saturation14'
  if (px42LoopCtrQGCGPS202203131707_B.roll >
      px42LoopCtrQGCGPS202203131707_P.Saturation14_UpperSat_l) {
    px42LoopCtrQGCGPS202203131707_B.roll =
      px42LoopCtrQGCGPS202203131707_P.Saturation14_UpperSat_l;
  } else if (px42LoopCtrQGCGPS202203131707_B.roll <
             px42LoopCtrQGCGPS202203131707_P.Saturation14_LowerSat_b) {
    px42LoopCtrQGCGPS202203131707_B.roll =
      px42LoopCtrQGCGPS202203131707_P.Saturation14_LowerSat_b;
  }

  // End of Saturate: '<S17>/Saturation14'

  // Gain: '<S17>/Gain3' incorporates:
  //   Sum: '<S17>/Add19'

  px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
    (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f -
     px42LoopCtrQGCGPS202203131707_B.roll) *
    px42LoopCtrQGCGPS202203131707_P.Gain3_Gain_l;

  // Sum: '<S17>/Add16' incorporates:
  //   Constant: '<S17>/Constant6'

  px42LoopCtrQGCGPS202203131707_B.z1_i =
    px42LoopCtrQGCGPS202203131707_P.Constant6_Value_o -
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;

  // Saturate: '<S17>/Saturation1'
  if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k >
      px42LoopCtrQGCGPS202203131707_P.Saturation1_UpperSat_a) {
    px42LoopCtrQGCGPS202203131707_B.roll =
      px42LoopCtrQGCGPS202203131707_P.Saturation1_UpperSat_a;
  } else if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k <
             px42LoopCtrQGCGPS202203131707_P.Saturation1_LowerSat_i) {
    px42LoopCtrQGCGPS202203131707_B.roll =
      px42LoopCtrQGCGPS202203131707_P.Saturation1_LowerSat_i;
  } else {
    px42LoopCtrQGCGPS202203131707_B.roll =
      px42LoopCtrQGCGPS202203131707_B.roll_hat_k;
  }

  // End of Saturate: '<S17>/Saturation1'

  // Gain: '<S17>/l2'
  px42LoopCtrQGCGPS202203131707_B.l2_j =
    px42LoopCtrQGCGPS202203131707_P.l2_Gain_l *
    px42LoopCtrQGCGPS202203131707_B.roll;

  // Sum: '<S17>/Add3'
  px42LoopCtrQGCGPS202203131707_B.roll =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 -
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1;

  // Fcn: '<S17>/Fcn7' incorporates:
  //   Constant: '<S17>/Constant1'

  if (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_j < 0.0) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = -rt_powd_snf
      (-px42LoopCtrQGCGPS202203131707_P.Constant1_Value_j, -0.75);
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = rt_powd_snf
      (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_j, -0.75);
  }

  // End of Fcn: '<S17>/Fcn7'

  // Product: '<S17>/Product7'
  px42LoopCtrQGCGPS202203131707_B.Product7_e =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 *
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f *
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k;

  // Saturate: '<S17>/Saturation15'
  if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k >
      px42LoopCtrQGCGPS202203131707_P.Saturation15_UpperSat_j) {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_P.Saturation15_UpperSat_j;
  } else if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k <
             px42LoopCtrQGCGPS202203131707_P.Saturation15_LowerSat_k) {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_P.Saturation15_LowerSat_k;
  } else {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_B.roll_hat_k;
  }

  // End of Saturate: '<S17>/Saturation15'

  // Sum: '<S17>/Add2' incorporates:
  //   DiscreteIntegrator: '<S17>/Discrete-Time Integrator3'
  //   Fcn: '<S17>/Fcn8'
  //   Gain: '<S17>/Gain6'
  //   Gain: '<S17>/lambda2'
  //   Product: '<S17>/Product8'
  //   Sum: '<S17>/Add20'

  px42LoopCtrQGCGPS202203131707_B.l2_j =
    (((px42LoopCtrQGCGPS202203131707_P.lambda2_Gain_j *
       px42LoopCtrQGCGPS202203131707_B.roll_hat_k +
       px42LoopCtrQGCGPS202203131707_B.l2_j) +
      px42LoopCtrQGCGPS202203131707_B.roll) +
     px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator3_DSTAT_a) +
    (rt_powd_snf(px42LoopCtrQGCGPS202203131707_B.e_l, 0.25) *
     px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f *
     px42LoopCtrQGCGPS202203131707_B.z1_i +
     px42LoopCtrQGCGPS202203131707_B.Product7_e) *
    px42LoopCtrQGCGPS202203131707_P.Gain6_Gain_e;

  // Saturate: '<S17>/Saturation3'
  if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k >
      px42LoopCtrQGCGPS202203131707_P.Saturation3_UpperSat_m) {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_P.Saturation3_UpperSat_m;
  } else if (px42LoopCtrQGCGPS202203131707_B.roll_hat_k <
             px42LoopCtrQGCGPS202203131707_P.Saturation3_LowerSat_i) {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_P.Saturation3_LowerSat_i;
  } else {
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
      px42LoopCtrQGCGPS202203131707_B.roll_hat_k;
  }

  // End of Saturate: '<S17>/Saturation3'

  // Gain: '<S17>/l4'
  px42LoopCtrQGCGPS202203131707_B.Product7_e =
    px42LoopCtrQGCGPS202203131707_P.l4_Gain_p *
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;

  // Gain: '<S17>/lambda4'
  px42LoopCtrQGCGPS202203131707_B.lambda4_n =
    px42LoopCtrQGCGPS202203131707_P.lambda4_Gain_a *
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k;

  // DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
  px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE_f;

  // Gain: '<S18>/Gain2'
  px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
    px42LoopCtrQGCGPS202203131707_P.Gain2_Gain_p *
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k;

  // ZeroOrderHold: '<S18>/Zero-Order Hold3' incorporates:
  //   DataStoreWrite: '<Root>/Data Store Write13'
  //   Gain: '<S18>/1//J'

  px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
    px42LoopCtrQGCGPS202203131707_P.uJ_Gain_g *
    px42LoopCtrQGCGPS202203131707_B.z2_l;

  // ZeroOrderHold: '<S18>/Zero-Order Hold2' incorporates:
  //   DataStoreRead: '<S18>/Data Store Read1'
  //   Gain: '<S18>/k//J'

  px42LoopCtrQGCGPS202203131707_B.roll =
    px42LoopCtrQGCGPS202203131707_P.kJ_Gain_p *
    px42LoopCtrQGCGPS20220313170_DW.roll_speed;

  // ZeroOrderHold: '<S18>/Zero-Order Hold1' incorporates:
  //   DataStoreRead: '<S18>/Data Store Read'

  px42LoopCtrQGCGPS202203131707_B.e_l = px42LoopCtrQGCGPS20220313170_DW.roll;

  // Switch: '<S18>/Switch' incorporates:
  //   Constant: '<S18>/Constant3'
  //   DataStoreRead: '<S18>/Data Store Read2'

  if (px42LoopCtrQGCGPS20220313170_DW.observer_flag) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 =
      px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS202203131707_B.roll;
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 =
      px42LoopCtrQGCGPS202203131707_P.Constant3_Value_a;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS202203131707_P.Constant3_Value_a;
    px42LoopCtrQGCGPS202203131707_B.e_l =
      px42LoopCtrQGCGPS202203131707_P.Constant3_Value_a;
  }

  // End of Switch: '<S18>/Switch'

  // Sum: '<S18>/Add1'
  px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
    px42LoopCtrQGCGPS202203131707_B.e_l -
    px42LoopCtrQGCGPS202203131707_B.roll_hat_k;

  // Abs: '<S18>/Abs3' incorporates:
  //   Abs: '<S18>/Abs4'
  //   Abs: '<S18>/Abs5'
  //   Abs: '<S18>/Abs6'

  px42LoopCtrQGCGPS202203131707_B.roll = fabs
    (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f);

  // Abs: '<S18>/Abs4'
  px42LoopCtrQGCGPS202203131707_B.e_l = px42LoopCtrQGCGPS202203131707_B.roll;

  // Saturate: '<S18>/Saturation'
  if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f >
      px42LoopCtrQGCGPS202203131707_P.Saturation_UpperSat_n1) {
    px42LoopCtrQGCGPS202203131707_B.z1_i =
      px42LoopCtrQGCGPS202203131707_P.Saturation_UpperSat_n1;
  } else if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f <
             px42LoopCtrQGCGPS202203131707_P.Saturation_LowerSat_c) {
    px42LoopCtrQGCGPS202203131707_B.z1_i =
      px42LoopCtrQGCGPS202203131707_P.Saturation_LowerSat_c;
  } else {
    px42LoopCtrQGCGPS202203131707_B.z1_i =
      px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;
  }

  // End of Saturate: '<S18>/Saturation'

  // Gain: '<S18>/l1'
  px42LoopCtrQGCGPS202203131707_B.roll_hat_k =
    px42LoopCtrQGCGPS202203131707_P.l1_Gain_d *
    px42LoopCtrQGCGPS202203131707_B.z1_i;

  // Gain: '<S18>/lambda1'
  px42LoopCtrQGCGPS202203131707_B.lambda1_e =
    px42LoopCtrQGCGPS202203131707_P.lambda1_Gain_g *
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;

  // DiscreteIntegrator: '<S18>/Discrete-Time Integrator1'
  px42LoopCtrQGCGPS202203131707_B.z1_i =
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator1_DSTAT_g;

  // Sum: '<S18>/Add7' incorporates:
  //   Constant: '<S18>/Constant1'
  //   Sum: '<S18>/Add13'
  //   Sum: '<S18>/Add18'

  px42LoopCtrQGCGPS202203131707_B.yaw =
    px42LoopCtrQGCGPS202203131707_P.Constant1_Value_ac +
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   Sum: '<S18>/Add7'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
    px42LoopCtrQGCGPS202203131707_B.yaw;

  // Sum: '<S18>/Add6' incorporates:
  //   Constant: '<S18>/Constant1'
  //   Sum: '<S18>/Add12'
  //   Sum: '<S18>/Add17'

  px42LoopCtrQGCGPS202203131707_B.l4_k =
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f -
    px42LoopCtrQGCGPS202203131707_P.Constant1_Value_ac;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Sum: '<S18>/Add6'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
    px42LoopCtrQGCGPS202203131707_B.l4_k;

  // Saturate: '<S18>/Saturation10'
  if (px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c >
      px42LoopCtrQGCGPS202203131707_P.Saturation10_UpperSat_a) {
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation10_UpperSat_a;
  } else if (px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c <
             px42LoopCtrQGCGPS202203131707_P.Saturation10_LowerSat_l) {
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation10_LowerSat_l;
  }

  // End of Saturate: '<S18>/Saturation10'

  // Saturate: '<S18>/Saturation11'
  if (px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p >
      px42LoopCtrQGCGPS202203131707_P.Saturation11_UpperSat_a) {
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_P.Saturation11_UpperSat_a;
  } else if (px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p <
             px42LoopCtrQGCGPS202203131707_P.Saturation11_LowerSat_a) {
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_P.Saturation11_LowerSat_a;
  }

  // End of Saturate: '<S18>/Saturation11'

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Gain: '<S18>/Gain'
  //   Sum: '<S18>/Add8'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
    (px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c -
     px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p) *
    px42LoopCtrQGCGPS202203131707_P.Gain_Gain_h;

  // Fcn: '<S18>/Fcn3' incorporates:
  //   Constant: '<S18>/Constant1'

  if (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_ac < 0.0) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = -rt_powd_snf
      (-px42LoopCtrQGCGPS202203131707_P.Constant1_Value_ac, -0.5);
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = rt_powd_snf
      (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_ac, -0.5);
  }

  // End of Fcn: '<S18>/Fcn3'

  // Product: '<S18>/Product3'
  px42LoopCtrQGCGPS202203131707_B.Product3_c =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 *
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p *
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;

  // Saturate: '<S18>/Saturation8'
  if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f >
      px42LoopCtrQGCGPS202203131707_P.Saturation8_UpperSat_c) {
    // DataStoreRead: '<Root>/Data Store Read49'
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation8_UpperSat_c;
  } else if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f <
             px42LoopCtrQGCGPS202203131707_P.Saturation8_LowerSat_c) {
    // DataStoreRead: '<Root>/Data Store Read49'
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation8_LowerSat_c;
  } else {
    // DataStoreRead: '<Root>/Data Store Read49'
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
      px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;
  }

  // End of Saturate: '<S18>/Saturation8'

  // Product: '<S18>/Product4' incorporates:
  //   Constant: '<S18>/Constant2'
  //   Fcn: '<S18>/Fcn4'
  //   Sum: '<S18>/Add10'

  px42LoopCtrQGCGPS202203131707_B.Product4_g = rt_powd_snf
    (px42LoopCtrQGCGPS202203131707_B.roll, 0.5) *
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c *
    (px42LoopCtrQGCGPS202203131707_P.Constant2_Value_k -
     px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p);

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Sum: '<S18>/Add13'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
    px42LoopCtrQGCGPS202203131707_B.yaw;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   Sum: '<S18>/Add12'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
    px42LoopCtrQGCGPS202203131707_B.l4_k;

  // Saturate: '<S18>/Saturation13'
  if (px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p >
      px42LoopCtrQGCGPS202203131707_P.Saturation13_UpperSat_p) {
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_P.Saturation13_UpperSat_p;
  } else if (px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p <
             px42LoopCtrQGCGPS202203131707_P.Saturation13_LowerSat_j) {
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_P.Saturation13_LowerSat_j;
  }

  // End of Saturate: '<S18>/Saturation13'

  // Saturate: '<S18>/Saturation9'
  if (px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c >
      px42LoopCtrQGCGPS202203131707_P.Saturation9_UpperSat_d) {
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation9_UpperSat_d;
  } else if (px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c <
             px42LoopCtrQGCGPS202203131707_P.Saturation9_LowerSat_c4) {
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation9_LowerSat_c4;
  }

  // End of Saturate: '<S18>/Saturation9'

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Gain: '<S18>/Gain1'
  //   Sum: '<S18>/Add14'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
    (px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p -
     px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c) *
    px42LoopCtrQGCGPS202203131707_P.Gain1_Gain_e;

  // Sum: '<S18>/Add11' incorporates:
  //   Constant: '<S18>/Constant4'

  px42LoopCtrQGCGPS202203131707_B.e_e1 =
    px42LoopCtrQGCGPS202203131707_P.Constant4_Value_l -
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p;

  // Fcn: '<S18>/Fcn6' incorporates:
  //   Constant: '<S18>/Constant1'

  if (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_ac < 0.0) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = -rt_powd_snf
      (-px42LoopCtrQGCGPS202203131707_P.Constant1_Value_ac, -0.9375);
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = rt_powd_snf
      (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_ac, -0.9375);
  }

  // End of Fcn: '<S18>/Fcn6'

  // Product: '<S18>/Product6'
  px42LoopCtrQGCGPS202203131707_B.Product6_a =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 *
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p *
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;

  // Saturate: '<S18>/Saturation12'
  if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f >
      px42LoopCtrQGCGPS202203131707_P.Saturation12_UpperSat_d) {
    // DataStoreRead: '<Root>/Data Store Read48'
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_P.Saturation12_UpperSat_d;
  } else if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f <
             px42LoopCtrQGCGPS202203131707_P.Saturation12_LowerSat_j) {
    // DataStoreRead: '<Root>/Data Store Read48'
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_P.Saturation12_LowerSat_j;
  } else {
    // DataStoreRead: '<Root>/Data Store Read48'
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;
  }

  // End of Saturate: '<S18>/Saturation12'

  // Product: '<S18>/Product5' incorporates:
  //   Fcn: '<S18>/Fcn5'

  px42LoopCtrQGCGPS202203131707_B.e_e1 *= rt_powd_snf
    (px42LoopCtrQGCGPS202203131707_B.e_l, 0.0625) *
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Sum: '<S18>/Add18'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
    px42LoopCtrQGCGPS202203131707_B.yaw;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   Sum: '<S18>/Add17'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
    px42LoopCtrQGCGPS202203131707_B.l4_k;

  // Saturate: '<S18>/Saturation16'
  if (px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p >
      px42LoopCtrQGCGPS202203131707_P.Saturation16_UpperSat_p) {
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_P.Saturation16_UpperSat_p;
  } else if (px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p <
             px42LoopCtrQGCGPS202203131707_P.Saturation16_LowerSat_i) {
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_P.Saturation16_LowerSat_i;
  }

  // End of Saturate: '<S18>/Saturation16'

  // Saturate: '<S18>/Saturation14'
  if (px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c >
      px42LoopCtrQGCGPS202203131707_P.Saturation14_UpperSat_n) {
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation14_UpperSat_n;
  } else if (px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c <
             px42LoopCtrQGCGPS202203131707_P.Saturation14_LowerSat_a) {
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation14_LowerSat_a;
  }

  // End of Saturate: '<S18>/Saturation14'

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Gain: '<S18>/Gain3'
  //   Sum: '<S18>/Add19'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
    (px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p -
     px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c) *
    px42LoopCtrQGCGPS202203131707_P.Gain3_Gain_p;

  // Sum: '<S18>/Add16' incorporates:
  //   Constant: '<S18>/Constant6'

  px42LoopCtrQGCGPS202203131707_B.e_l =
    px42LoopCtrQGCGPS202203131707_P.Constant6_Value_g -
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p;

  // Saturate: '<S18>/Saturation1'
  if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f >
      px42LoopCtrQGCGPS202203131707_P.Saturation1_UpperSat_d) {
    // DataStoreRead: '<Root>/Data Store Read49'
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation1_UpperSat_d;
  } else if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f <
             px42LoopCtrQGCGPS202203131707_P.Saturation1_LowerSat_g) {
    // DataStoreRead: '<Root>/Data Store Read49'
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
      px42LoopCtrQGCGPS202203131707_P.Saturation1_LowerSat_g;
  } else {
    // DataStoreRead: '<Root>/Data Store Read49'
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
      px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;
  }

  // End of Saturate: '<S18>/Saturation1'

  // Gain: '<S18>/l2'
  px42LoopCtrQGCGPS202203131707_B.yaw =
    px42LoopCtrQGCGPS202203131707_P.l2_Gain_i *
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   Sum: '<S18>/Add3'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 -
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1;

  // Fcn: '<S18>/Fcn7' incorporates:
  //   Constant: '<S18>/Constant1'

  if (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_ac < 0.0) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = -rt_powd_snf
      (-px42LoopCtrQGCGPS202203131707_P.Constant1_Value_ac, -0.75);
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = rt_powd_snf
      (px42LoopCtrQGCGPS202203131707_P.Constant1_Value_ac, -0.75);
  }

  // End of Fcn: '<S18>/Fcn7'

  // Product: '<S18>/Product7'
  px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 *
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p *
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;

  // Saturate: '<S18>/Saturation15'
  if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f >
      px42LoopCtrQGCGPS202203131707_P.Saturation15_UpperSat_k) {
    // DataStoreRead: '<Root>/Data Store Read48'
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_P.Saturation15_UpperSat_k;
  } else if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f <
             px42LoopCtrQGCGPS202203131707_P.Saturation15_LowerSat_h) {
    // DataStoreRead: '<Root>/Data Store Read48'
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_P.Saturation15_LowerSat_h;
  } else {
    // DataStoreRead: '<Root>/Data Store Read48'
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;
  }

  // End of Saturate: '<S18>/Saturation15'

  // Sum: '<S18>/Add2' incorporates:
  //   DiscreteIntegrator: '<S18>/Discrete-Time Integrator3'
  //   Fcn: '<S18>/Fcn8'
  //   Gain: '<S18>/Gain6'
  //   Gain: '<S18>/lambda2'
  //   Product: '<S18>/Product8'
  //   Sum: '<S18>/Add20'

  px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0 =
    (((px42LoopCtrQGCGPS202203131707_P.lambda2_Gain_d *
       px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f +
       px42LoopCtrQGCGPS202203131707_B.yaw) +
      px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c) +
     px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator3_DSTAT_m) +
    (rt_powd_snf(px42LoopCtrQGCGPS202203131707_B.roll, 0.25) *
     px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p *
     px42LoopCtrQGCGPS202203131707_B.e_l +
     px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1) *
    px42LoopCtrQGCGPS202203131707_P.Gain6_Gain_f;

  // Saturate: '<S18>/Saturation3'
  if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f >
      px42LoopCtrQGCGPS202203131707_P.Saturation3_UpperSat_i) {
    // DataStoreRead: '<Root>/Data Store Read48'
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_P.Saturation3_UpperSat_i;
  } else if (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f <
             px42LoopCtrQGCGPS202203131707_P.Saturation3_LowerSat_g) {
    // DataStoreRead: '<Root>/Data Store Read48'
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_P.Saturation3_LowerSat_g;
  } else {
    // DataStoreRead: '<Root>/Data Store Read48'
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;
  }

  // End of Saturate: '<S18>/Saturation3'

  // Gain: '<S18>/l4'
  px42LoopCtrQGCGPS202203131707_B.l4_k =
    px42LoopCtrQGCGPS202203131707_P.l4_Gain_o *
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p;

  // Gain: '<S18>/lambda4'
  px42LoopCtrQGCGPS202203131707_B.lambda4_h =
    px42LoopCtrQGCGPS202203131707_P.lambda4_Gain_b *
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;

  // MATLABSystem: '<S7>/SourceBlock'
  rtb_LogicalOperator = uORB_read_step
    (px42LoopCtrQGCGPS20220313170_DW.obj_n.orbMetadataObj,
     &px42LoopCtrQGCGPS20220313170_DW.obj_n.eventStructObj,
     &px42LoopCtrQGCGPS202203131707_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S48>/Enable'

  if (rtb_LogicalOperator) {
    // SignalConversion generated from: '<S48>/In1'
    px42LoopCtrQGCGPS202203131707_B.In1 =
      px42LoopCtrQGCGPS202203131707_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S7>/SourceBlock'
  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   Product: '<S60>/Product'
  //   SignalConversion generated from: '<Root>/Bus Selector2'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p = static_cast<real_T>
    (px42LoopCtrQGCGPS202203131707_B.In1.q[0]) *
    px42LoopCtrQGCGPS202203131707_B.In1.q[0];

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   Product: '<S60>/Product1'
  //   SignalConversion generated from: '<Root>/Bus Selector2'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c = static_cast<real_T>
    (px42LoopCtrQGCGPS202203131707_B.In1.q[1]) *
    px42LoopCtrQGCGPS202203131707_B.In1.q[1];

  // Product: '<S60>/Product2' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   SignalConversion generated from: '<Root>/Bus Selector2'

  px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f = static_cast<real_T>
    (px42LoopCtrQGCGPS202203131707_B.In1.q[2]) *
    px42LoopCtrQGCGPS202203131707_B.In1.q[2];

  // Product: '<S60>/Product3' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   SignalConversion generated from: '<Root>/Bus Selector2'

  px42LoopCtrQGCGPS202203131707_B.roll = static_cast<real_T>
    (px42LoopCtrQGCGPS202203131707_B.In1.q[3]) *
    px42LoopCtrQGCGPS202203131707_B.In1.q[3];

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   Sqrt: '<S59>/sqrt'
  //   Sum: '<S60>/Sum'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p = sqrt
    (((px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p +
       px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c) +
      px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f) +
     px42LoopCtrQGCGPS202203131707_B.roll);

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   Product: '<S54>/Product'
  //   SignalConversion generated from: '<Root>/Bus Selector2'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
    px42LoopCtrQGCGPS202203131707_B.In1.q[0] /
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p;

  // Product: '<S54>/Product1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   SignalConversion generated from: '<Root>/Bus Selector2'

  px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
    px42LoopCtrQGCGPS202203131707_B.In1.q[1] /
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p;

  // Product: '<S54>/Product2' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   SignalConversion generated from: '<Root>/Bus Selector2'

  px42LoopCtrQGCGPS202203131707_B.roll = px42LoopCtrQGCGPS202203131707_B.In1.q[2]
    / px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   Product: '<S54>/Product3'
  //   SignalConversion generated from: '<Root>/Bus Selector2'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
    px42LoopCtrQGCGPS202203131707_B.In1.q[3] /
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p;

  // Fcn: '<S9>/fcn1'
  px42LoopCtrQGCGPS202203131707_B.e_l =
    (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f *
     px42LoopCtrQGCGPS202203131707_B.roll +
     px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c *
     px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p) * 2.0;

  // Fcn: '<S9>/fcn2' incorporates:
  //   Fcn: '<S9>/fcn5'

  px42LoopCtrQGCGPS202203131707_B.yaw =
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c *
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c;
  px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 =
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f *
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;
  px42LoopCtrQGCGPS202203131707_B.TSamp_f = px42LoopCtrQGCGPS202203131707_B.roll
    * px42LoopCtrQGCGPS202203131707_B.roll;
  yaw_tmp = px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p *
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p;

  // DataStoreWrite: '<Root>/Data Store Write10' incorporates:
  //   Fcn: '<S9>/fcn2'
  //   Trigonometry: '<S53>/Trigonometric Function1'

  px42LoopCtrQGCGPS20220313170_DW.yaw = rt_atan2d_snf
    (px42LoopCtrQGCGPS202203131707_B.e_l, ((px42LoopCtrQGCGPS202203131707_B.yaw
       + px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0) -
      px42LoopCtrQGCGPS202203131707_B.TSamp_f) - yaw_tmp);

  // Fcn: '<S9>/fcn3'
  px42LoopCtrQGCGPS202203131707_B.e_l =
    (px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f *
     px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p -
     px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c *
     px42LoopCtrQGCGPS202203131707_B.roll) * -2.0;

  // If: '<S55>/If' incorporates:
  //   Constant: '<S56>/Constant'
  //   Constant: '<S57>/Constant'

  if (px42LoopCtrQGCGPS202203131707_B.e_l > 1.0) {
    // Outputs for IfAction SubSystem: '<S55>/If Action Subsystem' incorporates:
    //   ActionPort: '<S56>/Action Port'

    px42LoopCtrQGCGPS202203131707_B.e_l =
      px42LoopCtrQGCGPS202203131707_P.Constant_Value_e;

    // End of Outputs for SubSystem: '<S55>/If Action Subsystem'
  } else if (px42LoopCtrQGCGPS202203131707_B.e_l < -1.0) {
    // Outputs for IfAction SubSystem: '<S55>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S57>/Action Port'

    px42LoopCtrQGCGPS202203131707_B.e_l =
      px42LoopCtrQGCGPS202203131707_P.Constant_Value_b1;

    // End of Outputs for SubSystem: '<S55>/If Action Subsystem1'
  }

  // End of If: '<S55>/If'

  // Trigonometry: '<S53>/trigFcn'
  if (px42LoopCtrQGCGPS202203131707_B.e_l > 1.0) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 = 1.0;
  } else if (px42LoopCtrQGCGPS202203131707_B.e_l < -1.0) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 = -1.0;
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS202203131707_B.e_l;
  }

  // Fcn: '<S9>/fcn4'
  px42LoopCtrQGCGPS202203131707_B.e_l = (px42LoopCtrQGCGPS202203131707_B.roll *
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p +
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c *
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f) * 2.0;

  // DataStoreWrite: '<Root>/Data Store Write' incorporates:
  //   Fcn: '<S9>/fcn5'
  //   Trigonometry: '<S53>/Trigonometric Function3'

  px42LoopCtrQGCGPS20220313170_DW.roll = rt_atan2d_snf
    (px42LoopCtrQGCGPS202203131707_B.e_l, ((px42LoopCtrQGCGPS202203131707_B.yaw
       - px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0) -
      px42LoopCtrQGCGPS202203131707_B.TSamp_f) + yaw_tmp);

  // DataStoreWrite: '<Root>/Data Store Write1' incorporates:
  //   Trigonometry: '<S53>/trigFcn'

  px42LoopCtrQGCGPS20220313170_DW.pitch = asin
    (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1);

  // DataStoreWrite: '<Root>/Data Store Write20' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px42LoopCtrQGCGPS20220313170_DW.yaw_speed =
    px42LoopCtrQGCGPS202203131707_B.In1.yawspeed;

  // DataStoreWrite: '<Root>/Data Store Write21' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px42LoopCtrQGCGPS20220313170_DW.pitch_speed =
    px42LoopCtrQGCGPS202203131707_B.In1.pitchspeed;

  // DataStoreWrite: '<Root>/Data Store Write22' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px42LoopCtrQGCGPS20220313170_DW.roll_speed =
    px42LoopCtrQGCGPS202203131707_B.In1.rollspeed;

  // MATLAB Function: '<Root>/MATLAB Function3' incorporates:
  //   Constant: '<Root>/Constant4'
  //   DataStoreRead: '<Root>/Data Store Read40'
  //   DataStoreRead: '<Root>/Data Store Read52'
  //   DataStoreRead: '<Root>/Data Store Read56'
  //   MATLAB Function: '<Root>/MATLAB Function4'

  px42LoopCtrQGCGPS202203131707_B.e_l = cos
    (px42LoopCtrQGCGPS202203131707_P.Constant4_Value_a);
  px42LoopCtrQGCGPS202203131707_B.roll = sin
    (px42LoopCtrQGCGPS202203131707_P.Constant4_Value_a);
  px42LoopCtrQGCGPS20220313170_DW.roll_desire = asin
    ((px42LoopCtrQGCGPS20220313170_DW.q_x * px42LoopCtrQGCGPS202203131707_B.roll
      - px42LoopCtrQGCGPS20220313170_DW.q_y *
      px42LoopCtrQGCGPS202203131707_B.e_l) / sqrt
     ((px42LoopCtrQGCGPS20220313170_DW.q_x * px42LoopCtrQGCGPS20220313170_DW.q_x
       + px42LoopCtrQGCGPS20220313170_DW.q_y *
       px42LoopCtrQGCGPS20220313170_DW.q_y) +
      (px42LoopCtrQGCGPS20220313170_DW.q_z + 9.8) *
      (px42LoopCtrQGCGPS20220313170_DW.q_z + 9.8)));
  px42LoopCtrQGCGPS20220313170_DW.pitch_desire = atan
    ((px42LoopCtrQGCGPS20220313170_DW.q_x * px42LoopCtrQGCGPS202203131707_B.e_l
      + px42LoopCtrQGCGPS20220313170_DW.q_y *
      px42LoopCtrQGCGPS202203131707_B.roll) /
     (px42LoopCtrQGCGPS20220313170_DW.q_z + 9.8));
  if (px42LoopCtrQGCGPS20220313170_DW.roll_desire > 0.17453292519943295) {
    px42LoopCtrQGCGPS20220313170_DW.roll_desire = 0.17453292519943295;
  } else if (px42LoopCtrQGCGPS20220313170_DW.roll_desire < -0.17453292519943295)
  {
    px42LoopCtrQGCGPS20220313170_DW.roll_desire = -0.17453292519943295;
  }

  if (px42LoopCtrQGCGPS20220313170_DW.pitch_desire > 0.17453292519943295) {
    px42LoopCtrQGCGPS20220313170_DW.pitch_desire = 0.17453292519943295;
  } else if (px42LoopCtrQGCGPS20220313170_DW.pitch_desire < -0.17453292519943295)
  {
    px42LoopCtrQGCGPS20220313170_DW.pitch_desire = -0.17453292519943295;
  }

  // End of MATLAB Function: '<Root>/MATLAB Function3'

  // Switch: '<Root>/Switch' incorporates:
  //   Constant: '<Root>/Constant7'
  //   Constant: '<Root>/Constant8'
  //   Constant: '<S49>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read47'
  //   Switch: '<S49>/Switch'

  if (px42LoopCtrQGCGPS20220313170_DW.position_flag) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 =
      px42LoopCtrQGCGPS202203131707_P.Constant7_Value;

    // DataStoreRead: '<Root>/Data Store Read48' incorporates:
    //   Constant: '<Root>/Constant7'
    //   DiscreteIntegrator: '<Root>/Intgrt_dY'

    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS20220313170_DW.Intgrt_dY_DSTATE;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS202203131707_P.Constant7_Value;

    // ZeroOrderHold: '<S49>/Zero-Order Hold5' incorporates:
    //   Constant: '<Root>/Constant7'
    //   DiscreteIntegrator: '<Root>/Intgrt_ddY'

    px42LoopCtrQGCGPS202203131707_B.roll =
      px42LoopCtrQGCGPS20220313170_DW.Intgrt_ddY_DSTATE;
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 =
      px42LoopCtrQGCGPS202203131707_P.Constant8_Value;

    // DataStoreRead: '<Root>/Data Store Read48' incorporates:
    //   Constant: '<Root>/Constant8'
    //   Constant: '<S49>/Constant1'

    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
      px42LoopCtrQGCGPS202203131707_P.Constant1_Value_g;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS202203131707_P.Constant1_Value_g;

    // ZeroOrderHold: '<S49>/Zero-Order Hold5' incorporates:
    //   Constant: '<S49>/Constant1'

    px42LoopCtrQGCGPS202203131707_B.roll =
      px42LoopCtrQGCGPS202203131707_P.Constant1_Value_g;
  }

  // End of Switch: '<Root>/Switch'

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   ZeroOrderHold: '<S49>/Zero-Order Hold2'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1;

  // SampleTimeMath: '<S51>/TSamp'
  //
  //  About '<S51>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px42LoopCtrQGCGPS202203131707_B.TSamp_f =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 *
    px42LoopCtrQGCGPS202203131707_P.TSamp_WtEt_ow;

  // ZeroOrderHold: '<S49>/Zero-Order Hold6' incorporates:
  //   Sum: '<S51>/Diff'
  //   UnitDelay: '<S51>/UD'
  //
  //  Block description for '<S51>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S51>/UD':
  //
  //   Store in Global RAM

  px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
    px42LoopCtrQGCGPS202203131707_B.TSamp_f -
    px42LoopCtrQGCGPS20220313170_DW.UD_DSTATE_i;

  // Gain: '<S49>/C2' incorporates:
  //   Sum: '<S49>/Subtract1'

  px42LoopCtrQGCGPS202203131707_B.e_l = (px42LoopCtrQGCGPS202203131707_B.roll -
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f) *
    px42LoopCtrQGCGPS202203131707_P.C2_Gain;

  // DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
  px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE_a;

  // Sum: '<S49>/Subtract' incorporates:
  //   Sum: '<S49>/Subtract8'

  yaw_tmp = px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p -
    px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c;

  // Gain: '<S8>/Gain2' incorporates:
  //   Gain: '<S49>/C1'
  //   Gain: '<S49>/C3'
  //   Sum: '<S49>/Subtract'
  //   Sum: '<S49>/Subtract2'

  px42LoopCtrQGCGPS202203131707_B.roll = ((yaw_tmp *
    px42LoopCtrQGCGPS202203131707_P.C1_Gain +
    px42LoopCtrQGCGPS202203131707_B.e_l) +
    px42LoopCtrQGCGPS202203131707_P.C3_Gain *
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f) *
    px42LoopCtrQGCGPS202203131707_P.Gain2_Gain_ce;

  // Saturate: '<S8>/Saturation1'
  if (px42LoopCtrQGCGPS202203131707_B.roll >
      px42LoopCtrQGCGPS202203131707_P.Saturation1_UpperSat_j) {
    px42LoopCtrQGCGPS20220313170_DW.q_y =
      px42LoopCtrQGCGPS202203131707_P.Saturation1_UpperSat_j;
  } else if (px42LoopCtrQGCGPS202203131707_B.roll <
             px42LoopCtrQGCGPS202203131707_P.Saturation1_LowerSat_j) {
    px42LoopCtrQGCGPS20220313170_DW.q_y =
      px42LoopCtrQGCGPS202203131707_P.Saturation1_LowerSat_j;
  } else {
    px42LoopCtrQGCGPS20220313170_DW.q_y = px42LoopCtrQGCGPS202203131707_B.roll;
  }

  // End of Saturate: '<S8>/Saturation1'

  // DataStoreWrite: '<Root>/Data Store Write18' incorporates:
  //   Constant: '<S8>/Constant'

  px42LoopCtrQGCGPS20220313170_DW.q_z =
    px42LoopCtrQGCGPS202203131707_P.Constant_Value_e4;

  // Switch: '<S50>/Switch' incorporates:
  //   Constant: '<S50>/Constant1'
  //   DataStoreRead: '<S50>/Data Store Read'

  if (px42LoopCtrQGCGPS20220313170_DW.position_flag) {
    // ZeroOrderHold: '<S50>/Zero-Order Hold1' incorporates:
    //   DiscreteIntegrator: '<Root>/Intgrt_dX'

    px42LoopCtrQGCGPS202203131707_B.roll =
      px42LoopCtrQGCGPS20220313170_DW.Intgrt_dX_DSTATE;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0;

    // ZeroOrderHold: '<S50>/Zero-Order Hold5' incorporates:
    //   DiscreteIntegrator: '<Root>/Intgrt_ddX'

    px42LoopCtrQGCGPS202203131707_B.yaw =
      px42LoopCtrQGCGPS20220313170_DW.Intgrt_ddX_DSTATE;
  } else {
    // ZeroOrderHold: '<S50>/Zero-Order Hold1' incorporates:
    //   Constant: '<S50>/Constant1'

    px42LoopCtrQGCGPS202203131707_B.roll =
      px42LoopCtrQGCGPS202203131707_P.Constant1_Value_h;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 =
      px42LoopCtrQGCGPS202203131707_P.Constant1_Value_h;

    // ZeroOrderHold: '<S50>/Zero-Order Hold5' incorporates:
    //   Constant: '<S50>/Constant1'

    px42LoopCtrQGCGPS202203131707_B.yaw =
      px42LoopCtrQGCGPS202203131707_P.Constant1_Value_h;
  }

  // End of Switch: '<S50>/Switch'

  // ZeroOrderHold: '<S50>/Zero-Order Hold2'
  px42LoopCtrQGCGPS202203131707_B.e_l =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1;

  // SampleTimeMath: '<S52>/TSamp'
  //
  //  About '<S52>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 *=
    px42LoopCtrQGCGPS202203131707_P.TSamp_WtEt_g;

  // Sum: '<S50>/Subtract' incorporates:
  //   Sum: '<S50>/Subtract8'

  px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f =
    px42LoopCtrQGCGPS202203131707_B.roll - px42LoopCtrQGCGPS202203131707_B.e_l;

  // Gain: '<S8>/Gain4' incorporates:
  //   DiscreteIntegrator: '<S50>/Discrete-Time Integrator'
  //   Gain: '<S50>/C1'
  //   Gain: '<S50>/C2'
  //   Gain: '<S50>/C3'
  //   Sum: '<S50>/Subtract'
  //   Sum: '<S50>/Subtract1'
  //   Sum: '<S50>/Subtract2'
  //   Sum: '<S52>/Diff'
  //   UnitDelay: '<S52>/UD'
  //
  //  Block description for '<S52>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S52>/UD':
  //
  //   Store in Global RAM

  px42LoopCtrQGCGPS20220313170_DW.q_x = (((px42LoopCtrQGCGPS202203131707_B.yaw -
    (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1 -
     px42LoopCtrQGCGPS20220313170_DW.UD_DSTATE_nu)) *
    px42LoopCtrQGCGPS202203131707_P.C2_Gain_k +
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f *
    px42LoopCtrQGCGPS202203131707_P.C1_Gain_k) +
    px42LoopCtrQGCGPS202203131707_P.C3_Gain_o *
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE_k) *
    px42LoopCtrQGCGPS202203131707_P.Gain4_Gain_a;

  // Saturate: '<S8>/Saturation2'
  if (px42LoopCtrQGCGPS20220313170_DW.q_x >
      px42LoopCtrQGCGPS202203131707_P.Saturation2_UpperSat_h) {
    // Gain: '<S8>/Gain4'
    px42LoopCtrQGCGPS20220313170_DW.q_x =
      px42LoopCtrQGCGPS202203131707_P.Saturation2_UpperSat_h;
  } else if (px42LoopCtrQGCGPS20220313170_DW.q_x <
             px42LoopCtrQGCGPS202203131707_P.Saturation2_LowerSat_o) {
    // Gain: '<S8>/Gain4'
    px42LoopCtrQGCGPS20220313170_DW.q_x =
      px42LoopCtrQGCGPS202203131707_P.Saturation2_LowerSat_o;
  }

  // End of Saturate: '<S8>/Saturation2'

  // MATLAB Function: '<Root>/MATLAB Function2' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read1'
  //   DataStoreRead: '<Root>/Data Store Read2'
  //   DataStoreRead: '<Root>/Data Store Read4'

  px42LoopCtrQGCGPS202203131707_B.e_l = sqrt
    ((px42LoopCtrQGCGPS20220313170_DW.q_x * px42LoopCtrQGCGPS20220313170_DW.q_x
      + px42LoopCtrQGCGPS20220313170_DW.q_y *
      px42LoopCtrQGCGPS20220313170_DW.q_y) +
     (px42LoopCtrQGCGPS20220313170_DW.q_z + 9.8) *
     (px42LoopCtrQGCGPS20220313170_DW.q_z + 9.8));

  // DataStoreWrite: '<S11>/Data Store Write28' incorporates:
  //   Constant: '<S11>/attitude_flag'

  px42LoopCtrQGCGPS20220313170_DW.attitude_flag =
    px42LoopCtrQGCGPS202203131707_P.attitude_flag_Value;

  // DataStoreWrite: '<S12>/Data Store Write28' incorporates:
  //   Constant: '<S12>/observer_flag'

  px42LoopCtrQGCGPS20220313170_DW.observer_flag =
    px42LoopCtrQGCGPS202203131707_P.observer_flag_Value;

  // DataStoreWrite: '<S13>/Data Store Write28' incorporates:
  //   Constant: '<S13>/position_flag'

  px42LoopCtrQGCGPS20220313170_DW.position_flag =
    px42LoopCtrQGCGPS202203131707_P.position_flag_Value;
  for (int32_T i = 0; i < 4; i++) {
    // Gain: '<Root>/Gain4' incorporates:
    //   Constant: '<Root>/Constant1'
    //   Constant: '<Root>/Mixer matrix1'
    //   DataStoreRead: '<Root>/Data Store Read21'
    //   DataStoreRead: '<Root>/Data Store Read22'
    //   DataStoreRead: '<Root>/Data Store Read23'
    //   Product: '<Root>/Product2'
    //   SignalConversion generated from: '<Root>/Product2'

    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = floor
      ((((px42LoopCtrQGCGPS202203131707_P.Mixermatrix1_Value[i + 4] *
          px42LoopCtrQGCGPS202203131707_B.z2_e +
          px42LoopCtrQGCGPS202203131707_P.Mixermatrix1_Value[i] *
          px42LoopCtrQGCGPS202203131707_P.Constant1_Value_l) +
         px42LoopCtrQGCGPS202203131707_P.Mixermatrix1_Value[i + 8] *
         px42LoopCtrQGCGPS202203131707_B.z2_l) +
        px42LoopCtrQGCGPS202203131707_P.Mixermatrix1_Value[i + 12] *
        px42LoopCtrQGCGPS202203131707_B.yaw_thrust) *
       px42LoopCtrQGCGPS202203131707_P.Gain4_Gain_fc);
    if (rtIsNaN(px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0) || rtIsInf
        (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0)) {
      px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = 0.0;
    } else {
      px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = fmod
        (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0, 65536.0);
    }

    px42LoopCtrQGCGPS202203131707_B.Gain4[i] = static_cast<uint16_T>
      (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 < 0.0 ?
       static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
          static_cast<uint16_T>
          (-px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0)))) :
       static_cast<int32_T>(static_cast<uint16_T>
        (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0)));

    // End of Gain: '<Root>/Gain4'
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1'
  for (int32_T i = 0; i < 8; i++) {
    px42LoopCtrQGCGPS202203131707_B.pwmValue[i] = 0U;
  }

  // Sum: '<Root>/Add' incorporates:
  //   Constant: '<Root>/fault_1'

  px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = floor(static_cast<real_T>
    (px42LoopCtrQGCGPS202203131707_B.Gain4[0]) -
    px42LoopCtrQGCGPS202203131707_P.fault_1_Value);
  if (rtIsNaN(px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0) || rtIsInf
      (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0)) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = 0.0;
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = fmod
      (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Sum: '<Root>/Add'

  px42LoopCtrQGCGPS202203131707_B.pwmValue[0] = static_cast<uint16_T>
    (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 < 0.0 ?
     static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
        static_cast<uint16_T>(-px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0))))
     : static_cast<int32_T>(static_cast<uint16_T>
      (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0)));

  // Sum: '<Root>/Add1' incorporates:
  //   Constant: '<Root>/fault_2'

  px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = floor(static_cast<real_T>
    (px42LoopCtrQGCGPS202203131707_B.Gain4[1]) -
    px42LoopCtrQGCGPS202203131707_P.fault_2_Value);
  if (rtIsNaN(px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0) || rtIsInf
      (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0)) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = 0.0;
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = fmod
      (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Sum: '<Root>/Add1'

  px42LoopCtrQGCGPS202203131707_B.pwmValue[1] = static_cast<uint16_T>
    (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 < 0.0 ?
     static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
        static_cast<uint16_T>(-px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0))))
     : static_cast<int32_T>(static_cast<uint16_T>
      (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0)));

  // Sum: '<Root>/Add2' incorporates:
  //   Constant: '<Root>/fault_3'

  px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = floor(static_cast<real_T>
    (px42LoopCtrQGCGPS202203131707_B.Gain4[2]) -
    px42LoopCtrQGCGPS202203131707_P.fault_3_Value);
  if (rtIsNaN(px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0) || rtIsInf
      (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0)) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = 0.0;
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = fmod
      (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Sum: '<Root>/Add2'

  px42LoopCtrQGCGPS202203131707_B.pwmValue[2] = static_cast<uint16_T>
    (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 < 0.0 ?
     static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
        static_cast<uint16_T>(-px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0))))
     : static_cast<int32_T>(static_cast<uint16_T>
      (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0)));

  // Sum: '<Root>/Add3' incorporates:
  //   Constant: '<Root>/fault_4'

  px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = floor(static_cast<real_T>
    (px42LoopCtrQGCGPS202203131707_B.Gain4[3]) -
    px42LoopCtrQGCGPS202203131707_P.fault_4_Value);
  if (rtIsNaN(px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0) || rtIsInf
      (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0)) {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = 0.0;
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = fmod
      (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Constant: '<Root>/Constant2'
  //   DataStoreRead: '<Root>/Data Store Read6'
  //   Sum: '<Root>/Add3'

  px42LoopCtrQGCGPS202203131707_B.pwmValue[3] = static_cast<uint16_T>
    (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 < 0.0 ?
     static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
        static_cast<uint16_T>(-px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0))))
     : static_cast<int32_T>(static_cast<uint16_T>
      (px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0)));
  if (px42LoopCtrQGCGPS20220313170_DW.armed) {
    if (!px42LoopCtrQGCGPS20220313170_DW.obj.isArmed) {
      px42LoopCtrQGCGPS20220313170_DW.obj.isArmed = true;
      status = pwm_arm(&px42LoopCtrQGCGPS20220313170_DW.obj.pwmDevHandler,
                       &px42LoopCtrQGCGPS20220313170_DW.obj.armAdvertiseObj);
      px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus = static_cast<uint16_T>
        (px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus | status);
    }

    status = pwm_setServo(&px42LoopCtrQGCGPS20220313170_DW.obj.pwmDevHandler,
                          px42LoopCtrQGCGPS20220313170_DW.obj.servoCount,
                          px42LoopCtrQGCGPS20220313170_DW.obj.channelMask,
                          &px42LoopCtrQGCGPS202203131707_B.pwmValue[0],
                          px42LoopCtrQGCGPS20220313170_DW.obj.isMain,
                          &px42LoopCtrQGCGPS20220313170_DW.obj.actuatorAdvertiseObj);
    px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus = static_cast<uint16_T>
      (px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus | status);
  } else {
    status = pwm_disarm(&px42LoopCtrQGCGPS20220313170_DW.obj.pwmDevHandler,
                        &px42LoopCtrQGCGPS20220313170_DW.obj.armAdvertiseObj);
    px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus = static_cast<uint16_T>
      (px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus | status);
    px42LoopCtrQGCGPS20220313170_DW.obj.isArmed = false;
    status = pwm_resetServo(&px42LoopCtrQGCGPS20220313170_DW.obj.pwmDevHandler,
      px42LoopCtrQGCGPS20220313170_DW.obj.servoCount,
      px42LoopCtrQGCGPS20220313170_DW.obj.channelMask,
      px42LoopCtrQGCGPS20220313170_DW.obj.isMain,
      &px42LoopCtrQGCGPS20220313170_DW.obj.actuatorAdvertiseObj);
    px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus = static_cast<uint16_T>
      (px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus | status);
  }

  if (px42LoopCtrQGCGPS20220313170_DW.obj.isMain) {
    status = pwm_forceFailsafe
      (&px42LoopCtrQGCGPS20220313170_DW.obj.pwmDevHandler, static_cast<int32_T>
       (px42LoopCtrQGCGPS202203131707_P.Constant2_Value_kf));
    px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus = static_cast<uint16_T>
      (px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus | status);
  }

  // Switch: '<Root>/Switch1' incorporates:
  //   Constant: '<Root>/Constant5'
  //   DataStoreRead: '<Root>/Data Store Read53'
  //   MATLAB Function: '<Root>/MATLAB Function1'

  if (px42LoopCtrQGCGPS20220313170_DW.position_flag) {
    real_T rtb_Switch_idx_0_tmp;

    // MATLAB Function: '<Root>/MATLAB Function1' incorporates:
    //   DataStoreRead: '<Root>/Data Store Read'
    //   DataStoreRead: '<Root>/Data Store Read5'
    //   DataStoreRead: '<Root>/Data Store Read7'

    px42LoopCtrQGCGPS202203131707_B.roll = sin
      (px42LoopCtrQGCGPS20220313170_DW.yaw);
    px42LoopCtrQGCGPS202203131707_B.yaw = sin
      (px42LoopCtrQGCGPS20220313170_DW.pitch);
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_1 = cos
      (px42LoopCtrQGCGPS20220313170_DW.yaw);
    rtb_Switch_idx_0_tmp = cos(px42LoopCtrQGCGPS20220313170_DW.pitch) * sin
      (px42LoopCtrQGCGPS20220313170_DW.roll);
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 = (rtb_Switch_idx_0_tmp *
      px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_1 +
      px42LoopCtrQGCGPS202203131707_B.yaw * px42LoopCtrQGCGPS202203131707_B.roll)
      * -px42LoopCtrQGCGPS202203131707_B.e_l;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_1 = (rtb_Switch_idx_0_tmp *
      px42LoopCtrQGCGPS202203131707_B.roll - px42LoopCtrQGCGPS202203131707_B.yaw
      * px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_1) *
      -px42LoopCtrQGCGPS202203131707_B.e_l;
  } else {
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 =
      px42LoopCtrQGCGPS202203131707_P.Constant5_Value;
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_1 =
      px42LoopCtrQGCGPS202203131707_P.Constant5_Value;
  }

  // End of Switch: '<Root>/Switch1'

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read28'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
    px42LoopCtrQGCGPS202203131707_B.z2_e;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read29'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
    px42LoopCtrQGCGPS202203131707_B.z2_l;

  // DataStoreRead: '<Root>/Data Store Read32'
  px42LoopCtrQGCGPS202203131707_B.roll =
    px42LoopCtrQGCGPS202203131707_B.yaw_thrust;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read31'
  //   Gain: '<Root>/Gain8'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
    px42LoopCtrQGCGPS202203131707_P.Gain8_Gain_o1 *
    px42LoopCtrQGCGPS20220313170_DW.pitch;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   Gain: '<Root>/Gain10'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
    px42LoopCtrQGCGPS202203131707_P.Gain10_Gain * 0.0;

  // Gain: '<Root>/Gain7' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read30'

  px42LoopCtrQGCGPS202203131707_B.roll =
    px42LoopCtrQGCGPS202203131707_P.Gain7_Gain_a *
    px42LoopCtrQGCGPS20220313170_DW.roll;

  // Gain: '<Root>/Gain11'
  px42LoopCtrQGCGPS202203131707_B.e_l =
    px42LoopCtrQGCGPS202203131707_P.Gain11_Gain * 0.0;

  // Gain: '<Root>/Gain9' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read33'

  px42LoopCtrQGCGPS202203131707_B.yaw =
    px42LoopCtrQGCGPS202203131707_P.Gain9_Gain *
    px42LoopCtrQGCGPS20220313170_DW.yaw;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_dX'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead48_p =
    px42LoopCtrQGCGPS20220313170_DW.Intgrt_dX_DSTATE;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_dY'

  px42LoopCtrQGCGPS202203131707_B.rtb_DataStoreRead49_c =
    px42LoopCtrQGCGPS20220313170_DW.Intgrt_dY_DSTATE;

  // Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
  //   EnablePort: '<S10>/Enable'

  // DataStoreRead: '<Root>/Data Store Read54'
  if (px42LoopCtrQGCGPS20220313170_DW.attitude_flag) {
    // DiscreteIntegrator: '<S10>/Discrete-Time Integrator' incorporates:
    //   DataStoreWrite: '<S10>/Data Store Write27'

    px42LoopCtrQGCGPS20220313170_DW.t =
      px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTAT_fj;

    // Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S10>/Constant9'

    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTAT_fj +=
      px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator_gainval *
      px42LoopCtrQGCGPS202203131707_P.Constant9_Value;
  }

  // End of DataStoreRead: '<Root>/Data Store Read54'
  // End of Outputs for SubSystem: '<Root>/Subsystem1'

  // Update for UnitDelay: '<S38>/UD'
  //
  //  Block description for '<S38>/UD':
  //
  //   Store in Global RAM

  px42LoopCtrQGCGPS20220313170_DW.UD_DSTATE =
    px42LoopCtrQGCGPS202203131707_B.TSamp;

  // Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator3' incorporates:
  //   Gain: '<S19>/Gain7'
  //   Sum: '<S19>/Add15'
  //   Sum: '<S19>/Add5'

  px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator3_DSTATE +=
    ((px42LoopCtrQGCGPS202203131707_B.Product6 +
      px42LoopCtrQGCGPS202203131707_B.e_g) *
     px42LoopCtrQGCGPS202203131707_P.Gain7_Gain +
     (px42LoopCtrQGCGPS202203131707_B.l4 +
      px42LoopCtrQGCGPS202203131707_B.lambda4)) *
    px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator3_gainval;

  // Update for UnitDelay: '<S20>/UD'
  //
  //  Block description for '<S20>/UD':
  //
  //   Store in Global RAM

  px42LoopCtrQGCGPS20220313170_DW.UD_DSTATE_b =
    px42LoopCtrQGCGPS202203131707_B.z2;

  // Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator3' incorporates:
  //   Gain: '<S17>/Gain7'
  //   Sum: '<S17>/Add15'
  //   Sum: '<S17>/Add5'

  px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator3_DSTAT_a +=
    ((px42LoopCtrQGCGPS202203131707_B.Product6_i +
      px42LoopCtrQGCGPS202203131707_B.e_gq) *
     px42LoopCtrQGCGPS202203131707_P.Gain7_Gain_d +
     (px42LoopCtrQGCGPS202203131707_B.Product7_e +
      px42LoopCtrQGCGPS202203131707_B.lambda4_n)) *
    px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator3_gainv_m;

  // Update for UnitDelay: '<S29>/UD'
  //
  //  Block description for '<S29>/UD':
  //
  //   Store in Global RAM

  px42LoopCtrQGCGPS20220313170_DW.UD_DSTATE_n =
    px42LoopCtrQGCGPS202203131707_B.Product_c;

  // Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator3' incorporates:
  //   Gain: '<S18>/Gain7'
  //   Sum: '<S18>/Add15'
  //   Sum: '<S18>/Add5'

  px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator3_DSTAT_m +=
    ((px42LoopCtrQGCGPS202203131707_B.Product6_a +
      px42LoopCtrQGCGPS202203131707_B.e_e1) *
     px42LoopCtrQGCGPS202203131707_P.Gain7_Gain_l +
     (px42LoopCtrQGCGPS202203131707_B.l4_k +
      px42LoopCtrQGCGPS202203131707_B.lambda4_h)) *
    px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator3_gainv_e;

  // Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S19>/Discrete-Time Integrator1'
  //   Gain: '<S19>/Gain5'
  //   Gain: '<S19>/l1'
  //   Sum: '<S19>/Add'
  //   Sum: '<S19>/Add9'

  px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE +=
    (((px42LoopCtrQGCGPS202203131707_P.l1_Gain * rtb_Fcn_tmp +
       px42LoopCtrQGCGPS202203131707_B.Add3) +
      px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator1_DSTATE) +
     (px42LoopCtrQGCGPS202203131707_B.Product3 +
      px42LoopCtrQGCGPS202203131707_B.Product4) *
     px42LoopCtrQGCGPS202203131707_P.Gain5_Gain) *
    px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator_gainva_n;

  // Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator1'
  px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator1_DSTATE +=
    px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator1_gainval *
    px42LoopCtrQGCGPS202203131707_B.l2;

  // Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S17>/Gain5'
  //   Sum: '<S17>/Add'
  //   Sum: '<S17>/Add9'

  px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE_p +=
    (((px42LoopCtrQGCGPS202203131707_B.Product7 +
       px42LoopCtrQGCGPS202203131707_B.lambda1_a) +
      px42LoopCtrQGCGPS202203131707_B.Product_cm) +
     (px42LoopCtrQGCGPS202203131707_B.Product3_a +
      px42LoopCtrQGCGPS202203131707_B.Product4_k) *
     px42LoopCtrQGCGPS202203131707_P.Gain5_Gain_o) *
    px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator_gainva_e;

  // Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1'
  px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator1_DSTAT_i +=
    px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator1_gainv_n *
    px42LoopCtrQGCGPS202203131707_B.l2_j;

  // Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S18>/Gain5'
  //   Sum: '<S18>/Add'
  //   Sum: '<S18>/Add9'

  px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE_f +=
    (((px42LoopCtrQGCGPS202203131707_B.roll_hat_k +
       px42LoopCtrQGCGPS202203131707_B.lambda1_e) +
      px42LoopCtrQGCGPS202203131707_B.z1_i) +
     (px42LoopCtrQGCGPS202203131707_B.Product3_c +
      px42LoopCtrQGCGPS202203131707_B.Product4_g) *
     px42LoopCtrQGCGPS202203131707_P.Gain5_Gain_l) *
    px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator_gainv_nv;

  // Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator1'
  px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator1_DSTAT_g +=
    px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator1_gainv_g *
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_0;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_dX' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddX'

  px42LoopCtrQGCGPS20220313170_DW.Intgrt_dX_DSTATE +=
    px42LoopCtrQGCGPS202203131707_P.Intgrt_dX_gainval *
    px42LoopCtrQGCGPS20220313170_DW.Intgrt_ddX_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_dY' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddY'

  px42LoopCtrQGCGPS20220313170_DW.Intgrt_dY_DSTATE +=
    px42LoopCtrQGCGPS202203131707_P.Intgrt_dY_gainval *
    px42LoopCtrQGCGPS20220313170_DW.Intgrt_ddY_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_ddY' incorporates:
  //   Gain: '<Root>/slower4'

  px42LoopCtrQGCGPS20220313170_DW.Intgrt_ddY_DSTATE +=
    px42LoopCtrQGCGPS202203131707_P.slower4_Gain *
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_1 *
    px42LoopCtrQGCGPS202203131707_P.Intgrt_ddY_gainval;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_ddX' incorporates:
  //   Gain: '<Root>/slower3'

  px42LoopCtrQGCGPS20220313170_DW.Intgrt_ddX_DSTATE +=
    px42LoopCtrQGCGPS202203131707_P.slower3_Gain *
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_idx_0 *
    px42LoopCtrQGCGPS202203131707_P.Intgrt_ddX_gainval;

  // Update for UnitDelay: '<S51>/UD'
  //
  //  Block description for '<S51>/UD':
  //
  //   Store in Global RAM

  px42LoopCtrQGCGPS20220313170_DW.UD_DSTATE_i =
    px42LoopCtrQGCGPS202203131707_B.TSamp_f;

  // Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
  px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE_a +=
    px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator_gainva_h * yaw_tmp;

  // Update for UnitDelay: '<S52>/UD'
  //
  //  Block description for '<S52>/UD':
  //
  //   Store in Global RAM

  px42LoopCtrQGCGPS20220313170_DW.UD_DSTATE_nu =
    px42LoopCtrQGCGPS202203131707_B.rtb_Switch_o_idx_1;

  // Update for DiscreteIntegrator: '<S50>/Discrete-Time Integrator'
  px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE_k +=
    px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator_gainva_i *
    px42LoopCtrQGCGPS202203131707_B.DiscreteTimeIntegrator_f;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_dZ' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddZ'

  px42LoopCtrQGCGPS20220313170_DW.Intgrt_dZ_DSTATE +=
    px42LoopCtrQGCGPS202203131707_P.Intgrt_dZ_gainval *
    px42LoopCtrQGCGPS20220313170_DW.Intgrt_ddZ_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_ddZ' incorporates:
  //   Gain: '<Root>/slower5'

  px42LoopCtrQGCGPS20220313170_DW.Intgrt_ddZ_DSTATE +=
    px42LoopCtrQGCGPS202203131707_P.slower5_Gain * 0.0 *
    px42LoopCtrQGCGPS202203131707_P.Intgrt_ddZ_gainval;
}

// Model step function for TID1
void px42LoopCtrQGCGPS202203131707_step1(void) // Sample time: [0.01s, 0.0s]
{
  uint64_T rtb_timestamp;
  uint32_T rtb_noutputs;
  uint8_T rtb__padding0[4];
  boolean_T b_varargout_1;
  boolean_T rtb_NOT_o;

  // MATLABSystem: '<S6>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (px42LoopCtrQGCGPS20220313170_DW.obj_l.orbMetadataObj,
     &px42LoopCtrQGCGPS20220313170_DW.obj_l.eventStructObj,
     &px42LoopCtrQGCGPS202203131707_B.b_varargout_2_m, false, 1.0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S47>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S47>/In1'
    px42LoopCtrQGCGPS202203131707_B.In1_a =
      px42LoopCtrQGCGPS202203131707_B.b_varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb_timestamp = px42LoopCtrQGCGPS202203131707_B.In1_a.timestamp;

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb_noutputs = px42LoopCtrQGCGPS202203131707_B.In1_a.noutputs;

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb__padding0[0] = px42LoopCtrQGCGPS202203131707_B.In1_a._padding0[0];
  rtb__padding0[1] = px42LoopCtrQGCGPS202203131707_B.In1_a._padding0[1];
  rtb__padding0[2] = px42LoopCtrQGCGPS202203131707_B.In1_a._padding0[2];
  rtb__padding0[3] = px42LoopCtrQGCGPS202203131707_B.In1_a._padding0[3];

  // Logic: '<S6>/NOT' incorporates:
  //   MATLABSystem: '<S6>/SourceBlock'

  rtb_NOT_o = !b_varargout_1;
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void px42LoopCtrQGCGPS202203131707_step(int_T tid)
{
  switch (tid) {
   case 0 :
    px42LoopCtrQGCGPS202203131707_step0();
    break;

   case 1 :
    px42LoopCtrQGCGPS202203131707_step1();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void px42LoopCtrQGCGPS202203131707_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  px42LoopCtrQGCGPS202203131707_P.Saturation1_UpperSat_k = rtInf;

  // block I/O
  (void) memset((static_cast<void *>(&px42LoopCtrQGCGPS202203131707_B)), 0,
                sizeof(B_px42LoopCtrQGCGPS2022031317_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&px42LoopCtrQGCGPS20220313170_DW), 0,
                sizeof(DW_px42LoopCtrQGCGPS202203131_T));

  {
    boolean_T rtb_DataStoreRead6;

    // Start for DataStoreMemory: '<S40>/Data Store Memory'
    px42LoopCtrQGCGPS20220313170_DW.start_time_yaw =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory_InitialValue;

    // Start for DataStoreMemory: '<S22>/Data Store Memory'
    px42LoopCtrQGCGPS20220313170_DW.start_time =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory_InitialValue_l;

    // Start for DataStoreMemory: '<S31>/Data Store Memory'
    px42LoopCtrQGCGPS20220313170_DW.start_time_roll =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory_InitialValue_b;

    // Start for DataStoreMemory: '<S1>/e_pitch'
    px42LoopCtrQGCGPS20220313170_DW.e_pitch =
      px42LoopCtrQGCGPS202203131707_P.e_pitch_InitialValue;

    // Start for DataStoreMemory: '<S1>/e_pitch1'
    px42LoopCtrQGCGPS20220313170_DW.e_pitch_roll =
      px42LoopCtrQGCGPS202203131707_P.e_pitch1_InitialValue;

    // Start for DataStoreMemory: '<S1>/e_pitch2'
    px42LoopCtrQGCGPS20220313170_DW.e_pitch_yaw =
      px42LoopCtrQGCGPS202203131707_P.e_pitch2_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory'
    px42LoopCtrQGCGPS20220313170_DW.attitude_flag =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory_InitialValue_j;

    // Start for DataStoreMemory: '<Root>/Data Store Memory1'
    px42LoopCtrQGCGPS20220313170_DW.armed =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory1_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory16'
    px42LoopCtrQGCGPS20220313170_DW.yaw_speed =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory16_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory17'
    px42LoopCtrQGCGPS20220313170_DW.roll_speed =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory17_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory18'
    px42LoopCtrQGCGPS20220313170_DW.pitch_speed =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory18_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory22'
    px42LoopCtrQGCGPS20220313170_DW.roll_desire =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory22_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory23'
    px42LoopCtrQGCGPS20220313170_DW.pitch_desire =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory23_InitialValue;

    // Start for Gain: '<S8>/Gain4' incorporates:
    //   DataStoreMemory: '<Root>/Data Store Memory24'

    px42LoopCtrQGCGPS20220313170_DW.q_x =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory24_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory25'
    px42LoopCtrQGCGPS20220313170_DW.q_y =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory25_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory26'
    px42LoopCtrQGCGPS20220313170_DW.q_z =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory26_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory27'
    px42LoopCtrQGCGPS20220313170_DW.position_flag =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory27_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory29'
    px42LoopCtrQGCGPS20220313170_DW.t =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory29_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory30'
    px42LoopCtrQGCGPS20220313170_DW.observer_flag =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory30_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory4'
    px42LoopCtrQGCGPS20220313170_DW.pitch =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory4_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory6'
    px42LoopCtrQGCGPS20220313170_DW.roll =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory6_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory8'
    px42LoopCtrQGCGPS20220313170_DW.yaw =
      px42LoopCtrQGCGPS202203131707_P.DataStoreMemory8_InitialValue;
    px42LoopCtrQGCGPS202203_PrevZCX.Subsystem_Trig_ZCE_e = POS_ZCSIG;
    px42LoopCtrQGCGPS202203_PrevZCX.Subsystem_Trig_ZCE_j = POS_ZCSIG;
    px42LoopCtrQGCGPS202203_PrevZCX.Subsystem_Trig_ZCE = POS_ZCSIG;

    // InitializeConditions for UnitDelay: '<S38>/UD'
    //
    //  Block description for '<S38>/UD':
    //
    //   Store in Global RAM

    px42LoopCtrQGCGPS20220313170_DW.UD_DSTATE =
      px42LoopCtrQGCGPS202203131707_P.DiscreteDerivative1_ICPrevScale;

    // InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator3' 
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator3_DSTATE =
      px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator3_IC;

    // InitializeConditions for UnitDelay: '<S20>/UD'
    //
    //  Block description for '<S20>/UD':
    //
    //   Store in Global RAM

    px42LoopCtrQGCGPS20220313170_DW.UD_DSTATE_b =
      px42LoopCtrQGCGPS202203131707_P.DiscreteDerivative1_ICPrevSca_o;

    // InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator3' 
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator3_DSTAT_a =
      px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator3_IC_k;

    // InitializeConditions for UnitDelay: '<S29>/UD'
    //
    //  Block description for '<S29>/UD':
    //
    //   Store in Global RAM

    px42LoopCtrQGCGPS20220313170_DW.UD_DSTATE_n =
      px42LoopCtrQGCGPS202203131707_P.DiscreteDerivative1_ICPrevSca_d;

    // InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator3' 
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator3_DSTAT_m =
      px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator3_IC_l;

    // InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' 
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE =
      px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator_IC_l;

    // InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator1' 
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator1_DSTATE =
      px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' 
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE_p =
      px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator_IC_h;

    // InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' 
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator1_DSTAT_i =
      px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator1_IC_j;

    // InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' 
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE_f =
      px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator_IC_o;

    // InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator1' 
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator1_DSTAT_g =
      px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator1_IC_c;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_dX'
    px42LoopCtrQGCGPS20220313170_DW.Intgrt_dX_DSTATE =
      px42LoopCtrQGCGPS202203131707_P.Intgrt_dX_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_dY'
    px42LoopCtrQGCGPS20220313170_DW.Intgrt_dY_DSTATE =
      px42LoopCtrQGCGPS202203131707_P.Intgrt_dY_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_ddY'
    px42LoopCtrQGCGPS20220313170_DW.Intgrt_ddY_DSTATE =
      px42LoopCtrQGCGPS202203131707_P.Intgrt_ddY_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_ddX'
    px42LoopCtrQGCGPS20220313170_DW.Intgrt_ddX_DSTATE =
      px42LoopCtrQGCGPS202203131707_P.Intgrt_ddX_IC;

    // InitializeConditions for UnitDelay: '<S51>/UD'
    //
    //  Block description for '<S51>/UD':
    //
    //   Store in Global RAM

    px42LoopCtrQGCGPS20220313170_DW.UD_DSTATE_i =
      px42LoopCtrQGCGPS202203131707_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' 
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE_a =
      px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator_IC_hw;

    // InitializeConditions for UnitDelay: '<S52>/UD'
    //
    //  Block description for '<S52>/UD':
    //
    //   Store in Global RAM

    px42LoopCtrQGCGPS20220313170_DW.UD_DSTATE_nu =
      px42LoopCtrQGCGPS202203131707_P.DiscreteDerivative_ICPrevScal_a;

    // InitializeConditions for DiscreteIntegrator: '<S50>/Discrete-Time Integrator' 
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTATE_k =
      px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator_IC_e;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_dZ'
    px42LoopCtrQGCGPS20220313170_DW.Intgrt_dZ_DSTATE =
      px42LoopCtrQGCGPS202203131707_P.Intgrt_dZ_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_ddZ'
    px42LoopCtrQGCGPS20220313170_DW.Intgrt_ddZ_DSTATE =
      px42LoopCtrQGCGPS202203131707_P.Intgrt_ddZ_IC;

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S47>/In1' incorporates:
    //   Outport: '<S47>/Out1'

    px42LoopCtrQGCGPS202203131707_B.In1_a =
      px42LoopCtrQGCGPS202203131707_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S48>/In1' incorporates:
    //   Outport: '<S48>/Out1'

    px42LoopCtrQGCGPS202203131707_B.In1 =
      px42LoopCtrQGCGPS202203131707_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1'
    // InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' 
    px42LoopCtrQGCGPS20220313170_DW.DiscreteTimeIntegrator_DSTAT_fj =
      px42LoopCtrQGCGPS202203131707_P.DiscreteTimeIntegrator_IC;

    // End of SystemInitialize for SubSystem: '<Root>/Subsystem1'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    px42LoopCtrQGCGPS20220313170_DW.obj_n.matlabCodegenIsDeleted = false;
    px42LoopCtrQGCGPS20220313170_DW.obj_n.isSetupComplete = false;
    px42LoopCtrQGCGPS20220313170_DW.obj_n.isInitialized = 1;
    px42LoopCtrQGCGPS20220313170_DW.obj_n.orbMetadataObj = ORB_ID
      (vehicle_odometry);
    uORB_read_initialize(px42LoopCtrQGCGPS20220313170_DW.obj_n.orbMetadataObj,
                         &px42LoopCtrQGCGPS20220313170_DW.obj_n.eventStructObj);
    px42LoopCtrQGCGPS20220313170_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
    //   Constant: '<Root>/Constant2'

    px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus = 0U;
    px42LoopCtrQGCGPS20220313170_DW.obj.isInitialized = 0;
    px42LoopCtrQGCGPS20220313170_DW.obj.matlabCodegenIsDeleted = false;
    px42LoopCtrQGC_SystemCore_setup(&px42LoopCtrQGCGPS20220313170_DW.obj,
      rtb_DataStoreRead6, px42LoopCtrQGCGPS202203131707_P.Constant2_Value_kf);

    // Start for MATLABSystem: '<S6>/SourceBlock'
    px42LoopCtrQGCGPS20220313170_DW.obj_l.matlabCodegenIsDeleted = false;
    px42LoopCtrQGCGPS20220313170_DW.obj_l.isSetupComplete = false;
    px42LoopCtrQGCGPS20220313170_DW.obj_l.isInitialized = 1;
    px42LoopCtrQGCGPS20220313170_DW.obj_l.orbMetadataObj = ORB_ID
      (actuator_outputs);
    uORB_read_initialize(px42LoopCtrQGCGPS20220313170_DW.obj_l.orbMetadataObj,
                         &px42LoopCtrQGCGPS20220313170_DW.obj_l.eventStructObj);
    px42LoopCtrQGCGPS20220313170_DW.obj_l.isSetupComplete = true;
  }
}

// Model terminate function
void px42LoopCtrQGCGPS202203131707_terminate(void)
{
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!px42LoopCtrQGCGPS20220313170_DW.obj_n.matlabCodegenIsDeleted) {
    px42LoopCtrQGCGPS20220313170_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((px42LoopCtrQGCGPS20220313170_DW.obj_n.isInitialized == 1) &&
        px42LoopCtrQGCGPS20220313170_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&px42LoopCtrQGCGPS20220313170_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'

  // Terminate for MATLABSystem: '<Root>/PX4 PWM Output1'
  if (!px42LoopCtrQGCGPS20220313170_DW.obj.matlabCodegenIsDeleted) {
    px42LoopCtrQGCGPS20220313170_DW.obj.matlabCodegenIsDeleted = true;
    if ((px42LoopCtrQGCGPS20220313170_DW.obj.isInitialized == 1) &&
        px42LoopCtrQGCGPS20220313170_DW.obj.isSetupComplete) {
      uint16_T status;
      status = pwm_disarm(&px42LoopCtrQGCGPS20220313170_DW.obj.pwmDevHandler,
                          &px42LoopCtrQGCGPS20220313170_DW.obj.armAdvertiseObj);
      px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus = static_cast<uint16_T>
        (px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus | status);
      status = pwm_resetServo(&px42LoopCtrQGCGPS20220313170_DW.obj.pwmDevHandler,
        px42LoopCtrQGCGPS20220313170_DW.obj.servoCount,
        px42LoopCtrQGCGPS20220313170_DW.obj.channelMask,
        px42LoopCtrQGCGPS20220313170_DW.obj.isMain,
        &px42LoopCtrQGCGPS20220313170_DW.obj.actuatorAdvertiseObj);
      px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus = static_cast<uint16_T>
        (px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus | status);
      status = pwm_close(&px42LoopCtrQGCGPS20220313170_DW.obj.pwmDevHandler,
                         &px42LoopCtrQGCGPS20220313170_DW.obj.actuatorAdvertiseObj,
                         &px42LoopCtrQGCGPS20220313170_DW.obj.armAdvertiseObj);
      px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus = static_cast<uint16_T>
        (px42LoopCtrQGCGPS20220313170_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 PWM Output1'

  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!px42LoopCtrQGCGPS20220313170_DW.obj_l.matlabCodegenIsDeleted) {
    px42LoopCtrQGCGPS20220313170_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((px42LoopCtrQGCGPS20220313170_DW.obj_l.isInitialized == 1) &&
        px42LoopCtrQGCGPS20220313170_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&px42LoopCtrQGCGPS20220313170_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
