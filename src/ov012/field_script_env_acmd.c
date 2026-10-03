#include "field/field_acmd.h"
#include "field/field_script.h"

void FieldScriptEnv_AddAcmdTask(FieldScriptEnv *env, FieldAcmdTCB *task) {
    int i;

    for (i = 0; i < 8; i++) {
        if (env->subwork->acmdTasks[i] == NULL) {
            env->subwork->acmdTasks[i] = task;
            return;
        }
    }
}

BOOL FieldScriptEnv_CheckAcmdQueueRunning(FieldScriptEnv *env) {
    int i;
    BOOL running = FALSE;

    for (i = 0; i < 8; i++) {
        if (env->subwork->acmdTasks[i] != NULL) {
            if (FieldAcmdTCB_CheckEnded(env->subwork->acmdTasks[i]) == TRUE) {
                FieldAcmdTCB_Remove(env->subwork->acmdTasks[i]);
                env->subwork->acmdTasks[i] = NULL;
            } else {
                running = TRUE;
            }
        }
    }

    return running;
}

void func_ov012_021552c8(FieldScriptEnv *env) {
    int i;

    for (i = 0; i < 8; i++) {
        if (env->subwork->acmdTasks[i] != NULL) {
            FieldAcmdTCB_Remove(env->subwork->acmdTasks[i]);
            env->subwork->acmdTasks[i] = NULL;
        }
    }
}
