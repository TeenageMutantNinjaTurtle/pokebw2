#include "field/unity_tower.h"

u32 func_ov033_0217aac4(u8 *output, u32 index) {
    u32 result;

    result = 0xff;
    if (index < 5 && index < output[1]) {
        output += index;
        result = output[8];
    }
    return result;
}
