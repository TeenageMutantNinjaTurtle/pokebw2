#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerStall(void *context, void *item, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x11, 0);
    }
}

const BattleEventHandlerEntry *EventAddStall(u32 *priority) {
    *priority = numHandlersWithHandlerPri(7, 1);
    return data_ov167_021d7624;
}
