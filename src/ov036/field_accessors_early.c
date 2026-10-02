#include "field/field_internal.h"

void *Field_GetMsgBGSys(Field *field) {
    return field->msgBGSys;
}

FieldCamera *Field_GetCameraSystem(Field *field) {
    return field->cameraSystem;
}

NoGridMapper *Field_GetNoGridMapper(Field *field) {
    return field->noGridMapper;
}
