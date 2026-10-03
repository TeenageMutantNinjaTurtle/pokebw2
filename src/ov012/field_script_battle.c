#include "battle/battle_result.h"
#include "field/field_event.h"
#include "field/field_script.h"
#include "field/trainer_script.h"
#include "save/event_work.h"
#include "system/game_data.h"
#include "system/vm.h"

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

BOOL s008C_CallTrainerLose(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    ScriptWork_SetPostEvent(work, EventBattleLose_Create(gsys));
    VM_Halt(vm);
    return TRUE;
}

BOOL s008D_TrainerBattleIsVictory(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    u32 battleResult = GameData_GetLastBtlResult(gameData);
    if (IsBattleResultDefeat(battleResult, 1) == TRUE) {
        *result = 0;
    } else {
        *result = 1;
    }
    return FALSE;
}

BOOL s0176_CallWildLose(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    ScriptWork_SetPostEvent(work, EventBattleLose_Create(gsys));
    VM_Halt(vm);
    return TRUE;
}

BOOL s0177_WildBattleIsVictory(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    u32 battleResult = GameData_GetLastBtlResult(gameData);
    if (IsBattleResultDefeat(battleResult, 0) == TRUE) {
        *result = 0;
    } else {
        *result = 1;
    }
    return FALSE;
}

BOOL s0178_WildBattleGetResult(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    u32 battleResult = GameData_GetLastBtlResult(gameData);
    u16 *result = ScriptReadVar(vm, env);
    *result = GetWildBattleResultByCombined(battleResult);
    return FALSE;
}
