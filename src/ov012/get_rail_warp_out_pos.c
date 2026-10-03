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
