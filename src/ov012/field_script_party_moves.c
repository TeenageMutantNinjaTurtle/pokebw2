#include "constants/pokemon.h"
#include "field/field_script.h"
#include "pml/poke_party.h"

BOOL CheckPokeMoveLearned_NonEgg(PartyPkm *pkm, u16 move) {
    if (PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) != 0) {
        return FALSE;
    }
    if (PokeParty_GetParam(pkm, PKM_PARAM_MOVE1, NULL) == move ||
        PokeParty_GetParam(pkm, PKM_PARAM_MOVE1 + 1, NULL) == move ||
        PokeParty_GetParam(pkm, PKM_PARAM_MOVE1 + 2, NULL) == move ||
        PokeParty_GetParam(pkm, PKM_PARAM_MOVE1 + 3, NULL) == move) {
        return TRUE;
    }
    return FALSE;
}
