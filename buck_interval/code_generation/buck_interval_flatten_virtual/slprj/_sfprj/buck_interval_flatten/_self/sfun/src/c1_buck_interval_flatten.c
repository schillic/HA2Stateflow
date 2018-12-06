/* Include files */

#include <stddef.h>
#include "blas.h"
#include "buck_interval_flatten_sfun.h"
#include "c1_buck_interval_flatten.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "buck_interval_flatten_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_charging_charging_controller ((uint8_T)1U)
#define c1_IN_dcm_discharging_controller ((uint8_T)2U)
#define c1_IN_discharging_discharging_controller ((uint8_T)3U)
#define c1_const_VcH                   (12.1)
#define c1_const_buckboost_template_1_a11o (-45.4545)
#define c1_const_tmax                  (0.0375)
#define c1_const_buckboost_template_1_a01o (-377.3585)
#define c1_const_VcL                   (11.9)
#define c1_const_buckboost_template_1_a10o (454.5455)
#define c1_const_buckboost_template_1_a00o (-196.2264)
#define c1_const_buckboost_template_1_b1o (0.0)
#define c1_const_buckboost_template_1_b0o (0.0)
#define c1_const_buckboost_template_1_a11c (-45.4545)
#define c1_const_buckboost_template_1_b0c (377.3585)
#define c1_const_buckboost_template_1_a10c (454.5455)
#define c1_const_buckboost_template_1_b1c (0.0)
#define c1_const_buckboost_template_1_bounds (1000.0)
#define c1_const_buckboost_template_1_a01c (-377.3585)
#define c1_const_buckboost_template_1_a00c (-271.6981)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c1_dataWrittenToVector[9];

/* Function Declarations */
static void initialize_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static void initialize_params_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static void enable_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static void disable_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static void set_sim_state_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static void finalize_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static void sf_gateway_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static void zeroCrossings_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static void derivatives_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static void outputs_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static void initSimStructsc1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static void c1_eml_ini_fcn_to_be_inlined_206
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static void c1_eml_term_fcn_to_be_inlined_206
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_emlrt_marshallOut
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, const real_T c1_u);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance, const mxArray *c1_nargout, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_emlrt_marshallOut
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, const boolean_T c1_u);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_c_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct *
  chartInstance, const mxArray *c1_sf_internal_predicateOutput, const char_T
  *c1_identifier);
static boolean_T c1_d_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_emlrt_marshallOut
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, const int32_T c1_u);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_e_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance, const mxArray *c1_b_sfEvent, const char_T *c1_identifier);
static int32_T c1_f_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_emlrt_marshallOut
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, const uint8_T c1_u);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_g_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_charging_charging_controller, const
  char_T *c1_identifier);
static uint8_T c1_h_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_emlrt_marshallOut
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance);
static void c1_i_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance, const mxArray *c1_u);
static const mxArray *c1_j_emlrt_marshallIn
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, const mxArray
   *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier);
static const mxArray *c1_k_emlrt_marshallIn
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, const mxArray *c1_u,
   const emlrtMsgIdentifier *c1_parentId);
static void c1_updateDataWrittenToVector
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, uint32_T
   c1_vectorIndex);
static void c1_errorIfDataNotWrittenToFcn
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, uint32_T
   c1_vectorIndex, uint32_T c1_dataNumber);
static void init_dsm_address_info(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_tp_charging_charging_controller = 0U;
  chartInstance->c1_tp_dcm_discharging_controller = 0U;
  chartInstance->c1_tp_discharging_discharging_controller = 0U;
  chartInstance->c1_is_active_c1_buck_interval_flatten = 0U;
  chartInstance->c1_is_c1_buck_interval_flatten = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_VcH = 12.1;
  chartInstance->c1_buckboost_template_1_a11o = -45.4545;
  chartInstance->c1_tmax = 0.0375;
  chartInstance->c1_buckboost_template_1_a01o = -377.3585;
  chartInstance->c1_VcL = 11.9;
  chartInstance->c1_buckboost_template_1_a10o = 454.5455;
  chartInstance->c1_buckboost_template_1_a00o = -196.2264;
  chartInstance->c1_buckboost_template_1_b1o = 0.0;
  chartInstance->c1_buckboost_template_1_b0o = 0.0;
  chartInstance->c1_buckboost_template_1_a11c = -45.4545;
  chartInstance->c1_buckboost_template_1_b0c = 377.3585;
  chartInstance->c1_buckboost_template_1_a10c = 454.5455;
  chartInstance->c1_buckboost_template_1_b1c = 0.0;
  chartInstance->c1_buckboost_template_1_bounds = 1000.0;
  chartInstance->c1_buckboost_template_1_a01c = -377.3585;
  chartInstance->c1_buckboost_template_1_a00c = -271.6981;
}

static void initialize_params_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_buck_interval_flatten == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_buck_interval_flatten ==
      c1_IN_charging_charging_controller) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_buck_interval_flatten ==
      c1_IN_discharging_discharging_controller) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_buck_interval_flatten ==
      c1_IN_dcm_discharging_controller) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  const mxArray *c1_st = NULL;
  c1_st = NULL;
  sf_mex_assign(&c1_st, c1_e_emlrt_marshallOut(chartInstance), false);
  return c1_st;
}

static void set_sim_state_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, const mxArray *c1_st)
{
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_st));
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_buck_interval_flatten(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_c1_buck_interval_flatten ==
        c1_IN_charging_charging_controller) {
      chartInstance->c1_tp_charging_charging_controller = 1U;
    } else {
      chartInstance->c1_tp_charging_charging_controller = 0U;
    }

    if (chartInstance->c1_is_c1_buck_interval_flatten ==
        c1_IN_dcm_discharging_controller) {
      chartInstance->c1_tp_dcm_discharging_controller = 1U;
    } else {
      chartInstance->c1_tp_dcm_discharging_controller = 0U;
    }

    if (chartInstance->c1_is_c1_buck_interval_flatten ==
        c1_IN_discharging_discharging_controller) {
      chartInstance->c1_tp_discharging_discharging_controller = 1U;
    } else {
      chartInstance->c1_tp_discharging_discharging_controller = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  uint32_T c1_b_debug_family_var_map[3];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 0.0;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 0.0;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 0.0;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 0.0;
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 0.0;
  real_T *c1_il_out;
  real_T *c1_il;
  real_T *c1_t_out;
  real_T *c1_t;
  real_T *c1_vc_out;
  real_T *c1_vc;
  real_T *c1_mode_out_out;
  real_T *c1_mode_out;
  real_T *c1_rci1;
  real_T *c1_rcv1;
  real_T *c1_rci2;
  real_T *c1_rb1;
  real_T *c1_rcv2;
  real_T *c1_roi1;
  real_T *c1_rov1;
  real_T *c1_roi2;
  real_T *c1_rov2;
  real_T *c1_rdv2;
  real_T *c1_buck_dcm_vs2_interval_sys_1_location;
  real_T *c1_Vs;
  boolean_T guard1 = false;
  c1_Vs = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c1_buck_dcm_vs2_interval_sys_1_location = (real_T *)ssGetOutputPortSignal
    (chartInstance->S, 5);
  c1_rdv2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_rov2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_roi2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_rov1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_roi1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_rcv2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_rb1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_rci2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_rcv1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_rci1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_mode_out = (real_T *)(ssGetContStates(chartInstance->S) + 3);
  c1_mode_out_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_vc = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_vc_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_t = (real_T *)(ssGetContStates(chartInstance->S) + 1);
  c1_t_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_il = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  c1_il_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_set_sim_state_side_effects_c1_buck_interval_flatten(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (ssIsMajorTimeStep(chartInstance->S) != 0) {
    chartInstance->c1_lastMajorTime = _sfTime_;
    chartInstance->c1_stateChanged = false;
    _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_DATA_RANGE_CHECK(*c1_il_out, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_il, 1U);
    _SFD_DATA_RANGE_CHECK(*c1_t_out, 2U);
    _SFD_DATA_RANGE_CHECK(*c1_t, 3U);
    _SFD_DATA_RANGE_CHECK(*c1_vc_out, 4U);
    _SFD_DATA_RANGE_CHECK(*c1_vc, 5U);
    _SFD_DATA_RANGE_CHECK(*c1_mode_out_out, 6U);
    _SFD_DATA_RANGE_CHECK(*c1_mode_out, 7U);
    _SFD_DATA_RANGE_CHECK(*c1_rci1, 8U);
    _SFD_DATA_RANGE_CHECK(*c1_rcv1, 9U);
    _SFD_DATA_RANGE_CHECK(*c1_rci2, 10U);
    _SFD_DATA_RANGE_CHECK(*c1_rb1, 11U);
    _SFD_DATA_RANGE_CHECK(*c1_rcv2, 12U);
    _SFD_DATA_RANGE_CHECK(*c1_roi1, 13U);
    _SFD_DATA_RANGE_CHECK(*c1_rov1, 14U);
    _SFD_DATA_RANGE_CHECK(*c1_roi2, 15U);
    _SFD_DATA_RANGE_CHECK(*c1_rov2, 16U);
    _SFD_DATA_RANGE_CHECK(*c1_rdv2, 17U);
    _SFD_DATA_RANGE_CHECK(*c1_buck_dcm_vs2_interval_sys_1_location, 18U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_VcH, 19U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_buckboost_template_1_a11o, 20U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_tmax, 21U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_buckboost_template_1_a01o, 22U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_VcL, 23U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_buckboost_template_1_a10o, 24U);
    _SFD_DATA_RANGE_CHECK(*c1_Vs, 25U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_buckboost_template_1_a00o, 26U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_buckboost_template_1_b1o, 27U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_buckboost_template_1_b0o, 28U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_buckboost_template_1_a11c, 29U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_buckboost_template_1_b0c, 30U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_buckboost_template_1_a10c, 31U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_buckboost_template_1_b1c, 32U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_buckboost_template_1_bounds, 33U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_buckboost_template_1_a01c, 34U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_buckboost_template_1_a00c, 35U);
    chartInstance->c1_sfEvent = CALL_EVENT;
    _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_active_c1_buck_interval_flatten == 0U) {
      _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
      chartInstance->c1_stateChanged = true;
      chartInstance->c1_is_active_c1_buck_interval_flatten = 1U;
      _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_g_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      *c1_il = 0.0;
      c1_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_DATA_RANGE_CHECK(*c1_il, 1U);
      *c1_vc = 0.0;
      c1_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_DATA_RANGE_CHECK(*c1_vc, 5U);
      *c1_t = 0.0;
      c1_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(*c1_t, 3U);
      *c1_mode_out = 2.0;
      c1_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_DATA_RANGE_CHECK(*c1_mode_out, 7U);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c1_stateChanged = true;
      chartInstance->c1_is_c1_buck_interval_flatten =
        c1_IN_charging_charging_controller;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_charging_charging_controller = 1U;
    } else {
      switch (chartInstance->c1_is_c1_buck_interval_flatten) {
       case c1_IN_charging_charging_controller:
        CV_CHART_EVAL(0, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_d_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
        c1_out = CV_EML_IF(1, 0, 0, *c1_vc >= c1_const_VcH);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_e_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          *c1_mode_out = 1.0;
          c1_updateDataWrittenToVector(chartInstance, 7U);
          _SFD_DATA_RANGE_CHECK(*c1_mode_out, 7U);
          _SFD_SYMBOL_SCOPE_POP();
          chartInstance->c1_tp_charging_charging_controller = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
          chartInstance->c1_stateChanged = true;
          chartInstance->c1_is_c1_buck_interval_flatten =
            c1_IN_discharging_discharging_controller;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_discharging_discharging_controller = 1U;
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
        }
        break;

       case c1_IN_dcm_discharging_controller:
        CV_CHART_EVAL(0, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_j_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
        c1_b_out = CV_EML_IF(4, 0, 0, *c1_vc <= c1_const_VcL);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_k_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          *c1_mode_out = 2.0;
          c1_updateDataWrittenToVector(chartInstance, 7U);
          _SFD_DATA_RANGE_CHECK(*c1_mode_out, 7U);
          _SFD_SYMBOL_SCOPE_POP();
          chartInstance->c1_tp_dcm_discharging_controller = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
          chartInstance->c1_stateChanged = true;
          chartInstance->c1_is_c1_buck_interval_flatten =
            c1_IN_charging_charging_controller;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_charging_charging_controller = 1U;
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
        }
        break;

       case c1_IN_discharging_discharging_controller:
        CV_CHART_EVAL(0, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_h_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
        c1_c_out = CV_EML_IF(2, 0, 0, *c1_vc <= c1_const_VcL);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_i_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          *c1_mode_out = 2.0;
          c1_updateDataWrittenToVector(chartInstance, 7U);
          _SFD_DATA_RANGE_CHECK(*c1_mode_out, 7U);
          _SFD_SYMBOL_SCOPE_POP();
          chartInstance->c1_tp_discharging_discharging_controller = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
          chartInstance->c1_stateChanged = true;
          chartInstance->c1_is_c1_buck_interval_flatten =
            c1_IN_charging_charging_controller;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_charging_charging_controller = 1U;
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                       chartInstance->c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_f_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
          guard1 = false;
          if (CV_EML_COND(3, 0, 0, *c1_il <= 0.0)) {
            if (CV_EML_COND(3, 0, 1, *c1_vc > c1_const_VcL)) {
              CV_EML_MCDC(3, 0, 0, true);
              CV_EML_IF(3, 0, 0, true);
              c1_d_out = true;
            } else {
              guard1 = true;
            }
          } else {
            c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
            guard1 = true;
          }

          if (guard1 == true) {
            CV_EML_MCDC(3, 0, 0, false);
            CV_EML_IF(3, 0, 0, false);
            c1_d_out = false;
          }

          _SFD_SYMBOL_SCOPE_POP();
          if (c1_d_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_discharging_discharging_controller = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
            chartInstance->c1_stateChanged = true;
            chartInstance->c1_is_c1_buck_interval_flatten =
              c1_IN_dcm_discharging_controller;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_dcm_discharging_controller = 1U;
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
          }
        }
        break;

       default:
        CV_CHART_EVAL(0, 0, 0);
        chartInstance->c1_is_c1_buck_interval_flatten = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        break;
      }
    }

    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_stateChanged) {
      ssSetSolverNeedsReset(chartInstance->S);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  switch (chartInstance->c1_is_c1_buck_interval_flatten) {
   case c1_IN_charging_charging_controller:
    CV_CHART_EVAL(0, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    *c1_il_out = *c1_il;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_il_out, 0U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 3U, 3U);
    *c1_t_out = *c1_t;
    c1_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c1_t_out, 2U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    *c1_vc_out = *c1_vc;
    c1_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(*c1_vc_out, 4U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U);
    *c1_mode_out_out = *c1_mode_out;
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(*c1_mode_out_out, 6U);
    *c1_buck_dcm_vs2_interval_sys_1_location = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_DATA_RANGE_CHECK(*c1_buck_dcm_vs2_interval_sys_1_location, 18U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_dcm_discharging_controller:
    CV_CHART_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_c_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    *c1_il_out = *c1_il;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_il_out, 0U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 3U, 3U);
    *c1_t_out = *c1_t;
    c1_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c1_t_out, 2U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    *c1_vc_out = *c1_vc;
    c1_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(*c1_vc_out, 4U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U);
    *c1_mode_out_out = *c1_mode_out;
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(*c1_mode_out_out, 6U);
    *c1_buck_dcm_vs2_interval_sys_1_location = 3.0;
    c1_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_DATA_RANGE_CHECK(*c1_buck_dcm_vs2_interval_sys_1_location, 18U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_discharging_discharging_controller:
    CV_CHART_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_b_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    CV_SCRIPT_FCN(0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 1);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 1);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 1);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    *c1_il_out = *c1_il;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 2);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 3U, 3U);
    *c1_t_out = *c1_t;
    c1_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 2);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    *c1_vc_out = *c1_vc;
    c1_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 2);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U);
    *c1_mode_out_out = *c1_mode_out;
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 2);
    *c1_buck_dcm_vs2_interval_sys_1_location = 2.0;
    c1_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -2);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);
    break;
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_buck_interval_flattenMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void zeroCrossings_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_d_out;
  real_T *c1_zcVar;
  real_T *c1_vc;
  real_T *c1_il;
  boolean_T guard1 = false;
  c1_vc = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_il = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  c1_zcVar = (real_T *)(ssGetNonsampledZCs(chartInstance->S) + 0);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c1_lastMajorTime == _sfTime_) {
    *c1_zcVar = -1.0;
  } else {
    chartInstance->c1_stateChanged = false;
    if (chartInstance->c1_is_active_c1_buck_interval_flatten == 0U) {
      chartInstance->c1_stateChanged = true;
    } else {
      switch (chartInstance->c1_is_c1_buck_interval_flatten) {
       case c1_IN_charging_charging_controller:
        CV_CHART_EVAL(0, 0, 1);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_d_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
        c1_out = CV_EML_IF(1, 0, 0, *c1_vc >= c1_const_VcH);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_out) {
          chartInstance->c1_stateChanged = true;
        }
        break;

       case c1_IN_dcm_discharging_controller:
        CV_CHART_EVAL(0, 0, 2);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_j_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
        c1_b_out = CV_EML_IF(4, 0, 0, *c1_vc <= c1_const_VcL);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_b_out) {
          chartInstance->c1_stateChanged = true;
        }
        break;

       case c1_IN_discharging_discharging_controller:
        CV_CHART_EVAL(0, 0, 3);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_h_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
        c1_c_out = CV_EML_IF(2, 0, 0, *c1_vc <= c1_const_VcL);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_c_out) {
          chartInstance->c1_stateChanged = true;
        } else {
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_f_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
          guard1 = false;
          if (CV_EML_COND(3, 0, 0, *c1_il <= 0.0)) {
            if (CV_EML_COND(3, 0, 1, *c1_vc > c1_const_VcL)) {
              CV_EML_MCDC(3, 0, 0, true);
              CV_EML_IF(3, 0, 0, true);
              c1_d_out = true;
            } else {
              guard1 = true;
            }
          } else {
            c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
            guard1 = true;
          }

          if (guard1 == true) {
            CV_EML_MCDC(3, 0, 0, false);
            CV_EML_IF(3, 0, 0, false);
            c1_d_out = false;
          }

          _SFD_SYMBOL_SCOPE_POP();
          if (c1_d_out) {
            chartInstance->c1_stateChanged = true;
          }
        }
        break;

       default:
        CV_CHART_EVAL(0, 0, 0);
        chartInstance->c1_is_c1_buck_interval_flatten = c1_IN_NO_ACTIVE_CHILD;
        break;
      }
    }

    if (chartInstance->c1_stateChanged) {
      *c1_zcVar = 1.0;
    } else {
      *c1_zcVar = -1.0;
    }
  }
}

static void derivatives_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  real_T *c1_il_dot;
  real_T *c1_t_dot;
  real_T *c1_vc_dot;
  real_T *c1_mode_out_dot;
  real_T *c1_il;
  real_T *c1_rci1;
  real_T *c1_vc;
  real_T *c1_rcv1;
  real_T *c1_Vs;
  real_T *c1_rb1;
  real_T *c1_rci2;
  real_T *c1_rcv2;
  real_T *c1_il_out;
  real_T *c1_t_out;
  real_T *c1_vc_out;
  real_T *c1_mode_out_out;
  real_T *c1_buck_dcm_vs2_interval_sys_1_location;
  real_T *c1_rdv2;
  real_T *c1_roi1;
  real_T *c1_rov1;
  real_T *c1_roi2;
  real_T *c1_rov2;
  c1_Vs = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c1_buck_dcm_vs2_interval_sys_1_location = (real_T *)ssGetOutputPortSignal
    (chartInstance->S, 5);
  c1_rdv2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_rov2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_roi2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_rov1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_roi1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_rcv2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_rb1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_rci2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_rcv1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_rci1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_mode_out_dot = (real_T *)(ssGetdX(chartInstance->S) + 3);
  c1_mode_out_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_vc_dot = (real_T *)(ssGetdX(chartInstance->S) + 2);
  c1_vc = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_vc_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_t_dot = (real_T *)(ssGetdX(chartInstance->S) + 1);
  c1_t_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_il_dot = (real_T *)(ssGetdX(chartInstance->S) + 0);
  c1_il = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  c1_il_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  *c1_il_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_il_dot, 1U);
  *c1_t_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_t_dot, 3U);
  *c1_vc_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_vc_dot, 5U);
  *c1_mode_out_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_mode_out_dot, 7U);
  _sfTime_ = sf_get_time(chartInstance->S);
  switch (chartInstance->c1_is_c1_buck_interval_flatten) {
   case c1_IN_charging_charging_controller:
    CV_CHART_EVAL(0, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    *c1_il_dot = ((((c1_const_buckboost_template_1_a00c * *c1_il + *c1_rci1) +
                    c1_const_buckboost_template_1_a01c * *c1_vc) + *c1_rcv1) +
                  c1_const_buckboost_template_1_b0c * *c1_Vs) + *c1_rb1;
    _SFD_DATA_RANGE_CHECK(*c1_il_dot, 1U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    *c1_vc_dot = (((c1_const_buckboost_template_1_a10c * *c1_il + *c1_rci2) +
                   c1_const_buckboost_template_1_a11c * *c1_vc) + *c1_rcv2) +
      c1_const_buckboost_template_1_b1c * *c1_Vs;
    _SFD_DATA_RANGE_CHECK(*c1_vc_dot, 5U);
    *c1_t_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_t_dot, 3U);
    *c1_mode_out_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_mode_out_dot, 7U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_il_out, 0U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 3U, 3U);
    c1_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c1_t_out, 2U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    c1_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(*c1_vc_out, 4U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U);
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(*c1_mode_out_out, 6U);
    c1_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_DATA_RANGE_CHECK(*c1_buck_dcm_vs2_interval_sys_1_location, 18U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_dcm_discharging_controller:
    CV_CHART_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_c_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    *c1_il_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_il_dot, 1U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    *c1_vc_dot = (c1_const_buckboost_template_1_a11o * *c1_vc + *c1_rdv2) +
      c1_const_buckboost_template_1_b1o * *c1_Vs;
    _SFD_DATA_RANGE_CHECK(*c1_vc_dot, 5U);
    *c1_t_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_t_dot, 3U);
    *c1_mode_out_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_mode_out_dot, 7U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_il_out, 0U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 3U, 3U);
    c1_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c1_t_out, 2U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    c1_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(*c1_vc_out, 4U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U);
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(*c1_mode_out_out, 6U);
    c1_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_DATA_RANGE_CHECK(*c1_buck_dcm_vs2_interval_sys_1_location, 18U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_discharging_discharging_controller:
    CV_CHART_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_b_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    CV_SCRIPT_FCN(0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 1);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    *c1_il_dot = (((c1_const_buckboost_template_1_a00o * *c1_il + *c1_roi1) +
                   c1_const_buckboost_template_1_a01o * *c1_vc) + *c1_rov1) +
      c1_const_buckboost_template_1_b0o * *c1_Vs;
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 1);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    *c1_vc_dot = (((c1_const_buckboost_template_1_a10o * *c1_il + *c1_roi2) +
                   c1_const_buckboost_template_1_a11o * *c1_vc) + *c1_rov2) +
      c1_const_buckboost_template_1_b1o * *c1_Vs;
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 1);
    *c1_t_dot = 1.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 1);
    *c1_mode_out_dot = 0.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 1);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 2);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 3U, 3U);
    c1_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 2);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    c1_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 2);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U);
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 2);
    c1_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -2);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);
    break;
  }
}

static void outputs_c1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  real_T *c1_il_out;
  real_T *c1_il;
  real_T *c1_t_out;
  real_T *c1_t;
  real_T *c1_vc_out;
  real_T *c1_vc;
  real_T *c1_mode_out_out;
  real_T *c1_mode_out;
  real_T *c1_buck_dcm_vs2_interval_sys_1_location;
  c1_buck_dcm_vs2_interval_sys_1_location = (real_T *)ssGetOutputPortSignal
    (chartInstance->S, 5);
  c1_mode_out = (real_T *)(ssGetContStates(chartInstance->S) + 3);
  c1_mode_out_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_vc = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_vc_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_t = (real_T *)(ssGetContStates(chartInstance->S) + 1);
  c1_t_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_il = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  c1_il_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = sf_get_time(chartInstance->S);
  switch (chartInstance->c1_is_c1_buck_interval_flatten) {
   case c1_IN_charging_charging_controller:
    CV_CHART_EVAL(0, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    *c1_il_out = *c1_il;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_il_out, 0U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 3U, 3U);
    *c1_t_out = *c1_t;
    c1_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c1_t_out, 2U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    *c1_vc_out = *c1_vc;
    c1_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(*c1_vc_out, 4U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U);
    *c1_mode_out_out = *c1_mode_out;
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(*c1_mode_out_out, 6U);
    *c1_buck_dcm_vs2_interval_sys_1_location = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_DATA_RANGE_CHECK(*c1_buck_dcm_vs2_interval_sys_1_location, 18U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_dcm_discharging_controller:
    CV_CHART_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_c_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    *c1_il_out = *c1_il;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_il_out, 0U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 3U, 3U);
    *c1_t_out = *c1_t;
    c1_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c1_t_out, 2U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    *c1_vc_out = *c1_vc;
    c1_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(*c1_vc_out, 4U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U);
    *c1_mode_out_out = *c1_mode_out;
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(*c1_mode_out_out, 6U);
    *c1_buck_dcm_vs2_interval_sys_1_location = 3.0;
    c1_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_DATA_RANGE_CHECK(*c1_buck_dcm_vs2_interval_sys_1_location, 18U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_discharging_discharging_controller:
    CV_CHART_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_b_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    CV_SCRIPT_FCN(0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 1);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 1);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 1);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    *c1_il_out = *c1_il;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 2);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 3U, 3U);
    *c1_t_out = *c1_t;
    c1_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 2);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
    *c1_vc_out = *c1_vc;
    c1_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 2);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U);
    *c1_mode_out_out = *c1_mode_out;
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 2);
    *c1_buck_dcm_vs2_interval_sys_1_location = 2.0;
    c1_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -2);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);
    break;
  }
}

static void initSimStructsc1_buck_interval_flatten
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_ini_fcn_to_be_inlined_206
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_term_fcn_to_be_inlined_206
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, c1_instanceNumber, 0U,
    sf_debug_get_script_id(""));
}

static const mxArray *c1_emlrt_marshallOut
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, const real_T c1_u)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_buck_interval_flattenInstanceStruct *chartInstance;
  chartInstance = (SFc1_buck_interval_flattenInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_emlrt_marshallOut(chartInstance, *(real_T
    *)c1_inData), false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance, const mxArray *c1_nargout, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_buck_interval_flattenInstanceStruct *chartInstance;
  chartInstance = (SFc1_buck_interval_flattenInstanceStruct *)chartInstanceVoid;
  *(real_T *)c1_outData = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_emlrt_marshallOut
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, const boolean_T c1_u)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_buck_interval_flattenInstanceStruct *chartInstance;
  chartInstance = (SFc1_buck_interval_flattenInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_b_emlrt_marshallOut(chartInstance,
    *(boolean_T *)c1_inData), false);
  return c1_mxArrayOutData;
}

static boolean_T c1_c_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct *
  chartInstance, const mxArray *c1_sf_internal_predicateOutput, const char_T
  *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_sf_internal_predicateOutput), &c1_thisId);
  sf_mex_destroy(&c1_sf_internal_predicateOutput);
  return c1_y;
}

static boolean_T c1_d_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_buck_interval_flattenInstanceStruct *chartInstance;
  chartInstance = (SFc1_buck_interval_flattenInstanceStruct *)chartInstanceVoid;
  *(boolean_T *)c1_outData = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_buck_interval_flatten_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_c_emlrt_marshallOut
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, const int32_T c1_u)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_buck_interval_flattenInstanceStruct *chartInstance;
  chartInstance = (SFc1_buck_interval_flattenInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_c_emlrt_marshallOut(chartInstance,
    *(int32_T *)c1_inData), false);
  return c1_mxArrayOutData;
}

static int32_T c1_e_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance, const mxArray *c1_b_sfEvent, const char_T *c1_identifier)
{
  int32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  return c1_y;
}

static int32_T c1_f_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_buck_interval_flattenInstanceStruct *chartInstance;
  chartInstance = (SFc1_buck_interval_flattenInstanceStruct *)chartInstanceVoid;
  *(int32_T *)c1_outData = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_emlrt_marshallOut
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, const uint8_T c1_u)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_buck_interval_flattenInstanceStruct *chartInstance;
  chartInstance = (SFc1_buck_interval_flattenInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_d_emlrt_marshallOut(chartInstance,
    *(uint8_T *)c1_inData), false);
  return c1_mxArrayOutData;
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_charging_charging_controller, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_tp_charging_charging_controller), &c1_thisId);
  sf_mex_destroy(&c1_b_tp_charging_charging_controller);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_buck_interval_flattenInstanceStruct *chartInstance;
  chartInstance = (SFc1_buck_interval_flattenInstanceStruct *)chartInstanceVoid;
  *(uint8_T *)c1_outData = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_emlrt_marshallOut
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance)
{
  const mxArray *c1_y;
  real_T *c1_buck_dcm_vs2_interval_sys_1_location;
  real_T *c1_il_out;
  real_T *c1_mode_out_out;
  real_T *c1_t_out;
  real_T *c1_vc_out;
  real_T *c1_il;
  real_T *c1_mode_out;
  real_T *c1_t;
  real_T *c1_vc;
  c1_buck_dcm_vs2_interval_sys_1_location = (real_T *)ssGetOutputPortSignal
    (chartInstance->S, 5);
  c1_mode_out = (real_T *)(ssGetContStates(chartInstance->S) + 3);
  c1_mode_out_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_vc = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_vc_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_t = (real_T *)(ssGetContStates(chartInstance->S) + 1);
  c1_t_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_il = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  c1_il_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(11, 1), false);
  sf_mex_setcell(c1_y, 0, c1_emlrt_marshallOut(chartInstance,
    *c1_buck_dcm_vs2_interval_sys_1_location));
  sf_mex_setcell(c1_y, 1, c1_emlrt_marshallOut(chartInstance, *c1_il_out));
  sf_mex_setcell(c1_y, 2, c1_emlrt_marshallOut(chartInstance, *c1_mode_out_out));
  sf_mex_setcell(c1_y, 3, c1_emlrt_marshallOut(chartInstance, *c1_t_out));
  sf_mex_setcell(c1_y, 4, c1_emlrt_marshallOut(chartInstance, *c1_vc_out));
  sf_mex_setcell(c1_y, 5, c1_emlrt_marshallOut(chartInstance, *c1_il));
  sf_mex_setcell(c1_y, 6, c1_emlrt_marshallOut(chartInstance, *c1_mode_out));
  sf_mex_setcell(c1_y, 7, c1_emlrt_marshallOut(chartInstance, *c1_t));
  sf_mex_setcell(c1_y, 8, c1_emlrt_marshallOut(chartInstance, *c1_vc));
  sf_mex_setcell(c1_y, 9, c1_d_emlrt_marshallOut(chartInstance,
    chartInstance->c1_is_active_c1_buck_interval_flatten));
  sf_mex_setcell(c1_y, 10, c1_d_emlrt_marshallOut(chartInstance,
    chartInstance->c1_is_c1_buck_interval_flatten));
  return c1_y;
}

static void c1_i_emlrt_marshallIn(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance, const mxArray *c1_u)
{
  real_T *c1_buck_dcm_vs2_interval_sys_1_location;
  real_T *c1_il_out;
  real_T *c1_mode_out_out;
  real_T *c1_t_out;
  real_T *c1_vc_out;
  real_T *c1_il;
  real_T *c1_mode_out;
  real_T *c1_t;
  real_T *c1_vc;
  c1_buck_dcm_vs2_interval_sys_1_location = (real_T *)ssGetOutputPortSignal
    (chartInstance->S, 5);
  c1_mode_out = (real_T *)(ssGetContStates(chartInstance->S) + 3);
  c1_mode_out_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_vc = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_vc_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_t = (real_T *)(ssGetContStates(chartInstance->S) + 1);
  c1_t_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_il = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  c1_il_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  *c1_buck_dcm_vs2_interval_sys_1_location = c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 0)), "buck_dcm_vs2_interval_sys_1_location");
  *c1_il_out = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    1)), "il_out");
  *c1_mode_out_out = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 2)), "mode_out_out");
  *c1_t_out = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    3)), "t_out");
  *c1_vc_out = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    4)), "vc_out");
  *c1_il = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
    "il");
  *c1_mode_out = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 6)), "mode_out");
  *c1_t = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 7)),
    "t");
  *c1_vc = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 8)),
    "vc");
  chartInstance->c1_is_active_c1_buck_interval_flatten = c1_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 9)),
     "is_active_c1_buck_interval_flatten");
  chartInstance->c1_is_c1_buck_interval_flatten = c1_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 10)),
     "is_c1_buck_interval_flatten");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 11)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_j_emlrt_marshallIn
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, const mxArray
   *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_k_emlrt_marshallIn
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, const mxArray *c1_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_updateDataWrittenToVector
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, uint32_T
   c1_vectorIndex)
{
  (void)chartInstance;
  c1_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c1_vectorIndex, 0, 8, 1, 0)] = true;
}

static void c1_errorIfDataNotWrittenToFcn
  (SFc1_buck_interval_flattenInstanceStruct *chartInstance, uint32_T
   c1_vectorIndex, uint32_T c1_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c1_dataNumber, c1_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c1_vectorIndex, 0, 8, 1,
    0)]);
}

static void init_dsm_address_info(SFc1_buck_interval_flattenInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_buck_interval_flatten_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3621325988U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4167537359U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1432820892U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(77951753U);
}

mxArray *sf_c1_buck_interval_flatten_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("zqLI5Jnb1sDJZpYlTOc1wB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,11,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_buck_interval_flatten_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_buck_interval_flatten_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_buck_interval_flatten(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[19],T\"buck_dcm_vs2_interval_sys_1_location\",},{M[1],M[1],T\"il_out\",},{M[1],M[7],T\"mode_out_out\",},{M[1],M[3],T\"t_out\",},{M[1],M[5],T\"vc_out\",},{M[5],M[2],T\"il\",},{M[5],M[8],T\"mode_out\",},{M[5],M[4],T\"t\",},{M[5],M[6],T\"vc\",},{M[8],M[0],T\"is_active_c1_buck_interval_flatten\",}}",
    "100 S'type','srcId','name','auxInfo'{{M[9],M[0],T\"is_c1_buck_interval_flatten\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 11, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_buck_interval_flatten_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_buck_interval_flattenInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_buck_interval_flattenInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _buck_interval_flattenMachineNumber_,
           1,
           3,
           5,
           0,
           36,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_buck_interval_flattenMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_buck_interval_flattenMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _buck_interval_flattenMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"il_out");
          _SFD_SET_DATA_PROPS(1,0,0,0,"il");
          _SFD_SET_DATA_PROPS(2,2,0,1,"t_out");
          _SFD_SET_DATA_PROPS(3,0,0,0,"t");
          _SFD_SET_DATA_PROPS(4,2,0,1,"vc_out");
          _SFD_SET_DATA_PROPS(5,0,0,0,"vc");
          _SFD_SET_DATA_PROPS(6,2,0,1,"mode_out_out");
          _SFD_SET_DATA_PROPS(7,0,0,0,"mode_out");
          _SFD_SET_DATA_PROPS(8,1,1,0,"rci1");
          _SFD_SET_DATA_PROPS(9,1,1,0,"rcv1");
          _SFD_SET_DATA_PROPS(10,1,1,0,"rci2");
          _SFD_SET_DATA_PROPS(11,1,1,0,"rb1");
          _SFD_SET_DATA_PROPS(12,1,1,0,"rcv2");
          _SFD_SET_DATA_PROPS(13,1,1,0,"roi1");
          _SFD_SET_DATA_PROPS(14,1,1,0,"rov1");
          _SFD_SET_DATA_PROPS(15,1,1,0,"roi2");
          _SFD_SET_DATA_PROPS(16,1,1,0,"rov2");
          _SFD_SET_DATA_PROPS(17,1,1,0,"rdv2");
          _SFD_SET_DATA_PROPS(18,2,0,1,"buck_dcm_vs2_interval_sys_1_location");
          _SFD_SET_DATA_PROPS(19,7,0,0,"VcH");
          _SFD_SET_DATA_PROPS(20,7,0,0,"buckboost_template_1_a11o");
          _SFD_SET_DATA_PROPS(21,7,0,0,"tmax");
          _SFD_SET_DATA_PROPS(22,7,0,0,"buckboost_template_1_a01o");
          _SFD_SET_DATA_PROPS(23,7,0,0,"VcL");
          _SFD_SET_DATA_PROPS(24,7,0,0,"buckboost_template_1_a10o");
          _SFD_SET_DATA_PROPS(25,1,1,0,"Vs");
          _SFD_SET_DATA_PROPS(26,7,0,0,"buckboost_template_1_a00o");
          _SFD_SET_DATA_PROPS(27,7,0,0,"buckboost_template_1_b1o");
          _SFD_SET_DATA_PROPS(28,7,0,0,"buckboost_template_1_b0o");
          _SFD_SET_DATA_PROPS(29,7,0,0,"buckboost_template_1_a11c");
          _SFD_SET_DATA_PROPS(30,7,0,0,"buckboost_template_1_b0c");
          _SFD_SET_DATA_PROPS(31,7,0,0,"buckboost_template_1_a10c");
          _SFD_SET_DATA_PROPS(32,7,0,0,"buckboost_template_1_b1c");
          _SFD_SET_DATA_PROPS(33,7,0,0,"buckboost_template_1_bounds");
          _SFD_SET_DATA_PROPS(34,7,0,0,"buckboost_template_1_a01c");
          _SFD_SET_DATA_PROPS(35,7,0,0,"buckboost_template_1_a00c");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,
          "sf_internal_activity_action_discharging_discharging_controller_",0,-1,
          442);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,20,1,20);

        {
          static int condStart[] = { 1, 12 };

          static int condEnd[] = { 8, 20 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,20,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,10,1,10);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_il_out;
          real_T *c1_il;
          real_T *c1_t_out;
          real_T *c1_t;
          real_T *c1_vc_out;
          real_T *c1_vc;
          real_T *c1_mode_out_out;
          real_T *c1_mode_out;
          real_T *c1_rci1;
          real_T *c1_rcv1;
          real_T *c1_rci2;
          real_T *c1_rb1;
          real_T *c1_rcv2;
          real_T *c1_roi1;
          real_T *c1_rov1;
          real_T *c1_roi2;
          real_T *c1_rov2;
          real_T *c1_rdv2;
          real_T *c1_buck_dcm_vs2_interval_sys_1_location;
          real_T *c1_Vs;
          c1_Vs = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c1_buck_dcm_vs2_interval_sys_1_location = (real_T *)
            ssGetOutputPortSignal(chartInstance->S, 5);
          c1_rdv2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c1_rov2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c1_roi2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c1_rov1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c1_roi1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_rcv2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_rb1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_rci2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_rcv1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_rci1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_mode_out = (real_T *)(ssGetContStates(chartInstance->S) + 3);
          c1_mode_out_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_vc = (real_T *)(ssGetContStates(chartInstance->S) + 2);
          c1_vc_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_t = (real_T *)(ssGetContStates(chartInstance->S) + 1);
          c1_t_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_il = (real_T *)(ssGetContStates(chartInstance->S) + 0);
          c1_il_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_il_out);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_il);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_t_out);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_t);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_vc_out);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_vc);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_mode_out_out);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_mode_out);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_rci1);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_rcv1);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_rci2);
          _SFD_SET_DATA_VALUE_PTR(11U, c1_rb1);
          _SFD_SET_DATA_VALUE_PTR(12U, c1_rcv2);
          _SFD_SET_DATA_VALUE_PTR(13U, c1_roi1);
          _SFD_SET_DATA_VALUE_PTR(14U, c1_rov1);
          _SFD_SET_DATA_VALUE_PTR(15U, c1_roi2);
          _SFD_SET_DATA_VALUE_PTR(16U, c1_rov2);
          _SFD_SET_DATA_VALUE_PTR(17U, c1_rdv2);
          _SFD_SET_DATA_VALUE_PTR(18U, c1_buck_dcm_vs2_interval_sys_1_location);
          _SFD_SET_DATA_VALUE_PTR(19U, &chartInstance->c1_VcH);
          _SFD_SET_DATA_VALUE_PTR(20U,
            &chartInstance->c1_buckboost_template_1_a11o);
          _SFD_SET_DATA_VALUE_PTR(21U, &chartInstance->c1_tmax);
          _SFD_SET_DATA_VALUE_PTR(22U,
            &chartInstance->c1_buckboost_template_1_a01o);
          _SFD_SET_DATA_VALUE_PTR(23U, &chartInstance->c1_VcL);
          _SFD_SET_DATA_VALUE_PTR(24U,
            &chartInstance->c1_buckboost_template_1_a10o);
          _SFD_SET_DATA_VALUE_PTR(25U, c1_Vs);
          _SFD_SET_DATA_VALUE_PTR(26U,
            &chartInstance->c1_buckboost_template_1_a00o);
          _SFD_SET_DATA_VALUE_PTR(27U,
            &chartInstance->c1_buckboost_template_1_b1o);
          _SFD_SET_DATA_VALUE_PTR(28U,
            &chartInstance->c1_buckboost_template_1_b0o);
          _SFD_SET_DATA_VALUE_PTR(29U,
            &chartInstance->c1_buckboost_template_1_a11c);
          _SFD_SET_DATA_VALUE_PTR(30U,
            &chartInstance->c1_buckboost_template_1_b0c);
          _SFD_SET_DATA_VALUE_PTR(31U,
            &chartInstance->c1_buckboost_template_1_a10c);
          _SFD_SET_DATA_VALUE_PTR(32U,
            &chartInstance->c1_buckboost_template_1_b1c);
          _SFD_SET_DATA_VALUE_PTR(33U,
            &chartInstance->c1_buckboost_template_1_bounds);
          _SFD_SET_DATA_VALUE_PTR(34U,
            &chartInstance->c1_buckboost_template_1_a01c);
          _SFD_SET_DATA_VALUE_PTR(35U,
            &chartInstance->c1_buckboost_template_1_a00c);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _buck_interval_flattenMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "0G5SQNw4KI6N5Zuj6mzNyC";
}

static void sf_opaque_initialize_c1_buck_interval_flatten(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_buck_interval_flattenInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_buck_interval_flatten
    ((SFc1_buck_interval_flattenInstanceStruct*) chartInstanceVar);
  initialize_c1_buck_interval_flatten((SFc1_buck_interval_flattenInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_buck_interval_flatten(void *chartInstanceVar)
{
  enable_c1_buck_interval_flatten((SFc1_buck_interval_flattenInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_buck_interval_flatten(void *chartInstanceVar)
{
  disable_c1_buck_interval_flatten((SFc1_buck_interval_flattenInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_zeroCrossings_c1_buck_interval_flatten(void
  *chartInstanceVar)
{
  zeroCrossings_c1_buck_interval_flatten
    ((SFc1_buck_interval_flattenInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_outputs_c1_buck_interval_flatten(void *chartInstanceVar)
{
  outputs_c1_buck_interval_flatten((SFc1_buck_interval_flattenInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_derivatives_c1_buck_interval_flatten(void
  *chartInstanceVar)
{
  derivatives_c1_buck_interval_flatten((SFc1_buck_interval_flattenInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_buck_interval_flatten(void *chartInstanceVar)
{
  sf_gateway_c1_buck_interval_flatten((SFc1_buck_interval_flattenInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_buck_interval_flatten
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_buck_interval_flatten
    ((SFc1_buck_interval_flattenInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_buck_interval_flatten();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_buck_interval_flatten(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_buck_interval_flatten();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_buck_interval_flatten
    ((SFc1_buck_interval_flattenInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_buck_interval_flatten(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c1_buck_interval_flatten(S);
}

static void sf_opaque_set_sim_state_c1_buck_interval_flatten(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_buck_interval_flatten(S, st);
}

static void sf_opaque_terminate_c1_buck_interval_flatten(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_buck_interval_flattenInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_buck_interval_flatten_optimization_info();
    }

    finalize_c1_buck_interval_flatten((SFc1_buck_interval_flattenInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_buck_interval_flatten
    ((SFc1_buck_interval_flattenInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_buck_interval_flatten(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c1_buck_interval_flatten
      ((SFc1_buck_interval_flattenInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_buck_interval_flatten(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_buck_interval_flatten_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,11);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 11; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3124837657U));
  ssSetChecksum1(S,(534922605U));
  ssSetChecksum2(S,(3808882122U));
  ssSetChecksum3(S,(58517715U));
  ssSetNumContStates(S,4);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_buck_interval_flatten(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_buck_interval_flatten(SimStruct *S)
{
  SFc1_buck_interval_flattenInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_buck_interval_flattenInstanceStruct *)utMalloc(sizeof
    (SFc1_buck_interval_flattenInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_buck_interval_flattenInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_buck_interval_flatten;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_buck_interval_flatten;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_buck_interval_flatten;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_buck_interval_flatten;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_buck_interval_flatten;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_buck_interval_flatten;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_buck_interval_flatten;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_buck_interval_flatten;
  chartInstance->chartInfo.zeroCrossings =
    sf_opaque_zeroCrossings_c1_buck_interval_flatten;
  chartInstance->chartInfo.outputs = sf_opaque_outputs_c1_buck_interval_flatten;
  chartInstance->chartInfo.derivatives =
    sf_opaque_derivatives_c1_buck_interval_flatten;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_buck_interval_flatten;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_buck_interval_flatten;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_buck_interval_flatten;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_buck_interval_flatten_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_buck_interval_flatten(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_buck_interval_flatten(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_buck_interval_flatten(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_buck_interval_flatten_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
