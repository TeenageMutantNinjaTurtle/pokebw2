#include "battle/btl_action_order.h"
#include "battle/btl_handler.h"

struct BattleHandlerInterruptParam {
    u32 unk00;
    union {
        u8 monId;
        u16 moveId;
    };
    u16 unk06;
    u8 string[0x28];
};

// Function names from swan.
BOOL BattleHandler_InterruptAction(BattleHandler *handler, BattleHandlerInterruptParam *param) {
    if (ActionOrder_InterruptReserve((ActionOrder *)handler, param->monId)) {
        BattleHandler_SetString(handler, (BattleHandlerString *)param->string);
        return TRUE;
    }
    return FALSE;
}

u8 BattleHandler_InterruptMove(BattleHandler *handler, BattleHandlerInterruptParam *param) {
    return ActionOrder_InterruptReserveByMove((ActionOrder *)handler, param->moveId) != 0;
}

BOOL BattleHandler_SendLast(BattleHandler *handler, BattleHandlerInterruptParam *param) {
    if (ActionOrder_SendToLast((ActionOrder *)handler, param->monId)) {
        BattleHandler_SetString(handler, (BattleHandlerString *)param->string);
        return TRUE;
    }
    return FALSE;
}
