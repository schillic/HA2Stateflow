  /*********************** dSPACE target specific file *************************

   Header file buck_interval_flatten_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1103 7.2 (02-May-2014)
   Wed Jan 13 19:02:03 2016

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_buck_interval_flatten_trc_ptr_h_
  #define RTI_HEADER_buck_interval_flatten_trc_ptr_h_
  /* Include the model header file. */
  #include "buck_interval_flatten.h"
  #include "buck_interval_flatten_private.h"

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
              EXTERN_C volatile  real_T *p_0_buck_interval_flatten_real_T_0;
              EXTERN_C volatile  real_T *p_1_buck_interval_flatten_real_T_0;
              EXTERN_C volatile  real_T *p_2_buck_interval_flatten_real_T_0;
              EXTERN_C volatile  uint8_T *p_2_buck_interval_flatten_uint8_T_1;
              EXTERN_C volatile  real_T *p_3_buck_interval_flatten_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_0_buck_interval_flatten_real_T_0 = &buck_interval_flatten_B.il_out;\
              p_1_buck_interval_flatten_real_T_0 = &buck_interval_flatten_P.Constant_Value;\
              p_2_buck_interval_flatten_real_T_0 = &buck_interval_flatten_DW.lastMajorTime;\
              p_2_buck_interval_flatten_uint8_T_1 = &buck_interval_flatten_DW.is_active_c1_buck_interval_flat;\
              p_3_buck_interval_flatten_real_T_0 = &buck_interval_flatten_X.SFunction_CSTATE[0];\

   #endif                       /* RTI_HEADER_buck_interval_flatten_trc_ptr_h_ */
