#include "field/field_prop.h"
#include "gfl/heap.h"

void FieldPropSystem_Free(FieldPropSystem *system) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (system->handles[i] != NULL) {
            FieldPropHandle_Free(system->handles[i]);
        }
    }
    FieldPropSystem_FreeResInstances(system, system->unk220);
    FieldPropSystem_FreeResources(system);
    FieldPropSystem_FreeResBundle(system);
    FieldPropSystem_FreeTextures(system);
    GFL_HeapFree(system);
}

void FieldPropSystem_Update(FieldPropSystem *system) {
    s32 i;
    u32 j;

    FieldPropRTCState_Update(&system->rtcState);
    for (i = 0; i < 7; i++) {
        if (system->handles[i] != NULL) {
            FieldPropSystem_UpdateResInstance(system, &system->handles[i]->instance);
        }
    }
    for (j = 0; j < system->resInstanceCount; j++) {
        FieldPropSystem_UpdateResInstance(system, (u8 *)system->resInstances + 0x18 * j);
    }
}

void FieldPropSystem_DrawAllHandles(FieldPropSystem *system) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (system->handles[i] != NULL) {
            FieldPropHandle_Draw(system->handles[i]);
        }
    }
}
