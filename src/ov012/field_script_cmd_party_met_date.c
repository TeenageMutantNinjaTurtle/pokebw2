#include "field/field_script.h"
#include "pml/poke_party.h"

BOOL s011A_PokePartyGetMetDate(VM *vm, FieldScriptEnv *env) {
    u16 *year = ScriptReadVar(vm, env);
    u16 *month = ScriptReadVar(vm, env);
    u16 *day = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;

    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        *year = PokeParty_GetParam(pkm, 0x92, NULL);
        *month = PokeParty_GetParam(pkm, 0x93, NULL);
        *day = PokeParty_GetParam(pkm, 0x94, NULL);
    } else {
        *year = 0;
        *month = 0;
        *day = 0;
    }
    return FALSE;
}
