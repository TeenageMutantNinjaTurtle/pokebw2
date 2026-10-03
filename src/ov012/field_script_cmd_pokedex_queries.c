#include "field/field_script.h"
#include "save/pokedex.h"
#include "system/game_data.h"

BOOL s00DF_PokeDexIsRegist(VM *vm, FieldScriptEnv *env) {
    PokeDexSave *pokedex = GameData_GetPokedex(FieldScriptEnv_GetGameData(env));
    u16 kind = ScriptReadAny(vm, env);
    u16 species = ScriptReadAny(vm, env);
    u16 *result = ScriptReadVar(vm, env);

    switch (kind) {
    case 0:
        *result = PokeDex_IsSeen(pokedex, species);
        break;
    case 1:
        *result = PokeDex_IsCaught(pokedex, species);
        break;
    default:
        *result = FALSE;
        break;
    }
    return FALSE;
}

BOOL s00DD_PokeDexGetCount(VM *vm, FieldScriptEnv *env) {
    PokeDexSave *pokedex = GameData_GetPokedex(FieldScriptEnv_GetGameData(env));
    u16 kind = ScriptReadAny(vm, env);
    u16 *result = ScriptReadVar(vm, env);

    switch (kind) {
    case 0:
        *result = PokeDex_GetSeenNoNational(pokedex);
        break;
    case 1:
        *result = PokeDex_GetCaughtNoNational(pokedex);
        break;
    default:
        *result = 0;
        break;
    }
    return FALSE;
}
