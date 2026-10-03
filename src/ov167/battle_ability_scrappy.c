#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerScrappy(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (BattleEventVar_GetValue(0x15) == 7) {
            BattleEventVar_RewriteValue(0x4b, 1);
        }
    }
}

const BattleEventHandlerEntry *EventAddScrappy(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7814;
}
