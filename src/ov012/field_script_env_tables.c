#include "field/field_script.h"

void *GetScrEnvNowPkmVoice(FieldScriptEnv *env) {
    return env->subwork->nowPkmVoice;
}

void SetScrEnvNowPkmVoice(FieldScriptEnv *env, void *voice) {
    env->subwork->nowPkmVoice = voice;
}

void *FieldScriptEnv_GetElevatorTable(FieldScriptEnv *env) {
    return env->subwork->elevatorTable;
}

void FieldScriptEnv_SetElevatorTable(FieldScriptEnv *env, void *table) {
    env->subwork->elevatorTable = table;
}
