#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"

// Function names from swan.
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
