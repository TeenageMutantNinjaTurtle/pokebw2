#ifndef POKEBW2_DEMO_SHINKA_DEMO_H
#define POKEBW2_DEMO_SHINKA_DEMO_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// The evolution demo
#define OVERLAY_SHINKA_DEMO OVERLAY_ID(284)

typedef struct {
    GameData *gameData;
    PokeParty *party;
    u16 partyIndex;
    u8 unkA;
    u8 unkB;
    u32 unkC;
    u32 unk10;
} ShinkaDemoParam;

extern const GameProcFunctions SHINKA_DEMO_PROC_FUNCTIONS;

#endif // POKEBW2_DEMO_SHINKA_DEMO_H
