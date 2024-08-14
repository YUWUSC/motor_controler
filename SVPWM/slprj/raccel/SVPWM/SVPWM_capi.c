#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "SVPWM_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 18
#endif
#ifndef SS_INT64
#define SS_INT64 19
#endif
#else
#include "builtin_typeid_types.h"
#include "SVPWM.h"
#include "SVPWM_capi.h"
#include "SVPWM_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"SVPWM/Three-Phase V-I Measurement/Kv" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 1 , 0 , TARGET_STRING ( "SVPWM/Three-Phase V-I Measurement/Kv1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"SVPWM/时间计算/Multiport Switch" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 ,
1 } , { 3 , 0 , TARGET_STRING ( "SVPWM/载波调制/NOT" ) , TARGET_STRING ( "" )
, 0 , 1 , 0 , 0 , 1 } , { 4 , 0 , TARGET_STRING (
"SVPWM/载波调制/Relational Operator" ) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0
, 1 } , { 5 , 0 , TARGET_STRING (
"SVPWM/Universal Bridge/Model/Data Type Conversion" ) , TARGET_STRING ( "" )
, 0 , 0 , 2 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"SVPWM/Universal Bridge/Model/Saturation" ) , TARGET_STRING ( "" ) , 0 , 0 ,
2 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"SVPWM/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "" ) , 0 ,
0 , 3 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"SVPWM/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "" ) , 1 ,
0 , 2 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 9 ,
TARGET_STRING ( "SVPWM/Sine Wave" ) , TARGET_STRING ( "Bias" ) , 0 , 4 , 0 }
, { 10 , TARGET_STRING ( "SVPWM/Sine Wave" ) , TARGET_STRING ( "Frequency" )
, 0 , 4 , 0 } , { 11 , TARGET_STRING ( "SVPWM/Sine Wave" ) , TARGET_STRING (
"Phase" ) , 0 , 5 , 0 } , { 12 , TARGET_STRING ( "SVPWM/7段时间分配/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 4 , 0 } , { 13 , TARGET_STRING (
"SVPWM/Three-Phase V-I Measurement/Kv" ) , TARGET_STRING ( "Gain" ) , 0 , 4 ,
0 } , { 14 , TARGET_STRING ( "SVPWM/Three-Phase V-I Measurement/Kv1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 4 , 0 } , { 15 , TARGET_STRING (
"SVPWM/扇区判断/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 16
, TARGET_STRING ( "SVPWM/扇区判断/Constant1" ) , TARGET_STRING ( "Value" ) ,
0 , 4 , 0 } , { 17 , TARGET_STRING ( "SVPWM/扇区判断/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 18 , TARGET_STRING (
"SVPWM/扇区判断/Constant3" ) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 19
, TARGET_STRING ( "SVPWM/扇区判断/Constant4" ) , TARGET_STRING ( "Value" ) ,
0 , 4 , 0 } , { 20 , TARGET_STRING ( "SVPWM/扇区判断/Constant5" ) ,
TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 21 , TARGET_STRING (
"SVPWM/扇区判断/Constant6" ) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 22
, TARGET_STRING ( "SVPWM/扇区判断/Constant7" ) , TARGET_STRING ( "Value" ) ,
0 , 4 , 0 } , { 23 , TARGET_STRING ( "SVPWM/扇区判断/Constant8" ) ,
TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 24 , TARGET_STRING (
"SVPWM/扇区判断/Constant9" ) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 25
, TARGET_STRING ( "SVPWM/扇区判断/Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 4
, 0 } , { 26 , TARGET_STRING ( "SVPWM/扇区判断/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 4 , 0 } , { 27 , TARGET_STRING ( "SVPWM/扇区判断/Gain2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 4 , 0 } , { 28 , TARGET_STRING (
"SVPWM/扇区判断/Switch" ) , TARGET_STRING ( "Threshold" ) , 0 , 4 , 0 } , {
29 , TARGET_STRING ( "SVPWM/扇区判断/Switch1" ) , TARGET_STRING ( "Threshold"
) , 0 , 4 , 0 } , { 30 , TARGET_STRING ( "SVPWM/扇区判断/Switch2" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 4 , 0 } , { 31 , TARGET_STRING (
"SVPWM/时间计算/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 32
, TARGET_STRING ( "SVPWM/时间计算/Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 4
, 0 } , { 33 , TARGET_STRING ( "SVPWM/时间计算/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 4 , 0 } , { 34 , TARGET_STRING ( "SVPWM/时间计算/Gain2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 4 , 0 } , { 35 , TARGET_STRING (
"SVPWM/时间计算/Gain3" ) , TARGET_STRING ( "Gain" ) , 0 , 4 , 0 } , { 36 ,
TARGET_STRING ( "SVPWM/载波调制/Repeating Sequence" ) , TARGET_STRING (
"rep_seq_y" ) , 0 , 5 , 0 } , { 37 , TARGET_STRING (
"SVPWM/Universal Bridge/Model/0 4" ) , TARGET_STRING ( "Value" ) , 0 , 4 , 0
} , { 38 , TARGET_STRING ( "SVPWM/Universal Bridge/Model/1//Ron" ) ,
TARGET_STRING ( "Gain" ) , 0 , 4 , 0 } , { 39 , TARGET_STRING (
"SVPWM/Universal Bridge/Model/Saturation" ) , TARGET_STRING ( "UpperLimit" )
, 0 , 4 , 0 } , { 40 , TARGET_STRING (
"SVPWM/Universal Bridge/Model/Saturation" ) , TARGET_STRING ( "LowerLimit" )
, 0 , 4 , 0 } , { 41 , TARGET_STRING ( "SVPWM/Universal Bridge/Model/Switch"
) , TARGET_STRING ( "Threshold" ) , 0 , 4 , 0 } , { 42 , TARGET_STRING (
"SVPWM/Universal Bridge/Model/Unit Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 4 , 0 } , { 43 , TARGET_STRING (
"SVPWM/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "AS_param"
) , 0 , 6 , 0 } , { 44 , TARGET_STRING (
"SVPWM/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "BS_param"
) , 0 , 7 , 0 } , { 45 , TARGET_STRING (
"SVPWM/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "CS_param"
) , 0 , 8 , 0 } , { 46 , TARGET_STRING (
"SVPWM/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "DS_param"
) , 0 , 9 , 0 } , { 47 , TARGET_STRING (
"SVPWM/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "X0_param"
) , 0 , 2 , 0 } , { 48 , TARGET_STRING (
"SVPWM/扇区判断/abc to Alpha-Beta-Zero/Gain1" ) , TARGET_STRING ( "Gain" ) ,
0 , 4 , 0 } , { 49 , TARGET_STRING (
"SVPWM/扇区判断/abc to Alpha-Beta-Zero/Gain3" ) , TARGET_STRING ( "Gain" ) ,
0 , 10 , 0 } , { 50 , TARGET_STRING (
"SVPWM/载波调制/Repeating Sequence/Constant" ) , TARGET_STRING ( "Value" ) ,
0 , 4 , 0 } , { 51 , TARGET_STRING (
"SVPWM/载波调制/Repeating Sequence/Look-Up Table1" ) , TARGET_STRING (
"BreakpointsForDimension1" ) , 0 , 5 , 0 } , { 52 , TARGET_STRING (
"SVPWM/Three-Phase V-I Measurement/Model/I A:/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 4 , 0 } , { 53 , TARGET_STRING (
"SVPWM/Three-Phase V-I Measurement/Model/I B:/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 4 , 0 } , { 54 , TARGET_STRING (
"SVPWM/Three-Phase V-I Measurement/Model/I C:/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 4 , 0 } , { 55 , TARGET_STRING (
"SVPWM/Three-Phase V-I Measurement/Model/U AB:/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 4 , 0 } , { 56 , TARGET_STRING (
"SVPWM/Three-Phase V-I Measurement/Model/U BC:/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 4 , 0 } , { 57 , TARGET_STRING (
"SVPWM/Three-Phase V-I Measurement/Model/U CA:/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 4 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 58 , TARGET_STRING (
"_Vdc2f2SVPWM_sldd_" ) , 0 , 4 , 0 } , { 59 , TARGET_STRING (
"_m2f2SVPWM_sldd_" ) , 0 , 4 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . en3wjyqdju [ 0 ] , & rtB .
dqwh3ca4xi [ 0 ] , & rtB . eiihwmjf1j [ 0 ] , & rtB . pjks0m0pmo [ 0 ] , &
rtB . iusmv3md3a [ 0 ] , & rtB . exnbmwz04i [ 0 ] , & rtB . l35oohpje4 [ 0 ]
, & rtB . a1jevbgg4x [ 0 ] , & rtB . jbljr5tq4u [ 0 ] , & rtP . SineWave_Bias
, & rtP . SineWave_Freq , & rtP . SineWave_Phase [ 0 ] , & rtP .
Gain_Gain_jtfu24yj43 , & rtP . Kv_Gain , & rtP . Kv1_Gain , & rtP .
Constant_Value , & rtP . Constant1_Value , & rtP . Constant2_Value , & rtP .
Constant3_Value , & rtP . Constant4_Value , & rtP . Constant5_Value , & rtP .
Constant6_Value , & rtP . Constant7_Value , & rtP . Constant8_Value , & rtP .
Constant9_Value , & rtP . Gain_Gain , & rtP . Gain1_Gain_gnhgdq2zzz , & rtP .
Gain2_Gain_lxbjdzc3ab , & rtP . Switch_Threshold , & rtP . Switch1_Threshold
, & rtP . Switch2_Threshold , & rtP . Constant_Value_ffpsqzlbdy , & rtP .
Gain_Gain_o3ussx2pey , & rtP . Gain1_Gain_a1wggbqhys , & rtP . Gain2_Gain , &
rtP . Gain3_Gain , & rtP . RepeatingSequence_rep_seq_y [ 0 ] , & rtP .
u4_Value , & rtP . uRon_Gain , & rtP . Saturation_UpperSat , & rtP .
Saturation_LowerSat , & rtP . Switch_Threshold_jdj5zhvmwv , & rtP .
UnitDelay_InitialCondition , & rtP . StateSpace_AS_param [ 0 ] , & rtP .
StateSpace_BS_param [ 0 ] , & rtP . StateSpace_CS_param [ 0 ] , & rtP .
StateSpace_DS_param [ 0 ] , & rtP . StateSpace_X0_param [ 0 ] , & rtP .
Gain1_Gain , & rtP . Gain3_Gain_byafyznv0k [ 0 ] , & rtP .
Constant_Value_kboz1tvd2g , & rtP . LookUpTable1_bp01Data [ 0 ] , & rtP .
donotdeletethisgain_Gain_f0n5ohe52n , & rtP .
donotdeletethisgain_Gain_cljduyemw5 , & rtP .
donotdeletethisgain_Gain_fprakrrw0l , & rtP . donotdeletethisgain_Gain , &
rtP . donotdeletethisgain_Gain_d5clbn1ab5 , & rtP .
donotdeletethisgain_Gain_dii0kh5zng , & rtP . _Vdc2f2SVPWM_sldd_ , & rtP .
_m2f2SVPWM_sldd_ , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , ( uint8_T )
SS_BOOLEAN , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_SCALAR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 14 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 16 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 18 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 20 , 2
, 0 } } ; static const uint_T rtDimensionArray [ ] = { 3 , 1 , 2 , 1 , 6 , 1
, 12 , 1 , 1 , 1 , 1 , 3 , 6 , 6 , 6 , 7 , 12 , 6 , 12 , 7 , 3 , 3 } ; static
const real_T rtcapiStoredFloats [ ] = { 1.0E-6 , 0.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , (
int8_T ) 1 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ]
, ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 0 , ( uint8_T ) 0
} } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals ,
9 , rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 49 ,
rtModelParameters , 2 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 2154651661U , 2785804129U , 50835171U , 380630390U } , ( NULL ) , 0 , (
boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * SVPWM_GetCAPIStaticMap ( void ) { return &
mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void SVPWM_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void SVPWM_host_InitializeDataMapInfo ( SVPWM_host_DataMapInfo_T * dataMap ,
const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
