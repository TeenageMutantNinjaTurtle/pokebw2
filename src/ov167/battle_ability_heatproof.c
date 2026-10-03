#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
s32 func_ov167_021bd31c(s32 value, s32 minimum);

void HandlerHeatproofPower(void *context, void *flow, u32 monId) {
    u32 factor;

    factor = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(0x16) == 9) {
            BattleEventVar_MulValue(0x31, factor << 9);
        }
    }
}

void HandlerHeatproofStatus(void *context, void *flow, u32 monId) {
    s32 damage;

    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x1d) == 4) {
            damage = BattleEventVar_GetValue(0x32);
            damage = func_ov167_021bd31c(damage / 2, 1);
            BattleEventVar_RewriteValue(0x32, damage);
        }
    }
}

const BattleEventHandlerEntry *EventAddHeatproof(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a54;
}
