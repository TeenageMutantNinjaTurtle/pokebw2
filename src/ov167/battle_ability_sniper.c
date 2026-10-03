#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerSniper(void *context, void *item, u32 monId) {
    u32 multiplier;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        if (BattleEventVar_GetValue(0x45) != 0) {
            BattleEventVar_MulValue(0x35, multiplier << 11);
        }
    }
}

const BattleEventHandlerEntry *EventAddSniper(u32 *priority) {
    *priority = 1;
    return data_ov167_021d783c;
}
