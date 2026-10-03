#ifndef POKEBW2_FIELD_FIELD_CHUNK_H
#define POKEBW2_FIELD_FIELD_CHUNK_H

#include "types.h"
#include "nitro/fx.h"
#include "struct_decls.h"

void FieldChunk_ReleasePropInstance(FieldChunk *chunk, u16 propIndex);
void FieldChunk_SetActive(FieldChunk *chunk, u16 active);
u16 FieldChunk_IsActive(FieldChunk *chunk);
void FieldChunk_SetWorldPos(FieldChunk *chunk, const VecFx32 *position);
void FieldChunk_GetWorldPos(FieldChunk *chunk, VecFx32 *position);
void FieldChunk_GetLoaderHandle(FieldChunk *chunk, void **handle);
void GetChunkRawDataContainer(FieldChunk *chunk, void **container);
void FieldChunk_GetDatID(FieldChunk *chunk, u32 *datID);
void FieldChunk_GetRawDataLength(FieldChunk *chunk, u32 *length);
void FieldChunk_BindModel(FieldChunk *chunk, void *model);
void FieldChunk_UnbindModel(FieldChunk *chunk);
void *FieldChunk_GetModelResource(FieldChunk *chunk);
void FieldChunk_FreeTexRsc(FieldChunk *chunk);
void *FieldChunk_GetUsedTexRsc(FieldChunk *chunk);
void FieldChunk_SetupModel(FieldChunk *chunk);
void *FieldChunk_GetModel(FieldChunk *chunk);
void FieldChunk_ResetStreamer(FieldChunk *chunk);

void *FieldChunk_GetUsedTexRscCore(FieldChunk *chunk);
void FieldChunk_LinkMdlTex(void *model, void *resource, void *texture);

#endif // POKEBW2_FIELD_FIELD_CHUNK_H
