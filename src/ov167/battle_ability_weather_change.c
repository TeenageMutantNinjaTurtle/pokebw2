#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"

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
