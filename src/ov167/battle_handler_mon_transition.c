#include "battle/btl_action.h"
#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.

struct BattleHandlerSwapPokeParam {
    u32 unk00;
    u8 firstMonIndex;
    u8 secondMonIndex;
    u8 unk06[2];
    BattleHandlerString string;
};

BOOL BattleHandler_SwapPoke(BattleHandler *handler, BattleHandlerSwapPokeParam *param) {
    u8 clientId;
    BattleMon *first;
    BattleMon *second;
    BattleParty *party;
    s16 firstSlot;
    s16 secondSlot;

    if (param->firstMonIndex != param->secondMonIndex) {
        clientId = func_ov167_0219c648(param->firstMonIndex);
        if (clientId == func_ov167_0219c648(param->secondMonIndex)) {
            first = GetPokeParam(handler->pokeCon, param->firstMonIndex);
            second = GetPokeParam(handler->pokeCon, param->secondMonIndex);
            if (!IsFainted(first) && !IsFainted(second)) {
                party = GetPartyData(handler->pokeCon, clientId);
                firstSlot = FindPartyMon(party, first);
                secondSlot = FindPartyMon(party, second);
                if (firstSlot >= 0 && secondSlot >= 0) {
                    ServerControl_MoveCore(handler, clientId, firstSlot, secondSlot, 0);
                    BattleHandler_SetString(handler, &param->string);
                    ServerControl_AfterMove(handler, clientId, firstSlot, secondSlot);
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

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

struct BattleHandlerIllusionBreakParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05[3];
    BattleHandlerString string;
};

BOOL BattleHandler_IllusionBreak(BattleHandler *handler, BattleHandlerIllusionBreakParam *param) {
    BattleMon *mon;

    if (func_ov167_021ae0fc((u8 *)handler + 0x1ab8, param->monIndex)) {
        mon = GetPokeParam(handler->pokeCon, param->monIndex);
        if (IsIllusionEnabled(mon)) {
            IllusionBreak(mon);
            func_ov167_021b1434(handler->display, 0x4b, param->monIndex);
            BattleHandler_SetString(handler, &param->string);
            return TRUE;
        }
    }
    return FALSE;
}
