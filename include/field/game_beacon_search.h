#ifndef POKEBW2_FIELD_GAME_BEACON_SEARCH_H
#define POKEBW2_FIELD_GAME_BEACON_SEARCH_H

// Overlay 12's game_beacon_search.c: the game communication that looks for nearby players' beacons while the player is
// in the field, which the communication table of ARM9 main runs

#include "types.h"
#include "struct_decls.h"

void *func_ov012_0215f55c(void *param, GameSystem *gsys);
BOOL func_ov012_0215f5b4(u32 *seq, GameSystem *gsys, void *work);
BOOL func_ov012_0215f610(u32 *seq, GameSystem *gsys, void *work);
BOOL func_ov012_0215f628(u32 *seq, GameSystem *gsys, void *work);
void func_ov012_0215f654(u32 *seq, GameSystem *gsys, void *work);
// Waits a while before taking the beacons of type 0x35 again
void func_ov012_0215f94c(void *work);

#endif // POKEBW2_FIELD_GAME_BEACON_SEARCH_H
