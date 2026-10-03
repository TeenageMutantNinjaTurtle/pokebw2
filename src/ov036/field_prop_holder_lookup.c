#include "field/field_prop.h"
#include "gfl/heap.h"

FieldChunkPropHolder *FieldPropSystem_FindProp(FieldPropSystem *system, u32 propId, const FieldPropAreaBounds *bounds) {
    u32 count;
    FieldChunkPropHolder **holders;
    FieldChunkPropHolder *holder;

    holders = FieldPropSystem_FindPropsInArea(system, bounds, propId, &count);
    holder = holders[0];
    GFL_HeapFree(holders);
    return holder;
}

FieldChunkPropHolder *FieldPropSystem_FindPropAtPos(FieldPropSystem *system, u32 propId, const VecFx32 *position) {
    FieldPropAreaBounds bounds;

    FieldPropSearchArea_Set(&bounds, position);
    return FieldPropSystem_FindProp(system, propId, &bounds);
}

u8 FieldChunkPropHolder_GetPropType(FieldPropSystem *system, FieldChunkPropHolder *holder) {
    u32 index = FieldChunkPropHolder_GetResIndex(holder);
    if (index >= 0x80 || index >= system->resInfoCount) {
        index = 0;
    }
    return FieldPropResInfo_GetTypeConv(FieldPropSystem_GetResInfo(system, index));
}

void FieldChunkPropHolder_CallAnmCmd(FieldPropSystem *system, FieldChunkPropHolder *holder, u32 animation,
                                     u32 command) {
    u32 index = FieldChunkPropHolder_GetResIndex(holder);
    if (index >= 0x80 || index >= system->resInfoCount) {
        index = 0;
    }
    FieldPropResInstance_CallAnmCmd((u8 *)system->resInstances + 0x18 * index, animation, command);
}

void FieldChunkPropHolder_GetPosAbs(FieldChunkPropHolder *holder, VecFx32 *position) {
    VecFx32 chunkPos;
    FieldChunk_GetWorldPos(holder->chunk, &chunkPos);
    VEC_Add((VecFx32 *)((u8 *)holder->instance + 4), &chunkPos, position);
}
