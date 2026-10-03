#include "field/field_internal.h"
#include "field/zone_data.h"

u32 GetZoneFogIndexAll(Field *field, u16 zoneId) {
    if (zoneId == 0x78 && !func_ov011_02154e70(field->gameData, 0)) {
        return 0xfffffff;
    }
    return GetZoneFogIndex(zoneId);
}

u32 GetObjectProjectionMatrixOffset(u16 zoneId) {
    if (ZoneData_GetObjectProjectionMatrixType(zoneId) == 1) {
        return 0x1ee;
    }
    return 0x136;
}
