#include "field/field_script.h"
#include "pml/poke_party.h"
#include "system/game_data.h"

BOOL s0103_PokePartyGetCount(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 kind = ScriptReadAny(vm, env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    int count;

    switch (kind) {
    case 0:
        count = PokeParty_GetPkmCount(party);
        break;
    case 1:
        count = howManyPartyPokesAreNotEggs(party);
        break;
    case 2:
        count = howManyPokesAreAbleToFight(party);
        break;
    case 3:
        count = countAllEggsInParty(party);
        break;
    case 4:
        count = countSanityEggsInParty(party);
        break;
    case 5:
        count = PokeParty_GetCapacity(party);
        int partyCount = PokeParty_GetPkmCount(party);
        if (count < partyCount) {
            count = 0;
        } else {
            count -= partyCount;
        }
        break;
    default:
        count = 0;
        break;
    }
    *result = count;
    return FALSE;
}
