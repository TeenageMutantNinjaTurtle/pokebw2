#include "battle/btl_action.h"
#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

struct BattleHandlerAbilityChangeParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u16 ability;
    u8 targetIndex;
    u8 force;
    u8 unk08[4];
    BattleHandlerString string;
};

// Function name from swan.
BOOL BattleHandler_AbilityChange(BattleHandler *handler, BattleHandlerAbilityChangeParam *param) {
    BattleMon *mon;
    u16 oldAbility;
    u32 state;
    u32 command;

    mon = GetPokeParam(handler->pokeCon, param->targetIndex);
    oldAbility = GetBattleMonStat(mon, 0x10);
    if (func_ov167_021ad6e8(oldAbility)) {
        return FALSE;
    }
    if (IsFainted(mon)) {
        return FALSE;
    }
    if (param->force || param->ability != oldAbility) {
        if (param->popup) {
            func_ov167_021b1434(handler->display, 0x57, param->monIndex);
        }
        func_ov167_021b1434(handler->display, 0x49, param->targetIndex, param->ability);
        BattleHandler_SetString(handler, &param->string);
        command = 0x3cf6;
        state = PushState((BtlActionState *)&handler->actionState, command);
        ServerEvent_ChangeAbilityBefore(handler, param->targetIndex, oldAbility, param->ability);
        PopState((BtlActionState *)&handler->actionState, state, command + 2);
        AbilityEvent_RemoveItem(mon);
        ChangeAbility(mon, param->ability);
        func_ov167_021b1434(handler->display, 0x1d, param->targetIndex, param->ability);
        AbilityEvent_AddItem(mon);
        func_ov167_021b1434(handler->display, 0x58, param->targetIndex);
        if (oldAbility != param->ability) {
            state = PushState((BtlActionState *)&handler->actionState, command + 0x10);
            ServerEvent_ChangeAbilityAfter(handler, param->targetIndex);
            PopState((BtlActionState *)&handler->actionState, state, command + 0x12);
        }
        if (param->popup) {
            func_ov167_021b1434(handler->display, 0x58, param->monIndex);
        }
        if (!CheckCondition(mon, 16)) {
            if (oldAbility == 0x67) {
                ServerControl_CheckItemReaction(handler, mon, 0);
            }
            if (oldAbility == 0x7f) {
                ServerControl_UnnerveAction(handler, mon);
            }
        }
        return TRUE;
    }
    return FALSE;
}
