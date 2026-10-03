#include "field/zone.h"

void func_ov012_0215d88c(const ZoneBGEntity *entity, VecFx32 *position) {
    const s32 *coords;
    s32 x;
    s32 y;
    s32 z;

    coords = &entity->pos.grid.x;
    z = coords[1] << 16;
    x = coords[0] << 16;
    y = coords[2] << 12;
    position->x = x;
    position->y = y;
    position->z = z;
}
