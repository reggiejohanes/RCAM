#ifndef RTW_HEADER_RCAM_sim1_h_
#define RTW_HEADER_RCAM_sim1_h_
#ifndef RCAM_sim1_COMMON_INCLUDES_
#define RCAM_sim1_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
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
#include "RCAM_sim1_types.h"
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME RCAM_sim1
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (113) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (12)   
#elif NCSTATES != 12
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
typedef struct { real_T c10sww4qfc [ 3 ] ; real_T etd4am2wmj [ 3 ] ; real_T
iz1lzcyd3a [ 3 ] ; real_T d1t3jcdw1w ; real_T pwlerz4zmu [ 3 ] ; real_T
kwagzwu5gd ; real_T iam1jhjhep [ 3 ] ; real_T pntd0wqwje ; real_T njx2l41pcu
; real_T ftrrsvm4qz ; real_T o01hcd1hwc ; real_T fgkyl4gpeb ; real_T
gw5me3glut ; real_T mf4semtcii ; real_T f2sno0tuqf ; real_T dpzkdmkvzx ;
real_T ozpmvwdhed ; real_T gu4fdkfnej ; real_T ccfglqcque ; real_T fzzfxafjlu
[ 3 ] ; real_T akshdvntgj [ 9 ] ; real_T hmcdusmxx2 [ 3 ] ; real_T abopebv22d
[ 9 ] ; real_T pt5pzvbxss ; real_T oyvt50li2v ; real_T cnwqcjfxbd ; real_T
lfcw5ky34x ; real_T ppzmvjgz3o ; real_T ilkefjjycy ; real_T g5412zpwqu ;
real_T fdgklgayoh ; real_T idxg52v4a5 ; real_T mkj2w3ap12 ; real_T ixd3mmmbvw
; real_T jvposjqlvw ; real_T nlfhqpdwsg ; real_T lzdkj2knvd ; real_T
jjoh1jbcal ; real_T bzatbelz3c ; real_T iirpepr453 ; real_T cz4qtuhpp2 ;
real_T lgam5r5wm4 ; real_T l2a1ipflwy ; real_T kyodpk4kvr ; real_T galszwoxqw
; real_T hmndehnp3x ; real_T fph3doyxdf ; real_T nqkem2zrkc ; real_T
m2bzifekpx ; real_T dwusv2m5gc ; real_T lgmerzx4g3 ; real_T o0uiwu2wn4 ;
real_T m5hwtguh1n ; real_T pqj4t3vzft ; real_T kg5nlp1vty ; real_T e4fhvpsn0a
[ 3 ] ; real_T kiowxcg1sw [ 3 ] ; real_T fsb4j0khha [ 3 ] ; real_T fa1rxjoibu
[ 3 ] ; real_T lp44qocih1 [ 3 ] ; real_T mynduz3xvt [ 3 ] ; real_T mi1anjx3mq
[ 3 ] ; real_T kds1ep2sd0 ; real_T ihcsgspswd ; real_T dkdpuf2nrz ; real_T
oknc4qrqul ; real_T hp150xzlm5 ; real_T duwuhux2st ; real_T f45wytmhlu [ 3 ]
; real_T o250csv04h [ 3 ] ; real_T mw1ofaqc0d [ 6 ] ; real_T gvri4phsjb [ 3 ]
; real_T gu5gko2lp5 ; real_T akrbmyschb ; real_T lcr4hfaiul ; real_T
mlkbjznxlc ; real_T hf33apcafb ; real_T i3qqkdiw05 [ 3 ] ; real_T lnimvle1rj
; real_T hdtg2mz21g [ 9 ] ; real_T i1avsg3ef3 [ 3 ] ; real_T pz1o5ffnri [ 3 ]
; real_T o3faktraka [ 3 ] ; real_T i3xmajgkf0 [ 3 ] ; real_T ddtcpvxvbu [ 3 ]
; real_T febx52uog3 [ 3 ] ; real_T ay5hewygdd [ 3 ] ; real_T alzlbjc0as [ 3 ]
; real_T lgn5qxdsfl [ 3 ] ; real_T o2w2qidibo ; real_T bfvnrwgw1h ; real_T
en0jsvv1cd ; real_T eyyenf2ob2 ; real_T onfee4huot ; real_T e0tzo2c4hh ;
real_T j3jivuya1i [ 3 ] ; real_T kswqxwm5fc [ 3 ] ; real_T py1jp4xfdb [ 3 ] ;
real_T nbxandr1dq [ 3 ] ; real_T h4ublwxemc [ 9 ] ; real_T bcjcqbvmdf [ 3 ] ;
real_T fsrrtwrymg [ 3 ] ; real_T aex35jzv0e [ 12 ] ; real_T ogdzjb4jan ;
real_T nbnq3nxxt1 ; real_T ny4fdqpjjc ; real_T fs1sshlnh1 ; real_T hhre2rxku1
[ 3 ] ; real_T pdlcsr0mtt [ 9 ] ; real_T exah40fyce [ 9 ] ; real_T ghgjlawphx
[ 9 ] ; real_T kpztmnslrx [ 3 ] ; real_T pvuzvh4wal ; } B ; typedef struct {
real_T h1abylwox0 [ 9 ] ; struct { void * LoggedData [ 16 ] ; } hscbc0octt ;
struct { void * AQHandles [ 14 ] ; } pfdn5tsup5 ; struct { void * AQHandles ;
} bux0bm1vm5 ; struct { void * LoggedData [ 4 ] ; } iw20iq135h ; struct {
void * LoggedData [ 3 ] ; } oi4b5hlxk3 ; struct { void * LoggedData [ 3 ] ; }
bfstchyvk0 ; struct { void * LoggedData [ 3 ] ; } g23vkedp5p ; struct { void
* LoggedData [ 3 ] ; } ewg25jo1kp ; struct { void * LoggedData [ 3 ] ; }
kmt2j0zhf4 ; struct { void * LoggedData [ 3 ] ; } fqmnt2n3sq ; struct { void
* LoggedData [ 3 ] ; } j421adr5dl ; struct { void * AQHandles ; } kvvcjgui0t
; struct { void * AQHandles ; } lhn5xaz053 ; struct { void * AQHandles ; }
djq4c1imrv ; int_T gtrkyqalzw ; int_T bcixyiccvs ; int_T azdfo1yqhk ; int8_T
m5ykicffnh ; int8_T gqihoqfbig ; int8_T mzyyrqm3kv ; int8_T exrt0pkk0n ; } DW
; typedef struct { real_T a0yjmh1lt4 [ 3 ] ; real_T lbrsb4nz1j [ 3 ] ; real_T
hd5q5c4pq3 [ 3 ] ; real_T e1rxwddgzh [ 3 ] ; } X ; typedef int_T PeriodicIndX
[ 3 ] ; typedef real_T PeriodicRngX [ 6 ] ; typedef struct { real_T
a0yjmh1lt4 [ 3 ] ; real_T lbrsb4nz1j [ 3 ] ; real_T hd5q5c4pq3 [ 3 ] ; real_T
e1rxwddgzh [ 3 ] ; } XDot ; typedef struct { boolean_T a0yjmh1lt4 [ 3 ] ;
boolean_T lbrsb4nz1j [ 3 ] ; boolean_T hd5q5c4pq3 [ 3 ] ; boolean_T
e1rxwddgzh [ 3 ] ; } XDis ; typedef struct { real_T a0yjmh1lt4 [ 3 ] ; real_T
lbrsb4nz1j [ 3 ] ; real_T hd5q5c4pq3 [ 3 ] ; real_T e1rxwddgzh [ 3 ] ; }
CStateAbsTol ; typedef struct { real_T a0yjmh1lt4 [ 3 ] ; real_T lbrsb4nz1j [
3 ] ; real_T hd5q5c4pq3 [ 3 ] ; real_T e1rxwddgzh [ 3 ] ; } CXPtMin ; typedef
struct { real_T a0yjmh1lt4 [ 3 ] ; real_T lbrsb4nz1j [ 3 ] ; real_T
hd5q5c4pq3 [ 3 ] ; real_T e1rxwddgzh [ 3 ] ; } CXPtMax ; typedef struct {
real_T gpk0440qdo ; real_T a2s5i2cu4h ; real_T kcn5rnx1st ; real_T mbl10yqsuo
; real_T p1dw0zgaba ; real_T jjzt1fvbzq ; } ZCV ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T Ib [ 9 ] ;
real_T S ; real_T St ; real_T Vb0 [ 3 ] ; real_T Xe0 [ 3 ] ; real_T alpha_L0
; real_T alpha_switch ; real_T cbar ; real_T cd_c1 ; real_T cd_c2 ; real_T
cd_m1 ; real_T cd_m2 ; real_T dCYdRud ; real_T dCYdbeta ; real_T depsda ;
real_T euler0 [ 3 ] ; real_T g ; real_T lt ; real_T m ; real_T n ; real_T
pqr0 [ 3 ] ; real_T u0 [ 5 ] ; real_T umax [ 5 ] ; real_T umin [ 5 ] ; real_T
Polynomial_Coefs [ 4 ] ; real_T Gain_Gain ; real_T
phithetapsi_WrappedStateUpperValue ; real_T
phithetapsi_WrappedStateLowerValue ; real_T Gain_Gain_bxpznsjmpu ; real_T
Gain_Gain_h1ktjeexx1 ; real_T Gain_Gain_brtoidrzvi ; real_T
Gain_Gain_o2nz4hlc0y ; real_T Gain_Gain_grtmmf3s4r ; real_T
Gain_Gain_nkk2ewvwrs ; real_T Gain_Gain_cyh2wwurhc ; real_T
Gain_Gain_hnrzzhh2v0 ; real_T Gain_Gain_acmismgbcw ; real_T
Limitaltitudetotroposhere_UpperSat ; real_T
Limitaltitudetotroposhere_LowerSat ; real_T LapseRate_Gain ; real_T uT0_Gain
; real_T rho0_Gain ; real_T LimitaltitudetoStratosphere_UpperSat ; real_T
LimitaltitudetoStratosphere_LowerSat ; real_T gR_Gain ; real_T
Gain_Gain_bxawv450gg ; real_T Gain1_Gain ; real_T Step1_Time ; real_T
Step1_Y0 ; real_T Step1_YFinal ; real_T Gain1_Gain_hfbnedsnqk ; real_T
Gain2_Gain ; real_T Gain_Gain_bfommv4lak ; real_T Gain2_Gain_dwlwh44krh ;
real_T Gain_Gain_ftxlqxfaiq ; real_T Gain_Gain_lov5qcjzgk ; real_T
Gain_Gain_l2z5belp2u ; real_T Constant_Value ; real_T Constant1_Value ;
real_T Constant_Value_lag24fa1pj ; real_T Constant1_Value_mx4lv2w3em ; real_T
ControlEffectivenessMatrix_Value [ 9 ] ; real_T Constant1_Value_ogzj0ybhah [
9 ] ; real_T Constant_Value_jauwwxrr5h [ 3 ] ; real_T
Constant_Value_gstis4eggm ; real_T Constant1_Value_mrpwt2vxxm ; real_T
Constant2_Value [ 9 ] ; real_T AltitudeofTroposphere_Value ; real_T
Constant_Value_fqrpfjqhfg ; real_T SeaLevelTemperature_Value ; real_T
Constant3_Value ; real_T Constant1_Value_oqyl4nphju ; real_T mew1_Value [ 3 ]
; real_T mew2_Value [ 3 ] ; } ; extern const char_T *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern mxArray * mr_RCAM_sim1_GetDWork ( ) ; extern void
mr_RCAM_sim1_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_RCAM_sim1_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * RCAM_sim1_GetCAPIStaticMap ( void ) ; extern
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
