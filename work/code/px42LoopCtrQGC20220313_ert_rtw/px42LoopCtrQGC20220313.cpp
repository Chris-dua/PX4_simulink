//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px42LoopCtrQGC20220313.cpp
//
// Code generated for Simulink model 'px42LoopCtrQGC20220313'.
//
// Model version                  : 5.5
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Mar 23 21:30:24 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "px42LoopCtrQGC20220313.h"
#include "rtwtypes.h"
#include "px42LoopCtrQGC20220313_types.h"
#include "px42LoopCtrQGC20220313_private.h"
#include <math.h>

extern "C" {

#include "rt_nonfinite.h"

}
#include <string.h>
#include "rt_defines.h"
#include "zero_crossing_types.h"
#include "px42LoopCtrQGC20220313_dt.h"

// Block signals (default storage)
B_px42LoopCtrQGC20220313_T px42LoopCtrQGC20220313_B;

// Block states (default storage)
DW_px42LoopCtrQGC20220313_T px42LoopCtrQGC20220313_DW;

// Previous zero-crossings (trigger) states
PrevZCX_px42LoopCtrQGC2022031_T px42LoopCtrQGC20220313_PrevZCX;

// External outputs (root outports fed by signals with default storage)
ExtY_px42LoopCtrQGC20220313_T px42LoopCtrQGC20220313_Y;

// Real-time model
RT_MODEL_px42LoopCtrQGC202203_T px42LoopCtrQGC20220313_M_ =
  RT_MODEL_px42LoopCtrQGC202203_T();
RT_MODEL_px42LoopCtrQGC202203_T *const px42LoopCtrQGC20220313_M =
  &px42LoopCtrQGC20220313_M_;

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
void px42LoopCtrQGC20220313_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(px42LoopCtrQGC20220313_M, 1));
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

  (px42LoopCtrQGC20220313_M->Timing.TaskCounters.TID[1])++;
  if ((px42LoopCtrQGC20220313_M->Timing.TaskCounters.TID[1]) > 1) {// Sample time: [0.01s, 0.0s] 
    px42LoopCtrQGC20220313_M->Timing.TaskCounters.TID[1] = 0;
  }
}

//
// Output and update for atomic system:
//    '<S17>/MATLAB Function'
//    '<S26>/MATLAB Function'
//    '<S35>/MATLAB Function'
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
void px42LoopCtrQGC20220313_step0(void) // Sample time: [0.005s, 0.0s]
{
  real_T roll_tmp;
  real_T roll_tmp_0;
  real_T u0_tmp;
  uint16_T status;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_g2;
  boolean_T rtb_Compare_i;
  boolean_T rtb_LogicalOperator;

  {                                    // Sample time: [0.005s, 0.0s]
    rate_monotonic_scheduler();
  }

  // Reset subsysRan breadcrumbs
  srClearBC(px42LoopCtrQGC20220313_DW.Subsystem_SubsysRanBC_k);

  // Reset subsysRan breadcrumbs
  srClearBC(px42LoopCtrQGC20220313_DW.Subsystem_SubsysRanBC_m);

  // Reset subsysRan breadcrumbs
  srClearBC(px42LoopCtrQGC20220313_DW.Subsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px42LoopCtrQGC20220313_DW.EnabledSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px42LoopCtrQGC20220313_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px42LoopCtrQGC20220313_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px42LoopCtrQGC20220313_DW.IfActionSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px42LoopCtrQGC20220313_DW.Subsystem1_SubsysRanBC);

  // Switch: '<S11>/Switch' incorporates:
  //   Constant: '<Root>/Constant3'
  //   Constant: '<S11>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read20'
  //   DataStoreRead: '<S11>/Data Store Read'
  //   DataStoreRead: '<S11>/Data Store Read1'

  if (px42LoopCtrQGC20220313_DW.attitude_flag) {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 =
      px42LoopCtrQGC20220313_DW.yaw;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 =
      px42LoopCtrQGC20220313_P.Constant3_Value_g;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_DW.yaw_speed;
  } else {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 =
      px42LoopCtrQGC20220313_P.Constant1_Value_a;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 =
      px42LoopCtrQGC20220313_P.Constant1_Value_a;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_P.Constant1_Value_a;
  }

  // End of Switch: '<S11>/Switch'

  // RelationalOperator: '<S36>/Compare' incorporates:
  //   Abs: '<S35>/Abs'
  //   Constant: '<S36>/Constant'
  //   DataStoreRead: '<S35>/Data Store Read1'

  rtb_Compare = (fabs(px42LoopCtrQGC20220313_DW.e_pitch_yaw) >=
                 px42LoopCtrQGC20220313_P.CompareToConstant1_const);

  // Sum: '<S35>/Add' incorporates:
  //   DataStoreRead: '<S35>/Data Store Read'
  //   DataStoreRead: '<S35>/Data Store Read3'
  //   Sum: '<S38>/Add'

  px42LoopCtrQGC20220313_B.Abs6 = px42LoopCtrQGC20220313_DW.t -
    px42LoopCtrQGC20220313_DW.start_time_yaw;

  // Fcn: '<S35>/Fcn' incorporates:
  //   Constant: '<S35>/T'
  //   Constant: '<S35>/ch'
  //   Sum: '<S35>/Add'

  px42LoopCtrQGC20220313_B.rtb_Fcn_c = px42LoopCtrQGC20220313_P.ch_Value /
    (px42LoopCtrQGC20220313_P.T_Value - px42LoopCtrQGC20220313_B.Abs6);

  // MATLAB Function: '<S35>/MATLAB Function' incorporates:
  //   Constant: '<S35>/t'
  //   DataStoreRead: '<S35>/Data Store Read'
  //   DataStoreRead: '<S35>/Data Store Read3'

  px42LoopCtrQ_MATLABFunction(rtb_Compare, px42LoopCtrQGC20220313_DW.t,
    px42LoopCtrQGC20220313_DW.start_time_yaw, px42LoopCtrQGC20220313_B.rtb_Fcn_c,
    px42LoopCtrQGC20220313_P.t_Value, &px42LoopCtrQGC20220313_B.y);

  // Sum: '<S35>/Add1' incorporates:
  //   Constant: '<S35>/r'

  px42LoopCtrQGC20220313_B.z2 = px42LoopCtrQGC20220313_P.r_Value +
    px42LoopCtrQGC20220313_B.y;

  // Sum: '<S34>/Add' incorporates:
  //   Sum: '<S11>/Add2'

  px42LoopCtrQGC20220313_DW.e_pitch_yaw =
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 -
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1;

  // Gain: '<S34>/Gain4' incorporates:
  //   Constant: '<S11>/b'
  //   Product: '<S34>/Product'
  //   Sum: '<S34>/Add'

  px42LoopCtrQGC20220313_B.ManualSwitch_g =
    px42LoopCtrQGC20220313_DW.e_pitch_yaw * px42LoopCtrQGC20220313_B.z2 *
    px42LoopCtrQGC20220313_P.b_Value * px42LoopCtrQGC20220313_P.Gain4_Gain;

  // SampleTimeMath: '<S33>/TSamp'
  //
  //  About '<S33>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px42LoopCtrQGC20220313_B.TSamp = px42LoopCtrQGC20220313_B.ManualSwitch_g *
    px42LoopCtrQGC20220313_P.TSamp_WtEt;

  // Sum: '<S11>/Add1'
  px42LoopCtrQGC20220313_B.ManualSwitch_g =
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 -
    px42LoopCtrQGC20220313_B.ManualSwitch_g;

  // Gain: '<S1>/Gain1' incorporates:
  //   DiscreteIntegrator: '<S14>/Discrete-Time Integrator3'

  px42LoopCtrQGC20220313_B.Product6_a = px42LoopCtrQGC20220313_P.Gain1_Gain_o *
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator3_DSTATE;

  // Signum: '<S11>/Sign'
  if (rtIsNaN(px42LoopCtrQGC20220313_B.ManualSwitch_g)) {
    px42LoopCtrQGC20220313_B.fcn5 = px42LoopCtrQGC20220313_B.ManualSwitch_g;
  } else if (px42LoopCtrQGC20220313_B.ManualSwitch_g < 0.0) {
    px42LoopCtrQGC20220313_B.fcn5 = -1.0;
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = (px42LoopCtrQGC20220313_B.ManualSwitch_g >
      0.0);
  }

  // End of Signum: '<S11>/Sign'

  // Saturate: '<S1>/Saturation4'
  if (px42LoopCtrQGC20220313_B.Product6_a >
      px42LoopCtrQGC20220313_P.Saturation4_UpperSat) {
    px42LoopCtrQGC20220313_B.Product6_a =
      px42LoopCtrQGC20220313_P.Saturation4_UpperSat;
  } else if (px42LoopCtrQGC20220313_B.Product6_a <
             px42LoopCtrQGC20220313_P.Saturation4_LowerSat) {
    px42LoopCtrQGC20220313_B.Product6_a =
      px42LoopCtrQGC20220313_P.Saturation4_LowerSat;
  }

  // End of Saturate: '<S1>/Saturation4'

  // Sum: '<S1>/Add3' incorporates:
  //   Constant: '<S11>/b'
  //   Constant: '<S11>/l'
  //   DataStoreWrite: '<S11>/Data Store Write'
  //   Gain: '<S11>/Gain'
  //   Gain: '<S11>/Gain1'
  //   Product: '<S11>/Product'
  //   Product: '<S11>/Product1'
  //   Sum: '<S11>/Add'
  //   Sum: '<S33>/Diff'
  //   UnitDelay: '<S33>/UD'
  //
  //  Block description for '<S33>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S33>/UD':
  //
  //   Store in Global RAM

  px42LoopCtrQGC20220313_B.Add3 = (((((px42LoopCtrQGC20220313_B.TSamp -
    px42LoopCtrQGC20220313_DW.UD_DSTATE) - px42LoopCtrQGC20220313_DW.e_pitch_yaw)
    - px42LoopCtrQGC20220313_B.ManualSwitch_g * px42LoopCtrQGC20220313_B.z2 *
    px42LoopCtrQGC20220313_P.b_Value) - px42LoopCtrQGC20220313_B.fcn5 *
    px42LoopCtrQGC20220313_P.l_Value) - px42LoopCtrQGC20220313_P.Gain_Gain *
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2) *
    px42LoopCtrQGC20220313_P.Gain1_Gain - px42LoopCtrQGC20220313_B.Product6_a;

  // ManualSwitch: '<S1>/Manual Switch' incorporates:
  //   Constant: '<S1>/Constant'
  //   DataStoreWrite: '<Root>/Data Store Write11'

  if (px42LoopCtrQGC20220313_P.ManualSwitch_CurrentSetting == 1) {
    // Saturate: '<S1>/Saturation'
    if (px42LoopCtrQGC20220313_B.Add3 >
        px42LoopCtrQGC20220313_P.Saturation_UpperSat) {
      px42LoopCtrQGC20220313_B.DataStoreRead27 =
        px42LoopCtrQGC20220313_P.Saturation_UpperSat;
    } else if (px42LoopCtrQGC20220313_B.Add3 <
               px42LoopCtrQGC20220313_P.Saturation_LowerSat) {
      px42LoopCtrQGC20220313_B.DataStoreRead27 =
        px42LoopCtrQGC20220313_P.Saturation_LowerSat;
    } else {
      px42LoopCtrQGC20220313_B.DataStoreRead27 = px42LoopCtrQGC20220313_B.Add3;
    }

    // End of Saturate: '<S1>/Saturation'
  } else {
    px42LoopCtrQGC20220313_B.DataStoreRead27 =
      px42LoopCtrQGC20220313_P.Constant_Value_b;
  }

  // End of ManualSwitch: '<S1>/Manual Switch'

  // Sin: '<Root>/Sine Wave'
  if (px42LoopCtrQGC20220313_DW.systemEnable != 0) {
    px42LoopCtrQGC20220313_B.z2 = px42LoopCtrQGC20220313_P.SineWave_Freq *
      px42LoopCtrQGC20220313_M->Timing.taskTime0;
    px42LoopCtrQGC20220313_DW.lastSin = sin(px42LoopCtrQGC20220313_B.z2);
    px42LoopCtrQGC20220313_DW.lastCos = cos(px42LoopCtrQGC20220313_B.z2);
    px42LoopCtrQGC20220313_DW.systemEnable = 0;
  }

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Constant: '<Root>/Constant3'
  //   Sin: '<Root>/Sine Wave'

  if (px42LoopCtrQGC20220313_P.ManualSwitch_CurrentSetting_i == 1) {
    px42LoopCtrQGC20220313_B.ManualSwitch_g =
      ((px42LoopCtrQGC20220313_DW.lastSin *
        px42LoopCtrQGC20220313_P.SineWave_PCos +
        px42LoopCtrQGC20220313_DW.lastCos *
        px42LoopCtrQGC20220313_P.SineWave_PSin) *
       px42LoopCtrQGC20220313_P.SineWave_HCos +
       (px42LoopCtrQGC20220313_DW.lastCos *
        px42LoopCtrQGC20220313_P.SineWave_PCos -
        px42LoopCtrQGC20220313_DW.lastSin *
        px42LoopCtrQGC20220313_P.SineWave_PSin) *
       px42LoopCtrQGC20220313_P.SineWave_Hsin) *
      px42LoopCtrQGC20220313_P.SineWave_Amp +
      px42LoopCtrQGC20220313_P.SineWave_Bias;
  } else {
    px42LoopCtrQGC20220313_B.ManualSwitch_g =
      px42LoopCtrQGC20220313_P.Constant3_Value_g;
  }

  // End of ManualSwitch: '<Root>/Manual Switch'

  // Switch: '<S9>/Switch' incorporates:
  //   Constant: '<S9>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read14'
  //   DataStoreRead: '<S9>/Data Store Read'
  //   DataStoreRead: '<S9>/Data Store Read1'

  if (px42LoopCtrQGC20220313_DW.attitude_flag) {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 =
      px42LoopCtrQGC20220313_DW.pitch;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 =
      px42LoopCtrQGC20220313_B.ManualSwitch_g;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_DW.pitch_speed;
  } else {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 =
      px42LoopCtrQGC20220313_P.Constant1_Value;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 =
      px42LoopCtrQGC20220313_P.Constant1_Value;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_P.Constant1_Value;
  }

  // End of Switch: '<S9>/Switch'

  // RelationalOperator: '<S18>/Compare' incorporates:
  //   Abs: '<S17>/Abs'
  //   Constant: '<S18>/Constant'
  //   DataStoreRead: '<S17>/Data Store Read1'

  rtb_Compare_i = (fabs(px42LoopCtrQGC20220313_DW.e_pitch) >=
                   px42LoopCtrQGC20220313_P.CompareToConstant1_const_b);

  // Sum: '<S17>/Add' incorporates:
  //   DataStoreRead: '<S17>/Data Store Read'
  //   DataStoreRead: '<S17>/Data Store Read3'
  //   Sum: '<S20>/Add'

  px42LoopCtrQGC20220313_B.Product4 = px42LoopCtrQGC20220313_DW.t -
    px42LoopCtrQGC20220313_DW.start_time;

  // Fcn: '<S17>/Fcn' incorporates:
  //   Constant: '<S17>/T'
  //   Constant: '<S17>/ch'
  //   Sum: '<S17>/Add'

  px42LoopCtrQGC20220313_B.rtb_Fcn_b_k = px42LoopCtrQGC20220313_P.ch_Value_j /
    (px42LoopCtrQGC20220313_P.T_Value_p - px42LoopCtrQGC20220313_B.Product4);

  // MATLAB Function: '<S17>/MATLAB Function' incorporates:
  //   Constant: '<S17>/t'
  //   DataStoreRead: '<S17>/Data Store Read'
  //   DataStoreRead: '<S17>/Data Store Read3'

  px42LoopCtrQ_MATLABFunction(rtb_Compare_i, px42LoopCtrQGC20220313_DW.t,
    px42LoopCtrQGC20220313_DW.start_time, px42LoopCtrQGC20220313_B.rtb_Fcn_b_k,
    px42LoopCtrQGC20220313_P.t_Value_n, &px42LoopCtrQGC20220313_B.y_j);

  // Sum: '<S17>/Add1' incorporates:
  //   Constant: '<S17>/r'

  px42LoopCtrQGC20220313_B.z2_e = px42LoopCtrQGC20220313_P.r_Value_g +
    px42LoopCtrQGC20220313_B.y_j;

  // Sum: '<S16>/Add' incorporates:
  //   Sum: '<S9>/Add2'

  px42LoopCtrQGC20220313_DW.e_pitch =
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 -
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1;

  // Gain: '<S16>/Gain4' incorporates:
  //   Constant: '<S9>/b'
  //   Product: '<S16>/Product'
  //   Sum: '<S16>/Add'

  px42LoopCtrQGC20220313_B.roll_hat = px42LoopCtrQGC20220313_DW.e_pitch *
    px42LoopCtrQGC20220313_B.z2_e * px42LoopCtrQGC20220313_P.b_Value_l *
    px42LoopCtrQGC20220313_P.Gain4_Gain_b;

  // SampleTimeMath: '<S15>/TSamp'
  //
  //  About '<S15>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px42LoopCtrQGC20220313_B.z2 = px42LoopCtrQGC20220313_B.roll_hat *
    px42LoopCtrQGC20220313_P.TSamp_WtEt_p;

  // Sum: '<S9>/Add1'
  px42LoopCtrQGC20220313_B.roll_hat =
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 -
    px42LoopCtrQGC20220313_B.roll_hat;

  // Gain: '<S1>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S12>/Discrete-Time Integrator3'

  px42LoopCtrQGC20220313_B.Gain2 = px42LoopCtrQGC20220313_P.Gain2_Gain *
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator3_DSTAT_a;

  // Signum: '<S9>/Sign'
  if (rtIsNaN(px42LoopCtrQGC20220313_B.roll_hat)) {
    px42LoopCtrQGC20220313_B.fcn5 = px42LoopCtrQGC20220313_B.roll_hat;
  } else if (px42LoopCtrQGC20220313_B.roll_hat < 0.0) {
    px42LoopCtrQGC20220313_B.fcn5 = -1.0;
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = (px42LoopCtrQGC20220313_B.roll_hat > 0.0);
  }

  // End of Signum: '<S9>/Sign'

  // Sum: '<S1>/Add2' incorporates:
  //   Constant: '<S9>/b'
  //   Constant: '<S9>/l'
  //   DataStoreWrite: '<Root>/Data Store Write12'
  //   DataStoreWrite: '<S9>/Data Store Write'
  //   Gain: '<S9>/Gain'
  //   Gain: '<S9>/Gain1'
  //   Product: '<S9>/Product'
  //   Product: '<S9>/Product1'
  //   Sum: '<S15>/Diff'
  //   Sum: '<S9>/Add'
  //   UnitDelay: '<S15>/UD'
  //
  //  Block description for '<S15>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S15>/UD':
  //
  //   Store in Global RAM

  px42LoopCtrQGC20220313_B.DataStoreRead25 = (((((px42LoopCtrQGC20220313_B.z2 -
    px42LoopCtrQGC20220313_DW.UD_DSTATE_b) - px42LoopCtrQGC20220313_DW.e_pitch)
    - px42LoopCtrQGC20220313_B.roll_hat * px42LoopCtrQGC20220313_B.z2_e *
    px42LoopCtrQGC20220313_P.b_Value_l) - px42LoopCtrQGC20220313_B.fcn5 *
    px42LoopCtrQGC20220313_P.l_Value_b) - px42LoopCtrQGC20220313_P.Gain_Gain_o *
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2) *
    px42LoopCtrQGC20220313_P.Gain1_Gain_b - px42LoopCtrQGC20220313_B.Gain2;

  // Switch: '<S10>/Switch' incorporates:
  //   Constant: '<S10>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read18'
  //   DataStoreRead: '<S10>/Data Store Read'
  //   DataStoreRead: '<S10>/Data Store Read1'

  if (px42LoopCtrQGC20220313_DW.attitude_flag) {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 =
      px42LoopCtrQGC20220313_DW.roll;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 =
      px42LoopCtrQGC20220313_B.ManualSwitch_g;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_DW.roll_speed;
  } else {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 =
      px42LoopCtrQGC20220313_P.Constant1_Value_n;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 =
      px42LoopCtrQGC20220313_P.Constant1_Value_n;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_P.Constant1_Value_n;
  }

  // End of Switch: '<S10>/Switch'

  // RelationalOperator: '<S27>/Compare' incorporates:
  //   Abs: '<S26>/Abs'
  //   Constant: '<S27>/Constant'
  //   DataStoreRead: '<S26>/Data Store Read1'

  rtb_Compare_g2 = (fabs(px42LoopCtrQGC20220313_DW.e_pitch_roll) >=
                    px42LoopCtrQGC20220313_P.CompareToConstant1_const_h);

  // Sum: '<S26>/Add' incorporates:
  //   DataStoreRead: '<S26>/Data Store Read'
  //   DataStoreRead: '<S26>/Data Store Read3'
  //   Sum: '<S29>/Add'

  px42LoopCtrQGC20220313_B.Product6 = px42LoopCtrQGC20220313_DW.t -
    px42LoopCtrQGC20220313_DW.start_time_roll;

  // Fcn: '<S26>/Fcn' incorporates:
  //   Constant: '<S26>/T'
  //   Constant: '<S26>/ch'
  //   Sum: '<S26>/Add'

  px42LoopCtrQGC20220313_B.rtb_Fcn_a_c = px42LoopCtrQGC20220313_P.ch_Value_e /
    (px42LoopCtrQGC20220313_P.T_Value_c - px42LoopCtrQGC20220313_B.Product6);

  // MATLAB Function: '<S26>/MATLAB Function' incorporates:
  //   Constant: '<S26>/t'
  //   DataStoreRead: '<S26>/Data Store Read'
  //   DataStoreRead: '<S26>/Data Store Read3'

  px42LoopCtrQ_MATLABFunction(rtb_Compare_g2, px42LoopCtrQGC20220313_DW.t,
    px42LoopCtrQGC20220313_DW.start_time_roll,
    px42LoopCtrQGC20220313_B.rtb_Fcn_a_c, px42LoopCtrQGC20220313_P.t_Value_m,
    &px42LoopCtrQGC20220313_B.y_o);

  // Sum: '<S26>/Add1' incorporates:
  //   Constant: '<S26>/r'

  px42LoopCtrQGC20220313_B.z2_l = px42LoopCtrQGC20220313_P.r_Value_p +
    px42LoopCtrQGC20220313_B.y_o;

  // Sum: '<S25>/Add' incorporates:
  //   Sum: '<S10>/Add2'

  px42LoopCtrQGC20220313_DW.e_pitch_roll =
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 -
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1;

  // Gain: '<S25>/Gain4' incorporates:
  //   Constant: '<S10>/b'
  //   Product: '<S25>/Product'
  //   Sum: '<S25>/Add'

  px42LoopCtrQGC20220313_B.roll_hat = px42LoopCtrQGC20220313_DW.e_pitch_roll *
    px42LoopCtrQGC20220313_B.z2_l * px42LoopCtrQGC20220313_P.b_Value_h *
    px42LoopCtrQGC20220313_P.Gain4_Gain_o;

  // SampleTimeMath: '<S24>/TSamp'
  //
  //  About '<S24>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px42LoopCtrQGC20220313_B.z2_e = px42LoopCtrQGC20220313_B.roll_hat *
    px42LoopCtrQGC20220313_P.TSamp_WtEt_o;

  // Sum: '<S10>/Add1'
  px42LoopCtrQGC20220313_B.roll_hat =
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 -
    px42LoopCtrQGC20220313_B.roll_hat;

  // Gain: '<S1>/J' incorporates:
  //   DiscreteIntegrator: '<S13>/Discrete-Time Integrator3'

  px42LoopCtrQGC20220313_B.J = px42LoopCtrQGC20220313_P.J_Gain_b *
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator3_DSTAT_m;

  // Signum: '<S10>/Sign'
  if (rtIsNaN(px42LoopCtrQGC20220313_B.roll_hat)) {
    px42LoopCtrQGC20220313_B.fcn5 = px42LoopCtrQGC20220313_B.roll_hat;
  } else if (px42LoopCtrQGC20220313_B.roll_hat < 0.0) {
    px42LoopCtrQGC20220313_B.fcn5 = -1.0;
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = (px42LoopCtrQGC20220313_B.roll_hat > 0.0);
  }

  // End of Signum: '<S10>/Sign'

  // Sum: '<S1>/Add1' incorporates:
  //   Constant: '<S10>/b'
  //   Constant: '<S10>/l'
  //   DataStoreWrite: '<Root>/Data Store Write13'
  //   DataStoreWrite: '<S10>/Data Store Write'
  //   Gain: '<S10>/Gain'
  //   Gain: '<S10>/J'
  //   Product: '<S10>/Product'
  //   Product: '<S10>/Product1'
  //   Sum: '<S10>/Add'
  //   Sum: '<S24>/Diff'
  //   UnitDelay: '<S24>/UD'
  //
  //  Block description for '<S24>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S24>/UD':
  //
  //   Store in Global RAM

  px42LoopCtrQGC20220313_B.DataStoreRead26 = (((((px42LoopCtrQGC20220313_B.z2_e
    - px42LoopCtrQGC20220313_DW.UD_DSTATE_n) -
    px42LoopCtrQGC20220313_DW.e_pitch_roll) - px42LoopCtrQGC20220313_B.roll_hat *
    px42LoopCtrQGC20220313_B.z2_l * px42LoopCtrQGC20220313_P.b_Value_h) -
    px42LoopCtrQGC20220313_B.fcn5 * px42LoopCtrQGC20220313_P.l_Value_n) -
    px42LoopCtrQGC20220313_P.Gain_Gain_m *
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2) *
    px42LoopCtrQGC20220313_P.J_Gain - px42LoopCtrQGC20220313_B.J;

  // DataStoreRead: '<S35>/Data Store Read4'
  px42LoopCtrQGC20220313_B.DataStoreRead4 =
    px42LoopCtrQGC20220313_DW.start_time_yaw;

  // Logic: '<S38>/Logical Operator' incorporates:
  //   Abs: '<S38>/Abs1'
  //   Constant: '<S39>/Constant'
  //   Constant: '<S40>/Constant'
  //   DataStoreRead: '<S38>/Data Store Read2'
  //   RelationalOperator: '<S39>/Compare'
  //   RelationalOperator: '<S40>/Compare'

  rtb_LogicalOperator = ((fabs(px42LoopCtrQGC20220313_DW.e_pitch_yaw) >=
    px42LoopCtrQGC20220313_P.CompareToConstant2_const) &&
    (px42LoopCtrQGC20220313_B.Abs6 >=
     px42LoopCtrQGC20220313_P.CompareToConstant1_const_hq));

  // Outputs for Triggered SubSystem: '<S38>/Subsystem' incorporates:
  //   TriggerPort: '<S41>/Trigger'

  if (rtb_LogicalOperator && (px42LoopCtrQGC20220313_PrevZCX.Subsystem_Trig_ZCE
       != POS_ZCSIG)) {
    // DataStoreWrite: '<S41>/Data Store Write' incorporates:
    //   DataStoreRead: '<S41>/Data Store Read2'

    px42LoopCtrQGC20220313_DW.start_time_yaw = px42LoopCtrQGC20220313_DW.t;
    px42LoopCtrQGC20220313_DW.Subsystem_SubsysRanBC = 4;
  }

  px42LoopCtrQGC20220313_PrevZCX.Subsystem_Trig_ZCE = rtb_LogicalOperator;

  // End of Outputs for SubSystem: '<S38>/Subsystem'
  // DataStoreRead: '<S17>/Data Store Read4'
  px42LoopCtrQGC20220313_B.DataStoreRead4_g =
    px42LoopCtrQGC20220313_DW.start_time;

  // Logic: '<S20>/Logical Operator' incorporates:
  //   Abs: '<S20>/Abs1'
  //   Constant: '<S21>/Constant'
  //   Constant: '<S22>/Constant'
  //   DataStoreRead: '<S20>/Data Store Read2'
  //   RelationalOperator: '<S21>/Compare'
  //   RelationalOperator: '<S22>/Compare'

  rtb_LogicalOperator = ((fabs(px42LoopCtrQGC20220313_DW.e_pitch) >=
    px42LoopCtrQGC20220313_P.CompareToConstant2_const_o) &&
    (px42LoopCtrQGC20220313_B.Product4 >=
     px42LoopCtrQGC20220313_P.CompareToConstant1_const_p));

  // Outputs for Triggered SubSystem: '<S20>/Subsystem' incorporates:
  //   TriggerPort: '<S23>/Trigger'

  if (rtb_LogicalOperator &&
      (px42LoopCtrQGC20220313_PrevZCX.Subsystem_Trig_ZCE_e != POS_ZCSIG)) {
    // DataStoreWrite: '<S23>/Data Store Write' incorporates:
    //   DataStoreRead: '<S23>/Data Store Read2'

    px42LoopCtrQGC20220313_DW.start_time = px42LoopCtrQGC20220313_DW.t;
    px42LoopCtrQGC20220313_DW.Subsystem_SubsysRanBC_k = 4;
  }

  px42LoopCtrQGC20220313_PrevZCX.Subsystem_Trig_ZCE_e = rtb_LogicalOperator;

  // End of Outputs for SubSystem: '<S20>/Subsystem'
  // DataStoreRead: '<S26>/Data Store Read4'
  px42LoopCtrQGC20220313_B.DataStoreRead4_b =
    px42LoopCtrQGC20220313_DW.start_time_roll;

  // Logic: '<S29>/Logical Operator' incorporates:
  //   Abs: '<S29>/Abs1'
  //   Constant: '<S30>/Constant'
  //   Constant: '<S31>/Constant'
  //   DataStoreRead: '<S29>/Data Store Read2'
  //   RelationalOperator: '<S30>/Compare'
  //   RelationalOperator: '<S31>/Compare'

  rtb_LogicalOperator = ((fabs(px42LoopCtrQGC20220313_DW.e_pitch_roll) >=
    px42LoopCtrQGC20220313_P.CompareToConstant2_const_a) &&
    (px42LoopCtrQGC20220313_B.Product6 >=
     px42LoopCtrQGC20220313_P.CompareToConstant1_const_a));

  // Outputs for Triggered SubSystem: '<S29>/Subsystem' incorporates:
  //   TriggerPort: '<S32>/Trigger'

  if (rtb_LogicalOperator &&
      (px42LoopCtrQGC20220313_PrevZCX.Subsystem_Trig_ZCE_j != POS_ZCSIG)) {
    // DataStoreWrite: '<S32>/Data Store Write' incorporates:
    //   DataStoreRead: '<S32>/Data Store Read2'

    px42LoopCtrQGC20220313_DW.start_time_roll = px42LoopCtrQGC20220313_DW.t;
    px42LoopCtrQGC20220313_DW.Subsystem_SubsysRanBC_m = 4;
  }

  px42LoopCtrQGC20220313_PrevZCX.Subsystem_Trig_ZCE_j = rtb_LogicalOperator;

  // End of Outputs for SubSystem: '<S29>/Subsystem'

  // Gain: '<S14>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S14>/Discrete-Time Integrator'

  px42LoopCtrQGC20220313_B.rolldegree = px42LoopCtrQGC20220313_P.Gain2_Gain_c *
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTATE;

  // Switch: '<S14>/Switch' incorporates:
  //   Constant: '<S14>/Constant3'
  //   DataStoreRead: '<S14>/Data Store Read'
  //   DataStoreRead: '<S14>/Data Store Read1'
  //   DataStoreRead: '<S14>/Data Store Read2'
  //   Gain: '<S14>/1//J'
  //   Gain: '<S14>/k//J'
  //   ZeroOrderHold: '<S14>/Zero-Order Hold1'

  if (px42LoopCtrQGC20220313_DW.observer_flag) {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 =
      px42LoopCtrQGC20220313_P.uJ_Gain * px42LoopCtrQGC20220313_B.Add3;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 =
      px42LoopCtrQGC20220313_P.kJ_Gain * px42LoopCtrQGC20220313_DW.yaw_speed;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_DW.yaw;
  } else {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 =
      px42LoopCtrQGC20220313_P.Constant3_Value_d;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 =
      px42LoopCtrQGC20220313_P.Constant3_Value_d;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_P.Constant3_Value_d;
  }

  // End of Switch: '<S14>/Switch'

  // Sum: '<S14>/Add1' incorporates:
  //   DiscreteIntegrator: '<S14>/Discrete-Time Integrator'

  px42LoopCtrQGC20220313_B.Abs6 =
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 -
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTATE;

  // Abs: '<S14>/Abs3' incorporates:
  //   Abs: '<S14>/Abs4'
  //   Abs: '<S14>/Abs5'
  //   Abs: '<S14>/Abs6'

  px42LoopCtrQGC20220313_B.z2_l = fabs(px42LoopCtrQGC20220313_B.Abs6);

  // Sum: '<S14>/Add7' incorporates:
  //   Constant: '<S14>/Constant1'
  //   Sum: '<S14>/Add13'
  //   Sum: '<S14>/Add18'

  px42LoopCtrQGC20220313_B.lambda4_h =
    px42LoopCtrQGC20220313_P.Constant1_Value_f + px42LoopCtrQGC20220313_B.Abs6;

  // Sum: '<S14>/Add6' incorporates:
  //   Constant: '<S14>/Constant1'
  //   Sum: '<S14>/Add12'
  //   Sum: '<S14>/Add17'

  u0_tmp = px42LoopCtrQGC20220313_B.Abs6 -
    px42LoopCtrQGC20220313_P.Constant1_Value_f;

  // Saturate: '<S14>/Saturation10' incorporates:
  //   Sum: '<S14>/Add7'

  if (px42LoopCtrQGC20220313_B.lambda4_h >
      px42LoopCtrQGC20220313_P.Saturation10_UpperSat) {
    px42LoopCtrQGC20220313_B.Product6_a =
      px42LoopCtrQGC20220313_P.Saturation10_UpperSat;
  } else if (px42LoopCtrQGC20220313_B.lambda4_h <
             px42LoopCtrQGC20220313_P.Saturation10_LowerSat) {
    px42LoopCtrQGC20220313_B.Product6_a =
      px42LoopCtrQGC20220313_P.Saturation10_LowerSat;
  } else {
    px42LoopCtrQGC20220313_B.Product6_a = px42LoopCtrQGC20220313_B.lambda4_h;
  }

  // End of Saturate: '<S14>/Saturation10'

  // Saturate: '<S14>/Saturation11' incorporates:
  //   Sum: '<S14>/Add6'

  if (u0_tmp > px42LoopCtrQGC20220313_P.Saturation11_UpperSat) {
    px42LoopCtrQGC20220313_B.Product5_l =
      px42LoopCtrQGC20220313_P.Saturation11_UpperSat;
  } else if (u0_tmp < px42LoopCtrQGC20220313_P.Saturation11_LowerSat) {
    px42LoopCtrQGC20220313_B.Product5_l =
      px42LoopCtrQGC20220313_P.Saturation11_LowerSat;
  } else {
    px42LoopCtrQGC20220313_B.Product5_l = u0_tmp;
  }

  // End of Saturate: '<S14>/Saturation11'

  // Gain: '<S14>/Gain' incorporates:
  //   Sum: '<S14>/Add8'

  px42LoopCtrQGC20220313_B.roll_hat_e = (px42LoopCtrQGC20220313_B.Product6_a -
    px42LoopCtrQGC20220313_B.Product5_l) * px42LoopCtrQGC20220313_P.Gain_Gain_ml;

  // Fcn: '<S14>/Fcn3' incorporates:
  //   Constant: '<S14>/Constant1'

  if (px42LoopCtrQGC20220313_P.Constant1_Value_f < 0.0) {
    px42LoopCtrQGC20220313_B.fcn5 = -rt_powd_snf
      (-px42LoopCtrQGC20220313_P.Constant1_Value_f, -0.5);
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = rt_powd_snf
      (px42LoopCtrQGC20220313_P.Constant1_Value_f, -0.5);
  }

  // End of Fcn: '<S14>/Fcn3'

  // Product: '<S14>/Product3'
  px42LoopCtrQGC20220313_B.Add3 = px42LoopCtrQGC20220313_B.fcn5 *
    px42LoopCtrQGC20220313_B.roll_hat_e * px42LoopCtrQGC20220313_B.Abs6;

  // Saturate: '<S14>/Saturation8'
  if (px42LoopCtrQGC20220313_B.Abs6 >
      px42LoopCtrQGC20220313_P.Saturation8_UpperSat) {
    px42LoopCtrQGC20220313_B.Product2_d =
      px42LoopCtrQGC20220313_P.Saturation8_UpperSat;
  } else if (px42LoopCtrQGC20220313_B.Abs6 <
             px42LoopCtrQGC20220313_P.Saturation8_LowerSat) {
    px42LoopCtrQGC20220313_B.Product2_d =
      px42LoopCtrQGC20220313_P.Saturation8_LowerSat;
  } else {
    px42LoopCtrQGC20220313_B.Product2_d = px42LoopCtrQGC20220313_B.Abs6;
  }

  // End of Saturate: '<S14>/Saturation8'

  // Product: '<S14>/Product4' incorporates:
  //   Abs: '<S14>/Abs3'
  //   Constant: '<S14>/Constant2'
  //   Fcn: '<S14>/Fcn4'
  //   Sum: '<S14>/Add10'

  px42LoopCtrQGC20220313_B.Product4 = rt_powd_snf(px42LoopCtrQGC20220313_B.z2_l,
    0.5) * px42LoopCtrQGC20220313_B.Product2_d *
    (px42LoopCtrQGC20220313_P.Constant2_Value -
     px42LoopCtrQGC20220313_B.roll_hat_e);

  // Saturate: '<S14>/Saturation13'
  if (px42LoopCtrQGC20220313_B.lambda4_h >
      px42LoopCtrQGC20220313_P.Saturation13_UpperSat) {
    px42LoopCtrQGC20220313_B.Product6_a =
      px42LoopCtrQGC20220313_P.Saturation13_UpperSat;
  } else if (px42LoopCtrQGC20220313_B.lambda4_h <
             px42LoopCtrQGC20220313_P.Saturation13_LowerSat) {
    px42LoopCtrQGC20220313_B.Product6_a =
      px42LoopCtrQGC20220313_P.Saturation13_LowerSat;
  } else {
    px42LoopCtrQGC20220313_B.Product6_a = px42LoopCtrQGC20220313_B.lambda4_h;
  }

  // End of Saturate: '<S14>/Saturation13'

  // Saturate: '<S14>/Saturation9'
  if (u0_tmp > px42LoopCtrQGC20220313_P.Saturation9_UpperSat) {
    px42LoopCtrQGC20220313_B.Product5_l =
      px42LoopCtrQGC20220313_P.Saturation9_UpperSat;
  } else if (u0_tmp < px42LoopCtrQGC20220313_P.Saturation9_LowerSat) {
    px42LoopCtrQGC20220313_B.Product5_l =
      px42LoopCtrQGC20220313_P.Saturation9_LowerSat;
  } else {
    px42LoopCtrQGC20220313_B.Product5_l = u0_tmp;
  }

  // End of Saturate: '<S14>/Saturation9'

  // Gain: '<S14>/Gain1' incorporates:
  //   Sum: '<S14>/Add14'

  px42LoopCtrQGC20220313_B.roll_hat_e = (px42LoopCtrQGC20220313_B.Product6_a -
    px42LoopCtrQGC20220313_B.Product5_l) * px42LoopCtrQGC20220313_P.Gain1_Gain_a;

  // Fcn: '<S14>/Fcn6' incorporates:
  //   Constant: '<S14>/Constant1'

  if (px42LoopCtrQGC20220313_P.Constant1_Value_f < 0.0) {
    px42LoopCtrQGC20220313_B.fcn5 = -rt_powd_snf
      (-px42LoopCtrQGC20220313_P.Constant1_Value_f, -0.9375);
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = rt_powd_snf
      (px42LoopCtrQGC20220313_P.Constant1_Value_f, -0.9375);
  }

  // End of Fcn: '<S14>/Fcn6'

  // Product: '<S14>/Product6'
  px42LoopCtrQGC20220313_B.Product6 = px42LoopCtrQGC20220313_B.fcn5 *
    px42LoopCtrQGC20220313_B.roll_hat_e * px42LoopCtrQGC20220313_B.Abs6;

  // Saturate: '<S14>/Saturation12'
  if (px42LoopCtrQGC20220313_B.Abs6 >
      px42LoopCtrQGC20220313_P.Saturation12_UpperSat) {
    px42LoopCtrQGC20220313_B.Product2_d =
      px42LoopCtrQGC20220313_P.Saturation12_UpperSat;
  } else if (px42LoopCtrQGC20220313_B.Abs6 <
             px42LoopCtrQGC20220313_P.Saturation12_LowerSat) {
    px42LoopCtrQGC20220313_B.Product2_d =
      px42LoopCtrQGC20220313_P.Saturation12_LowerSat;
  } else {
    px42LoopCtrQGC20220313_B.Product2_d = px42LoopCtrQGC20220313_B.Abs6;
  }

  // End of Saturate: '<S14>/Saturation12'

  // Product: '<S14>/Product5' incorporates:
  //   Constant: '<S14>/Constant4'
  //   Fcn: '<S14>/Fcn5'
  //   Sum: '<S14>/Add11'

  px42LoopCtrQGC20220313_B.roll_hat = rt_powd_snf(px42LoopCtrQGC20220313_B.z2_l,
    0.0625) * px42LoopCtrQGC20220313_B.Product2_d *
    (px42LoopCtrQGC20220313_P.Constant4_Value -
     px42LoopCtrQGC20220313_B.roll_hat_e);

  // Saturate: '<S14>/Saturation16'
  if (px42LoopCtrQGC20220313_B.lambda4_h >
      px42LoopCtrQGC20220313_P.Saturation16_UpperSat) {
    px42LoopCtrQGC20220313_B.lambda4_h =
      px42LoopCtrQGC20220313_P.Saturation16_UpperSat;
  } else if (px42LoopCtrQGC20220313_B.lambda4_h <
             px42LoopCtrQGC20220313_P.Saturation16_LowerSat) {
    px42LoopCtrQGC20220313_B.lambda4_h =
      px42LoopCtrQGC20220313_P.Saturation16_LowerSat;
  }

  // End of Saturate: '<S14>/Saturation16'

  // Saturate: '<S14>/Saturation14'
  if (u0_tmp > px42LoopCtrQGC20220313_P.Saturation14_UpperSat) {
    u0_tmp = px42LoopCtrQGC20220313_P.Saturation14_UpperSat;
  } else if (u0_tmp < px42LoopCtrQGC20220313_P.Saturation14_LowerSat) {
    u0_tmp = px42LoopCtrQGC20220313_P.Saturation14_LowerSat;
  }

  // End of Saturate: '<S14>/Saturation14'

  // Gain: '<S14>/Gain3' incorporates:
  //   Sum: '<S14>/Add19'

  px42LoopCtrQGC20220313_B.roll_hat_e = (px42LoopCtrQGC20220313_B.lambda4_h -
    u0_tmp) * px42LoopCtrQGC20220313_P.Gain3_Gain;

  // Saturate: '<S14>/Saturation1'
  if (px42LoopCtrQGC20220313_B.Abs6 >
      px42LoopCtrQGC20220313_P.Saturation1_UpperSat) {
    px42LoopCtrQGC20220313_B.Product2_d =
      px42LoopCtrQGC20220313_P.Saturation1_UpperSat;
  } else if (px42LoopCtrQGC20220313_B.Abs6 <
             px42LoopCtrQGC20220313_P.Saturation1_LowerSat) {
    px42LoopCtrQGC20220313_B.Product2_d =
      px42LoopCtrQGC20220313_P.Saturation1_LowerSat;
  } else {
    px42LoopCtrQGC20220313_B.Product2_d = px42LoopCtrQGC20220313_B.Abs6;
  }

  // End of Saturate: '<S14>/Saturation1'

  // Fcn: '<S14>/Fcn7' incorporates:
  //   Constant: '<S14>/Constant1'

  if (px42LoopCtrQGC20220313_P.Constant1_Value_f < 0.0) {
    px42LoopCtrQGC20220313_B.fcn5 = -rt_powd_snf
      (-px42LoopCtrQGC20220313_P.Constant1_Value_f, -0.75);
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = rt_powd_snf
      (px42LoopCtrQGC20220313_P.Constant1_Value_f, -0.75);
  }

  // End of Fcn: '<S14>/Fcn7'

  // Saturate: '<S14>/Saturation15'
  if (px42LoopCtrQGC20220313_B.Abs6 >
      px42LoopCtrQGC20220313_P.Saturation15_UpperSat) {
    px42LoopCtrQGC20220313_B.lambda1_a =
      px42LoopCtrQGC20220313_P.Saturation15_UpperSat;
  } else if (px42LoopCtrQGC20220313_B.Abs6 <
             px42LoopCtrQGC20220313_P.Saturation15_LowerSat) {
    px42LoopCtrQGC20220313_B.lambda1_a =
      px42LoopCtrQGC20220313_P.Saturation15_LowerSat;
  } else {
    px42LoopCtrQGC20220313_B.lambda1_a = px42LoopCtrQGC20220313_B.Abs6;
  }

  // End of Saturate: '<S14>/Saturation15'

  // Sum: '<S14>/Add2' incorporates:
  //   Constant: '<S14>/Constant6'
  //   DiscreteIntegrator: '<S14>/Discrete-Time Integrator3'
  //   Fcn: '<S14>/Fcn8'
  //   Gain: '<S14>/Gain6'
  //   Gain: '<S14>/l2'
  //   Gain: '<S14>/lambda2'
  //   Product: '<S14>/Product7'
  //   Product: '<S14>/Product8'
  //   Sum: '<S14>/Add16'
  //   Sum: '<S14>/Add20'
  //   Sum: '<S14>/Add3'

  px42LoopCtrQGC20220313_B.z2_l = (((px42LoopCtrQGC20220313_P.lambda2_Gain *
    px42LoopCtrQGC20220313_B.Abs6 + px42LoopCtrQGC20220313_P.l2_Gain *
    px42LoopCtrQGC20220313_B.Product2_d) +
    (px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 -
     px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1)) +
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator3_DSTATE) +
    (px42LoopCtrQGC20220313_B.fcn5 * px42LoopCtrQGC20220313_B.roll_hat_e *
     px42LoopCtrQGC20220313_B.Abs6 + rt_powd_snf(px42LoopCtrQGC20220313_B.z2_l,
      0.25) * px42LoopCtrQGC20220313_B.lambda1_a *
     (px42LoopCtrQGC20220313_P.Constant6_Value -
      px42LoopCtrQGC20220313_B.roll_hat_e)) *
    px42LoopCtrQGC20220313_P.Gain6_Gain;

  // Gain: '<S12>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S12>/Discrete-Time Integrator'

  px42LoopCtrQGC20220313_B.rolldegree_l = px42LoopCtrQGC20220313_P.Gain2_Gain_g *
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTATE_p;

  // Switch: '<S12>/Switch' incorporates:
  //   Constant: '<S12>/Constant3'
  //   DataStoreRead: '<S12>/Data Store Read'
  //   DataStoreRead: '<S12>/Data Store Read1'
  //   DataStoreRead: '<S12>/Data Store Read2'
  //   DataStoreWrite: '<Root>/Data Store Write12'
  //   Gain: '<S12>/1//J'
  //   Gain: '<S12>/k//J'
  //   ZeroOrderHold: '<S12>/Zero-Order Hold1'

  if (px42LoopCtrQGC20220313_DW.observer_flag) {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 =
      px42LoopCtrQGC20220313_P.uJ_Gain_p *
      px42LoopCtrQGC20220313_B.DataStoreRead25;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 =
      px42LoopCtrQGC20220313_P.kJ_Gain_c * px42LoopCtrQGC20220313_DW.pitch_speed;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_DW.pitch;
  } else {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 =
      px42LoopCtrQGC20220313_P.Constant3_Value;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 =
      px42LoopCtrQGC20220313_P.Constant3_Value;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_P.Constant3_Value;
  }

  // End of Switch: '<S12>/Switch'

  // Sum: '<S12>/Add1' incorporates:
  //   DiscreteIntegrator: '<S12>/Discrete-Time Integrator'

  px42LoopCtrQGC20220313_B.Product2_d =
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 -
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTATE_p;

  // Abs: '<S12>/Abs3' incorporates:
  //   Abs: '<S12>/Abs4'
  //   Abs: '<S12>/Abs5'
  //   Abs: '<S12>/Abs6'

  px42LoopCtrQGC20220313_B.Add2_o = fabs(px42LoopCtrQGC20220313_B.Product2_d);

  // Saturate: '<S12>/Saturation'
  if (px42LoopCtrQGC20220313_B.Product2_d >
      px42LoopCtrQGC20220313_P.Saturation_UpperSat_n) {
    px42LoopCtrQGC20220313_B.roll_hat_e =
      px42LoopCtrQGC20220313_P.Saturation_UpperSat_n;
  } else if (px42LoopCtrQGC20220313_B.Product2_d <
             px42LoopCtrQGC20220313_P.Saturation_LowerSat_g) {
    px42LoopCtrQGC20220313_B.roll_hat_e =
      px42LoopCtrQGC20220313_P.Saturation_LowerSat_g;
  } else {
    px42LoopCtrQGC20220313_B.roll_hat_e = px42LoopCtrQGC20220313_B.Product2_d;
  }

  // End of Saturate: '<S12>/Saturation'

  // Gain: '<S12>/lambda1'
  px42LoopCtrQGC20220313_B.lambda1_a = px42LoopCtrQGC20220313_P.lambda1_Gain_a *
    px42LoopCtrQGC20220313_B.Product2_d;

  // Sum: '<S12>/Add7' incorporates:
  //   Constant: '<S12>/Constant1'
  //   Sum: '<S12>/Add13'
  //   Sum: '<S12>/Add18'

  px42LoopCtrQGC20220313_B.lambda4_h =
    px42LoopCtrQGC20220313_P.Constant1_Value_j +
    px42LoopCtrQGC20220313_B.Product2_d;

  // Sum: '<S12>/Add6' incorporates:
  //   Constant: '<S12>/Constant1'
  //   Sum: '<S12>/Add12'
  //   Sum: '<S12>/Add17'

  u0_tmp = px42LoopCtrQGC20220313_B.Product2_d -
    px42LoopCtrQGC20220313_P.Constant1_Value_j;

  // Saturate: '<S12>/Saturation10' incorporates:
  //   Sum: '<S12>/Add7'

  if (px42LoopCtrQGC20220313_B.lambda4_h >
      px42LoopCtrQGC20220313_P.Saturation10_UpperSat_o) {
    px42LoopCtrQGC20220313_B.Product6_a =
      px42LoopCtrQGC20220313_P.Saturation10_UpperSat_o;
  } else if (px42LoopCtrQGC20220313_B.lambda4_h <
             px42LoopCtrQGC20220313_P.Saturation10_LowerSat_b) {
    px42LoopCtrQGC20220313_B.Product6_a =
      px42LoopCtrQGC20220313_P.Saturation10_LowerSat_b;
  } else {
    px42LoopCtrQGC20220313_B.Product6_a = px42LoopCtrQGC20220313_B.lambda4_h;
  }

  // End of Saturate: '<S12>/Saturation10'

  // Saturate: '<S12>/Saturation11' incorporates:
  //   Sum: '<S12>/Add6'

  if (u0_tmp > px42LoopCtrQGC20220313_P.Saturation11_UpperSat_p) {
    px42LoopCtrQGC20220313_B.Product5_l =
      px42LoopCtrQGC20220313_P.Saturation11_UpperSat_p;
  } else if (u0_tmp < px42LoopCtrQGC20220313_P.Saturation11_LowerSat_i) {
    px42LoopCtrQGC20220313_B.Product5_l =
      px42LoopCtrQGC20220313_P.Saturation11_LowerSat_i;
  } else {
    px42LoopCtrQGC20220313_B.Product5_l = u0_tmp;
  }

  // End of Saturate: '<S12>/Saturation11'

  // Gain: '<S12>/Gain' incorporates:
  //   Sum: '<S12>/Add8'

  px42LoopCtrQGC20220313_B.roll_hat_k = (px42LoopCtrQGC20220313_B.Product6_a -
    px42LoopCtrQGC20220313_B.Product5_l) * px42LoopCtrQGC20220313_P.Gain_Gain_g;

  // Fcn: '<S12>/Fcn3' incorporates:
  //   Constant: '<S12>/Constant1'

  if (px42LoopCtrQGC20220313_P.Constant1_Value_j < 0.0) {
    px42LoopCtrQGC20220313_B.fcn5 = -rt_powd_snf
      (-px42LoopCtrQGC20220313_P.Constant1_Value_j, -0.5);
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = rt_powd_snf
      (px42LoopCtrQGC20220313_P.Constant1_Value_j, -0.5);
  }

  // End of Fcn: '<S12>/Fcn3'

  // Product: '<S12>/Product3'
  px42LoopCtrQGC20220313_B.Product3_a = px42LoopCtrQGC20220313_B.fcn5 *
    px42LoopCtrQGC20220313_B.roll_hat_k * px42LoopCtrQGC20220313_B.Product2_d;

  // Saturate: '<S12>/Saturation8'
  if (px42LoopCtrQGC20220313_B.Product2_d >
      px42LoopCtrQGC20220313_P.Saturation8_UpperSat_g) {
    px42LoopCtrQGC20220313_B.lambda4_n =
      px42LoopCtrQGC20220313_P.Saturation8_UpperSat_g;
  } else if (px42LoopCtrQGC20220313_B.Product2_d <
             px42LoopCtrQGC20220313_P.Saturation8_LowerSat_g) {
    px42LoopCtrQGC20220313_B.lambda4_n =
      px42LoopCtrQGC20220313_P.Saturation8_LowerSat_g;
  } else {
    px42LoopCtrQGC20220313_B.lambda4_n = px42LoopCtrQGC20220313_B.Product2_d;
  }

  // End of Saturate: '<S12>/Saturation8'

  // Product: '<S12>/Product4' incorporates:
  //   Abs: '<S12>/Abs3'
  //   Constant: '<S12>/Constant2'
  //   Fcn: '<S12>/Fcn4'
  //   Sum: '<S12>/Add10'

  px42LoopCtrQGC20220313_B.Product4_k = rt_powd_snf
    (px42LoopCtrQGC20220313_B.Add2_o, 0.5) * px42LoopCtrQGC20220313_B.lambda4_n *
    (px42LoopCtrQGC20220313_P.Constant2_Value_h -
     px42LoopCtrQGC20220313_B.roll_hat_k);

  // Saturate: '<S12>/Saturation13'
  if (px42LoopCtrQGC20220313_B.lambda4_h >
      px42LoopCtrQGC20220313_P.Saturation13_UpperSat_i) {
    px42LoopCtrQGC20220313_B.Product6_a =
      px42LoopCtrQGC20220313_P.Saturation13_UpperSat_i;
  } else if (px42LoopCtrQGC20220313_B.lambda4_h <
             px42LoopCtrQGC20220313_P.Saturation13_LowerSat_c) {
    px42LoopCtrQGC20220313_B.Product6_a =
      px42LoopCtrQGC20220313_P.Saturation13_LowerSat_c;
  } else {
    px42LoopCtrQGC20220313_B.Product6_a = px42LoopCtrQGC20220313_B.lambda4_h;
  }

  // End of Saturate: '<S12>/Saturation13'

  // Saturate: '<S12>/Saturation9'
  if (u0_tmp > px42LoopCtrQGC20220313_P.Saturation9_UpperSat_i) {
    px42LoopCtrQGC20220313_B.Product5_l =
      px42LoopCtrQGC20220313_P.Saturation9_UpperSat_i;
  } else if (u0_tmp < px42LoopCtrQGC20220313_P.Saturation9_LowerSat_c) {
    px42LoopCtrQGC20220313_B.Product5_l =
      px42LoopCtrQGC20220313_P.Saturation9_LowerSat_c;
  } else {
    px42LoopCtrQGC20220313_B.Product5_l = u0_tmp;
  }

  // End of Saturate: '<S12>/Saturation9'

  // Gain: '<S12>/Gain1' incorporates:
  //   Sum: '<S12>/Add14'

  px42LoopCtrQGC20220313_B.roll_hat_k = (px42LoopCtrQGC20220313_B.Product6_a -
    px42LoopCtrQGC20220313_B.Product5_l) * px42LoopCtrQGC20220313_P.Gain1_Gain_d;

  // Fcn: '<S12>/Fcn6' incorporates:
  //   Constant: '<S12>/Constant1'

  if (px42LoopCtrQGC20220313_P.Constant1_Value_j < 0.0) {
    px42LoopCtrQGC20220313_B.fcn5 = -rt_powd_snf
      (-px42LoopCtrQGC20220313_P.Constant1_Value_j, -0.9375);
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = rt_powd_snf
      (px42LoopCtrQGC20220313_P.Constant1_Value_j, -0.9375);
  }

  // End of Fcn: '<S12>/Fcn6'

  // Product: '<S12>/Product6'
  px42LoopCtrQGC20220313_B.Product6_i = px42LoopCtrQGC20220313_B.fcn5 *
    px42LoopCtrQGC20220313_B.roll_hat_k * px42LoopCtrQGC20220313_B.Product2_d;

  // Saturate: '<S12>/Saturation12'
  if (px42LoopCtrQGC20220313_B.Product2_d >
      px42LoopCtrQGC20220313_P.Saturation12_UpperSat_c) {
    px42LoopCtrQGC20220313_B.lambda4_n =
      px42LoopCtrQGC20220313_P.Saturation12_UpperSat_c;
  } else if (px42LoopCtrQGC20220313_B.Product2_d <
             px42LoopCtrQGC20220313_P.Saturation12_LowerSat_b) {
    px42LoopCtrQGC20220313_B.lambda4_n =
      px42LoopCtrQGC20220313_P.Saturation12_LowerSat_b;
  } else {
    px42LoopCtrQGC20220313_B.lambda4_n = px42LoopCtrQGC20220313_B.Product2_d;
  }

  // End of Saturate: '<S12>/Saturation12'

  // Product: '<S12>/Product5' incorporates:
  //   Constant: '<S12>/Constant4'
  //   Fcn: '<S12>/Fcn5'
  //   Sum: '<S12>/Add11'

  px42LoopCtrQGC20220313_B.Product5_b = rt_powd_snf
    (px42LoopCtrQGC20220313_B.Add2_o, 0.0625) *
    px42LoopCtrQGC20220313_B.lambda4_n *
    (px42LoopCtrQGC20220313_P.Constant4_Value_n -
     px42LoopCtrQGC20220313_B.roll_hat_k);

  // Saturate: '<S12>/Saturation16'
  if (px42LoopCtrQGC20220313_B.lambda4_h >
      px42LoopCtrQGC20220313_P.Saturation16_UpperSat_l) {
    px42LoopCtrQGC20220313_B.lambda4_h =
      px42LoopCtrQGC20220313_P.Saturation16_UpperSat_l;
  } else if (px42LoopCtrQGC20220313_B.lambda4_h <
             px42LoopCtrQGC20220313_P.Saturation16_LowerSat_g) {
    px42LoopCtrQGC20220313_B.lambda4_h =
      px42LoopCtrQGC20220313_P.Saturation16_LowerSat_g;
  }

  // End of Saturate: '<S12>/Saturation16'

  // Saturate: '<S12>/Saturation14'
  if (u0_tmp > px42LoopCtrQGC20220313_P.Saturation14_UpperSat_l) {
    u0_tmp = px42LoopCtrQGC20220313_P.Saturation14_UpperSat_l;
  } else if (u0_tmp < px42LoopCtrQGC20220313_P.Saturation14_LowerSat_b) {
    u0_tmp = px42LoopCtrQGC20220313_P.Saturation14_LowerSat_b;
  }

  // End of Saturate: '<S12>/Saturation14'

  // Gain: '<S12>/Gain3' incorporates:
  //   Sum: '<S12>/Add19'

  px42LoopCtrQGC20220313_B.roll_hat_k = (px42LoopCtrQGC20220313_B.lambda4_h -
    u0_tmp) * px42LoopCtrQGC20220313_P.Gain3_Gain_l;

  // Saturate: '<S12>/Saturation1'
  if (px42LoopCtrQGC20220313_B.Product2_d >
      px42LoopCtrQGC20220313_P.Saturation1_UpperSat_a) {
    px42LoopCtrQGC20220313_B.lambda4_n =
      px42LoopCtrQGC20220313_P.Saturation1_UpperSat_a;
  } else if (px42LoopCtrQGC20220313_B.Product2_d <
             px42LoopCtrQGC20220313_P.Saturation1_LowerSat_i) {
    px42LoopCtrQGC20220313_B.lambda4_n =
      px42LoopCtrQGC20220313_P.Saturation1_LowerSat_i;
  } else {
    px42LoopCtrQGC20220313_B.lambda4_n = px42LoopCtrQGC20220313_B.Product2_d;
  }

  // End of Saturate: '<S12>/Saturation1'

  // Fcn: '<S12>/Fcn7' incorporates:
  //   Constant: '<S12>/Constant1'

  if (px42LoopCtrQGC20220313_P.Constant1_Value_j < 0.0) {
    px42LoopCtrQGC20220313_B.fcn5 = -rt_powd_snf
      (-px42LoopCtrQGC20220313_P.Constant1_Value_j, -0.75);
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = rt_powd_snf
      (px42LoopCtrQGC20220313_P.Constant1_Value_j, -0.75);
  }

  // End of Fcn: '<S12>/Fcn7'

  // Saturate: '<S12>/Saturation15'
  if (px42LoopCtrQGC20220313_B.Product2_d >
      px42LoopCtrQGC20220313_P.Saturation15_UpperSat_j) {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_P.Saturation15_UpperSat_j;
  } else if (px42LoopCtrQGC20220313_B.Product2_d <
             px42LoopCtrQGC20220313_P.Saturation15_LowerSat_k) {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_P.Saturation15_LowerSat_k;
  } else {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_B.Product2_d;
  }

  // End of Saturate: '<S12>/Saturation15'

  // Sum: '<S12>/Add2' incorporates:
  //   Constant: '<S12>/Constant6'
  //   DiscreteIntegrator: '<S12>/Discrete-Time Integrator3'
  //   Fcn: '<S12>/Fcn8'
  //   Gain: '<S12>/Gain6'
  //   Gain: '<S12>/l2'
  //   Gain: '<S12>/lambda2'
  //   Product: '<S12>/Product7'
  //   Product: '<S12>/Product8'
  //   Sum: '<S12>/Add16'
  //   Sum: '<S12>/Add20'
  //   Sum: '<S12>/Add3'

  px42LoopCtrQGC20220313_B.Add2_o = (((px42LoopCtrQGC20220313_P.lambda2_Gain_j *
    px42LoopCtrQGC20220313_B.Product2_d + px42LoopCtrQGC20220313_P.l2_Gain_l *
    px42LoopCtrQGC20220313_B.lambda4_n) +
    (px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 -
     px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1)) +
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator3_DSTAT_a) +
    (px42LoopCtrQGC20220313_B.fcn5 * px42LoopCtrQGC20220313_B.roll_hat_k *
     px42LoopCtrQGC20220313_B.Product2_d + rt_powd_snf
     (px42LoopCtrQGC20220313_B.Add2_o, 0.25) *
     px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 *
     (px42LoopCtrQGC20220313_P.Constant6_Value_o -
      px42LoopCtrQGC20220313_B.roll_hat_k)) *
    px42LoopCtrQGC20220313_P.Gain6_Gain_e;

  // Saturate: '<S12>/Saturation3'
  if (px42LoopCtrQGC20220313_B.Product2_d >
      px42LoopCtrQGC20220313_P.Saturation3_UpperSat_m) {
    px42LoopCtrQGC20220313_B.roll_hat_k =
      px42LoopCtrQGC20220313_P.Saturation3_UpperSat_m;
  } else if (px42LoopCtrQGC20220313_B.Product2_d <
             px42LoopCtrQGC20220313_P.Saturation3_LowerSat_i) {
    px42LoopCtrQGC20220313_B.roll_hat_k =
      px42LoopCtrQGC20220313_P.Saturation3_LowerSat_i;
  } else {
    px42LoopCtrQGC20220313_B.roll_hat_k = px42LoopCtrQGC20220313_B.Product2_d;
  }

  // End of Saturate: '<S12>/Saturation3'

  // Gain: '<S12>/lambda4'
  px42LoopCtrQGC20220313_B.lambda4_n = px42LoopCtrQGC20220313_P.lambda4_Gain_a *
    px42LoopCtrQGC20220313_B.Product2_d;

  // Gain: '<S13>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S13>/Discrete-Time Integrator'

  px42LoopCtrQGC20220313_B.rolldegree_c = px42LoopCtrQGC20220313_P.Gain2_Gain_p *
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTATE_f;

  // Switch: '<S13>/Switch' incorporates:
  //   Constant: '<S13>/Constant3'
  //   DataStoreRead: '<S13>/Data Store Read'
  //   DataStoreRead: '<S13>/Data Store Read1'
  //   DataStoreRead: '<S13>/Data Store Read2'
  //   DataStoreWrite: '<Root>/Data Store Write13'
  //   Gain: '<S13>/1//J'
  //   Gain: '<S13>/k//J'
  //   ZeroOrderHold: '<S13>/Zero-Order Hold1'

  if (px42LoopCtrQGC20220313_DW.observer_flag) {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 =
      px42LoopCtrQGC20220313_P.uJ_Gain_g *
      px42LoopCtrQGC20220313_B.DataStoreRead26;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 =
      px42LoopCtrQGC20220313_P.kJ_Gain_p * px42LoopCtrQGC20220313_DW.roll_speed;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_DW.roll;
  } else {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 =
      px42LoopCtrQGC20220313_P.Constant3_Value_a;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 =
      px42LoopCtrQGC20220313_P.Constant3_Value_a;
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_P.Constant3_Value_a;
  }

  // End of Switch: '<S13>/Switch'

  // Sum: '<S13>/Add1' incorporates:
  //   DiscreteIntegrator: '<S13>/Discrete-Time Integrator'

  px42LoopCtrQGC20220313_B.Product1_p =
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 -
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTATE_f;

  // Abs: '<S13>/Abs3' incorporates:
  //   Abs: '<S13>/Abs4'
  //   Abs: '<S13>/Abs5'
  //   Abs: '<S13>/Abs6'

  px42LoopCtrQGC20220313_B.Product2_d = fabs(px42LoopCtrQGC20220313_B.Product1_p);

  // Saturate: '<S13>/Saturation'
  if (px42LoopCtrQGC20220313_B.Product1_p >
      px42LoopCtrQGC20220313_P.Saturation_UpperSat_n1) {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_P.Saturation_UpperSat_n1;
  } else if (px42LoopCtrQGC20220313_B.Product1_p <
             px42LoopCtrQGC20220313_P.Saturation_LowerSat_c) {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_P.Saturation_LowerSat_c;
  } else {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 =
      px42LoopCtrQGC20220313_B.Product1_p;
  }

  // End of Saturate: '<S13>/Saturation'

  // Gain: '<S13>/lambda1'
  px42LoopCtrQGC20220313_B.lambda1_e = px42LoopCtrQGC20220313_P.lambda1_Gain_g *
    px42LoopCtrQGC20220313_B.Product1_p;

  // Sum: '<S13>/Add7' incorporates:
  //   Constant: '<S13>/Constant1'
  //   Sum: '<S13>/Add13'
  //   Sum: '<S13>/Add18'

  px42LoopCtrQGC20220313_B.lambda4_h =
    px42LoopCtrQGC20220313_P.Constant1_Value_ac +
    px42LoopCtrQGC20220313_B.Product1_p;

  // Sum: '<S13>/Add6' incorporates:
  //   Constant: '<S13>/Constant1'
  //   Sum: '<S13>/Add12'
  //   Sum: '<S13>/Add17'

  u0_tmp = px42LoopCtrQGC20220313_B.Product1_p -
    px42LoopCtrQGC20220313_P.Constant1_Value_ac;

  // Saturate: '<S13>/Saturation10' incorporates:
  //   Sum: '<S13>/Add7'

  if (px42LoopCtrQGC20220313_B.lambda4_h >
      px42LoopCtrQGC20220313_P.Saturation10_UpperSat_a) {
    px42LoopCtrQGC20220313_B.Product6_a =
      px42LoopCtrQGC20220313_P.Saturation10_UpperSat_a;
  } else if (px42LoopCtrQGC20220313_B.lambda4_h <
             px42LoopCtrQGC20220313_P.Saturation10_LowerSat_l) {
    px42LoopCtrQGC20220313_B.Product6_a =
      px42LoopCtrQGC20220313_P.Saturation10_LowerSat_l;
  } else {
    px42LoopCtrQGC20220313_B.Product6_a = px42LoopCtrQGC20220313_B.lambda4_h;
  }

  // End of Saturate: '<S13>/Saturation10'

  // Saturate: '<S13>/Saturation11' incorporates:
  //   Sum: '<S13>/Add6'

  if (u0_tmp > px42LoopCtrQGC20220313_P.Saturation11_UpperSat_a) {
    px42LoopCtrQGC20220313_B.Product5_l =
      px42LoopCtrQGC20220313_P.Saturation11_UpperSat_a;
  } else if (u0_tmp < px42LoopCtrQGC20220313_P.Saturation11_LowerSat_a) {
    px42LoopCtrQGC20220313_B.Product5_l =
      px42LoopCtrQGC20220313_P.Saturation11_LowerSat_a;
  } else {
    px42LoopCtrQGC20220313_B.Product5_l = u0_tmp;
  }

  // End of Saturate: '<S13>/Saturation11'

  // Gain: '<S13>/Gain' incorporates:
  //   Sum: '<S13>/Add8'

  px42LoopCtrQGC20220313_B.Product3_i = (px42LoopCtrQGC20220313_B.Product6_a -
    px42LoopCtrQGC20220313_B.Product5_l) * px42LoopCtrQGC20220313_P.Gain_Gain_h;

  // Fcn: '<S13>/Fcn3' incorporates:
  //   Constant: '<S13>/Constant1'

  if (px42LoopCtrQGC20220313_P.Constant1_Value_ac < 0.0) {
    px42LoopCtrQGC20220313_B.fcn5 = -rt_powd_snf
      (-px42LoopCtrQGC20220313_P.Constant1_Value_ac, -0.5);
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = rt_powd_snf
      (px42LoopCtrQGC20220313_P.Constant1_Value_ac, -0.5);
  }

  // End of Fcn: '<S13>/Fcn3'

  // Product: '<S13>/Product3'
  px42LoopCtrQGC20220313_B.Product3_c = px42LoopCtrQGC20220313_B.fcn5 *
    px42LoopCtrQGC20220313_B.Product3_i * px42LoopCtrQGC20220313_B.Product1_p;

  // Saturate: '<S13>/Saturation8'
  if (px42LoopCtrQGC20220313_B.Product1_p >
      px42LoopCtrQGC20220313_P.Saturation8_UpperSat_c) {
    px42LoopCtrQGC20220313_B.rtb_Product1_p_b =
      px42LoopCtrQGC20220313_P.Saturation8_UpperSat_c;
  } else if (px42LoopCtrQGC20220313_B.Product1_p <
             px42LoopCtrQGC20220313_P.Saturation8_LowerSat_c) {
    px42LoopCtrQGC20220313_B.rtb_Product1_p_b =
      px42LoopCtrQGC20220313_P.Saturation8_LowerSat_c;
  } else {
    px42LoopCtrQGC20220313_B.rtb_Product1_p_b =
      px42LoopCtrQGC20220313_B.Product1_p;
  }

  // End of Saturate: '<S13>/Saturation8'

  // Product: '<S13>/Product4' incorporates:
  //   Abs: '<S13>/Abs3'
  //   Constant: '<S13>/Constant2'
  //   Fcn: '<S13>/Fcn4'
  //   Sum: '<S13>/Add10'

  px42LoopCtrQGC20220313_B.Product4_g = rt_powd_snf
    (px42LoopCtrQGC20220313_B.Product2_d, 0.5) *
    px42LoopCtrQGC20220313_B.rtb_Product1_p_b *
    (px42LoopCtrQGC20220313_P.Constant2_Value_k -
     px42LoopCtrQGC20220313_B.Product3_i);

  // Saturate: '<S13>/Saturation13'
  if (px42LoopCtrQGC20220313_B.lambda4_h >
      px42LoopCtrQGC20220313_P.Saturation13_UpperSat_p) {
    px42LoopCtrQGC20220313_B.Product6_a =
      px42LoopCtrQGC20220313_P.Saturation13_UpperSat_p;
  } else if (px42LoopCtrQGC20220313_B.lambda4_h <
             px42LoopCtrQGC20220313_P.Saturation13_LowerSat_j) {
    px42LoopCtrQGC20220313_B.Product6_a =
      px42LoopCtrQGC20220313_P.Saturation13_LowerSat_j;
  } else {
    px42LoopCtrQGC20220313_B.Product6_a = px42LoopCtrQGC20220313_B.lambda4_h;
  }

  // End of Saturate: '<S13>/Saturation13'

  // Saturate: '<S13>/Saturation9'
  if (u0_tmp > px42LoopCtrQGC20220313_P.Saturation9_UpperSat_d) {
    px42LoopCtrQGC20220313_B.Product5_l =
      px42LoopCtrQGC20220313_P.Saturation9_UpperSat_d;
  } else if (u0_tmp < px42LoopCtrQGC20220313_P.Saturation9_LowerSat_c4) {
    px42LoopCtrQGC20220313_B.Product5_l =
      px42LoopCtrQGC20220313_P.Saturation9_LowerSat_c4;
  } else {
    px42LoopCtrQGC20220313_B.Product5_l = u0_tmp;
  }

  // End of Saturate: '<S13>/Saturation9'

  // Gain: '<S13>/Gain1' incorporates:
  //   Sum: '<S13>/Add14'

  px42LoopCtrQGC20220313_B.Product3_i = (px42LoopCtrQGC20220313_B.Product6_a -
    px42LoopCtrQGC20220313_B.Product5_l) * px42LoopCtrQGC20220313_P.Gain1_Gain_e;

  // Fcn: '<S13>/Fcn6' incorporates:
  //   Constant: '<S13>/Constant1'

  if (px42LoopCtrQGC20220313_P.Constant1_Value_ac < 0.0) {
    px42LoopCtrQGC20220313_B.fcn5 = -rt_powd_snf
      (-px42LoopCtrQGC20220313_P.Constant1_Value_ac, -0.9375);
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = rt_powd_snf
      (px42LoopCtrQGC20220313_P.Constant1_Value_ac, -0.9375);
  }

  // End of Fcn: '<S13>/Fcn6'

  // Product: '<S13>/Product6'
  px42LoopCtrQGC20220313_B.Product6_a = px42LoopCtrQGC20220313_B.fcn5 *
    px42LoopCtrQGC20220313_B.Product3_i * px42LoopCtrQGC20220313_B.Product1_p;

  // Saturate: '<S13>/Saturation12'
  if (px42LoopCtrQGC20220313_B.Product1_p >
      px42LoopCtrQGC20220313_P.Saturation12_UpperSat_d) {
    px42LoopCtrQGC20220313_B.rtb_Product1_p_b =
      px42LoopCtrQGC20220313_P.Saturation12_UpperSat_d;
  } else if (px42LoopCtrQGC20220313_B.Product1_p <
             px42LoopCtrQGC20220313_P.Saturation12_LowerSat_j) {
    px42LoopCtrQGC20220313_B.rtb_Product1_p_b =
      px42LoopCtrQGC20220313_P.Saturation12_LowerSat_j;
  } else {
    px42LoopCtrQGC20220313_B.rtb_Product1_p_b =
      px42LoopCtrQGC20220313_B.Product1_p;
  }

  // End of Saturate: '<S13>/Saturation12'

  // Product: '<S13>/Product5' incorporates:
  //   Constant: '<S13>/Constant4'
  //   Fcn: '<S13>/Fcn5'
  //   Sum: '<S13>/Add11'

  px42LoopCtrQGC20220313_B.Product5_l = rt_powd_snf
    (px42LoopCtrQGC20220313_B.Product2_d, 0.0625) *
    px42LoopCtrQGC20220313_B.rtb_Product1_p_b *
    (px42LoopCtrQGC20220313_P.Constant4_Value_l -
     px42LoopCtrQGC20220313_B.Product3_i);

  // Saturate: '<S13>/Saturation16'
  if (px42LoopCtrQGC20220313_B.lambda4_h >
      px42LoopCtrQGC20220313_P.Saturation16_UpperSat_p) {
    px42LoopCtrQGC20220313_B.lambda4_h =
      px42LoopCtrQGC20220313_P.Saturation16_UpperSat_p;
  } else if (px42LoopCtrQGC20220313_B.lambda4_h <
             px42LoopCtrQGC20220313_P.Saturation16_LowerSat_i) {
    px42LoopCtrQGC20220313_B.lambda4_h =
      px42LoopCtrQGC20220313_P.Saturation16_LowerSat_i;
  }

  // End of Saturate: '<S13>/Saturation16'

  // Saturate: '<S13>/Saturation14'
  if (u0_tmp > px42LoopCtrQGC20220313_P.Saturation14_UpperSat_n) {
    u0_tmp = px42LoopCtrQGC20220313_P.Saturation14_UpperSat_n;
  } else if (u0_tmp < px42LoopCtrQGC20220313_P.Saturation14_LowerSat_a) {
    u0_tmp = px42LoopCtrQGC20220313_P.Saturation14_LowerSat_a;
  }

  // End of Saturate: '<S13>/Saturation14'

  // Gain: '<S13>/Gain3' incorporates:
  //   Sum: '<S13>/Add19'

  px42LoopCtrQGC20220313_B.Product3_i = (px42LoopCtrQGC20220313_B.lambda4_h -
    u0_tmp) * px42LoopCtrQGC20220313_P.Gain3_Gain_p;

  // Saturate: '<S13>/Saturation1'
  if (px42LoopCtrQGC20220313_B.Product1_p >
      px42LoopCtrQGC20220313_P.Saturation1_UpperSat_d) {
    px42LoopCtrQGC20220313_B.rtb_Product1_p_b =
      px42LoopCtrQGC20220313_P.Saturation1_UpperSat_d;
  } else if (px42LoopCtrQGC20220313_B.Product1_p <
             px42LoopCtrQGC20220313_P.Saturation1_LowerSat_g) {
    px42LoopCtrQGC20220313_B.rtb_Product1_p_b =
      px42LoopCtrQGC20220313_P.Saturation1_LowerSat_g;
  } else {
    px42LoopCtrQGC20220313_B.rtb_Product1_p_b =
      px42LoopCtrQGC20220313_B.Product1_p;
  }

  // End of Saturate: '<S13>/Saturation1'

  // Fcn: '<S13>/Fcn7' incorporates:
  //   Constant: '<S13>/Constant1'

  if (px42LoopCtrQGC20220313_P.Constant1_Value_ac < 0.0) {
    px42LoopCtrQGC20220313_B.fcn5 = -rt_powd_snf
      (-px42LoopCtrQGC20220313_P.Constant1_Value_ac, -0.75);
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = rt_powd_snf
      (px42LoopCtrQGC20220313_P.Constant1_Value_ac, -0.75);
  }

  // End of Fcn: '<S13>/Fcn7'

  // Saturate: '<S13>/Saturation15'
  if (px42LoopCtrQGC20220313_B.Product1_p >
      px42LoopCtrQGC20220313_P.Saturation15_UpperSat_k) {
    px42LoopCtrQGC20220313_B.lambda4_h =
      px42LoopCtrQGC20220313_P.Saturation15_UpperSat_k;
  } else if (px42LoopCtrQGC20220313_B.Product1_p <
             px42LoopCtrQGC20220313_P.Saturation15_LowerSat_h) {
    px42LoopCtrQGC20220313_B.lambda4_h =
      px42LoopCtrQGC20220313_P.Saturation15_LowerSat_h;
  } else {
    px42LoopCtrQGC20220313_B.lambda4_h = px42LoopCtrQGC20220313_B.Product1_p;
  }

  // End of Saturate: '<S13>/Saturation15'

  // Sum: '<S13>/Add2' incorporates:
  //   Constant: '<S13>/Constant6'
  //   DiscreteIntegrator: '<S13>/Discrete-Time Integrator3'
  //   Fcn: '<S13>/Fcn8'
  //   Gain: '<S13>/Gain6'
  //   Gain: '<S13>/l2'
  //   Gain: '<S13>/lambda2'
  //   Product: '<S13>/Product7'
  //   Product: '<S13>/Product8'
  //   Sum: '<S13>/Add16'
  //   Sum: '<S13>/Add20'
  //   Sum: '<S13>/Add3'

  px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 =
    (((px42LoopCtrQGC20220313_P.lambda2_Gain_d *
       px42LoopCtrQGC20220313_B.Product1_p + px42LoopCtrQGC20220313_P.l2_Gain_i *
       px42LoopCtrQGC20220313_B.rtb_Product1_p_b) +
      (px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0 -
       px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1)) +
     px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator3_DSTAT_m) +
    (px42LoopCtrQGC20220313_B.fcn5 * px42LoopCtrQGC20220313_B.Product3_i *
     px42LoopCtrQGC20220313_B.Product1_p + rt_powd_snf
     (px42LoopCtrQGC20220313_B.Product2_d, 0.25) *
     px42LoopCtrQGC20220313_B.lambda4_h *
     (px42LoopCtrQGC20220313_P.Constant6_Value_g -
      px42LoopCtrQGC20220313_B.Product3_i)) *
    px42LoopCtrQGC20220313_P.Gain6_Gain_f;

  // Saturate: '<S13>/Saturation3'
  if (px42LoopCtrQGC20220313_B.Product1_p >
      px42LoopCtrQGC20220313_P.Saturation3_UpperSat_i) {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 =
      px42LoopCtrQGC20220313_P.Saturation3_UpperSat_i;
  } else if (px42LoopCtrQGC20220313_B.Product1_p <
             px42LoopCtrQGC20220313_P.Saturation3_LowerSat_g) {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 =
      px42LoopCtrQGC20220313_P.Saturation3_LowerSat_g;
  } else {
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 =
      px42LoopCtrQGC20220313_B.Product1_p;
  }

  // End of Saturate: '<S13>/Saturation3'

  // Gain: '<S13>/lambda4'
  px42LoopCtrQGC20220313_B.lambda4_h = px42LoopCtrQGC20220313_P.lambda4_Gain_b *
    px42LoopCtrQGC20220313_B.Product1_p;

  // MATLABSystem: '<S3>/SourceBlock'
  rtb_LogicalOperator = uORB_read_step
    (px42LoopCtrQGC20220313_DW.obj_n.orbMetadataObj,
     &px42LoopCtrQGC20220313_DW.obj_n.eventStructObj,
     &px42LoopCtrQGC20220313_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S43>/Enable'

  if (rtb_LogicalOperator) {
    // SignalConversion generated from: '<S43>/In1'
    px42LoopCtrQGC20220313_B.In1 = px42LoopCtrQGC20220313_B.b_varargout_2;
    srUpdateBC(px42LoopCtrQGC20220313_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'

  // Sqrt: '<S50>/sqrt' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   Product: '<S51>/Product'
  //   Product: '<S51>/Product1'
  //   Product: '<S51>/Product2'
  //   Product: '<S51>/Product3'
  //   Sum: '<S51>/Sum'

  px42LoopCtrQGC20220313_B.Product3_i = sqrt(((static_cast<real_T>
    (px42LoopCtrQGC20220313_B.In1.q[0]) * px42LoopCtrQGC20220313_B.In1.q[0] +
    static_cast<real_T>(px42LoopCtrQGC20220313_B.In1.q[1]) *
    px42LoopCtrQGC20220313_B.In1.q[1]) + static_cast<real_T>
    (px42LoopCtrQGC20220313_B.In1.q[2]) * px42LoopCtrQGC20220313_B.In1.q[2]) +
    static_cast<real_T>(px42LoopCtrQGC20220313_B.In1.q[3]) *
    px42LoopCtrQGC20220313_B.In1.q[3]);

  // Product: '<S45>/Product' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px42LoopCtrQGC20220313_B.fcn5 = px42LoopCtrQGC20220313_B.In1.q[0] /
    px42LoopCtrQGC20220313_B.Product3_i;

  // Product: '<S45>/Product1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px42LoopCtrQGC20220313_B.Product1_p = px42LoopCtrQGC20220313_B.In1.q[1] /
    px42LoopCtrQGC20220313_B.Product3_i;

  // Product: '<S45>/Product2' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px42LoopCtrQGC20220313_B.Product2_d = px42LoopCtrQGC20220313_B.In1.q[2] /
    px42LoopCtrQGC20220313_B.Product3_i;

  // Product: '<S45>/Product3' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px42LoopCtrQGC20220313_B.Product3_i = px42LoopCtrQGC20220313_B.In1.q[3] /
    px42LoopCtrQGC20220313_B.Product3_i;

  // Fcn: '<S4>/fcn3'
  px42LoopCtrQGC20220313_B.fcn3 = (px42LoopCtrQGC20220313_B.Product1_p *
    px42LoopCtrQGC20220313_B.Product3_i - px42LoopCtrQGC20220313_B.fcn5 *
    px42LoopCtrQGC20220313_B.Product2_d) * -2.0;

  // If: '<S46>/If' incorporates:
  //   Constant: '<S47>/Constant'
  //   Constant: '<S48>/Constant'

  if (px42LoopCtrQGC20220313_B.fcn3 > 1.0) {
    // Outputs for IfAction SubSystem: '<S46>/If Action Subsystem' incorporates:
    //   ActionPort: '<S47>/Action Port'

    px42LoopCtrQGC20220313_B.fcn3 = px42LoopCtrQGC20220313_P.Constant_Value_e;

    // End of Outputs for SubSystem: '<S46>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S46>/If Action Subsystem' incorporates:
    //   ActionPort: '<S47>/Action Port'

    // Update for If: '<S46>/If' incorporates:
    //   Constant: '<S47>/Constant'

    srUpdateBC(px42LoopCtrQGC20220313_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S46>/If Action Subsystem'
  } else if (px42LoopCtrQGC20220313_B.fcn3 < -1.0) {
    // Outputs for IfAction SubSystem: '<S46>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S48>/Action Port'

    px42LoopCtrQGC20220313_B.fcn3 = px42LoopCtrQGC20220313_P.Constant_Value_b1;

    // End of Outputs for SubSystem: '<S46>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S46>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S48>/Action Port'

    // Update for If: '<S46>/If' incorporates:
    //   Constant: '<S48>/Constant'

    srUpdateBC(px42LoopCtrQGC20220313_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S46>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S46>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S49>/Action Port'

    // Update for If: '<S46>/If'
    srUpdateBC(px42LoopCtrQGC20220313_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S46>/If Action Subsystem2'
  }

  // End of If: '<S46>/If'

  // Fcn: '<S4>/fcn5' incorporates:
  //   Fcn: '<S4>/fcn2'

  u0_tmp = px42LoopCtrQGC20220313_B.fcn5 * px42LoopCtrQGC20220313_B.fcn5;
  px42LoopCtrQGC20220313_B.rtb_Product1_p_b =
    px42LoopCtrQGC20220313_B.Product1_p * px42LoopCtrQGC20220313_B.Product1_p;
  roll_tmp = px42LoopCtrQGC20220313_B.Product2_d *
    px42LoopCtrQGC20220313_B.Product2_d;
  roll_tmp_0 = px42LoopCtrQGC20220313_B.Product3_i *
    px42LoopCtrQGC20220313_B.Product3_i;

  // DataStoreWrite: '<Root>/Data Store Write' incorporates:
  //   Fcn: '<S4>/fcn4'
  //   Fcn: '<S4>/fcn5'
  //   Trigonometry: '<S44>/Trigonometric Function3'

  px42LoopCtrQGC20220313_DW.roll = rt_atan2d_snf
    ((px42LoopCtrQGC20220313_B.Product2_d * px42LoopCtrQGC20220313_B.Product3_i
      + px42LoopCtrQGC20220313_B.fcn5 * px42LoopCtrQGC20220313_B.Product1_p) *
     2.0, ((u0_tmp - px42LoopCtrQGC20220313_B.rtb_Product1_p_b) - roll_tmp) +
     roll_tmp_0);

  // Trigonometry: '<S44>/trigFcn'
  if (px42LoopCtrQGC20220313_B.fcn3 > 1.0) {
    px42LoopCtrQGC20220313_B.fcn3 = 1.0;
  } else if (px42LoopCtrQGC20220313_B.fcn3 < -1.0) {
    px42LoopCtrQGC20220313_B.fcn3 = -1.0;
  }

  // DataStoreWrite: '<Root>/Data Store Write1' incorporates:
  //   Trigonometry: '<S44>/trigFcn'

  px42LoopCtrQGC20220313_DW.pitch = asin(px42LoopCtrQGC20220313_B.fcn3);

  // DataStoreWrite: '<Root>/Data Store Write10' incorporates:
  //   Fcn: '<S4>/fcn1'
  //   Fcn: '<S4>/fcn2'
  //   Trigonometry: '<S44>/Trigonometric Function1'

  px42LoopCtrQGC20220313_DW.yaw = rt_atan2d_snf
    ((px42LoopCtrQGC20220313_B.Product1_p * px42LoopCtrQGC20220313_B.Product2_d
      + px42LoopCtrQGC20220313_B.fcn5 * px42LoopCtrQGC20220313_B.Product3_i) *
     2.0, ((u0_tmp + px42LoopCtrQGC20220313_B.rtb_Product1_p_b) - roll_tmp) -
     roll_tmp_0);

  // DataStoreWrite: '<Root>/Data Store Write20' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px42LoopCtrQGC20220313_DW.yaw_speed = px42LoopCtrQGC20220313_B.In1.yawspeed;

  // DataStoreWrite: '<Root>/Data Store Write21' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px42LoopCtrQGC20220313_DW.pitch_speed =
    px42LoopCtrQGC20220313_B.In1.pitchspeed;

  // DataStoreWrite: '<Root>/Data Store Write22' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px42LoopCtrQGC20220313_DW.roll_speed = px42LoopCtrQGC20220313_B.In1.rollspeed;

  // DataStoreWrite: '<S6>/Data Store Write28' incorporates:
  //   Constant: '<S6>/attitude_flag'

  px42LoopCtrQGC20220313_DW.attitude_flag =
    px42LoopCtrQGC20220313_P.attitude_flag_Value;

  // DataStoreWrite: '<S7>/Data Store Write28' incorporates:
  //   Constant: '<S7>/observer_flag'

  px42LoopCtrQGC20220313_DW.observer_flag =
    px42LoopCtrQGC20220313_P.observer_flag_Value;
  for (int32_T i = 0; i < 4; i++) {
    // Gain: '<Root>/Gain4' incorporates:
    //   Constant: '<Root>/Constant1'
    //   Constant: '<Root>/Mixer matrix1'
    //   DataStoreRead: '<Root>/Data Store Read21'
    //   DataStoreRead: '<Root>/Data Store Read22'
    //   DataStoreRead: '<Root>/Data Store Read23'
    //   Product: '<Root>/Product2'
    //   SignalConversion generated from: '<Root>/Product2'

    px42LoopCtrQGC20220313_B.fcn5 = floor
      ((((px42LoopCtrQGC20220313_P.Mixermatrix1_Value[i + 4] *
          px42LoopCtrQGC20220313_B.DataStoreRead25 +
          px42LoopCtrQGC20220313_P.Mixermatrix1_Value[i] *
          px42LoopCtrQGC20220313_P.Constant1_Value_l) +
         px42LoopCtrQGC20220313_P.Mixermatrix1_Value[i + 8] *
         px42LoopCtrQGC20220313_B.DataStoreRead26) +
        px42LoopCtrQGC20220313_P.Mixermatrix1_Value[i + 12] *
        px42LoopCtrQGC20220313_B.DataStoreRead27) *
       px42LoopCtrQGC20220313_P.Gain4_Gain_fc);
    if (rtIsNaN(px42LoopCtrQGC20220313_B.fcn5) || rtIsInf
        (px42LoopCtrQGC20220313_B.fcn5)) {
      px42LoopCtrQGC20220313_B.fcn5 = 0.0;
    } else {
      px42LoopCtrQGC20220313_B.fcn5 = fmod(px42LoopCtrQGC20220313_B.fcn5,
        65536.0);
    }

    px42LoopCtrQGC20220313_B.Gain4[i] = static_cast<uint16_T>
      (px42LoopCtrQGC20220313_B.fcn5 < 0.0 ? static_cast<int32_T>
       (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
          (-px42LoopCtrQGC20220313_B.fcn5)))) : static_cast<int32_T>(
        static_cast<uint16_T>(px42LoopCtrQGC20220313_B.fcn5)));

    // End of Gain: '<Root>/Gain4'
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1'
  for (int32_T i = 0; i < 8; i++) {
    px42LoopCtrQGC20220313_B.pwmValue[i] = 0U;
  }

  // Sum: '<Root>/Add' incorporates:
  //   Constant: '<Root>/fault_1'

  px42LoopCtrQGC20220313_B.fcn5 = floor(static_cast<real_T>
    (px42LoopCtrQGC20220313_B.Gain4[0]) - px42LoopCtrQGC20220313_P.fault_1_Value);
  if (rtIsNaN(px42LoopCtrQGC20220313_B.fcn5) || rtIsInf
      (px42LoopCtrQGC20220313_B.fcn5)) {
    px42LoopCtrQGC20220313_B.fcn5 = 0.0;
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = fmod(px42LoopCtrQGC20220313_B.fcn5, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Sum: '<Root>/Add'

  px42LoopCtrQGC20220313_B.pwmValue[0] = static_cast<uint16_T>
    (px42LoopCtrQGC20220313_B.fcn5 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-px42LoopCtrQGC20220313_B.fcn5)))) : static_cast<int32_T>
     (static_cast<uint16_T>(px42LoopCtrQGC20220313_B.fcn5)));

  // Sum: '<Root>/Add1' incorporates:
  //   Constant: '<Root>/fault_2'

  px42LoopCtrQGC20220313_B.fcn5 = floor(static_cast<real_T>
    (px42LoopCtrQGC20220313_B.Gain4[1]) - px42LoopCtrQGC20220313_P.fault_2_Value);
  if (rtIsNaN(px42LoopCtrQGC20220313_B.fcn5) || rtIsInf
      (px42LoopCtrQGC20220313_B.fcn5)) {
    px42LoopCtrQGC20220313_B.fcn5 = 0.0;
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = fmod(px42LoopCtrQGC20220313_B.fcn5, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Sum: '<Root>/Add1'

  px42LoopCtrQGC20220313_B.pwmValue[1] = static_cast<uint16_T>
    (px42LoopCtrQGC20220313_B.fcn5 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-px42LoopCtrQGC20220313_B.fcn5)))) : static_cast<int32_T>
     (static_cast<uint16_T>(px42LoopCtrQGC20220313_B.fcn5)));

  // Sum: '<Root>/Add2' incorporates:
  //   Constant: '<Root>/fault_3'

  px42LoopCtrQGC20220313_B.fcn5 = floor(static_cast<real_T>
    (px42LoopCtrQGC20220313_B.Gain4[2]) - px42LoopCtrQGC20220313_P.fault_3_Value);
  if (rtIsNaN(px42LoopCtrQGC20220313_B.fcn5) || rtIsInf
      (px42LoopCtrQGC20220313_B.fcn5)) {
    px42LoopCtrQGC20220313_B.fcn5 = 0.0;
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = fmod(px42LoopCtrQGC20220313_B.fcn5, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Sum: '<Root>/Add2'

  px42LoopCtrQGC20220313_B.pwmValue[2] = static_cast<uint16_T>
    (px42LoopCtrQGC20220313_B.fcn5 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-px42LoopCtrQGC20220313_B.fcn5)))) : static_cast<int32_T>
     (static_cast<uint16_T>(px42LoopCtrQGC20220313_B.fcn5)));

  // Sum: '<Root>/Add3' incorporates:
  //   Constant: '<Root>/fault_4'

  px42LoopCtrQGC20220313_B.fcn5 = floor(static_cast<real_T>
    (px42LoopCtrQGC20220313_B.Gain4[3]) - px42LoopCtrQGC20220313_P.fault_4_Value);
  if (rtIsNaN(px42LoopCtrQGC20220313_B.fcn5) || rtIsInf
      (px42LoopCtrQGC20220313_B.fcn5)) {
    px42LoopCtrQGC20220313_B.fcn5 = 0.0;
  } else {
    px42LoopCtrQGC20220313_B.fcn5 = fmod(px42LoopCtrQGC20220313_B.fcn5, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Reset'
  //   Sum: '<Root>/Add3'

  px42LoopCtrQGC20220313_B.pwmValue[3] = static_cast<uint16_T>
    (px42LoopCtrQGC20220313_B.fcn5 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-px42LoopCtrQGC20220313_B.fcn5)))) : static_cast<int32_T>
     (static_cast<uint16_T>(px42LoopCtrQGC20220313_B.fcn5)));
  if (px42LoopCtrQGC20220313_P.Reset_Value) {
    if (!px42LoopCtrQGC20220313_DW.obj.isArmed) {
      px42LoopCtrQGC20220313_DW.obj.isArmed = true;
      status = pwm_arm(&px42LoopCtrQGC20220313_DW.obj.pwmDevHandler,
                       &px42LoopCtrQGC20220313_DW.obj.armAdvertiseObj);
      px42LoopCtrQGC20220313_DW.obj.errorStatus = static_cast<uint16_T>
        (px42LoopCtrQGC20220313_DW.obj.errorStatus | status);
    }

    status = pwm_setServo(&px42LoopCtrQGC20220313_DW.obj.pwmDevHandler,
                          px42LoopCtrQGC20220313_DW.obj.servoCount,
                          px42LoopCtrQGC20220313_DW.obj.channelMask,
                          &px42LoopCtrQGC20220313_B.pwmValue[0],
                          px42LoopCtrQGC20220313_DW.obj.isMain,
                          &px42LoopCtrQGC20220313_DW.obj.actuatorAdvertiseObj);
    px42LoopCtrQGC20220313_DW.obj.errorStatus = static_cast<uint16_T>
      (px42LoopCtrQGC20220313_DW.obj.errorStatus | status);
  } else {
    status = pwm_disarm(&px42LoopCtrQGC20220313_DW.obj.pwmDevHandler,
                        &px42LoopCtrQGC20220313_DW.obj.armAdvertiseObj);
    px42LoopCtrQGC20220313_DW.obj.errorStatus = static_cast<uint16_T>
      (px42LoopCtrQGC20220313_DW.obj.errorStatus | status);
    px42LoopCtrQGC20220313_DW.obj.isArmed = false;
    status = pwm_resetServo(&px42LoopCtrQGC20220313_DW.obj.pwmDevHandler,
      px42LoopCtrQGC20220313_DW.obj.servoCount,
      px42LoopCtrQGC20220313_DW.obj.channelMask,
      px42LoopCtrQGC20220313_DW.obj.isMain,
      &px42LoopCtrQGC20220313_DW.obj.actuatorAdvertiseObj);
    px42LoopCtrQGC20220313_DW.obj.errorStatus = static_cast<uint16_T>
      (px42LoopCtrQGC20220313_DW.obj.errorStatus | status);
  }

  if (px42LoopCtrQGC20220313_DW.obj.isMain) {
    status = pwm_forceFailsafe(&px42LoopCtrQGC20220313_DW.obj.pwmDevHandler,
      static_cast<int32_T>(px42LoopCtrQGC20220313_P.Constant2_Value_kf));
    px42LoopCtrQGC20220313_DW.obj.errorStatus = static_cast<uint16_T>
      (px42LoopCtrQGC20220313_DW.obj.errorStatus | status);
  }

  // Gain: '<Root>/Gain8' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read31'

  px42LoopCtrQGC20220313_B.pitch = px42LoopCtrQGC20220313_P.Gain8_Gain_o1 *
    px42LoopCtrQGC20220313_DW.pitch;

  // Gain: '<Root>/Gain10'
  px42LoopCtrQGC20220313_B.pitch_a = px42LoopCtrQGC20220313_P.Gain10_Gain *
    px42LoopCtrQGC20220313_B.ManualSwitch_g;

  // Gain: '<Root>/Gain7' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read30'

  px42LoopCtrQGC20220313_B.roll = px42LoopCtrQGC20220313_P.Gain7_Gain_a *
    px42LoopCtrQGC20220313_DW.roll;

  // Gain: '<Root>/Gain11'
  px42LoopCtrQGC20220313_B.pitch_g = px42LoopCtrQGC20220313_P.Gain11_Gain *
    px42LoopCtrQGC20220313_B.ManualSwitch_g;

  // Gain: '<Root>/Gain9' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read33'

  px42LoopCtrQGC20220313_B.yaw = px42LoopCtrQGC20220313_P.Gain9_Gain *
    px42LoopCtrQGC20220313_DW.yaw;

  // Logic: '<S3>/NOT' incorporates:
  //   MATLABSystem: '<S3>/SourceBlock'

  px42LoopCtrQGC20220313_B.NOT = !rtb_LogicalOperator;

  // Gain: '<Root>/Gain5' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read10'

  px42LoopCtrQGC20220313_B.Gain5 = px42LoopCtrQGC20220313_P.Gain5_Gain_g *
    px42LoopCtrQGC20220313_DW.pitch;

  // Gain: '<Root>/Gain3' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read11'

  px42LoopCtrQGC20220313_B.Gain3 = px42LoopCtrQGC20220313_P.Gain3_Gain_c *
    px42LoopCtrQGC20220313_DW.roll;

  // DataStoreRead: '<Root>/Data Store Read12' incorporates:
  //   Constant: '<Root>/Reset'

  px42LoopCtrQGC20220313_B.DataStoreRead12 =
    px42LoopCtrQGC20220313_P.Reset_Value;

  // DataStoreRead: '<Root>/Data Store Read13' incorporates:
  //   Constant: '<Root>/Constant1'

  px42LoopCtrQGC20220313_B.DataStoreRead13 =
    px42LoopCtrQGC20220313_P.Constant1_Value_l;

  // DataStoreRead: '<Root>/Data Store Read15'
  px42LoopCtrQGC20220313_B.DataStoreRead15 = px42LoopCtrQGC20220313_DW.speed_y;

  // DataStoreRead: '<Root>/Data Store Read16'
  px42LoopCtrQGC20220313_B.DataStoreRead16 = px42LoopCtrQGC20220313_DW.pos_x;

  // DataStoreRead: '<Root>/Data Store Read17'
  px42LoopCtrQGC20220313_B.DataStoreRead17 = px42LoopCtrQGC20220313_DW.pos_y;

  // DataStoreRead: '<Root>/Data Store Read19'
  px42LoopCtrQGC20220313_B.DataStoreRead19 = px42LoopCtrQGC20220313_DW.speed_x;

  // Gain: '<Root>/Gain6' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read24'

  px42LoopCtrQGC20220313_B.Gain6 = px42LoopCtrQGC20220313_P.Gain6_Gain_k *
    px42LoopCtrQGC20220313_DW.yaw;

  // DataStoreRead: '<Root>/Data Store Read28'
  px42LoopCtrQGC20220313_B.pitch_thrust =
    px42LoopCtrQGC20220313_B.DataStoreRead25;

  // DataStoreRead: '<Root>/Data Store Read29'
  px42LoopCtrQGC20220313_B.roll_thrust =
    px42LoopCtrQGC20220313_B.DataStoreRead26;

  // DataStoreRead: '<Root>/Data Store Read32'
  px42LoopCtrQGC20220313_B.yaw_thrust = px42LoopCtrQGC20220313_B.DataStoreRead27;

  // DataStoreRead: '<Root>/Data Store Read41'
  px42LoopCtrQGC20220313_B.DataStoreRead41 = px42LoopCtrQGC20220313_DW.u1;

  // DataStoreRead: '<Root>/Data Store Read34'
  px42LoopCtrQGC20220313_B.DataStoreRead34 = px42LoopCtrQGC20220313_DW.yaw_speed;

  // DataStoreRead: '<Root>/Data Store Read35'
  px42LoopCtrQGC20220313_B.DataStoreRead35 =
    px42LoopCtrQGC20220313_DW.pitch_speed;

  // DataStoreRead: '<Root>/Data Store Read36'
  px42LoopCtrQGC20220313_B.DataStoreRead36 =
    px42LoopCtrQGC20220313_DW.roll_speed;

  // DataStoreRead: '<Root>/Data Store Read37'
  px42LoopCtrQGC20220313_B.DataStoreRead37 = px42LoopCtrQGC20220313_DW.yaw_acc;

  // DataStoreRead: '<Root>/Data Store Read38'
  px42LoopCtrQGC20220313_B.DataStoreRead38 = px42LoopCtrQGC20220313_DW.pitch_acc;

  // DataStoreRead: '<Root>/Data Store Read39'
  px42LoopCtrQGC20220313_B.DataStoreRead39 = px42LoopCtrQGC20220313_DW.roll_acc;

  // DataStoreRead: '<Root>/Data Store Read48'
  px42LoopCtrQGC20220313_B.DataStoreRead48 = px42LoopCtrQGC20220313_DW.pos_x;

  // DataStoreRead: '<Root>/Data Store Read49'
  px42LoopCtrQGC20220313_B.DataStoreRead49 = px42LoopCtrQGC20220313_DW.pos_y;

  // Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
  //   EnablePort: '<S5>/Enable'

  // DataStoreRead: '<Root>/Data Store Read54'
  if (px42LoopCtrQGC20220313_DW.attitude_flag) {
    // DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
    //   DataStoreWrite: '<S5>/Data Store Write27'

    px42LoopCtrQGC20220313_DW.t =
      px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTAT_fj;

    // Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S5>/Constant9'

    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTAT_fj +=
      px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_gainval *
      px42LoopCtrQGC20220313_P.Constant9_Value;
    srUpdateBC(px42LoopCtrQGC20220313_DW.Subsystem1_SubsysRanBC);
  }

  // End of DataStoreRead: '<Root>/Data Store Read54'
  // End of Outputs for SubSystem: '<Root>/Subsystem1'

  // DataStoreRead: '<Root>/Data Store Read55'
  px42LoopCtrQGC20220313_B.DataStoreRead55 = px42LoopCtrQGC20220313_DW.t;

  // DataStoreRead: '<Root>/Data Store Read8'
  px42LoopCtrQGC20220313_B.DataStoreRead8 = px42LoopCtrQGC20220313_DW.accX;

  // DataStoreRead: '<Root>/Data Store Read9'
  px42LoopCtrQGC20220313_B.DataStoreRead9 = px42LoopCtrQGC20220313_DW.accY;

  // Update for UnitDelay: '<S33>/UD'
  //
  //  Block description for '<S33>/UD':
  //
  //   Store in Global RAM

  px42LoopCtrQGC20220313_DW.UD_DSTATE = px42LoopCtrQGC20220313_B.TSamp;

  // Saturate: '<S14>/Saturation3'
  if (px42LoopCtrQGC20220313_B.Abs6 >
      px42LoopCtrQGC20220313_P.Saturation3_UpperSat) {
    px42LoopCtrQGC20220313_B.Product2_d =
      px42LoopCtrQGC20220313_P.Saturation3_UpperSat;
  } else if (px42LoopCtrQGC20220313_B.Abs6 <
             px42LoopCtrQGC20220313_P.Saturation3_LowerSat) {
    px42LoopCtrQGC20220313_B.Product2_d =
      px42LoopCtrQGC20220313_P.Saturation3_LowerSat;
  } else {
    px42LoopCtrQGC20220313_B.Product2_d = px42LoopCtrQGC20220313_B.Abs6;
  }

  // End of Saturate: '<S14>/Saturation3'

  // Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator3' incorporates:
  //   Gain: '<S14>/Gain7'
  //   Gain: '<S14>/l4'
  //   Gain: '<S14>/lambda4'
  //   Sum: '<S14>/Add15'
  //   Sum: '<S14>/Add5'

  px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator3_DSTATE +=
    ((px42LoopCtrQGC20220313_P.l4_Gain * px42LoopCtrQGC20220313_B.Product2_d +
      px42LoopCtrQGC20220313_P.lambda4_Gain * px42LoopCtrQGC20220313_B.Abs6) +
     (px42LoopCtrQGC20220313_B.Product6 + px42LoopCtrQGC20220313_B.roll_hat) *
     px42LoopCtrQGC20220313_P.Gain7_Gain) *
    px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator3_gainval;

  // Update for Sin: '<Root>/Sine Wave'
  px42LoopCtrQGC20220313_B.TSamp = px42LoopCtrQGC20220313_DW.lastSin;
  px42LoopCtrQGC20220313_DW.lastSin = px42LoopCtrQGC20220313_DW.lastSin *
    px42LoopCtrQGC20220313_P.SineWave_HCos + px42LoopCtrQGC20220313_DW.lastCos *
    px42LoopCtrQGC20220313_P.SineWave_Hsin;
  px42LoopCtrQGC20220313_DW.lastCos = px42LoopCtrQGC20220313_DW.lastCos *
    px42LoopCtrQGC20220313_P.SineWave_HCos - px42LoopCtrQGC20220313_B.TSamp *
    px42LoopCtrQGC20220313_P.SineWave_Hsin;

  // Update for UnitDelay: '<S15>/UD'
  //
  //  Block description for '<S15>/UD':
  //
  //   Store in Global RAM

  px42LoopCtrQGC20220313_DW.UD_DSTATE_b = px42LoopCtrQGC20220313_B.z2;

  // Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator3' incorporates:
  //   Gain: '<S12>/Gain7'
  //   Gain: '<S12>/l4'
  //   Sum: '<S12>/Add15'
  //   Sum: '<S12>/Add5'

  px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator3_DSTAT_a +=
    ((px42LoopCtrQGC20220313_P.l4_Gain_p * px42LoopCtrQGC20220313_B.roll_hat_k +
      px42LoopCtrQGC20220313_B.lambda4_n) + (px42LoopCtrQGC20220313_B.Product6_i
      + px42LoopCtrQGC20220313_B.Product5_b) *
     px42LoopCtrQGC20220313_P.Gain7_Gain_d) *
    px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator3_gainv_m;

  // Update for UnitDelay: '<S24>/UD'
  //
  //  Block description for '<S24>/UD':
  //
  //   Store in Global RAM

  px42LoopCtrQGC20220313_DW.UD_DSTATE_n = px42LoopCtrQGC20220313_B.z2_e;

  // Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator3' incorporates:
  //   Gain: '<S13>/Gain7'
  //   Gain: '<S13>/l4'
  //   Sum: '<S13>/Add15'
  //   Sum: '<S13>/Add5'

  px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator3_DSTAT_m +=
    ((px42LoopCtrQGC20220313_P.l4_Gain_o *
      px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_1 +
      px42LoopCtrQGC20220313_B.lambda4_h) + (px42LoopCtrQGC20220313_B.Product6_a
      + px42LoopCtrQGC20220313_B.Product5_l) *
     px42LoopCtrQGC20220313_P.Gain7_Gain_l) *
    px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator3_gainv_e;

  // Saturate: '<S14>/Saturation'
  if (px42LoopCtrQGC20220313_B.Abs6 >
      px42LoopCtrQGC20220313_P.Saturation_UpperSat_b) {
    px42LoopCtrQGC20220313_B.Product2_d =
      px42LoopCtrQGC20220313_P.Saturation_UpperSat_b;
  } else if (px42LoopCtrQGC20220313_B.Abs6 <
             px42LoopCtrQGC20220313_P.Saturation_LowerSat_k) {
    px42LoopCtrQGC20220313_B.Product2_d =
      px42LoopCtrQGC20220313_P.Saturation_LowerSat_k;
  } else {
    px42LoopCtrQGC20220313_B.Product2_d = px42LoopCtrQGC20220313_B.Abs6;
  }

  // End of Saturate: '<S14>/Saturation'

  // Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S14>/Discrete-Time Integrator1'
  //   Gain: '<S14>/Gain5'
  //   Gain: '<S14>/l1'
  //   Gain: '<S14>/lambda1'
  //   Sum: '<S14>/Add'
  //   Sum: '<S14>/Add9'

  px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTATE +=
    (((px42LoopCtrQGC20220313_P.l1_Gain * px42LoopCtrQGC20220313_B.Product2_d +
       px42LoopCtrQGC20220313_P.lambda1_Gain * px42LoopCtrQGC20220313_B.Abs6) +
      px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator1_DSTATE) +
     (px42LoopCtrQGC20220313_B.Add3 + px42LoopCtrQGC20220313_B.Product4) *
     px42LoopCtrQGC20220313_P.Gain5_Gain) *
    px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_gainva_n;

  // Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1'
  px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator1_DSTATE +=
    px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator1_gainval *
    px42LoopCtrQGC20220313_B.z2_l;

  // Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S12>/Discrete-Time Integrator1'
  //   Gain: '<S12>/Gain5'
  //   Gain: '<S12>/l1'
  //   Sum: '<S12>/Add'
  //   Sum: '<S12>/Add9'

  px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTATE_p +=
    (((px42LoopCtrQGC20220313_P.l1_Gain_p * px42LoopCtrQGC20220313_B.roll_hat_e
       + px42LoopCtrQGC20220313_B.lambda1_a) +
      px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator1_DSTAT_i) +
     (px42LoopCtrQGC20220313_B.Product3_a + px42LoopCtrQGC20220313_B.Product4_k)
     * px42LoopCtrQGC20220313_P.Gain5_Gain_o) *
    px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_gainva_e;

  // Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1'
  px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator1_DSTAT_i +=
    px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator1_gainv_n *
    px42LoopCtrQGC20220313_B.Add2_o;

  // Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S13>/Discrete-Time Integrator1'
  //   Gain: '<S13>/Gain5'
  //   Gain: '<S13>/l1'
  //   Sum: '<S13>/Add'
  //   Sum: '<S13>/Add9'

  px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTATE_f +=
    (((px42LoopCtrQGC20220313_P.l1_Gain_d *
       px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_2 +
       px42LoopCtrQGC20220313_B.lambda1_e) +
      px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator1_DSTAT_g) +
     (px42LoopCtrQGC20220313_B.Product3_c + px42LoopCtrQGC20220313_B.Product4_g)
     * px42LoopCtrQGC20220313_P.Gain5_Gain_l) *
    px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_gainv_nv;

  // Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator1'
  px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator1_DSTAT_g +=
    px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator1_gainv_g *
    px42LoopCtrQGC20220313_B.rtb_DataTypeConversion3_idx_0;

  // External mode
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)px42LoopCtrQGC20220313_M->Timing.taskTime0);

  // signal main to stop simulation
  {                                    // Sample time: [0.005s, 0.0s]
    if ((rtmGetTFinal(px42LoopCtrQGC20220313_M)!=-1) &&
        !((rtmGetTFinal(px42LoopCtrQGC20220313_M)-
           px42LoopCtrQGC20220313_M->Timing.taskTime0) >
          px42LoopCtrQGC20220313_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(px42LoopCtrQGC20220313_M, "Simulation finished");
    }

    if (rtmGetStopRequested(px42LoopCtrQGC20220313_M)) {
      rtmSetErrorStatus(px42LoopCtrQGC20220313_M, "Simulation finished");
    }
  }

  // Update absolute time
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  px42LoopCtrQGC20220313_M->Timing.taskTime0 =
    ((time_T)(++px42LoopCtrQGC20220313_M->Timing.clockTick0)) *
    px42LoopCtrQGC20220313_M->Timing.stepSize0;
}

// Model step function for TID1
void px42LoopCtrQGC20220313_step1(void) // Sample time: [0.01s, 0.0s]
{
  uint64_T rtb_timestamp;
  uint32_T rtb_noutputs;
  uint8_T rtb__padding0[4];
  boolean_T b_varargout_1;
  boolean_T rtb_NOT;

  // Reset subsysRan breadcrumbs
  srClearBC(px42LoopCtrQGC20220313_DW.EnabledSubsystem_SubsysRanBC_b);

  // MATLABSystem: '<S2>/SourceBlock'
  b_varargout_1 = uORB_read_step(px42LoopCtrQGC20220313_DW.obj_l.orbMetadataObj,
    &px42LoopCtrQGC20220313_DW.obj_l.eventStructObj,
    &px42LoopCtrQGC20220313_B.b_varargout_2_m, false, 1.0);

  // Outputs for Enabled SubSystem: '<S2>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S42>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S42>/In1'
    px42LoopCtrQGC20220313_B.In1_a = px42LoopCtrQGC20220313_B.b_varargout_2_m;
    srUpdateBC(px42LoopCtrQGC20220313_DW.EnabledSubsystem_SubsysRanBC_b);
  }

  // End of Outputs for SubSystem: '<S2>/Enabled Subsystem'

  // SignalConversion generated from: '<Root>/Bus Selector'
  memcpy(&px42LoopCtrQGC20220313_B.output[0],
         &px42LoopCtrQGC20220313_B.In1_a.output[0], sizeof(real32_T) << 4U);

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb_timestamp = px42LoopCtrQGC20220313_B.In1_a.timestamp;

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb_noutputs = px42LoopCtrQGC20220313_B.In1_a.noutputs;

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb__padding0[0] = px42LoopCtrQGC20220313_B.In1_a._padding0[0];
  rtb__padding0[1] = px42LoopCtrQGC20220313_B.In1_a._padding0[1];
  rtb__padding0[2] = px42LoopCtrQGC20220313_B.In1_a._padding0[2];
  rtb__padding0[3] = px42LoopCtrQGC20220313_B.In1_a._padding0[3];

  // Logic: '<S2>/NOT' incorporates:
  //   MATLABSystem: '<S2>/SourceBlock'

  rtb_NOT = !b_varargout_1;
  rtExtModeUpload(1, (real_T)((px42LoopCtrQGC20220313_M->Timing.clockTick1) *
    0.01));

  // Update absolute time
  // The "clockTick1" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.01, which is the step size
  //  of the task. Size of "clockTick1" ensures timer will not overflow during the
  //  application lifespan selected.

  px42LoopCtrQGC20220313_M->Timing.clockTick1++;
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void px42LoopCtrQGC20220313_step(int_T tid)
{
  switch (tid) {
   case 0 :
    px42LoopCtrQGC20220313_step0();
    break;

   case 1 :
    px42LoopCtrQGC20220313_step1();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void px42LoopCtrQGC20220313_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(px42LoopCtrQGC20220313_M, -1);
  px42LoopCtrQGC20220313_M->Timing.stepSize0 = 0.005;

  // External mode info
  px42LoopCtrQGC20220313_M->Sizes.checksums[0] = (2862294771U);
  px42LoopCtrQGC20220313_M->Sizes.checksums[1] = (871401741U);
  px42LoopCtrQGC20220313_M->Sizes.checksums[2] = (998257096U);
  px42LoopCtrQGC20220313_M->Sizes.checksums[3] = (569271191U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[27];
    px42LoopCtrQGC20220313_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &px42LoopCtrQGC20220313_DW.Subsystem_SubsysRanBC_k;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)
      &px42LoopCtrQGC20220313_DW.Subsystem_SubsysRanBC_m;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)
      &px42LoopCtrQGC20220313_DW.Subsystem_SubsysRanBC;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = (sysRanDType *)
      &px42LoopCtrQGC20220313_DW.EnabledSubsystem_SubsysRanBC_b;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = (sysRanDType *)
      &px42LoopCtrQGC20220313_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = (sysRanDType *)
      &px42LoopCtrQGC20220313_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &px42LoopCtrQGC20220313_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &px42LoopCtrQGC20220313_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &px42LoopCtrQGC20220313_DW.Subsystem1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(px42LoopCtrQGC20220313_M->extModeInfo,
      &px42LoopCtrQGC20220313_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(px42LoopCtrQGC20220313_M->extModeInfo,
                        px42LoopCtrQGC20220313_M->Sizes.checksums);
    rteiSetTPtr(px42LoopCtrQGC20220313_M->extModeInfo, rtmGetTPtr
                (px42LoopCtrQGC20220313_M));
  }

  // block I/O
  (void) memset((static_cast<void *>(&px42LoopCtrQGC20220313_B)), 0,
                sizeof(B_px42LoopCtrQGC20220313_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&px42LoopCtrQGC20220313_DW), 0,
                sizeof(DW_px42LoopCtrQGC20220313_T));

  // external outputs
  px42LoopCtrQGC20220313_Y.u = 0.0;

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    px42LoopCtrQGC20220313_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 26;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    boolean_T rtb_DataStoreRead6;

    // Start for DataStoreMemory: '<S35>/Data Store Memory'
    px42LoopCtrQGC20220313_DW.start_time_yaw =
      px42LoopCtrQGC20220313_P.DataStoreMemory_InitialValue;

    // Start for DataStoreMemory: '<S17>/Data Store Memory'
    px42LoopCtrQGC20220313_DW.start_time =
      px42LoopCtrQGC20220313_P.DataStoreMemory_InitialValue_l;

    // Start for DataStoreMemory: '<S26>/Data Store Memory'
    px42LoopCtrQGC20220313_DW.start_time_roll =
      px42LoopCtrQGC20220313_P.DataStoreMemory_InitialValue_b;

    // Start for Sum: '<S16>/Add' incorporates:
    //   DataStoreMemory: '<S1>/e_pitch'

    px42LoopCtrQGC20220313_DW.e_pitch =
      px42LoopCtrQGC20220313_P.e_pitch_InitialValue;

    // Start for Sum: '<S25>/Add' incorporates:
    //   DataStoreMemory: '<S1>/e_pitch1'

    px42LoopCtrQGC20220313_DW.e_pitch_roll =
      px42LoopCtrQGC20220313_P.e_pitch1_InitialValue;

    // Start for Sum: '<S34>/Add' incorporates:
    //   DataStoreMemory: '<S1>/e_pitch2'

    px42LoopCtrQGC20220313_DW.e_pitch_yaw =
      px42LoopCtrQGC20220313_P.e_pitch2_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory'
    px42LoopCtrQGC20220313_DW.attitude_flag =
      px42LoopCtrQGC20220313_P.DataStoreMemory_InitialValue_j;

    // Start for DataStoreMemory: '<Root>/Data Store Memory10'
    px42LoopCtrQGC20220313_DW.speed_y =
      px42LoopCtrQGC20220313_P.DataStoreMemory10_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory11'
    px42LoopCtrQGC20220313_DW.pos_x =
      px42LoopCtrQGC20220313_P.DataStoreMemory11_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory12'
    px42LoopCtrQGC20220313_DW.pos_y =
      px42LoopCtrQGC20220313_P.DataStoreMemory12_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory16'
    px42LoopCtrQGC20220313_DW.yaw_speed =
      px42LoopCtrQGC20220313_P.DataStoreMemory16_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory17'
    px42LoopCtrQGC20220313_DW.roll_speed =
      px42LoopCtrQGC20220313_P.DataStoreMemory17_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory18'
    px42LoopCtrQGC20220313_DW.pitch_speed =
      px42LoopCtrQGC20220313_P.DataStoreMemory18_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory19'
    px42LoopCtrQGC20220313_DW.pitch_acc =
      px42LoopCtrQGC20220313_P.DataStoreMemory19_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory2'
    px42LoopCtrQGC20220313_DW.accX =
      px42LoopCtrQGC20220313_P.DataStoreMemory2_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory20'
    px42LoopCtrQGC20220313_DW.roll_acc =
      px42LoopCtrQGC20220313_P.DataStoreMemory20_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory21'
    px42LoopCtrQGC20220313_DW.yaw_acc =
      px42LoopCtrQGC20220313_P.DataStoreMemory21_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory28'
    px42LoopCtrQGC20220313_DW.u1 =
      px42LoopCtrQGC20220313_P.DataStoreMemory28_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory29'
    px42LoopCtrQGC20220313_DW.t =
      px42LoopCtrQGC20220313_P.DataStoreMemory29_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory3'
    px42LoopCtrQGC20220313_DW.accY =
      px42LoopCtrQGC20220313_P.DataStoreMemory3_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory30'
    px42LoopCtrQGC20220313_DW.observer_flag =
      px42LoopCtrQGC20220313_P.DataStoreMemory30_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory4'
    px42LoopCtrQGC20220313_DW.pitch =
      px42LoopCtrQGC20220313_P.DataStoreMemory4_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory6'
    px42LoopCtrQGC20220313_DW.roll =
      px42LoopCtrQGC20220313_P.DataStoreMemory6_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory8'
    px42LoopCtrQGC20220313_DW.yaw =
      px42LoopCtrQGC20220313_P.DataStoreMemory8_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory9'
    px42LoopCtrQGC20220313_DW.speed_x =
      px42LoopCtrQGC20220313_P.DataStoreMemory9_InitialValue;
    px42LoopCtrQGC20220313_PrevZCX.Subsystem_Trig_ZCE_e = POS_ZCSIG;
    px42LoopCtrQGC20220313_PrevZCX.Subsystem_Trig_ZCE_j = POS_ZCSIG;
    px42LoopCtrQGC20220313_PrevZCX.Subsystem_Trig_ZCE = POS_ZCSIG;

    // InitializeConditions for UnitDelay: '<S33>/UD'
    //
    //  Block description for '<S33>/UD':
    //
    //   Store in Global RAM

    px42LoopCtrQGC20220313_DW.UD_DSTATE =
      px42LoopCtrQGC20220313_P.DiscreteDerivative1_ICPrevScale;

    // InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator3' 
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator3_DSTATE =
      px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator3_IC;

    // InitializeConditions for UnitDelay: '<S15>/UD'
    //
    //  Block description for '<S15>/UD':
    //
    //   Store in Global RAM

    px42LoopCtrQGC20220313_DW.UD_DSTATE_b =
      px42LoopCtrQGC20220313_P.DiscreteDerivative1_ICPrevSca_o;

    // InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator3' 
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator3_DSTAT_a =
      px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator3_IC_k;

    // InitializeConditions for UnitDelay: '<S24>/UD'
    //
    //  Block description for '<S24>/UD':
    //
    //   Store in Global RAM

    px42LoopCtrQGC20220313_DW.UD_DSTATE_n =
      px42LoopCtrQGC20220313_P.DiscreteDerivative1_ICPrevSca_d;

    // InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator3' 
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator3_DSTAT_m =
      px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator3_IC_l;

    // InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' 
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTATE =
      px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_IC_l;

    // InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' 
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator1_DSTATE =
      px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' 
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTATE_p =
      px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_IC_h;

    // InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' 
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator1_DSTAT_i =
      px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator1_IC_j;

    // InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' 
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTATE_f =
      px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_IC_o;

    // InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator1' 
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator1_DSTAT_g =
      px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator1_IC_c;

    // SystemInitialize for Enabled SubSystem: '<S2>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S42>/In1' incorporates:
    //   Outport: '<S42>/Out1'

    px42LoopCtrQGC20220313_B.In1_a = px42LoopCtrQGC20220313_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S2>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S43>/In1' incorporates:
    //   Outport: '<S43>/Out1'

    px42LoopCtrQGC20220313_B.In1 = px42LoopCtrQGC20220313_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1'
    // InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' 
    px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTAT_fj =
      px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_IC;

    // End of SystemInitialize for SubSystem: '<Root>/Subsystem1'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    px42LoopCtrQGC20220313_DW.obj_n.matlabCodegenIsDeleted = false;
    px42LoopCtrQGC20220313_DW.obj_n.isSetupComplete = false;
    px42LoopCtrQGC20220313_DW.obj_n.isInitialized = 1;
    px42LoopCtrQGC20220313_DW.obj_n.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(px42LoopCtrQGC20220313_DW.obj_n.orbMetadataObj,
                         &px42LoopCtrQGC20220313_DW.obj_n.eventStructObj);
    px42LoopCtrQGC20220313_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
    //   Constant: '<Root>/Constant2'

    px42LoopCtrQGC20220313_DW.obj.errorStatus = 0U;
    px42LoopCtrQGC20220313_DW.obj.isInitialized = 0;
    px42LoopCtrQGC20220313_DW.obj.matlabCodegenIsDeleted = false;
    px42LoopCtrQGC_SystemCore_setup(&px42LoopCtrQGC20220313_DW.obj,
      rtb_DataStoreRead6, px42LoopCtrQGC20220313_P.Constant2_Value_kf);

    // Start for MATLABSystem: '<S2>/SourceBlock'
    px42LoopCtrQGC20220313_DW.obj_l.matlabCodegenIsDeleted = false;
    px42LoopCtrQGC20220313_DW.obj_l.isSetupComplete = false;
    px42LoopCtrQGC20220313_DW.obj_l.isInitialized = 1;
    px42LoopCtrQGC20220313_DW.obj_l.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_read_initialize(px42LoopCtrQGC20220313_DW.obj_l.orbMetadataObj,
                         &px42LoopCtrQGC20220313_DW.obj_l.eventStructObj);
    px42LoopCtrQGC20220313_DW.obj_l.isSetupComplete = true;

    // Enable for Sin: '<Root>/Sine Wave'
    px42LoopCtrQGC20220313_DW.systemEnable = 1;

    // ConstCode for Outport: '<Root>/u'
    px42LoopCtrQGC20220313_Y.u = 0.0;
  }
}

// Model terminate function
void px42LoopCtrQGC20220313_terminate(void)
{
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!px42LoopCtrQGC20220313_DW.obj_n.matlabCodegenIsDeleted) {
    px42LoopCtrQGC20220313_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((px42LoopCtrQGC20220313_DW.obj_n.isInitialized == 1) &&
        px42LoopCtrQGC20220313_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&px42LoopCtrQGC20220313_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'

  // Terminate for MATLABSystem: '<Root>/PX4 PWM Output1'
  if (!px42LoopCtrQGC20220313_DW.obj.matlabCodegenIsDeleted) {
    px42LoopCtrQGC20220313_DW.obj.matlabCodegenIsDeleted = true;
    if ((px42LoopCtrQGC20220313_DW.obj.isInitialized == 1) &&
        px42LoopCtrQGC20220313_DW.obj.isSetupComplete) {
      uint16_T status;
      status = pwm_disarm(&px42LoopCtrQGC20220313_DW.obj.pwmDevHandler,
                          &px42LoopCtrQGC20220313_DW.obj.armAdvertiseObj);
      px42LoopCtrQGC20220313_DW.obj.errorStatus = static_cast<uint16_T>
        (px42LoopCtrQGC20220313_DW.obj.errorStatus | status);
      status = pwm_resetServo(&px42LoopCtrQGC20220313_DW.obj.pwmDevHandler,
        px42LoopCtrQGC20220313_DW.obj.servoCount,
        px42LoopCtrQGC20220313_DW.obj.channelMask,
        px42LoopCtrQGC20220313_DW.obj.isMain,
        &px42LoopCtrQGC20220313_DW.obj.actuatorAdvertiseObj);
      px42LoopCtrQGC20220313_DW.obj.errorStatus = static_cast<uint16_T>
        (px42LoopCtrQGC20220313_DW.obj.errorStatus | status);
      status = pwm_close(&px42LoopCtrQGC20220313_DW.obj.pwmDevHandler,
                         &px42LoopCtrQGC20220313_DW.obj.actuatorAdvertiseObj,
                         &px42LoopCtrQGC20220313_DW.obj.armAdvertiseObj);
      px42LoopCtrQGC20220313_DW.obj.errorStatus = static_cast<uint16_T>
        (px42LoopCtrQGC20220313_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 PWM Output1'

  // Terminate for MATLABSystem: '<S2>/SourceBlock'
  if (!px42LoopCtrQGC20220313_DW.obj_l.matlabCodegenIsDeleted) {
    px42LoopCtrQGC20220313_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((px42LoopCtrQGC20220313_DW.obj_l.isInitialized == 1) &&
        px42LoopCtrQGC20220313_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&px42LoopCtrQGC20220313_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S2>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
