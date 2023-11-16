/*
 * badgerscontroller_private.h
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

#ifndef RTW_HEADER_badgerscontroller_private_h_
#define RTW_HEADER_badgerscontroller_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "badgerscontroller.h"
#include "badgerscontroller_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern void badgersco_EnabledSubsystem_Init(B_EnabledSubsystem_badgerscon_T
  *localB, P_EnabledSubsystem_badgerscon_T *localP);
extern void badgerscontrol_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_badgerscontroller_std_msgs_Float64 *rtu_In1,
  B_EnabledSubsystem_badgerscon_T *localB);

/* private model entry point functions */
extern void badgerscontroller_derivatives(void);

#endif                             /* RTW_HEADER_badgerscontroller_private_h_ */
