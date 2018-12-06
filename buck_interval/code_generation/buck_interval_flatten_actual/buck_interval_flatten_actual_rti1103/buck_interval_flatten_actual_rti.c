/*********************** dSPACE target specific file *************************

   Include file buck_interval_flatten_actual_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1103 7.2 (02-May-2014)
   Wed Jan 13 19:17:17 2016

   (c) Copyright 2006, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "buck_interval_flatten_actual.h"
#include "buck_interval_flatten_actual_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             buck_interval_flatten_actual_B
#define RTP_STRUCTURE_NAME             buck_interval_flatten_actual_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <def1103.h>
#include <slvdsp1103.h>
#include <rti_slv1103.h>

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* ===== Definition of interface functions for simulation engine =========== */
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        rtmIsSampleHit(RTM,sti,0)
#endif

#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

static void rti_mdl_initialize_host_services(void)
{
  ts_timestamp_type ts = { 0, 0 };

  host_service(1, &ts);
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1103, (void *) 0,
                        VCM_TXT_RTI1103, 7, 2, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 8, 3, 0,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 8, 3, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 8, 6, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW, msg_mod_ptr,
                          VCM_TXT_STATEFLOW, 8, 3, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW_CODER, msg_mod_ptr,
                          VCM_TXT_STATEFLOW_CODER, 8, 6, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }
  }

  /* dSPACE I/O Board DS1103 #1 */
  /* Initialize master - slave DSP communication */
  ds1103_slave_dsp_communication_init();

  /* Initialize automatic index generation */
  rti_slv1103_init_fcn_index();

  /* Initialize slave DSP error level */
  rti_slv1103_error_level = 0;
  ds1103_slave_dsp_bit_io_set_register(1, &rti_slv1103_fcn_index[11], 2);
  ds1103_slave_dsp_bit_io_clear_register(1, &rti_slv1103_fcn_index[14], 2);

  /* Initialization of Master ADC units */
  ds1103_adc_trigger_setup(1, DS1103_TRIGGER_DISABLE);

  /* Initialization of Master MUXADC units */
}

/* Function rti_mdl_slave_load() is empty */
#define rti_mdl_slave_load()

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

static void rti_mdl_initialize_io_units(void)
{
  /* dSPACE I/O Board DS1103 #1 Unit:SLV_BIT_IO */
  ds1103_slave_dsp_bit_io_init(1, 2, SLVDSP1103_BIT_IO_BIT4_MSK,
    SLVDSP1103_BIT_IO_BIT4_OUT);

  /* dSPACE I/O Board DS1103 #1 Unit:SLV_BIT_IO Group:BIT_OUT */
  rti_slv1103_taskqueue_error[1] = ds1103_slave_dsp_bit_io_clear(1,
    rti_slv1103_fcn_index[14], SLVDSP1103_BIT_IO_BIT4_MSK);
}

/* Function rti_mdl_acknowledge_interrupts() is empty */
#define rti_mdl_acknowledge_interrupts()

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

/* Function rti_mdl_timesync_simstate() is empty */
#define rti_mdl_timesync_simstate()

/* Function rti_mdl_timesync_baserate() is empty */
#define rti_mdl_timesync_baserate()

static void rti_mdl_background(void)
{
  /* dSPACE I/O Board DS1103 #1 */
  /* Check master - slave dsp communication */
  rti_slv1103_taskqueue_error_all_check();
}

__INLINE void rti_mdl_sample_input(void)
{
  /* Calls for base sample time: [2.0E-5, 0] */
  /* dSPACE I/O Board DS1103 #1 Unit:MultiAdc */
  {
    Float64 pvalues[20];
    ds1103_adc_multi_conv_read(DS1103_ADC_CHANNEL1, pvalues);
    buck_interval_flatten_actual_B.SFunction = pvalues[0];
  }
}

static void rti_mdl_daq_service()
{
  /* dSPACE Host Service */
  host_service(1, rtk_current_task_absolute_time_ptr_get());
}

#undef __INLINE

/****** [EOF] ****************************************************************/
