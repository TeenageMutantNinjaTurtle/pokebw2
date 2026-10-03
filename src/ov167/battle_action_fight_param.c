#include "battle/btl_action.h"

// Function names from swan.
void BattleAction_SetFightParam(BattleAction *action, u16 move, u8 target) {
    action->raw = 0;
    action->bits.action = 1;
    action->bits.target = target;
    action->bits.move = move;
}

void BattleAction_ChangeFightTargetPos(BattleAction *action, u8 target) {
    if (action->bits.action == 1 && target != 6) {
        action->bits.target = target;
    }
}
