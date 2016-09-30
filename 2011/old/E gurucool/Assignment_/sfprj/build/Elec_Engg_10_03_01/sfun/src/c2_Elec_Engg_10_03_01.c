/* Include files */
#include "Elec_Engg_10_03_01_sfun.h"
#include "c2_Elec_Engg_10_03_01.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "Elec_Engg_10_03_01_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_Elec_Engg_10_03_01InstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_Elec_Engg_10_03_01(void);
static void initialize_params_c2_Elec_Engg_10_03_01(void);
static void enable_c2_Elec_Engg_10_03_01(void);
static void disable_c2_Elec_Engg_10_03_01(void);
static void finalize_c2_Elec_Engg_10_03_01(void);
static void sf_c2_Elec_Engg_10_03_01(void);
static real_T *c2_u(void);
static real_T *c2_y(void);

/* Function Definitions */
static void initialize_c2_Elec_Engg_10_03_01(void)
{
  chartInstance.c2_is_active_c2_Elec_Engg_10_03_01 = 0;
  if(!(cdrGetOutputPortReusable(chartInstance.S, 1) != 0)) {
  }
}

static void initialize_params_c2_Elec_Engg_10_03_01(void)
{
}

static void enable_c2_Elec_Engg_10_03_01(void)
{
}

static void disable_c2_Elec_Engg_10_03_01(void)
{
}

static void finalize_c2_Elec_Engg_10_03_01(void)
{
}

static void sf_c2_Elec_Engg_10_03_01(void)
{
  uint8_T c2_previousEvent;
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c2_u(), 1U);
  _SFD_DATA_RANGE_CHECK(*c2_y(), 0U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  {
    real_T c2_em_d0;
    real_T c2_b_u;
    _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
    c2_b_u = *c2_u();
    sf_debug_push_symbol_scope(2);
    sf_debug_symbol_scope_add_symbol("u", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
     &c2_b_u);
    sf_debug_symbol_scope_add_symbol("y", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
     &c2_em_d0);
    CV_EML_FCN(0, 0);
    /*  This block supports an embeddable subset of the MATLAB language. */
    /*  See the help menu for details.  */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,5);
    c2_em_d0 = c2_b_u;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-5);
    sf_debug_pop_symbol_scope();
    *c2_y() = c2_em_d0;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  }
  _sfEvent_ = c2_previousEvent;
}

static real_T *c2_u(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
}

static real_T *c2_y(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
}

/* SFunction Glue Code */
void sf_c2_Elec_Engg_10_03_01_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(210922385U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(10377962U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(402000084U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2230411932U);
}

mxArray *sf_c2_Elec_Engg_10_03_01_get_autoinheritance_info(void)
{
  const char *autoinheritanceInfoStructFieldNames[] =
  {"checksum","inputTypes","inputComplexities","parameterTypes","parameterComplexities","outputSizes","outputTypes","outputComplexities"};
  mxArray *mxAutoinheritanceInfo = NULL;
  mxArray *mxChecksum = NULL;
  mxArray *mxInputTypes = NULL;
  mxArray *mxInputComplexities = NULL;
  mxArray *mxParameterTypes = NULL;
  mxArray *mxParameterComplexities = NULL;
  mxArray *mxOutputSizes = NULL;
  mxArray *mxOutputTypes = NULL;
  mxArray *mxOutputComplexities = NULL;

  mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,
   sizeof(autoinheritanceInfoStructFieldNames)/sizeof(char *),
   autoinheritanceInfoStructFieldNames);

  mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
  ((real_T *)mxGetPr((mxChecksum)))[0] = (real_T)(2168511454U);
  ((real_T *)mxGetPr((mxChecksum)))[1] = (real_T)(290514179U);
  ((real_T *)mxGetPr((mxChecksum)))[2] = (real_T)(1648705217U);
  ((real_T *)mxGetPr((mxChecksum)))[3] = (real_T)(1592043565U);

  mxInputTypes = mxCreateDoubleMatrix(1,1,mxREAL);
  mxInputComplexities = mxCreateDoubleMatrix(1,1,mxREAL);
  ((real_T *)mxGetPr((mxInputTypes)))[0] = (real_T)(10U);
  ((real_T *)mxGetPr((mxInputComplexities)))[0] = (real_T)(0U);

  mxParameterTypes = mxCreateDoubleMatrix(1,0,mxREAL);
  mxParameterComplexities = mxCreateDoubleMatrix(1,0,mxREAL);

  mxOutputSizes = mxCreateDoubleMatrix(2,1,mxREAL);
  mxOutputTypes = mxCreateDoubleMatrix(1,1,mxREAL);
  mxOutputComplexities = mxCreateDoubleMatrix(1,1,mxREAL);
  ((real_T *)mxGetPr((mxOutputSizes)))[0] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputSizes)))[1] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputTypes)))[0] = (real_T)(10U);
  ((real_T *)mxGetPr((mxOutputComplexities)))[0] = (real_T)(0U);

  mxSetFieldByNumber(mxAutoinheritanceInfo,0,0,mxChecksum);
  mxSetFieldByNumber(mxAutoinheritanceInfo,0,1,mxInputTypes);
  mxSetFieldByNumber(mxAutoinheritanceInfo,0,2,mxInputComplexities);
  mxSetFieldByNumber(mxAutoinheritanceInfo,0,3,mxParameterTypes);
  mxSetFieldByNumber(mxAutoinheritanceInfo,0,4,mxParameterComplexities);
  mxSetFieldByNumber(mxAutoinheritanceInfo,0,5,mxOutputSizes);
  mxSetFieldByNumber(mxAutoinheritanceInfo,0,6,mxOutputTypes);
  mxSetFieldByNumber(mxAutoinheritanceInfo,0,7,mxOutputComplexities);

  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S)
{
  if(ssIsFirstInitCond(S)) {
    /* do this only if simulation is starting */
    if(!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent =
          sf_debug_initialize_chart(_Elec_Engg_10_03_01MachineNumber_,
         2,
         1,
         1,
         2,
         0,
         0,
         0,
         0,
         &(chartInstance.chartNumber),
         &(chartInstance.instanceNumber),
         ssGetPath(S),
         (void *)S);
        if(chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting(_Elec_Engg_10_03_01MachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_Elec_Engg_10_03_01MachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"u",0);
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"y",0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }
        _SFD_CV_INIT_CHART(0,0,0,0);
        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,128);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_SET_DATA_VALUE_PTR(1U, c2_u());
        _SFD_SET_DATA_VALUE_PTR(0U, c2_y());
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_Elec_Engg_10_03_01MachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_Elec_Engg_10_03_01(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S);
  initialize_c2_Elec_Engg_10_03_01();
  initialize_params_c2_Elec_Engg_10_03_01();
}

static void sf_opaque_enable_c2_Elec_Engg_10_03_01(void *chartInstanceVar)
{
  enable_c2_Elec_Engg_10_03_01();
}

static void sf_opaque_disable_c2_Elec_Engg_10_03_01(void *chartInstanceVar)
{
  disable_c2_Elec_Engg_10_03_01();
}

static void sf_opaque_gateway_c2_Elec_Engg_10_03_01(void *chartInstanceVar)
{
  sf_c2_Elec_Engg_10_03_01();
}

static void sf_opaque_terminate_c2_Elec_Engg_10_03_01(void *chartInstanceVar)
{
  finalize_c2_Elec_Engg_10_03_01();
}

static void mdlProcessParameters_c2_Elec_Engg_10_03_01(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    ssUpdateDlgParamAsRunTimeParam(S, i);
  }
  initialize_params_c2_Elec_Engg_10_03_01();
}

static void mdlSetWorkWidths_c2_Elec_Engg_10_03_01(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Elec_Engg_10_03_01",2);
    int_T chartIsMultiInstanced =
      (int_T)sf_is_chart_multi_instanced("Elec_Engg_10_03_01",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Elec_Engg_10_03_01",2,1);
      sf_mark_chart_reusable_outputs(S,"Elec_Engg_10_03_01",2,1);
    }
    if (!sf_is_chart_instance_optimized_out("Elec_Engg_10_03_01",2)) {
      int dtId;
      char *chartInstanceTypedefName =
        sf_chart_instance_typedef_name("Elec_Engg_10_03_01",2);
      dtId = ssRegisterDataType(S, chartInstanceTypedefName);
      if (dtId == INVALID_DTYPE_ID ) return;
      /* Register the size of the udt */
      if (!ssSetDataTypeSize(S, dtId, 8)) return;
      if(!ssSetNumDWork(S,1)) return;
      ssSetDWorkDataType(S, 0, dtId);
      ssSetDWorkWidth(S, 0, 1);
      ssSetDWorkName(S, 0, "ChartInstance"); /*optional name, less than 16 chars*/
      sf_set_rtw_identifier(S);
    }
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(210922385U));
  ssSetChecksum1(S,(10377962U));
  ssSetChecksum2(S,(402000084U));
  ssSetChecksum3(S,(2230411932U));

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_Elec_Engg_10_03_01(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Elec_Engg_10_03_01", 2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Elec_Engg_10_03_01(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_Elec_Engg_10_03_01;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_Elec_Engg_10_03_01;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c2_Elec_Engg_10_03_01;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c2_Elec_Engg_10_03_01;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c2_Elec_Engg_10_03_01;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_Elec_Engg_10_03_01;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_Elec_Engg_10_03_01;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_Elec_Engg_10_03_01;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */
}

void c2_Elec_Engg_10_03_01_method_dispatcher(SimStruct *S, int_T method, void
 *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Elec_Engg_10_03_01(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Elec_Engg_10_03_01(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Elec_Engg_10_03_01(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c2_Elec_Engg_10_03_01_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

