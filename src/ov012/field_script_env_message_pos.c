#include "field/field_script.h"

u8 ActorMsgWin_GetPosActual(FieldScriptEnv *env) {
    return env->subwork->actorMsgPosActual;
}

void ActorMsgWin_SetPosActual(FieldScriptEnv *env, u8 pos) {
    env->subwork->actorMsgPosActual = pos;
}

u8 ActorMsgWin_GetPos(FieldScriptEnv *env) {
    return env->subwork->actorMsgPos;
}

void ActorMsgWin_SetPos(FieldScriptEnv *env, u8 pos) {
    env->subwork->actorMsgPos = pos;
}
