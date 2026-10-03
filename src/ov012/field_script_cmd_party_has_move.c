#include "field/field_script.h"
#include "pml/poke_party.h"
#include "system/game_data.h"

BOOL s0115_PokePartyHasMove(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 move = ScriptReadAny(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;

    *result = FALSE;
    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        if (CheckPokeMoveLearned_NonEgg(pkm, move) == TRUE) {
            *result = TRUE;
        }
    }
    return FALSE;
}

BOOL s0116_PokePartyHasMoveAny(VM *vm, FieldScriptEnv *env) {
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    u16 *result = ScriptReadVar(vm, env);
    u16 move = ScriptReadAny(vm, env);
    int i;
    int count = PokeParty_GetPkmCount(party);

    *result = 6;
    for (i = 0; i < count; i++) {
        PartyPkm *pkm = PokeParty_GetPkm(party, i);
        if (CheckPokeMoveLearned_NonEgg(pkm, move) == TRUE) {
            *result = i;
            break;
        }
    }
    return FALSE;
}
