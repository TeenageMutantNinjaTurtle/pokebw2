#ifndef POKEBW2_APP_BATTLE_RECORDER_BR_RES_H
#define POKEBW2_APP_BATTLE_RECORDER_BR_RES_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The Battle Recorder's resources (br_res.c): the font, the messages, the BG and OBJ graphics, and the color the
// player chose for it

BrRes *func_ov271_021f266c(u32 color, BOOL isBrowse, HeapID heapId);
void func_ov271_021f2714(BrRes *res);
void func_ov271_021f274c(BrRes *res, u32 bgID, HeapID heapId);
void func_ov271_021f2b8c(BrRes *res, u32 bgID);
// The fade color for the player's color
u16 func_ov271_021f3010(BrRes *res);
// The color the player chose
u32 func_ov271_021f3024(BrRes *res);

#endif // POKEBW2_APP_BATTLE_RECORDER_BR_RES_H
