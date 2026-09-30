#ifndef POKEBW2_APP_OV207_H
#define POKEBW2_APP_OV207_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// Overlay 207's screen that the evolution demo runs to pick a move to forget for a new one

#define OVERLAY_OV207 OVERLAY_ID(207)

typedef struct {
    PokeParty *party;
    void *trainerData;
    GameData *gameData;
    u8 unkC;
    u8 unkD;
    u8 partyCount;
    u8 partyIndex;
    u8 unk10;
    // The slot of the move to forget, and 0 once one has been picked
    u8 slot;
    u8 result;
    u16 move;
    u8 unk16[0xa];
    u32 unk20;
    u32 unk24;
} Ov207Param;

extern const GameProcFunctions data_ov207_021bb6a0;

#endif // POKEBW2_APP_OV207_H
