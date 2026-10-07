#include "types.h"
#include "app/ov207.h"
#include "gfl/heap.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "gfl/std.h"
#include "system/game_system.h"
#include "worldtrade_local.h"

// The Global Trade Station's summary screen of a Pokémon in the boxes, which runs overlay 207's summary. The names
// are ours, guessed

int WorldTrade_Status_Init(WorldTradeWork *wk, int seq) {
    Ov207Param *status;

    WorldTrade_ExitGraphics(wk);
    wk->subProcParam = GFL_HeapAllocate(HEAPID_WORLDTRADE, sizeof(Ov207Param), FALSE, "worldtrade_status.c", 76);
    sys_memset(wk->subProcParam, 0, sizeof(Ov207Param));
    status = wk->subProcParam;
    status->trainerData = wk->param->config;
    status->gameData = GSYS_GetGameData(wk->param->gsys);
    if (WorldTrade_GetPPorPPP(wk->boxTrayNo)) {
        status->partyCount = WorldTrade_GetBoxPokeNum(wk->param->myparty, wk->param->mybox, wk->boxTrayNo);
    } else {
        status->partyCount = 30;
    }
    status->partyIndex = wk->boxCursorPos;
    status->unkD = 1;
    status->move = 0;
    status->unk10 = 0;
    status->isNationalDex = wk->param->isNationalDex;
    status->unk20 = 0;
    if (WorldTrade_GetPPorPPP(wk->boxTrayNo)) {
        status->party = wk->param->myparty;
        status->unkC = 1;
    } else {
        status->party = (PokeParty *)WorldTrade_GetPokePtr(wk->param->myparty, wk->param->mybox, wk->boxTrayNo, 0);
        status->unkC = 2;
    }
    QueueGameProc(wk->procManager, OVERLAY_ID(207), &data_ov207_021bb6a0, status);
    wk->subprocFlag = 1;
    return WT_SEQ_FADEIN;
}

int WorldTrade_Status_Main(WorldTradeWork *wk, int seq) {
    int ret = WT_SEQ_MAIN;

    if (!wk->procResult) {
        WorldTrade_SubProcessChange(wk, WORLDTRADE_MYBOX, wk->subProcessMode);
        ret = WT_SEQ_FADEOUT;
    }
    return ret;
}

int WorldTrade_Status_End(WorldTradeWork *wk, int seq) {
    wk->boxCursorPos = ((Ov207Param *)wk->subProcParam)->partyIndex;
    GFL_HeapFree(wk->subProcParam);
    WorldTrade_InitGraphics(wk);
    WorldTrade_SubProcessUpdate(wk);
    return WT_SEQ_INIT;
}
