#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_math.h"

// Function names from swan.
void HandlerTintedLens(void *context, void *item, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (func_ov167_021bd2e8(BattleEventVar_GetValue(0x38)) == 3) {
            BattleEventVar_MulValue(0x35, 2 << 12);
        }
    }
}

const BattleEventHandlerEntry *EventAddTintedLens(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77bc;
}

void HandlerSolidRock(void *context, void *item, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (func_ov167_021bd2e8(BattleEventVar_GetValue(0x38)) == 2) {
            BattleEventVar_MulValue(0x35, 3 << 10);
        }
    }
}

const BattleEventHandlerEntry *EventAddSolidRock(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7844;
}
