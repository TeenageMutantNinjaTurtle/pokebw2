#include "field/field_prop.h"

u32 FieldPropSystem_ConvResIDToIndex(const FieldPropSystem *system, u32 resId) {
    u8 index;

    if (resId >= 0x200) {
        resId = 0;
    }
    index = ((const u8 *)system + resId)[0x1c];
    if (index >= 0x80 || index >= system->resInfoCount) {
        index = 0;
    }
    return index;
}
