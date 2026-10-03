#include "field/event_data.h"
#include "field/zone.h"

struct ZoneWarp {
    u8 unk0[0x14];
};

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
