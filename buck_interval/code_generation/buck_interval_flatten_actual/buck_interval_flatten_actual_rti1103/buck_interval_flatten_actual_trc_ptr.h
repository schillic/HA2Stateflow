  /*********************** dSPACE target specific file *************************

   Header file buck_interval_flatten_actual_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1103 7.2 (02-May-2014)
   Wed Jan 13 19:17:17 2016

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_buck_interval_flatten_actual_trc_ptr_h_
  #define RTI_HEADER_buck_interval_flatten_actual_trc_ptr_h_
  /* Include the model header file. */
  #include "buck_interval_flatten_actual.h"
  #include "buck_interval_flatten_actual_private.h"

  #ifdef EXTERN_C
  #undef EXTERN_C
  #endif

  #ifdef __cplusplus
  #define EXTERN_C                       extern "C"
  #else
  #define EXTERN_C                       extern
  #endif

  /*
   *  Declare the global TRC pointers
   */
              EXTERN_C volatile  real_T *p_0_buck_interval_flatten_actual_real_T_0;
              EXTERN_C volatile  boolean_T *p_0_buck_interval_flatten_actual_boolean_T_1;
              EXTERN_C volatile  real_T *p_1_buck_interval_flatten_actual_real_T_0;
              EXTERN_C volatile  boolean_T *p_1_buck_interval_flatten_actual_boolean_T_1;
              EXTERN_C volatile  real_T *p_2_buck_interval_flatten_actual_real_T_0;
              EXTERN_C volatile  uint8_T *p_2_buck_interval_flatten_actual_uint8_T_1;
              EXTERN_C volatile  real_T *p_3_buck_interval_flatten_actual_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_0_buck_interval_flatten_actual_real_T_0 = &buck_interval_flatten_actual_B.SFunction;\
              p_0_buck_interval_flatten_actual_boolean_T_1 = &buck_interval_flatten_actual_B.DataTypeConversion;\
              p_1_buck_interval_flatten_actual_real_T_0 = &buck_interval_flatten_actual_P.Constant_Value;\
              p_1_buck_interval_flatten_actual_boolean_T_1 = &buck_interval_flatten_actual_P.Command_Value;\
              p_2_buck_interval_flatten_actual_real_T_0 = &buck_interval_flatten_actual_DW.lastMajorTime;\
              p_2_buck_interval_flatten_actual_uint8_T_1 = &buck_interval_flatten_actual_DW.is_active_c1_buck_interval_flat;\
              p_3_buck_interval_flatten_actual_real_T_0 = &buck_interval_flatten_actual_X.SFunction_CSTATE[0];\

   #endif                       /* RTI_HEADER_buck_interval_flatten_actual_trc_ptr_h_ */
