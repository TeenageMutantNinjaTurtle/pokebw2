#ifndef POKEBW2_APP_OV174_H
#define POKEBW2_APP_OV174_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// Overlay 174's screen, which the Battle Subway and the infrared event show

#define OVERLAY_OV174 OVERLAY_ID(174)

typedef struct {
    GameData *gameData;
    PokeParty *party;
    // The parties of the infrared players, by net ID
    PokeParty *parties[4];
    // Each infrared player's place, by net ID
    u8 order[4];
    // The mode the screen starts in, and what it was left with: 0xb, 0xc or 0xd for the Battle Subway
    u32 result;
    u8 unk20[8];
} Ov174Param;

extern const GameProcFunctions data_ov174_0219f0fc;

#endif // POKEBW2_APP_OV174_H
