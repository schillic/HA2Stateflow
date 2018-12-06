/*
 * buck_interval_flatten.c
 *
 * Code generation for model "buck_interval_flatten".
 *
 * Model version              : 1.87
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Jan 13 19:02:03 2016
 *
 * Target selection: rti1103.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "buck_interval_flatten_trc_ptr.h"
#include "buck_interval_flatten.h"
#include "buck_interval_flatten_private.h"

/* Named constants for Chart: '<S2>/buck_dcm_vs2_interval_sys_1' */
#define IN_charging_charging_controller ((uint8_T)1U)
#define IN_discharging_discharging_cont ((uint8_T)3U)
#define b_IN_dcm_discharging_controller ((uint8_T)2U)
#define buck__buckboost_template_1_a00c (-271.6981)
#define buck__buckboost_template_1_a00o (-196.2264)
#define buck__buckboost_template_1_a01c (-377.3585)
#define buck__buckboost_template_1_a01o (-377.3585)
#define buck__buckboost_template_1_a10c (454.5455)
#define buck__buckboost_template_1_a10o (454.5455)
#define buck__buckboost_template_1_a11c (-45.4545)
#define buck__buckboost_template_1_a11o (-45.4545)
#define buck_i_buckboost_template_1_b0c (377.3585)
#define buck_i_buckboost_template_1_b0o (0.0)
#define buck_i_buckboost_template_1_b1c (0.0)
#define buck_i_buckboost_template_1_b1o (0.0)
#define buck_interva_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define buck_interval_flatten_VcH      (12.1)
#define buck_interval_flatten_VcL      (11.9)

/* Block signals (auto storage) */
B_buck_interval_flatten_T buck_interval_flatten_B;

/* Continuous states */
X_buck_interval_flatten_T buck_interval_flatten_X;

/* Block states (auto storage) */
DW_buck_interval_flatten_T buck_interval_flatten_DW;

/* Real-time model */
RT_MODEL_buck_interval_flatte_T buck_interval_flatten_M_;
RT_MODEL_buck_interval_flatte_T *const buck_interval_flatten_M =
  &buck_interval_flatten_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  buck_interval_flatten_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  buck_interval_flatten_output();
  buck_interval_flatten_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  buck_interval_flatten_output();
  buck_interval_flatten_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  buck_interval_flatten_output();
  buck_interval_flatten_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void buck_interval_flatten_output(void)
{
  boolean_T out;
  boolean_T stateChanged;
  if (rtmIsMajorTimeStep(buck_interval_flatten_M)) {
    /* set solver stop time */
    if (!(buck_interval_flatten_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&buck_interval_flatten_M->solverInfo,
                            ((buck_interval_flatten_M->Timing.clockTickH0 + 1) *
        buck_interval_flatten_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&buck_interval_flatten_M->solverInfo,
                            ((buck_interval_flatten_M->Timing.clockTick0 + 1) *
        buck_interval_flatten_M->Timing.stepSize0 +
        buck_interval_flatten_M->Timing.clockTickH0 *
        buck_interval_flatten_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(buck_interval_flatten_M)) {
    buck_interval_flatten_M->Timing.t[0] = rtsiGetT
      (&buck_interval_flatten_M->solverInfo);
  }

  /* Chart: '<S2>/buck_dcm_vs2_interval_sys_1' */
  if (rtmIsMajorTimeStep(buck_interval_flatten_M) != 0) {
    buck_interval_flatten_DW.lastMajorTime = buck_interval_flatten_M->Timing.t[0];
    stateChanged = false;

    /* Gateway: Source_1/buck_dcm_vs2_interval_sys_1 */
    /* During: Source_1/buck_dcm_vs2_interval_sys_1 */
    if (buck_interval_flatten_DW.is_active_c1_buck_interval_flat == 0U) {
      /* Entry: Source_1/buck_dcm_vs2_interval_sys_1 */
      buck_interval_flatten_DW.is_active_c1_buck_interval_flat = 1U;

      /* Entry Internal: Source_1/buck_dcm_vs2_interval_sys_1 */
      /* Transition: '<S6>:21' */
      buck_interval_flatten_X.SFunction_CSTATE[0] = 0.0;
      buck_interval_flatten_X.SFunction_CSTATE[2] = 0.0;
      buck_interval_flatten_X.SFunction_CSTATE[1] = 0.0;
      buck_interval_flatten_X.SFunction_CSTATE[3] = 2.0;
      stateChanged = true;
      buck_interval_flatten_DW.is_c1_buck_interval_flatten =
        IN_charging_charging_controller;
    } else {
      switch (buck_interval_flatten_DW.is_c1_buck_interval_flatten) {
       case IN_charging_charging_controller:
        /* During 'charging_charging_controller': '<S6>:20' */
        if (buck_interval_flatten_X.SFunction_CSTATE[2] >=
            buck_interval_flatten_VcH) {
          /* Transition: '<S6>:24' */
          buck_interval_flatten_X.SFunction_CSTATE[3] = 1.0;
          stateChanged = true;
          buck_interval_flatten_DW.is_c1_buck_interval_flatten =
            IN_discharging_discharging_cont;
        }
        break;

       case b_IN_dcm_discharging_controller:
        /* During 'dcm_discharging_controller': '<S6>:23' */
        if (buck_interval_flatten_X.SFunction_CSTATE[2] <=
            buck_interval_flatten_VcL) {
          /* Transition: '<S6>:27' */
          buck_interval_flatten_X.SFunction_CSTATE[3] = 2.0;
          stateChanged = true;
          buck_interval_flatten_DW.is_c1_buck_interval_flatten =
            IN_charging_charging_controller;
        }
        break;

       default:
        /* During 'discharging_discharging_controller': '<S6>:22' */
        if (buck_interval_flatten_X.SFunction_CSTATE[2] <=
            buck_interval_flatten_VcL) {
          /* Transition: '<S6>:25' */
          buck_interval_flatten_X.SFunction_CSTATE[3] = 2.0;
          stateChanged = true;
          buck_interval_flatten_DW.is_c1_buck_interval_flatten =
            IN_charging_charging_controller;
        } else {
          out = ((buck_interval_flatten_X.SFunction_CSTATE[0] <= 0.0) &&
                 (buck_interval_flatten_X.SFunction_CSTATE[2] >
                  buck_interval_flatten_VcL));
          if (out) {
            /* Transition: '<S6>:26' */
            stateChanged = true;
            buck_interval_flatten_DW.is_c1_buck_interval_flatten =
              b_IN_dcm_discharging_controller;
          }
        }
        break;
      }
    }

    if (stateChanged) {
      rtsiSetSolverNeedsReset(&buck_interval_flatten_M->solverInfo, true);
    }
  }

  switch (buck_interval_flatten_DW.is_c1_buck_interval_flatten) {
   case IN_charging_charging_controller:
    /* During 'charging_charging_controller': '<S6>:20' */
    buck_interval_flatten_B.il_out = buck_interval_flatten_X.SFunction_CSTATE[0];
    buck_interval_flatten_B.t_out = buck_interval_flatten_X.SFunction_CSTATE[1];
    buck_interval_flatten_B.vc_out = buck_interval_flatten_X.SFunction_CSTATE[2];
    buck_interval_flatten_B.mode_out_out =
      buck_interval_flatten_X.SFunction_CSTATE[3];
    buck_interval_flatten_B.buck_dcm_vs2_interval_sys_1_loc = 1.0;
    break;

   case b_IN_dcm_discharging_controller:
    /* During 'dcm_discharging_controller': '<S6>:23' */
    buck_interval_flatten_B.il_out = buck_interval_flatten_X.SFunction_CSTATE[0];
    buck_interval_flatten_B.t_out = buck_interval_flatten_X.SFunction_CSTATE[1];
    buck_interval_flatten_B.vc_out = buck_interval_flatten_X.SFunction_CSTATE[2];
    buck_interval_flatten_B.mode_out_out =
      buck_interval_flatten_X.SFunction_CSTATE[3];
    buck_interval_flatten_B.buck_dcm_vs2_interval_sys_1_loc = 3.0;
    break;

   default:
    /* During 'discharging_discharging_controller': '<S6>:22' */
    /* '<S6>:22:3' */
    /* '<S6>:22:4' */
    /* '<S6>:22:5' */
    /* '<S6>:22:6' */
    /* '<S6>:22:7' */
    buck_interval_flatten_B.il_out = buck_interval_flatten_X.SFunction_CSTATE[0];

    /* '<S6>:22:8' */
    buck_interval_flatten_B.t_out = buck_interval_flatten_X.SFunction_CSTATE[1];

    /* '<S6>:22:9' */
    buck_interval_flatten_B.vc_out = buck_interval_flatten_X.SFunction_CSTATE[2];

    /* '<S6>:22:10' */
    buck_interval_flatten_B.mode_out_out =
      buck_interval_flatten_X.SFunction_CSTATE[3];

    /* '<S6>:22:11' */
    buck_interval_flatten_B.buck_dcm_vs2_interval_sys_1_loc = 2.0;
    break;
  }

  /* End of Chart: '<S2>/buck_dcm_vs2_interval_sys_1' */
}

/* Model update function */
void buck_interval_flatten_update(void)
{
  if (rtmIsMajorTimeStep(buck_interval_flatten_M)) {
    rt_ertODEUpdateContinuousStates(&buck_interval_flatten_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++buck_interval_flatten_M->Timing.clockTick0)) {
    ++buck_interval_flatten_M->Timing.clockTickH0;
  }

  buck_interval_flatten_M->Timing.t[0] = rtsiGetSolverStopTime
    (&buck_interval_flatten_M->solverInfo);

  {
    /* Update absolute timer for sample time: [2.0E-5s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++buck_interval_flatten_M->Timing.clockTick1)) {
      ++buck_interval_flatten_M->Timing.clockTickH1;
    }

    buck_interval_flatten_M->Timing.t[1] =
      buck_interval_flatten_M->Timing.clockTick1 *
      buck_interval_flatten_M->Timing.stepSize1 +
      buck_interval_flatten_M->Timing.clockTickH1 *
      buck_interval_flatten_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void buck_interval_flatten_derivatives(void)
{
  XDot_buck_interval_flatten_T *_rtXdot;
  _rtXdot = ((XDot_buck_interval_flatten_T *)
             buck_interval_flatten_M->ModelData.derivs);

  /* Derivatives for Chart: '<S2>/buck_dcm_vs2_interval_sys_1' incorporates:
   *  Constant: '<S2>/Constant'
   */
  _rtXdot->SFunction_CSTATE[0] = 0.0;
  _rtXdot->SFunction_CSTATE[1] = 0.0;
  _rtXdot->SFunction_CSTATE[2] = 0.0;
  _rtXdot->SFunction_CSTATE[3] = 0.0;
  switch (buck_interval_flatten_DW.is_c1_buck_interval_flatten) {
   case IN_charging_charging_controller:
    /* During 'charging_charging_controller': '<S6>:20' */
    _rtXdot->SFunction_CSTATE[0] = ((((buck__buckboost_template_1_a00c *
      buck_interval_flatten_X.SFunction_CSTATE[0] + 0.0) +
      buck__buckboost_template_1_a01c *
      buck_interval_flatten_X.SFunction_CSTATE[2]) + 0.0) +
      buck_i_buckboost_template_1_b0c * buck_interval_flatten_P.Constant_Value)
      + 0.0;
    _rtXdot->SFunction_CSTATE[2] = (((buck__buckboost_template_1_a10c *
      buck_interval_flatten_X.SFunction_CSTATE[0] + 0.0) +
      buck__buckboost_template_1_a11c *
      buck_interval_flatten_X.SFunction_CSTATE[2]) + 0.0) +
      buck_i_buckboost_template_1_b1c * buck_interval_flatten_P.Constant_Value;
    _rtXdot->SFunction_CSTATE[1] = 1.0;
    _rtXdot->SFunction_CSTATE[3] = 0.0;
    break;

   case b_IN_dcm_discharging_controller:
    /* During 'dcm_discharging_controller': '<S6>:23' */
    _rtXdot->SFunction_CSTATE[0] = 0.0;
    _rtXdot->SFunction_CSTATE[2] = (buck__buckboost_template_1_a11o *
      buck_interval_flatten_X.SFunction_CSTATE[2] + 0.0) +
      buck_i_buckboost_template_1_b1o * buck_interval_flatten_P.Constant_Value;
    _rtXdot->SFunction_CSTATE[1] = 1.0;
    _rtXdot->SFunction_CSTATE[3] = 0.0;
    break;

   default:
    /* During 'discharging_discharging_controller': '<S6>:22' */
    /* '<S6>:22:3' */
    _rtXdot->SFunction_CSTATE[0] = (((buck__buckboost_template_1_a00o *
      buck_interval_flatten_X.SFunction_CSTATE[0] + 0.0) +
      buck__buckboost_template_1_a01o *
      buck_interval_flatten_X.SFunction_CSTATE[2]) + 0.0) +
      buck_i_buckboost_template_1_b0o * buck_interval_flatten_P.Constant_Value;

    /* '<S6>:22:4' */
    _rtXdot->SFunction_CSTATE[2] = (((buck__buckboost_template_1_a10o *
      buck_interval_flatten_X.SFunction_CSTATE[0] + 0.0) +
      buck__buckboost_template_1_a11o *
      buck_interval_flatten_X.SFunction_CSTATE[2]) + 0.0) +
      buck_i_buckboost_template_1_b1o * buck_interval_flatten_P.Constant_Value;

    /* '<S6>:22:5' */
    _rtXdot->SFunction_CSTATE[1] = 1.0;

    /* '<S6>:22:6' */
    _rtXdot->SFunction_CSTATE[3] = 0.0;

    /* '<S6>:22:7' */
    /* '<S6>:22:8' */
    /* '<S6>:22:9' */
    /* '<S6>:22:10' */
    /* '<S6>:22:11' */
    break;
  }

  /* End of Derivatives for Chart: '<S2>/buck_dcm_vs2_interval_sys_1' */
}

/* Model initialize function */
void buck_interval_flatten_initialize(void)
{
  /* InitializeConditions for Chart: '<S2>/buck_dcm_vs2_interval_sys_1' */
  buck_interval_flatten_DW.is_active_c1_buck_interval_flat = 0U;
  buck_interval_flatten_DW.is_c1_buck_interval_flatten =
    buck_interva_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void buck_interval_flatten_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  buck_interval_flatten_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  buck_interval_flatten_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  buck_interval_flatten_initialize();
}

void MdlTerminate(void)
{
  buck_interval_flatten_terminate();
}

/* Registration function */
RT_MODEL_buck_interval_flatte_T *buck_interval_flatten(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)buck_interval_flatten_M, 0,
                sizeof(RT_MODEL_buck_interval_flatte_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&buck_interval_flatten_M->solverInfo,
                          &buck_interval_flatten_M->Timing.simTimeStep);
    rtsiSetTPtr(&buck_interval_flatten_M->solverInfo, &rtmGetTPtr
                (buck_interval_flatten_M));
    rtsiSetStepSizePtr(&buck_interval_flatten_M->solverInfo,
                       &buck_interval_flatten_M->Timing.stepSize0);
    rtsiSetdXPtr(&buck_interval_flatten_M->solverInfo,
                 &buck_interval_flatten_M->ModelData.derivs);
    rtsiSetContStatesPtr(&buck_interval_flatten_M->solverInfo, (real_T **)
                         &buck_interval_flatten_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&buck_interval_flatten_M->solverInfo,
      &buck_interval_flatten_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&buck_interval_flatten_M->solverInfo,
                          (&rtmGetErrorStatus(buck_interval_flatten_M)));
    rtsiSetRTModelPtr(&buck_interval_flatten_M->solverInfo,
                      buck_interval_flatten_M);
  }

  rtsiSetSimTimeStep(&buck_interval_flatten_M->solverInfo, MAJOR_TIME_STEP);
  buck_interval_flatten_M->ModelData.intgData.y =
    buck_interval_flatten_M->ModelData.odeY;
  buck_interval_flatten_M->ModelData.intgData.f[0] =
    buck_interval_flatten_M->ModelData.odeF[0];
  buck_interval_flatten_M->ModelData.intgData.f[1] =
    buck_interval_flatten_M->ModelData.odeF[1];
  buck_interval_flatten_M->ModelData.intgData.f[2] =
    buck_interval_flatten_M->ModelData.odeF[2];
  buck_interval_flatten_M->ModelData.intgData.f[3] =
    buck_interval_flatten_M->ModelData.odeF[3];
  buck_interval_flatten_M->ModelData.contStates = ((real_T *)
    &buck_interval_flatten_X);
  rtsiSetSolverData(&buck_interval_flatten_M->solverInfo, (void *)
                    &buck_interval_flatten_M->ModelData.intgData);
  rtsiSetSolverName(&buck_interval_flatten_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = buck_interval_flatten_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    buck_interval_flatten_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    buck_interval_flatten_M->Timing.sampleTimes =
      (&buck_interval_flatten_M->Timing.sampleTimesArray[0]);
    buck_interval_flatten_M->Timing.offsetTimes =
      (&buck_interval_flatten_M->Timing.offsetTimesArray[0]);

    /* task periods */
    buck_interval_flatten_M->Timing.sampleTimes[0] = (0.0);
    buck_interval_flatten_M->Timing.sampleTimes[1] = (2.0E-5);

    /* task offsets */
    buck_interval_flatten_M->Timing.offsetTimes[0] = (0.0);
    buck_interval_flatten_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(buck_interval_flatten_M, &buck_interval_flatten_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = buck_interval_flatten_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    buck_interval_flatten_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(buck_interval_flatten_M, -1);
  buck_interval_flatten_M->Timing.stepSize0 = 2.0E-5;
  buck_interval_flatten_M->Timing.stepSize1 = 2.0E-5;
  buck_interval_flatten_M->solverInfoPtr = (&buck_interval_flatten_M->solverInfo);
  buck_interval_flatten_M->Timing.stepSize = (2.0E-5);
  rtsiSetFixedStepSize(&buck_interval_flatten_M->solverInfo, 2.0E-5);
  rtsiSetSolverMode(&buck_interval_flatten_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  buck_interval_flatten_M->ModelData.blockIO = ((void *)
    &buck_interval_flatten_B);
  (void) memset(((void *) &buck_interval_flatten_B), 0,
                sizeof(B_buck_interval_flatten_T));

  /* parameters */
  buck_interval_flatten_M->ModelData.defaultParam = ((real_T *)
    &buck_interval_flatten_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &buck_interval_flatten_X;
    buck_interval_flatten_M->ModelData.contStates = (x);
    (void) memset((void *)&buck_interval_flatten_X, 0,
                  sizeof(X_buck_interval_flatten_T));
  }

  /* states (dwork) */
  buck_interval_flatten_M->ModelData.dwork = ((void *) &buck_interval_flatten_DW);
  (void) memset((void *)&buck_interval_flatten_DW, 0,
                sizeof(DW_buck_interval_flatten_T));

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }

  /* Initialize Sizes */
  buck_interval_flatten_M->Sizes.numContStates = (4);/* Number of continuous states */
  buck_interval_flatten_M->Sizes.numY = (0);/* Number of model outputs */
  buck_interval_flatten_M->Sizes.numU = (0);/* Number of model inputs */
  buck_interval_flatten_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  buck_interval_flatten_M->Sizes.numSampTimes = (2);/* Number of sample times */
  buck_interval_flatten_M->Sizes.numBlocks = (3);/* Number of blocks */
  buck_interval_flatten_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  buck_interval_flatten_M->Sizes.numBlockPrms = (1);/* Sum of parameter "widths" */
  return buck_interval_flatten_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
