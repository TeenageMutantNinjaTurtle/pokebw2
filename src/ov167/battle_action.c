#include "types.h"
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

// Function name from swan.
void BattleAction_SetNull(BattleAction *action) {
    action->bits.action = 0;
    action->raw &= 0xf;
}

void BattleAction_SetSkip(BattleAction *action) {
    action->bits.action = 7;
}

u32 BattleAction_GetAction(const BattleAction *action) {
    return action->bits.action;
}
