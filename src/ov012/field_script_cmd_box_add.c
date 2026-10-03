#include "field/field_script.h"
#include "system/game_data.h"

BOOL s0122_BoxAdd(VM *vm, FieldScriptEnv *env) {
    GameData *gameData;
    HeapID heapId;
    u16 *result;
    u16 species;
    u16 level;
    u16 paramC;
    BoxPkmCreateParams params;

    FieldScriptEnv_GetGameSystem(env);
    gameData = FieldScriptEnv_GetGameData(env);
    heapId = FieldScriptEnv_GetHeapID(env);
    GameData_GetParty(gameData);
    GetGameDataPlayerInfo(gameData);
    result = ScriptReadVar(vm, env);
    species = ScriptReadAny(vm, env);
    level = ScriptReadAny(vm, env);
    paramC = ScriptReadAny(vm, env);
    params.heapId = heapId;
    params.species = species;
    params.level = level;
    params.paramC = paramC;
    params.param10 = 0;
    params.param14 = 2;
    params.param18 = 2;
    params.param1C = 2;
    params.param20 = 4;
    *result = GameData_AddBoxPkm(gameData, &params);
    return FALSE;
}

BOOL s0123_BoxAddEx(VM *vm, FieldScriptEnv *env) {
    GameData *gameData;
    HeapID heapId;
    u16 *result;
    u16 species;
    u16 level;
    u16 paramC;
    u16 param14;
    u16 param18;
    u16 param1C;
    u16 param10;
    u16 param20;
    BoxPkmCreateParams params;

    FieldScriptEnv_GetGameSystem(env);
    gameData = FieldScriptEnv_GetGameData(env);
    heapId = FieldScriptEnv_GetHeapID(env);
    GameData_GetParty(gameData);
    GetGameDataPlayerInfo(gameData);
    result = ScriptReadVar(vm, env);
    species = ScriptReadAny(vm, env);
    level = ScriptReadAny(vm, env);
    paramC = ScriptReadAny(vm, env);
    param14 = ScriptReadAny(vm, env);
    param18 = ScriptReadAny(vm, env);
    param1C = ScriptReadAny(vm, env);
    param10 = ScriptReadAny(vm, env);
    param20 = ScriptReadAny(vm, env);
    params.heapId = heapId;
    params.species = species;
    params.level = level;
    params.paramC = paramC;
    params.param10 = param10;
    params.param14 = param14;
    if (params.param14 >= 3)
        params.param14 = 2;
    params.param18 = param18;
    if (params.param18 >= 3)
        params.param18 = 2;
    params.param1C = param1C;
    if (params.param1C >= 3)
        params.param1C = 2;
    params.param20 = param20;
    *result = GameData_AddBoxPkm(gameData, &params);
    return FALSE;
}
