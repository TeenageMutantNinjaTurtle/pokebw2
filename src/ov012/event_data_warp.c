#include "field/event_data.h"
#include "field/field_actor.h"
#include "field/zone.h"

s32 GetWarpAtPosition(EventData *data, const VecFx32 *position) {
    s32 index;
    ZoneWarp *warp = data->warpPtr;

    for (index = 0; index < data->warpCount; index++, warp++) {
        if (CheckWarpPositionMatch(warp, position)) {
            return index;
        }
    }
    return 0xffff;
}

s32 GetWarpIDByPlayerPos(EventData *data, const VecFx32 *position, u16 direction) {
    VecFx32 front = *position;
    s32 index;
    ZoneWarp *warp = data->warpPtr;

    ExpandVecInGridDir(direction, &front, 0x10000);
    for (index = 0; index < data->warpCount; index++, warp++) {
        if (warp->transitionType == 1) {
            if (!IsWarpZoneOrWarpID0xFFFF(warp) && CheckWarpPositionMatch(warp, position) == TRUE) {
                return index;
            }
        } else {
            if (CheckWarpDirectionMatch(warp, direction) == TRUE && CheckWarpPositionMatch(warp, &front) == TRUE) {
                return 1;
            }
        }
    }
    return 0xffff;
}

s32 GetWarpIDByPlayerPosRail(EventData *data, const RailPosition *position) {
    s32 index;
    ZoneWarp *warp = data->warpPtr;

    for (index = 0; index < data->warpCount; index++, warp++) {
        if (CheckWarpPositionMatchRail(warp, position)) {
            return index;
        }
    }
    return 0xffff;
}

ZoneWarp *GetZoneWarpByID(EventData *data, u16 warpId) {
    ZoneWarp *warps = data->warpPtr;

    if (warps == NULL) {
        return NULL;
    }
    if (warpId >= data->warpCount) {
        return NULL;
    }
    return &warps[warpId];
}

BOOL IsWarpDestId256(ZoneWarp *warp) {
    return warp->destId == 0x100;
}
