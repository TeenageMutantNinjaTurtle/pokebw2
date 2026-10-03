#include "field/field_script.h"
#include "save/pokedex.h"
#include "system/game_data.h"

BOOL s01C6_PokeDexGiveNational(VM *vm, FieldScriptEnv *env) {
    PokeDexSave *pokedex = GameData_GetPokedex(FieldScriptEnv_GetGameData(env));
    PokeDex_EnableHabitatList(pokedex);
    PokeDex_SetNationalObtained(pokedex);
    return FALSE;
}

BOOL s01C7_PokeDexHaveNational(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);
    PokeDexSave *pokedex = GameData_GetPokedex(FieldScriptEnv_GetGameData(env));
    *value = PokeDex_IsNationalObtained(pokedex);
    return FALSE;
}

BOOL s01C8_PokeDexEnable(VM *vm, FieldScriptEnv *env) {
    PokeDexSave *pokedex = GameData_GetPokedex(FieldScriptEnv_GetGameData(env));
    givePlayerPokedex(pokedex);
    return FALSE;
}

BOOL s02D0_PokeDexEnableHabitatList(VM *vm, FieldScriptEnv *env) {
    PokeDexSave *pokedex = GameData_GetPokedex(FieldScriptEnv_GetGameData(env));
    PokeDex_EnableHabitatList(pokedex);
    return FALSE;
}
