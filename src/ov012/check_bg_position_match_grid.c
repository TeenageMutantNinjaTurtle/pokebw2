#include "field/zone.h"

BOOL CheckBGPositionMatchGrid(const ZoneBGEntity *entity, const VecFx32 *position) {
    const s32 *coords;
    s32 zRaw;
    s32 x;
    s32 y;
    s32 z;

    if (entity->isRail == 1) {
        return FALSE;
    }
    zRaw = position->z;
    coords = &entity->pos.grid.x;
    z = (zRaw >> 4) / 4096;
    x = (position->x >> 4) / 4096;
    y = position->y >> 12;
    if (coords[0] == x && coords[1] == z && coords[2] - 2 <= y && coords[2] + 2 > y) {
        return TRUE;
    }
    return FALSE;
}
