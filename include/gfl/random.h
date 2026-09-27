#ifndef POKEBW2_GFL_RANDOM_H
#define POKEBW2_GFL_RANDOM_H

#include "types.h"

u32 GFL_RandomLC(u32 max);
u32 GFL_RandomMT(void);

// A random number below range, or any 32-bit number if range is 0
static inline u32 GFL_RandomMTRange(u32 range) {
    u64 value = GFL_RandomMT();

    if (range != 0) {
        value *= range;
        value >>= 32;
    }
    return value;
}

#endif // POKEBW2_GFL_RANDOM_H
