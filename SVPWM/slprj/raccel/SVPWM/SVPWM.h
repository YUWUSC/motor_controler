#ifndef RTW_HEADER_SVPWM_h_
#define RTW_HEADER_SVPWM_h_
#ifndef SVPWM_COMMON_INCLUDES_
#define SVPWM_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "SVPWM_types.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#include "rt_nonfinite.h"
#define MODEL_NAME SVPWM
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (9) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T a1jevbgg4x [ 12 ] ; real_T jbljr5tq4u [ 6 ] ; real_T
eiihwmjf1j [ 2 ] ; real_T exnbmwz04i [ 6 ] ; real_T l35oohpje4 [ 6 ] ; real_T
dqwh3ca4xi [ 3 ] ; real_T en3wjyqdju [ 3 ] ; boolean_T iusmv3md3a [ 3 ] ;
boolean_T pjks0m0pmo [ 3 ] ; } B ; typedef struct { real_T jiydzlq20v [ 6 ] ;
real_T djelptucdk [ 6 ] ; struct { void * AS ; void * BS ; void * CS ; void *
DS ; void * DX_COL ; void * BD_COL ; void * TMP1 ; void * TMP2 ; void * XTMP
; void * SWITCH_STATUS ; void * SWITCH_STATUS_INIT ; void * SW_CHG ; void *
G_STATE ; void * USWLAST ; void * XKM12 ; void * XKP12 ; void * XLAST ; void
* ULAST ; void * IDX_SW_CHG ; void * Y_SWITCH ; void * SWITCH_TYPES ; void *
IDX_OUT_SW ; void * SWITCH_TOPO_SAVED_IDX ; void * SWITCH_MAP ; } mpy40nreq3
; struct { void * LoggedData [ 2 ] ; } ahjsbkznjq ; struct { void *
LoggedData [ 6 ] ; } kt5gzitgzu ; struct { void * LoggedData ; } h21b5dj40j ;
struct { void * LoggedData ; } oihcveypcc ; int_T h0oh5ydh3u [ 11 ] ; } DW ;
typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ {
real_T _Vdc2f2SVPWM_sldd_ ; real_T _m2f2SVPWM_sldd_ ; real_T
RepeatingSequence_rep_seq_y [ 3 ] ; real_T Gain2_Gain ; real_T Gain3_Gain ;
real_T StateSpace_AS_param [ 36 ] ; real_T StateSpace_BS_param [ 42 ] ;
real_T StateSpace_CS_param [ 72 ] ; real_T StateSpace_DS_param [ 84 ] ;
real_T StateSpace_X0_param [ 6 ] ; real_T LookUpTable1_bp01Data [ 3 ] ;
real_T SineWave_Bias ; real_T SineWave_Freq ; real_T SineWave_Phase [ 3 ] ;
real_T Gain3_Gain_byafyznv0k [ 9 ] ; real_T Gain1_Gain ; real_T
Switch_Threshold ; real_T Gain1_Gain_gnhgdq2zzz ; real_T Gain_Gain ; real_T
Switch1_Threshold ; real_T Gain2_Gain_lxbjdzc3ab ; real_T Switch2_Threshold ;
real_T Gain_Gain_o3ussx2pey ; real_T Gain1_Gain_a1wggbqhys ; real_T
Gain_Gain_jtfu24yj43 ; real_T u4_Value ; real_T uRon_Gain ; real_T
Switch_Threshold_jdj5zhvmwv ; real_T Saturation_UpperSat ; real_T
Saturation_LowerSat ; real_T UnitDelay_InitialCondition ; real_T
donotdeletethisgain_Gain ; real_T donotdeletethisgain_Gain_d5clbn1ab5 ;
real_T donotdeletethisgain_Gain_dii0kh5zng ; real_T Kv1_Gain ; real_T
donotdeletethisgain_Gain_f0n5ohe52n ; real_T
donotdeletethisgain_Gain_cljduyemw5 ; real_T
donotdeletethisgain_Gain_fprakrrw0l ; real_T Kv_Gain ; real_T Constant_Value
; real_T Constant1_Value ; real_T Constant2_Value ; real_T Constant3_Value ;
real_T Constant4_Value ; real_T Constant5_Value ; real_T Constant6_Value ;
real_T Constant7_Value ; real_T Constant8_Value ; real_T Constant9_Value ;
real_T Constant_Value_ffpsqzlbdy ; real_T Constant_Value_kboz1tvd2g ; } ;
extern const real_T SVPWM_RGND ; extern const char_T *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern P rtP ;
extern mxArray * mr_SVPWM_GetDWork ( ) ; extern void mr_SVPWM_SetDWork (
const mxArray * ssDW ) ; extern mxArray *
mr_SVPWM_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * SVPWM_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
