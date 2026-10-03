#ifndef POKEBW2_FIELD_ZONE_DATA_H
#define POKEBW2_FIELD_ZONE_DATA_H

#include "types.h"

u32 GetZoneFogIndex(u16 zoneId);
u32 ZoneData_GetObjectProjectionMatrixType(u16 zoneId);
u32 GetObjectProjectionMatrixOffset(u16 zoneId);
BOOL IsZoneTwoPassLoad(u16 zoneId);
u32 GetZoneMapType(u16 zoneId);
u32 GetZoneMapType2(u16 zoneId);

#endif // POKEBW2_FIELD_ZONE_DATA_H
