#include "types.h"
#include "battle/btl_ability.h"
#include "battle/btl_action.h"
#include "battle/btl_calc.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"
#include "battle/btl_handler.h"
#include "battle/btl_handler_work.h"
#include "battle/btl_item.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"
#include "battle/handler_common.h"
#include "pml/item.h"
#include "pml/waza.h"

// The strongest moves Forewarn found, one entry per move
typedef struct ForewarnEntry {
    u8 monId;
    u16 move;
} ForewarnEntry;

// Pickup's scratch buffer: the allies, and those whose item was used this turn
typedef struct PickupWork {
    u8 mons[6];
    u8 candidates[6];
    u8 count;
    u8 numCandidates;
} PickupWork;

// Moody's scratch buffer: every raise/lower pair, then the stats that can go up and down
typedef struct MoodyWork {
    u16 pairs[0x54];
    u8 up[7];
    u8 down[7];
} MoodyWork;

// Function names from swan.
BattleEventItem *AbilityEvent_AddItem(BattleMon *mon) {
    u16 ability;
    u32 i;
    u16 subPriority;
    u8 monId;
    const BattleEventHandlerEntry *handlers;
    u32 packed;
    u32 priority;

    ability = GetBattleMonStat(mon, 0x10);
    for (i = 0; i < 0x9e; i++) {
        if (ability == data_ov167_021d7ef8[i].ability) {
            subPriority = calcAbilHandlerSubPriority(mon);
            monId = GetMonID(mon);
            handlers = data_ov167_021d7ef8[i].eventAdd(&packed);
            priority = devideNumHandersAndPri(&packed);
            return BattleEvent_AddItem(4, ability, priority, subPriority, monId, handlers, packed);
        }
    }
    return NULL;
}

u32 numHandlersWithHandlerPri(u32 priority, u32 count) {
    return (priority << 16) | count;
}

u32 devideNumHandersAndPri(u32 *packed) {
    u32 priority;

    priority = (*packed >> 16) & 0xffff;
    if (priority == 0) {
        priority = 5;
    }
    *packed &= 0xffff;
    return priority;
}

void AbilityEvent_RemoveItem(BattleMon *mon) {
    BattleEventItem *item;
    u8 monId;

    monId = GetMonID(mon);
    item = BattleEvent_SeekItem(4, monId);
    if (item != NULL) {
        do {
            BattleEventItem_Remove(item);
            item = BattleEvent_SeekItem(4, monId);
        } while (item != NULL);
    }
}

void AbilityEvent_ItemRotationSleep(BattleMon *mon) {
    BattleEvent_ItemRotationSleep(GetMonID(mon), 4);
}

void AbilityEvent_ItemRotationWake(BattleMon *mon) {
    if (!BattleEvent_ItemRotationWake(GetMonID(mon), 4)) {
        AbilityEvent_AddItem(mon);
    }
}

void AbilityEvent_Swap(BattleMon *first, BattleMon *second) {
    u8 firstId;
    u8 secondId;
    BattleEventItem *firstItem;
    BattleEventItem *secondItem;

    firstId = GetMonID(first);
    secondId = GetMonID(second);
    firstItem = BattleEvent_SeekItem(4, firstId);
    secondItem = BattleEvent_SeekItem(4, secondId);
    if (firstItem != NULL) {
        BattleEventItem_Remove(firstItem);
    }
    if (secondItem != NULL) {
        BattleEventItem_Remove(secondItem);
    }
    AbilityEvent_AddItem(first);
    AbilityEvent_AddItem(second);
}

// Function name from swan.
u16 calcAbilHandlerSubPriority(BattleMon *mon) {
    return RawBattleMonStat(mon, 12);
}

// Function name from swan.
BOOL AbilityEvent_RollEffectChance(BtlServerFlow *flow, u32 chance) {
    BOOL result;
    BOOL check;

    if (RollEffectChance(chance)) {
        return TRUE;

    }
    check = func_ov167_021abdf8(flow, 1);
    result = TRUE;
    if (!check) {
        result = FALSE;
    }
    return result;
}

const BattleEventHandlerEntry *EventAddIntimidate(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7944;
}

void HandlerIntimidateMemberIn(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 *mons;
    u32 side;
    u32 count;
    u32 i;
    BattleHandlerStatChangeParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        side = func_ov167_021ab840(flow, monId);
        mons = func_ov167_021abc60(flow, 6);
        count = HandlerGetAlivePartyCount(flow, (u16)(side | 0x100), mons);
        if (count != 0) {
            BattleHandler_PushRun(flow, 2, monId);
            param = BattleHandler_PushWork(flow, 0xe, monId);
            param->stat = 1;
            param->change = -1;
            param->unk0e = 1;
            param->count = count;
            for (i = 0; i < count; i++) {
                param->monIds[i] = mons[i];
            }
            BattleHandler_PopWork(flow, param);
            BattleHandler_PushRun(flow, 3, monId);
        }
    }
}

const BattleEventHandlerEntry *EventAddInnerFocus(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7794;
}

void HandlerInnerFocus(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

const BattleEventHandlerEntry *EventAddSteadfast(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7834;
}

void HandlerSteadfast(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerStatChangeParam *param;

    if (BattleEventVar_GetValue(0x22) == 6) {
        if (BattleEventVar_GetValue(2) == monId) {
            param = BattleHandler_PushWork(flow, 0xe, monId);
            param->popup = 1;
            param->stat = 5;
            param->change = 1;
            param->unk0e = 0;
            param->count = 1;
            param->monIds[0] = monId;
            BattleHandler_PopWork(flow, param);
        }
    }
}

const BattleEventHandlerEntry *EventAddThickFat(u32 *priority) {
    *priority = 1;
    return data_ov167_021d763c;
}

void HandlerThickFat(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 type;

    if (BattleEventVar_GetValue(4) == monId) {
        type = BattleEventVar_GetValue(0x16);
        if (type == 14 || type == 9) {
            BattleEventVar_MulValue(0x35, FX32_CONST(0.5));
        }
    }
}

const BattleEventHandlerEntry *EventAddHugePower(u32 *priority) {
    *priority = 1;
    return data_ov167_021d784c;
}

void HandlerHugePower(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u16 move;

    if (BattleEventVar_GetValue(3) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (PML_MoveGetCategory(move) == 1) {
            BattleEventVar_MulValue(0x35, FX32_CONST(2));
        }
    }
}

void HandlerSwiftSwim(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetWeather(flow) == 2) {
            BattleEventVar_MulValue(0x35, FX32_CONST(2));
        }
    }
}

const BattleEventHandlerEntry *EventAddSwiftSwim(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77c4;
}

void HandlerChlorophyll(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetWeather(flow) == 1) {
            BattleEventVar_MulValue(0x35, FX32_CONST(2));
        }
    }
}

const BattleEventHandlerEntry *EventAddChlorophyll(u32 *priority) {
    *priority = 1;
    return data_ov167_021d765c;
}

void HandlerQuickFeet(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetBattleMonStatus(GetBattleMon(flow, monId)) != 0) {
            BattleEventVar_MulValue(0x35, FX32_CONST(1.5));
            BattleEventVar_RewriteValue(0x51, 0);
        }
    }
}

const BattleEventHandlerEntry *EventAddQuickFeet(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77cc;
}

void HandlerTangledFeet(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (CheckCondition(GetBattleMon(flow, monId), 6)) {
            BattleEventVar_MulValue(0x35, FX32_CONST(0.5));
        }
    }
}

const BattleEventHandlerEntry *EventAddTangledFeet(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76ec;
}

void HandlerHustleAccuracy(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u16 move;

    if (BattleEventVar_GetValue(3) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (PML_MoveGetCategory(move) == 1) {
            BattleEventVar_MulValue(0x35, FX32_CONST(0.8));
        }
    }
}

void HandlerHustlePower(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u32 value;

    if (BattleEventVar_GetValue(3) == monId) {
        if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 1) {
            value = BattleEventVar_GetValue(0x33);
            value = fixed_round(value, (3 << 11));
            BattleEventVar_RewriteValue(0x33, value);
        }
    }
}

const BattleEventHandlerEntry *EventAddHustle(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a44;
}

void HandlerStall(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x11, 0);
    }
}

const BattleEventHandlerEntry *EventAddStall(u32 *priority) {
    *priority = numHandlersWithHandlerPri(7, 1);
    return data_ov167_021d7624;
}

void HandlerSlowStartCalcSpeed(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId && work[3] != 0) {
        BattleEventVar_MulValue(0x35, 0x800);
    }
}

void HandlerSlowStartAttackPower(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId && work[3] != 0) {
        if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 1) {
            BattleEventVar_MulValue(0x35, 0x800);
        }
    }
}

void HandlerSlowStartMemberIn(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        HandlerSlowStartTextSet(item, flow, monId, work);
    }
}

void func_ov167_021be18c(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (work[0] == 0) {
        HandlerSlowStartTextSet(item, flow, monId, work);
    }
}

void HandlerSlowStartTextSet(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerMessageParam *param;

    work[0] = 1;
    work[1] = 0;
    work[2] = 0;
    work[3] = work[0];
    param = BattleHandler_PushWork(flow, 4, monId);
    param->popup = 1;
    BattleHandler_StrSetup(&param->string, 2, 0x1f0);
    BattleHandler_AddArg(&param->string, monId);
    BattleHandler_PopWork(flow, param);
}

void HandlerSlowStartTurnCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleAction action;
    BattleHandlerMessageParam *param;

    if (BattleEventVar_GetValue(2) == monId && work[2] == 0) {
        if (work[1] < 5) {
            if (!func_ov167_021abb8c(flow, monId, &action)) {
                return;
            }
            if (action.bits.action == 3) {
                return;
            }
            work[1]++;
        }
        if (work[1] >= 5) {
            param = BattleHandler_PushWork(flow, 4, monId);
            BattleHandler_StrSetup(&param->string, 2, 0x1f3);
            BattleHandler_AddArg(&param->string, monId);
            BattleHandler_PopWork(flow, param);
            work[3] = 0;
            work[2] = 1;
        }
    }
}

const BattleEventHandlerEntry *EventAddSlowStart(u32 *priority) {
    *priority = 6;
    return data_ov167_021d7df0;
}

void HandlerCompoundEyes(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_MulValue(0x35, FX32_CONST(1.3));
    }
}

const BattleEventHandlerEntry *EventAddCompoundEyes(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76d4;
}

void HandlerSandVeil(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (GetWeather(flow) == 4) {
            BattleEventVar_MulValue(0x35, FX32_CONST(0.8));
        }
    }
}

void HandlerSandVeilWeather(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonWeatherGuard(item, flow, monId, work, 4);
}

const BattleEventHandlerEntry *EventAddSandVeil(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a64;
}

void HandlerSnowCloak(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (GetWeather(flow) == 3) {
            BattleEventVar_MulValue(0x35, FX32_CONST(0.8));
        }
    }
}

void HandlerSnowCloakWeather(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonWeatherGuard(item, flow, monId, work, 3);
}

const BattleEventHandlerEntry *EventAddSnowCloak(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a74;
}

void CommonWeatherGuard(BattleEventItem *item, BtlServerFlow *flow, u32 monId, u32 *work, u8 weather) {
    if (BattleEventVar_GetValue(2) == monId) {
        if ((s32)BattleEventVar_GetValue(0x32) > 0) {
            if (BattleEventVar_GetValue(0x39) == weather) {
                BattleEventVar_RewriteValue(0x41, 1);
            }
        }
    }
}

void HandlerTintedLens(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (func_ov167_021bd2e8(BattleEventVar_GetValue(0x38)) == 3) {
            BattleEventVar_MulValue(0x35, FX32_CONST(2));
        }
    }
}

const BattleEventHandlerEntry *EventAddTintedLens(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77bc;
}

void HandlerSolidRock(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (func_ov167_021bd2e8(BattleEventVar_GetValue(0x38)) == 2) {
            BattleEventVar_MulValue(0x35, FX32_CONST(0.75));
        }
    }
}

const BattleEventHandlerEntry *EventAddSolidRock(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7844;
}

void HandlerSniper(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (BattleEventVar_GetValue(0x45) != 0) {
            BattleEventVar_MulValue(0x35, FX32_CONST(1.5));
        }
    }
}

const BattleEventHandlerEntry *EventAddSniper(u32 *priority) {
    *priority = 1;
    return data_ov167_021d783c;
}

void HandlerSpeedBoost(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    BattleHandlerStatChangeParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetAdditionalConditionFlag(mon, 0)) {
            param = BattleHandler_PushWork(flow, 0xe, monId);
            param->popup = 1;
            param->stat = 5;
            param->count = 1;
            param->monIds[0] = monId;
            param->change = 1;
            BattleHandler_PopWork(flow, param);
        }
    }
}

const BattleEventHandlerEntry *EventAddSpeedBoost(u32 *priority) {
    *priority = 1;
    return data_ov167_021d771c;
}

void HandlerAdaptability(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x44) != 0) {
            BattleEventVar_RewriteValue(0x35, (2 << 12));
        }
    }
}

const BattleEventHandlerEntry *EventAddAdaptability(u32 *priority) {
    *priority = 1;
    return data_ov167_021d785c;
}

void HandlerBlaze(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonLowHPBoostAbility(flow, monId, 9);
}

const BattleEventHandlerEntry *EventAddBlaze(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7734;
}

void HandlerTorrent(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonLowHPBoostAbility(flow, monId, 10);
}

const BattleEventHandlerEntry *EventAddTorrent(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7694;
}

void HandlerOvergrow(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonLowHPBoostAbility(flow, monId, 11);
}

const BattleEventHandlerEntry *EventAddOvergrow(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76cc;
}

void HandlerSwarm(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonLowHPBoostAbility(flow, monId, 6);
}

const BattleEventHandlerEntry *EventAddSwarm(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76c4;
}

void CommonLowHPBoostAbility(BtlServerFlow *flow, u8 monId, u32 type) {
    BattleMon *mon;
    u32 threshold;
    u32 divisor;

    divisor = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        mon = GetBattleMon(flow, monId);
        threshold = DivideMaxHp(mon, divisor);
        if (GetBattleMonStat(mon, 0xd) <= threshold) {
            if (BattleEventVar_GetValue(0x16) == type) {
                BattleEventVar_MulValue(0x35, divisor << 11);
            }
        }
    }
}

void HandlerGuts(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;

    if (BattleEventVar_GetValue(3) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetBattleMonStatus(mon) != 0) {
            if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 1) {
                BattleEventVar_MulValue(0x35, FX32_CONST(1.5));
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddGuts(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76bc;
}

void HandlerPlusMinus(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (func_ov167_021be5c4(flow, monId, (u8 *)work, 0x39) || func_ov167_021be5c4(flow, monId, (u8 *)work, 0x3a)) {
            if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 2) {
                BattleEventVar_MulValue(0x35, FX32_CONST(1.5));
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddPlusMinus(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7724;
}

BOOL func_ov167_021be5c4(BtlServerFlow *flow, u8 monId, u8 *mons, u32 ability) {
    u16 packed;
    u32 pos;
    u8 count;
    u8 i;

    pos = func_ov167_021abb50(flow, monId);
    if (pos != 6) {
        packed = (7 << 8) | pos;
        count = HandlerGetAlivePartyCount(flow, packed, mons);
        for (i = 0; i < count; i++) {
            if (monId != mons[i] && GetBattleMonStat(GetBattleMon(flow, mons[i]), 0x11) == ability) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

BOOL CheckFlowerGiftEnablePokemon(BtlServerFlow *flow, u8 monId) {
    return GetBattleMonSpecies(GetBattleMon(flow, monId)) == 0x1a5;
}

void HandlerFlowerGiftMemberOnField(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u32 sunny;
    u32 weather;

    if (CheckFlowerGiftEnablePokemon(flow, monId)) {
        weather = GetWeather(flow);
        sunny = 1;
        if (weather != 1) {
            sunny = 0;
        }
        CommonFlowerGiftFormChange(item, flow, monId, sunny, 1);
        *work = 1;
    }
}

void HandlerFlowerGiftGotAbility(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        HandlerFlowerGiftMemberOnField(item, flow, monId, work);
    }
}

void CommonFlowerGiftFormChange(BattleEventItem *item, BtlServerFlow *flow, u8 monId, u8 sunny, u8 cause) {
    BattleMon *mon;
    BattleHandlerChangeFormParam *work;

    mon = GetBattleMon(flow, monId);
    if (sunny != GetBattleMonStat(mon, 0x13)) {
        work = BattleHandler_PushWork(flow, 0x39, monId);
        work->monIndex = monId;
        work->form = sunny;
        work->popup = cause;
        BattleHandler_StrSetup(&work->string, 2, 0xde);
        BattleHandler_AddArg(&work->string, monId);
        BattleHandler_PopWork(flow, work);
    }
}

void HandlerFlowerGiftWeather(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u32 weather;
    u32 sunny;

    if (*work) {
        if (CheckFlowerGiftEnablePokemon(flow, monId)) {
            weather = GetWeather(flow);
            sunny = 1;
            if (weather != 1) {
                sunny = 0;
            }
            CommonFlowerGiftFormChange(item, flow, monId, sunny, 1);
        }
    }
}

void HandlerFlowerGiftAbilityOff(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (*work) {
        if (BattleEventVar_GetValue(2) == monId) {
            if (CheckFlowerGiftEnablePokemon(flow, monId)) {
                CommonFlowerGiftFormChange(item, flow, monId, 0, 0);
            }
        }
    }
}

void HandlerFlowerGiftAirLock(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (*work) {
        if (CheckFlowerGiftEnablePokemon(flow, monId)) {
            CommonFlowerGiftFormChange(item, flow, monId, 0, 0);
        }
    }
}

void HandlerFlowerGiftAbilityChange(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u32 ability;

    if (*work) {
        if (CheckFlowerGiftEnablePokemon(flow, monId)) {
            if (BattleEventVar_GetValue(2) == monId) {
                ability = BattleEventVar_GetValue(0x10);
                if (ability != BattleEventItem_GetSubID(item)) {
                    CommonFlowerGiftFormChange(item, flow, monId, 0, 0);
                }
            }
        }
    }
}

void HandlerFlowerGiftPower(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 allyMonId;

    if (CheckFlowerGiftEnablePokemon(flow, monId)) {
        if (GetWeather(flow) == 1) {
            allyMonId = BattleEventVar_GetValue(3);
            if (IsAllyMonID(monId, allyMonId)) {
                if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 1) {
                    BattleEventVar_MulValue(0x35, FX32_CONST(1.5));
                }
            }
        }
    }
}

void HandlerFlowerGiftSpecialDefense(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 allyMonId;

    if (CheckFlowerGiftEnablePokemon(flow, monId)) {
        if (GetWeather(flow) == 1) {
            allyMonId = BattleEventVar_GetValue(4);
            if (IsAllyMonID(monId, allyMonId)) {
                if (BattleEventVar_GetValue(0x1a) == 2) {
                    BattleEventVar_MulValue(0x35, FX32_CONST(1.5));
                }
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddFlowerGift(u32 *priority) {
    *priority = 11;
    return data_ov167_021d7ea0;
}

void HandlerRivalry(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *attacker;
    BattleMon *defender;
    u8 attackerGender;
    u8 defenderGender;
    u32 targetMonId;
    u32 multiplier;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        attacker = GetBattleMon(flow, monId);
        targetMonId = BattleEventVar_GetValue(4);
        defender = GetBattleMon(flow, (u8)targetMonId);
        attackerGender = GetBattleMonStat(attacker, 0x12);
        defenderGender = GetBattleMonStat(defender, 0x12);
        if (attackerGender != 2 && defenderGender != 2) {
            if (attackerGender == defenderGender) {
                BattleEventVar_MulValue(0x31, FX32_CONST(1.25));
                return;
            }
            BattleEventVar_MulValue(0x31, multiplier << 10);
        }
    }
}

const BattleEventHandlerEntry *EventAddRivalry(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7864;
}

void HandlerTechnician(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (BattleEventVar_GetValue(0x30) <= 0x3c) {
            BattleEventVar_MulValue(0x31, FX32_CONST(1.5));
        }
    }
}

const BattleEventHandlerEntry *EventAddTechnician(u32 *priority) {
    *priority = 1;
    return data_ov167_021d768c;
}

void HandlerIronFist(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (getMoveFlag(BattleEventVar_GetValue(0x12), 7)) {
            BattleEventVar_MulValue(0x31, FX32_CONST(1.2));
        }
    }
}

const BattleEventHandlerEntry *EventAddIronFist(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77dc;
}

void HandlerReckless(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u16 move;

    if (BattleEventVar_GetValue(3) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (PML_MoveGetParam(move, 0x1e) || move == 0x1a || move == 0x88) {
            BattleEventVar_MulValue(0x31, FX32_CONST(1.2));
        }
    }
}

const BattleEventHandlerEntry *EventAddReckless(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77a4;
}

void HandlerMarvelScale(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;

    if (BattleEventVar_GetValue(4) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetBattleMonStatus(mon)) {
            BattleEventVar_GetValue(0x12);
            if (BattleEventVar_GetValue(0x1a) == 1) {
                BattleEventVar_MulValue(0x35, FX32_CONST(1.5));
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddMarvelScale(u32 *priority) {
    *priority = 1;
    return data_ov167_021d772c;
}

void HandlerSkillLink(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x51, 1);
    }
}

const BattleEventHandlerEntry *EventAddSkillLink(u32 *priority) {
    *priority = 1;
    return data_ov167_021d769c;
}

const BattleEventHandlerEntry *EventAddHyperCutter(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7904;
}

void HandlerHyperCutterCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonStatDropGuardCheck(flow, monId, work, 1);
}

void HandlerHyperCutterGuard(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonStatDropGuardFixed(flow, monId, work, 0xc9);
}

const BattleEventHandlerEntry *EventAddKeenEye(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7914;
}

void HandlerKeenEyeCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonStatDropGuardCheck(flow, monId, work, 6);
}

void HandlerKeenEyeGuard(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonStatDropGuardFixed(flow, monId, work, 0xcf);
}

const BattleEventHandlerEntry *EventAddClearBody(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7924;
}

void HandlerClearBodyCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonStatDropGuardCheck(flow, monId, work, 8);
}

void HandlerClearBodyGuard(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonStatDropGuardFixed(flow, monId, work, 0xc6);
}

void CommonStatDropGuardCheck(BtlServerFlow *flow, u32 monId, u32 *result, u32 stat) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(3) != monId) {
            if (stat == 8 || BattleEventVar_GetValue(0x1f) == stat) {
                if ((s32)BattleEventVar_GetValue(0x20) < 0) {
                    *result = BattleEventVar_RewriteValue(0x41, 1);
                }
            }
        }
    }
}

void CommonStatDropGuardFixed(BtlServerFlow *flow, u32 monId, u32 *result, u16 message) {
    u32 source;
    BattleHandlerMessageParam *work;

    if (BattleEventVar_GetValue(2) == monId && result[0]) {
        source = BattleEventVar_GetValue(0x19);
        if (source == 0 || result[1] != source) {
            BattleHandler_PushRun(flow, 2, monId);
            work = BattleHandler_PushWork(flow, 4, monId);
            BattleHandler_StrSetup(&work->string, 2, message);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork(flow, work);
            BattleHandler_PushRun(flow, 3, monId);
            result[1] = source;
        }
        result[0] = 0;
    }
}

void HandlerSimple(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x20, BattleEventVar_GetValue(0x20) << 1);
    }
}

const BattleEventHandlerEntry *EventAddSimple(u32 *priority) {
    *priority = 1;
    return data_ov167_021d773c;
}

void HandlerLeafGuard(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u32 condition;

    if (BattleEventVar_GetValue(4) == monId) {
        if (GetWeather(flow) == 1) {
            condition = BattleEventVar_GetValue(0x1d);
            if (IsBasicStatus(condition) || condition == 0xe) {
                *work = BattleEventVar_RewriteValue(0x41, 1);
            }
        }
    }
}

void HandlerLeafGuardYawnCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetWeather(flow) == 1) {
            BattleEventVar_RewriteValue(0x41, 1);
        }
    }
}

const BattleEventHandlerEntry *EventAddLeafGuard(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7ac4;
}

void HandlerLimberStatus(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    *work = HandlerCommonGuardStatus(flow, monId, 1);
}

void HandlerLimberCureStatus(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAbilityCureStatus(flow, monId, 1);
}

void HandlerLimberActionEnd(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAbilityCureStatusCore(flow, monId, 1);
}

const BattleEventHandlerEntry *EventAddLimber(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7c80;
}

void HandlerInsomniaStatus(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    *work = HandlerCommonGuardStatus(flow, monId, 2);
    if (!*work) {
        *work = HandlerCommonGuardStatus(flow, monId, 0xe);
    }
}

void HandlerInsomniaWake(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAbilityCureStatus(flow, monId, 2);
}

void HandlerInsomniaActionEnd(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAbilityCureStatusCore(flow, monId, 2);
}

void HandlerInsomniaYawnCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

const BattleEventHandlerEntry *EventAddInsomnia(u32 *priority) {
    *priority = 6;
    return data_ov167_021d7dc0;
}

void HandlerMagmaArmorStatus(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    *work = HandlerCommonGuardStatus(flow, monId, 3);
}

void HandlerMagmaArmorCureStatus(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAbilityCureStatus(flow, monId, 3);
}

void HandlerMagmaArmorActionEnd(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAbilityCureStatusCore(flow, monId, 3);
}

const BattleEventHandlerEntry *EventAddMagmaArmor(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7cd0;
}

void HandlerImmunity(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    *work = HandlerCommonGuardStatus(flow, monId, 5);
}

void HandlerImmunityCureStatus(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAbilityCureStatus(flow, monId, 5);
}

void HandlerImmunityActionEnd(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAbilityCureStatusCore(flow, monId, 5);
}

const BattleEventHandlerEntry *EventAddImmunity(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7cf8;
}

void HandlerWaterVeil(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    *work = HandlerCommonGuardStatus(flow, monId, 4);
}

void HandlerWaterVeilCureStatus(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAbilityCureStatus(flow, monId, 4);
}

void HandlerWaterVeilActionEnd(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAbilityCureStatusCore(flow, monId, 4);
}

const BattleEventHandlerEntry *EventAddWaterVeil(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7d20;
}

void HandlerOwnTempoStatus(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    *work = HandlerCommonGuardStatus(flow, monId, 6);
}

void HandlerOwnTempoAddStatusFailed(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAddStatusFailed(item, flow, monId, work, 0x165);
}

void HandlerOwnTempoCureStatus(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAbilityCureStatus(flow, monId, 6);
}

void HandlerOwnTempoActionEnd(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAbilityCureStatusCore(flow, monId, 6);
}

const BattleEventHandlerEntry *EventAddOwnTempo(u32 *priority) {
    *priority = 4;
    return data_ov167_021d7c38;
}

void HandlerOblivious(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    *work = HandlerCommonGuardStatus(flow, monId, 7);
}

void HandlerObliviousCureStatus(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAbilityCureStatus(flow, monId, 7);
}

void HandlerObliviousActionEnd(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAbilityCureStatusCore(flow, monId, 7);
}

void HandlerObliviousNoEffectCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerMessageParam *param;

    if (BattleEventVar_GetValue(4) == monId) {
        if ((u16)BattleEventVar_GetValue(0x12) == 0x1bd) {
            if (BattleEventVar_RewriteValue(0x40, 1)) {
                BattleHandler_PushRun(flow, 2, monId);
                param = BattleHandler_PushWork(flow, 4, monId);
                BattleHandler_StrSetup(&param->string, 2, 0xd2);
                BattleHandler_AddArg(&param->string, monId);
                BattleHandler_PopWork(flow, param);
                BattleHandler_PushRun(flow, 3, monId);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddOblivious(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7d48;
}

BOOL HandlerCommonGuardStatus(void *flow, u32 monId, u32 status) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(0x1d) == status) {
            return BattleEventVar_RewriteValue(0x41, 1);
        }
    }
    return FALSE;
}

void CommonAddStatusFailed(BattleEventItem *item, BtlServerFlow *flow, u32 monId, u32 *result, u16 message) {
    BattleHandlerMessageParam *work;

    if (BattleEventVar_GetValue(4) == monId) {
        if (*result == 1) {
            BattleHandler_PushRun(flow, 2, monId);
            work = BattleHandler_PushWork(flow, 4, monId);
            BattleHandler_StrSetup(&work->string, 2, message);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork(flow, work);
            BattleHandler_PushRun(flow, 3, monId);
            *result = 0;
        }
    }
}

void HandlerAddStatusFailedCommon(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonAddStatusFailed(item, flow, monId, work, 0xd2);
}

void CommonAbilityCureStatus(BtlServerFlow *flow, u8 monId, u32 status) {
    if (BattleEventVar_GetValue(2) == monId) {
        CommonAbilityCureStatusCore(flow, monId, status);
    }
}

void CommonAbilityCureStatusCore(BtlServerFlow *flow, u8 monId, u32 status) {
    BattleMon *mon;
    BattleHandlerCureConditionParam *work;

    mon = GetBattleMon(flow, monId);
    if (CheckCondition(mon, status)) {
        BattleHandler_PushRun(flow, 2, monId);
        work = BattleHandler_PushWork(flow, 0xb, monId);
        work->condition = status;
        work->count = 1;
        work->monIds[0] = monId;
        BattleHandler_PopWork(flow, work);
        BattleHandler_PushRun(flow, 3, monId);
    }
}

void HandlerDrizzle(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonWeatherChangeAbility(flow, monId, 2);
}

const BattleEventHandlerEntry *EventAddDrizzle(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7954;
}

void HandlerDrought(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonWeatherChangeAbility(flow, monId, 1);
}

const BattleEventHandlerEntry *EventAddDrought(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7964;
}

void HandlerSandStream(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonWeatherChangeAbility(flow, monId, 4);
}

const BattleEventHandlerEntry *EventAddSandStream(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7974;
}

void HandlerSnowWarning(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonWeatherChangeAbility(flow, monId, 3);
}

const BattleEventHandlerEntry *EventAddSnowWarning(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7984;
}

void CommonWeatherChangeAbility(BtlServerFlow *flow, u32 monId, u32 weather) {
    BattleHandlerChangeWeatherParam *work;

    if (BattleEventVar_GetValue(2) == monId) {
        work = BattleHandler_PushWork(flow, 0x1d, monId);
        work->popup = 1;
        work->weather = weather;
        work->duration = 0xff;
        BattleHandler_PopWork(flow, work);
    }
}

void HandlerAirLockMemberIn(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerChangeWeatherParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        param = BattleHandler_PushWork(flow, 0x1d, monId);
        param->popup = 1;
        param->weather = 0;
        param->notifyAirLock = 1;
        BattleHandler_StrSetup(&param->string, 1, 0x5e);
        BattleHandler_PopWork(flow, param);
    }
}

BOOL HandlerAirLockChangeWeather(void *context, void *flow, u32 monId) {
    return BattleEventVar_RewriteValue(0x41, 1);
}

const BattleEventHandlerEntry *EventAddAirLock(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7994;
}

void HandlerIceBody(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonWeatherRecoveryAbility(flow, monId, 3);
}

const BattleEventHandlerEntry *EventAddIceBody(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7644;
}

void HandlerRainDish(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonWeatherRecoveryAbility(flow, monId, 2);
}

const BattleEventHandlerEntry *EventAddRainDish(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76f4;
}

void CommonWeatherRecoveryAbility(BtlServerFlow *flow, u8 monId, u32 weather) {
    BattleMon *mon;
    BattleHandlerRecoverHPParam *work;

    if (BattleEventVar_GetValue(0x39) == weather) {
        if (BattleEventVar_GetValue(2) == monId) {
            mon = GetBattleMon(flow, monId);
            work = BattleHandler_PushWork(flow, 5, monId);
            work->popup = 1;
            work->targetIndex = monId;
            work->amount = DivideMaxHPZeroCheck(mon, 0x10);
            BattleHandler_PopWork(flow, work);
            BattleEventVar_RewriteValue(0x41, 1);
        }
    }
}

void HandlerSolarPowerWeather(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    BattleHandlerDamageParam *param;
    u16 amount;

    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x39) == 1) {
            mon = GetBattleMon(flow, monId);
            amount = DivideMaxHPZeroCheck(mon, 8);
            BattleHandler_PushRun(flow, 2, monId);
            param = BattleHandler_PushWork(flow, 7, monId);
            param->targetIndex = monId;
            param->amount = amount;
            BattleHandler_PopWork(flow, param);
            BattleHandler_PushRun(flow, 3, monId);
        }
    }
}

void HandlerSolarPowerPower(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (GetWeather(flow) == 1) {
            if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 2) {
                BattleEventVar_MulValue(0x35, FX32_CONST(1.5));
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddSolarPower(u32 *priority) {
    *priority = 2;
    return data_ov167_021d79b4;
}

void HandlerShieldDustStatus(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(3) != monId) {
            if (BattleEventVar_GetValue(0x1d) != 8) {
                BattleEventVar_RewriteValue(0x41, 1);
            }
        }
    }
}

void HandlerShieldDustRank(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(3) != monId) {
            BattleEventVar_RewriteValue(0x41, 1);
        }
    }
}

void HandlerShieldDustShrink(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

void HandlerShieldDustGuard(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x47, 1);
    }
}

void HandlerShieldDustGuardHitEnd(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (func_ov167_021cde38(monId)) {
        if (BattleEventVar_GetValue(5) == 1) {
            BattleEventVar_RewriteValue(0x47, 1);
        }
    }
}

const BattleEventHandlerEntry *EventAddShieldDust(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7d70;
}

void HandlerSereneGrace(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u32 chance;

    if (BattleEventVar_GetValue(3) == monId) {
        chance = BattleEventVar_GetValue(0x26);
        chance = (u16)(chance << 1);
        BattleEventVar_RewriteValue(0x26, chance);
    }
}

void HandlerSereneGraceShrink(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x45, 1);
    }
}

const BattleEventHandlerEntry *EventAddSereneGrace(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7b0c;
}

void HandlerHydration(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    BattleHandlerCureConditionParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        if (GetWeather(flow) == 2) {
            mon = GetBattleMon(flow, monId);
            if (GetBattleMonStatus(mon)) {
                BattleHandler_PushRun(flow, 2, monId);
                param = BattleHandler_PushWork(flow, 0xb, monId);
                param->condition = 0x24;
                param->monIds[0] = monId;
                param->count = 1;
                param->unk25 = 1;
                BattleHandler_PopWork(flow, param);
                BattleHandler_PushRun(flow, 3, monId);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddHydration(u32 *priority) {
    *priority = 1;
    return data_ov167_021d762c;
}

void HandlerShedSkin(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    BattleHandlerCureConditionParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetBattleMonStatus(mon)) {
            if (AbilityEvent_RollEffectChance(flow, 0x21)) {
                param = BattleHandler_PushWork(flow, 0xb, monId);
                param->popup = 1;
                param->unk25 = 1;
                param->condition = 0x24;
                param->monIds[0] = monId;
                param->count = 1;
                BattleHandler_PopWork(flow, param);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddShedSkin(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78fc;
}

void HandlerPoisonHeal(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    BattleHandlerRecoverHPParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x1d) == 5) {
            mon = GetBattleMon(flow, monId);
            BattleEventVar_RewriteValue(0x32, 0);
            param = BattleHandler_PushWork(flow, 5, monId);
            param->amount = DivideMaxHPZeroCheck(mon, 8);
            param->targetIndex = monId;
            param->popup = 1;
            BattleHandler_PopWork(flow, param);
        }
    }
}

const BattleEventHandlerEntry *EventAddPoisonHeal(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78f4;
}

void HandlerBattleArmor(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

const BattleEventHandlerEntry *EventAddBattleArmor(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78ec;
}

void HandlerSuperLuck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u32 level;

    if (BattleEventVar_GetValue(3) == monId) {
        level = BattleEventVar_GetValue(0x2c);
        level = (u8)(level + 1);
        BattleEventVar_RewriteValue(0x2c, level);
    }
}

const BattleEventHandlerEntry *EventAddSuperLuck(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78e4;
}

void HandlerAngerPoint(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    BattleHandlerStatChangeParam *param;
    s32 amount;

    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(0x46) == 0) {
            if (BattleEventVar_GetValue(0x45) != 0) {
                mon = GetBattleMon(flow, monId);
                if (func_ov167_021bb550(mon, 1) > 0) {
                    param = BattleHandler_PushWork(flow, 0xe, monId);
                    param->stat = 1;
                    amount = func_ov167_021bb550(mon, 1);
                    param->change = amount;
                    param->unk0e = 1;
                    param->count = 1;
                    param->monIds[0] = monId;
                    param->flag = 1;
                    param->popup = 1;
                    BattleHandler_StrSetup(&param->string, 2, 0x1e1);
                    BattleHandler_AddArg(&param->string, monId);
                    BattleHandler_PopWork(flow, param);
                }
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddAngerPoint(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78dc;
}

void HandlerPoisonPoint(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleCondition condition;

    condition = func_ov167_021bd52c(5);
    CommonContactStatusAbility(flow, monId, 5, condition, 0x1e);
}

// Function name from swan.
const BattleEventHandlerEntry *EventAddPoisonPoint(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78d4;
}

void HandlerStatic(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleCondition condition;

    condition = func_ov167_021bd52c(1);
    CommonContactStatusAbility(flow, monId, 1, condition, 0x1e);
}

// Function name from swan.
const BattleEventHandlerEntry *EventAddStatic(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78cc;
}

void HandlerFlameBody(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleCondition condition;

    condition = func_ov167_021bd52c(4);
    CommonContactStatusAbility(flow, monId, 4, condition, 0x1e);
}

// Function name from swan.
const BattleEventHandlerEntry *EventAddFlameBody(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78c4;
}

void HandlerCuteCharm(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    BattleMon *attacker;
    u8 sex;
    u8 attackerSex;
    BattleCondition condition;

    if (BattleEventVar_GetValue(4) == monId && BattleEventVar_GetValue(0x46) == 0 && !func_ov167_021abf14(flow)) {
        mon = GetBattleMon(flow, monId);
        attacker = GetBattleMon(flow, (u8)BattleEventVar_GetValue(3));
        sex = GetBattleMonStat(mon, 0x12);
        attackerSex = GetBattleMonStat(attacker, 0x12);
        if (sex != 2 && attackerSex != 2 && sex != attackerSex) {
            func_ov167_021bd5d4(7, mon, &condition);
            CommonContactStatusAbility(flow, monId, 7, condition, 30);
        }
    }
}

const BattleEventHandlerEntry *EventAddCuteCharm(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78bc;
}

void HandlerEffectSpore(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u32 rand;
    u32 status;
    BattleCondition condition;

    if (BattleEventVar_GetValue(4) == monId && BattleEventVar_GetValue(0x46) == 0) {
        rand = BattleRandom(30);
        if (rand > 20) {
            status = 5;
        } else if (rand > 10) {
            status = 1;
        } else {
            status = 2;
        }
        condition = func_ov167_021bd52c(status);
        CommonContactStatusAbility(flow, monId, status, condition, 30);
    }
}

const BattleEventHandlerEntry *EventAddEffectSpore(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78b4;
}

void CommonContactStatusAbility(BtlServerFlow *flow, u32 monId, u32 status, BattleCondition condition, u8 chance) {
    BattleHandlerAddConditionParam *param;

    if (BattleEventVar_GetValue(4) == monId && BattleEventVar_GetValue(0x46) == 0) {
        if (getMoveFlag(BattleEventVar_GetValue(0x12), 0) && AbilityEvent_RollEffectChance(flow, chance)) {
            param = BattleHandler_PushWork(flow, 0xc, monId);
            param->popup = 1;
            param->condition = status;
            param->value = condition;
            param->showFail = 0;
            param->targetIndex = BattleEventVar_GetValue(3);
            BattleHandler_PopWork(flow, param);
        }
    }
}

void HandlerRoughSkin(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 attackerId;
    BattleMon *attacker;
    BattleHandlerDamageParam *param;

    if (BattleEventVar_GetValue(4) == monId && BattleEventVar_GetValue(0x46) == 0) {
        if (getMoveFlag(BattleEventVar_GetValue(0x12), 0)) {
            attackerId = BattleEventVar_GetValue(3);
            attacker = GetBattleMon(flow, attackerId);
            if (!IsFainted(attacker)) {
                param = BattleHandler_PushWork(flow, 7, monId);
                param->popup = 1;
                param->targetIndex = attackerId;
                param->amount = DivideMaxHPZeroCheck(attacker, 8);
                BattleHandler_StrSetup(&param->string, 2, 0x1ae);
                BattleHandler_AddArg(&param->string, attackerId);
                BattleHandler_PopWork(flow, param);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddRoughSkin(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78ac;
}

void HandlerAftermath(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 attackerId;
    BattleMon *attacker;
    BattleHandlerDamageParam *param;

    if (BattleEventVar_GetValue(4) == monId && IsFainted(GetBattleMon(flow, monId))) {
        if (getMoveFlag(BattleEventVar_GetValue(0x12), 0)) {
            attackerId = BattleEventVar_GetValue(3);
            attacker = GetBattleMon(flow, attackerId);
            param = BattleHandler_PushWork(flow, 7, monId);
            param->popup = 1;
            param->targetIndex = attackerId;
            param->amount = DivideMaxHPZeroCheck(attacker, 4);
            param->checkSemi = 1;
            BattleHandler_StrSetup(&param->string, 2, 0x192);
            BattleHandler_AddArg(&param->string, attackerId);
            BattleHandler_PopWork(flow, param);
        }
    }
}

const BattleEventHandlerEntry *EventAddAftermath(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78a4;
}

void HandlerColorChange(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    u8 type;
    BattleHandlerChangeTypeParam *param;

    if (func_ov167_021cde38(monId) && !func_ov167_021abf14(flow)) {
        mon = GetBattleMon(flow, monId);
        if (!IsFainted(mon)) {
            type = BattleEventVar_GetValue(0x16);
            if (type != 0x11 && !DoesMonHaveType(mon, type)) {
                BattleHandler_PushRun(flow, 2, monId);
                param = BattleHandler_PushWork(flow, 0x14, monId);
                param->type = func_ov167_021ce530(type);
                param->monIndex = monId;
                BattleHandler_PopWork(flow, param);
                BattleHandler_PushRun(flow, 3, monId);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddColorChange(u32 *priority) {
    *priority = 1;
    return data_ov167_021d789c;
}

void HandlerSynchronize(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleConditionCont cont;
    u8 attackerId;
    BattleMon *mon;
    BattleHandlerAddConditionParam *param;
    u32 status;

    if (BattleEventVar_GetValue(4) == monId) {
        status = BattleEventVar_GetValue(0x1d);
        if (status == 5 || status == 1 || status == 4) {
            attackerId = BattleEventVar_GetValue(3);
            if (attackerId != 0x1f && attackerId != monId) {
                mon = GetBattleMon(flow, monId);
                cont.raw = BattleEventVar_GetValue(0x1e);
                BattleHandler_PushRun(flow, 2, monId);
                param = BattleHandler_PushWork(flow, 0xc, monId);
                param->targetIndex = attackerId;
                param->condition = status;
                if (status == 5 && Condition_IsBadlyPoisoned(cont)) {
                    param->value = cont;
                } else {
                    func_ov167_021bd5d4(status, mon, &param->value);
                }
                param->showFail = 1;
                BattleHandler_PopWork(flow, param);
                BattleHandler_PushRun(flow, 3, monId);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddSynchronize(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7894;
}

void HandlerRockHead(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

const BattleEventHandlerEntry *EventAddRockHead(u32 *priority) {
    *priority = 1;
    return data_ov167_021d788c;
}

void HandlerNormalize(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x16, 0);
    }
}

const BattleEventHandlerEntry *EventAddNormalize(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7884;
}

const BattleEventHandlerEntry *EventAddTrace(u32 *priority) {
    *priority = 1;
    return data_ov167_021d787c;
}

void HandlerTrace(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 enteringId;
    u32 targetId;
    u32 ability;
    u8 pos;
    u8 myPos;
    u32 count;
    u8 numCandidates;
    u8 i;
    BattleMon *mon;
    u8 mons[5];
    u8 candidates[3];

    enteringId = BattleEventVar_GetValue(2);
    targetId = 0x1f;
    ability = 0;
    if (enteringId == monId) {
        myPos = func_ov167_021ab840(flow, monId);
        count = HandlerGetAlivePartyCount(flow, myPos | 0x100, mons);
        numCandidates = 0;
        for (i = 0; i < count; i++) {
            if (!func_ov169_0689cacc(GetBattleMonStat(GetBattleMon(flow, mons[i]), 0x10))) {
                candidates[numCandidates++] = mons[i];
            }
        }
        if (numCandidates != 0) {
            i = (numCandidates == 1) ? 0 : BattleRandom(numCandidates);
            mon = GetBattleMon(flow, candidates[i]);
            ability = GetBattleMonStat(mon, 0x10);
            targetId = GetMonID(mon);
        } else {
            work[0] = 1;
        }
    } else if (!IsAllyMonID(enteringId, monId) && work[0] == 1) {
        pos = func_ov167_021abb50(flow, enteringId);
        myPos = func_ov167_021ab840(flow, monId);
        if (pos != 6 && (func_ov167_021abc9c(flow) != 2 || IsAdjacentOpponent(myPos, pos))) {
            count = GetBattleMonStat(GetBattleMon(flow, enteringId), 0x10);
            if (!func_ov169_0689cacc(count)) {
                ability = count;
                targetId = enteringId;
            }
        }
    }
    if (ability != 0 && monId != 0x1f) {
        BattleHandlerAbilityChangeParam *param;

        param = BattleHandler_PushWork(flow, 0x1f, monId);
        param->targetIndex = monId;
        param->ability = ability;
        param->unk08 = 1;
        param->popup = 1;
        BattleHandler_StrSetup(&param->string, 2, 0x17d);
        BattleHandler_AddArg(&param->string, targetId);
        BattleHandler_AddArg(&param->string, param->ability);
        BattleHandler_PopWork(flow, param);
    }
}

void HandlerNaturalCure(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerCureConditionParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        param = BattleHandler_PushWork(flow, 0xb, monId);
        param->condition = 0x24;
        param->count = 1;
        param->monIds[0] = monId;
        param->useString = 1;
        BattleHandler_PopWork(flow, param);
    }
}

const BattleEventHandlerEntry *EventAddNaturalCure(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7874;
}

void HandlerDownload(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 count;
    u16 defense;
    u16 spDefense;
    u8 i;
    BattleMon *mon;
    u32 stat;
    BattleHandlerStatChangeParam *param;
    u8 mons[4];

    if (BattleEventVar_GetValue(2) == monId) {
        count = func_ov167_021ab894(flow, monId, mons);
        if (count != 0) {
            defense = 0;
            spDefense = 0;
            for (i = 0; i < count; i++) {
                mon = GetBattleMon(flow, mons[i]);
                defense += (u16)GetBattleMonStat(mon, 9);
                spDefense += (u16)GetBattleMonStat(mon, 0xb);
            }
            if (defense >= spDefense) {
                stat = 3;
            } else {
                stat = 1;
            }
            param = BattleHandler_PushWork(flow, 0xe, monId);
            param->popup = 1;
            param->count = 1;
            param->monIds[0] = monId;
            param->stat = stat;
            param->change = 1;
            BattleHandler_PopWork(flow, param);
        }
    }
}

const BattleEventHandlerEntry *EventAddDownload(u32 *priority) {
    *priority = 2;
    return data_ov167_021d79f4;
}

void HandlerForewarn(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    ForewarnEntry *entries;
    u8 count;
    u8 moveCount;
    u8 i;
    u8 j;
    u16 move;
    u8 numEntries;
    u32 best;
    u32 power;
    BattleHandlerMessageParam *param;
    u8 mons[4];

    if (BattleEventVar_GetValue(2) == monId) {
        count = func_ov167_021ab894(flow, monId, mons);
        best = 0;
        numEntries = 0;
        entries = (ForewarnEntry *)func_ov167_021abc60(flow, 0xc);
        for (i = 0; i < count; i++) {
            mon = GetBattleMon(flow, mons[i]);
            moveCount = GetBattleMonMoveCount(mon);
            for (j = 0; j < moveCount; j++) {
                move = MoveGetID(mon, j);
                if (PML_MoveGetCategory(move) != 0) {
                    power = (u8)PML_MoveGetBasePower(move);
                    if (power == 1) {
                        if (PML_MoveGetQuality(move) == 9) {
                            power = 150;
                        } else if (move == 0x44 || move == 0xf3 || move == 0x170) {
                            power = 120;
                        } else {
                            power = 80;
                        }
                    }
                } else {
                    power = 1;
                }
                if (power >= best) {
                    if (power > best) {
                        best = power;
                        numEntries = 0;
                    }
                    entries[numEntries].monId = GetMonID(mon);
                    entries[numEntries].move = move;
                    numEntries++;
                }
            }
        }
        if (numEntries != 0) {
            i = BattleRandom(numEntries);
            BattleHandler_PushRun(flow, 2, monId);
            param = BattleHandler_PushWork(flow, 4, monId);
            BattleHandler_StrSetup(&param->string, 2, 0x1b1);
            BattleHandler_AddArg(&param->string, entries[i].monId);
            BattleHandler_AddArg(&param->string, entries[i].move);
            BattleHandler_PopWork(flow, param);
            BattleHandler_PushRun(flow, 3, monId);
        }
    }
}

const BattleEventHandlerEntry *EventAddForewarn(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a04;
}

void HandlerAnticipation(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u32 count;
    BattleMon *mon;
    u8 i;
    BattleHandlerMessageParam *param;
    u8 mons[4];

    if (BattleEventVar_GetValue(2) == monId) {
        count = func_ov167_021ab894(flow, monId, mons);
        mon = GetBattleMon(flow, monId);
        for (i = 0; i < count; i++) {
            if (CheckAnticipationMon(mon, GetBattleMon(flow, mons[i]))) {
                break;
            }
        }
        if (i != count) {
            BattleHandler_PushRun(flow, 2, monId);
            param = BattleHandler_PushWork(flow, 4, monId);
            BattleHandler_StrSetup(&param->string, 2, 0x1b4);
            BattleHandler_AddArg(&param->string, monId);
            BattleHandler_PopWork(flow, param);
            BattleHandler_PushRun(flow, 3, monId);
        }
    }
}

BOOL CheckAnticipationMon(BattleMon *mon, BattleMon *opponent) {
    PokeTypePair types;
    u32 moveCount;
    u8 i;
    u16 move;

    types = GetPokeType(mon);
    moveCount = GetBattleMonMoveCount(opponent);
    for (i = 0; i < moveCount; i++) {
        move = MoveGetID(opponent, i);
        if (PML_MoveGetQuality(move) == 9) {
            return TRUE;
        }
        if (PML_MoveIsDamaging(move) && func_ov167_021bd1b0(PML_MoveGetType(move), types) > 3) {
            return TRUE;
        }
    }
    return FALSE;
}

const BattleEventHandlerEntry *EventAddAnticipation(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a24;
}

void HandlerFrisk(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 count;
    u8 numItems;
    u8 i;
    BattleMon *mon;
    BattleHandlerMessageParam *param;
    u16 items[4];
    u8 mons[4];

    if (BattleEventVar_GetValue(2) == monId) {
        count = func_ov167_021ab894(flow, monId, mons);
        numItems = 0;
        for (i = 0; i < count; i++) {
            mon = GetBattleMon(flow, mons[i]);
            items[numItems] = GetBattleMonHeldItem(mon);
            if (items[numItems] != 0) {
                numItems++;
            }
        }
        if (numItems != 0) {
            i = BattleRandom(numItems);
            BattleHandler_PushRun(flow, 2, monId);
            param = BattleHandler_PushWork(flow, 4, monId);
            BattleHandler_StrSetup(&param->string, 2, 0x1b7);
            BattleHandler_AddArg(&param->string, monId);
            BattleHandler_AddArg(&param->string, items[i]);
            BattleHandler_PopWork(flow, param);
            BattleHandler_PushRun(flow, 3, monId);
        }
    }
}

const BattleEventHandlerEntry *EventAddFrisk(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a34;
}

const BattleEventHandlerEntry *EventAddSturdy(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7b84;
}

void HandlerSturdyOneshotCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerMessageParam *param;

    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_RewriteValue(0x41, 1)) {
            BattleHandler_PushRun(flow, 2, monId);
            param = BattleHandler_PushWork(flow, 4, monId);
            BattleHandler_StrSetup(&param->string, 2, 0xd2);
            BattleHandler_AddArg(&param->string, monId);
            BattleHandler_PopWork(flow, param);
            BattleHandler_PushRun(flow, 3, monId);
        }
    }
}

void HandlerSturdyEndureCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (IsMonFullHP(GetBattleMon(flow, monId))) {
            *work = BattleEventVar_RewriteValue(0x3a, 4);
        } else {
            *work = 0;
        }
    }
}

void HandlerSturdySurvive(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerMessageParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        if (*work) {
            BattleHandler_PushRun(flow, 2, monId);
            param = BattleHandler_PushWork(flow, 4, monId);
            BattleHandler_StrSetup(&param->string, 2, 0x202);
            BattleHandler_AddArg(&param->string, monId);
            BattleHandler_PopWork(flow, param);
            BattleHandler_PushRun(flow, 3, monId);
            *work = 0;
        }
    }
}

void HandlerUnawareHitRank(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x28, 6);
    } else if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x27, 6);
    }
}

void HandlerUnawareAttackRank(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x51, 1);
    }
}

void HandlerUnawareDefenseRank(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x51, 1);
    }
}

const BattleEventHandlerEntry *EventAddUnaware(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7b9c;
}

void HandlerHeatproofPower(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(0x16) == 9) {
            BattleEventVar_MulValue(0x31, FX32_CONST(0.5));
        }
    }
}

void HandlerHeatproofStatus(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    s32 damage;

    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x1d) == 4) {
            damage = BattleEventVar_GetValue(0x32);
            damage = func_ov167_021bd31c(damage / 2, 1);
            BattleEventVar_RewriteValue(0x32, damage);
        }
    }
}

const BattleEventHandlerEntry *EventAddHeatproof(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a54;
}

BOOL CommonDamageRecoverCheck(BtlServerFlow *flow, u32 monId, u32 type) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(3) != monId) {
            if (BattleEventVar_GetValue(0x16) == type) {
                return BattleEventVar_RewriteValue(0x40, 1);
            }
        }
    }
    return FALSE;
}

void CommonTypeRecoverHP(BtlServerFlow *flow, u8 monId, u32 divisor) {
    BattleMon *mon;
    BattleHandlerRecoverHPParam *work;
    BattleHandlerMessageParam *message;

    mon = GetBattleMon(flow, monId);
    if (!IsMonFullHP(mon)) {
        work = BattleHandler_PushWork(flow, 5, monId);
        work->targetIndex = monId;
        work->amount = DivideMaxHPZeroCheck(mon, divisor);
        work->popup = 1;
        BattleHandler_StrSetup(&work->string, 2, 0x183);
        BattleHandler_AddArg(&work->string, monId);
        BattleHandler_PopWork(flow, work);
    } else {
        message = BattleHandler_PushWork(flow, 4, monId);
        BattleHandler_StrSetup(&message->string, 2, 0xd2);
        BattleHandler_AddArg(&message->string, monId);
        message->popup = 1;
        BattleHandler_PopWork(flow, message);
    }
    BattleEventVar_RewriteValue(0x51, 1);
}

void CommonTypeNoEffectRankUp(BtlServerFlow *flow, u8 monId, u32 stat, u32 amount) {
    BattleMon *mon;
    BattleHandlerStatChangeParam *work;
    BattleHandlerMessageParam *message;

    mon = GetBattleMon(flow, monId);
    if (IsStatChangeValid(mon, stat, amount)) {
        work = BattleHandler_PushWork(flow, 0xe, monId);
        work->count = 1;
        work->monIds[0] = monId;
        work->unk0e = 1;
        work->stat = stat;
        work->change = amount;
        work->popup = 1;
        BattleHandler_PopWork(flow, work);
    } else {
        message = BattleHandler_PushWork(flow, 4, monId);
        BattleHandler_StrSetup(&message->string, 2, 0xd2);
        BattleHandler_AddArg(&message->string, monId);
        message->popup = 1;
        BattleHandler_PopWork(flow, message);
    }
}

void HandlerDrySkinWeather(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    BattleHandlerDamageParam *damage;
    BattleHandlerRecoverHPParam *recover;
    u8 weather;

    if (BattleEventVar_GetValue(2) == monId) {
        mon = GetBattleMon(flow, monId);
        weather = BattleEventVar_GetValue(0x39);
        if (weather == 1) {
            BattleHandler_PushRun(flow, 2, monId);
            damage = BattleHandler_PushWork(flow, 7, monId);
            damage->targetIndex = monId;
            damage->amount = DivideMaxHPZeroCheck(mon, 8);
            BattleHandler_PopWork(flow, damage);
            BattleHandler_PushRun(flow, 3, monId);
        } else if (weather == 2) {
            recover = BattleHandler_PushWork(flow, 5, monId);
            recover->popup = 1;
            recover->targetIndex = monId;
            recover->amount = DivideMaxHPZeroCheck(mon, 8);
            BattleHandler_PopWork(flow, recover);
        }
    }
}

void HandlerDrySkinDamageRecover(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(0x16) == 9) {
            BattleEventVar_MulValue(0x31, FX32_CONST(1.25));
        }
    }
}

void HandlerDrySkinCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (CommonDamageRecoverCheck(flow, monId, 10)) {
        CommonTypeRecoverHP(flow, monId, 4);
    }
}

const BattleEventHandlerEntry *EventAddDrySkin(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7bb4;
}

void HandlerWaterAbsorbCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (CommonDamageRecoverCheck(flow, monId, 10)) {
        CommonTypeRecoverHP(flow, monId, 4);
    }
}

const BattleEventHandlerEntry *EventAddWaterAbsorb(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77b4;
}

void HandlerVoltAbsorbCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (CommonDamageRecoverCheck(flow, monId, 12)) {
        CommonTypeRecoverHP(flow, monId, 4);
    }
}

const BattleEventHandlerEntry *EventAddVoltAbsorb(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7824;
}

const BattleEventHandlerEntry *EventAddMotorDrive(u32 *priority) {
    *priority = 1;
    return data_ov167_021d781c;
}

void HandlerMotorDriveCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (CommonDamageRecoverCheck(flow, monId, 12)) {
        CommonTypeNoEffectRankUp(flow, monId, 5, 1);
    }
}

void HandlerScrappy(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (BattleEventVar_GetValue(0x15) == 7) {
            BattleEventVar_RewriteValue(0x4b, 1);
        }
    }
}

const BattleEventHandlerEntry *EventAddScrappy(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7814;
}

void HandlerSoundproof(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerMessageParam *param;
    u16 move;

    if (BattleEventVar_GetValue(4) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (getMoveFlag(move, 8)) {
            if (BattleEventVar_RewriteValue(0x40, 1)) {
                BattleHandler_PushRun(flow, 2, monId);
                param = BattleHandler_PushWork(flow, 4, monId);
                BattleHandler_StrSetup(&param->string, 2, 0xd2);
                BattleHandler_AddArg(&param->string, monId);
                BattleHandler_PopWork(flow, param);
                BattleHandler_PushRun(flow, 3, monId);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddSoundproof(u32 *priority) {
    *priority = 1;
    return data_ov167_021d780c;
}

void HandlerLevitate(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x51) == 0) {
            *work = BattleEventVar_RewriteValue(0x51, 1);
        }
    }
}

void HandlerLevitateAddImmunity(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerMessageParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        if (*work) {
            param = BattleHandler_PushWork(flow, 4, monId);
            param->popup = 1;
            BattleHandler_StrSetup(&param->string, 2, 0xd2);
            BattleHandler_AddArg(&param->string, monId);
            BattleHandler_PopWork(flow, param);
            *work = 0;
        }
    }
}

void HandlerLevitateTurnCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        *work = 0;
    }
}

const BattleEventHandlerEntry *EventAddLevitate(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7a94;
}

void HandlerWonderGuard(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerMessageParam *param;
    u16 move;
    u32 run;

    if (BattleEventVar_GetValue(4) == monId) {
        run = 3;
        if (BattleEventVar_GetValue(run) != monId) {
            GetBattleMon(flow, monId);
            move = BattleEventVar_GetValue(0x12);
            if (PML_MoveIsDamaging(move)) {
                if (move != 0xa5) {
                    if ((s32)BattleEventVar_GetValue(0x38) <= 3) {
                        if (BattleEventVar_RewriteValue(0x40, 1)) {
                            BattleHandler_PushRun(flow, 2, monId);
                            param = BattleHandler_PushWork(flow, 4, monId);
                            BattleHandler_StrSetup(&param->string, 2, 0xd2);
                            BattleHandler_AddArg(&param->string, monId);
                            BattleHandler_PopWork(flow, param);
                            BattleHandler_PushRun(flow, run, monId);
                        }
                    }
                }
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddWonderGuard(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76e4;
}

void HandlerTruant(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (work[0] != 0) {
            work[1] = BattleEventVar_RewriteValue(0x22, 0x13);
            work[0] = 0;
        } else {
            work[0] = 1;
        }
    }
}

void HandlerTruantGet(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetTurnFlag(GetBattleMon(flow, monId), 0)) {
            *work = 1;
        }
    }
}

void HandlerTruantFailed(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerMessageParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        if (work[1] != 0) {
            param = BattleHandler_PushWork(flow, 4, monId);
            param->popup = 1;
            BattleHandler_StrSetup(&param->string, 2, 0x1bd);
            BattleHandler_AddArg(&param->string, monId);
            BattleHandler_PopWork(flow, param);
            work[1] = 0;
        }
    }
}

void HandlerTruantEndAction(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0xc) == 7) {
            *work = 0;
        }
    }
}

const BattleEventHandlerEntry *EventAddTruant(u32 *priority) {
    *priority = 4;
    return data_ov167_021d7c18;
}

void HandlerDamp(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u16 move;
    u32 key;

    move = BattleEventVar_GetValue(0x12);
    work[0] = 0;
    if (move == 0x99 || move == 0x78) {
        key = 0x22;
        if (BattleEventVar_GetValue(key) == 0) {
            work[0] = BattleEventVar_RewriteValue(key, 0x13);
            work[1] = move;
        }
    }
}

void HandlerDampEffective(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 target;
    BattleHandlerMessageParam *param;

    if (work[0]) {
        target = BattleEventVar_GetValue(2);
        param = BattleHandler_PushWork(flow, 4, monId);
        param->popup = 1;
        BattleHandler_StrSetup(&param->string, 2, 0x389);
        BattleHandler_AddArg(&param->string, target);
        BattleHandler_AddArg(&param->string, work[1]);
        BattleHandler_PopWork(flow, param);
        work[0] = 0;
    }
}

void HandlerDampStart(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleEventItem_AttachSkipCheckHandler(item, HandlerDampSkipCheck);
}

void func_ov167_021c06cc(BattleEventItem *item) {
    BattleEventItem_DetachSkipCheckHandler(item);
}

void HandlerDampEnd(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventItem_DetachSkipCheckHandler(item);
    }
}

BOOL HandlerDampSkipCheck(BattleEventItem *item, BtlServerFlow *flow, u32 factorType, u32 event, u16 subId, u8 monId) {
    if (factorType == 4) {
        if (subId == 0x6a) {
            return TRUE;

        }
    }
    return FALSE;
}

const BattleEventHandlerEntry *EventAddDamp(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7c58;
}

void HandlerFlashFirePower(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (GetAdditionalConditionFlag(GetBattleMon(flow, monId), 0xd)) {
            if (BattleEventVar_GetValue(0x16) == 9) {
                BattleEventVar_MulValue(0x35, FX32_CONST(1.5));
            }
        }
    }
}

void HandlerFlashFireRemove(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerFlagParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        if (GetAdditionalConditionFlag(GetBattleMon(flow, monId), 0xd)) {
            param = BattleHandler_PushWork(flow, 0x18, monId);
            param->monIndex = monId;
            param->flag = 0xd;
            BattleHandler_PopWork(flow, param);
        }
    }
}

void HandlerFlashFireCheckNoEffect(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerMessageParam *message;
    BattleHandlerFlagParam *param;

    if (CommonDamageRecoverCheck(flow, monId, 9)) {
        BattleHandler_PushRun(flow, 2, monId);
        if (!GetAdditionalConditionFlag(GetBattleMon(flow, monId), 0xd)) {
            message = BattleHandler_PushWork(flow, 4, monId);
            BattleHandler_StrSetup(&message->string, 2, 0x1ab);
            BattleHandler_AddArg(&message->string, monId);
            BattleHandler_PopWork(flow, message);
            param = BattleHandler_PushWork(flow, 0x17, monId);
            param->monIndex = monId;
            param->flag = 0xd;
            BattleHandler_PopWork(flow, param);
        } else {
            message = BattleHandler_PushWork(flow, 4, monId);
            BattleHandler_StrSetup(&message->string, 2, 0xd2);
            BattleHandler_AddArg(&message->string, monId);
            BattleHandler_PopWork(flow, message);
        }
        BattleHandler_PushRun(flow, 3, monId);
    }
}

const BattleEventHandlerEntry *EventAddFlashFire(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7aac;
}

void HandlerBadDreams(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    u8 count;
    u8 i;
    BOOL popup;
    u8 mons[4];
    BattleHandlerDamageParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        popup = FALSE;
        count = HandlerGetAlivePartyCount(flow, func_ov167_021ab840(flow, monId) | 0x100, mons);
        for (i = 0; i < count; i++) {
            mon = GetBattleMon(flow, mons[i]);
            if (CheckCondition(mon, 2)) {
                if (!popup) {
                    popup = TRUE;
                    BattleHandler_PushRun(flow, 2, monId);
                }
                param = BattleHandler_PushWork(flow, 7, monId);
                param->targetIndex = mons[i];
                param->amount = DivideMaxHPZeroCheck(mon, 8);
                BattleHandler_StrSetup(&param->string, 2, 0x1e4);
                BattleHandler_AddArg(&param->string, mons[i]);
                BattleHandler_PopWork(flow, param);
            }
        }
        if (popup) {
            BattleHandler_PushRun(flow, 3, monId);
        }
    }
}

const BattleEventHandlerEntry *EventAddBadDreams(u32 *priority) {
    *priority = 1;
    return data_ov167_021d786c;
}

void HandlerRunAway(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonRunCalcSkip(item, flow, monId, work);
}

void HandlerRunAwayMessage(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerMessageParam *param;

    if (CommonCheckRunMessage(item, flow, monId)) {
        param = BattleHandler_PushWork(flow, 4, monId);
        param->popup = 1;
        BattleHandler_StrSetup(&param->string, 1, 0x48);
        BattleHandler_AddSoundEffect(&param->string, 0x56a);
        BattleHandler_PopWork(flow, param);
    }
}

const BattleEventHandlerEntry *EventAddRunAway(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7934;
}

void HandlerMoldBreakerMemberIn(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u16 message;
    BattleHandlerMessageParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        switch (BattleEventItem_GetSubID(item)) {
        case 0xa3:
            message = 0x1f9;
            break;
        case 0xa4:
            message = 0x1f6;
            break;
        default:
            message = 0x1ba;
            break;
        }
        BattleHandler_PushRun(flow, 2, monId);
        param = BattleHandler_PushWork(flow, 4, monId);
        BattleHandler_StrSetup(&param->string, 2, message);
        BattleHandler_AddArg(&param->string, monId);
        BattleHandler_PopWork(flow, param);
        BattleHandler_PushRun(flow, 3, monId);
    }
}

BOOL func_ov167_021c09d0(BattleEventItem *item, BtlServerFlow *flow, u32 factorType, u32 event, u16 subId, u8 monId) {
    if (factorType == 4 && func_ov169_0689cb38(subId)) {
        return TRUE;
    }
    return FALSE;
}

void HandlerMoldBreakerStart(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (*work == 0) {
            BattleEventItem_AttachSkipCheckHandler(item, func_ov167_021c09d0);
            *work = 1;
        }
    }
}

void HandlerMoldBreakerEnd(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (*work == 1) {
            BattleEventItem_DetachSkipCheckHandler(item);
            *work = 0;
        }
    }
}

void HandlerMoldBreakerConfirm(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (*work == 1) {
            BattleEventItem_DetachSkipCheckHandler(item);
            *work = 0;
        }
    }
}

const BattleEventHandlerEntry *EventAddMoldBreaker(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7ca8;
}

void HandlerForecastMemberOnField(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u32 weather;

    weather = GetWeather(flow);
    CommonForecastFormChange(flow, monId, weather);
    *work = 1;
}

void HandlerForecastGetAbility(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        HandlerForecastMemberOnField(item, flow, monId, work);
    }
}

void HandlerForecastWeather(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u32 weather;

    if (*work) {
        weather = GetWeather(flow);
        CommonForecastFormChange(flow, monId, weather);
    }
}

void HandlerForecastAirLock(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (*work) {
        CommonForecastOff(item, flow, monId);
    }
}

void HandlerForecastChangeAbility(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u32 subId;

    if (BattleEventVar_GetValue(2) == monId) {
        subId = BattleEventVar_GetValue(0x10);
        if (subId != BattleEventItem_GetSubID(item)) {
            CommonForecastOff(item, flow, monId);
        }
    }
}

void HandlerForecastAbilityOff(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        CommonForecastOff(item, flow, monId);
    }
}

void CommonForecastOff(BattleEventItem *item, BtlServerFlow *flow, u8 monId) {
    BattleMon *mon;
    BattleHandlerChangeFormParam *work;

    mon = GetBattleMon(flow, monId);
    if (GetBattleMonSpecies(mon) == 0x15f) {
        if (GetBattleMonStat(mon, 0x13) != 0) {
            work = BattleHandler_PushWork(flow, 0x39, monId);
            work->monIndex = monId;
            work->form = 0;
            BattleHandler_StrSetup(&work->string, 2, 0xde);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork(flow, work);
        }
    }
}

void CommonForecastFormChange(BtlServerFlow *flow, u8 monId, u32 weather) {
    BattleMon *mon;
    BattleHandlerChangeFormParam *work;
    u8 currentForm;
    u32 newForm;

    mon = GetBattleMon(flow, monId);
    if (GetBattleMonSpecies(mon) == 0x15f) {
        currentForm = GetBattleMonStat(mon, 0x13);
        switch (weather) {
        case 0:
            newForm = 0;
            break;
        case 1:
            newForm = 1;
            break;
        case 2:
            newForm = 2;
            break;
        case 3:
            newForm = 3;
            break;
        default:
            newForm = 0;
            break;
        }
        if (newForm != currentForm) {
            work = BattleHandler_PushWork(flow, 0x39, monId);
            work->popup = 1;
            work->monIndex = monId;
            work->form = newForm;
            BattleHandler_StrSetup(&work->string, 2, 0xde);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork(flow, work);
        }
    }
}

const BattleEventHandlerEntry *EventAddForecast(u32 *priority) {
    *priority = 9;
    return data_ov167_021d7e58;
}

const BattleEventHandlerEntry *EventAddStormDrain(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7adc;
}

void HandlerStormDrain(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    *work = CommonMoveTargetChangeToMe(flow, monId, work, 10);
}

void HandlerStormDrainCheckNoEffect(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (CommonDamageRecoverCheck(flow, monId, 10)) {
        CommonTypeNoEffectRankUp(flow, monId, 3, 1);
    }
}

const BattleEventHandlerEntry *EventAddLightningRod(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7af4;
}

void HandlerLightningRod(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    *work = CommonMoveTargetChangeToMe(flow, monId, work, 12);
}

void HandlerLightningRodStart(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerMessageParam *param;

    if (*work) {
        if (func_ov167_021cde38(monId)) {
            param = BattleHandler_PushWork(flow, 4, monId);
            param->popup = 1;
            BattleHandler_StrSetup(&param->string, 2, 7 << 6);
            BattleHandler_AddArg(&param->string, monId);
            BattleHandler_PopWork(flow, param);
        }
        *work = 0;
    }
}

void HandlerLightningRodCheckNoEffect(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (CommonDamageRecoverCheck(flow, monId, 12)) {
        CommonTypeNoEffectRankUp(flow, monId, 3, 1);
    }
}

BOOL CommonMoveTargetChangeToMe(BtlServerFlow *flow, u8 monId, s32 *work, u32 type) {
    u8 attackerId;
    u16 move;
    u8 targetId;

    attackerId = BattleEventVar_GetValue(3);
    if (attackerId != monId && BattleEventVar_GetValue(0x16) == type) {
        move = BattleEventVar_GetValue(0x12);
        if (!func_ov167_021abdd0(flow, attackerId, monId, move) && !func_ov169_0689ca74(move)) {
            targetId = BattleEventVar_GetValue(4);
            if (BattleEventVar_RewriteValue(4, monId) && targetId != monId) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

void HandlerSuctionCups(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerMessageParam *param;

    if (BattleEventVar_GetValue(4) == monId && BattleEventVar_RewriteValue(0x41, 1)) {
        param = BattleHandler_PushWork(flow, 4, monId);
        param->popup = 1;
        BattleHandler_StrSetup(&param->string, 2, 0x1c6);
        BattleHandler_AddArg(&param->string, monId);
        BattleHandler_PopWork(flow, param);
    }
}

const BattleEventHandlerEntry *EventAddSuctionCups(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7674;
}

void HandlerLiquidOoze(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u16 amount;
    BattleHandlerDamageParam *param;

    if (BattleEventVar_GetValue(4) == monId) {
        amount = BattleEventVar_GetValue(0x20);
        BattleEventVar_RewriteValue(0x20, 0);
        if (amount != 0) {
            param = BattleHandler_PushWork(flow, 7, monId);
            param->popup = 1;
            param->targetIndex = BattleEventVar_GetValue(3);
            param->amount = amount;
            BattleHandler_StrSetup(&param->string, 2, 0x1c9);
            BattleHandler_AddArg(&param->string, param->targetIndex);
            BattleHandler_PopWork(flow, param);
        }
    }
}

void HandlerLiquidOozeFainted(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventItem_ConvertToIsolated(item);
    }
}

const BattleEventHandlerEntry *EventAddLiquidOoze(u32 *priority) {
    *priority = 2;
    return data_ov167_021d79a4;
}

BOOL HandlerKlutzSkipCheck(BattleEventItem *item, BtlServerFlow *flow, u32 factorType, u32 event, u16 subId, u8 monId) {
    u32 i;

    if (CheckCondition(GetBattleMon(flow, monId), 0x10)) {
        return FALSE;
    }
    if (factorType == 5 && HandlerGetMainModule(item) == monId) {
        for (i = 0; i < 13; i++) {
            if (subId == data_ov167_021d7bfc[i]) {
                return FALSE;
            }
        }
        return TRUE;
    }
    return FALSE;
}

void HandlerKlutzMemberInPrev(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (work[0] == 0) {
        BattleEventItem_AttachSkipCheckHandler(item, HandlerKlutzSkipCheck);
        work[0] = 1;
    }
}

void HandlerKlutzGetAbility(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        HandlerKlutzMemberInPrev(item, flow, monId, work);
    }
}

void HandlerKlutzPreChange(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventItem_DetachSkipCheckHandler(item);
    }
}

void HandlerKlutzGastroAcid(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerCheckHeldItemParam *param;

    if (BattleEventVar_GetValue(2) == monId && GetBattleMonHeldItem(GetBattleMon(flow, monId)) != 0) {
        param = BattleHandler_PushWork(flow, 0x21, monId);
        param->monIndex = monId;
        BattleHandler_PopWork(flow, param);
    }
}

void HandlerKlutzCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u16 move;

    if (BattleEventVar_GetValue(2) == monId) {
        move = BattleEventVar_GetValue(0x12);
        work[2] = 0;
        if (move == 0x16b && BattleEventVar_GetValue(2) == monId) {
            work[2] = BattleEventVar_RewriteValue(0x22, 0x13);
        }
    }
}

void HandlerKlutzFail(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 attackerId;
    BattleHandlerMessageParam *param;

    if (BattleEventVar_GetValue(2) == monId && work[2] != 0) {
        attackerId = BattleEventVar_GetValue(2);
        param = BattleHandler_PushWork(flow, 4, monId);
        param->popup = 1;
        BattleHandler_StrSetup(&param->string, 2, 0x389);
        BattleHandler_AddArg(&param->string, monId);
        BattleHandler_AddArg(&param->string, BattleEventVar_GetValue(0x12));
        BattleHandler_PopWork(flow, param);
        work[2] = 0;
    }
}

const BattleEventHandlerEntry *EventAddKlutz(u32 *priority) {
    *priority = 7;
    return data_ov167_021d7e20;
}

void HandlerStickyHoldNoEffect(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u16 move;
    BattleHandlerMessageParam *param;

    if (BattleEventVar_GetValue(4) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if ((move == 0x10f || move == 0x19f) && BattleEventVar_RewriteValue(0x40, 1)) {
            param = BattleHandler_PushWork(flow, 4, monId);
            param->popup = 1;
            BattleHandler_StrSetup(&param->string, 2, 0xd2);
            BattleHandler_AddArg(&param->string, monId);
            BattleHandler_PopWork(flow, param);
        }
    }
}

void HandlerStickyHold(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId && BattleEventVar_GetValue(0x2d) == 0) {
        work[0] = BattleEventVar_RewriteValue(0x41, 1);
    }
}

void HandlerStickyHoldReaction(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerMessageParam *param;

    if (BattleEventVar_GetValue(2) == monId && work[0] != 0) {
        param = BattleHandler_PushWork(flow, 4, monId);
        param->popup = 1;
        BattleHandler_StrSetup(&param->string, 2, 0x1ed);
        BattleHandler_AddArg(&param->string, monId);
        BattleHandler_PopWork(flow, param);
        work[0] = 0;
    }
}

const BattleEventHandlerEntry *EventAddStickyHold(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7b24;
}

const BattleEventHandlerEntry *EventAddPressure(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7b3c;
}

void HandlerPressureMemberIn(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerMessageParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        BattleHandler_PushRun(flow, 2, monId);
        param = BattleHandler_PushWork(flow, 4, monId);
        BattleHandler_StrSetup(&param->string, 2, 0x1e7);
        BattleHandler_AddArg(&param->string, monId);
        BattleHandler_PopWork(flow, param);
        BattleHandler_PushRun(flow, 3, monId);
    }
}

void HandlerPressure(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BOOL apply;
    u16 move;
    u8 volume;

    if (!IsAllyMonID(BattleEventVar_GetValue(3), monId)) {
        apply = FALSE;
        if (func_ov167_021cde38(monId)) {
            apply = TRUE;
        } else {
            move = BattleEventVar_GetValue(0x12);
            if (PML_MoveGetQuality(move) == 10) {
                apply = TRUE;
            } else if (func_ov169_0689ca64(move)) {
                apply = TRUE;
            }
        }
        if (apply) {
            volume = BattleEventVar_GetValue(0x20) + 1;
            BattleEventVar_RewriteValue(0x20, volume);
        }
    }
}

const BattleEventHandlerEntry *EventAddMagicGuard(u32 *priority) {
    *priority = 1;
    return data_ov167_021d777c;
}

void HandlerMagicGuard(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x51, 0);
    }
}

const BattleEventHandlerEntry *EventAddStench(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7774;
}

void HandlerStench(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 chance;

    if (BattleEventVar_GetValue(3) == monId) {
        chance = BattleEventVar_GetValue(0x25);
        if (chance == 0) {
            BattleEventVar_RewriteValue(0x26, 10);
        }
    }
}

const BattleEventHandlerEntry *EventAddShadowTag(u32 *priority) {
    *priority = 1;
    return data_ov167_021d776c;
}

void HandlerShadowTag(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 count;
    u8 i;
    u8 mons[4];

    if (!IsAllyMonID(BattleEventVar_GetValue(2), monId)) {
        count = HandlerGetAlivePartyCount(flow, func_ov167_021ab840(flow, monId) | 0x100, mons);
        for (i = 0; i < count; i++) {
            if (GetBattleMonStat(GetBattleMon(flow, mons[i]), 0x11) == 0x17) {
                return;
            }
        }
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

const BattleEventHandlerEntry *EventAddArenaTrap(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7764;
}

void HandlerArenaTrap(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 count;
    u8 i;
    u8 mons[4];

    if (!IsAllyMonID(BattleEventVar_GetValue(2), monId)) {
        count = HandlerGetAlivePartyCount(flow, func_ov167_021ab840(flow, monId) | 0x100, mons);
        for (i = 0; i < count; i++) {
            if (!func_ov167_021abd74(flow, mons[i])) {
                BattleEventVar_RewriteValue(0x41, 1);
                return;
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddMagnetPull(u32 *priority) {
    *priority = 1;
    return data_ov167_021d775c;
}

void HandlerMagnetPull(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 count;
    u8 i;
    u8 mons[4];

    if (!IsAllyMonID(BattleEventVar_GetValue(2), monId)) {
        count = HandlerGetAlivePartyCount(flow, func_ov167_021ab840(flow, monId) | 0x100, mons);
        for (i = 0; i < count; i++) {
            if (DoesMonHaveType(GetBattleMon(flow, mons[i]), 8)) {
                BattleEventVar_RewriteValue(0x41, 1);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddUnburden(u32 *priority) {
    *priority = 2;
    return data_ov167_021d79e4;
}

void HandlerUnburdenBeforeItemSet(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId && BattleEventVar_GetValue(0x2d) == 0) {
        if (GetBattleMonHeldItem(GetBattleMon(flow, monId)) != 0) {
            work[0] = 1;
        }
    }
}

void HandlerUnburdenSpeed(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId && work[0] == 1) {
        if (GetBattleMonHeldItem(GetBattleMon(flow, monId)) == 0) {
            BattleEventVar_MulValue(0x35, 0x2000);
        }
    }
}

const BattleEventHandlerEntry *EventAddPickup(u32 *priority) {
    *priority = 1;
    return data_ov167_021d774c;
}

void HandlerPickup(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 pos;
    PickupWork *wk;
    u8 numCandidates;
    u8 i;
    BattleMon *mon;
    u8 targetId;
    u16 consumed;
    BattleHandlerSetItemParam *param;

    if (BattleEventVar_GetValue(2) == monId && GetBattleMonHeldItem(GetBattleMon(flow, monId)) == 0) {
        pos = func_ov167_021ab840(flow, monId);
        wk = (PickupWork *)func_ov167_021abc60(flow, 0xe);
        wk->count = HandlerGetAlivePartyCount(flow, (2 << 8) | pos, wk->mons);
        numCandidates = 0;
        wk->numCandidates = 0;
        for (i = 0; i < wk->count; i++) {
            mon = GetBattleMon(flow, wk->mons[i]);
            if (GetTurnFlag(mon, 8) && GetConsumedItem(mon) != 0) {
                wk->candidates[numCandidates++] = GetMonID(mon);
            }
        }
        if (numCandidates != 0) {
            i = BattleRandom(numCandidates);
            targetId = wk->candidates[i];
            consumed = GetConsumedItem(GetBattleMon(flow, targetId));
            if (consumed != 0) {
                param = BattleHandler_PushWork(flow, 0x20, monId);
                param->popup = 1;
                param->targetIndex = monId;
                param->item = consumed;
                param->clearOtherConsumed = 1;
                param->otherIndex = targetId;
                BattleHandler_StrSetup(&param->string, 2, 0x1ea);
                BattleHandler_AddArg(&param->string, monId);
                BattleHandler_AddArg(&param->string, consumed);
                BattleHandler_PopWork(flow, param);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddPickpocket(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7744;
}

void HandlerPickpocket(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 attackerId;
    BattleMon *mon;
    BattleMon *attacker;
    BattleHandlerSwapItemParam *param;

    if (func_ov167_021cde38(monId)) {
        attackerId = BattleEventVar_GetValue(3);
        if (!func_ov167_021cdf28(flow, monId, attackerId) && getMoveFlag(BattleEventVar_GetValue(0x12), 0)) {
            mon = GetBattleMon(flow, monId);
            attacker = GetBattleMon(flow, attackerId);
            if (GetBattleMonHeldItem(mon) == 0 && GetBattleMonHeldItem(attacker) != 0) {
                param = BattleHandler_PushWork(flow, 0x24, monId);
                param->popup = 1;
                param->otherIndex = attackerId;
                BattleHandler_StrSetup(&param->firstString, 2, 0x1cc);
                BattleHandler_AddArg(&param->firstString, attackerId);
                BattleHandler_AddArg(&param->firstString, GetBattleMonHeldItem(attacker));
                BattleHandler_PopWork(flow, param);
            }
        }
    }
}

void HandlerCursedBody(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 attackerId;
    BattleMon *attacker;
    u16 move;
    u8 turns;
    BattleHandlerAddConditionParam *param;

    if (BattleEventVar_GetValue(4) == monId && BattleEventVar_GetValue(0x46) == 0 && !func_ov167_021abf14(flow)) {
        attackerId = BattleEventVar_GetValue(3);
        attacker = GetBattleMon(flow, attackerId);
        if (!CheckCondition(attacker, 0xd)) {
            move = BattleEventVar_GetValue(0x14);
            if (move != 0 && move != 0xa5 && !func_ov169_0689ca54(move) && AbilityEvent_RollEffectChance(flow, 30)) {
                turns = 4;
                if (GetTurnFlag(attacker, 1)) {
                    turns++;
                }
                param = BattleHandler_PushWork(flow, 0xc, monId);
                param->condition = 0xd;
                param->value = AddTurnCondition(turns, move);
                param->targetIndex = attackerId;
                param->popup = 1;
                BattleHandler_PopWork(flow, param);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddCursedBody(u32 *priority) {
    *priority = 1;
    return data_ov167_021d779c;
}

void HandlerWeakArmor(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    BOOL apply;
    BattleHandlerStatChangeParam *param;

    if (BattleEventVar_GetValue(4) == monId && BattleEventVar_GetValue(0x1a) == 1 && BattleEventVar_GetValue(0x46) == 0) {
        mon = GetBattleMon(flow, monId);
        apply = FALSE;
        if (IsStatChangeValid(mon, 2, -1) || IsStatChangeValid(mon, 5, 1)) {
            apply = TRUE;
        }
        if (apply && !IsFainted(mon)) {
            BattleHandler_PushRun(flow, 2, monId);
            param = BattleHandler_PushWork(flow, 0xe, monId);
            param->count = 1;
            param->monIds[0] = monId;
            param->unk0e = 1;
            param->stat = 2;
            param->change = -1;
            BattleHandler_PopWork(flow, param);
            param = BattleHandler_PushWork(flow, 0xe, monId);
            param->count = 1;
            param->monIds[0] = monId;
            param->unk0e = 1;
            param->stat = 5;
            param->change = 1;
            BattleHandler_PopWork(flow, param);
            BattleHandler_PushRun(flow, 3, monId);
        }
    }
}

const BattleEventHandlerEntry *EventAddWeakArmor(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7854;
}

void HandlerSheerForcePower(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId && IsAffectedBySheerForce(BattleEventVar_GetValue(0x12))) {
        BattleEventVar_MulValue(0x31, 0x14cd);
    }
}

void HandlerSheerForceCheckFail(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId && IsAffectedBySheerForce(BattleEventVar_GetValue(0x12))) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

void HandlerSheerForceShrinkCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

void HandlerSheerForceHitCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId && IsAffectedBySheerForce(BattleEventVar_GetValue(0x12))) {
        BattleEventVar_RewriteValue(0x48, 1);
    }
}

const BattleEventHandlerEntry *EventAddSheerForce(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7d98;
}

BOOL IsAffectedBySheerForce(u16 move) {
    s32 quality;
    u32 count;
    u32 i;
    s32 stage;

    quality = PML_MoveGetQuality(move);
    if (PML_MoveGetParam(move, 10) != 0) {
        return TRUE;
    }
    switch (quality) {
    case 4:
        if (PML_MoveGetParam(move, 0xb) == 8) {
            return FALSE;
        }
    case 6:
        return TRUE;
    case 7:
        count = PML_MoveGetStatChangeStat(move);
        for (i = 0; i < count; i++) {
            PML_MoveGetStatChangeStage(move, i, &stage);
            if (stage < 0) {
                return FALSE;
            }
        }
        return TRUE;
    }
    if (move == 0x122) {
        return TRUE;
    }
    return FALSE;
}

void HandlerDefiant(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 attackerId;
    BattleHandlerStatChangeParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        attackerId = BattleEventVar_GetValue(3);
        if (!IsAllyMonID(monId, attackerId) && (s32)BattleEventVar_GetValue(0x20) < 0) {
            param = BattleHandler_PushWork(flow, 0xe, monId);
            param->popup = 1;
            param->stat = 1;
            param->change = 2;
            param->unk0e = 1;
            param->count = 1;
            param->monIds[0] = monId;
            BattleHandler_PopWork(flow, param);
        }
    }
}

const BattleEventHandlerEntry *EventAddDefiant(u32 *priority) {
    *priority = 1;
    return data_ov167_021d770c;
}

void HandlerDefeatist(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    u32 hp;

    if (BattleEventVar_GetValue(3) == monId) {
        mon = GetBattleMon(flow, monId);
        hp = GetBattleMonStat(mon, 0xd);
        if (hp <= DivideMaxHp(mon, 2)) {
            BattleEventVar_MulValue(0x35, 0x800);
        }
    }
}

const BattleEventHandlerEntry *EventAddDefeatist(u32 *priority) {
    *priority = 1;
    return data_ov167_021d782c;
}

void HandlerMultiscale(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId && IsMonFullHP(GetBattleMon(flow, monId))) {
        BattleEventVar_MulValue(0x35, 0x800);
    }
}

const BattleEventHandlerEntry *EventAddMultiscale(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7714;
}

void HandlerFriendGuard(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 targetId;

    targetId = BattleEventVar_GetValue(4);
    if (targetId != monId && IsAllyMonID(monId, targetId)) {
        BattleEventVar_MulValue(0x35, 0xc00);
    }
}

const BattleEventHandlerEntry *EventAddFriendGuard(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7804;
}

void HandlerHealer(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 count;
    u8 i;
    BattleHandlerCureConditionParam *param;
    u8 mons[4];

    if (BattleEventVar_GetValue(2) == monId) {
        count = HandlerGetAlivePartyCount(flow, (2 << 9) | func_ov167_021abb50(flow, monId), mons);
        for (i = 0; i < count; i++) {
            if (mons[i] != monId && GetBattleMonStatus(GetBattleMon(flow, mons[i])) != 0 && AbilityEvent_RollEffectChance(flow, 30)) {
                param = BattleHandler_PushWork(flow, 0xb, monId);
                param->popup = 1;
                param->unk25 = 1;
                param->count = 1;
                param->monIds[0] = mons[i];
                param->condition = 0x24;
                BattleHandler_PopWork(flow, param);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddHealer(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77fc;
}

void HandlerToxicBoost(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId && CheckCondition(GetBattleMon(flow, monId), 5) && BattleEventVar_GetValue(0x1a) == 1) {
        BattleEventVar_MulValue(0x31, 0x1800);
    }
}

const BattleEventHandlerEntry *EventAddToxicBoost(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77ec;
}

void HandlerFlareBoost(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId && CheckCondition(GetBattleMon(flow, monId), 4) && BattleEventVar_GetValue(0x1a) == 2) {
        BattleEventVar_MulValue(0x31, 0x1800);
    }
}

const BattleEventHandlerEntry *EventAddFlareBoost(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76a4;
}

void HandlerTelepathy(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 attackerId;
    BattleHandlerMessageParam *param;

    if (BattleEventVar_GetValue(4) == monId) {
        attackerId = BattleEventVar_GetValue(3);
        if (IsAllyMonID(monId, attackerId) && monId != attackerId && PML_MoveIsDamaging(BattleEventVar_GetValue(0x12)) &&
            BattleEventVar_RewriteValue(0x40, 1)) {
            param = BattleHandler_PushWork(flow, 4, monId);
            param->popup = 1;
            BattleHandler_StrSetup(&param->string, 2, 0x1d5);
            BattleHandler_AddArg(&param->string, monId);
            BattleHandler_PopWork(flow, param);
        }
    }
}

const BattleEventHandlerEntry *EventAddTelepathy(u32 *priority) {
    *priority = 1;
    return data_ov167_021d766c;
}

void HandlerMoody(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u32 i;
    u8 numPairs;
    u8 numUp;
    u8 upStat;
    BattleHandlerStatChangeParam *param;
    u8 downStat;
    u32 j;
    BattleMon *mon;
    u8 numDown;
    MoodyWork *wk;
    u16 pair;

    if (BattleEventVar_GetValue(2) == monId) {
        wk = (MoodyWork *)func_ov167_021abc60(flow, 0xb6);
        mon = GetBattleMon(flow, monId);
        numDown = 0;
        numUp = 0;
        for (i = 0; i < 7; i++) {
            if (IsStatChangeValid(mon, i + 1, 1)) {
                wk->up[numUp++] = i + 1;
            }
            if (IsStatChangeValid(mon, i + 1, -1)) {
                wk->down[numDown++] = i + 1;
            }
        }
        downStat = 0;
        upStat = 0;
        if (numUp == 0 && numDown != 0) {
            downStat = wk->down[BattleRandom(numDown)];
        } else if (numUp != 0 && numDown == 0) {
            upStat = wk->up[BattleRandom(numUp)];
        } else if (numUp != 0 && numDown != 0) {
            numPairs = 0;
            for (i = 0; i < numUp; i++) {
                for (j = 0; j < numDown; j++) {
                    if (wk->up[i] != wk->down[j]) {
                        wk->pairs[numPairs++] = (wk->up[i] << 8) | wk->down[j];
                        if (numPairs >= 0x54) {
                            break;
                        }
                    }
                }
            }
            pair = wk->pairs[BattleRandom(numPairs)];
            upStat = pair >> 8;
            downStat = pair;
        }
        BattleHandler_PushRun(flow, 2, monId);
        if (upStat != 0) {
            param = BattleHandler_PushWork(flow, 0xe, monId);
            param->count = 1;
            param->monIds[0] = monId;
            param->stat = upStat;
            param->change = 2;
            BattleHandler_PopWork(flow, param);
        }
        if (downStat != 0) {
            param = BattleHandler_PushWork(flow, 0xe, monId);
            param->count = 1;
            param->monIds[0] = monId;
            param->stat = downStat;
            param->change = -1;
            BattleHandler_PopWork(flow, param);
        }
        BattleHandler_PushRun(flow, 3, monId);
    }
}

const BattleEventHandlerEntry *EventAddMoody(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76dc;
}

void HandlerOvercoat(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId && (s32)BattleEventVar_GetValue(0x32) > 0) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

const BattleEventHandlerEntry *EventAddOvercoat(u32 *priority) {
    *priority = 1;
    return data_ov167_021d767c;
}

void HandlerPoisonTouch(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerAddConditionParam *param;

    if (BattleEventVar_GetValue(3) == monId && BattleEventVar_GetValue(0x46) == 0 && BattleEventVar_GetValue(0x47) == 0 &&
        getMoveFlag(BattleEventVar_GetValue(0x12), 0) && AbilityEvent_RollEffectChance(flow, 30)) {
        param = BattleHandler_PushWork(flow, 0xc, monId);
        param->popup = 1;
        param->targetIndex = BattleEventVar_GetValue(4);
        param->condition = 5;
        param->value = func_ov167_021bd52c(5);
        BattleHandler_StrSetup(&param->string, 2, 0x1d8);
        BattleHandler_AddArg(&param->string, param->targetIndex);
        BattleHandler_PopWork(flow, param);
    }
}

const BattleEventHandlerEntry *EventAddPoisonTouch(u32 *priority) {
    *priority = numHandlersWithHandlerPri(4, 1);
    return data_ov167_021d7684;
}

void HandlerRegenerator(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    u32 amount;
    u32 missing;
    BattleHandlerChangeHPParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        mon = GetBattleMon(flow, monId);
        if (!IsFainted(mon) && !IsMonFullHP(mon)) {
            amount = DivideMaxHPZeroCheck(mon, 3);
            missing = GetBattleMonStat(mon, 0xe) - GetBattleMonStat(mon, 0xd);
            if (amount > missing) {
                amount = missing;
            }
            param = BattleHandler_PushWork(flow, 8, monId);
            param->monIds[0] = monId;
            param->hpChanges[0] = amount;
            param->count = 1;
            param->suppress = 1;
            BattleHandler_PopWork(flow, param);
        }
    }
}

// Function name from swan.
const BattleEventHandlerEntry *EventAddRegenerator(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7784;
}

const BattleEventHandlerEntry *EventAddBigPecks(u32 *priority) {
    *priority = 2;
    return data_ov167_021d79c4;
}

void HandlerBigPecksCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonStatDropGuardCheck(flow, monId, work, 2);
}

void HandlerBigPecksGuard(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonStatDropGuardFixed(flow, monId, work, 0xcc);
}

const BattleEventHandlerEntry *EventAddSandRush(u32 *priority) {
    *priority = 2;
    return data_ov167_021d79d4;
}

void HandlerSandRush(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId && GetWeather(flow) == 4) {
        BattleEventVar_MulValue(0x35, 0x2000);
    }
}

const BattleEventHandlerEntry *EventAddWonderSkin(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7754;
}

void HandlerWonderSkin(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId && BattleEventVar_GetValue(0x1a) == 0 && BattleEventVar_GetValue(0x2b) > 50) {
        BattleEventVar_RewriteValue(0x2b, 50);
    }
}

const BattleEventHandlerEntry *EventAddAnalytic(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76ac;
}

void HandlerAnalytic(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId && !func_ov169_0689ca54(BattleEventVar_GetValue(0x12)) && IsMonLastInTurnOrder(flow, monId)) {
        BattleEventVar_MulValue(0x31, 0x14cd);
    }
}

const BattleEventHandlerEntry *EventAddSandForce(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a14;
}

void HandlerSandForce(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId && GetWeather(flow) == 4) {
        switch ((u8)BattleEventVar_GetValue(0x16)) {
        case 4:
        case 5:
        case 8:
            BattleEventVar_MulValue(0x31, 0x14cd);
            break;
        }
    }
}

void HandlerZenMode(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    u8 form;
    BattleHandlerChangeFormParam *param;
    u16 message;

    mon = GetBattleMon(flow, monId);
    if (GetBattleMonSpecies(mon) == 0x22b) {
        form = GetBattleMonStat(mon, 0xd) <= DivideMaxHp(mon, 2) ? 1 : 0;
        if (form != GetBattleMonStat(mon, 0x13)) {
            param = BattleHandler_PushWork(flow, 0x39, monId);
            param->popup = 1;
            param->monIndex = monId;
            param->form = form;
            message = form == 1 ? 0xb9 : 0xba;
            BattleHandler_StrSetup(&param->string, 1, message);
            BattleHandler_PopWork(flow, param);
        }
    }
}

void HandlerZenModeGastroAcid(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerChangeFormParam *param;

    if (BattleEventVar_GetValue(2) == monId && GetBattleMonSpecies(GetBattleMon(flow, monId)) == 0x22b) {
        param = BattleHandler_PushWork(flow, 0x39, monId);
        param->monIndex = monId;
        param->form = 0;
        BattleHandler_StrSetup(&param->string, 1, 0xba);
        BattleHandler_AddArg(&param->string, monId);
        BattleHandler_PopWork(flow, param);
    }
}

const BattleEventHandlerEntry *EventAddZenMode(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7bcc;
}

BOOL HandlerInfiltratorSkipCheck(BattleEventItem *item, BtlServerFlow *flow, u32 factorType, u32 event, u16 subId, u8 monId) {
    u8 side;

    if (factorType == 2) {
        side = GetSideFromMonID(HandlerGetMainModule(item));
        if (side != monId && subId <= 3) {
            return TRUE;
        }
    }
    return FALSE;
}

void HandlerInfiltratorStart(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventItem_AttachSkipCheckHandler(item, HandlerInfiltratorSkipCheck);
    }
}

void HandlerInfiltratorEnd(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventItem_DetachSkipCheckHandler(item);
    }
}

const BattleEventHandlerEntry *EventAddInfiltrator(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a84;
}

const BattleEventHandlerEntry *EventAddMoxie(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77f4;
}

void HandlerMoxie(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u32 count;
    u32 i;
    BattleHandlerStatChangeParam *param;

    if (BattleEventVar_GetValue(3) == monId) {
        count = BattleEventVar_GetValue(5);
        for (i = 0; i < count; i++) {
            if (IsFainted(GetBattleMon(flow, (u8)BattleEventVar_GetValue(6 + i)))) {
                param = BattleHandler_PushWork(flow, 0xe, monId);
                param->popup = 1;
                param->count = 1;
                param->monIds[0] = monId;
                param->stat = 1;
                param->change = 1;
                BattleHandler_PopWork(flow, param);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddJustified(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7654;
}

void HandlerJustified(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleHandlerStatChangeParam *param;

    if (BattleEventVar_GetValue(4) == monId && BattleEventVar_GetValue(0x46) == 0 && BattleEventVar_GetValue(0x16) == 0x10) {
        param = BattleHandler_PushWork(flow, 0xe, monId);
        param->popup = 1;
        param->count = 1;
        param->monIds[0] = monId;
        param->stat = 1;
        param->change = 1;
        BattleHandler_PopWork(flow, param);
    }
}

const BattleEventHandlerEntry *EventAddRattled(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7634;
}

void HandlerRattled(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 type;
    BattleHandlerStatChangeParam *param;

    if (BattleEventVar_GetValue(4) == monId && BattleEventVar_GetValue(0x46) == 0) {
        type = BattleEventVar_GetValue(0x16);
        if (type == 0x10 || type == 6 || type == 7) {
            param = BattleHandler_PushWork(flow, 0xe, monId);
            param->popup = 1;
            param->count = 1;
            param->monIds[0] = monId;
            param->stat = 5;
            param->change = 1;
            BattleHandler_PopWork(flow, param);
        }
    }
}

const BattleEventHandlerEntry *EventAddMummy(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76fc;
}

void HandlerMummy(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 attackerId;
    BattleHandlerAbilityChangeParam *param;

    if (BattleEventVar_GetValue(4) == monId && BattleEventVar_GetValue(0x46) == 0 && !func_ov167_021abf14(flow) &&
        getMoveFlag(BattleEventVar_GetValue(0x12), 0)) {
        attackerId = BattleEventVar_GetValue(3);
        if (GetBattleMonStat(GetBattleMon(flow, attackerId), 0x10) != 0x98) {
            param = BattleHandler_PushWork(flow, 0x1f, monId);
            param->ability = 0x98;
            param->targetIndex = attackerId;
            BattleHandler_StrSetup(&param->string, 2, 0x1cf);
            BattleHandler_AddArg(&param->string, param->targetIndex);
            if (!IsAllyMonID(monId, attackerId)) {
                param->popup = 1;
            }
            BattleHandler_PopWork(flow, param);
        }
    }
}

void HandlerSapSipperCheckNoEffect(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (CommonDamageRecoverCheck(flow, monId, 0xb)) {
        CommonTypeNoEffectRankUp(flow, monId, 1, 1);
    }
}

const BattleEventHandlerEntry *EventAddSapSipper(u32 *priority) {
    *priority = 1;
    return data_ov167_021d764c;
}

void HandlerPrankster(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 priority;

    if (BattleEventVar_GetValue(3) == monId && PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 0) {
        priority = BattleEventVar_GetValue(0x18);
        BattleEventVar_RewriteValue(0x18, priority + 1);
    }
}

const BattleEventHandlerEntry *EventAddPrankster(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76b4;
}

void HandlerMagicBounceCheck(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonMagicCoatCheckMoveEffect(item, flow, monId, work);
}

void HandlerMagicBounceWait(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    CommonMagicCoatWait(item, flow, monId, work);
}

void HandlerMagicBounceReflect(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId && BattleEventVar_RewriteValue(0x51, 1)) {
        BattleHandler_PushRun(flow, 2, monId);
        func_ov167_021ce044(item, flow, monId, work);
        BattleHandler_PushRun(flow, 3, monId);
    }
}

const BattleEventHandlerEntry *EventAddMagicBounce(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7b54;
}

void HandlerHarvest(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    BattleMon *mon;
    u16 berry;
    BattleHandlerSetItemParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        mon = GetBattleMon(flow, monId);
        berry = GetConsumedItem(mon);
        if (berry != 0 && PML_ItemIsBerry(berry) && GetBattleMonHeldItem(mon) == 0) {
            if (GetWeather(flow) == 1 || AbilityEvent_RollEffectChance(flow, 50)) {
                param = BattleHandler_PushWork(flow, 0x20, monId);
                param->popup = 1;
                param->item = berry;
                param->targetIndex = monId;
                param->clearConsumed = 1;
                BattleHandler_StrSetup(&param->string, 2, 0x1db);
                BattleHandler_AddArg(&param->string, monId);
                BattleHandler_AddArg(&param->string, berry);
                BattleHandler_PopWork(flow, param);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddHarvest(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77ac;
}

const BattleEventHandlerEntry *EventAddHeavyMetal(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7704;
}

void HandlerHeavyMetal(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_MulValue(0x35, 0x2000);
    }
}

const BattleEventHandlerEntry *EventAddLightMetal(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7664;
}

void HandlerLightMetal(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_MulValue(0x35, 0x800);
    }
}

void HandlerContrary(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        work[0] = BattleEventVar_RewriteValue(0x20, -BattleEventVar_GetValue(0x20));
    }
}

const BattleEventHandlerEntry *EventAddContrary(u32 *priority) {
    *priority = 1;
    return data_ov167_021d778c;
}

void HandlerUnnerveMemberIn(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        HandlerUnnerveRotationIn(item, flow, monId, work);
    }
}

void HandlerUnnerveRotationIn(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 opposingSide;
    BattleHandlerMessageParam *param;

    if (work[0] == 0) {
        opposingSide = func_ov167_0219d338(GetSideFromMonID(monId));
        BattleHandler_PushRun(flow, 2, monId);
        param = BattleHandler_PushWork(flow, 4, monId);
        BattleHandler_StrSetup(&param->string, 1, 0xb0);
        BattleHandler_AddArg(&param->string, opposingSide);
        BattleHandler_PopWork(flow, param);
        BattleHandler_PushRun(flow, 3, monId);
        BattleEventItem_AttachSkipCheckHandler(item, HandlerUnnerveSkipCheck);
        work[0] = 1;
    }
}

BOOL HandlerUnnerveSkipCheck(BattleEventItem *item, BtlServerFlow *flow, u32 factorType, u32 event, u16 subId, u8 monId) {
    if (factorType == 5 && !IsAllyMonID(HandlerGetMainModule(item), monId) && PML_ItemIsBerry(subId)) {
        return TRUE;
    }
    return FALSE;
}

const BattleEventHandlerEntry *EventAddUnnerve(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7b6c;
}

void HandlerImposter(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 pos;
    u8 targetId;
    BattleMon *target;
    BattleHandlerTransformParam *param;

    if (BattleEventVar_GetValue(2) == monId) {
        pos = func_ov167_021abb50(flow, monId);
        targetId = func_ov167_021abb60(flow, func_ov167_0219c4c8(func_ov167_021abc9c(flow), pos));
        target = GetBattleMon(flow, targetId);
        if (!IsFainted(GetBattleMon(flow, monId)) && !IsFainted(target)) {
            param = BattleHandler_PushWork(flow, 0x33, monId);
            param->popup = 1;
            param->targetIndex = targetId;
            BattleHandler_StrSetup(&param->string, 2, 0x284);
            BattleHandler_AddArg(&param->string, monId);
            BattleHandler_AddArg(&param->string, param->targetIndex);
            BattleHandler_PopWork(flow, param);
        }
    }
}

const BattleEventHandlerEntry *EventAddImposter(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77d4;
}

const BattleEventHandlerEntry *EventAddIllusion(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7be4;
}

void HandlerIllusionDamage(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(4) == monId && BattleEventVar_GetValue(0x46) == 0) {
        CommonIllusionBreak(item, flow, monId);
    }
}

void HandlerIllusionGastroAcid(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(2) == monId) {
        CommonIllusionBreak(item, flow, monId);
    }
}

void HandlerIllusionChangeAbility(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    if (BattleEventVar_GetValue(0x10) != BattleEventItem_GetSubID(item) && BattleEventVar_GetValue(2) == monId) {
        CommonIllusionBreak(item, flow, monId);
    }
}

void CommonIllusionBreak(BattleEventItem *item, BtlServerFlow *flow, u8 monId) {
    BattleHandlerIllusionBreakParam *param;

    if (IsIllusionEnabled(GetBattleMon(flow, monId))) {
        param = BattleHandler_PushWork(flow, 0x34, monId);
        param->monIndex = monId;
        BattleHandler_StrSetup(&param->string, 2, 0x1de);
        BattleHandler_AddArg(&param->string, monId);
        BattleHandler_PopWork(flow, param);
    }
}

const BattleEventHandlerEntry *EventAddVictoryStar(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77e4;
}

void HandlerVictoryStar(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work) {
    u8 attackerId;

    attackerId = BattleEventVar_GetValue(3);
    if (IsAllyMonID(monId, attackerId)) {
        BattleEventVar_MulValue(0x35, 0x119a);
    }
}
