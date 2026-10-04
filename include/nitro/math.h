#ifndef POKEBW2_NITRO_MATH_H
#define POKEBW2_NITRO_MATH_H

#include "types.h"

#define MATH_ABS(a) (((a) < 0) ? -(a) : (a))

// NitroSDK's linear congruential random numbers, which are inline in the SDK

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext32;

static inline void MATH_InitRand32(MATHRandContext32 *context, u64 seed) {
    context->x = seed;
    context->mul = (1566083941LL << 32) + 1812433253LL;
    context->add = 2531011;
}

// A random number below max, or any 32-bit number when max is 0
static inline u32 MATH_Rand32(MATHRandContext32 *context, u32 max) {
    context->x = context->mul * context->x + context->add;
    if (max == 0) {
        return (u32)(context->x >> 32);
    } else {
        return (u32)(((context->x >> 32) * max) >> 32);
    }
}

#endif // POKEBW2_NITRO_MATH_H
