#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerTruantEndAction(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0xc) == 7) {
            *result = 0;
        }
    }
}

const BattleEventHandlerEntry *EventAddTruant(u32 *priority) {
    *priority = 4;
    return data_ov167_021d7c18;
}
