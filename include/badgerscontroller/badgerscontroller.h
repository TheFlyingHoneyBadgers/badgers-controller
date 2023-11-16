/*
 * badgerscontroller.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "badgerscontroller".
 *
 * Model version              : 8.0
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C++ source code generated on : Thu Nov 16 11:00:42 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_badgerscontroller_h_
#define RTW_HEADER_badgerscontroller_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "badgerscontroller_types.h"
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
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

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals for system '<S3>/Enabled Subsystem' */
struct B_EnabledSubsystem_badgerscon_T {
  SL_Bus_badgerscontroller_std_msgs_Float64 In1;/* '<S6>/In1' */
};

/* Block signals (default storage) */
struct B_badgerscontroller_T {
  real_T ProportionalGain;             /* '<S45>/Proportional Gain' */
  real_T DerivativeGain;               /* '<S34>/Derivative Gain' */
  real_T FilterCoefficient;            /* '<S43>/Filter Coefficient' */
  real_T Sum;                          /* '<S49>/Sum' */
  real_T IntegralGain;                 /* '<S37>/Integral Gain' */
  B_EnabledSubsystem_badgerscon_T EnabledSubsystem_f;/* '<S4>/Enabled Subsystem' */
  B_EnabledSubsystem_badgerscon_T EnabledSubsystem;/* '<S3>/Enabled Subsystem' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_badgerscontroller_T {
  ros_slroscpp_internal_block_P_T obj; /* '<S2>/SinkBlock' */
  ros_slroscpp_internal_block_S_T obj_k;/* '<S4>/SourceBlock' */
  ros_slroscpp_internal_block_S_T obj_n;/* '<S3>/SourceBlock' */
  boolean_T objisempty;                /* '<S4>/SourceBlock' */
  boolean_T objisempty_h;              /* '<S3>/SourceBlock' */
  boolean_T objisempty_f;              /* '<S2>/SinkBlock' */
};

/* Continuous states (default storage) */
struct X_badgerscontroller_T {
  real_T Integrator_CSTATE;            /* '<S40>/Integrator' */
  real_T Filter_CSTATE;                /* '<S35>/Filter' */
};

/* State derivatives (default storage) */
struct XDot_badgerscontroller_T {
  real_T Integrator_CSTATE;            /* '<S40>/Integrator' */
  real_T Filter_CSTATE;                /* '<S35>/Filter' */
};

/* State disabled  */
struct XDis_badgerscontroller_T {
  boolean_T Integrator_CSTATE;         /* '<S40>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S35>/Filter' */
};

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
struct ODE3_IntgData {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
};

#endif

/* Parameters for system: '<S3>/Enabled Subsystem' */
struct P_EnabledSubsystem_badgerscon_T_ {
  SL_Bus_badgerscontroller_std_msgs_Float64 Out1_Y0;/* Computed Parameter: Out1_Y0
                                                     * Referenced by: '<S6>/Out1'
                                                     */
};

/* Parameters (default storage) */
struct P_badgerscontroller_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S34>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S37>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S35>/Filter'
                               */
  real_T PIDController_InitialConditio_a;
                              /* Mask Parameter: PIDController_InitialConditio_a
                               * Referenced by: '<S40>/Integrator'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S43>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S45>/Proportional Gain'
                                        */
  SL_Bus_badgerscontroller_std_msgs_Float64 Constant_Value;/* Computed Parameter: Constant_Value
                                                            * Referenced by: '<S1>/Constant'
                                                            */
  SL_Bus_badgerscontroller_std_msgs_Float64 Constant_Value_g;/* Computed Parameter: Constant_Value_g
                                                              * Referenced by: '<S3>/Constant'
                                                              */
  SL_Bus_badgerscontroller_std_msgs_Float64 Constant_Value_f;/* Computed Parameter: Constant_Value_f
                                                              * Referenced by: '<S4>/Constant'
                                                              */
  real_T Constant_Value_n;             /* Expression: 3
                                        * Referenced by: '<S5>/Constant'
                                        */
  P_EnabledSubsystem_badgerscon_T EnabledSubsystem_f;/* '<S4>/Enabled Subsystem' */
  P_EnabledSubsystem_badgerscon_T EnabledSubsystem;/* '<S3>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_badgerscontroller_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_badgerscontroller_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_badgerscontroller_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_badgerscontroller_T badgerscontroller_P;

#ifdef __cplusplus

}

#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_badgerscontroller_T badgerscontroller_B;

#ifdef __cplusplus

}

#endif

/* Continuous states (default storage) */
extern X_badgerscontroller_T badgerscontroller_X;

/* Disabled states (default storage) */
extern XDis_badgerscontroller_T badgerscontroller_XDis;

/* Block states (default storage) */
extern struct DW_badgerscontroller_T badgerscontroller_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern void badgerscontroller_initialize(void);
  extern void badgerscontroller_step(void);
  extern void badgerscontroller_terminate(void);

#ifdef __cplusplus

}

#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_badgerscontroller_T *const badgerscontroller_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'badgerscontroller'
 * '<S1>'   : 'badgerscontroller/Blank Message'
 * '<S2>'   : 'badgerscontroller/Publish'
 * '<S3>'   : 'badgerscontroller/Subscribe'
 * '<S4>'   : 'badgerscontroller/Subscribe1'
 * '<S5>'   : 'badgerscontroller/Subsystem'
 * '<S6>'   : 'badgerscontroller/Subscribe/Enabled Subsystem'
 * '<S7>'   : 'badgerscontroller/Subscribe1/Enabled Subsystem'
 * '<S8>'   : 'badgerscontroller/Subsystem/PID Controller'
 * '<S9>'   : 'badgerscontroller/Subsystem/PID Controller/Anti-windup'
 * '<S10>'  : 'badgerscontroller/Subsystem/PID Controller/D Gain'
 * '<S11>'  : 'badgerscontroller/Subsystem/PID Controller/Filter'
 * '<S12>'  : 'badgerscontroller/Subsystem/PID Controller/Filter ICs'
 * '<S13>'  : 'badgerscontroller/Subsystem/PID Controller/I Gain'
 * '<S14>'  : 'badgerscontroller/Subsystem/PID Controller/Ideal P Gain'
 * '<S15>'  : 'badgerscontroller/Subsystem/PID Controller/Ideal P Gain Fdbk'
 * '<S16>'  : 'badgerscontroller/Subsystem/PID Controller/Integrator'
 * '<S17>'  : 'badgerscontroller/Subsystem/PID Controller/Integrator ICs'
 * '<S18>'  : 'badgerscontroller/Subsystem/PID Controller/N Copy'
 * '<S19>'  : 'badgerscontroller/Subsystem/PID Controller/N Gain'
 * '<S20>'  : 'badgerscontroller/Subsystem/PID Controller/P Copy'
 * '<S21>'  : 'badgerscontroller/Subsystem/PID Controller/Parallel P Gain'
 * '<S22>'  : 'badgerscontroller/Subsystem/PID Controller/Reset Signal'
 * '<S23>'  : 'badgerscontroller/Subsystem/PID Controller/Saturation'
 * '<S24>'  : 'badgerscontroller/Subsystem/PID Controller/Saturation Fdbk'
 * '<S25>'  : 'badgerscontroller/Subsystem/PID Controller/Sum'
 * '<S26>'  : 'badgerscontroller/Subsystem/PID Controller/Sum Fdbk'
 * '<S27>'  : 'badgerscontroller/Subsystem/PID Controller/Tracking Mode'
 * '<S28>'  : 'badgerscontroller/Subsystem/PID Controller/Tracking Mode Sum'
 * '<S29>'  : 'badgerscontroller/Subsystem/PID Controller/Tsamp - Integral'
 * '<S30>'  : 'badgerscontroller/Subsystem/PID Controller/Tsamp - Ngain'
 * '<S31>'  : 'badgerscontroller/Subsystem/PID Controller/postSat Signal'
 * '<S32>'  : 'badgerscontroller/Subsystem/PID Controller/preSat Signal'
 * '<S33>'  : 'badgerscontroller/Subsystem/PID Controller/Anti-windup/Passthrough'
 * '<S34>'  : 'badgerscontroller/Subsystem/PID Controller/D Gain/Internal Parameters'
 * '<S35>'  : 'badgerscontroller/Subsystem/PID Controller/Filter/Cont. Filter'
 * '<S36>'  : 'badgerscontroller/Subsystem/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S37>'  : 'badgerscontroller/Subsystem/PID Controller/I Gain/Internal Parameters'
 * '<S38>'  : 'badgerscontroller/Subsystem/PID Controller/Ideal P Gain/Passthrough'
 * '<S39>'  : 'badgerscontroller/Subsystem/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S40>'  : 'badgerscontroller/Subsystem/PID Controller/Integrator/Continuous'
 * '<S41>'  : 'badgerscontroller/Subsystem/PID Controller/Integrator ICs/Internal IC'
 * '<S42>'  : 'badgerscontroller/Subsystem/PID Controller/N Copy/Disabled'
 * '<S43>'  : 'badgerscontroller/Subsystem/PID Controller/N Gain/Internal Parameters'
 * '<S44>'  : 'badgerscontroller/Subsystem/PID Controller/P Copy/Disabled'
 * '<S45>'  : 'badgerscontroller/Subsystem/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S46>'  : 'badgerscontroller/Subsystem/PID Controller/Reset Signal/Disabled'
 * '<S47>'  : 'badgerscontroller/Subsystem/PID Controller/Saturation/Passthrough'
 * '<S48>'  : 'badgerscontroller/Subsystem/PID Controller/Saturation Fdbk/Disabled'
 * '<S49>'  : 'badgerscontroller/Subsystem/PID Controller/Sum/Sum_PID'
 * '<S50>'  : 'badgerscontroller/Subsystem/PID Controller/Sum Fdbk/Disabled'
 * '<S51>'  : 'badgerscontroller/Subsystem/PID Controller/Tracking Mode/Disabled'
 * '<S52>'  : 'badgerscontroller/Subsystem/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S53>'  : 'badgerscontroller/Subsystem/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S54>'  : 'badgerscontroller/Subsystem/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S55>'  : 'badgerscontroller/Subsystem/PID Controller/postSat Signal/Forward_Path'
 * '<S56>'  : 'badgerscontroller/Subsystem/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_badgerscontroller_h_ */
