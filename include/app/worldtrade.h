#ifndef POKEBW2_APP_WORLDTRADE_H
#define POKEBW2_APP_WORLDTRADE_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// The Global Trade Station
#define OVERLAY_WORLDTRADE OVERLAY_ID(214)

typedef struct {
    WorldTradeData *worldTrade;
    void *adventure;
    void *party;
    BoxSaveAccessor *boxes;
    void *pokedex;
    WifiList *wifiList;
    void *unityTowerSurvey;
    PlayerInfo *playerInfo;
    void *trainerData;
    void *trainerCardInfo;
    BagSave *bag;
    BOOL isNationalDex;
    s32 profileId;
    u32 unk34;
    u32 unk38;
    SaveControl *save;
    GameSystem *gsys;
} WorldTradeParam;

extern const GameProcFunctions WORLDTRADE_PROC_FUNCTIONS;

#endif // POKEBW2_APP_WORLDTRADE_H
