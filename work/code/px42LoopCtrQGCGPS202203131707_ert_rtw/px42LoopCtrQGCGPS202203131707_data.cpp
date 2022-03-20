//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px42LoopCtrQGCGPS202203131707_data.cpp
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

// Block parameters (default storage)
P_px42LoopCtrQGCGPS2022031317_T px42LoopCtrQGCGPS202203131707_P = {
  // Mask Parameter: DiscreteDerivative1_ICPrevScale
  //  Referenced by: '<S38>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_o
  //  Referenced by: '<S20>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_d
  //  Referenced by: '<S29>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S51>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_a
  //  Referenced by: '<S52>/UD'

  0.0,

  // Mask Parameter: CompareToConstant1_const
  //  Referenced by: '<S41>/Constant'

  0.087266462599716474,

  // Mask Parameter: CompareToConstant1_const_b
  //  Referenced by: '<S23>/Constant'

  0.087266462599716474,

  // Mask Parameter: CompareToConstant1_const_h
  //  Referenced by: '<S32>/Constant'

  0.087266462599716474,

  // Mask Parameter: CompareToConstant2_const
  //  Referenced by: '<S45>/Constant'

  0.087266462599716474,

  // Mask Parameter: CompareToConstant1_const_hq
  //  Referenced by: '<S44>/Constant'

  4.8,

  // Mask Parameter: CompareToConstant2_const_o
  //  Referenced by: '<S27>/Constant'

  0.087266462599716474,

  // Mask Parameter: CompareToConstant1_const_p
  //  Referenced by: '<S26>/Constant'

  4.6,

  // Mask Parameter: CompareToConstant2_const_a
  //  Referenced by: '<S36>/Constant'

  0.087266462599716474,

  // Mask Parameter: CompareToConstant1_const_a
  //  Referenced by: '<S35>/Constant'

  4.6,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S48>/Out1'

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
  //  Referenced by: '<S7>/Constant'

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
  //  Referenced by: '<S47>/Out1'

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
  //  Referenced by: '<S6>/Constant'

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
  //  Referenced by: '<S14>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S15>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S16>/Constant1'

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
  //  Referenced by: '<S17>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S18>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S19>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S49>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S50>/Constant1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S56>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S57>/Constant'

  1.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S10>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S10>/Discrete-Time Integrator'

  0.0,

  // Expression: 1
  //  Referenced by: '<S10>/Constant9'

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
  //  Referenced by: '<Root>/Data Store Memory5'

  0.0,

  // Expression: 8.00109649122807
  //  Referenced by: '<S40>/r'

  8.00109649122807,

  // Expression: 2
  //  Referenced by: '<S40>/ch'

  2.0,

  // Expression: 5
  //  Referenced by: '<S40>/T'

  5.0,

  // Expression: 0
  //  Referenced by: '<S40>/t'

  0.0,

  // Expression: 2.036184210526316
  //  Referenced by: '<S16>/b'

  2.0361842105263159,

  // Expression: -1
  //  Referenced by: '<S39>/Gain4'

  -1.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S38>/TSamp'

  200.0,

  // Expression: 0.5282118055555556
  //  Referenced by: '<S16>/l'

  0.52821180555555558,

  // Expression: 0.01/0.0052
  //  Referenced by: '<S16>/Gain'

  1.9230769230769231,

  // Expression: 0.00502
  //  Referenced by: '<S16>/Gain1'

  0.00502,

  // Computed Parameter: DiscreteTimeIntegrator3_gainval
  //  Referenced by: '<S19>/Discrete-Time Integrator3'

  0.005,

  // Expression: 0
  //  Referenced by: '<S19>/Discrete-Time Integrator3'

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
  //  Referenced by: '<S22>/r'

  6.0336538461538458,

  // Expression: 2
  //  Referenced by: '<S22>/ch'

  2.0,

  // Expression: 5.018640350877193
  //  Referenced by: '<S22>/T'

  5.0186403508771926,

  // Expression: 0
  //  Referenced by: '<S22>/t'

  0.0,

  // Expression: 2.470900809716599
  //  Referenced by: '<S14>/b'

  2.470900809716599,

  // Expression: -1
  //  Referenced by: '<S21>/Gain4'

  -1.0,

  // Computed Parameter: TSamp_WtEt_p
  //  Referenced by: '<S20>/TSamp'

  200.0,

  // Expression: 0.5282118055555556
  //  Referenced by: '<S14>/l'

  0.52821180555555558,

  // Expression: 0.01/0.0052
  //  Referenced by: '<S14>/Gain'

  1.9230769230769231,

  // Expression: 0.00502
  //  Referenced by: '<S14>/Gain1'

  0.00502,

  // Computed Parameter: DiscreteTimeIntegrator3_gainv_m
  //  Referenced by: '<S17>/Discrete-Time Integrator3'

  0.005,

  // Expression: 0
  //  Referenced by: '<S17>/Discrete-Time Integrator3'

  0.0,

  // Expression: 0.00478
  //  Referenced by: '<S1>/Gain2'

  0.00478,

  // Expression: 6.001388888888889
  //  Referenced by: '<S31>/r'

  6.0013888888888891,

  // Expression: 2
  //  Referenced by: '<S31>/ch'

  2.0,

  // Expression: 5
  //  Referenced by: '<S31>/T'

  5.0,

  // Expression: 0
  //  Referenced by: '<S31>/t'

  0.0,

  // Expression: 2.490277777777778
  //  Referenced by: '<S15>/b'

  2.490277777777778,

  // Expression: -1
  //  Referenced by: '<S30>/Gain4'

  -1.0,

  // Computed Parameter: TSamp_WtEt_o
  //  Referenced by: '<S29>/TSamp'

  200.0,

  // Expression: 0.5340277777777778
  //  Referenced by: '<S15>/l'

  0.53402777777777777,

  // Expression: 0.01/0.0052
  //  Referenced by: '<S15>/Gain'

  1.9230769230769231,

  // Expression: 0.00478
  //  Referenced by: '<S15>/J'

  0.00478,

  // Computed Parameter: DiscreteTimeIntegrator3_gainv_e
  //  Referenced by: '<S18>/Discrete-Time Integrator3'

  0.005,

  // Expression: 0
  //  Referenced by: '<S18>/Discrete-Time Integrator3'

  0.0,

  // Expression: 0.00478
  //  Referenced by: '<S1>/J'

  0.00478,

  // Expression: 0
  //  Referenced by: '<S40>/Data Store Memory'

  0.0,

  // Expression: 0
  //  Referenced by: '<S22>/Data Store Memory'

  0.0,

  // Expression: 0
  //  Referenced by: '<S31>/Data Store Memory'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_n
  //  Referenced by: '<S19>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S19>/Discrete-Time Integrator'

  0.0,

  // Expression: 180/pi
  //  Referenced by: '<S19>/Gain2'

  57.295779513082323,

  // Expression: 1/0.008
  //  Referenced by: '<S19>/1//J'

  125.0,

  // Expression: 0.01/0.008
  //  Referenced by: '<S19>/k//J'

  1.25,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Saturation'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S19>/l1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S19>/lambda1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator1_gainval
  //  Referenced by: '<S19>/Discrete-Time Integrator1'

  0.005,

  // Expression: 0
  //  Referenced by: '<S19>/Discrete-Time Integrator1'

  0.0,

  // Expression: 0.1
  //  Referenced by: '<S19>/Constant1'

  0.1,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation10'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Saturation10'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation11'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Saturation11'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S19>/Gain'

  0.5,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation8'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Saturation8'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S19>/Constant2'

  1.0,

  // Expression: 30
  //  Referenced by: '<S19>/Gain5'

  30.0,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation13'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Saturation13'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation9'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Saturation9'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S19>/Gain1'

  0.5,

  // Expression: 1
  //  Referenced by: '<S19>/Constant4'

  1.0,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation12'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Saturation12'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation16'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Saturation16'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation14'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Saturation14'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S19>/Gain3'

  0.5,

  // Expression: 1
  //  Referenced by: '<S19>/Constant6'

  1.0,

  // Expression: 0
  //  Referenced by: '<S19>/lambda2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Saturation1'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S19>/l2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation15'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Saturation15'

  -1.0,

  // Expression: 30
  //  Referenced by: '<S19>/Gain6'

  30.0,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation19'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Saturation19'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation17'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Saturation17'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S19>/Gain4'

  0.5,

  // Expression: 1
  //  Referenced by: '<S19>/Constant8'

  1.0,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation18'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Saturation18'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation3'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Saturation3'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S19>/l4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S19>/lambda4'

  0.0,

  // Expression: 40
  //  Referenced by: '<S19>/Gain7'

  40.0,

  // Expression: 1
  //  Referenced by: '<S19>/Gain8'

  1.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_e
  //  Referenced by: '<S17>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S17>/Discrete-Time Integrator'

  0.0,

  // Expression: 180/pi
  //  Referenced by: '<S17>/Gain2'

  57.295779513082323,

  // Expression: 1/0.00478
  //  Referenced by: '<S17>/1//J'

  209.20502092050208,

  // Expression: 0.01/0.00478
  //  Referenced by: '<S17>/k//J'

  2.0920502092050208,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S17>/Saturation'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S17>/l1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S17>/lambda1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator1_gainv_n
  //  Referenced by: '<S17>/Discrete-Time Integrator1'

  0.005,

  // Expression: 0
  //  Referenced by: '<S17>/Discrete-Time Integrator1'

  0.0,

  // Expression: 0.1
  //  Referenced by: '<S17>/Constant1'

  0.1,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation10'

  1.0,

  // Expression: -1
  //  Referenced by: '<S17>/Saturation10'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation11'

  1.0,

  // Expression: -1
  //  Referenced by: '<S17>/Saturation11'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S17>/Gain'

  0.5,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation8'

  1.0,

  // Expression: -1
  //  Referenced by: '<S17>/Saturation8'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S17>/Constant2'

  1.0,

  // Expression: 30
  //  Referenced by: '<S17>/Gain5'

  30.0,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation13'

  1.0,

  // Expression: -1
  //  Referenced by: '<S17>/Saturation13'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation9'

  1.0,

  // Expression: -1
  //  Referenced by: '<S17>/Saturation9'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S17>/Gain1'

  0.5,

  // Expression: 1
  //  Referenced by: '<S17>/Constant4'

  1.0,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation12'

  1.0,

  // Expression: -1
  //  Referenced by: '<S17>/Saturation12'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation16'

  1.0,

  // Expression: -1
  //  Referenced by: '<S17>/Saturation16'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation14'

  1.0,

  // Expression: -1
  //  Referenced by: '<S17>/Saturation14'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S17>/Gain3'

  0.5,

  // Expression: 1
  //  Referenced by: '<S17>/Constant6'

  1.0,

  // Expression: 0
  //  Referenced by: '<S17>/lambda2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S17>/Saturation1'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S17>/l2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation15'

  1.0,

  // Expression: -1
  //  Referenced by: '<S17>/Saturation15'

  -1.0,

  // Expression: 30
  //  Referenced by: '<S17>/Gain6'

  30.0,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation19'

  1.0,

  // Expression: -1
  //  Referenced by: '<S17>/Saturation19'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation17'

  1.0,

  // Expression: -1
  //  Referenced by: '<S17>/Saturation17'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S17>/Gain4'

  0.5,

  // Expression: 1
  //  Referenced by: '<S17>/Constant8'

  1.0,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation18'

  1.0,

  // Expression: -1
  //  Referenced by: '<S17>/Saturation18'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation3'

  1.0,

  // Expression: -1
  //  Referenced by: '<S17>/Saturation3'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S17>/l4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S17>/lambda4'

  0.0,

  // Expression: 40
  //  Referenced by: '<S17>/Gain7'

  40.0,

  // Expression: 1
  //  Referenced by: '<S17>/Gain8'

  1.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainv_nv
  //  Referenced by: '<S18>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S18>/Discrete-Time Integrator'

  0.0,

  // Expression: 180/pi
  //  Referenced by: '<S18>/Gain2'

  57.295779513082323,

  // Expression: 1/0.00478
  //  Referenced by: '<S18>/1//J'

  209.20502092050208,

  // Expression: 0.01/0.00478
  //  Referenced by: '<S18>/k//J'

  2.0920502092050208,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S18>/Saturation'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S18>/l1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S18>/lambda1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator1_gainv_g
  //  Referenced by: '<S18>/Discrete-Time Integrator1'

  0.005,

  // Expression: 0
  //  Referenced by: '<S18>/Discrete-Time Integrator1'

  0.0,

  // Expression: 0.1
  //  Referenced by: '<S18>/Constant1'

  0.1,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation10'

  1.0,

  // Expression: -1
  //  Referenced by: '<S18>/Saturation10'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation11'

  1.0,

  // Expression: -1
  //  Referenced by: '<S18>/Saturation11'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S18>/Gain'

  0.5,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation8'

  1.0,

  // Expression: -1
  //  Referenced by: '<S18>/Saturation8'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S18>/Constant2'

  1.0,

  // Expression: 30
  //  Referenced by: '<S18>/Gain5'

  30.0,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation13'

  1.0,

  // Expression: -1
  //  Referenced by: '<S18>/Saturation13'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation9'

  1.0,

  // Expression: -1
  //  Referenced by: '<S18>/Saturation9'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S18>/Gain1'

  0.5,

  // Expression: 1
  //  Referenced by: '<S18>/Constant4'

  1.0,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation12'

  1.0,

  // Expression: -1
  //  Referenced by: '<S18>/Saturation12'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation16'

  1.0,

  // Expression: -1
  //  Referenced by: '<S18>/Saturation16'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation14'

  1.0,

  // Expression: -1
  //  Referenced by: '<S18>/Saturation14'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S18>/Gain3'

  0.5,

  // Expression: 1
  //  Referenced by: '<S18>/Constant6'

  1.0,

  // Expression: 0
  //  Referenced by: '<S18>/lambda2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S18>/Saturation1'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S18>/l2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation15'

  1.0,

  // Expression: -1
  //  Referenced by: '<S18>/Saturation15'

  -1.0,

  // Expression: 30
  //  Referenced by: '<S18>/Gain6'

  30.0,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation19'

  1.0,

  // Expression: -1
  //  Referenced by: '<S18>/Saturation19'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation17'

  1.0,

  // Expression: -1
  //  Referenced by: '<S18>/Saturation17'

  -1.0,

  // Expression: 0.5
  //  Referenced by: '<S18>/Gain4'

  0.5,

  // Expression: 1
  //  Referenced by: '<S18>/Constant8'

  1.0,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation18'

  1.0,

  // Expression: -1
  //  Referenced by: '<S18>/Saturation18'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation3'

  1.0,

  // Expression: -1
  //  Referenced by: '<S18>/Saturation3'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S18>/l4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S18>/lambda4'

  0.0,

  // Expression: 40
  //  Referenced by: '<S18>/Gain7'

  40.0,

  // Expression: 1
  //  Referenced by: '<S18>/Gain8'

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

  // Expression: 1.1
  //  Referenced by: '<Root>/Constant1'

  1.1,

  // Expression: 0
  //  Referenced by: '<Root>/Constant4'

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

  // Expression: 40.16186580802367
  //  Referenced by: '<S49>/C1'

  40.16186580802367,

  // Computed Parameter: TSamp_WtEt_ow
  //  Referenced by: '<S51>/TSamp'

  200.0,

  // Expression: 76.12044208511008
  //  Referenced by: '<S49>/C2'

  76.120442085110085,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_h
  //  Referenced by: '<S49>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S49>/Discrete-Time Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S49>/C3'

  0.0,

  // Expression: 0.1
  //  Referenced by: '<S8>/Gain2'

  0.1,

  // Expression: 0.5
  //  Referenced by: '<S8>/Saturation1'

  0.5,

  // Expression: -0.5
  //  Referenced by: '<S8>/Saturation1'

  -0.5,

  // Expression: 0
  //  Referenced by: '<S8>/Constant'

  0.0,

  // Expression: 40.16186580802367
  //  Referenced by: '<S50>/C1'

  40.16186580802367,

  // Computed Parameter: TSamp_WtEt_g
  //  Referenced by: '<S52>/TSamp'

  200.0,

  // Expression: 76.12044208511008
  //  Referenced by: '<S50>/C2'

  76.120442085110085,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_i
  //  Referenced by: '<S50>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S50>/Discrete-Time Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S50>/C3'

  0.0,

  // Expression: 0.1
  //  Referenced by: '<S8>/Gain4'

  0.1,

  // Expression: 0.5
  //  Referenced by: '<S8>/Saturation2'

  0.5,

  // Expression: -0.5
  //  Referenced by: '<S8>/Saturation2'

  -0.5,

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

  // Computed Parameter: attitude_flag_Value
  //  Referenced by: '<S11>/attitude_flag'

  false,

  // Computed Parameter: observer_flag_Value
  //  Referenced by: '<S12>/observer_flag'

  false,

  // Computed Parameter: position_flag_Value
  //  Referenced by: '<S13>/position_flag'

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
