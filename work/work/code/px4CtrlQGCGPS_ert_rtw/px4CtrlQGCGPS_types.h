//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4CtrlQGCGPS_types.h
//
// Code generated for Simulink model 'px4CtrlQGCGPS'.
//
// Model version                  : 5.30
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Mar 14 21:30:28 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_px4CtrlQGCGPS_types_h_
#define RTW_HEADER_px4CtrlQGCGPS_types_h_
#include "rtwtypes.h"
#include <uORB/topics/vehicle_gps_position.h>
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/input_rc.h>

// Model Code Variants
#ifndef struct_c_coder_internal_mt19937ar_px_T
#define struct_c_coder_internal_mt19937ar_px_T

struct c_coder_internal_mt19937ar_px_T
{
  uint32_T Seed;
  uint32_T State[625];
};

#endif                                // struct_c_coder_internal_mt19937ar_px_T

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

#ifndef struct_px4_internal_block_Publisher__T
#define struct_px4_internal_block_Publisher__T

struct px4_internal_block_Publisher__T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  orb_advert_t orbAdvertiseObj;
  orb_metadata_t * orbMetadataObj;
};

#endif                                // struct_px4_internal_block_Publisher__T

#ifndef struct_px4_internal_block_PWM_px4Ctr_T
#define struct_px4_internal_block_PWM_px4Ctr_T

struct px4_internal_block_PWM_px4Ctr_T
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

#endif                                // struct_px4_internal_block_PWM_px4Ctr_T

#ifndef typedef_coder_internal_RngNt_px4CtrlQ_T
#define typedef_coder_internal_RngNt_px4CtrlQ_T

typedef int32_T coder_internal_RngNt_px4CtrlQ_T;

#endif                               // typedef_coder_internal_RngNt_px4CtrlQ_T

#ifndef coder_internal_RngNt_constants
#define coder_internal_RngNt_constants

// enum coder_internal_RngNt
const coder_internal_RngNt_px4CtrlQ_T ziggurat = 0;
const coder_internal_RngNt_px4CtrlQ_T polar = 1;
const coder_internal_RngNt_px4CtrlQ_T inversion = 2;

#endif                                 // coder_internal_RngNt_constants

#ifndef struct_b_coder_internal_RandStream_p_T
#define struct_b_coder_internal_RandStream_p_T

struct b_coder_internal_RandStream_p_T
{
  coder_internal_RngNt_px4CtrlQ_T NtMethod;
  real_T SavedPolarValue;
  boolean_T HaveSavedPolarValue;
  c_coder_internal_mt19937ar_px_T *Generator;
  c_coder_internal_mt19937ar_px_T MtGenerator;
};

#endif                                // struct_b_coder_internal_RandStream_p_T

#ifndef struct_fusion_internal_simulink_gpsS_T
#define struct_fusion_internal_simulink_gpsS_T

struct fusion_internal_simulink_gpsS_T
{
  boolean_T tunablePropertyChanged[4];
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T HorizontalPositionAccuracy;
  real_T VerticalPositionAccuracy;
  real_T VelocityAccuracy;
  real_T DecayFactor;
  b_coder_internal_RandStream_p_T *pStream;
  real_T pPositionErrorFilterNum;
  real_T pPositionErrorFilterDen[2];
  real32_T pPositionErrorFilterStates[3];
  real_T pSigmaScaled[3];
  b_coder_internal_RandStream_p_T _pobj0;
};

#endif                                // struct_fusion_internal_simulink_gpsS_T

// Parameters (default storage)
typedef struct P_px4CtrlQGCGPS_T_ P_px4CtrlQGCGPS_T;

// Forward declaration for rtModel
typedef struct tag_RTM_px4CtrlQGCGPS_T RT_MODEL_px4CtrlQGCGPS_T;

#endif                                 // RTW_HEADER_px4CtrlQGCGPS_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
