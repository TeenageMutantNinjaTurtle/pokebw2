#include "battle/btl_action_order.h"

// Function names from swan.
BOOL ActionOrder_InterruptReserve(ActionOrder *order, u8 monId) {
    ActionOrderEntry *entry;

    entry = ActionOrder_SearchByMonID(order, monId);
    if (entry && !entry->done && ActionOrderTool_Interrupt(order, entry, 0) >= 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL ActionOrder_InterruptReserveByMove(ActionOrder *order, u16 moveId) {
    u32 start;
    BOOL didInterrupt;
    ActionOrderEntry *entry;
    s32 index;

    start = 0;
    entry = ActionOrder_SearchByMoveID(order, moveId, 0);
    didInterrupt = FALSE;
    while (entry) {
        index = ActionOrderTool_Interrupt(order, entry, start);
        if (index < 0) {
            break;
        }
        start = index + 1;
        entry = ActionOrder_SearchByMoveID(order, moveId, (u8)start);
        didInterrupt = TRUE;
    }
    return didInterrupt;
}

BOOL ActionOrder_SendToLast(ActionOrder *order, u8 monId) {
    ActionOrderEntry *entry;

    entry = ActionOrder_SearchByMonID(order, monId);
    if (entry && !entry->done) {
        ActionOrderTool_SendToLast(order, entry);
        return TRUE;
    }
    return FALSE;
}

void ActionOrder_ForceDone(ActionOrder *order, u8 monId) {
    ActionOrderEntry *entry;

    entry = ActionOrder_SearchByMonID(order, monId);
    if (entry) {
        entry->done = 1;
    }
}
