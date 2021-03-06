//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4_noGPS.cpp
//
// Code generated for Simulink model 'px4_noGPS'.
//
// Model version                  : 5.147
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Mar 19 20:52:24 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "px4_noGPS.h"
#include "rtwtypes.h"
#include "px4_noGPS_types.h"
#include "px4_noGPS_private.h"
#include <math.h>

extern "C" {

#include "rt_nonfinite.h"

}
#include <string.h>
#include "rt_defines.h"
#include "zero_crossing_types.h"
#include "px4_noGPS_dt.h"

// Block signals (default storage)
B_px4_noGPS_T px4_noGPS_B;

// Block states (default storage)
DW_px4_noGPS_T px4_noGPS_DW;

// Previous zero-crossings (trigger) states
PrevZCX_px4_noGPS_T px4_noGPS_PrevZCX;

// Real-time model
RT_MODEL_px4_noGPS_T px4_noGPS_M_ = RT_MODEL_px4_noGPS_T();
RT_MODEL_px4_noGPS_T *const px4_noGPS_M = &px4_noGPS_M_;

// Forward declaration for local functions
static void px4_noGPS_SystemCore_setup(px4_internal_block_PWM_px4_no_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void px4_noGPS_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(px4_noGPS_M, 1));
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

  (px4_noGPS_M->Timing.TaskCounters.TID[1])++;
  if ((px4_noGPS_M->Timing.TaskCounters.TID[1]) > 1) {// Sample time: [0.01s, 0.0s] 
    px4_noGPS_M->Timing.TaskCounters.TID[1] = 0;
  }
}

//
// Output and update for atomic system:
//    '<S25>/MATLAB Function'
//    '<S34>/MATLAB Function'
//    '<S43>/MATLAB Function'
//
void px4_noGPS_MATLABFunction(boolean_T rtu_e, real_T rtu_t, real_T rtu_s_t,
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

//
// Output and update for atomic system:
//    '<Root>/MATLAB Function1'
//    '<Root>/MATLAB Function5'
//
void px4_noGPS_MATLABFunction1(real_T rtu_phi, real_T rtu_theta, real_T rtu_psi,
  real_T rtu_u, real_T *rty_dd_x, real_T *rty_dd_y, real_T *rty_dd_z)
{
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  tmp = sin(rtu_psi);
  tmp_0 = sin(rtu_phi);
  tmp_1 = cos(rtu_psi);
  tmp_2 = cos(rtu_phi);
  *rty_dd_x = (tmp_2 * sin(rtu_theta) * tmp_1 + tmp_0 * tmp) * -rtu_u;
  *rty_dd_y = (cos(rtu_phi) * sin(rtu_theta) * tmp - tmp_0 * tmp_1) * -rtu_u;
  *rty_dd_z = -rtu_u * cos(rtu_theta) * tmp_2 + 9.8;
}

//
// Output and update for atomic system:
//    '<Root>/MATLAB Function6'
//    '<Root>/MATLAB Function7'
//
void px4_noGPS_MATLABFunction6(real_T rtu_q_x, real_T rtu_q_y, real_T rtu_q_z,
  real_T *rty_u)
{
  *rty_u = sqrt((rtu_q_x * rtu_q_x + rtu_q_y * rtu_q_y) + (rtu_q_z + 9.8) *
                (rtu_q_z + 9.8));
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

static void px4_noGPS_SystemCore_setup(px4_internal_block_PWM_px4_no_T *obj,
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
void px4_noGPS_step0(void)             // Sample time: [0.005s, 0.0s]
{
  real_T roll_tmp;
  uint16_T status;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_g2;
  boolean_T rtb_Compare_i;
  boolean_T rtb_LogicalOperator;

  {                                    // Sample time: [0.005s, 0.0s]
    rate_monotonic_scheduler();
  }

  // Reset subsysRan breadcrumbs
  srClearBC(px4_noGPS_DW.Subsystem_SubsysRanBC_k);

  // Reset subsysRan breadcrumbs
  srClearBC(px4_noGPS_DW.Subsystem_SubsysRanBC_m);

  // Reset subsysRan breadcrumbs
  srClearBC(px4_noGPS_DW.Subsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px4_noGPS_DW.EnabledSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px4_noGPS_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px4_noGPS_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px4_noGPS_DW.IfActionSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(px4_noGPS_DW.Subsystem1_SubsysRanBC);

  // Switch: '<S19>/Switch' incorporates:
  //   Constant: '<S19>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read20'
  //   DataStoreRead: '<S19>/Data Store Read'
  //   DataStoreRead: '<S19>/Data Store Read1'

  if (px4_noGPS_DW.attitude_flag) {
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_DW.yaw;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = 0.0;
    px4_noGPS_B.rtb_u_f_c = px4_noGPS_DW.yaw_speed;
  } else {
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_P.Constant1_Value_a;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_P.Constant1_Value_a;
    px4_noGPS_B.rtb_u_f_c = px4_noGPS_P.Constant1_Value_a;
  }

  // End of Switch: '<S19>/Switch'

  // RelationalOperator: '<S44>/Compare' incorporates:
  //   Abs: '<S43>/Abs'
  //   Constant: '<S44>/Constant'
  //   DataStoreRead: '<S43>/Data Store Read1'

  rtb_Compare = (fabs(px4_noGPS_DW.e_pitch_yaw) >=
                 px4_noGPS_P.CompareToConstant1_const);

  // Sum: '<S43>/Add' incorporates:
  //   DataStoreRead: '<S43>/Data Store Read'
  //   DataStoreRead: '<S43>/Data Store Read3'
  //   Sum: '<S46>/Add'

  px4_noGPS_B.rtb_Fcn_tmp = px4_noGPS_DW.t - px4_noGPS_DW.start_time_yaw;

  // Fcn: '<S43>/Fcn' incorporates:
  //   Constant: '<S43>/T'
  //   Constant: '<S43>/ch'
  //   Sum: '<S43>/Add'

  px4_noGPS_B.rtb_Fcn_g = px4_noGPS_P.ch_Value / (px4_noGPS_P.T_Value -
    px4_noGPS_B.rtb_Fcn_tmp);

  // MATLAB Function: '<S43>/MATLAB Function' incorporates:
  //   Constant: '<S43>/t'
  //   DataStoreRead: '<S43>/Data Store Read'
  //   DataStoreRead: '<S43>/Data Store Read3'

  px4_noGPS_MATLABFunction(rtb_Compare, px4_noGPS_DW.t,
    px4_noGPS_DW.start_time_yaw, px4_noGPS_B.rtb_Fcn_g, px4_noGPS_P.t_Value,
    &px4_noGPS_B.y);

  // Sum: '<S43>/Add1' incorporates:
  //   Constant: '<S43>/r'

  px4_noGPS_B.z2 = px4_noGPS_P.r_Value + px4_noGPS_B.y;

  // Sum: '<S42>/Add' incorporates:
  //   Sum: '<S19>/Add2'

  px4_noGPS_DW.e_pitch_yaw = px4_noGPS_B.rtb_DataTypeConversion3_idx_0 -
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1;

  // Gain: '<S42>/Gain4' incorporates:
  //   Constant: '<S19>/b'
  //   Product: '<S42>/Product'
  //   Sum: '<S42>/Add'

  px4_noGPS_B.roll_hat = px4_noGPS_DW.e_pitch_yaw * px4_noGPS_B.z2 *
    px4_noGPS_P.b_Value * px4_noGPS_P.Gain4_Gain;

  // SampleTimeMath: '<S41>/TSamp'
  //
  //  About '<S41>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS_B.TSamp = px4_noGPS_B.roll_hat * px4_noGPS_P.TSamp_WtEt;

  // Sum: '<S19>/Add1'
  px4_noGPS_B.roll_hat = px4_noGPS_B.rtb_u_f_c - px4_noGPS_B.roll_hat;

  // Gain: '<S1>/Gain1' incorporates:
  //   DiscreteIntegrator: '<S22>/Discrete-Time Integrator3'

  px4_noGPS_B.TSamp_kj = px4_noGPS_P.Gain1_Gain_o *
    px4_noGPS_DW.DiscreteTimeIntegrator3_DSTATE;

  // Signum: '<S19>/Sign'
  if (rtIsNaN(px4_noGPS_B.roll_hat)) {
    px4_noGPS_B.Add2_g = px4_noGPS_B.roll_hat;
  } else if (px4_noGPS_B.roll_hat < 0.0) {
    px4_noGPS_B.Add2_g = -1.0;
  } else {
    px4_noGPS_B.Add2_g = (px4_noGPS_B.roll_hat > 0.0);
  }

  // End of Signum: '<S19>/Sign'

  // Saturate: '<S1>/Saturation4'
  if (px4_noGPS_B.TSamp_kj > px4_noGPS_P.Saturation4_UpperSat) {
    px4_noGPS_B.TSamp_kj = px4_noGPS_P.Saturation4_UpperSat;
  } else if (px4_noGPS_B.TSamp_kj < px4_noGPS_P.Saturation4_LowerSat) {
    px4_noGPS_B.TSamp_kj = px4_noGPS_P.Saturation4_LowerSat;
  }

  // End of Saturate: '<S1>/Saturation4'

  // Sum: '<S1>/Add3' incorporates:
  //   Constant: '<S19>/b'
  //   Constant: '<S19>/l'
  //   DataStoreWrite: '<S19>/Data Store Write'
  //   Gain: '<S19>/Gain'
  //   Gain: '<S19>/Gain1'
  //   Product: '<S19>/Product'
  //   Product: '<S19>/Product1'
  //   Sum: '<S19>/Add'
  //   Sum: '<S41>/Diff'
  //   UnitDelay: '<S41>/UD'
  //
  //  Block description for '<S41>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S41>/UD':
  //
  //   Store in Global RAM

  px4_noGPS_B.Add3 = (((((px4_noGPS_B.TSamp - px4_noGPS_DW.UD_DSTATE) -
    px4_noGPS_DW.e_pitch_yaw) - px4_noGPS_B.roll_hat * px4_noGPS_B.z2 *
                        px4_noGPS_P.b_Value) - px4_noGPS_B.Add2_g *
                       px4_noGPS_P.l_Value) - px4_noGPS_P.Gain_Gain *
                      px4_noGPS_B.rtb_u_f_c) * px4_noGPS_P.Gain1_Gain -
    px4_noGPS_B.TSamp_kj;

  // ManualSwitch: '<S1>/Manual Switch' incorporates:
  //   Constant: '<S1>/Constant'
  //   DataStoreWrite: '<Root>/Data Store Write11'

  if (px4_noGPS_P.ManualSwitch_CurrentSetting == 1) {
    // Saturate: '<S1>/Saturation'
    if (px4_noGPS_B.Add3 > px4_noGPS_P.Saturation_UpperSat) {
      px4_noGPS_B.DataStoreRead27 = px4_noGPS_P.Saturation_UpperSat;
    } else if (px4_noGPS_B.Add3 < px4_noGPS_P.Saturation_LowerSat) {
      px4_noGPS_B.DataStoreRead27 = px4_noGPS_P.Saturation_LowerSat;
    } else {
      px4_noGPS_B.DataStoreRead27 = px4_noGPS_B.Add3;
    }

    // End of Saturate: '<S1>/Saturation'
  } else {
    px4_noGPS_B.DataStoreRead27 = px4_noGPS_P.Constant_Value_b;
  }

  // End of ManualSwitch: '<S1>/Manual Switch'

  // Switch: '<S17>/Switch' incorporates:
  //   Constant: '<S17>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read14'
  //   DataStoreRead: '<Root>/Data Store Read69'
  //   DataStoreRead: '<S17>/Data Store Read'
  //   DataStoreRead: '<S17>/Data Store Read1'

  if (px4_noGPS_DW.attitude_flag) {
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_DW.pitch;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_DW.pitch_desire;
    px4_noGPS_B.rtb_u_f_c = px4_noGPS_DW.pitch_speed;
  } else {
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_P.Constant1_Value;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_P.Constant1_Value;
    px4_noGPS_B.rtb_u_f_c = px4_noGPS_P.Constant1_Value;
  }

  // End of Switch: '<S17>/Switch'

  // RelationalOperator: '<S26>/Compare' incorporates:
  //   Abs: '<S25>/Abs'
  //   Constant: '<S26>/Constant'
  //   DataStoreRead: '<S25>/Data Store Read1'

  rtb_Compare_i = (fabs(px4_noGPS_DW.e_pitch) >=
                   px4_noGPS_P.CompareToConstant1_const_b);

  // Sum: '<S25>/Add' incorporates:
  //   DataStoreRead: '<S25>/Data Store Read'
  //   DataStoreRead: '<S25>/Data Store Read3'
  //   Sum: '<S28>/Add'

  px4_noGPS_B.Product3 = px4_noGPS_DW.t - px4_noGPS_DW.start_time;

  // Fcn: '<S25>/Fcn' incorporates:
  //   Constant: '<S25>/T'
  //   Constant: '<S25>/ch'
  //   Sum: '<S25>/Add'

  px4_noGPS_B.rtb_Fcn_b_g = px4_noGPS_P.ch_Value_j / (px4_noGPS_P.T_Value_p -
    px4_noGPS_B.Product3);

  // MATLAB Function: '<S25>/MATLAB Function' incorporates:
  //   Constant: '<S25>/t'
  //   DataStoreRead: '<S25>/Data Store Read'
  //   DataStoreRead: '<S25>/Data Store Read3'

  px4_noGPS_MATLABFunction(rtb_Compare_i, px4_noGPS_DW.t,
    px4_noGPS_DW.start_time, px4_noGPS_B.rtb_Fcn_b_g, px4_noGPS_P.t_Value_n,
    &px4_noGPS_B.y_j);

  // Sum: '<S25>/Add1' incorporates:
  //   Constant: '<S25>/r'

  px4_noGPS_B.z2_e = px4_noGPS_P.r_Value_g + px4_noGPS_B.y_j;

  // Sum: '<S24>/Add' incorporates:
  //   Sum: '<S17>/Add2'

  px4_noGPS_DW.e_pitch = px4_noGPS_B.rtb_DataTypeConversion3_idx_0 -
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1;

  // Gain: '<S24>/Gain4' incorporates:
  //   Constant: '<S17>/b'
  //   Product: '<S24>/Product'
  //   Sum: '<S24>/Add'

  px4_noGPS_B.roll_hat = px4_noGPS_DW.e_pitch * px4_noGPS_B.z2_e *
    px4_noGPS_P.b_Value_l * px4_noGPS_P.Gain4_Gain_b;

  // SampleTimeMath: '<S23>/TSamp'
  //
  //  About '<S23>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS_B.z2 = px4_noGPS_B.roll_hat * px4_noGPS_P.TSamp_WtEt_p;

  // Sum: '<S17>/Add1'
  px4_noGPS_B.roll_hat = px4_noGPS_B.rtb_u_f_c - px4_noGPS_B.roll_hat;

  // Gain: '<S1>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S20>/Discrete-Time Integrator3'

  px4_noGPS_B.Gain2 = px4_noGPS_P.Gain2_Gain *
    px4_noGPS_DW.DiscreteTimeIntegrator3_DSTAT_a;

  // Signum: '<S17>/Sign'
  if (rtIsNaN(px4_noGPS_B.roll_hat)) {
    px4_noGPS_B.Add2_g = px4_noGPS_B.roll_hat;
  } else if (px4_noGPS_B.roll_hat < 0.0) {
    px4_noGPS_B.Add2_g = -1.0;
  } else {
    px4_noGPS_B.Add2_g = (px4_noGPS_B.roll_hat > 0.0);
  }

  // End of Signum: '<S17>/Sign'

  // Sum: '<S1>/Add2' incorporates:
  //   Constant: '<S17>/b'
  //   Constant: '<S17>/l'
  //   DataStoreWrite: '<Root>/Data Store Write12'
  //   DataStoreWrite: '<S17>/Data Store Write'
  //   Gain: '<S17>/Gain'
  //   Gain: '<S17>/Gain1'
  //   Product: '<S17>/Product'
  //   Product: '<S17>/Product1'
  //   Sum: '<S17>/Add'
  //   Sum: '<S23>/Diff'
  //   UnitDelay: '<S23>/UD'
  //
  //  Block description for '<S23>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S23>/UD':
  //
  //   Store in Global RAM

  px4_noGPS_B.DataStoreRead25 = (((((px4_noGPS_B.z2 - px4_noGPS_DW.UD_DSTATE_b)
    - px4_noGPS_DW.e_pitch) - px4_noGPS_B.roll_hat * px4_noGPS_B.z2_e *
    px4_noGPS_P.b_Value_l) - px4_noGPS_B.Add2_g * px4_noGPS_P.l_Value_b) -
    px4_noGPS_P.Gain_Gain_o * px4_noGPS_B.rtb_u_f_c) * px4_noGPS_P.Gain1_Gain_b
    - px4_noGPS_B.Gain2;

  // Switch: '<S18>/Switch' incorporates:
  //   Constant: '<S18>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read18'
  //   DataStoreRead: '<Root>/Data Store Read68'
  //   DataStoreRead: '<S18>/Data Store Read'
  //   DataStoreRead: '<S18>/Data Store Read1'

  if (px4_noGPS_DW.attitude_flag) {
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_DW.roll;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_DW.roll_desire;
    px4_noGPS_B.rtb_u_f_c = px4_noGPS_DW.roll_speed;
  } else {
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_P.Constant1_Value_n;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_P.Constant1_Value_n;
    px4_noGPS_B.rtb_u_f_c = px4_noGPS_P.Constant1_Value_n;
  }

  // End of Switch: '<S18>/Switch'

  // RelationalOperator: '<S35>/Compare' incorporates:
  //   Abs: '<S34>/Abs'
  //   Constant: '<S35>/Constant'
  //   DataStoreRead: '<S34>/Data Store Read1'

  rtb_Compare_g2 = (fabs(px4_noGPS_DW.e_pitch_roll) >=
                    px4_noGPS_P.CompareToConstant1_const_h);

  // Sum: '<S34>/Add' incorporates:
  //   DataStoreRead: '<S34>/Data Store Read'
  //   DataStoreRead: '<S34>/Data Store Read3'
  //   Sum: '<S37>/Add'

  px4_noGPS_B.Product6 = px4_noGPS_DW.t - px4_noGPS_DW.start_time_roll;

  // Fcn: '<S34>/Fcn' incorporates:
  //   Constant: '<S34>/T'
  //   Constant: '<S34>/ch'
  //   Sum: '<S34>/Add'

  px4_noGPS_B.rtb_Fcn_a_f = px4_noGPS_P.ch_Value_e / (px4_noGPS_P.T_Value_c -
    px4_noGPS_B.Product6);

  // MATLAB Function: '<S34>/MATLAB Function' incorporates:
  //   Constant: '<S34>/t'
  //   DataStoreRead: '<S34>/Data Store Read'
  //   DataStoreRead: '<S34>/Data Store Read3'

  px4_noGPS_MATLABFunction(rtb_Compare_g2, px4_noGPS_DW.t,
    px4_noGPS_DW.start_time_roll, px4_noGPS_B.rtb_Fcn_a_f, px4_noGPS_P.t_Value_m,
    &px4_noGPS_B.y_o);

  // Sum: '<S34>/Add1' incorporates:
  //   Constant: '<S34>/r'

  px4_noGPS_B.z2_l = px4_noGPS_P.r_Value_p + px4_noGPS_B.y_o;

  // Sum: '<S33>/Add' incorporates:
  //   Sum: '<S18>/Add2'

  px4_noGPS_DW.e_pitch_roll = px4_noGPS_B.rtb_DataTypeConversion3_idx_0 -
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1;

  // Gain: '<S33>/Gain4' incorporates:
  //   Constant: '<S18>/b'
  //   Product: '<S33>/Product'
  //   Sum: '<S33>/Add'

  px4_noGPS_B.roll_hat = px4_noGPS_DW.e_pitch_roll * px4_noGPS_B.z2_l *
    px4_noGPS_P.b_Value_h * px4_noGPS_P.Gain4_Gain_o;

  // SampleTimeMath: '<S32>/TSamp'
  //
  //  About '<S32>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS_B.z2_e = px4_noGPS_B.roll_hat * px4_noGPS_P.TSamp_WtEt_o;

  // Sum: '<S18>/Add1'
  px4_noGPS_B.roll_hat = px4_noGPS_B.rtb_u_f_c - px4_noGPS_B.roll_hat;

  // Gain: '<S1>/J' incorporates:
  //   DiscreteIntegrator: '<S21>/Discrete-Time Integrator3'

  px4_noGPS_B.J = px4_noGPS_P.J_Gain_b *
    px4_noGPS_DW.DiscreteTimeIntegrator3_DSTAT_m;

  // Signum: '<S18>/Sign'
  if (rtIsNaN(px4_noGPS_B.roll_hat)) {
    px4_noGPS_B.Add2_g = px4_noGPS_B.roll_hat;
  } else if (px4_noGPS_B.roll_hat < 0.0) {
    px4_noGPS_B.Add2_g = -1.0;
  } else {
    px4_noGPS_B.Add2_g = (px4_noGPS_B.roll_hat > 0.0);
  }

  // End of Signum: '<S18>/Sign'

  // Sum: '<S1>/Add1' incorporates:
  //   Constant: '<S18>/b'
  //   Constant: '<S18>/l'
  //   DataStoreWrite: '<Root>/Data Store Write13'
  //   DataStoreWrite: '<S18>/Data Store Write'
  //   Gain: '<S18>/Gain'
  //   Gain: '<S18>/J'
  //   Product: '<S18>/Product'
  //   Product: '<S18>/Product1'
  //   Sum: '<S18>/Add'
  //   Sum: '<S32>/Diff'
  //   UnitDelay: '<S32>/UD'
  //
  //  Block description for '<S32>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S32>/UD':
  //
  //   Store in Global RAM

  px4_noGPS_B.DataStoreRead26 = (((((px4_noGPS_B.z2_e - px4_noGPS_DW.UD_DSTATE_n)
    - px4_noGPS_DW.e_pitch_roll) - px4_noGPS_B.roll_hat * px4_noGPS_B.z2_l *
    px4_noGPS_P.b_Value_h) - px4_noGPS_B.Add2_g * px4_noGPS_P.l_Value_n) -
    px4_noGPS_P.Gain_Gain_m * px4_noGPS_B.rtb_u_f_c) * px4_noGPS_P.J_Gain -
    px4_noGPS_B.J;

  // DataStoreRead: '<S43>/Data Store Read4'
  px4_noGPS_B.DataStoreRead4 = px4_noGPS_DW.start_time_yaw;

  // Logic: '<S46>/Logical Operator' incorporates:
  //   Abs: '<S46>/Abs1'
  //   Constant: '<S47>/Constant'
  //   Constant: '<S48>/Constant'
  //   DataStoreRead: '<S46>/Data Store Read2'
  //   RelationalOperator: '<S47>/Compare'
  //   RelationalOperator: '<S48>/Compare'

  rtb_LogicalOperator = ((fabs(px4_noGPS_DW.e_pitch_yaw) >=
    px4_noGPS_P.CompareToConstant2_const) && (px4_noGPS_B.rtb_Fcn_tmp >=
    px4_noGPS_P.CompareToConstant1_const_hq));

  // Outputs for Triggered SubSystem: '<S46>/Subsystem' incorporates:
  //   TriggerPort: '<S49>/Trigger'

  if (rtb_LogicalOperator && (px4_noGPS_PrevZCX.Subsystem_Trig_ZCE != POS_ZCSIG))
  {
    // DataStoreWrite: '<S49>/Data Store Write' incorporates:
    //   DataStoreRead: '<S49>/Data Store Read2'

    px4_noGPS_DW.start_time_yaw = px4_noGPS_DW.t;
    px4_noGPS_DW.Subsystem_SubsysRanBC = 4;
  }

  px4_noGPS_PrevZCX.Subsystem_Trig_ZCE = rtb_LogicalOperator;

  // End of Outputs for SubSystem: '<S46>/Subsystem'
  // DataStoreRead: '<S25>/Data Store Read4'
  px4_noGPS_B.DataStoreRead4_g = px4_noGPS_DW.start_time;

  // Logic: '<S28>/Logical Operator' incorporates:
  //   Abs: '<S28>/Abs1'
  //   Constant: '<S29>/Constant'
  //   Constant: '<S30>/Constant'
  //   DataStoreRead: '<S28>/Data Store Read2'
  //   RelationalOperator: '<S29>/Compare'
  //   RelationalOperator: '<S30>/Compare'

  rtb_LogicalOperator = ((fabs(px4_noGPS_DW.e_pitch) >=
    px4_noGPS_P.CompareToConstant2_const_o) && (px4_noGPS_B.Product3 >=
    px4_noGPS_P.CompareToConstant1_const_p));

  // Outputs for Triggered SubSystem: '<S28>/Subsystem' incorporates:
  //   TriggerPort: '<S31>/Trigger'

  if (rtb_LogicalOperator && (px4_noGPS_PrevZCX.Subsystem_Trig_ZCE_e !=
       POS_ZCSIG)) {
    // DataStoreWrite: '<S31>/Data Store Write' incorporates:
    //   DataStoreRead: '<S31>/Data Store Read2'

    px4_noGPS_DW.start_time = px4_noGPS_DW.t;
    px4_noGPS_DW.Subsystem_SubsysRanBC_k = 4;
  }

  px4_noGPS_PrevZCX.Subsystem_Trig_ZCE_e = rtb_LogicalOperator;

  // End of Outputs for SubSystem: '<S28>/Subsystem'
  // DataStoreRead: '<S34>/Data Store Read4'
  px4_noGPS_B.DataStoreRead4_b = px4_noGPS_DW.start_time_roll;

  // Logic: '<S37>/Logical Operator' incorporates:
  //   Abs: '<S37>/Abs1'
  //   Constant: '<S38>/Constant'
  //   Constant: '<S39>/Constant'
  //   DataStoreRead: '<S37>/Data Store Read2'
  //   RelationalOperator: '<S38>/Compare'
  //   RelationalOperator: '<S39>/Compare'

  rtb_LogicalOperator = ((fabs(px4_noGPS_DW.e_pitch_roll) >=
    px4_noGPS_P.CompareToConstant2_const_a) && (px4_noGPS_B.Product6 >=
    px4_noGPS_P.CompareToConstant1_const_a));

  // Outputs for Triggered SubSystem: '<S37>/Subsystem' incorporates:
  //   TriggerPort: '<S40>/Trigger'

  if (rtb_LogicalOperator && (px4_noGPS_PrevZCX.Subsystem_Trig_ZCE_j !=
       POS_ZCSIG)) {
    // DataStoreWrite: '<S40>/Data Store Write' incorporates:
    //   DataStoreRead: '<S40>/Data Store Read2'

    px4_noGPS_DW.start_time_roll = px4_noGPS_DW.t;
    px4_noGPS_DW.Subsystem_SubsysRanBC_m = 4;
  }

  px4_noGPS_PrevZCX.Subsystem_Trig_ZCE_j = rtb_LogicalOperator;

  // End of Outputs for SubSystem: '<S37>/Subsystem'

  // Gain: '<S22>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S22>/Discrete-Time Integrator'

  px4_noGPS_B.rolldegree = px4_noGPS_P.Gain2_Gain_c *
    px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE;

  // ZeroOrderHold: '<S22>/Zero-Order Hold1' incorporates:
  //   DataStoreRead: '<S22>/Data Store Read'

  px4_noGPS_B.rtb_u_f_c = px4_noGPS_DW.yaw;

  // Switch: '<S22>/Switch' incorporates:
  //   Constant: '<S22>/Constant3'
  //   DataStoreRead: '<S22>/Data Store Read1'
  //   DataStoreRead: '<S22>/Data Store Read2'
  //   Gain: '<S22>/1//J'
  //   Gain: '<S22>/k//J'

  if (px4_noGPS_DW.observer_flag) {
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_P.uJ_Gain *
      px4_noGPS_B.Add3;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_P.kJ_Gain *
      px4_noGPS_DW.yaw_speed;
  } else {
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_P.Constant3_Value_d;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_P.Constant3_Value_d;
    px4_noGPS_B.rtb_u_f_c = px4_noGPS_P.Constant3_Value_d;
  }

  // End of Switch: '<S22>/Switch'

  // Sum: '<S22>/Add1' incorporates:
  //   DiscreteIntegrator: '<S22>/Discrete-Time Integrator'

  px4_noGPS_B.rtb_u_f_c -= px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE;

  // Abs: '<S22>/Abs3' incorporates:
  //   Abs: '<S22>/Abs4'
  //   Abs: '<S22>/Abs5'
  //   Abs: '<S22>/Abs6'

  px4_noGPS_B.Add2_b = fabs(px4_noGPS_B.rtb_u_f_c);

  // Saturate: '<S22>/Saturation'
  if (px4_noGPS_B.rtb_u_f_c > px4_noGPS_P.Saturation_UpperSat_b) {
    px4_noGPS_B.rtb_Fcn_tmp = px4_noGPS_P.Saturation_UpperSat_b;
  } else if (px4_noGPS_B.rtb_u_f_c < px4_noGPS_P.Saturation_LowerSat_k) {
    px4_noGPS_B.rtb_Fcn_tmp = px4_noGPS_P.Saturation_LowerSat_k;
  } else {
    px4_noGPS_B.rtb_Fcn_tmp = px4_noGPS_B.rtb_u_f_c;
  }

  // End of Saturate: '<S22>/Saturation'

  // Gain: '<S22>/lambda1'
  px4_noGPS_B.Add3 = px4_noGPS_P.lambda1_Gain * px4_noGPS_B.rtb_u_f_c;

  // Sum: '<S22>/Add7' incorporates:
  //   Constant: '<S22>/Constant1'
  //   Sum: '<S22>/Add13'
  //   Sum: '<S22>/Add18'

  px4_noGPS_B.u0_tmp = px4_noGPS_P.Constant1_Value_f + px4_noGPS_B.rtb_u_f_c;

  // Sum: '<S22>/Add6' incorporates:
  //   Constant: '<S22>/Constant1'
  //   Sum: '<S22>/Add12'
  //   Sum: '<S22>/Add17'

  px4_noGPS_B.lambda4_h = px4_noGPS_B.rtb_u_f_c - px4_noGPS_P.Constant1_Value_f;

  // Saturate: '<S22>/Saturation10' incorporates:
  //   Sum: '<S22>/Add7'

  if (px4_noGPS_B.u0_tmp > px4_noGPS_P.Saturation10_UpperSat) {
    px4_noGPS_B.TSamp_kj = px4_noGPS_P.Saturation10_UpperSat;
  } else if (px4_noGPS_B.u0_tmp < px4_noGPS_P.Saturation10_LowerSat) {
    px4_noGPS_B.TSamp_kj = px4_noGPS_P.Saturation10_LowerSat;
  } else {
    px4_noGPS_B.TSamp_kj = px4_noGPS_B.u0_tmp;
  }

  // End of Saturate: '<S22>/Saturation10'

  // Saturate: '<S22>/Saturation11' incorporates:
  //   Sum: '<S22>/Add6'

  if (px4_noGPS_B.lambda4_h > px4_noGPS_P.Saturation11_UpperSat) {
    px4_noGPS_B.Product6_a = px4_noGPS_P.Saturation11_UpperSat;
  } else if (px4_noGPS_B.lambda4_h < px4_noGPS_P.Saturation11_LowerSat) {
    px4_noGPS_B.Product6_a = px4_noGPS_P.Saturation11_LowerSat;
  } else {
    px4_noGPS_B.Product6_a = px4_noGPS_B.lambda4_h;
  }

  // End of Saturate: '<S22>/Saturation11'

  // Gain: '<S22>/Gain' incorporates:
  //   Sum: '<S22>/Add8'

  px4_noGPS_B.roll_hat_e = (px4_noGPS_B.TSamp_kj - px4_noGPS_B.Product6_a) *
    px4_noGPS_P.Gain_Gain_ml;

  // Fcn: '<S22>/Fcn3' incorporates:
  //   Constant: '<S22>/Constant1'

  if (px4_noGPS_P.Constant1_Value_f < 0.0) {
    px4_noGPS_B.Add2_g = -rt_powd_snf(-px4_noGPS_P.Constant1_Value_f, -0.5);
  } else {
    px4_noGPS_B.Add2_g = rt_powd_snf(px4_noGPS_P.Constant1_Value_f, -0.5);
  }

  // End of Fcn: '<S22>/Fcn3'

  // Product: '<S22>/Product3'
  px4_noGPS_B.Product3 = px4_noGPS_B.Add2_g * px4_noGPS_B.roll_hat_e *
    px4_noGPS_B.rtb_u_f_c;

  // Saturate: '<S22>/Saturation8'
  if (px4_noGPS_B.rtb_u_f_c > px4_noGPS_P.Saturation8_UpperSat) {
    px4_noGPS_B.lambda1_a = px4_noGPS_P.Saturation8_UpperSat;
  } else if (px4_noGPS_B.rtb_u_f_c < px4_noGPS_P.Saturation8_LowerSat) {
    px4_noGPS_B.lambda1_a = px4_noGPS_P.Saturation8_LowerSat;
  } else {
    px4_noGPS_B.lambda1_a = px4_noGPS_B.rtb_u_f_c;
  }

  // End of Saturate: '<S22>/Saturation8'

  // Product: '<S22>/Product4' incorporates:
  //   Abs: '<S22>/Abs3'
  //   Constant: '<S22>/Constant2'
  //   Fcn: '<S22>/Fcn4'
  //   Sum: '<S22>/Add10'

  px4_noGPS_B.roll_hat = rt_powd_snf(px4_noGPS_B.Add2_b, 0.5) *
    px4_noGPS_B.lambda1_a * (px4_noGPS_P.Constant2_Value -
    px4_noGPS_B.roll_hat_e);

  // Saturate: '<S22>/Saturation13'
  if (px4_noGPS_B.u0_tmp > px4_noGPS_P.Saturation13_UpperSat) {
    px4_noGPS_B.TSamp_kj = px4_noGPS_P.Saturation13_UpperSat;
  } else if (px4_noGPS_B.u0_tmp < px4_noGPS_P.Saturation13_LowerSat) {
    px4_noGPS_B.TSamp_kj = px4_noGPS_P.Saturation13_LowerSat;
  } else {
    px4_noGPS_B.TSamp_kj = px4_noGPS_B.u0_tmp;
  }

  // End of Saturate: '<S22>/Saturation13'

  // Saturate: '<S22>/Saturation9'
  if (px4_noGPS_B.lambda4_h > px4_noGPS_P.Saturation9_UpperSat) {
    px4_noGPS_B.Product6_a = px4_noGPS_P.Saturation9_UpperSat;
  } else if (px4_noGPS_B.lambda4_h < px4_noGPS_P.Saturation9_LowerSat) {
    px4_noGPS_B.Product6_a = px4_noGPS_P.Saturation9_LowerSat;
  } else {
    px4_noGPS_B.Product6_a = px4_noGPS_B.lambda4_h;
  }

  // End of Saturate: '<S22>/Saturation9'

  // Gain: '<S22>/Gain1' incorporates:
  //   Sum: '<S22>/Add14'

  px4_noGPS_B.roll_hat_e = (px4_noGPS_B.TSamp_kj - px4_noGPS_B.Product6_a) *
    px4_noGPS_P.Gain1_Gain_a;

  // Fcn: '<S22>/Fcn6' incorporates:
  //   Constant: '<S22>/Constant1'

  if (px4_noGPS_P.Constant1_Value_f < 0.0) {
    px4_noGPS_B.Add2_g = -rt_powd_snf(-px4_noGPS_P.Constant1_Value_f, -0.9375);
  } else {
    px4_noGPS_B.Add2_g = rt_powd_snf(px4_noGPS_P.Constant1_Value_f, -0.9375);
  }

  // End of Fcn: '<S22>/Fcn6'

  // Product: '<S22>/Product6'
  px4_noGPS_B.Product6 = px4_noGPS_B.Add2_g * px4_noGPS_B.roll_hat_e *
    px4_noGPS_B.rtb_u_f_c;

  // Saturate: '<S22>/Saturation12'
  if (px4_noGPS_B.rtb_u_f_c > px4_noGPS_P.Saturation12_UpperSat) {
    px4_noGPS_B.lambda1_a = px4_noGPS_P.Saturation12_UpperSat;
  } else if (px4_noGPS_B.rtb_u_f_c < px4_noGPS_P.Saturation12_LowerSat) {
    px4_noGPS_B.lambda1_a = px4_noGPS_P.Saturation12_LowerSat;
  } else {
    px4_noGPS_B.lambda1_a = px4_noGPS_B.rtb_u_f_c;
  }

  // End of Saturate: '<S22>/Saturation12'

  // Product: '<S22>/Product5' incorporates:
  //   Constant: '<S22>/Constant4'
  //   Fcn: '<S22>/Fcn5'
  //   Sum: '<S22>/Add11'

  px4_noGPS_B.z2_l = rt_powd_snf(px4_noGPS_B.Add2_b, 0.0625) *
    px4_noGPS_B.lambda1_a * (px4_noGPS_P.Constant4_Value -
    px4_noGPS_B.roll_hat_e);

  // Saturate: '<S22>/Saturation16'
  if (px4_noGPS_B.u0_tmp > px4_noGPS_P.Saturation16_UpperSat) {
    px4_noGPS_B.u0_tmp = px4_noGPS_P.Saturation16_UpperSat;
  } else if (px4_noGPS_B.u0_tmp < px4_noGPS_P.Saturation16_LowerSat) {
    px4_noGPS_B.u0_tmp = px4_noGPS_P.Saturation16_LowerSat;
  }

  // End of Saturate: '<S22>/Saturation16'

  // Saturate: '<S22>/Saturation14'
  if (px4_noGPS_B.lambda4_h > px4_noGPS_P.Saturation14_UpperSat) {
    px4_noGPS_B.lambda4_h = px4_noGPS_P.Saturation14_UpperSat;
  } else if (px4_noGPS_B.lambda4_h < px4_noGPS_P.Saturation14_LowerSat) {
    px4_noGPS_B.lambda4_h = px4_noGPS_P.Saturation14_LowerSat;
  }

  // End of Saturate: '<S22>/Saturation14'

  // Gain: '<S22>/Gain3' incorporates:
  //   Sum: '<S22>/Add19'

  px4_noGPS_B.roll_hat_e = (px4_noGPS_B.u0_tmp - px4_noGPS_B.lambda4_h) *
    px4_noGPS_P.Gain3_Gain;

  // Saturate: '<S22>/Saturation1'
  if (px4_noGPS_B.rtb_u_f_c > px4_noGPS_P.Saturation1_UpperSat) {
    px4_noGPS_B.lambda1_a = px4_noGPS_P.Saturation1_UpperSat;
  } else if (px4_noGPS_B.rtb_u_f_c < px4_noGPS_P.Saturation1_LowerSat) {
    px4_noGPS_B.lambda1_a = px4_noGPS_P.Saturation1_LowerSat;
  } else {
    px4_noGPS_B.lambda1_a = px4_noGPS_B.rtb_u_f_c;
  }

  // End of Saturate: '<S22>/Saturation1'

  // Fcn: '<S22>/Fcn7' incorporates:
  //   Constant: '<S22>/Constant1'

  if (px4_noGPS_P.Constant1_Value_f < 0.0) {
    px4_noGPS_B.Add2_g = -rt_powd_snf(-px4_noGPS_P.Constant1_Value_f, -0.75);
  } else {
    px4_noGPS_B.Add2_g = rt_powd_snf(px4_noGPS_P.Constant1_Value_f, -0.75);
  }

  // End of Fcn: '<S22>/Fcn7'

  // Saturate: '<S22>/Saturation15'
  if (px4_noGPS_B.rtb_u_f_c > px4_noGPS_P.Saturation15_UpperSat) {
    px4_noGPS_B.Product3_a = px4_noGPS_P.Saturation15_UpperSat;
  } else if (px4_noGPS_B.rtb_u_f_c < px4_noGPS_P.Saturation15_LowerSat) {
    px4_noGPS_B.Product3_a = px4_noGPS_P.Saturation15_LowerSat;
  } else {
    px4_noGPS_B.Product3_a = px4_noGPS_B.rtb_u_f_c;
  }

  // End of Saturate: '<S22>/Saturation15'

  // Sum: '<S22>/Add2' incorporates:
  //   Constant: '<S22>/Constant6'
  //   DiscreteIntegrator: '<S22>/Discrete-Time Integrator3'
  //   Fcn: '<S22>/Fcn8'
  //   Gain: '<S22>/Gain6'
  //   Gain: '<S22>/l2'
  //   Gain: '<S22>/lambda2'
  //   Product: '<S22>/Product7'
  //   Product: '<S22>/Product8'
  //   Sum: '<S22>/Add16'
  //   Sum: '<S22>/Add20'
  //   Sum: '<S22>/Add3'

  px4_noGPS_B.Add2_b = (((px4_noGPS_P.lambda2_Gain * px4_noGPS_B.rtb_u_f_c +
    px4_noGPS_P.l2_Gain * px4_noGPS_B.lambda1_a) +
    (px4_noGPS_B.rtb_DataTypeConversion3_idx_0 -
     px4_noGPS_B.rtb_DataTypeConversion3_idx_1)) +
                        px4_noGPS_DW.DiscreteTimeIntegrator3_DSTATE) +
    (px4_noGPS_B.Add2_g * px4_noGPS_B.roll_hat_e * px4_noGPS_B.rtb_u_f_c +
     rt_powd_snf(px4_noGPS_B.Add2_b, 0.25) * px4_noGPS_B.Product3_a *
     (px4_noGPS_P.Constant6_Value - px4_noGPS_B.roll_hat_e)) *
    px4_noGPS_P.Gain6_Gain;

  // Saturate: '<S22>/Saturation3'
  if (px4_noGPS_B.rtb_u_f_c > px4_noGPS_P.Saturation3_UpperSat) {
    px4_noGPS_B.y_m = px4_noGPS_P.Saturation3_UpperSat;
  } else if (px4_noGPS_B.rtb_u_f_c < px4_noGPS_P.Saturation3_LowerSat) {
    px4_noGPS_B.y_m = px4_noGPS_P.Saturation3_LowerSat;
  } else {
    px4_noGPS_B.y_m = px4_noGPS_B.rtb_u_f_c;
  }

  // End of Saturate: '<S22>/Saturation3'

  // Gain: '<S22>/lambda4'
  px4_noGPS_B.lambda4 = px4_noGPS_P.lambda4_Gain * px4_noGPS_B.rtb_u_f_c;

  // Gain: '<S20>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S20>/Discrete-Time Integrator'

  px4_noGPS_B.rolldegree_l = px4_noGPS_P.Gain2_Gain_g *
    px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE_p;

  // Switch: '<S20>/Switch' incorporates:
  //   Constant: '<S20>/Constant3'
  //   DataStoreRead: '<S20>/Data Store Read'
  //   DataStoreRead: '<S20>/Data Store Read1'
  //   DataStoreRead: '<S20>/Data Store Read2'
  //   DataStoreWrite: '<Root>/Data Store Write12'
  //   Gain: '<S20>/1//J'
  //   Gain: '<S20>/k//J'
  //   ZeroOrderHold: '<S20>/Zero-Order Hold1'

  if (px4_noGPS_DW.observer_flag) {
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_P.uJ_Gain_p *
      px4_noGPS_B.DataStoreRead25;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_P.kJ_Gain_c *
      px4_noGPS_DW.pitch_speed;
    px4_noGPS_B.rtb_u_f_c = px4_noGPS_DW.pitch;
  } else {
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_P.Constant3_Value;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_P.Constant3_Value;
    px4_noGPS_B.rtb_u_f_c = px4_noGPS_P.Constant3_Value;
  }

  // End of Switch: '<S20>/Switch'

  // Sum: '<S20>/Add1' incorporates:
  //   DiscreteIntegrator: '<S20>/Discrete-Time Integrator'

  px4_noGPS_B.ZeroOrderHold1 = px4_noGPS_B.rtb_u_f_c -
    px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE_p;

  // Abs: '<S20>/Abs3' incorporates:
  //   Abs: '<S20>/Abs4'
  //   Abs: '<S20>/Abs5'
  //   Abs: '<S20>/Abs6'

  px4_noGPS_B.rtb_u_f_c = fabs(px4_noGPS_B.ZeroOrderHold1);

  // Saturate: '<S20>/Saturation'
  if (px4_noGPS_B.ZeroOrderHold1 > px4_noGPS_P.Saturation_UpperSat_n) {
    px4_noGPS_B.roll_hat_e = px4_noGPS_P.Saturation_UpperSat_n;
  } else if (px4_noGPS_B.ZeroOrderHold1 < px4_noGPS_P.Saturation_LowerSat_g) {
    px4_noGPS_B.roll_hat_e = px4_noGPS_P.Saturation_LowerSat_g;
  } else {
    px4_noGPS_B.roll_hat_e = px4_noGPS_B.ZeroOrderHold1;
  }

  // End of Saturate: '<S20>/Saturation'

  // Gain: '<S20>/lambda1'
  px4_noGPS_B.lambda1_a = px4_noGPS_P.lambda1_Gain_a *
    px4_noGPS_B.ZeroOrderHold1;

  // Sum: '<S20>/Add7' incorporates:
  //   Constant: '<S20>/Constant1'
  //   Sum: '<S20>/Add13'
  //   Sum: '<S20>/Add18'

  px4_noGPS_B.u0_tmp = px4_noGPS_P.Constant1_Value_j +
    px4_noGPS_B.ZeroOrderHold1;

  // Sum: '<S20>/Add6' incorporates:
  //   Constant: '<S20>/Constant1'
  //   Sum: '<S20>/Add12'
  //   Sum: '<S20>/Add17'

  px4_noGPS_B.lambda4_h = px4_noGPS_B.ZeroOrderHold1 -
    px4_noGPS_P.Constant1_Value_j;

  // Saturate: '<S20>/Saturation10' incorporates:
  //   Sum: '<S20>/Add7'

  if (px4_noGPS_B.u0_tmp > px4_noGPS_P.Saturation10_UpperSat_o) {
    px4_noGPS_B.TSamp_kj = px4_noGPS_P.Saturation10_UpperSat_o;
  } else if (px4_noGPS_B.u0_tmp < px4_noGPS_P.Saturation10_LowerSat_b) {
    px4_noGPS_B.TSamp_kj = px4_noGPS_P.Saturation10_LowerSat_b;
  } else {
    px4_noGPS_B.TSamp_kj = px4_noGPS_B.u0_tmp;
  }

  // End of Saturate: '<S20>/Saturation10'

  // Saturate: '<S20>/Saturation11' incorporates:
  //   Sum: '<S20>/Add6'

  if (px4_noGPS_B.lambda4_h > px4_noGPS_P.Saturation11_UpperSat_p) {
    px4_noGPS_B.Product6_a = px4_noGPS_P.Saturation11_UpperSat_p;
  } else if (px4_noGPS_B.lambda4_h < px4_noGPS_P.Saturation11_LowerSat_i) {
    px4_noGPS_B.Product6_a = px4_noGPS_P.Saturation11_LowerSat_i;
  } else {
    px4_noGPS_B.Product6_a = px4_noGPS_B.lambda4_h;
  }

  // End of Saturate: '<S20>/Saturation11'

  // Gain: '<S20>/Gain' incorporates:
  //   Sum: '<S20>/Add8'

  px4_noGPS_B.roll_hat_k = (px4_noGPS_B.TSamp_kj - px4_noGPS_B.Product6_a) *
    px4_noGPS_P.Gain_Gain_g;

  // Fcn: '<S20>/Fcn3' incorporates:
  //   Constant: '<S20>/Constant1'

  if (px4_noGPS_P.Constant1_Value_j < 0.0) {
    px4_noGPS_B.Add2_g = -rt_powd_snf(-px4_noGPS_P.Constant1_Value_j, -0.5);
  } else {
    px4_noGPS_B.Add2_g = rt_powd_snf(px4_noGPS_P.Constant1_Value_j, -0.5);
  }

  // End of Fcn: '<S20>/Fcn3'

  // Product: '<S20>/Product3'
  px4_noGPS_B.Product3_a = px4_noGPS_B.Add2_g * px4_noGPS_B.roll_hat_k *
    px4_noGPS_B.ZeroOrderHold1;

  // Saturate: '<S20>/Saturation8'
  if (px4_noGPS_B.ZeroOrderHold1 > px4_noGPS_P.Saturation8_UpperSat_g) {
    px4_noGPS_B.rtb_ZeroOrderHold1_pp = px4_noGPS_P.Saturation8_UpperSat_g;
  } else if (px4_noGPS_B.ZeroOrderHold1 < px4_noGPS_P.Saturation8_LowerSat_g) {
    px4_noGPS_B.rtb_ZeroOrderHold1_pp = px4_noGPS_P.Saturation8_LowerSat_g;
  } else {
    px4_noGPS_B.rtb_ZeroOrderHold1_pp = px4_noGPS_B.ZeroOrderHold1;
  }

  // End of Saturate: '<S20>/Saturation8'

  // Product: '<S20>/Product4' incorporates:
  //   Abs: '<S20>/Abs3'
  //   Constant: '<S20>/Constant2'
  //   Fcn: '<S20>/Fcn4'
  //   Sum: '<S20>/Add10'

  px4_noGPS_B.Product4_k = rt_powd_snf(px4_noGPS_B.rtb_u_f_c, 0.5) *
    px4_noGPS_B.rtb_ZeroOrderHold1_pp * (px4_noGPS_P.Constant2_Value_h -
    px4_noGPS_B.roll_hat_k);

  // Saturate: '<S20>/Saturation13'
  if (px4_noGPS_B.u0_tmp > px4_noGPS_P.Saturation13_UpperSat_i) {
    px4_noGPS_B.TSamp_kj = px4_noGPS_P.Saturation13_UpperSat_i;
  } else if (px4_noGPS_B.u0_tmp < px4_noGPS_P.Saturation13_LowerSat_c) {
    px4_noGPS_B.TSamp_kj = px4_noGPS_P.Saturation13_LowerSat_c;
  } else {
    px4_noGPS_B.TSamp_kj = px4_noGPS_B.u0_tmp;
  }

  // End of Saturate: '<S20>/Saturation13'

  // Saturate: '<S20>/Saturation9'
  if (px4_noGPS_B.lambda4_h > px4_noGPS_P.Saturation9_UpperSat_i) {
    px4_noGPS_B.Product6_a = px4_noGPS_P.Saturation9_UpperSat_i;
  } else if (px4_noGPS_B.lambda4_h < px4_noGPS_P.Saturation9_LowerSat_c) {
    px4_noGPS_B.Product6_a = px4_noGPS_P.Saturation9_LowerSat_c;
  } else {
    px4_noGPS_B.Product6_a = px4_noGPS_B.lambda4_h;
  }

  // End of Saturate: '<S20>/Saturation9'

  // Gain: '<S20>/Gain1' incorporates:
  //   Sum: '<S20>/Add14'

  px4_noGPS_B.roll_hat_k = (px4_noGPS_B.TSamp_kj - px4_noGPS_B.Product6_a) *
    px4_noGPS_P.Gain1_Gain_d;

  // Fcn: '<S20>/Fcn6' incorporates:
  //   Constant: '<S20>/Constant1'

  if (px4_noGPS_P.Constant1_Value_j < 0.0) {
    px4_noGPS_B.Add2_g = -rt_powd_snf(-px4_noGPS_P.Constant1_Value_j, -0.9375);
  } else {
    px4_noGPS_B.Add2_g = rt_powd_snf(px4_noGPS_P.Constant1_Value_j, -0.9375);
  }

  // End of Fcn: '<S20>/Fcn6'

  // Product: '<S20>/Product6'
  px4_noGPS_B.Product6_i = px4_noGPS_B.Add2_g * px4_noGPS_B.roll_hat_k *
    px4_noGPS_B.ZeroOrderHold1;

  // Saturate: '<S20>/Saturation12'
  if (px4_noGPS_B.ZeroOrderHold1 > px4_noGPS_P.Saturation12_UpperSat_c) {
    px4_noGPS_B.rtb_ZeroOrderHold1_pp = px4_noGPS_P.Saturation12_UpperSat_c;
  } else if (px4_noGPS_B.ZeroOrderHold1 < px4_noGPS_P.Saturation12_LowerSat_b) {
    px4_noGPS_B.rtb_ZeroOrderHold1_pp = px4_noGPS_P.Saturation12_LowerSat_b;
  } else {
    px4_noGPS_B.rtb_ZeroOrderHold1_pp = px4_noGPS_B.ZeroOrderHold1;
  }

  // End of Saturate: '<S20>/Saturation12'

  // Product: '<S20>/Product5' incorporates:
  //   Constant: '<S20>/Constant4'
  //   Fcn: '<S20>/Fcn5'
  //   Sum: '<S20>/Add11'

  px4_noGPS_B.Product5_b = rt_powd_snf(px4_noGPS_B.rtb_u_f_c, 0.0625) *
    px4_noGPS_B.rtb_ZeroOrderHold1_pp * (px4_noGPS_P.Constant4_Value_n -
    px4_noGPS_B.roll_hat_k);

  // Saturate: '<S20>/Saturation16'
  if (px4_noGPS_B.u0_tmp > px4_noGPS_P.Saturation16_UpperSat_l) {
    px4_noGPS_B.u0_tmp = px4_noGPS_P.Saturation16_UpperSat_l;
  } else if (px4_noGPS_B.u0_tmp < px4_noGPS_P.Saturation16_LowerSat_g) {
    px4_noGPS_B.u0_tmp = px4_noGPS_P.Saturation16_LowerSat_g;
  }

  // End of Saturate: '<S20>/Saturation16'

  // Saturate: '<S20>/Saturation14'
  if (px4_noGPS_B.lambda4_h > px4_noGPS_P.Saturation14_UpperSat_l) {
    px4_noGPS_B.lambda4_h = px4_noGPS_P.Saturation14_UpperSat_l;
  } else if (px4_noGPS_B.lambda4_h < px4_noGPS_P.Saturation14_LowerSat_b) {
    px4_noGPS_B.lambda4_h = px4_noGPS_P.Saturation14_LowerSat_b;
  }

  // End of Saturate: '<S20>/Saturation14'

  // Gain: '<S20>/Gain3' incorporates:
  //   Sum: '<S20>/Add19'

  px4_noGPS_B.roll_hat_k = (px4_noGPS_B.u0_tmp - px4_noGPS_B.lambda4_h) *
    px4_noGPS_P.Gain3_Gain_l;

  // Saturate: '<S20>/Saturation1'
  if (px4_noGPS_B.ZeroOrderHold1 > px4_noGPS_P.Saturation1_UpperSat_a) {
    px4_noGPS_B.rtb_ZeroOrderHold1_pp = px4_noGPS_P.Saturation1_UpperSat_a;
  } else if (px4_noGPS_B.ZeroOrderHold1 < px4_noGPS_P.Saturation1_LowerSat_i) {
    px4_noGPS_B.rtb_ZeroOrderHold1_pp = px4_noGPS_P.Saturation1_LowerSat_i;
  } else {
    px4_noGPS_B.rtb_ZeroOrderHold1_pp = px4_noGPS_B.ZeroOrderHold1;
  }

  // End of Saturate: '<S20>/Saturation1'

  // Fcn: '<S20>/Fcn7' incorporates:
  //   Constant: '<S20>/Constant1'

  if (px4_noGPS_P.Constant1_Value_j < 0.0) {
    px4_noGPS_B.Add2_g = -rt_powd_snf(-px4_noGPS_P.Constant1_Value_j, -0.75);
  } else {
    px4_noGPS_B.Add2_g = rt_powd_snf(px4_noGPS_P.Constant1_Value_j, -0.75);
  }

  // End of Fcn: '<S20>/Fcn7'

  // Saturate: '<S20>/Saturation15'
  if (px4_noGPS_B.ZeroOrderHold1 > px4_noGPS_P.Saturation15_UpperSat_j) {
    px4_noGPS_B.lambda1_e = px4_noGPS_P.Saturation15_UpperSat_j;
  } else if (px4_noGPS_B.ZeroOrderHold1 < px4_noGPS_P.Saturation15_LowerSat_k) {
    px4_noGPS_B.lambda1_e = px4_noGPS_P.Saturation15_LowerSat_k;
  } else {
    px4_noGPS_B.lambda1_e = px4_noGPS_B.ZeroOrderHold1;
  }

  // End of Saturate: '<S20>/Saturation15'

  // Sum: '<S20>/Add2' incorporates:
  //   Constant: '<S20>/Constant6'
  //   DiscreteIntegrator: '<S20>/Discrete-Time Integrator3'
  //   Fcn: '<S20>/Fcn8'
  //   Gain: '<S20>/Gain6'
  //   Gain: '<S20>/l2'
  //   Gain: '<S20>/lambda2'
  //   Product: '<S20>/Product7'
  //   Product: '<S20>/Product8'
  //   Sum: '<S20>/Add16'
  //   Sum: '<S20>/Add20'
  //   Sum: '<S20>/Add3'

  px4_noGPS_B.roll_hat_k = (((px4_noGPS_P.lambda2_Gain_j *
    px4_noGPS_B.ZeroOrderHold1 + px4_noGPS_P.l2_Gain_l *
    px4_noGPS_B.rtb_ZeroOrderHold1_pp) +
    (px4_noGPS_B.rtb_DataTypeConversion3_idx_0 -
     px4_noGPS_B.rtb_DataTypeConversion3_idx_1)) +
    px4_noGPS_DW.DiscreteTimeIntegrator3_DSTAT_a) + (px4_noGPS_B.Add2_g *
    px4_noGPS_B.roll_hat_k * px4_noGPS_B.ZeroOrderHold1 + rt_powd_snf
    (px4_noGPS_B.rtb_u_f_c, 0.25) * px4_noGPS_B.lambda1_e *
    (px4_noGPS_P.Constant6_Value_o - px4_noGPS_B.roll_hat_k)) *
    px4_noGPS_P.Gain6_Gain_e;

  // Saturate: '<S20>/Saturation3'
  if (px4_noGPS_B.ZeroOrderHold1 > px4_noGPS_P.Saturation3_UpperSat_m) {
    px4_noGPS_B.y_n = px4_noGPS_P.Saturation3_UpperSat_m;
  } else if (px4_noGPS_B.ZeroOrderHold1 < px4_noGPS_P.Saturation3_LowerSat_i) {
    px4_noGPS_B.y_n = px4_noGPS_P.Saturation3_LowerSat_i;
  } else {
    px4_noGPS_B.y_n = px4_noGPS_B.ZeroOrderHold1;
  }

  // End of Saturate: '<S20>/Saturation3'

  // Gain: '<S20>/lambda4'
  px4_noGPS_B.lambda4_n = px4_noGPS_P.lambda4_Gain_a *
    px4_noGPS_B.ZeroOrderHold1;

  // Gain: '<S21>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S21>/Discrete-Time Integrator'

  px4_noGPS_B.rolldegree_c = px4_noGPS_P.Gain2_Gain_p *
    px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE_f;

  // Switch: '<S21>/Switch' incorporates:
  //   Constant: '<S21>/Constant3'
  //   DataStoreRead: '<S21>/Data Store Read'
  //   DataStoreRead: '<S21>/Data Store Read1'
  //   DataStoreRead: '<S21>/Data Store Read2'
  //   DataStoreWrite: '<Root>/Data Store Write13'
  //   Gain: '<S21>/1//J'
  //   Gain: '<S21>/k//J'
  //   ZeroOrderHold: '<S21>/Zero-Order Hold1'

  if (px4_noGPS_DW.observer_flag) {
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_P.uJ_Gain_g *
      px4_noGPS_B.DataStoreRead26;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_P.kJ_Gain_p *
      px4_noGPS_DW.roll_speed;
    px4_noGPS_B.rtb_u_f_c = px4_noGPS_DW.roll;
  } else {
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_P.Constant3_Value_a;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_P.Constant3_Value_a;
    px4_noGPS_B.rtb_u_f_c = px4_noGPS_P.Constant3_Value_a;
  }

  // End of Switch: '<S21>/Switch'

  // Sum: '<S21>/Add1' incorporates:
  //   DiscreteIntegrator: '<S21>/Discrete-Time Integrator'

  px4_noGPS_B.DiscreteTimeIntegrator_n = px4_noGPS_B.rtb_u_f_c -
    px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE_f;

  // Abs: '<S21>/Abs3' incorporates:
  //   Abs: '<S21>/Abs4'
  //   Abs: '<S21>/Abs5'
  //   Abs: '<S21>/Abs6'

  px4_noGPS_B.ZeroOrderHold2_b = fabs(px4_noGPS_B.DiscreteTimeIntegrator_n);

  // Saturate: '<S21>/Saturation'
  if (px4_noGPS_B.DiscreteTimeIntegrator_n > px4_noGPS_P.Saturation_UpperSat_n1)
  {
    px4_noGPS_B.rtb_ZeroOrderHold1_pp = px4_noGPS_P.Saturation_UpperSat_n1;
  } else if (px4_noGPS_B.DiscreteTimeIntegrator_n <
             px4_noGPS_P.Saturation_LowerSat_c) {
    px4_noGPS_B.rtb_ZeroOrderHold1_pp = px4_noGPS_P.Saturation_LowerSat_c;
  } else {
    px4_noGPS_B.rtb_ZeroOrderHold1_pp = px4_noGPS_B.DiscreteTimeIntegrator_n;
  }

  // End of Saturate: '<S21>/Saturation'

  // Gain: '<S21>/lambda1'
  px4_noGPS_B.lambda1_e = px4_noGPS_P.lambda1_Gain_g *
    px4_noGPS_B.DiscreteTimeIntegrator_n;

  // Sum: '<S21>/Add7' incorporates:
  //   Constant: '<S21>/Constant1'
  //   Sum: '<S21>/Add13'
  //   Sum: '<S21>/Add18'

  px4_noGPS_B.u0_tmp = px4_noGPS_P.Constant1_Value_ac +
    px4_noGPS_B.DiscreteTimeIntegrator_n;

  // Sum: '<S21>/Add6' incorporates:
  //   Constant: '<S21>/Constant1'
  //   Sum: '<S21>/Add12'
  //   Sum: '<S21>/Add17'

  px4_noGPS_B.lambda4_h = px4_noGPS_B.DiscreteTimeIntegrator_n -
    px4_noGPS_P.Constant1_Value_ac;

  // Saturate: '<S21>/Saturation10' incorporates:
  //   Sum: '<S21>/Add7'

  if (px4_noGPS_B.u0_tmp > px4_noGPS_P.Saturation10_UpperSat_a) {
    px4_noGPS_B.TSamp_kj = px4_noGPS_P.Saturation10_UpperSat_a;
  } else if (px4_noGPS_B.u0_tmp < px4_noGPS_P.Saturation10_LowerSat_l) {
    px4_noGPS_B.TSamp_kj = px4_noGPS_P.Saturation10_LowerSat_l;
  } else {
    px4_noGPS_B.TSamp_kj = px4_noGPS_B.u0_tmp;
  }

  // End of Saturate: '<S21>/Saturation10'

  // Saturate: '<S21>/Saturation11' incorporates:
  //   Sum: '<S21>/Add6'

  if (px4_noGPS_B.lambda4_h > px4_noGPS_P.Saturation11_UpperSat_a) {
    px4_noGPS_B.Product6_a = px4_noGPS_P.Saturation11_UpperSat_a;
  } else if (px4_noGPS_B.lambda4_h < px4_noGPS_P.Saturation11_LowerSat_a) {
    px4_noGPS_B.Product6_a = px4_noGPS_P.Saturation11_LowerSat_a;
  } else {
    px4_noGPS_B.Product6_a = px4_noGPS_B.lambda4_h;
  }

  // End of Saturate: '<S21>/Saturation11'

  // Gain: '<S21>/Gain' incorporates:
  //   Sum: '<S21>/Add8'

  px4_noGPS_B.ZeroOrderHold1_p = (px4_noGPS_B.TSamp_kj - px4_noGPS_B.Product6_a)
    * px4_noGPS_P.Gain_Gain_h;

  // Fcn: '<S21>/Fcn3' incorporates:
  //   Constant: '<S21>/Constant1'

  if (px4_noGPS_P.Constant1_Value_ac < 0.0) {
    px4_noGPS_B.Add2_g = -rt_powd_snf(-px4_noGPS_P.Constant1_Value_ac, -0.5);
  } else {
    px4_noGPS_B.Add2_g = rt_powd_snf(px4_noGPS_P.Constant1_Value_ac, -0.5);
  }

  // End of Fcn: '<S21>/Fcn3'

  // Product: '<S21>/Product3'
  px4_noGPS_B.Product3_c = px4_noGPS_B.Add2_g * px4_noGPS_B.ZeroOrderHold1_p *
    px4_noGPS_B.DiscreteTimeIntegrator_n;

  // Saturate: '<S21>/Saturation8'
  if (px4_noGPS_B.DiscreteTimeIntegrator_n > px4_noGPS_P.Saturation8_UpperSat_c)
  {
    px4_noGPS_B.ZeroOrderHold1 = px4_noGPS_P.Saturation8_UpperSat_c;
  } else if (px4_noGPS_B.DiscreteTimeIntegrator_n <
             px4_noGPS_P.Saturation8_LowerSat_c) {
    px4_noGPS_B.ZeroOrderHold1 = px4_noGPS_P.Saturation8_LowerSat_c;
  } else {
    px4_noGPS_B.ZeroOrderHold1 = px4_noGPS_B.DiscreteTimeIntegrator_n;
  }

  // End of Saturate: '<S21>/Saturation8'

  // Product: '<S21>/Product4' incorporates:
  //   Abs: '<S21>/Abs3'
  //   Constant: '<S21>/Constant2'
  //   Fcn: '<S21>/Fcn4'
  //   Sum: '<S21>/Add10'

  px4_noGPS_B.Product4_g = rt_powd_snf(px4_noGPS_B.ZeroOrderHold2_b, 0.5) *
    px4_noGPS_B.ZeroOrderHold1 * (px4_noGPS_P.Constant2_Value_k -
    px4_noGPS_B.ZeroOrderHold1_p);

  // Saturate: '<S21>/Saturation13'
  if (px4_noGPS_B.u0_tmp > px4_noGPS_P.Saturation13_UpperSat_p) {
    px4_noGPS_B.TSamp_kj = px4_noGPS_P.Saturation13_UpperSat_p;
  } else if (px4_noGPS_B.u0_tmp < px4_noGPS_P.Saturation13_LowerSat_j) {
    px4_noGPS_B.TSamp_kj = px4_noGPS_P.Saturation13_LowerSat_j;
  } else {
    px4_noGPS_B.TSamp_kj = px4_noGPS_B.u0_tmp;
  }

  // End of Saturate: '<S21>/Saturation13'

  // Saturate: '<S21>/Saturation9'
  if (px4_noGPS_B.lambda4_h > px4_noGPS_P.Saturation9_UpperSat_d) {
    px4_noGPS_B.Product6_a = px4_noGPS_P.Saturation9_UpperSat_d;
  } else if (px4_noGPS_B.lambda4_h < px4_noGPS_P.Saturation9_LowerSat_c4) {
    px4_noGPS_B.Product6_a = px4_noGPS_P.Saturation9_LowerSat_c4;
  } else {
    px4_noGPS_B.Product6_a = px4_noGPS_B.lambda4_h;
  }

  // End of Saturate: '<S21>/Saturation9'

  // Gain: '<S21>/Gain1' incorporates:
  //   Sum: '<S21>/Add14'

  px4_noGPS_B.ZeroOrderHold1_p = (px4_noGPS_B.TSamp_kj - px4_noGPS_B.Product6_a)
    * px4_noGPS_P.Gain1_Gain_e;

  // Fcn: '<S21>/Fcn6' incorporates:
  //   Constant: '<S21>/Constant1'

  if (px4_noGPS_P.Constant1_Value_ac < 0.0) {
    px4_noGPS_B.Add2_g = -rt_powd_snf(-px4_noGPS_P.Constant1_Value_ac, -0.9375);
  } else {
    px4_noGPS_B.Add2_g = rt_powd_snf(px4_noGPS_P.Constant1_Value_ac, -0.9375);
  }

  // End of Fcn: '<S21>/Fcn6'

  // Product: '<S21>/Product6'
  px4_noGPS_B.Product6_a = px4_noGPS_B.Add2_g * px4_noGPS_B.ZeroOrderHold1_p *
    px4_noGPS_B.DiscreteTimeIntegrator_n;

  // Saturate: '<S21>/Saturation12'
  if (px4_noGPS_B.DiscreteTimeIntegrator_n > px4_noGPS_P.Saturation12_UpperSat_d)
  {
    px4_noGPS_B.ZeroOrderHold1 = px4_noGPS_P.Saturation12_UpperSat_d;
  } else if (px4_noGPS_B.DiscreteTimeIntegrator_n <
             px4_noGPS_P.Saturation12_LowerSat_j) {
    px4_noGPS_B.ZeroOrderHold1 = px4_noGPS_P.Saturation12_LowerSat_j;
  } else {
    px4_noGPS_B.ZeroOrderHold1 = px4_noGPS_B.DiscreteTimeIntegrator_n;
  }

  // End of Saturate: '<S21>/Saturation12'

  // Product: '<S21>/Product5' incorporates:
  //   Constant: '<S21>/Constant4'
  //   Fcn: '<S21>/Fcn5'
  //   Sum: '<S21>/Add11'

  px4_noGPS_B.Product5_l = rt_powd_snf(px4_noGPS_B.ZeroOrderHold2_b, 0.0625) *
    px4_noGPS_B.ZeroOrderHold1 * (px4_noGPS_P.Constant4_Value_l -
    px4_noGPS_B.ZeroOrderHold1_p);

  // Saturate: '<S21>/Saturation16'
  if (px4_noGPS_B.u0_tmp > px4_noGPS_P.Saturation16_UpperSat_p) {
    px4_noGPS_B.u0_tmp = px4_noGPS_P.Saturation16_UpperSat_p;
  } else if (px4_noGPS_B.u0_tmp < px4_noGPS_P.Saturation16_LowerSat_i) {
    px4_noGPS_B.u0_tmp = px4_noGPS_P.Saturation16_LowerSat_i;
  }

  // End of Saturate: '<S21>/Saturation16'

  // Saturate: '<S21>/Saturation14'
  if (px4_noGPS_B.lambda4_h > px4_noGPS_P.Saturation14_UpperSat_n) {
    px4_noGPS_B.lambda4_h = px4_noGPS_P.Saturation14_UpperSat_n;
  } else if (px4_noGPS_B.lambda4_h < px4_noGPS_P.Saturation14_LowerSat_a) {
    px4_noGPS_B.lambda4_h = px4_noGPS_P.Saturation14_LowerSat_a;
  }

  // End of Saturate: '<S21>/Saturation14'

  // Gain: '<S21>/Gain3' incorporates:
  //   Sum: '<S21>/Add19'

  px4_noGPS_B.ZeroOrderHold1_p = (px4_noGPS_B.u0_tmp - px4_noGPS_B.lambda4_h) *
    px4_noGPS_P.Gain3_Gain_p;

  // Saturate: '<S21>/Saturation1'
  if (px4_noGPS_B.DiscreteTimeIntegrator_n > px4_noGPS_P.Saturation1_UpperSat_d)
  {
    px4_noGPS_B.ZeroOrderHold1 = px4_noGPS_P.Saturation1_UpperSat_d;
  } else if (px4_noGPS_B.DiscreteTimeIntegrator_n <
             px4_noGPS_P.Saturation1_LowerSat_g) {
    px4_noGPS_B.ZeroOrderHold1 = px4_noGPS_P.Saturation1_LowerSat_g;
  } else {
    px4_noGPS_B.ZeroOrderHold1 = px4_noGPS_B.DiscreteTimeIntegrator_n;
  }

  // End of Saturate: '<S21>/Saturation1'

  // Fcn: '<S21>/Fcn7' incorporates:
  //   Constant: '<S21>/Constant1'

  if (px4_noGPS_P.Constant1_Value_ac < 0.0) {
    px4_noGPS_B.Add2_g = -rt_powd_snf(-px4_noGPS_P.Constant1_Value_ac, -0.75);
  } else {
    px4_noGPS_B.Add2_g = rt_powd_snf(px4_noGPS_P.Constant1_Value_ac, -0.75);
  }

  // End of Fcn: '<S21>/Fcn7'

  // Saturate: '<S21>/Saturation15'
  if (px4_noGPS_B.DiscreteTimeIntegrator_n > px4_noGPS_P.Saturation15_UpperSat_k)
  {
    px4_noGPS_B.u0_tmp = px4_noGPS_P.Saturation15_UpperSat_k;
  } else if (px4_noGPS_B.DiscreteTimeIntegrator_n <
             px4_noGPS_P.Saturation15_LowerSat_h) {
    px4_noGPS_B.u0_tmp = px4_noGPS_P.Saturation15_LowerSat_h;
  } else {
    px4_noGPS_B.u0_tmp = px4_noGPS_B.DiscreteTimeIntegrator_n;
  }

  // End of Saturate: '<S21>/Saturation15'

  // Sum: '<S21>/Add2' incorporates:
  //   Constant: '<S21>/Constant6'
  //   DiscreteIntegrator: '<S21>/Discrete-Time Integrator3'
  //   Fcn: '<S21>/Fcn8'
  //   Gain: '<S21>/Gain6'
  //   Gain: '<S21>/l2'
  //   Gain: '<S21>/lambda2'
  //   Product: '<S21>/Product7'
  //   Product: '<S21>/Product8'
  //   Sum: '<S21>/Add16'
  //   Sum: '<S21>/Add20'
  //   Sum: '<S21>/Add3'

  px4_noGPS_B.Add2_g = (((px4_noGPS_P.lambda2_Gain_d *
    px4_noGPS_B.DiscreteTimeIntegrator_n + px4_noGPS_P.l2_Gain_i *
    px4_noGPS_B.ZeroOrderHold1) + (px4_noGPS_B.rtb_DataTypeConversion3_idx_0 -
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1)) +
                        px4_noGPS_DW.DiscreteTimeIntegrator3_DSTAT_m) +
    (px4_noGPS_B.Add2_g * px4_noGPS_B.ZeroOrderHold1_p *
     px4_noGPS_B.DiscreteTimeIntegrator_n + rt_powd_snf
     (px4_noGPS_B.ZeroOrderHold2_b, 0.25) * px4_noGPS_B.u0_tmp *
     (px4_noGPS_P.Constant6_Value_g - px4_noGPS_B.ZeroOrderHold1_p)) *
    px4_noGPS_P.Gain6_Gain_f;

  // Saturate: '<S21>/Saturation3'
  if (px4_noGPS_B.DiscreteTimeIntegrator_n > px4_noGPS_P.Saturation3_UpperSat_i)
  {
    px4_noGPS_B.u0_tmp = px4_noGPS_P.Saturation3_UpperSat_i;
  } else if (px4_noGPS_B.DiscreteTimeIntegrator_n <
             px4_noGPS_P.Saturation3_LowerSat_g) {
    px4_noGPS_B.u0_tmp = px4_noGPS_P.Saturation3_LowerSat_g;
  } else {
    px4_noGPS_B.u0_tmp = px4_noGPS_B.DiscreteTimeIntegrator_n;
  }

  // End of Saturate: '<S21>/Saturation3'

  // Gain: '<S21>/lambda4'
  px4_noGPS_B.lambda4_h = px4_noGPS_P.lambda4_Gain_b *
    px4_noGPS_B.DiscreteTimeIntegrator_n;

  // MATLABSystem: '<S10>/SourceBlock'
  rtb_LogicalOperator = uORB_read_step(px4_noGPS_DW.obj_n.orbMetadataObj,
    &px4_noGPS_DW.obj_n.eventStructObj, &px4_noGPS_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S51>/Enable'

  if (rtb_LogicalOperator) {
    // SignalConversion generated from: '<S51>/In1'
    px4_noGPS_B.In1 = px4_noGPS_B.b_varargout_2;
    srUpdateBC(px4_noGPS_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S10>/Enabled Subsystem'

  // Sqrt: '<S62>/sqrt' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   Product: '<S63>/Product'
  //   Product: '<S63>/Product1'
  //   Product: '<S63>/Product2'
  //   Product: '<S63>/Product3'
  //   Sum: '<S63>/Sum'

  px4_noGPS_B.ZeroOrderHold1_p = sqrt(((static_cast<real_T>(px4_noGPS_B.In1.q[0])
    * px4_noGPS_B.In1.q[0] + static_cast<real_T>(px4_noGPS_B.In1.q[1]) *
    px4_noGPS_B.In1.q[1]) + static_cast<real_T>(px4_noGPS_B.In1.q[2]) *
    px4_noGPS_B.In1.q[2]) + static_cast<real_T>(px4_noGPS_B.In1.q[3]) *
    px4_noGPS_B.In1.q[3]);

  // Product: '<S57>/Product' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4_noGPS_B.ZeroOrderHold2_b = px4_noGPS_B.In1.q[0] /
    px4_noGPS_B.ZeroOrderHold1_p;

  // Product: '<S57>/Product1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4_noGPS_B.DiscreteTimeIntegrator_n = px4_noGPS_B.In1.q[1] /
    px4_noGPS_B.ZeroOrderHold1_p;

  // Product: '<S57>/Product2' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4_noGPS_B.ZeroOrderHold1 = px4_noGPS_B.In1.q[2] /
    px4_noGPS_B.ZeroOrderHold1_p;

  // Product: '<S57>/Product3' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  px4_noGPS_B.ZeroOrderHold1_p = px4_noGPS_B.In1.q[3] /
    px4_noGPS_B.ZeroOrderHold1_p;

  // Fcn: '<S12>/fcn3'
  px4_noGPS_B.fcn3 = (px4_noGPS_B.DiscreteTimeIntegrator_n *
                      px4_noGPS_B.ZeroOrderHold1_p -
                      px4_noGPS_B.ZeroOrderHold2_b * px4_noGPS_B.ZeroOrderHold1)
    * -2.0;

  // If: '<S58>/If' incorporates:
  //   Constant: '<S59>/Constant'
  //   Constant: '<S60>/Constant'

  if (px4_noGPS_B.fcn3 > 1.0) {
    // Outputs for IfAction SubSystem: '<S58>/If Action Subsystem' incorporates:
    //   ActionPort: '<S59>/Action Port'

    px4_noGPS_B.fcn3 = px4_noGPS_P.Constant_Value_e;

    // End of Outputs for SubSystem: '<S58>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S58>/If Action Subsystem' incorporates:
    //   ActionPort: '<S59>/Action Port'

    // Update for If: '<S58>/If' incorporates:
    //   Constant: '<S59>/Constant'

    srUpdateBC(px4_noGPS_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S58>/If Action Subsystem'
  } else if (px4_noGPS_B.fcn3 < -1.0) {
    // Outputs for IfAction SubSystem: '<S58>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S60>/Action Port'

    px4_noGPS_B.fcn3 = px4_noGPS_P.Constant_Value_b1;

    // End of Outputs for SubSystem: '<S58>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S58>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S60>/Action Port'

    // Update for If: '<S58>/If' incorporates:
    //   Constant: '<S60>/Constant'

    srUpdateBC(px4_noGPS_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S58>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S58>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S61>/Action Port'

    // Update for If: '<S58>/If'
    srUpdateBC(px4_noGPS_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S58>/If Action Subsystem2'
  }

  // End of If: '<S58>/If'

  // Fcn: '<S12>/fcn5' incorporates:
  //   Fcn: '<S12>/fcn2'

  px4_noGPS_B.TSamp_kj = px4_noGPS_B.ZeroOrderHold2_b *
    px4_noGPS_B.ZeroOrderHold2_b;
  px4_noGPS_B.rtb_DataTypeConversion3_idx_0 =
    px4_noGPS_B.DiscreteTimeIntegrator_n * px4_noGPS_B.DiscreteTimeIntegrator_n;
  px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_B.ZeroOrderHold1 *
    px4_noGPS_B.ZeroOrderHold1;
  roll_tmp = px4_noGPS_B.ZeroOrderHold1_p * px4_noGPS_B.ZeroOrderHold1_p;

  // DataStoreWrite: '<Root>/Data Store Write' incorporates:
  //   Fcn: '<S12>/fcn4'
  //   Fcn: '<S12>/fcn5'
  //   Trigonometry: '<S56>/Trigonometric Function3'

  px4_noGPS_DW.roll = rt_atan2d_snf((px4_noGPS_B.ZeroOrderHold1 *
    px4_noGPS_B.ZeroOrderHold1_p + px4_noGPS_B.ZeroOrderHold2_b *
    px4_noGPS_B.DiscreteTimeIntegrator_n) * 2.0, ((px4_noGPS_B.TSamp_kj -
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0) -
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1) + roll_tmp);

  // Trigonometry: '<S56>/trigFcn'
  if (px4_noGPS_B.fcn3 > 1.0) {
    px4_noGPS_B.fcn3 = 1.0;
  } else if (px4_noGPS_B.fcn3 < -1.0) {
    px4_noGPS_B.fcn3 = -1.0;
  }

  // DataStoreWrite: '<Root>/Data Store Write1' incorporates:
  //   Trigonometry: '<S56>/trigFcn'

  px4_noGPS_DW.pitch = asin(px4_noGPS_B.fcn3);

  // DataStoreWrite: '<Root>/Data Store Write10' incorporates:
  //   Fcn: '<S12>/fcn1'
  //   Fcn: '<S12>/fcn2'
  //   Trigonometry: '<S56>/Trigonometric Function1'

  px4_noGPS_DW.yaw = rt_atan2d_snf((px4_noGPS_B.DiscreteTimeIntegrator_n *
    px4_noGPS_B.ZeroOrderHold1 + px4_noGPS_B.ZeroOrderHold2_b *
    px4_noGPS_B.ZeroOrderHold1_p) * 2.0, ((px4_noGPS_B.TSamp_kj +
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0) -
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1) - roll_tmp);

  // DataStoreWrite: '<Root>/Data Store Write20' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px4_noGPS_DW.yaw_speed = px4_noGPS_B.In1.yawspeed;

  // DataStoreWrite: '<Root>/Data Store Write21' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px4_noGPS_DW.pitch_speed = px4_noGPS_B.In1.pitchspeed;

  // DataStoreWrite: '<Root>/Data Store Write22' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  px4_noGPS_DW.roll_speed = px4_noGPS_B.In1.rollspeed;

  // MATLAB Function: '<Root>/MATLAB Function3' incorporates:
  //   Constant: '<Root>/Constant6'
  //   DataStoreRead: '<Root>/Data Store Read45'
  //   DataStoreRead: '<Root>/Data Store Read52'
  //   DataStoreRead: '<Root>/Data Store Read56'
  //   MATLAB Function: '<Root>/MATLAB Function4'

  px4_noGPS_B.ZeroOrderHold1_p = cos(px4_noGPS_P.Constant6_Value_p);
  px4_noGPS_B.ZeroOrderHold2_b = sin(px4_noGPS_P.Constant6_Value_p);
  px4_noGPS_DW.roll_desire = asin((px4_noGPS_DW.q_x *
    px4_noGPS_B.ZeroOrderHold2_b - px4_noGPS_DW.q_y *
    px4_noGPS_B.ZeroOrderHold1_p) / sqrt((px4_noGPS_DW.q_x * px4_noGPS_DW.q_x +
    px4_noGPS_DW.q_y * px4_noGPS_DW.q_y) + (px4_noGPS_DW.q_z + 9.8) *
    (px4_noGPS_DW.q_z + 9.8)));
  px4_noGPS_DW.pitch_desire = atan((px4_noGPS_DW.q_x *
    px4_noGPS_B.ZeroOrderHold1_p + px4_noGPS_DW.q_y *
    px4_noGPS_B.ZeroOrderHold2_b) / (px4_noGPS_DW.q_z + 9.8));
  if (px4_noGPS_DW.roll_desire > 0.17453292519943295) {
    px4_noGPS_DW.roll_desire = 0.17453292519943295;
  } else if (px4_noGPS_DW.roll_desire < -0.17453292519943295) {
    px4_noGPS_DW.roll_desire = -0.17453292519943295;
  }

  if (px4_noGPS_DW.pitch_desire > 0.17453292519943295) {
    px4_noGPS_DW.pitch_desire = 0.17453292519943295;
  } else if (px4_noGPS_DW.pitch_desire < -0.17453292519943295) {
    px4_noGPS_DW.pitch_desire = -0.17453292519943295;
  }

  // End of MATLAB Function: '<Root>/MATLAB Function3'

  // Switch: '<Root>/Switch' incorporates:
  //   Constant: '<Root>/Constant7'
  //   Constant: '<Root>/Constant8'
  //   Constant: '<S52>/Constant1'
  //   DataStoreRead: '<Root>/Data Store Read57'
  //   DiscreteIntegrator: '<Root>/Intgrt_dY'
  //   DiscreteIntegrator: '<Root>/Intgrt_ddY'
  //   Switch: '<S52>/Switch'

  if (px4_noGPS_DW.position_flag) {
    px4_noGPS_B.ZeroOrderHold1 = px4_noGPS_P.Constant7_Value;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_DW.Intgrt_dY_DSTATE;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_P.Constant7_Value;
    px4_noGPS_B.rtb_u_f_c = px4_noGPS_DW.Intgrt_ddY_DSTATE;
  } else {
    px4_noGPS_B.ZeroOrderHold1 = px4_noGPS_P.Constant8_Value;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_P.Constant1_Value_g;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_P.Constant1_Value_g;
    px4_noGPS_B.rtb_u_f_c = px4_noGPS_P.Constant1_Value_g;
  }

  // End of Switch: '<Root>/Switch'

  // ZeroOrderHold: '<S52>/Zero-Order Hold1'
  px4_noGPS_B.ZeroOrderHold1_p = px4_noGPS_B.rtb_DataTypeConversion3_idx_0;

  // ZeroOrderHold: '<S52>/Zero-Order Hold2'
  px4_noGPS_B.ZeroOrderHold2_b = px4_noGPS_B.rtb_DataTypeConversion3_idx_1;

  // SampleTimeMath: '<S54>/TSamp'
  //
  //  About '<S54>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS_B.DiscreteTimeIntegrator_n =
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 * px4_noGPS_P.TSamp_WtEt_d;

  // Gain: '<S11>/Gain2' incorporates:
  //   DiscreteIntegrator: '<S52>/Discrete-Time Integrator'
  //   Gain: '<S52>/C1'
  //   Gain: '<S52>/C2'
  //   Gain: '<S52>/C3'
  //   Sum: '<S52>/Subtract'
  //   Sum: '<S52>/Subtract1'
  //   Sum: '<S52>/Subtract2'
  //   Sum: '<S54>/Diff'
  //   UnitDelay: '<S54>/UD'
  //   ZeroOrderHold: '<S52>/Zero-Order Hold1'
  //   ZeroOrderHold: '<S52>/Zero-Order Hold2'
  //   ZeroOrderHold: '<S52>/Zero-Order Hold5'
  //
  //  Block description for '<S54>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S54>/UD':
  //
  //   Store in Global RAM

  px4_noGPS_B.TSamp_kj = (((px4_noGPS_B.rtb_u_f_c -
    (px4_noGPS_B.DiscreteTimeIntegrator_n - px4_noGPS_DW.UD_DSTATE_n2)) *
    px4_noGPS_P.C2_Gain + (px4_noGPS_B.rtb_DataTypeConversion3_idx_0 -
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1) * px4_noGPS_P.C1_Gain) +
    px4_noGPS_P.C3_Gain * px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE_d) *
    px4_noGPS_P.Gain2_Gain_d;

  // Saturate: '<S11>/Saturation1'
  if (px4_noGPS_B.TSamp_kj > px4_noGPS_P.Saturation1_UpperSat_h) {
    px4_noGPS_DW.q_y = px4_noGPS_P.Saturation1_UpperSat_h;
  } else if (px4_noGPS_B.TSamp_kj < px4_noGPS_P.Saturation1_LowerSat_o) {
    px4_noGPS_DW.q_y = px4_noGPS_P.Saturation1_LowerSat_o;
  } else {
    px4_noGPS_DW.q_y = px4_noGPS_B.TSamp_kj;
  }

  // End of Saturate: '<S11>/Saturation1'

  // DataStoreWrite: '<Root>/Data Store Write18' incorporates:
  //   Constant: '<S11>/Constant'

  px4_noGPS_DW.q_z = px4_noGPS_P.Constant_Value_i;

  // Switch: '<S53>/Switch' incorporates:
  //   Constant: '<S53>/Constant1'
  //   DataStoreRead: '<S53>/Data Store Read'
  //   DiscreteIntegrator: '<Root>/Intgrt_dX'
  //   DiscreteIntegrator: '<Root>/Intgrt_ddX'

  if (px4_noGPS_DW.position_flag) {
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_DW.Intgrt_dX_DSTATE;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_B.ZeroOrderHold1;
    px4_noGPS_B.rtb_u_f_c = px4_noGPS_DW.Intgrt_ddX_DSTATE;
  } else {
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 = px4_noGPS_P.Constant1_Value_nr;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_P.Constant1_Value_nr;
    px4_noGPS_B.rtb_u_f_c = px4_noGPS_P.Constant1_Value_nr;
  }

  // End of Switch: '<S53>/Switch'

  // SampleTimeMath: '<S55>/TSamp'
  //
  //  About '<S55>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  px4_noGPS_B.TSamp_kj = px4_noGPS_B.rtb_DataTypeConversion3_idx_1 *
    px4_noGPS_P.TSamp_WtEt_e;

  // Sum: '<S53>/Subtract' incorporates:
  //   Sum: '<S53>/Subtract8'
  //   ZeroOrderHold: '<S53>/Zero-Order Hold1'
  //   ZeroOrderHold: '<S53>/Zero-Order Hold2'

  px4_noGPS_B.rtb_DataTypeConversion3_idx_0 -=
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1;

  // Gain: '<S11>/Gain4' incorporates:
  //   DiscreteIntegrator: '<S53>/Discrete-Time Integrator'
  //   Gain: '<S53>/C1'
  //   Gain: '<S53>/C2'
  //   Gain: '<S53>/C3'
  //   Sum: '<S53>/Subtract'
  //   Sum: '<S53>/Subtract1'
  //   Sum: '<S53>/Subtract2'
  //   Sum: '<S55>/Diff'
  //   UnitDelay: '<S55>/UD'
  //
  //  Block description for '<S55>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S55>/UD':
  //
  //   Store in Global RAM

  px4_noGPS_B.rtb_u_f_c = (((px4_noGPS_B.rtb_u_f_c - (px4_noGPS_B.TSamp_kj -
    px4_noGPS_DW.UD_DSTATE_m)) * px4_noGPS_P.C2_Gain_b +
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 * px4_noGPS_P.C1_Gain_d) +
    px4_noGPS_P.C3_Gain_j * px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE_i) *
    px4_noGPS_P.Gain4_Gain_ff;

  // Saturate: '<S11>/Saturation2'
  if (px4_noGPS_B.rtb_u_f_c > px4_noGPS_P.Saturation2_UpperSat_c) {
    px4_noGPS_DW.q_x = px4_noGPS_P.Saturation2_UpperSat_c;
  } else if (px4_noGPS_B.rtb_u_f_c < px4_noGPS_P.Saturation2_LowerSat_f) {
    px4_noGPS_DW.q_x = px4_noGPS_P.Saturation2_LowerSat_f;
  } else {
    px4_noGPS_DW.q_x = px4_noGPS_B.rtb_u_f_c;
  }

  // End of Saturate: '<S11>/Saturation2'

  // MATLAB Function: '<Root>/MATLAB Function2' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read'
  //   DataStoreRead: '<Root>/Data Store Read7'

  px4_noGPS_B.rtb_u_i_c = 9.8 / (cos(px4_noGPS_DW.roll) * cos(px4_noGPS_DW.pitch));

  // MATLAB Function: '<Root>/MATLAB Function1' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read'
  //   DataStoreRead: '<Root>/Data Store Read7'

  px4_noGPS_MATLABFunction1(px4_noGPS_DW.pitch, px4_noGPS_DW.roll, 0.0,
    px4_noGPS_B.rtb_u_i_c, &px4_noGPS_B.rtb_dd_y_c, &px4_noGPS_B.rtb_dd_x_b,
    &px4_noGPS_B.rtb_dd_z_h_p);

  // MATLAB Function: '<Root>/MATLAB Function6' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read63'
  //   DataStoreRead: '<Root>/Data Store Read64'
  //   DataStoreRead: '<Root>/Data Store Read65'

  px4_noGPS_MATLABFunction6(px4_noGPS_DW.q_x, px4_noGPS_DW.q_y, px4_noGPS_DW.q_z,
    &px4_noGPS_B.rtb_u_f_c);

  // MATLAB Function: '<Root>/MATLAB Function5' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read58'
  //   DataStoreRead: '<Root>/Data Store Read66'
  //   DataStoreRead: '<Root>/Data Store Read67'

  px4_noGPS_MATLABFunction1(px4_noGPS_DW.pitch, px4_noGPS_DW.roll,
    px4_noGPS_DW.yaw, px4_noGPS_B.rtb_u_f_c, &px4_noGPS_B.rtb_dd_x_b,
    &px4_noGPS_B.rtb_dd_y_c, &px4_noGPS_B.rtb_dd_z_k);

  // MATLAB Function: '<Root>/MATLAB Function7' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read70'
  //   DataStoreRead: '<Root>/Data Store Read71'
  //   DataStoreRead: '<Root>/Data Store Read72'

  px4_noGPS_MATLABFunction6(px4_noGPS_DW.q_x, px4_noGPS_DW.q_y, px4_noGPS_DW.q_z,
    &px4_noGPS_B.rtb_u_f_c);

  // DataStoreWrite: '<S14>/Data Store Write28' incorporates:
  //   Constant: '<S14>/attitude_flag'

  px4_noGPS_DW.attitude_flag = px4_noGPS_P.attitude_flag_Value;

  // DataStoreWrite: '<S15>/Data Store Write28' incorporates:
  //   Constant: '<S15>/observer_flag'

  px4_noGPS_DW.observer_flag = px4_noGPS_P.observer_flag_Value;

  // DataStoreWrite: '<S16>/Data Store Write28' incorporates:
  //   Constant: '<S16>/position_flag'

  px4_noGPS_DW.position_flag = px4_noGPS_P.position_flag_Value;

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Constant: '<Root>/Constant2'

  status = pwm_disarm(&px4_noGPS_DW.obj.pwmDevHandler,
                      &px4_noGPS_DW.obj.armAdvertiseObj);
  px4_noGPS_DW.obj.errorStatus = static_cast<uint16_T>
    (px4_noGPS_DW.obj.errorStatus | status);
  px4_noGPS_DW.obj.isArmed = false;
  status = pwm_resetServo(&px4_noGPS_DW.obj.pwmDevHandler,
    px4_noGPS_DW.obj.servoCount, px4_noGPS_DW.obj.channelMask,
    px4_noGPS_DW.obj.isMain, &px4_noGPS_DW.obj.actuatorAdvertiseObj);
  px4_noGPS_DW.obj.errorStatus = static_cast<uint16_T>
    (px4_noGPS_DW.obj.errorStatus | status);
  if (px4_noGPS_DW.obj.isMain) {
    status = pwm_forceFailsafe(&px4_noGPS_DW.obj.pwmDevHandler,
      static_cast<int32_T>(px4_noGPS_P.Constant2_Value_kf));
    px4_noGPS_DW.obj.errorStatus = static_cast<uint16_T>
      (px4_noGPS_DW.obj.errorStatus | status);
  }

  // End of MATLABSystem: '<Root>/PX4 PWM Output1'

  // Logic: '<S10>/NOT' incorporates:
  //   MATLABSystem: '<S10>/SourceBlock'

  px4_noGPS_B.NOT = !rtb_LogicalOperator;

  // Switch: '<Root>/Switch1' incorporates:
  //   Constant: '<Root>/Constant5'
  //   DataStoreRead: '<Root>/Data Store Read53'
  //   DataStoreWrite: '<Root>/Data Store Write5'
  //   DataStoreWrite: '<Root>/Data Store Write6'

  if (px4_noGPS_DW.position_flag) {
    px4_noGPS_B.ZeroOrderHold1 = px4_noGPS_B.rtb_dd_x_b;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_B.rtb_dd_y_c;
  } else {
    px4_noGPS_B.ZeroOrderHold1 = px4_noGPS_P.Constant5_Value;
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 = px4_noGPS_P.Constant5_Value;
  }

  // End of Switch: '<Root>/Switch1'

  // Gain: '<Root>/Gain5' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read10'

  px4_noGPS_B.Gain5 = px4_noGPS_P.Gain5_Gain_g * px4_noGPS_DW.pitch;

  // Gain: '<Root>/Gain3' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read11'

  px4_noGPS_B.Gain3 = px4_noGPS_P.Gain3_Gain_c * px4_noGPS_DW.roll;

  // DataStoreRead: '<Root>/Data Store Read12' incorporates:
  //   DataStoreWrite: '<Root>/Data Store Write16'

  px4_noGPS_B.DataStoreRead12 = false;

  // DataStoreRead: '<Root>/Data Store Read13' incorporates:
  //   DataStoreWrite: '<Root>/Data Store Write9'

  px4_noGPS_B.DataStoreRead13 = px4_noGPS_B.rtb_u_f_c;

  // DataStoreRead: '<Root>/Data Store Read15' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddY'

  px4_noGPS_B.DataStoreRead15 = px4_noGPS_DW.Intgrt_ddY_DSTATE;

  // DataStoreRead: '<Root>/Data Store Read16' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_dX'

  px4_noGPS_B.DataStoreRead16 = px4_noGPS_DW.Intgrt_dX_DSTATE;

  // DataStoreRead: '<Root>/Data Store Read17' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_dY'

  px4_noGPS_B.DataStoreRead17 = px4_noGPS_DW.Intgrt_dY_DSTATE;

  // DataStoreRead: '<Root>/Data Store Read19' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddX'

  px4_noGPS_B.DataStoreRead19 = px4_noGPS_DW.Intgrt_ddX_DSTATE;

  // Gain: '<Root>/Gain6' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read24'

  px4_noGPS_B.Gain6 = px4_noGPS_P.Gain6_Gain_k * px4_noGPS_DW.yaw;

  // DataStoreRead: '<Root>/Data Store Read28'
  px4_noGPS_B.pitch_thrust = px4_noGPS_B.DataStoreRead25;

  // DataStoreRead: '<Root>/Data Store Read29'
  px4_noGPS_B.roll_thrust = px4_noGPS_B.DataStoreRead26;

  // DataStoreRead: '<Root>/Data Store Read32'
  px4_noGPS_B.yaw_thrust = px4_noGPS_B.DataStoreRead27;

  // DataStoreRead: '<Root>/Data Store Read73' incorporates:
  //   DataStoreWrite: '<Root>/Data Store Write9'

  px4_noGPS_B.DataStoreRead73 = px4_noGPS_B.rtb_u_f_c;

  // Gain: '<Root>/Gain8' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read31'

  px4_noGPS_B.pitch = px4_noGPS_P.Gain8_Gain_o1 * px4_noGPS_DW.pitch;

  // Gain: '<Root>/Gain10' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read74'

  px4_noGPS_B.pitch_a = px4_noGPS_P.Gain10_Gain * px4_noGPS_DW.pitch_desire;

  // Gain: '<Root>/Gain7' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read30'

  px4_noGPS_B.roll = px4_noGPS_P.Gain7_Gain_a * px4_noGPS_DW.roll;

  // Gain: '<Root>/Gain11' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read41'

  px4_noGPS_B.pitch_g = px4_noGPS_P.Gain11_Gain * px4_noGPS_DW.roll_desire;

  // Gain: '<Root>/Gain9' incorporates:
  //   DataStoreRead: '<Root>/Data Store Read33'

  px4_noGPS_B.yaw = px4_noGPS_P.Gain9_Gain * px4_noGPS_DW.yaw;

  // DataStoreRead: '<Root>/Data Store Read34'
  px4_noGPS_B.DataStoreRead34 = px4_noGPS_DW.yaw_speed;

  // DataStoreRead: '<Root>/Data Store Read35'
  px4_noGPS_B.DataStoreRead35 = px4_noGPS_DW.pitch_speed;

  // DataStoreRead: '<Root>/Data Store Read36'
  px4_noGPS_B.DataStoreRead36 = px4_noGPS_DW.roll_speed;

  // DataStoreRead: '<Root>/Data Store Read37'
  px4_noGPS_B.DataStoreRead37 = px4_noGPS_DW.yaw_acc;

  // DataStoreRead: '<Root>/Data Store Read38'
  px4_noGPS_B.DataStoreRead38 = px4_noGPS_DW.pitch_acc;

  // DataStoreRead: '<Root>/Data Store Read39'
  px4_noGPS_B.DataStoreRead39 = px4_noGPS_DW.roll_acc;

  // DataStoreRead: '<Root>/Data Store Read42'
  px4_noGPS_B.DataStoreRead42 = px4_noGPS_DW.lat;

  // DataStoreRead: '<Root>/Data Store Read43'
  px4_noGPS_B.DataStoreRead43 = px4_noGPS_DW.lon;

  // DataStoreRead: '<Root>/Data Store Read44'
  px4_noGPS_B.DataStoreRead44 = px4_noGPS_DW.alt;

  // DataStoreRead: '<Root>/Data Store Read48' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_dX'

  px4_noGPS_B.DataStoreRead48 = px4_noGPS_DW.Intgrt_dX_DSTATE;

  // DataStoreRead: '<Root>/Data Store Read49' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_dY'

  px4_noGPS_B.DataStoreRead49 = px4_noGPS_DW.Intgrt_dY_DSTATE;

  // Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
  //   EnablePort: '<S13>/Enable'

  // DataStoreRead: '<Root>/Data Store Read54'
  if (px4_noGPS_DW.attitude_flag) {
    // DiscreteIntegrator: '<S13>/Discrete-Time Integrator' incorporates:
    //   DataStoreWrite: '<S13>/Data Store Write27'

    px4_noGPS_DW.t = px4_noGPS_DW.DiscreteTimeIntegrator_DSTAT_fj;

    // Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S13>/Constant9'

    px4_noGPS_DW.DiscreteTimeIntegrator_DSTAT_fj +=
      px4_noGPS_P.DiscreteTimeIntegrator_gainval * px4_noGPS_P.Constant9_Value;
    srUpdateBC(px4_noGPS_DW.Subsystem1_SubsysRanBC);
  }

  // End of DataStoreRead: '<Root>/Data Store Read54'
  // End of Outputs for SubSystem: '<Root>/Subsystem1'

  // DataStoreRead: '<Root>/Data Store Read55'
  px4_noGPS_B.DataStoreRead55 = px4_noGPS_DW.t;

  // DataStoreRead: '<Root>/Data Store Read8' incorporates:
  //   DataStoreWrite: '<Root>/Data Store Write6'

  px4_noGPS_B.DataStoreRead8 = px4_noGPS_B.rtb_dd_x_b;

  // DataStoreRead: '<Root>/Data Store Read9' incorporates:
  //   DataStoreWrite: '<Root>/Data Store Write5'

  px4_noGPS_B.DataStoreRead9 = px4_noGPS_B.rtb_dd_y_c;

  // Update for UnitDelay: '<S41>/UD'
  //
  //  Block description for '<S41>/UD':
  //
  //   Store in Global RAM

  px4_noGPS_DW.UD_DSTATE = px4_noGPS_B.TSamp;

  // Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator3' incorporates:
  //   Gain: '<S22>/Gain7'
  //   Gain: '<S22>/l4'
  //   Sum: '<S22>/Add15'
  //   Sum: '<S22>/Add5'

  px4_noGPS_DW.DiscreteTimeIntegrator3_DSTATE += ((px4_noGPS_P.l4_Gain *
    px4_noGPS_B.y_m + px4_noGPS_B.lambda4) + (px4_noGPS_B.Product6 +
    px4_noGPS_B.z2_l) * px4_noGPS_P.Gain7_Gain) *
    px4_noGPS_P.DiscreteTimeIntegrator3_gainval;

  // Update for UnitDelay: '<S23>/UD'
  //
  //  Block description for '<S23>/UD':
  //
  //   Store in Global RAM

  px4_noGPS_DW.UD_DSTATE_b = px4_noGPS_B.z2;

  // Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator3' incorporates:
  //   Gain: '<S20>/Gain7'
  //   Gain: '<S20>/l4'
  //   Sum: '<S20>/Add15'
  //   Sum: '<S20>/Add5'

  px4_noGPS_DW.DiscreteTimeIntegrator3_DSTAT_a += ((px4_noGPS_P.l4_Gain_p *
    px4_noGPS_B.y_n + px4_noGPS_B.lambda4_n) + (px4_noGPS_B.Product6_i +
    px4_noGPS_B.Product5_b) * px4_noGPS_P.Gain7_Gain_d) *
    px4_noGPS_P.DiscreteTimeIntegrator3_gainv_m;

  // Update for UnitDelay: '<S32>/UD'
  //
  //  Block description for '<S32>/UD':
  //
  //   Store in Global RAM

  px4_noGPS_DW.UD_DSTATE_n = px4_noGPS_B.z2_e;

  // Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator3' incorporates:
  //   Gain: '<S21>/Gain7'
  //   Gain: '<S21>/l4'
  //   Sum: '<S21>/Add15'
  //   Sum: '<S21>/Add5'

  px4_noGPS_DW.DiscreteTimeIntegrator3_DSTAT_m += ((px4_noGPS_P.l4_Gain_o *
    px4_noGPS_B.u0_tmp + px4_noGPS_B.lambda4_h) + (px4_noGPS_B.Product6_a +
    px4_noGPS_B.Product5_l) * px4_noGPS_P.Gain7_Gain_l) *
    px4_noGPS_P.DiscreteTimeIntegrator3_gainv_e;

  // Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S22>/Discrete-Time Integrator1'
  //   Gain: '<S22>/Gain5'
  //   Gain: '<S22>/l1'
  //   Sum: '<S22>/Add'
  //   Sum: '<S22>/Add9'

  px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE += (((px4_noGPS_P.l1_Gain *
    px4_noGPS_B.rtb_Fcn_tmp + px4_noGPS_B.Add3) +
    px4_noGPS_DW.DiscreteTimeIntegrator1_DSTATE) + (px4_noGPS_B.Product3 +
    px4_noGPS_B.roll_hat) * px4_noGPS_P.Gain5_Gain) *
    px4_noGPS_P.DiscreteTimeIntegrator_gainva_n;

  // Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1'
  px4_noGPS_DW.DiscreteTimeIntegrator1_DSTATE +=
    px4_noGPS_P.DiscreteTimeIntegrator1_gainval * px4_noGPS_B.Add2_b;

  // Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S20>/Discrete-Time Integrator1'
  //   Gain: '<S20>/Gain5'
  //   Gain: '<S20>/l1'
  //   Sum: '<S20>/Add'
  //   Sum: '<S20>/Add9'

  px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE_p += (((px4_noGPS_P.l1_Gain_p *
    px4_noGPS_B.roll_hat_e + px4_noGPS_B.lambda1_a) +
    px4_noGPS_DW.DiscreteTimeIntegrator1_DSTAT_i) + (px4_noGPS_B.Product3_a +
    px4_noGPS_B.Product4_k) * px4_noGPS_P.Gain5_Gain_o) *
    px4_noGPS_P.DiscreteTimeIntegrator_gainva_e;

  // Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator1'
  px4_noGPS_DW.DiscreteTimeIntegrator1_DSTAT_i +=
    px4_noGPS_P.DiscreteTimeIntegrator1_gainv_n * px4_noGPS_B.roll_hat_k;

  // Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S21>/Discrete-Time Integrator1'
  //   Gain: '<S21>/Gain5'
  //   Gain: '<S21>/l1'
  //   Sum: '<S21>/Add'
  //   Sum: '<S21>/Add9'

  px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE_f += (((px4_noGPS_P.l1_Gain_d *
    px4_noGPS_B.rtb_ZeroOrderHold1_pp + px4_noGPS_B.lambda1_e) +
    px4_noGPS_DW.DiscreteTimeIntegrator1_DSTAT_g) + (px4_noGPS_B.Product3_c +
    px4_noGPS_B.Product4_g) * px4_noGPS_P.Gain5_Gain_l) *
    px4_noGPS_P.DiscreteTimeIntegrator_gainv_nv;

  // Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator1'
  px4_noGPS_DW.DiscreteTimeIntegrator1_DSTAT_g +=
    px4_noGPS_P.DiscreteTimeIntegrator1_gainv_g * px4_noGPS_B.Add2_g;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_dX' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddX'

  px4_noGPS_DW.Intgrt_dX_DSTATE += px4_noGPS_P.Intgrt_dX_gainval *
    px4_noGPS_DW.Intgrt_ddX_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_dY' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddY'

  px4_noGPS_DW.Intgrt_dY_DSTATE += px4_noGPS_P.Intgrt_dY_gainval *
    px4_noGPS_DW.Intgrt_ddY_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_ddY' incorporates:
  //   Gain: '<Root>/slower4'

  px4_noGPS_DW.Intgrt_ddY_DSTATE += px4_noGPS_P.slower4_Gain *
    px4_noGPS_B.rtb_DataTypeConversion3_idx_1 * px4_noGPS_P.Intgrt_ddY_gainval;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_ddX' incorporates:
  //   Gain: '<Root>/slower3'

  px4_noGPS_DW.Intgrt_ddX_DSTATE += px4_noGPS_P.slower3_Gain *
    px4_noGPS_B.ZeroOrderHold1 * px4_noGPS_P.Intgrt_ddX_gainval;

  // Update for UnitDelay: '<S54>/UD'
  //
  //  Block description for '<S54>/UD':
  //
  //   Store in Global RAM

  px4_noGPS_DW.UD_DSTATE_n2 = px4_noGPS_B.DiscreteTimeIntegrator_n;

  // Update for DiscreteIntegrator: '<S52>/Discrete-Time Integrator' incorporates:
  //   Sum: '<S52>/Subtract8'

  px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE_d += (px4_noGPS_B.ZeroOrderHold1_p
    - px4_noGPS_B.ZeroOrderHold2_b) *
    px4_noGPS_P.DiscreteTimeIntegrator_gainva_h;

  // Update for UnitDelay: '<S55>/UD'
  //
  //  Block description for '<S55>/UD':
  //
  //   Store in Global RAM

  px4_noGPS_DW.UD_DSTATE_m = px4_noGPS_B.TSamp_kj;

  // Update for DiscreteIntegrator: '<S53>/Discrete-Time Integrator'
  px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE_i +=
    px4_noGPS_B.rtb_DataTypeConversion3_idx_0 *
    px4_noGPS_P.DiscreteTimeIntegrator_gainva_p;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_dZ' incorporates:
  //   DiscreteIntegrator: '<Root>/Intgrt_ddZ'

  px4_noGPS_DW.Intgrt_dZ_DSTATE += px4_noGPS_P.Intgrt_dZ_gainval *
    px4_noGPS_DW.Intgrt_ddZ_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Intgrt_ddZ' incorporates:
  //   Gain: '<Root>/slower5'

  px4_noGPS_DW.Intgrt_ddZ_DSTATE += px4_noGPS_P.slower5_Gain * 0.0 *
    px4_noGPS_P.Intgrt_ddZ_gainval;

  // External mode
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)px4_noGPS_M->Timing.taskTime0);

  // signal main to stop simulation
  {                                    // Sample time: [0.005s, 0.0s]
    if ((rtmGetTFinal(px4_noGPS_M)!=-1) &&
        !((rtmGetTFinal(px4_noGPS_M)-px4_noGPS_M->Timing.taskTime0) >
          px4_noGPS_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(px4_noGPS_M, "Simulation finished");
    }

    if (rtmGetStopRequested(px4_noGPS_M)) {
      rtmSetErrorStatus(px4_noGPS_M, "Simulation finished");
    }
  }

  // Update absolute time
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  px4_noGPS_M->Timing.taskTime0 =
    ((time_T)(++px4_noGPS_M->Timing.clockTick0)) * px4_noGPS_M->Timing.stepSize0;
}

// Model step function for TID1
void px4_noGPS_step1(void)             // Sample time: [0.01s, 0.0s]
{
  uint64_T rtb_timestamp;
  uint32_T rtb_noutputs;
  uint8_T rtb__padding0[4];
  boolean_T b_varargout_1;
  boolean_T rtb_NOT;

  // Reset subsysRan breadcrumbs
  srClearBC(px4_noGPS_DW.EnabledSubsystem_SubsysRanBC_b);

  // MATLABSystem: '<S9>/SourceBlock'
  b_varargout_1 = uORB_read_step(px4_noGPS_DW.obj_l.orbMetadataObj,
    &px4_noGPS_DW.obj_l.eventStructObj, &px4_noGPS_B.b_varargout_2_m, false, 1.0);

  // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S50>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S50>/In1'
    px4_noGPS_B.In1_a = px4_noGPS_B.b_varargout_2_m;
    srUpdateBC(px4_noGPS_DW.EnabledSubsystem_SubsysRanBC_b);
  }

  // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'

  // SignalConversion generated from: '<Root>/Bus Selector'
  memcpy(&px4_noGPS_B.output[0], &px4_noGPS_B.In1_a.output[0], sizeof(real32_T) <<
         4U);

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb_timestamp = px4_noGPS_B.In1_a.timestamp;

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb_noutputs = px4_noGPS_B.In1_a.noutputs;

  // SignalConversion generated from: '<Root>/Bus Selector'
  rtb__padding0[0] = px4_noGPS_B.In1_a._padding0[0];
  rtb__padding0[1] = px4_noGPS_B.In1_a._padding0[1];
  rtb__padding0[2] = px4_noGPS_B.In1_a._padding0[2];
  rtb__padding0[3] = px4_noGPS_B.In1_a._padding0[3];

  // Logic: '<S9>/NOT' incorporates:
  //   MATLABSystem: '<S9>/SourceBlock'

  rtb_NOT = !b_varargout_1;
  rtExtModeUpload(1, (real_T)((px4_noGPS_M->Timing.clockTick1) * 0.01));

  // Update absolute time
  // The "clockTick1" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.01, which is the step size
  //  of the task. Size of "clockTick1" ensures timer will not overflow during the
  //  application lifespan selected.

  px4_noGPS_M->Timing.clockTick1++;
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void px4_noGPS_step(int_T tid)
{
  switch (tid) {
   case 0 :
    px4_noGPS_step0();
    break;

   case 1 :
    px4_noGPS_step1();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void px4_noGPS_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  px4_noGPS_P.Saturation1_UpperSat_k = rtInf;
  rtmSetTFinal(px4_noGPS_M, -1);
  px4_noGPS_M->Timing.stepSize0 = 0.005;

  // External mode info
  px4_noGPS_M->Sizes.checksums[0] = (1063988621U);
  px4_noGPS_M->Sizes.checksums[1] = (2154102270U);
  px4_noGPS_M->Sizes.checksums[2] = (1309426222U);
  px4_noGPS_M->Sizes.checksums[3] = (4192412788U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[42];
    px4_noGPS_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&px4_noGPS_DW.Subsystem_SubsysRanBC_k;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)&px4_noGPS_DW.Subsystem_SubsysRanBC_m;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)&px4_noGPS_DW.Subsystem_SubsysRanBC;
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
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = (sysRanDType *)&px4_noGPS_DW.EnabledSubsystem_SubsysRanBC_b;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = (sysRanDType *)&px4_noGPS_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = (sysRanDType *)&px4_noGPS_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[35] = (sysRanDType *)&px4_noGPS_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[36] = (sysRanDType *)&px4_noGPS_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[37] = (sysRanDType *)&px4_noGPS_DW.Subsystem1_SubsysRanBC;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(px4_noGPS_M->extModeInfo,
      &px4_noGPS_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(px4_noGPS_M->extModeInfo, px4_noGPS_M->Sizes.checksums);
    rteiSetTPtr(px4_noGPS_M->extModeInfo, rtmGetTPtr(px4_noGPS_M));
  }

  // block I/O
  (void) memset((static_cast<void *>(&px4_noGPS_B)), 0,
                sizeof(B_px4_noGPS_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&px4_noGPS_DW), 0,
                sizeof(DW_px4_noGPS_T));

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    px4_noGPS_M->SpecialInfo.mappingInfo = (&dtInfo);
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

    // Start for DataStoreMemory: '<S43>/Data Store Memory'
    px4_noGPS_DW.start_time_yaw = px4_noGPS_P.DataStoreMemory_InitialValue;

    // Start for DataStoreMemory: '<S25>/Data Store Memory'
    px4_noGPS_DW.start_time = px4_noGPS_P.DataStoreMemory_InitialValue_l;

    // Start for DataStoreMemory: '<S34>/Data Store Memory'
    px4_noGPS_DW.start_time_roll = px4_noGPS_P.DataStoreMemory_InitialValue_b;

    // Start for Sum: '<S24>/Add' incorporates:
    //   DataStoreMemory: '<S1>/e_pitch'

    px4_noGPS_DW.e_pitch = px4_noGPS_P.e_pitch_InitialValue;

    // Start for Sum: '<S33>/Add' incorporates:
    //   DataStoreMemory: '<S1>/e_pitch1'

    px4_noGPS_DW.e_pitch_roll = px4_noGPS_P.e_pitch1_InitialValue;

    // Start for Sum: '<S42>/Add' incorporates:
    //   DataStoreMemory: '<S1>/e_pitch2'

    px4_noGPS_DW.e_pitch_yaw = px4_noGPS_P.e_pitch2_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory'
    px4_noGPS_DW.attitude_flag = px4_noGPS_P.DataStoreMemory_InitialValue_j;

    // Start for DataStoreMemory: '<Root>/Data Store Memory16'
    px4_noGPS_DW.yaw_speed = px4_noGPS_P.DataStoreMemory16_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory17'
    px4_noGPS_DW.roll_speed = px4_noGPS_P.DataStoreMemory17_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory18'
    px4_noGPS_DW.pitch_speed = px4_noGPS_P.DataStoreMemory18_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory19'
    px4_noGPS_DW.pitch_acc = px4_noGPS_P.DataStoreMemory19_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory20'
    px4_noGPS_DW.roll_acc = px4_noGPS_P.DataStoreMemory20_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory21'
    px4_noGPS_DW.yaw_acc = px4_noGPS_P.DataStoreMemory21_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory22'
    px4_noGPS_DW.roll_desire = px4_noGPS_P.DataStoreMemory22_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory23'
    px4_noGPS_DW.pitch_desire = px4_noGPS_P.DataStoreMemory23_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory24'
    px4_noGPS_DW.q_x = px4_noGPS_P.DataStoreMemory24_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory25'
    px4_noGPS_DW.q_y = px4_noGPS_P.DataStoreMemory25_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory26'
    px4_noGPS_DW.q_z = px4_noGPS_P.DataStoreMemory26_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory27'
    px4_noGPS_DW.position_flag = px4_noGPS_P.DataStoreMemory27_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory28'
    px4_noGPS_DW.lat = px4_noGPS_P.DataStoreMemory28_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory29'
    px4_noGPS_DW.t = px4_noGPS_P.DataStoreMemory29_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory30'
    px4_noGPS_DW.observer_flag = px4_noGPS_P.DataStoreMemory30_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory31'
    px4_noGPS_DW.lon = px4_noGPS_P.DataStoreMemory31_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory32'
    px4_noGPS_DW.alt = px4_noGPS_P.DataStoreMemory32_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory4'
    px4_noGPS_DW.pitch = px4_noGPS_P.DataStoreMemory4_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory6'
    px4_noGPS_DW.roll = px4_noGPS_P.DataStoreMemory6_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory8'
    px4_noGPS_DW.yaw = px4_noGPS_P.DataStoreMemory8_InitialValue;
    px4_noGPS_PrevZCX.Subsystem_Trig_ZCE_e = POS_ZCSIG;
    px4_noGPS_PrevZCX.Subsystem_Trig_ZCE_j = POS_ZCSIG;
    px4_noGPS_PrevZCX.Subsystem_Trig_ZCE = POS_ZCSIG;

    // InitializeConditions for UnitDelay: '<S41>/UD'
    //
    //  Block description for '<S41>/UD':
    //
    //   Store in Global RAM

    px4_noGPS_DW.UD_DSTATE = px4_noGPS_P.DiscreteDerivative1_ICPrevScale;

    // InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator3' 
    px4_noGPS_DW.DiscreteTimeIntegrator3_DSTATE =
      px4_noGPS_P.DiscreteTimeIntegrator3_IC;

    // InitializeConditions for UnitDelay: '<S23>/UD'
    //
    //  Block description for '<S23>/UD':
    //
    //   Store in Global RAM

    px4_noGPS_DW.UD_DSTATE_b = px4_noGPS_P.DiscreteDerivative1_ICPrevSca_o;

    // InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator3' 
    px4_noGPS_DW.DiscreteTimeIntegrator3_DSTAT_a =
      px4_noGPS_P.DiscreteTimeIntegrator3_IC_k;

    // InitializeConditions for UnitDelay: '<S32>/UD'
    //
    //  Block description for '<S32>/UD':
    //
    //   Store in Global RAM

    px4_noGPS_DW.UD_DSTATE_n = px4_noGPS_P.DiscreteDerivative1_ICPrevSca_d;

    // InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator3' 
    px4_noGPS_DW.DiscreteTimeIntegrator3_DSTAT_m =
      px4_noGPS_P.DiscreteTimeIntegrator3_IC_l;

    // InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' 
    px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE =
      px4_noGPS_P.DiscreteTimeIntegrator_IC_l;

    // InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' 
    px4_noGPS_DW.DiscreteTimeIntegrator1_DSTATE =
      px4_noGPS_P.DiscreteTimeIntegrator1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' 
    px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE_p =
      px4_noGPS_P.DiscreteTimeIntegrator_IC_h;

    // InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator1' 
    px4_noGPS_DW.DiscreteTimeIntegrator1_DSTAT_i =
      px4_noGPS_P.DiscreteTimeIntegrator1_IC_j;

    // InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' 
    px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE_f =
      px4_noGPS_P.DiscreteTimeIntegrator_IC_o;

    // InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator1' 
    px4_noGPS_DW.DiscreteTimeIntegrator1_DSTAT_g =
      px4_noGPS_P.DiscreteTimeIntegrator1_IC_c;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_dX'
    px4_noGPS_DW.Intgrt_dX_DSTATE = px4_noGPS_P.Intgrt_dX_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_dY'
    px4_noGPS_DW.Intgrt_dY_DSTATE = px4_noGPS_P.Intgrt_dY_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_ddY'
    px4_noGPS_DW.Intgrt_ddY_DSTATE = px4_noGPS_P.Intgrt_ddY_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_ddX'
    px4_noGPS_DW.Intgrt_ddX_DSTATE = px4_noGPS_P.Intgrt_ddX_IC;

    // InitializeConditions for UnitDelay: '<S54>/UD'
    //
    //  Block description for '<S54>/UD':
    //
    //   Store in Global RAM

    px4_noGPS_DW.UD_DSTATE_n2 = px4_noGPS_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for DiscreteIntegrator: '<S52>/Discrete-Time Integrator' 
    px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE_d =
      px4_noGPS_P.DiscreteTimeIntegrator_IC_f;

    // InitializeConditions for UnitDelay: '<S55>/UD'
    //
    //  Block description for '<S55>/UD':
    //
    //   Store in Global RAM

    px4_noGPS_DW.UD_DSTATE_m = px4_noGPS_P.DiscreteDerivative_ICPrevScal_g;

    // InitializeConditions for DiscreteIntegrator: '<S53>/Discrete-Time Integrator' 
    px4_noGPS_DW.DiscreteTimeIntegrator_DSTATE_i =
      px4_noGPS_P.DiscreteTimeIntegrator_IC_ff;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_dZ'
    px4_noGPS_DW.Intgrt_dZ_DSTATE = px4_noGPS_P.Intgrt_dZ_IC;

    // InitializeConditions for DiscreteIntegrator: '<Root>/Intgrt_ddZ'
    px4_noGPS_DW.Intgrt_ddZ_DSTATE = px4_noGPS_P.Intgrt_ddZ_IC;

    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S50>/In1' incorporates:
    //   Outport: '<S50>/Out1'

    px4_noGPS_B.In1_a = px4_noGPS_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S10>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S51>/In1' incorporates:
    //   Outport: '<S51>/Out1'

    px4_noGPS_B.In1 = px4_noGPS_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S10>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1'
    // InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' 
    px4_noGPS_DW.DiscreteTimeIntegrator_DSTAT_fj =
      px4_noGPS_P.DiscreteTimeIntegrator_IC;

    // End of SystemInitialize for SubSystem: '<Root>/Subsystem1'

    // Start for MATLABSystem: '<S10>/SourceBlock'
    px4_noGPS_DW.obj_n.matlabCodegenIsDeleted = false;
    px4_noGPS_DW.obj_n.isSetupComplete = false;
    px4_noGPS_DW.obj_n.isInitialized = 1;
    px4_noGPS_DW.obj_n.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(px4_noGPS_DW.obj_n.orbMetadataObj,
                         &px4_noGPS_DW.obj_n.eventStructObj);
    px4_noGPS_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
    //   Constant: '<Root>/Constant2'

    px4_noGPS_DW.obj.errorStatus = 0U;
    px4_noGPS_DW.obj.isInitialized = 0;
    px4_noGPS_DW.obj.matlabCodegenIsDeleted = false;
    px4_noGPS_SystemCore_setup(&px4_noGPS_DW.obj, rtb_DataStoreRead6,
      px4_noGPS_P.Constant2_Value_kf);

    // Start for MATLABSystem: '<S9>/SourceBlock'
    px4_noGPS_DW.obj_l.matlabCodegenIsDeleted = false;
    px4_noGPS_DW.obj_l.isSetupComplete = false;
    px4_noGPS_DW.obj_l.isInitialized = 1;
    px4_noGPS_DW.obj_l.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_read_initialize(px4_noGPS_DW.obj_l.orbMetadataObj,
                         &px4_noGPS_DW.obj_l.eventStructObj);
    px4_noGPS_DW.obj_l.isSetupComplete = true;
  }
}

// Model terminate function
void px4_noGPS_terminate(void)
{
  // Terminate for MATLABSystem: '<S10>/SourceBlock'
  if (!px4_noGPS_DW.obj_n.matlabCodegenIsDeleted) {
    px4_noGPS_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((px4_noGPS_DW.obj_n.isInitialized == 1) &&
        px4_noGPS_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&px4_noGPS_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S10>/SourceBlock'

  // Terminate for MATLABSystem: '<Root>/PX4 PWM Output1'
  if (!px4_noGPS_DW.obj.matlabCodegenIsDeleted) {
    px4_noGPS_DW.obj.matlabCodegenIsDeleted = true;
    if ((px4_noGPS_DW.obj.isInitialized == 1) &&
        px4_noGPS_DW.obj.isSetupComplete) {
      uint16_T status;
      status = pwm_disarm(&px4_noGPS_DW.obj.pwmDevHandler,
                          &px4_noGPS_DW.obj.armAdvertiseObj);
      px4_noGPS_DW.obj.errorStatus = static_cast<uint16_T>
        (px4_noGPS_DW.obj.errorStatus | status);
      status = pwm_resetServo(&px4_noGPS_DW.obj.pwmDevHandler,
        px4_noGPS_DW.obj.servoCount, px4_noGPS_DW.obj.channelMask,
        px4_noGPS_DW.obj.isMain, &px4_noGPS_DW.obj.actuatorAdvertiseObj);
      px4_noGPS_DW.obj.errorStatus = static_cast<uint16_T>
        (px4_noGPS_DW.obj.errorStatus | status);
      status = pwm_close(&px4_noGPS_DW.obj.pwmDevHandler,
                         &px4_noGPS_DW.obj.actuatorAdvertiseObj,
                         &px4_noGPS_DW.obj.armAdvertiseObj);
      px4_noGPS_DW.obj.errorStatus = static_cast<uint16_T>
        (px4_noGPS_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 PWM Output1'

  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!px4_noGPS_DW.obj_l.matlabCodegenIsDeleted) {
    px4_noGPS_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((px4_noGPS_DW.obj_l.isInitialized == 1) &&
        px4_noGPS_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&px4_noGPS_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
