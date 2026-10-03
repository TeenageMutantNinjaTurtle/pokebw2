#include "field/zone.h"

void GetRailWarpOutPos(ZoneWarp *warp, u32 direction, RailPosition *position) {
    ZoneWarpRailPosition *rail = (ZoneWarpRailPosition *)&warp->gridPos;
    u32 warpDirection = ZoneWarp_GetDirection(warp);
    s16 side;
    u16 param;

    position->componentId = rail->componentId;
    position->componentIsLine = 1;
    position->railDirection = ConvDirToRailDir(warpDirection);
    side = *(volatile s16 *)&rail->posSide;
    param = rail->param;
    position->posSide = side;
    position->posFront = rail->posFront;
    if (rail->sideSpan > 1) {
        position->posSide += (s16)CalcWarpTransferAddend(direction, warpDirection, 1, param, rail->sideSpan);
    } else if (rail->frontSpan > 1) {
        position->posFront += CalcWarpTransferAddend(direction, warpDirection, 1, param, rail->frontSpan);
    }
}

BOOL CheckWarpPositionMatchRail(const ZoneWarp *warp, const RailPosition *position) {
    const ZoneWarpRailPosition *rail;

    if (warp->isRail == 0) {
        return FALSE;
    }
    rail = (const ZoneWarpRailPosition *)&warp->gridPos;
    if (rail->componentId == position->componentId && rail->posFront <= position->posFront &&
        rail->posFront + rail->frontSpan > position->posFront && rail->posSide <= position->posSide &&
        rail->posSide + rail->sideSpan > position->posSide) {
        return TRUE;
    }
    return FALSE;
}
