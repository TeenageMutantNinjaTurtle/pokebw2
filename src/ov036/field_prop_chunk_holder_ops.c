#include "field/field_prop.h"

void FieldPropSystem_ReleaseChunkPropHolders(FieldPropSystem *system, void *chunk) {
    FieldChunkPropHolder *holders;
    s32 i;

    i = 0;
    holders = system->chunkPropHolders;
    for (; i < 0x120; i++) {
        if (holders[i].chunk == chunk) {
            FieldPropSystem_ReleaseChunkPropHolder(system, &holders[i]);
        }
    }
}

void FieldPropSystem_ReleaseChunkPropHolder(FieldPropSystem *system, FieldChunkPropHolder *holder) {
    FieldChunk_ReleasePropInstance(holder->chunk, holder->propIndex);
    FieldChunkPropHolder_Release(system, holder);
}

u8 FieldChunkPropHolder_GetResIndex(FieldChunkPropHolder *holder) {
    if (holder->instance[0] == 0xffffffff) {
        return holder->savedResIndex;
    }
    return holder->instance[0];
}

void FieldChunkPropHolder_SetVisible(FieldChunkPropHolder *holder, BOOL visible) {
    if (visible) {
        holder->instance[0] = holder->savedResIndex;
        holder->savedResIndex = 0xffffffff;
        holder->visible = 1;
    } else {
        holder->savedResIndex = holder->instance[0];
        holder->instance[0] = 0xffffffff;
        holder->visible = 0;
    }
}

void FieldChunkPropHolder_ChangeResID(FieldPropSystem *system, FieldChunkPropHolder *holder, u32 resId) {
    holder->instance[0] = FieldPropSystem_ConvResIDToIndex(system, resId);
}
