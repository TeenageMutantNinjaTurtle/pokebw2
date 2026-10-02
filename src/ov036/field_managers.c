#include "field/field_internal.h"

FieldExpObjSystem *Field_GetExpObjSystem(Field *field) {
    return field->expObjSystem;
}

TCBManager *Field_GetTCBMgr(Field *field) {
    return field->tcbManager;
}

FieldTaskManager *Field_GetTaskManager(Field *field) {
    return field->taskManager;
}
