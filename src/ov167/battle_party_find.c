#include "battle/btl_main.h"

// Function name from swan.
s32 FindPartyMon(BattleParty *party, BattleMon *mon) {
    s32 i;

    // The original reloads the party count after checking each mon.
    for (i = 0; i < ((volatile BattleParty *)party)->count; i++) {
        if (party->mons[i] == mon) {
            return i;
        }
    }
    return -1;
}
