#include "field/field_chunk.h"
#include "gfl/g3d.h"

void FieldChunk_SetActive(FieldChunk *chunk, u16 active) {
    *(u16 *)chunk = active;
}

u16 FieldChunk_IsActive(FieldChunk *chunk) {
    return *(u16 *)chunk;
}

void FieldChunk_SetWorldPos(FieldChunk *chunk, const VecFx32 *position) {
    *(VecFx32 *)((u8 *)chunk + 4) = *position;
}

void FieldChunk_GetWorldPos(FieldChunk *chunk, VecFx32 *position) {
    *position = *(VecFx32 *)((u8 *)chunk + 4);
}

void FieldChunk_GetLoaderHandle(FieldChunk *chunk, void **handle) {
    *handle = (u8 *)chunk + 0xb0;
}

void GetChunkRawDataContainer(FieldChunk *chunk, void **container) {
    *container = *(void **)((u8 *)chunk + 0xd4);
}

void FieldChunk_GetDatID(FieldChunk *chunk, u32 *datID) {
    *datID = *(u32 *)((u8 *)chunk + 0x14);
}

void FieldChunk_GetRawDataLength(FieldChunk *chunk, u32 *length) {
    *length = *(u32 *)((u8 *)chunk + 0xbc);
}

void FieldChunk_BindModel(FieldChunk *chunk, void *model) {
    GFL_G3DResBindData(*(void **)((u8 *)chunk + 0x84), 1, model);
}

void FieldChunk_UnbindModel(FieldChunk *chunk) {
    GFL_G3DResBindData(*(void **)((u8 *)chunk + 0x84), 1, NULL);
}

void *FieldChunk_GetModelResource(FieldChunk *chunk) {
    return *(void **)((u8 *)chunk + 0x84);
}

void FieldChunk_FreeTexRsc(FieldChunk *chunk) {
    GFL_G3DResBindData(*(void **)((u8 *)chunk + 0x88), 2, NULL);
}

void *FieldChunk_GetUsedTexRsc(FieldChunk *chunk) {
    return FieldChunk_GetUsedTexRscCore(chunk);
}

void FieldChunk_SetupModel(FieldChunk *chunk) {
    void *texture = FieldChunk_GetUsedTexRscCore(chunk);
    FieldChunk_LinkMdlTex(*(void **)((u8 *)chunk + 0x2c), *(void **)((u8 *)chunk + 0x84), texture);
}

void *FieldChunk_GetModel(FieldChunk *chunk) {
    return *(void **)((u8 *)chunk + 0x2c);
}

void FieldChunk_ResetStreamer(FieldChunk *chunk) {
    *(u32 *)((u8 *)chunk + 0xb4) = 0;
    *(u32 *)((u8 *)chunk + 0xc0) = 0;
    *(u32 *)((u8 *)chunk + 0xc8) = 0;
    *(u32 *)((u8 *)chunk + 0xcc) = 0;
    *(u32 *)((u8 *)chunk + 0xd0) = 0;
}
