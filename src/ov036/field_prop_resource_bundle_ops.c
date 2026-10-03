#include "field/field_prop.h"
#include "gfl/arc.h"
#include "gfl/heap.h"
#include "gfl/std.h"

void *FieldPropSystem_GetResBank(FieldPropSystem *system) {
    return system->unk220;
}

void FieldPropSystem_LoadResBundle(FieldPropSystem *system, u32 arcId, u32 fileId) {
    ArcTool *arc;
    u32 count;

    arc = GFL_ArcSysCreateFileHandle(arcId, HEAPID_TAIL(system->heapId));
    if (GFL_ArcToolGetDataMax(arc) <= fileId) {
        fileId = 0;
    }
    system->resBundle = GFL_ArcToolReadHeapNew(arc, fileId, system->heapId);
    count = (u32)system->resBundle->countFlags >> 1;
    system->resInfoCount = count;
    if (count > 0x200) {
        system->resInfoCount = 0x80;
    }
    GFL_ArcToolFree(arc);
}

void FieldPropSystem_FreeResBundle(FieldPropSystem *system) {
    GFL_HeapFree(system->resBundle);
    system->resInfoCount = 0;
}

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
