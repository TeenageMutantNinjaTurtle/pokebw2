#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerNormalize(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x16, 0);
    }
}

const BattleEventHandlerEntry *EventAddNormalize(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7884;
}
