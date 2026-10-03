#include "field/field_prop.h"

BOOL FieldPropHandle_GetAnimSoundIDCore(FieldPropHandle *handle, u32 animation, u16 *soundId) {
    u32 type;
    u32 i;

    if (handle == NULL) {
        return FALSE;
    }
    type = FieldPropHandle_GetPropType(handle);
    *soundId = 0;
    if (animation >= 4) {
        return FALSE;
    }
    for (i = 0; i < 6; i++) {
        if (type == DOOR_SOUND_ID_LUT[i][0]) {
            *soundId = *(const u16 *)(data_ov036_021ca8e6 + i * 10 + animation * 2);
            return TRUE;
        }
    }
    return FALSE;
}

BOOL FieldPropHandle_GetAnimSoundID(FieldPropHandle *handle, u16 *soundId) {
    if (handle == NULL) {
        return FALSE;
    }
    return FieldPropHandle_GetAnimSoundIDCore(handle, handle->animation, soundId);
}
