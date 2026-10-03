#include "field/zone.h"

u16 ZoneWarp_CalcPosWeightBitsGrid_(ZoneWarp *warp, const VecFx32 *position) {
    ZoneWarpGridPosition *grid;
    u32 direction;

    direction = ZoneWarp_GetDirection(warp);
    grid = &warp->gridPos;
    if (grid->width > 1) {
        return ((grid->width << 4) | (((position->x >> 12) - (s16)grid->x) / 16)) | (direction << 8);
    }
    if (grid->height > 1) {
        return ((grid->height << 4) | (((position->z >> 12) - (s16)grid->z) / 16)) | (direction << 8);
    }
    return (direction << 8) | 0x10;
}
