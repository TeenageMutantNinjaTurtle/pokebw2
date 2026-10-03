#include "battle/btl_pokeparam.h"

// Function name from swan.
u8 GetConditionCount(BattleMon *mon, u32 index) {
    u8 *data;

    data = (u8 *)mon + index;
    return data[0x157];
}
