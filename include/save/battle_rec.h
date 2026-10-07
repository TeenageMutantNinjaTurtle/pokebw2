#ifndef POKEBW2_SAVE_BATTLE_REC_H
#define POKEBW2_SAVE_BATTLE_REC_H

#include "types.h"
#include "gfl/heap.h"
#include "save/gds_profile.h"
#include "struct_decls.h"

// battle_rec.c: the battle video that is loaded, which the battle recorder plays and the extra save data keeps

// Loads the saved video of a slot (0 is the player's own, 1 to 3 the downloaded ones). result is 1 if it loaded
void func_0200bc9c(SaveControl *save, HeapID heapId, u32 *result, u32 slot);
// The profile of the player who recorded the loaded video. The name is swan's
GdsProfile *getVSPlayerAllocation(void);
// The header of the loaded video
BattleRecHeader *func_0200c0c0(void);
// A value from the header, such as the video's number
u64 func_0200c124(BattleRecHeader *header, u32 id, u32 index);

#endif // POKEBW2_SAVE_BATTLE_REC_H
