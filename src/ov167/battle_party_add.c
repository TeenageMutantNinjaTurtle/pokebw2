#include "battle/btl_main.h"

// Function name from swan.
void AddBattleMonToParty(BattleParty *party, BattleMon *mon) {
    party->mons[party->count++] = mon;
}
