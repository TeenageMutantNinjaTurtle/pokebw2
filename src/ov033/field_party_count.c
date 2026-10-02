#include "field/field_party.h"
#include "pml/poke_party.h"
#include "system/game_data.h"
#include "system/game_system.h"

int countNonEggsInParty(GameSystem *gsys) {
    return howManyPartyPokesAreNotEggs(GameData_GetParty(GSYS_GetGameData(gsys)));
}
