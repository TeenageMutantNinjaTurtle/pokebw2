#include "field/field_map.h"
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

BOOL s00DA_MapReplaceSetEvent(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    u16 uid = ScriptReadAny(vm, env);
    u16 set = ScriptReadAny(vm, env);
    u16 reload = ScriptReadAny(vm, env);

    GameData_SetEventMapReplace(gameData, uid, set);
    if (reload != 0) {
        MapMatrix *matrix = GetMapMatrixSystem(gameData);
        PlayerState *playerState = GameData_GetPlayerState(gameData);
        u16 zoneId = PlayerState_GetZoneID(playerState);
        u16 matrixId = GetZoneMatrixId(zoneId);
        HeapID heapId = FieldScriptEnv_GetHeapID(env);

        MapMatrix_Load(matrix, matrixId, zoneId, heapId);
        MapMatrix_Patch(matrix, gsys, heapId);
    }

    return FALSE;
}

BOOL s00D8_MapReplaceIsEventSet(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    u16 uid = ScriptReadAny(vm, env);
    u16 *result = ScriptReadVar(vm, env);
    *result = GameData_IsMapReplaceEventSet(gameData, uid);
    return FALSE;
}
