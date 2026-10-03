#include "field/zone.h"

u32 GetActualRespawnZoneIdx(u32 index) {
    if (!RangeCheckTeleportZone(index)) {
        index = GetLeaguePokeCenReturnLocationIdx();
    }
    return index - 1;
}
