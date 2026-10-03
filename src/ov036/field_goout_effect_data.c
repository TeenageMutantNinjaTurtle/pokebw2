#include "types.h"
#include "field/field_lens_flare.h"
#include "gfl/arc.h"
#include "gfl/heap.h"
#include "system/aeabi.h"

#define RESOURCE_AT(symbol) (*(const u16 *)((const u8 *)(symbol) + effectSet * 12))

FieldLensFlareData *FieldLensFlareData_Create(HeapID heapId) {
    FieldLensFlareData *data;

    data = GFL_HeapAllocate(heapId, sizeof(FieldLensFlareData), TRUE, "field_goout_effect_data.c", 57);
    data->entries = GFL_ArcSysReadHeapNewLZGetLen(0xf1, 0, 0, heapId, &data->byteCount);
    return data;
}

void FieldLensFlareData_Free(FieldLensFlareData *data) {
    GFL_HeapFree(data->entries);
    GFL_HeapFree(data);
}

u16 FieldLensFlare_GetEffectSetID(FieldLensFlareData *data, u32 entryIndex, u32 effectIndex, u32 subIndex) {
    FieldLensFlareEntry *entry;

    entry = FieldLensFlareData_GetEntry(data, entryIndex);
    return entry->effectSetIds[effectIndex][subIndex];
}

u32 FieldLensFlareData_BytesToEntryCount(FieldLensFlareData *data) {
    return __aeabi_uidivmod(data->byteCount, sizeof(FieldLensFlareEntry));
}

u16 FieldLensFlareData_GetLensFlareID(FieldLensFlareData *data, u32 effectSet, u32 index) {
    return data_ov036_021d4768[effectSet][index];
}

u8 FieldLensFlareData_GetEffectSetSize(FieldLensFlareData *data, u32 effectSet) {
    int index;

    for (index = 0; index < 4; index++) {
        if (FieldLensFlareData_GetLensFlareID(data, effectSet, index) == 8) {
            break;
        }
    }
    return index;
}

u16 FieldLensFlareData_GetResDatID(FieldLensFlareData *data, u32 effectSet, u32 index) {
    switch (index) {
    case 0:
        return RESOURCE_AT(LENS_FLARE_RESOURCE_IDS);
    case 1:
        return RESOURCE_AT(data_ov036_021d47ba);
    case 2:
        return RESOURCE_AT(data_ov036_021d47bc);
    case 3:
        return RESOURCE_AT(data_ov036_021d47be);
    case 4:
        return RESOURCE_AT(data_ov036_021d47c0);
    default:
        return 0;
    }
}

FieldLensFlareEntry *FieldLensFlareData_GetEntry(FieldLensFlareData *data, u32 index) {
    return &data->entries[index];
}

u32 FieldLensFlareData_GetIdxForZoneTransit(FieldLensFlareData *data, u16 zoneId, u16 transitId) {
    u32 index;
    FieldLensFlareEntry *entry;

    index = 0;
    while (index < FieldLensFlareData_BytesToEntryCount(data)) {
        entry = FieldLensFlareData_GetEntry(data, index);
        if (entry->zoneId == zoneId && entry->transitId == transitId) {
            break;
        }
        index++;
    }
    return index;
}
