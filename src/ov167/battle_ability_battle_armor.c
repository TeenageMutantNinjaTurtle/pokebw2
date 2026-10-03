#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerBattleArmor(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

const BattleEventHandlerEntry *EventAddBattleArmor(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78ec;
}
