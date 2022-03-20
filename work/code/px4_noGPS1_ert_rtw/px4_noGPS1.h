//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4_noGPS1.h
//
// Code generated for Simulink model 'px4_noGPS1'.
//
// Model version                  : 5.149
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sun Mar 20 13:02:07 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_px4_noGPS1_h_
#define RTW_HEADER_px4_noGPS1_h_
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
#include "px4_noGPS1_types.h"
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/actuator_outputs.h>
#include <float.h>
#include <string.h>

extern "C" {

#include "rt_nonfinite.h"

}
#include <stddef.h>
#include "zero_crossing_types.h"

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
struct B_px4_noGPS1_T {
  px4_Bus_vehicle_odometry In1;        // '<S47>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  px4_Bus_actuator_outputs In1_a;      // '<S46>/In1'
  px4_Bus_actuator_outputs b_varargout_2_m;
  uint16_T pwmValue[8];
  real_T Gain2;                        // '<S1>/Gain2'
  real_T J;                            // '<S1>/J'
  real_T DataStoreRead4;               // '<S39>/Data Store Read4'
  real_T DataStoreRead4_g;             // '<S21>/Data Store Read4'
  real_T DataStoreRead4_b;             // '<S30>/Data Store Read4'
  real_T rolldegree;                   // '<S18>/Gain2'
  real_T rolldegree_l;                 // '<S16>/Gain2'
  real_T rolldegree_c;                 // '<S17>/Gain2'
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
  real_T DataStoreRead73;              // '<Root>/Data Store Read73'
  real_T pitch;                        // '<Root>/Gain8'
  real_T pitch_a;                      // '<Root>/Gain10'
  real_T roll;                         // '<Root>/Gain7'
  real_T pitch_g;                      // '<Root>/Gain11'
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
  real_T y;                            // '<S39>/MATLAB Function'
  real_T y_o;                          // '<S30>/MATLAB Function'
  real_T y_j;                          // '<S21>/MATLAB Function'
  real32_T output[16];
                 // '<Root>/BusConversion_InsertedFor_Bus Selector_at_inport_0'
  real_T roll_hat;                     // '<S18>/Discrete-Time Integrator'
  real_T z2;                           // '<S18>/Discrete-Time Integrator3'
  real_T TSamp;                        // '<S37>/TSamp'
  real_T Add3;                         // '<S1>/Add3'
  real_T z2_e;                         // '<S16>/Discrete-Time Integrator3'
  real_T z2_l;                         // '<S17>/Discrete-Time Integrator3'
  real_T Gain4;                        // '<S7>/Gain4'
  real_T ZeroOrderHold1;               // '<S49>/Zero-Order Hold1'
  real_T roll_hat_e;                   // '<S16>/Discrete-Time Integrator'
  real_T Product4;                     // '<S18>/Product4'
  real_T Product5;                     // '<S18>/Product5'
  real_T lambda1_a;                    // '<S16>/lambda1'
  real_T DiscreteTimeIntegrator_n;     // '<S48>/Discrete-Time Integrator'
  real_T roll_hat_k;                   // '<S17>/Discrete-Time Integrator'
  real_T Product3_a;                   // '<S16>/Product3'
  real_T Product4_k;                   // '<S16>/Product4'
  real_T Product6_i;                   // '<S16>/Product6'
  real_T Product5_b;                   // '<S16>/Product5'
  real_T Add2_o;                       // '<S16>/Add2'
  real_T lambda4_n;                    // '<S16>/lambda4'
  real_T lambda1_e;                    // '<S17>/lambda1'
  real_T ZeroOrderHold2_b;             // '<S48>/Zero-Order Hold2'
  real_T ZeroOrderHold1_p;             // '<S48>/Zero-Order Hold1'
  real_T Product3_c;                   // '<S17>/Product3'
  real_T Product4_g;                   // '<S17>/Product4'
  real_T Product6_a;                   // '<S17>/Product6'
  real_T Product5_l;                   // '<S17>/Product5'
  real_T Add2_g;                       // '<S17>/Add2'
  real_T lambda4_h;                    // '<S17>/lambda4'
  real_T rtb_Fcn_a_c;
  real_T rtb_Fcn_b_k;
  real_T rtb_Fcn_c;
  real_T rtb_ZeroOrderHold1_tmp;
  real_T rtb_DataTypeConversion3_idx_0;
  real_T rtb_DataTypeConversion3_idx_1;
  real_T rtb_DataTypeConversion3_idx_2;
  uint16_T Gain4_f[4];                 // '<Root>/Gain4'
  boolean_T NOT;                       // '<S6>/NOT'
  boolean_T DataStoreRead12;           // '<Root>/Data Store Read12'
};

// Block states (default storage) for system '<Root>'
struct DW_px4_noGPS1_T {
  px4_internal_block_PWM_px4_no_T obj; // '<Root>/PX4 PWM Output1'
  px4_internal_block_Subscriber_T obj_n;// '<S6>/SourceBlock'
  px4_internal_block_Subscriber_T obj_l;// '<S5>/SourceBlock'
  real_T UD_DSTATE;                    // '<S37>/UD'
  real_T DiscreteTimeIntegrator3_DSTATE;// '<S18>/Discrete-Time Integrator3'
  real_T UD_DSTATE_b;                  // '<S19>/UD'
  real_T DiscreteTimeIntegrator3_DSTAT_a;// '<S16>/Discrete-Time Integrator3'
  real_T UD_DSTATE_n;                  // '<S28>/UD'
  real_T DiscreteTimeIntegrator3_DSTAT_m;// '<S17>/Discrete-Time Integrator3'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S18>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator1_DSTATE;// '<S18>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator_DSTATE_p;// '<S16>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator1_DSTAT_i;// '<S16>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator_DSTATE_f;// '<S17>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator1_DSTAT_g;// '<S17>/Discrete-Time Integrator1'
  real_T Intgrt_dX_DSTATE;             // '<Root>/Intgrt_dX'
  real_T Intgrt_dY_DSTATE;             // '<Root>/Intgrt_dY'
  real_T Intgrt_ddY_DSTATE;            // '<Root>/Intgrt_ddY'
  real_T Intgrt_ddX_DSTATE;            // '<Root>/Intgrt_ddX'
  real_T UD_DSTATE_n2;                 // '<S50>/UD'
  real_T DiscreteTimeIntegrator_DSTATE_d;// '<S48>/Discrete-Time Integrator'
  real_T UD_DSTATE_m;                  // '<S51>/UD'
  real_T DiscreteTimeIntegrator_DSTATE_i;// '<S49>/Discrete-Time Integrator'
  real_T Intgrt_dZ_DSTATE;             // '<Root>/Intgrt_dZ'
  real_T Intgrt_ddZ_DSTATE;            // '<Root>/Intgrt_ddZ'
  real_T DiscreteTimeIntegrator_DSTAT_fj;// '<S9>/Discrete-Time Integrator'
  real_T start_time_yaw;               // '<S39>/Data Store Memory'
  real_T start_time;                   // '<S21>/Data Store Memory'
  real_T start_time_roll;              // '<S30>/Data Store Memory'
  real_T e_pitch;                      // '<S1>/e_pitch'
  real_T e_pitch_roll;                 // '<S1>/e_pitch1'
  real_T e_pitch_yaw;                  // '<S1>/e_pitch2'
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
    void *LoggedData;
  } Scope_PWORK;                       // '<S39>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_o;                     // '<S21>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_i;                     // '<S30>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_ot;                    // '<S18>/Scope'

  struct {
    void *LoggedData[2];
  } Scope_PWORK_f;                     // '<S1>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_b;                     // '<S16>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     // '<S17>/Scope'

  struct {
    void *LoggedData[4];
  } Scope1_PWORK;                      // '<Root>/Scope1'

  struct {
    void *LoggedData[3];
  } Scope_PWORK_m;                     // '<Root>/Scope'

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      // '<Root>/Scope2'

  int8_T Subsystem1_SubsysRanBC;       // '<Root>/Subsystem1'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S54>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S54>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S54>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S6>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_b;// '<S5>/Enabled Subsystem'
  int8_T Subsystem_SubsysRanBC;        // '<S42>/Subsystem'
  int8_T Subsystem_SubsysRanBC_m;      // '<S33>/Subsystem'
  int8_T Subsystem_SubsysRanBC_k;      // '<S24>/Subsystem'
  boolean_T attitude_flag;             // '<Root>/Data Store Memory'
  boolean_T position_flag;             // '<Root>/Data Store Memory27'
  boolean_T observer_flag;             // '<Root>/Data Store Memory30'
};

// Zero-crossing (trigger) state
struct PrevZCX_px4_noGPS1_T {
  ZCSigState Subsystem_Trig_ZCE;       // '<S42>/Subsystem'
  ZCSigState Subsystem_Trig_ZCE_j;     // '<S33>/Subsystem'
  ZCSigState Subsystem_Trig_ZCE_e;     // '<S24>/Subsystem'
};

// Parameters (default storage)
struct P_px4_noGPS1_T_ {
  real_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S37>/UD'

  real_T DiscreteDerivative1_ICPrevSca_o;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_o
                                 //  Referenced by: '<S19>/UD'

  real_T DiscreteDerivative1_ICPrevSca_d;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_d
                                 //  Referenced by: '<S28>/UD'

  real_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S50>/UD'

  real_T DiscreteDerivative_ICPrevScal_g;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_g
                                 //  Referenced by: '<S51>/UD'

  real_T CompareToConstant1_const;   // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S40>/Constant'

  real_T CompareToConstant1_const_b;
                                   // Mask Parameter: CompareToConstant1_const_b
                                      //  Referenced by: '<S22>/Constant'

  real_T CompareToConstant1_const_h;
                                   // Mask Parameter: CompareToConstant1_const_h
                                      //  Referenced by: '<S31>/Constant'

  real_T CompareToConstant2_const;   // Mask Parameter: CompareToConstant2_const
                                        //  Referenced by: '<S44>/Constant'

  real_T CompareToConstant1_const_hq;
                                  // Mask Parameter: CompareToConstant1_const_hq
                                     //  Referenced by: '<S43>/Constant'

  real_T CompareToConstant2_const_o;
                                   // Mask Parameter: CompareToConstant2_const_o
                                      //  Referenced by: '<S26>/Constant'

  real_T CompareToConstant1_const_p;
                                   // Mask Parameter: CompareToConstant1_const_p
                                      //  Referenced by: '<S25>/Constant'

  real_T CompareToConstant2_const_a;
                                   // Mask Parameter: CompareToConstant2_const_a
                                      //  Referenced by: '<S35>/Constant'

  real_T CompareToConstant1_const_a;
                                   // Mask Parameter: CompareToConstant1_const_a
                                      //  Referenced by: '<S34>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S47>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S6>/Constant'

  px4_Bus_actuator_outputs Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S46>/Out1'

  px4_Bus_actuator_outputs Constant_Value_c;// Computed Parameter: Constant_Value_c
                                               //  Referenced by: '<S5>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S13>/Constant1'

  real_T Constant1_Value_n;            // Expression: 0
                                          //  Referenced by: '<S14>/Constant1'

  real_T Constant1_Value_a;            // Expression: 0
                                          //  Referenced by: '<S15>/Constant1'

  real_T Saturation_UpperSat;          // Expression: 0.1
                                          //  Referenced by: '<S1>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.1
                                          //  Referenced by: '<S1>/Saturation'

  real_T Constant_Value_b;             // Expression: 0
                                          //  Referenced by: '<S1>/Constant'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<S16>/Constant3'

  real_T Constant3_Value_a;            // Expression: 0
                                          //  Referenced by: '<S17>/Constant3'

  real_T Constant3_Value_d;            // Expression: 0
                                          //  Referenced by: '<S18>/Constant3'

  real_T Constant1_Value_g;            // Expression: 0
                                          //  Referenced by: '<S48>/Constant1'

  real_T Constant1_Value_nr;           // Expression: 0
                                          //  Referenced by: '<S49>/Constant1'

  real_T Constant_Value_e;             // Expression: 1
                                          //  Referenced by: '<S55>/Constant'

  real_T Constant_Value_b1;            // Expression: 1
                                          //  Referenced by: '<S56>/Constant'

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

  real_T DataStoreMemory33_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory33'

  real_T DataStoreMemory34_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory34'

  real_T DataStoreMemory35_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory35'

  real_T DataStoreMemory5_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Data Store Memory5'

  real_T r_Value;                      // Expression: 8.00109649122807
                                          //  Referenced by: '<S39>/r'

  real_T ch_Value;                     // Expression: 2
                                          //  Referenced by: '<S39>/ch'

  real_T T_Value;                      // Expression: 5
                                          //  Referenced by: '<S39>/T'

  real_T t_Value;                      // Expression: 0
                                          //  Referenced by: '<S39>/t'

  real_T b_Value;                      // Expression: 2.036184210526316
                                          //  Referenced by: '<S15>/b'

  real_T Gain4_Gain;                   // Expression: -1
                                          //  Referenced by: '<S38>/Gain4'

  real_T TSamp_WtEt;                   // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S37>/TSamp'

  real_T l_Value;                      // Expression: 0.5282118055555556
                                          //  Referenced by: '<S15>/l'

  real_T Gain_Gain;                    // Expression: 0.01/0.0052
                                          //  Referenced by: '<S15>/Gain'

  real_T Gain1_Gain;                   // Expression: 0.00502
                                          //  Referenced by: '<S15>/Gain1'

  real_T DiscreteTimeIntegrator3_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator3_gainval
                             //  Referenced by: '<S18>/Discrete-Time Integrator3'

  real_T DiscreteTimeIntegrator3_IC;   // Expression: 0
                                          //  Referenced by: '<S18>/Discrete-Time Integrator3'

  real_T Gain1_Gain_o;                 // Expression: 0.008
                                          //  Referenced by: '<S1>/Gain1'

  real_T Saturation4_UpperSat;         // Expression: 0.2
                                          //  Referenced by: '<S1>/Saturation4'

  real_T Saturation4_LowerSat;         // Expression: -0.5
                                          //  Referenced by: '<S1>/Saturation4'

  real_T r_Value_g;                    // Expression: 6.033653846153846
                                          //  Referenced by: '<S21>/r'

  real_T ch_Value_j;                   // Expression: 2
                                          //  Referenced by: '<S21>/ch'

  real_T T_Value_p;                    // Expression: 5.018640350877193
                                          //  Referenced by: '<S21>/T'

  real_T t_Value_n;                    // Expression: 0
                                          //  Referenced by: '<S21>/t'

  real_T b_Value_l;                    // Expression: 2.470900809716599
                                          //  Referenced by: '<S13>/b'

  real_T Gain4_Gain_b;                 // Expression: -1
                                          //  Referenced by: '<S20>/Gain4'

  real_T TSamp_WtEt_p;                 // Computed Parameter: TSamp_WtEt_p
                                          //  Referenced by: '<S19>/TSamp'

  real_T l_Value_b;                    // Expression: 0.5282118055555556
                                          //  Referenced by: '<S13>/l'

  real_T Gain_Gain_o;                  // Expression: 0.01/0.0052
                                          //  Referenced by: '<S13>/Gain'

  real_T Gain1_Gain_b;                 // Expression: 0.00502
                                          //  Referenced by: '<S13>/Gain1'

  real_T DiscreteTimeIntegrator3_gainv_m;
                          // Computed Parameter: DiscreteTimeIntegrator3_gainv_m
                             //  Referenced by: '<S16>/Discrete-Time Integrator3'

  real_T DiscreteTimeIntegrator3_IC_k; // Expression: 0
                                          //  Referenced by: '<S16>/Discrete-Time Integrator3'

  real_T Gain2_Gain;                   // Expression: 0.00478
                                          //  Referenced by: '<S1>/Gain2'

  real_T r_Value_p;                    // Expression: 6.001388888888889
                                          //  Referenced by: '<S30>/r'

  real_T ch_Value_e;                   // Expression: 2
                                          //  Referenced by: '<S30>/ch'

  real_T T_Value_c;                    // Expression: 5
                                          //  Referenced by: '<S30>/T'

  real_T t_Value_m;                    // Expression: 0
                                          //  Referenced by: '<S30>/t'

  real_T b_Value_h;                    // Expression: 2.490277777777778
                                          //  Referenced by: '<S14>/b'

  real_T Gain4_Gain_o;                 // Expression: -1
                                          //  Referenced by: '<S29>/Gain4'

  real_T TSamp_WtEt_o;                 // Computed Parameter: TSamp_WtEt_o
                                          //  Referenced by: '<S28>/TSamp'

  real_T l_Value_n;                    // Expression: 0.5340277777777778
                                          //  Referenced by: '<S14>/l'

  real_T Gain_Gain_m;                  // Expression: 0.01/0.0052
                                          //  Referenced by: '<S14>/Gain'

  real_T J_Gain;                       // Expression: 0.00478
                                          //  Referenced by: '<S14>/J'

  real_T DiscreteTimeIntegrator3_gainv_e;
                          // Computed Parameter: DiscreteTimeIntegrator3_gainv_e
                             //  Referenced by: '<S17>/Discrete-Time Integrator3'

  real_T DiscreteTimeIntegrator3_IC_l; // Expression: 0
                                          //  Referenced by: '<S17>/Discrete-Time Integrator3'

  real_T J_Gain_b;                     // Expression: 0.00478
                                          //  Referenced by: '<S1>/J'

  real_T DataStoreMemory_InitialValue; // Expression: 0
                                          //  Referenced by: '<S39>/Data Store Memory'

  real_T DataStoreMemory_InitialValue_l;// Expression: 0
                                           //  Referenced by: '<S21>/Data Store Memory'

  real_T DataStoreMemory_InitialValue_b;// Expression: 0
                                           //  Referenced by: '<S30>/Data Store Memory'

  real_T DiscreteTimeIntegrator_gainva_n;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_n
                             //  Referenced by: '<S18>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_l;  // Expression: 0
                                          //  Referenced by: '<S18>/Discrete-Time Integrator'

  real_T Gain2_Gain_c;                 // Expression: 180/pi
                                          //  Referenced by: '<S18>/Gain2'

  real_T uJ_Gain;                      // Expression: 1/0.008
                                          //  Referenced by: '<S18>/1//J'

  real_T kJ_Gain;                      // Expression: 0.01/0.008
                                          //  Referenced by: '<S18>/k//J'

  real_T Saturation_UpperSat_b;        // Expression: 1
                                          //  Referenced by: '<S18>/Saturation'

  real_T Saturation_LowerSat_k;        // Expression: -1
                                          //  Referenced by: '<S18>/Saturation'

  real_T l1_Gain;                      // Expression: 0
                                          //  Referenced by: '<S18>/l1'

  real_T lambda1_Gain;                 // Expression: 0
                                          //  Referenced by: '<S18>/lambda1'

  real_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S18>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC;   // Expression: 0
                                          //  Referenced by: '<S18>/Discrete-Time Integrator1'

  real_T Constant1_Value_f;            // Expression: 0.1
                                          //  Referenced by: '<S18>/Constant1'

  real_T Saturation10_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S18>/Saturation10'

  real_T Saturation10_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S18>/Saturation10'

  real_T Saturation11_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S18>/Saturation11'

  real_T Saturation11_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S18>/Saturation11'

  real_T Gain_Gain_ml;                 // Expression: 0.5
                                          //  Referenced by: '<S18>/Gain'

  real_T Saturation8_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S18>/Saturation8'

  real_T Saturation8_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S18>/Saturation8'

  real_T Constant2_Value;              // Expression: 1
                                          //  Referenced by: '<S18>/Constant2'

  real_T Gain5_Gain;                   // Expression: 30
                                          //  Referenced by: '<S18>/Gain5'

  real_T Saturation13_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S18>/Saturation13'

  real_T Saturation13_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S18>/Saturation13'

  real_T Saturation9_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S18>/Saturation9'

  real_T Saturation9_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S18>/Saturation9'

  real_T Gain1_Gain_a;                 // Expression: 0.5
                                          //  Referenced by: '<S18>/Gain1'

  real_T Constant4_Value;              // Expression: 1
                                          //  Referenced by: '<S18>/Constant4'

  real_T Saturation12_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S18>/Saturation12'

  real_T Saturation12_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S18>/Saturation12'

  real_T Saturation16_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S18>/Saturation16'

  real_T Saturation16_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S18>/Saturation16'

  real_T Saturation14_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S18>/Saturation14'

  real_T Saturation14_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S18>/Saturation14'

  real_T Gain3_Gain;                   // Expression: 0.5
                                          //  Referenced by: '<S18>/Gain3'

  real_T Constant6_Value;              // Expression: 1
                                          //  Referenced by: '<S18>/Constant6'

  real_T lambda2_Gain;                 // Expression: 0
                                          //  Referenced by: '<S18>/lambda2'

  real_T Saturation1_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S18>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S18>/Saturation1'

  real_T l2_Gain;                      // Expression: 0
                                          //  Referenced by: '<S18>/l2'

  real_T Saturation15_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S18>/Saturation15'

  real_T Saturation15_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S18>/Saturation15'

  real_T Gain6_Gain;                   // Expression: 30
                                          //  Referenced by: '<S18>/Gain6'

  real_T Saturation19_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S18>/Saturation19'

  real_T Saturation19_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S18>/Saturation19'

  real_T Saturation17_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S18>/Saturation17'

  real_T Saturation17_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S18>/Saturation17'

  real_T Gain4_Gain_f;                 // Expression: 0.5
                                          //  Referenced by: '<S18>/Gain4'

  real_T Constant8_Value_j;            // Expression: 1
                                          //  Referenced by: '<S18>/Constant8'

  real_T Saturation18_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S18>/Saturation18'

  real_T Saturation18_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S18>/Saturation18'

  real_T Saturation3_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S18>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S18>/Saturation3'

  real_T l4_Gain;                      // Expression: 0
                                          //  Referenced by: '<S18>/l4'

  real_T lambda4_Gain;                 // Expression: 0
                                          //  Referenced by: '<S18>/lambda4'

  real_T Gain7_Gain;                   // Expression: 40
                                          //  Referenced by: '<S18>/Gain7'

  real_T Gain8_Gain;                   // Expression: 1
                                          //  Referenced by: '<S18>/Gain8'

  real_T DiscreteTimeIntegrator_gainva_e;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_e
                             //  Referenced by: '<S16>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_h;  // Expression: 0
                                          //  Referenced by: '<S16>/Discrete-Time Integrator'

  real_T Gain2_Gain_g;                 // Expression: 180/pi
                                          //  Referenced by: '<S16>/Gain2'

  real_T uJ_Gain_p;                    // Expression: 1/0.00478
                                          //  Referenced by: '<S16>/1//J'

  real_T kJ_Gain_c;                    // Expression: 0.01/0.00478
                                          //  Referenced by: '<S16>/k//J'

  real_T Saturation_UpperSat_n;        // Expression: 1
                                          //  Referenced by: '<S16>/Saturation'

  real_T Saturation_LowerSat_g;        // Expression: -1
                                          //  Referenced by: '<S16>/Saturation'

  real_T l1_Gain_p;                    // Expression: 0
                                          //  Referenced by: '<S16>/l1'

  real_T lambda1_Gain_a;               // Expression: 0
                                          //  Referenced by: '<S16>/lambda1'

  real_T DiscreteTimeIntegrator1_gainv_n;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainv_n
                             //  Referenced by: '<S16>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC_j; // Expression: 0
                                          //  Referenced by: '<S16>/Discrete-Time Integrator1'

  real_T Constant1_Value_j;            // Expression: 0.1
                                          //  Referenced by: '<S16>/Constant1'

  real_T Saturation10_UpperSat_o;      // Expression: 1
                                          //  Referenced by: '<S16>/Saturation10'

  real_T Saturation10_LowerSat_b;      // Expression: -1
                                          //  Referenced by: '<S16>/Saturation10'

  real_T Saturation11_UpperSat_p;      // Expression: 1
                                          //  Referenced by: '<S16>/Saturation11'

  real_T Saturation11_LowerSat_i;      // Expression: -1
                                          //  Referenced by: '<S16>/Saturation11'

  real_T Gain_Gain_g;                  // Expression: 0.5
                                          //  Referenced by: '<S16>/Gain'

  real_T Saturation8_UpperSat_g;       // Expression: 1
                                          //  Referenced by: '<S16>/Saturation8'

  real_T Saturation8_LowerSat_g;       // Expression: -1
                                          //  Referenced by: '<S16>/Saturation8'

  real_T Constant2_Value_h;            // Expression: 1
                                          //  Referenced by: '<S16>/Constant2'

  real_T Gain5_Gain_o;                 // Expression: 30
                                          //  Referenced by: '<S16>/Gain5'

  real_T Saturation13_UpperSat_i;      // Expression: 1
                                          //  Referenced by: '<S16>/Saturation13'

  real_T Saturation13_LowerSat_c;      // Expression: -1
                                          //  Referenced by: '<S16>/Saturation13'

  real_T Saturation9_UpperSat_i;       // Expression: 1
                                          //  Referenced by: '<S16>/Saturation9'

  real_T Saturation9_LowerSat_c;       // Expression: -1
                                          //  Referenced by: '<S16>/Saturation9'

  real_T Gain1_Gain_d;                 // Expression: 0.5
                                          //  Referenced by: '<S16>/Gain1'

  real_T Constant4_Value_n;            // Expression: 1
                                          //  Referenced by: '<S16>/Constant4'

  real_T Saturation12_UpperSat_c;      // Expression: 1
                                          //  Referenced by: '<S16>/Saturation12'

  real_T Saturation12_LowerSat_b;      // Expression: -1
                                          //  Referenced by: '<S16>/Saturation12'

  real_T Saturation16_UpperSat_l;      // Expression: 1
                                          //  Referenced by: '<S16>/Saturation16'

  real_T Saturation16_LowerSat_g;      // Expression: -1
                                          //  Referenced by: '<S16>/Saturation16'

  real_T Saturation14_UpperSat_l;      // Expression: 1
                                          //  Referenced by: '<S16>/Saturation14'

  real_T Saturation14_LowerSat_b;      // Expression: -1
                                          //  Referenced by: '<S16>/Saturation14'

  real_T Gain3_Gain_l;                 // Expression: 0.5
                                          //  Referenced by: '<S16>/Gain3'

  real_T Constant6_Value_o;            // Expression: 1
                                          //  Referenced by: '<S16>/Constant6'

  real_T lambda2_Gain_j;               // Expression: 0
                                          //  Referenced by: '<S16>/lambda2'

  real_T Saturation1_UpperSat_a;       // Expression: 1
                                          //  Referenced by: '<S16>/Saturation1'

  real_T Saturation1_LowerSat_i;       // Expression: -1
                                          //  Referenced by: '<S16>/Saturation1'

  real_T l2_Gain_l;                    // Expression: 0
                                          //  Referenced by: '<S16>/l2'

  real_T Saturation15_UpperSat_j;      // Expression: 1
                                          //  Referenced by: '<S16>/Saturation15'

  real_T Saturation15_LowerSat_k;      // Expression: -1
                                          //  Referenced by: '<S16>/Saturation15'

  real_T Gain6_Gain_e;                 // Expression: 30
                                          //  Referenced by: '<S16>/Gain6'

  real_T Saturation19_UpperSat_b;      // Expression: 1
                                          //  Referenced by: '<S16>/Saturation19'

  real_T Saturation19_LowerSat_j;      // Expression: -1
                                          //  Referenced by: '<S16>/Saturation19'

  real_T Saturation17_UpperSat_d;      // Expression: 1
                                          //  Referenced by: '<S16>/Saturation17'

  real_T Saturation17_LowerSat_o;      // Expression: -1
                                          //  Referenced by: '<S16>/Saturation17'

  real_T Gain4_Gain_n;                 // Expression: 0.5
                                          //  Referenced by: '<S16>/Gain4'

  real_T Constant8_Value_f;            // Expression: 1
                                          //  Referenced by: '<S16>/Constant8'

  real_T Saturation18_UpperSat_a;      // Expression: 1
                                          //  Referenced by: '<S16>/Saturation18'

  real_T Saturation18_LowerSat_h;      // Expression: -1
                                          //  Referenced by: '<S16>/Saturation18'

  real_T Saturation3_UpperSat_m;       // Expression: 1
                                          //  Referenced by: '<S16>/Saturation3'

  real_T Saturation3_LowerSat_i;       // Expression: -1
                                          //  Referenced by: '<S16>/Saturation3'

  real_T l4_Gain_p;                    // Expression: 0
                                          //  Referenced by: '<S16>/l4'

  real_T lambda4_Gain_a;               // Expression: 0
                                          //  Referenced by: '<S16>/lambda4'

  real_T Gain7_Gain_d;                 // Expression: 40
                                          //  Referenced by: '<S16>/Gain7'

  real_T Gain8_Gain_b;                 // Expression: 1
                                          //  Referenced by: '<S16>/Gain8'

  real_T DiscreteTimeIntegrator_gainv_nv;
                          // Computed Parameter: DiscreteTimeIntegrator_gainv_nv
                             //  Referenced by: '<S17>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_o;  // Expression: 0
                                          //  Referenced by: '<S17>/Discrete-Time Integrator'

  real_T Gain2_Gain_p;                 // Expression: 180/pi
                                          //  Referenced by: '<S17>/Gain2'

  real_T uJ_Gain_g;                    // Expression: 1/0.00478
                                          //  Referenced by: '<S17>/1//J'

  real_T kJ_Gain_p;                    // Expression: 0.01/0.00478
                                          //  Referenced by: '<S17>/k//J'

  real_T Saturation_UpperSat_n1;       // Expression: 1
                                          //  Referenced by: '<S17>/Saturation'

  real_T Saturation_LowerSat_c;        // Expression: -1
                                          //  Referenced by: '<S17>/Saturation'

  real_T l1_Gain_d;                    // Expression: 0
                                          //  Referenced by: '<S17>/l1'

  real_T lambda1_Gain_g;               // Expression: 0
                                          //  Referenced by: '<S17>/lambda1'

  real_T DiscreteTimeIntegrator1_gainv_g;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainv_g
                             //  Referenced by: '<S17>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC_c; // Expression: 0
                                          //  Referenced by: '<S17>/Discrete-Time Integrator1'

  real_T Constant1_Value_ac;           // Expression: 0.1
                                          //  Referenced by: '<S17>/Constant1'

  real_T Saturation10_UpperSat_a;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation10'

  real_T Saturation10_LowerSat_l;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation10'

  real_T Saturation11_UpperSat_a;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation11'

  real_T Saturation11_LowerSat_a;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation11'

  real_T Gain_Gain_h;                  // Expression: 0.5
                                          //  Referenced by: '<S17>/Gain'

  real_T Saturation8_UpperSat_c;       // Expression: 1
                                          //  Referenced by: '<S17>/Saturation8'

  real_T Saturation8_LowerSat_c;       // Expression: -1
                                          //  Referenced by: '<S17>/Saturation8'

  real_T Constant2_Value_k;            // Expression: 1
                                          //  Referenced by: '<S17>/Constant2'

  real_T Gain5_Gain_l;                 // Expression: 30
                                          //  Referenced by: '<S17>/Gain5'

  real_T Saturation13_UpperSat_p;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation13'

  real_T Saturation13_LowerSat_j;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation13'

  real_T Saturation9_UpperSat_d;       // Expression: 1
                                          //  Referenced by: '<S17>/Saturation9'

  real_T Saturation9_LowerSat_c4;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation9'

  real_T Gain1_Gain_e;                 // Expression: 0.5
                                          //  Referenced by: '<S17>/Gain1'

  real_T Constant4_Value_l;            // Expression: 1
                                          //  Referenced by: '<S17>/Constant4'

  real_T Saturation12_UpperSat_d;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation12'

  real_T Saturation12_LowerSat_j;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation12'

  real_T Saturation16_UpperSat_p;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation16'

  real_T Saturation16_LowerSat_i;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation16'

  real_T Saturation14_UpperSat_n;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation14'

  real_T Saturation14_LowerSat_a;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation14'

  real_T Gain3_Gain_p;                 // Expression: 0.5
                                          //  Referenced by: '<S17>/Gain3'

  real_T Constant6_Value_g;            // Expression: 1
                                          //  Referenced by: '<S17>/Constant6'

  real_T lambda2_Gain_d;               // Expression: 0
                                          //  Referenced by: '<S17>/lambda2'

  real_T Saturation1_UpperSat_d;       // Expression: 1
                                          //  Referenced by: '<S17>/Saturation1'

  real_T Saturation1_LowerSat_g;       // Expression: -1
                                          //  Referenced by: '<S17>/Saturation1'

  real_T l2_Gain_i;                    // Expression: 0
                                          //  Referenced by: '<S17>/l2'

  real_T Saturation15_UpperSat_k;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation15'

  real_T Saturation15_LowerSat_h;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation15'

  real_T Gain6_Gain_f;                 // Expression: 30
                                          //  Referenced by: '<S17>/Gain6'

  real_T Saturation19_UpperSat_bc;     // Expression: 1
                                          //  Referenced by: '<S17>/Saturation19'

  real_T Saturation19_LowerSat_e;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation19'

  real_T Saturation17_UpperSat_o;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation17'

  real_T Saturation17_LowerSat_m;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation17'

  real_T Gain4_Gain_e;                 // Expression: 0.5
                                          //  Referenced by: '<S17>/Gain4'

  real_T Constant8_Value_p;            // Expression: 1
                                          //  Referenced by: '<S17>/Constant8'

  real_T Saturation18_UpperSat_c;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation18'

  real_T Saturation18_LowerSat_g;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation18'

  real_T Saturation3_UpperSat_i;       // Expression: 1
                                          //  Referenced by: '<S17>/Saturation3'

  real_T Saturation3_LowerSat_g;       // Expression: -1
                                          //  Referenced by: '<S17>/Saturation3'

  real_T l4_Gain_o;                    // Expression: 0
                                          //  Referenced by: '<S17>/l4'

  real_T lambda4_Gain_b;               // Expression: 0
                                          //  Referenced by: '<S17>/lambda4'

  real_T Gain7_Gain_l;                 // Expression: 40
                                          //  Referenced by: '<S17>/Gain7'

  real_T Gain8_Gain_o;                 // Expression: 1
                                          //  Referenced by: '<S17>/Gain8'

  real_T Saturation2_UpperSat;         // Expression: 0.2
                                          //  Referenced by: '<S1>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -0.5
                                          //  Referenced by: '<S1>/Saturation2'

  real_T e_pitch_InitialValue;         // Expression: 0
                                          //  Referenced by: '<S1>/e_pitch'

  real_T e_pitch1_InitialValue;        // Expression: 0
                                          //  Referenced by: '<S1>/e_pitch1'

  real_T e_pitch2_InitialValue;        // Expression: 0
                                          //  Referenced by: '<S1>/e_pitch2'

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

  real_T Constant6_Value_p;            // Expression: 0
                                          //  Referenced by: '<Root>/Constant6'

  real_T C1_Gain;                      // Expression: 40.16186580802367
                                          //  Referenced by: '<S48>/C1'

  real_T TSamp_WtEt_d;                 // Computed Parameter: TSamp_WtEt_d
                                          //  Referenced by: '<S50>/TSamp'

  real_T C2_Gain;                      // Expression: 76.12044208511008
                                          //  Referenced by: '<S48>/C2'

  real_T DiscreteTimeIntegrator_gainva_h;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_h
                             //  Referenced by: '<S48>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_f;  // Expression: 0
                                          //  Referenced by: '<S48>/Discrete-Time Integrator'

  real_T C3_Gain;                      // Expression: 0
                                          //  Referenced by: '<S48>/C3'

  real_T Gain2_Gain_d;                 // Expression: 0.01
                                          //  Referenced by: '<S7>/Gain2'

  real_T Saturation1_UpperSat_h;       // Expression: 0.5
                                          //  Referenced by: '<S7>/Saturation1'

  real_T Saturation1_LowerSat_o;       // Expression: -0.5
                                          //  Referenced by: '<S7>/Saturation1'

  real_T Constant_Value_i;             // Expression: 0
                                          //  Referenced by: '<S7>/Constant'

  real_T C1_Gain_d;                    // Expression: 40.16186580802367
                                          //  Referenced by: '<S49>/C1'

  real_T TSamp_WtEt_e;                 // Computed Parameter: TSamp_WtEt_e
                                          //  Referenced by: '<S51>/TSamp'

  real_T C2_Gain_b;                    // Expression: 76.12044208511008
                                          //  Referenced by: '<S49>/C2'

  real_T DiscreteTimeIntegrator_gainva_p;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_p
                             //  Referenced by: '<S49>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_ff; // Expression: 0
                                          //  Referenced by: '<S49>/Discrete-Time Integrator'

  real_T C3_Gain_j;                    // Expression: 0
                                          //  Referenced by: '<S49>/C3'

  real_T Gain4_Gain_ff;                // Expression: 0.01
                                          //  Referenced by: '<S7>/Gain4'

  real_T Saturation2_UpperSat_c;       // Expression: 0.5
                                          //  Referenced by: '<S7>/Saturation2'

  real_T Saturation2_LowerSat_f;       // Expression: -0.5
                                          //  Referenced by: '<S7>/Saturation2'

  real_T Saturation2_UpperSat_o;       // Expression: 1.5
                                          //  Referenced by: '<Root>/Saturation2'

  real_T Saturation2_LowerSat_b;       // Expression: 1
                                          //  Referenced by: '<Root>/Saturation2'

  real_T Saturation_UpperSat_bm;       // Expression: 1.5
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat_co;       // Expression: 1
                                          //  Referenced by: '<Root>/Saturation'

  real_T fault_1_Value;                // Expression: 0
                                          //  Referenced by: '<Root>/fault_1'

  real_T Mixermatrix1_Value[16];
                          // Expression: [1 1 -1 1;1 -1 1 1;1 1 1 -1;1 -1 -1 -1]
                             //  Referenced by: '<Root>/Mixer matrix1'

  real_T Gain4_Gain_fc;                // Expression: 1000
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

  real_T Gain8_Gain_o1;                // Expression: 180/3.1415926
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

  boolean_T Constant2_Value_kf;        // Computed Parameter: Constant2_Value_kf
                                          //  Referenced by: '<Root>/Constant2'

  boolean_T DataStoreMemory_InitialValue_j;
                           // Computed Parameter: DataStoreMemory_InitialValue_j
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
struct tag_RTM_px4_noGPS1_T {
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

  extern P_px4_noGPS1_T px4_noGPS1_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_px4_noGPS1_T px4_noGPS1_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_px4_noGPS1_T px4_noGPS1_DW;

// Zero-crossing (trigger) state
extern PrevZCX_px4_noGPS1_T px4_noGPS1_PrevZCX;

// External function called from main
#ifdef __cplusplus

extern "C" {

#endif

  extern void px4_noGPS1_SetEventsForThisBaseStep(boolean_T *eventFlags);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void px4_noGPS1_SetEventsForThisBaseStep(boolean_T *eventFlags);
  extern void px4_noGPS1_initialize(void);
  extern void px4_noGPS1_step0(void);
  extern void px4_noGPS1_step1(void);
  extern void px4_noGPS1_step(int_T tid);
  extern void px4_noGPS1_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_px4_noGPS1_T *const px4_noGPS1_M;

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
//  '<Root>' : 'px4_noGPS1'
//  '<S1>'   : 'px4_noGPS1/Attitude controller'
//  '<S2>'   : 'px4_noGPS1/MATLAB Function1'
//  '<S3>'   : 'px4_noGPS1/MATLAB Function3'
//  '<S4>'   : 'px4_noGPS1/MATLAB Function5'
//  '<S5>'   : 'px4_noGPS1/PX4 uORB Read'
//  '<S6>'   : 'px4_noGPS1/PX4 uORB Read2'
//  '<S7>'   : 'px4_noGPS1/Position controller'
//  '<S8>'   : 'px4_noGPS1/Quaternions to Rotation Angles'
//  '<S9>'   : 'px4_noGPS1/Subsystem1'
//  '<S10>'  : 'px4_noGPS1/attitude_button'
//  '<S11>'  : 'px4_noGPS1/observer_button'
//  '<S12>'  : 'px4_noGPS1/position_button'
//  '<S13>'  : 'px4_noGPS1/Attitude controller/Subsystem'
//  '<S14>'  : 'px4_noGPS1/Attitude controller/Subsystem6'
//  '<S15>'  : 'px4_noGPS1/Attitude controller/Subsystem7'
//  '<S16>'  : 'px4_noGPS1/Attitude controller/observer_pitch_3'
//  '<S17>'  : 'px4_noGPS1/Attitude controller/observer_roll_3'
//  '<S18>'  : 'px4_noGPS1/Attitude controller/observer_yaw'
//  '<S19>'  : 'px4_noGPS1/Attitude controller/Subsystem/Discrete Derivative1'
//  '<S20>'  : 'px4_noGPS1/Attitude controller/Subsystem/Subsystem1'
//  '<S21>'  : 'px4_noGPS1/Attitude controller/Subsystem/Subsystem1/Subsystem'
//  '<S22>'  : 'px4_noGPS1/Attitude controller/Subsystem/Subsystem1/Subsystem/Compare To Constant1'
//  '<S23>'  : 'px4_noGPS1/Attitude controller/Subsystem/Subsystem1/Subsystem/MATLAB Function'
//  '<S24>'  : 'px4_noGPS1/Attitude controller/Subsystem/Subsystem1/Subsystem/start_time'
//  '<S25>'  : 'px4_noGPS1/Attitude controller/Subsystem/Subsystem1/Subsystem/start_time/Compare To Constant1'
//  '<S26>'  : 'px4_noGPS1/Attitude controller/Subsystem/Subsystem1/Subsystem/start_time/Compare To Constant2'
//  '<S27>'  : 'px4_noGPS1/Attitude controller/Subsystem/Subsystem1/Subsystem/start_time/Subsystem'
//  '<S28>'  : 'px4_noGPS1/Attitude controller/Subsystem6/Discrete Derivative1'
//  '<S29>'  : 'px4_noGPS1/Attitude controller/Subsystem6/Subsystem1'
//  '<S30>'  : 'px4_noGPS1/Attitude controller/Subsystem6/Subsystem1/Subsystem'
//  '<S31>'  : 'px4_noGPS1/Attitude controller/Subsystem6/Subsystem1/Subsystem/Compare To Constant1'
//  '<S32>'  : 'px4_noGPS1/Attitude controller/Subsystem6/Subsystem1/Subsystem/MATLAB Function'
//  '<S33>'  : 'px4_noGPS1/Attitude controller/Subsystem6/Subsystem1/Subsystem/start_time'
//  '<S34>'  : 'px4_noGPS1/Attitude controller/Subsystem6/Subsystem1/Subsystem/start_time/Compare To Constant1'
//  '<S35>'  : 'px4_noGPS1/Attitude controller/Subsystem6/Subsystem1/Subsystem/start_time/Compare To Constant2'
//  '<S36>'  : 'px4_noGPS1/Attitude controller/Subsystem6/Subsystem1/Subsystem/start_time/Subsystem'
//  '<S37>'  : 'px4_noGPS1/Attitude controller/Subsystem7/Discrete Derivative1'
//  '<S38>'  : 'px4_noGPS1/Attitude controller/Subsystem7/Subsystem1'
//  '<S39>'  : 'px4_noGPS1/Attitude controller/Subsystem7/Subsystem1/Subsystem'
//  '<S40>'  : 'px4_noGPS1/Attitude controller/Subsystem7/Subsystem1/Subsystem/Compare To Constant1'
//  '<S41>'  : 'px4_noGPS1/Attitude controller/Subsystem7/Subsystem1/Subsystem/MATLAB Function'
//  '<S42>'  : 'px4_noGPS1/Attitude controller/Subsystem7/Subsystem1/Subsystem/start_time'
//  '<S43>'  : 'px4_noGPS1/Attitude controller/Subsystem7/Subsystem1/Subsystem/start_time/Compare To Constant1'
//  '<S44>'  : 'px4_noGPS1/Attitude controller/Subsystem7/Subsystem1/Subsystem/start_time/Compare To Constant2'
//  '<S45>'  : 'px4_noGPS1/Attitude controller/Subsystem7/Subsystem1/Subsystem/start_time/Subsystem'
//  '<S46>'  : 'px4_noGPS1/PX4 uORB Read/Enabled Subsystem'
//  '<S47>'  : 'px4_noGPS1/PX4 uORB Read2/Enabled Subsystem'
//  '<S48>'  : 'px4_noGPS1/Position controller/Subsystem1'
//  '<S49>'  : 'px4_noGPS1/Position controller/Subsystem3'
//  '<S50>'  : 'px4_noGPS1/Position controller/Subsystem1/Discrete Derivative'
//  '<S51>'  : 'px4_noGPS1/Position controller/Subsystem3/Discrete Derivative'
//  '<S52>'  : 'px4_noGPS1/Quaternions to Rotation Angles/Angle Calculation'
//  '<S53>'  : 'px4_noGPS1/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S54>'  : 'px4_noGPS1/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S55>'  : 'px4_noGPS1/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S56>'  : 'px4_noGPS1/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S57>'  : 'px4_noGPS1/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S58>'  : 'px4_noGPS1/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S59>'  : 'px4_noGPS1/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                                 // RTW_HEADER_px4_noGPS1_h_

//
// File trailer for generated code.
//
// [EOF]
//
