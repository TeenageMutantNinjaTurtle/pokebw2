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
