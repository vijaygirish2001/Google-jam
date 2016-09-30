/* Include files */
#include "Elec_Engg_10_03_01_sfun.h"
#include "c2_Elec_Engg_10_03_01.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _Elec_Engg_10_03_01MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Elec_Engg_10_03_01_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void Elec_Engg_10_03_01_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Elec_Engg_10_03_01_method_dispatcher(SimStruct *simstructPtr,
 const char *chartName, int_T method, void *data)
{
  if(!strcmp_ignore_ws(chartName,"Elec_Engg_10_03_01/Embedded MATLAB Function/ SFunction "))
  {
    c2_Elec_Engg_10_03_01_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  return 0;
}
unsigned int sf_Elec_Engg_10_03_01_process_check_sum_call( int nlhs, mxArray *
 plhs[], int nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) ) return 0;
  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"sf_get_check_sum")) return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if(nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if(!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2964093531U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1329512950U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1173141499U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(240095536U);
    }else if(!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    }else if(!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2374835296U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3536917271U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3953393690U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(56175844U);
    }else if(nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch(chartFileNumber) {
       case 2:
        {
          extern void sf_c2_Elec_Engg_10_03_01_get_check_sum(mxArray *plhs[]);
          sf_c2_Elec_Engg_10_03_01_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    }else if(!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3764540431U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1647328094U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2173129360U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2124855466U);
    }else {
      return 0;
    }
  } else{
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1655547205U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3067572243U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(124917320U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1495109410U);
  }
  return 1;
#else
  return 0;
#endif
}

unsigned int sf_Elec_Engg_10_03_01_autoinheritance_info( int nlhs, mxArray *
 plhs[], int nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) ) return 0;
  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"get_autoinheritance_info")) return 0;
  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch(chartFileNumber) {
     case 2:
      {
        extern mxArray *sf_c2_Elec_Engg_10_03_01_get_autoinheritance_info(void);
        plhs[0] = sf_c2_Elec_Engg_10_03_01_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }
  return 1;
#else
  return 0;
#endif
}
void Elec_Engg_10_03_01_debug_initialize(void)
{
  _Elec_Engg_10_03_01MachineNumber_ =
    sf_debug_initialize_machine("Elec_Engg_10_03_01","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(_Elec_Engg_10_03_01MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_Elec_Engg_10_03_01MachineNumber_,0);
}

