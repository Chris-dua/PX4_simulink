//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4CtrlQGCGPS.cpp
//
// Code generated for Simulink model 'px4CtrlQGCGPS'.
//
// Model version                  : 5.30
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Fri Mar 18 18:41:57 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "px4CtrlQGCGPS.h"
#include "rtwtypes.h"
#include "px4CtrlQGCGPS_types.h"
#include "px4CtrlQGCGPS_private.h"
#include <math.h>

extern "C" {

#include "rt_nonfinite.h"

}
#include <string.h>
#include "rt_defines.h"
#include "zero_crossing_types.h"
#include "px4CtrlQGCGPS_dt.h"

// Block signals (default storage)
B_px4CtrlQGCGPS_T px4CtrlQGCGPS_B;

// Block states (default storage)
DW_px4CtrlQGCGPS_T px4CtrlQGCGPS_DW;

// Previous zero-crossings (trigger) states
PrevZCX_px4CtrlQGCGPS_T px4CtrlQGCGPS_PrevZCX;

// Real-time model
RT_MODEL_px4CtrlQGCGPS_T px4CtrlQGCGPS_M_ = RT_MODEL_px4CtrlQGCGPS_T();
RT_MODEL_px4CtrlQGCGPS_T *const px4CtrlQGCGPS_M = &px4CtrlQGCGPS_M_;

// Forward declaration for local functions
static void px4CtrlQGCGPS_SystemCore_setup(px4_internal_block_PWM_px4Ctr_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void px4CtrlQGCGPS_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(px4CtrlQGCGPS_M, 1));
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

  (px4CtrlQGCGPS_M->Timing.TaskCounters.TID[1])++;
  if ((px4CtrlQGCGPS_M->Timing.TaskCounters.TID[1]) > 1) {// Sample time: [0.01s, 0.0s] 
    px4CtrlQGCGPS_M->Timing.TaskCounters.TID[1] = 0;
  }
}

//
// Output and update for atomic system:
//    '<S19>/MATLAB Function'
//    '<S28>/MATLAB Function'
//    '<S37>/MATLAB Function'
//
void px4CtrlQGCGP_MATLABFunction(boolean_T rtu_e, real_T rtu_t, real_T rtu_s_t,
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

static void px4CtrlQGCGPS_SystemCore_setup(px4_internal_block_PWM_px4Ctr_T *obj,
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
void px4CtrlQGCGPS_step0(void)         // Sample time: [0.005s, 0.0s]
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
  srClearBC(px4CtrlQGCGPS_DW.Subsystem_SubsysRanBC_k);

  // Reset subsysRan breadcrumbs
  srClearBC(px4CtrlQGCGPS_DW.Subsystem_SubsysRanBC_m);

  // Reset subsysRan breadcrumbs
  srClearBC(px4CtrlQGCGPS_DW.Subsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px4CtrlQGCGPS_DW.EnabledSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px4CtrlQGCGPS_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px4CtrlQGCGPS_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px4CtrlQGCGPS_DW.IfActionSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px4CtrlQGCGPS_DW.Subsystem1_SubsysRanBC);

  // Switch: '<S13>/Switch' incorporates:
  //   Constant: '<Root>/Constant3'
  //   Constant: '<S13>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read20'
  //   DataStoreRead: '<S13>/Data Store Read'
  //   DataStoreRead: '<S13>/Data Store Read1'

  if (px4CtrlQGCGPS_DW.attitude_flag) {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 = px4CtrlQGCGPS_DW.yaw;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1 =
      px4CtrlQGCGPS_P.Constant3_Value_g;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 = px4CtrlQGCGPS_DW.yaw_speed;
  } else {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 =
      px4CtrlQGCGPS_P.Constant1_Value_a;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1 =
      px4CtrlQGCGPS_P.Constant1_Value_a;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 =
      px4CtrlQGCGPS_P.Constant1_Value_a;
  }

  // End of Switch: '<S13>/Switch'

  // RelationalOperator: '<S38>/Compare' incorporates:
  //   Abs: '<S37>/Abs'
  //   Constant: '<S38>/Constant'
  //   DataStoreRead: '<S37>/Data Store Read1'

  rtb_Compare = (fabs(px4CtrlQGCGPS_DW.e_pitch_yaw) >=
                 px4CtrlQGCGPS_P.CompareToConstant1_const);

  // Sum: '<S37>/Add' incorporates:
  //   DataStoreRead: '<S37>/Data Store Read'
  //   DataStoreRead: '<S37>/Data Store Read3'
  //   Sum: '<S40>/Add'

  px4CtrlQGCGPS_B.Abs6 = px4CtrlQGCGPS_DW.t - px4CtrlQGCGPS_DW.start_time_yaw;

  // Fcn: '<S37>/Fcn' incorporates:
  //   Constant: '<S37>/T'
  //   Constant: '<S37>/ch'
  //   Sum: '<S37>/Add'

  px4CtrlQGCGPS_B.rtb_Fcn_c = px4CtrlQGCGPS_P.ch_Value /
    (px4CtrlQGCGPS_P.T_Value - px4CtrlQGCGPS_B.Abs6);

  // MATLAB Function: '<S37>/MATLAB Function' incorporates:
  //   Constant: '<S37>/t'
  //   DataStoreRead: '<S37>/Data Store Read'
  //   DataStoreRead: '<S37>/Data Store Read3'

  px4CtrlQGCGP_MATLABFunction(rtb_Compare, px4CtrlQGCGPS_DW.t,
    px4CtrlQGCGPS_DW.start_time_yaw, px4CtrlQGCGPS_B.rtb_Fcn_c,
    px4CtrlQGCGPS_P.t_Value, &px4CtrlQGCGPS_B.y);

  // Sum: '<S37>/Add1' incorporates:
  //   Constant: '<S37>/r'

  px4CtrlQGCGPS_B.z2 = px4CtrlQGCGPS_P.r_Value + px4CtrlQGCGPS_B.y;

  // Sum: '<S36>/Add' incorporates:
  //   Sum: '<S13>/Add2'

  px4CtrlQGCGPS_DW.e_pitch_yaw = px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 -
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1;

  // Gain: '<S36>/Gain4' incorporates:
  //   Constant: '<S13>/b'
  //   Product: '<S36>/Product'
  //   Sum: '<S36>/Add'

  px4CtrlQGCGPS_B.ManualSwitch_g = px4CtrlQGCGPS_DW.e_pitch_yaw *
    px4CtrlQGCGPS_B.z2 * px4CtrlQGCGPS_P.b_Value * px4CtrlQGCGPS_P.Gain4_Gain;

  // SampleTimeMath: '<S35>/TSamp'
  //
  //  About '<S35>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4CtrlQGCGPS_B.TSamp = px4CtrlQGCGPS_B.ManualSwitch_g *
    px4CtrlQGCGPS_P.TSamp_WtEt;

  // Sum: '<S13>/Add1'
  px4CtrlQGCGPS_B.ManualSwitch_g = px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2
    - px4CtrlQGCGPS_B.ManualSwitch_g;

  // Gain: '<S1>/Gain1' incorporates:
  //   DiscreteIntegrator: '<S16>/Discrete-Time Integrator3'

  px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_P.Gain1_Gain_o *
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator3_DSTATE;

  // Signum: '<S13>/Sign'
  if (rtIsNaN(px4CtrlQGCGPS_B.ManualSwitch_g)) {
    px4CtrlQGCGPS_B.fcn5 = px4CtrlQGCGPS_B.ManualSwitch_g;
  } else if (px4CtrlQGCGPS_B.ManualSwitch_g < 0.0) {
    px4CtrlQGCGPS_B.fcn5 = -1.0;
  } else {
    px4CtrlQGCGPS_B.fcn5 = (px4CtrlQGCGPS_B.ManualSwitch_g > 0.0);
  }

  // End of Signum: '<S13>/Sign'

  // Saturate: '<S1>/Saturation4'
  if (px4CtrlQGCGPS_B.Product6_a > px4CtrlQGCGPS_P.Saturation4_UpperSat) {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_P.Saturation4_UpperSat;
  } else if (px4CtrlQGCGPS_B.Product6_a < px4CtrlQGCGPS_P.Saturation4_LowerSat)
  {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_P.Saturation4_LowerSat;
  }

  // End of Saturate: '<S1>/Saturation4'

  // Sum: '<S1>/Add3' incorporates:
  //   Constant: '<S13>/b'
  //   Constant: '<S13>/l'
  //   DataStoreWrite: '<S13>/Data Store Write'
  //   Gain: '<S13>/Gain'
  //   Gain: '<S13>/Gain1'
  //   Product: '<S13>/Product'
  //   Product: '<S13>/Product1'
  //   Sum: '<S13>/Add'
  //   Sum: '<S35>/Diff'
  //   UnitDelay: '<S35>/UD'
  //
  //  Block description for '<S35>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S35>/UD':
  //
  //   Store in Global RAM

  px4CtrlQGCGPS_B.Add3 = (((((px4CtrlQGCGPS_B.TSamp - px4CtrlQGCGPS_DW.UD_DSTATE)
    - px4CtrlQGCGPS_DW.e_pitch_yaw) - px4CtrlQGCGPS_B.ManualSwitch_g *
    px4CtrlQGCGPS_B.z2 * px4CtrlQGCGPS_P.b_Value) - px4CtrlQGCGPS_B.fcn5 *
    px4CtrlQGCGPS_P.l_Value) - px4CtrlQGCGPS_P.Gain_Gain *
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2) * px4CtrlQGCGPS_P.Gain1_Gain
    - px4CtrlQGCGPS_B.Product6_a;

  // ManualSwitch: '<S1>/Manual Switch' incorporates:
  //   Constant: '<S1>/Constant'
  //   DataStoreWrite: '<Root>/Data Store Write11'

  if (px4CtrlQGCGPS_P.ManualSwitch_CurrentSetting == 1) {
    // Saturate: '<S1>/Saturation'
    if (px4CtrlQGCGPS_B.Add3 > px4CtrlQGCGPS_P.Saturation_UpperSat) {
      px4CtrlQGCGPS_B.DataStoreRead27 = px4CtrlQGCGPS_P.Saturation_UpperSat;
    } else if (px4CtrlQGCGPS_B.Add3 < px4CtrlQGCGPS_P.Saturation_LowerSat) {
      px4CtrlQGCGPS_B.DataStoreRead27 = px4CtrlQGCGPS_P.Saturation_LowerSat;
    } else {
      px4CtrlQGCGPS_B.DataStoreRead27 = px4CtrlQGCGPS_B.Add3;
    }

    // End of Saturate: '<S1>/Saturation'
  } else {
    px4CtrlQGCGPS_B.DataStoreRead27 = px4CtrlQGCGPS_P.Constant_Value_b;
  }

  // End of ManualSwitch: '<S1>/Manual Switch'

  // Sin: '<Root>/Sine Wave'
  if (px4CtrlQGCGPS_DW.systemEnable != 0) {
    px4CtrlQGCGPS_B.z2 = px4CtrlQGCGPS_P.SineWave_Freq *
      px4CtrlQGCGPS_M->Timing.taskTime0;
    px4CtrlQGCGPS_DW.lastSin = sin(px4CtrlQGCGPS_B.z2);
    px4CtrlQGCGPS_DW.lastCos = cos(px4CtrlQGCGPS_B.z2);
    px4CtrlQGCGPS_DW.systemEnable = 0;
  }

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Constant: '<Root>/Constant3'
  //   Sin: '<Root>/Sine Wave'

  if (px4CtrlQGCGPS_P.ManualSwitch_CurrentSetting_i == 1) {
    px4CtrlQGCGPS_B.ManualSwitch_g = ((px4CtrlQGCGPS_DW.lastSin *
      px4CtrlQGCGPS_P.SineWave_PCos + px4CtrlQGCGPS_DW.lastCos *
      px4CtrlQGCGPS_P.SineWave_PSin) * px4CtrlQGCGPS_P.SineWave_HCos +
      (px4CtrlQGCGPS_DW.lastCos * px4CtrlQGCGPS_P.SineWave_PCos -
       px4CtrlQGCGPS_DW.lastSin * px4CtrlQGCGPS_P.SineWave_PSin) *
      px4CtrlQGCGPS_P.SineWave_Hsin) * px4CtrlQGCGPS_P.SineWave_Amp +
      px4CtrlQGCGPS_P.SineWave_Bias;
  } else {
    px4CtrlQGCGPS_B.ManualSwitch_g = px4CtrlQGCGPS_P.Constant3_Value_g;
  }

  // End of ManualSwitch: '<Root>/Manual Switch'

  // Switch: '<S11>/Switch' incorporates:
  //   Constant: '<S11>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read14'
  //   DataStoreRead: '<S11>/Data Store Read'
  //   DataStoreRead: '<S11>/Data Store Read1'

  if (px4CtrlQGCGPS_DW.attitude_flag) {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 = px4CtrlQGCGPS_DW.pitch;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1 =
      px4CtrlQGCGPS_B.ManualSwitch_g;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 = px4CtrlQGCGPS_DW.pitch_speed;
  } else {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 =
      px4CtrlQGCGPS_P.Constant1_Value;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1 =
      px4CtrlQGCGPS_P.Constant1_Value;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 =
      px4CtrlQGCGPS_P.Constant1_Value;
  }

  // End of Switch: '<S11>/Switch'

  // RelationalOperator: '<S20>/Compare' incorporates:
  //   Abs: '<S19>/Abs'
  //   Constant: '<S20>/Constant'
  //   DataStoreRead: '<S19>/Data Store Read1'

  rtb_Compare_i = (fabs(px4CtrlQGCGPS_DW.e_pitch) >=
                   px4CtrlQGCGPS_P.CompareToConstant1_const_b);

  // Sum: '<S19>/Add' incorporates:
  //   DataStoreRead: '<S19>/Data Store Read'
  //   DataStoreRead: '<S19>/Data Store Read3'
  //   Sum: '<S22>/Add'

  px4CtrlQGCGPS_B.Product4 = px4CtrlQGCGPS_DW.t - px4CtrlQGCGPS_DW.start_time;

  // Fcn: '<S19>/Fcn' incorporates:
  //   Constant: '<S19>/T'
  //   Constant: '<S19>/ch'
  //   Sum: '<S19>/Add'

  px4CtrlQGCGPS_B.rtb_Fcn_b_k = px4CtrlQGCGPS_P.ch_Value_j /
    (px4CtrlQGCGPS_P.T_Value_p - px4CtrlQGCGPS_B.Product4);

  // MATLAB Function: '<S19>/MATLAB Function' incorporates:
  //   Constant: '<S19>/t'
  //   DataStoreRead: '<S19>/Data Store Read'
  //   DataStoreRead: '<S19>/Data Store Read3'

  px4CtrlQGCGP_MATLABFunction(rtb_Compare_i, px4CtrlQGCGPS_DW.t,
    px4CtrlQGCGPS_DW.start_time, px4CtrlQGCGPS_B.rtb_Fcn_b_k,
    px4CtrlQGCGPS_P.t_Value_n, &px4CtrlQGCGPS_B.y_j);

  // Sum: '<S19>/Add1' incorporates:
  //   Constant: '<S19>/r'

  px4CtrlQGCGPS_B.z2_e = px4CtrlQGCGPS_P.r_Value_g + px4CtrlQGCGPS_B.y_j;

  // Sum: '<S18>/Add' incorporates:
  //   Sum: '<S11>/Add2'

  px4CtrlQGCGPS_DW.e_pitch = px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 -
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1;

  // Gain: '<S18>/Gain4' incorporates:
  //   Constant: '<S11>/b'
  //   Product: '<S18>/Product'
  //   Sum: '<S18>/Add'

  px4CtrlQGCGPS_B.roll_hat = px4CtrlQGCGPS_DW.e_pitch * px4CtrlQGCGPS_B.z2_e *
    px4CtrlQGCGPS_P.b_Value_l * px4CtrlQGCGPS_P.Gain4_Gain_b;

  // SampleTimeMath: '<S17>/TSamp'
  //
  //  About '<S17>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4CtrlQGCGPS_B.z2 = px4CtrlQGCGPS_B.roll_hat * px4CtrlQGCGPS_P.TSamp_WtEt_p;

  // Sum: '<S11>/Add1'
  px4CtrlQGCGPS_B.roll_hat = px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 -
    px4CtrlQGCGPS_B.roll_hat;

  // Gain: '<S1>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S14>/Discrete-Time Integrator3'

  px4CtrlQGCGPS_B.Gain2 = px4CtrlQGCGPS_P.Gain2_Gain *
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator3_DSTAT_a;

  // Signum: '<S11>/Sign'
  if (rtIsNaN(px4CtrlQGCGPS_B.roll_hat)) {
    px4CtrlQGCGPS_B.fcn5 = px4CtrlQGCGPS_B.roll_hat;
  } else if (px4CtrlQGCGPS_B.roll_hat < 0.0) {
    px4CtrlQGCGPS_B.fcn5 = -1.0;
  } else {
    px4CtrlQGCGPS_B.fcn5 = (px4CtrlQGCGPS_B.roll_hat > 0.0);
  }

  // End of Signum: '<S11>/Sign'

  // Sum: '<S1>/Add2' incorporates:
  //   Constant: '<S11>/b'
  //   Constant: '<S11>/l'
  //   DataStoreWrite: '<Root>/Data Store Write12'
  //   DataStoreWrite: '<S11>/Data Store Write'
  //   Gain: '<S11>/Gain'
  //   Gain: '<S11>/Gain1'
  //   Product: '<S11>/Product'
  //   Product: '<S11>/Product1'
  //   Sum: '<S11>/Add'
  //   Sum: '<S17>/Diff'
  //   UnitDelay: '<S17>/UD'
  //
  //  Block description for '<S17>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S17>/UD':
  //
  //   Store in Global RAM

  px4CtrlQGCGPS_B.DataStoreRead25 = (((((px4CtrlQGCGPS_B.z2 -
    px4CtrlQGCGPS_DW.UD_DSTATE_b) - px4CtrlQGCGPS_DW.e_pitch) -
    px4CtrlQGCGPS_B.roll_hat * px4CtrlQGCGPS_B.z2_e * px4CtrlQGCGPS_P.b_Value_l)
    - px4CtrlQGCGPS_B.fcn5 * px4CtrlQGCGPS_P.l_Value_b) -
    px4CtrlQGCGPS_P.Gain_Gain_o * px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2)
    * px4CtrlQGCGPS_P.Gain1_Gain_b - px4CtrlQGCGPS_B.Gain2;

  // Switch: '<S12>/Switch' incorporates:
  //   Constant: '<S12>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read18'
  //   DataStoreRead: '<S12>/Data Store Read'
  //   DataStoreRead: '<S12>/Data Store Read1'

  if (px4CtrlQGCGPS_DW.attitude_flag) {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 = px4CtrlQGCGPS_DW.roll;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1 =
      px4CtrlQGCGPS_B.ManualSwitch_g;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 = px4CtrlQGCGPS_DW.roll_speed;
  } else {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 =
      px4CtrlQGCGPS_P.Constant1_Value_n;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1 =
      px4CtrlQGCGPS_P.Constant1_Value_n;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 =
      px4CtrlQGCGPS_P.Constant1_Value_n;
  }

  // End of Switch: '<S12>/Switch'

  // RelationalOperator: '<S29>/Compare' incorporates:
  //   Abs: '<S28>/Abs'
  //   Constant: '<S29>/Constant'
  //   DataStoreRead: '<S28>/Data Store Read1'

  rtb_Compare_g2 = (fabs(px4CtrlQGCGPS_DW.e_pitch_roll) >=
                    px4CtrlQGCGPS_P.CompareToConstant1_const_h);

  // Sum: '<S28>/Add' incorporates:
  //   DataStoreRead: '<S28>/Data Store Read'
  //   DataStoreRead: '<S28>/Data Store Read3'
  //   Sum: '<S31>/Add'

  px4CtrlQGCGPS_B.Product6 = px4CtrlQGCGPS_DW.t -
    px4CtrlQGCGPS_DW.start_time_roll;

  // Fcn: '<S28>/Fcn' incorporates:
  //   Constant: '<S28>/T'
  //   Constant: '<S28>/ch'
  //   Sum: '<S28>/Add'

  px4CtrlQGCGPS_B.rtb_Fcn_a_c = px4CtrlQGCGPS_P.ch_Value_e /
    (px4CtrlQGCGPS_P.T_Value_c - px4CtrlQGCGPS_B.Product6);

  // MATLAB Function: '<S28>/MATLAB Function' incorporates:
  //   Constant: '<S28>/t'
  //   DataStoreRead: '<S28>/Data Store Read'
  //   DataStoreRead: '<S28>/Data Store Read3'

  px4CtrlQGCGP_MATLABFunction(rtb_Compare_g2, px4CtrlQGCGPS_DW.t,
    px4CtrlQGCGPS_DW.start_time_roll, px4CtrlQGCGPS_B.rtb_Fcn_a_c,
    px4CtrlQGCGPS_P.t_Value_m, &px4CtrlQGCGPS_B.y_o);

  // Sum: '<S28>/Add1' incorporates:
  //   Constant: '<S28>/r'

  px4CtrlQGCGPS_B.z2_l = px4CtrlQGCGPS_P.r_Value_p + px4CtrlQGCGPS_B.y_o;

  // Sum: '<S27>/Add' incorporates:
  //   Sum: '<S12>/Add2'

  px4CtrlQGCGPS_DW.e_pitch_roll = px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0
    - px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1;

  // Gain: '<S27>/Gain4' incorporates:
  //   Constant: '<S12>/b'
  //   Product: '<S27>/Product'
  //   Sum: '<S27>/Add'

  px4CtrlQGCGPS_B.roll_hat = px4CtrlQGCGPS_DW.e_pitch_roll *
    px4CtrlQGCGPS_B.z2_l * px4CtrlQGCGPS_P.b_Value_h *
    px4CtrlQGCGPS_P.Gain4_Gain_o;

  // SampleTimeMath: '<S26>/TSamp'
  //
  //  About '<S26>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4CtrlQGCGPS_B.z2_e = px4CtrlQGCGPS_B.roll_hat * px4CtrlQGCGPS_P.TSamp_WtEt_o;

  // Sum: '<S12>/Add1'
  px4CtrlQGCGPS_B.roll_hat = px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 -
    px4CtrlQGCGPS_B.roll_hat;

  // Gain: '<S1>/J' incorporates:
  //   DiscreteIntegrator: '<S15>/Discrete-Time Integrator3'

  px4CtrlQGCGPS_B.J = px4CtrlQGCGPS_P.J_Gain_b *
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator3_DSTAT_m;

  // Signum: '<S12>/Sign'
  if (rtIsNaN(px4CtrlQGCGPS_B.roll_hat)) {
    px4CtrlQGCGPS_B.fcn5 = px4CtrlQGCGPS_B.roll_hat;
  } else if (px4CtrlQGCGPS_B.roll_hat < 0.0) {
    px4CtrlQGCGPS_B.fcn5 = -1.0;
  } else {
    px4CtrlQGCGPS_B.fcn5 = (px4CtrlQGCGPS_B.roll_hat > 0.0);
  }

  // End of Signum: '<S12>/Sign'

  // Sum: '<S1>/Add1' incorporates:
  //   Constant: '<S12>/b'
  //   Constant: '<S12>/l'
  //   DataStoreWrite: '<Root>/Data Store Write13'
  //   DataStoreWrite: '<S12>/Data Store Write'
  //   Gain: '<S12>/Gain'
  //   Gain: '<S12>/J'
  //   Product: '<S12>/Product'
  //   Product: '<S12>/Product1'
  //   Sum: '<S12>/Add'
  //   Sum: '<S26>/Diff'
  //   UnitDelay: '<S26>/UD'
  //
  //  Block description for '<S26>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S26>/UD':
  //
  //   Store in Global RAM

  px4CtrlQGCGPS_B.DataStoreRead26 = (((((px4CtrlQGCGPS_B.z2_e -
    px4CtrlQGCGPS_DW.UD_DSTATE_n) - px4CtrlQGCGPS_DW.e_pitch_roll) -
    px4CtrlQGCGPS_B.roll_hat * px4CtrlQGCGPS_B.z2_l * px4CtrlQGCGPS_P.b_Value_h)
    - px4CtrlQGCGPS_B.fcn5 * px4CtrlQGCGPS_P.l_Value_n) -
    px4CtrlQGCGPS_P.Gain_Gain_m * px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2)
    * px4CtrlQGCGPS_P.J_Gain - px4CtrlQGCGPS_B.J;

  // DataStoreRead: '<S37>/Data Store Read4'
  px4CtrlQGCGPS_B.DataStoreRead4 = px4CtrlQGCGPS_DW.start_time_yaw;

  // Logic: '<S40>/Logical Operator' incorporates:
  //   Abs: '<S40>/Abs1'
  //   Constant: '<S41>/Constant'
  //   Constant: '<S42>/Constant'
  //   DataStoreRead: '<S40>/Data Store Read2'
  //   RelationalOperator: '<S41>/Compare'
  //   RelationalOperator: '<S42>/Compare'

  rtb_LogicalOperator = ((fabs(px4CtrlQGCGPS_DW.e_pitch_yaw) >=
    px4CtrlQGCGPS_P.CompareToConstant2_const) && (px4CtrlQGCGPS_B.Abs6 >=
    px4CtrlQGCGPS_P.CompareToConstant1_const_hq));

  // Outputs for Triggered SubSystem: '<S40>/Subsystem' incorporates:
  //   TriggerPort: '<S43>/Trigger'

  if (rtb_LogicalOperator && (px4CtrlQGCGPS_PrevZCX.Subsystem_Trig_ZCE !=
       POS_ZCSIG)) {
    // DataStoreWrite: '<S43>/Data Store Write' incorporates:
    //   DataStoreRead: '<S43>/Data Store Read2'

    px4CtrlQGCGPS_DW.start_time_yaw = px4CtrlQGCGPS_DW.t;
    px4CtrlQGCGPS_DW.Subsystem_SubsysRanBC = 4;
  }

  px4CtrlQGCGPS_PrevZCX.Subsystem_Trig_ZCE = rtb_LogicalOperator;

  // End of Outputs for SubSystem: '<S40>/Subsystem'
  // DataStoreRead: '<S19>/Data Store Read4'
  px4CtrlQGCGPS_B.DataStoreRead4_g = px4CtrlQGCGPS_DW.start_time;

  // Logic: '<S22>/Logical Operator' incorporates:
  //   Abs: '<S22>/Abs1'
  //   Constant: '<S23>/Constant'
  //   Constant: '<S24>/Constant'
  //   DataStoreRead: '<S22>/Data Store Read2'
  //   RelationalOperator: '<S23>/Compare'
  //   RelationalOperator: '<S24>/Compare'

  rtb_LogicalOperator = ((fabs(px4CtrlQGCGPS_DW.e_pitch) >=
    px4CtrlQGCGPS_P.CompareToConstant2_const_o) && (px4CtrlQGCGPS_B.Product4 >=
    px4CtrlQGCGPS_P.CompareToConstant1_const_p));

  // Outputs for Triggered SubSystem: '<S22>/Subsystem' incorporates:
  //   TriggerPort: '<S25>/Trigger'

  if (rtb_LogicalOperator && (px4CtrlQGCGPS_PrevZCX.Subsystem_Trig_ZCE_e !=
       POS_ZCSIG)) {
    // DataStoreWrite: '<S25>/Data Store Write' incorporates:
    //   DataStoreRead: '<S25>/Data Store Read2'

    px4CtrlQGCGPS_DW.start_time = px4CtrlQGCGPS_DW.t;
    px4CtrlQGCGPS_DW.Subsystem_SubsysRanBC_k = 4;
  }

  px4CtrlQGCGPS_PrevZCX.Subsystem_Trig_ZCE_e = rtb_LogicalOperator;

  // End of Outputs for SubSystem: '<S22>/Subsystem'
  // DataStoreRead: '<S28>/Data Store Read4'
  px4CtrlQGCGPS_B.DataStoreRead4_b = px4CtrlQGCGPS_DW.start_time_roll;

  // Logic: '<S31>/Logical Operator' incorporates:
  //   Abs: '<S31>/Abs1'
  //   Constant: '<S32>/Constant'
  //   Constant: '<S33>/Constant'
  //   DataStoreRead: '<S31>/Data Store Read2'
  //   RelationalOperator: '<S32>/Compare'
  //   RelationalOperator: '<S33>/Compare'

  rtb_LogicalOperator = ((fabs(px4CtrlQGCGPS_DW.e_pitch_roll) >=
    px4CtrlQGCGPS_P.CompareToConstant2_const_a) && (px4CtrlQGCGPS_B.Product6 >=
    px4CtrlQGCGPS_P.CompareToConstant1_const_a));

  // Outputs for Triggered SubSystem: '<S31>/Subsystem' incorporates:
  //   TriggerPort: '<S34>/Trigger'

  if (rtb_LogicalOperator && (px4CtrlQGCGPS_PrevZCX.Subsystem_Trig_ZCE_j !=
       POS_ZCSIG)) {
    // DataStoreWrite: '<S34>/Data Store Write' incorporates:
    //   DataStoreRead: '<S34>/Data Store Read2'

    px4CtrlQGCGPS_DW.start_time_roll = px4CtrlQGCGPS_DW.t;
    px4CtrlQGCGPS_DW.Subsystem_SubsysRanBC_m = 4;
  }

  px4CtrlQGCGPS_PrevZCX.Subsystem_Trig_ZCE_j = rtb_LogicalOperator;

  // End of Outputs for SubSystem: '<S31>/Subsystem'

  // Gain: '<S16>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S16>/Discrete-Time Integrator'

  px4CtrlQGCGPS_B.rolldegree = px4CtrlQGCGPS_P.Gain2_Gain_c *
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator_DSTATE;

  // Switch: '<S16>/Switch' incorporates:
  //   Constant: '<S16>/Constant3'
  //   DataStoreRead: '<S16>/Data Store Read'
  //   DataStoreRead: '<S16>/Data Store Read1'
  //   DataStoreRead: '<S16>/Data Store Read2'
  //   Gain: '<S16>/1//J'
  //   Gain: '<S16>/k//J'
  //   ZeroOrderHold: '<S16>/Zero-Order Hold1'

  if (px4CtrlQGCGPS_DW.observer_flag) {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 = px4CtrlQGCGPS_P.uJ_Gain *
      px4CtrlQGCGPS_B.Add3;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1 = px4CtrlQGCGPS_P.kJ_Gain *
      px4CtrlQGCGPS_DW.yaw_speed;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 = px4CtrlQGCGPS_DW.yaw;
  } else {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 =
      px4CtrlQGCGPS_P.Constant3_Value_d;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1 =
      px4CtrlQGCGPS_P.Constant3_Value_d;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 =
      px4CtrlQGCGPS_P.Constant3_Value_d;
  }

  // End of Switch: '<S16>/Switch'

  // Sum: '<S16>/Add1' incorporates:
  //   DiscreteIntegrator: '<S16>/Discrete-Time Integrator'

  px4CtrlQGCGPS_B.Abs6 = px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 -
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator_DSTATE;

  // Abs: '<S16>/Abs3' incorporates:
  //   Abs: '<S16>/Abs4'
  //   Abs: '<S16>/Abs5'
  //   Abs: '<S16>/Abs6'

  px4CtrlQGCGPS_B.z2_l = fabs(px4CtrlQGCGPS_B.Abs6);

  // Sum: '<S16>/Add7' incorporates:
  //   Constant: '<S16>/Constant1'
  //   Sum: '<S16>/Add13'
  //   Sum: '<S16>/Add18'

  px4CtrlQGCGPS_B.lambda4_h = px4CtrlQGCGPS_P.Constant1_Value_f +
    px4CtrlQGCGPS_B.Abs6;

  // Sum: '<S16>/Add6' incorporates:
  //   Constant: '<S16>/Constant1'
  //   Sum: '<S16>/Add12'
  //   Sum: '<S16>/Add17'

  u0_tmp = px4CtrlQGCGPS_B.Abs6 - px4CtrlQGCGPS_P.Constant1_Value_f;

  // Saturate: '<S16>/Saturation10' incorporates:
  //   Sum: '<S16>/Add7'

  if (px4CtrlQGCGPS_B.lambda4_h > px4CtrlQGCGPS_P.Saturation10_UpperSat) {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_P.Saturation10_UpperSat;
  } else if (px4CtrlQGCGPS_B.lambda4_h < px4CtrlQGCGPS_P.Saturation10_LowerSat)
  {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_P.Saturation10_LowerSat;
  } else {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_B.lambda4_h;
  }

  // End of Saturate: '<S16>/Saturation10'

  // Saturate: '<S16>/Saturation11' incorporates:
  //   Sum: '<S16>/Add6'

  if (u0_tmp > px4CtrlQGCGPS_P.Saturation11_UpperSat) {
    px4CtrlQGCGPS_B.Product5_l = px4CtrlQGCGPS_P.Saturation11_UpperSat;
  } else if (u0_tmp < px4CtrlQGCGPS_P.Saturation11_LowerSat) {
    px4CtrlQGCGPS_B.Product5_l = px4CtrlQGCGPS_P.Saturation11_LowerSat;
  } else {
    px4CtrlQGCGPS_B.Product5_l = u0_tmp;
  }

  // End of Saturate: '<S16>/Saturation11'

  // Gain: '<S16>/Gain' incorporates:
  //   Sum: '<S16>/Add8'

  px4CtrlQGCGPS_B.roll_hat_e = (px4CtrlQGCGPS_B.Product6_a -
    px4CtrlQGCGPS_B.Product5_l) * px4CtrlQGCGPS_P.Gain_Gain_ml;

  // Fcn: '<S16>/Fcn3' incorporates:
  //   Constant: '<S16>/Constant1'

  if (px4CtrlQGCGPS_P.Constant1_Value_f < 0.0) {
    px4CtrlQGCGPS_B.fcn5 = -rt_powd_snf(-px4CtrlQGCGPS_P.Constant1_Value_f, -0.5);
  } else {
    px4CtrlQGCGPS_B.fcn5 = rt_powd_snf(px4CtrlQGCGPS_P.Constant1_Value_f, -0.5);
  }

  // End of Fcn: '<S16>/Fcn3'

  // Product: '<S16>/Product3'
  px4CtrlQGCGPS_B.Add3 = px4CtrlQGCGPS_B.fcn5 * px4CtrlQGCGPS_B.roll_hat_e *
    px4CtrlQGCGPS_B.Abs6;

  // Saturate: '<S16>/Saturation8'
  if (px4CtrlQGCGPS_B.Abs6 > px4CtrlQGCGPS_P.Saturation8_UpperSat) {
    px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_P.Saturation8_UpperSat;
  } else if (px4CtrlQGCGPS_B.Abs6 < px4CtrlQGCGPS_P.Saturation8_LowerSat) {
    px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_P.Saturation8_LowerSat;
  } else {
    px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_B.Abs6;
  }

  // End of Saturate: '<S16>/Saturation8'

  // Product: '<S16>/Product4' incorporates:
  //   Abs: '<S16>/Abs3'
  //   Constant: '<S16>/Constant2'
  //   Fcn: '<S16>/Fcn4'
  //   Sum: '<S16>/Add10'

  px4CtrlQGCGPS_B.Product4 = rt_powd_snf(px4CtrlQGCGPS_B.z2_l, 0.5) *
    px4CtrlQGCGPS_B.Product2_d * (px4CtrlQGCGPS_P.Constant2_Value -
    px4CtrlQGCGPS_B.roll_hat_e);

  // Saturate: '<S16>/Saturation13'
  if (px4CtrlQGCGPS_B.lambda4_h > px4CtrlQGCGPS_P.Saturation13_UpperSat) {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_P.Saturation13_UpperSat;
  } else if (px4CtrlQGCGPS_B.lambda4_h < px4CtrlQGCGPS_P.Saturation13_LowerSat)
  {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_P.Saturation13_LowerSat;
  } else {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_B.lambda4_h;
  }

  // End of Saturate: '<S16>/Saturation13'

  // Saturate: '<S16>/Saturation9'
  if (u0_tmp > px4CtrlQGCGPS_P.Saturation9_UpperSat) {
    px4CtrlQGCGPS_B.Product5_l = px4CtrlQGCGPS_P.Saturation9_UpperSat;
  } else if (u0_tmp < px4CtrlQGCGPS_P.Saturation9_LowerSat) {
    px4CtrlQGCGPS_B.Product5_l = px4CtrlQGCGPS_P.Saturation9_LowerSat;
  } else {
    px4CtrlQGCGPS_B.Product5_l = u0_tmp;
  }

  // End of Saturate: '<S16>/Saturation9'

  // Gain: '<S16>/Gain1' incorporates:
  //   Sum: '<S16>/Add14'

  px4CtrlQGCGPS_B.roll_hat_e = (px4CtrlQGCGPS_B.Product6_a -
    px4CtrlQGCGPS_B.Product5_l) * px4CtrlQGCGPS_P.Gain1_Gain_a;

  // Fcn: '<S16>/Fcn6' incorporates:
  //   Constant: '<S16>/Constant1'

  if (px4CtrlQGCGPS_P.Constant1_Value_f < 0.0) {
    px4CtrlQGCGPS_B.fcn5 = -rt_powd_snf(-px4CtrlQGCGPS_P.Constant1_Value_f,
      -0.9375);
  } else {
    px4CtrlQGCGPS_B.fcn5 = rt_powd_snf(px4CtrlQGCGPS_P.Constant1_Value_f,
      -0.9375);
  }

  // End of Fcn: '<S16>/Fcn6'

  // Product: '<S16>/Product6'
  px4CtrlQGCGPS_B.Product6 = px4CtrlQGCGPS_B.fcn5 * px4CtrlQGCGPS_B.roll_hat_e *
    px4CtrlQGCGPS_B.Abs6;

  // Saturate: '<S16>/Saturation12'
  if (px4CtrlQGCGPS_B.Abs6 > px4CtrlQGCGPS_P.Saturation12_UpperSat) {
    px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_P.Saturation12_UpperSat;
  } else if (px4CtrlQGCGPS_B.Abs6 < px4CtrlQGCGPS_P.Saturation12_LowerSat) {
    px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_P.Saturation12_LowerSat;
  } else {
    px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_B.Abs6;
  }

  // End of Saturate: '<S16>/Saturation12'

  // Product: '<S16>/Product5' incorporates:
  //   Constant: '<S16>/Constant4'
  //   Fcn: '<S16>/Fcn5'
  //   Sum: '<S16>/Add11'

  px4CtrlQGCGPS_B.roll_hat = rt_powd_snf(px4CtrlQGCGPS_B.z2_l, 0.0625) *
    px4CtrlQGCGPS_B.Product2_d * (px4CtrlQGCGPS_P.Constant4_Value -
    px4CtrlQGCGPS_B.roll_hat_e);

  // Saturate: '<S16>/Saturation16'
  if (px4CtrlQGCGPS_B.lambda4_h > px4CtrlQGCGPS_P.Saturation16_UpperSat) {
    px4CtrlQGCGPS_B.lambda4_h = px4CtrlQGCGPS_P.Saturation16_UpperSat;
  } else if (px4CtrlQGCGPS_B.lambda4_h < px4CtrlQGCGPS_P.Saturation16_LowerSat)
  {
    px4CtrlQGCGPS_B.lambda4_h = px4CtrlQGCGPS_P.Saturation16_LowerSat;
  }

  // End of Saturate: '<S16>/Saturation16'

  // Saturate: '<S16>/Saturation14'
  if (u0_tmp > px4CtrlQGCGPS_P.Saturation14_UpperSat) {
    u0_tmp = px4CtrlQGCGPS_P.Saturation14_UpperSat;
  } else if (u0_tmp < px4CtrlQGCGPS_P.Saturation14_LowerSat) {
    u0_tmp = px4CtrlQGCGPS_P.Saturation14_LowerSat;
  }

  // End of Saturate: '<S16>/Saturation14'

  // Gain: '<S16>/Gain3' incorporates:
  //   Sum: '<S16>/Add19'

  px4CtrlQGCGPS_B.roll_hat_e = (px4CtrlQGCGPS_B.lambda4_h - u0_tmp) *
    px4CtrlQGCGPS_P.Gain3_Gain;

  // Saturate: '<S16>/Saturation1'
  if (px4CtrlQGCGPS_B.Abs6 > px4CtrlQGCGPS_P.Saturation1_UpperSat) {
    px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_P.Saturation1_UpperSat;
  } else if (px4CtrlQGCGPS_B.Abs6 < px4CtrlQGCGPS_P.Saturation1_LowerSat) {
    px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_P.Saturation1_LowerSat;
  } else {
    px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_B.Abs6;
  }

  // End of Saturate: '<S16>/Saturation1'

  // Fcn: '<S16>/Fcn7' incorporates:
  //   Constant: '<S16>/Constant1'

  if (px4CtrlQGCGPS_P.Constant1_Value_f < 0.0) {
    px4CtrlQGCGPS_B.fcn5 = -rt_powd_snf(-px4CtrlQGCGPS_P.Constant1_Value_f,
      -0.75);
  } else {
    px4CtrlQGCGPS_B.fcn5 = rt_powd_snf(px4CtrlQGCGPS_P.Constant1_Value_f, -0.75);
  }

  // End of Fcn: '<S16>/Fcn7'

  // Saturate: '<S16>/Saturation15'
  if (px4CtrlQGCGPS_B.Abs6 > px4CtrlQGCGPS_P.Saturation15_UpperSat) {
    px4CtrlQGCGPS_B.lambda1_a = px4CtrlQGCGPS_P.Saturation15_UpperSat;
  } else if (px4CtrlQGCGPS_B.Abs6 < px4CtrlQGCGPS_P.Saturation15_LowerSat) {
    px4CtrlQGCGPS_B.lambda1_a = px4CtrlQGCGPS_P.Saturation15_LowerSat;
  } else {
    px4CtrlQGCGPS_B.lambda1_a = px4CtrlQGCGPS_B.Abs6;
  }

  // End of Saturate: '<S16>/Saturation15'

  // Sum: '<S16>/Add2' incorporates:
  //   Constant: '<S16>/Constant6'
  //   DiscreteIntegrator: '<S16>/Discrete-Time Integrator3'
  //   Fcn: '<S16>/Fcn8'
  //   Gain: '<S16>/Gain6'
  //   Gain: '<S16>/l2'
  //   Gain: '<S16>/lambda2'
  //   Product: '<S16>/Product7'
  //   Product: '<S16>/Product8'
  //   Sum: '<S16>/Add16'
  //   Sum: '<S16>/Add20'
  //   Sum: '<S16>/Add3'

  px4CtrlQGCGPS_B.z2_l = (((px4CtrlQGCGPS_P.lambda2_Gain * px4CtrlQGCGPS_B.Abs6
    + px4CtrlQGCGPS_P.l2_Gain * px4CtrlQGCGPS_B.Product2_d) +
    (px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 -
     px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1)) +
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator3_DSTATE) + (px4CtrlQGCGPS_B.fcn5 *
    px4CtrlQGCGPS_B.roll_hat_e * px4CtrlQGCGPS_B.Abs6 + rt_powd_snf
    (px4CtrlQGCGPS_B.z2_l, 0.25) * px4CtrlQGCGPS_B.lambda1_a *
    (px4CtrlQGCGPS_P.Constant6_Value - px4CtrlQGCGPS_B.roll_hat_e)) *
    px4CtrlQGCGPS_P.Gain6_Gain;

  // Gain: '<S14>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S14>/Discrete-Time Integrator'

  px4CtrlQGCGPS_B.rolldegree_l = px4CtrlQGCGPS_P.Gain2_Gain_g *
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator_DSTATE_p;

  // Switch: '<S14>/Switch' incorporates:
  //   Constant: '<S14>/Constant3'
  //   DataStoreRead: '<S14>/Data Store Read'
  //   DataStoreRead: '<S14>/Data Store Read1'
  //   DataStoreRead: '<S14>/Data Store Read2'
  //   DataStoreWrite: '<Root>/Data Store Write12'
  //   Gain: '<S14>/1//J'
  //   Gain: '<S14>/k//J'
  //   ZeroOrderHold: '<S14>/Zero-Order Hold1'

  if (px4CtrlQGCGPS_DW.observer_flag) {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 = px4CtrlQGCGPS_P.uJ_Gain_p *
      px4CtrlQGCGPS_B.DataStoreRead25;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1 = px4CtrlQGCGPS_P.kJ_Gain_c *
      px4CtrlQGCGPS_DW.pitch_speed;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 = px4CtrlQGCGPS_DW.pitch;
  } else {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 =
      px4CtrlQGCGPS_P.Constant3_Value;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1 =
      px4CtrlQGCGPS_P.Constant3_Value;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 =
      px4CtrlQGCGPS_P.Constant3_Value;
  }

  // End of Switch: '<S14>/Switch'

  // Sum: '<S14>/Add1' incorporates:
  //   DiscreteIntegrator: '<S14>/Discrete-Time Integrator'

  px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 -
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator_DSTATE_p;

  // Abs: '<S14>/Abs3' incorporates:
  //   Abs: '<S14>/Abs4'
  //   Abs: '<S14>/Abs5'
  //   Abs: '<S14>/Abs6'

  px4CtrlQGCGPS_B.Add2_o = fabs(px4CtrlQGCGPS_B.Product2_d);

  // Saturate: '<S14>/Saturation'
  if (px4CtrlQGCGPS_B.Product2_d > px4CtrlQGCGPS_P.Saturation_UpperSat_n) {
    px4CtrlQGCGPS_B.roll_hat_e = px4CtrlQGCGPS_P.Saturation_UpperSat_n;
  } else if (px4CtrlQGCGPS_B.Product2_d < px4CtrlQGCGPS_P.Saturation_LowerSat_g)
  {
    px4CtrlQGCGPS_B.roll_hat_e = px4CtrlQGCGPS_P.Saturation_LowerSat_g;
  } else {
    px4CtrlQGCGPS_B.roll_hat_e = px4CtrlQGCGPS_B.Product2_d;
  }

  // End of Saturate: '<S14>/Saturation'

  // Gain: '<S14>/lambda1'
  px4CtrlQGCGPS_B.lambda1_a = px4CtrlQGCGPS_P.lambda1_Gain_a *
    px4CtrlQGCGPS_B.Product2_d;

  // Sum: '<S14>/Add7' incorporates:
  //   Constant: '<S14>/Constant1'
  //   Sum: '<S14>/Add13'
  //   Sum: '<S14>/Add18'

  px4CtrlQGCGPS_B.lambda4_h = px4CtrlQGCGPS_P.Constant1_Value_j +
    px4CtrlQGCGPS_B.Product2_d;

  // Sum: '<S14>/Add6' incorporates:
  //   Constant: '<S14>/Constant1'
  //   Sum: '<S14>/Add12'
  //   Sum: '<S14>/Add17'

  u0_tmp = px4CtrlQGCGPS_B.Product2_d - px4CtrlQGCGPS_P.Constant1_Value_j;

  // Saturate: '<S14>/Saturation10' incorporates:
  //   Sum: '<S14>/Add7'

  if (px4CtrlQGCGPS_B.lambda4_h > px4CtrlQGCGPS_P.Saturation10_UpperSat_o) {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_P.Saturation10_UpperSat_o;
  } else if (px4CtrlQGCGPS_B.lambda4_h < px4CtrlQGCGPS_P.Saturation10_LowerSat_b)
  {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_P.Saturation10_LowerSat_b;
  } else {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_B.lambda4_h;
  }

  // End of Saturate: '<S14>/Saturation10'

  // Saturate: '<S14>/Saturation11' incorporates:
  //   Sum: '<S14>/Add6'

  if (u0_tmp > px4CtrlQGCGPS_P.Saturation11_UpperSat_p) {
    px4CtrlQGCGPS_B.Product5_l = px4CtrlQGCGPS_P.Saturation11_UpperSat_p;
  } else if (u0_tmp < px4CtrlQGCGPS_P.Saturation11_LowerSat_i) {
    px4CtrlQGCGPS_B.Product5_l = px4CtrlQGCGPS_P.Saturation11_LowerSat_i;
  } else {
    px4CtrlQGCGPS_B.Product5_l = u0_tmp;
  }

  // End of Saturate: '<S14>/Saturation11'

  // Gain: '<S14>/Gain' incorporates:
  //   Sum: '<S14>/Add8'

  px4CtrlQGCGPS_B.roll_hat_k = (px4CtrlQGCGPS_B.Product6_a -
    px4CtrlQGCGPS_B.Product5_l) * px4CtrlQGCGPS_P.Gain_Gain_g;

  // Fcn: '<S14>/Fcn3' incorporates:
  //   Constant: '<S14>/Constant1'

  if (px4CtrlQGCGPS_P.Constant1_Value_j < 0.0) {
    px4CtrlQGCGPS_B.fcn5 = -rt_powd_snf(-px4CtrlQGCGPS_P.Constant1_Value_j, -0.5);
  } else {
    px4CtrlQGCGPS_B.fcn5 = rt_powd_snf(px4CtrlQGCGPS_P.Constant1_Value_j, -0.5);
  }

  // End of Fcn: '<S14>/Fcn3'

  // Product: '<S14>/Product3'
  px4CtrlQGCGPS_B.Product3_a = px4CtrlQGCGPS_B.fcn5 * px4CtrlQGCGPS_B.roll_hat_k
    * px4CtrlQGCGPS_B.Product2_d;

  // Saturate: '<S14>/Saturation8'
  if (px4CtrlQGCGPS_B.Product2_d > px4CtrlQGCGPS_P.Saturation8_UpperSat_g) {
    px4CtrlQGCGPS_B.lambda4_n = px4CtrlQGCGPS_P.Saturation8_UpperSat_g;
  } else if (px4CtrlQGCGPS_B.Product2_d < px4CtrlQGCGPS_P.Saturation8_LowerSat_g)
  {
    px4CtrlQGCGPS_B.lambda4_n = px4CtrlQGCGPS_P.Saturation8_LowerSat_g;
  } else {
    px4CtrlQGCGPS_B.lambda4_n = px4CtrlQGCGPS_B.Product2_d;
  }

  // End of Saturate: '<S14>/Saturation8'

  // Product: '<S14>/Product4' incorporates:
  //   Abs: '<S14>/Abs3'
  //   Constant: '<S14>/Constant2'
  //   Fcn: '<S14>/Fcn4'
  //   Sum: '<S14>/Add10'

  px4CtrlQGCGPS_B.Product4_k = rt_powd_snf(px4CtrlQGCGPS_B.Add2_o, 0.5) *
    px4CtrlQGCGPS_B.lambda4_n * (px4CtrlQGCGPS_P.Constant2_Value_h -
    px4CtrlQGCGPS_B.roll_hat_k);

  // Saturate: '<S14>/Saturation13'
  if (px4CtrlQGCGPS_B.lambda4_h > px4CtrlQGCGPS_P.Saturation13_UpperSat_i) {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_P.Saturation13_UpperSat_i;
  } else if (px4CtrlQGCGPS_B.lambda4_h < px4CtrlQGCGPS_P.Saturation13_LowerSat_c)
  {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_P.Saturation13_LowerSat_c;
  } else {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_B.lambda4_h;
  }

  // End of Saturate: '<S14>/Saturation13'

  // Saturate: '<S14>/Saturation9'
  if (u0_tmp > px4CtrlQGCGPS_P.Saturation9_UpperSat_i) {
    px4CtrlQGCGPS_B.Product5_l = px4CtrlQGCGPS_P.Saturation9_UpperSat_i;
  } else if (u0_tmp < px4CtrlQGCGPS_P.Saturation9_LowerSat_c) {
    px4CtrlQGCGPS_B.Product5_l = px4CtrlQGCGPS_P.Saturation9_LowerSat_c;
  } else {
    px4CtrlQGCGPS_B.Product5_l = u0_tmp;
  }

  // End of Saturate: '<S14>/Saturation9'

  // Gain: '<S14>/Gain1' incorporates:
  //   Sum: '<S14>/Add14'

  px4CtrlQGCGPS_B.roll_hat_k = (px4CtrlQGCGPS_B.Product6_a -
    px4CtrlQGCGPS_B.Product5_l) * px4CtrlQGCGPS_P.Gain1_Gain_d;

  // Fcn: '<S14>/Fcn6' incorporates:
  //   Constant: '<S14>/Constant1'

  if (px4CtrlQGCGPS_P.Constant1_Value_j < 0.0) {
    px4CtrlQGCGPS_B.fcn5 = -rt_powd_snf(-px4CtrlQGCGPS_P.Constant1_Value_j,
      -0.9375);
  } else {
    px4CtrlQGCGPS_B.fcn5 = rt_powd_snf(px4CtrlQGCGPS_P.Constant1_Value_j,
      -0.9375);
  }

  // End of Fcn: '<S14>/Fcn6'

  // Product: '<S14>/Product6'
  px4CtrlQGCGPS_B.Product6_i = px4CtrlQGCGPS_B.fcn5 * px4CtrlQGCGPS_B.roll_hat_k
    * px4CtrlQGCGPS_B.Product2_d;

  // Saturate: '<S14>/Saturation12'
  if (px4CtrlQGCGPS_B.Product2_d > px4CtrlQGCGPS_P.Saturation12_UpperSat_c) {
    px4CtrlQGCGPS_B.lambda4_n = px4CtrlQGCGPS_P.Saturation12_UpperSat_c;
  } else if (px4CtrlQGCGPS_B.Product2_d <
             px4CtrlQGCGPS_P.Saturation12_LowerSat_b) {
    px4CtrlQGCGPS_B.lambda4_n = px4CtrlQGCGPS_P.Saturation12_LowerSat_b;
  } else {
    px4CtrlQGCGPS_B.lambda4_n = px4CtrlQGCGPS_B.Product2_d;
  }

  // End of Saturate: '<S14>/Saturation12'

  // Product: '<S14>/Product5' incorporates:
  //   Constant: '<S14>/Constant4'
  //   Fcn: '<S14>/Fcn5'
  //   Sum: '<S14>/Add11'

  px4CtrlQGCGPS_B.Product5_b = rt_powd_snf(px4CtrlQGCGPS_B.Add2_o, 0.0625) *
    px4CtrlQGCGPS_B.lambda4_n * (px4CtrlQGCGPS_P.Constant4_Value_n -
    px4CtrlQGCGPS_B.roll_hat_k);

  // Saturate: '<S14>/Saturation16'
  if (px4CtrlQGCGPS_B.lambda4_h > px4CtrlQGCGPS_P.Saturation16_UpperSat_l) {
    px4CtrlQGCGPS_B.lambda4_h = px4CtrlQGCGPS_P.Saturation16_UpperSat_l;
  } else if (px4CtrlQGCGPS_B.lambda4_h < px4CtrlQGCGPS_P.Saturation16_LowerSat_g)
  {
    px4CtrlQGCGPS_B.lambda4_h = px4CtrlQGCGPS_P.Saturation16_LowerSat_g;
  }

  // End of Saturate: '<S14>/Saturation16'

  // Saturate: '<S14>/Saturation14'
  if (u0_tmp > px4CtrlQGCGPS_P.Saturation14_UpperSat_l) {
    u0_tmp = px4CtrlQGCGPS_P.Saturation14_UpperSat_l;
  } else if (u0_tmp < px4CtrlQGCGPS_P.Saturation14_LowerSat_b) {
    u0_tmp = px4CtrlQGCGPS_P.Saturation14_LowerSat_b;
  }

  // End of Saturate: '<S14>/Saturation14'

  // Gain: '<S14>/Gain3' incorporates:
  //   Sum: '<S14>/Add19'

  px4CtrlQGCGPS_B.roll_hat_k = (px4CtrlQGCGPS_B.lambda4_h - u0_tmp) *
    px4CtrlQGCGPS_P.Gain3_Gain_l;

  // Saturate: '<S14>/Saturation1'
  if (px4CtrlQGCGPS_B.Product2_d > px4CtrlQGCGPS_P.Saturation1_UpperSat_a) {
    px4CtrlQGCGPS_B.lambda4_n = px4CtrlQGCGPS_P.Saturation1_UpperSat_a;
  } else if (px4CtrlQGCGPS_B.Product2_d < px4CtrlQGCGPS_P.Saturation1_LowerSat_i)
  {
    px4CtrlQGCGPS_B.lambda4_n = px4CtrlQGCGPS_P.Saturation1_LowerSat_i;
  } else {
    px4CtrlQGCGPS_B.lambda4_n = px4CtrlQGCGPS_B.Product2_d;
  }

  // End of Saturate: '<S14>/Saturation1'

  // Fcn: '<S14>/Fcn7' incorporates:
  //   Constant: '<S14>/Constant1'

  if (px4CtrlQGCGPS_P.Constant1_Value_j < 0.0) {
    px4CtrlQGCGPS_B.fcn5 = -rt_powd_snf(-px4CtrlQGCGPS_P.Constant1_Value_j,
      -0.75);
  } else {
    px4CtrlQGCGPS_B.fcn5 = rt_powd_snf(px4CtrlQGCGPS_P.Constant1_Value_j, -0.75);
  }

  // End of Fcn: '<S14>/Fcn7'

  // Saturate: '<S14>/Saturation15'
  if (px4CtrlQGCGPS_B.Product2_d > px4CtrlQGCGPS_P.Saturation15_UpperSat_j) {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 =
      px4CtrlQGCGPS_P.Saturation15_UpperSat_j;
  } else if (px4CtrlQGCGPS_B.Product2_d <
             px4CtrlQGCGPS_P.Saturation15_LowerSat_k) {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 =
      px4CtrlQGCGPS_P.Saturation15_LowerSat_k;
  } else {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 = px4CtrlQGCGPS_B.Product2_d;
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

  px4CtrlQGCGPS_B.Add2_o = (((px4CtrlQGCGPS_P.lambda2_Gain_j *
    px4CtrlQGCGPS_B.Product2_d + px4CtrlQGCGPS_P.l2_Gain_l *
    px4CtrlQGCGPS_B.lambda4_n) + (px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0
    - px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1)) +
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator3_DSTAT_a) + (px4CtrlQGCGPS_B.fcn5 *
    px4CtrlQGCGPS_B.roll_hat_k * px4CtrlQGCGPS_B.Product2_d + rt_powd_snf
    (px4CtrlQGCGPS_B.Add2_o, 0.25) *
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 *
    (px4CtrlQGCGPS_P.Constant6_Value_o - px4CtrlQGCGPS_B.roll_hat_k)) *
    px4CtrlQGCGPS_P.Gain6_Gain_e;

  // Saturate: '<S14>/Saturation3'
  if (px4CtrlQGCGPS_B.Product2_d > px4CtrlQGCGPS_P.Saturation3_UpperSat_m) {
    px4CtrlQGCGPS_B.roll_hat_k = px4CtrlQGCGPS_P.Saturation3_UpperSat_m;
  } else if (px4CtrlQGCGPS_B.Product2_d < px4CtrlQGCGPS_P.Saturation3_LowerSat_i)
  {
    px4CtrlQGCGPS_B.roll_hat_k = px4CtrlQGCGPS_P.Saturation3_LowerSat_i;
  } else {
    px4CtrlQGCGPS_B.roll_hat_k = px4CtrlQGCGPS_B.Product2_d;
  }

  // End of Saturate: '<S14>/Saturation3'

  // Gain: '<S14>/lambda4'
  px4CtrlQGCGPS_B.lambda4_n = px4CtrlQGCGPS_P.lambda4_Gain_a *
    px4CtrlQGCGPS_B.Product2_d;

  // Gain: '<S15>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S15>/Discrete-Time Integrator'

  px4CtrlQGCGPS_B.rolldegree_c = px4CtrlQGCGPS_P.Gain2_Gain_p *
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator_DSTATE_f;

  // Switch: '<S15>/Switch' incorporates:
  //   Constant: '<S15>/Constant3'
  //   DataStoreRead: '<S15>/Data Store Read'
  //   DataStoreRead: '<S15>/Data Store Read1'
  //   DataStoreRead: '<S15>/Data Store Read2'
  //   DataStoreWrite: '<Root>/Data Store Write13'
  //   Gain: '<S15>/1//J'
  //   Gain: '<S15>/k//J'
  //   ZeroOrderHold: '<S15>/Zero-Order Hold1'

  if (px4CtrlQGCGPS_DW.observer_flag) {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 = px4CtrlQGCGPS_P.uJ_Gain_g *
      px4CtrlQGCGPS_B.DataStoreRead26;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1 = px4CtrlQGCGPS_P.kJ_Gain_p *
      px4CtrlQGCGPS_DW.roll_speed;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 = px4CtrlQGCGPS_DW.roll;
  } else {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 =
      px4CtrlQGCGPS_P.Constant3_Value_a;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1 =
      px4CtrlQGCGPS_P.Constant3_Value_a;
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 =
      px4CtrlQGCGPS_P.Constant3_Value_a;
  }

  // End of Switch: '<S15>/Switch'

  // Sum: '<S15>/Add1' incorporates:
  //   DiscreteIntegrator: '<S15>/Discrete-Time Integrator'

  px4CtrlQGCGPS_B.Product1_p = px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 -
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator_DSTATE_f;

  // Abs: '<S15>/Abs3' incorporates:
  //   Abs: '<S15>/Abs4'
  //   Abs: '<S15>/Abs5'
  //   Abs: '<S15>/Abs6'

  px4CtrlQGCGPS_B.Product2_d = fabs(px4CtrlQGCGPS_B.Product1_p);

  // Saturate: '<S15>/Saturation'
  if (px4CtrlQGCGPS_B.Product1_p > px4CtrlQGCGPS_P.Saturation_UpperSat_n1) {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 =
      px4CtrlQGCGPS_P.Saturation_UpperSat_n1;
  } else if (px4CtrlQGCGPS_B.Product1_p < px4CtrlQGCGPS_P.Saturation_LowerSat_c)
  {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 =
      px4CtrlQGCGPS_P.Saturation_LowerSat_c;
  } else {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2 = px4CtrlQGCGPS_B.Product1_p;
  }

  // End of Saturate: '<S15>/Saturation'

  // Gain: '<S15>/lambda1'
  px4CtrlQGCGPS_B.lambda1_e = px4CtrlQGCGPS_P.lambda1_Gain_g *
    px4CtrlQGCGPS_B.Product1_p;

  // Sum: '<S15>/Add7' incorporates:
  //   Constant: '<S15>/Constant1'
  //   Sum: '<S15>/Add13'
  //   Sum: '<S15>/Add18'

  px4CtrlQGCGPS_B.lambda4_h = px4CtrlQGCGPS_P.Constant1_Value_ac +
    px4CtrlQGCGPS_B.Product1_p;

  // Sum: '<S15>/Add6' incorporates:
  //   Constant: '<S15>/Constant1'
  //   Sum: '<S15>/Add12'
  //   Sum: '<S15>/Add17'

  u0_tmp = px4CtrlQGCGPS_B.Product1_p - px4CtrlQGCGPS_P.Constant1_Value_ac;

  // Saturate: '<S15>/Saturation10' incorporates:
  //   Sum: '<S15>/Add7'

  if (px4CtrlQGCGPS_B.lambda4_h > px4CtrlQGCGPS_P.Saturation10_UpperSat_a) {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_P.Saturation10_UpperSat_a;
  } else if (px4CtrlQGCGPS_B.lambda4_h < px4CtrlQGCGPS_P.Saturation10_LowerSat_l)
  {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_P.Saturation10_LowerSat_l;
  } else {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_B.lambda4_h;
  }

  // End of Saturate: '<S15>/Saturation10'

  // Saturate: '<S15>/Saturation11' incorporates:
  //   Sum: '<S15>/Add6'

  if (u0_tmp > px4CtrlQGCGPS_P.Saturation11_UpperSat_a) {
    px4CtrlQGCGPS_B.Product5_l = px4CtrlQGCGPS_P.Saturation11_UpperSat_a;
  } else if (u0_tmp < px4CtrlQGCGPS_P.Saturation11_LowerSat_a) {
    px4CtrlQGCGPS_B.Product5_l = px4CtrlQGCGPS_P.Saturation11_LowerSat_a;
  } else {
    px4CtrlQGCGPS_B.Product5_l = u0_tmp;
  }

  // End of Saturate: '<S15>/Saturation11'

  // Gain: '<S15>/Gain' incorporates:
  //   Sum: '<S15>/Add8'

  px4CtrlQGCGPS_B.Product3_i = (px4CtrlQGCGPS_B.Product6_a -
    px4CtrlQGCGPS_B.Product5_l) * px4CtrlQGCGPS_P.Gain_Gain_h;

  // Fcn: '<S15>/Fcn3' incorporates:
  //   Constant: '<S15>/Constant1'

  if (px4CtrlQGCGPS_P.Constant1_Value_ac < 0.0) {
    px4CtrlQGCGPS_B.fcn5 = -rt_powd_snf(-px4CtrlQGCGPS_P.Constant1_Value_ac,
      -0.5);
  } else {
    px4CtrlQGCGPS_B.fcn5 = rt_powd_snf(px4CtrlQGCGPS_P.Constant1_Value_ac, -0.5);
  }

  // End of Fcn: '<S15>/Fcn3'

  // Product: '<S15>/Product3'
  px4CtrlQGCGPS_B.Product3_c = px4CtrlQGCGPS_B.fcn5 * px4CtrlQGCGPS_B.Product3_i
    * px4CtrlQGCGPS_B.Product1_p;

  // Saturate: '<S15>/Saturation8'
  if (px4CtrlQGCGPS_B.Product1_p > px4CtrlQGCGPS_P.Saturation8_UpperSat_c) {
    px4CtrlQGCGPS_B.rtb_Product1_p_b = px4CtrlQGCGPS_P.Saturation8_UpperSat_c;
  } else if (px4CtrlQGCGPS_B.Product1_p < px4CtrlQGCGPS_P.Saturation8_LowerSat_c)
  {
    px4CtrlQGCGPS_B.rtb_Product1_p_b = px4CtrlQGCGPS_P.Saturation8_LowerSat_c;
  } else {
    px4CtrlQGCGPS_B.rtb_Product1_p_b = px4CtrlQGCGPS_B.Product1_p;
  }

  // End of Saturate: '<S15>/Saturation8'

  // Product: '<S15>/Product4' incorporates:
  //   Abs: '<S15>/Abs3'
  //   Constant: '<S15>/Constant2'
  //   Fcn: '<S15>/Fcn4'
  //   Sum: '<S15>/Add10'

  px4CtrlQGCGPS_B.Product4_g = rt_powd_snf(px4CtrlQGCGPS_B.Product2_d, 0.5) *
    px4CtrlQGCGPS_B.rtb_Product1_p_b * (px4CtrlQGCGPS_P.Constant2_Value_k -
    px4CtrlQGCGPS_B.Product3_i);

  // Saturate: '<S15>/Saturation13'
  if (px4CtrlQGCGPS_B.lambda4_h > px4CtrlQGCGPS_P.Saturation13_UpperSat_p) {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_P.Saturation13_UpperSat_p;
  } else if (px4CtrlQGCGPS_B.lambda4_h < px4CtrlQGCGPS_P.Saturation13_LowerSat_j)
  {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_P.Saturation13_LowerSat_j;
  } else {
    px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_B.lambda4_h;
  }

  // End of Saturate: '<S15>/Saturation13'

  // Saturate: '<S15>/Saturation9'
  if (u0_tmp > px4CtrlQGCGPS_P.Saturation9_UpperSat_d) {
    px4CtrlQGCGPS_B.Product5_l = px4CtrlQGCGPS_P.Saturation9_UpperSat_d;
  } else if (u0_tmp < px4CtrlQGCGPS_P.Saturation9_LowerSat_c4) {
    px4CtrlQGCGPS_B.Product5_l = px4CtrlQGCGPS_P.Saturation9_LowerSat_c4;
  } else {
    px4CtrlQGCGPS_B.Product5_l = u0_tmp;
  }

  // End of Saturate: '<S15>/Saturation9'

  // Gain: '<S15>/Gain1' incorporates:
  //   Sum: '<S15>/Add14'

  px4CtrlQGCGPS_B.Product3_i = (px4CtrlQGCGPS_B.Product6_a -
    px4CtrlQGCGPS_B.Product5_l) * px4CtrlQGCGPS_P.Gain1_Gain_e;

  // Fcn: '<S15>/Fcn6' incorporates:
  //   Constant: '<S15>/Constant1'

  if (px4CtrlQGCGPS_P.Constant1_Value_ac < 0.0) {
    px4CtrlQGCGPS_B.fcn5 = -rt_powd_snf(-px4CtrlQGCGPS_P.Constant1_Value_ac,
      -0.9375);
  } else {
    px4CtrlQGCGPS_B.fcn5 = rt_powd_snf(px4CtrlQGCGPS_P.Constant1_Value_ac,
      -0.9375);
  }

  // End of Fcn: '<S15>/Fcn6'

  // Product: '<S15>/Product6'
  px4CtrlQGCGPS_B.Product6_a = px4CtrlQGCGPS_B.fcn5 * px4CtrlQGCGPS_B.Product3_i
    * px4CtrlQGCGPS_B.Product1_p;

  // Saturate: '<S15>/Saturation12'
  if (px4CtrlQGCGPS_B.Product1_p > px4CtrlQGCGPS_P.Saturation12_UpperSat_d) {
    px4CtrlQGCGPS_B.rtb_Product1_p_b = px4CtrlQGCGPS_P.Saturation12_UpperSat_d;
  } else if (px4CtrlQGCGPS_B.Product1_p <
             px4CtrlQGCGPS_P.Saturation12_LowerSat_j) {
    px4CtrlQGCGPS_B.rtb_Product1_p_b = px4CtrlQGCGPS_P.Saturation12_LowerSat_j;
  } else {
    px4CtrlQGCGPS_B.rtb_Product1_p_b = px4CtrlQGCGPS_B.Product1_p;
  }

  // End of Saturate: '<S15>/Saturation12'

  // Product: '<S15>/Product5' incorporates:
  //   Constant: '<S15>/Constant4'
  //   Fcn: '<S15>/Fcn5'
  //   Sum: '<S15>/Add11'

  px4CtrlQGCGPS_B.Product5_l = rt_powd_snf(px4CtrlQGCGPS_B.Product2_d, 0.0625) *
    px4CtrlQGCGPS_B.rtb_Product1_p_b * (px4CtrlQGCGPS_P.Constant4_Value_l -
    px4CtrlQGCGPS_B.Product3_i);

  // Saturate: '<S15>/Saturation16'
  if (px4CtrlQGCGPS_B.lambda4_h > px4CtrlQGCGPS_P.Saturation16_UpperSat_p) {
    px4CtrlQGCGPS_B.lambda4_h = px4CtrlQGCGPS_P.Saturation16_UpperSat_p;
  } else if (px4CtrlQGCGPS_B.lambda4_h < px4CtrlQGCGPS_P.Saturation16_LowerSat_i)
  {
    px4CtrlQGCGPS_B.lambda4_h = px4CtrlQGCGPS_P.Saturation16_LowerSat_i;
  }

  // End of Saturate: '<S15>/Saturation16'

  // Saturate: '<S15>/Saturation14'
  if (u0_tmp > px4CtrlQGCGPS_P.Saturation14_UpperSat_n) {
    u0_tmp = px4CtrlQGCGPS_P.Saturation14_UpperSat_n;
  } else if (u0_tmp < px4CtrlQGCGPS_P.Saturation14_LowerSat_a) {
    u0_tmp = px4CtrlQGCGPS_P.Saturation14_LowerSat_a;
  }

  // End of Saturate: '<S15>/Saturation14'

  // Gain: '<S15>/Gain3' incorporates:
  //   Sum: '<S15>/Add19'

  px4CtrlQGCGPS_B.Product3_i = (px4CtrlQGCGPS_B.lambda4_h - u0_tmp) *
    px4CtrlQGCGPS_P.Gain3_Gain_p;

  // Saturate: '<S15>/Saturation1'
  if (px4CtrlQGCGPS_B.Product1_p > px4CtrlQGCGPS_P.Saturation1_UpperSat_d) {
    px4CtrlQGCGPS_B.rtb_Product1_p_b = px4CtrlQGCGPS_P.Saturation1_UpperSat_d;
  } else if (px4CtrlQGCGPS_B.Product1_p < px4CtrlQGCGPS_P.Saturation1_LowerSat_g)
  {
    px4CtrlQGCGPS_B.rtb_Product1_p_b = px4CtrlQGCGPS_P.Saturation1_LowerSat_g;
  } else {
    px4CtrlQGCGPS_B.rtb_Product1_p_b = px4CtrlQGCGPS_B.Product1_p;
  }

  // End of Saturate: '<S15>/Saturation1'

  // Fcn: '<S15>/Fcn7' incorporates:
  //   Constant: '<S15>/Constant1'

  if (px4CtrlQGCGPS_P.Constant1_Value_ac < 0.0) {
    px4CtrlQGCGPS_B.fcn5 = -rt_powd_snf(-px4CtrlQGCGPS_P.Constant1_Value_ac,
      -0.75);
  } else {
    px4CtrlQGCGPS_B.fcn5 = rt_powd_snf(px4CtrlQGCGPS_P.Constant1_Value_ac, -0.75);
  }

  // End of Fcn: '<S15>/Fcn7'

  // Saturate: '<S15>/Saturation15'
  if (px4CtrlQGCGPS_B.Product1_p > px4CtrlQGCGPS_P.Saturation15_UpperSat_k) {
    px4CtrlQGCGPS_B.lambda4_h = px4CtrlQGCGPS_P.Saturation15_UpperSat_k;
  } else if (px4CtrlQGCGPS_B.Product1_p <
             px4CtrlQGCGPS_P.Saturation15_LowerSat_h) {
    px4CtrlQGCGPS_B.lambda4_h = px4CtrlQGCGPS_P.Saturation15_LowerSat_h;
  } else {
    px4CtrlQGCGPS_B.lambda4_h = px4CtrlQGCGPS_B.Product1_p;
  }

  // End of Saturate: '<S15>/Saturation15'

  // Sum: '<S15>/Add2' incorporates:
  //   Constant: '<S15>/Constant6'
  //   DiscreteIntegrator: '<S15>/Discrete-Time Integrator3'
  //   Fcn: '<S15>/Fcn8'
  //   Gain: '<S15>/Gain6'
  //   Gain: '<S15>/l2'
  //   Gain: '<S15>/lambda2'
  //   Product: '<S15>/Product7'
  //   Product: '<S15>/Product8'
  //   Sum: '<S15>/Add16'
  //   Sum: '<S15>/Add20'
  //   Sum: '<S15>/Add3'

  px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 =
    (((px4CtrlQGCGPS_P.lambda2_Gain_d * px4CtrlQGCGPS_B.Product1_p +
       px4CtrlQGCGPS_P.l2_Gain_i * px4CtrlQGCGPS_B.rtb_Product1_p_b) +
      (px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0 -
       px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1)) +
     px4CtrlQGCGPS_DW.DiscreteTimeIntegrator3_DSTAT_m) + (px4CtrlQGCGPS_B.fcn5 *
    px4CtrlQGCGPS_B.Product3_i * px4CtrlQGCGPS_B.Product1_p + rt_powd_snf
    (px4CtrlQGCGPS_B.Product2_d, 0.25) * px4CtrlQGCGPS_B.lambda4_h *
    (px4CtrlQGCGPS_P.Constant6_Value_g - px4CtrlQGCGPS_B.Product3_i)) *
    px4CtrlQGCGPS_P.Gain6_Gain_f;

  // Saturate: '<S15>/Saturation3'
  if (px4CtrlQGCGPS_B.Product1_p > px4CtrlQGCGPS_P.Saturation3_UpperSat_i) {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1 =
      px4CtrlQGCGPS_P.Saturation3_UpperSat_i;
  } else if (px4CtrlQGCGPS_B.Product1_p < px4CtrlQGCGPS_P.Saturation3_LowerSat_g)
  {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1 =
      px4CtrlQGCGPS_P.Saturation3_LowerSat_g;
  } else {
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1 = px4CtrlQGCGPS_B.Product1_p;
  }

  // End of Saturate: '<S15>/Saturation3'

  // Gain: '<S15>/lambda4'
  px4CtrlQGCGPS_B.lambda4_h = px4CtrlQGCGPS_P.lambda4_Gain_b *
    px4CtrlQGCGPS_B.Product1_p;

  // MATLABSystem: '<S5>/SourceBlock'
  rtb_LogicalOperator = uORB_read_step(px4CtrlQGCGPS_DW.obj_n.orbMetadataObj,
    &px4CtrlQGCGPS_DW.obj_n.eventStructObj, &px4CtrlQGCGPS_B.b_varargout_2,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S45>/Enable'

  if (rtb_LogicalOperator) {
    // SignalConversion generated from: '<S45>/In1'
    px4CtrlQGCGPS_B.In1 = px4CtrlQGCGPS_B.b_varargout_2;
    srUpdateBC(px4CtrlQGCGPS_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'

  // Sqrt: '<S52>/sqrt' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   Product: '<S53>/Product'
  //   Product: '<S53>/Product1'
  //   Product: '<S53>/Product2'
  //   Product: '<S53>/Product3'
  //   Sum: '<S53>/Sum'

  px4CtrlQGCGPS_B.Product3_i = sqrt(((static_cast<real_T>(px4CtrlQGCGPS_B.In1.q
    [0]) * px4CtrlQGCGPS_B.In1.q[0] + static_cast<real_T>(px4CtrlQGCGPS_B.In1.q
    [1]) * px4CtrlQGCGPS_B.In1.q[1]) + static_cast<real_T>
    (px4CtrlQGCGPS_B.In1.q[2]) * px4CtrlQGCGPS_B.In1.q[2]) + static_cast<real_T>
    (px4CtrlQGCGPS_B.In1.q[3]) * px4CtrlQGCGPS_B.In1.q[3]);

  // Product: '<S47>/Product' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4CtrlQGCGPS_B.fcn5 = px4CtrlQGCGPS_B.In1.q[0] / px4CtrlQGCGPS_B.Product3_i;

  // Product: '<S47>/Product1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4CtrlQGCGPS_B.Product1_p = px4CtrlQGCGPS_B.In1.q[1] /
    px4CtrlQGCGPS_B.Product3_i;

  // Product: '<S47>/Product2' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_B.In1.q[2] /
    px4CtrlQGCGPS_B.Product3_i;

  // Product: '<S47>/Product3' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4CtrlQGCGPS_B.Product3_i = px4CtrlQGCGPS_B.In1.q[3] /
    px4CtrlQGCGPS_B.Product3_i;

  // Fcn: '<S6>/fcn3'
  px4CtrlQGCGPS_B.fcn3 = (px4CtrlQGCGPS_B.Product1_p *
    px4CtrlQGCGPS_B.Product3_i - px4CtrlQGCGPS_B.fcn5 *
    px4CtrlQGCGPS_B.Product2_d) * -2.0;

  // If: '<S48>/If' incorporates:
  //   Constant: '<S49>/Constant'
  //   Constant: '<S50>/Constant'

  if (px4CtrlQGCGPS_B.fcn3 > 1.0) {
    // Outputs for IfAction SubSystem: '<S48>/If Action Subsystem' incorporates:
    //   ActionPort: '<S49>/Action Port'

    px4CtrlQGCGPS_B.fcn3 = px4CtrlQGCGPS_P.Constant_Value_e;

    // End of Outputs for SubSystem: '<S48>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S48>/If Action Subsystem' incorporates:
    //   ActionPort: '<S49>/Action Port'

    // Update for If: '<S48>/If' incorporates:
    //   Constant: '<S49>/Constant'

    srUpdateBC(px4CtrlQGCGPS_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S48>/If Action Subsystem'
  } else if (px4CtrlQGCGPS_B.fcn3 < -1.0) {
    // Outputs for IfAction SubSystem: '<S48>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S50>/Action Port'

    px4CtrlQGCGPS_B.fcn3 = px4CtrlQGCGPS_P.Constant_Value_b1;

    // End of Outputs for SubSystem: '<S48>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S48>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S50>/Action Port'

    // Update for If: '<S48>/If' incorporates:
    //   Constant: '<S50>/Constant'

    srUpdateBC(px4CtrlQGCGPS_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S48>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S48>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S51>/Action Port'

    // Update for If: '<S48>/If'
    srUpdateBC(px4CtrlQGCGPS_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S48>/If Action Subsystem2'
  }

  // End of If: '<S48>/If'

  // Fcn: '<S6>/fcn5' incorporates:
  //   Fcn: '<S6>/fcn2'

  u0_tmp = px4CtrlQGCGPS_B.fcn5 * px4CtrlQGCGPS_B.fcn5;
  px4CtrlQGCGPS_B.rtb_Product1_p_b = px4CtrlQGCGPS_B.Product1_p *
    px4CtrlQGCGPS_B.Product1_p;
  roll_tmp = px4CtrlQGCGPS_B.Product2_d * px4CtrlQGCGPS_B.Product2_d;
  roll_tmp_0 = px4CtrlQGCGPS_B.Product3_i * px4CtrlQGCGPS_B.Product3_i;

  // DataStoreWrite: '<Root>/Data Store Write' incorporates:
  //   Fcn: '<S6>/fcn4'
  //   Fcn: '<S6>/fcn5'
  //   Trigonometry: '<S46>/Trigonometric Function3'

  px4CtrlQGCGPS_DW.roll = rt_atan2d_snf((px4CtrlQGCGPS_B.Product2_d *
    px4CtrlQGCGPS_B.Product3_i + px4CtrlQGCGPS_B.fcn5 *
    px4CtrlQGCGPS_B.Product1_p) * 2.0, ((u0_tmp -
    px4CtrlQGCGPS_B.rtb_Product1_p_b) - roll_tmp) + roll_tmp_0);

  // Trigonometry: '<S46>/trigFcn'
  if (px4CtrlQGCGPS_B.fcn3 > 1.0) {
    px4CtrlQGCGPS_B.fcn3 = 1.0;
  } else if (px4CtrlQGCGPS_B.fcn3 < -1.0) {
    px4CtrlQGCGPS_B.fcn3 = -1.0;
  }

  // DataStoreWrite: '<Root>/Data Store Write1' incorporates:
  //   Trigonometry: '<S46>/trigFcn'

  px4CtrlQGCGPS_DW.pitch = asin(px4CtrlQGCGPS_B.fcn3);

  // DataStoreWrite: '<Root>/Data Store Write10' incorporates:
  //   Fcn: '<S6>/fcn1'
  //   Fcn: '<S6>/fcn2'
  //   Trigonometry: '<S46>/Trigonometric Function1'

  px4CtrlQGCGPS_DW.yaw = rt_atan2d_snf((px4CtrlQGCGPS_B.Product1_p *
    px4CtrlQGCGPS_B.Product2_d + px4CtrlQGCGPS_B.fcn5 *
    px4CtrlQGCGPS_B.Product3_i) * 2.0, ((u0_tmp +
    px4CtrlQGCGPS_B.rtb_Product1_p_b) - roll_tmp) - roll_tmp_0);

  // DataStoreWrite: '<Root>/Data Store Write20' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px4CtrlQGCGPS_DW.yaw_speed = px4CtrlQGCGPS_B.In1.yawspeed;

  // DataStoreWrite: '<Root>/Data Store Write21' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px4CtrlQGCGPS_DW.pitch_speed = px4CtrlQGCGPS_B.In1.pitchspeed;

  // DataStoreWrite: '<Root>/Data Store Write22' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px4CtrlQGCGPS_DW.roll_speed = px4CtrlQGCGPS_B.In1.rollspeed;

  // MATLAB Function: '<Root>/MATLAB Function2' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read'
  //   DataStoreRead: '<Root>/Data Store Read7'
  //   MATLAB Function: '<Root>/MATLAB Function1'

  px4CtrlQGCGPS_B.Product1_p = cos(px4CtrlQGCGPS_DW.pitch);
  px4CtrlQGCGPS_B.Product2_d = 9.8 / (cos(px4CtrlQGCGPS_DW.roll) *
    px4CtrlQGCGPS_B.Product1_p);

  // MATLAB Function: '<Root>/MATLAB Function1' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read'
  //   DataStoreRead: '<Root>/Data Store Read7'
  //   DataStoreWrite: '<Root>/Data Store Write2'
  //   DataStoreWrite: '<Root>/Data Store Write3'

  px4CtrlQGCGPS_B.fcn5 = sin(px4CtrlQGCGPS_DW.pitch);
  px4CtrlQGCGPS_B.DataStoreRead8 = (px4CtrlQGCGPS_B.Product1_p * sin
    (px4CtrlQGCGPS_DW.roll) + px4CtrlQGCGPS_B.fcn5 * 0.0) *
    -px4CtrlQGCGPS_B.Product2_d;
  px4CtrlQGCGPS_B.DataStoreRead9 = (cos(px4CtrlQGCGPS_DW.pitch) * sin
    (px4CtrlQGCGPS_DW.roll) * 0.0 - px4CtrlQGCGPS_B.fcn5) *
    -px4CtrlQGCGPS_B.Product2_d;

  // DataStoreWrite: '<S8>/Data Store Write28' incorporates:
  //   Constant: '<S8>/attitude_flag'

  px4CtrlQGCGPS_DW.attitude_flag = px4CtrlQGCGPS_P.attitude_flag_Value;

  // DataStoreWrite: '<S9>/Data Store Write28' incorporates:
  //   Constant: '<S9>/observer_flag'

  px4CtrlQGCGPS_DW.observer_flag = px4CtrlQGCGPS_P.observer_flag_Value;
  for (int32_T i = 0; i < 4; i++) {
    // Gain: '<Root>/Gain4' incorporates:
    //   Constant: '<Root>/Constant1'
    //   Constant: '<Root>/Mixer matrix1'
    //   DataStoreRead: '<Root>/Data Store Read21'
    //   DataStoreRead: '<Root>/Data Store Read22'
    //   DataStoreRead: '<Root>/Data Store Read23'
    //   Product: '<Root>/Product2'
    //   SignalConversion generated from: '<Root>/Product2'

    px4CtrlQGCGPS_B.fcn5 = floor((((px4CtrlQGCGPS_P.Mixermatrix1_Value[i + 4] *
      px4CtrlQGCGPS_B.DataStoreRead25 + px4CtrlQGCGPS_P.Mixermatrix1_Value[i] *
      px4CtrlQGCGPS_P.Constant1_Value_l) + px4CtrlQGCGPS_P.Mixermatrix1_Value[i
      + 8] * px4CtrlQGCGPS_B.DataStoreRead26) +
      px4CtrlQGCGPS_P.Mixermatrix1_Value[i + 12] *
      px4CtrlQGCGPS_B.DataStoreRead27) * px4CtrlQGCGPS_P.Gain4_Gain_fc);
    if (rtIsNaN(px4CtrlQGCGPS_B.fcn5) || rtIsInf(px4CtrlQGCGPS_B.fcn5)) {
      px4CtrlQGCGPS_B.fcn5 = 0.0;
    } else {
      px4CtrlQGCGPS_B.fcn5 = fmod(px4CtrlQGCGPS_B.fcn5, 65536.0);
    }

    px4CtrlQGCGPS_B.Gain4[i] = static_cast<uint16_T>(px4CtrlQGCGPS_B.fcn5 < 0.0 ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-px4CtrlQGCGPS_B.fcn5)))) : static_cast<int32_T>(
      static_cast<uint16_T>(px4CtrlQGCGPS_B.fcn5)));

    // End of Gain: '<Root>/Gain4'
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1'
  for (int32_T i = 0; i < 8; i++) {
    px4CtrlQGCGPS_B.pwmValue[i] = 0U;
  }

  // Sum: '<Root>/Add' incorporates:
  //   Constant: '<Root>/fault_1'

  px4CtrlQGCGPS_B.fcn5 = floor(static_cast<real_T>(px4CtrlQGCGPS_B.Gain4[0]) -
    px4CtrlQGCGPS_P.fault_1_Value);
  if (rtIsNaN(px4CtrlQGCGPS_B.fcn5) || rtIsInf(px4CtrlQGCGPS_B.fcn5)) {
    px4CtrlQGCGPS_B.fcn5 = 0.0;
  } else {
    px4CtrlQGCGPS_B.fcn5 = fmod(px4CtrlQGCGPS_B.fcn5, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Sum: '<Root>/Add'

  px4CtrlQGCGPS_B.pwmValue[0] = static_cast<uint16_T>(px4CtrlQGCGPS_B.fcn5 < 0.0
    ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-px4CtrlQGCGPS_B.fcn5)))) : static_cast<int32_T>(
    static_cast<uint16_T>(px4CtrlQGCGPS_B.fcn5)));

  // Sum: '<Root>/Add1' incorporates:
  //   Constant: '<Root>/fault_2'

  px4CtrlQGCGPS_B.fcn5 = floor(static_cast<real_T>(px4CtrlQGCGPS_B.Gain4[1]) -
    px4CtrlQGCGPS_P.fault_2_Value);
  if (rtIsNaN(px4CtrlQGCGPS_B.fcn5) || rtIsInf(px4CtrlQGCGPS_B.fcn5)) {
    px4CtrlQGCGPS_B.fcn5 = 0.0;
  } else {
    px4CtrlQGCGPS_B.fcn5 = fmod(px4CtrlQGCGPS_B.fcn5, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Sum: '<Root>/Add1'

  px4CtrlQGCGPS_B.pwmValue[1] = static_cast<uint16_T>(px4CtrlQGCGPS_B.fcn5 < 0.0
    ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-px4CtrlQGCGPS_B.fcn5)))) : static_cast<int32_T>(
    static_cast<uint16_T>(px4CtrlQGCGPS_B.fcn5)));

  // Sum: '<Root>/Add2' incorporates:
  //   Constant: '<Root>/fault_3'

  px4CtrlQGCGPS_B.fcn5 = floor(static_cast<real_T>(px4CtrlQGCGPS_B.Gain4[2]) -
    px4CtrlQGCGPS_P.fault_3_Value);
  if (rtIsNaN(px4CtrlQGCGPS_B.fcn5) || rtIsInf(px4CtrlQGCGPS_B.fcn5)) {
    px4CtrlQGCGPS_B.fcn5 = 0.0;
  } else {
    px4CtrlQGCGPS_B.fcn5 = fmod(px4CtrlQGCGPS_B.fcn5, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Sum: '<Root>/Add2'

  px4CtrlQGCGPS_B.pwmValue[2] = static_cast<uint16_T>(px4CtrlQGCGPS_B.fcn5 < 0.0
    ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-px4CtrlQGCGPS_B.fcn5)))) : static_cast<int32_T>(
    static_cast<uint16_T>(px4CtrlQGCGPS_B.fcn5)));

  // Sum: '<Root>/Add3' incorporates:
  //   Constant: '<Root>/fault_4'

  px4CtrlQGCGPS_B.fcn5 = floor(static_cast<real_T>(px4CtrlQGCGPS_B.Gain4[3]) -
    px4CtrlQGCGPS_P.fault_4_Value);
  if (rtIsNaN(px4CtrlQGCGPS_B.fcn5) || rtIsInf(px4CtrlQGCGPS_B.fcn5)) {
    px4CtrlQGCGPS_B.fcn5 = 0.0;
  } else {
    px4CtrlQGCGPS_B.fcn5 = fmod(px4CtrlQGCGPS_B.fcn5, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Constant: '<Root>/Constant2'
  //   DataStoreRead: '<Root>/Data Store Read6'
  //   Sum: '<Root>/Add3'

  px4CtrlQGCGPS_B.pwmValue[3] = static_cast<uint16_T>(px4CtrlQGCGPS_B.fcn5 < 0.0
    ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-px4CtrlQGCGPS_B.fcn5)))) : static_cast<int32_T>(
    static_cast<uint16_T>(px4CtrlQGCGPS_B.fcn5)));
  if (px4CtrlQGCGPS_DW.armed) {
    if (!px4CtrlQGCGPS_DW.obj.isArmed) {
      px4CtrlQGCGPS_DW.obj.isArmed = true;
      status = pwm_arm(&px4CtrlQGCGPS_DW.obj.pwmDevHandler,
                       &px4CtrlQGCGPS_DW.obj.armAdvertiseObj);
      px4CtrlQGCGPS_DW.obj.errorStatus = static_cast<uint16_T>
        (px4CtrlQGCGPS_DW.obj.errorStatus | status);
    }

    status = pwm_setServo(&px4CtrlQGCGPS_DW.obj.pwmDevHandler,
                          px4CtrlQGCGPS_DW.obj.servoCount,
                          px4CtrlQGCGPS_DW.obj.channelMask,
                          &px4CtrlQGCGPS_B.pwmValue[0],
                          px4CtrlQGCGPS_DW.obj.isMain,
                          &px4CtrlQGCGPS_DW.obj.actuatorAdvertiseObj);
    px4CtrlQGCGPS_DW.obj.errorStatus = static_cast<uint16_T>
      (px4CtrlQGCGPS_DW.obj.errorStatus | status);
  } else {
    status = pwm_disarm(&px4CtrlQGCGPS_DW.obj.pwmDevHandler,
                        &px4CtrlQGCGPS_DW.obj.armAdvertiseObj);
    px4CtrlQGCGPS_DW.obj.errorStatus = static_cast<uint16_T>
      (px4CtrlQGCGPS_DW.obj.errorStatus | status);
    px4CtrlQGCGPS_DW.obj.isArmed = false;
    status = pwm_resetServo(&px4CtrlQGCGPS_DW.obj.pwmDevHandler,
      px4CtrlQGCGPS_DW.obj.servoCount, px4CtrlQGCGPS_DW.obj.channelMask,
      px4CtrlQGCGPS_DW.obj.isMain, &px4CtrlQGCGPS_DW.obj.actuatorAdvertiseObj);
    px4CtrlQGCGPS_DW.obj.errorStatus = static_cast<uint16_T>
      (px4CtrlQGCGPS_DW.obj.errorStatus | status);
  }

  if (px4CtrlQGCGPS_DW.obj.isMain) {
    status = pwm_forceFailsafe(&px4CtrlQGCGPS_DW.obj.pwmDevHandler, static_cast<
      int32_T>(px4CtrlQGCGPS_P.Constant2_Value_kf));
    px4CtrlQGCGPS_DW.obj.errorStatus = static_cast<uint16_T>
      (px4CtrlQGCGPS_DW.obj.errorStatus | status);
  }

  // Gain: '<Root>/Gain8' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read31'

  px4CtrlQGCGPS_B.pitch = px4CtrlQGCGPS_P.Gain8_Gain_o1 * px4CtrlQGCGPS_DW.pitch;

  // Gain: '<Root>/Gain10'
  px4CtrlQGCGPS_B.pitch_a = px4CtrlQGCGPS_P.Gain10_Gain *
    px4CtrlQGCGPS_B.ManualSwitch_g;

  // Gain: '<Root>/Gain7' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read30'

  px4CtrlQGCGPS_B.roll = px4CtrlQGCGPS_P.Gain7_Gain_a * px4CtrlQGCGPS_DW.roll;

  // Gain: '<Root>/Gain11'
  px4CtrlQGCGPS_B.pitch_g = px4CtrlQGCGPS_P.Gain11_Gain *
    px4CtrlQGCGPS_B.ManualSwitch_g;

  // Gain: '<Root>/Gain9' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read33'

  px4CtrlQGCGPS_B.yaw = px4CtrlQGCGPS_P.Gain9_Gain * px4CtrlQGCGPS_DW.yaw;

  // Logic: '<S5>/NOT' incorporates:
  //   MATLABSystem: '<S5>/SourceBlock'

  px4CtrlQGCGPS_B.NOT = !rtb_LogicalOperator;

  // Switch: '<Root>/Switch1' incorporates:
  //   Constant: '<Root>/Constant5'
  //   Constant: '<S10>/position_flag'
  //   DataStoreRead: '<Root>/Data Store Read50'
  //   DataStoreRead: '<Root>/Data Store Read51'

  if (px4CtrlQGCGPS_P.position_flag_Value) {
    px4CtrlQGCGPS_B.ManualSwitch_g = px4CtrlQGCGPS_B.DataStoreRead8;
    px4CtrlQGCGPS_B.fcn5 = px4CtrlQGCGPS_B.DataStoreRead9;
  } else {
    px4CtrlQGCGPS_B.ManualSwitch_g = px4CtrlQGCGPS_P.Constant5_Value;
    px4CtrlQGCGPS_B.fcn5 = px4CtrlQGCGPS_P.Constant5_Value;
  }

  // End of Switch: '<Root>/Switch1'

  // Gain: '<Root>/Gain5' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read10'

  px4CtrlQGCGPS_B.Gain5 = px4CtrlQGCGPS_P.Gain5_Gain_g * px4CtrlQGCGPS_DW.pitch;

  // Gain: '<Root>/Gain3' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read11'

  px4CtrlQGCGPS_B.Gain3 = px4CtrlQGCGPS_P.Gain3_Gain_c * px4CtrlQGCGPS_DW.roll;

  // DataStoreRead: '<Root>/Data Store Read12'
  px4CtrlQGCGPS_B.DataStoreRead12 = px4CtrlQGCGPS_DW.armed;

  // DataStoreRead: '<Root>/Data Store Read13' incorporates:
  //   Constant: '<Root>/Constant1'

  px4CtrlQGCGPS_B.DataStoreRead13 = px4CtrlQGCGPS_P.Constant1_Value_l;

  // DataStoreRead: '<Root>/Data Store Read15' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddY'

  px4CtrlQGCGPS_B.DataStoreRead15 = px4CtrlQGCGPS_DW.Intgrt_ddY_DSTATE;

  // DataStoreRead: '<Root>/Data Store Read16' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_dX'

  px4CtrlQGCGPS_B.DataStoreRead16 = px4CtrlQGCGPS_DW.Intgrt_dX_DSTATE;

  // DataStoreRead: '<Root>/Data Store Read17' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_dY'

  px4CtrlQGCGPS_B.DataStoreRead17 = px4CtrlQGCGPS_DW.Intgrt_dY_DSTATE;

  // DataStoreRead: '<Root>/Data Store Read19' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddX'

  px4CtrlQGCGPS_B.DataStoreRead19 = px4CtrlQGCGPS_DW.Intgrt_ddX_DSTATE;

  // Gain: '<Root>/Gain6' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read24'

  px4CtrlQGCGPS_B.Gain6 = px4CtrlQGCGPS_P.Gain6_Gain_k * px4CtrlQGCGPS_DW.yaw;

  // DataStoreRead: '<Root>/Data Store Read28'
  px4CtrlQGCGPS_B.pitch_thrust = px4CtrlQGCGPS_B.DataStoreRead25;

  // DataStoreRead: '<Root>/Data Store Read29'
  px4CtrlQGCGPS_B.roll_thrust = px4CtrlQGCGPS_B.DataStoreRead26;

  // DataStoreRead: '<Root>/Data Store Read32'
  px4CtrlQGCGPS_B.yaw_thrust = px4CtrlQGCGPS_B.DataStoreRead27;

  // DataStoreRead: '<Root>/Data Store Read34'
  px4CtrlQGCGPS_B.DataStoreRead34 = px4CtrlQGCGPS_DW.yaw_speed;

  // DataStoreRead: '<Root>/Data Store Read35'
  px4CtrlQGCGPS_B.DataStoreRead35 = px4CtrlQGCGPS_DW.pitch_speed;

  // DataStoreRead: '<Root>/Data Store Read36'
  px4CtrlQGCGPS_B.DataStoreRead36 = px4CtrlQGCGPS_DW.roll_speed;

  // DataStoreRead: '<Root>/Data Store Read37'
  px4CtrlQGCGPS_B.DataStoreRead37 = px4CtrlQGCGPS_DW.yaw_acc;

  // DataStoreRead: '<Root>/Data Store Read38'
  px4CtrlQGCGPS_B.DataStoreRead38 = px4CtrlQGCGPS_DW.pitch_acc;

  // DataStoreRead: '<Root>/Data Store Read39'
  px4CtrlQGCGPS_B.DataStoreRead39 = px4CtrlQGCGPS_DW.roll_acc;

  // DataStoreRead: '<Root>/Data Store Read42'
  px4CtrlQGCGPS_B.DataStoreRead42 = px4CtrlQGCGPS_DW.lat;

  // DataStoreRead: '<Root>/Data Store Read43'
  px4CtrlQGCGPS_B.DataStoreRead43 = px4CtrlQGCGPS_DW.lon;

  // DataStoreRead: '<Root>/Data Store Read44'
  px4CtrlQGCGPS_B.DataStoreRead44 = px4CtrlQGCGPS_DW.alt;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_dX'

  px4CtrlQGCGPS_B.DataStoreRead48 = px4CtrlQGCGPS_DW.Intgrt_dX_DSTATE;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_dY'

  px4CtrlQGCGPS_B.DataStoreRead49 = px4CtrlQGCGPS_DW.Intgrt_dY_DSTATE;

  // Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
  //   EnablePort: '<S7>/Enable'

  // DataStoreRead: '<Root>/Data Store Read54'
  if (px4CtrlQGCGPS_DW.attitude_flag) {
    // DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
    //   DataStoreWrite: '<S7>/Data Store Write27'

    px4CtrlQGCGPS_DW.t = px4CtrlQGCGPS_DW.DiscreteTimeIntegrator_DSTAT_fj;

    // Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S7>/Constant9'

    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator_DSTAT_fj +=
      px4CtrlQGCGPS_P.DiscreteTimeIntegrator_gainval *
      px4CtrlQGCGPS_P.Constant9_Value;
    srUpdateBC(px4CtrlQGCGPS_DW.Subsystem1_SubsysRanBC);
  }

  // End of DataStoreRead: '<Root>/Data Store Read54'
  // End of Outputs for SubSystem: '<Root>/Subsystem1'

  // DataStoreRead: '<Root>/Data Store Read55'
  px4CtrlQGCGPS_B.DataStoreRead55 = px4CtrlQGCGPS_DW.t;

  // Update for UnitDelay: '<S35>/UD'
  //
  //  Block description for '<S35>/UD':
  //
  //   Store in Global RAM

  px4CtrlQGCGPS_DW.UD_DSTATE = px4CtrlQGCGPS_B.TSamp;

  // Saturate: '<S16>/Saturation3'
  if (px4CtrlQGCGPS_B.Abs6 > px4CtrlQGCGPS_P.Saturation3_UpperSat) {
    px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_P.Saturation3_UpperSat;
  } else if (px4CtrlQGCGPS_B.Abs6 < px4CtrlQGCGPS_P.Saturation3_LowerSat) {
    px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_P.Saturation3_LowerSat;
  } else {
    px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_B.Abs6;
  }

  // End of Saturate: '<S16>/Saturation3'

  // Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator3' incorporates:
  //   Gain: '<S16>/Gain7'
  //   Gain: '<S16>/l4'
  //   Gain: '<S16>/lambda4'
  //   Sum: '<S16>/Add15'
  //   Sum: '<S16>/Add5'

  px4CtrlQGCGPS_DW.DiscreteTimeIntegrator3_DSTATE += ((px4CtrlQGCGPS_P.l4_Gain *
    px4CtrlQGCGPS_B.Product2_d + px4CtrlQGCGPS_P.lambda4_Gain *
    px4CtrlQGCGPS_B.Abs6) + (px4CtrlQGCGPS_B.Product6 + px4CtrlQGCGPS_B.roll_hat)
    * px4CtrlQGCGPS_P.Gain7_Gain) *
    px4CtrlQGCGPS_P.DiscreteTimeIntegrator3_gainval;

  // Update for Sin: '<Root>/Sine Wave'
  px4CtrlQGCGPS_B.TSamp = px4CtrlQGCGPS_DW.lastSin;
  px4CtrlQGCGPS_DW.lastSin = px4CtrlQGCGPS_DW.lastSin *
    px4CtrlQGCGPS_P.SineWave_HCos + px4CtrlQGCGPS_DW.lastCos *
    px4CtrlQGCGPS_P.SineWave_Hsin;
  px4CtrlQGCGPS_DW.lastCos = px4CtrlQGCGPS_DW.lastCos *
    px4CtrlQGCGPS_P.SineWave_HCos - px4CtrlQGCGPS_B.TSamp *
    px4CtrlQGCGPS_P.SineWave_Hsin;

  // Update for UnitDelay: '<S17>/UD'
  //
  //  Block description for '<S17>/UD':
  //
  //   Store in Global RAM

  px4CtrlQGCGPS_DW.UD_DSTATE_b = px4CtrlQGCGPS_B.z2;

  // Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator3' incorporates:
  //   Gain: '<S14>/Gain7'
  //   Gain: '<S14>/l4'
  //   Sum: '<S14>/Add15'
  //   Sum: '<S14>/Add5'

  px4CtrlQGCGPS_DW.DiscreteTimeIntegrator3_DSTAT_a +=
    ((px4CtrlQGCGPS_P.l4_Gain_p * px4CtrlQGCGPS_B.roll_hat_k +
      px4CtrlQGCGPS_B.lambda4_n) + (px4CtrlQGCGPS_B.Product6_i +
      px4CtrlQGCGPS_B.Product5_b) * px4CtrlQGCGPS_P.Gain7_Gain_d) *
    px4CtrlQGCGPS_P.DiscreteTimeIntegrator3_gainv_m;

  // Update for UnitDelay: '<S26>/UD'
  //
  //  Block description for '<S26>/UD':
  //
  //   Store in Global RAM

  px4CtrlQGCGPS_DW.UD_DSTATE_n = px4CtrlQGCGPS_B.z2_e;

  // Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator3' incorporates:
  //   Gain: '<S15>/Gain7'
  //   Gain: '<S15>/l4'
  //   Sum: '<S15>/Add15'
  //   Sum: '<S15>/Add5'

  px4CtrlQGCGPS_DW.DiscreteTimeIntegrator3_DSTAT_m +=
    ((px4CtrlQGCGPS_P.l4_Gain_o * px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_1
      + px4CtrlQGCGPS_B.lambda4_h) + (px4CtrlQGCGPS_B.Product6_a +
      px4CtrlQGCGPS_B.Product5_l) * px4CtrlQGCGPS_P.Gain7_Gain_l) *
    px4CtrlQGCGPS_P.DiscreteTimeIntegrator3_gainv_e;

  // Saturate: '<S16>/Saturation'
  if (px4CtrlQGCGPS_B.Abs6 > px4CtrlQGCGPS_P.Saturation_UpperSat_b) {
    px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_P.Saturation_UpperSat_b;
  } else if (px4CtrlQGCGPS_B.Abs6 < px4CtrlQGCGPS_P.Saturation_LowerSat_k) {
    px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_P.Saturation_LowerSat_k;
  } else {
    px4CtrlQGCGPS_B.Product2_d = px4CtrlQGCGPS_B.Abs6;
  }

  // End of Saturate: '<S16>/Saturation'

  // Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S16>/Discrete-Time Integrator1'
  //   Gain: '<S16>/Gain5'
  //   Gain: '<S16>/l1'
  //   Gain: '<S16>/lambda1'
  //   Sum: '<S16>/Add'
  //   Sum: '<S16>/Add9'

  px4CtrlQGCGPS_DW.DiscreteTimeIntegrator_DSTATE += (((px4CtrlQGCGPS_P.l1_Gain *
    px4CtrlQGCGPS_B.Product2_d + px4CtrlQGCGPS_P.lambda1_Gain *
    px4CtrlQGCGPS_B.Abs6) + px4CtrlQGCGPS_DW.DiscreteTimeIntegrator1_DSTATE) +
    (px4CtrlQGCGPS_B.Add3 + px4CtrlQGCGPS_B.Product4) *
    px4CtrlQGCGPS_P.Gain5_Gain) *
    px4CtrlQGCGPS_P.DiscreteTimeIntegrator_gainva_n;

  // Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator1'
  px4CtrlQGCGPS_DW.DiscreteTimeIntegrator1_DSTATE +=
    px4CtrlQGCGPS_P.DiscreteTimeIntegrator1_gainval * px4CtrlQGCGPS_B.z2_l;

  // Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S14>/Discrete-Time Integrator1'
  //   Gain: '<S14>/Gain5'
  //   Gain: '<S14>/l1'
  //   Sum: '<S14>/Add'
  //   Sum: '<S14>/Add9'

  px4CtrlQGCGPS_DW.DiscreteTimeIntegrator_DSTATE_p +=
    (((px4CtrlQGCGPS_P.l1_Gain_p * px4CtrlQGCGPS_B.roll_hat_e +
       px4CtrlQGCGPS_B.lambda1_a) +
      px4CtrlQGCGPS_DW.DiscreteTimeIntegrator1_DSTAT_i) +
     (px4CtrlQGCGPS_B.Product3_a + px4CtrlQGCGPS_B.Product4_k) *
     px4CtrlQGCGPS_P.Gain5_Gain_o) *
    px4CtrlQGCGPS_P.DiscreteTimeIntegrator_gainva_e;

  // Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1'
  px4CtrlQGCGPS_DW.DiscreteTimeIntegrator1_DSTAT_i +=
    px4CtrlQGCGPS_P.DiscreteTimeIntegrator1_gainv_n * px4CtrlQGCGPS_B.Add2_o;

  // Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S15>/Discrete-Time Integrator1'
  //   Gain: '<S15>/Gain5'
  //   Gain: '<S15>/l1'
  //   Sum: '<S15>/Add'
  //   Sum: '<S15>/Add9'

  px4CtrlQGCGPS_DW.DiscreteTimeIntegrator_DSTATE_f +=
    (((px4CtrlQGCGPS_P.l1_Gain_d * px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_2
       + px4CtrlQGCGPS_B.lambda1_e) +
      px4CtrlQGCGPS_DW.DiscreteTimeIntegrator1_DSTAT_g) +
     (px4CtrlQGCGPS_B.Product3_c + px4CtrlQGCGPS_B.Product4_g) *
     px4CtrlQGCGPS_P.Gain5_Gain_l) *
    px4CtrlQGCGPS_P.DiscreteTimeIntegrator_gainv_nv;

  // Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator1'
  px4CtrlQGCGPS_DW.DiscreteTimeIntegrator1_DSTAT_g +=
    px4CtrlQGCGPS_P.DiscreteTimeIntegrator1_gainv_g *
    px4CtrlQGCGPS_B.rtb_DataTypeConversion3_idx_0;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_dX' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddX'

  px4CtrlQGCGPS_DW.Intgrt_dX_DSTATE += px4CtrlQGCGPS_P.Intgrt_dX_gainval *
    px4CtrlQGCGPS_DW.Intgrt_ddX_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_dY' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddY'

  px4CtrlQGCGPS_DW.Intgrt_dY_DSTATE += px4CtrlQGCGPS_P.Intgrt_dY_gainval *
    px4CtrlQGCGPS_DW.Intgrt_ddY_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_ddY' incorporates:
  //   Gain: '<Root>/slower4'

  px4CtrlQGCGPS_DW.Intgrt_ddY_DSTATE += px4CtrlQGCGPS_P.slower4_Gain *
    px4CtrlQGCGPS_B.fcn5 * px4CtrlQGCGPS_P.Intgrt_ddY_gainval;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_ddX' incorporates:
  //   Gain: '<Root>/slower3'

  px4CtrlQGCGPS_DW.Intgrt_ddX_DSTATE += px4CtrlQGCGPS_P.slower3_Gain *
    px4CtrlQGCGPS_B.ManualSwitch_g * px4CtrlQGCGPS_P.Intgrt_ddX_gainval;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_dZ' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddZ'

  px4CtrlQGCGPS_DW.Intgrt_dZ_DSTATE += px4CtrlQGCGPS_P.Intgrt_dZ_gainval *
    px4CtrlQGCGPS_DW.Intgrt_ddZ_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_ddZ' incorporates:
  //   Gain: '<Root>/slower5'

  px4CtrlQGCGPS_DW.Intgrt_ddZ_DSTATE += px4CtrlQGCGPS_P.slower5_Gain * 0.0 *
    px4CtrlQGCGPS_P.Intgrt_ddZ_gainval;

  // External mode
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)px4CtrlQGCGPS_M->Timing.taskTime0);

  // signal main to stop simulation
  {                                    // Sample time: [0.005s, 0.0s]
    if ((rtmGetTFinal(px4CtrlQGCGPS_M)!=-1) &&
        !((rtmGetTFinal(px4CtrlQGCGPS_M)-px4CtrlQGCGPS_M->Timing.taskTime0) >
          px4CtrlQGCGPS_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(px4CtrlQGCGPS_M, "Simulation finished");
    }

    if (rtmGetStopRequested(px4CtrlQGCGPS_M)) {
      rtmSetErrorStatus(px4CtrlQGCGPS_M, "Simulation finished");
    }
  }

  // Update absolute time
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  px4CtrlQGCGPS_M->Timing.taskTime0 =
    ((time_T)(++px4CtrlQGCGPS_M->Timing.clockTick0)) *
    px4CtrlQGCGPS_M->Timing.stepSize0;
}

// Model step function for TID1
void px4CtrlQGCGPS_step1(void)         // Sample time: [0.01s, 0.0s]
{
  uint64_T rtb_timestamp;
  uint32_T rtb_noutputs;
  uint8_T rtb__padding0[4];
  boolean_T b_varargout_1;
  boolean_T rtb_NOT;

  // Reset subsysRan breadcrumbs
  srClearBC(px4CtrlQGCGPS_DW.EnabledSubsystem_SubsysRanBC_b);

  // MATLABSystem: '<S4>/SourceBlock'
  b_varargout_1 = uORB_read_step(px4CtrlQGCGPS_DW.obj_l.orbMetadataObj,
    &px4CtrlQGCGPS_DW.obj_l.eventStructObj, &px4CtrlQGCGPS_B.b_varargout_2_m,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S44>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S44>/In1'
    px4CtrlQGCGPS_B.In1_a = px4CtrlQGCGPS_B.b_varargout_2_m;
    srUpdateBC(px4CtrlQGCGPS_DW.EnabledSubsystem_SubsysRanBC_b);
  }

  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'

  // SignalConversion generated from: '<Root>/Bus Selector'
  memcpy(&px4CtrlQGCGPS_B.output[0], &px4CtrlQGCGPS_B.In1_a.output[0], sizeof
         (real32_T) << 4U);

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb_timestamp = px4CtrlQGCGPS_B.In1_a.timestamp;

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb_noutputs = px4CtrlQGCGPS_B.In1_a.noutputs;

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb__padding0[0] = px4CtrlQGCGPS_B.In1_a._padding0[0];
  rtb__padding0[1] = px4CtrlQGCGPS_B.In1_a._padding0[1];
  rtb__padding0[2] = px4CtrlQGCGPS_B.In1_a._padding0[2];
  rtb__padding0[3] = px4CtrlQGCGPS_B.In1_a._padding0[3];

  // Logic: '<S4>/NOT' incorporates:
  //   MATLABSystem: '<S4>/SourceBlock'

  rtb_NOT = !b_varargout_1;
  rtExtModeUpload(1, (real_T)((px4CtrlQGCGPS_M->Timing.clockTick1) * 0.01));

  // Update absolute time
  // The "clockTick1" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.01, which is the step size
  //  of the task. Size of "clockTick1" ensures timer will not overflow during the
  //  application lifespan selected.

  px4CtrlQGCGPS_M->Timing.clockTick1++;
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void px4CtrlQGCGPS_step(int_T tid)
{
  switch (tid) {
   case 0 :
    px4CtrlQGCGPS_step0();
    break;

   case 1 :
    px4CtrlQGCGPS_step1();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void px4CtrlQGCGPS_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  px4CtrlQGCGPS_P.Saturation1_UpperSat_k = rtInf;
  rtmSetTFinal(px4CtrlQGCGPS_M, -1);
  px4CtrlQGCGPS_M->Timing.stepSize0 = 0.005;

  // External mode info
  px4CtrlQGCGPS_M->Sizes.checksums[0] = (2661919328U);
  px4CtrlQGCGPS_M->Sizes.checksums[1] = (2081695294U);
  px4CtrlQGCGPS_M->Sizes.checksums[2] = (1665006267U);
  px4CtrlQGCGPS_M->Sizes.checksums[3] = (3051797346U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[31];
    px4CtrlQGCGPS_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&px4CtrlQGCGPS_DW.Subsystem_SubsysRanBC_k;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)&px4CtrlQGCGPS_DW.Subsystem_SubsysRanBC_m;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)&px4CtrlQGCGPS_DW.Subsystem_SubsysRanBC;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = (sysRanDType *)
      &px4CtrlQGCGPS_DW.EnabledSubsystem_SubsysRanBC_b;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = (sysRanDType *)
      &px4CtrlQGCGPS_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = (sysRanDType *)
      &px4CtrlQGCGPS_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &px4CtrlQGCGPS_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &px4CtrlQGCGPS_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[28] = (sysRanDType *)&px4CtrlQGCGPS_DW.Subsystem1_SubsysRanBC;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(px4CtrlQGCGPS_M->extModeInfo,
      &px4CtrlQGCGPS_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(px4CtrlQGCGPS_M->extModeInfo,
                        px4CtrlQGCGPS_M->Sizes.checksums);
    rteiSetTPtr(px4CtrlQGCGPS_M->extModeInfo, rtmGetTPtr(px4CtrlQGCGPS_M));
  }

  // block I/O
  (void) memset((static_cast<void *>(&px4CtrlQGCGPS_B)), 0,
                sizeof(B_px4CtrlQGCGPS_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&px4CtrlQGCGPS_DW), 0,
                sizeof(DW_px4CtrlQGCGPS_T));

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    px4CtrlQGCGPS_M->SpecialInfo.mappingInfo = (&dtInfo);
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

    // Start for DataStoreMemory: '<S37>/Data Store Memory'
    px4CtrlQGCGPS_DW.start_time_yaw =
      px4CtrlQGCGPS_P.DataStoreMemory_InitialValue;

    // Start for DataStoreMemory: '<S19>/Data Store Memory'
    px4CtrlQGCGPS_DW.start_time = px4CtrlQGCGPS_P.DataStoreMemory_InitialValue_l;

    // Start for DataStoreMemory: '<S28>/Data Store Memory'
    px4CtrlQGCGPS_DW.start_time_roll =
      px4CtrlQGCGPS_P.DataStoreMemory_InitialValue_b;

    // Start for Sum: '<S18>/Add' incorporates:
    //   DataStoreMemory: '<S1>/e_pitch'

    px4CtrlQGCGPS_DW.e_pitch = px4CtrlQGCGPS_P.e_pitch_InitialValue;

    // Start for Sum: '<S27>/Add' incorporates:
    //   DataStoreMemory: '<S1>/e_pitch1'

    px4CtrlQGCGPS_DW.e_pitch_roll = px4CtrlQGCGPS_P.e_pitch1_InitialValue;

    // Start for Sum: '<S36>/Add' incorporates:
    //   DataStoreMemory: '<S1>/e_pitch2'

    px4CtrlQGCGPS_DW.e_pitch_yaw = px4CtrlQGCGPS_P.e_pitch2_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory'
    px4CtrlQGCGPS_DW.attitude_flag =
      px4CtrlQGCGPS_P.DataStoreMemory_InitialValue_j;

    // Start for DataStoreMemory: '<Root>/Data Store Memory1'
    px4CtrlQGCGPS_DW.armed = px4CtrlQGCGPS_P.DataStoreMemory1_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory16'
    px4CtrlQGCGPS_DW.yaw_speed = px4CtrlQGCGPS_P.DataStoreMemory16_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory17'
    px4CtrlQGCGPS_DW.roll_speed = px4CtrlQGCGPS_P.DataStoreMemory17_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory18'
    px4CtrlQGCGPS_DW.pitch_speed =
      px4CtrlQGCGPS_P.DataStoreMemory18_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory19'
    px4CtrlQGCGPS_DW.pitch_acc = px4CtrlQGCGPS_P.DataStoreMemory19_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory20'
    px4CtrlQGCGPS_DW.roll_acc = px4CtrlQGCGPS_P.DataStoreMemory20_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory21'
    px4CtrlQGCGPS_DW.yaw_acc = px4CtrlQGCGPS_P.DataStoreMemory21_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory28'
    px4CtrlQGCGPS_DW.lat = px4CtrlQGCGPS_P.DataStoreMemory28_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory29'
    px4CtrlQGCGPS_DW.t = px4CtrlQGCGPS_P.DataStoreMemory29_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory30'
    px4CtrlQGCGPS_DW.observer_flag =
      px4CtrlQGCGPS_P.DataStoreMemory30_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory31'
    px4CtrlQGCGPS_DW.lon = px4CtrlQGCGPS_P.DataStoreMemory31_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory32'
    px4CtrlQGCGPS_DW.alt = px4CtrlQGCGPS_P.DataStoreMemory32_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory4'
    px4CtrlQGCGPS_DW.pitch = px4CtrlQGCGPS_P.DataStoreMemory4_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory6'
    px4CtrlQGCGPS_DW.roll = px4CtrlQGCGPS_P.DataStoreMemory6_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory8'
    px4CtrlQGCGPS_DW.yaw = px4CtrlQGCGPS_P.DataStoreMemory8_InitialValue;
    px4CtrlQGCGPS_PrevZCX.Subsystem_Trig_ZCE_e = POS_ZCSIG;
    px4CtrlQGCGPS_PrevZCX.Subsystem_Trig_ZCE_j = POS_ZCSIG;
    px4CtrlQGCGPS_PrevZCX.Subsystem_Trig_ZCE = POS_ZCSIG;

    // InitializeConditions for UnitDelay: '<S35>/UD'
    //
    //  Block description for '<S35>/UD':
    //
    //   Store in Global RAM

    px4CtrlQGCGPS_DW.UD_DSTATE = px4CtrlQGCGPS_P.DiscreteDerivative1_ICPrevScale;

    // InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator3' 
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator3_DSTATE =
      px4CtrlQGCGPS_P.DiscreteTimeIntegrator3_IC;

    // InitializeConditions for UnitDelay: '<S17>/UD'
    //
    //  Block description for '<S17>/UD':
    //
    //   Store in Global RAM

    px4CtrlQGCGPS_DW.UD_DSTATE_b =
      px4CtrlQGCGPS_P.DiscreteDerivative1_ICPrevSca_o;

    // InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator3' 
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator3_DSTAT_a =
      px4CtrlQGCGPS_P.DiscreteTimeIntegrator3_IC_k;

    // InitializeConditions for UnitDelay: '<S26>/UD'
    //
    //  Block description for '<S26>/UD':
    //
    //   Store in Global RAM

    px4CtrlQGCGPS_DW.UD_DSTATE_n =
      px4CtrlQGCGPS_P.DiscreteDerivative1_ICPrevSca_d;

    // InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator3' 
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator3_DSTAT_m =
      px4CtrlQGCGPS_P.DiscreteTimeIntegrator3_IC_l;

    // InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' 
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator_DSTATE =
      px4CtrlQGCGPS_P.DiscreteTimeIntegrator_IC_l;

    // InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator1' 
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator1_DSTATE =
      px4CtrlQGCGPS_P.DiscreteTimeIntegrator1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' 
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator_DSTATE_p =
      px4CtrlQGCGPS_P.DiscreteTimeIntegrator_IC_h;

    // InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' 
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator1_DSTAT_i =
      px4CtrlQGCGPS_P.DiscreteTimeIntegrator1_IC_j;

    // InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' 
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator_DSTATE_f =
      px4CtrlQGCGPS_P.DiscreteTimeIntegrator_IC_o;

    // InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' 
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator1_DSTAT_g =
      px4CtrlQGCGPS_P.DiscreteTimeIntegrator1_IC_c;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_dX'
    px4CtrlQGCGPS_DW.Intgrt_dX_DSTATE = px4CtrlQGCGPS_P.Intgrt_dX_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_dY'
    px4CtrlQGCGPS_DW.Intgrt_dY_DSTATE = px4CtrlQGCGPS_P.Intgrt_dY_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_ddY'
    px4CtrlQGCGPS_DW.Intgrt_ddY_DSTATE = px4CtrlQGCGPS_P.Intgrt_ddY_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_ddX'
    px4CtrlQGCGPS_DW.Intgrt_ddX_DSTATE = px4CtrlQGCGPS_P.Intgrt_ddX_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_dZ'
    px4CtrlQGCGPS_DW.Intgrt_dZ_DSTATE = px4CtrlQGCGPS_P.Intgrt_dZ_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_ddZ'
    px4CtrlQGCGPS_DW.Intgrt_ddZ_DSTATE = px4CtrlQGCGPS_P.Intgrt_ddZ_IC;

    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S44>/In1' incorporates:
    //   Outport: '<S44>/Out1'

    px4CtrlQGCGPS_B.In1_a = px4CtrlQGCGPS_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S45>/In1' incorporates:
    //   Outport: '<S45>/Out1'

    px4CtrlQGCGPS_B.In1 = px4CtrlQGCGPS_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1'
    // InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' 
    px4CtrlQGCGPS_DW.DiscreteTimeIntegrator_DSTAT_fj =
      px4CtrlQGCGPS_P.DiscreteTimeIntegrator_IC;

    // End of SystemInitialize for SubSystem: '<Root>/Subsystem1'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    px4CtrlQGCGPS_DW.obj_n.matlabCodegenIsDeleted = false;
    px4CtrlQGCGPS_DW.obj_n.isSetupComplete = false;
    px4CtrlQGCGPS_DW.obj_n.isInitialized = 1;
    px4CtrlQGCGPS_DW.obj_n.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(px4CtrlQGCGPS_DW.obj_n.orbMetadataObj,
                         &px4CtrlQGCGPS_DW.obj_n.eventStructObj);
    px4CtrlQGCGPS_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
    //   Constant: '<Root>/Constant2'

    px4CtrlQGCGPS_DW.obj.errorStatus = 0U;
    px4CtrlQGCGPS_DW.obj.isInitialized = 0;
    px4CtrlQGCGPS_DW.obj.matlabCodegenIsDeleted = false;
    px4CtrlQGCGPS_SystemCore_setup(&px4CtrlQGCGPS_DW.obj, rtb_DataStoreRead6,
      px4CtrlQGCGPS_P.Constant2_Value_kf);

    // Start for MATLABSystem: '<S4>/SourceBlock'
    px4CtrlQGCGPS_DW.obj_l.matlabCodegenIsDeleted = false;
    px4CtrlQGCGPS_DW.obj_l.isSetupComplete = false;
    px4CtrlQGCGPS_DW.obj_l.isInitialized = 1;
    px4CtrlQGCGPS_DW.obj_l.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_read_initialize(px4CtrlQGCGPS_DW.obj_l.orbMetadataObj,
                         &px4CtrlQGCGPS_DW.obj_l.eventStructObj);
    px4CtrlQGCGPS_DW.obj_l.isSetupComplete = true;

    // Enable for Sin: '<Root>/Sine Wave'
    px4CtrlQGCGPS_DW.systemEnable = 1;
  }
}

// Model terminate function
void px4CtrlQGCGPS_terminate(void)
{
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!px4CtrlQGCGPS_DW.obj_n.matlabCodegenIsDeleted) {
    px4CtrlQGCGPS_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((px4CtrlQGCGPS_DW.obj_n.isInitialized == 1) &&
        px4CtrlQGCGPS_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&px4CtrlQGCGPS_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'

  // Terminate for MATLABSystem: '<Root>/PX4 PWM Output1'
  if (!px4CtrlQGCGPS_DW.obj.matlabCodegenIsDeleted) {
    px4CtrlQGCGPS_DW.obj.matlabCodegenIsDeleted = true;
    if ((px4CtrlQGCGPS_DW.obj.isInitialized == 1) &&
        px4CtrlQGCGPS_DW.obj.isSetupComplete) {
      uint16_T status;
      status = pwm_disarm(&px4CtrlQGCGPS_DW.obj.pwmDevHandler,
                          &px4CtrlQGCGPS_DW.obj.armAdvertiseObj);
      px4CtrlQGCGPS_DW.obj.errorStatus = static_cast<uint16_T>
        (px4CtrlQGCGPS_DW.obj.errorStatus | status);
      status = pwm_resetServo(&px4CtrlQGCGPS_DW.obj.pwmDevHandler,
        px4CtrlQGCGPS_DW.obj.servoCount, px4CtrlQGCGPS_DW.obj.channelMask,
        px4CtrlQGCGPS_DW.obj.isMain, &px4CtrlQGCGPS_DW.obj.actuatorAdvertiseObj);
      px4CtrlQGCGPS_DW.obj.errorStatus = static_cast<uint16_T>
        (px4CtrlQGCGPS_DW.obj.errorStatus | status);
      status = pwm_close(&px4CtrlQGCGPS_DW.obj.pwmDevHandler,
                         &px4CtrlQGCGPS_DW.obj.actuatorAdvertiseObj,
                         &px4CtrlQGCGPS_DW.obj.armAdvertiseObj);
      px4CtrlQGCGPS_DW.obj.errorStatus = static_cast<uint16_T>
        (px4CtrlQGCGPS_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 PWM Output1'

  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!px4CtrlQGCGPS_DW.obj_l.matlabCodegenIsDeleted) {
    px4CtrlQGCGPS_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((px4CtrlQGCGPS_DW.obj_l.isInitialized == 1) &&
        px4CtrlQGCGPS_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&px4CtrlQGCGPS_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
