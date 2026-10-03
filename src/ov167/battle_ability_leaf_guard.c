#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"
#include "battle/btl_pokeparam.h"

// Function names from swan.
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
