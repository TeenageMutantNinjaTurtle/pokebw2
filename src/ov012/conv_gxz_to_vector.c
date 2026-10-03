#include "field/field_actor.h"

void ConvGXZToVector(u32 x, u32 z, VecFx32 *position) {
    position->x = (x << 16) + 0x8000;
    position->z = (z << 16) + 0x8000;
}
