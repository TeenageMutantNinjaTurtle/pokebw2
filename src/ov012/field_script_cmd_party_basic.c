#include "constants/pokemon.h"
#include "field/field_script.h"
#include "pml/poke_party.h"
#include "system/game_data.h"

BOOL s011B_PokePartyGetTypes(VM *vm, FieldScriptEnv *env) {
    u16 *type1 = ScriptReadVar(vm, env);
    u16 *type2 = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;

    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        *type1 = PokeParty_GetParam(pkm, PKM_PARAM_TYPE1, NULL);
        *type2 = PokeParty_GetParam(pkm, PKM_PARAM_TYPE2, NULL);
    } else {
        *type1 = 0;
        *type2 = 0;
    }
    return FALSE;
}

BOOL s0104_PokePartyRecoverAll(VM *vm, FieldScriptEnv *env) {
    PokeParty_RecoverAll(GameData_GetParty(FieldScriptEnv_GetGameData(env)));
    return FALSE;
}
