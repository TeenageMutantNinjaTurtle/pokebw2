#ifndef POKEBW2_SPL_INTERNAL_H
#define POKEBW2_SPL_INTERNAL_H

#include "types.h"
#include "nitro/fx.h"
#include "nitro/spl.h"

// What SPL's files share among themselves

// A linear congruential generator, its high bits the random value
extern u32 gSPLRandomState;

static inline u32 SPLRandom_Next(void) {
    gSPLRandomState = gSPLRandomState * 0x5eedf715 + 0x1b0cb173;
    return gSPLRandomState;
}

// The top bits of the next value, as a signed fixed-point number: a fraction of [-1, 1) for 24 bits
static inline fx32 SPLRandom_Fx32(u32 bits) {
    return (fx32)SPLRandom_Next() >> (32 - bits);
}

// A random value in [-range, range), range an integer or a fixed-point number. A macro, as the library reads range
// after drawing the number
#define SPLRandom_Range(range) (((range) * (s32)(SPLRandom_Next() >> 23) - ((range) << 8)) >> 8)

// A random unit vector, or one in the xy plane
void SPLRandom_VecFx32(VecFx32 *vec);
void SPLRandom_VecFx32_XY(VecFx32 *vec);

#endif // POKEBW2_SPL_INTERNAL_H
