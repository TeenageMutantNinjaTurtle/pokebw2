#include "field/field_controller.h"

u32 FieldmapCtrlHybrid_GetActiveTypeID(void *controller) {
    return *(u32 *)controller;
}
