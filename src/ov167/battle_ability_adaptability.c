#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerAdaptability(void *context, void *item, u32 monId) {
    u32 multiplier;

    multiplier = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x44) != 0) {
            BattleEventVar_RewriteValue(0x35, multiplier << 12);
        }
    }
}

const BattleEventHandlerEntry *EventAddAdaptability(u32 *priority) {
    *priority = 1;
    return data_ov167_021d785c;
}
