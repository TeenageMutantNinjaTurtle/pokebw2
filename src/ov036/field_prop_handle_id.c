#include "field/field_prop.h"

u16 FieldPropSystem_GetHandleID(FieldPropSystem *system, FieldPropHandle *handle) {
    s32 i;

    if (handle == NULL) {
        return 0;
    }
    for (i = 0; i < 7; i++) {
        if (system->handles[i] == handle) {
            return 0xfff0 | i;
        }
    }
    return 0;
}
