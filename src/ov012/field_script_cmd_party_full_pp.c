#include "constants/pokemon.h"
#include "field/field_script.h"
#include "pml/poke_party.h"

BOOL s024E_PokePartyIsFullPP(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;
    u16 pp;
    u16 i;
    u32 full;

    *result = FALSE;
    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        full = TRUE;

        if (PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == TRUE || PokeParty_GetParam(pkm, 3, NULL) == TRUE) {
            *result = TRUE;
            return FALSE;
        }

        for (i = 0; i < 4; i++) {
            if ((u16)PokeParty_GetParam(pkm, PKM_PARAM_MOVE1 + i, NULL) == 0) {
                continue;
            }
            pp = (u16)PokeParty_GetParam(pkm, 0x3a + i, NULL);
            u16 maxPp = (u16)PokeParty_GetParam(pkm, 0x42 + i, NULL);
            if (pp != maxPp) {
                full = FALSE;
                break;
            }
        }
        *result = full;
    }
    return FALSE;
}
