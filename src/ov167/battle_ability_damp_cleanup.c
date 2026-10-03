#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.

void HandlerDampEnd(BattleEventItem *item, BtlServerFlow *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventItem_DetachSkipCheckHandler(item);
    }
}

BOOL HandlerDampSkipCheck(void *a, void *b, u32 c, void *d, u16 move) {
    if (c == 4) {
        if (move == 0x6a) {
            return TRUE;
        }
    }
    return FALSE;
}

const BattleEventHandlerEntry *EventAddDamp(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7c58;
}
