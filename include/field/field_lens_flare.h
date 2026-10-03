#ifndef POKEBW2_FIELD_FIELD_LENS_FLARE_H
#define POKEBW2_FIELD_FIELD_LENS_FLARE_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

typedef struct FieldLensFlareEntry {
    u16 zoneId;
    u16 transitId;
    u16 effectSetIds[4][3];
} FieldLensFlareEntry;

typedef struct FieldLensFlareData {
    u32 byteCount;
    FieldLensFlareEntry *entries;
} FieldLensFlareData;

struct FieldLensFlare {
    FieldExpObjSystem *expObjSys;
    u32 requested;
    u32 active;
    FieldLensFlareData *data;
    u32 state;
    FieldLensFlareData *ownedData;
    u32 unk18;
    u16 effectId;
};

extern const u16 data_ov036_021d4768[][4];
extern const char data_ov036_021d5728[];
extern const u16 LENS_FLARE_RESOURCE_IDS[];
extern const u16 data_ov036_021d47ba[];
extern const u16 data_ov036_021d47bc[];
extern const u16 data_ov036_021d47be[];
extern const u16 data_ov036_021d47c0[];

FieldLensFlareData *FieldLensFlareData_Create(HeapID heapId);
void FieldLensFlareData_Free(FieldLensFlareData *data);
void FieldLensFlare_Free(FieldLensFlare *lensFlare);
void FieldLensFlare_RequestStart(FieldLensFlare *lensFlare);
void FieldLensFlare_GreenlightStart(FieldLensFlare *lensFlare);
void FieldLensFlare_Cancel(FieldLensFlare *lensFlare);
u8 FieldLensFlare_GetSubIndexForDayPeriod(u32 period);
u16 FieldLensFlare_GetEffectSetID(FieldLensFlareData *data, u32 entryIndex, u32 effectIndex, u32 subIndex);
u32 FieldLensFlareData_BytesToEntryCount(FieldLensFlareData *data);
u16 FieldLensFlareData_GetLensFlareID(FieldLensFlareData *data, u32 effectSet, u32 index);
u8 FieldLensFlareData_GetEffectSetSize(FieldLensFlareData *data, u32 effectSet);
u16 FieldLensFlareData_GetResDatID(FieldLensFlareData *data, u32 effectSet, u32 index);
FieldLensFlareEntry *FieldLensFlareData_GetEntry(FieldLensFlareData *data, u32 index);
u32 FieldLensFlareData_GetIdxForZoneTransit(FieldLensFlareData *data, u16 zoneId, u16 transitId);

#endif // POKEBW2_FIELD_FIELD_LENS_FLARE_H
