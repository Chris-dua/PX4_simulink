//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4_noGPS1_data.cpp
//
// Code generated for Simulink model 'px4_noGPS1'.
//
// Model version                  : 5.150
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Mar 23 21:15:16 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "px4_noGPS1.h"

// Block parameters (default storage)
P_px4_noGPS1_T px4_noGPS1_P = {
  // Mask Parameter: DiscreteDerivative1_ICPrevScale
  //  Referenced by: '<S33>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_o
  //  Referenced by: '<S15>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_d
  //  Referenced by: '<S24>/UD'

  0.0,

  // Mask Parameter: CompareToConstant1_const
  //  Referenced by: '<S36>/Constant'

  0.087266462599716474,

  // Mask Parameter: CompareToConstant1_const_b
  //  Referenced by: '<S18>/Constant'

  0.087266462599716474,

  // Mask Parameter: CompareToConstant1_const_h
  //  Referenced by: '<S27>/Constant'

  0.087266462599716474,

  // Mask Parameter: CompareToConstant2_const
  //  Referenced by: '<S40>/Constant'

  0.087266462599716474,

  // Mask Parameter: CompareToConstant1_const_hq
  //  Referenced by: '<S39>/Constant'

  4.8,

  // Mask Parameter: CompareToConstant2_const_o
  //  Referenced by: '<S22>/Constant'

  0.087266462599716474,

  // Mask Parameter: CompareToConstant1_const_p
  //  Referenced by: '<S21>/Constant'

  4.6,

  // Mask Parameter: CompareToConstant2_const_a
  //  Referenced by: '<S31>/Constant'

  0.087266462599716474,

  // Mask Parameter: CompareToConstant1_const_a
  //  Referenced by: '<S30>/Constant'

  4.6,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S43>/Out1'

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
  //  Referenced by: '<S3>/Constant'

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
  //  Referenced by: '<S42>/Out1'

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
  //  Referenced by: '<S2>/Constant'

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
  //  Referenced by: '<S9>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S10>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S11>/Constant1'

  0.0,

  // Expression: 0.1
  //  Referenced by: '<S1>/Saturation'

  0.1,

  // Expression: -0.1
  //  Referenced by: '<S1>/Saturation'

  -0.1,

  // Expression: 0
  //  Referenced by: '<S1>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S12>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S13>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S14>/Constant3'

  0.0,

  // Expression: 1
  //  Referenced by: '<S47>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S48>/Constant'

  1.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S5>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S5>/Discrete-Time Integrator'

  0.0,

  // Expression: 1
  //  Referenced by: '<S5>/Constant9'

  1.0,

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

  // Expression: 8.00109649122807
  //  Referenced by: '<S35>/r'

  8.00109649122807,

  // Expression: 2
  //  Referenced by: '<S35>/ch'

  2.0,

  // Expression: 5
  //  Referenced by: '<S35>/T'

  5.0,

  // Expression: 0
  //  Referenced by: '<S35>/t'

  0.0,

  // Expression: 2.036184210526316
  //  Referenced by: '<S11>/b'

  2.0361842105263159,

  // Expression: -1
  //  Referenced by: '<S34>/Gain4'

  -1.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S33>/TSamp'

  200.0,

  // Expression: 0.5282118055555556
  //  Referenced by: '<S11>/l'

  0.52821180555555558,

  // Expression: 0.01/0.0052
  //  Referenced by: '<S11>/Gain'

  1.9230769230769231,

  // Expression: 0.00502
  //  Referenced by: '<S11>/Gain1'

  0.00502,

  // Computed Parameter: DiscreteTimeIntegrator3_gainval
  //  Referenced by: '<S14>/Discrete-Time Integrator3'

  0.005,

  // Expression: 0
  //  Referenced by: '<S14>/Discrete-Time Integrator3'

  0.0,

  // Expression: 0.008
  //  Referenced by: '<S1>/Gain1'

  0.008,

  // Expression: 0.2
  //  Referenced by: '<S1>/Saturation4'

  0.2,

  // Expression: -0.5
  //  Referenced by: '<S1>/Saturation4'

  -0.5,

  // Expression: 6.033653846153846
  //  Referenced by: '<S17>/r'

  6.0336538461538458,

  // Expression: 2
  //  Referenced by: '<S17>/ch'

  2.0,

  // Expression: 5.018640350877193
  //  Referenced by: '<S17>/T'

  5.0186403508771926,

  // Expression: 0
  //  Referenced by: '<S17>/t'

  0.0,

  // Expression: 2.470900809716599
  //  Referenced by: '<S9>/b'

  2.470900809716599,

  // Expression: -1
  //  Referenced by: '<S16>/Gain4'

  -1.0,

  // Computed Parameter: TSamp_WtEt_p
  //  Referenced by: '<S15>/TSamp'

  200.0,

  // Expression: 0.5282118055555556
  //  Referenced by: '<S9>/l'

  0.52821180555555558,

  // Expression: 0.01/0.0052
  //  Referenced by: '<S9>/Gain'

  1.9230769230769231,

  // Expression: 0.00502
  //  Referenced by: '<S9>/Gain1'

  0.00502,

  // Computed Parameter: DiscreteTimeIntegrator3_gainv_m
  //  Referenced by: '<S12>/Discrete-Time Integrator3'

  0.005,

  // Expression: 0
  //  Referenced by: '<S12>/Discrete-Time Integrator3'

  0.0,

  // Expression: 0.00478
  //  Referenced by: '<S1>/Gain2'

  0.00478,

  // Expression: 6.001388888888889
  //  Referenced by: '<S26>/r'

  6.0013888888888891,

  // Expression: 2
  //  Referenced by: '<S26>/ch'

  2.0,

  // Expression: 5
  //  Referenced by: '<S26>/T'

  5.0,

  // Expression: 0
  //  Referenced by: '<S26>/t'

  0.0,

  // Expression: 2.490277777777778
  //  Referenced by: '<S10>/b'

  2.490277777777778,

  // Expression: -1
  //  Referenced by: '<S25>/Gain4'

  -1.0,

  // Computed Parameter: TSamp_WtEt_o
  //  Referenced by: '<S24>/TSamp'

  200.0,

  // Expression: 0.5340277777777778
  //  Referenced by: '<S10>/l'

  0.53402777777777777,

  // Expression: 0.01/0.0052
  //  Referenced by: '<S10>/Gain'

  1.9230769230769231,

  // Expression: 0.00478
  //  Referenced by: '<S10>/J'

  0.00478,

  // Computed Parameter: DiscreteTimeIntegrator3_gainv_e
  //  Referenced by: '<S13>/Discrete-Time Integrator3'

  0.005,

  // Expression: 0
  //  Referenced by: '<S13>/Discrete-Time Integrator3'

  0.0,

  // Expression: 0.00478
  //  Referenced by: '<S1>/J'

  0.00478,

  // Expression: 0
  //  Referenced by: '<S35>/Data Store Memory'

  0.0,

  // Expression: 0
  //  Referenced by: '<S17>/Data Store Memory'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Data Store Memory'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_n
  //  Referenced by: '<S14>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S14>/Discrete-Time Integrator'

  0.0,

  // Expression: 180/pi
  //  Referenced by: '<S14>/Gain2'

  57.295779513082323,

  // Expression: 1/0.008
  //  Referenced by: '<S14>/1//J'

  125.0,

  // Expression: 0.01/0.008
  //  Referenced by: '<S14>/k//J'

  1.25,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Saturation'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S14>/l1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S14>/lambda1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator1_gainval
  //  Referenced by: '<S14>/Discrete-Time Integrator1'

  0.005,

  // Expression: 0
  //  Referenced by: '<S14>/Discrete-Time Integrator1'

  0.0,

  // Expression: 0.1
  //  Referenced by: '<S14>/Constant1'

  0.1,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation10'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Saturation10'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation11'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Saturation11'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S14>/Gain'

  0.5,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation8'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Saturation8'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S14>/Constant2'

  1.0,

  // Expression: 30
  //  Referenced by: '<S14>/Gain5'

  30.0,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation13'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Saturation13'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation9'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Saturation9'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S14>/Gain1'

  0.5,

  // Expression: 1
  //  Referenced by: '<S14>/Constant4'

  1.0,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation12'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Saturation12'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation16'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Saturation16'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation14'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Saturation14'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S14>/Gain3'

  0.5,

  // Expression: 1
  //  Referenced by: '<S14>/Constant6'

  1.0,

  // Expression: 0
  //  Referenced by: '<S14>/lambda2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Saturation1'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S14>/l2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation15'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Saturation15'

  -1.0,

  // Expression: 30
  //  Referenced by: '<S14>/Gain6'

  30.0,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation19'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Saturation19'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation17'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Saturation17'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S14>/Gain4'

  0.5,

  // Expression: 1
  //  Referenced by: '<S14>/Constant8'

  1.0,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation18'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Saturation18'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation3'

  1.0,

  // Expression: -1
  //  Referenced by: '<S14>/Saturation3'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S14>/l4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S14>/lambda4'

  0.0,

  // Expression: 40
  //  Referenced by: '<S14>/Gain7'

  40.0,

  // Expression: 1
  //  Referenced by: '<S14>/Gain8'

  1.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_e
  //  Referenced by: '<S12>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S12>/Discrete-Time Integrator'

  0.0,

  // Expression: 180/pi
  //  Referenced by: '<S12>/Gain2'

  57.295779513082323,

  // Expression: 1/0.00478
  //  Referenced by: '<S12>/1//J'

  209.20502092050208,

  // Expression: 0.01/0.00478
  //  Referenced by: '<S12>/k//J'

  2.0920502092050208,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Saturation'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S12>/l1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S12>/lambda1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator1_gainv_n
  //  Referenced by: '<S12>/Discrete-Time Integrator1'

  0.005,

  // Expression: 0
  //  Referenced by: '<S12>/Discrete-Time Integrator1'

  0.0,

  // Expression: 0.1
  //  Referenced by: '<S12>/Constant1'

  0.1,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation10'

  1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Saturation10'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation11'

  1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Saturation11'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S12>/Gain'

  0.5,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation8'

  1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Saturation8'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S12>/Constant2'

  1.0,

  // Expression: 30
  //  Referenced by: '<S12>/Gain5'

  30.0,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation13'

  1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Saturation13'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation9'

  1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Saturation9'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S12>/Gain1'

  0.5,

  // Expression: 1
  //  Referenced by: '<S12>/Constant4'

  1.0,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation12'

  1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Saturation12'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation16'

  1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Saturation16'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation14'

  1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Saturation14'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S12>/Gain3'

  0.5,

  // Expression: 1
  //  Referenced by: '<S12>/Constant6'

  1.0,

  // Expression: 0
  //  Referenced by: '<S12>/lambda2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Saturation1'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S12>/l2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation15'

  1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Saturation15'

  -1.0,

  // Expression: 30
  //  Referenced by: '<S12>/Gain6'

  30.0,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation19'

  1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Saturation19'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation17'

  1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Saturation17'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S12>/Gain4'

  0.5,

  // Expression: 1
  //  Referenced by: '<S12>/Constant8'

  1.0,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation18'

  1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Saturation18'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation3'

  1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Saturation3'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S12>/l4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S12>/lambda4'

  0.0,

  // Expression: 40
  //  Referenced by: '<S12>/Gain7'

  40.0,

  // Expression: 1
  //  Referenced by: '<S12>/Gain8'

  1.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainv_nv
  //  Referenced by: '<S13>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S13>/Discrete-Time Integrator'

  0.0,

  // Expression: 180/pi
  //  Referenced by: '<S13>/Gain2'

  57.295779513082323,

  // Expression: 1/0.00478
  //  Referenced by: '<S13>/1//J'

  209.20502092050208,

  // Expression: 0.01/0.00478
  //  Referenced by: '<S13>/k//J'

  2.0920502092050208,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Saturation'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S13>/l1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S13>/lambda1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator1_gainv_g
  //  Referenced by: '<S13>/Discrete-Time Integrator1'

  0.005,

  // Expression: 0
  //  Referenced by: '<S13>/Discrete-Time Integrator1'

  0.0,

  // Expression: 0.1
  //  Referenced by: '<S13>/Constant1'

  0.1,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation10'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Saturation10'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation11'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Saturation11'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S13>/Gain'

  0.5,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation8'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Saturation8'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S13>/Constant2'

  1.0,

  // Expression: 30
  //  Referenced by: '<S13>/Gain5'

  30.0,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation13'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Saturation13'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation9'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Saturation9'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S13>/Gain1'

  0.5,

  // Expression: 1
  //  Referenced by: '<S13>/Constant4'

  1.0,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation12'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Saturation12'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation16'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Saturation16'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation14'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Saturation14'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S13>/Gain3'

  0.5,

  // Expression: 1
  //  Referenced by: '<S13>/Constant6'

  1.0,

  // Expression: 0
  //  Referenced by: '<S13>/lambda2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Saturation1'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S13>/l2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation15'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Saturation15'

  -1.0,

  // Expression: 30
  //  Referenced by: '<S13>/Gain6'

  30.0,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation19'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Saturation19'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation17'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Saturation17'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S13>/Gain4'

  0.5,

  // Expression: 1
  //  Referenced by: '<S13>/Constant8'

  1.0,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation18'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Saturation18'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation3'

  1.0,

  // Expression: -1
  //  Referenced by: '<S13>/Saturation3'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S13>/l4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S13>/lambda4'

  0.0,

  // Expression: 40
  //  Referenced by: '<S13>/Gain7'

  40.0,

  // Expression: 1
  //  Referenced by: '<S13>/Gain8'

  1.0,

  // Expression: 0.2
  //  Referenced by: '<S1>/Saturation2'

  0.2,

  // Expression: -0.5
  //  Referenced by: '<S1>/Saturation2'

  -0.5,

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

  true,

  // Computed Parameter: attitude_flag_Value
  //  Referenced by: '<S6>/attitude_flag'

  false,

  // Computed Parameter: observer_flag_Value
  //  Referenced by: '<S7>/observer_flag'

  false,

  // Computed Parameter: position_flag_Value
  //  Referenced by: '<S8>/position_flag'

  false,

  // Computed Parameter: Constant2_Value_kf
  //  Referenced by: '<Root>/Constant2'

  false,

  // Computed Parameter: DataStoreMemory_InitialValue_j
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
