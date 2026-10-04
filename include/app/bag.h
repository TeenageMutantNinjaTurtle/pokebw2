#ifndef POKEBW2_APP_BAG_H
#define POKEBW2_APP_BAG_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// The bag, overlay 142 (itemmenu.c and bag_item.c)
#define OVERLAY_BAG OVERLAY_ID(142)

// What the bag is started with, 0x4c bytes that func_02034ad0 allocates
struct BagProcessData {
    GameData *gameData;
    void *unk04;
    PlayerInfo *playerInfo;
    void *unk0C;
    void *unk10;
    BagSave *bag;
    u8 unk18[0x20];
    u32 unk38;
    u8 unk3C[8];
    // What the player did, 0 for nothing
    u32 result;
    u32 item;
};

extern const GameProcFunctions data_ov142_021a0910;

// Creates the bag's data for a mode, in the main module
BagProcessData *func_02034ad0(GameData *gameData, void *a1, u32 mode, HeapID heapId);
// Sets the item the bag opens on, in what unk0C points to
void func_020088a4(void *a0, u16 item);

#endif // POKEBW2_APP_BAG_H
