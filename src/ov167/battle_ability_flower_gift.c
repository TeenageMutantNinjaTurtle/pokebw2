#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"
#include "pml/waza.h"

// Function names from swan.
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

struct FlowerGiftFormWork {
    u32 flags;
    u8 monId;
    u8 form;
    u8 reserved[2];
    BattleHandlerString string;
};

void CommonFlowerGiftFormChange(void *context, BtlServerFlow *flow, u32 monId, u8 sunny, u8 cause) {
    BattleMon *mon;
    FlowerGiftFormWork *work;

    mon = GetBattleMon(flow, monId);
    if (sunny != GetBattleMonStat(mon, 0x13)) {
        work = BattleHandler_PushWork((BattleHandler *)flow, 0x39, (void *)monId);
        work->monId = monId;
        work->form = sunny;
        work->flags = (work->flags & 0xff7fffff) | ((cause & 1) << 23);
        BattleHandler_StrSetup(&work->string, 2, 0xde);
        BattleHandler_AddArg(&work->string, monId);
        BattleHandler_PopWork((BattleHandler *)flow, work);
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
