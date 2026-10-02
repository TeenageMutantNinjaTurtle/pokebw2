#ifndef POKEBW2_APP_PASS_POWER_H
#define POKEBW2_APP_PASS_POWER_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

#define OVERLAY_PASS_POWER_APP OVERLAY_ID(328)

struct PassPowerEntry {
    u8 id;
    u8 pad;
    u16 seconds;
};

struct PassPowerParam {
    GameSystem *gsys;
    void *argument;
    u32 highLinkIds[3];
    u8 highLinkCount;
    u8 powerCount;
    u16 itemCount;
    PassPowerEntry powers[10];
};

extern const GameProcFunctions data_ov328_0219ed2c;

#endif // POKEBW2_APP_PASS_POWER_H
