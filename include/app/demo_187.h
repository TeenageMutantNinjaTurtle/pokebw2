#ifndef POKEBW2_APP_DEMO_187_H
#define POKEBW2_APP_DEMO_187_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

#define OVERLAY_DEMO_187 OVERLAY_ID(187)

struct Demo187Param {
    GameSystem *gsys;
    GameData *gameData;
    u8 param0;
    u8 param1;
    u8 unkA[2];
};

extern const GameProcFunctions data_ov187_021ea06c;

#endif // POKEBW2_APP_DEMO_187_H
