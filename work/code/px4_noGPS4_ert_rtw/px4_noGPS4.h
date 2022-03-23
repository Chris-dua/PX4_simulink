//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4_noGPS4.h
//
// Code generated for Simulink model 'px4_noGPS4'.
//
// Model version                  : 5.150
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Mar 23 21:49:27 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_px4_noGPS4_h_
#define RTW_HEADER_px4_noGPS4_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "px4_noGPS4_types.h"
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/actuator_outputs.h>

extern "C" {

#include "rtGetInf.h"

}
#include <float.h>
#include <string.h>

extern "C" {

#include "rt_nonfinite.h"

}
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

// Block signals (default storage)
struct B_px4_noGPS4_T {
  px4_Bus_vehicle_odometry In1;        // '<S23>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  px4_Bus_actuator_outputs In1_a;      // '<S22>/In1'
  px4_Bus_actuator_outputs b_varargout_2_m;
  uint16_T pwmValue[8];
  real_T DataStore;                    // '<Root>/Data Store '
  real_T Gain5;                        // '<Root>/Gain5'
  real_T Gain3;                        // '<Root>/Gain3'
  real_T DataStoreRead13;              // '<Root>/Data Store Read13'
  real_T DataStoreRead15;              // '<Root>/Data Store Read15'
  real_T DataStoreRead16;              // '<Root>/Data Store Read16'
  real_T DataStoreRead17;              // '<Root>/Data Store Read17'
  real_T DataStoreRead19;              // '<Root>/Data Store Read19'
  real_T Gain6;                        // '<Root>/Gain6'
  real_T DataStoreRead25;              // '<Root>/Data Store Read25'
  real_T DataStoreRead26;              // '<Root>/Data Store Read26'
  real_T DataStoreRead27;              // '<Root>/Data Store Read27'
  real_T pitch_thrust;                 // '<Root>/Data Store Read28'
  real_T roll_thrust;                  // '<Root>/Data Store Read29'
  real_T yaw_thrust;                   // '<Root>/Data Store Read32'
  real_T tau_thrust;                   // '<Root>/Data Store Read73'
  real_T pitch;                        // '<Root>/Gain8'
  real_T pitch_desire;                 // '<Root>/Gain10'
  real_T roll;                         // '<Root>/Gain7'
  real_T roll_desire;                  // '<Root>/Gain11'
  real_T yaw;                          // '<Root>/Gain9'
  real_T DataStoreRead34;              // '<Root>/Data Store Read34'
  real_T DataStoreRead35;              // '<Root>/Data Store Read35'
  real_T DataStoreRead36;              // '<Root>/Data Store Read36'
  real_T DataStoreRead37;              // '<Root>/Data Store Read37'
  real_T DataStoreRead38;              // '<Root>/Data Store Read38'
  real_T DataStoreRead39;              // '<Root>/Data Store Read39'
  real_T DataStoreRead42;              // '<Root>/Data Store Read42'
  real_T DataStoreRead43;              // '<Root>/Data Store Read43'
  real_T DataStoreRead44;              // '<Root>/Data Store Read44'
  real_T DataStoreRead48;              // '<Root>/Data Store Read48'
  real_T DataStoreRead49;              // '<Root>/Data Store Read49'
  real_T DataStoreRead55;              // '<Root>/Data Store Read55'
  real_T DataStoreRead8;               // '<Root>/Data Store Read8'
  real_T DataStoreRead9;               // '<Root>/Data Store Read9'
  real32_T output[16];
                 // '<Root>/BusConversion_InsertedFor_Bus Selector_at_inport_0'
  real_T Add3;                         // '<S15>/Add3'
  real_T TSamp;                        // '<S20>/TSamp'
  real_T Add4;                         // '<S15>/Add4'
  real_T TSamp_k;                      // '<S21>/TSamp'
  real_T TSamp_e;                      // '<S16>/TSamp'
  real_T Product2_d;                   // '<S31>/Product2'
  real_T TSamp_g;                      // '<S17>/TSamp'
  real_T TSamp_i;                      // '<S18>/TSamp'
  real_T x1_dot;                       // '<S25>/Subtract1'
  real_T TSamp_d;                      // '<S19>/TSamp'
  boolean_T NOT;                       // '<S6>/NOT'
  boolean_T DataStoreRead12;           // '<Root>/Data Store Read12'
};

// Block states (default storage) for system '<Root>'
struct DW_px4_noGPS4_T {
  px4_internal_block_PWM_px4_no_T obj; // '<Root>/PX4 PWM Output1'
  px4_internal_block_Subscriber_T obj_n;// '<S6>/SourceBlock'
  px4_internal_block_Subscriber_T obj_l;// '<S5>/SourceBlock'
  real_T UD_DSTATE;                    // '<S20>/UD'
  real_T UD_DSTATE_f;                  // '<S21>/UD'
  real_T UD_DSTATE_j;                  // '<S16>/UD'
  real_T UD_DSTATE_l;                  // '<S17>/UD'
  real_T UD_DSTATE_m;                  // '<S18>/UD'
  real_T UD_DSTATE_n;                  // '<S19>/UD'
  real_T Intgrt_dX_DSTATE;             // '<Root>/Intgrt_dX'
  real_T Intgrt_dY_DSTATE;             // '<Root>/Intgrt_dY'
  real_T Intgrt_ddY_DSTATE;            // '<Root>/Intgrt_ddY'
  real_T Intgrt_ddX_DSTATE;            // '<Root>/Intgrt_ddX'
  real_T UD_DSTATE_g;                  // '<S26>/UD'
  real_T UD_DSTATE_c;                  // '<S27>/UD'
  real_T UD_DSTATE_n3;                 // '<S28>/UD'
  real_T UD_DSTATE_nw;                 // '<S29>/UD'
  real_T Intgrt_dZ_DSTATE;             // '<Root>/Intgrt_dZ'
  real_T Intgrt_ddZ_DSTATE;            // '<Root>/Intgrt_ddZ'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S9>/Discrete-Time Integrator'
  real_T s6_yaw;                       // '<S15>/Data Store Memory'
  real_T s4_pitch;                     // '<S13>/Data Store Memory'
  real_T s5_roll;                      // '<S14>/Data Store Memory'
  real_T yaw_speed;                    // '<Root>/Data Store Memory16'
  real_T roll_speed;                   // '<Root>/Data Store Memory17'
  real_T pitch_speed;                  // '<Root>/Data Store Memory18'
  real_T pitch_acc;                    // '<Root>/Data Store Memory19'
  real_T roll_acc;                     // '<Root>/Data Store Memory20'
  real_T yaw_acc;                      // '<Root>/Data Store Memory21'
  real_T roll_desire;                  // '<Root>/Data Store Memory22'
  real_T pitch_desire;                 // '<Root>/Data Store Memory23'
  real_T q_x;                          // '<Root>/Data Store Memory24'
  real_T q_y;                          // '<Root>/Data Store Memory25'
  real_T q_z;                          // '<Root>/Data Store Memory26'
  real_T lat;                          // '<Root>/Data Store Memory28'
  real_T t;                            // '<Root>/Data Store Memory29'
  real_T lon;                          // '<Root>/Data Store Memory31'
  real_T alt;                          // '<Root>/Data Store Memory32'
  real_T U1;                           // '<Root>/Data Store Memory36'
  real_T pitch;                        // '<Root>/Data Store Memory4'
  real_T roll;                         // '<Root>/Data Store Memory6'
  real_T yaw;                          // '<Root>/Data Store Memory8'
  struct {
    void *LoggedData[4];
  } Scope1_PWORK;                      // '<Root>/Scope1'

  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       // '<Root>/Scope'

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      // '<Root>/Scope2'

  int8_T Subsystem1_SubsysRanBC;       // '<Root>/Subsystem1'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S32>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S32>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S32>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S6>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_b;// '<S5>/Enabled Subsystem'
  boolean_T attitude_flag;             // '<Root>/Data Store Memory'
  boolean_T position_flag;             // '<Root>/Data Store Memory27'
};

// Parameters (default storage)
struct P_px4_noGPS4_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S20>/UD'

  real_T DiscreteDerivative2_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative2_ICPrevScale
                                 //  Referenced by: '<S21>/UD'

  real_T DiscreteDerivative_ICPrevScal_k;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_k
                                 //  Referenced by: '<S16>/UD'

  real_T DiscreteDerivative2_ICPrevSca_a;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_a
                                 //  Referenced by: '<S17>/UD'

  real_T DiscreteDerivative_ICPrevScal_a;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_a
                                 //  Referenced by: '<S18>/UD'

  real_T DiscreteDerivative2_ICPrevSca_o;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_o
                                 //  Referenced by: '<S19>/UD'

  real_T DiscreteDerivative_ICPrevScal_f;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_f
                                 //  Referenced by: '<S26>/UD'

  real_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S27>/UD'

  real_T DiscreteDerivative_ICPrevScal_e;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_e
                                 //  Referenced by: '<S28>/UD'

  real_T DiscreteDerivative1_ICPrevSca_k;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_k
                                 //  Referenced by: '<S29>/UD'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S23>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S6>/Constant'

  px4_Bus_actuator_outputs Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S22>/Out1'

  px4_Bus_actuator_outputs Constant_Value_c;// Computed Parameter: Constant_Value_c
                                               //  Referenced by: '<S5>/Constant'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S13>/Constant2'

  real_T Constant3_Value;              // Expression: 1
                                          //  Referenced by: '<S13>/Constant3'

  real_T Constant4_Value;              // Expression: -1
                                          //  Referenced by: '<S13>/Constant4'

  real_T Constant2_Value_l;            // Expression: 0
                                          //  Referenced by: '<S14>/Constant2'

  real_T Constant3_Value_b;            // Expression: 1
                                          //  Referenced by: '<S14>/Constant3'

  real_T Constant4_Value_j;            // Expression: -1
                                          //  Referenced by: '<S14>/Constant4'

  real_T Constant2_Value_a;            // Expression: 0
                                          //  Referenced by: '<S15>/Constant2'

  real_T Constant3_Value_p;            // Expression: 1
                                          //  Referenced by: '<S15>/Constant3'

  real_T Switch2_Threshold;            // Expression: 0
                                          //  Referenced by: '<S15>/Switch2'

  real_T Gain8_Gain;                   // Expression: -0.1
                                          //  Referenced by: '<S15>/Gain8'

  real_T Constant_Value_f;             // Expression: 1.25
                                          //  Referenced by: '<S15>/Constant'

  real_T Gain5_Gain;                   // Expression: 0.2
                                          //  Referenced by: '<S15>/Gain5'

  real_T Gain6_Gain;                   // Expression: 0.012
                                          //  Referenced by: '<S15>/Gain6'

  real_T Gain4_Gain;                   // Expression: -50
                                          //  Referenced by: '<S15>/Gain4'

  real_T Gain3_Gain;                   // Expression: 50
                                          //  Referenced by: '<S15>/Gain3'

  real_T Gain2_Gain;                   // Expression: -4.854809437386564
                                          //  Referenced by: '<S15>/Gain2'

  real_T Saturation_UpperSat;          // Expression: 0.1
                                          //  Referenced by: '<S1>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.1
                                          //  Referenced by: '<S1>/Saturation'

  real_T Constant_Value_d;             // Expression: 0
                                          //  Referenced by: '<S1>/Constant'

  real_T Constant_Value_p;             // Expression: 1
                                          //  Referenced by: '<S24>/Constant'

  real_T Constant2_Value_o;            // Expression: -1
                                          //  Referenced by: '<S24>/Constant2'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S24>/Constant1'

  real_T Constant_Value_j;             // Expression: 1
                                          //  Referenced by: '<S25>/Constant'

  real_T Constant2_Value_e;            // Expression: -1
                                          //  Referenced by: '<S25>/Constant2'

  real_T Constant1_Value_d;            // Expression: 0
                                          //  Referenced by: '<S25>/Constant1'

  real_T Constant_Value_e;             // Expression: 1
                                          //  Referenced by: '<S33>/Constant'

  real_T Constant_Value_b;             // Expression: 1
                                          //  Referenced by: '<S34>/Constant'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S9>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                          //  Referenced by: '<S9>/Discrete-Time Integrator'

  real_T Constant9_Value;              // Expression: 1
                                          //  Referenced by: '<S9>/Constant9'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant5'

  real_T Constant7_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant7'

  real_T Constant8_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant8'

  real_T e_pitch_InitialValue;         // Expression: 0
                                          //  Referenced by: '<S1>/e_pitch'

  real_T e_pitch1_InitialValue;        // Expression: 0
                                          //  Referenced by: '<S1>/e_pitch1'

  real_T e_pitch2_InitialValue;        // Expression: 0
                                          //  Referenced by: '<S1>/e_pitch2'

  real_T DataStoreMemory33_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory33'

  real_T DataStoreMemory34_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory34'

  real_T DataStoreMemory35_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory35'

  real_T DataStoreMemory5_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Data Store Memory5'

  real_T TSamp_WtEt;                   // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S20>/TSamp'

  real_T TSamp_WtEt_l;                 // Computed Parameter: TSamp_WtEt_l
                                          //  Referenced by: '<S21>/TSamp'

  real_T Gain3_Gain_m;                 // Expression: 50
                                          //  Referenced by: '<S13>/Gain3'

  real_T TSamp_WtEt_m;                 // Computed Parameter: TSamp_WtEt_m
                                          //  Referenced by: '<S16>/TSamp'

  real_T Gain2_Gain_n;                 // Expression: -40
                                          //  Referenced by: '<S13>/Gain2'

  real_T Gain4_Gain_i;                 // Expression: -50
                                          //  Referenced by: '<S13>/Gain4'

  real_T Gain5_Gain_j;                 // Expression: 0.2
                                          //  Referenced by: '<S13>/Gain5'

  real_T Gain6_Gain_b;                 // Expression: 0.012
                                          //  Referenced by: '<S13>/Gain6'

  real_T Constant_Value_bt;            // Expression: 1.25
                                          //  Referenced by: '<S13>/Constant'

  real_T TSamp_WtEt_j;                 // Computed Parameter: TSamp_WtEt_j
                                          //  Referenced by: '<S17>/TSamp'

  real_T Switch2_Threshold_m;          // Expression: 0
                                          //  Referenced by: '<S13>/Switch2'

  real_T Gain8_Gain_e;                 // Expression: -0.1
                                          //  Referenced by: '<S13>/Gain8'

  real_T Gain3_Gain_f;                 // Expression: 50
                                          //  Referenced by: '<S14>/Gain3'

  real_T TSamp_WtEt_h;                 // Computed Parameter: TSamp_WtEt_h
                                          //  Referenced by: '<S18>/TSamp'

  real_T Gain2_Gain_o;                 // Expression: -4.854809437386564
                                          //  Referenced by: '<S14>/Gain2'

  real_T Gain4_Gain_g;                 // Expression: -50
                                          //  Referenced by: '<S14>/Gain4'

  real_T Gain5_Gain_p;                 // Expression: 0.2
                                          //  Referenced by: '<S14>/Gain5'

  real_T Gain6_Gain_a;                 // Expression: 0.012
                                          //  Referenced by: '<S14>/Gain6'

  real_T Constant_Value_n;             // Expression: 1.25
                                          //  Referenced by: '<S14>/Constant'

  real_T TSamp_WtEt_g;                 // Computed Parameter: TSamp_WtEt_g
                                          //  Referenced by: '<S19>/TSamp'

  real_T Switch2_Threshold_h;          // Expression: 0
                                          //  Referenced by: '<S14>/Switch2'

  real_T Gain8_Gain_p;                 // Expression: -0.1
                                          //  Referenced by: '<S14>/Gain8'

  real_T Gain7_Gain;                   // Expression: -4.896830143540669
                                          //  Referenced by: '<S15>/Gain7'

  real_T DataStoreMemory_InitialValue; // Expression: 0
                                          //  Referenced by: '<S15>/Data Store Memory'

  real_T Gain7_Gain_c;                 // Expression: -49.03250773993808
                                          //  Referenced by: '<S13>/Gain7'

  real_T DataStoreMemory_InitialValue_f;// Expression: 0
                                           //  Referenced by: '<S13>/Data Store Memory'

  real_T Gain7_Gain_i;                 // Expression: -5
                                          //  Referenced by: '<S14>/Gain7'

  real_T DataStoreMemory_InitialValue_l;// Expression: 0
                                           //  Referenced by: '<S14>/Data Store Memory'

  real_T Intgrt_dX_gainval;            // Computed Parameter: Intgrt_dX_gainval
                                          //  Referenced by: '<Root>/Intgrt_dX'

  real_T Intgrt_dX_IC;                 // Expression: 0
                                          //  Referenced by: '<Root>/Intgrt_dX'

  real_T Intgrt_dY_gainval;            // Computed Parameter: Intgrt_dY_gainval
                                          //  Referenced by: '<Root>/Intgrt_dY'

  real_T Intgrt_dY_IC;                 // Expression: 0
                                          //  Referenced by: '<Root>/Intgrt_dY'

  real_T Intgrt_ddY_gainval;           // Computed Parameter: Intgrt_ddY_gainval
                                          //  Referenced by: '<Root>/Intgrt_ddY'

  real_T Intgrt_ddY_IC;                // Expression: 0
                                          //  Referenced by: '<Root>/Intgrt_ddY'

  real_T Intgrt_ddX_gainval;           // Computed Parameter: Intgrt_ddX_gainval
                                          //  Referenced by: '<Root>/Intgrt_ddX'

  real_T Intgrt_ddX_IC;                // Expression: 0
                                          //  Referenced by: '<Root>/Intgrt_ddX'

  real_T Constant6_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant6'

  real_T K1_Gain;                      // Expression: 5
                                          //  Referenced by: '<S24>/K1'

  real_T TSamp_WtEt_c;                 // Computed Parameter: TSamp_WtEt_c
                                          //  Referenced by: '<S26>/TSamp'

  real_T C1_Gain;                      // Expression: -5.99814967105263
                                          //  Referenced by: '<S24>/C1'

  real_T C3_Gain;                      // Expression: -5
                                          //  Referenced by: '<S24>/C3'

  real_T C4_Gain;                      // Expression: -6.98499177631578
                                          //  Referenced by: '<S24>/C4'

  real_T Switch1_Threshold;            // Expression: 0
                                          //  Referenced by: '<S24>/Switch1'

  real_T Gain_Gain;                    // Expression: -0.1
                                          //  Referenced by: '<S24>/Gain'

  real_T k3_Gain;                      // Expression: 0.01
                                          //  Referenced by: '<S24>/k3'

  real_T Constant3_Value_h;            // Expression: 2
                                          //  Referenced by: '<S24>/Constant3'

  real_T TSamp_WtEt_l2;                // Computed Parameter: TSamp_WtEt_l2
                                          //  Referenced by: '<S27>/TSamp'

  real_T Gain2_Gain_oq;                // Expression: 0.01
                                          //  Referenced by: '<S7>/Gain2'

  real_T Saturation1_UpperSat;         // Expression: 0.5
                                          //  Referenced by: '<S7>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -0.5
                                          //  Referenced by: '<S7>/Saturation1'

  real_T Constant_Value_i;             // Expression: 0
                                          //  Referenced by: '<S7>/Constant'

  real_T k2_Gain;                      // Expression: 5
                                          //  Referenced by: '<S25>/k2'

  real_T TSamp_WtEt_p;                 // Computed Parameter: TSamp_WtEt_p
                                          //  Referenced by: '<S28>/TSamp'

  real_T C1_Gain_j;                    // Expression: -5.107574679943099
                                          //  Referenced by: '<S25>/C1'

  real_T k1_Gain;                      // Expression: -5
                                          //  Referenced by: '<S25>/k1'

  real_T C2_Gain;                      // Expression: -6.814544807965859
                                          //  Referenced by: '<S25>/C2'

  real_T Switch1_Threshold_k;          // Expression: 0
                                          //  Referenced by: '<S25>/Switch1'

  real_T Gain_Gain_a;                  // Expression: -0.1
                                          //  Referenced by: '<S25>/Gain'

  real_T k3_Gain_f;                    // Expression: 0.01
                                          //  Referenced by: '<S25>/k3'

  real_T Constant3_Value_f;            // Expression: 2
                                          //  Referenced by: '<S25>/Constant3'

  real_T TSamp_WtEt_i;                 // Computed Parameter: TSamp_WtEt_i
                                          //  Referenced by: '<S29>/TSamp'

  real_T Gain4_Gain_c;                 // Expression: 0.01
                                          //  Referenced by: '<S7>/Gain4'

  real_T Saturation2_UpperSat;         // Expression: 0.5
                                          //  Referenced by: '<S7>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -0.5
                                          //  Referenced by: '<S7>/Saturation2'

  real_T Saturation2_UpperSat_b;       // Expression: 1.5
                                          //  Referenced by: '<Root>/Saturation2'

  real_T Saturation2_LowerSat_m;       // Expression: 1
                                          //  Referenced by: '<Root>/Saturation2'

  real_T fault_1_Value;                // Expression: 0
                                          //  Referenced by: '<Root>/fault_1'

  real_T Mixermatrix1_Value[16];
                          // Expression: [1 1 -1 1;1 -1 1 1;1 1 1 -1;1 -1 -1 -1]
                             //  Referenced by: '<Root>/Mixer matrix1'

  real_T Gain4_Gain_f;                 // Expression: 1000
                                          //  Referenced by: '<Root>/Gain4'

  real_T fault_2_Value;                // Expression: 0.3835227272727273
                                          //  Referenced by: '<Root>/fault_2'

  real_T fault_3_Value;                // Expression: 0
                                          //  Referenced by: '<Root>/fault_3'

  real_T fault_4_Value;                // Expression: 0
                                          //  Referenced by: '<Root>/fault_4'

  real_T Intgrt_dZ_gainval;            // Computed Parameter: Intgrt_dZ_gainval
                                          //  Referenced by: '<Root>/Intgrt_dZ'

  real_T Intgrt_dZ_IC;                 // Expression: 0
                                          //  Referenced by: '<Root>/Intgrt_dZ'

  real_T Intgrt_ddZ_gainval;           // Computed Parameter: Intgrt_ddZ_gainval
                                          //  Referenced by: '<Root>/Intgrt_ddZ'

  real_T Intgrt_ddZ_IC;                // Expression: 0
                                          //  Referenced by: '<Root>/Intgrt_ddZ'

  real_T Saturation1_UpperSat_k;       // Expression: inf
                                          //  Referenced by: '<Root>/Saturation1'

  real_T Saturation1_LowerSat_c;       // Expression: 0
                                          //  Referenced by: '<Root>/Saturation1'

  real_T slower3_Gain;                 // Expression: 1
                                          //  Referenced by: '<Root>/slower3'

  real_T slower4_Gain;                 // Expression: 1
                                          //  Referenced by: '<Root>/slower4'

  real_T slower5_Gain;                 // Expression: 1
                                          //  Referenced by: '<Root>/slower5'

  real_T Gain5_Gain_g;                 // Expression: 180/3.1415926
                                          //  Referenced by: '<Root>/Gain5'

  real_T Gain3_Gain_c;                 // Expression: 180/3.1415926
                                          //  Referenced by: '<Root>/Gain3'

  real_T Gain6_Gain_k;                 // Expression: 180/3.1415926
                                          //  Referenced by: '<Root>/Gain6'

  real_T Gain8_Gain_o;                 // Expression: 180/3.1415926
                                          //  Referenced by: '<Root>/Gain8'

  real_T Gain10_Gain;                  // Expression: 180/3.1415926
                                          //  Referenced by: '<Root>/Gain10'

  real_T Gain7_Gain_a;                 // Expression: 180/3.1415926
                                          //  Referenced by: '<Root>/Gain7'

  real_T Gain11_Gain;                  // Expression: 180/3.1415926
                                          //  Referenced by: '<Root>/Gain11'

  real_T Gain9_Gain;                   // Expression: 180/3.1415926
                                          //  Referenced by: '<Root>/Gain9'

  real_T DataStoreMemory10_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory10'

  real_T DataStoreMemory11_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory11'

  real_T DataStoreMemory12_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory12'

  real_T DataStoreMemory13_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory13'

  real_T DataStoreMemory14_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory14'

  real_T DataStoreMemory15_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory15'

  real_T DataStoreMemory16_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory16'

  real_T DataStoreMemory17_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory17'

  real_T DataStoreMemory18_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory18'

  real_T DataStoreMemory19_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory19'

  real_T DataStoreMemory2_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Data Store Memory2'

  real_T DataStoreMemory20_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory20'

  real_T DataStoreMemory21_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory21'

  real_T DataStoreMemory22_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory22'

  real_T DataStoreMemory23_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory23'

  real_T DataStoreMemory24_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory24'

  real_T DataStoreMemory25_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory25'

  real_T DataStoreMemory26_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory26'

  real_T DataStoreMemory28_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory28'

  real_T DataStoreMemory29_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory29'

  real_T DataStoreMemory3_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Data Store Memory3'

  real_T DataStoreMemory31_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory31'

  real_T DataStoreMemory32_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory32'

  real_T DataStoreMemory36_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory36'

  real_T DataStoreMemory4_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Data Store Memory4'

  real_T DataStoreMemory6_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Data Store Memory6'

  real_T DataStoreMemory7_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Data Store Memory7'

  real_T DataStoreMemory8_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Data Store Memory8'

  real_T DataStoreMemory9_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Data Store Memory9'

  boolean_T Reset_Value;               // Computed Parameter: Reset_Value
                                          //  Referenced by: '<Root>/Reset'

  boolean_T attitude_flag_Value;      // Computed Parameter: attitude_flag_Value
                                         //  Referenced by: '<S10>/attitude_flag'

  boolean_T observer_flag_Value;      // Computed Parameter: observer_flag_Value
                                         //  Referenced by: '<S11>/observer_flag'

  boolean_T position_flag_Value;      // Computed Parameter: position_flag_Value
                                         //  Referenced by: '<S12>/position_flag'

  boolean_T Constant2_Value_k;         // Computed Parameter: Constant2_Value_k
                                          //  Referenced by: '<Root>/Constant2'

  boolean_T DataStoreMemory_InitialValue_b;
                           // Computed Parameter: DataStoreMemory_InitialValue_b
                              //  Referenced by: '<Root>/Data Store Memory'

  boolean_T DataStoreMemory1_InitialValue;
                            // Computed Parameter: DataStoreMemory1_InitialValue
                               //  Referenced by: '<Root>/Data Store Memory1'

  boolean_T DataStoreMemory27_InitialValue;
                           // Computed Parameter: DataStoreMemory27_InitialValue
                              //  Referenced by: '<Root>/Data Store Memory27'

  boolean_T DataStoreMemory30_InitialValue;
                           // Computed Parameter: DataStoreMemory30_InitialValue
                              //  Referenced by: '<Root>/Data Store Memory30'

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<S1>/Manual Switch'

};

// Real-time Model Data Structure
struct tag_RTM_px4_noGPS4_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_px4_noGPS4_T px4_noGPS4_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_px4_noGPS4_T px4_noGPS4_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_px4_noGPS4_T px4_noGPS4_DW;

// External function called from main
#ifdef __cplusplus

extern "C" {

#endif

  extern void px4_noGPS4_SetEventsForThisBaseStep(boolean_T *eventFlags);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void px4_noGPS4_SetEventsForThisBaseStep(boolean_T *eventFlags);
  extern void px4_noGPS4_initialize(void);
  extern void px4_noGPS4_step0(void);
  extern void px4_noGPS4_step1(void);
  extern void px4_noGPS4_step(int_T tid);
  extern void px4_noGPS4_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_px4_noGPS4_T *const px4_noGPS4_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'px4_noGPS4'
//  '<S1>'   : 'px4_noGPS4/Attitude controller'
//  '<S2>'   : 'px4_noGPS4/MATLAB Function1'
//  '<S3>'   : 'px4_noGPS4/MATLAB Function3'
//  '<S4>'   : 'px4_noGPS4/MATLAB Function5'
//  '<S5>'   : 'px4_noGPS4/PX4 uORB Read'
//  '<S6>'   : 'px4_noGPS4/PX4 uORB Read2'
//  '<S7>'   : 'px4_noGPS4/Position controller'
//  '<S8>'   : 'px4_noGPS4/Quaternions to Rotation Angles'
//  '<S9>'   : 'px4_noGPS4/Subsystem1'
//  '<S10>'  : 'px4_noGPS4/attitude_button'
//  '<S11>'  : 'px4_noGPS4/observer_button'
//  '<S12>'  : 'px4_noGPS4/position_button'
//  '<S13>'  : 'px4_noGPS4/Attitude controller/Subsystem'
//  '<S14>'  : 'px4_noGPS4/Attitude controller/Subsystem6'
//  '<S15>'  : 'px4_noGPS4/Attitude controller/Subsystem7'
//  '<S16>'  : 'px4_noGPS4/Attitude controller/Subsystem/Discrete Derivative'
//  '<S17>'  : 'px4_noGPS4/Attitude controller/Subsystem/Discrete Derivative2'
//  '<S18>'  : 'px4_noGPS4/Attitude controller/Subsystem6/Discrete Derivative'
//  '<S19>'  : 'px4_noGPS4/Attitude controller/Subsystem6/Discrete Derivative2'
//  '<S20>'  : 'px4_noGPS4/Attitude controller/Subsystem7/Discrete Derivative'
//  '<S21>'  : 'px4_noGPS4/Attitude controller/Subsystem7/Discrete Derivative2'
//  '<S22>'  : 'px4_noGPS4/PX4 uORB Read/Enabled Subsystem'
//  '<S23>'  : 'px4_noGPS4/PX4 uORB Read2/Enabled Subsystem'
//  '<S24>'  : 'px4_noGPS4/Position controller/Subsystem1'
//  '<S25>'  : 'px4_noGPS4/Position controller/Subsystem3'
//  '<S26>'  : 'px4_noGPS4/Position controller/Subsystem1/Discrete Derivative'
//  '<S27>'  : 'px4_noGPS4/Position controller/Subsystem1/Discrete Derivative1'
//  '<S28>'  : 'px4_noGPS4/Position controller/Subsystem3/Discrete Derivative'
//  '<S29>'  : 'px4_noGPS4/Position controller/Subsystem3/Discrete Derivative1'
//  '<S30>'  : 'px4_noGPS4/Quaternions to Rotation Angles/Angle Calculation'
//  '<S31>'  : 'px4_noGPS4/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S32>'  : 'px4_noGPS4/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S33>'  : 'px4_noGPS4/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S34>'  : 'px4_noGPS4/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S35>'  : 'px4_noGPS4/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S36>'  : 'px4_noGPS4/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S37>'  : 'px4_noGPS4/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                                 // RTW_HEADER_px4_noGPS4_h_

//
// File trailer for generated code.
//
// [EOF]
//
