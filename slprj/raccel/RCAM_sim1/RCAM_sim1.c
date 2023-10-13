#include "RCAM_sim1.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include "RCAM_sim1_private.h"
#include <string.h>
#include "rt_logging_mmi.h"
#include "RCAM_sim1_capi.h"
#include "RCAM_sim1_dt.h"
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
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "10.7 (R2023a) 19-Nov-2022" ; void
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
B rtB ; X rtX ; DW rtDW ; PeriodicIndX rtPeriodicIndX ; PeriodicRngX
rtPeriodicRngX ; static SimStruct model_S ; SimStruct * const rtS = & model_S
; void rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf ( const real_T u0 [ 3 ] , const
real_T u1 [ 9 ] , real_T y [ 3 ] ) { real_T A [ 9 ] ; real_T a21 ; real_T
maxval ; int32_T r1 ; int32_T r2 ; int32_T r3 ; int32_T rtemp ; memcpy ( & A
[ 0 ] , & u1 [ 0 ] , 9U * sizeof ( real_T ) ) ; r1 = 0 ; r2 = 1 ; r3 = 2 ;
maxval = muDoubleScalarAbs ( u1 [ 0 ] ) ; a21 = muDoubleScalarAbs ( u1 [ 1 ]
) ; if ( a21 > maxval ) { maxval = a21 ; r1 = 1 ; r2 = 0 ; } if (
muDoubleScalarAbs ( u1 [ 2 ] ) > maxval ) { r1 = 2 ; r2 = 1 ; r3 = 0 ; } A [
r2 ] = u1 [ r2 ] / u1 [ r1 ] ; A [ r3 ] /= A [ r1 ] ; A [ r2 + 3 ] -= A [ r1
+ 3 ] * A [ r2 ] ; A [ r3 + 3 ] -= A [ r1 + 3 ] * A [ r3 ] ; A [ r2 + 6 ] -=
A [ r1 + 6 ] * A [ r2 ] ; A [ r3 + 6 ] -= A [ r1 + 6 ] * A [ r3 ] ; if (
muDoubleScalarAbs ( A [ r3 + 3 ] ) > muDoubleScalarAbs ( A [ r2 + 3 ] ) ) {
rtemp = r2 + 1 ; r2 = r3 ; r3 = rtemp - 1 ; } A [ r3 + 3 ] /= A [ r2 + 3 ] ;
A [ r3 + 6 ] -= A [ r3 + 3 ] * A [ r2 + 6 ] ; y [ r1 ] = u0 [ 0 ] / A [ r1 ]
; y [ r2 ] = u0 [ 1 ] - A [ r1 + 3 ] * y [ r1 ] ; y [ r3 ] = u0 [ 2 ] - A [
r1 + 6 ] * y [ r1 ] ; y [ r2 ] /= A [ r2 + 3 ] ; y [ r3 ] -= A [ r2 + 6 ] * y
[ r2 ] ; y [ r3 ] /= A [ r3 + 6 ] ; y [ r2 ] -= A [ r3 + 3 ] * y [ r3 ] ; y [
r1 ] -= y [ r3 ] * A [ r3 ] ; y [ r1 ] -= y [ r2 ] * A [ r2 ] ; } void
MdlInitialize ( void ) { rtX . a0yjmh1lt4 [ 0 ] = rtP . Vb0 [ 0 ] ; rtX .
lbrsb4nz1j [ 0 ] = rtP . pqr0 [ 0 ] ; rtX . hd5q5c4pq3 [ 0 ] = rtP . euler0 [
0 ] ; rtX . e1rxwddgzh [ 0 ] = rtP . Xe0 [ 0 ] ; rtX . a0yjmh1lt4 [ 1 ] = rtP
. Vb0 [ 1 ] ; rtX . lbrsb4nz1j [ 1 ] = rtP . pqr0 [ 1 ] ; rtX . hd5q5c4pq3 [
1 ] = rtP . euler0 [ 1 ] ; rtX . e1rxwddgzh [ 1 ] = rtP . Xe0 [ 1 ] ; rtX .
a0yjmh1lt4 [ 2 ] = rtP . Vb0 [ 2 ] ; rtX . lbrsb4nz1j [ 2 ] = rtP . pqr0 [ 2
] ; rtX . hd5q5c4pq3 [ 2 ] = rtP . euler0 [ 2 ] ; rtX . e1rxwddgzh [ 2 ] =
rtP . Xe0 [ 2 ] ; { int_T rootPeriodicContStateIndices [ 3 ] = { 6 , 7 , 8 }
; real_T rootPeriodicContStateRanges [ 6 ] = { - 3.1415926535897931 ,
3.1415926535897931 , - 3.1415926535897931 , 3.1415926535897931 , -
3.1415926535897931 , 3.1415926535897931 } ; ( void ) memcpy ( ( void * )
rtPeriodicIndX , rootPeriodicContStateIndices , 3 * sizeof ( int_T ) ) ; (
void ) memcpy ( ( void * ) rtPeriodicRngX , rootPeriodicContStateRanges , 6 *
sizeof ( real_T ) ) ; } } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
blockPath = sdiGetLabelFromChars ( "RCAM_sim1/Scopes&Output/To Workspace" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; const char_T * leafUnits [ 14 ] = { "m/s^2" ,
"m/s^2" , "rad/s^2" , "rad/s" , "m/s" , "1" , "rad" , "m" , "m/s" , "kg/m^3"
, "" , "" , "" , "" } ; sdiVirtualBusLeafElementInfoU leafElInfo [ 14 ] ;
int_T childDimsArray0 [ 1 ] = { 3 } ; int_T childDimsArray1 [ 1 ] = { 3 } ;
int_T childDimsArray2 [ 1 ] = { 3 } ; int_T childDimsArray3 [ 1 ] = { 3 } ;
int_T childDimsArray4 [ 1 ] = { 3 } ; int_T childDimsArray5 [ 2 ] = { 3 , 3 }
; int_T childDimsArray6 [ 1 ] = { 3 } ; int_T childDimsArray7 [ 1 ] = { 3 } ;
int_T childDimsArray8 [ 1 ] = { 3 } ; int_T childDimsArray9 [ 1 ] = { 1 } ;
int_T childDimsArray10 [ 1 ] = { 1 } ; int_T childDimsArray11 [ 1 ] = { 1 } ;
int_T childDimsArray12 [ 1 ] = { 1 } ; int_T childDimsArray13 [ 1 ] = { 1 } ;
{ sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; leafElInfo [ 0 ] . hDataType = hDT ; leafElInfo [ 0 ] .
signalName = sdiGetLabelFromChars ( ".Abe" ) ; leafElInfo [ 0 ] . dims .
nDims = 1 ; leafElInfo [ 0 ] . dims . dimensions = childDimsArray0 ;
leafElInfo [ 0 ] . dimsMode = DIMENSIONS_MODE_FIXED ; leafElInfo [ 0 ] .
complexity = REAL ; leafElInfo [ 0 ] . isLinearInterp = 1 ; leafElInfo [ 0 ]
. units = leafUnits [ 0 ] ; } { sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; leafElInfo [ 1 ]
. hDataType = hDT ; leafElInfo [ 1 ] . signalName = sdiGetLabelFromChars (
".Abb" ) ; leafElInfo [ 1 ] . dims . nDims = 1 ; leafElInfo [ 1 ] . dims .
dimensions = childDimsArray1 ; leafElInfo [ 1 ] . dimsMode =
DIMENSIONS_MODE_FIXED ; leafElInfo [ 1 ] . complexity = REAL ; leafElInfo [ 1
] . isLinearInterp = 1 ; leafElInfo [ 1 ] . units = leafUnits [ 1 ] ; } {
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; leafElInfo [ 2 ] . hDataType = hDT ; leafElInfo [ 2 ] .
signalName = sdiGetLabelFromChars ( ".domegadt" ) ; leafElInfo [ 2 ] . dims .
nDims = 1 ; leafElInfo [ 2 ] . dims . dimensions = childDimsArray2 ;
leafElInfo [ 2 ] . dimsMode = DIMENSIONS_MODE_FIXED ; leafElInfo [ 2 ] .
complexity = REAL ; leafElInfo [ 2 ] . isLinearInterp = 1 ; leafElInfo [ 2 ]
. units = leafUnits [ 2 ] ; } { sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; leafElInfo [ 3 ]
. hDataType = hDT ; leafElInfo [ 3 ] . signalName = sdiGetLabelFromChars (
".omega" ) ; leafElInfo [ 3 ] . dims . nDims = 1 ; leafElInfo [ 3 ] . dims .
dimensions = childDimsArray3 ; leafElInfo [ 3 ] . dimsMode =
DIMENSIONS_MODE_FIXED ; leafElInfo [ 3 ] . complexity = REAL ; leafElInfo [ 3
] . isLinearInterp = 1 ; leafElInfo [ 3 ] . units = leafUnits [ 3 ] ; } {
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; leafElInfo [ 4 ] . hDataType = hDT ; leafElInfo [ 4 ] .
signalName = sdiGetLabelFromChars ( ".Vb" ) ; leafElInfo [ 4 ] . dims . nDims
= 1 ; leafElInfo [ 4 ] . dims . dimensions = childDimsArray4 ; leafElInfo [ 4
] . dimsMode = DIMENSIONS_MODE_FIXED ; leafElInfo [ 4 ] . complexity = REAL ;
leafElInfo [ 4 ] . isLinearInterp = 1 ; leafElInfo [ 4 ] . units = leafUnits
[ 4 ] ; } { sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; leafElInfo [ 5 ]
. hDataType = hDT ; leafElInfo [ 5 ] . signalName = sdiGetLabelFromChars (
".DCMbe" ) ; leafElInfo [ 5 ] . dims . nDims = 2 ; leafElInfo [ 5 ] . dims .
dimensions = childDimsArray5 ; leafElInfo [ 5 ] . dimsMode =
DIMENSIONS_MODE_FIXED ; leafElInfo [ 5 ] . complexity = REAL ; leafElInfo [ 5
] . isLinearInterp = 1 ; leafElInfo [ 5 ] . units = leafUnits [ 5 ] ; } {
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; leafElInfo [ 6 ] . hDataType = hDT ; leafElInfo [ 6 ] .
signalName = sdiGetLabelFromChars ( ".euler" ) ; leafElInfo [ 6 ] . dims .
nDims = 1 ; leafElInfo [ 6 ] . dims . dimensions = childDimsArray6 ;
leafElInfo [ 6 ] . dimsMode = DIMENSIONS_MODE_FIXED ; leafElInfo [ 6 ] .
complexity = REAL ; leafElInfo [ 6 ] . isLinearInterp = 1 ; leafElInfo [ 6 ]
. units = leafUnits [ 6 ] ; } { sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; leafElInfo [ 7 ]
. hDataType = hDT ; leafElInfo [ 7 ] . signalName = sdiGetLabelFromChars (
".Xe" ) ; leafElInfo [ 7 ] . dims . nDims = 1 ; leafElInfo [ 7 ] . dims .
dimensions = childDimsArray7 ; leafElInfo [ 7 ] . dimsMode =
DIMENSIONS_MODE_FIXED ; leafElInfo [ 7 ] . complexity = REAL ; leafElInfo [ 7
] . isLinearInterp = 1 ; leafElInfo [ 7 ] . units = leafUnits [ 7 ] ; } {
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; leafElInfo [ 8 ] . hDataType = hDT ; leafElInfo [ 8 ] .
signalName = sdiGetLabelFromChars ( ".Ve" ) ; leafElInfo [ 8 ] . dims . nDims
= 1 ; leafElInfo [ 8 ] . dims . dimensions = childDimsArray8 ; leafElInfo [ 8
] . dimsMode = DIMENSIONS_MODE_FIXED ; leafElInfo [ 8 ] . complexity = REAL ;
leafElInfo [ 8 ] . isLinearInterp = 1 ; leafElInfo [ 8 ] . units = leafUnits
[ 8 ] ; } { sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; leafElInfo [ 9 ]
. hDataType = hDT ; leafElInfo [ 9 ] . signalName = sdiGetLabelFromChars (
".rho" ) ; leafElInfo [ 9 ] . dims . nDims = 1 ; leafElInfo [ 9 ] . dims .
dimensions = childDimsArray9 ; leafElInfo [ 9 ] . dimsMode =
DIMENSIONS_MODE_FIXED ; leafElInfo [ 9 ] . complexity = REAL ; leafElInfo [ 9
] . isLinearInterp = 1 ; leafElInfo [ 9 ] . units = leafUnits [ 9 ] ; } {
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; leafElInfo [ 10 ] . hDataType = hDT ; leafElInfo [ 10 ]
. signalName = sdiGetLabelFromChars ( ".gamma" ) ; leafElInfo [ 10 ] . dims .
nDims = 1 ; leafElInfo [ 10 ] . dims . dimensions = childDimsArray10 ;
leafElInfo [ 10 ] . dimsMode = DIMENSIONS_MODE_FIXED ; leafElInfo [ 10 ] .
complexity = REAL ; leafElInfo [ 10 ] . isLinearInterp = 1 ; leafElInfo [ 10
] . units = leafUnits [ 10 ] ; } { sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; leafElInfo [ 11 ]
. hDataType = hDT ; leafElInfo [ 11 ] . signalName = sdiGetLabelFromChars (
".Va" ) ; leafElInfo [ 11 ] . dims . nDims = 1 ; leafElInfo [ 11 ] . dims .
dimensions = childDimsArray11 ; leafElInfo [ 11 ] . dimsMode =
DIMENSIONS_MODE_FIXED ; leafElInfo [ 11 ] . complexity = REAL ; leafElInfo [
11 ] . isLinearInterp = 1 ; leafElInfo [ 11 ] . units = leafUnits [ 11 ] ; }
{ sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; leafElInfo [ 12 ] . hDataType = hDT ; leafElInfo [ 12 ]
. signalName = sdiGetLabelFromChars ( ".beta" ) ; leafElInfo [ 12 ] . dims .
nDims = 1 ; leafElInfo [ 12 ] . dims . dimensions = childDimsArray12 ;
leafElInfo [ 12 ] . dimsMode = DIMENSIONS_MODE_FIXED ; leafElInfo [ 12 ] .
complexity = REAL ; leafElInfo [ 12 ] . isLinearInterp = 1 ; leafElInfo [ 12
] . units = leafUnits [ 12 ] ; } { sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; leafElInfo [ 13 ]
. hDataType = hDT ; leafElInfo [ 13 ] . signalName = sdiGetLabelFromChars (
".alpha" ) ; leafElInfo [ 13 ] . dims . nDims = 1 ; leafElInfo [ 13 ] . dims
. dimensions = childDimsArray13 ; leafElInfo [ 13 ] . dimsMode =
DIMENSIONS_MODE_FIXED ; leafElInfo [ 13 ] . complexity = REAL ; leafElInfo [
13 ] . isLinearInterp = 1 ; leafElInfo [ 13 ] . units = leafUnits [ 13 ] ; }
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ;
sdiCreateAsyncQueuesForVirtualBusWithExportSettings ( & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"2d6a0f24-a38a-4c42-bcf4-b6babc74c742" , 14 , leafElInfo , & rtDW .
pfdn5tsup5 . AQHandles [ 0 ] , 1 , 0 , "x" , "" , "x" ) ;
slsaCacheDWorkDataForSimTargetOP ( rtS , & rtDW . pfdn5tsup5 . AQHandles [ 0
] , 14 * sizeof ( & rtDW . pfdn5tsup5 . AQHandles [ 0 ] ) ) ; if ( rtDW .
pfdn5tsup5 . AQHandles [ 0 ] ) { sdiLabelU loggedName = sdiGetLabelFromChars
( "x" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "x" ) ; sdiSetSignalSampleTimeString ( rtDW
. pfdn5tsup5 . AQHandles [ 0 ] , "Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ;
sdiSetSignalRefRate ( rtDW . pfdn5tsup5 . AQHandles [ 0 ] , 0.0 ) ;
sdiSetRunStartTime ( rtDW . pfdn5tsup5 . AQHandles [ 0 ] , ssGetTaskTime (
rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . pfdn5tsup5 .
AQHandles [ 0 ] , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
pfdn5tsup5 . AQHandles [ 0 ] , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . pfdn5tsup5 . AQHandles [ 0 ] ) ;
sdiSetSignalSampleTimeString ( rtDW . pfdn5tsup5 . AQHandles [ 1 ] ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
pfdn5tsup5 . AQHandles [ 1 ] , 0.0 ) ; sdiSetRunStartTime ( rtDW . pfdn5tsup5
. AQHandles [ 1 ] , ssGetTaskTime ( rtS , 0 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . pfdn5tsup5 . AQHandles [ 1 ] , 1
, 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . pfdn5tsup5 . AQHandles [ 1 ]
, loggedName , origSigName , propName ) ; sdiAsyncRepoSetBlockPathDomain (
rtDW . pfdn5tsup5 . AQHandles [ 1 ] ) ; sdiSetSignalSampleTimeString ( rtDW .
pfdn5tsup5 . AQHandles [ 2 ] , "Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ;
sdiSetSignalRefRate ( rtDW . pfdn5tsup5 . AQHandles [ 2 ] , 0.0 ) ;
sdiSetRunStartTime ( rtDW . pfdn5tsup5 . AQHandles [ 2 ] , ssGetTaskTime (
rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . pfdn5tsup5 .
AQHandles [ 2 ] , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
pfdn5tsup5 . AQHandles [ 2 ] , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . pfdn5tsup5 . AQHandles [ 2 ] ) ;
sdiSetSignalSampleTimeString ( rtDW . pfdn5tsup5 . AQHandles [ 3 ] ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
pfdn5tsup5 . AQHandles [ 3 ] , 0.0 ) ; sdiSetRunStartTime ( rtDW . pfdn5tsup5
. AQHandles [ 3 ] , ssGetTaskTime ( rtS , 0 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . pfdn5tsup5 . AQHandles [ 3 ] , 1
, 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . pfdn5tsup5 . AQHandles [ 3 ]
, loggedName , origSigName , propName ) ; sdiAsyncRepoSetBlockPathDomain (
rtDW . pfdn5tsup5 . AQHandles [ 3 ] ) ; sdiSetSignalSampleTimeString ( rtDW .
pfdn5tsup5 . AQHandles [ 4 ] , "Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ;
sdiSetSignalRefRate ( rtDW . pfdn5tsup5 . AQHandles [ 4 ] , 0.0 ) ;
sdiSetRunStartTime ( rtDW . pfdn5tsup5 . AQHandles [ 4 ] , ssGetTaskTime (
rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . pfdn5tsup5 .
AQHandles [ 4 ] , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
pfdn5tsup5 . AQHandles [ 4 ] , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . pfdn5tsup5 . AQHandles [ 4 ] ) ;
sdiSetSignalSampleTimeString ( rtDW . pfdn5tsup5 . AQHandles [ 5 ] ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
pfdn5tsup5 . AQHandles [ 5 ] , 0.0 ) ; sdiSetRunStartTime ( rtDW . pfdn5tsup5
. AQHandles [ 5 ] , ssGetTaskTime ( rtS , 0 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . pfdn5tsup5 . AQHandles [ 5 ] , 1
, 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . pfdn5tsup5 . AQHandles [ 5 ]
, loggedName , origSigName , propName ) ; sdiAsyncRepoSetBlockPathDomain (
rtDW . pfdn5tsup5 . AQHandles [ 5 ] ) ; sdiSetSignalSampleTimeString ( rtDW .
pfdn5tsup5 . AQHandles [ 6 ] , "Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ;
sdiSetSignalRefRate ( rtDW . pfdn5tsup5 . AQHandles [ 6 ] , 0.0 ) ;
sdiSetRunStartTime ( rtDW . pfdn5tsup5 . AQHandles [ 6 ] , ssGetTaskTime (
rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . pfdn5tsup5 .
AQHandles [ 6 ] , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
pfdn5tsup5 . AQHandles [ 6 ] , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . pfdn5tsup5 . AQHandles [ 6 ] ) ;
sdiSetSignalSampleTimeString ( rtDW . pfdn5tsup5 . AQHandles [ 7 ] ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
pfdn5tsup5 . AQHandles [ 7 ] , 0.0 ) ; sdiSetRunStartTime ( rtDW . pfdn5tsup5
. AQHandles [ 7 ] , ssGetTaskTime ( rtS , 0 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . pfdn5tsup5 . AQHandles [ 7 ] , 1
, 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . pfdn5tsup5 . AQHandles [ 7 ]
, loggedName , origSigName , propName ) ; sdiAsyncRepoSetBlockPathDomain (
rtDW . pfdn5tsup5 . AQHandles [ 7 ] ) ; sdiSetSignalSampleTimeString ( rtDW .
pfdn5tsup5 . AQHandles [ 8 ] , "Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ;
sdiSetSignalRefRate ( rtDW . pfdn5tsup5 . AQHandles [ 8 ] , 0.0 ) ;
sdiSetRunStartTime ( rtDW . pfdn5tsup5 . AQHandles [ 8 ] , ssGetTaskTime (
rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . pfdn5tsup5 .
AQHandles [ 8 ] , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
pfdn5tsup5 . AQHandles [ 8 ] , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . pfdn5tsup5 . AQHandles [ 8 ] ) ;
sdiSetSignalSampleTimeString ( rtDW . pfdn5tsup5 . AQHandles [ 9 ] ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
pfdn5tsup5 . AQHandles [ 9 ] , 0.0 ) ; sdiSetRunStartTime ( rtDW . pfdn5tsup5
. AQHandles [ 9 ] , ssGetTaskTime ( rtS , 0 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . pfdn5tsup5 . AQHandles [ 9 ] , 1
, 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . pfdn5tsup5 . AQHandles [ 9 ]
, loggedName , origSigName , propName ) ; sdiAsyncRepoSetBlockPathDomain (
rtDW . pfdn5tsup5 . AQHandles [ 9 ] ) ; sdiSetSignalSampleTimeString ( rtDW .
pfdn5tsup5 . AQHandles [ 10 ] , "Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ;
sdiSetSignalRefRate ( rtDW . pfdn5tsup5 . AQHandles [ 10 ] , 0.0 ) ;
sdiSetRunStartTime ( rtDW . pfdn5tsup5 . AQHandles [ 10 ] , ssGetTaskTime (
rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . pfdn5tsup5 .
AQHandles [ 10 ] , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
pfdn5tsup5 . AQHandles [ 10 ] , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . pfdn5tsup5 . AQHandles [ 10 ] ) ;
sdiSetSignalSampleTimeString ( rtDW . pfdn5tsup5 . AQHandles [ 11 ] ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
pfdn5tsup5 . AQHandles [ 11 ] , 0.0 ) ; sdiSetRunStartTime ( rtDW .
pfdn5tsup5 . AQHandles [ 11 ] , ssGetTaskTime ( rtS , 0 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . pfdn5tsup5 . AQHandles [ 11 ] ,
1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . pfdn5tsup5 . AQHandles [
11 ] , loggedName , origSigName , propName ) ; sdiAsyncRepoSetBlockPathDomain
( rtDW . pfdn5tsup5 . AQHandles [ 11 ] ) ; sdiSetSignalSampleTimeString (
rtDW . pfdn5tsup5 . AQHandles [ 12 ] , "Continuous" , 0.0 , ssGetTFinal ( rtS
) ) ; sdiSetSignalRefRate ( rtDW . pfdn5tsup5 . AQHandles [ 12 ] , 0.0 ) ;
sdiSetRunStartTime ( rtDW . pfdn5tsup5 . AQHandles [ 12 ] , ssGetTaskTime (
rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . pfdn5tsup5 .
AQHandles [ 12 ] , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
pfdn5tsup5 . AQHandles [ 12 ] , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . pfdn5tsup5 . AQHandles [ 12 ] ) ;
sdiSetSignalSampleTimeString ( rtDW . pfdn5tsup5 . AQHandles [ 13 ] ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
pfdn5tsup5 . AQHandles [ 13 ] , 0.0 ) ; sdiSetRunStartTime ( rtDW .
pfdn5tsup5 . AQHandles [ 13 ] , ssGetTaskTime ( rtS , 0 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . pfdn5tsup5 . AQHandles [ 13 ] ,
1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . pfdn5tsup5 . AQHandles [
13 ] , loggedName , origSigName , propName ) ; sdiAsyncRepoSetBlockPathDomain
( rtDW . pfdn5tsup5 . AQHandles [ 13 ] ) ; sdiFreeLabel ( loggedName ) ;
sdiFreeLabel ( origSigName ) ; sdiFreeLabel ( propName ) ; } sdiFreeLabel (
sigName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ;
sdiFreeLabel ( subPath ) ; sdiFreeName ( leafElInfo [ 0 ] . signalName ) ;
sdiFreeName ( leafElInfo [ 1 ] . signalName ) ; sdiFreeName ( leafElInfo [ 2
] . signalName ) ; sdiFreeName ( leafElInfo [ 3 ] . signalName ) ;
sdiFreeName ( leafElInfo [ 4 ] . signalName ) ; sdiFreeName ( leafElInfo [ 5
] . signalName ) ; sdiFreeName ( leafElInfo [ 6 ] . signalName ) ;
sdiFreeName ( leafElInfo [ 7 ] . signalName ) ; sdiFreeName ( leafElInfo [ 8
] . signalName ) ; sdiFreeName ( leafElInfo [ 9 ] . signalName ) ;
sdiFreeName ( leafElInfo [ 10 ] . signalName ) ; sdiFreeName ( leafElInfo [
11 ] . signalName ) ; sdiFreeName ( leafElInfo [ 12 ] . signalName ) ;
sdiFreeName ( leafElInfo [ 13 ] . signalName ) ; } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"x" ) ; sdiRegisterWksVariable ( rtDW . pfdn5tsup5 . AQHandles [ 0 ] ,
varName , "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "xdot" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "xdot" ) ; sdiLabelU blockPath = sdiGetLabelFromChars
( "RCAM_sim1/Scopes&Output/To Workspace1" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "xdot" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 12 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . bux0bm1vm5 . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "fb5c62a2-9c65-4a89-b61f-75b1e2ab0a5a" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . bux0bm1vm5 . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . bux0bm1vm5 . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . bux0bm1vm5 . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . bux0bm1vm5 .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . bux0bm1vm5 . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
bux0bm1vm5 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
bux0bm1vm5 . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . bux0bm1vm5 . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"xdot" ) ; sdiRegisterWksVariable ( rtDW . bux0bm1vm5 . AQHandles , varName ,
"array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "F_a_s" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "F_a_s" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"RCAM_sim1/RCAM/Aerodynamics/Product" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "F_a_s" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 3 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . kvvcjgui0t . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "09eccd7f-c73b-4b7c-82bb-1a75adccb42f" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . kvvcjgui0t . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . kvvcjgui0t . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . kvvcjgui0t . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . kvvcjgui0t .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . kvvcjgui0t . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
kvvcjgui0t . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
kvvcjgui0t . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"RCAM_sim1/RCAM/Aerodynamics/CLTail/Gain2" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . lhn5xaz053 . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "c994a8da-2aaf-4778-922c-252a4aab4a88" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . lhn5xaz053 . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . lhn5xaz053 . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . lhn5xaz053 . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . lhn5xaz053 .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . lhn5xaz053 . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
lhn5xaz053 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
lhn5xaz053 . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "epsilon" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "epsilon" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"RCAM_sim1/RCAM/Aerodynamics/CLTail/Gain" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "epsilon" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . djq4c1imrv . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "9a2719c5-cf4a-46ca-acf4-e5cef4b377e7" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . djq4c1imrv . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . djq4c1imrv . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . djq4c1imrv . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . djq4c1imrv .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . djq4c1imrv . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
djq4c1imrv . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
djq4c1imrv . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } rtDW . m5ykicffnh = 0 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . gqihoqfbig = - 1
; MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T gyysqz5j0r [ 9
] ; real_T kpb33w5sqa [ 5 ] ; real_T bkulx1vpsw [ 3 ] ; real_T
dci3fqdzol_idx_0 ; real_T dci3fqdzol_idx_1 ; real_T dci3fqdzol_idx_2 ; real_T
f1glz1ozzp ; real_T jnnmzryieq_idx_0 ; real_T jnnmzryieq_idx_1 ; real_T
jnnmzryieq_idx_2 ; real_T lgrnr0ewrf_idx_0 ; real_T lgrnr0ewrf_idx_1 ; real_T
lgrnr0ewrf_idx_2 ; real_T ljrbigxsf3 ; real_T nc5eokin3a ; real_T nz5t34xhkj
; int32_T i ; int8_T rtAction ; int8_T rtPrevAction ; srClearBC ( rtDW .
exrt0pkk0n ) ; srClearBC ( rtDW . mzyyrqm3kv ) ; rtB . c10sww4qfc [ 0 ] = rtX
. a0yjmh1lt4 [ 0 ] ; rtB . etd4am2wmj [ 0 ] = rtX . a0yjmh1lt4 [ 0 ] ; rtB .
iz1lzcyd3a [ 0 ] = rtX . lbrsb4nz1j [ 0 ] ; rtB . pwlerz4zmu [ 0 ] = rtX .
hd5q5c4pq3 [ 0 ] ; rtB . iam1jhjhep [ 0 ] = rtX . e1rxwddgzh [ 0 ] ; rtB .
c10sww4qfc [ 1 ] = rtX . a0yjmh1lt4 [ 1 ] ; rtB . etd4am2wmj [ 1 ] = rtX .
a0yjmh1lt4 [ 1 ] ; rtB . iz1lzcyd3a [ 1 ] = rtX . lbrsb4nz1j [ 1 ] ; rtB .
pwlerz4zmu [ 1 ] = rtX . hd5q5c4pq3 [ 1 ] ; rtB . iam1jhjhep [ 1 ] = rtX .
e1rxwddgzh [ 1 ] ; rtB . c10sww4qfc [ 2 ] = rtX . a0yjmh1lt4 [ 2 ] ; rtB .
etd4am2wmj [ 2 ] = rtX . a0yjmh1lt4 [ 2 ] ; rtB . iz1lzcyd3a [ 2 ] = rtX .
lbrsb4nz1j [ 2 ] ; rtB . pwlerz4zmu [ 2 ] = rtX . hd5q5c4pq3 [ 2 ] ; rtB .
iam1jhjhep [ 2 ] = rtX . e1rxwddgzh [ 2 ] ; rtB . d1t3jcdw1w = rtP .
Gain_Gain * rtB . iz1lzcyd3a [ 0 ] ; rtB . kwagzwu5gd = rtP .
Gain_Gain_bxpznsjmpu * rtB . pwlerz4zmu [ 0 ] ; rtB . pntd0wqwje = rtP .
Gain_Gain_h1ktjeexx1 * rtB . iz1lzcyd3a [ 1 ] ; rtB . njx2l41pcu = rtP .
Gain_Gain_brtoidrzvi * rtB . pwlerz4zmu [ 1 ] ; rtB . ftrrsvm4qz = - rtB .
etd4am2wmj [ 2 ] ; rtB . o01hcd1hwc = rtP . Gain_Gain_o2nz4hlc0y * rtB .
iz1lzcyd3a [ 2 ] ; rtB . fgkyl4gpeb = rtP . Gain_Gain_grtmmf3s4r * rtB .
pwlerz4zmu [ 2 ] ; rtB . gw5me3glut = - rtB . iam1jhjhep [ 2 ] ; nz5t34xhkj =
( rtX . a0yjmh1lt4 [ 0 ] * rtX . a0yjmh1lt4 [ 0 ] + rtX . a0yjmh1lt4 [ 1 ] *
rtX . a0yjmh1lt4 [ 1 ] ) + rtX . a0yjmh1lt4 [ 2 ] * rtX . a0yjmh1lt4 [ 2 ] ;
if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . m5ykicffnh != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
m5ykicffnh = 0 ; } rtB . mf4semtcii = muDoubleScalarSqrt ( nz5t34xhkj ) ; }
else if ( nz5t34xhkj < 0.0 ) { rtB . mf4semtcii = - muDoubleScalarSqrt (
muDoubleScalarAbs ( nz5t34xhkj ) ) ; rtDW . m5ykicffnh = 1 ; } else { rtB .
mf4semtcii = muDoubleScalarSqrt ( nz5t34xhkj ) ; } rtB . f2sno0tuqf =
muDoubleScalarAtan2 ( rtB . etd4am2wmj [ 2 ] , rtB . etd4am2wmj [ 0 ] ) ; rtB
. dpzkdmkvzx = rtP . Gain_Gain_nkk2ewvwrs * rtB . f2sno0tuqf ; rtB .
ozpmvwdhed = rtB . etd4am2wmj [ 1 ] / rtB . mf4semtcii ; if ( rtB .
ozpmvwdhed > 1.0 ) { jnnmzryieq_idx_0 = 1.0 ; } else if ( rtB . ozpmvwdhed <
- 1.0 ) { jnnmzryieq_idx_0 = - 1.0 ; } else { jnnmzryieq_idx_0 = rtB .
ozpmvwdhed ; } nz5t34xhkj = muDoubleScalarAsin ( jnnmzryieq_idx_0 ) ; rtB .
gu4fdkfnej = rtP . Gain_Gain_cyh2wwurhc * nz5t34xhkj ; nc5eokin3a = rtB .
pwlerz4zmu [ 1 ] - rtB . f2sno0tuqf ; rtB . ccfglqcque = rtP .
Gain_Gain_hnrzzhh2v0 * nc5eokin3a ; rtB . fzzfxafjlu [ 0 ] = rtB . pwlerz4zmu
[ 2 ] ; rtB . fzzfxafjlu [ 1 ] = rtB . pwlerz4zmu [ 1 ] ; rtB . fzzfxafjlu [
2 ] = rtB . pwlerz4zmu [ 0 ] ; muDoubleScalarSinCos ( rtB . fzzfxafjlu [ 0 ]
, & jnnmzryieq_idx_0 , & bkulx1vpsw [ 0 ] ) ; muDoubleScalarSinCos ( rtB .
fzzfxafjlu [ 1 ] , & jnnmzryieq_idx_1 , & bkulx1vpsw [ 1 ] ) ;
muDoubleScalarSinCos ( rtB . fzzfxafjlu [ 2 ] , & jnnmzryieq_idx_2 , &
bkulx1vpsw [ 2 ] ) ; rtB . akshdvntgj [ 0 ] = bkulx1vpsw [ 0 ] * bkulx1vpsw [
1 ] ; rtB . akshdvntgj [ 1 ] = jnnmzryieq_idx_1 * jnnmzryieq_idx_2 *
bkulx1vpsw [ 0 ] - jnnmzryieq_idx_0 * bkulx1vpsw [ 2 ] ; rtB . akshdvntgj [ 2
] = jnnmzryieq_idx_1 * bkulx1vpsw [ 2 ] * bkulx1vpsw [ 0 ] + jnnmzryieq_idx_0
* jnnmzryieq_idx_2 ; rtB . akshdvntgj [ 3 ] = jnnmzryieq_idx_0 * bkulx1vpsw [
1 ] ; rtB . akshdvntgj [ 4 ] = jnnmzryieq_idx_1 * jnnmzryieq_idx_2 *
jnnmzryieq_idx_0 + bkulx1vpsw [ 0 ] * bkulx1vpsw [ 2 ] ; rtB . akshdvntgj [ 5
] = jnnmzryieq_idx_1 * bkulx1vpsw [ 2 ] * jnnmzryieq_idx_0 - bkulx1vpsw [ 0 ]
* jnnmzryieq_idx_2 ; rtB . akshdvntgj [ 6 ] = - jnnmzryieq_idx_1 ; rtB .
akshdvntgj [ 7 ] = bkulx1vpsw [ 1 ] * jnnmzryieq_idx_2 ; rtB . akshdvntgj [ 8
] = bkulx1vpsw [ 1 ] * bkulx1vpsw [ 2 ] ; jnnmzryieq_idx_2 = rtB . kpztmnslrx
[ 1 ] ; ljrbigxsf3 = rtB . kpztmnslrx [ 0 ] ; jnnmzryieq_idx_0 = rtB .
kpztmnslrx [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) { rtB . hmcdusmxx2 [ i ] = (
rtB . akshdvntgj [ i + 3 ] * jnnmzryieq_idx_2 + rtB . akshdvntgj [ i ] *
ljrbigxsf3 ) + rtB . akshdvntgj [ i + 6 ] * jnnmzryieq_idx_0 ; }
jnnmzryieq_idx_2 = muDoubleScalarCos ( rtB . f2sno0tuqf ) ; rtB . abopebv22d
[ 0 ] = jnnmzryieq_idx_2 ; rtB . abopebv22d [ 1 ] = rtP .
Constant_Value_gstis4eggm ; ljrbigxsf3 = muDoubleScalarSin ( rtB . f2sno0tuqf
) ; rtB . abopebv22d [ 2 ] = ljrbigxsf3 ; rtB . abopebv22d [ 3 ] = rtP .
Constant_Value_gstis4eggm ; rtB . abopebv22d [ 4 ] = rtP .
Constant1_Value_mrpwt2vxxm ; rtB . abopebv22d [ 5 ] = rtP .
Constant_Value_gstis4eggm ; rtB . abopebv22d [ 6 ] = rtP .
Gain_Gain_acmismgbcw * ljrbigxsf3 ; rtB . abopebv22d [ 7 ] = rtP .
Constant_Value_gstis4eggm ; rtB . abopebv22d [ 8 ] = jnnmzryieq_idx_2 ; rtB .
pt5pzvbxss = - rtB . iam1jhjhep [ 2 ] ; if ( ssIsModeUpdateTimeStep ( rtS ) )
{ rtDW . gtrkyqalzw = rtB . pt5pzvbxss >= rtP .
Limitaltitudetotroposhere_UpperSat ? 1 : rtB . pt5pzvbxss > rtP .
Limitaltitudetotroposhere_LowerSat ? 0 : - 1 ; } rtB . oyvt50li2v = rtDW .
gtrkyqalzw == 1 ? rtP . Limitaltitudetotroposhere_UpperSat : rtDW .
gtrkyqalzw == - 1 ? rtP . Limitaltitudetotroposhere_LowerSat : rtB .
pt5pzvbxss ; rtB . cnwqcjfxbd = rtP . LapseRate_Gain * rtB . oyvt50li2v ; rtB
. lfcw5ky34x = rtP . SeaLevelTemperature_Value - rtB . cnwqcjfxbd ; rtB .
ppzmvjgz3o = rtP . uT0_Gain * rtB . lfcw5ky34x ; if ( ( rtB . ppzmvjgz3o <
0.0 ) && ( rtP . Constant_Value_fqrpfjqhfg > muDoubleScalarFloor ( rtP .
Constant_Value_fqrpfjqhfg ) ) ) { jnnmzryieq_idx_0 = - muDoubleScalarPower (
- rtB . ppzmvjgz3o , rtP . Constant_Value_fqrpfjqhfg ) ; } else {
jnnmzryieq_idx_0 = muDoubleScalarPower ( rtB . ppzmvjgz3o , rtP .
Constant_Value_fqrpfjqhfg ) ; } rtB . ilkefjjycy = jnnmzryieq_idx_0 / rtB .
ppzmvjgz3o ; rtB . g5412zpwqu = rtP . rho0_Gain * rtB . ilkefjjycy ; rtB .
fdgklgayoh = rtP . AltitudeofTroposphere_Value - rtB . pt5pzvbxss ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . bcixyiccvs = rtB . fdgklgayoh >=
rtP . LimitaltitudetoStratosphere_UpperSat ? 1 : rtB . fdgklgayoh > rtP .
LimitaltitudetoStratosphere_LowerSat ? 0 : - 1 ; } rtB . idxg52v4a5 = rtDW .
bcixyiccvs == 1 ? rtP . LimitaltitudetoStratosphere_UpperSat : rtDW .
bcixyiccvs == - 1 ? rtP . LimitaltitudetoStratosphere_LowerSat : rtB .
fdgklgayoh ; rtB . mkj2w3ap12 = rtP . gR_Gain * rtB . idxg52v4a5 ; rtB .
ixd3mmmbvw = 1.0 / rtB . lfcw5ky34x * rtB . mkj2w3ap12 ; rtB . jvposjqlvw =
rtB . g5412zpwqu * muDoubleScalarExp ( rtB . ixd3mmmbvw ) ; rtB . nlfhqpdwsg
= rtP . Gain_Gain_bxawv450gg * rtB . jvposjqlvw ; rtB . lzdkj2knvd = rtB .
mf4semtcii * rtB . mf4semtcii * rtB . nlfhqpdwsg ; rtB . jjoh1jbcal = rtP . S
* rtB . lzdkj2knvd ; rtB . bzatbelz3c = rtP . cd_m1 * rtB . f2sno0tuqf ; rtB
. iirpepr453 = rtB . bzatbelz3c + rtP . cd_c1 ; rtB . cz4qtuhpp2 = rtB .
iirpepr453 * rtB . iirpepr453 * rtP . cd_m2 ; rtB . lgam5r5wm4 = rtB .
cz4qtuhpp2 + rtP . cd_c2 ; rtB . e4fhvpsn0a [ 0 ] = rtP . Gain1_Gain * rtB .
lgam5r5wm4 ; rtB . l2a1ipflwy = rtP . dCYdbeta * nz5t34xhkj ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . azdfo1yqhk = ( ssGetTaskTime ( rtS ,
1 ) >= rtP . Step1_Time ) ; if ( rtDW . azdfo1yqhk == 1 ) { f1glz1ozzp = rtP
. Step1_YFinal ; } else { f1glz1ozzp = rtP . Step1_Y0 ; } for ( i = 0 ; i < 5
; i ++ ) { kpb33w5sqa [ i ] = rtP . u0 [ i ] * f1glz1ozzp ; } if ( kpb33w5sqa
[ 2 ] > rtP . umax [ 2 ] ) { f1glz1ozzp = rtP . umax [ 2 ] ; } else if (
kpb33w5sqa [ 2 ] < rtP . umin [ 2 ] ) { f1glz1ozzp = rtP . umin [ 2 ] ; }
else { f1glz1ozzp = kpb33w5sqa [ 2 ] ; } rtB . kyodpk4kvr = rtP . dCYdRud *
f1glz1ozzp ; } rtB . e4fhvpsn0a [ 1 ] = rtB . l2a1ipflwy + rtB . kyodpk4kvr ;
rtPrevAction = rtDW . gqihoqfbig ; if ( ssIsModeUpdateTimeStep ( rtS ) ) {
rtAction = ( int8_T ) ! ( rtP . alpha_switch >= rtB . f2sno0tuqf ) ; rtDW .
gqihoqfbig = rtAction ; } else { rtAction = rtDW . gqihoqfbig ; } if (
rtPrevAction != rtAction ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; switch ( rtPrevAction ) { case 0 : break ; case 1 : break ; } } if (
rtAction == 0 ) { if ( rtPrevAction != 0 ) { if ( ssGetTaskTime ( rtS , 0 )
!= ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } } rtB . pvuzvh4wal = rtB . f2sno0tuqf - rtP . alpha_L0 ; rtB . galszwoxqw
= rtP . n * rtB . pvuzvh4wal ; if ( ssIsModeUpdateTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . exrt0pkk0n ) ; } } else { if ( rtAction != rtPrevAction )
{ if ( ssGetTaskTime ( rtS , 0 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB . galszwoxqw =
rtP . Polynomial_Coefs [ 0 ] ; rtB . galszwoxqw = rtB . galszwoxqw * rtB .
f2sno0tuqf + rtP . Polynomial_Coefs [ 1 ] ; rtB . galszwoxqw = rtB .
galszwoxqw * rtB . f2sno0tuqf + rtP . Polynomial_Coefs [ 2 ] ; rtB .
galszwoxqw = rtB . galszwoxqw * rtB . f2sno0tuqf + rtP . Polynomial_Coefs [ 3
] ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW . mzyyrqm3kv )
; } } rtB . hmndehnp3x = rtB . f2sno0tuqf - rtP . alpha_L0 ; rtB . fph3doyxdf
= rtP . depsda * rtB . hmndehnp3x ; rtB . nqkem2zrkc = rtB . f2sno0tuqf - rtB
. fph3doyxdf ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( kpb33w5sqa [ 1 ] >
rtP . umax [ 1 ] ) { rtB . m2bzifekpx = rtP . umax [ 1 ] ; } else if (
kpb33w5sqa [ 1 ] < rtP . umin [ 1 ] ) { rtB . m2bzifekpx = rtP . umin [ 1 ] ;
} else { rtB . m2bzifekpx = kpb33w5sqa [ 1 ] ; } } rtB . dwusv2m5gc = rtP .
Gain1_Gain_hfbnedsnqk * rtB . iz1lzcyd3a [ 1 ] ; rtB . lgmerzx4g3 = rtP . lt
/ rtB . mf4semtcii ; rtB . o0uiwu2wn4 = rtB . dwusv2m5gc * rtB . lgmerzx4g3 ;
rtB . m5hwtguh1n = ( rtB . nqkem2zrkc + rtB . m2bzifekpx ) + rtB . o0uiwu2wn4
; rtB . pqj4t3vzft = rtP . St / rtP . S * 3.1 * rtB . m5hwtguh1n ; rtB .
kg5nlp1vty = rtB . galszwoxqw + rtB . pqj4t3vzft ; rtB . e4fhvpsn0a [ 2 ] =
rtP . Gain2_Gain * rtB . kg5nlp1vty ; rtB . kiowxcg1sw [ 0 ] = rtB .
jjoh1jbcal * rtB . e4fhvpsn0a [ 0 ] ; rtB . kiowxcg1sw [ 1 ] = rtB .
jjoh1jbcal * rtB . e4fhvpsn0a [ 1 ] ; rtB . kiowxcg1sw [ 2 ] = rtB .
jjoh1jbcal * rtB . e4fhvpsn0a [ 2 ] ; jnnmzryieq_idx_2 = rtB . kiowxcg1sw [ 1
] ; ljrbigxsf3 = rtB . kiowxcg1sw [ 0 ] ; jnnmzryieq_idx_0 = rtB . kiowxcg1sw
[ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) { rtB . fsb4j0khha [ i ] = ( rtB .
abopebv22d [ i + 3 ] * jnnmzryieq_idx_2 + rtB . abopebv22d [ i ] * ljrbigxsf3
) + rtB . abopebv22d [ i + 6 ] * jnnmzryieq_idx_0 ; } if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { if ( kpb33w5sqa [ 3 ] > rtP . umax [ 3 ] ) {
jnnmzryieq_idx_0 = rtP . umax [ 3 ] ; } else if ( kpb33w5sqa [ 3 ] < rtP .
umin [ 3 ] ) { jnnmzryieq_idx_0 = rtP . umin [ 3 ] ; } else {
jnnmzryieq_idx_0 = kpb33w5sqa [ 3 ] ; } lgrnr0ewrf_idx_0 = rtP . m * rtP . g
* jnnmzryieq_idx_0 ; lgrnr0ewrf_idx_1 = rtP . Constant1_Value_oqyl4nphju ;
lgrnr0ewrf_idx_2 = rtP . Constant1_Value_oqyl4nphju ; if ( kpb33w5sqa [ 4 ] >
rtP . umax [ 4 ] ) { jnnmzryieq_idx_0 = rtP . umax [ 4 ] ; } else if (
kpb33w5sqa [ 4 ] < rtP . umin [ 4 ] ) { jnnmzryieq_idx_0 = rtP . umin [ 4 ] ;
} else { jnnmzryieq_idx_0 = kpb33w5sqa [ 4 ] ; } dci3fqdzol_idx_0 = rtP . m *
rtP . g * jnnmzryieq_idx_0 ; dci3fqdzol_idx_1 = rtP .
Constant1_Value_oqyl4nphju ; dci3fqdzol_idx_2 = rtP .
Constant1_Value_oqyl4nphju ; rtB . fa1rxjoibu [ 0 ] = lgrnr0ewrf_idx_0 +
dci3fqdzol_idx_0 ; rtB . fa1rxjoibu [ 1 ] = rtP . Constant1_Value_oqyl4nphju
+ rtP . Constant1_Value_oqyl4nphju ; rtB . fa1rxjoibu [ 2 ] = rtP .
Constant1_Value_oqyl4nphju + rtP . Constant1_Value_oqyl4nphju ; } rtB .
kds1ep2sd0 = rtB . c10sww4qfc [ 1 ] * rtB . iz1lzcyd3a [ 2 ] ; rtB .
ihcsgspswd = rtB . iz1lzcyd3a [ 0 ] * rtB . c10sww4qfc [ 2 ] ; rtB .
dkdpuf2nrz = rtB . c10sww4qfc [ 0 ] * rtB . iz1lzcyd3a [ 1 ] ; rtB .
oknc4qrqul = rtB . iz1lzcyd3a [ 1 ] * rtB . c10sww4qfc [ 2 ] ; rtB .
hp150xzlm5 = rtB . c10sww4qfc [ 0 ] * rtB . iz1lzcyd3a [ 2 ] ; rtB .
duwuhux2st = rtB . iz1lzcyd3a [ 0 ] * rtB . c10sww4qfc [ 1 ] ; rtB .
f45wytmhlu [ 0 ] = rtB . kds1ep2sd0 - rtB . oknc4qrqul ; rtB . f45wytmhlu [ 1
] = rtB . ihcsgspswd - rtB . hp150xzlm5 ; rtB . f45wytmhlu [ 2 ] = rtB .
dkdpuf2nrz - rtB . duwuhux2st ; rtB . mw1ofaqc0d [ 0 ] = rtB . fsb4j0khha [ 1
] * rtP . Constant_Value_jauwwxrr5h [ 2 ] ; rtB . mw1ofaqc0d [ 1 ] = rtP .
Constant_Value_jauwwxrr5h [ 0 ] * rtB . fsb4j0khha [ 2 ] ; rtB . mw1ofaqc0d [
2 ] = rtB . fsb4j0khha [ 0 ] * rtP . Constant_Value_jauwwxrr5h [ 1 ] ; rtB .
mw1ofaqc0d [ 3 ] = rtP . Constant_Value_jauwwxrr5h [ 1 ] * rtB . fsb4j0khha [
2 ] ; rtB . mw1ofaqc0d [ 4 ] = rtB . fsb4j0khha [ 0 ] * rtP .
Constant_Value_jauwwxrr5h [ 2 ] ; rtB . mw1ofaqc0d [ 5 ] = rtP .
Constant_Value_jauwwxrr5h [ 0 ] * rtB . fsb4j0khha [ 1 ] ; jnnmzryieq_idx_2 =
rtB . fsb4j0khha [ 0 ] + rtB . fa1rxjoibu [ 0 ] ; rtB . lp44qocih1 [ 0 ] =
jnnmzryieq_idx_2 ; jnnmzryieq_idx_2 += rtB . hmcdusmxx2 [ 0 ] ; rtB .
mynduz3xvt [ 0 ] = jnnmzryieq_idx_2 ; jnnmzryieq_idx_2 /= rtP . m ; rtB .
mi1anjx3mq [ 0 ] = jnnmzryieq_idx_2 ; rtB . o250csv04h [ 0 ] =
jnnmzryieq_idx_2 + rtB . f45wytmhlu [ 0 ] ; rtB . gvri4phsjb [ 0 ] = rtB .
mw1ofaqc0d [ 0 ] - rtB . mw1ofaqc0d [ 3 ] ; jnnmzryieq_idx_2 = rtB .
fsb4j0khha [ 1 ] + rtB . fa1rxjoibu [ 1 ] ; rtB . lp44qocih1 [ 1 ] =
jnnmzryieq_idx_2 ; jnnmzryieq_idx_2 += rtB . hmcdusmxx2 [ 1 ] ; rtB .
mynduz3xvt [ 1 ] = jnnmzryieq_idx_2 ; jnnmzryieq_idx_2 /= rtP . m ; rtB .
mi1anjx3mq [ 1 ] = jnnmzryieq_idx_2 ; rtB . o250csv04h [ 1 ] =
jnnmzryieq_idx_2 + rtB . f45wytmhlu [ 1 ] ; rtB . gvri4phsjb [ 1 ] = rtB .
mw1ofaqc0d [ 1 ] - rtB . mw1ofaqc0d [ 4 ] ; jnnmzryieq_idx_2 = rtB .
fsb4j0khha [ 2 ] + rtB . fa1rxjoibu [ 2 ] ; rtB . lp44qocih1 [ 2 ] =
jnnmzryieq_idx_2 ; jnnmzryieq_idx_2 += rtB . hmcdusmxx2 [ 2 ] ; rtB .
mynduz3xvt [ 2 ] = jnnmzryieq_idx_2 ; jnnmzryieq_idx_2 /= rtP . m ; rtB .
mi1anjx3mq [ 2 ] = jnnmzryieq_idx_2 ; rtB . o250csv04h [ 2 ] =
jnnmzryieq_idx_2 + rtB . f45wytmhlu [ 2 ] ; rtB . gvri4phsjb [ 2 ] = rtB .
mw1ofaqc0d [ 2 ] - rtB . mw1ofaqc0d [ 5 ] ; rtB . gu5gko2lp5 = rtP . cbar *
rtB . jjoh1jbcal ; rtB . i3qqkdiw05 [ 0 ] = rtP . Gain_Gain_bfommv4lak *
nz5t34xhkj ; rtB . akrbmyschb = rtB . f2sno0tuqf - rtB . fph3doyxdf ; rtB .
lcr4hfaiul = rtP . St * rtP . lt * 3.1 / ( rtP . S * rtP . cbar ) * rtB .
akrbmyschb ; rtB . i3qqkdiw05 [ 1 ] = rtP . Constant_Value_lag24fa1pj - rtB .
lcr4hfaiul ; rtB . mlkbjznxlc = rtP . Gain2_Gain_dwlwh44krh * rtB .
f2sno0tuqf ; rtB . hf33apcafb = rtP . Constant1_Value_mx4lv2w3em - rtB .
mlkbjznxlc ; rtB . i3qqkdiw05 [ 2 ] = rtB . hf33apcafb * nz5t34xhkj ; rtB .
lnimvle1rj = rtP . cbar / rtB . mf4semtcii ; for ( i = 0 ; i < 9 ; i ++ ) {
rtB . hdtg2mz21g [ i ] = rtB . lnimvle1rj * rtP . Constant1_Value_ogzj0ybhah
[ i ] ; } jnnmzryieq_idx_2 = rtB . iz1lzcyd3a [ 1 ] ; ljrbigxsf3 = rtB .
iz1lzcyd3a [ 0 ] ; jnnmzryieq_idx_0 = rtB . iz1lzcyd3a [ 2 ] ; for ( i = 0 ;
i < 3 ; i ++ ) { rtB . i1avsg3ef3 [ i ] = ( rtB . hdtg2mz21g [ i + 3 ] *
jnnmzryieq_idx_2 + rtB . hdtg2mz21g [ i ] * ljrbigxsf3 ) + rtB . hdtg2mz21g [
i + 6 ] * jnnmzryieq_idx_0 ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
kpb33w5sqa [ 0 ] > rtP . umax [ 0 ] ) { bkulx1vpsw [ 0 ] = rtP . umax [ 0 ] ;
} else if ( kpb33w5sqa [ 0 ] < rtP . umin [ 0 ] ) { bkulx1vpsw [ 0 ] = rtP .
umin [ 0 ] ; } else { bkulx1vpsw [ 0 ] = kpb33w5sqa [ 0 ] ; } for ( i = 0 ; i
< 3 ; i ++ ) { rtB . pz1o5ffnri [ i ] = ( rtP .
ControlEffectivenessMatrix_Value [ i + 3 ] * rtB . m2bzifekpx + rtP .
ControlEffectivenessMatrix_Value [ i ] * bkulx1vpsw [ 0 ] ) + rtP .
ControlEffectivenessMatrix_Value [ i + 6 ] * f1glz1ozzp ; } rtB . febx52uog3
[ 0 ] = ( rtP . mew1_Value [ 1 ] * lgrnr0ewrf_idx_2 - lgrnr0ewrf_idx_1 * rtP
. mew1_Value [ 2 ] ) + ( rtP . mew2_Value [ 1 ] * dci3fqdzol_idx_2 -
dci3fqdzol_idx_1 * rtP . mew2_Value [ 2 ] ) ; rtB . febx52uog3 [ 1 ] = (
lgrnr0ewrf_idx_0 * rtP . mew1_Value [ 2 ] - rtP . mew1_Value [ 0 ] *
lgrnr0ewrf_idx_2 ) + ( dci3fqdzol_idx_0 * rtP . mew2_Value [ 2 ] - rtP .
mew2_Value [ 0 ] * dci3fqdzol_idx_2 ) ; rtB . febx52uog3 [ 2 ] = ( rtP .
mew1_Value [ 0 ] * lgrnr0ewrf_idx_1 - lgrnr0ewrf_idx_0 * rtP . mew1_Value [ 1
] ) + ( rtP . mew2_Value [ 0 ] * dci3fqdzol_idx_1 - dci3fqdzol_idx_0 * rtP .
mew2_Value [ 1 ] ) ; } f1glz1ozzp = ( rtB . i3qqkdiw05 [ 0 ] + rtB .
i1avsg3ef3 [ 0 ] ) + rtB . pz1o5ffnri [ 0 ] ; rtB . o3faktraka [ 0 ] =
f1glz1ozzp ; f1glz1ozzp *= rtB . gu5gko2lp5 ; rtB . i3xmajgkf0 [ 0 ] =
f1glz1ozzp ; rtB . ddtcpvxvbu [ 0 ] = rtB . gvri4phsjb [ 0 ] + f1glz1ozzp ;
f1glz1ozzp = ( rtB . i3qqkdiw05 [ 1 ] + rtB . i1avsg3ef3 [ 1 ] ) + rtB .
pz1o5ffnri [ 1 ] ; rtB . o3faktraka [ 1 ] = f1glz1ozzp ; f1glz1ozzp *= rtB .
gu5gko2lp5 ; rtB . i3xmajgkf0 [ 1 ] = f1glz1ozzp ; rtB . ddtcpvxvbu [ 1 ] =
rtB . gvri4phsjb [ 1 ] + f1glz1ozzp ; f1glz1ozzp = ( rtB . i3qqkdiw05 [ 2 ] +
rtB . i1avsg3ef3 [ 2 ] ) + rtB . pz1o5ffnri [ 2 ] ; rtB . o3faktraka [ 2 ] =
f1glz1ozzp ; f1glz1ozzp *= rtB . gu5gko2lp5 ; rtB . i3xmajgkf0 [ 2 ] =
f1glz1ozzp ; rtB . ddtcpvxvbu [ 2 ] = rtB . gvri4phsjb [ 2 ] + f1glz1ozzp ;
jnnmzryieq_idx_2 = rtB . iz1lzcyd3a [ 1 ] ; ljrbigxsf3 = rtB . iz1lzcyd3a [ 0
] ; jnnmzryieq_idx_0 = rtB . iz1lzcyd3a [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ )
{ rtB . ay5hewygdd [ i ] = rtB . ddtcpvxvbu [ i ] + rtB . febx52uog3 [ i ] ;
rtB . lgn5qxdsfl [ i ] = ( rtB . pdlcsr0mtt [ i + 3 ] * jnnmzryieq_idx_2 +
rtB . pdlcsr0mtt [ i ] * ljrbigxsf3 ) + rtB . pdlcsr0mtt [ i + 6 ] *
jnnmzryieq_idx_0 ; rtB . alzlbjc0as [ i ] = ( rtB . exah40fyce [ i + 3 ] *
jnnmzryieq_idx_2 + rtB . exah40fyce [ i ] * ljrbigxsf3 ) + rtB . exah40fyce [
i + 6 ] * jnnmzryieq_idx_0 ; } rtB . o2w2qidibo = rtB . iz1lzcyd3a [ 1 ] *
rtB . lgn5qxdsfl [ 2 ] ; rtB . bfvnrwgw1h = rtB . lgn5qxdsfl [ 0 ] * rtB .
iz1lzcyd3a [ 2 ] ; rtB . en0jsvv1cd = rtB . iz1lzcyd3a [ 0 ] * rtB .
lgn5qxdsfl [ 1 ] ; rtB . eyyenf2ob2 = rtB . lgn5qxdsfl [ 1 ] * rtB .
iz1lzcyd3a [ 2 ] ; rtB . onfee4huot = rtB . iz1lzcyd3a [ 0 ] * rtB .
lgn5qxdsfl [ 2 ] ; rtB . e0tzo2c4hh = rtB . lgn5qxdsfl [ 0 ] * rtB .
iz1lzcyd3a [ 1 ] ; rtB . j3jivuya1i [ 0 ] = rtB . o2w2qidibo - rtB .
eyyenf2ob2 ; rtB . j3jivuya1i [ 1 ] = rtB . bfvnrwgw1h - rtB . onfee4huot ;
rtB . j3jivuya1i [ 2 ] = rtB . en0jsvv1cd - rtB . e0tzo2c4hh ; rtB .
kswqxwm5fc [ 0 ] = ( rtB . ay5hewygdd [ 0 ] - rtB . alzlbjc0as [ 0 ] ) - rtB
. j3jivuya1i [ 0 ] ; rtB . kswqxwm5fc [ 1 ] = ( rtB . ay5hewygdd [ 1 ] - rtB
. alzlbjc0as [ 1 ] ) - rtB . j3jivuya1i [ 1 ] ; rtB . kswqxwm5fc [ 2 ] = (
rtB . ay5hewygdd [ 2 ] - rtB . alzlbjc0as [ 2 ] ) - rtB . j3jivuya1i [ 2 ] ;
rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf ( rtB . kswqxwm5fc , rtB . ghgjlawphx ,
rtB . py1jp4xfdb ) ; for ( i = 0 ; i < 3 ; i ++ ) { rtB . nbxandr1dq [ i ] =
rtB . py1jp4xfdb [ i ] ; rtB . h4ublwxemc [ 3 * i ] = rtB . akshdvntgj [ i ]
; rtB . h4ublwxemc [ 3 * i + 1 ] = rtB . akshdvntgj [ i + 3 ] ; rtB .
h4ublwxemc [ 3 * i + 2 ] = rtB . akshdvntgj [ i + 6 ] ; } lgrnr0ewrf_idx_0 =
rtB . c10sww4qfc [ 1 ] ; lgrnr0ewrf_idx_1 = rtB . c10sww4qfc [ 0 ] ;
lgrnr0ewrf_idx_2 = rtB . c10sww4qfc [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) {
dci3fqdzol_idx_0 = ( rtB . h4ublwxemc [ i + 3 ] * lgrnr0ewrf_idx_0 + rtB .
h4ublwxemc [ i ] * lgrnr0ewrf_idx_1 ) + rtB . h4ublwxemc [ i + 6 ] *
lgrnr0ewrf_idx_2 ; rtB . bcjcqbvmdf [ i ] = dci3fqdzol_idx_0 ; rtB .
fsrrtwrymg [ i ] = dci3fqdzol_idx_0 ; } { if ( rtDW . pfdn5tsup5 . AQHandles
[ 0 ] && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . pfdn5tsup5 .
AQHandles [ 0 ] , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB . mi1anjx3mq [
0 ] + 0 ) ; sdiWriteSignal ( rtDW . pfdn5tsup5 . AQHandles [ 1 ] ,
ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB . o250csv04h [ 0 ] + 0 ) ;
sdiWriteSignal ( rtDW . pfdn5tsup5 . AQHandles [ 2 ] , ssGetTaskTime ( rtS ,
0 ) , ( char * ) & rtB . nbxandr1dq [ 0 ] + 0 ) ; sdiWriteSignal ( rtDW .
pfdn5tsup5 . AQHandles [ 3 ] , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB .
iz1lzcyd3a [ 0 ] + 0 ) ; sdiWriteSignal ( rtDW . pfdn5tsup5 . AQHandles [ 4 ]
, ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB . etd4am2wmj [ 0 ] + 0 ) ;
sdiWriteSignal ( rtDW . pfdn5tsup5 . AQHandles [ 5 ] , ssGetTaskTime ( rtS ,
0 ) , ( char * ) & rtB . akshdvntgj [ 0 ] + 0 ) ; sdiWriteSignal ( rtDW .
pfdn5tsup5 . AQHandles [ 6 ] , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB .
pwlerz4zmu [ 0 ] + 0 ) ; sdiWriteSignal ( rtDW . pfdn5tsup5 . AQHandles [ 7 ]
, ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB . iam1jhjhep [ 0 ] + 0 ) ;
sdiWriteSignal ( rtDW . pfdn5tsup5 . AQHandles [ 8 ] , ssGetTaskTime ( rtS ,
0 ) , ( char * ) & rtB . fsrrtwrymg [ 0 ] + 0 ) ; sdiWriteSignal ( rtDW .
pfdn5tsup5 . AQHandles [ 9 ] , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB .
jvposjqlvw + 0 ) ; sdiWriteSignal ( rtDW . pfdn5tsup5 . AQHandles [ 10 ] ,
ssGetTaskTime ( rtS , 0 ) , ( char * ) & nc5eokin3a + 0 ) ; sdiWriteSignal (
rtDW . pfdn5tsup5 . AQHandles [ 11 ] , ssGetTaskTime ( rtS , 0 ) , ( char * )
& rtB . mf4semtcii + 0 ) ; sdiWriteSignal ( rtDW . pfdn5tsup5 . AQHandles [
12 ] , ssGetTaskTime ( rtS , 0 ) , ( char * ) & nz5t34xhkj + 0 ) ;
sdiWriteSignal ( rtDW . pfdn5tsup5 . AQHandles [ 13 ] , ssGetTaskTime ( rtS ,
0 ) , ( char * ) & rtB . f2sno0tuqf + 0 ) ; } } rtB . aex35jzv0e [ 0 ] = rtB
. o250csv04h [ 0 ] ; rtB . aex35jzv0e [ 1 ] = rtB . o250csv04h [ 1 ] ; rtB .
aex35jzv0e [ 2 ] = rtB . o250csv04h [ 2 ] ; rtB . aex35jzv0e [ 3 ] = rtB .
nbxandr1dq [ 0 ] ; rtB . aex35jzv0e [ 4 ] = rtB . nbxandr1dq [ 1 ] ; rtB .
aex35jzv0e [ 5 ] = rtB . nbxandr1dq [ 2 ] ; gyysqz5j0r [ 0 ] = rtP .
Constant_Value ; gyysqz5j0r [ 1 ] = rtP . Constant1_Value ; gyysqz5j0r [ 2 ]
= rtP . Constant1_Value ; nz5t34xhkj = muDoubleScalarSin ( rtB . pwlerz4zmu [
0 ] ) ; nc5eokin3a = muDoubleScalarTan ( rtB . pwlerz4zmu [ 1 ] ) ;
gyysqz5j0r [ 3 ] = nz5t34xhkj * nc5eokin3a ; f1glz1ozzp = muDoubleScalarCos (
rtB . pwlerz4zmu [ 0 ] ) ; gyysqz5j0r [ 4 ] = f1glz1ozzp ; jnnmzryieq_idx_2 =
muDoubleScalarCos ( rtB . pwlerz4zmu [ 1 ] ) ; gyysqz5j0r [ 5 ] = nz5t34xhkj
/ jnnmzryieq_idx_2 ; gyysqz5j0r [ 6 ] = f1glz1ozzp * nc5eokin3a ; gyysqz5j0r
[ 7 ] = - nz5t34xhkj ; gyysqz5j0r [ 8 ] = f1glz1ozzp / jnnmzryieq_idx_2 ;
jnnmzryieq_idx_2 = rtB . iz1lzcyd3a [ 1 ] ; ljrbigxsf3 = rtB . iz1lzcyd3a [ 0
] ; jnnmzryieq_idx_0 = rtB . iz1lzcyd3a [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ )
{ bkulx1vpsw [ i ] = ( gyysqz5j0r [ i + 3 ] * jnnmzryieq_idx_2 + gyysqz5j0r [
i ] * ljrbigxsf3 ) + gyysqz5j0r [ i + 6 ] * jnnmzryieq_idx_0 ; } rtB .
aex35jzv0e [ 6 ] = bkulx1vpsw [ 0 ] ; rtB . aex35jzv0e [ 7 ] = bkulx1vpsw [ 1
] ; rtB . aex35jzv0e [ 8 ] = bkulx1vpsw [ 2 ] ; rtB . aex35jzv0e [ 9 ] = rtB
. fsrrtwrymg [ 0 ] ; rtB . aex35jzv0e [ 10 ] = rtB . fsrrtwrymg [ 1 ] ; rtB .
aex35jzv0e [ 11 ] = rtB . fsrrtwrymg [ 2 ] ; { if ( rtDW . bux0bm1vm5 .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . bux0bm1vm5 .
AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB . aex35jzv0e [ 0 ] +
0 ) ; } } rtB . ogdzjb4jan = rtP . Gain_Gain_ftxlqxfaiq * rtB . nbxandr1dq [
0 ] ; rtB . nbnq3nxxt1 = rtP . Gain_Gain_lov5qcjzgk * rtB . nbxandr1dq [ 1 ]
; rtB . ny4fdqpjjc = rtP . Gain_Gain_l2z5belp2u * rtB . nbxandr1dq [ 2 ] ;
rtB . fs1sshlnh1 = - rtB . fsrrtwrymg [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 ,
0 ) ) { { if ( rtDW . kvvcjgui0t . AQHandles && ssGetLogOutput ( rtS ) ) {
sdiWriteSignal ( rtDW . kvvcjgui0t . AQHandles , ssGetTaskTime ( rtS , 1 ) ,
( char * ) & rtB . kiowxcg1sw [ 0 ] + 0 ) ; } } { if ( rtDW . lhn5xaz053 .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . lhn5xaz053 .
AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . pqj4t3vzft + 0 ) ;
} } { if ( rtDW . djq4c1imrv . AQHandles && ssGetLogOutput ( rtS ) ) {
sdiWriteSignal ( rtDW . djq4c1imrv . AQHandles , ssGetTaskTime ( rtS , 1 ) ,
( char * ) & rtB . fph3doyxdf + 0 ) ; } } } muDoubleScalarSinCos ( rtB .
pwlerz4zmu [ 0 ] , & bkulx1vpsw [ 0 ] , & jnnmzryieq_idx_0 ) ;
muDoubleScalarSinCos ( rtB . pwlerz4zmu [ 1 ] , & bkulx1vpsw [ 1 ] , &
jnnmzryieq_idx_1 ) ; rtB . hhre2rxku1 [ 0 ] = ( bkulx1vpsw [ 0 ] * rtB .
iz1lzcyd3a [ 1 ] + jnnmzryieq_idx_0 * rtB . iz1lzcyd3a [ 2 ] ) * ( bkulx1vpsw
[ 1 ] / jnnmzryieq_idx_1 ) + rtB . iz1lzcyd3a [ 0 ] ; rtB . hhre2rxku1 [ 1 ]
= jnnmzryieq_idx_0 * rtB . iz1lzcyd3a [ 1 ] - bkulx1vpsw [ 0 ] * rtB .
iz1lzcyd3a [ 2 ] ; rtB . hhre2rxku1 [ 2 ] = ( bkulx1vpsw [ 0 ] * rtB .
iz1lzcyd3a [ 1 ] + jnnmzryieq_idx_0 * rtB . iz1lzcyd3a [ 2 ] ) /
jnnmzryieq_idx_1 ; UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2 ( int_T
tid ) { real_T e3kctmyeph_p ; int32_T i ; for ( i = 0 ; i < 3 ; i ++ ) {
e3kctmyeph_p = rtP . Ib [ 3 * i ] ; rtB . pdlcsr0mtt [ 3 * i ] = e3kctmyeph_p
; rtB . exah40fyce [ 3 * i ] = rtP . Constant2_Value [ 3 * i ] ; rtB .
ghgjlawphx [ 3 * i ] = e3kctmyeph_p ; e3kctmyeph_p = rtP . Ib [ 3 * i + 1 ] ;
rtB . pdlcsr0mtt [ 3 * i + 1 ] = e3kctmyeph_p ; rtB . exah40fyce [ 3 * i + 1
] = rtP . Constant2_Value [ 3 * i + 1 ] ; rtB . ghgjlawphx [ 3 * i + 1 ] =
e3kctmyeph_p ; e3kctmyeph_p = rtP . Ib [ 3 * i + 2 ] ; rtB . pdlcsr0mtt [ 3 *
i + 2 ] = e3kctmyeph_p ; rtB . exah40fyce [ 3 * i + 2 ] = rtP .
Constant2_Value [ 3 * i + 2 ] ; rtB . ghgjlawphx [ 3 * i + 2 ] = e3kctmyeph_p
; } rtB . kpztmnslrx [ 0 ] = rtP . Constant3_Value ; rtB . kpztmnslrx [ 1 ] =
rtP . Constant3_Value ; rtB . kpztmnslrx [ 2 ] = rtP . m * rtP . g ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { UNUSED_PARAMETER
( tid ) ; } void MdlUpdateTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
void MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * )
ssGetdX ( rtS ) ) ; _rtXdot -> a0yjmh1lt4 [ 0 ] = rtB . o250csv04h [ 0 ] ;
_rtXdot -> lbrsb4nz1j [ 0 ] = rtB . nbxandr1dq [ 0 ] ; _rtXdot -> hd5q5c4pq3
[ 0 ] = rtB . hhre2rxku1 [ 0 ] ; _rtXdot -> e1rxwddgzh [ 0 ] = rtB .
bcjcqbvmdf [ 0 ] ; _rtXdot -> a0yjmh1lt4 [ 1 ] = rtB . o250csv04h [ 1 ] ;
_rtXdot -> lbrsb4nz1j [ 1 ] = rtB . nbxandr1dq [ 1 ] ; _rtXdot -> hd5q5c4pq3
[ 1 ] = rtB . hhre2rxku1 [ 1 ] ; _rtXdot -> e1rxwddgzh [ 1 ] = rtB .
bcjcqbvmdf [ 1 ] ; _rtXdot -> a0yjmh1lt4 [ 2 ] = rtB . o250csv04h [ 2 ] ;
_rtXdot -> lbrsb4nz1j [ 2 ] = rtB . nbxandr1dq [ 2 ] ; _rtXdot -> hd5q5c4pq3
[ 2 ] = rtB . hhre2rxku1 [ 2 ] ; _rtXdot -> e1rxwddgzh [ 2 ] = rtB .
bcjcqbvmdf [ 2 ] ; } void MdlProjection ( void ) { } void MdlZeroCrossings (
void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector (
rtS ) ) ; _rtZCSV -> gpk0440qdo = rtB . pt5pzvbxss - rtP .
Limitaltitudetotroposhere_UpperSat ; _rtZCSV -> a2s5i2cu4h = rtB . pt5pzvbxss
- rtP . Limitaltitudetotroposhere_LowerSat ; _rtZCSV -> kcn5rnx1st = rtB .
fdgklgayoh - rtP . LimitaltitudetoStratosphere_UpperSat ; _rtZCSV ->
mbl10yqsuo = rtB . fdgklgayoh - rtP . LimitaltitudetoStratosphere_LowerSat ;
_rtZCSV -> p1dw0zgaba = ssGetT ( rtS ) - rtP . Step1_Time ; _rtZCSV ->
jjzt1fvbzq = 0.0 ; if ( rtP . alpha_switch >= rtB . f2sno0tuqf ) { _rtZCSV ->
jjzt1fvbzq = 1.0 ; } } void MdlTerminate ( void ) { { if ( rtDW . pfdn5tsup5
. AQHandles [ 0 ] ) { sdiTerminateStreaming ( & rtDW . pfdn5tsup5 . AQHandles
[ 0 ] ) ; } if ( rtDW . pfdn5tsup5 . AQHandles [ 1 ] ) {
sdiTerminateStreaming ( & rtDW . pfdn5tsup5 . AQHandles [ 1 ] ) ; } if ( rtDW
. pfdn5tsup5 . AQHandles [ 2 ] ) { sdiTerminateStreaming ( & rtDW .
pfdn5tsup5 . AQHandles [ 2 ] ) ; } if ( rtDW . pfdn5tsup5 . AQHandles [ 3 ] )
{ sdiTerminateStreaming ( & rtDW . pfdn5tsup5 . AQHandles [ 3 ] ) ; } if (
rtDW . pfdn5tsup5 . AQHandles [ 4 ] ) { sdiTerminateStreaming ( & rtDW .
pfdn5tsup5 . AQHandles [ 4 ] ) ; } if ( rtDW . pfdn5tsup5 . AQHandles [ 5 ] )
{ sdiTerminateStreaming ( & rtDW . pfdn5tsup5 . AQHandles [ 5 ] ) ; } if (
rtDW . pfdn5tsup5 . AQHandles [ 6 ] ) { sdiTerminateStreaming ( & rtDW .
pfdn5tsup5 . AQHandles [ 6 ] ) ; } if ( rtDW . pfdn5tsup5 . AQHandles [ 7 ] )
{ sdiTerminateStreaming ( & rtDW . pfdn5tsup5 . AQHandles [ 7 ] ) ; } if (
rtDW . pfdn5tsup5 . AQHandles [ 8 ] ) { sdiTerminateStreaming ( & rtDW .
pfdn5tsup5 . AQHandles [ 8 ] ) ; } if ( rtDW . pfdn5tsup5 . AQHandles [ 9 ] )
{ sdiTerminateStreaming ( & rtDW . pfdn5tsup5 . AQHandles [ 9 ] ) ; } if (
rtDW . pfdn5tsup5 . AQHandles [ 10 ] ) { sdiTerminateStreaming ( & rtDW .
pfdn5tsup5 . AQHandles [ 10 ] ) ; } if ( rtDW . pfdn5tsup5 . AQHandles [ 11 ]
) { sdiTerminateStreaming ( & rtDW . pfdn5tsup5 . AQHandles [ 11 ] ) ; } if (
rtDW . pfdn5tsup5 . AQHandles [ 12 ] ) { sdiTerminateStreaming ( & rtDW .
pfdn5tsup5 . AQHandles [ 12 ] ) ; } if ( rtDW . pfdn5tsup5 . AQHandles [ 13 ]
) { sdiTerminateStreaming ( & rtDW . pfdn5tsup5 . AQHandles [ 13 ] ) ; } } {
if ( rtDW . bux0bm1vm5 . AQHandles ) { sdiTerminateStreaming ( & rtDW .
bux0bm1vm5 . AQHandles ) ; } } { if ( rtDW . kvvcjgui0t . AQHandles ) {
sdiTerminateStreaming ( & rtDW . kvvcjgui0t . AQHandles ) ; } } { if ( rtDW .
lhn5xaz053 . AQHandles ) { sdiTerminateStreaming ( & rtDW . lhn5xaz053 .
AQHandles ) ; } } { if ( rtDW . djq4c1imrv . AQHandles ) {
sdiTerminateStreaming ( & rtDW . djq4c1imrv . AQHandles ) ; } } } static void
mr_RCAM_sim1_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) ; static void
mr_RCAM_sim1_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_RCAM_sim1_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_RCAM_sim1_restoreDataFromMxArray ( void * destData , const mxArray *
srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_RCAM_sim1_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_RCAM_sim1_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j
, uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_RCAM_sim1_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex
i , int j , uint_T numBits ) ; static uint_T
mr_RCAM_sim1_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex
i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_RCAM_sim1_cacheDataToMxArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_RCAM_sim1_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_RCAM_sim1_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_RCAM_sim1_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_RCAM_sim1_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_RCAM_sim1_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
real_T ) fieldVal ) ) ; } static uint_T
mr_RCAM_sim1_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_RCAM_sim1_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_RCAM_sim1_GetDWork ( ) { static const char_T *
ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW
= mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_RCAM_sim1_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB ) ,
sizeof ( rtB ) ) ; { static const char_T * rtdwDataFieldNames [ 8 ] = {
"rtDW.h1abylwox0" , "rtDW.gtrkyqalzw" , "rtDW.bcixyiccvs" , "rtDW.azdfo1yqhk"
, "rtDW.m5ykicffnh" , "rtDW.gqihoqfbig" , "rtDW.mzyyrqm3kv" ,
"rtDW.exrt0pkk0n" , } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 , 8
, rtdwDataFieldNames ) ; mr_RCAM_sim1_cacheDataAsMxArray ( rtdwData , 0 , 0 ,
( const void * ) & ( rtDW . h1abylwox0 ) , sizeof ( rtDW . h1abylwox0 ) ) ;
mr_RCAM_sim1_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & (
rtDW . gtrkyqalzw ) , sizeof ( rtDW . gtrkyqalzw ) ) ;
mr_RCAM_sim1_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & (
rtDW . bcixyiccvs ) , sizeof ( rtDW . bcixyiccvs ) ) ;
mr_RCAM_sim1_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & (
rtDW . azdfo1yqhk ) , sizeof ( rtDW . azdfo1yqhk ) ) ;
mr_RCAM_sim1_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & (
rtDW . m5ykicffnh ) , sizeof ( rtDW . m5ykicffnh ) ) ;
mr_RCAM_sim1_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & (
rtDW . gqihoqfbig ) , sizeof ( rtDW . gqihoqfbig ) ) ;
mr_RCAM_sim1_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & (
rtDW . mzyyrqm3kv ) , sizeof ( rtDW . mzyyrqm3kv ) ) ;
mr_RCAM_sim1_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & (
rtDW . exrt0pkk0n ) , sizeof ( rtDW . exrt0pkk0n ) ) ; mxSetFieldByNumber (
ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void mr_RCAM_sim1_SetDWork (
const mxArray * ssDW ) { ( void ) ssDW ; mr_RCAM_sim1_restoreDataFromMxArray
( ( void * ) & ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray *
rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_RCAM_sim1_restoreDataFromMxArray ( ( void * ) & ( rtDW . h1abylwox0 ) ,
rtdwData , 0 , 0 , sizeof ( rtDW . h1abylwox0 ) ) ;
mr_RCAM_sim1_restoreDataFromMxArray ( ( void * ) & ( rtDW . gtrkyqalzw ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . gtrkyqalzw ) ) ;
mr_RCAM_sim1_restoreDataFromMxArray ( ( void * ) & ( rtDW . bcixyiccvs ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . bcixyiccvs ) ) ;
mr_RCAM_sim1_restoreDataFromMxArray ( ( void * ) & ( rtDW . azdfo1yqhk ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . azdfo1yqhk ) ) ;
mr_RCAM_sim1_restoreDataFromMxArray ( ( void * ) & ( rtDW . m5ykicffnh ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . m5ykicffnh ) ) ;
mr_RCAM_sim1_restoreDataFromMxArray ( ( void * ) & ( rtDW . gqihoqfbig ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . gqihoqfbig ) ) ;
mr_RCAM_sim1_restoreDataFromMxArray ( ( void * ) & ( rtDW . mzyyrqm3kv ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . mzyyrqm3kv ) ) ;
mr_RCAM_sim1_restoreDataFromMxArray ( ( void * ) & ( rtDW . exrt0pkk0n ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . exrt0pkk0n ) ) ; } } mxArray *
mr_RCAM_sim1_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 9 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char_T * blockType [ 9 ] = { "Scope" , "Scope" , "Scope" , "Scope" , "Scope"
, "Scope" , "Scope" , "Scope" , "Scope" , } ; static const char_T * blockPath
[ 9 ] = { "RCAM_sim1/Scopes&Output/RCAMScope1" ,
"RCAM_sim1/Scopes&Output/alphabetagamma" , "RCAM_sim1/Scopes&Output/euler" ,
"RCAM_sim1/Scopes&Output/pqr" , "RCAM_sim1/Scopes&Output/pqrdot" ,
"RCAM_sim1/Scopes&Output/uvw" , "RCAM_sim1/Scopes&Output/uvwdot" ,
"RCAM_sim1/Scopes&Output/ve" , "RCAM_sim1/Scopes&Output/xe" , } ; static
const int reason [ 9 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , } ; for ( subs
[ 0 ] = 0 ; subs [ 0 ] < 9 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateDoubleScalar ( ( real_T ) reason [ subs [ 0 ] ] ) ) ; } } return data
; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 12 ) ;
ssSetNumPeriodicContStates ( rtS , 3 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 251 ) ; ssSetNumBlockIO ( rtS , 113 ) ;
ssSetNumBlockParams ( rtS , 135 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 449807628U ) ;
ssSetChecksumVal ( rtS , 1 , 3424572996U ) ; ssSetChecksumVal ( rtS , 2 ,
336135214U ) ; ssSetChecksumVal ( rtS , 3 , 2211097397U ) ; }
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
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; } { real_T * x
= ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void
* ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW )
) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) &
dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ;
dtInfo . numDataTypes = 23 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ]
; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } RCAM_sim1_InitializeDataMapInfo (
) ; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS )
; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"RCAM_sim1" ) ; ssSetPath ( rtS , "RCAM_sim1" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 0.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 3 , 3
, 3 , 3 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 }
; static int_T rt_LoggedStateDimensions [ ] = { 3 , 3 , 3 , 3 } ; static
boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 } ; static
BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0
, 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/ub,vb,wb" ,
"RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/p,q,r " ,
 "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/Calculate DCM &\nEuler Angles/phi\ntheta\npsi"
, "RCAM_sim1/RCAM/EOM&Environment/6DOF (Euler Angles)/xe,ye,ze" } ; static
const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" } ; static
boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 4 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 4 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . a0yjmh1lt4 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . lbrsb4nz1j [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . hd5q5c4pq3 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . e1rxwddgzh [ 0 ] ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ;
ssSetPeriodicContStateIndices ( rtS , rtPeriodicIndX ) ; ( void ) memset ( (
void * ) rtPeriodicIndX , 0 , 3 * sizeof ( int_T ) ) ;
ssSetPeriodicContStateRanges ( rtS , rtPeriodicRngX ) ; ( void ) memset ( (
void * ) rtPeriodicRngX , 0 , 6 * sizeof ( real_T ) ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 12 ] ;
static real_T absTol [ 12 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static
uint8_T absTolControl [ 12 ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U } ; static real_T contStateJacPerturbBoundMinVec [ 12 ] ; static
real_T contStateJacPerturbBoundMaxVec [ 12 ] ; static uint8_T zcAttributes [
6 ] = { ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) } ; static
ssNonContDerivSigInfo nonContDerivSigInfo [ 5 ] = { { 3 * sizeof ( real_T ) ,
( char * ) ( & rtB . febx52uog3 [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real_T
) , ( char * ) ( & rtB . pz1o5ffnri [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real_T ) , ( char * ) ( & rtB . fa1rxjoibu [ 0 ] ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . m2bzifekpx ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . kyodpk4kvr ) , ( NULL ) } } ; { int
i ; for ( i = 0 ; i < 12 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ] = 0
; contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } } ssSetSolverRelTol
( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0
) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 )
; ssSetMaxStepSize ( rtS , 0.2 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
5 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 6 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 6 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 449807628U ) ; ssSetChecksumVal ( rtS , 1 ,
3424572996U ) ; ssSetChecksumVal ( rtS , 2 , 336135214U ) ; ssSetChecksumVal
( rtS , 3 , 2211097397U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 3 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = ( sysRanDType * ) &
rtDW . mzyyrqm3kv ; systemRan [ 2 ] = ( sysRanDType * ) & rtDW . exrt0pkk0n ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_RCAM_sim1_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP (
rtS , mr_RCAM_sim1_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_RCAM_sim1_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
