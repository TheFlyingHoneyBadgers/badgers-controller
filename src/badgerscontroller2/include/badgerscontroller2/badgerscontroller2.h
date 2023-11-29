//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: badgerscontroller2.h
//
// Code generated for Simulink model 'badgerscontroller2'.
//
// Model version                  : 8.0
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Tue Nov 28 19:05:19 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_badgerscontroller2_h_
#define RTW_HEADER_badgerscontroller2_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "badgerscontroller2_types.h"

extern "C"
{

#include "rtGetInf.h"

}

#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block signals (default storage)
struct B_badgerscontroller2_T {
  real_T Data;
  real_T Sum2;                         // '<S5>/Sum2'
  real_T ProportionalGain;             // '<S46>/Proportional Gain'
  real_T DerivativeGain;               // '<S35>/Derivative Gain'
  real_T FilterCoefficient;            // '<S44>/Filter Coefficient'
  real_T ProportionalGain_d;           // '<S94>/Proportional Gain'
  real_T DerivativeGain_o;             // '<S83>/Derivative Gain'
  real_T FilterCoefficient_f;          // '<S92>/Filter Coefficient'
  real_T IntegralGain;                 // '<S38>/Integral Gain'
  real_T IntegralGain_f;               // '<S86>/Integral Gain'
  SL_Bus_badgerscontroller2_std_msgs_Float64 In1;// '<S7>/In1'
  SL_Bus_badgerscontroller2_std_msgs_Float64 In1_n;// '<S6>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_badgerscontroller2_T {
  ros_slroscpp_internal_block_P_T obj; // '<S2>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_k;// '<S4>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_n;// '<S3>/SourceBlock'
};

// Continuous states (default storage)
struct X_badgerscontroller2_T {
  real_T Integrator_CSTATE;            // '<S41>/Integrator'
  real_T Filter_CSTATE;                // '<S36>/Filter'
  real_T Integrator_CSTATE_a;          // '<S89>/Integrator'
  real_T Filter_CSTATE_o;              // '<S84>/Filter'
};

// State derivatives (default storage)
struct XDot_badgerscontroller2_T {
  real_T Integrator_CSTATE;            // '<S41>/Integrator'
  real_T Filter_CSTATE;                // '<S36>/Filter'
  real_T Integrator_CSTATE_a;          // '<S89>/Integrator'
  real_T Filter_CSTATE_o;              // '<S84>/Filter'
};

// State disabled
struct XDis_badgerscontroller2_T {
  boolean_T Integrator_CSTATE;         // '<S41>/Integrator'
  boolean_T Filter_CSTATE;             // '<S36>/Filter'
  boolean_T Integrator_CSTATE_a;       // '<S89>/Integrator'
  boolean_T Filter_CSTATE_o;           // '<S84>/Filter'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_badgerscontroller2_T_ {
  real_T PIDController_D;              // Mask Parameter: PIDController_D
                                          //  Referenced by: '<S35>/Derivative Gain'

  real_T PIDController1_D;             // Mask Parameter: PIDController1_D
                                          //  Referenced by: '<S83>/Derivative Gain'

  real_T PIDController_I;              // Mask Parameter: PIDController_I
                                          //  Referenced by: '<S38>/Integral Gain'

  real_T PIDController1_I;             // Mask Parameter: PIDController1_I
                                          //  Referenced by: '<S86>/Integral Gain'

  real_T PIDController_InitialConditionF;
                              // Mask Parameter: PIDController_InitialConditionF
                                 //  Referenced by: '<S36>/Filter'

  real_T PIDController1_InitialCondition;
                              // Mask Parameter: PIDController1_InitialCondition
                                 //  Referenced by: '<S84>/Filter'

  real_T PIDController_InitialConditio_h;
                              // Mask Parameter: PIDController_InitialConditio_h
                                 //  Referenced by: '<S41>/Integrator'

  real_T PIDController1_InitialConditi_d;
                              // Mask Parameter: PIDController1_InitialConditi_d
                                 //  Referenced by: '<S89>/Integrator'

  real_T PIDController_N;              // Mask Parameter: PIDController_N
                                          //  Referenced by: '<S44>/Filter Coefficient'

  real_T PIDController1_N;             // Mask Parameter: PIDController1_N
                                          //  Referenced by: '<S92>/Filter Coefficient'

  real_T PIDController_P;              // Mask Parameter: PIDController_P
                                          //  Referenced by: '<S46>/Proportional Gain'

  real_T PIDController1_P;             // Mask Parameter: PIDController1_P
                                          //  Referenced by: '<S94>/Proportional Gain'

  SL_Bus_badgerscontroller2_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                               //  Referenced by: '<S1>/Constant'

  SL_Bus_badgerscontroller2_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                        //  Referenced by: '<S6>/Out1'

  SL_Bus_badgerscontroller2_std_msgs_Float64 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                                 //  Referenced by: '<S3>/Constant'

  SL_Bus_badgerscontroller2_std_msgs_Float64 Out1_Y0_i;// Computed Parameter: Out1_Y0_i
                                                          //  Referenced by: '<S7>/Out1'

  SL_Bus_badgerscontroller2_std_msgs_Float64 Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                                 //  Referenced by: '<S4>/Constant'

  real_T Switch_Threshold;             // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

  real_T Saturation_UpperSat;          // Expression: 1.5
                                          //  Referenced by: '<S5>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -5
                                          //  Referenced by: '<S5>/Saturation'

  real_T Constant2_Value;              // Expression: 0.01
                                          //  Referenced by: '<S5>/Constant2'

  real_T Constant_Value_l;             // Expression: 3
                                          //  Referenced by: '<S5>/Constant'

  real_T Constant1_Value;              // Expression: -5
                                          //  Referenced by: '<S5>/Constant1'

  real_T Switch1_Threshold;            // Expression: 2.5
                                          //  Referenced by: '<S5>/Switch1'

};

// Real-time Model Data Structure
struct tag_RTM_badgerscontroller2_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_badgerscontroller2_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_badgerscontroller2_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint16_T clockTick0;
    time_T stepSize0;
    uint16_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_badgerscontroller2_T badgerscontroller2_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_badgerscontroller2_T badgerscontroller2_B;

#ifdef __cplusplus

}

#endif

// Continuous states (default storage)
extern X_badgerscontroller2_T badgerscontroller2_X;

// Block states (default storage)
extern struct DW_badgerscontroller2_T badgerscontroller2_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void badgerscontroller2_initialize(void);
  extern void badgerscontroller2_step(void);
  extern void badgerscontroller2_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_badgerscontroller2_T *const badgerscontroller2_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination


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
//  '<Root>' : 'badgerscontroller2'
//  '<S1>'   : 'badgerscontroller2/Blank Message'
//  '<S2>'   : 'badgerscontroller2/Publish'
//  '<S3>'   : 'badgerscontroller2/Subscribe'
//  '<S4>'   : 'badgerscontroller2/Subscribe1'
//  '<S5>'   : 'badgerscontroller2/Subsystem'
//  '<S6>'   : 'badgerscontroller2/Subscribe/Enabled Subsystem'
//  '<S7>'   : 'badgerscontroller2/Subscribe1/Enabled Subsystem'
//  '<S8>'   : 'badgerscontroller2/Subsystem/PID Controller'
//  '<S9>'   : 'badgerscontroller2/Subsystem/PID Controller1'
//  '<S10>'  : 'badgerscontroller2/Subsystem/PID Controller/Anti-windup'
//  '<S11>'  : 'badgerscontroller2/Subsystem/PID Controller/D Gain'
//  '<S12>'  : 'badgerscontroller2/Subsystem/PID Controller/Filter'
//  '<S13>'  : 'badgerscontroller2/Subsystem/PID Controller/Filter ICs'
//  '<S14>'  : 'badgerscontroller2/Subsystem/PID Controller/I Gain'
//  '<S15>'  : 'badgerscontroller2/Subsystem/PID Controller/Ideal P Gain'
//  '<S16>'  : 'badgerscontroller2/Subsystem/PID Controller/Ideal P Gain Fdbk'
//  '<S17>'  : 'badgerscontroller2/Subsystem/PID Controller/Integrator'
//  '<S18>'  : 'badgerscontroller2/Subsystem/PID Controller/Integrator ICs'
//  '<S19>'  : 'badgerscontroller2/Subsystem/PID Controller/N Copy'
//  '<S20>'  : 'badgerscontroller2/Subsystem/PID Controller/N Gain'
//  '<S21>'  : 'badgerscontroller2/Subsystem/PID Controller/P Copy'
//  '<S22>'  : 'badgerscontroller2/Subsystem/PID Controller/Parallel P Gain'
//  '<S23>'  : 'badgerscontroller2/Subsystem/PID Controller/Reset Signal'
//  '<S24>'  : 'badgerscontroller2/Subsystem/PID Controller/Saturation'
//  '<S25>'  : 'badgerscontroller2/Subsystem/PID Controller/Saturation Fdbk'
//  '<S26>'  : 'badgerscontroller2/Subsystem/PID Controller/Sum'
//  '<S27>'  : 'badgerscontroller2/Subsystem/PID Controller/Sum Fdbk'
//  '<S28>'  : 'badgerscontroller2/Subsystem/PID Controller/Tracking Mode'
//  '<S29>'  : 'badgerscontroller2/Subsystem/PID Controller/Tracking Mode Sum'
//  '<S30>'  : 'badgerscontroller2/Subsystem/PID Controller/Tsamp - Integral'
//  '<S31>'  : 'badgerscontroller2/Subsystem/PID Controller/Tsamp - Ngain'
//  '<S32>'  : 'badgerscontroller2/Subsystem/PID Controller/postSat Signal'
//  '<S33>'  : 'badgerscontroller2/Subsystem/PID Controller/preSat Signal'
//  '<S34>'  : 'badgerscontroller2/Subsystem/PID Controller/Anti-windup/Passthrough'
//  '<S35>'  : 'badgerscontroller2/Subsystem/PID Controller/D Gain/Internal Parameters'
//  '<S36>'  : 'badgerscontroller2/Subsystem/PID Controller/Filter/Cont. Filter'
//  '<S37>'  : 'badgerscontroller2/Subsystem/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S38>'  : 'badgerscontroller2/Subsystem/PID Controller/I Gain/Internal Parameters'
//  '<S39>'  : 'badgerscontroller2/Subsystem/PID Controller/Ideal P Gain/Passthrough'
//  '<S40>'  : 'badgerscontroller2/Subsystem/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S41>'  : 'badgerscontroller2/Subsystem/PID Controller/Integrator/Continuous'
//  '<S42>'  : 'badgerscontroller2/Subsystem/PID Controller/Integrator ICs/Internal IC'
//  '<S43>'  : 'badgerscontroller2/Subsystem/PID Controller/N Copy/Disabled'
//  '<S44>'  : 'badgerscontroller2/Subsystem/PID Controller/N Gain/Internal Parameters'
//  '<S45>'  : 'badgerscontroller2/Subsystem/PID Controller/P Copy/Disabled'
//  '<S46>'  : 'badgerscontroller2/Subsystem/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S47>'  : 'badgerscontroller2/Subsystem/PID Controller/Reset Signal/Disabled'
//  '<S48>'  : 'badgerscontroller2/Subsystem/PID Controller/Saturation/Passthrough'
//  '<S49>'  : 'badgerscontroller2/Subsystem/PID Controller/Saturation Fdbk/Disabled'
//  '<S50>'  : 'badgerscontroller2/Subsystem/PID Controller/Sum/Sum_PID'
//  '<S51>'  : 'badgerscontroller2/Subsystem/PID Controller/Sum Fdbk/Disabled'
//  '<S52>'  : 'badgerscontroller2/Subsystem/PID Controller/Tracking Mode/Disabled'
//  '<S53>'  : 'badgerscontroller2/Subsystem/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S54>'  : 'badgerscontroller2/Subsystem/PID Controller/Tsamp - Integral/Passthrough'
//  '<S55>'  : 'badgerscontroller2/Subsystem/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S56>'  : 'badgerscontroller2/Subsystem/PID Controller/postSat Signal/Forward_Path'
//  '<S57>'  : 'badgerscontroller2/Subsystem/PID Controller/preSat Signal/Forward_Path'
//  '<S58>'  : 'badgerscontroller2/Subsystem/PID Controller1/Anti-windup'
//  '<S59>'  : 'badgerscontroller2/Subsystem/PID Controller1/D Gain'
//  '<S60>'  : 'badgerscontroller2/Subsystem/PID Controller1/Filter'
//  '<S61>'  : 'badgerscontroller2/Subsystem/PID Controller1/Filter ICs'
//  '<S62>'  : 'badgerscontroller2/Subsystem/PID Controller1/I Gain'
//  '<S63>'  : 'badgerscontroller2/Subsystem/PID Controller1/Ideal P Gain'
//  '<S64>'  : 'badgerscontroller2/Subsystem/PID Controller1/Ideal P Gain Fdbk'
//  '<S65>'  : 'badgerscontroller2/Subsystem/PID Controller1/Integrator'
//  '<S66>'  : 'badgerscontroller2/Subsystem/PID Controller1/Integrator ICs'
//  '<S67>'  : 'badgerscontroller2/Subsystem/PID Controller1/N Copy'
//  '<S68>'  : 'badgerscontroller2/Subsystem/PID Controller1/N Gain'
//  '<S69>'  : 'badgerscontroller2/Subsystem/PID Controller1/P Copy'
//  '<S70>'  : 'badgerscontroller2/Subsystem/PID Controller1/Parallel P Gain'
//  '<S71>'  : 'badgerscontroller2/Subsystem/PID Controller1/Reset Signal'
//  '<S72>'  : 'badgerscontroller2/Subsystem/PID Controller1/Saturation'
//  '<S73>'  : 'badgerscontroller2/Subsystem/PID Controller1/Saturation Fdbk'
//  '<S74>'  : 'badgerscontroller2/Subsystem/PID Controller1/Sum'
//  '<S75>'  : 'badgerscontroller2/Subsystem/PID Controller1/Sum Fdbk'
//  '<S76>'  : 'badgerscontroller2/Subsystem/PID Controller1/Tracking Mode'
//  '<S77>'  : 'badgerscontroller2/Subsystem/PID Controller1/Tracking Mode Sum'
//  '<S78>'  : 'badgerscontroller2/Subsystem/PID Controller1/Tsamp - Integral'
//  '<S79>'  : 'badgerscontroller2/Subsystem/PID Controller1/Tsamp - Ngain'
//  '<S80>'  : 'badgerscontroller2/Subsystem/PID Controller1/postSat Signal'
//  '<S81>'  : 'badgerscontroller2/Subsystem/PID Controller1/preSat Signal'
//  '<S82>'  : 'badgerscontroller2/Subsystem/PID Controller1/Anti-windup/Passthrough'
//  '<S83>'  : 'badgerscontroller2/Subsystem/PID Controller1/D Gain/Internal Parameters'
//  '<S84>'  : 'badgerscontroller2/Subsystem/PID Controller1/Filter/Cont. Filter'
//  '<S85>'  : 'badgerscontroller2/Subsystem/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S86>'  : 'badgerscontroller2/Subsystem/PID Controller1/I Gain/Internal Parameters'
//  '<S87>'  : 'badgerscontroller2/Subsystem/PID Controller1/Ideal P Gain/Passthrough'
//  '<S88>'  : 'badgerscontroller2/Subsystem/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S89>'  : 'badgerscontroller2/Subsystem/PID Controller1/Integrator/Continuous'
//  '<S90>'  : 'badgerscontroller2/Subsystem/PID Controller1/Integrator ICs/Internal IC'
//  '<S91>'  : 'badgerscontroller2/Subsystem/PID Controller1/N Copy/Disabled'
//  '<S92>'  : 'badgerscontroller2/Subsystem/PID Controller1/N Gain/Internal Parameters'
//  '<S93>'  : 'badgerscontroller2/Subsystem/PID Controller1/P Copy/Disabled'
//  '<S94>'  : 'badgerscontroller2/Subsystem/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S95>'  : 'badgerscontroller2/Subsystem/PID Controller1/Reset Signal/Disabled'
//  '<S96>'  : 'badgerscontroller2/Subsystem/PID Controller1/Saturation/Passthrough'
//  '<S97>'  : 'badgerscontroller2/Subsystem/PID Controller1/Saturation Fdbk/Disabled'
//  '<S98>'  : 'badgerscontroller2/Subsystem/PID Controller1/Sum/Sum_PID'
//  '<S99>'  : 'badgerscontroller2/Subsystem/PID Controller1/Sum Fdbk/Disabled'
//  '<S100>' : 'badgerscontroller2/Subsystem/PID Controller1/Tracking Mode/Disabled'
//  '<S101>' : 'badgerscontroller2/Subsystem/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S102>' : 'badgerscontroller2/Subsystem/PID Controller1/Tsamp - Integral/Passthrough'
//  '<S103>' : 'badgerscontroller2/Subsystem/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S104>' : 'badgerscontroller2/Subsystem/PID Controller1/postSat Signal/Forward_Path'
//  '<S105>' : 'badgerscontroller2/Subsystem/PID Controller1/preSat Signal/Forward_Path'

#endif                                 // RTW_HEADER_badgerscontroller2_h_

//
// File trailer for generated code.
//
// [EOF]
//
