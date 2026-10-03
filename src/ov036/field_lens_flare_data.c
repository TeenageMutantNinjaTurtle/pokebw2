#include "field/field_lens_flare.h"

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

#define RESOURCE_AT(symbol) (*(const u16 *)((const u8 *)(symbol) + effectSet * 12))

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
