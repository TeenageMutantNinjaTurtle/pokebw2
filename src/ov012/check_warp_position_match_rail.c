#include "field/zone.h"

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
