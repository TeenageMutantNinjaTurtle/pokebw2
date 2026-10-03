#include "battle/btl_pokeparam.h"

// Function names from swan.
void IncrementTurn(BattleCondition *condition, u32 amount) {
    if (condition->common.type == 2 && condition->common.turns < 8) {
        condition->common.turns += amount;
    }
    if (condition->common.type == 4 && condition->common.turns < 8) {
        condition->common.turns += amount;
    }
}

void SetTurns(BattleCondition *condition, u32 turns) {
    if (condition->common.type == 2 && condition->common.turns < 8) {
        condition->common.turns = turns;
    }
    if (condition->common.type == 4 && condition->common.turns < 8) {
        condition->common.turns = turns;
    }
}
