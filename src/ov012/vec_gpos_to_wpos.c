#include "field/zone.h"

void VecGPosToWPos(s32 x, s32 y, s32 z, VecFx32 *position) {
    position->x = x << 16;
    position->y = y << 16;
    position->z = z << 16;
}
