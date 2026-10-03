#include "field/field_script.h"
#include "field/trainer_script.h"
#include "save/event_work.h"
#include "system/game_data.h"

BOOL s0095_TrainerFlagSet(VM *vm, FieldScriptEnv *env) {
    EventWork *eventWork = GameData_GetEventWork(FieldScriptEnv_GetGameData(env));
    u16 trainerId = ScriptReadAny(vm, env);
    setTrainerBattleFlag(eventWork, trainerId);
    return FALSE;
}

BOOL s0096_TrainerFlagReset(VM *vm, FieldScriptEnv *env) {
    EventWork *eventWork = GameData_GetEventWork(FieldScriptEnv_GetGameData(env));
    u16 trainerId = ScriptReadAny(vm, env);
    clearTrainerBattleFlag(eventWork, trainerId);
    return FALSE;
}

BOOL s0097_TrainerFlagGet(VM *vm, FieldScriptEnv *env) {
    EventWork *eventWork = GameData_GetEventWork(FieldScriptEnv_GetGameData(env));
    u16 trainerId = ScriptReadAny(vm, env);
    u16 *result = ScriptReadVar(vm, env);
    *result = TrainerFlagGet(eventWork, trainerId);
    return FALSE;
}
