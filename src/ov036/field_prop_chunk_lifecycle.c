#include "field/field_prop.h"

void FieldPropSystem_UnlinkChunk(FieldPropSystem *system, void *chunk) {
    FieldPropSystem_ReleaseChunkPropHolders(system, chunk);
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

void FieldPropSystem_InstantiateFromInfo(FieldPropSystem *system, void *chunk, const struct FieldPropSourceInfo *info,
                                         u32 propIndex) {
    struct PropInstanceInfo instance;
    u16 resId;

    resId = info->lowResId + (info->highResId << 8);
    instance.resIndex = FieldPropSystem_ConvResIDToIndex(system, resId);
    s32 x, y, z;
    x = info->x;
    z = -info->z;
    y = info->y;
    instance.x = x;
    instance.y = y;
    instance.z = z;
    instance.unk10 = info->unkC;
    FieldPropSystem_LinkPropToChunk(system, chunk, (u32)&instance, propIndex);
}
