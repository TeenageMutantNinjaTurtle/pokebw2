#include "constants/pokemon.h"
#include "field/field_script.h"
#include "pml/poke_party.h"

BOOL s0108_PokePartyGetMoveCount(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;
    int i;
    int count = 0;

    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        for (i = 0; i < 4; i++) {
            if (PokeParty_GetParam(pkm, PKM_PARAM_MOVE1 + i, NULL) != 0) {
                count++;
            }
        }
    }
    *result = count;
    return FALSE;
}

BOOL s010A_PokePartyGetMove(VM *vm, FieldScriptEnv *env) {
    PartyPkm *pkm;
    u16 slot;
    u16 index;
    u16 *result;

    result = ScriptReadVar(vm, env);
    index = ScriptReadAny(vm, env);
    slot = ScriptReadAny(vm, env);

    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        *result = PokeParty_GetParam(pkm, PKM_PARAM_MOVE1 + slot, NULL);
    } else {
        *result = 0;
    }
    return FALSE;
}
