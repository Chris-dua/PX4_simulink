//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px42LoopCtrQGC20220313_private.h
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
#ifndef RTW_HEADER_px42LoopCtrQGC20220313_private_h_
#define RTW_HEADER_px42LoopCtrQGC20220313_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "px42LoopCtrQGC20220313.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void px42LoopCtrQ_MATLABFunction(boolean_T rtu_e, real_T rtu_t, real_T
  rtu_s_t, real_T rtu_y1, real_T rtu_y2, real_T *rty_y);

#endif                          // RTW_HEADER_px42LoopCtrQGC20220313_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
