#include "battle/btl_main.h"

// Function name from swan.
u8 GetPosOnSameSide(u8 pos, u8 index) {
    if ((pos & 1) == 0) {
        return index * 2;
    }
    return index * 2 + 1;
}
