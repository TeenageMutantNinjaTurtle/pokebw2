#include "field/field_script.h"
#include "field/player_state.h"
#include "system/game_data.h"
#include "system/vm.h"

u16 *ScriptReadVar(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    u16 id = VM_Read16(vm);

    return ScriptWork_GetWkAddr(work, gameData, id);
}

u16 ScriptReadAny(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    u16 value = VM_Read16(vm);

    return ScriptWork_ResolveHybridValue(work, gameData, value);
}

u16 FieldScriptEnv_GetZoneID(FieldScriptEnv *env) {
    return PlayerState_GetZoneID(GameData_GetPlayerState(FieldScriptEnv_GetGameData(env)));
}
