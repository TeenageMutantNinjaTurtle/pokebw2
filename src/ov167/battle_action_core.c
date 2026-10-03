#include "battle/btl_action.h"

// Function names from swan.

// Function name from swan.
void BattleAction_SetNull(BattleAction *action) {
    action->bits.action = 0;
    action->raw &= 0xf;
}

void BattleAction_SetSkip(BattleAction *action) {
    action->bits.action = 7;
}

u32 BattleAction_GetAction(const void *action) {
    return ((const BattleAction *)action)->bits.action;
}
