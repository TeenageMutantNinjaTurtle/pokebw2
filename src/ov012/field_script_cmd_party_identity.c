#include "constants/pokemon.h"
#include "field/field_script.h"
#include "pml/poke_party.h"
#include "system/game_data.h"

BOOL s00FE_PokePartyGetSpecies(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);

    if (GetScrPokeStat(env, index, PKM_PARAM_IS_EGG) != 0) {
        *result = SPECIES_EGG;
    } else {
        *result = GetScrPokeStat(env, index, PKM_PARAM_SPECIES);
    }
    return FALSE;
}

BOOL s00FF_PokePartyGetForme(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    *result = GetScrPokeStat(env, index, PKM_PARAM_FORM);
    return FALSE;
}

BOOL s010D_PokePartyGetMemberByType(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 kind = ScriptReadAny(vm, env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    u16 index;

    switch (kind) {
    case 2:
        index = PokeParty_GetFirstBattleReady(party);
        break;
    case 1:
        index = isEggInParty(party);
        break;
    default:
        index = 0;
        break;
    }
    *result = index;
    return FALSE;
}
