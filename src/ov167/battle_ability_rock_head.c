#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerRockHead(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

const BattleEventHandlerEntry *EventAddRockHead(u32 *priority) {
    *priority = 1;
    return data_ov167_021d788c;
}
