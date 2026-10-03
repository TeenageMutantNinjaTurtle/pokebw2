#include "constants/pokemon.h"
#include "field/field_script.h"
#include "pml/poke_party.h"

BOOL s0101_PokePartyIsFullHP(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;

    *result = FALSE;
    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        u16 hp = (u16)PokeParty_GetParam(pkm, PKM_PARAM_HP, NULL);
        u16 maxHp = (u16)PokeParty_GetParam(pkm, PKM_PARAM_HP + 1, NULL);
        if (hp == maxHp || PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == TRUE) {
            *result = TRUE;
        }
    }
    return FALSE;
}
