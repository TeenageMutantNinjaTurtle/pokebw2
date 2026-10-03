#include "field/event_data.h"
#include "field/zone.h"

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
