#include "battle/btl_pokeparam.h"

// Function name from swan.
void SetIllusionDisguise(BattleMon *mon, void *disguise) {
    u8 *data;

    data = (u8 *)mon;
    *(void **)(data + 4) = disguise;
    data[0x1b] |= 0x40;
}
