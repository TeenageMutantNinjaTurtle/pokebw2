#ifndef POKEBW2_FIELD_FIELD_CAMERA_H
#define POKEBW2_FIELD_FIELD_CAMERA_H

#include "types.h"
#include "nitro/fx.h"
#include "struct_decls.h"

void FieldCamera_CalcTransform(FieldCamera *camera, u32 a1);
void FieldCamera_CoordsGetTarget(FieldCamera *camera, VecFx32 *target);
void FieldCamera_DisableDelay(FieldCamera *camera);
void FieldCamera_SetDefaultsIndex(FieldCamera *camera, u32 index);
void FieldCamera_EnableDelay(FieldCamera *camera);
// Tasks that move the camera's zoom over frames: this one by a distance from its current zoom
void FieldCameraZoomTCB_Create(Field *field, u32 frames, fx32 distance);
void func_ov036_021c05d4(Field *field, u32 frames, fx32 distance);

#endif // POKEBW2_FIELD_FIELD_CAMERA_H
