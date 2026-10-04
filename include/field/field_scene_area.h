#ifndef POKEBW2_FIELD_FIELD_SCENE_AREA_H
#define POKEBW2_FIELD_FIELD_SCENE_AREA_H

#include "types.h"
#include "nitro/fx.h"
#include "gfl/heap.h"
#include "struct_decls.h"
// Overlay 36: the camera areas of a zone, and the loader of their data. Function names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)
void *FieldSceneArea_Create(HeapID heapId, FieldCamera *camera, Field *field);
void FreeFieldSceneArea(void *area);
void BuildSceneArea(void *area, void *cameraData, u32 count, const void *funcs);
void ResetSceneArea(void *area);
BOOL FieldCameraArea_Update(void *area, const VecFx32 *pos);
void *FieldSceneAreaLoader_Create(HeapID heapId);
void FreeFieldSceneAreaLoader(void *loader);
void LoadCameraDataToSceneAreaLoader(void *loader, u32 index, u32 cameraId, HeapID heapId);
void ResetSceneAreaLoader(void *loader);
void *GetFldSceneAreaLoaderCameraData(void *loader);
u32 GetFldSceneAreaLoaderCamCount(void *loader);
const void *GetFldSceneAreaLoaderCamFuncsStaticOffs(void *loader);

#endif // POKEBW2_FIELD_FIELD_SCENE_AREA_H
