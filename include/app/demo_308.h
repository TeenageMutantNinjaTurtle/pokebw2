#ifndef POKEBW2_APP_DEMO_308_H
#define POKEBW2_APP_DEMO_308_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

#define OVERLAY_DEMO_308 OVERLAY_ID(308)

struct Demo308Param {
    GameSystem *gsys;
    GameData *gameData;
    u8 param0;
    u8 param1;
    u8 unkA[2];
};

extern const GameProcFunctions data_ov308_021a17dc;

#endif // POKEBW2_APP_DEMO_308_H
