#ifndef POKEBW2_FIELD_FIELD_CHUNK_H
#define POKEBW2_FIELD_FIELD_CHUNK_H

#include "types.h"
#include "gfl/g3d.h"
#include "nitro/fx.h"
#include "struct_decls.h"

// Layouts from swan's field_map_chunk.h.
typedef struct {
    u16 state;
    u16 pad02;
    u32 nowLoadedLength;
    u32 bufferLoadedLength;
    u32 totalRawLength;
    BOOL unk10;
    BOOL unk14;
    BOOL unk18;
    BOOL unk1c;
    BOOL terrainLoadDone;
} FieldChunkLoader;

struct FieldChunk {
    u16 active;
    u16 disableStreamer;
    VecFx32 worldPos;
    ArcTool *arc;
    u32 reqLoadDatID;
    u32 vtableIndex;
    u32 bufferSize;
    u32 textureVRAMSize;
    u32 streamerBufSize;
    void *vtable;
    NNSG3dRenderObj *model;
    NNSG3dRenderObj modelObj;
    void *modelRsc;
    void *texRsc;
    u32 textureVRAM;
    u32 paletteVRAM;
    void *mapTextures;
    void *propResBank;
    void *propInstances;
    void *propInstances2;
    u16 propCapacity1;
    u16 propCapacity2;
    u32 unkA8;
    u32 unkAC;
    FieldChunkLoader loader;
    void *container;
    void *context;
};

void FieldChunk_ReleasePropInstance(FieldChunk *chunk, u16 propIndex);
void FieldChunk_SetActive(FieldChunk *chunk, u16 active);
u16 FieldChunk_IsActive(FieldChunk *chunk);
void FieldChunk_SetWorldPos(FieldChunk *chunk, const VecFx32 *position);
void FieldChunk_GetWorldPos(FieldChunk *chunk, VecFx32 *position);
void FieldChunk_GetLoaderHandle(FieldChunk *chunk, FieldChunkLoader **handle);
void GetChunkRawDataContainer(FieldChunk *chunk, void **container);
void FieldChunk_GetDatID(FieldChunk *chunk, u32 *datID);
void FieldChunk_GetRawDataLength(FieldChunk *chunk, u32 *length);
void FieldChunk_BindModel(FieldChunk *chunk, void *model);
void FieldChunk_UnbindModel(FieldChunk *chunk);
void *FieldChunk_GetModelResource(FieldChunk *chunk);
void FieldChunk_FreeTexRsc(FieldChunk *chunk);
void *FieldChunk_GetUsedTexRsc(FieldChunk *chunk);
void FieldChunk_SetupModel(FieldChunk *chunk);
NNSG3dRenderObj *FieldChunk_GetModel(FieldChunk *chunk);
void FieldChunk_ResetStreamer(FieldChunk *chunk);

void *FieldChunk_GetUsedTexRscCore(FieldChunk *chunk);
void FieldChunk_LinkMdlTex(NNSG3dRenderObj *model, void *resource, void *texture);

#endif // POKEBW2_FIELD_FIELD_CHUNK_H
