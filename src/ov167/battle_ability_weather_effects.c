#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"
#include "pml/waza.h"

// Function names from swan.

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

struct WeatherChangeAbilityWork {
    u32 flags;
    u8 weather;
    u8 duration;
};

void CommonWeatherChangeAbility(void *flow, u32 monId, u32 weather) {
    WeatherChangeAbilityWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        work = BattleHandler_PushWork((BattleHandler *)flow, 0x1d, (void *)monId);
        work->flags |= flag << 22;
        work->weather = weather;
        work->duration = 0xff;
        BattleHandler_PopWork((BattleHandler *)flow, work);
    }
}

struct AirLockWeatherWork {
    u32 flags;
    u8 weather;
    u8 duration;
    u8 active;
    u8 reserved;
    BattleHandlerString string;
};

void HandlerAirLockMemberIn(void *context, void *flow, u32 monId) {
    AirLockWeatherWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        work = BattleHandler_PushWork((BattleHandler *)flow, 0x1d, (void *)monId);
        work->flags |= flag << 22;
        work->weather = 0;
        work->active = 1;
        BattleHandler_StrSetup(&work->string, 1, 0x5e);
        BattleHandler_PopWork((BattleHandler *)flow, work);
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

struct WeatherRecoveryWork {
    u32 flags;
    u16 amount;
    u8 monId;
};

void CommonWeatherRecoveryAbility(BtlServerFlow *flow, u32 monId, u32 weather) {
    BattleMon *mon;
    WeatherRecoveryWork *work;

    if (BattleEventVar_GetValue(0x39) == weather) {
        if (BattleEventVar_GetValue(2) == monId) {
            mon = GetBattleMon(flow, monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, 5, (void *)monId);
            work->flags |= 2 << 22;
            work->monId = monId;
            work->amount = DivideMaxHPZeroCheck(mon, 0x10);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleEventVar_RewriteValue(0x41, 1);
        }
    }
}

struct SolarPowerWork {
    u32 flags;
    u16 amount;
    u8 monId;
};

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
            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, 7, (void *)monId);
            work->monId = monId;
            work->amount = amount;
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
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
