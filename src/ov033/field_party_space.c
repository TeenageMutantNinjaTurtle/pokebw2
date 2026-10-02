#include "field/field_party.h"
#include "pml/poke_party.h"
#include "system/game_data.h"

BOOL doesPartyHaveSpace(void *context, GameData *gameData) {
    return PokeParty_GetPkmCount(GameData_GetParty(gameData)) < 6;
}
