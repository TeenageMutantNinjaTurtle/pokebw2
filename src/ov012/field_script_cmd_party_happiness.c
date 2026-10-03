#include "constants/pokemon.h"
#include "field/field_script.h"
#include "pml/poke_party.h"

BOOL s00FC_PokePartyGetHappiness(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;

    *result = 0;
    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        if (PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == 0) {
            *result = PokeParty_GetParam(pkm, PKM_PARAM_HAPPINESS, NULL);
        }
    }
    return FALSE;
}
