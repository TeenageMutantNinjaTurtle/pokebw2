#include "field/field_controller.h"
#include "field/field_internal.h"

static const u8 sResolvedControllerTypes[4] = { 0, 1, 2, 0 };

u32 Field_GetControllerTypeID(Field *field) {
    return *field->controllerTypeID;
}

u32 Field_GetResolvedControllerTypeID(Field *field) {
    u32 type = sResolvedControllerTypes[*field->controllerTypeID];
    if (type == 2) {
        type = FieldmapCtrlHybrid_GetActiveTypeID(field->controller);
    }
    return type;
}
