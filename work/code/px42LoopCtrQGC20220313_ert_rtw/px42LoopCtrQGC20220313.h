//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px42LoopCtrQGC20220313.h
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
#ifndef RTW_HEADER_px42LoopCtrQGC20220313_h_
#define RTW_HEADER_px42LoopCtrQGC20220313_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "px42LoopCtrQGC20220313_types.h"
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
struct B_px42LoopCtrQGC20220313_T {
  px4_Bus_vehicle_odometry In1;        // '<S43>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  px4_Bus_actuator_outputs In1_a;      // '<S42>/In1'
  px4_Bus_actuator_outputs b_varargout_2_m;
  uint16_T pwmValue[8];
  real_T Gain2;                        // '<S1>/Gain2'
  real_T J;                            // '<S1>/J'
  real_T DataStoreRead4;               // '<S35>/Data Store Read4'
  real_T DataStoreRead4_g;             // '<S17>/Data Store Read4'
  real_T DataStoreRead4_b;             // '<S26>/Data Store Read4'
  real_T rolldegree;                   // '<S14>/Gain2'
  real_T rolldegree_l;                 // '<S12>/Gain2'
  real_T rolldegree_c;                 // '<S13>/Gain2'
  real_T pitch;                        // '<Root>/Gain8'
  real_T pitch_a;                      // '<Root>/Gain10'
  real_T roll;                         // '<Root>/Gain7'
  real_T pitch_g;                      // '<Root>/Gain11'
  real_T yaw;                          // '<Root>/Gain9'
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
  real_T DataStoreRead41;              // '<Root>/Data Store Read41'
  real_T DataStoreRead34;              // '<Root>/Data Store Read34'
  real_T DataStoreRead35;              // '<Root>/Data Store Read35'
  real_T DataStoreRead36;              // '<Root>/Data Store Read36'
  real_T DataStoreRead37;              // '<Root>/Data Store Read37'
  real_T DataStoreRead38;              // '<Root>/Data Store Read38'
  real_T DataStoreRead39;              // '<Root>/Data Store Read39'
  real_T DataStoreRead48;              // '<Root>/Data Store Read48'
  real_T DataStoreRead49;              // '<Root>/Data Store Read49'
  real_T DataStoreRead55;              // '<Root>/Data Store Read55'
  real_T DataStoreRead8;               // '<Root>/Data Store Read8'
  real_T DataStoreRead9;               // '<Root>/Data Store Read9'
  real_T y;                            // '<S35>/MATLAB Function'
  real_T y_o;                          // '<S26>/MATLAB Function'
  real_T y_j;                          // '<S17>/MATLAB Function'
  real32_T output[16];
                 // '<Root>/BusConversion_InsertedFor_Bus Selector_at_inport_0'
  real_T ManualSwitch_g;               // '<Root>/Manual Switch'
  real_T z2;                           // '<S14>/Discrete-Time Integrator3'
  real_T TSamp;                        // '<S33>/TSamp'
  real_T Add3;                         // '<S1>/Add3'
  real_T roll_hat;                     // '<S14>/Discrete-Time Integrator'
  real_T z2_e;                         // '<S12>/Discrete-Time Integrator3'
  real_T z2_l;                         // '<S13>/Discrete-Time Integrator3'
  real_T Abs6;                         // '<S13>/Abs6'
  real_T Product2_d;                   // '<S45>/Product2'
  real_T roll_hat_e;                   // '<S12>/Discrete-Time Integrator'
  real_T Product4;                     // '<S14>/Product4'
  real_T Product6;                     // '<S14>/Product6'
  real_T lambda1_a;                    // '<S12>/lambda1'
  real_T Product1_p;                   // '<S45>/Product1'
  real_T roll_hat_k;                   // '<S13>/Discrete-Time Integrator'
  real_T Product3_a;                   // '<S12>/Product3'
  real_T Product4_k;                   // '<S12>/Product4'
  real_T Product6_i;                   // '<S12>/Product6'
  real_T Product5_b;                   // '<S12>/Product5'
  real_T Add2_o;                       // '<S12>/Add2'
  real_T lambda4_n;                    // '<S12>/lambda4'
  real_T lambda1_e;                    // '<S13>/lambda1'
  real_T fcn5;                         // '<S4>/fcn5'
  real_T Product3_i;                   // '<S45>/Product3'
  real_T Product3_c;                   // '<S13>/Product3'
  real_T Product4_g;                   // '<S13>/Product4'
  real_T Product6_a;                   // '<S13>/Product6'
  real_T Product5_l;                   // '<S13>/Product5'
  real_T lambda4_h;                    // '<S13>/lambda4'
  real_T fcn3;                         // '<S4>/fcn3'
  real_T rtb_Fcn_a_c;
  real_T rtb_Fcn_b_k;
  real_T rtb_Fcn_c;
  real_T rtb_DataTypeConversion3_idx_0;
  real_T rtb_DataTypeConversion3_idx_1;
  real_T rtb_DataTypeConversion3_idx_2;
  real_T rtb_Product1_p_b;
  uint16_T Gain4[4];                   // '<Root>/Gain4'
  boolean_T NOT;                       // '<S3>/NOT'
  boolean_T DataStoreRead12;           // '<Root>/Data Store Read12'
};

// Block states (default storage) for system '<Root>'
struct DW_px42LoopCtrQGC20220313_T {
  px4_internal_block_PWM_px42Lo_T obj; // '<Root>/PX4 PWM Output1'
  px4_internal_block_Subscriber_T obj_n;// '<S3>/SourceBlock'
  px4_internal_block_Subscriber_T obj_l;// '<S2>/SourceBlock'
  real_T UD_DSTATE;                    // '<S33>/UD'
  real_T DiscreteTimeIntegrator3_DSTATE;// '<S14>/Discrete-Time Integrator3'
  real_T UD_DSTATE_b;                  // '<S15>/UD'
  real_T DiscreteTimeIntegrator3_DSTAT_a;// '<S12>/Discrete-Time Integrator3'
  real_T UD_DSTATE_n;                  // '<S24>/UD'
  real_T DiscreteTimeIntegrator3_DSTAT_m;// '<S13>/Discrete-Time Integrator3'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S14>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator1_DSTATE;// '<S14>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator_DSTATE_p;// '<S12>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator1_DSTAT_i;// '<S12>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator_DSTATE_f;// '<S13>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator1_DSTAT_g;// '<S13>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator_DSTAT_fj;// '<S5>/Discrete-Time Integrator'
  real_T lastSin;                      // '<Root>/Sine Wave'
  real_T lastCos;                      // '<Root>/Sine Wave'
  real_T start_time_yaw;               // '<S35>/Data Store Memory'
  real_T start_time;                   // '<S17>/Data Store Memory'
  real_T start_time_roll;              // '<S26>/Data Store Memory'
  real_T e_pitch;                      // '<S1>/e_pitch'
  real_T e_pitch_roll;                 // '<S1>/e_pitch1'
  real_T e_pitch_yaw;                  // '<S1>/e_pitch2'
  real_T speed_y;                      // '<Root>/Data Store Memory10'
  real_T pos_x;                        // '<Root>/Data Store Memory11'
  real_T pos_y;                        // '<Root>/Data Store Memory12'
  real_T yaw_speed;                    // '<Root>/Data Store Memory16'
  real_T roll_speed;                   // '<Root>/Data Store Memory17'
  real_T pitch_speed;                  // '<Root>/Data Store Memory18'
  real_T pitch_acc;                    // '<Root>/Data Store Memory19'
  real_T accX;                         // '<Root>/Data Store Memory2'
  real_T roll_acc;                     // '<Root>/Data Store Memory20'
  real_T yaw_acc;                      // '<Root>/Data Store Memory21'
  real_T u1;                           // '<Root>/Data Store Memory28'
  real_T t;                            // '<Root>/Data Store Memory29'
  real_T accY;                         // '<Root>/Data Store Memory3'
  real_T pitch;                        // '<Root>/Data Store Memory4'
  real_T roll;                         // '<Root>/Data Store Memory6'
  real_T yaw;                          // '<Root>/Data Store Memory8'
  real_T speed_x;                      // '<Root>/Data Store Memory9'
  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<S35>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_o;                     // '<S17>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_i;                     // '<S26>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_ot;                    // '<S14>/Scope'

  struct {
    void *LoggedData[2];
  } Scope_PWORK_f;                     // '<S1>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_b;                     // '<S12>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     // '<S13>/Scope'

  struct {
    void *LoggedData[3];
  } Scope_PWORK_m;                     // '<Root>/Scope'

  struct {
    void *LoggedData[4];
  } Scope1_PWORK;                      // '<Root>/Scope1'

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      // '<Root>/Scope2'

  int32_T systemEnable;                // '<Root>/Sine Wave'
  int8_T Subsystem1_SubsysRanBC;       // '<Root>/Subsystem1'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S46>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S46>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S46>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S3>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_b;// '<S2>/Enabled Subsystem'
  int8_T Subsystem_SubsysRanBC;        // '<S38>/Subsystem'
  int8_T Subsystem_SubsysRanBC_m;      // '<S29>/Subsystem'
  int8_T Subsystem_SubsysRanBC_k;      // '<S20>/Subsystem'
  boolean_T attitude_flag;             // '<Root>/Data Store Memory'
  boolean_T observer_flag;             // '<Root>/Data Store Memory30'
};

// Zero-crossing (trigger) state
struct PrevZCX_px42LoopCtrQGC2022031_T {
  ZCSigState Subsystem_Trig_ZCE;       // '<S38>/Subsystem'
  ZCSigState Subsystem_Trig_ZCE_j;     // '<S29>/Subsystem'
  ZCSigState Subsystem_Trig_ZCE_e;     // '<S20>/Subsystem'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY_px42LoopCtrQGC20220313_T {
  real_T u;                            // '<Root>/u'
};

// Parameters (default storage)
struct P_px42LoopCtrQGC20220313_T_ {
  real_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S33>/UD'

  real_T DiscreteDerivative1_ICPrevSca_o;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_o
                                 //  Referenced by: '<S15>/UD'

  real_T DiscreteDerivative1_ICPrevSca_d;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_d
                                 //  Referenced by: '<S24>/UD'

  real_T CompareToConstant1_const;   // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S36>/Constant'

  real_T CompareToConstant1_const_b;
                                   // Mask Parameter: CompareToConstant1_const_b
                                      //  Referenced by: '<S18>/Constant'

  real_T CompareToConstant1_const_h;
                                   // Mask Parameter: CompareToConstant1_const_h
                                      //  Referenced by: '<S27>/Constant'

  real_T CompareToConstant2_const;   // Mask Parameter: CompareToConstant2_const
                                        //  Referenced by: '<S40>/Constant'

  real_T CompareToConstant1_const_hq;
                                  // Mask Parameter: CompareToConstant1_const_hq
                                     //  Referenced by: '<S39>/Constant'

  real_T CompareToConstant2_const_o;
                                   // Mask Parameter: CompareToConstant2_const_o
                                      //  Referenced by: '<S22>/Constant'

  real_T CompareToConstant1_const_p;
                                   // Mask Parameter: CompareToConstant1_const_p
                                      //  Referenced by: '<S21>/Constant'

  real_T CompareToConstant2_const_a;
                                   // Mask Parameter: CompareToConstant2_const_a
                                      //  Referenced by: '<S31>/Constant'

  real_T CompareToConstant1_const_a;
                                   // Mask Parameter: CompareToConstant1_const_a
                                      //  Referenced by: '<S30>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S43>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S3>/Constant'

  px4_Bus_actuator_outputs Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S42>/Out1'

  px4_Bus_actuator_outputs Constant_Value_c;// Computed Parameter: Constant_Value_c
                                               //  Referenced by: '<S2>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S9>/Constant1'

  real_T Constant1_Value_n;            // Expression: 0
                                          //  Referenced by: '<S10>/Constant1'

  real_T Constant1_Value_a;            // Expression: 0
                                          //  Referenced by: '<S11>/Constant1'

  real_T Saturation_UpperSat;          // Expression: 0.1
                                          //  Referenced by: '<S1>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.1
                                          //  Referenced by: '<S1>/Saturation'

  real_T Constant_Value_b;             // Expression: 0
                                          //  Referenced by: '<S1>/Constant'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<S12>/Constant3'

  real_T Constant3_Value_a;            // Expression: 0
                                          //  Referenced by: '<S13>/Constant3'

  real_T Constant3_Value_d;            // Expression: 0
                                          //  Referenced by: '<S14>/Constant3'

  real_T Constant_Value_e;             // Expression: 1
                                          //  Referenced by: '<S47>/Constant'

  real_T Constant_Value_b1;            // Expression: 1
                                          //  Referenced by: '<S48>/Constant'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S5>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                          //  Referenced by: '<S5>/Discrete-Time Integrator'

  real_T Constant9_Value;              // Expression: 1
                                          //  Referenced by: '<S5>/Constant9'

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

  real_T DataStoreMemory5_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Data Store Memory5'

  real_T Constant3_Value_g;            // Expression: 0
                                          //  Referenced by: '<Root>/Constant3'

  real_T r_Value;                      // Expression: 8.00109649122807
                                          //  Referenced by: '<S35>/r'

  real_T ch_Value;                     // Expression: 2
                                          //  Referenced by: '<S35>/ch'

  real_T T_Value;                      // Expression: 5
                                          //  Referenced by: '<S35>/T'

  real_T t_Value;                      // Expression: 0
                                          //  Referenced by: '<S35>/t'

  real_T b_Value;                      // Expression: 2.036184210526316
                                          //  Referenced by: '<S11>/b'

  real_T Gain4_Gain;                   // Expression: -1
                                          //  Referenced by: '<S34>/Gain4'

  real_T TSamp_WtEt;                   // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S33>/TSamp'

  real_T l_Value;                      // Expression: 0.5282118055555556
                                          //  Referenced by: '<S11>/l'

  real_T Gain_Gain;                    // Expression: 0.01/0.0052
                                          //  Referenced by: '<S11>/Gain'

  real_T Gain1_Gain;                   // Expression: 0.00502
                                          //  Referenced by: '<S11>/Gain1'

  real_T DiscreteTimeIntegrator3_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator3_gainval
                             //  Referenced by: '<S14>/Discrete-Time Integrator3'

  real_T DiscreteTimeIntegrator3_IC;   // Expression: 0
                                          //  Referenced by: '<S14>/Discrete-Time Integrator3'

  real_T Gain1_Gain_o;                 // Expression: 0.008
                                          //  Referenced by: '<S1>/Gain1'

  real_T Saturation4_UpperSat;         // Expression: 0.2
                                          //  Referenced by: '<S1>/Saturation4'

  real_T Saturation4_LowerSat;         // Expression: -0.5
                                          //  Referenced by: '<S1>/Saturation4'

  real_T SineWave_Amp;                 // Expression: pi/18
                                          //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_Bias;                // Expression: 0
                                          //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_Freq;                // Expression: pi/5
                                          //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_Hsin;                // Computed Parameter: SineWave_Hsin
                                          //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_HCos;                // Computed Parameter: SineWave_HCos
                                          //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_PSin;                // Computed Parameter: SineWave_PSin
                                          //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_PCos;                // Computed Parameter: SineWave_PCos
                                          //  Referenced by: '<Root>/Sine Wave'

  real_T r_Value_g;                    // Expression: 6.033653846153846
                                          //  Referenced by: '<S17>/r'

  real_T ch_Value_j;                   // Expression: 2
                                          //  Referenced by: '<S17>/ch'

  real_T T_Value_p;                    // Expression: 5.018640350877193
                                          //  Referenced by: '<S17>/T'

  real_T t_Value_n;                    // Expression: 0
                                          //  Referenced by: '<S17>/t'

  real_T b_Value_l;                    // Expression: 2.470900809716599
                                          //  Referenced by: '<S9>/b'

  real_T Gain4_Gain_b;                 // Expression: -1
                                          //  Referenced by: '<S16>/Gain4'

  real_T TSamp_WtEt_p;                 // Computed Parameter: TSamp_WtEt_p
                                          //  Referenced by: '<S15>/TSamp'

  real_T l_Value_b;                    // Expression: 0.5282118055555556
                                          //  Referenced by: '<S9>/l'

  real_T Gain_Gain_o;                  // Expression: 0.01/0.0052
                                          //  Referenced by: '<S9>/Gain'

  real_T Gain1_Gain_b;                 // Expression: 0.00502
                                          //  Referenced by: '<S9>/Gain1'

  real_T DiscreteTimeIntegrator3_gainv_m;
                          // Computed Parameter: DiscreteTimeIntegrator3_gainv_m
                             //  Referenced by: '<S12>/Discrete-Time Integrator3'

  real_T DiscreteTimeIntegrator3_IC_k; // Expression: 0
                                          //  Referenced by: '<S12>/Discrete-Time Integrator3'

  real_T Gain2_Gain;                   // Expression: 0.00478
                                          //  Referenced by: '<S1>/Gain2'

  real_T r_Value_p;                    // Expression: 6.001388888888889
                                          //  Referenced by: '<S26>/r'

  real_T ch_Value_e;                   // Expression: 2
                                          //  Referenced by: '<S26>/ch'

  real_T T_Value_c;                    // Expression: 5
                                          //  Referenced by: '<S26>/T'

  real_T t_Value_m;                    // Expression: 0
                                          //  Referenced by: '<S26>/t'

  real_T b_Value_h;                    // Expression: 2.490277777777778
                                          //  Referenced by: '<S10>/b'

  real_T Gain4_Gain_o;                 // Expression: -1
                                          //  Referenced by: '<S25>/Gain4'

  real_T TSamp_WtEt_o;                 // Computed Parameter: TSamp_WtEt_o
                                          //  Referenced by: '<S24>/TSamp'

  real_T l_Value_n;                    // Expression: 0.5340277777777778
                                          //  Referenced by: '<S10>/l'

  real_T Gain_Gain_m;                  // Expression: 0.01/0.0052
                                          //  Referenced by: '<S10>/Gain'

  real_T J_Gain;                       // Expression: 0.00478
                                          //  Referenced by: '<S10>/J'

  real_T DiscreteTimeIntegrator3_gainv_e;
                          // Computed Parameter: DiscreteTimeIntegrator3_gainv_e
                             //  Referenced by: '<S13>/Discrete-Time Integrator3'

  real_T DiscreteTimeIntegrator3_IC_l; // Expression: 0
                                          //  Referenced by: '<S13>/Discrete-Time Integrator3'

  real_T J_Gain_b;                     // Expression: 0.00478
                                          //  Referenced by: '<S1>/J'

  real_T DataStoreMemory_InitialValue; // Expression: 0
                                          //  Referenced by: '<S35>/Data Store Memory'

  real_T DataStoreMemory_InitialValue_l;// Expression: 0
                                           //  Referenced by: '<S17>/Data Store Memory'

  real_T DataStoreMemory_InitialValue_b;// Expression: 0
                                           //  Referenced by: '<S26>/Data Store Memory'

  real_T DiscreteTimeIntegrator_gainva_n;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_n
                             //  Referenced by: '<S14>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_l;  // Expression: 0
                                          //  Referenced by: '<S14>/Discrete-Time Integrator'

  real_T Gain2_Gain_c;                 // Expression: 180/pi
                                          //  Referenced by: '<S14>/Gain2'

  real_T uJ_Gain;                      // Expression: 1/0.008
                                          //  Referenced by: '<S14>/1//J'

  real_T kJ_Gain;                      // Expression: 0.01/0.008
                                          //  Referenced by: '<S14>/k//J'

  real_T Saturation_UpperSat_b;        // Expression: 1
                                          //  Referenced by: '<S14>/Saturation'

  real_T Saturation_LowerSat_k;        // Expression: -1
                                          //  Referenced by: '<S14>/Saturation'

  real_T l1_Gain;                      // Expression: 0
                                          //  Referenced by: '<S14>/l1'

  real_T lambda1_Gain;                 // Expression: 0
                                          //  Referenced by: '<S14>/lambda1'

  real_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S14>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC;   // Expression: 0
                                          //  Referenced by: '<S14>/Discrete-Time Integrator1'

  real_T Constant1_Value_f;            // Expression: 0.1
                                          //  Referenced by: '<S14>/Constant1'

  real_T Saturation10_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S14>/Saturation10'

  real_T Saturation10_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S14>/Saturation10'

  real_T Saturation11_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S14>/Saturation11'

  real_T Saturation11_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S14>/Saturation11'

  real_T Gain_Gain_ml;                 // Expression: 0.5
                                          //  Referenced by: '<S14>/Gain'

  real_T Saturation8_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S14>/Saturation8'

  real_T Saturation8_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S14>/Saturation8'

  real_T Constant2_Value;              // Expression: 1
                                          //  Referenced by: '<S14>/Constant2'

  real_T Gain5_Gain;                   // Expression: 30
                                          //  Referenced by: '<S14>/Gain5'

  real_T Saturation13_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S14>/Saturation13'

  real_T Saturation13_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S14>/Saturation13'

  real_T Saturation9_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S14>/Saturation9'

  real_T Saturation9_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S14>/Saturation9'

  real_T Gain1_Gain_a;                 // Expression: 0.5
                                          //  Referenced by: '<S14>/Gain1'

  real_T Constant4_Value;              // Expression: 1
                                          //  Referenced by: '<S14>/Constant4'

  real_T Saturation12_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S14>/Saturation12'

  real_T Saturation12_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S14>/Saturation12'

  real_T Saturation16_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S14>/Saturation16'

  real_T Saturation16_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S14>/Saturation16'

  real_T Saturation14_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S14>/Saturation14'

  real_T Saturation14_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S14>/Saturation14'

  real_T Gain3_Gain;                   // Expression: 0.5
                                          //  Referenced by: '<S14>/Gain3'

  real_T Constant6_Value;              // Expression: 1
                                          //  Referenced by: '<S14>/Constant6'

  real_T lambda2_Gain;                 // Expression: 0
                                          //  Referenced by: '<S14>/lambda2'

  real_T Saturation1_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S14>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S14>/Saturation1'

  real_T l2_Gain;                      // Expression: 0
                                          //  Referenced by: '<S14>/l2'

  real_T Saturation15_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S14>/Saturation15'

  real_T Saturation15_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S14>/Saturation15'

  real_T Gain6_Gain;                   // Expression: 30
                                          //  Referenced by: '<S14>/Gain6'

  real_T Saturation19_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S14>/Saturation19'

  real_T Saturation19_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S14>/Saturation19'

  real_T Saturation17_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S14>/Saturation17'

  real_T Saturation17_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S14>/Saturation17'

  real_T Gain4_Gain_f;                 // Expression: 0.5
                                          //  Referenced by: '<S14>/Gain4'

  real_T Constant8_Value;              // Expression: 1
                                          //  Referenced by: '<S14>/Constant8'

  real_T Saturation18_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S14>/Saturation18'

  real_T Saturation18_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S14>/Saturation18'

  real_T Saturation3_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S14>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S14>/Saturation3'

  real_T l4_Gain;                      // Expression: 0
                                          //  Referenced by: '<S14>/l4'

  real_T lambda4_Gain;                 // Expression: 0
                                          //  Referenced by: '<S14>/lambda4'

  real_T Gain7_Gain;                   // Expression: 40
                                          //  Referenced by: '<S14>/Gain7'

  real_T Gain8_Gain;                   // Expression: 1
                                          //  Referenced by: '<S14>/Gain8'

  real_T DiscreteTimeIntegrator_gainva_e;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_e
                             //  Referenced by: '<S12>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_h;  // Expression: 0
                                          //  Referenced by: '<S12>/Discrete-Time Integrator'

  real_T Gain2_Gain_g;                 // Expression: 180/pi
                                          //  Referenced by: '<S12>/Gain2'

  real_T uJ_Gain_p;                    // Expression: 1/0.00478
                                          //  Referenced by: '<S12>/1//J'

  real_T kJ_Gain_c;                    // Expression: 0.01/0.00478
                                          //  Referenced by: '<S12>/k//J'

  real_T Saturation_UpperSat_n;        // Expression: 1
                                          //  Referenced by: '<S12>/Saturation'

  real_T Saturation_LowerSat_g;        // Expression: -1
                                          //  Referenced by: '<S12>/Saturation'

  real_T l1_Gain_p;                    // Expression: 0
                                          //  Referenced by: '<S12>/l1'

  real_T lambda1_Gain_a;               // Expression: 0
                                          //  Referenced by: '<S12>/lambda1'

  real_T DiscreteTimeIntegrator1_gainv_n;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainv_n
                             //  Referenced by: '<S12>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC_j; // Expression: 0
                                          //  Referenced by: '<S12>/Discrete-Time Integrator1'

  real_T Constant1_Value_j;            // Expression: 0.1
                                          //  Referenced by: '<S12>/Constant1'

  real_T Saturation10_UpperSat_o;      // Expression: 1
                                          //  Referenced by: '<S12>/Saturation10'

  real_T Saturation10_LowerSat_b;      // Expression: -1
                                          //  Referenced by: '<S12>/Saturation10'

  real_T Saturation11_UpperSat_p;      // Expression: 1
                                          //  Referenced by: '<S12>/Saturation11'

  real_T Saturation11_LowerSat_i;      // Expression: -1
                                          //  Referenced by: '<S12>/Saturation11'

  real_T Gain_Gain_g;                  // Expression: 0.5
                                          //  Referenced by: '<S12>/Gain'

  real_T Saturation8_UpperSat_g;       // Expression: 1
                                          //  Referenced by: '<S12>/Saturation8'

  real_T Saturation8_LowerSat_g;       // Expression: -1
                                          //  Referenced by: '<S12>/Saturation8'

  real_T Constant2_Value_h;            // Expression: 1
                                          //  Referenced by: '<S12>/Constant2'

  real_T Gain5_Gain_o;                 // Expression: 30
                                          //  Referenced by: '<S12>/Gain5'

  real_T Saturation13_UpperSat_i;      // Expression: 1
                                          //  Referenced by: '<S12>/Saturation13'

  real_T Saturation13_LowerSat_c;      // Expression: -1
                                          //  Referenced by: '<S12>/Saturation13'

  real_T Saturation9_UpperSat_i;       // Expression: 1
                                          //  Referenced by: '<S12>/Saturation9'

  real_T Saturation9_LowerSat_c;       // Expression: -1
                                          //  Referenced by: '<S12>/Saturation9'

  real_T Gain1_Gain_d;                 // Expression: 0.5
                                          //  Referenced by: '<S12>/Gain1'

  real_T Constant4_Value_n;            // Expression: 1
                                          //  Referenced by: '<S12>/Constant4'

  real_T Saturation12_UpperSat_c;      // Expression: 1
                                          //  Referenced by: '<S12>/Saturation12'

  real_T Saturation12_LowerSat_b;      // Expression: -1
                                          //  Referenced by: '<S12>/Saturation12'

  real_T Saturation16_UpperSat_l;      // Expression: 1
                                          //  Referenced by: '<S12>/Saturation16'

  real_T Saturation16_LowerSat_g;      // Expression: -1
                                          //  Referenced by: '<S12>/Saturation16'

  real_T Saturation14_UpperSat_l;      // Expression: 1
                                          //  Referenced by: '<S12>/Saturation14'

  real_T Saturation14_LowerSat_b;      // Expression: -1
                                          //  Referenced by: '<S12>/Saturation14'

  real_T Gain3_Gain_l;                 // Expression: 0.5
                                          //  Referenced by: '<S12>/Gain3'

  real_T Constant6_Value_o;            // Expression: 1
                                          //  Referenced by: '<S12>/Constant6'

  real_T lambda2_Gain_j;               // Expression: 0
                                          //  Referenced by: '<S12>/lambda2'

  real_T Saturation1_UpperSat_a;       // Expression: 1
                                          //  Referenced by: '<S12>/Saturation1'

  real_T Saturation1_LowerSat_i;       // Expression: -1
                                          //  Referenced by: '<S12>/Saturation1'

  real_T l2_Gain_l;                    // Expression: 0
                                          //  Referenced by: '<S12>/l2'

  real_T Saturation15_UpperSat_j;      // Expression: 1
                                          //  Referenced by: '<S12>/Saturation15'

  real_T Saturation15_LowerSat_k;      // Expression: -1
                                          //  Referenced by: '<S12>/Saturation15'

  real_T Gain6_Gain_e;                 // Expression: 30
                                          //  Referenced by: '<S12>/Gain6'

  real_T Saturation19_UpperSat_b;      // Expression: 1
                                          //  Referenced by: '<S12>/Saturation19'

  real_T Saturation19_LowerSat_j;      // Expression: -1
                                          //  Referenced by: '<S12>/Saturation19'

  real_T Saturation17_UpperSat_d;      // Expression: 1
                                          //  Referenced by: '<S12>/Saturation17'

  real_T Saturation17_LowerSat_o;      // Expression: -1
                                          //  Referenced by: '<S12>/Saturation17'

  real_T Gain4_Gain_n;                 // Expression: 0.5
                                          //  Referenced by: '<S12>/Gain4'

  real_T Constant8_Value_f;            // Expression: 1
                                          //  Referenced by: '<S12>/Constant8'

  real_T Saturation18_UpperSat_a;      // Expression: 1
                                          //  Referenced by: '<S12>/Saturation18'

  real_T Saturation18_LowerSat_h;      // Expression: -1
                                          //  Referenced by: '<S12>/Saturation18'

  real_T Saturation3_UpperSat_m;       // Expression: 1
                                          //  Referenced by: '<S12>/Saturation3'

  real_T Saturation3_LowerSat_i;       // Expression: -1
                                          //  Referenced by: '<S12>/Saturation3'

  real_T l4_Gain_p;                    // Expression: 0
                                          //  Referenced by: '<S12>/l4'

  real_T lambda4_Gain_a;               // Expression: 0
                                          //  Referenced by: '<S12>/lambda4'

  real_T Gain7_Gain_d;                 // Expression: 40
                                          //  Referenced by: '<S12>/Gain7'

  real_T Gain8_Gain_b;                 // Expression: 1
                                          //  Referenced by: '<S12>/Gain8'

  real_T DiscreteTimeIntegrator_gainv_nv;
                          // Computed Parameter: DiscreteTimeIntegrator_gainv_nv
                             //  Referenced by: '<S13>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_o;  // Expression: 0
                                          //  Referenced by: '<S13>/Discrete-Time Integrator'

  real_T Gain2_Gain_p;                 // Expression: 180/pi
                                          //  Referenced by: '<S13>/Gain2'

  real_T uJ_Gain_g;                    // Expression: 1/0.00478
                                          //  Referenced by: '<S13>/1//J'

  real_T kJ_Gain_p;                    // Expression: 0.01/0.00478
                                          //  Referenced by: '<S13>/k//J'

  real_T Saturation_UpperSat_n1;       // Expression: 1
                                          //  Referenced by: '<S13>/Saturation'

  real_T Saturation_LowerSat_c;        // Expression: -1
                                          //  Referenced by: '<S13>/Saturation'

  real_T l1_Gain_d;                    // Expression: 0
                                          //  Referenced by: '<S13>/l1'

  real_T lambda1_Gain_g;               // Expression: 0
                                          //  Referenced by: '<S13>/lambda1'

  real_T DiscreteTimeIntegrator1_gainv_g;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainv_g
                             //  Referenced by: '<S13>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC_c; // Expression: 0
                                          //  Referenced by: '<S13>/Discrete-Time Integrator1'

  real_T Constant1_Value_ac;           // Expression: 0.1
                                          //  Referenced by: '<S13>/Constant1'

  real_T Saturation10_UpperSat_a;      // Expression: 1
                                          //  Referenced by: '<S13>/Saturation10'

  real_T Saturation10_LowerSat_l;      // Expression: -1
                                          //  Referenced by: '<S13>/Saturation10'

  real_T Saturation11_UpperSat_a;      // Expression: 1
                                          //  Referenced by: '<S13>/Saturation11'

  real_T Saturation11_LowerSat_a;      // Expression: -1
                                          //  Referenced by: '<S13>/Saturation11'

  real_T Gain_Gain_h;                  // Expression: 0.5
                                          //  Referenced by: '<S13>/Gain'

  real_T Saturation8_UpperSat_c;       // Expression: 1
                                          //  Referenced by: '<S13>/Saturation8'

  real_T Saturation8_LowerSat_c;       // Expression: -1
                                          //  Referenced by: '<S13>/Saturation8'

  real_T Constant2_Value_k;            // Expression: 1
                                          //  Referenced by: '<S13>/Constant2'

  real_T Gain5_Gain_l;                 // Expression: 30
                                          //  Referenced by: '<S13>/Gain5'

  real_T Saturation13_UpperSat_p;      // Expression: 1
                                          //  Referenced by: '<S13>/Saturation13'

  real_T Saturation13_LowerSat_j;      // Expression: -1
                                          //  Referenced by: '<S13>/Saturation13'

  real_T Saturation9_UpperSat_d;       // Expression: 1
                                          //  Referenced by: '<S13>/Saturation9'

  real_T Saturation9_LowerSat_c4;      // Expression: -1
                                          //  Referenced by: '<S13>/Saturation9'

  real_T Gain1_Gain_e;                 // Expression: 0.5
                                          //  Referenced by: '<S13>/Gain1'

  real_T Constant4_Value_l;            // Expression: 1
                                          //  Referenced by: '<S13>/Constant4'

  real_T Saturation12_UpperSat_d;      // Expression: 1
                                          //  Referenced by: '<S13>/Saturation12'

  real_T Saturation12_LowerSat_j;      // Expression: -1
                                          //  Referenced by: '<S13>/Saturation12'

  real_T Saturation16_UpperSat_p;      // Expression: 1
                                          //  Referenced by: '<S13>/Saturation16'

  real_T Saturation16_LowerSat_i;      // Expression: -1
                                          //  Referenced by: '<S13>/Saturation16'

  real_T Saturation14_UpperSat_n;      // Expression: 1
                                          //  Referenced by: '<S13>/Saturation14'

  real_T Saturation14_LowerSat_a;      // Expression: -1
                                          //  Referenced by: '<S13>/Saturation14'

  real_T Gain3_Gain_p;                 // Expression: 0.5
                                          //  Referenced by: '<S13>/Gain3'

  real_T Constant6_Value_g;            // Expression: 1
                                          //  Referenced by: '<S13>/Constant6'

  real_T lambda2_Gain_d;               // Expression: 0
                                          //  Referenced by: '<S13>/lambda2'

  real_T Saturation1_UpperSat_d;       // Expression: 1
                                          //  Referenced by: '<S13>/Saturation1'

  real_T Saturation1_LowerSat_g;       // Expression: -1
                                          //  Referenced by: '<S13>/Saturation1'

  real_T l2_Gain_i;                    // Expression: 0
                                          //  Referenced by: '<S13>/l2'

  real_T Saturation15_UpperSat_k;      // Expression: 1
                                          //  Referenced by: '<S13>/Saturation15'

  real_T Saturation15_LowerSat_h;      // Expression: -1
                                          //  Referenced by: '<S13>/Saturation15'

  real_T Gain6_Gain_f;                 // Expression: 30
                                          //  Referenced by: '<S13>/Gain6'

  real_T Saturation19_UpperSat_bc;     // Expression: 1
                                          //  Referenced by: '<S13>/Saturation19'

  real_T Saturation19_LowerSat_e;      // Expression: -1
                                          //  Referenced by: '<S13>/Saturation19'

  real_T Saturation17_UpperSat_o;      // Expression: 1
                                          //  Referenced by: '<S13>/Saturation17'

  real_T Saturation17_LowerSat_m;      // Expression: -1
                                          //  Referenced by: '<S13>/Saturation17'

  real_T Gain4_Gain_e;                 // Expression: 0.5
                                          //  Referenced by: '<S13>/Gain4'

  real_T Constant8_Value_p;            // Expression: 1
                                          //  Referenced by: '<S13>/Constant8'

  real_T Saturation18_UpperSat_c;      // Expression: 1
                                          //  Referenced by: '<S13>/Saturation18'

  real_T Saturation18_LowerSat_g;      // Expression: -1
                                          //  Referenced by: '<S13>/Saturation18'

  real_T Saturation3_UpperSat_i;       // Expression: 1
                                          //  Referenced by: '<S13>/Saturation3'

  real_T Saturation3_LowerSat_g;       // Expression: -1
                                          //  Referenced by: '<S13>/Saturation3'

  real_T l4_Gain_o;                    // Expression: 0
                                          //  Referenced by: '<S13>/l4'

  real_T lambda4_Gain_b;               // Expression: 0
                                          //  Referenced by: '<S13>/lambda4'

  real_T Gain7_Gain_l;                 // Expression: 40
                                          //  Referenced by: '<S13>/Gain7'

  real_T Gain8_Gain_o;                 // Expression: 1
                                          //  Referenced by: '<S13>/Gain8'

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

  real_T Constant1_Value_l;            // Expression: 1.1
                                          //  Referenced by: '<Root>/Constant1'

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

  real_T Gain5_Gain_g;                 // Expression: 180/3.1415926
                                          //  Referenced by: '<Root>/Gain5'

  real_T Gain3_Gain_c;                 // Expression: 180/3.1415926
                                          //  Referenced by: '<Root>/Gain3'

  real_T Gain6_Gain_k;                 // Expression: 180/3.1415926
                                          //  Referenced by: '<Root>/Gain6'

  real_T Saturation_UpperSat_e;        // Expression: 1.2
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat_l;        // Expression: 1
                                          //  Referenced by: '<Root>/Saturation'

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

  real_T DataStoreMemory28_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory28'

  real_T DataStoreMemory29_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory29'

  real_T DataStoreMemory3_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Data Store Memory3'

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
                                         //  Referenced by: '<S6>/attitude_flag'

  boolean_T observer_flag_Value;      // Computed Parameter: observer_flag_Value
                                         //  Referenced by: '<S7>/observer_flag'

  boolean_T position_flag_Value;      // Computed Parameter: position_flag_Value
                                         //  Referenced by: '<S8>/position_flag'

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

  uint8_T ManualSwitch_CurrentSetting_i;
                            // Computed Parameter: ManualSwitch_CurrentSetting_i
                               //  Referenced by: '<Root>/Manual Switch'

};

// Real-time Model Data Structure
struct tag_RTM_px42LoopCtrQGC2022031_T {
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

  extern P_px42LoopCtrQGC20220313_T px42LoopCtrQGC20220313_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_px42LoopCtrQGC20220313_T px42LoopCtrQGC20220313_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_px42LoopCtrQGC20220313_T px42LoopCtrQGC20220313_DW;

// Zero-crossing (trigger) state
extern PrevZCX_px42LoopCtrQGC2022031_T px42LoopCtrQGC20220313_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // External outputs (root outports fed by signals with default storage)
  extern struct ExtY_px42LoopCtrQGC20220313_T px42LoopCtrQGC20220313_Y;

#ifdef __cplusplus

}
#endif

// External function called from main
#ifdef __cplusplus

extern "C" {

#endif

  extern void px42LoopCtrQGC20220313_SetEventsForThisBaseStep(boolean_T
    *eventFlags);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void px42LoopCtrQGC20220313_SetEventsForThisBaseStep(boolean_T
    *eventFlags);
  extern void px42LoopCtrQGC20220313_initialize(void);
  extern void px42LoopCtrQGC20220313_step0(void);
  extern void px42LoopCtrQGC20220313_step1(void);
  extern void px42LoopCtrQGC20220313_step(int_T tid);
  extern void px42LoopCtrQGC20220313_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_px42LoopCtrQGC202203_T *const px42LoopCtrQGC20220313_M;

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
//  '<Root>' : 'px42LoopCtrQGC20220313'
//  '<S1>'   : 'px42LoopCtrQGC20220313/Attitude controller'
//  '<S2>'   : 'px42LoopCtrQGC20220313/PX4 uORB Read'
//  '<S3>'   : 'px42LoopCtrQGC20220313/PX4 uORB Read2'
//  '<S4>'   : 'px42LoopCtrQGC20220313/Quaternions to Rotation Angles'
//  '<S5>'   : 'px42LoopCtrQGC20220313/Subsystem1'
//  '<S6>'   : 'px42LoopCtrQGC20220313/attitude_button'
//  '<S7>'   : 'px42LoopCtrQGC20220313/observer_button'
//  '<S8>'   : 'px42LoopCtrQGC20220313/position_button'
//  '<S9>'   : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem'
//  '<S10>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem6'
//  '<S11>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem7'
//  '<S12>'  : 'px42LoopCtrQGC20220313/Attitude controller/observer_pitch_3'
//  '<S13>'  : 'px42LoopCtrQGC20220313/Attitude controller/observer_roll_3'
//  '<S14>'  : 'px42LoopCtrQGC20220313/Attitude controller/observer_yaw'
//  '<S15>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem/Discrete Derivative1'
//  '<S16>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem/Subsystem1'
//  '<S17>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem/Subsystem1/Subsystem'
//  '<S18>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem/Subsystem1/Subsystem/Compare To Constant1'
//  '<S19>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem/Subsystem1/Subsystem/MATLAB Function'
//  '<S20>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem/Subsystem1/Subsystem/start_time'
//  '<S21>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem/Subsystem1/Subsystem/start_time/Compare To Constant1'
//  '<S22>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem/Subsystem1/Subsystem/start_time/Compare To Constant2'
//  '<S23>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem/Subsystem1/Subsystem/start_time/Subsystem'
//  '<S24>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem6/Discrete Derivative1'
//  '<S25>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem6/Subsystem1'
//  '<S26>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem6/Subsystem1/Subsystem'
//  '<S27>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem6/Subsystem1/Subsystem/Compare To Constant1'
//  '<S28>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem6/Subsystem1/Subsystem/MATLAB Function'
//  '<S29>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem6/Subsystem1/Subsystem/start_time'
//  '<S30>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem6/Subsystem1/Subsystem/start_time/Compare To Constant1'
//  '<S31>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem6/Subsystem1/Subsystem/start_time/Compare To Constant2'
//  '<S32>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem6/Subsystem1/Subsystem/start_time/Subsystem'
//  '<S33>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem7/Discrete Derivative1'
//  '<S34>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem7/Subsystem1'
//  '<S35>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem7/Subsystem1/Subsystem'
//  '<S36>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem7/Subsystem1/Subsystem/Compare To Constant1'
//  '<S37>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem7/Subsystem1/Subsystem/MATLAB Function'
//  '<S38>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem7/Subsystem1/Subsystem/start_time'
//  '<S39>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem7/Subsystem1/Subsystem/start_time/Compare To Constant1'
//  '<S40>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem7/Subsystem1/Subsystem/start_time/Compare To Constant2'
//  '<S41>'  : 'px42LoopCtrQGC20220313/Attitude controller/Subsystem7/Subsystem1/Subsystem/start_time/Subsystem'
//  '<S42>'  : 'px42LoopCtrQGC20220313/PX4 uORB Read/Enabled Subsystem'
//  '<S43>'  : 'px42LoopCtrQGC20220313/PX4 uORB Read2/Enabled Subsystem'
//  '<S44>'  : 'px42LoopCtrQGC20220313/Quaternions to Rotation Angles/Angle Calculation'
//  '<S45>'  : 'px42LoopCtrQGC20220313/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S46>'  : 'px42LoopCtrQGC20220313/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S47>'  : 'px42LoopCtrQGC20220313/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S48>'  : 'px42LoopCtrQGC20220313/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S49>'  : 'px42LoopCtrQGC20220313/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S50>'  : 'px42LoopCtrQGC20220313/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S51>'  : 'px42LoopCtrQGC20220313/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                                 // RTW_HEADER_px42LoopCtrQGC20220313_h_

//
// File trailer for generated code.
//
// [EOF]
//
