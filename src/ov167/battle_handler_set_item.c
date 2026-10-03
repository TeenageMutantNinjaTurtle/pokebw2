#include "battle/btl_action.h"
#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

struct BattleHandlerSetItemParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u16 item;
    u8 targetIndex;
    u8 clearConsumed;
    u8 clearOtherConsumed;
    u8 otherIndex;
    u8 unk0a[2];
    BattleHandlerString string;
};

// Function name from swan.
BOOL BattleHandler_SetItem(BattleHandler *handler, BattleHandlerSetItemParam *param) {
    BattleMon *mon;
    u8 result;
    u32 state;
    u32 command;

    mon = GetPokeParam(handler->pokeCon, param->targetIndex);
    if (param->monIndex != param->targetIndex) {
        command = 0x3d2c;
        state = PushState((BtlActionState *)&handler->actionState, command);
        result = ServerEvent_CheckItemSet(handler, mon, param->item);
        PopState((BtlActionState *)&handler->actionState, state, command + 2);
        if (result) {
            state = PushState((BtlActionState *)&handler->actionState, command + 6);
            ServerEvent_ItemSetFailed(handler, mon);
            PopState((BtlActionState *)&handler->actionState, state, command + 8);
            return FALSE;
        }
    }
    if (param->popup) {
        func_ov167_021b1434(handler->display, 0x57, param->monIndex);
    }
    BattleHandler_SetString(handler, &param->string);
    ServerControl_ChangeHeldItem(handler, mon, param->item, 0);
    if (param->popup) {
        func_ov167_021b1434(handler->display, 0x58, param->monIndex);
    }
    if (param->clearConsumed) {
        ClearConsumedItem(mon);
        func_ov167_021b1434(handler->display, 0x2b, param->targetIndex);
    }
    if (param->clearOtherConsumed) {
        ClearConsumedItem(GetPokeParam(handler->pokeCon, param->otherIndex));
        func_ov167_021b1434(handler->display, 0x2b, param->otherIndex);
    }
    ServerControl_CheckItemReaction(handler, mon, 0);
    return TRUE;
}
