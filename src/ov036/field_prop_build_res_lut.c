#include "field/field_prop.h"
#include "gfl/std.h"

void FieldPropSystem_BuildResIDLUT(FieldPropSystem *system, u32 defaultResId) {
    u8 i;
    u8 defaultIndex;
    s32 j;
    FieldPropResInfo *info;

    sys_memset(system->resIdToIndex, 0x80, 0x200);
    for (i = 0; i < system->resInfoCount; i++) {
        info = FieldPropSystem_GetResInfo(system, i);
        system->resIdToIndex[info->resId] = i;
    }
    defaultIndex = system->resIdToIndex[defaultResId];
    for (j = 0; j < 0x200; j++) {
        if (system->resIdToIndex[j] == 0x80) {
            system->resIdToIndex[j] = defaultIndex;
        }
    }
}
