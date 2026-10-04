#ifndef POKEBW2_GFL_BLACT_H
#define POKEBW2_GFL_BLACT_H

#include "types.h"
#include "nitro/fx.h"
#include "gfl/heap.h"
#include "gfl/g3d.h"
#include "struct_decls.h"
// The billboard actors of GFL. Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)
typedef struct BlActSys BlActSys;
typedef struct BlActScene BlActScene;
// Uploads an actor's texture or palette to VRAM
typedef void (*BlActVRAMUploadFunc)(u32 type, u32 dest, const void *src, u32 size);
BlActSys *BlActSys_Create(u32 actorCount, u32 resourceCount, BlActVRAMUploadFunc uploadFunc, HeapID heapId);
void BlActSys_Free(BlActSys *system);
BlActScene *BlActSys_GetScene(BlActSys *system);
void BlActSys_UpdateActors(BlActSys *system);
void BlActSys_Draw(BlActSys *system, G3DCamera *camera, G3DLight *lights);
void BlActScene_SetScale(BlActScene *scene, const VecFx32 *scale);
void BlActScene_SetBasePolyID(BlActScene *scene, const u8 *polyId);
void BlActScene_SetGeomOrigin(BlActScene *scene, u8 origin);
void BlActScene_SetTexcoordOffset(BlActScene *scene, s16 s, s16 t);

#endif // POKEBW2_GFL_BLACT_H
