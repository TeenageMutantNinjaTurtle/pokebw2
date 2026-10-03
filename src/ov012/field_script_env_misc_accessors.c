#include "field/field_script.h"

void *func_ov012_0215518c(FieldScriptEnv *env) {
    return *(void **)ScriptWork_GetFieldWork(FieldScriptEnv_GetScriptWork(env));
}

MsgData *GetFieldScriptMsgData(FieldScriptEnv *env) {
    return env->msgData;
}

u16 GetFieldScriptMsgFileNo(FieldScriptEnv *env) {
    return env->msgFileNo;
}

void setMapDisplayInfoPtr(FieldScriptEnv *env, void *info) {
    env->subwork->mapDisplayInfo = info;
}

void *getMapDisplayInfoPtr(FieldScriptEnv *env) {
    return env->subwork->mapDisplayInfo;
}

void SetSpecialMessageIconPtr(FieldScriptEnv *env, void *icon) {
    env->subwork->specialMessageIcon = icon;
}

void *func_ov012_021551c0(FieldScriptEnv *env) {
    return env->subwork->specialMessageIcon;
}

void *GetFieldScriptActorWk(FieldScriptEnv *env) {
    return env->subwork->actorWork;
}

void FieldScriptEnv_SetPlayerGridEventTCB(FieldScriptEnv *env, void *task) {
    env->subwork->playerGridEventTCB = task;
}

void *FieldScriptEnv_GetPlayerGridEventTCB(FieldScriptEnv *env) {
    return env->subwork->playerGridEventTCB;
}
