#include "field/zone_data.h"

void *GetZoneFieldmapCtrlVTable(u16 zoneId) {
    return *(void *const *)(data_ov036_021ca058 + 0x48 * GetZoneMapType2(zoneId));
}

u32 GetFieldmapZoneHeapSize(u16 zoneId) {
    return *(const u32 *)(data_ov036_021ca060 + 0x48 * GetZoneMapType2(zoneId));
}
