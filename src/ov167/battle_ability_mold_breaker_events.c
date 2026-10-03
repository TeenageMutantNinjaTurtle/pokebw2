#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerMoldBreakerStart(BattleEventItem *item, BtlServerFlow *flow, u32 monId, u32 *active) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (*active == 0) {
            BattleEventItem_AttachSkipCheckHandler(item, (void *)func_ov167_021c09d0);
            *active = 1;
        }
    }
}

void HandlerMoldBreakerEnd(BattleEventItem *item, BtlServerFlow *flow, u32 monId, u32 *active) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (*active == 1) {
            BattleEventItem_DetachSkipCheckHandler(item);
            *active = 0;
        }
    }
}

void HandlerMoldBreakerConfirm(BattleEventItem *item, BtlServerFlow *flow, u32 monId, u32 *active) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (*active == 1) {
            BattleEventItem_DetachSkipCheckHandler(item);
            *active = 0;
        }
    }
}

const BattleEventHandlerEntry *EventAddMoldBreaker(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7ca8;
}
