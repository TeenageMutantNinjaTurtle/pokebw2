#include "field/field_prop.h"
#include "gfl/g3d.h"

void FieldPropHandle_CallAnmCmd(FieldPropHandle *handle, u32 animation, u32 command) {
    if (handle != NULL) {
        handle->animation = animation;
        FieldPropResInstance_CallAnmCmd(&handle->instance, animation, command);
    }
}

void FieldPropHandle_CallAnmCmdSilent(FieldPropHandle *handle, u32 command) {
    if (handle != NULL) {
        FieldPropResInstance_CallAnmCmd(&handle->instance, handle->animation, command);
    }
}

BOOL FieldPropHandle_IsAnmFinished(FieldPropHandle *handle) {
    if (handle == NULL) {
        return TRUE;
    }
    if (FieldPropHandle_IsCurrentAnmIdle(handle) == TRUE) {
        FieldPropHandle_CallAnmCmdSilent(handle, 3);
        return TRUE;
    }
    return FALSE;
}

BOOL FieldPropHandle_IsAnmIdle(FieldPropHandle *handle, u32 animation) {
    if (handle == NULL) {
        return FALSE;
    }
    return FieldPropResInstance_IsAnmIdle(&handle->instance, animation);
}

BOOL FieldPropHandle_IsCurrentAnmIdle(FieldPropHandle *handle) {
    if (handle == NULL) {
        return FALSE;
    }
    return FieldPropResInstance_IsAnmIdle(&handle->instance, handle->animation);
}

u16 FieldPropHandle_GetPropType(FieldPropHandle *handle) {
    if (handle == NULL) {
        return 0;
    }
    return (*handle->instance.resInfoRef)->type;
}

void FieldPropHandle_Draw(FieldPropHandle *handle) {
    if (handle != NULL) {
        GFL_G3DSysDrawObjBBoxCull(handle->instance.drawObject, (SRTMatrix *)&handle->transform);
    }
}
