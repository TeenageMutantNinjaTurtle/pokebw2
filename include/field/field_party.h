#ifndef POKEBW2_FIELD_FIELD_PARTY_H
#define POKEBW2_FIELD_FIELD_PARTY_H

#include "types.h"
#include "struct_decls.h"

// Function names from swan.
BOOL doesPartyHaveSpace(void *context, GameData *gameData);
int countNonEggsInParty(GameSystem *gsys);

#endif // POKEBW2_FIELD_FIELD_PARTY_H
