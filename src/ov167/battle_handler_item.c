#include "battle/btl_action.h"
#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_item.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.

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

struct BattleHandlerCheckHeldItemParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05[3];
    u32 reaction;
};

// Function name from swan.
BOOL BattleHandler_CheckHeldItem(BattleHandler *handler, BattleHandlerCheckHeldItemParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    ServerControl_CheckItemReaction(handler, mon, param->reaction);
    return TRUE;
}

struct BattleHandlerUseHeldItemParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 19;
    u32 checkFullHp : 1;
    u32 allowFainted : 1;
    u32 unk22 : 30;
};

// Function name from swan.
BOOL BattleHandler_UseHeldItem(BattleHandler *handler, BattleHandlerUseHeldItemParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon) || param->allowFainted) {
        if (param->checkFullHp && IsMonFullHP(mon)) {
            return FALSE;
        }
        if (ServerControl_UseHeldItem(handler, mon)) {
            return TRUE;
        }
    }
    return FALSE;
}

struct BattleHandlerForceUseItemParam {
    u32 unk00 : 8;
    u32 monIndex2 : 5;
    u32 unk13 : 19;
    u8 monIndex;
    u8 unk05;
    u16 item;
};

// Function name from swan.
BOOL BattleHandler_ForceUseItem(BattleHandler *handler, BattleHandlerForceUseItemParam *param) {
    BattleMon *mon;
    void *temp;
    u32 reserve;
    u32 state;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        temp = ItemEvent_TempAdd(mon, param->item);
        if (temp != NULL) {
            reserve = SCQUE_RESERVE_Pos(handler->display, 0x42);
            state = PushState((BtlActionState *)&handler->actionState, 0x3db8);
            ServerEvent_EquipTempItem(handler, mon, param->monIndex2);
            if (BattleHandler_Result(handler) == 2) {
                func_ov167_021b14ec(handler->display, reserve, 0x42, param->monIndex);
            }
            PopState((BtlActionState *)&handler->actionState, state, 0x3dbf);
            func_ov167_021c27c4(temp);
            return TRUE;
        }
    }
    return FALSE;
}

struct BattleHandlerConsumeItemParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 19;
    u32 skipDisplay;
    u8 string[0x28];
};

// Function name from swan.
BOOL BattleHandler_ConsumeItem(BattleHandler *handler, BattleHandlerConsumeItemParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (param->skipDisplay == 0) {
        ServerDisplay_UseHeldItem(handler, mon);
        BattleHandler_SetString(handler, (BattleHandlerString *)param->string);
    }
    ServerControl_ChangeHeldItem(handler, mon, 0, 1);
    return TRUE;
}
