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

FieldPropHandle *FieldPropSystem_FindHandleByID(FieldPropSystem *system, u32 id) {
    u16 index;
    u16 marker;

    index = id & 0xffff000f;
    marker = id & 0xfff0;
    if (marker != 0xfff0) {
        return NULL;
    }
    if (index >= 7) {
        return NULL;
    }
    return system->handles[index];
}

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
