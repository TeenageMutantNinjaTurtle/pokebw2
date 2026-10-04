#ifndef POKEBW2_NITRO_FX_H
#define POKEBW2_NITRO_FX_H

#include "types.h"

// Fixed point numbers with 12 fractional bits
typedef s16 fx16;
typedef s32 fx32;
typedef s64 fx64;

#define FX16_ONE (1 << 12)
#define FX32_SHIFT 12
#define FX32_ONE (1 << FX32_SHIFT)
#define FX32_CONST(x) ((fx32)(((x) > 0) ? ((x) * FX32_ONE + 0.5f) : ((x) * FX32_ONE - 0.5f)))
#define FX_Whole(a) ((s32)((a) >> FX32_SHIFT))

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct {
    fx16 x;
    fx16 y;
    fx16 z;
} VecFx16;

typedef struct {
    fx32 m[3][3];
} MtxFx33;

typedef struct {
    fx32 m[4][3];
} MtxFx43;

typedef struct {
    fx32 m[4][4];
} MtxFx44;

// The sine and cosine of 4096 angles around the circle, as pairs
extern const fx16 FX_SIN_COS_TABLE[4096 * 2];

// An angle in whole degrees as the 16-bit angle that FX_SinIdx and FX_CosIdx take, 0x10000 for a full turn
#define DEG_TO_IDX(deg) ((u16)((deg) * 0x10000 / 360))

static inline fx16 FX_SinIdx(int idx) {
    return FX_SIN_COS_TABLE[(idx >> 4) << 1];
}

static inline fx16 FX_CosIdx(int idx) {
    return FX_SIN_COS_TABLE[((idx >> 4) << 1) + 1];
}

void MAT3_Identity(MtxFx33 *mtx);
// A rotation matrix from 16-bit angles about each axis
void MAT3_RotationEulerZYX(u16 x, u16 y, u16 z, MtxFx33 *mtx);

// A rotation about the Y axis from its sine and cosine
void MAT43_RotationY(MtxFx43 *mtx, fx32 sin, fx32 cos);
void MAT3_RotationX(MtxFx33 *mtx, fx32 sin, fx32 cos);
void MAT43_MulVec(const VecFx32 *vec, const MtxFx43 *mtx, VecFx32 *dest);

void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
void vecfx_normalize(const VecFx32 *src, VecFx32 *dest);
void vecfx_muladd(fx32 scale, const VecFx32 *a, const VecFx32 *b, VecFx32 *dest);
void vecfx_mul(const VecFx32 *src, fx32 scale, VecFx32 *dest);
fx32 VEC_Mag(const VecFx32 *v);

// An angle in fixed point degrees as a 16-bit angle
#define FX64C_65536_360 ((s64)0x000000b60b60b60bLL)
#define FX_DEG_TO_IDX(deg) ((u16)(((deg) * FX64C_65536_360 + 0x80000000000LL) >> 44))

fx32 FX_Div(fx32 numer, fx32 denom);
fx32 FX_Sqrt(fx32 x);
fx32 FX_InvSqrt(fx32 x);

static inline fx32 FX_Mul(fx32 v1, fx32 v2) {
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> FX32_SHIFT);
}

static inline void VEC_Set(VecFx32 *v, fx32 x, fx32 y, fx32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

#endif // POKEBW2_NITRO_FX_H
