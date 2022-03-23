//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4_noGPS4_data.cpp
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
#include "px4_noGPS4.h"

// Block parameters (default storage)
P_px4_noGPS4_T px4_noGPS4_P = {
  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S20>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevScale
  //  Referenced by: '<S21>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_k
  //  Referenced by: '<S16>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_a
  //  Referenced by: '<S17>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_a
  //  Referenced by: '<S18>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_o
  //  Referenced by: '<S19>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_f
  //  Referenced by: '<S26>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevScale
  //  Referenced by: '<S27>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_e
  //  Referenced by: '<S28>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_k
  //  Referenced by: '<S29>/UD'

  0.0,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S23>/Out1'

  {
    (0ULL),                            // timestamp
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q_offset

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // pose_covariance
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // velocity_covariance
    0U,                                // local_frame

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S6>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q_offset

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // pose_covariance
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // velocity_covariance
    0U,                                // local_frame

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S22>/Out1'

  {
    (0ULL),                            // timestamp
    0U,                                // noutputs

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // output

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S5>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // noutputs

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // output

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Expression: 0
  //  Referenced by: '<S13>/Constant2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S13>/Constant3'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Constant4'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S14>/Constant2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S14>/Constant3'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Constant4'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S15>/Constant2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S15>/Constant3'

  1.0,

  // Expression: 0
  //  Referenced by: '<S15>/Switch2'

  0.0,

  // Expression: -0.1
  //  Referenced by: '<S15>/Gain8'

  -0.1,

  // Expression: 1.25
  //  Referenced by: '<S15>/Constant'

  1.25,

  // Expression: 0.2
  //  Referenced by: '<S15>/Gain5'

  0.2,

  // Expression: 0.012
  //  Referenced by: '<S15>/Gain6'

  0.012,

  // Expression: -50
  //  Referenced by: '<S15>/Gain4'

  -50.0,

  // Expression: 50
  //  Referenced by: '<S15>/Gain3'

  50.0,

  // Expression: -4.854809437386564
  //  Referenced by: '<S15>/Gain2'

  -4.8548094373865638,

  // Expression: 0.1
  //  Referenced by: '<S1>/Saturation'

  0.1,

  // Expression: -0.1
  //  Referenced by: '<S1>/Saturation'

  -0.1,

  // Expression: 0
  //  Referenced by: '<S1>/Constant'

  0.0,

  // Expression: 1
  //  Referenced by: '<S24>/Constant'

  1.0,

  // Expression: -1
  //  Referenced by: '<S24>/Constant2'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S24>/Constant1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S25>/Constant'

  1.0,

  // Expression: -1
  //  Referenced by: '<S25>/Constant2'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S25>/Constant1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S33>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S34>/Constant'

  1.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S9>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S9>/Discrete-Time Integrator'

  0.0,

  // Expression: 1
  //  Referenced by: '<S9>/Constant9'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant7'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant8'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/e_pitch'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/e_pitch1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/e_pitch2'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory33'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory34'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory35'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory5'

  0.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S20>/TSamp'

  200.0,

  // Computed Parameter: TSamp_WtEt_l
  //  Referenced by: '<S21>/TSamp'

  200.0,

  // Expression: 50
  //  Referenced by: '<S13>/Gain3'

  50.0,

  // Computed Parameter: TSamp_WtEt_m
  //  Referenced by: '<S16>/TSamp'

  200.0,

  // Expression: -40
  //  Referenced by: '<S13>/Gain2'

  -40.0,

  // Expression: -50
  //  Referenced by: '<S13>/Gain4'

  -50.0,

  // Expression: 0.2
  //  Referenced by: '<S13>/Gain5'

  0.2,

  // Expression: 0.012
  //  Referenced by: '<S13>/Gain6'

  0.012,

  // Expression: 1.25
  //  Referenced by: '<S13>/Constant'

  1.25,

  // Computed Parameter: TSamp_WtEt_j
  //  Referenced by: '<S17>/TSamp'

  200.0,

  // Expression: 0
  //  Referenced by: '<S13>/Switch2'

  0.0,

  // Expression: -0.1
  //  Referenced by: '<S13>/Gain8'

  -0.1,

  // Expression: 50
  //  Referenced by: '<S14>/Gain3'

  50.0,

  // Computed Parameter: TSamp_WtEt_h
  //  Referenced by: '<S18>/TSamp'

  200.0,

  // Expression: -4.854809437386564
  //  Referenced by: '<S14>/Gain2'

  -4.8548094373865638,

  // Expression: -50
  //  Referenced by: '<S14>/Gain4'

  -50.0,

  // Expression: 0.2
  //  Referenced by: '<S14>/Gain5'

  0.2,

  // Expression: 0.012
  //  Referenced by: '<S14>/Gain6'

  0.012,

  // Expression: 1.25
  //  Referenced by: '<S14>/Constant'

  1.25,

  // Computed Parameter: TSamp_WtEt_g
  //  Referenced by: '<S19>/TSamp'

  200.0,

  // Expression: 0
  //  Referenced by: '<S14>/Switch2'

  0.0,

  // Expression: -0.1
  //  Referenced by: '<S14>/Gain8'

  -0.1,

  // Expression: -4.896830143540669
  //  Referenced by: '<S15>/Gain7'

  -4.8968301435406687,

  // Expression: 0
  //  Referenced by: '<S15>/Data Store Memory'

  0.0,

  // Expression: -49.03250773993808
  //  Referenced by: '<S13>/Gain7'

  -49.032507739938083,

  // Expression: 0
  //  Referenced by: '<S13>/Data Store Memory'

  0.0,

  // Expression: -5
  //  Referenced by: '<S14>/Gain7'

  -5.0,

  // Expression: 0
  //  Referenced by: '<S14>/Data Store Memory'

  0.0,

  // Computed Parameter: Intgrt_dX_gainval
  //  Referenced by: '<Root>/Intgrt_dX'

  0.005,

  // Expression: 0
  //  Referenced by: '<Root>/Intgrt_dX'

  0.0,

  // Computed Parameter: Intgrt_dY_gainval
  //  Referenced by: '<Root>/Intgrt_dY'

  0.005,

  // Expression: 0
  //  Referenced by: '<Root>/Intgrt_dY'

  0.0,

  // Computed Parameter: Intgrt_ddY_gainval
  //  Referenced by: '<Root>/Intgrt_ddY'

  0.005,

  // Expression: 0
  //  Referenced by: '<Root>/Intgrt_ddY'

  0.0,

  // Computed Parameter: Intgrt_ddX_gainval
  //  Referenced by: '<Root>/Intgrt_ddX'

  0.005,

  // Expression: 0
  //  Referenced by: '<Root>/Intgrt_ddX'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant6'

  0.0,

  // Expression: 5
  //  Referenced by: '<S24>/K1'

  5.0,

  // Computed Parameter: TSamp_WtEt_c
  //  Referenced by: '<S26>/TSamp'

  200.0,

  // Expression: -5.99814967105263
  //  Referenced by: '<S24>/C1'

  -5.99814967105263,

  // Expression: -5
  //  Referenced by: '<S24>/C3'

  -5.0,

  // Expression: -6.98499177631578
  //  Referenced by: '<S24>/C4'

  -6.98499177631578,

  // Expression: 0
  //  Referenced by: '<S24>/Switch1'

  0.0,

  // Expression: -0.1
  //  Referenced by: '<S24>/Gain'

  -0.1,

  // Expression: 0.01
  //  Referenced by: '<S24>/k3'

  0.01,

  // Expression: 2
  //  Referenced by: '<S24>/Constant3'

  2.0,

  // Computed Parameter: TSamp_WtEt_l2
  //  Referenced by: '<S27>/TSamp'

  200.0,

  // Expression: 0.01
  //  Referenced by: '<S7>/Gain2'

  0.01,

  // Expression: 0.5
  //  Referenced by: '<S7>/Saturation1'

  0.5,

  // Expression: -0.5
  //  Referenced by: '<S7>/Saturation1'

  -0.5,

  // Expression: 0
  //  Referenced by: '<S7>/Constant'

  0.0,

  // Expression: 5
  //  Referenced by: '<S25>/k2'

  5.0,

  // Computed Parameter: TSamp_WtEt_p
  //  Referenced by: '<S28>/TSamp'

  200.0,

  // Expression: -5.107574679943099
  //  Referenced by: '<S25>/C1'

  -5.1075746799430988,

  // Expression: -5
  //  Referenced by: '<S25>/k1'

  -5.0,

  // Expression: -6.814544807965859
  //  Referenced by: '<S25>/C2'

  -6.8145448079658593,

  // Expression: 0
  //  Referenced by: '<S25>/Switch1'

  0.0,

  // Expression: -0.1
  //  Referenced by: '<S25>/Gain'

  -0.1,

  // Expression: 0.01
  //  Referenced by: '<S25>/k3'

  0.01,

  // Expression: 2
  //  Referenced by: '<S25>/Constant3'

  2.0,

  // Computed Parameter: TSamp_WtEt_i
  //  Referenced by: '<S29>/TSamp'

  200.0,

  // Expression: 0.01
  //  Referenced by: '<S7>/Gain4'

  0.01,

  // Expression: 0.5
  //  Referenced by: '<S7>/Saturation2'

  0.5,

  // Expression: -0.5
  //  Referenced by: '<S7>/Saturation2'

  -0.5,

  // Expression: 1.5
  //  Referenced by: '<Root>/Saturation2'

  1.5,

  // Expression: 1
  //  Referenced by: '<Root>/Saturation2'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/fault_1'

  0.0,

  // Expression: [1 1 -1 1;1 -1 1 1;1 1 1 -1;1 -1 -1 -1]
  //  Referenced by: '<Root>/Mixer matrix1'

  { 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, -1.0, -1.0, 1.0, 1.0, -1.0, 1.0, 1.0,
    -1.0, -1.0 },

  // Expression: 1000
  //  Referenced by: '<Root>/Gain4'

  1000.0,

  // Expression: 0.3835227272727273
  //  Referenced by: '<Root>/fault_2'

  0.38352272727272729,

  // Expression: 0
  //  Referenced by: '<Root>/fault_3'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/fault_4'

  0.0,

  // Computed Parameter: Intgrt_dZ_gainval
  //  Referenced by: '<Root>/Intgrt_dZ'

  0.005,

  // Expression: 0
  //  Referenced by: '<Root>/Intgrt_dZ'

  0.0,

  // Computed Parameter: Intgrt_ddZ_gainval
  //  Referenced by: '<Root>/Intgrt_ddZ'

  0.005,

  // Expression: 0
  //  Referenced by: '<Root>/Intgrt_ddZ'

  0.0,

  // Expression: inf
  //  Referenced by: '<Root>/Saturation1'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Saturation1'

  0.0,

  // Expression: 1
  //  Referenced by: '<Root>/slower3'

  1.0,

  // Expression: 1
  //  Referenced by: '<Root>/slower4'

  1.0,

  // Expression: 1
  //  Referenced by: '<Root>/slower5'

  1.0,

  // Expression: 180/3.1415926
  //  Referenced by: '<Root>/Gain5'

  57.295780490442965,

  // Expression: 180/3.1415926
  //  Referenced by: '<Root>/Gain3'

  57.295780490442965,

  // Expression: 180/3.1415926
  //  Referenced by: '<Root>/Gain6'

  57.295780490442965,

  // Expression: 180/3.1415926
  //  Referenced by: '<Root>/Gain8'

  57.295780490442965,

  // Expression: 180/3.1415926
  //  Referenced by: '<Root>/Gain10'

  57.295780490442965,

  // Expression: 180/3.1415926
  //  Referenced by: '<Root>/Gain7'

  57.295780490442965,

  // Expression: 180/3.1415926
  //  Referenced by: '<Root>/Gain11'

  57.295780490442965,

  // Expression: 180/3.1415926
  //  Referenced by: '<Root>/Gain9'

  57.295780490442965,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory10'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory11'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory12'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory13'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory14'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory15'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory16'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory17'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory18'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory19'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory2'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory20'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory21'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory22'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory23'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory24'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory25'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory26'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory28'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory29'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory3'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory31'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory32'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory36'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory4'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory6'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory7'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory8'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory9'

  0.0,

  // Computed Parameter: Reset_Value
  //  Referenced by: '<Root>/Reset'

  false,

  // Computed Parameter: attitude_flag_Value
  //  Referenced by: '<S10>/attitude_flag'

  false,

  // Computed Parameter: observer_flag_Value
  //  Referenced by: '<S11>/observer_flag'

  false,

  // Computed Parameter: position_flag_Value
  //  Referenced by: '<S12>/position_flag'

  false,

  // Computed Parameter: Constant2_Value_k
  //  Referenced by: '<Root>/Constant2'

  false,

  // Computed Parameter: DataStoreMemory_InitialValue_b
  //  Referenced by: '<Root>/Data Store Memory'

  false,

  // Computed Parameter: DataStoreMemory1_InitialValue
  //  Referenced by: '<Root>/Data Store Memory1'

  false,

  // Computed Parameter: DataStoreMemory27_InitialValue
  //  Referenced by: '<Root>/Data Store Memory27'

  false,

  // Computed Parameter: DataStoreMemory30_InitialValue
  //  Referenced by: '<Root>/Data Store Memory30'

  false,

  // Computed Parameter: ManualSwitch_CurrentSetting
  //  Referenced by: '<S1>/Manual Switch'

  1U
};

//
// File trailer for generated code.
//
// [EOF]
//
