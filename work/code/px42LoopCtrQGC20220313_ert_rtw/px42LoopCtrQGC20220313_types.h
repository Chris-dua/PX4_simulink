//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px42LoopCtrQGC20220313_types.h
//
// Code generated for Simulink model 'px42LoopCtrQGC20220313'.
//
// Model version                  : 5.5
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Mar 16 10:17:15 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_px42LoopCtrQGC20220313_types_h_
#define RTW_HEADER_px42LoopCtrQGC20220313_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/input_rc.h>

// Model Code Variants
#ifndef struct_px4_internal_block_PWM_px42Lo_T
#define struct_px4_internal_block_PWM_px42Lo_T

struct px4_internal_block_PWM_px42Lo_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  int pwmDevHandler;
  const char * pwmDevObj;
  unsigned int servoCount;
  int channelMask;
  boolean_T isMain;
  uint16_T errorStatus;
  orb_advert_t armAdvertiseObj;
  orb_advert_t actuatorAdvertiseObj;
  boolean_T isArmed;
};

#endif                                // struct_px4_internal_block_PWM_px42Lo_T

#ifndef struct_e_px4_internal_block_SampleTi_T
#define struct_e_px4_internal_block_SampleTi_T

struct e_px4_internal_block_SampleTi_T
{
  int32_T __dummy;
};

#endif                                // struct_e_px4_internal_block_SampleTi_T

#ifndef struct_px4_internal_block_Subscriber_T
#define struct_px4_internal_block_Subscriber_T

struct px4_internal_block_Subscriber_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  e_px4_internal_block_SampleTi_T SampleTimeHandler;
  pollfd_t eventStructObj;
  orb_metadata_t * orbMetadataObj;
};

#endif                                // struct_px4_internal_block_Subscriber_T

// Custom Type definition for MATLABSystem: '<Root>/Serial Transmit1'
#include "MW_SVD.h"
#ifndef struct_c_px4_internal_block_Hardware_T
#define struct_c_px4_internal_block_Hardware_T

struct c_px4_internal_block_Hardware_T
{
  int32_T __dummy;
};

#endif                                // struct_c_px4_internal_block_Hardware_T

#ifndef struct_d_px4_internal_block_PX4SCIDr_T
#define struct_d_px4_internal_block_PX4SCIDr_T

struct d_px4_internal_block_PX4SCIDr_T
{
  MW_Handle_Type MW_SCIHANDLE;
};

#endif                                // struct_d_px4_internal_block_PX4SCIDr_T

#ifndef struct_px4_internal_block_PX4SCIWrit_T
#define struct_px4_internal_block_PX4SCIWrit_T

struct px4_internal_block_PX4SCIWrit_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_px4_internal_block_Hardware_T Hw;
  d_px4_internal_block_PX4SCIDr_T SCIDriverObj;
};

#endif                                // struct_px4_internal_block_PX4SCIWrit_T

// Parameters (default storage)
typedef struct P_px42LoopCtrQGC20220313_T_ P_px42LoopCtrQGC20220313_T;

// Forward declaration for rtModel
typedef struct tag_RTM_px42LoopCtrQGC2022031_T RT_MODEL_px42LoopCtrQGC202203_T;

#endif                            // RTW_HEADER_px42LoopCtrQGC20220313_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
