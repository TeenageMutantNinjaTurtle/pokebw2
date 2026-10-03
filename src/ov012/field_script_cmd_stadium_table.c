#include "field/field_script.h"
#include "field/stadium_script.h"
#include "gfl/arc.h"
#include "gfl/heap.h"

BOOL s01E1_StadiumLoadTrainerTable(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    void *trainers = GFL_ArcSysReadHeapNewLZ(0xce, 0, 0, HEAPID_TAIL(4));
    ScriptWork_SetStadiumTrainers(work, trainers);
    return FALSE;
}

BOOL s01E2_StadiumFreeTrainerTable(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    void *trainers = ScriptWork_GetStadiumTrainers(work);
    if (trainers != NULL) {
        GFL_HeapFree(trainers);
        ScriptWork_SetStadiumTrainers(work, NULL);
    }
    return FALSE;
}
