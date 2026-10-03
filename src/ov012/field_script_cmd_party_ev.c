#include "constants/pokemon.h"
#include "field/field_script.h"
#include "pml/poke_party.h"

BOOL s0112_PokePartyGetEVTotal(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;
    u16 total = 0;

    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        total += (u16)PokeParty_GetParam(pkm, PKM_PARAM_EV_HP, NULL);
        total += (u16)PokeParty_GetParam(pkm, PKM_PARAM_EV_HP + 1, NULL);
        total += (u16)PokeParty_GetParam(pkm, PKM_PARAM_EV_HP + 2, NULL);
        total += (u16)PokeParty_GetParam(pkm, PKM_PARAM_EV_HP + 3, NULL);
        total += (u16)PokeParty_GetParam(pkm, PKM_PARAM_EV_HP + 4, NULL);
        total += (u16)PokeParty_GetParam(pkm, PKM_PARAM_EV_HP + 5, NULL);
    }
    *result = total;
    return FALSE;
}
