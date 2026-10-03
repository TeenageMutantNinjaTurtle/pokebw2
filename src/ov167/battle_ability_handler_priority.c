#include "battle/btl_ability.h"

// Function names from swan.
u32 numHandlersWithHandlerPri(u32 priority, u32 count) {
    return (priority << 16) | count;
}

u32 devideNumHandersAndPri(u32 *packed) {
    u32 priority;

    priority = (*packed >> 16) & 0xffff;
    if (priority == 0) {
        priority = 5;
    }
    *packed &= 0xffff;
    return priority;
}
