#include "types.h"
#include "field/field_chunk.h"
#include "gfl/g3d.h"
#include "nitro/fx.h"

void FieldChunk_SetActive(FieldChunk *chunk, u16 active) {
    chunk->active = active;
}

u16 FieldChunk_IsActive(FieldChunk *chunk) {
    return chunk->active;
}

void FieldChunk_SetWorldPos(FieldChunk *chunk, const VecFx32 *position) {
    chunk->worldPos = *position;
}

void FieldChunk_GetWorldPos(FieldChunk *chunk, VecFx32 *position) {
    *position = chunk->worldPos;
}

void FieldChunk_GetLoaderHandle(FieldChunk *chunk, FieldChunkLoader **handle) {
    *handle = &chunk->loader;
}

void GetChunkRawDataContainer(FieldChunk *chunk, void **container) {
    *container = chunk->container;
}

void FieldChunk_GetDatID(FieldChunk *chunk, u32 *datID) {
    *datID = chunk->reqLoadDatID;
}

void FieldChunk_GetRawDataLength(FieldChunk *chunk, u32 *length) {
    *length = chunk->loader.totalRawLength;
}

void FieldChunk_BindModel(FieldChunk *chunk, void *model) {
    GFL_G3DResBindData(chunk->modelRsc, 1, model);
}

void FieldChunk_UnbindModel(FieldChunk *chunk) {
    GFL_G3DResBindData(chunk->modelRsc, 1, NULL);
}

void *FieldChunk_GetModelResource(FieldChunk *chunk) {
    return chunk->modelRsc;
}

void FieldChunk_FreeTexRsc(FieldChunk *chunk) {
    GFL_G3DResBindData(chunk->texRsc, 2, NULL);
}

void *FieldChunk_GetUsedTexRsc(FieldChunk *chunk) {
    return FieldChunk_GetUsedTexRscCore(chunk);
}

void FieldChunk_SetupModel(FieldChunk *chunk) {
    void *texture = FieldChunk_GetUsedTexRscCore(chunk);
    FieldChunk_LinkMdlTex(chunk->model, chunk->modelRsc, texture);
}

NNSG3dRenderObj *FieldChunk_GetModel(FieldChunk *chunk) {
    return chunk->model;
}

void FieldChunk_ResetStreamer(FieldChunk *chunk) {
    chunk->loader.nowLoadedLength = 0;
    chunk->loader.unk10 = 0;
    chunk->loader.unk18 = 0;
    chunk->loader.unk1c = 0;
    chunk->loader.terrainLoadDone = 0;
}
