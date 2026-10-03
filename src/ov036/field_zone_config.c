#include "field/field_internal.h"
#include "field/field_map.h"
#include "field/zone.h"
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

BOOL func_ov036_021813b8(u16 zoneId) {
    if (zoneId == 0x249) {
        return FALSE;
    }
    if (IsZone150Or151(zoneId) == TRUE) {
        return FALSE;
    }
    if (zoneId == 0xf1) {
        return FALSE;
    }
    if (zoneId == 0xf2) {
        return FALSE;
    }
    if (zoneId == 0xf3) {
        return FALSE;
    }
    if (zoneId == 0xf4) {
        return FALSE;
    }
    return TRUE;
}

BOOL IsZoneTwoPassLoad(u16 zoneId) {
    if (zoneId == 0x6c)
        return TRUE;
    if (zoneId == 0x249)
        return TRUE;
    if (zoneId == 0x8f)
        return TRUE;
    return FALSE;
}

BOOL func_ov036_0218141c(u16 zoneId) {
    if (zoneId == 0x1de) {
        goto match;
    }
    if (zoneId != 0x1df) {
        goto noMatch;
    }
match:
    return TRUE;
noMatch:
    return FALSE;
}

u32 GetZoneMapType2(u16 zoneId) {
    return GetZoneMapType(zoneId);
}

struct ZoneMapTypeData {
    u8 bytes[0x14];
    u16 width;
    u16 height;
    u32 count;
    u32 *chunkIDs;
    u32 unk20;
    u32 unk24;
    u32 texSetId;
    u32 srtAnmId;
    u32 patAnmId;
    u8 tail[8];
};

void SetupLoadZoneMapTypeData(u16 zoneId, AreaData *area, struct ZoneMapTypeData *out, MapMatrix *matrix) {
    u32 type;
    const u8 *src;

    type = GetZoneMapType2(zoneId);
    src = MAP_CONFIGS + 0x48 * type;
    *out = *(const struct ZoneMapTypeData *)src;
    if (*(const u32 *)(data_ov036_021ca05c + 0x48 * type) != 0) {
        out->width = GetMapMatrixWidth(matrix);
        out->height = GetMapMatrixHeight(matrix);
        out->count = GetMapMatrixChunkIDCount(matrix);
        out->chunkIDs = GetMapMatrixChunkIDs(matrix);
    }
    out->unk20 = 1;
    out->unk24 = 14;
    out->texSetId = AreaData_GetTexSetID(area);
    out->srtAnmId = AreaData_GetSRTAnmID(area);
    out->patAnmId = AreaData_GetPatAnmID(area);
}

void *GetZoneFieldmapCtrlVTable(u16 zoneId) {
    return *(void *const *)(data_ov036_021ca058 + 0x48 * GetZoneMapType2(zoneId));
}

u32 GetFieldmapZoneHeapSize(u16 zoneId) {
    return *(const u32 *)(data_ov036_021ca060 + 0x48 * GetZoneMapType2(zoneId));
}
