#ifndef RTW_HEADER_SVPWM_types_h_
#define RTW_HEADER_SVPWM_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_WZVFj3jdkCnLphe3BuXLZF_
#define DEFINED_TYPEDEF_FOR_struct_WZVFj3jdkCnLphe3BuXLZF_
typedef struct { real_T SwitchResistance [ 6 ] ; real_T SwitchVf [ 12 ] ;
real_T SwitchType [ 6 ] ; real_T SwitchGateInitialValue [ 6 ] ; real_T
EnableUseOfTLC ; real_T OutputsToResetToZero [ 6 ] ; real_T
NoErrorOnMaxIteration ; real_T Ts ; real_T Interpolate ; real_T SaveMatrices
; real_T BufferSize ; boolean_T TBEON ; uint8_T sl_padding0 [ 7 ] ; real_T A
[ 36 ] ; real_T B [ 42 ] ; real_T C [ 72 ] ; real_T D [ 84 ] ; real_T x0 [ 6
] ; } struct_WZVFj3jdkCnLphe3BuXLZF ;
#endif
#ifndef SS_UINT64
#define SS_UINT64 18
#endif
#ifndef SS_INT64
#define SS_INT64 19
#endif
typedef struct P_ P ;
#endif
