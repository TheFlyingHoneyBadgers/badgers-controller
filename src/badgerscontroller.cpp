/*
 * badgerscontroller.cpp
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

#include "badgerscontroller.h"
#include "rtwtypes.h"
#include "badgerscontroller_types.h"
#include "badgerscontroller_private.h"
#include <string.h>

/* Block signals (default storage) */
B_badgerscontroller_T badgerscontroller_B;

/* Continuous states */
X_badgerscontroller_T badgerscontroller_X;

/* Disabled State Vector */
XDis_badgerscontroller_T badgerscontroller_XDis;

/* Block states (default storage) */
DW_badgerscontroller_T badgerscontroller_DW;

/* Real-time model */
RT_MODEL_badgerscontroller_T badgerscontroller_M_ = RT_MODEL_badgerscontroller_T
  ();
RT_MODEL_badgerscontroller_T *const badgerscontroller_M = &badgerscontroller_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  badgerscontroller_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  badgerscontroller_step();
  badgerscontroller_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  badgerscontroller_step();
  badgerscontroller_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for enable system:
 *    '<S3>/Enabled Subsystem'
 *    '<S4>/Enabled Subsystem'
 */
void badgersco_EnabledSubsystem_Init(B_EnabledSubsystem_badgerscon_T *localB,
  P_EnabledSubsystem_badgerscon_T *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S6>/In1' incorporates:
   *  Outport: '<S6>/Out1'
   */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for enable system:
 *    '<S3>/Enabled Subsystem'
 *    '<S4>/Enabled Subsystem'
 */
void badgerscontrol_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_badgerscontroller_std_msgs_Float64 *rtu_In1,
  B_EnabledSubsystem_badgerscon_T *localB)
{
  /* Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S6>/In1' */
    localB->In1 = *rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S3>/Enabled Subsystem' */
}

/* Model step function */
void badgerscontroller_step(void)
{
  /* local block i/o variables */
  SL_Bus_badgerscontroller_std_msgs_Float64 rtb_SourceBlock_o2;
  SL_Bus_badgerscontroller_std_msgs_Float64 rtb_SourceBlock_o2_b;
  boolean_T rtb_SourceBlock_o1;
  boolean_T rtb_SourceBlock_o1_k;
  SL_Bus_badgerscontroller_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_Data;
  real_T rtb_Sum2;
  if (rtmIsMajorTimeStep(badgerscontroller_M)) {
    /* set solver stop time */
    if (!(badgerscontroller_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&badgerscontroller_M->solverInfo,
                            ((badgerscontroller_M->Timing.clockTickH0 + 1) *
        badgerscontroller_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&badgerscontroller_M->solverInfo,
                            ((badgerscontroller_M->Timing.clockTick0 + 1) *
        badgerscontroller_M->Timing.stepSize0 +
        badgerscontroller_M->Timing.clockTickH0 *
        badgerscontroller_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(badgerscontroller_M)) {
    badgerscontroller_M->Timing.t[0] = rtsiGetT(&badgerscontroller_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(badgerscontroller_M)) {
    /* Outputs for Atomic SubSystem: '<Root>/Subscribe1' */
    /* MATLABSystem: '<S4>/SourceBlock' */
    rtb_SourceBlock_o1 = Sub_badgerscontroller_47.getLatestMessage
      (&rtb_SourceBlock_o2);

    /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' */
    badgerscontrol_EnabledSubsystem(rtb_SourceBlock_o1, &rtb_SourceBlock_o2,
      &badgerscontroller_B.EnabledSubsystem_f);

    /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Subscribe1' */

    /* SignalConversion generated from: '<Root>/Bus Selector1' */
    rtb_Data = badgerscontroller_B.EnabledSubsystem_f.In1.Data;

    /* Outputs for Atomic SubSystem: '<Root>/Subscribe' */
    /* MATLABSystem: '<S3>/SourceBlock' */
    rtb_SourceBlock_o1_k = Sub_badgerscontroller_34.getLatestMessage
      (&rtb_SourceBlock_o2_b);

    /* Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' */
    badgerscontrol_EnabledSubsystem(rtb_SourceBlock_o1_k, &rtb_SourceBlock_o2_b,
      &badgerscontroller_B.EnabledSubsystem);

    /* End of Outputs for SubSystem: '<S3>/Enabled Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Subscribe' */

    /* Sum: '<S5>/Sum2' incorporates:
     *  Constant: '<S5>/Constant'
     *  Product: '<S5>/Divide'
     */
    rtb_Sum2 = rtb_Data / badgerscontroller_B.EnabledSubsystem.In1.Data -
      badgerscontroller_P.Constant_Value_n;

    /* Gain: '<S45>/Proportional Gain' */
    badgerscontroller_B.ProportionalGain = badgerscontroller_P.PIDController_P *
      rtb_Sum2;

    /* Gain: '<S34>/Derivative Gain' */
    badgerscontroller_B.DerivativeGain = badgerscontroller_P.PIDController_D *
      rtb_Sum2;
  }

  /* Gain: '<S43>/Filter Coefficient' incorporates:
   *  Integrator: '<S35>/Filter'
   *  Sum: '<S35>/SumD'
   */
  badgerscontroller_B.FilterCoefficient = (badgerscontroller_B.DerivativeGain -
    badgerscontroller_X.Filter_CSTATE) * badgerscontroller_P.PIDController_N;

  /* Sum: '<S49>/Sum' incorporates:
   *  Integrator: '<S40>/Integrator'
   */
  badgerscontroller_B.Sum = (badgerscontroller_B.ProportionalGain +
    badgerscontroller_X.Integrator_CSTATE) +
    badgerscontroller_B.FilterCoefficient;

  /* BusAssignment: '<Root>/Bus Assignment' */
  rtb_BusAssignment.Data = badgerscontroller_B.Sum;

  /* Outputs for Atomic SubSystem: '<Root>/Publish' */
  /* MATLABSystem: '<S2>/SinkBlock' */
  Pub_badgerscontroller_35.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish' */
  if (rtmIsMajorTimeStep(badgerscontroller_M)) {
    /* Gain: '<S37>/Integral Gain' */
    badgerscontroller_B.IntegralGain = badgerscontroller_P.PIDController_I *
      rtb_Sum2;
  }

  if (rtmIsMajorTimeStep(badgerscontroller_M)) {
    rt_ertODEUpdateContinuousStates(&badgerscontroller_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++badgerscontroller_M->Timing.clockTick0)) {
      ++badgerscontroller_M->Timing.clockTickH0;
    }

    badgerscontroller_M->Timing.t[0] = rtsiGetSolverStopTime
      (&badgerscontroller_M->solverInfo);

    {
      /* Update absolute timer for sample time: [20.0s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 20.0, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      badgerscontroller_M->Timing.clockTick1++;
      if (!badgerscontroller_M->Timing.clockTick1) {
        badgerscontroller_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void badgerscontroller_derivatives(void)
{
  XDot_badgerscontroller_T *_rtXdot;
  _rtXdot = ((XDot_badgerscontroller_T *) badgerscontroller_M->derivs);

  /* Derivatives for Integrator: '<S40>/Integrator' */
  _rtXdot->Integrator_CSTATE = badgerscontroller_B.IntegralGain;

  /* Derivatives for Integrator: '<S35>/Filter' */
  _rtXdot->Filter_CSTATE = badgerscontroller_B.FilterCoefficient;
}

/* Model initialize function */
void badgerscontroller_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&badgerscontroller_M->solverInfo,
                          &badgerscontroller_M->Timing.simTimeStep);
    rtsiSetTPtr(&badgerscontroller_M->solverInfo, &rtmGetTPtr
                (badgerscontroller_M));
    rtsiSetStepSizePtr(&badgerscontroller_M->solverInfo,
                       &badgerscontroller_M->Timing.stepSize0);
    rtsiSetdXPtr(&badgerscontroller_M->solverInfo, &badgerscontroller_M->derivs);
    rtsiSetContStatesPtr(&badgerscontroller_M->solverInfo, (real_T **)
                         &badgerscontroller_M->contStates);
    rtsiSetNumContStatesPtr(&badgerscontroller_M->solverInfo,
      &badgerscontroller_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&badgerscontroller_M->solverInfo,
      &badgerscontroller_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&badgerscontroller_M->solverInfo,
      &badgerscontroller_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&badgerscontroller_M->solverInfo,
      &badgerscontroller_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&badgerscontroller_M->solverInfo, (boolean_T**)
      &badgerscontroller_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&badgerscontroller_M->solverInfo, (&rtmGetErrorStatus
      (badgerscontroller_M)));
    rtsiSetRTModelPtr(&badgerscontroller_M->solverInfo, badgerscontroller_M);
  }

  rtsiSetSimTimeStep(&badgerscontroller_M->solverInfo, MAJOR_TIME_STEP);
  badgerscontroller_M->intgData.y = badgerscontroller_M->odeY;
  badgerscontroller_M->intgData.f[0] = badgerscontroller_M->odeF[0];
  badgerscontroller_M->intgData.f[1] = badgerscontroller_M->odeF[1];
  badgerscontroller_M->intgData.f[2] = badgerscontroller_M->odeF[2];
  badgerscontroller_M->contStates = ((X_badgerscontroller_T *)
    &badgerscontroller_X);
  badgerscontroller_M->contStateDisabled = ((XDis_badgerscontroller_T *)
    &badgerscontroller_XDis);
  badgerscontroller_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&badgerscontroller_M->solverInfo, static_cast<void *>
                    (&badgerscontroller_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&badgerscontroller_M->solverInfo, false);
  rtsiSetSolverName(&badgerscontroller_M->solverInfo,"ode3");
  rtmSetTPtr(badgerscontroller_M, &badgerscontroller_M->Timing.tArray[0]);
  badgerscontroller_M->Timing.stepSize0 = 20.0;

  /* block I/O */
  (void) memset((static_cast<void *>(&badgerscontroller_B)), 0,
                sizeof(B_badgerscontroller_T));

  /* states (continuous) */
  {
    (void) memset(static_cast<void *>(&badgerscontroller_X), 0,
                  sizeof(X_badgerscontroller_T));
  }

  /* disabled states */
  {
    (void) memset(static_cast<void *>(&badgerscontroller_XDis), 0,
                  sizeof(XDis_badgerscontroller_T));
  }

  /* states (dwork) */
  (void) memset(static_cast<void *>(&badgerscontroller_DW), 0,
                sizeof(DW_badgerscontroller_T));

  {
    int32_T i;
    char_T b_zeroDelimTopic_0[17];
    char_T b_zeroDelimTopic_1[15];
    char_T b_zeroDelimTopic[11];
    static const char_T tmp[10] = { '/', 'l', 'e', 'a', 'd', '_', 'd', 'i', 's',
      't' };

    static const char_T tmp_0[16] = { '/', 'c', 'a', 'r', '/', 's', 't', 'a',
      't', 'e', '/', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_1[14] = { '/', 'c', 'm', 'd', '_', 'a', 'c', 'c',
      'e', 'l', '_', 's', 'l', 'm' };

    /* Start for Atomic SubSystem: '<Root>/Subscribe1' */
    /* Start for MATLABSystem: '<S4>/SourceBlock' */
    badgerscontroller_DW.obj_k.matlabCodegenIsDeleted = false;
    badgerscontroller_DW.objisempty = true;
    badgerscontroller_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[10] = '\x00';
    Sub_badgerscontroller_47.createSubscriber(&b_zeroDelimTopic[0], 1);
    badgerscontroller_DW.obj_k.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe1' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe' */
    /* Start for MATLABSystem: '<S3>/SourceBlock' */
    badgerscontroller_DW.obj_n.matlabCodegenIsDeleted = false;
    badgerscontroller_DW.objisempty_h = true;
    badgerscontroller_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[16] = '\x00';
    Sub_badgerscontroller_34.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    badgerscontroller_DW.obj_n.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S3>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe' */

    /* Start for Atomic SubSystem: '<Root>/Publish' */
    /* Start for MATLABSystem: '<S2>/SinkBlock' */
    badgerscontroller_DW.obj.matlabCodegenIsDeleted = false;
    badgerscontroller_DW.objisempty_f = true;
    badgerscontroller_DW.obj.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      b_zeroDelimTopic_1[i] = tmp_1[i];
    }

    b_zeroDelimTopic_1[14] = '\x00';
    Pub_badgerscontroller_35.createPublisher(&b_zeroDelimTopic_1[0], 1);
    badgerscontroller_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S2>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish' */
  }

  /* InitializeConditions for Integrator: '<S40>/Integrator' */
  badgerscontroller_X.Integrator_CSTATE =
    badgerscontroller_P.PIDController_InitialConditio_a;

  /* InitializeConditions for Integrator: '<S35>/Filter' */
  badgerscontroller_X.Filter_CSTATE =
    badgerscontroller_P.PIDController_InitialConditionF;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1' */
  /* SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  badgersco_EnabledSubsystem_Init(&badgerscontroller_B.EnabledSubsystem_f,
    &badgerscontroller_P.EnabledSubsystem_f);

  /* End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe1' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe' */
  /* SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem' */
  badgersco_EnabledSubsystem_Init(&badgerscontroller_B.EnabledSubsystem,
    &badgerscontroller_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe' */
}

/* Model terminate function */
void badgerscontroller_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Subscribe1' */
  /* Terminate for MATLABSystem: '<S4>/SourceBlock' */
  if (!badgerscontroller_DW.obj_k.matlabCodegenIsDeleted) {
    badgerscontroller_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe1' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe' */
  /* Terminate for MATLABSystem: '<S3>/SourceBlock' */
  if (!badgerscontroller_DW.obj_n.matlabCodegenIsDeleted) {
    badgerscontroller_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe' */

  /* Terminate for Atomic SubSystem: '<Root>/Publish' */
  /* Terminate for MATLABSystem: '<S2>/SinkBlock' */
  if (!badgerscontroller_DW.obj.matlabCodegenIsDeleted) {
    badgerscontroller_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish' */
}
