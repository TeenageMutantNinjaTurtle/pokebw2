#include "field/field_prop.h"

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
