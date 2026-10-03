#include "types.h"
#include "battle/btl_ability.h"
#include "battle/btl_action.h"
#include "battle/btl_action_order.h"
#include "battle/btl_display.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"
#include "battle/btl_handler.h"
#include "battle/btl_item.h"
#include "battle/btl_main.h"
#include "battle/btl_math.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server.h"
#include "battle/btl_server_flow.h"
#include "battle/btl_setup.h"
#include "battle/btlv.h"
#include "constants/pokemon.h"
#include "gfl/std.h"
#include "pml/poke_party.h"
#include "pml/waza.h"
#include "save/bag.h"
#include "save/config.h"

u32 ConvertConditionCode(BattleMon *mon, u32 *condition);

BOOL func_ov167_021acca8(u32 condition, u32 value, BattleMon *mon, u32 context, BattleHandlerString *string);

BOOL func_ov167_021aceb4(void *state, u8 monId);

BOOL func_ov167_021acec4(void *state, u8 monId);

BOOL IsStatChangeValid(BattleMon *mon, u32 stat, s32 change);

BOOL func_ov167_021a6ab8(BtlServerFlow *handler, u8 monId, BattleMon *mon, u32 stat, s32 change, u32 displayCode,
                          u32 context, u32 value, u8 extra, BOOL flag);

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.
// Function name from swan.
ActionOrderEntry *ActionOrder_SearchByMonID(BtlServerFlow *flow, u8 monId) {
    u32 i;

    for (i = 0; i < flow->actionOrderCount; i++) {
        if (GetMonID(flow->actionOrder[i].mon) == monId) {
            return &flow->actionOrder[i];
        }
    }
    return NULL;
}

// Function names from swan.
BOOL ActionOrder_InterruptReserve(BtlServerFlow *flow, u8 monId) {
    ActionOrderEntry *entry;

    entry = ActionOrder_SearchByMonID(flow, monId);
    if (entry && !entry->done && ActionOrderTool_Interrupt(flow, entry, 0) >= 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL ActionOrder_InterruptReserveByMove(BtlServerFlow *flow, u16 moveId) {
    u32 start;
    BOOL didInterrupt;
    ActionOrderEntry *entry;
    s32 index;

    start = 0;
    entry = ActionOrder_SearchByMoveID(flow, moveId, 0);
    didInterrupt = FALSE;
    while (entry) {
        index = ActionOrderTool_Interrupt(flow, entry, start);
        if (index < 0) {
            break;
        }
        start = index + 1;
        entry = ActionOrder_SearchByMoveID(flow, moveId, (u8)start);
        didInterrupt = TRUE;
    }
    return didInterrupt;
}

BOOL ActionOrder_SendToLast(BtlServerFlow *flow, u8 monId) {
    ActionOrderEntry *entry;

    entry = ActionOrder_SearchByMonID(flow, monId);
    if (entry && !entry->done) {
        ActionOrderTool_SendToLast(flow, entry);
        return TRUE;
    }
    return FALSE;
}

void ActionOrder_ForceDone(BtlServerFlow *flow, u8 monId) {
    ActionOrderEntry *entry;

    entry = ActionOrder_SearchByMonID(flow, monId);
    if (entry) {
        entry->done = 1;
    }
}

// Function names from swan.
void ServerDisplay_AbilityPopupAdd(BtlServerFlow *handler, BattleMon *mon) {
    func_ov167_021b1434(handler->display, 0x57, GetMonID(mon));
}

void ServerDisplay_AbilityPopupRemove(BtlServerFlow *handler, BattleMon *mon) {
    func_ov167_021b1434(handler->display, 0x58, GetMonID(mon));
}

// Function names from swan.
void scPut_SetContFlag(BtlServerFlow *handler, BattleMon *mon, u32 flag) {
    func_ov167_021bb7e4(mon, flag);
    func_ov167_021b1434(handler->display, 0x19, GetMonID(mon), flag);
}

void scPut_ResetContFlag(BtlServerFlow *handler, BattleMon *mon, u32 flag) {
    func_ov167_021bb808(mon, flag);
    func_ov167_021b1434(handler->display, 0x1a, GetMonID(mon), flag);
}

void ServerDisplay_SetTurnFlag(BtlServerFlow *handler, BattleMon *mon, u32 flag) {
    func_ov167_021bb7c0(mon, flag);
    func_ov167_021b1434(handler->display, 0x1b, GetMonID(mon), flag);
}

// Function names from swan.

void BattleHandler_StrClear(BattleHandlerString *string) {
    sys_memset(string, 0, 0x28);
    string->enabled = 0;
}

BOOL BattleHandler_StrIsEnabled(BattleHandlerString *string) {
    return string->enabled != 0;
}

void BattleHandler_StrSetup(BattleHandlerString *string, u32 enabled, u16 message) {
    string->enabled = enabled;
    string->message = message;
    string->count = 0;
}

void BattleHandler_AddArg(BattleHandlerString *string, u32 arg) {
    u16 count;

    count = string->count;
    if (count < 9) {
        string->count = count + 1;
        string->args[count] = arg;
    }
}

void BattleHandler_AddSoundEffect(BattleHandlerString *string, u32 soundEffect) {
    if (string->count < 9) {
        string->soundEffect = soundEffect;
        string->hasSound = 1;
    }
}

void *BattleHandler_PushWork(BtlServerFlow *flow, u32 command, u32 monId) {
    return func_ov167_021b0920(&flow->actionState, command, monId);
}

void BattleHandler_PushRun(BtlServerFlow *flow, u32 command, u32 monId) {
    void *work;

    work = BattleHandler_PushWork(flow, command, monId);
    BattleHandler_PopWork(flow, work);
}

void BattleHandler_PopWork(BtlServerFlow *flow, void *work) {
    BattleHandler_Execute(flow);
    PopWork(&flow->actionState, work);
}

u32 BattleHandler_Result(BtlServerFlow *handler) {
    BtlActionState *state;

    state = &handler->actionState;
    if (IsUsed(state)) {
        if (func_ov167_021b0918(state)) {
            return 2;
        }
        return 1;
    }
    return 0;
}

// Function name from swan.
BOOL BattleHandler_AbilityPopupRemove(BtlServerFlow *handler, BattleHandlerPopupParam *param) {
    BattleMon *mon = GetPokeParam(handler->pokeCon, param->monId);
    ServerDisplay_AbilityPopupRemove(handler, mon);
    return TRUE;
}

// Function name from swan.
BOOL BattleHandler_Drain(BtlServerFlow *handler, BattleHandlerDrainParam *param) {
    BattleMon *source;
    BattleMon *mon;

    source = NULL;
    if (param->sourceIndex != 0x1f) {
        source = GetPokeParam(handler->pokeCon, param->sourceIndex);
    }
    if (func_ov167_021ac988(handler->unk1ab8, param->monIndex)) {
        mon = GetPokeParam(handler->pokeCon, param->monIndex);
        if (!IsFainted(mon)) {
            if (ServerControl_DrainCore(handler, mon, source, param->amount)) {
                if (param->string.enabled) {
                    BattleHandler_SetString(handler, &param->string);
                }
                return TRUE;
            }
        }
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_Damage(BtlServerFlow *handler, BattleHandlerDamageParam *param) {
    BattleMon *mon;
    BattleMon *source;

    if (func_ov167_021aca54(handler->unk1ab8, param->targetIndex)) {
        mon = GetPokeParam(handler->pokeCon, param->targetIndex);
        source = NULL;
        if (param->sourceIndex != 0x1f) {
            source = GetPokeParam(handler->pokeCon, param->sourceIndex);
        }
        if (!IsFainted(mon)) {
            if (!param->checkSemi || !IsSemiInvulnMove(mon)) {
                if (ServerControl_CheckSimpleDamageEnabled(handler, mon, param->amount)) {
                    if (param->popup) {
                        ServerDisplay_AbilityPopupAdd(handler, source);
                    }
                    if (param->showViewEffect) {
                        ServerControl_ViewEffect(handler, param->effect, param->effectArg1, param->effectArg2, 0, 0);
                    }
                    ServerControl_SimpleDamageCore(handler, mon, param->amount, &param->string);
                    if (param->popup) {
                        ServerDisplay_AbilityPopupRemove(handler, source);
                    }
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_ChangeHP(BtlServerFlow *handler, BattleHandlerChangeHPParam *param) {
    u32 result;
    u32 i;
    BattleMon *mon;

    result = FALSE;
    for (i = 0; i < param->count; i++) {
        if (func_ov167_021acad4(handler->unk1ab8, param->monIds[i])) {
            mon = GetPokeParam(handler->pokeCon, param->monIds[i]);
            if (!IsFainted(mon)) {
                ServerDisplay_SimpleHP(handler, mon, param->hpChanges[i], param->suppress == 0);
                if (param->skipReaction == 0) {
                    ServerControl_CheckItemReaction(handler, mon, 1);
                }
                result = TRUE;
            }
        }
    }
    return result;
}

// Function name from swan.
BOOL BattleHandler_DecrementPP(BtlServerFlow *handler, BattleHandlerDecrementPPParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon) || param->allowFainted) {
        if (ServerControl_DecrementPP(handler, mon, param->moveIndex, param->amount)) {
            BattleHandler_SetString(handler, &param->string);
            if (ServerEvent_DecrementPP(handler, mon, param->moveIndex)) {
                ServerControl_UseHeldItem(handler, mon);
            }
        }
        return TRUE;
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_CureCondition(BtlServerFlow *handler, struct BattleHandlerCureConditionParam *param, u32 context) {
    BattleMon *mon;
    BattleMon *target;
    u32 changed;
    u32 i;
    u32 condition;
    u32 code;
    u32 resultCondition;
    BattleHandlerString *string;

    target = GetPokeParam(handler->pokeCon, param->monIndex);
    changed = FALSE;
    if (param->popup) {
        ServerDisplay_AbilityPopupAdd(handler, target);
    }
    for (i = 0; i < param->count; i++) {
        mon = GetPokeParam(handler->pokeCon, param->monIds[i]);
        if (!CanPokemonBattle(mon)) {
            continue;
        }
        condition = param->condition;
        code = ConvertConditionCode(mon, &condition);
        if (code == 0) {
            continue;
        }
        string = &param->string;
        changed = TRUE;
        do {
                    ((void (*)(BtlServerFlow *, BattleMon *, u32, u32 *))ServerControl_CureCondition)(handler, mon, code,
                                                                                                 &resultCondition);
                    if (param->useString == 0) {
                        if (func_ov167_021acca8(code, resultCondition, mon, context,
                                                &handler->message)) {
                            BattleHandler_SetString(handler, &handler->message);
                            BattleHandler_StrClear(&handler->message);
                        }
                    } else {
                        BattleHandler_SetString(handler, string);
                    }
                    if (code == 0x13) {
                        ServerControl_CheckItemReaction(handler, mon, 0);
                    }
                    code = ConvertConditionCode(mon, &condition);
        } while (code);
    }
    if (param->popup) {
        ServerDisplay_AbilityPopupRemove(handler, target);
    }
    return changed;
}

// Function name from swan.
BOOL BattleHandler_StatChange(BtlServerFlow *handler, struct BattleHandlerStatChangeParam *param, u32 context) {
    BattleMon *popupMon;
    BattleMon *mon;
    BOOL valid;
    BOOL result;
    u32 i;
    u32 stat;

    popupMon = GetPokeParam(handler->pokeCon, param->monIndex);
    valid = FALSE;
    result = FALSE;
    for (i = 0; i < param->count; i++) {
        if (func_ov167_021aceb4(handler->unk1ab8, param->monIds[i])) {
            mon = GetPokeParam(handler->pokeCon, param->monIds[i]);
            if (!IsFainted(mon) && IsStatChangeValid(mon, param->stat, param->change)) {
                valid = TRUE;
                break;
            }
        }
    }
    if (valid && param->popup) {
        ServerDisplay_AbilityPopupAdd(handler, popupMon);
    }
    for (i = 0; i < param->count; i++) {
        if (func_ov167_021acec4(handler->unk1ab8, param->monIds[i])) {
            mon = GetPokeParam(handler->pokeCon, param->monIds[i]);
            if (!IsFainted(mon)) {
                stat = param->stat;
                if (func_ov167_021a6ab8(handler, param->monIndex, mon, stat, param->change, 0x1f, context,
                                         param->value, param->unk0e, param->flag == 0)) {
                    BattleHandler_SetString(handler, &param->string);
                    result = TRUE;
                }
            }
        }
    }
    if (valid && param->popup) {
        ServerDisplay_AbilityPopupRemove(handler, popupMon);
    }
    return result;
}

// Function names from swan.
u8 BattleHandler_RecoverStatStage(BtlServerFlow *handler, BattleHandlerRecoverStatStageParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        func_ov167_021b1434(handler->display, 0xc, param->monIndex);
        return StatStageRecover(mon);
    }
    return FALSE;
}

BOOL BattleHandler_ResetStatStage(BtlServerFlow *handler, BattleHandlerResetStatStageParam *param) {
    u32 i;
    BOOL result;
    BattleMon *mon;

    result = FALSE;
    for (i = 0; i < param->count; i++) {
        mon = GetPokeParam(handler->pokeCon, param->monIndices[i]);
        if (!IsFainted(mon)) {
            func_ov167_021b1434(handler->display, 0xd, param->monIndices[i]);
            StatStageReset(mon);
            result = TRUE;
        }
    }
    return result;
}

// Function name from swan.
BOOL BattleHandler_Faint(BtlServerFlow *handler, BattleHandlerFaintParam *param) {
    BattleMon *mon;

    if (func_ov167_021ad15c(handler->unk1ab8, param->monIndex)) {
        mon = GetPokeParam(handler->pokeCon, param->monIndex);
        if (!IsFainted(mon) || param->force) {
            BattleHandler_SetString(handler, &param->string);
            ServerControl_FaintPokemon(handler, mon);
            return TRUE;
        }
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_ChangeType(BtlServerFlow *handler, BattleHandlerChangeTypeParam *param) {
    BattleMon *mon;

    if (func_ov167_021ad1f4(handler->unk1ab8, param->monIndex)) {
        mon = GetPokeParam(handler->pokeCon, param->monIndex);
        if (!IsFainted(mon) && !func_ov167_021ad204(GetBattleMonSpecies(mon))) {
            func_ov167_021b1434(handler->display, 0x16, param->monIndex, param->type);
            ChangePokeType(mon, param->type);
            if (!param->suppressMessage && PokeTypePair_IsMonotype(param->type)) {
                func_ov167_021b15d0(handler->display, 0x5b, 0x380, param->monIndex, PokeTypePair_GetType1(param->type),
                                    0xffff0000);
            }
            return TRUE;
        }
    }
    return FALSE;
}

BOOL BattleHandler_Message(BtlServerFlow *handler, BattleHandlerMessageParam *param) {
    BattleMon *mon;

    mon = NULL;
    if (param->monIndex != 0x1f) {
        mon = GetPokeParam(handler->pokeCon, param->monIndex);
    }
    if (param->popup && mon != NULL) {
        ServerDisplay_AbilityPopupAdd(handler, mon);
    }
    BattleHandler_SetString(handler, &param->string);
    if (param->popup && mon != NULL) {
        ServerDisplay_AbilityPopupRemove(handler, mon);
    }
    return TRUE;
}

BOOL BattleHandler_SetTurnFlag(BtlServerFlow *handler, BattleHandlerFlagParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        func_ov167_021bb7c0(mon, param->flag);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_ResetTurnFlag(BtlServerFlow *handler, BattleHandlerFlagParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        func_ov167_021bbc40(mon, param->flag);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_SetContinueFlag(BtlServerFlow *handler, BattleHandlerFlagParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        scPut_SetContFlag(handler, mon, param->flag);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_ResetContinueFlag(BtlServerFlow *handler, BattleHandlerFlagParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        scPut_ResetContFlag(handler, mon, param->flag);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_AddFieldEffect(BtlServerFlow *handler, BattleHandlerAddFieldEffectParam *param) {
    if (ServerControl_FieldEffectCore(handler, param->effect, param->value, param->duration)) {
        BattleHandler_SetString(handler, &param->string);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_RemoveFieldEffect(BtlServerFlow *handler, BattleHandlerRemoveFieldEffectParam *param) {
    if (FieldStatusRemoveEffect(param->effect)) {
        ServerControl_FieldEffectEnd(handler, param->effect);
        return TRUE;
    }
    return FALSE;
}

u8 BattleHandler_ChangeWeather(BtlServerFlow *handler, BattleHandlerChangeWeatherParam *param) {
    BattleMon *mon;
    u32 result;
    u32 state;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    result = FALSE;
    if (param->weather != 0) {
        if (ServerControl_ChangeWeatherCheck(handler, param->weather, param->duration)) {
            if (param->popup) {
                ServerDisplay_AbilityPopupAdd(handler, mon);
            }
            ServerControl_ChangeWeatherCore(handler, param->weather, param->duration);
            BattleHandler_SetString(handler, &param->string);
            result = TRUE;
            if (param->popup) {
                ServerDisplay_AbilityPopupRemove(handler, mon);
            }
        }
    } else if (param->notifyAirLock != 0) {
        if (param->popup) {
            ServerDisplay_AbilityPopupAdd(handler, mon);
        }
        BattleHandler_SetString(handler, &param->string);
        state = PushState(&handler->actionState, 0x3c98);
        ServerEvent_NotifyAirLock(handler);
        PopState(&handler->actionState, state, 0x3c9a);
        result = TRUE;
        if (param->popup) {
            ServerDisplay_AbilityPopupRemove(handler, mon);
        }
    }
    return result;
}

// Function name from swan.
BOOL BattleHandler_SetString(BtlServerFlow *handler, BattleHandlerString *string) {
    u16 soundEffect;
    u32 flags;

    flags = string->flags;

    if (!((flags << 16) >> 31)) {
        switch ((flags & 0xff)) {
        case 1:
            ServerDisplay_StandardMessage(handler, string->message, ((flags << 17) >> 25), string->args);
            return TRUE;
        case 2:
            ServerDisplay_SetMessage(handler, string->message, ((flags << 17) >> 25), string->args);
            return TRUE;
        }
    } else {
        soundEffect = string->soundEffect;
        switch ((flags & 0xff)) {
        case 1:
            ServerDisplay_StandardMessageEx(handler, string->message, soundEffect, ((flags << 17) >> 25), string->args);
            return TRUE;
        case 2:
            ServerDisplay_SetMessageEx(handler, string->message, soundEffect, ((flags << 17) >> 25), string->args);
            return TRUE;
        }
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_AbilityChange(BtlServerFlow *handler, BattleHandlerAbilityChangeParam *param) {
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
        state = PushState(&handler->actionState, command);
        ServerEvent_ChangeAbilityBefore(handler, param->targetIndex, oldAbility, param->ability);
        PopState(&handler->actionState, state, command + 2);
        AbilityEvent_RemoveItem(mon);
        ChangeAbility(mon, param->ability);
        func_ov167_021b1434(handler->display, 0x1d, param->targetIndex, param->ability);
        AbilityEvent_AddItem(mon);
        func_ov167_021b1434(handler->display, 0x58, param->targetIndex);
        if (oldAbility != param->ability) {
            state = PushState(&handler->actionState, command + 0x10);
            ServerEvent_ChangeAbilityAfter(handler, param->targetIndex);
            PopState(&handler->actionState, state, command + 0x12);
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

// Function name from swan.
BOOL BattleHandler_SetItem(BtlServerFlow *handler, BattleHandlerSetItemParam *param) {
    BattleMon *mon;
    u8 result;
    u32 state;
    u32 command;

    mon = GetPokeParam(handler->pokeCon, param->targetIndex);
    if (param->monIndex != param->targetIndex) {
        command = 0x3d2c;
        state = PushState(&handler->actionState, command);
        result = ServerEvent_CheckItemSet(handler, mon, param->item);
        PopState(&handler->actionState, state, command + 2);
        if (result) {
            state = PushState(&handler->actionState, command + 6);
            ServerEvent_ItemSetFailed(handler, mon);
            PopState(&handler->actionState, state, command + 8);
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

// Function name from swan.
BOOL BattleHandler_SwapItem(BtlServerFlow *handler, BattleHandlerSwapItemParam *param) {
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
    state = PushState(&handler->actionState, command);
    result = ServerEvent_CheckItemSet(handler, first, firstItem);
    PopState(&handler->actionState, state, command + 2);
    if (result) {
        state = PushState(&handler->actionState, command + 5);
        ServerEvent_ItemSetFailed(handler, first);
        PopState(&handler->actionState, state, command + 7);
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

// Function name from swan.
BOOL BattleHandler_CheckHeldItem(BtlServerFlow *handler, BattleHandlerCheckHeldItemParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    ServerControl_CheckItemReaction(handler, mon, param->reaction);
    return TRUE;
}

// Function name from swan.
BOOL BattleHandler_UseHeldItem(BtlServerFlow *handler, BattleHandlerUseHeldItemParam *param) {
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

// Function name from swan.
BOOL BattleHandler_ForceUseItem(BtlServerFlow *handler, BattleHandlerForceUseItemParam *param) {
    BattleMon *mon;
    void *temp;
    u32 reserve;
    u32 state;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        temp = ItemEvent_TempAdd(mon, param->item);
        if (temp != NULL) {
            reserve = SCQUE_RESERVE_Pos(handler->display, 0x42);
            state = PushState(&handler->actionState, 0x3db8);
            ServerEvent_EquipTempItem(handler, mon, param->monIndex2);
            if (BattleHandler_Result(handler) == 2) {
                func_ov167_021b14ec(handler->display, reserve, 0x42, param->monIndex);
            }
            PopState(&handler->actionState, state, 0x3dbf);
            func_ov167_021c27c4(temp);
            return TRUE;
        }
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_ConsumeItem(BtlServerFlow *handler, BattleHandlerConsumeItemParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (param->skipDisplay == 0) {
        ServerDisplay_UseHeldItem(handler, mon);
        BattleHandler_SetString(handler, &param->string);
    }
    ServerControl_ChangeHeldItem(handler, mon, 0, 1);
    return TRUE;
}

// Function name from swan.
BOOL BattleHandler_SetCounter(BtlServerFlow *handler, BattleHandlerSetCounterParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    ServerControl_SetMonCounter(handler, mon, param->counter, param->value);
    return TRUE;
}

// Function name from swan.
BOOL BattleHandler_QuitBattle(BtlServerFlow *handler, BattleHandlerQuitBattleParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (ServerControl_EscapeSub(handler, mon, TRUE)) {
        handler->unk14 = 5;
        return TRUE;
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_Switch(BtlServerFlow *handler, BattleHandlerSwitchParam *param) {
    BattleMon *mon;
    u8 pos;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!ServerControl_CheckMatchup(handler) && !func_ov167_021abeb4(handler, param->monIndex) && handler->unk14 == 0) {
        BattleHandler_SetString(handler, &param->firstString);
        if (ServerControl_SwitchOut(handler, mon, param->flag)) {
            pos = MonIDToBattlePos(handler->mainModule, handler->pokeCon, param->monIndex);
            RequestChangePokemon(handler->server, pos);
            BattleHandler_SetString(handler, &param->secondString);
            handler->unk14 = 1;
            return TRUE;
        }
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_BatonPass(BtlServerFlow *handler, BattleHandlerBatonPassParam *param) {
    BattleMon *source;
    BattleMon *target;
    u8 substitute;

    source = GetPokeParam(handler->pokeCon, param->sourceMonIndex);
    target = GetPokeParam(handler->pokeCon, param->targetMonIndex);
    if (CheckCondition(source, 16)) {
        ServerEvent_GastroAcidConfirmed(handler, target);
    }
    CopyBatonPassParams(target, source);
    func_ov167_021b1434(handler->display, 0x26, param->sourceMonIndex, param->targetMonIndex);
    if (IsSubstituteActive(target)) {
        substitute = func_ov167_021add78(handler->unk1ab8, param->targetMonIndex);
        func_ov167_021b1434(handler->display, 0x51, substitute);
    }
    return TRUE;
}

// Function name from swan.
u8 BattleHandler_Flinch(BtlServerFlow *handler, BattleHandlerFlinchParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (ServerControl_FlinchCore(handler, mon, param->flag)) {
        return TRUE;
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_Revive(BtlServerFlow *handler, BattleHandlerReviveParam *param) {
    BattleMon *mon;
    u8 pos;
    u8 target;
    u8 slot;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    HPAdd(mon, param->amount);
    func_ov167_021b1434(handler->display, 2, param->monIndex, param->amount);
    handler->unk7a9[param->monIndex] = 0;
    BattleHandler_SetString(handler, &param->string);
    pos = MonIDToBattlePos(handler->mainModule, handler->pokeCon, param->monIndex);
    if (pos != BTL_POS_MAX) {
        target = func_ov167_0219c648(param->monIndex);
        slot = func_ov167_0219c658(handler->mainModule, pos);
        ServerControl_SwitchInFillSlot(handler, target, slot, slot, TRUE);
        ServerControl_AfterSwitchIn(handler);
    }
    return TRUE;
}

// Function name from swan.
BOOL BattleHandler_SetWeight(BtlServerFlow *handler, BattleHandlerSetWeightParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    SetWeight(mon, param->weight);
    func_ov167_021b1434(handler->display, 0x14, param->monIndex, param->weight);
    BattleHandler_SetString(handler, &param->string);
    return TRUE;
}

// Function names from swan.
BOOL BattleHandler_InterruptAction(BtlServerFlow *handler, BattleHandlerInterruptParam *param) {
    if (ActionOrder_InterruptReserve(handler, param->monId)) {
        BattleHandler_SetString(handler, &param->string);
        return TRUE;
    }
    return FALSE;
}

u8 BattleHandler_InterruptMove(BtlServerFlow *handler, BattleHandlerInterruptParam *param) {
    return ActionOrder_InterruptReserveByMove(handler, param->moveId) != 0;
}

BOOL BattleHandler_SendLast(BtlServerFlow *handler, BattleHandlerInterruptParam *param) {
    if (ActionOrder_SendToLast(handler, param->monId)) {
        BattleHandler_SetString(handler, &param->string);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_SwapPoke(BtlServerFlow *handler, BattleHandlerSwapPokeParam *param) {
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

BOOL BattleHandler_Transform(BtlServerFlow *handler, BattleHandlerTransformParam *param) {
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
                state = PushState(&handler->actionState, 0x3f37);
                ServerEvent_ChangeAbilityAfter(handler, monId);
                PopState(&handler->actionState, state, 0x3f39);
            }
            return TRUE;
        }
    }
    return FALSE;
}

BOOL BattleHandler_IllusionBreak(BtlServerFlow *handler, BattleHandlerIllusionBreakParam *param) {
    BattleMon *mon;

    if (func_ov167_021ae0fc(handler->unk1ab8, param->monIndex)) {
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

BOOL BattleHandler_GravityCheck(BtlServerFlow *handler, BattleHandlerGravityCheckParam *param) {
    u8 monIds[6];
    u32 count;
    u8 i;
    BattleMon *mon;
    u32 changed;
    u16 code;
    u8 pos;

    pos = MonIDToBattlePos(handler->mainModule, handler->pokeCon, param->monIndex);
    code = (2 << 10) | pos;
    count = HandlerGetAlivePartyCount(handler, code, monIds);
    for (i = 0; i < count; i++) {
        mon = GetPokeParam(handler->pokeCon, monIds[i]);
        changed = FALSE;
        if (GetAdditionalConditionFlag(mon, 3)) {
            ServerControl_HideTurnCancel(handler, mon, 3);
            changed = TRUE;
        }
        if (ServerEvent_CheckFloating(handler, mon, 1)) {
            changed = TRUE;
        }
        if (CheckCondition(mon, 0x1e)) {
            ServerControl_CureCondition(handler, mon, 0x1e, 0);
            changed = TRUE;
        }
        if (CheckCondition(mon, 0x20)) {
            ServerControl_CureCondition(handler, mon, 0x20, 0);
            changed = TRUE;
        }
        if (changed) {
            func_ov167_021b15d0(handler->display, 0x5b, 0x43b, monIds[i], 0xffff0000);
        }
    }
    return TRUE;
}

BOOL BattleHandler_HideTurnCancel(BtlServerFlow *handler, BattleHandlerHideTurnParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon) && ServerControl_HideTurnCancel(handler, mon, param->flag)) {
        BattleHandler_SetString(handler, &param->string);
        return TRUE;
    }
    return FALSE;
}

// Function names from swan.

// Function name from swan.
BOOL BattleHandler_RemoveMessageWindow(BtlServerFlow *handler) {
    func_ov167_021b1434(handler->display, 0x56, 0);
    return TRUE;
}

// Function name from swan.
BOOL BattleHandler_ChangeForm(BtlServerFlow *handler, BattleHandlerChangeFormParam *param) {
    BattleMon *mon;
    u8 currentForm;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon) && !TransformCheck(mon)) {
        currentForm = GetBattleMonStat(mon, 0x13);
        if (currentForm != param->form) {
            if (param->popup) {
                ServerDisplay_AbilityPopupAdd(handler, mon);
            }
            ChangeForm(mon, param->form);
            func_ov167_021b1434(handler->display, 0x4f, param->monIndex, param->form);
            BattleHandler_SetString(handler, &param->string);
            if (param->popup) {
                ServerDisplay_AbilityPopupRemove(handler, mon);
            }
            return TRUE;
        }
    }
    return FALSE;
}

BOOL BattleHandler_SetMoveEffectIndex(BtlServerFlow *handler, BattleHandlerMoveEffectParam *param) {
    handler->moveEffect->index = param->index;
    return TRUE;
}

BOOL BattleHandler_SetMoveEffectEnable(BtlServerFlow *handler) {
    if (!handler->moveEffect->enabled) {
        handler->moveEffect->enabled = 1;
    }
    return TRUE;
}

// Function names from swan.
void PopState(BtlActionState *state, u32 value, u32 command) {
    state->raw = value;
}

u16 GetUseItemNo(BtlActionState *state) {
    return state->useItemNo;
}

BOOL IsUsed(BtlActionState *state) {
    return state->used;
}

void SetResult(BtlActionState *state, BOOL result) {
    if (result) {
        state->prevResult = 1;
        state->result = 1;
    } else {
        state->prevResult = 0;
    }
    state->used = 1;
}

BOOL GetPrevResult(BtlActionState *state) {
    return state->prevResult;
}
