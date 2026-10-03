#include "field/field_script.h"
#include "pml/poke_party.h"

BOOL s0111_PokePartySetIV(VM *vm, FieldScriptEnv *env) {
    u16 index = ScriptReadAny(vm, env);
    u16 param = ScriptReadAny(vm, env);
    u16 value = ScriptReadAny(vm, env);
    u32 i;

    for (i = 0; i < 6; i++) {
        if (param == data_ov012_0216ca1a[2 * i]) {
            if (value <= data_ov012_0216ca1c[2 * i]) {
                PartyPkm *pkm;
                if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
                    PokeParty_SetParam(pkm, param, value);
                    PokeParty_RecalcStats(pkm);
                }
            }
            return FALSE;
        }
    }
    return FALSE;
}
