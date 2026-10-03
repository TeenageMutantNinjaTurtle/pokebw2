#ifndef POKEBW2_FIELD_FIELD_LENS_FLARE_H
#define POKEBW2_FIELD_FIELD_LENS_FLARE_H

#include "types.h"
#include "gfl/heap.h"

typedef struct FieldLensFlareEntry {
    u16 zoneId;
    u16 transitId;
    u16 effectSetIds[4][3];
} FieldLensFlareEntry;

typedef struct FieldLensFlareData {
    u32 byteCount;
    FieldLensFlareEntry *entries;
} FieldLensFlareData;

extern const u16 data_ov036_021d4768[][4];
extern const char data_ov036_021d5728[];

FieldLensFlareData *FieldLensFlareData_Create(HeapID heapId);
void FieldLensFlareData_Free(FieldLensFlareData *data);
u16 FieldLensFlare_GetEffectSetID(FieldLensFlareData *data, u32 entryIndex, u32 effectIndex, u32 subIndex);
u32 FieldLensFlareData_BytesToEntryCount(FieldLensFlareData *data);
u16 FieldLensFlareData_GetLensFlareID(FieldLensFlareData *data, u32 effectSet, u32 index);
u8 FieldLensFlareData_GetEffectSetSize(FieldLensFlareData *data, u32 effectSet);
FieldLensFlareEntry *FieldLensFlareData_GetEntry(FieldLensFlareData *data, u32 index);
u32 FieldLensFlareData_GetIdxForZoneTransit(FieldLensFlareData *data, u16 zoneId, u16 transitId);

#endif // POKEBW2_FIELD_FIELD_LENS_FLARE_H
