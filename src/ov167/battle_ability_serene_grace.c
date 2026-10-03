#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerSereneGrace(void *context, void *flow, u32 monId) {
    u32 chance;

    if (BattleEventVar_GetValue(3) == monId) {
        chance = BattleEventVar_GetValue(0x26);
        chance = (u16)(chance << 1);
        BattleEventVar_RewriteValue(0x26, chance);
    }
}

void HandlerSereneGraceShrink(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x45, 1);
    }
}

const BattleEventHandlerEntry *EventAddSereneGrace(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7b0c;
}
