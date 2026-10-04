#ifndef POKEBW2_APP_OV287_H
#define POKEBW2_APP_OV287_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/overlay.h"
#include "gfl/tcb.h"
#include "struct_decls.h"

// Overlay 287's screen for picking a move to forget, which runs on the evolution demo's tasks with overlay 285 loaded.
// It sets done when it ends

#define OVERLAY_OV285 OVERLAY_ID(285)
#define OVERLAY_OV287 OVERLAY_ID(287)

typedef struct {
    GameData *gameData;
    PokeParty *party;
    void *unk8;
    Font *font;
    HeapID heapId;
    u32 unk14;
    void *unk18;
    u8 unk1C;
    u8 unk1D[2];
    u8 unk1F;
    u8 partyIndex;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u16 item;
    u16 move;
    TCBManager *tcbManager;
    void *unk2C;
    u32 unk30;
    u32 unk34;
    u8 unk38[6];
    u8 unk3E[2];
    u32 unk40;
    u8 *usingKeys;
    u8 unk48[3];
    // The slot of the move to forget, or 4 for none
    u8 slot;
    u8 done;
} Ov287Param;

void func_ov287_021f8714(Ov287Param *param);

#endif // POKEBW2_APP_OV287_H
