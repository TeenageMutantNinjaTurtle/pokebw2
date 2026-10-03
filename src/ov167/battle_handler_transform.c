#include "battle/btl_action.h"
#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

struct BattleHandlerTransformParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u8 targetIndex;
    u8 unk05[3];
    BattleHandlerString string;
};

// Function name from swan.
BOOL BattleHandler_Transform(BattleHandler *handler, BattleHandlerTransformParam *param) {
    BattleMon *mon;
    BattleMon *target;
    u16 oldAbility;
    u8 monId;
    u8 targetId;
    u32 state;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    target = GetPokeParam(handler->pokeCon, param->targetIndex);
    if (!IsIllusionEnabled(mon) && !IsIllusionEnabled(target) && !IsSemiInvulnMove(mon)) {
        oldAbility = GetBattleMonStat(mon, 0x10);
        if (TransformSet(mon, target)) {
            monId = GetMonID(mon);
            targetId = GetMonID(target);
            if (param->popup) {
                ServerDisplay_AbilityPopupAdd(handler, mon);
            }
            RemoveForceAll(mon);
            AbilityEvent_RemoveItem(mon);
            AbilityEvent_AddItem(mon);
            func_ov167_021b1434(handler->display, 0x53, monId, targetId);
            BattleHandler_SetString(handler, &param->string);
            if (param->popup) {
                ServerDisplay_AbilityPopupRemove(handler, mon);
            }
            if (oldAbility != GetBattleMonStat(mon, 0x11)) {
                state = PushState((BtlActionState *)&handler->actionState, 0x3f37);
                ServerEvent_ChangeAbilityAfter(handler, monId);
                PopState((BtlActionState *)&handler->actionState, state, 0x3f39);
            }
            return TRUE;
        }
    }
    return FALSE;
}
