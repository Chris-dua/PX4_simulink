//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4_noGPS_types.h
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
#ifndef RTW_HEADER_px4_noGPS_types_h_
#define RTW_HEADER_px4_noGPS_types_h_
#include "rtwtypes.h"
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/vehicle_odometry.h>

// Model Code Variants
#ifndef struct_px4_internal_block_PWM_px4_no_T
#define struct_px4_internal_block_PWM_px4_no_T

struct px4_internal_block_PWM_px4_no_T
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

#endif                                // struct_px4_internal_block_PWM_px4_no_T

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

// Parameters (default storage)
typedef struct P_px4_noGPS_T_ P_px4_noGPS_T;

// Forward declaration for rtModel
typedef struct tag_RTM_px4_noGPS_T RT_MODEL_px4_noGPS_T;

#endif                                 // RTW_HEADER_px4_noGPS_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
