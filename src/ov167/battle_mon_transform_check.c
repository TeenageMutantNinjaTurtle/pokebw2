#include "battle/btl_pokeparam.h"

// Function name from swan.
BOOL TransformCheck(BattleMon *mon) {
    return ((u32)((u8 *)mon)[0x1b] << 26) >> 31;
}
