#include "field/event_data.h"
#include "field/zone.h"

BOOL CheckWarpDirectionMatch(const ZoneWarp *warp, u16 direction) {
    if ((direction == 0 && warp->unk4 == 2) || (direction == 1 && warp->unk4 == 1) ||
        (direction == 2 && warp->unk4 == 4) || (direction == 3 && warp->unk4 == 3)) {
        return TRUE;
    }
    return FALSE;
}

u32 GetWarpTransitionType(ZoneWarp *warp) {
    return warp->transitionType;
}

BOOL IsWarpZoneOrWarpID0xFFFF(const ZoneWarp *warp) {
    return warp->unk0 == 0xffff || warp->destId == 0xffff;
}

void SetZoneWarpLocation(EventData *data, u16 warpId, u16 x, u16 y, u16 z) {
    ZoneWarp *warps;

    if (data->warpCount < warpId) {
        return;
    }
    warps = data->warpPtr;
    if (warps == NULL) {
        return;
    }
    warps = &warps[warpId];
    if (warps->isRail != 0) {
        return;
    }
    ZoneWarpGridPosition *pos = &warps->gridPos;
    pos->x = x * 16 + 8;
    pos->y = y * 16;
    pos->z = z * 16 + 8;
}