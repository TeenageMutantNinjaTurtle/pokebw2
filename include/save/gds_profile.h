#ifndef POKEBW2_SAVE_GDS_PROFILE_H
#define POKEBW2_SAVE_GDS_PROFILE_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// gds_profile.c: the profile of the player that a battle video or a musical photo sent to the Global Link carries

// Fills the profile from the player's game data
void func_0200de68(GdsProfile *profile, GameData *gameData);
// A new string with the player's name
StrBuf *func_0200df68(GdsProfile *profile, HeapID heapId);
// The player's sex, or 0 if it isn't valid
u32 func_0200df84(GdsProfile *profile);

#endif // POKEBW2_SAVE_GDS_PROFILE_H
