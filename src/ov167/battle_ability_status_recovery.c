#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.

struct HydrationWork {
    u32 flags;
    u32 status;
    u8 monId;
    u8 reserved[0xb];
    u8 active;
};

void HandlerHydration(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    HydrationWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetWeather(flow) == 2) {
            mon = GetBattleMon(flow, monId);
            if (GetBattleMonStatus(mon)) {
                BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
                work = BattleHandler_PushWork((BattleHandler *)flow, 0xb, (void *)monId);
                work->status = 0x24;
                work->monId = monId;
                work->active = 1;
                work->flags |= flag << 24;
                BattleHandler_PopWork((BattleHandler *)flow, work);
                BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddHydration(u32 *priority) {
    *priority = 1;
    return data_ov167_021d762c;
}

struct ShedSkinWork {
    u32 flags;
    u32 status;
    u8 monId;
    u8 reserved[0xb];
    u8 active;
};

void HandlerShedSkin(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    ShedSkinWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetBattleMonStatus(mon)) {
            if (AbilityEvent_RollEffectChance((BattleMon *)flow, 0x21)) {
                work = BattleHandler_PushWork((BattleHandler *)flow, 0xb, (void *)monId);
                work->flags |= flag << 22;
                work->flags |= flag << 24;
                work->status = 0x24;
                work->monId = monId;
                work->active = 1;
                BattleHandler_PopWork((BattleHandler *)flow, work);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddShedSkin(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78fc;
}

struct PoisonHealWork {
    u32 flags;
    u16 amount;
    u8 monId;
};

void HandlerPoisonHeal(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    PoisonHealWork *work;
    u32 flag;

    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x1d) == 5) {
            mon = GetBattleMon(flow, monId);
            BattleEventVar_RewriteValue(0x32, 0);
            work = BattleHandler_PushWork((BattleHandler *)flow, 5, (void *)monId);
            work->amount = DivideMaxHPZeroCheck(mon, 8);
            work->monId = monId;
            flag = 8;
            work->flags |= flag << 20;
            BattleHandler_PopWork((BattleHandler *)flow, work);
        }
    }
}

const BattleEventHandlerEntry *EventAddPoisonHeal(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78f4;
}
