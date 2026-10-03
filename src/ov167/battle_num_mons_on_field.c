#include "battle/btl_setup.h"

// Function name from swan.
u32 GetNumMonsOnField(u32 battleType, u32 count) {
    if (battleType == 3) {
        count = 3;
    }
    return count;
}
