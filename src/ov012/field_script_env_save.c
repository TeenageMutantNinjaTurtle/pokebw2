#include "field/field_script.h"

void FieldScriptEnv_Save(FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    env->ownedHeap = ScriptWork_CreateVarCopy(work);
}

void FieldScriptEnv_Restore(FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    ScriptWork_RestoreVarCopy(work, env->ownedHeap);
    env->ownedHeap = NULL;
}

void SetScrEnvVMIndex(FieldScriptEnv *env, u8 index) {
    env->vmIndex = index;
}

u8 FieldScriptEnv_GetVMIndex(FieldScriptEnv *env) {
    return env->vmIndex;
}
