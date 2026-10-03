#include "field/field_prop.h"

void *FieldPropSystem_FindResInfo(FieldPropSystem *system, u32 resId) {
    u32 index = FieldPropSystem_ConvResIDToIndex(system, resId);
    return FieldPropResBundle_GetResInfo(system->resBundle, index);
}

void *FieldPropSystem_GetResInfo(FieldPropSystem *system, u32 index) {
    return FieldPropResBundle_GetResInfo(system->resBundle, index);
}
