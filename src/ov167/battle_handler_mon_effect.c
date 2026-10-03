#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.

struct BattleHandlerFlinchParam {
    u32 unk00;
    u8 monIndex;
    u8 flag;
};

// Function name from swan.
u8 BattleHandler_Flinch(BattleHandler *handler, BattleHandlerFlinchParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (ServerControl_FlinchCore(handler, mon, param->flag)) {
        return TRUE;
    }
    return FALSE;
}

struct BattleHandlerReviveParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05;
    u16 amount;
    u8 string[0x28];
};

// Function name from swan.
BOOL BattleHandler_Revive(BattleHandler *handler, BattleHandlerReviveParam *param) {
    BattleMon *mon;
    u8 pos;
    u8 target;
    u8 slot;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    HPAdd(mon, param->amount);
    func_ov167_021b1434(handler->display, 2, param->monIndex, param->amount);
    handler->unk7a9[param->monIndex] = 0;
    BattleHandler_SetString(handler, (BattleHandlerString *)param->string);
    pos = MonIDToBattlePos(handler->mainModule, handler->pokeCon, param->monIndex);
    if (pos != BTL_POS_MAX) {
        target = func_ov167_0219c648(param->monIndex);
        slot = func_ov167_0219c658(handler->mainModule, pos);
        ServerControl_SwitchInFillSlot(handler, target, slot, slot, TRUE);
        ServerControl_AfterSwitchIn(handler);
    }
    return TRUE;
}

struct BattleHandlerSetWeightParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05;
    u16 weight;
    u8 string[0x28];
};

// Function name from swan.
BOOL BattleHandler_SetWeight(BattleHandler *handler, BattleHandlerSetWeightParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    SetWeight(mon, param->weight);
    func_ov167_021b1434(handler->display, 0x14, param->monIndex, param->weight);
    BattleHandler_SetString(handler, (BattleHandlerString *)param->string);
    return TRUE;
}
