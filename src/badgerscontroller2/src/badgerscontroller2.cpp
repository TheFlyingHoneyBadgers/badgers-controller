//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: badgerscontroller2.cpp
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
#include "badgerscontroller2.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rtwtypes.h"
#include "badgerscontroller2_types.h"
#include "badgerscontroller2_private.h"

// Block signals (default storage)
B_badgerscontroller2_T badgerscontroller2_B;

// Continuous states
X_badgerscontroller2_T badgerscontroller2_X;

// Block states (default storage)
DW_badgerscontroller2_T badgerscontroller2_DW;

// Real-time model
RT_MODEL_badgerscontroller2_T badgerscontroller2_M_ =
  RT_MODEL_badgerscontroller2_T();
RT_MODEL_badgerscontroller2_T *const badgerscontroller2_M =
  &badgerscontroller2_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  badgerscontroller2_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  badgerscontroller2_step();
  badgerscontroller2_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  badgerscontroller2_step();
  badgerscontroller2_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void badgerscontroller2_step(void)
{
  SL_Bus_badgerscontroller2_std_msgs_Float64 b_varargout_2;
  SL_Bus_badgerscontroller2_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_Switch;
  if (rtmIsMajorTimeStep(badgerscontroller2_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&badgerscontroller2_M->solverInfo,
                          ((badgerscontroller2_M->Timing.clockTick0+1)*
      badgerscontroller2_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(badgerscontroller2_M)) {
    badgerscontroller2_M->Timing.t[0] = rtsiGetT
      (&badgerscontroller2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(badgerscontroller2_M)) {
    boolean_T b_varargout_1;

    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S4>/SourceBlock'
    b_varargout_1 = Sub_badgerscontroller2_47.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S7>/Enable'

    if (b_varargout_1) {
      // SignalConversion generated from: '<S7>/In1'
      badgerscontroller2_B.In1 = b_varargout_2;
    }

    // End of MATLABSystem: '<S4>/SourceBlock'
    // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // SignalConversion generated from: '<Root>/Bus Selector1'
    badgerscontroller2_B.Data = badgerscontroller2_B.In1.Data;

    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S3>/SourceBlock'
    b_varargout_1 = Sub_badgerscontroller2_34.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S6>/Enable'

    if (b_varargout_1) {
      // SignalConversion generated from: '<S6>/In1'
      badgerscontroller2_B.In1_n = b_varargout_2;
    }

    // End of MATLABSystem: '<S3>/SourceBlock'
    // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // MinMax: '<S5>/Max' incorporates:
    //   Constant: '<S5>/Constant2'

    if ((badgerscontroller2_B.In1_n.Data >= badgerscontroller2_P.Constant2_Value)
        || rtIsNaN(badgerscontroller2_P.Constant2_Value)) {
      rtb_Switch = badgerscontroller2_B.In1_n.Data;
    } else {
      rtb_Switch = badgerscontroller2_P.Constant2_Value;
    }

    // Sum: '<S5>/Sum2' incorporates:
    //   Constant: '<S5>/Constant'
    //   MinMax: '<S5>/Max'
    //   Product: '<S5>/Divide'

    badgerscontroller2_B.Sum2 = badgerscontroller2_B.Data / rtb_Switch -
      badgerscontroller2_P.Constant_Value_l;

    // Gain: '<S46>/Proportional Gain'
    badgerscontroller2_B.ProportionalGain = badgerscontroller2_P.PIDController_P
      * badgerscontroller2_B.Sum2;

    // Gain: '<S35>/Derivative Gain'
    badgerscontroller2_B.DerivativeGain = badgerscontroller2_P.PIDController_D *
      badgerscontroller2_B.Sum2;

    // Gain: '<S94>/Proportional Gain'
    badgerscontroller2_B.ProportionalGain_d =
      badgerscontroller2_P.PIDController1_P * badgerscontroller2_B.Sum2;

    // Gain: '<S83>/Derivative Gain'
    badgerscontroller2_B.DerivativeGain_o =
      badgerscontroller2_P.PIDController1_D * badgerscontroller2_B.Sum2;
  }

  // Gain: '<S44>/Filter Coefficient' incorporates:
  //   Integrator: '<S36>/Filter'
  //   Sum: '<S36>/SumD'

  badgerscontroller2_B.FilterCoefficient = (badgerscontroller2_B.DerivativeGain
    - badgerscontroller2_X.Filter_CSTATE) * badgerscontroller2_P.PIDController_N;

  // Gain: '<S92>/Filter Coefficient' incorporates:
  //   Integrator: '<S84>/Filter'
  //   Sum: '<S84>/SumD'

  badgerscontroller2_B.FilterCoefficient_f =
    (badgerscontroller2_B.DerivativeGain_o -
     badgerscontroller2_X.Filter_CSTATE_o) *
    badgerscontroller2_P.PIDController1_N;

  // Switch: '<S5>/Switch1'
  if (badgerscontroller2_B.Data > badgerscontroller2_P.Switch1_Threshold) {
    // Switch: '<S5>/Switch' incorporates:
    //   Integrator: '<S41>/Integrator'
    //   Integrator: '<S89>/Integrator'
    //   Sum: '<S50>/Sum'
    //   Sum: '<S98>/Sum'

    if (badgerscontroller2_B.Sum2 > badgerscontroller2_P.Switch_Threshold) {
      rtb_Switch = (badgerscontroller2_B.ProportionalGain +
                    badgerscontroller2_X.Integrator_CSTATE) +
        badgerscontroller2_B.FilterCoefficient;
    } else {
      rtb_Switch = (badgerscontroller2_B.ProportionalGain_d +
                    badgerscontroller2_X.Integrator_CSTATE_a) +
        badgerscontroller2_B.FilterCoefficient_f;
    }

    // End of Switch: '<S5>/Switch'

    // Saturate: '<S5>/Saturation'
    if (rtb_Switch > badgerscontroller2_P.Saturation_UpperSat) {
      // BusAssignment: '<Root>/Bus Assignment'
      rtb_BusAssignment.Data = badgerscontroller2_P.Saturation_UpperSat;
    } else if (rtb_Switch < badgerscontroller2_P.Saturation_LowerSat) {
      // BusAssignment: '<Root>/Bus Assignment'
      rtb_BusAssignment.Data = badgerscontroller2_P.Saturation_LowerSat;
    } else {
      // BusAssignment: '<Root>/Bus Assignment'
      rtb_BusAssignment.Data = rtb_Switch;
    }

    // End of Saturate: '<S5>/Saturation'
  } else {
    // BusAssignment: '<Root>/Bus Assignment' incorporates:
    //   Constant: '<S5>/Constant1'

    rtb_BusAssignment.Data = badgerscontroller2_P.Constant1_Value;
  }

  // End of Switch: '<S5>/Switch1'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S2>/SinkBlock'
  Pub_badgerscontroller2_35.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (rtmIsMajorTimeStep(badgerscontroller2_M)) {
    // Gain: '<S38>/Integral Gain'
    badgerscontroller2_B.IntegralGain = badgerscontroller2_P.PIDController_I *
      badgerscontroller2_B.Sum2;

    // Gain: '<S86>/Integral Gain'
    badgerscontroller2_B.IntegralGain_f = badgerscontroller2_P.PIDController1_I *
      badgerscontroller2_B.Sum2;
  }

  if (rtmIsMajorTimeStep(badgerscontroller2_M)) {
    rt_ertODEUpdateContinuousStates(&badgerscontroller2_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++badgerscontroller2_M->Timing.clockTick0;
    badgerscontroller2_M->Timing.t[0] = rtsiGetSolverStopTime
      (&badgerscontroller2_M->solverInfo);

    {
      // Update absolute timer for sample time: [20.0s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 20.0, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      badgerscontroller2_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void badgerscontroller2_derivatives(void)
{
  XDot_badgerscontroller2_T *_rtXdot;
  _rtXdot = ((XDot_badgerscontroller2_T *) badgerscontroller2_M->derivs);

  // Derivatives for Integrator: '<S41>/Integrator'
  _rtXdot->Integrator_CSTATE = badgerscontroller2_B.IntegralGain;

  // Derivatives for Integrator: '<S36>/Filter'
  _rtXdot->Filter_CSTATE = badgerscontroller2_B.FilterCoefficient;

  // Derivatives for Integrator: '<S89>/Integrator'
  _rtXdot->Integrator_CSTATE_a = badgerscontroller2_B.IntegralGain_f;

  // Derivatives for Integrator: '<S84>/Filter'
  _rtXdot->Filter_CSTATE_o = badgerscontroller2_B.FilterCoefficient_f;
}

// Model initialize function
void badgerscontroller2_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&badgerscontroller2_M->solverInfo,
                          &badgerscontroller2_M->Timing.simTimeStep);
    rtsiSetTPtr(&badgerscontroller2_M->solverInfo, &rtmGetTPtr
                (badgerscontroller2_M));
    rtsiSetStepSizePtr(&badgerscontroller2_M->solverInfo,
                       &badgerscontroller2_M->Timing.stepSize0);
    rtsiSetdXPtr(&badgerscontroller2_M->solverInfo,
                 &badgerscontroller2_M->derivs);
    rtsiSetContStatesPtr(&badgerscontroller2_M->solverInfo, (real_T **)
                         &badgerscontroller2_M->contStates);
    rtsiSetNumContStatesPtr(&badgerscontroller2_M->solverInfo,
      &badgerscontroller2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&badgerscontroller2_M->solverInfo,
      &badgerscontroller2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&badgerscontroller2_M->solverInfo,
      &badgerscontroller2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&badgerscontroller2_M->solverInfo,
      &badgerscontroller2_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&badgerscontroller2_M->solverInfo, (&rtmGetErrorStatus
      (badgerscontroller2_M)));
    rtsiSetRTModelPtr(&badgerscontroller2_M->solverInfo, badgerscontroller2_M);
  }

  rtsiSetSimTimeStep(&badgerscontroller2_M->solverInfo, MAJOR_TIME_STEP);
  badgerscontroller2_M->intgData.y = badgerscontroller2_M->odeY;
  badgerscontroller2_M->intgData.f[0] = badgerscontroller2_M->odeF[0];
  badgerscontroller2_M->intgData.f[1] = badgerscontroller2_M->odeF[1];
  badgerscontroller2_M->intgData.f[2] = badgerscontroller2_M->odeF[2];
  badgerscontroller2_M->contStates = ((X_badgerscontroller2_T *)
    &badgerscontroller2_X);
  rtsiSetSolverData(&badgerscontroller2_M->solverInfo, static_cast<void *>
                    (&badgerscontroller2_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&badgerscontroller2_M->solverInfo, false);
  rtsiSetSolverName(&badgerscontroller2_M->solverInfo,"ode3");
  rtmSetTPtr(badgerscontroller2_M, &badgerscontroller2_M->Timing.tArray[0]);
  badgerscontroller2_M->Timing.stepSize0 = 20.0;

  {
    char_T b_zeroDelimTopic_0[17];
    char_T b_zeroDelimTopic[11];
    static const char_T tmp[10] = { '/', 'l', 'e', 'a', 'd', '_', 'd', 'i', 's',
      't' };

    static const char_T tmp_0[16] = { '/', 'c', 'a', 'r', '/', 's', 't', 'a',
      't', 'e', '/', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_1[10] = { '/', 'c', 'm', 'd', '_', 'a', 'c', 'c',
      'e', 'l' };

    // InitializeConditions for Integrator: '<S41>/Integrator'
    badgerscontroller2_X.Integrator_CSTATE =
      badgerscontroller2_P.PIDController_InitialConditio_h;

    // InitializeConditions for Integrator: '<S36>/Filter'
    badgerscontroller2_X.Filter_CSTATE =
      badgerscontroller2_P.PIDController_InitialConditionF;

    // InitializeConditions for Integrator: '<S89>/Integrator'
    badgerscontroller2_X.Integrator_CSTATE_a =
      badgerscontroller2_P.PIDController1_InitialConditi_d;

    // InitializeConditions for Integrator: '<S84>/Filter'
    badgerscontroller2_X.Filter_CSTATE_o =
      badgerscontroller2_P.PIDController1_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S7>/In1' incorporates:
    //   Outport: '<S7>/Out1'

    badgerscontroller2_B.In1 = badgerscontroller2_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    badgerscontroller2_DW.obj_k.matlabCodegenIsDeleted = false;
    badgerscontroller2_DW.obj_k.isInitialized = 1;
    for (int32_T i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[10] = '\x00';
    Sub_badgerscontroller2_47.createSubscriber(&b_zeroDelimTopic[0], 1);
    badgerscontroller2_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S6>/In1' incorporates:
    //   Outport: '<S6>/Out1'

    badgerscontroller2_B.In1_n = badgerscontroller2_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    badgerscontroller2_DW.obj_n.matlabCodegenIsDeleted = false;
    badgerscontroller2_DW.obj_n.isInitialized = 1;
    for (int32_T i = 0; i < 16; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[16] = '\x00';
    Sub_badgerscontroller2_34.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    badgerscontroller2_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S2>/SinkBlock'
    badgerscontroller2_DW.obj.matlabCodegenIsDeleted = false;
    badgerscontroller2_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = tmp_1[i];
    }

    b_zeroDelimTopic[10] = '\x00';
    Pub_badgerscontroller2_35.createPublisher(&b_zeroDelimTopic[0], 1);
    badgerscontroller2_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void badgerscontroller2_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!badgerscontroller2_DW.obj_k.matlabCodegenIsDeleted) {
    badgerscontroller2_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!badgerscontroller2_DW.obj_n.matlabCodegenIsDeleted) {
    badgerscontroller2_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S2>/SinkBlock'
  if (!badgerscontroller2_DW.obj.matlabCodegenIsDeleted) {
    badgerscontroller2_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
