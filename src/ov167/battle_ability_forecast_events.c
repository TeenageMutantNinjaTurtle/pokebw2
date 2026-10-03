#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"

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
