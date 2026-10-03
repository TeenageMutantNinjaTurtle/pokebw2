#include "constants/pokemon.h"
#include "field/field_script.h"
#include "pml/poke_party.h"
#include "system/vm.h"

BOOL s00FD_PokePartyAdjustHappiness(VM *vm, FieldScriptEnv *env) {
    u16 index = ScriptReadAny(vm, env);
    u16 delta = ScriptReadAny(vm, env);
    u16 mode = VM_Read16(vm);
    PartyPkm *pkm = NULL;
    u8 happiness;

    if (!CheckGetPartyPokemon(env, index, &pkm)) {
        return FALSE;
    }
    if (PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == TRUE) {
        return FALSE;
    }
    happiness = (u8)PokeParty_GetParam(pkm, PKM_PARAM_HAPPINESS, NULL);
    switch (mode) {
    case 0:
        if (delta > 255) {
            happiness = 255;
        } else {
            happiness = (u8)delta;
        }
        break;
    case 1:
        if (happiness + delta > 255) {
            happiness = 255;
        } else {
            happiness += (u8)delta;
        }
        break;
    case 2:
        if (happiness < delta) {
            happiness = 0;
        } else {
            happiness -= (u8)delta;
        }
        break;
    }
    PokeParty_SetParam(pkm, PKM_PARAM_HAPPINESS, happiness);
    return FALSE;
}
