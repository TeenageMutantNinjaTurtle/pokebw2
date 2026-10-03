#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "pml/waza.h"

// Function names from swan.
const BattleEventHandlerEntry *EventAddHugePower(u32 *priority) {
    *priority = 1;
    return data_ov167_021d784c;
}

void HandlerHugePower(void *context, void *item, u32 monId) {
    u16 move;

    if (BattleEventVar_GetValue(3) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (PML_MoveGetCategory(move) == 1) {
            BattleEventVar_MulValue(0x35, 2 << 12);
        }
    }
}
