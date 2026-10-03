#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_math.h"
#include "pml/waza.h"

// Function names from swan.
void HandlerHustleAccuracy(void *context, void *item, u32 monId) {
    u16 move;

    if (BattleEventVar_GetValue(3) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (PML_MoveGetCategory(move) == 1) {
            BattleEventVar_MulValue(0x35, 0xccd);
        }
    }
}

void HandlerHustlePower(void *context, void *item, u32 monId) {
    u32 multiplier;
    u32 value;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 1) {
            value = BattleEventVar_GetValue(0x33);
            value = fixed_round(value, multiplier << 11);
            BattleEventVar_RewriteValue(0x33, value);
        }
    }
}

const BattleEventHandlerEntry *EventAddHustle(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a44;
}
