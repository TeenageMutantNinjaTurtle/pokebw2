#include "battle/btl_math.h"

// Function name from swan.
u32 GetRatioOverZero(u32 value, u32 ratio) {
    u32 result;

    result = fixed_round(value, ratio);
    if (result == 0) {
        result = 1;
    }
    return result;
}
