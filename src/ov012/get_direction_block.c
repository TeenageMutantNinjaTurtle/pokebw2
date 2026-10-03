#include "field/zone.h"

u32 func_ov012_0215ed38(u32 direction, u16 angle) {
    u32 index;

    index = data_ov012_0216cd68[((u32)(data_ov012_0216cd60[direction] + angle) << 16) >> 28];
    return data_ov012_0216cdc9[index << 2];
}
