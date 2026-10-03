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

u16 func_ov012_0215d654(ZoneWarp *warp, const RailPosition *position) {
    const ZoneWarpRailPosition *rail;
    u32 direction;
    BOOL frontFlip;
    BOOL sideFlip;
    s32 offset;

    rail = (const ZoneWarpRailPosition *)&warp->gridPos;
    frontFlip = FALSE;
    sideFlip = FALSE;
    direction = ZoneWarp_GetDirection(warp);
    switch (rail->param) {
    case 0:
        frontFlip = TRUE;
        break;
    case 1:
        sideFlip = TRUE;
        break;
    case 2:
        frontFlip = TRUE;
        sideFlip = TRUE;
        break;
    case 3:
        break;
    }
    if (rail->sideSpan > 1) {
        offset = position->posSide - rail->posSide;
        if (sideFlip) {
            offset = (rail->sideSpan - 1) - offset;
        }
        return ((rail->sideSpan << 4) | offset) | (direction << 8);
    }
    if (rail->frontSpan > 1) {
        offset = position->posFront - rail->posFront;
        if (frontFlip) {
            offset = (rail->frontSpan - 1) - offset;
        }
        return ((rail->frontSpan << 4) | offset) | (direction << 8);
    }
    return (direction << 8) | 0x10;
}

u32 ZoneWarp_GetDirection(const ZoneWarp *warp) {
    switch (warp->unk4) {
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 3;
    default:
        return 1;
    }
}

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
