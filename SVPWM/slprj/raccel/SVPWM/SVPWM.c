#include "SVPWM.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include "SVPWM_private.h"
#include "rt_logging_mmi.h"
#include "SVPWM_capi.h"
#include "SVPWM_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.9 (R2023a) 19-Nov-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
const real_T SVPWM_RGND = 0.0 ; B rtB ; DW rtDW ; static SimStruct model_S ;
SimStruct * const rtS = & model_S ; real_T look1_binlxpw ( real_T u0 , const
real_T bp0 [ ] , const real_T table [ ] , uint32_T maxIndex ) { real_T frac ;
real_T yL_0d0 ; uint32_T bpIdx ; uint32_T iLeft ; uint32_T iRght ; if ( u0 <=
bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [
0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx = maxIndex >> 1U ; iLeft
= 0U ; iRght = maxIndex ; while ( iRght - iLeft > 1U ) { if ( u0 < bp0 [
bpIdx ] ) { iRght = bpIdx ; } else { iLeft = bpIdx ; } bpIdx = ( iRght +
iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0
[ iLeft ] ) ; } else { iLeft = maxIndex - 1U ; frac = ( u0 - bp0 [ maxIndex -
1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex - 1U ] ) ; } yL_0d0 = table [
iLeft ] ; return ( table [ iLeft + 1U ] - yL_0d0 ) * frac + yL_0d0 ; } void
MdlInitialize ( void ) { int32_T i ; { int32_T i , j ; real_T * As = ( real_T
* ) rtDW . mpy40nreq3 . AS ; real_T * Bs = ( real_T * ) rtDW . mpy40nreq3 .
BS ; real_T * Cs = ( real_T * ) rtDW . mpy40nreq3 . CS ; real_T * Ds = (
real_T * ) rtDW . mpy40nreq3 . DS ; real_T * X0 = ( real_T * ) & rtDW .
jiydzlq20v [ 0 ] ; for ( i = 0 ; i < 6 ; i ++ ) { X0 [ i ] = ( rtP .
StateSpace_X0_param [ i ] ) ; } for ( i = 0 ; i < 6 ; i ++ ) { for ( j = 0 ;
j < 6 ; j ++ ) As [ i * 6 + j ] = ( rtP . StateSpace_AS_param [ i + j * 6 ] )
; for ( j = 0 ; j < 7 ; j ++ ) Bs [ i * 7 + j ] = ( rtP . StateSpace_BS_param
[ i + j * 6 ] ) ; } for ( i = 0 ; i < 12 ; i ++ ) { for ( j = 0 ; j < 6 ; j
++ ) Cs [ i * 6 + j ] = ( rtP . StateSpace_CS_param [ i + j * 12 ] ) ; } for
( i = 0 ; i < 12 ; i ++ ) { for ( j = 0 ; j < 7 ; j ++ ) Ds [ i * 7 + j ] = (
rtP . StateSpace_DS_param [ i + j * 12 ] ) ; } { int_T * switch_status = (
int_T * ) rtDW . mpy40nreq3 . SWITCH_STATUS ; int_T * gState = ( int_T * )
rtDW . mpy40nreq3 . G_STATE ; real_T * yswitch = ( real_T * ) rtDW .
mpy40nreq3 . Y_SWITCH ; int_T * switchTypes = ( int_T * ) rtDW . mpy40nreq3 .
SWITCH_TYPES ; int_T * idxOutSw = ( int_T * ) rtDW . mpy40nreq3 . IDX_OUT_SW
; int_T * switch_status_init = ( int_T * ) rtDW . mpy40nreq3 .
SWITCH_STATUS_INIT ; switch_status [ 0 ] = 0 ; switch_status_init [ 0 ] = 0 ;
gState [ 0 ] = ( int_T ) 0.0 ; yswitch [ 0 ] = 1 / 0.001 ; switchTypes [ 0 ]
= ( int_T ) 7.0 ; idxOutSw [ 0 ] = ( ( int_T ) 0.0 ) - 1 ; switch_status [ 1
] = 0 ; switch_status_init [ 1 ] = 0 ; gState [ 1 ] = ( int_T ) 0.0 ; yswitch
[ 1 ] = 1 / 0.001 ; switchTypes [ 1 ] = ( int_T ) 7.0 ; idxOutSw [ 1 ] = ( (
int_T ) 0.0 ) - 1 ; switch_status [ 2 ] = 0 ; switch_status_init [ 2 ] = 0 ;
gState [ 2 ] = ( int_T ) 0.0 ; yswitch [ 2 ] = 1 / 0.001 ; switchTypes [ 2 ]
= ( int_T ) 7.0 ; idxOutSw [ 2 ] = ( ( int_T ) 0.0 ) - 1 ; switch_status [ 3
] = 0 ; switch_status_init [ 3 ] = 0 ; gState [ 3 ] = ( int_T ) 0.0 ; yswitch
[ 3 ] = 1 / 0.001 ; switchTypes [ 3 ] = ( int_T ) 7.0 ; idxOutSw [ 3 ] = ( (
int_T ) 0.0 ) - 1 ; switch_status [ 4 ] = 0 ; switch_status_init [ 4 ] = 0 ;
gState [ 4 ] = ( int_T ) 0.0 ; yswitch [ 4 ] = 1 / 0.001 ; switchTypes [ 4 ]
= ( int_T ) 7.0 ; idxOutSw [ 4 ] = ( ( int_T ) 0.0 ) - 1 ; switch_status [ 5
] = 0 ; switch_status_init [ 5 ] = 0 ; gState [ 5 ] = ( int_T ) 0.0 ; yswitch
[ 5 ] = 1 / 0.001 ; switchTypes [ 5 ] = ( int_T ) 7.0 ; idxOutSw [ 5 ] = ( (
int_T ) 0.0 ) - 1 ; } } for ( i = 0 ; i < 6 ; i ++ ) { rtDW . djelptucdk [ i
] = rtP . UnitDelay_InitialCondition ; } } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [
] = { 3 } ; static int_T rt_ScopeSignalNumDimensions [ ] = { 1 } ; static
int_T rt_ScopeSignalDimensions [ ] = { 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 1 , 1 , 1 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ; static
char_T rt_ScopeBlockName [ ] = "SVPWM/Scope" ; static int_T rt_ScopeFrameData
[ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . h21b5dj40j . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "VabcL" , 1 , 0 , 1 , 1.0E-6 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . h21b5dj40j .
LoggedData == ( NULL ) ) return ; } { rtDW . mpy40nreq3 . AS = ( real_T * )
calloc ( 6 * 6 , sizeof ( real_T ) ) ; rtDW . mpy40nreq3 . BS = ( real_T * )
calloc ( 6 * 7 , sizeof ( real_T ) ) ; rtDW . mpy40nreq3 . CS = ( real_T * )
calloc ( 12 * 6 , sizeof ( real_T ) ) ; rtDW . mpy40nreq3 . DS = ( real_T * )
calloc ( 12 * 7 , sizeof ( real_T ) ) ; rtDW . mpy40nreq3 . DX_COL = ( real_T
* ) calloc ( 12 , sizeof ( real_T ) ) ; rtDW . mpy40nreq3 . TMP2 = ( real_T *
) calloc ( 7 , sizeof ( real_T ) ) ; rtDW . mpy40nreq3 . BD_COL = ( real_T *
) calloc ( 6 , sizeof ( real_T ) ) ; rtDW . mpy40nreq3 . TMP1 = ( real_T * )
calloc ( 6 , sizeof ( real_T ) ) ; rtDW . mpy40nreq3 . XTMP = ( real_T * )
calloc ( 6 , sizeof ( real_T ) ) ; rtDW . mpy40nreq3 . SWITCH_STATUS = (
int_T * ) calloc ( 6 , sizeof ( int_T ) ) ; rtDW . mpy40nreq3 . SW_CHG = (
int_T * ) calloc ( 6 , sizeof ( int_T ) ) ; rtDW . mpy40nreq3 . G_STATE = (
int_T * ) calloc ( 6 , sizeof ( int_T ) ) ; rtDW . mpy40nreq3 . Y_SWITCH = (
real_T * ) calloc ( 6 , sizeof ( real_T ) ) ; rtDW . mpy40nreq3 .
SWITCH_TYPES = ( int_T * ) calloc ( 6 , sizeof ( int_T ) ) ; rtDW .
mpy40nreq3 . IDX_OUT_SW = ( int_T * ) calloc ( 6 , sizeof ( int_T ) ) ; rtDW
. mpy40nreq3 . SWITCH_STATUS_INIT = ( int_T * ) calloc ( 6 , sizeof ( int_T )
) ; rtDW . mpy40nreq3 . USWLAST = ( real_T * ) calloc ( 6 , sizeof ( real_T )
) ; } MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T hu0x51y4wj
[ 3 ] ; real_T bbv01k1p2n ; real_T bucp1be4i0 ; real_T irdajucxg3 ; real_T
jpqk5zk4br ; int32_T i ; boolean_T iusmv3md3a ; { real_T accum ; int_T *
switch_status = ( int_T * ) rtDW . mpy40nreq3 . SWITCH_STATUS ; int_T *
switch_status_init = ( int_T * ) rtDW . mpy40nreq3 . SWITCH_STATUS_INIT ;
int_T * SwitchChange = ( int_T * ) rtDW . mpy40nreq3 . SW_CHG ; int_T *
gState = ( int_T * ) rtDW . mpy40nreq3 . G_STATE ; real_T * yswitch = (
real_T * ) rtDW . mpy40nreq3 . Y_SWITCH ; int_T * switchTypes = ( int_T * )
rtDW . mpy40nreq3 . SWITCH_TYPES ; int_T * idxOutSw = ( int_T * ) rtDW .
mpy40nreq3 . IDX_OUT_SW ; real_T * DxCol = ( real_T * ) rtDW . mpy40nreq3 .
DX_COL ; real_T * tmp2 = ( real_T * ) rtDW . mpy40nreq3 . TMP2 ; real_T *
BDcol = ( real_T * ) rtDW . mpy40nreq3 . BD_COL ; real_T * tmp1 = ( real_T *
) rtDW . mpy40nreq3 . TMP1 ; real_T * uswlast = ( real_T * ) rtDW .
mpy40nreq3 . USWLAST ; int_T newState ; int_T swChanged = 0 ; int loopsToDo =
20 ; real_T temp ; memcpy ( switch_status_init , switch_status , 6 * sizeof (
int_T ) ) ; memcpy ( uswlast , & rtB . a1jevbgg4x [ 0 ] , 6 * sizeof ( real_T
) ) ; do { if ( loopsToDo == 1 ) { swChanged = 0 ; { int_T i1 ; for ( i1 = 0
; i1 < 6 ; i1 ++ ) { swChanged = ( ( SwitchChange [ i1 ] = switch_status_init
[ i1 ] - switch_status [ i1 ] ) != 0 ) ? 1 : swChanged ; switch_status [ i1 ]
= switch_status_init [ i1 ] ; } } } else { real_T * Cs = ( real_T * ) rtDW .
mpy40nreq3 . CS ; real_T * Ds = ( real_T * ) rtDW . mpy40nreq3 . DS ; { int_T
i1 ; real_T * y0 = & rtB . a1jevbgg4x [ 0 ] ; for ( i1 = 0 ; i1 < 12 ; i1 ++
) { accum = 0.0 ; { int_T i2 ; real_T * xd = & rtDW . jiydzlq20v [ 0 ] ; for
( i2 = 0 ; i2 < 6 ; i2 ++ ) { accum += * ( Cs ++ ) * xd [ i2 ] ; } } { int_T
i2 ; const real_T * u0 ; for ( i2 = 0 ; i2 < 6 ; i2 ++ ) { accum += * ( Ds ++
) * 0.0 ; } accum += * ( Ds ++ ) * rtP . _Vdc2f2SVPWM_sldd_ ; } y0 [ i1 ] =
accum ; } } swChanged = 0 ; { int_T i1 ; real_T * y0 = & rtB . a1jevbgg4x [ 0
] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { newState = ( ( y0 [ i1 ] > 0.0 ) && (
gState [ i1 ] > 0 ) ) || ( y0 [ i1 ] < 0.0 ) ? 1 : ( ( ( y0 [ i1 ] > 0.0 ) &&
gState [ i1 ] == 0 ) ? 0 : switch_status [ i1 ] ) ; swChanged = ( (
SwitchChange [ i1 ] = newState - switch_status [ i1 ] ) != 0 ) ? 1 :
swChanged ; switch_status [ i1 ] = newState ; } } } if ( swChanged ) { real_T
* As = ( real_T * ) rtDW . mpy40nreq3 . AS ; real_T * Cs = ( real_T * ) rtDW
. mpy40nreq3 . CS ; real_T * Bs = ( real_T * ) rtDW . mpy40nreq3 . BS ;
real_T * Ds = ( real_T * ) rtDW . mpy40nreq3 . DS ; real_T a1 ; { int_T i1 ;
for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { if ( SwitchChange [ i1 ] != 0 ) { a1 =
1000.0 * SwitchChange [ i1 ] ; temp = 1 / ( 1 - Ds [ i1 * 8 ] * a1 ) ; {
int_T i2 ; for ( i2 = 0 ; i2 < 12 ; i2 ++ ) { DxCol [ i2 ] = Ds [ i2 * 7 + i1
] * temp * a1 ; } } DxCol [ i1 ] = temp ; { int_T i2 ; for ( i2 = 0 ; i2 < 6
; i2 ++ ) { BDcol [ i2 ] = Bs [ i2 * 7 + i1 ] * a1 ; } } memcpy ( tmp1 , & Cs
[ i1 * 6 ] , 6 * sizeof ( real_T ) ) ; memset ( & Cs [ i1 * 6 ] , '\0' , 6 *
sizeof ( real_T ) ) ; memcpy ( tmp2 , & Ds [ i1 * 7 ] , 7 * sizeof ( real_T )
) ; memset ( & Ds [ i1 * 7 ] , '\0' , 7 * sizeof ( real_T ) ) ; { int_T i2 ;
for ( i2 = 0 ; i2 < 12 ; i2 ++ ) { a1 = DxCol [ i2 ] ; { int_T i3 ; for ( i3
= 0 ; i3 < 6 ; i3 ++ ) { Cs [ i2 * 6 + i3 ] += a1 * tmp1 [ i3 ] ; } } { int_T
i3 ; for ( i3 = 0 ; i3 < 7 ; i3 ++ ) { Ds [ i2 * 7 + i3 ] += a1 * tmp2 [ i3 ]
; } } } } { int_T i2 ; for ( i2 = 0 ; i2 < 6 ; i2 ++ ) { a1 = BDcol [ i2 ] ;
{ int_T i3 ; for ( i3 = 0 ; i3 < 6 ; i3 ++ ) { As [ i2 * 6 + i3 ] += a1 * Cs
[ i1 * 6 + i3 ] ; } } { int_T i3 ; for ( i3 = 0 ; i3 < 7 ; i3 ++ ) { Bs [ i2
* 7 + i3 ] += a1 * Ds [ i1 * 7 + i3 ] ; } } } } } } } } } while ( swChanged >
0 && -- loopsToDo > 0 ) ; if ( loopsToDo == 0 ) { real_T * Cs = ( real_T * )
rtDW . mpy40nreq3 . CS ; real_T * Ds = ( real_T * ) rtDW . mpy40nreq3 . DS ;
{ int_T i1 ; real_T * y0 = & rtB . a1jevbgg4x [ 0 ] ; for ( i1 = 0 ; i1 < 12
; i1 ++ ) { accum = 0.0 ; { int_T i2 ; real_T * xd = & rtDW . jiydzlq20v [ 0
] ; for ( i2 = 0 ; i2 < 6 ; i2 ++ ) { accum += * ( Cs ++ ) * xd [ i2 ] ; } }
{ int_T i2 ; const real_T * u0 ; for ( i2 = 0 ; i2 < 6 ; i2 ++ ) { accum += *
( Ds ++ ) * 0.0 ; } accum += * ( Ds ++ ) * rtP . _Vdc2f2SVPWM_sldd_ ; } y0 [
i1 ] = accum ; } } } { int_T i1 ; real_T * y1 = & rtB . jbljr5tq4u [ 0 ] ;
for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { y1 [ i1 ] = ( real_T ) switch_status [ i1 ]
; } } } bucp1be4i0 = look1_binlxpw ( muDoubleScalarRem ( ssGetT ( rtS ) , rtP
. Constant_Value_kboz1tvd2g ) , rtP . LookUpTable1_bp01Data , rtP .
RepeatingSequence_rep_seq_y , 2U ) ; bbv01k1p2n = rtP . SineWave_Freq *
ssGetTaskTime ( rtS , 0 ) ; irdajucxg3 = muDoubleScalarSin ( bbv01k1p2n + rtP
. SineWave_Phase [ 0 ] ) * rtP . _m2f2SVPWM_sldd_ + rtP . SineWave_Bias ;
jpqk5zk4br = muDoubleScalarSin ( bbv01k1p2n + rtP . SineWave_Phase [ 1 ] ) *
rtP . _m2f2SVPWM_sldd_ + rtP . SineWave_Bias ; bbv01k1p2n = muDoubleScalarSin
( bbv01k1p2n + rtP . SineWave_Phase [ 2 ] ) * rtP . _m2f2SVPWM_sldd_ + rtP .
SineWave_Bias ; for ( i = 0 ; i < 3 ; i ++ ) { hu0x51y4wj [ i ] = ( ( rtP .
Gain3_Gain_byafyznv0k [ i + 3 ] * jpqk5zk4br + rtP . Gain3_Gain_byafyznv0k [
i ] * irdajucxg3 ) + rtP . Gain3_Gain_byafyznv0k [ i + 6 ] * bbv01k1p2n ) *
rtP . Gain1_Gain ; } irdajucxg3 = rtP . Gain_Gain * hu0x51y4wj [ 0 ] ; if (
hu0x51y4wj [ 1 ] > rtP . Switch_Threshold ) { bbv01k1p2n = rtP .
Constant_Value ; } else { bbv01k1p2n = rtP . Constant1_Value ; } if (
hu0x51y4wj [ 1 ] - irdajucxg3 > rtP . Switch1_Threshold ) { jpqk5zk4br = rtP
. Constant_Value ; } else { jpqk5zk4br = rtP . Constant1_Value ; } if (
hu0x51y4wj [ 1 ] + irdajucxg3 > rtP . Switch2_Threshold ) { irdajucxg3 = rtP
. Constant_Value ; } else { irdajucxg3 = rtP . Constant1_Value ; } switch ( (
int32_T ) ( ( rtP . Gain1_Gain_gnhgdq2zzz * bbv01k1p2n + rtP .
Gain2_Gain_lxbjdzc3ab * jpqk5zk4br ) + irdajucxg3 ) ) { case 0 : irdajucxg3 =
rtP . Constant2_Value ; break ; case 1 : irdajucxg3 = rtP . Constant3_Value ;
break ; case 2 : irdajucxg3 = rtP . Constant4_Value ; break ; case 3 :
irdajucxg3 = rtP . Constant5_Value ; break ; case 4 : irdajucxg3 = rtP .
Constant6_Value ; break ; case 5 : irdajucxg3 = rtP . Constant7_Value ; break
; case 6 : irdajucxg3 = rtP . Constant8_Value ; break ; default : irdajucxg3
= rtP . Constant9_Value ; break ; } bbv01k1p2n = rtP . Gain_Gain_o3ussx2pey *
hu0x51y4wj [ 0 ] ; jpqk5zk4br = rtP . Gain1_Gain_a1wggbqhys * hu0x51y4wj [ 1
] ; switch ( ( int32_T ) irdajucxg3 ) { case 1 : rtB . eiihwmjf1j [ 0 ] =
bbv01k1p2n - jpqk5zk4br ; rtB . eiihwmjf1j [ 1 ] = hu0x51y4wj [ 1 ] ; break ;
case 2 : rtB . eiihwmjf1j [ 0 ] = bbv01k1p2n + jpqk5zk4br ; rtB . eiihwmjf1j
[ 1 ] = jpqk5zk4br - bbv01k1p2n ; break ; case 3 : rtB . eiihwmjf1j [ 0 ] =
hu0x51y4wj [ 1 ] ; rtB . eiihwmjf1j [ 1 ] = ( 0.0 - bbv01k1p2n ) - jpqk5zk4br
; break ; case 4 : rtB . eiihwmjf1j [ 0 ] = jpqk5zk4br - bbv01k1p2n ; rtB .
eiihwmjf1j [ 1 ] = rtP . Gain2_Gain * hu0x51y4wj [ 1 ] ; break ; case 5 : rtB
. eiihwmjf1j [ 0 ] = ( 0.0 - bbv01k1p2n ) - jpqk5zk4br ; rtB . eiihwmjf1j [ 1
] = bbv01k1p2n - jpqk5zk4br ; break ; default : rtB . eiihwmjf1j [ 0 ] = rtP
. Gain3_Gain * hu0x51y4wj [ 1 ] ; rtB . eiihwmjf1j [ 1 ] = bbv01k1p2n +
jpqk5zk4br ; break ; } bbv01k1p2n = ( ( rtP . Constant_Value_ffpsqzlbdy - rtB
. eiihwmjf1j [ 1 ] ) - rtB . eiihwmjf1j [ 0 ] ) * rtP . Gain_Gain_jtfu24yj43
; switch ( ( int32_T ) irdajucxg3 ) { case 1 : hu0x51y4wj [ 0 ] = bbv01k1p2n
; hu0x51y4wj [ 1 ] = rtB . eiihwmjf1j [ 0 ] + bbv01k1p2n ; hu0x51y4wj [ 2 ] =
( rtB . eiihwmjf1j [ 0 ] + rtB . eiihwmjf1j [ 1 ] ) + bbv01k1p2n ; break ;
case 2 : hu0x51y4wj [ 0 ] = rtB . eiihwmjf1j [ 1 ] + bbv01k1p2n ; hu0x51y4wj
[ 1 ] = bbv01k1p2n ; hu0x51y4wj [ 2 ] = ( rtB . eiihwmjf1j [ 0 ] + rtB .
eiihwmjf1j [ 1 ] ) + bbv01k1p2n ; break ; case 3 : hu0x51y4wj [ 0 ] = ( rtB .
eiihwmjf1j [ 0 ] + rtB . eiihwmjf1j [ 1 ] ) + bbv01k1p2n ; hu0x51y4wj [ 1 ] =
bbv01k1p2n ; hu0x51y4wj [ 2 ] = rtB . eiihwmjf1j [ 0 ] + bbv01k1p2n ; break ;
case 4 : hu0x51y4wj [ 0 ] = ( rtB . eiihwmjf1j [ 0 ] + rtB . eiihwmjf1j [ 1 ]
) + bbv01k1p2n ; hu0x51y4wj [ 1 ] = rtB . eiihwmjf1j [ 1 ] + bbv01k1p2n ;
hu0x51y4wj [ 2 ] = bbv01k1p2n ; break ; case 5 : hu0x51y4wj [ 0 ] = rtB .
eiihwmjf1j [ 0 ] + bbv01k1p2n ; hu0x51y4wj [ 1 ] = ( rtB . eiihwmjf1j [ 0 ] +
rtB . eiihwmjf1j [ 1 ] ) + bbv01k1p2n ; hu0x51y4wj [ 2 ] = bbv01k1p2n ; break
; default : hu0x51y4wj [ 0 ] = bbv01k1p2n ; hu0x51y4wj [ 1 ] = ( rtB .
eiihwmjf1j [ 0 ] + rtB . eiihwmjf1j [ 1 ] ) + bbv01k1p2n ; hu0x51y4wj [ 2 ] =
rtB . eiihwmjf1j [ 1 ] + bbv01k1p2n ; break ; } iusmv3md3a = ( bucp1be4i0 >
hu0x51y4wj [ 0 ] ) ; rtB . iusmv3md3a [ 0 ] = iusmv3md3a ; rtB . pjks0m0pmo [
0 ] = ! iusmv3md3a ; iusmv3md3a = ( bucp1be4i0 > hu0x51y4wj [ 1 ] ) ; rtB .
iusmv3md3a [ 1 ] = iusmv3md3a ; rtB . pjks0m0pmo [ 1 ] = ! iusmv3md3a ;
iusmv3md3a = ( bucp1be4i0 > hu0x51y4wj [ 2 ] ) ; rtB . iusmv3md3a [ 2 ] =
iusmv3md3a ; rtB . pjks0m0pmo [ 2 ] = ! iusmv3md3a ; rtB . exnbmwz04i [ 0 ] =
rtB . iusmv3md3a [ 0 ] ; rtB . exnbmwz04i [ 1 ] = rtB . pjks0m0pmo [ 0 ] ;
rtB . exnbmwz04i [ 2 ] = rtB . iusmv3md3a [ 1 ] ; rtB . exnbmwz04i [ 3 ] =
rtB . pjks0m0pmo [ 1 ] ; rtB . exnbmwz04i [ 4 ] = rtB . iusmv3md3a [ 2 ] ;
rtB . exnbmwz04i [ 5 ] = rtB . pjks0m0pmo [ 2 ] ; for ( i = 0 ; i < 6 ; i ++
) { if ( rtB . jbljr5tq4u [ i ] >= rtP . Switch_Threshold_jdj5zhvmwv ) {
bbv01k1p2n = rtP . uRon_Gain * rtB . a1jevbgg4x [ i ] ; } else { bbv01k1p2n =
rtP . u4_Value ; } if ( bbv01k1p2n > rtP . Saturation_UpperSat ) { rtB .
l35oohpje4 [ i ] = rtP . Saturation_UpperSat ; } else if ( bbv01k1p2n < rtP .
Saturation_LowerSat ) { rtB . l35oohpje4 [ i ] = rtP . Saturation_LowerSat ;
} else { rtB . l35oohpje4 [ i ] = bbv01k1p2n ; } } rtB . dqwh3ca4xi [ 0 ] =
rtP . donotdeletethisgain_Gain * rtB . a1jevbgg4x [ 6 ] * rtP . Kv1_Gain ;
rtB . dqwh3ca4xi [ 1 ] = rtP . donotdeletethisgain_Gain_d5clbn1ab5 * rtB .
a1jevbgg4x [ 7 ] * rtP . Kv1_Gain ; rtB . dqwh3ca4xi [ 2 ] = rtP .
donotdeletethisgain_Gain_dii0kh5zng * rtB . a1jevbgg4x [ 8 ] * rtP . Kv1_Gain
; if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * )
rtDW . h21b5dj40j . LoggedData ; LogVar * var = svar -> signals . values ; {
double locTime = ssGetTaskTime ( rtS , 1 ) ; rt_UpdateLogVar ( ( LogVar * )
svar -> time , & locTime , 0 ) ; } { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB .
dqwh3ca4xi [ 0 ] ; up0 [ 1 ] = rtB . dqwh3ca4xi [ 1 ] ; up0 [ 2 ] = rtB .
dqwh3ca4xi [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } rtB .
en3wjyqdju [ 0 ] = rtP . donotdeletethisgain_Gain_f0n5ohe52n * rtB .
a1jevbgg4x [ 9 ] * rtP . Kv_Gain ; rtB . en3wjyqdju [ 1 ] = rtP .
donotdeletethisgain_Gain_cljduyemw5 * rtB . a1jevbgg4x [ 10 ] * rtP . Kv_Gain
; rtB . en3wjyqdju [ 2 ] = rtP . donotdeletethisgain_Gain_fprakrrw0l * rtB .
a1jevbgg4x [ 11 ] * rtP . Kv_Gain ; UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlUpdate (
int_T tid ) { int32_T i ; { const real_T * As = ( real_T * ) rtDW .
mpy40nreq3 . AS ; const real_T * Bs = ( real_T * ) rtDW . mpy40nreq3 . BS ;
real_T * xtmp = ( real_T * ) rtDW . mpy40nreq3 . XTMP ; real_T accum ; {
int_T i1 ; real_T * xd = & rtDW . jiydzlq20v [ 0 ] ; for ( i1 = 0 ; i1 < 6 ;
i1 ++ ) { accum = 0.0 ; { int_T i2 ; real_T * xd = & rtDW . jiydzlq20v [ 0 ]
; for ( i2 = 0 ; i2 < 6 ; i2 ++ ) { accum += * ( As ++ ) * xd [ i2 ] ; } } {
int_T i2 ; const real_T * u0 ; for ( i2 = 0 ; i2 < 6 ; i2 ++ ) { accum += * (
Bs ++ ) * 0.0 ; } accum += * ( Bs ++ ) * rtP . _Vdc2f2SVPWM_sldd_ ; } xtmp [
i1 ] = accum ; } } { int_T i1 ; real_T * xd = & rtDW . jiydzlq20v [ 0 ] ; for
( i1 = 0 ; i1 < 6 ; i1 ++ ) { xd [ i1 ] = xtmp [ i1 ] ; } } { int_T * gState
= ( int_T * ) rtDW . mpy40nreq3 . G_STATE ; { int_T i1 ; const real_T * u1 =
& rtB . exnbmwz04i [ 0 ] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { * ( gState ++ )
= ( int_T ) u1 [ i1 ] ; } } } } for ( i = 0 ; i < 6 ; i ++ ) { rtDW .
djelptucdk [ i ] = rtB . l35oohpje4 [ i ] ; } UNUSED_PARAMETER ( tid ) ; }
void MdlUpdateTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlTerminate ( void ) { { free ( rtDW . mpy40nreq3 . AS ) ; free ( rtDW .
mpy40nreq3 . BS ) ; free ( rtDW . mpy40nreq3 . CS ) ; free ( rtDW .
mpy40nreq3 . DS ) ; free ( rtDW . mpy40nreq3 . DX_COL ) ; free ( rtDW .
mpy40nreq3 . TMP2 ) ; free ( rtDW . mpy40nreq3 . BD_COL ) ; free ( rtDW .
mpy40nreq3 . TMP1 ) ; free ( rtDW . mpy40nreq3 . XTMP ) ; free ( rtDW .
mpy40nreq3 . G_STATE ) ; free ( rtDW . mpy40nreq3 . SWITCH_STATUS ) ; free (
rtDW . mpy40nreq3 . SW_CHG ) ; free ( rtDW . mpy40nreq3 . SWITCH_STATUS_INIT
) ; } } static void mr_SVPWM_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) ; static void
mr_SVPWM_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j , const
void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_SVPWM_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_SVPWM_restoreDataFromMxArray ( void * destData , const mxArray * srcArray
, mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * ) destData , (
const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ,
numBytes ) ; } static void mr_SVPWM_cacheBitFieldToMxArray ( mxArray *
destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_SVPWM_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j ,
uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_SVPWM_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i ,
int j , uint_T numBits ) ; static uint_T mr_SVPWM_extractBitFieldFromMxArray
( const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) { const
uint_T varVal = ( uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i ,
j ) ) ; return varVal & ( ( 1u << numBits ) - 1u ) ; } static void
mr_SVPWM_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int
j , mwIndex offset , const void * srcData , size_t numBytes ) ; static void
mr_SVPWM_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int
j , mwIndex offset , const void * srcData , size_t numBytes ) { uint8_T *
varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber ( destArray , i , j )
) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes ] , ( const uint8_T
* ) srcData , numBytes ) ; } static void
mr_SVPWM_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ; static
void mr_SVPWM_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) {
const uint8_T * varData = ( const uint8_T * ) mxGetData ( mxGetFieldByNumber
( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData , ( const uint8_T *
) & varData [ offset * numBytes ] , numBytes ) ; } static void
mr_SVPWM_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_SVPWM_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , uint_T fieldVal ) { mxSetCell ( mxGetFieldByNumber
( destArray , i , j ) , offset , mxCreateDoubleScalar ( ( real_T ) fieldVal )
) ; } static uint_T mr_SVPWM_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ;
static uint_T mr_SVPWM_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_SVPWM_GetDWork ( ) { static const char_T * ssDWFieldNames
[ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_SVPWM_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB ) ,
sizeof ( rtB ) ) ; { static const char_T * rtdwDataFieldNames [ 3 ] = {
"rtDW.jiydzlq20v" , "rtDW.djelptucdk" , "rtDW.h0oh5ydh3u" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 3 , rtdwDataFieldNames ) ;
mr_SVPWM_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & ( rtDW .
jiydzlq20v ) , sizeof ( rtDW . jiydzlq20v ) ) ; mr_SVPWM_cacheDataAsMxArray (
rtdwData , 0 , 1 , ( const void * ) & ( rtDW . djelptucdk ) , sizeof ( rtDW .
djelptucdk ) ) ; mr_SVPWM_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const
void * ) & ( rtDW . h0oh5ydh3u ) , sizeof ( rtDW . h0oh5ydh3u ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_SVPWM_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_SVPWM_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0 ,
sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0
, 1 ) ; mr_SVPWM_restoreDataFromMxArray ( ( void * ) & ( rtDW . jiydzlq20v )
, rtdwData , 0 , 0 , sizeof ( rtDW . jiydzlq20v ) ) ;
mr_SVPWM_restoreDataFromMxArray ( ( void * ) & ( rtDW . djelptucdk ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . djelptucdk ) ) ;
mr_SVPWM_restoreDataFromMxArray ( ( void * ) & ( rtDW . h0oh5ydh3u ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . h0oh5ydh3u ) ) ; } } mxArray *
mr_SVPWM_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 6 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char_T * blockType [ 6 ] = { "S-Function" , "Scope" , "Scope" , "Scope" ,
"Scope" , "S-Function" , } ; static const char_T * blockPath [ 6 ] = {
"SVPWM/powergui/EquivalentModel1/State-Space" ,
"SVPWM/&#x65F6;&#x95F4;&#x8BA1;&#x7B97;/Scope" ,
"SVPWM/&#x8F7D;&#x6CE2;&#x8C03;&#x5236;/Scope" , "SVPWM/Scope" ,
"SVPWM/Scope1" , "SVPWM/powergui/EquivalentModel1/State-Space" , } ; static
const int reason [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 2 , } ; for ( subs [ 0 ] = 0 ;
subs [ 0 ] < 6 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateDoubleScalar ( ( real_T ) reason [ subs [ 0 ] ] ) ) ; } } return data
; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 130 ) ;
ssSetNumBlockIO ( rtS , 9 ) ; ssSetNumBlockParams ( rtS , 300 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 1.0E-6 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 2154651661U ) ; ssSetChecksumVal ( rtS , 1 ,
2785804129U ) ; ssSetChecksumVal ( rtS , 2 , 50835171U ) ; ssSetChecksumVal (
rtS , 3 , 380630390U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char_T * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo ,
0 , sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) &
blkInfo2 , 0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T *
) & blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ;
ssSetBlkInfo2Ptr ( rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , &
blkInfoSLSize ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo (
rtS , executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T
mdlPeriod [ NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ;
static time_T mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [
NSAMPLE_TIMES ] ; static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static
boolean_T mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T
mdlPerTaskSampleHits [ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T
mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i <
NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ;
mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } }
ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , &
mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ;
ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , &
mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr ( rtS , &
mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS , &
mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; } { void *
dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset
( dwork , 0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void
) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 24 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } SVPWM_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"SVPWM" ) ; ssSetPath ( rtS , "SVPWM" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 10.0 ) ; ssSetStepSize ( rtS , 1.0E-6 ) ;
ssSetFixedStepSize ( rtS , 1.0E-6 ) ; { static RTWLogInfo rt_DataLoggingInfo
; rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 6 , 6
} ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 6 , 6 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) } ; static
const char_T * rt_LoggedStateLabels [ ] = { "DSTATE" , "DSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"SVPWM/powergui/EquivalentModel1/State-Space" ,
"SVPWM/Universal Bridge/Model/Unit Delay" } ; static const char_T *
rt_LoggedStateNames [ ] = { "DSTATE" , "DSTATE" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } }
; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 2 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 2 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) rtDW . jiydzlq20v ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) rtDW . djelptucdk ; } rtliSetLogT
( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS )
, "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "xFinal" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; ssSetNumNonContDerivSigInfos ( rtS , 0 ) ;
ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS , &
slvrInfo ) ; ssSetSolverName ( rtS , "FixedStepDiscrete" ) ;
ssSetVariableStepSolver ( rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 ,
2154651661U ) ; ssSetChecksumVal ( rtS , 1 , 2785804129U ) ; ssSetChecksumVal
( rtS , 2 , 50835171U ) ; ssSetChecksumVal ( rtS , 3 , 380630390U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 7 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_SVPWM_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP ( rtS ,
mr_SVPWM_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS , mr_SVPWM_SetDWork
) ; rtP . Saturation_UpperSat = rtInf ; rt_RapidReadMatFileAndUpdateParams (
rtS ) ; if ( ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
