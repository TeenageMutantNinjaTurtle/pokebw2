#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"

struct BattleHandlerFlagParam {
    u32 unk00;
    u32 flag;
    u8 monIndex;
};

// Function names from swan.
BOOL BattleHandler_SetTurnFlag(BattleHandler *handler, BattleHandlerFlagParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        func_ov167_021bb7c0(mon, param->flag);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_ResetTurnFlag(BattleHandler *handler, BattleHandlerFlagParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        func_ov167_021bbc40(mon, param->flag);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_SetContinueFlag(BattleHandler *handler, BattleHandlerFlagParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        scPut_SetContFlag(handler, mon, param->flag);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_ResetContinueFlag(BattleHandler *handler, BattleHandlerFlagParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        scPut_ResetContFlag(handler, mon, param->flag);
        return TRUE;
    }
    return FALSE;
}
