#include "field/zone.h"

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
