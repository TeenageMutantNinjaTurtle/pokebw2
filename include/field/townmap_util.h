#ifndef POKEBW2_FIELD_TOWNMAP_UTIL_H
#define POKEBW2_FIELD_TOWNMAP_UTIL_H

// Overlay 12's townmap_util.c (the name is a guess): what the town map and the Pokédex ask of where the player is

#include "types.h"
#include "struct_decls.h"

// The zone the town map shows for a zone, after the zones whose place depends on the game
u16 func_ov012_02160eb4(GameData *gameData, u16 zoneId);
// An event flag, or one of the pseudo flags from 0xf000
BOOL func_ov012_02160f74(GameData *gameData, u16 flag);

#endif // POKEBW2_FIELD_TOWNMAP_UTIL_H
