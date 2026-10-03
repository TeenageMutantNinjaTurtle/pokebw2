#include "field/festival.h"
#include "field/field_actor.h"
#include "field/field_script.h"
#include "field/funfest_scripts.h"
#include "system/game_system.h"

BOOL s0277_FunfestActorDelete(VM *vm, FieldScriptEnv *env) {
    ScriptWork *scriptWork = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    Field *field = GSYS_GetField(gsys);
    u16 zoneId = GetScriptEnvZoneID(env);
    u8 actorIndex = GetActorUID(ScriptWork_GetParentActor(scriptWork)) - 0xec;
    void *gimmick = Field_GetFesGimmick(field);

    if (!FesGimmick_IsCurrent(gimmick, 5)) {
        return TRUE;
    }
    DeleteFunfestActor(Field_GetFesGimmick(field), zoneId, actorIndex);
    return TRUE;
}

BOOL s027A_FunfestGetGenericInfo(VM *vm, FieldScriptEnv *env) {
    ScriptWork *scriptWork = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    void *gimmick = Field_GetFesGimmick(GSYS_GetField(gsys));
    u16 param = ScriptReadAny(vm, env);
    u16 *result = ScriptReadVar(vm, env);

    if (!FesGimmick_IsCurrent(gimmick, 5)) {
        *result = 0;
        return TRUE;
    }
    *result = GetActorUserParam(ScriptWork_GetParentActor(scriptWork), param);
    return TRUE;
}
