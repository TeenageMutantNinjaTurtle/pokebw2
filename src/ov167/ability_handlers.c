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

BOOL IsStatChangeValid(BattleMon *mon, u32 stat, s32 change);

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

struct IntimidateWork {
    u32 flags;
    u32 command;
    u8 unk08[4];
    s8 target;
    u8 unk0d;
    u8 active;
    u8 count;
    u8 mons[6];
};

struct SteadfastWork {
    u32 flags;
    u32 count;
    u8 unk08[4];
    u8 active;
    u8 unk0d;
    u8 unk0e;
    u8 amount;
    u8 monId;
};

struct SpeedBoostWork {
    u32 flags;
    u32 count;
    u8 unk08[4];
    u8 active;
    u8 unk0d[2];
    u8 amount;
    u8 monId;
};

struct FlowerGiftFormWork {
    u32 flags;
    u8 monId;
    u8 form;
    u8 reserved[2];
    BattleHandlerString string;
};

struct StatDropGuardMessageWork {
    u32 flags;
    BattleHandlerString string;
};

struct ObliviousMessageWork {
    u32 flags;
    BattleHandlerString string;
};

struct StatusFailedMessageWork {
    u32 flags;
    BattleHandlerString string;
};

struct AbilityCureStatusWork {
    u32 flags;
    u32 status;
    u8 monId;
    u8 reserved[0xb];
    u8 active;
};

struct WeatherChangeAbilityWork {
    u32 flags;
    u8 weather;
    u8 duration;
};

struct AirLockWeatherWork {
    u32 flags;
    u8 weather;
    u8 duration;
    u8 active;
    u8 reserved;
    BattleHandlerString string;
};

struct WeatherRecoveryWork {
    u32 flags;
    u16 amount;
    u8 monId;
};

struct SolarPowerWork {
    u32 flags;
    u16 amount;
    u8 monId;
};

struct HydrationWork {
    u32 flags;
    u32 status;
    u8 monId;
    u8 reserved[0xb];
    u8 active;
};

struct ShedSkinWork {
    u32 flags;
    u32 status;
    u8 monId;
    u8 reserved[0xb];
    u8 active;
};

struct PoisonHealWork {
    u32 flags;
    u16 amount;
    u8 monId;
};

struct AngerPointWork {
    u32 flags;
    u32 stage;
    u8 reserved08[4];
    u8 amount;
    u8 active;
    u8 showPopup;
    u8 showMessage;
    u8 monId;
    u8 reserved11[7];
    BattleHandlerString string;
};

// Function names from swan.
extern const BattleEventHandlerEntry data_ov167_021d78d4[];

extern const BattleEventHandlerEntry data_ov167_021d78cc[];

extern const BattleEventHandlerEntry data_ov167_021d78c4[];

u32 func_ov167_021bd52c(u32 status);

void CommonContactStatusAbility(void *flow, u32 monId, u32 status, u32 value, u32 chance);

// Function names from swan.
struct NaturalCureWork {
    u32 flags;
    u32 status;
    u8 monId;
    u8 reserved09[0xb];
    u8 active;
    u8 showPopup;
};

// Function names from swan.

struct SturdyMessageWork {
    u32 flags;
    BattleHandlerString string;
};

s32 func_ov167_021bd31c(s32 value, s32 minimum);

struct TypeRecoverWork {
    u32 flags;
    u16 amount;
    u8 monId;
    u8 reserved07;
    BattleHandlerString string;
};

struct TypeRecoverMessageWork {
    u32 flags;
    BattleHandlerString string;
};

struct TypeRankUpWork {
    u32 flags;
    u32 stat;
    u8 reserved08[4];
    u8 amount;
    u8 reserved0d;
    u8 active;
    u8 showPopup;
    u8 monId;
};

struct TypeRankMessageWork {
    u32 flags;
    BattleHandlerString string;
};

struct DrySkinWeatherWork {
    u32 flags;
    u16 amount;
    u8 monId;
};

struct SoundproofMessageWork {
    u32 flags;
    BattleHandlerString string;
};

struct LevitateImmunityWork {
    u32 flags;
    BattleHandlerString string;
};

struct WonderGuardMessageWork {
    u32 flags;
    BattleHandlerString string;
};

struct TruantMessageWork {
    u32 flags;
    BattleHandlerString string;
};

struct DampMessageWork {
    u32 flags;
    BattleHandlerString string;
};

// Function names from swan.
struct FlashFireRemoveWork {
    u32 flags;
    u32 condition;
    u8 monId;
};

struct FlashFireMessageWork {
    u32 flags;
    BattleHandlerString string;
};

// Function names from swan.
struct RunAwayMessageWork {
    u32 flags;
    BattleHandlerString string;
};

struct ForecastFormWork {
    u32 flags;
    u8 monId;
    u8 form;
    u8 reserved06[2];
    BattleHandlerString string;
};

// Function names from swan.
struct LightningRodMessageWork {
    u32 flags;
    BattleHandlerString string;
};

// Function names from swan.
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

// Function names from swan.
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

// Function names from swan.

// Function name from swan.
u16 calcAbilHandlerSubPriority(BattleMon *mon) {
    return RawBattleMonStat(mon, 12);
}

// Function name from swan.
BOOL AbilityEvent_RollEffectChance(BattleMon *mon, u32 chance) {
    BOOL result;
    BOOL check;

    if (RollEffectChance(chance)) {
        return TRUE;
    }
    check = func_ov167_021abdf8(mon, 1);
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

void HandlerIntimidateMemberIn(void *context, void *flow, u32 monId) {
    u8 *mons;
    u32 side;
    u32 count;
    u32 i;
    struct IntimidateWork *work;

    if (BattleEventVar_GetValue(2) == monId) {
        side = func_ov167_021ab840(flow, monId);
        mons = func_ov167_021abc60(flow, 6);
        count = HandlerGetAlivePartyCount(flow, (u16)(side | 0x100), mons);
        if (count != 0) {
            BattleHandler_PushRun(flow, 2, monId);
            work = BattleHandler_PushWork(flow, 0xe, monId);
            work->command = 1;
            work->target = -1;
            work->active = 1;
            work->count = count;
            for (i = 0; i < count; i++) {
                work->mons[i] = mons[i];
            }
            BattleHandler_PopWork(flow, work);
            BattleHandler_PushRun(flow, 3, monId);
        }
    }
}

const BattleEventHandlerEntry *EventAddInnerFocus(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7794;
}

void HandlerInnerFocus(void *context, void *item, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

const BattleEventHandlerEntry *EventAddSteadfast(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7834;
}

void HandlerSteadfast(void *context, void *flow, u32 monId) {
    struct SteadfastWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(0x22) == 6) {
        if (BattleEventVar_GetValue(2) == monId) {
            work = BattleHandler_PushWork(flow, 0xe, monId);
            work->flags |= flag << 22;
            work->count = 5;
            work->active = 1;
            work->unk0e = 0;
            work->amount = 1;
            work->monId = monId;
            BattleHandler_PopWork(flow, work);
        }
    }
}

const BattleEventHandlerEntry *EventAddThickFat(u32 *priority) {
    *priority = 1;
    return data_ov167_021d763c;
}

void HandlerThickFat(void *context, void *item, u32 monId) {
    u8 type;

    if (BattleEventVar_GetValue(4) == monId) {
        type = BattleEventVar_GetValue(0x16);
        if (type == 14 || type == 9) {
            BattleEventVar_MulValue(0x35, 2 << 10);
        }
    }
}

const BattleEventHandlerEntry *EventAddHugePower(u32 *priority) {
    *priority = 1;
    return data_ov167_021d784c;
}

void HandlerHugePower(void *context, void *item, u32 monId) {
    u16 move;

    if (BattleEventVar_GetValue(3) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (PML_MoveGetCategory(move) == 1) {
            BattleEventVar_MulValue(0x35, 2 << 12);
        }
    }
}

void HandlerSwiftSwim(void *context, void *flow, u32 monId) {
    u32 multiplier;

    multiplier = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetWeather(flow) == 2) {
            BattleEventVar_MulValue(0x35, multiplier << 12);
        }
    }
}

const BattleEventHandlerEntry *EventAddSwiftSwim(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77c4;
}

void HandlerChlorophyll(void *context, void *flow, u32 monId) {
    u32 multiplier;

    multiplier = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetWeather(flow) == 1) {
            BattleEventVar_MulValue(0x35, multiplier << 12);
        }
    }
}

const BattleEventHandlerEntry *EventAddChlorophyll(u32 *priority) {
    *priority = 1;
    return data_ov167_021d765c;
}

void HandlerQuickFeet(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetBattleMonStatus(GetBattleMon(flow, monId)) != 0) {
            BattleEventVar_MulValue(0x35, 6 << 10);
            BattleEventVar_RewriteValue(0x51, 0);
        }
    }
}

const BattleEventHandlerEntry *EventAddQuickFeet(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77cc;
}

void HandlerTangledFeet(void *context, void *flow, u32 monId) {
    u32 multiplier;

    multiplier = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if (CheckCondition(GetBattleMon(flow, monId), 6)) {
            BattleEventVar_MulValue(0x35, multiplier << 9);
        }
    }
}

const BattleEventHandlerEntry *EventAddTangledFeet(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76ec;
}

void HandlerHustleAccuracy(void *context, void *item, u32 monId) {
    u16 move;

    if (BattleEventVar_GetValue(3) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (PML_MoveGetCategory(move) == 1) {
            BattleEventVar_MulValue(0x35, 0xccd);
        }
    }
}

void HandlerHustlePower(void *context, void *item, u32 monId) {
    u32 multiplier;
    u32 value;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 1) {
            value = BattleEventVar_GetValue(0x33);
            value = fixed_round(value, multiplier << 11);
            BattleEventVar_RewriteValue(0x33, value);
        }
    }
}

const BattleEventHandlerEntry *EventAddHustle(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a44;
}

void HandlerStall(void *context, void *item, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x11, 0);
    }
}

const BattleEventHandlerEntry *EventAddStall(u32 *priority) {
    *priority = numHandlersWithHandlerPri(7, 1);
    return data_ov167_021d7624;
}

// Function names from swan.

void HandlerCompoundEyes(void *context, void *item, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_MulValue(0x35, 0x14cd);
    }
}

const BattleEventHandlerEntry *EventAddCompoundEyes(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76d4;
}

void HandlerSandVeil(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (GetWeather(flow) == 4) {
            BattleEventVar_MulValue(0x35, 0xccd);
        }
    }
}

void HandlerSandVeilWeather(void *context, void *flow, u32 monId, u32 value) {
    CommonWeatherGuard(context, flow, monId, value, 4);
}

const BattleEventHandlerEntry *EventAddSandVeil(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a64;
}

void HandlerSnowCloak(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (GetWeather(flow) == 3) {
            BattleEventVar_MulValue(0x35, 0xccd);
        }
    }
}

void HandlerSnowCloakWeather(void *context, void *flow, u32 monId, u32 value) {
    CommonWeatherGuard(context, flow, monId, value, 3);
}

const BattleEventHandlerEntry *EventAddSnowCloak(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a74;
}

void CommonWeatherGuard(void *context, void *flow, u32 monId, u32 value, u8 weather) {
    if (BattleEventVar_GetValue(2) == monId) {
        if ((s32)BattleEventVar_GetValue(0x32) > 0) {
            if (BattleEventVar_GetValue(0x39) == weather) {
                BattleEventVar_RewriteValue(0x41, 1);
            }
        }
    }
}

void HandlerTintedLens(void *context, void *item, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (func_ov167_021bd2e8(BattleEventVar_GetValue(0x38)) == 3) {
            BattleEventVar_MulValue(0x35, 2 << 12);
        }
    }
}

const BattleEventHandlerEntry *EventAddTintedLens(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77bc;
}

void HandlerSolidRock(void *context, void *item, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (func_ov167_021bd2e8(BattleEventVar_GetValue(0x38)) == 2) {
            BattleEventVar_MulValue(0x35, 3 << 10);
        }
    }
}

const BattleEventHandlerEntry *EventAddSolidRock(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7844;
}

void HandlerSniper(void *context, void *item, u32 monId) {
    u32 multiplier;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        if (BattleEventVar_GetValue(0x45) != 0) {
            BattleEventVar_MulValue(0x35, multiplier << 11);
        }
    }
}

const BattleEventHandlerEntry *EventAddSniper(u32 *priority) {
    *priority = 1;
    return data_ov167_021d783c;
}

void HandlerSpeedBoost(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    SpeedBoostWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetAdditionalConditionFlag(mon, 0)) {
            work = BattleHandler_PushWork(flow, 0xe, monId);
            work->flags |= flag << 22;
            work->count = 5;
            work->amount = 1;
            work->monId = monId;
            work->active = 1;
            BattleHandler_PopWork(flow, work);
        }
    }
}

const BattleEventHandlerEntry *EventAddSpeedBoost(u32 *priority) {
    *priority = 1;
    return data_ov167_021d771c;
}

void HandlerAdaptability(void *context, void *item, u32 monId) {
    u32 multiplier;

    multiplier = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x44) != 0) {
            BattleEventVar_RewriteValue(0x35, multiplier << 12);
        }
    }
}

const BattleEventHandlerEntry *EventAddAdaptability(u32 *priority) {
    *priority = 1;
    return data_ov167_021d785c;
}

void HandlerBlaze(void *context, BtlServerFlow *flow, u32 monId) {
    CommonLowHPBoostAbility(flow, monId, 9);
}

const BattleEventHandlerEntry *EventAddBlaze(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7734;
}

void HandlerTorrent(void *context, BtlServerFlow *flow, u32 monId) {
    CommonLowHPBoostAbility(flow, monId, 10);
}

const BattleEventHandlerEntry *EventAddTorrent(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7694;
}

void HandlerOvergrow(void *context, BtlServerFlow *flow, u32 monId) {
    CommonLowHPBoostAbility(flow, monId, 11);
}

const BattleEventHandlerEntry *EventAddOvergrow(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76cc;
}

void HandlerSwarm(void *context, BtlServerFlow *flow, u32 monId) {
    CommonLowHPBoostAbility(flow, monId, 6);
}

const BattleEventHandlerEntry *EventAddSwarm(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76c4;
}

void CommonLowHPBoostAbility(BtlServerFlow *flow, u32 monId, u32 type) {
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

void HandlerGuts(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    u32 multiplier;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetBattleMonStatus(mon) != 0) {
            if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 1) {
                BattleEventVar_MulValue(0x35, multiplier << 11);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddGuts(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76bc;
}

void HandlerPlusMinus(void *context, void *flow, u32 monId, void *list) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (func_ov167_021be5c4(flow, monId, list, 0x39) || func_ov167_021be5c4(flow, monId, list, 0x3a)) {
            if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 2) {
                BattleEventVar_MulValue(0x35, 6 << 10);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddPlusMinus(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7724;
}

BOOL func_ov167_021be5c4(void *flow, u32 monId, void *list, u32 ability) {
    volatile u32 count;
    u32 clientCount;
    u16 packed;
    u8 i;
    u8 *mons;

    mons = list;
    clientCount = func_ov167_021abb50(flow);
    if (clientCount != 6) {
        packed = (7 << 8) | clientCount;
        count = HandlerGetAlivePartyCount(flow, packed, mons);
        for (i = 0; i < count; i++) {
            if (monId != mons[i]) {
                if (GetBattleMonStat(GetBattleMon(flow, mons[i]), 0x11) == ability) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

BOOL CheckFlowerGiftEnablePokemon(BtlServerFlow *flow, u32 monId) {
    return GetBattleMonSpecies(GetBattleMon(flow, monId)) == 0x1a5;
}

void HandlerFlowerGiftMemberOnField(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    u32 sunny;
    u32 weather;

    if (CheckFlowerGiftEnablePokemon(flow, monId)) {
        weather = GetWeather(flow);
        sunny = 1;
        if (weather != 1) {
            sunny = 0;
        }
        CommonFlowerGiftFormChange(context, flow, monId, sunny, 1);
        *result = 1;
    }
}

void HandlerFlowerGiftGotAbility(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    if (BattleEventVar_GetValue(2) == monId) {
        HandlerFlowerGiftMemberOnField(context, flow, monId, result);
    }
}

void CommonFlowerGiftFormChange(void *context, BtlServerFlow *flow, u32 monId, u8 sunny, u8 cause) {
    BattleMon *mon;
    FlowerGiftFormWork *work;

    mon = GetBattleMon(flow, monId);
    if (sunny != GetBattleMonStat(mon, 0x13)) {
        work = BattleHandler_PushWork(flow, 0x39, monId);
        work->monId = monId;
        work->form = sunny;
        work->flags = (work->flags & 0xff7fffff) | ((cause & 1) << 23);
        BattleHandler_StrSetup(&work->string, 2, 0xde);
        BattleHandler_AddArg(&work->string, monId);
        BattleHandler_PopWork(flow, work);
    }
}

void HandlerFlowerGiftWeather(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    u32 weather;
    u32 sunny;

    if (*active) {
        if (CheckFlowerGiftEnablePokemon(flow, monId)) {
            weather = GetWeather(flow);
            sunny = 1;
            if (weather != 1) {
                sunny = 0;
            }
            CommonFlowerGiftFormChange(context, flow, monId, sunny, 1);
        }
    }
}

void HandlerFlowerGiftAbilityOff(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    if (*active) {
        if (BattleEventVar_GetValue(2) == monId) {
            if (CheckFlowerGiftEnablePokemon(flow, monId)) {
                CommonFlowerGiftFormChange(context, flow, monId, 0, 0);
            }
        }
    }
}

void HandlerFlowerGiftAirLock(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    if (*active) {
        if (CheckFlowerGiftEnablePokemon(flow, monId)) {
            CommonFlowerGiftFormChange(context, flow, monId, 0, 0);
        }
    }
}

void HandlerFlowerGiftAbilityChange(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    u32 ability;

    if (*active) {
        if (CheckFlowerGiftEnablePokemon(flow, monId)) {
            if (BattleEventVar_GetValue(2) == monId) {
                ability = BattleEventVar_GetValue(0x10);
                if (ability != BattleEventItem_GetSubID(context)) {
                    CommonFlowerGiftFormChange(context, flow, monId, 0, 0);
                }
            }
        }
    }
}

void HandlerFlowerGiftPower(void *context, BtlServerFlow *flow, u8 monId) {
    u32 multiplier;
    u8 allyMonId;

    multiplier = 3;
    if (CheckFlowerGiftEnablePokemon(flow, monId)) {
        if (GetWeather(flow) == 1) {
            allyMonId = BattleEventVar_GetValue(3);
            if (IsAllyMonID(monId, allyMonId)) {
                if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 1) {
                    BattleEventVar_MulValue(0x35, multiplier << 11);
                }
            }
        }
    }
}

void HandlerFlowerGiftSpecialDefense(void *context, BtlServerFlow *flow, u8 monId) {
    u8 allyMonId;

    if (CheckFlowerGiftEnablePokemon(flow, monId)) {
        if (GetWeather(flow) == 1) {
            allyMonId = BattleEventVar_GetValue(4);
            if (IsAllyMonID(monId, allyMonId)) {
                if (BattleEventVar_GetValue(0x1a) == 2) {
                    BattleEventVar_MulValue(0x35, 6 << 10);
                }
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddFlowerGift(u32 *priority) {
    *priority = 11;
    return data_ov167_021d7ea0;
}

void HandlerRivalry(void *context, BtlServerFlow *flow, u32 monId) {
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
                BattleEventVar_MulValue(0x31, 5 << 10);
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

void HandlerTechnician(void *context, void *flow, u32 monId) {
    u32 multiplier;

    multiplier = 0x30;
    if (BattleEventVar_GetValue(3) == monId) {
        if (BattleEventVar_GetValue(0x30) <= 0x3c) {
            BattleEventVar_MulValue(0x31, multiplier << 7);
        }
    }
}

const BattleEventHandlerEntry *EventAddTechnician(u32 *priority) {
    *priority = 1;
    return data_ov167_021d768c;
}

void HandlerIronFist(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (getMoveFlag(BattleEventVar_GetValue(0x12), 7)) {
            BattleEventVar_MulValue(0x31, 0x1333);
        }
    }
}

const BattleEventHandlerEntry *EventAddIronFist(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77dc;
}

void HandlerReckless(void *context, void *flow, u32 monId) {
    u16 move;

    if (BattleEventVar_GetValue(3) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (PML_MoveGetParam(move, 0x1e) || move == 0x1a || move == 0x88) {
            BattleEventVar_MulValue(0x31, 0x1333);
        }
    }
}

const BattleEventHandlerEntry *EventAddReckless(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77a4;
}

void HandlerMarvelScale(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;

    if (BattleEventVar_GetValue(4) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetBattleMonStatus(mon)) {
            BattleEventVar_GetValue(0x12);
            if (BattleEventVar_GetValue(0x1a) == 1) {
                BattleEventVar_MulValue(0x35, 6 << 10);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddMarvelScale(u32 *priority) {
    *priority = 1;
    return data_ov167_021d772c;
}

void HandlerSkillLink(void *context, void *flow, u32 monId) {
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

void HandlerHyperCutterCheck(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardCheck(flow, monId, result, 1);
}

void HandlerHyperCutterGuard(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardFixed(flow, monId, result, 0xc9);
}

const BattleEventHandlerEntry *EventAddKeenEye(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7914;
}

void HandlerKeenEyeCheck(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardCheck(flow, monId, result, 6);
}

void HandlerKeenEyeGuard(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardFixed(flow, monId, result, 0xcf);
}

const BattleEventHandlerEntry *EventAddClearBody(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7924;
}

void HandlerClearBodyCheck(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardCheck(flow, monId, result, 8);
}

void HandlerClearBodyGuard(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardFixed(flow, monId, result, 0xc6);
}

void CommonStatDropGuardCheck(void *flow, u32 monId, u32 *result, u32 stat) {
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

void CommonStatDropGuardFixed(void *flow, u32 monId, u32 *result, u16 message) {
    u32 source;
    StatDropGuardMessageWork *work;

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

void HandlerSimple(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x20, BattleEventVar_GetValue(0x20) << 1);
    }
}

const BattleEventHandlerEntry *EventAddSimple(u32 *priority) {
    *priority = 1;
    return data_ov167_021d773c;
}

void HandlerLeafGuard(void *context, void *flow, u32 monId, u32 *result) {
    u32 condition;

    if (BattleEventVar_GetValue(4) == monId) {
        if (GetWeather(flow) == 1) {
            condition = BattleEventVar_GetValue(0x1d);
            if (IsBasicStatus(condition) || condition == 0xe) {
                *result = BattleEventVar_RewriteValue(0x41, 1);
            }
        }
    }
}

void HandlerLeafGuardYawnCheck(void *context, void *flow, u32 monId) {
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

void HandlerLimberStatus(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 1);
}

void HandlerLimberCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 1);
}

void HandlerLimberActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 1);
}

const BattleEventHandlerEntry *EventAddLimber(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7c80;
}

void HandlerInsomniaStatus(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 2);
    if (!*result) {
        *result = HandlerCommonGuardStatus(flow, monId, 0xe);
    }
}

void HandlerInsomniaWake(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 2);
}

void HandlerInsomniaActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 2);
}

void HandlerInsomniaYawnCheck(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

const BattleEventHandlerEntry *EventAddInsomnia(u32 *priority) {
    *priority = 6;
    return data_ov167_021d7dc0;
}

void HandlerMagmaArmorStatus(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 3);
}

void HandlerMagmaArmorCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 3);
}

void HandlerMagmaArmorActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 3);
}

const BattleEventHandlerEntry *EventAddMagmaArmor(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7cd0;
}

void HandlerImmunity(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 5);
}

void HandlerImmunityCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 5);
}

void HandlerImmunityActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 5);
}

const BattleEventHandlerEntry *EventAddImmunity(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7cf8;
}

void HandlerWaterVeil(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 4);
}

void HandlerWaterVeilCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 4);
}

void HandlerWaterVeilActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 4);
}

const BattleEventHandlerEntry *EventAddWaterVeil(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7d20;
}

void HandlerOwnTempoStatus(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 6);
}

void HandlerOwnTempoAddStatusFailed(void *context, void *flow, u32 monId, void *result) {
    CommonAddStatusFailed(context, flow, monId, result, 0x165);
}

void HandlerOwnTempoCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 6);
}

void HandlerOwnTempoActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 6);
}

const BattleEventHandlerEntry *EventAddOwnTempo(u32 *priority) {
    *priority = 4;
    return data_ov167_021d7c38;
}

void HandlerOblivious(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 7);
}

void HandlerObliviousCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 7);
}

void HandlerObliviousActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 7);
}

void HandlerObliviousNoEffectCheck(void *context, void *flow, u32 monId) {
    ObliviousMessageWork *work;
    u32 command;

    command = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if ((u16)BattleEventVar_GetValue(0x12) == 0x1bd) {
            if (BattleEventVar_RewriteValue(0x40, 1)) {
                BattleHandler_PushRun(flow, 2, monId);
                work = BattleHandler_PushWork(flow, command, monId);
                BattleHandler_StrSetup(&work->string, 2, 0xd2);
                BattleHandler_AddArg(&work->string, monId);
                BattleHandler_PopWork(flow, work);
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

void CommonAddStatusFailed(void *context, void *flow, u32 monId, u32 *result, u16 message) {
    StatusFailedMessageWork *work;
    u32 command;

    command = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if (*result == 1) {
            BattleHandler_PushRun(flow, 2, monId);
            work = BattleHandler_PushWork(flow, command, monId);
            BattleHandler_StrSetup(&work->string, 2, message);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork(flow, work);
            BattleHandler_PushRun(flow, 3, monId);
            *result = 0;
        }
    }
}

void HandlerAddStatusFailedCommon(void *context, void *flow, u32 monId, u32 *result) {
    CommonAddStatusFailed(context, flow, monId, result, 0xd2);
}

void CommonAbilityCureStatus(void *flow, u32 monId, u32 status) {
    if (BattleEventVar_GetValue(2) == monId) {
        CommonAbilityCureStatusCore(flow, monId, status);
    }
}

void CommonAbilityCureStatusCore(void *flow, u32 monId, u32 status) {
    BattleMon *mon;
    AbilityCureStatusWork *work;

    mon = GetBattleMon(flow, monId);
    if (CheckCondition(mon, status)) {
        BattleHandler_PushRun(flow, 2, monId);
        work = BattleHandler_PushWork(flow, 0xb, monId);
        work->status = status;
        work->active = 1;
        work->monId = monId;
        BattleHandler_PopWork(flow, work);
        BattleHandler_PushRun(flow, 3, monId);
    }
}

void HandlerDrizzle(void *context, void *flow, u32 monId) {
    CommonWeatherChangeAbility(flow, monId, 2);
}

const BattleEventHandlerEntry *EventAddDrizzle(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7954;
}

void HandlerDrought(void *context, void *flow, u32 monId) {
    CommonWeatherChangeAbility(flow, monId, 1);
}

const BattleEventHandlerEntry *EventAddDrought(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7964;
}

void HandlerSandStream(void *context, void *flow, u32 monId) {
    CommonWeatherChangeAbility(flow, monId, 4);
}

const BattleEventHandlerEntry *EventAddSandStream(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7974;
}

void HandlerSnowWarning(void *context, void *flow, u32 monId) {
    CommonWeatherChangeAbility(flow, monId, 3);
}

const BattleEventHandlerEntry *EventAddSnowWarning(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7984;
}

void CommonWeatherChangeAbility(void *flow, u32 monId, u32 weather) {
    WeatherChangeAbilityWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        work = BattleHandler_PushWork(flow, 0x1d, monId);
        work->flags |= flag << 22;
        work->weather = weather;
        work->duration = 0xff;
        BattleHandler_PopWork(flow, work);
    }
}

void HandlerAirLockMemberIn(void *context, void *flow, u32 monId) {
    AirLockWeatherWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        work = BattleHandler_PushWork(flow, 0x1d, monId);
        work->flags |= flag << 22;
        work->weather = 0;
        work->active = 1;
        BattleHandler_StrSetup(&work->string, 1, 0x5e);
        BattleHandler_PopWork(flow, work);
    }
}

BOOL HandlerAirLockChangeWeather(void *context, void *flow, u32 monId) {
    return BattleEventVar_RewriteValue(0x41, 1);
}

const BattleEventHandlerEntry *EventAddAirLock(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7994;
}

void HandlerIceBody(void *context, BtlServerFlow *flow, u32 monId) {
    CommonWeatherRecoveryAbility(flow, monId, 3);
}

const BattleEventHandlerEntry *EventAddIceBody(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7644;
}

void HandlerRainDish(void *context, BtlServerFlow *flow, u32 monId) {
    CommonWeatherRecoveryAbility(flow, monId, 2);
}

const BattleEventHandlerEntry *EventAddRainDish(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76f4;
}

void CommonWeatherRecoveryAbility(BtlServerFlow *flow, u32 monId, u32 weather) {
    BattleMon *mon;
    WeatherRecoveryWork *work;

    if (BattleEventVar_GetValue(0x39) == weather) {
        if (BattleEventVar_GetValue(2) == monId) {
            mon = GetBattleMon(flow, monId);
            work = BattleHandler_PushWork(flow, 5, monId);
            work->flags |= 2 << 22;
            work->monId = monId;
            work->amount = DivideMaxHPZeroCheck(mon, 0x10);
            BattleHandler_PopWork(flow, work);
            BattleEventVar_RewriteValue(0x41, 1);
        }
    }
}

void HandlerSolarPowerWeather(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    SolarPowerWork *work;
    u16 amount;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x39) == 1) {
            mon = GetBattleMon(flow, monId);
            amount = DivideMaxHPZeroCheck(mon, 8);
            BattleHandler_PushRun(flow, 2, monId);
            work = BattleHandler_PushWork(flow, 7, monId);
            work->monId = monId;
            work->amount = amount;
            BattleHandler_PopWork(flow, work);
            BattleHandler_PushRun(flow, 3, monId);
        }
    }
}

void HandlerSolarPowerPower(void *context, BtlServerFlow *flow, u32 monId) {
    u32 multiplier;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        if (GetWeather(flow) == 1) {
            if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 2) {
                BattleEventVar_MulValue(0x35, multiplier << 11);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddSolarPower(u32 *priority) {
    *priority = 2;
    return data_ov167_021d79b4;
}

void HandlerShieldDustStatus(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(3) != monId) {
            if (BattleEventVar_GetValue(0x1d) != 8) {
                BattleEventVar_RewriteValue(0x41, 1);
            }
        }
    }
}

void HandlerShieldDustRank(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(3) != monId) {
            BattleEventVar_RewriteValue(0x41, 1);
        }
    }
}

void HandlerShieldDustShrink(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

void HandlerShieldDustGuard(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x47, 1);
    }
}

void HandlerShieldDustGuardHitEnd(void *context, void *flow, u32 monId) {
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

void HandlerSereneGrace(void *context, void *flow, u32 monId) {
    u32 chance;

    if (BattleEventVar_GetValue(3) == monId) {
        chance = BattleEventVar_GetValue(0x26);
        chance = (u16)(chance << 1);
        BattleEventVar_RewriteValue(0x26, chance);
    }
}

void HandlerSereneGraceShrink(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x45, 1);
    }
}

const BattleEventHandlerEntry *EventAddSereneGrace(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7b0c;
}

void HandlerHydration(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    HydrationWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetWeather(flow) == 2) {
            mon = GetBattleMon(flow, monId);
            if (GetBattleMonStatus(mon)) {
                BattleHandler_PushRun(flow, 2, monId);
                work = BattleHandler_PushWork(flow, 0xb, monId);
                work->status = 0x24;
                work->monId = monId;
                work->active = 1;
                work->flags |= flag << 24;
                BattleHandler_PopWork(flow, work);
                BattleHandler_PushRun(flow, 3, monId);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddHydration(u32 *priority) {
    *priority = 1;
    return data_ov167_021d762c;
}

void HandlerShedSkin(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    ShedSkinWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetBattleMonStatus(mon)) {
            if (AbilityEvent_RollEffectChance((BattleMon *)flow, 0x21)) {
                work = BattleHandler_PushWork(flow, 0xb, monId);
                work->flags |= flag << 22;
                work->flags |= flag << 24;
                work->status = 0x24;
                work->monId = monId;
                work->active = 1;
                BattleHandler_PopWork(flow, work);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddShedSkin(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78fc;
}

void HandlerPoisonHeal(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    PoisonHealWork *work;
    u32 flag;

    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x1d) == 5) {
            mon = GetBattleMon(flow, monId);
            BattleEventVar_RewriteValue(0x32, 0);
            work = BattleHandler_PushWork(flow, 5, monId);
            work->amount = DivideMaxHPZeroCheck(mon, 8);
            work->monId = monId;
            flag = 8;
            work->flags |= flag << 20;
            BattleHandler_PopWork(flow, work);
        }
    }
}

const BattleEventHandlerEntry *EventAddPoisonHeal(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78f4;
}

void HandlerBattleArmor(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

const BattleEventHandlerEntry *EventAddBattleArmor(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78ec;
}

void HandlerSuperLuck(void *context, void *flow, u32 monId) {
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

void HandlerAngerPoint(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    AngerPointWork *work;
    s32 amount;

    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(0x46) == 0) {
            if (BattleEventVar_GetValue(0x45) != 0) {
                mon = GetBattleMon(flow, monId);
                if (func_ov167_021bb550(mon, 1) > 0) {
                    work = BattleHandler_PushWork(flow, 0xe, monId);
                    work->stage = 1;
                    amount = func_ov167_021bb550(mon, 1);
                    work->amount = amount;
                    work->showPopup = 1;
                    work->showMessage = 1;
                    work->monId = monId;
                    work->active = 1;
                    work->flags |= 1 << 23;
                    BattleHandler_StrSetup(&work->string, 2, 0x1e1);
                    BattleHandler_AddArg(&work->string, monId);
                    BattleHandler_PopWork(flow, work);
                }
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddAngerPoint(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78dc;
}

void HandlerPoisonPoint(void *context, void *flow, u32 monId) {
    u32 value;

    value = func_ov167_021bd52c(5);
    CommonContactStatusAbility(flow, monId, 5, value, 0x1e);
}

// Function name from swan.
const BattleEventHandlerEntry *EventAddPoisonPoint(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78d4;
}

void HandlerStatic(void *context, void *flow, u32 monId) {
    u32 value;

    value = func_ov167_021bd52c(1);
    CommonContactStatusAbility(flow, monId, 1, value, 0x1e);
}

// Function name from swan.
const BattleEventHandlerEntry *EventAddStatic(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78cc;
}

void HandlerFlameBody(void *context, void *flow, u32 monId) {
    u32 value;

    value = func_ov167_021bd52c(4);
    CommonContactStatusAbility(flow, monId, 4, value, 0x1e);
}

// Function name from swan.
const BattleEventHandlerEntry *EventAddFlameBody(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78c4;
}

// Function names from swan.

void HandlerRockHead(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

const BattleEventHandlerEntry *EventAddRockHead(u32 *priority) {
    *priority = 1;
    return data_ov167_021d788c;
}

void HandlerNormalize(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x16, 0);
    }
}

const BattleEventHandlerEntry *EventAddNormalize(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7884;
}

// Function names from swan.
const BattleEventHandlerEntry *EventAddTrace(u32 *priority) {
    *priority = 1;
    return data_ov167_021d787c;
}

void HandlerNaturalCure(void *context, BtlServerFlow *flow, u32 monId) {
    NaturalCureWork *work;

    if (BattleEventVar_GetValue(2) == monId) {
        work = BattleHandler_PushWork(flow, 0xb, monId);
        work->status = 0x24;
        work->active = 1;
        work->monId = monId;
        work->showPopup = 1;
        BattleHandler_PopWork(flow, work);
    }
}

const BattleEventHandlerEntry *EventAddNaturalCure(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7874;
}

const BattleEventHandlerEntry *EventAddSturdy(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7b84;
}

void HandlerSturdyOneshotCheck(void *context, BtlServerFlow *flow, u32 monId) {
    SturdyMessageWork *work;
    u32 command;
    command = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_RewriteValue(0x41, 1)) {
            BattleHandler_PushRun(flow, 2, monId);
            work = BattleHandler_PushWork(flow, command, monId);
            BattleHandler_StrSetup(&work->string, 2, 0xd2);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork(flow, work);
            BattleHandler_PushRun(flow, 3, monId);
        }
    }
}

void HandlerSturdyEndureCheck(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    u32 value;
    value = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if (IsMonFullHP(GetBattleMon(flow, monId))) {
            *result = BattleEventVar_RewriteValue(0x3a, value);
        } else {
            *result = 0;
        }
    }
}

void HandlerSturdySurvive(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    SturdyMessageWork *work;
    if (BattleEventVar_GetValue(2) == monId) {
        if (*active) {
            BattleHandler_PushRun(flow, 2, monId);
            work = BattleHandler_PushWork(flow, 4, monId);
            BattleHandler_StrSetup(&work->string, 2, 0x202);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork(flow, work);
            BattleHandler_PushRun(flow, 3, monId);
            *active = 0;
        }
    }
}

void HandlerUnawareHitRank(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x28, 6);
    } else if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x27, 6);
    }
}

void HandlerUnawareAttackRank(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x51, 1);
    }
}

void HandlerUnawareDefenseRank(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x51, 1);
    }
}

const BattleEventHandlerEntry *EventAddUnaware(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7b9c;
}

void HandlerHeatproofPower(void *context, void *flow, u32 monId) {
    u32 factor;

    factor = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(0x16) == 9) {
            BattleEventVar_MulValue(0x31, factor << 9);
        }
    }
}

void HandlerHeatproofStatus(void *context, void *flow, u32 monId) {
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

void CommonTypeRecoverHP(BtlServerFlow *flow, u32 monId, u32 divisor) {
    BattleMon *mon;
    TypeRecoverWork *work;
    TypeRecoverMessageWork *message;
    mon = GetBattleMon(flow, monId);
    if (!IsMonFullHP(mon)) {
        work = BattleHandler_PushWork(flow, 5, monId);
        work->monId = monId;
        work->amount = DivideMaxHPZeroCheck(mon, divisor);
        work->flags |= 2 << 22;
        BattleHandler_StrSetup(&work->string, 2, 0x183);
        BattleHandler_AddArg(&work->string, monId);
        BattleHandler_PopWork(flow, work);
    } else {
        message = BattleHandler_PushWork(flow, 4, monId);
        BattleHandler_StrSetup(&message->string, 2, 0xd2);
        BattleHandler_AddArg(&message->string, monId);
        message->flags |= 2 << 22;
        BattleHandler_PopWork(flow, message);
    }
    BattleEventVar_RewriteValue(0x51, 1);
}

void CommonTypeNoEffectRankUp(BtlServerFlow *flow, u32 monId, u32 stat, u32 amount) {
    BattleMon *mon;
    TypeRankUpWork *work;
    TypeRankMessageWork *message;
    mon = GetBattleMon(flow, monId);
    if (IsStatChangeValid(mon, stat, amount)) {
        work = BattleHandler_PushWork(flow, 0xe, monId);
        work->showPopup = 1;
        work->monId = monId;
        work->active = 1;
        work->stat = stat;
        work->amount = amount;
        work->flags |= 1 << 23;
        BattleHandler_PopWork(flow, work);
    } else {
        message = BattleHandler_PushWork(flow, 4, monId);
        BattleHandler_StrSetup(&message->string, 2, 0xd2);
        BattleHandler_AddArg(&message->string, monId);
        message->flags |= 2 << 22;
        BattleHandler_PopWork(flow, message);
    }
}

void HandlerDrySkinWeather(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    DrySkinWeatherWork *work;
    u8 weather;
    if (BattleEventVar_GetValue(2) == monId) {
        mon = GetBattleMon(flow, monId);
        weather = BattleEventVar_GetValue(0x39);
        if (weather == 1) {
            BattleHandler_PushRun(flow, 2, monId);
            work = BattleHandler_PushWork(flow, 7, monId);
            work->monId = monId;
            work->amount = DivideMaxHPZeroCheck(mon, 8);
            BattleHandler_PopWork(flow, work);
            BattleHandler_PushRun(flow, 3, monId);
        } else if (weather == 2) {
            work = BattleHandler_PushWork(flow, 5, monId);
            work->flags |= 2 << 22;
            work->monId = monId;
            work->amount = DivideMaxHPZeroCheck(mon, 8);
            BattleHandler_PopWork(flow, work);
        }
    }
}

void HandlerDrySkinDamageRecover(void *context, BtlServerFlow *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(0x16) == 9) {
            BattleEventVar_MulValue(0x31, 5 << 10);
        }
    }
}

void HandlerDrySkinCheck(void *context, BtlServerFlow *flow, u32 monId) {
    if (CommonDamageRecoverCheck(flow, monId, 10)) {
        CommonTypeRecoverHP(flow, monId, 4);
    }
}

const BattleEventHandlerEntry *EventAddDrySkin(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7bb4;
}

void HandlerWaterAbsorbCheck(void *context, BtlServerFlow *flow, u32 monId) {
    if (CommonDamageRecoverCheck(flow, monId, 10)) {
        CommonTypeRecoverHP(flow, monId, 4);
    }
}

const BattleEventHandlerEntry *EventAddWaterAbsorb(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77b4;
}

void HandlerVoltAbsorbCheck(void *context, BtlServerFlow *flow, u32 monId) {
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

void HandlerMotorDriveCheck(void *context, BtlServerFlow *flow, u32 monId) {
    if (CommonDamageRecoverCheck(flow, monId, 12)) {
        CommonTypeNoEffectRankUp(flow, monId, 5, 1);
    }
}

void HandlerScrappy(void *context, void *flow, u32 monId) {
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

void HandlerSoundproof(void *context, BtlServerFlow *flow, u32 monId) {
    SoundproofMessageWork *work;
    u32 command;
    u16 move;

    command = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (getMoveFlag(move, 8)) {
            if (BattleEventVar_RewriteValue(0x40, 1)) {
                BattleHandler_PushRun(flow, 2, monId);
                work = BattleHandler_PushWork(flow, command, monId);
                BattleHandler_StrSetup(&work->string, 2, 0xd2);
                BattleHandler_AddArg(&work->string, monId);
                BattleHandler_PopWork(flow, work);
                BattleHandler_PushRun(flow, 3, monId);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddSoundproof(u32 *priority) {
    *priority = 1;
    return data_ov167_021d780c;
}

void HandlerLevitate(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    u32 key;

    if (BattleEventVar_GetValue(2) == monId) {
        key = 0x51;
        if (BattleEventVar_GetValue(key) == 0) {
            *result = BattleEventVar_RewriteValue(key, 1);
        }
    }
}

void HandlerLevitateAddImmunity(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    LevitateImmunityWork *work;

    if (BattleEventVar_GetValue(2) == monId) {
        if (*active) {
            work = BattleHandler_PushWork(flow, 4, monId);
            work->flags |= 4 << 21;
            BattleHandler_StrSetup(&work->string, 2, 0xd2);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork(flow, work);
            *active = 0;
        }
    }
}

void HandlerLevitateTurnCheck(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    if (BattleEventVar_GetValue(2) == monId) {
        *result = 0;
    }
}

const BattleEventHandlerEntry *EventAddLevitate(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7a94;
}

void HandlerWonderGuard(void *context, BtlServerFlow *flow, u32 monId) {
    WonderGuardMessageWork *work;
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
                            work = BattleHandler_PushWork(flow, 4, monId);
                            BattleHandler_StrSetup(&work->string, 2, 0xd2);
                            BattleHandler_AddArg(&work->string, monId);
                            BattleHandler_PopWork(flow, work);
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

// Function names from swan.
void HandlerTruant(void *context, BtlServerFlow *flow, u32 monId, u32 *state) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (state[0] != 0) {
            state[1] = BattleEventVar_RewriteValue(0x22, 0x13);
            state[0] = 0;
        } else {
            state[0] = 1;
        }
    }
}

void HandlerTruantGet(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetTurnFlag(GetBattleMon(flow, monId), 0)) {
            *result = 1;
        }
    }
}

void HandlerTruantFailed(void *context, BtlServerFlow *flow, u32 monId, u32 *state) {
    struct TruantMessageWork *work;

    if (BattleEventVar_GetValue(2) == monId) {
        if (state[1] != 0) {
            work = BattleHandler_PushWork(flow, 4, monId);
            work->flags |= 4 << 21;
            BattleHandler_StrSetup(&work->string, 2, 0x1bd);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork(flow, work);
            state[1] = 0;
        }
    }
}

void HandlerTruantEndAction(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0xc) == 7) {
            *result = 0;
        }
    }
}

const BattleEventHandlerEntry *EventAddTruant(u32 *priority) {
    *priority = 4;
    return data_ov167_021d7c18;
}

// Function names from swan.

void HandlerDamp(void *context, BtlServerFlow *flow, u32 monId, u32 *state) {
    u16 move;
    u32 key;

    move = BattleEventVar_GetValue(0x12);
    state[0] = 0;
    if (move == 0x99 || move == 0x78) {
        key = 0x22;
        if (BattleEventVar_GetValue(key) == 0) {
            state[0] = BattleEventVar_RewriteValue(key, 0x13);
            state[1] = move;
        }
    }
}

void HandlerDampEffective(void *context, BtlServerFlow *flow, u32 monId, u32 *state) {
    u8 target;
    DampMessageWork *work;

    if (state[0]) {
        target = BattleEventVar_GetValue(2);
        work = BattleHandler_PushWork(flow, 4, monId);
        work->flags |= 4 << 21;
        BattleHandler_StrSetup(&work->string, 2, 0x389);
        BattleHandler_AddArg(&work->string, target);
        BattleHandler_AddArg(&work->string, state[1]);
        BattleHandler_PopWork(flow, work);
        state[0] = 0;
    }
}

void HandlerDampStart(BattleEventItem *item, BtlServerFlow *flow, u32 monId) {
    BattleEventItem_AttachSkipCheckHandler(item, HandlerDampSkipCheck);
}

void func_ov167_021c06cc(BattleEventItem *item) {
    BattleEventItem_DetachSkipCheckHandler(item);
}

void HandlerDampEnd(BattleEventItem *item, BtlServerFlow *flow, u32 monId) {
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

void HandlerFlashFirePower(void *context, BtlServerFlow *flow, u32 monId) {
    u32 multiplier;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        if (GetAdditionalConditionFlag(GetBattleMon(flow, monId), 0xd)) {
            if (BattleEventVar_GetValue(0x16) == 9) {
                BattleEventVar_MulValue(0x35, multiplier << 11);
            }
        }
    }
}

void HandlerFlashFireRemove(void *context, BtlServerFlow *flow, u32 monId) {
    FlashFireRemoveWork *work;
    u32 condition;

    if (BattleEventVar_GetValue(2) == monId) {
        condition = 0xd;
        if (GetAdditionalConditionFlag(GetBattleMon(flow, monId), condition)) {
            work = BattleHandler_PushWork(flow, 0x18, monId);
            work->monId = monId;
            work->condition = condition;
            BattleHandler_PopWork(flow, work);
        }
    }
}

void HandlerFlashFireCheckNoEffect(void *context, BtlServerFlow *flow, u32 monId) {
    FlashFireMessageWork *message;
    FlashFireRemoveWork *work;
    u32 condition;

    if (CommonDamageRecoverCheck(flow, monId, 9)) {
        BattleHandler_PushRun(flow, 2, monId);
        condition = 0xd;
        if (!GetAdditionalConditionFlag(GetBattleMon(flow, monId), condition)) {
            message = BattleHandler_PushWork(flow, 4, monId);
            BattleHandler_StrSetup(&message->string, 2, 0x1ab);
            BattleHandler_AddArg(&message->string, monId);
            BattleHandler_PopWork(flow, message);
            work = BattleHandler_PushWork(flow, 0x17, monId);
            work->monId = monId;
            work->condition = condition;
            BattleHandler_PopWork(flow, work);
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

void HandlerRunAwayMessage(void *context, BtlServerFlow *flow, u32 monId) {
    RunAwayMessageWork *work;
    u32 flags;

    if (CommonCheckRunMessage(context)) {
        flags = 4;
        work = BattleHandler_PushWork(flow, 4, monId);
        work->flags |= flags << 21;
        BattleHandler_StrSetup(&work->string, 1, 0x48);
        BattleHandler_AddSoundEffect(&work->string, 0x56a);
        BattleHandler_PopWork(flow, work);
    }
}

const BattleEventHandlerEntry *EventAddRunAway(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7934;
}

// Function names from swan.
void HandlerMoldBreakerStart(BattleEventItem *item, BtlServerFlow *flow, u32 monId, u32 *active) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (*active == 0) {
            BattleEventItem_AttachSkipCheckHandler(item, func_ov167_021c09d0);
            *active = 1;
        }
    }
}

void HandlerMoldBreakerEnd(BattleEventItem *item, BtlServerFlow *flow, u32 monId, u32 *active) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (*active == 1) {
            BattleEventItem_DetachSkipCheckHandler(item);
            *active = 0;
        }
    }
}

void HandlerMoldBreakerConfirm(BattleEventItem *item, BtlServerFlow *flow, u32 monId, u32 *active) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (*active == 1) {
            BattleEventItem_DetachSkipCheckHandler(item);
            *active = 0;
        }
    }
}

const BattleEventHandlerEntry *EventAddMoldBreaker(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7ca8;
}

// Function names from swan.

void HandlerForecastMemberOnField(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    u32 weather;

    weather = GetWeather(flow);
    CommonForecastFormChange(flow, monId, weather);
    *active = 1;
}

void HandlerForecastGetAbility(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    if (BattleEventVar_GetValue(2) == monId) {
        HandlerForecastMemberOnField(context, flow, monId, active);
    }
}

void HandlerForecastWeather(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    u32 weather;

    if (*active) {
        weather = GetWeather(flow);
        CommonForecastFormChange(flow, monId, weather);
    }
}

void HandlerForecastAirLock(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    if (*active) {
        CommonForecastOff(context, flow, monId);
    }
}

void HandlerForecastChangeAbility(BattleEventItem *item, BtlServerFlow *flow, u32 monId, u32 *active) {
    u32 subId;

    if (BattleEventVar_GetValue(2) == monId) {
        subId = BattleEventVar_GetValue(0x10);
        if (subId != BattleEventItem_GetSubID(item)) {
            CommonForecastOff(item, flow, monId);
        }
    }
}

void HandlerForecastAbilityOff(void *context, BtlServerFlow *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        CommonForecastOff(context, flow, monId);
    }
}

void CommonForecastOff(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    ForecastFormWork *work;
    mon = GetBattleMon(flow, monId);
    if (GetBattleMonSpecies(mon) == 0x15f) {
        if (GetBattleMonStat(mon, 0x13) != 0) {
            work = BattleHandler_PushWork(flow, 0x39, monId);
            work->monId = monId;
            work->form = 0;
            BattleHandler_StrSetup(&work->string, 2, 0xde);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork(flow, work);
        }
    }
}

void CommonForecastFormChange(BtlServerFlow *flow, u32 monId, u32 weather) {
    BattleMon *mon;
    ForecastFormWork *work;
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
            work->flags |= 2 << 22;
            work->monId = monId;
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

void HandlerStormDrain(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    *result = CommonMoveTargetChangeToMe(flow, monId, result, 10);
}

void HandlerStormDrainCheckNoEffect(void *context, BtlServerFlow *flow, u32 monId) {
    if (CommonDamageRecoverCheck(flow, monId, 10)) {
        CommonTypeNoEffectRankUp(flow, monId, 3, 1);
    }
}

const BattleEventHandlerEntry *EventAddLightningRod(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7af4;
}

void HandlerLightningRod(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    *result = CommonMoveTargetChangeToMe(flow, monId, result, 12);
}

void HandlerLightningRodStart(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    LightningRodMessageWork *work;
    u32 flags;
    if (*active) {
        if (func_ov167_021cde38(monId)) {
            work = BattleHandler_PushWork(flow, 4, monId);
            flags = 4;
            work->flags |= flags << 21;
            BattleHandler_StrSetup(&work->string, 2, 7 << 6);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork(flow, work);
        }
        *active = 0;
    }
}

void HandlerLightningRodCheckNoEffect(void *context, BtlServerFlow *flow, u32 monId) {
    if (CommonDamageRecoverCheck(flow, monId, 12)) {
        CommonTypeNoEffectRankUp(flow, monId, 3, 1);
    }
}

// Function name from swan.
const BattleEventHandlerEntry *EventAddRegenerator(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7784;
}

// Function names from swan.
const BattleEventHandlerEntry *EventAddBigPecks(u32 *priority) {
    *priority = 2;
    return data_ov167_021d79c4;
}

void HandlerBigPecksCheck(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardCheck(flow, monId, result, 2);
}

void HandlerBigPecksGuard(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardFixed(flow, monId, result, 0xcc);
}
