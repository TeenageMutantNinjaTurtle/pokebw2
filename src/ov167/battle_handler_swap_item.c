#include "battle/btl_action.h"
#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

struct BattleHandlerSwapItemParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u8 otherIndex;
    u8 unk05[3];
    BattleHandlerString firstString;
    BattleHandlerString secondString;
    BattleHandlerString thirdString;
};

// Function name from swan.
BOOL BattleHandler_SwapItem(BattleHandler *handler, BattleHandlerSwapItemParam *param) {
    BattleMon *first;
    BattleMon *second;
    u16 firstItem;
    u16 secondItem;
    u8 result;
    u32 state;
    u32 command;

    first = GetPokeParam(handler->pokeCon, param->otherIndex);
    second = GetPokeParam(handler->pokeCon, param->monIndex);
    firstItem = GetBattleMonHeldItem(second);
    secondItem = GetBattleMonHeldItem(first);
    command = 0x3d64;
    state = PushState((BtlActionState *)&handler->actionState, command);
    result = ServerEvent_CheckItemSet(handler, first, firstItem);
    PopState((BtlActionState *)&handler->actionState, state, command + 2);
    if (result) {
        state = PushState((BtlActionState *)&handler->actionState, command + 5);
        ServerEvent_ItemSetFailed(handler, first);
        PopState((BtlActionState *)&handler->actionState, state, command + 7);
        return FALSE;
    }
    if (param->popup) {
        ServerDisplay_AbilityPopupAdd(handler, second);
    }
    BattleHandler_SetString(handler, &param->firstString);
    BattleHandler_SetString(handler, &param->secondString);
    BattleHandler_SetString(handler, &param->thirdString);
    if (param->popup) {
        ServerDisplay_AbilityPopupRemove(handler, second);
    }
    ServerControl_ChangeHeldItem(handler, second, secondItem, 0);
    ServerControl_ChangeHeldItem(handler, first, firstItem, 0);
    ServerControl_CheckItemReaction(handler, second, 0);
    ServerControl_CheckItemReaction(handler, first, 0);
    return TRUE;
}
