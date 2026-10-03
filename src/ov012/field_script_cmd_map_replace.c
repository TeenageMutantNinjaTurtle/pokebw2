#include "field/field_map.h"
#include "field/field_script.h"
#include "field/player_state.h"
#include "field/zone.h"
#include "system/game_data.h"

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
