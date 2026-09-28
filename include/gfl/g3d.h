#ifndef POKEBW2_GFL_G3D_H
#define POKEBW2_GFL_G3D_H

// Names, layouts and constants from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0), except the scene
// setup, whose layout comes from the intro's data

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"

typedef struct G3DActor G3DActor;
typedef struct G3DCamera G3DCamera;
typedef struct G3DManager G3DManager;

typedef enum {
    G3DCAM_PROJECTION_PERSPECTIVE,
    G3DCAM_PROJECTION_FRUSTUM,
    G3DCAM_PROJECTION_ORTHO,
} G3DCameraProjectionMode;

typedef struct {
    VecFx32 translation;
    VecFx32 scale;
    MtxFx33 rotation;
} SRTMatrix;

// A scene that GFL_G3DMgrNewScene loads: its resources, and its actors, each a model with animations
typedef struct {
    u32 arcId;
    u32 fileId;
    u32 unk8;
} G3DSceneResourceSetup;

typedef struct {
    u16 resource;
    u16 index;
} G3DSceneAnimationSetup;

typedef struct {
    u16 modelResource;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    const G3DSceneAnimationSetup *animations;
    u32 animationCount;
} G3DSceneActorSetup;

typedef struct {
    const G3DSceneResourceSetup *resources;
    u32 resourceCount;
    const G3DSceneActorSetup *actors;
    u32 actorCount;
} G3DSceneSetup;

G3DCamera *GFL_G3DCameraCreate(G3DCameraProjectionMode proj, fx32 param1, fx32 param2, fx32 param3, fx32 param4,
                               fx32 near, fx32 far, fx32 ndcRangeOverride, VecFx32 *position, VecFx32 *upVector,
                               VecFx32 *target, HeapID heapId);
void GFL_G3DCameraFree(G3DCamera *cam);
void GFL_G3DCameraFlush(G3DCamera *cam);

BOOL GFL_G3DActorBindAnm(G3DActor *actor, u8 anmIdx);
BOOL GFL_G3DActorUnbindAnm(G3DActor *actor, u8 anmIdx);
BOOL GFL_G3DActorSetAnmFrame(G3DActor *actor, u8 anmIdx, fx32 *frame);
// Returns FALSE once the animation has reached its end
BOOL GFL_G3DActorStepAnmFrame(G3DActor *actor, u8 anmIdx, fx16 addend);
void GFL_G3DSysDrawObj(G3DActor *obj, SRTMatrix *mdlMtx);

G3DManager *GFL_G3DMgrCreate(u16 resourceLimit, u16 actorLimit, HeapID heapId);
void GFL_G3DMgrFree(G3DManager *manager);
u16 GFL_G3DMgrNewScene(G3DManager *manager, const G3DSceneSetup *setup);
void GFL_G3DMgrDeleteScene(G3DManager *manager, u16 scene);
G3DActor *GFL_G3DMgrGetActor(G3DManager *manager, u16 scene);

#endif // POKEBW2_GFL_G3D_H
