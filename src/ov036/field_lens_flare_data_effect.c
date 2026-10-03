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
