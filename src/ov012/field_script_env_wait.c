#include "field/field_script.h"

void FieldScriptEnv_SetWaitCounter(FieldScriptEnv *env, u16 frames) {
    env->subwork->waitCounter = frames;
}

BOOL FieldScriptEnv_UpdateWaitCounter(FieldScriptEnv *env) {
    if (env->subwork->waitCounter == 0) {
        return TRUE;
    }
    env->subwork->waitCounter--;
    return FALSE;
}
