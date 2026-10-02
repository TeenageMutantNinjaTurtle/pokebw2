#ifndef POKEBW2_APP_FESTIVAL_H
#define POKEBW2_APP_FESTIVAL_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

#define OVERLAY_FESTIVAL_APP OVERLAY_ID(309)

struct FestivalEventParam {
    GameSystem *gsys;
    GameData *gameData;
    u32 mode;
    LinkFestival *festival;
    void *missionConfig;
    void *saveBlock;
};

extern const GameProcFunctions data_ov309_021a01d0;

#endif // POKEBW2_APP_FESTIVAL_H
