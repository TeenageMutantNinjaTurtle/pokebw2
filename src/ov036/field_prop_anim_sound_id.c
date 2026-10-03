#include "field/field_prop.h"

BOOL FieldPropHandle_GetAnimSoundID(FieldPropHandle *handle, u16 *soundId) {
    if (handle == NULL) {
        return FALSE;
    }
    return FieldPropHandle_GetAnimSoundIDCore(handle, handle->animation, soundId);
}
