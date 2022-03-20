//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px42LoopCtrQGCGPS202203131707.h
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
#ifndef RTW_HEADER_px42LoopCtrQGCGPS202203131707_h_
#define RTW_HEADER_px42LoopCtrQGCGPS202203131707_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "px42LoopCtrQGCGPS202203131707_types.h"
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/actuator_outputs.h>
#include <string.h>

extern "C" {

#include "rt_nonfinite.h"

}
#include <stddef.h>
#include "zero_crossing_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define px42LoopCtrQGCGPS202203131707_M (px42LoopCtrQGCGPS20220313170_M)

// Block signals (default storage)
struct B_px42LoopCtrQGCGPS2022031317_T {
  px4_Bus_vehicle_odometry In1;        // '<S48>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  px4_Bus_actuator_outputs In1_a;      // '<S47>/In1'
  px4_Bus_actuator_outputs b_varargout_2_m;
  uint16_T pwmValue[8];
  real_T z1_i;                         // '<S18>/Discrete-Time Integrator1'
  real_T z2;                           // '<S19>/Discrete-Time Integrator3'
  real_T TSamp;                        // '<S38>/TSamp'
  real_T Add3;                         // '<S1>/Add3'
  real_T z2_e;                         // '<S17>/Discrete-Time Integrator3'
  real_T Product_c;                    // '<S14>/Product'
  real_T yaw;                          // '<Root>/Gain9'
  real_T z2_l;                         // '<S18>/Discrete-Time Integrator3'
  real_T Product_cm;                   // '<S15>/Product'
  real_T roll;                         // '<Root>/Gain7'
  real_T DiscreteTimeIntegrator_f;     // '<S49>/Discrete-Time Integrator'
  real_T roll_hat_k;                   // '<S18>/Discrete-Time Integrator'
  real_T Product3;                     // '<S19>/Product3'
  real_T Product4;                     // '<S19>/Product4'
  real_T e_g;                          // '<S19>/Add11'
  real_T Product6;                     // '<S19>/Product6'
  real_T l2;                           // '<S19>/l2'
  real_T Product7;                     // '<S19>/Product7'
  real_T l4;                           // '<S19>/l4'
  real_T lambda4;                      // '<S19>/lambda4'
  real_T lambda1_a;                    // '<S17>/lambda1'
  real_T Product3_a;                   // '<S17>/Product3'
  real_T Product4_k;                   // '<S17>/Product4'
  real_T e_gq;                         // '<S17>/Add11'
  real_T Product6_i;                   // '<S17>/Product6'
  real_T l2_j;                         // '<S17>/l2'
  real_T Product7_e;                   // '<S17>/Product7'
  real_T lambda4_n;                    // '<S17>/lambda4'
  real_T lambda1_e;                    // '<S18>/lambda1'
  real_T Product3_c;                   // '<S18>/Product3'
  real_T Product4_g;                   // '<S18>/Product4'
  real_T e_e1;                         // '<S18>/Add11'
  real_T Product6_a;                   // '<S18>/Product6'
  real_T e_l;                          // '<S18>/Add16'
  real_T l4_k;                         // '<S18>/l4'
  real_T lambda4_h;                    // '<S18>/lambda4'
  real_T TSamp_f;                      // '<S51>/TSamp'
  real_T rtb_DataStoreRead49_c;
  real_T rtb_Fcn_a_k;
  real_T rtb_roll_hat_e_c;
  real_T rtb_Fcn_b_b;
  real_T rtb_DataStoreRead48_p;
  real_T rtb_Fcn_c;
  real_T yaw_thrust;
  real_T rtb_Switch_o_idx_1;
  real_T rtb_Switch_o_idx_0;
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  uint16_T Gain4[4];                   // '<Root>/Gain4'
};

// Block states (default storage) for system '<Root>'
struct DW_px42LoopCtrQGCGPS202203131_T {
  px4_internal_block_PWM_px42Lo_T obj; // '<Root>/PX4 PWM Output1'
  px4_internal_block_Subscriber_T obj_n;// '<S7>/SourceBlock'
  px4_internal_block_Subscriber_T obj_l;// '<S6>/SourceBlock'
  real_T UD_DSTATE;                    // '<S38>/UD'
  real_T DiscreteTimeIntegrator3_DSTATE;// '<S19>/Discrete-Time Integrator3'
  real_T UD_DSTATE_b;                  // '<S20>/UD'
  real_T DiscreteTimeIntegrator3_DSTAT_a;// '<S17>/Discrete-Time Integrator3'
  real_T UD_DSTATE_n;                  // '<S29>/UD'
  real_T DiscreteTimeIntegrator3_DSTAT_m;// '<S18>/Discrete-Time Integrator3'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S19>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator1_DSTATE;// '<S19>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator_DSTATE_p;// '<S17>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator1_DSTAT_i;// '<S17>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator_DSTATE_f;// '<S18>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator1_DSTAT_g;// '<S18>/Discrete-Time Integrator1'
  real_T Intgrt_dX_DSTATE;             // '<Root>/Intgrt_dX'
  real_T Intgrt_dY_DSTATE;             // '<Root>/Intgrt_dY'
  real_T Intgrt_ddY_DSTATE;            // '<Root>/Intgrt_ddY'
  real_T Intgrt_ddX_DSTATE;            // '<Root>/Intgrt_ddX'
  real_T UD_DSTATE_i;                  // '<S51>/UD'
  real_T DiscreteTimeIntegrator_DSTATE_a;// '<S49>/Discrete-Time Integrator'
  real_T UD_DSTATE_nu;                 // '<S52>/UD'
  real_T DiscreteTimeIntegrator_DSTATE_k;// '<S50>/Discrete-Time Integrator'
  real_T Intgrt_dZ_DSTATE;             // '<Root>/Intgrt_dZ'
  real_T Intgrt_ddZ_DSTATE;            // '<Root>/Intgrt_ddZ'
  real_T DiscreteTimeIntegrator_DSTAT_fj;// '<S10>/Discrete-Time Integrator'
  real_T start_time_yaw;               // '<S40>/Data Store Memory'
  real_T start_time;                   // '<S22>/Data Store Memory'
  real_T start_time_roll;              // '<S31>/Data Store Memory'
  real_T e_pitch;                      // '<S1>/e_pitch'
  real_T e_pitch_roll;                 // '<S1>/e_pitch1'
  real_T e_pitch_yaw;                  // '<S1>/e_pitch2'
  real_T yaw_speed;                    // '<Root>/Data Store Memory16'
  real_T roll_speed;                   // '<Root>/Data Store Memory17'
  real_T pitch_speed;                  // '<Root>/Data Store Memory18'
  real_T roll_desire;                  // '<Root>/Data Store Memory22'
  real_T pitch_desire;                 // '<Root>/Data Store Memory23'
  real_T q_x;                          // '<Root>/Data Store Memory24'
  real_T q_y;                          // '<Root>/Data Store Memory25'
  real_T q_z;                          // '<Root>/Data Store Memory26'
  real_T t;                            // '<Root>/Data Store Memory29'
  real_T pitch;                        // '<Root>/Data Store Memory4'
  real_T roll;                         // '<Root>/Data Store Memory6'
  real_T yaw;                          // '<Root>/Data Store Memory8'
  boolean_T attitude_flag;             // '<Root>/Data Store Memory'
  boolean_T armed;                     // '<Root>/Data Store Memory1'
  boolean_T position_flag;             // '<Root>/Data Store Memory27'
  boolean_T observer_flag;             // '<Root>/Data Store Memory30'
};

// Zero-crossing (trigger) state
struct PrevZCX_px42LoopCtrQGCGPS2022_T {
  ZCSigState Subsystem_Trig_ZCE;       // '<S43>/Subsystem'
  ZCSigState Subsystem_Trig_ZCE_j;     // '<S34>/Subsystem'
  ZCSigState Subsystem_Trig_ZCE_e;     // '<S25>/Subsystem'
};

// Parameters (default storage)
struct P_px42LoopCtrQGCGPS2022031317_T_ {
  real_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S38>/UD'

  real_T DiscreteDerivative1_ICPrevSca_o;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_o
                                 //  Referenced by: '<S20>/UD'

  real_T DiscreteDerivative1_ICPrevSca_d;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_d
                                 //  Referenced by: '<S29>/UD'

  real_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S51>/UD'

  real_T DiscreteDerivative_ICPrevScal_a;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_a
                                 //  Referenced by: '<S52>/UD'

  real_T CompareToConstant1_const;   // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S41>/Constant'

  real_T CompareToConstant1_const_b;
                                   // Mask Parameter: CompareToConstant1_const_b
                                      //  Referenced by: '<S23>/Constant'

  real_T CompareToConstant1_const_h;
                                   // Mask Parameter: CompareToConstant1_const_h
                                      //  Referenced by: '<S32>/Constant'

  real_T CompareToConstant2_const;   // Mask Parameter: CompareToConstant2_const
                                        //  Referenced by: '<S45>/Constant'

  real_T CompareToConstant1_const_hq;
                                  // Mask Parameter: CompareToConstant1_const_hq
                                     //  Referenced by: '<S44>/Constant'

  real_T CompareToConstant2_const_o;
                                   // Mask Parameter: CompareToConstant2_const_o
                                      //  Referenced by: '<S27>/Constant'

  real_T CompareToConstant1_const_p;
                                   // Mask Parameter: CompareToConstant1_const_p
                                      //  Referenced by: '<S26>/Constant'

  real_T CompareToConstant2_const_a;
                                   // Mask Parameter: CompareToConstant2_const_a
                                      //  Referenced by: '<S36>/Constant'

  real_T CompareToConstant1_const_a;
                                   // Mask Parameter: CompareToConstant1_const_a
                                      //  Referenced by: '<S35>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S48>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S7>/Constant'

  px4_Bus_actuator_outputs Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S47>/Out1'

  px4_Bus_actuator_outputs Constant_Value_c;// Computed Parameter: Constant_Value_c
                                               //  Referenced by: '<S6>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S14>/Constant1'

  real_T Constant1_Value_n;            // Expression: 0
                                          //  Referenced by: '<S15>/Constant1'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant3'

  real_T Constant1_Value_a;            // Expression: 0
                                          //  Referenced by: '<S16>/Constant1'

  real_T Saturation_UpperSat;          // Expression: 0.1
                                          //  Referenced by: '<S1>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.1
                                          //  Referenced by: '<S1>/Saturation'

  real_T Constant_Value_b;             // Expression: 0
                                          //  Referenced by: '<S1>/Constant'

  real_T Constant3_Value_f;            // Expression: 0
                                          //  Referenced by: '<S17>/Constant3'

  real_T Constant3_Value_a;            // Expression: 0
                                          //  Referenced by: '<S18>/Constant3'

  real_T Constant3_Value_d;            // Expression: 0
                                          //  Referenced by: '<S19>/Constant3'

  real_T Constant1_Value_g;            // Expression: 0
                                          //  Referenced by: '<S49>/Constant1'

  real_T Constant1_Value_h;            // Expression: 0
                                          //  Referenced by: '<S50>/Constant1'

  real_T Constant_Value_e;             // Expression: 1
                                          //  Referenced by: '<S56>/Constant'

  real_T Constant_Value_b1;            // Expression: 1
                                          //  Referenced by: '<S57>/Constant'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S10>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                          //  Referenced by: '<S10>/Discrete-Time Integrator'

  real_T Constant9_Value;              // Expression: 1
                                          //  Referenced by: '<S10>/Constant9'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant5'

  real_T Constant7_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant7'

  real_T Constant8_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant8'

  real_T DataStoreMemory5_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Data Store Memory5'

  real_T r_Value;                      // Expression: 8.00109649122807
                                          //  Referenced by: '<S40>/r'

  real_T ch_Value;                     // Expression: 2
                                          //  Referenced by: '<S40>/ch'

  real_T T_Value;                      // Expression: 5
                                          //  Referenced by: '<S40>/T'

  real_T t_Value;                      // Expression: 0
                                          //  Referenced by: '<S40>/t'

  real_T b_Value;                      // Expression: 2.036184210526316
                                          //  Referenced by: '<S16>/b'

  real_T Gain4_Gain;                   // Expression: -1
                                          //  Referenced by: '<S39>/Gain4'

  real_T TSamp_WtEt;                   // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S38>/TSamp'

  real_T l_Value;                      // Expression: 0.5282118055555556
                                          //  Referenced by: '<S16>/l'

  real_T Gain_Gain;                    // Expression: 0.01/0.0052
                                          //  Referenced by: '<S16>/Gain'

  real_T Gain1_Gain;                   // Expression: 0.00502
                                          //  Referenced by: '<S16>/Gain1'

  real_T DiscreteTimeIntegrator3_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator3_gainval
                             //  Referenced by: '<S19>/Discrete-Time Integrator3'

  real_T DiscreteTimeIntegrator3_IC;   // Expression: 0
                                          //  Referenced by: '<S19>/Discrete-Time Integrator3'

  real_T Gain1_Gain_o;                 // Expression: 0.008
                                          //  Referenced by: '<S1>/Gain1'

  real_T Saturation4_UpperSat;         // Expression: 0.2
                                          //  Referenced by: '<S1>/Saturation4'

  real_T Saturation4_LowerSat;         // Expression: -0.5
                                          //  Referenced by: '<S1>/Saturation4'

  real_T r_Value_g;                    // Expression: 6.033653846153846
                                          //  Referenced by: '<S22>/r'

  real_T ch_Value_j;                   // Expression: 2
                                          //  Referenced by: '<S22>/ch'

  real_T T_Value_p;                    // Expression: 5.018640350877193
                                          //  Referenced by: '<S22>/T'

  real_T t_Value_n;                    // Expression: 0
                                          //  Referenced by: '<S22>/t'

  real_T b_Value_l;                    // Expression: 2.470900809716599
                                          //  Referenced by: '<S14>/b'

  real_T Gain4_Gain_b;                 // Expression: -1
                                          //  Referenced by: '<S21>/Gain4'

  real_T TSamp_WtEt_p;                 // Computed Parameter: TSamp_WtEt_p
                                          //  Referenced by: '<S20>/TSamp'

  real_T l_Value_b;                    // Expression: 0.5282118055555556
                                          //  Referenced by: '<S14>/l'

  real_T Gain_Gain_o;                  // Expression: 0.01/0.0052
                                          //  Referenced by: '<S14>/Gain'

  real_T Gain1_Gain_b;                 // Expression: 0.00502
                                          //  Referenced by: '<S14>/Gain1'

  real_T DiscreteTimeIntegrator3_gainv_m;
                          // Computed Parameter: DiscreteTimeIntegrator3_gainv_m
                             //  Referenced by: '<S17>/Discrete-Time Integrator3'

  real_T DiscreteTimeIntegrator3_IC_k; // Expression: 0
                                          //  Referenced by: '<S17>/Discrete-Time Integrator3'

  real_T Gain2_Gain;                   // Expression: 0.00478
                                          //  Referenced by: '<S1>/Gain2'

  real_T r_Value_p;                    // Expression: 6.001388888888889
                                          //  Referenced by: '<S31>/r'

  real_T ch_Value_e;                   // Expression: 2
                                          //  Referenced by: '<S31>/ch'

  real_T T_Value_c;                    // Expression: 5
                                          //  Referenced by: '<S31>/T'

  real_T t_Value_m;                    // Expression: 0
                                          //  Referenced by: '<S31>/t'

  real_T b_Value_h;                    // Expression: 2.490277777777778
                                          //  Referenced by: '<S15>/b'

  real_T Gain4_Gain_o;                 // Expression: -1
                                          //  Referenced by: '<S30>/Gain4'

  real_T TSamp_WtEt_o;                 // Computed Parameter: TSamp_WtEt_o
                                          //  Referenced by: '<S29>/TSamp'

  real_T l_Value_n;                    // Expression: 0.5340277777777778
                                          //  Referenced by: '<S15>/l'

  real_T Gain_Gain_m;                  // Expression: 0.01/0.0052
                                          //  Referenced by: '<S15>/Gain'

  real_T J_Gain;                       // Expression: 0.00478
                                          //  Referenced by: '<S15>/J'

  real_T DiscreteTimeIntegrator3_gainv_e;
                          // Computed Parameter: DiscreteTimeIntegrator3_gainv_e
                             //  Referenced by: '<S18>/Discrete-Time Integrator3'

  real_T DiscreteTimeIntegrator3_IC_l; // Expression: 0
                                          //  Referenced by: '<S18>/Discrete-Time Integrator3'

  real_T J_Gain_b;                     // Expression: 0.00478
                                          //  Referenced by: '<S1>/J'

  real_T DataStoreMemory_InitialValue; // Expression: 0
                                          //  Referenced by: '<S40>/Data Store Memory'

  real_T DataStoreMemory_InitialValue_l;// Expression: 0
                                           //  Referenced by: '<S22>/Data Store Memory'

  real_T DataStoreMemory_InitialValue_b;// Expression: 0
                                           //  Referenced by: '<S31>/Data Store Memory'

  real_T DiscreteTimeIntegrator_gainva_n;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_n
                             //  Referenced by: '<S19>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_l;  // Expression: 0
                                          //  Referenced by: '<S19>/Discrete-Time Integrator'

  real_T Gain2_Gain_c;                 // Expression: 180/pi
                                          //  Referenced by: '<S19>/Gain2'

  real_T uJ_Gain;                      // Expression: 1/0.008
                                          //  Referenced by: '<S19>/1//J'

  real_T kJ_Gain;                      // Expression: 0.01/0.008
                                          //  Referenced by: '<S19>/k//J'

  real_T Saturation_UpperSat_b;        // Expression: 1
                                          //  Referenced by: '<S19>/Saturation'

  real_T Saturation_LowerSat_k;        // Expression: -1
                                          //  Referenced by: '<S19>/Saturation'

  real_T l1_Gain;                      // Expression: 0
                                          //  Referenced by: '<S19>/l1'

  real_T lambda1_Gain;                 // Expression: 0
                                          //  Referenced by: '<S19>/lambda1'

  real_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S19>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC;   // Expression: 0
                                          //  Referenced by: '<S19>/Discrete-Time Integrator1'

  real_T Constant1_Value_f;            // Expression: 0.1
                                          //  Referenced by: '<S19>/Constant1'

  real_T Saturation10_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S19>/Saturation10'

  real_T Saturation10_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S19>/Saturation10'

  real_T Saturation11_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S19>/Saturation11'

  real_T Saturation11_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S19>/Saturation11'

  real_T Gain_Gain_ml;                 // Expression: 0.5
                                          //  Referenced by: '<S19>/Gain'

  real_T Saturation8_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S19>/Saturation8'

  real_T Saturation8_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S19>/Saturation8'

  real_T Constant2_Value;              // Expression: 1
                                          //  Referenced by: '<S19>/Constant2'

  real_T Gain5_Gain;                   // Expression: 30
                                          //  Referenced by: '<S19>/Gain5'

  real_T Saturation13_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S19>/Saturation13'

  real_T Saturation13_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S19>/Saturation13'

  real_T Saturation9_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S19>/Saturation9'

  real_T Saturation9_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S19>/Saturation9'

  real_T Gain1_Gain_a;                 // Expression: 0.5
                                          //  Referenced by: '<S19>/Gain1'

  real_T Constant4_Value;              // Expression: 1
                                          //  Referenced by: '<S19>/Constant4'

  real_T Saturation12_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S19>/Saturation12'

  real_T Saturation12_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S19>/Saturation12'

  real_T Saturation16_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S19>/Saturation16'

  real_T Saturation16_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S19>/Saturation16'

  real_T Saturation14_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S19>/Saturation14'

  real_T Saturation14_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S19>/Saturation14'

  real_T Gain3_Gain;                   // Expression: 0.5
                                          //  Referenced by: '<S19>/Gain3'

  real_T Constant6_Value;              // Expression: 1
                                          //  Referenced by: '<S19>/Constant6'

  real_T lambda2_Gain;                 // Expression: 0
                                          //  Referenced by: '<S19>/lambda2'

  real_T Saturation1_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S19>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S19>/Saturation1'

  real_T l2_Gain;                      // Expression: 0
                                          //  Referenced by: '<S19>/l2'

  real_T Saturation15_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S19>/Saturation15'

  real_T Saturation15_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S19>/Saturation15'

  real_T Gain6_Gain;                   // Expression: 30
                                          //  Referenced by: '<S19>/Gain6'

  real_T Saturation19_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S19>/Saturation19'

  real_T Saturation19_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S19>/Saturation19'

  real_T Saturation17_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S19>/Saturation17'

  real_T Saturation17_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S19>/Saturation17'

  real_T Gain4_Gain_f;                 // Expression: 0.5
                                          //  Referenced by: '<S19>/Gain4'

  real_T Constant8_Value_j;            // Expression: 1
                                          //  Referenced by: '<S19>/Constant8'

  real_T Saturation18_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S19>/Saturation18'

  real_T Saturation18_LowerSat;        // Expression: -1
                                          //  Referenced by: '<S19>/Saturation18'

  real_T Saturation3_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S19>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S19>/Saturation3'

  real_T l4_Gain;                      // Expression: 0
                                          //  Referenced by: '<S19>/l4'

  real_T lambda4_Gain;                 // Expression: 0
                                          //  Referenced by: '<S19>/lambda4'

  real_T Gain7_Gain;                   // Expression: 40
                                          //  Referenced by: '<S19>/Gain7'

  real_T Gain8_Gain;                   // Expression: 1
                                          //  Referenced by: '<S19>/Gain8'

  real_T DiscreteTimeIntegrator_gainva_e;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_e
                             //  Referenced by: '<S17>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_h;  // Expression: 0
                                          //  Referenced by: '<S17>/Discrete-Time Integrator'

  real_T Gain2_Gain_g;                 // Expression: 180/pi
                                          //  Referenced by: '<S17>/Gain2'

  real_T uJ_Gain_p;                    // Expression: 1/0.00478
                                          //  Referenced by: '<S17>/1//J'

  real_T kJ_Gain_c;                    // Expression: 0.01/0.00478
                                          //  Referenced by: '<S17>/k//J'

  real_T Saturation_UpperSat_n;        // Expression: 1
                                          //  Referenced by: '<S17>/Saturation'

  real_T Saturation_LowerSat_g;        // Expression: -1
                                          //  Referenced by: '<S17>/Saturation'

  real_T l1_Gain_p;                    // Expression: 0
                                          //  Referenced by: '<S17>/l1'

  real_T lambda1_Gain_a;               // Expression: 0
                                          //  Referenced by: '<S17>/lambda1'

  real_T DiscreteTimeIntegrator1_gainv_n;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainv_n
                             //  Referenced by: '<S17>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC_j; // Expression: 0
                                          //  Referenced by: '<S17>/Discrete-Time Integrator1'

  real_T Constant1_Value_j;            // Expression: 0.1
                                          //  Referenced by: '<S17>/Constant1'

  real_T Saturation10_UpperSat_o;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation10'

  real_T Saturation10_LowerSat_b;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation10'

  real_T Saturation11_UpperSat_p;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation11'

  real_T Saturation11_LowerSat_i;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation11'

  real_T Gain_Gain_g;                  // Expression: 0.5
                                          //  Referenced by: '<S17>/Gain'

  real_T Saturation8_UpperSat_g;       // Expression: 1
                                          //  Referenced by: '<S17>/Saturation8'

  real_T Saturation8_LowerSat_g;       // Expression: -1
                                          //  Referenced by: '<S17>/Saturation8'

  real_T Constant2_Value_h;            // Expression: 1
                                          //  Referenced by: '<S17>/Constant2'

  real_T Gain5_Gain_o;                 // Expression: 30
                                          //  Referenced by: '<S17>/Gain5'

  real_T Saturation13_UpperSat_i;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation13'

  real_T Saturation13_LowerSat_c;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation13'

  real_T Saturation9_UpperSat_i;       // Expression: 1
                                          //  Referenced by: '<S17>/Saturation9'

  real_T Saturation9_LowerSat_c;       // Expression: -1
                                          //  Referenced by: '<S17>/Saturation9'

  real_T Gain1_Gain_d;                 // Expression: 0.5
                                          //  Referenced by: '<S17>/Gain1'

  real_T Constant4_Value_n;            // Expression: 1
                                          //  Referenced by: '<S17>/Constant4'

  real_T Saturation12_UpperSat_c;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation12'

  real_T Saturation12_LowerSat_b;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation12'

  real_T Saturation16_UpperSat_l;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation16'

  real_T Saturation16_LowerSat_g;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation16'

  real_T Saturation14_UpperSat_l;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation14'

  real_T Saturation14_LowerSat_b;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation14'

  real_T Gain3_Gain_l;                 // Expression: 0.5
                                          //  Referenced by: '<S17>/Gain3'

  real_T Constant6_Value_o;            // Expression: 1
                                          //  Referenced by: '<S17>/Constant6'

  real_T lambda2_Gain_j;               // Expression: 0
                                          //  Referenced by: '<S17>/lambda2'

  real_T Saturation1_UpperSat_a;       // Expression: 1
                                          //  Referenced by: '<S17>/Saturation1'

  real_T Saturation1_LowerSat_i;       // Expression: -1
                                          //  Referenced by: '<S17>/Saturation1'

  real_T l2_Gain_l;                    // Expression: 0
                                          //  Referenced by: '<S17>/l2'

  real_T Saturation15_UpperSat_j;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation15'

  real_T Saturation15_LowerSat_k;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation15'

  real_T Gain6_Gain_e;                 // Expression: 30
                                          //  Referenced by: '<S17>/Gain6'

  real_T Saturation19_UpperSat_b;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation19'

  real_T Saturation19_LowerSat_j;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation19'

  real_T Saturation17_UpperSat_d;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation17'

  real_T Saturation17_LowerSat_o;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation17'

  real_T Gain4_Gain_n;                 // Expression: 0.5
                                          //  Referenced by: '<S17>/Gain4'

  real_T Constant8_Value_f;            // Expression: 1
                                          //  Referenced by: '<S17>/Constant8'

  real_T Saturation18_UpperSat_a;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation18'

  real_T Saturation18_LowerSat_h;      // Expression: -1
                                          //  Referenced by: '<S17>/Saturation18'

  real_T Saturation3_UpperSat_m;       // Expression: 1
                                          //  Referenced by: '<S17>/Saturation3'

  real_T Saturation3_LowerSat_i;       // Expression: -1
                                          //  Referenced by: '<S17>/Saturation3'

  real_T l4_Gain_p;                    // Expression: 0
                                          //  Referenced by: '<S17>/l4'

  real_T lambda4_Gain_a;               // Expression: 0
                                          //  Referenced by: '<S17>/lambda4'

  real_T Gain7_Gain_d;                 // Expression: 40
                                          //  Referenced by: '<S17>/Gain7'

  real_T Gain8_Gain_b;                 // Expression: 1
                                          //  Referenced by: '<S17>/Gain8'

  real_T DiscreteTimeIntegrator_gainv_nv;
                          // Computed Parameter: DiscreteTimeIntegrator_gainv_nv
                             //  Referenced by: '<S18>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_o;  // Expression: 0
                                          //  Referenced by: '<S18>/Discrete-Time Integrator'

  real_T Gain2_Gain_p;                 // Expression: 180/pi
                                          //  Referenced by: '<S18>/Gain2'

  real_T uJ_Gain_g;                    // Expression: 1/0.00478
                                          //  Referenced by: '<S18>/1//J'

  real_T kJ_Gain_p;                    // Expression: 0.01/0.00478
                                          //  Referenced by: '<S18>/k//J'

  real_T Saturation_UpperSat_n1;       // Expression: 1
                                          //  Referenced by: '<S18>/Saturation'

  real_T Saturation_LowerSat_c;        // Expression: -1
                                          //  Referenced by: '<S18>/Saturation'

  real_T l1_Gain_d;                    // Expression: 0
                                          //  Referenced by: '<S18>/l1'

  real_T lambda1_Gain_g;               // Expression: 0
                                          //  Referenced by: '<S18>/lambda1'

  real_T DiscreteTimeIntegrator1_gainv_g;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainv_g
                             //  Referenced by: '<S18>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC_c; // Expression: 0
                                          //  Referenced by: '<S18>/Discrete-Time Integrator1'

  real_T Constant1_Value_ac;           // Expression: 0.1
                                          //  Referenced by: '<S18>/Constant1'

  real_T Saturation10_UpperSat_a;      // Expression: 1
                                          //  Referenced by: '<S18>/Saturation10'

  real_T Saturation10_LowerSat_l;      // Expression: -1
                                          //  Referenced by: '<S18>/Saturation10'

  real_T Saturation11_UpperSat_a;      // Expression: 1
                                          //  Referenced by: '<S18>/Saturation11'

  real_T Saturation11_LowerSat_a;      // Expression: -1
                                          //  Referenced by: '<S18>/Saturation11'

  real_T Gain_Gain_h;                  // Expression: 0.5
                                          //  Referenced by: '<S18>/Gain'

  real_T Saturation8_UpperSat_c;       // Expression: 1
                                          //  Referenced by: '<S18>/Saturation8'

  real_T Saturation8_LowerSat_c;       // Expression: -1
                                          //  Referenced by: '<S18>/Saturation8'

  real_T Constant2_Value_k;            // Expression: 1
                                          //  Referenced by: '<S18>/Constant2'

  real_T Gain5_Gain_l;                 // Expression: 30
                                          //  Referenced by: '<S18>/Gain5'

  real_T Saturation13_UpperSat_p;      // Expression: 1
                                          //  Referenced by: '<S18>/Saturation13'

  real_T Saturation13_LowerSat_j;      // Expression: -1
                                          //  Referenced by: '<S18>/Saturation13'

  real_T Saturation9_UpperSat_d;       // Expression: 1
                                          //  Referenced by: '<S18>/Saturation9'

  real_T Saturation9_LowerSat_c4;      // Expression: -1
                                          //  Referenced by: '<S18>/Saturation9'

  real_T Gain1_Gain_e;                 // Expression: 0.5
                                          //  Referenced by: '<S18>/Gain1'

  real_T Constant4_Value_l;            // Expression: 1
                                          //  Referenced by: '<S18>/Constant4'

  real_T Saturation12_UpperSat_d;      // Expression: 1
                                          //  Referenced by: '<S18>/Saturation12'

  real_T Saturation12_LowerSat_j;      // Expression: -1
                                          //  Referenced by: '<S18>/Saturation12'

  real_T Saturation16_UpperSat_p;      // Expression: 1
                                          //  Referenced by: '<S18>/Saturation16'

  real_T Saturation16_LowerSat_i;      // Expression: -1
                                          //  Referenced by: '<S18>/Saturation16'

  real_T Saturation14_UpperSat_n;      // Expression: 1
                                          //  Referenced by: '<S18>/Saturation14'

  real_T Saturation14_LowerSat_a;      // Expression: -1
                                          //  Referenced by: '<S18>/Saturation14'

  real_T Gain3_Gain_p;                 // Expression: 0.5
                                          //  Referenced by: '<S18>/Gain3'

  real_T Constant6_Value_g;            // Expression: 1
                                          //  Referenced by: '<S18>/Constant6'

  real_T lambda2_Gain_d;               // Expression: 0
                                          //  Referenced by: '<S18>/lambda2'

  real_T Saturation1_UpperSat_d;       // Expression: 1
                                          //  Referenced by: '<S18>/Saturation1'

  real_T Saturation1_LowerSat_g;       // Expression: -1
                                          //  Referenced by: '<S18>/Saturation1'

  real_T l2_Gain_i;                    // Expression: 0
                                          //  Referenced by: '<S18>/l2'

  real_T Saturation15_UpperSat_k;      // Expression: 1
                                          //  Referenced by: '<S18>/Saturation15'

  real_T Saturation15_LowerSat_h;      // Expression: -1
                                          //  Referenced by: '<S18>/Saturation15'

  real_T Gain6_Gain_f;                 // Expression: 30
                                          //  Referenced by: '<S18>/Gain6'

  real_T Saturation19_UpperSat_bc;     // Expression: 1
                                          //  Referenced by: '<S18>/Saturation19'

  real_T Saturation19_LowerSat_e;      // Expression: -1
                                          //  Referenced by: '<S18>/Saturation19'

  real_T Saturation17_UpperSat_o;      // Expression: 1
                                          //  Referenced by: '<S18>/Saturation17'

  real_T Saturation17_LowerSat_m;      // Expression: -1
                                          //  Referenced by: '<S18>/Saturation17'

  real_T Gain4_Gain_e;                 // Expression: 0.5
                                          //  Referenced by: '<S18>/Gain4'

  real_T Constant8_Value_p;            // Expression: 1
                                          //  Referenced by: '<S18>/Constant8'

  real_T Saturation18_UpperSat_c;      // Expression: 1
                                          //  Referenced by: '<S18>/Saturation18'

  real_T Saturation18_LowerSat_g;      // Expression: -1
                                          //  Referenced by: '<S18>/Saturation18'

  real_T Saturation3_UpperSat_i;       // Expression: 1
                                          //  Referenced by: '<S18>/Saturation3'

  real_T Saturation3_LowerSat_g;       // Expression: -1
                                          //  Referenced by: '<S18>/Saturation3'

  real_T l4_Gain_o;                    // Expression: 0
                                          //  Referenced by: '<S18>/l4'

  real_T lambda4_Gain_b;               // Expression: 0
                                          //  Referenced by: '<S18>/lambda4'

  real_T Gain7_Gain_l;                 // Expression: 40
                                          //  Referenced by: '<S18>/Gain7'

  real_T Gain8_Gain_o;                 // Expression: 1
                                          //  Referenced by: '<S18>/Gain8'

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

  real_T Constant4_Value_a;            // Expression: 0
                                          //  Referenced by: '<Root>/Constant4'

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

  real_T C1_Gain;                      // Expression: 40.16186580802367
                                          //  Referenced by: '<S49>/C1'

  real_T TSamp_WtEt_ow;                // Computed Parameter: TSamp_WtEt_ow
                                          //  Referenced by: '<S51>/TSamp'

  real_T C2_Gain;                      // Expression: 76.12044208511008
                                          //  Referenced by: '<S49>/C2'

  real_T DiscreteTimeIntegrator_gainva_h;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_h
                             //  Referenced by: '<S49>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_hw; // Expression: 0
                                          //  Referenced by: '<S49>/Discrete-Time Integrator'

  real_T C3_Gain;                      // Expression: 0
                                          //  Referenced by: '<S49>/C3'

  real_T Gain2_Gain_ce;                // Expression: 0.1
                                          //  Referenced by: '<S8>/Gain2'

  real_T Saturation1_UpperSat_j;       // Expression: 0.5
                                          //  Referenced by: '<S8>/Saturation1'

  real_T Saturation1_LowerSat_j;       // Expression: -0.5
                                          //  Referenced by: '<S8>/Saturation1'

  real_T Constant_Value_e4;            // Expression: 0
                                          //  Referenced by: '<S8>/Constant'

  real_T C1_Gain_k;                    // Expression: 40.16186580802367
                                          //  Referenced by: '<S50>/C1'

  real_T TSamp_WtEt_g;                 // Computed Parameter: TSamp_WtEt_g
                                          //  Referenced by: '<S52>/TSamp'

  real_T C2_Gain_k;                    // Expression: 76.12044208511008
                                          //  Referenced by: '<S50>/C2'

  real_T DiscreteTimeIntegrator_gainva_i;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_i
                             //  Referenced by: '<S50>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_e;  // Expression: 0
                                          //  Referenced by: '<S50>/Discrete-Time Integrator'

  real_T C3_Gain_o;                    // Expression: 0
                                          //  Referenced by: '<S50>/C3'

  real_T Gain4_Gain_a;                 // Expression: 0.1
                                          //  Referenced by: '<S8>/Gain4'

  real_T Saturation2_UpperSat_h;       // Expression: 0.5
                                          //  Referenced by: '<S8>/Saturation2'

  real_T Saturation2_LowerSat_o;       // Expression: -0.5
                                          //  Referenced by: '<S8>/Saturation2'

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

  boolean_T attitude_flag_Value;      // Computed Parameter: attitude_flag_Value
                                         //  Referenced by: '<S11>/attitude_flag'

  boolean_T observer_flag_Value;      // Computed Parameter: observer_flag_Value
                                         //  Referenced by: '<S12>/observer_flag'

  boolean_T position_flag_Value;      // Computed Parameter: position_flag_Value
                                         //  Referenced by: '<S13>/position_flag'

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
struct tag_RTM_px42LoopCtrQGCGPS2022_T {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_px42LoopCtrQGCGPS2022031317_T px42LoopCtrQGCGPS202203131707_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_px42LoopCtrQGCGPS2022031317_T px42LoopCtrQGCGPS202203131707_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_px42LoopCtrQGCGPS202203131_T px42LoopCtrQGCGPS20220313170_DW;

// Zero-crossing (trigger) state
extern PrevZCX_px42LoopCtrQGCGPS2022_T px42LoopCtrQGCGPS202203_PrevZCX;

// External function called from main
#ifdef __cplusplus

extern "C" {

#endif

  extern void px42LoopCtrQGCGPS202203131707_SetEventsForThisBaseStep(boolean_T
    *eventFlags);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void px42LoopCtrQGCGPS202203131707_SetEventsForThisBaseStep(boolean_T
    *eventFlags);
  extern void px42LoopCtrQGCGPS202203131707_initialize(void);
  extern void px42LoopCtrQGCGPS202203131707_step0(void);
  extern void px42LoopCtrQGCGPS202203131707_step1(void);
  extern void px42LoopCtrQGCGPS202203131707_step(int_T tid);
  extern void px42LoopCtrQGCGPS202203131707_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_px42LoopCtrQGCGPS202_T *const px42LoopCtrQGCGPS20220313170_M;

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
//  '<Root>' : 'px42LoopCtrQGCGPS202203131707'
//  '<S1>'   : 'px42LoopCtrQGCGPS202203131707/Attitude controller'
//  '<S2>'   : 'px42LoopCtrQGCGPS202203131707/MATLAB Function1'
//  '<S3>'   : 'px42LoopCtrQGCGPS202203131707/MATLAB Function2'
//  '<S4>'   : 'px42LoopCtrQGCGPS202203131707/MATLAB Function3'
//  '<S5>'   : 'px42LoopCtrQGCGPS202203131707/MATLAB Function4'
//  '<S6>'   : 'px42LoopCtrQGCGPS202203131707/PX4 uORB Read'
//  '<S7>'   : 'px42LoopCtrQGCGPS202203131707/PX4 uORB Read2'
//  '<S8>'   : 'px42LoopCtrQGCGPS202203131707/Position controller'
//  '<S9>'   : 'px42LoopCtrQGCGPS202203131707/Quaternions to Rotation Angles'
//  '<S10>'  : 'px42LoopCtrQGCGPS202203131707/Subsystem1'
//  '<S11>'  : 'px42LoopCtrQGCGPS202203131707/attitude_button'
//  '<S12>'  : 'px42LoopCtrQGCGPS202203131707/observer_button'
//  '<S13>'  : 'px42LoopCtrQGCGPS202203131707/position_button'
//  '<S14>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem'
//  '<S15>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem6'
//  '<S16>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem7'
//  '<S17>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/observer_pitch_3'
//  '<S18>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/observer_roll_3'
//  '<S19>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/observer_yaw'
//  '<S20>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem/Discrete Derivative1'
//  '<S21>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem/Subsystem1'
//  '<S22>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem/Subsystem1/Subsystem'
//  '<S23>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem/Subsystem1/Subsystem/Compare To Constant1'
//  '<S24>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem/Subsystem1/Subsystem/MATLAB Function'
//  '<S25>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem/Subsystem1/Subsystem/start_time'
//  '<S26>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem/Subsystem1/Subsystem/start_time/Compare To Constant1'
//  '<S27>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem/Subsystem1/Subsystem/start_time/Compare To Constant2'
//  '<S28>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem/Subsystem1/Subsystem/start_time/Subsystem'
//  '<S29>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem6/Discrete Derivative1'
//  '<S30>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem6/Subsystem1'
//  '<S31>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem6/Subsystem1/Subsystem'
//  '<S32>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem6/Subsystem1/Subsystem/Compare To Constant1'
//  '<S33>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem6/Subsystem1/Subsystem/MATLAB Function'
//  '<S34>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem6/Subsystem1/Subsystem/start_time'
//  '<S35>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem6/Subsystem1/Subsystem/start_time/Compare To Constant1'
//  '<S36>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem6/Subsystem1/Subsystem/start_time/Compare To Constant2'
//  '<S37>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem6/Subsystem1/Subsystem/start_time/Subsystem'
//  '<S38>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem7/Discrete Derivative1'
//  '<S39>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem7/Subsystem1'
//  '<S40>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem7/Subsystem1/Subsystem'
//  '<S41>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem7/Subsystem1/Subsystem/Compare To Constant1'
//  '<S42>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem7/Subsystem1/Subsystem/MATLAB Function'
//  '<S43>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem7/Subsystem1/Subsystem/start_time'
//  '<S44>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem7/Subsystem1/Subsystem/start_time/Compare To Constant1'
//  '<S45>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem7/Subsystem1/Subsystem/start_time/Compare To Constant2'
//  '<S46>'  : 'px42LoopCtrQGCGPS202203131707/Attitude controller/Subsystem7/Subsystem1/Subsystem/start_time/Subsystem'
//  '<S47>'  : 'px42LoopCtrQGCGPS202203131707/PX4 uORB Read/Enabled Subsystem'
//  '<S48>'  : 'px42LoopCtrQGCGPS202203131707/PX4 uORB Read2/Enabled Subsystem'
//  '<S49>'  : 'px42LoopCtrQGCGPS202203131707/Position controller/Subsystem1'
//  '<S50>'  : 'px42LoopCtrQGCGPS202203131707/Position controller/Subsystem3'
//  '<S51>'  : 'px42LoopCtrQGCGPS202203131707/Position controller/Subsystem1/Discrete Derivative'
//  '<S52>'  : 'px42LoopCtrQGCGPS202203131707/Position controller/Subsystem3/Discrete Derivative'
//  '<S53>'  : 'px42LoopCtrQGCGPS202203131707/Quaternions to Rotation Angles/Angle Calculation'
//  '<S54>'  : 'px42LoopCtrQGCGPS202203131707/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S55>'  : 'px42LoopCtrQGCGPS202203131707/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S56>'  : 'px42LoopCtrQGCGPS202203131707/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S57>'  : 'px42LoopCtrQGCGPS202203131707/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S58>'  : 'px42LoopCtrQGCGPS202203131707/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S59>'  : 'px42LoopCtrQGCGPS202203131707/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S60>'  : 'px42LoopCtrQGCGPS202203131707/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                           // RTW_HEADER_px42LoopCtrQGCGPS202203131707_h_

//
// File trailer for generated code.
//
// [EOF]
//
