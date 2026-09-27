#ifndef POKEBW2_NITRO_FX_H
#define POKEBW2_NITRO_FX_H

#include "types.h"

// Fixed point numbers with 12 fractional bits
typedef s16 fx16;
typedef s32 fx32;
typedef s64 fx64;

#define FX32_SHIFT 12
#define FX32_ONE (1 << FX32_SHIFT)
#define FX32_CONST(x) ((fx32)((x) * FX32_ONE))
#define FX_Whole(a) ((s32)((a) >> FX32_SHIFT))

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

static inline void VEC_Set(VecFx32 *v, fx32 x, fx32 y, fx32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

#endif // POKEBW2_NITRO_FX_H
