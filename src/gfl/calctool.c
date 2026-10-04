#include "types.h"
#include "gfl/calctool.h"
#include "nitro/fx.h"

void MAT2_SetScaleRot(MtxFx22 *mtx, u16 rotation, fx32 scaleX, fx32 scaleY, u8 rotationMode) {
    if (rotationMode == MAT2_ROT_256) {
        rotation = (rotation * 0xffff) >> 8;
    } else if (rotationMode == MAT2_ROT_DEG) {
        rotation = (u32)(rotation * 0xffff) / 360;
    }
    MAT2_Rotation(mtx, FX_SinIdx(rotation), FX_CosIdx(rotation));
    MAT2_Scale(mtx, mtx, FX_Inv(scaleX), FX_Inv(scaleY));
}

void CalcSphere_Set(CalcSphere *sphere, const VecFx32 *center, fx32 radius) {
    sphere->center = *center;
    sphere->radius = radius;
}

BOOL CalcCapsule_HitSphere(const CalcCapsule *capsule, const CalcSphere *sphere, CalcHitResult *result) {
    CalcHitResult hit;
    VecFx32 segment;
    VecFx32 toCenter;
    VecFx32 diff;
    fx32 t;

    hit.hit = FALSE;
    VEC_Subtract(&capsule->end, &capsule->start, &segment);
    VEC_Subtract(&sphere->center, &capsule->start, &toCenter);
    t = FX_Div(vecfx_dot(&segment, &toCenter), vecfx_dot(&segment, &segment));
    if (t >= 0 && t <= FX32_ONE) {
        // The nearest point is inside the segment
        vecfx_mul(&segment, t, &segment);
        VEC_Subtract(&segment, &toCenter, &diff);
        hit.dist = VEC_Mag(&diff);
        if (hit.dist <= sphere->radius + capsule->radius) {
            hit.hit = TRUE;
        }
    } else {
        // The nearest point is an end
        VEC_Subtract(&sphere->center, &capsule->end, &diff);
        hit.dist = VEC_Mag(&diff);
        if (hit.dist <= sphere->radius) {
            hit.hit = TRUE;
        } else {
            diff = toCenter;
            hit.dist = VEC_Mag(&diff);
            if (hit.dist <= sphere->radius) {
                hit.hit = TRUE;
            }
        }
    }
    if (result != NULL) {
        vecfx_normalize(&diff, &hit.dir);
        *result = hit;
    }
    return hit.hit;
}

void CalcCapsule_Set(CalcCapsule *capsule, const VecFx32 *start, const VecFx32 *end, fx32 radius) {
    capsule->start = *start;
    capsule->end = *end;
    capsule->radius = radius;
}

void vecfx_mul(const VecFx32 *v, fx32 scale, VecFx32 *dest) {
    dest->x = fx_mul_round(v->x, scale);
    dest->y = fx_mul_round(v->y, scale);
    dest->z = fx_mul_round(v->z, scale);
}

void vecfx_div(const VecFx32 *v, fx32 divisor, VecFx32 *dest) {
    dest->x = FX_Div(v->x, divisor);
    dest->y = FX_Div(v->y, divisor);
    dest->z = FX_Div(v->z, divisor);
}

void MAT3_RotationEulerZYX(u16 x, u16 y, u16 z, MtxFx33 *mtx) {
    MtxFx33 rotation;

    MAT3_Identity(mtx);
    MAT3_RotationX(mtx, FX_SinIdx(x), FX_CosIdx(x));
    MAT3_RotationY(&rotation, FX_SinIdx(y), FX_CosIdx(y));
    MAT3_Mul(mtx, &rotation, mtx);
    MAT3_RotationZ(&rotation, FX_SinIdx(z), FX_CosIdx(z));
    MAT3_Mul(mtx, &rotation, mtx);
}

void MAT3_RotationDir(const VecFx32 *dir, MtxFx33 *mtx) {
    VecFx32 flat;
    MtxFx33 rotationX;
    MtxFx33 rotationY;
    u16 angle;

    flat = *dir;
    flat.y = 0;
    angle = fx_atan2(-dir->y, VEC_Mag(&flat));
    MAT3_RotationX(&rotationX, FX_SinIdx(angle), FX_CosIdx(angle));
    angle = fx_atan2(dir->x, dir->z);
    MAT3_RotationY(&rotationY, FX_SinIdx(angle), FX_CosIdx(angle));
    MAT3_Mul(&rotationX, &rotationY, mtx);
}
