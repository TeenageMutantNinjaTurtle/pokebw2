#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerSimple(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x20, BattleEventVar_GetValue(0x20) << 1);
    }
}

const BattleEventHandlerEntry *EventAddSimple(u32 *priority) {
    *priority = 1;
    return data_ov167_021d773c;
}
