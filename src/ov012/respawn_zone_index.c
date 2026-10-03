#include "field/zone.h"

u32 GetLeaguePokeCenReturnLocationIdx(void) {
    return 1;
}

BOOL RangeCheckTeleportZone(s32 index) {
    if (index <= 0 || (u32)index > 0x52) {
        return FALSE;
    }
    return TRUE;
}

u16 GetRespawnZoneMainZone(u16 index) {
    return RESPAWN_ZONE_INFO[GetActualRespawnZoneIdx(index)].mainZoneId;
}
