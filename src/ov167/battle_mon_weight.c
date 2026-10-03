#include "battle/btl_pokeparam.h"

// Function names from swan.
void SetWeight(BattleMon *mon, u16 weight) {
    if (weight < 1) {
        weight = 1;
    }
    *(u16 *)((u8 *)mon + 0x13e) = weight;
}

u16 GetBattleMonWeight(BattleMon *mon) {
    return *(u16 *)((u8 *)mon + 0x13e);
}
