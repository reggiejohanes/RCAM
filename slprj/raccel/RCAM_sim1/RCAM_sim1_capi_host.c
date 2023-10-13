#include "RCAM_sim1_capi_host.h"
static RCAM_sim1_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        RCAM_sim1_host_InitializeDataMapInfo(&(root), "RCAM_sim1");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction(){return(getRootMappingInfo());}
