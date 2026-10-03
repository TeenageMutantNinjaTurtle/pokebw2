#include "field/field_lens_flare.h"

FieldLensFlareEntry *FieldLensFlareData_GetEntry(FieldLensFlareData *data, u32 index) {
    return &data->entries[index];
}
