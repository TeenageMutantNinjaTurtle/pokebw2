#include "battle/btl_ability.h"

// Function names from swan.
const BattleEventHandlerEntry *EventAddRegenerator(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7784;
}

const BattleEventHandlerEntry *EventAddBigPecks(u32 *priority) {
    *priority = 2;
    return data_ov167_021d79c4;
}

void HandlerBigPecksCheck(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardCheck(flow, monId, result, 2);
}

void HandlerBigPecksGuard(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardFixed(flow, monId, result, 0xcc);
}
