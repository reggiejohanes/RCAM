#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "RCAM_sim1_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "RCAM_sim1.h"
#include "RCAM_sim1_capi.h"
#include "RCAM_sim1_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"RCAM_sim1/FCC/Saturation1" ) , TARGET_STRING ( "dStab" ) , 0 , 0 , 0 , 0 , 0
} , { 1 , 0 , TARGET_STRING ( "RCAM_sim1/RCAM/Sum" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 1 } , { 2 , 0 , TARGET_STRING ( "RCAM_sim1/RCAM/Sum1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 3 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Unary Minus" ) , TARGET_STRING ( "(-)Ze [m]" ) , 0 ,
0 , 0 , 0 , 1 } , { 4 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Unary Minus1" ) , TARGET_STRING ( "(-)w [m/s]" ) , 0
, 0 , 0 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Unary Minus2" ) , TARGET_STRING ( "(-)w_e [m/s]" ) ,
0 , 0 , 0 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/Vector Concatenate" ) , TARGET_STRING ( "" ) , 0
, 0 , 1 , 0 , 1 } , { 7 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 8 , 0 , TARGET_STRING ( "RCAM_sim1/RCAM/Aerodynamics/Gain1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 9 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/Gain2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 1 } , { 10 , 0 , TARGET_STRING ( "RCAM_sim1/RCAM/Aerodynamics/Gain3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/Product" ) , TARGET_STRING ( "F_a_s" ) , 0 , 0 ,
1 , 0 , 1 } , { 12 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/Product1" ) , TARGET_STRING ( "F_a_b" ) , 0 , 0
, 1 , 0 , 1 } , { 13 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/Product2" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 1 } , { 14 , 0 , TARGET_STRING ( "RCAM_sim1/RCAM/Aerodynamics/Add" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 15 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/Sum" ) , TARGET_STRING ( "CL" ) , 0 , 0 , 0 , 0
, 1 } , { 16 , 0 , TARGET_STRING ( "RCAM_sim1/RCAM/Aerodynamics/Sum1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 17 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0
, 1 } , { 18 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Unary Minus" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 19 , 0 , TARGET_STRING ( "RCAM_sim1/RCAM/Propulsion/Sum" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Propulsion/Sum1" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0
} , { 21 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees/Gain" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 22 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees1/Gain" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 23 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees10/Gain" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 24 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees12/Gain" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 25 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees2/Gain" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 26 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees3/Gain" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 27 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees4/Gain" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 28 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees5/Gain" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 29 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees6/Gain" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 30 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees7/Gain" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 31 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees8/Gain" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 32 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees9/Gain" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 33 , 0 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/xdot/Vector Concatenate" ) , TARGET_STRING ( "" ) ,
0 , 0 , 2 , 0 , 1 } , { 34 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CD/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 35 , 0 , TARGET_STRING ( "RCAM_sim1/RCAM/Aerodynamics/CD/Gain1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 36 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CD/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 1 } , { 37 , 0 , TARGET_STRING ( "RCAM_sim1/RCAM/Aerodynamics/CD/Sum1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 38 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLTail/Gain" ) , TARGET_STRING ( "epsilon" ) , 0
, 0 , 0 , 0 , 1 } , { 39 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLTail/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 40 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLTail/Gain2" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 41 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLTail/Divide" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 42 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLTail/Product" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 43 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLTail/Add" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 44 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLTail/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 45 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLTail/Sum1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 46 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLWingBody/If Action Subsystem" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 47 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLWingBody/If Action Subsystem1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 48 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLWingBody/Merge" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 49 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to alpha & beta/Vector Concatenate" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 50 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to alpha & beta/Gain" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 51 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to alpha & beta/Gain1" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 52 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to alpha & beta/Gain2" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 53 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to alpha & beta/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 54 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to alpha & beta/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 55 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to alpha & beta/Sum1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 56 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to alpha & beta/Sum2" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 57 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to controls/Product" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 0 } , { 58 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to pqr/Divide" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 59 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to pqr/Product" ) , TARGET_STRING ( "" )
, 0 , 0 , 3 , 0 , 1 } , { 60 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to pqr/Product1" ) , TARGET_STRING ( "" )
, 0 , 0 , 1 , 0 , 1 } , { 61 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CY/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 62 , 0 , TARGET_STRING ( "RCAM_sim1/RCAM/Aerodynamics/CY/Gain1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 63 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CY/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 1 } , { 64 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/Cross Product/Element Product" ) , TARGET_STRING
( "" ) , 0 , 0 , 4 , 0 , 1 } , { 65 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/Cross Product/Sum" ) , TARGET_STRING ( "" ) , 0
, 0 , 1 , 0 , 1 } , { 66 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/YAxisTransform/Gain" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 67 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/calcDynamicPresure/Gain" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 68 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/calcDynamicPresure/Product" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 69 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/p,q,r " ) , TARGET_STRING
( "" ) , 0 , 0 , 1 , 0 , 1 } , { 70 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/ub,vb,wb" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 71 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/xe,ye,ze" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 72 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Transpose" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 1 } , { 73 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 74 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 1 } , { 75 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/AlphaBetaGamma/Divide1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 76 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/AlphaBetaGamma/Trigonometric Function" ) ,
TARGET_STRING ( "alpha" ) , 0 , 0 , 0 , 0 , 1 } , { 77 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/AlphaBetaGamma/Sqrt" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 78 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/1//T0" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 79 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Lapse Rate" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 80 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/g//R" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 81 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/rho0" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 82 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Product" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 83 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Product1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 84 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Product3" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 85 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Limit  altitude  to Stratosphere"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 86 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Limit  altitude  to troposhere" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 87 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Sum" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 88 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Sum1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 89 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Gravity/Vector Concatenate1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 2 } , { 90 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Gravity/Product3" ) , TARGET_STRING ( "F" ) ,
0 , 0 , 1 , 0 , 1 } , { 91 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLWingBody/If Action Subsystem/Polynomial" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 92 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLWingBody/If Action Subsystem1/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 93 , 2 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLWingBody/If Action Subsystem1/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 94 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/Aerodynamics/YAxisTransform/Create 3x3 Matrix/Vector Concatenate"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 95 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate DCM & Euler Angles/phi theta psi"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 96 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate omega_dot/Product2"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 97 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate omega_dot/Reshape"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 98 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate omega_dot/Selector"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 2 } , { 99 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate omega_dot/Selector1"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 2 } , { 100 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate omega_dot/Selector2"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 2 } , { 101 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate omega_dot/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 102 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Vbxw/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 103 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Velocity Conversion/Unit Conversion"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 104 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Velocity Conversion1/Unit Conversion"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 105 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/transform to Inertial axes /Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 1 } , { 106 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn11"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 107 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn12"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 108 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn13"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 109 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn21"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 110 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn22"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 111 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn23"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 112 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn31"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 113 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn32"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 114 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn33"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 115 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 116 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate omega_dot/I x w/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 1 } , { 117 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate omega_dot/I x w1/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 1 } , { 118 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Vbxw/Subsystem/i x j" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 119 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Vbxw/Subsystem/j x k" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 120 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Vbxw/Subsystem/k x i" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 121 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Vbxw/Subsystem1/i x k" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 122 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Vbxw/Subsystem1/j x i" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 123 , 0 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Vbxw/Subsystem1/k x j" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 124 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix/Vector Concatenate"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 125 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem/i x j"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 126 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem/j x k"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 127 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem/k x i"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 128 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem1/i x k"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 129 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem1/j x i"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 130 , 0 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem1/k x j"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 131 , TARGET_STRING ( "RCAM_sim1/FCC/Step1" ) ,
TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , { 132 , TARGET_STRING (
"RCAM_sim1/FCC/Step1" ) , TARGET_STRING ( "Before" ) , 0 , 0 , 0 } , { 133 ,
TARGET_STRING ( "RCAM_sim1/FCC/Step1" ) , TARGET_STRING ( "After" ) , 0 , 0 ,
0 } , { 134 , TARGET_STRING ( "RCAM_sim1/RCAM/Aerodynamics/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 135 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0
} , { 136 , TARGET_STRING ( "RCAM_sim1/RCAM/Aerodynamics/Gain2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 137 , TARGET_STRING (
"RCAM_sim1/RCAM/Propulsion/Constant1" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 138 , TARGET_STRING ( "RCAM_sim1/RCAM/Propulsion/mew1" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 139 , TARGET_STRING (
"RCAM_sim1/RCAM/Propulsion/mew2" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 }
, { 140 , TARGET_STRING ( "RCAM_sim1/Scopes&Output/Radians to Degrees/Gain" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 141 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees1/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 142 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees10/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 143 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees12/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 144 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees2/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 145 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees3/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 146 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees4/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 147 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees5/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 148 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees6/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 149 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees7/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 150 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees8/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 151 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/Radians to Degrees9/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 152 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLTail/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 153 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to alpha & beta/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 154 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to alpha & beta/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 155 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to alpha & beta/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 156 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to alpha & beta/Gain2" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 157 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to controls/Control Effectiveness Matrix"
) , TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 158 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CM due to pqr/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 3 , 0 } , { 159 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/YAxisTransform/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 160 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/YAxisTransform/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 161 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/YAxisTransform/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 162 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/calcDynamicPresure/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 163 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Altitude of Troposphere" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 164 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 165 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Sea Level  Temperature" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 166 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/1//T0" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 167 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Lapse Rate" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 168 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/g//R" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 169 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/rho0" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 170 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Limit  altitude  to Stratosphere"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 171 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Limit  altitude  to Stratosphere"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 172 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Limit  altitude  to troposhere" )
, TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 173 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Atmosphere/Limit  altitude  to troposhere" )
, TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 174 , TARGET_STRING (
"RCAM_sim1/RCAM/EOM&Environment/Gravity/Constant3" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 175 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/xdot/Subsystem/Constant" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 176 , TARGET_STRING (
"RCAM_sim1/Scopes&Output/xdot/Subsystem/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 177 , TARGET_STRING (
"RCAM_sim1/RCAM/Aerodynamics/CLWingBody/If Action Subsystem/Polynomial" ) ,
TARGET_STRING ( "Coefs" ) , 0 , 8 , 0 } , { 178 , TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate DCM & Euler Angles/phi theta psi"
) , TARGET_STRING ( "WrappedStateUpperValue" ) , 0 , 0 , 0 } , { 179 ,
TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate DCM & Euler Angles/phi theta psi"
) , TARGET_STRING ( "WrappedStateLowerValue" ) , 0 , 0 , 0 } , { 180 ,
TARGET_STRING (
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Determine Force,  Mass & Inertia/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 181 , TARGET_STRING (
"Ib" ) , 0 , 3 , 0 } , { 182 , TARGET_STRING ( "S" ) , 0 , 0 , 0 } , { 183 ,
TARGET_STRING ( "St" ) , 0 , 0 , 0 } , { 184 , TARGET_STRING ( "Vb0" ) , 0 ,
1 , 0 } , { 185 , TARGET_STRING ( "Xe0" ) , 0 , 1 , 0 } , { 186 ,
TARGET_STRING ( "alpha_L0" ) , 0 , 0 , 0 } , { 187 , TARGET_STRING (
"alpha_switch" ) , 0 , 0 , 0 } , { 188 , TARGET_STRING ( "cbar" ) , 0 , 0 , 0
} , { 189 , TARGET_STRING ( "cd_c1" ) , 0 , 0 , 0 } , { 190 , TARGET_STRING (
"cd_c2" ) , 0 , 0 , 0 } , { 191 , TARGET_STRING ( "cd_m1" ) , 0 , 0 , 0 } , {
192 , TARGET_STRING ( "cd_m2" ) , 0 , 0 , 0 } , { 193 , TARGET_STRING (
"dCYdRud" ) , 0 , 0 , 0 } , { 194 , TARGET_STRING ( "dCYdbeta" ) , 0 , 0 , 0
} , { 195 , TARGET_STRING ( "depsda" ) , 0 , 0 , 0 } , { 196 , TARGET_STRING
( "euler0" ) , 0 , 1 , 0 } , { 197 , TARGET_STRING ( "g" ) , 0 , 0 , 0 } , {
198 , TARGET_STRING ( "lt" ) , 0 , 0 , 0 } , { 199 , TARGET_STRING ( "m" ) ,
0 , 0 , 0 } , { 200 , TARGET_STRING ( "n" ) , 0 , 0 , 0 } , { 201 ,
TARGET_STRING ( "pqr0" ) , 0 , 1 , 0 } , { 202 , TARGET_STRING ( "u0" ) , 0 ,
9 , 0 } , { 203 , TARGET_STRING ( "umax" ) , 0 , 10 , 0 } , { 204 ,
TARGET_STRING ( "umin" ) , 0 , 10 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . m2bzifekpx , & rtB . lp44qocih1 [
0 ] , & rtB . ay5hewygdd [ 0 ] , & rtB . gw5me3glut , & rtB . ftrrsvm4qz , &
rtB . fs1sshlnh1 , & rtB . e4fhvpsn0a [ 0 ] , & rtB . jjoh1jbcal , & rtB .
e4fhvpsn0a [ 0 ] , ( & rtB . e4fhvpsn0a [ 0 ] + 2 ) , & rtB . gu5gko2lp5 , &
rtB . kiowxcg1sw [ 0 ] , & rtB . fsb4j0khha [ 0 ] , & rtB . i3xmajgkf0 [ 0 ]
, & rtB . o3faktraka [ 0 ] , & rtB . kg5nlp1vty , & rtB . ddtcpvxvbu [ 0 ] ,
& rtB . mynduz3xvt [ 0 ] , & rtB . pt5pzvbxss , & rtB . fa1rxjoibu [ 0 ] , &
rtB . febx52uog3 [ 0 ] , & rtB . d1t3jcdw1w , & rtB . pntd0wqwje , & rtB .
nbnq3nxxt1 , & rtB . ny4fdqpjjc , & rtB . o01hcd1hwc , & rtB . kwagzwu5gd , &
rtB . njx2l41pcu , & rtB . fgkyl4gpeb , & rtB . gu4fdkfnej , & rtB .
dpzkdmkvzx , & rtB . ccfglqcque , & rtB . ogdzjb4jan , & rtB . aex35jzv0e [ 0
] , & rtB . bzatbelz3c , & rtB . cz4qtuhpp2 , & rtB . iirpepr453 , & rtB .
lgam5r5wm4 , & rtB . fph3doyxdf , & rtB . dwusv2m5gc , & rtB . pqj4t3vzft , &
rtB . lgmerzx4g3 , & rtB . o0uiwu2wn4 , & rtB . m5hwtguh1n , & rtB .
hmndehnp3x , & rtB . nqkem2zrkc , & rtB . galszwoxqw , & rtB . galszwoxqw , &
rtB . galszwoxqw , & rtB . i3qqkdiw05 [ 0 ] , & rtB . i3qqkdiw05 [ 0 ] , &
rtB . lcr4hfaiul , & rtB . mlkbjznxlc , ( & rtB . i3qqkdiw05 [ 0 ] + 2 ) , &
rtB . akrbmyschb , ( & rtB . i3qqkdiw05 [ 0 ] + 1 ) , & rtB . hf33apcafb , &
rtB . pz1o5ffnri [ 0 ] , & rtB . lnimvle1rj , & rtB . hdtg2mz21g [ 0 ] , &
rtB . i1avsg3ef3 [ 0 ] , & rtB . l2a1ipflwy , & rtB . kyodpk4kvr , ( & rtB .
e4fhvpsn0a [ 0 ] + 1 ) , & rtB . mw1ofaqc0d [ 0 ] , & rtB . gvri4phsjb [ 0 ]
, ( & rtB . abopebv22d [ 0 ] + 6 ) , & rtB . nlfhqpdwsg , & rtB . lzdkj2knvd
, & rtB . iz1lzcyd3a [ 0 ] , & rtB . c10sww4qfc [ 0 ] , & rtB . iam1jhjhep [
0 ] , & rtB . h4ublwxemc [ 0 ] , & rtB . mi1anjx3mq [ 0 ] , & rtB .
o250csv04h [ 0 ] , & rtB . ozpmvwdhed , & rtB . f2sno0tuqf , & rtB .
mf4semtcii , & rtB . ppzmvjgz3o , & rtB . cnwqcjfxbd , & rtB . mkj2w3ap12 , &
rtB . g5412zpwqu , & rtB . ilkefjjycy , & rtB . ixd3mmmbvw , & rtB .
jvposjqlvw , & rtB . idxg52v4a5 , & rtB . oyvt50li2v , & rtB . fdgklgayoh , &
rtB . lfcw5ky34x , & rtB . kpztmnslrx [ 0 ] , & rtB . hmcdusmxx2 [ 0 ] , &
rtB . galszwoxqw , & rtB . galszwoxqw , & rtB . pvuzvh4wal , & rtB .
abopebv22d [ 0 ] , & rtB . pwlerz4zmu [ 0 ] , & rtB . py1jp4xfdb [ 0 ] , &
rtB . nbxandr1dq [ 0 ] , & rtB . pdlcsr0mtt [ 0 ] , & rtB . exah40fyce [ 0 ]
, & rtB . ghgjlawphx [ 0 ] , & rtB . kswqxwm5fc [ 0 ] , & rtB . f45wytmhlu [
0 ] , & rtB . etd4am2wmj [ 0 ] , & rtB . fsrrtwrymg [ 0 ] , & rtB .
bcjcqbvmdf [ 0 ] , & rtB . akshdvntgj [ 0 ] , ( & rtB . akshdvntgj [ 0 ] + 3
) , ( & rtB . akshdvntgj [ 0 ] + 6 ) , ( & rtB . akshdvntgj [ 0 ] + 1 ) , ( &
rtB . akshdvntgj [ 0 ] + 4 ) , ( & rtB . akshdvntgj [ 0 ] + 7 ) , ( & rtB .
akshdvntgj [ 0 ] + 2 ) , ( & rtB . akshdvntgj [ 0 ] + 5 ) , ( & rtB .
akshdvntgj [ 0 ] + 8 ) , & rtB . j3jivuya1i [ 0 ] , & rtB . lgn5qxdsfl [ 0 ]
, & rtB . alzlbjc0as [ 0 ] , & rtB . dkdpuf2nrz , & rtB . kds1ep2sd0 , & rtB
. ihcsgspswd , & rtB . hp150xzlm5 , & rtB . duwuhux2st , & rtB . oknc4qrqul ,
& rtB . akshdvntgj [ 0 ] , & rtB . en0jsvv1cd , & rtB . o2w2qidibo , & rtB .
bfvnrwgw1h , & rtB . onfee4huot , & rtB . e0tzo2c4hh , & rtB . eyyenf2ob2 , &
rtP . Step1_Time , & rtP . Step1_Y0 , & rtP . Step1_YFinal , & rtP .
Constant_Value_jauwwxrr5h [ 0 ] , & rtP . Gain1_Gain , & rtP . Gain2_Gain , &
rtP . Constant1_Value_oqyl4nphju , & rtP . mew1_Value [ 0 ] , & rtP .
mew2_Value [ 0 ] , & rtP . Gain_Gain , & rtP . Gain_Gain_h1ktjeexx1 , & rtP .
Gain_Gain_lov5qcjzgk , & rtP . Gain_Gain_l2z5belp2u , & rtP .
Gain_Gain_o2nz4hlc0y , & rtP . Gain_Gain_bxpznsjmpu , & rtP .
Gain_Gain_brtoidrzvi , & rtP . Gain_Gain_grtmmf3s4r , & rtP .
Gain_Gain_cyh2wwurhc , & rtP . Gain_Gain_nkk2ewvwrs , & rtP .
Gain_Gain_hnrzzhh2v0 , & rtP . Gain_Gain_ftxlqxfaiq , & rtP .
Gain1_Gain_hfbnedsnqk , & rtP . Constant_Value_lag24fa1pj , & rtP .
Constant1_Value_mx4lv2w3em , & rtP . Gain_Gain_bfommv4lak , & rtP .
Gain2_Gain_dwlwh44krh , & rtP . ControlEffectivenessMatrix_Value [ 0 ] , &
rtP . Constant1_Value_ogzj0ybhah [ 0 ] , & rtP . Constant_Value_gstis4eggm ,
& rtP . Constant1_Value_mrpwt2vxxm , & rtP . Gain_Gain_acmismgbcw , & rtP .
Gain_Gain_bxawv450gg , & rtP . AltitudeofTroposphere_Value , & rtP .
Constant_Value_fqrpfjqhfg , & rtP . SeaLevelTemperature_Value , & rtP .
uT0_Gain , & rtP . LapseRate_Gain , & rtP . gR_Gain , & rtP . rho0_Gain , &
rtP . LimitaltitudetoStratosphere_UpperSat , & rtP .
LimitaltitudetoStratosphere_LowerSat , & rtP .
Limitaltitudetotroposhere_UpperSat , & rtP .
Limitaltitudetotroposhere_LowerSat , & rtP . Constant3_Value , & rtP .
Constant_Value , & rtP . Constant1_Value , & rtP . Polynomial_Coefs [ 0 ] , &
rtP . phithetapsi_WrappedStateUpperValue , & rtP .
phithetapsi_WrappedStateLowerValue , & rtP . Constant2_Value [ 0 ] , & rtP .
Ib [ 0 ] , & rtP . S , & rtP . St , & rtP . Vb0 [ 0 ] , & rtP . Xe0 [ 0 ] , &
rtP . alpha_L0 , & rtP . alpha_switch , & rtP . cbar , & rtP . cd_c1 , & rtP
. cd_c2 , & rtP . cd_m1 , & rtP . cd_m2 , & rtP . dCYdRud , & rtP . dCYdbeta
, & rtP . depsda , & rtP . euler0 [ 0 ] , & rtP . g , & rtP . lt , & rtP . m
, & rtP . n , & rtP . pqr0 [ 0 ] , & rtP . u0 [ 0 ] , & rtP . umax [ 0 ] , &
rtP . umin [ 0 ] , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 2 , 2
, 0 } , { rtwCAPI_VECTOR , 14 , 2 , 0 } , { rtwCAPI_VECTOR , 16 , 2 , 0 } , {
rtwCAPI_VECTOR , 18 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] =
{ 1 , 1 , 3 , 1 , 12 , 1 , 3 , 3 , 6 , 1 , 9 , 1 , 1 , 3 , 1 , 4 , 5 , 1 , 1
, 5 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , (
int8_T ) 1 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ]
, ( const void * ) & rtcapiStoredFloats [ 0 ] , ( int8_T ) 0 , ( uint8_T ) 0
} , { ( NULL ) , ( NULL ) , 2 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 131 , rtRootInputs , 0 , rtRootOutputs , 0 }
, { rtBlockParameters , 50 , rtModelParameters , 24 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 449807628U , 3424572996U , 336135214U ,
2211097397U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * RCAM_sim1_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void RCAM_sim1_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
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
void RCAM_sim1_host_InitializeDataMapInfo ( RCAM_sim1_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
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
