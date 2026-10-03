#ifndef POKEBW2_FIELD_ZONE_DATA_H
#define POKEBW2_FIELD_ZONE_DATA_H

#include "types.h"

extern const u8 data_ov036_021ca058[];
extern const u8 data_ov036_021ca060[];

u32 GetZoneFogIndex(u16 zoneId);
u32 ZoneData_GetObjectProjectionMatrixType(u16 zoneId);
u32 GetObjectProjectionMatrixOffset(u16 zoneId);
BOOL func_ov036_021813b8(u16 zoneId);
BOOL IsZoneTwoPassLoad(u16 zoneId);
BOOL func_ov036_0218141c(u16 zoneId);
u32 GetZoneMapType(u16 zoneId);
u32 GetZoneMapType2(u16 zoneId);
void *GetZoneFieldmapCtrlVTable(u16 zoneId);
u32 GetFieldmapZoneHeapSize(u16 zoneId);

#endif // POKEBW2_FIELD_ZONE_DATA_H
