#include "field/field_lens_flare.h"

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
