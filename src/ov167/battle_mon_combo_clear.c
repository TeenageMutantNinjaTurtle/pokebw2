#include "battle/btl_pokeparam.h"

// Function name from swan.
void ComboMove_ClearParam(BattleMon *mon) {
    u8 *data;

    data = (u8 *)mon;
    if (data[0x1f6] != 0x1f) {
        data[0x1f6] = 0x1f;
        *(u16 *)(data + 0x1f4) = 0;
    }
}
