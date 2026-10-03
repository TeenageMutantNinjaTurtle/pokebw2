#include "field/field_script.h"
#include "field/player_state.h"
#include "field/zone.h"
#include "system/game_data.h"

BOOL s00D3_RTGetZoneID(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);
    *value = GetScriptEnvZoneID(env);
    return FALSE;
}

BOOL s00D9_FieldSetTeleportZone(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    u16 zone = ScriptReadAny(vm, env);
    if (RangeCheckTeleportZone(zone) == TRUE) {
        SetCurrentTeleportOrDeathZone(gameData, zone);
    }
    return FALSE;
}

BOOL s00DB_FieldSetNextZoneHere(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    PlayerState *playerState = GameData_GetPlayerState(gameData);
    VecFx32 *pos = PlayerState_GetWPos(playerState);
    u16 zone = PlayerState_GetZoneID(playerState);
    u16 direction = PlayerState_CalcDirection(playerState);
    ZoneSpawnInfo spawn;

    CreateZoneChangeData(&spawn, zone, direction, pos->x, pos->y, pos->z);
    GameData_SetNextZone(gameData, &spawn);
    return FALSE;
}

BOOL s00DC_FieldSetNextZone(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    u16 zone = ScriptReadAny(vm, env);
    u16 direction = ScriptReadAny(vm, env);
    u16 x = ScriptReadAny(vm, env);
    u16 y = ScriptReadAny(vm, env);
    u16 z = ScriptReadAny(vm, env);
    ZoneSpawnInfo spawn;

    CreateZoneChangeData(&spawn, zone, (s16)direction, x << 16, y << 16, z << 16);
    GameData_SetNextZone(gameData, &spawn);
    return FALSE;
}
