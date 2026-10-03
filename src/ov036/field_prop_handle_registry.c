#include "field/field_prop.h"

void FieldPropSystem_DeleteHandle(FieldPropSystem *system, FieldPropHandle *handle) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (system->handles[i] == handle) {
            system->handles[i] = NULL;
            return;
        }
    }
}

void FieldPropSystem_RegistHandle(FieldPropSystem *system, FieldPropHandle *handle) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (system->handles[i] == NULL) {
            system->handles[i] = handle;
            return;
        }
    }
}
