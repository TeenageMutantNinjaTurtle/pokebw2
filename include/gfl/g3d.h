#ifndef POKEBW2_GFL_G3D_H
#define POKEBW2_GFL_G3D_H

// Names, layouts and constants from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0), except the scene
// setup, whose layout comes from the intro's data

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "nitro/gx.h"

typedef struct G3DActor G3DActor;
typedef struct G3DCamera G3DCamera;
typedef struct G3DCurve G3DCurve;
typedef struct G3DLight G3DLight;
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

typedef void (*G3DSystemInitCallback)(void);

typedef struct {
    VecFx16 direction;
    GXRgb color;
} Light;

typedef struct {
    u8 index;
    Light light;
} LightSetup;

typedef struct {
    const LightSetup *lights;
    u8 count;
} LightSetupList;

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

void GFL_G3DSysCreate(BOOL useFrmHeapVramMgr, u32 numMgmtBlks, u32 dat3, u32 dat4, u16 dtcmAllocSize, HeapID heapId,
                      G3DSystemInitCallback initCallback);
void GFL_G3DSysFree(void);
void GFL_G3DSysLightSet(u8 lightId, const Light *light);
void GFL_G3DSysMtxViewFlush(void);
void GFL_G3DSysReqSwapBuffers(void);
void GFL_G3DSysReset(void);
void GFL_G3DSysSetSwapBufferParams(u32 sortMode, u32 bufferMode);

G3DLight *GFL_G3DLightCreate(const LightSetupList *setup, HeapID heapId);
void GFL_G3DLightFree(G3DLight *lights);
void GFL_G3DLightFlush(G3DLight *lights);

G3DCamera *GFL_G3DCameraCreate(G3DCameraProjectionMode proj, fx32 param1, fx32 param2, fx32 param3, fx32 param4,
                               fx32 near, fx32 far, fx32 ndcRangeOverride, const VecFx32 *position,
                               const VecFx32 *upVector, const VecFx32 *target, HeapID heapId);
void GFL_G3DCameraFree(G3DCamera *cam);
void GFL_G3DCameraFlush(G3DCamera *cam);
void GFL_G3DCameraSetProjectionZNear(G3DCamera *cam, fx32 *zNear);
void GFL_G3DCameraSetProjectionZFar(G3DCamera *cam, fx32 *zFar);

BOOL GFL_G3DActorBindAnm(G3DActor *actor, u16 anmIdx);
BOOL GFL_G3DActorUnbindAnm(G3DActor *actor, u16 anmIdx);
BOOL GFL_G3DActorSetAnmFrame(G3DActor *actor, u16 anmIdx, fx32 *frame);
// Returns FALSE once the animation has reached its end
BOOL GFL_G3DActorStepAnmFrame(G3DActor *actor, u16 anmIdx, fx16 addend);
// The same, going back to the start at the end
BOOL GFL_G3DActorStepAnmFrameLoop(G3DActor *actor, u16 anmIdx, fx16 addend);
void GFL_G3DSysDrawObj(G3DActor *obj, SRTMatrix *mdlMtx);

G3DManager *GFL_G3DMgrCreate(u16 resourceLimit, u16 actorLimit, HeapID heapId);
void GFL_G3DMgrFree(G3DManager *manager);
u16 GFL_G3DMgrNewScene(G3DManager *manager, const G3DSceneSetup *setup);
void GFL_G3DMgrDeleteScene(G3DManager *manager, u16 scene);
// The index of an actor, which GFL_G3DMgrGetActor takes. A scene's actors have consecutive indices
G3DActor *GFL_G3DMgrGetActor(G3DManager *manager, u16 actor);
u16 GFL_G3DMgrGetSceneFirstActorIdx(G3DManager *manager, u16 scene);

// Curves, which move a camera along a path loaded from a file, a frame at a time
G3DCurve *GFL_G3DCurveLoadFileAll(HeapID heapId, u32 arcId, u32 fileId);
void GFL_G3DCurveFree(G3DCurve *curve);
// Returns TRUE once the curve has reached its last frame, where it stays
BOOL GFL_G3DCurveFrameStep(G3DCurve *curve, fx32 step);
void GFL_G3DCurveFrameSet(G3DCurve *curve, fx32 frame);
fx32 GFL_G3DCurveGetNowFrame(G3DCurve *curve);
void GFL_G3DCurveApplyCamera(G3DCamera *camera, G3DCurve *curve);

#endif // POKEBW2_GFL_G3D_H
