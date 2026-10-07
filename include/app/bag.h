#ifndef POKEBW2_APP_BAG_H
#define POKEBW2_APP_BAG_H

#include "types.h"
#include "field/player_action.h"
#include "gfl/heap.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// The bag, overlay 142 (itemmenu.c and bag_item.c)
#define OVERLAY_BAG OVERLAY_ID(142)

// What the bag is started with, 0x4c bytes that BagParam_Create (bag_param.c) allocates
struct BagProcessData {
    GameData *gameData;
    TrainerDataSave *trainerData;
    PlayerInfo *playerInfo;
    void *unk0C;
    u32 unk10;
    BagSave *bag;
    PlayerActionPerms perms;
    u32 mode;
    BOOL isCycling;
    // Whether the last subscreen was subscreen 6
    BOOL unk40;
    // What the player did, 0 for nothing
    u32 result;
    u32 item;
};

extern const GameProcFunctions data_ov142_021a0910;

// Creates the bag's data for a mode, in the main module, with a copy of the perms when they are given
BagProcessData *BagParam_Create(GameData *gameData, const PlayerActionPerms *perms, u32 mode, HeapID heapId);
// Sets the item the bag opens on, in what unk0C points to
void func_020088a4(void *a0, u16 item);
void func_020088c4(void *a0, void *a1, void *a2);
void func_020088e0(void *a0, u16 item, u8 a2);
u8 func_020088e8(void *a0);

#endif // POKEBW2_APP_BAG_H
