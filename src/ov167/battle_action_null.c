#include "battle/btl_action.h"

// Function name from swan.
void BattleAction_SetNull(BattleAction *action) {
    action->bits.action = 0;
    action->raw &= 0xf;
}
