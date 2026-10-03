#include "field/field_script.h"
#include "gfl/heap.h"
#include "pml/poke_party.h"
#include "save/pokedex.h"
#include "system/game_data.h"

BOOL s00DE_PokeDexRegist(VM *vm, FieldScriptEnv *env) {
    PokeDexSave *pokedex = GameData_GetPokedex(FieldScriptEnv_GetGameData(env));
    HeapID heapId = FieldScriptEnv_GetHeapID(env);
    u16 kind = ScriptReadAny(vm, env);
    u16 species = ScriptReadAny(vm, env);
    PartyPkm *pkm = PokeParty_NewTempPkm(species, 1, 0xffffffff00000000ULL, heapId);

    switch (kind) {
    case 0:
        PokeDex_RegistPkm(pokedex, pkm);
        break;
    case 1:
        break;
    }

    GFL_HeapFree(pkm);
    return FALSE;
}

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
