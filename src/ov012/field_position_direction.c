#include "field/field_actor.h"
#include "field/zone.h"

s16 GetDirectionVectorCompX(u32 direction) {
    return DIRECTION_VEC_X[direction];
}

s16 GetDirectionVectorCompZ(u32 direction) {
    return DIRECTION_VEC_Z[direction];
}

void ExpandVecInGridDir(u16 direction, VecFx32 *position, fx32 amount) {
    switch (direction) {
    case 0:
        position->z -= amount;
        break;
    case 1:
        position->z += amount;
        break;
    case 2:
        position->x -= amount;
        break;
    case 3:
        position->x += amount;
        break;
    }
}

void AdjusGridXZByDir(u32 direction, s16 *x, s16 *z, s16 amount) {
    switch (direction) {
    case 0:
        *z = (s16)(*z - amount);
        break;
    case 1:
        *z = (s16)(*z + amount);
        break;
    case 2:
        *x = (s16)(*x - amount);
        break;
    case 3:
        *x = (s16)(*x + amount);
        break;
    }
}

void ConvGXZToVector(u32 x, u32 z, VecFx32 *position) {
    position->x = (x << 16) + 0x8000;
    position->z = (z << 16) + 0x8000;
}

void VecGPosToWPos(s32 x, s32 y, s32 z, VecFx32 *position) {
    position->x = x << 16;
    position->y = y << 16;
    position->z = z << 16;
}

u16 GetInverseDirection(u32 direction) {
    return INV_DIR_TABLE[direction];
}

u16 GetDirFromPosToPos(s32 x1, s32 z1, s32 x2, s32 z2) {
    s32 direction;

    if (x1 > x2) {
        return 2;
    }
    if (x1 < x2) {
        return 3;
    }
    direction = 1;
    if (z1 > z2) {
        direction = 0;
    }
    return direction;
}

u32 func_ov012_0215ed38(u32 direction, u16 angle) {
    u32 index;

    index = data_ov012_0216cd68[((u32)(data_ov012_0216cd60[direction] + angle) << 16) >> 28];
    return data_ov012_0216cdc9[index << 2];
}