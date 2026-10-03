#include "battle/btl_pokeparam.h"

// Function names from swan.
void ConsumeItem(BattleMon *mon, u16 item) {
    u16 *words;

    words = (u16 *)mon;
    words[10] = item;
    words[9] = 0;
}

void ClearConsumedItem(BattleMon *mon) {
    ((u16 *)mon)[10] = 0;
}

u16 GetConsumedItem(BattleMon *mon) {
    return ((u16 *)mon)[10];
}
