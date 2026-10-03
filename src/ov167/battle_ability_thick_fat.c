#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
const BattleEventHandlerEntry *EventAddThickFat(u32 *priority) {
    *priority = 1;
    return data_ov167_021d763c;
}

void HandlerThickFat(void *context, void *item, u32 monId) {
    u8 type;

    if (BattleEventVar_GetValue(4) == monId) {
        type = BattleEventVar_GetValue(0x16);
        if (type == 14 || type == 9) {
            BattleEventVar_MulValue(0x35, 2 << 10);
        }
    }
}
