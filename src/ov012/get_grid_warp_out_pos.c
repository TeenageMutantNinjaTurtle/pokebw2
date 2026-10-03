#include "field/zone.h"

void GetGridWarpOutPos(ZoneWarp *warp, u32 direction, VecFx32 *position) {
    ZoneWarpGridPosition *grid = &warp->gridPos;
    u32 warpDirection = ZoneWarp_GetDirection(warp);

    position->x = (s16)grid->x << 12;
    position->y = (s16)grid->y << 12;
    position->z = (s16)grid->z << 12;
    if (grid->width > 1) {
        position->x += CalcWarpTransferAddend(direction, warpDirection, 0, 0, grid->width) << 16;
    } else if (grid->height > 1) {
        position->z += CalcWarpTransferAddend(direction, warpDirection, 0, 0, grid->height) << 16;
    }
}
