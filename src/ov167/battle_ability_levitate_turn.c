#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerLevitateTurnCheck(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    if (BattleEventVar_GetValue(2) == monId) {
        *result = 0;
    }
}

const BattleEventHandlerEntry *EventAddLevitate(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7a94;
}
