#include "field/field_prop.h"
#include "gfl/arc.h"
#include "gfl/heap.h"
#include "gfl/std.h"

void *FieldPropSystem_FindResInfo(FieldPropSystem *system, u32 resId) {
    u32 index = FieldPropSystem_ConvResIDToIndex(system, resId);
    return FieldPropResBundle_GetResInfo(system->resBundle, index);
}

void *FieldPropSystem_GetResInfo(FieldPropSystem *system, u32 index) {
    return FieldPropResBundle_GetResInfo(system->resBundle, index);
}

struct FieldPropDoorResInfo {
    u8 pad[4];
    u16 id;
    s16 x;
    s16 y;
    s16 z;
};

BOOL FieldPropSystem_CheckCreateDoorReq(FieldPropSystem *system, u32 resId, VecFx32 *position, u32 *resIndex) {
    struct FieldPropDoorResInfo *info;
    s32 x;
    s32 y;
    s32 z;

    info = FieldPropSystem_FindResInfo(system, resId);
    if (info->id == 0xffff) {
        return FALSE;
    }
    *resIndex = FieldPropSystem_ConvResIDToIndex(system, info->id);
    x = info->x << 12;
    z = info->z << 12;
    y = info->y << 12;
    position->x = x;
    position->y = y;
    position->z = z;
    return TRUE;
}

struct FieldPropSourceInfo {
    s32 x;
    s32 y;
    s32 z;
    u16 unkC;
    u8 highResId;
    u8 lowResId;
};

struct PropInstanceInfo {
    u32 resIndex;
    s32 x;
    s32 y;
    s32 z;
    u16 unk10;
};

s32 FieldPropSystem_InstantiateProps(FieldPropSystem *system, void *chunk, const FieldPropSourceInfo *infos,
                                     s32 count) {
    struct PropInstanceInfo instance;
    s32 i;
    s32 n;
    u16 resId;

    i = 0;
    n = 0;
    while (i < count) {
        FieldPropSystem_InstantiateFromInfo(system, chunk, &infos[i], n);
        resId = infos[i].lowResId + (infos[i].highResId << 8);
        if (FieldPropSystem_CheckCreateDoorReq(system, resId, (VecFx32 *)&instance.x, &instance.resIndex) == TRUE) {
            instance.unk10 = infos[i].unkC;
            n++;
            instance.x += infos[i].x;
            instance.y += infos[i].y;
            instance.z -= infos[i].z;
            FieldPropSystem_LinkPropToChunk(system, chunk, (u32)&instance, n);
        }
        n++;
        i++;
    }
    return n;
}

void FieldPropSystem_UnlinkChunk(FieldPropSystem *system, void *chunk) {
    FieldPropSystem_ReleaseChunkPropHolders(system, chunk);
}

void FieldPropSystem_InstantiateFromInfo(FieldPropSystem *system, void *chunk, const struct FieldPropSourceInfo *info,
                                         u32 propIndex) {
    struct PropInstanceInfo instance;
    u16 resId;
    s32 x, y, z;

    resId = info->lowResId + (info->highResId << 8);
    instance.resIndex = FieldPropSystem_ConvResIDToIndex(system, resId);
    x = info->x;
    z = -info->z;
    y = info->y;
    instance.x = x;
    instance.y = y;
    instance.z = z;
    instance.unk10 = info->unkC;
    FieldPropSystem_LinkPropToChunk(system, chunk, (u32)&instance, propIndex);
}

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
    u32 count;

    count = (u32)bundle->countFlags >> 1;
    return (u8 *)bundle + bundle->offsets[count + index];
}

void *FieldPropResAnmHeader_GetAnmData(FieldPropResAnmHeader *header, u32 index) {
    return (u8 *)header + header->animationIds[index];
}
