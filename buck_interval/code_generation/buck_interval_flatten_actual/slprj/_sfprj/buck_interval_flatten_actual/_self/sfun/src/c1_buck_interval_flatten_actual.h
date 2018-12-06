#ifndef __c1_buck_interval_flatten_actual_h__
#define __c1_buck_interval_flatten_actual_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_buck_interval_flatten_actualInstanceStruct
#define typedef_SFc1_buck_interval_flatten_actualInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_charging_charging_controller;
  uint8_T c1_tp_discharging_discharging_controller;
  uint8_T c1_tp_dcm_discharging_controller;
  boolean_T c1_isStable;
  boolean_T c1_stateChanged;
  real_T c1_lastMajorTime;
  uint8_T c1_is_active_c1_buck_interval_flatten_actual;
  uint8_T c1_is_c1_buck_interval_flatten_actual;
  real_T c1_VcH;
  real_T c1_buckboost_template_1_a11o;
  real_T c1_tmax;
  real_T c1_buckboost_template_1_a01o;
  real_T c1_VcL;
  real_T c1_buckboost_template_1_a10o;
  real_T c1_buckboost_template_1_a00o;
  real_T c1_buckboost_template_1_b1o;
  real_T c1_buckboost_template_1_b0o;
  real_T c1_buckboost_template_1_a11c;
  real_T c1_buckboost_template_1_b0c;
  real_T c1_buckboost_template_1_a10c;
  real_T c1_buckboost_template_1_b1c;
  real_T c1_buckboost_template_1_bounds;
  real_T c1_buckboost_template_1_a01c;
  real_T c1_buckboost_template_1_a00c;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_buck_interval_flatten_actualInstanceStruct;

#endif                                 /*typedef_SFc1_buck_interval_flatten_actualInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_buck_interval_flatten_actual_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_buck_interval_flatten_actual_get_check_sum(mxArray *plhs[]);
extern void c1_buck_interval_flatten_actual_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
