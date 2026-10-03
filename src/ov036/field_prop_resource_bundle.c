#include "field/field_prop.h"

void *FieldPropResBundle_GetResInfo(FieldPropResBundle *bundle, u32 index) {
    return (u8 *)bundle + bundle->offsets[index];
}

void *FieldPropResBundle_GetModelData(FieldPropResBundle *bundle, u32 index) {
    u32 count = (u32)bundle->countFlags >> 1;
    return (u8 *)bundle + bundle->offsets[count + index];
}

void *FieldPropResAnmHeader_GetAnmData(FieldPropResAnmHeader *header, u32 index) {
    return (u8 *)header + header->animationIds[index];
}
