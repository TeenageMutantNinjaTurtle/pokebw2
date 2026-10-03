#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerCompoundEyes(void *context, void *item, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_MulValue(0x35, 0x14cd);
    }
}

const BattleEventHandlerEntry *EventAddCompoundEyes(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76d4;
}
