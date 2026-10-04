#ifndef POKEBW2_FIELD_FIELD_CAMERA_H
#define POKEBW2_FIELD_FIELD_CAMERA_H

#include "types.h"
#include "gfl/g3d.h"
#include "nitro/fx.h"
#include "struct_decls.h"

// An event camera animation's target and what it animates. Names and layouts from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)
typedef struct {
    VecFx32 cameraPos;
    VecFx32 targetPos;
    VecFx32 extraTranslation;
    u16 pitch;
    u16 yaw;
    fx32 distance;
    u16 fov;
    u16 padFov;
} FieldEvCameraAnimationCoords;

typedef struct {
    BOOL animateExtraTranslation;
    BOOL animatePitch;
    BOOL animateYaw;
    BOOL animateTargetDistance;
    BOOL animateFOV;
    BOOL animateTargetPos;
} FieldEvCameraAnimationFlags;

typedef struct {
    FieldEvCameraAnimationCoords targetCoords;
    FieldEvCameraAnimationFlags flags;
} FieldEvCameraAnimationSetup;

void FieldCamera_CalcTransform(FieldCamera *camera, u32 a1);
G3DCamera *FieldCamera_GetG3DCamera(FieldCamera *camera);
void FieldCamera_CoordsGetEyeOffset(FieldCamera *camera, VecFx32 *offset);
void FieldCamera_CoordsGetTarget(FieldCamera *camera, VecFx32 *target);
void FieldCamera_CoordsGetTargetOffset(FieldCamera *camera, VecFx32 *offset);
void FieldCamera_CoordsSetEyeOffset(FieldCamera *camera, const VecFx32 *offset);
void FieldCamera_CoordsSetTargetOffset(FieldCamera *camera, const VecFx32 *offset);
u16 FieldCamera_CoordsGetPitch(FieldCamera *camera);
u16 FieldCamera_CoordsGetYaw(FieldCamera *camera);
fx32 FieldCamera_CoordsGetZoom(FieldCamera *camera);
void FieldCamera_CoordsSetTarget(FieldCamera *camera, const VecFx32 *target);
void FieldCamera_CoordsSetYaw(FieldCamera *camera, u16 yaw);
// Whether the camera keeps inside the zone's boundary
BOOL FieldCamera_IsUseBoundaryEnable(FieldCamera *camera);
void FieldCamera_SetUseBoundaryEnable(FieldCamera *camera, BOOL enable);
// Stop the camera following its target, and follow it again
void FieldCamera_ClearBind(FieldCamera *camera);
void FieldCamera_ResetBind(FieldCamera *camera);
void FieldCamera_LoadDefaults(FieldCamera *camera);
void FieldCamera_DisableDelay(FieldCamera *camera);
void FieldCamera_SetDefaultsIndex(FieldCamera *camera, u32 index);
void FieldCamera_EnableDelay(FieldCamera *camera);
void FieldCamera_FinishDelay(FieldCamera *camera);
BOOL FieldCamera_IsDelayActive(FieldCamera *camera);
// What the camera follows
void *FieldCamera_GetBind(FieldCamera *camera);
void FieldCamera_SetBind(FieldCamera *camera, void *bind);
// The event camera's animations: start, animate to a target or back over frames, and end
void FieldCamera_EVCameraInit(FieldCamera *camera);
void FieldCameraAnm_EnsureInitDone(FieldCamera *camera);
void FieldCameraAnm_SetAnimation(FieldCamera *camera, const FieldEvCameraAnimationSetup *setup, u16 frames);
void FieldCameraAnm_SetReturnAnimation(FieldCamera *camera, const FieldEvCameraAnimationFlags *flags, u16 frames);
BOOL FieldCamera_IsAnimating(FieldCamera *camera);
void FieldCameraAnm_EVCameraEnd(FieldCamera *camera);
// Whether the no-grid mapper's camera areas move the camera
void FieldNoGridMapper_SetCameraAreaEnabled(NoGridMapper *mapper, BOOL enabled);
// Tasks that move the camera's zoom over frames: this one by a distance from its current zoom
void FieldCameraZoomTCB_Create(Field *field, u32 frames, fx32 distance);
void func_ov036_021c05d4(Field *field, u32 frames, fx32 distance);

#endif // POKEBW2_FIELD_FIELD_CAMERA_H
