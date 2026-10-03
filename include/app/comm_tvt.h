#ifndef POKEBW2_APP_COMM_TVT_H
#define POKEBW2_APP_COMM_TVT_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// Video chat with the Xtransceiver
#define OVERLAY_COMM_TVT OVERLAY_ID(257)
#define OVERLAY_COMM_TVT_FIELD_APP OVERLAY_ID(198)

struct CommTvtParam {
    GameData *gameData;
    u32 unk4;
    u32 unk8;
    u32 unkC;
};

extern const GameProcFunctions COMM_TVT_PROC_FUNCTIONS;
extern const GameProcFunctions data_ov198_021b44a4;

#endif // POKEBW2_APP_COMM_TVT_H
