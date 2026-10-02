#include "battle/btl_main.h"
#include "constants/pokemon.h"
#include "pml/poke_party.h"

// Function name from swan.
s32 GetPartyPkmnEligibleForBattle(PokeParty *party) {
    s32 index;
    PartyPkm *pkm;

    for (index = PokeParty_GetPkmCount(party) - 1; index >= 0; index--) {
        pkm = PokeParty_GetPkm(party, index);
        if (PokeParty_GetParam(pkm, (PkmField)PKM_PARAM_IS_EGG, NULL) == 0 &&
            PokeParty_GetParam(pkm, (PkmField)PKM_PARAM_HP, NULL) != 0) {
            return index;
        }
    }
    return -1;
}
