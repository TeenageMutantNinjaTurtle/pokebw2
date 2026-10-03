#include "field/field_script.h"
#include "gfl/heap.h"
#include "gfl/msg.h"

FieldScriptEnv *CreateFieldScriptEnv(const FieldScriptEnvArgs *args, HeapID heapId) {
    FieldScriptEnv *env =
        GFL_HeapAllocate(HEAPID_TAIL(heapId), sizeof(FieldScriptEnv), TRUE, data_ov012_0216e1e4, 0x97);

    env->heapId = heapId;
    env->args = *args;
    env->subwork = ScriptWork_GetSubwork(args->work);
    return env;
}

void FreeFieldScriptEnv(FieldScriptEnv *env) {
    if (env->ownedHeap != NULL) {
        GFL_HeapFree(env->ownedHeap);
    }
    if (env->msgData != NULL) {
        GFL_MsgDataFree(env->msgData);
    }
    func_ov012_021552c8(env);
    GFL_HeapFree(env);
}
