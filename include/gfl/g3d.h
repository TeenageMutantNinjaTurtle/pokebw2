#ifndef POKEBW2_GFL_G3D_H
#define POKEBW2_GFL_G3D_H

// Names, layouts and constants from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0), except the scene
// setup, whose layout comes from the intro's data

#include "types.h"
#include "gfl/std.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "nitro/gx.h"
#include "nitro/mi.h"
#include "struct_decls.h"

typedef struct G3DActor G3DActor;
typedef struct G3DCamera G3DCamera;
typedef struct G3DCurve G3DCurve;
typedef struct G3DLight G3DLight;
typedef struct G3DManager G3DManager;
typedef struct G3DModel G3DModel;

G3DCurve *GFL_G3DCurveCreateToLoadBuffer(HeapID heapId, u32 arcId, u32 fileId, u32 type, void *buffer, u32 bufferSize);
void GFL_G3DResBindData(void *resource, u32 kind, void *data);
BOOL GFL_G3DCurveFrameStepLoop(G3DCurve *curve, fx32 step);
BOOL GFL_G3DCurveGetNowTranslation(G3DCurve *curve, VecFx32 *translation);
BOOL GFL_G3DCurveGetNowRotation(G3DCurve *curve, VecFx32 *rotation);

// NitroSystem's model resource, and the start of its render object, which draws a model resource
typedef struct NNSG3dResMdl NNSG3dResMdl;

// The start of NitroSystem's model resource
typedef struct {
    u8 sbcType;
    u8 scalingRule;
    u8 texMtxMode;
    u8 numNode;
    u8 numMat;
    u8 numShp;
    u8 firstUnusedMtxStackID;
    u8 dummy_;
    fx32 posScale;
    fx32 invPosScale;
    u16 numVertex;
    u16 numPolygon;
    u16 numTriangle;
    u16 numQuad;
    fx16 boxX;
    fx16 boxY;
    fx16 boxZ;
    fx16 boxW;
    fx16 boxH;
    fx16 boxD;
    fx32 boxPosScale;
    fx32 boxInvPosScale;
} NNSG3dResMdlInfo;

struct NNSG3dResMdl {
    u32 size;
    u32 ofsSbc;
    u32 ofsMat;
    u32 ofsShp;
    u32 ofsEvpMtx;
    NNSG3dResMdlInfo info;
};

// The start of NitroSDK's animation resources
typedef struct {
    u8 category0;
    u8 revision;
    u8 category1[2];
    u16 numFrame;
    u16 dummy_;
} NNSG3dResAnmCommon;

// NitroSDK's animation object
typedef struct NNSG3dAnmObj {
    fx32 frame;
    fx32 ratio;
    NNSG3dResAnmCommon *resAnm;
    void *funcAnm;
    struct NNSG3dAnmObj *next;
    const void *resTex;
    u8 priority;
    u8 numMapData;
    u16 mapData[1];
} NNSG3dAnmObj;

// NitroSDK's render object, 0x54 bytes
typedef struct {
    u32 flag;
    NNSG3dResMdl *resMdl;
    void *anmMat;
    void *funcBlendMat;
    void *anmJnt;
    void *funcBlendJnt;
    void *anmVis;
    void *funcBlendVis;
    void *cbFunc;
    u8 cbCmd;
    u8 cbTiming;
    u16 dummy_;
    void *cbInitFunc;
    void *ptrUser;
    u8 *ptrUserSbc;
    void *recJntAnm;
    void *recMatAnm;
    u32 hintMatAnmExist[2];
    u32 hintJntAnmExist[2];
    u32 hintVisAnmExist[2];
} NNSG3dRenderObj;

typedef enum {
    G3DCAM_PROJECTION_PERSPECTIVE,
    G3DCAM_PROJECTION_FRUSTUM,
    G3DCAM_PROJECTION_ORTHO,
} G3DCameraProjectionMode;

// A projection: for a perspective one, the sine and cosine of half its field of view, its aspect ratio and an unused
// value, or for the others, the top, bottom, left and right of the view
typedef struct {
    G3DCameraProjectionMode type;
    fx32 param1;
    fx32 param2;
    fx32 param3;
    fx32 param4;
    fx32 near;
    fx32 far;
    fx32 ndcRangeOverride;
} G3DCameraProjection;

typedef struct {
    VecFx32 position;
    VecFx32 upVector;
    VecFx32 target;
} FxLookAt;

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
    u16 fileId;
    u16 unk6;
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
    u16 animationCount;
} G3DSceneActorSetup;

typedef struct {
    const G3DSceneResourceSetup *resources;
    u16 resourceCount;
    const G3DSceneActorSetup *actors;
    u16 actorCount;
} G3DSceneSetup;

void GFL_G3DSysCreate(BOOL useFrmHeapVramMgr, u32 numMgmtBlks, u32 dat3, u32 dat4, u16 dtcmAllocSize, HeapID heapId,
                      G3DSystemInitCallback initCallback);
void GFL_G3DSysFree(void);
void GFL_G3DSysLightSet(u8 lightId, const Light *light);
void GFL_G3DSysMtxGetProjection(G3DCameraProjection *dest);
void GFL_G3DSysMtxSetProjection(const G3DCameraProjection *projection);
void GFL_G3DSysMtxGetViewLookAt(FxLookAt *dest);
void GFL_G3DSysMtxSetViewLookAt(const FxLookAt *lookAt);
void GFL_G3DSysMtxViewFlush(void);
void GFL_G3DSysReqSwapBuffers(void);
void GFL_G3DSysReset(void);
void GFL_G3DSysSetSwapBufferParams(u32 sortMode, u32 bufferMode);
void *GFL_G3DSysReadArcToolResource(ArcTool *handle, u32 fileId);
BOOL GFL_G3DResCheckType(void *resource, u32 type);
void GFL_G3DResUploadTexData(void *resource);
void GFL_G3DResFreeTexData(void *resource);
void GFL_G3DResFree(void *resource);
// The size of a resource's header, which GFL_G3DResSetup fills in
u32 GFL_G3DResGetAllocSize(void);
void GFL_G3DResSetup(void *resource, void *data);
void *GFL_G3DSysReadArcSysResource(u32 arcId, u32 fileId);
BOOL GFL_G3DResUploadAndReleaseTexData(void *resource);
G3DModel *GFL_G3DMdlCreate(void *resource, u32 modelId, void *texture);
void GFL_G3DMdlFree(G3DModel *model);
void *GFL_G3DAnmCreate(G3DModel *model, void *resource, u32 a2);
void GFL_G3DAnmFree(void *animation);
NNSG3dAnmObj *GFL_G3DAnmGetRenderObj(void *animation);
G3DActor *GFL_G3DActorCreate(G3DModel *model, void **animations, u32 count);
void GFL_G3DActorFree(G3DActor *actor);

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
void GFL_G3DCameraGetLookatPos(G3DCamera *cam, VecFx32 *pos);
void GFL_G3DCameraGetLookatUpVector(G3DCamera *cam, VecFx32 *up);
void GFL_G3DCameraGetLookatTarget(G3DCamera *cam, VecFx32 *target);

BOOL GFL_G3DActorBindAnm(G3DActor *actor, u16 anmIdx);
BOOL GFL_G3DActorUnbindAnm(G3DActor *actor, u16 anmIdx);
void GFL_G3DActorResetAnmFrame(G3DActor *actor, u16 anmIdx);
BOOL GFL_G3DActorSetAnmFrame(G3DActor *actor, u16 anmIdx, fx32 *frame);
// Returns FALSE once the animation has reached its end
BOOL GFL_G3DActorStepAnmFrame(G3DActor *actor, u16 anmIdx, fx32 addend);
// The same, going back to the start at the end
BOOL GFL_G3DActorStepAnmFrameLoop(G3DActor *actor, u16 anmIdx, fx16 addend);
void GFL_G3DSysDrawObj(G3DActor *obj, const SRTMatrix *mdlMtx);
void GFL_G3DSysDrawObjBBoxCull(G3DActor *obj, const SRTMatrix *mdlMtx);
G3DModel *GFL_G3DActorGetMdl(G3DActor *actor);
s32 GFL_G3DActorGetAnmCount(G3DActor *actor);
void *GFL_G3DActorGetAnm(G3DActor *actor, u16 index);
NNSG3dRenderObj *GFL_G3DMdlGetEngineModel(G3DModel *model);
void *GFL_G3DMdlGetTexResource(G3DModel *model);

// NitroSystem's global state of the geometry engine, up to the base matrix that models are drawn with
typedef struct {
    u32 cmd0;
    u32 mtxmode_proj;
    MtxFx44 projMtx;
    u32 mtxmode_posvec;
    MtxFx43 cameraMtx;
    u32 cmd1;
    u32 lightVec[4];
    u32 cmd2;
    u32 prmMatColor0;
    u32 prmMatColor1;
    u32 prmPolygonAttr;
    u32 prmViewPort;
    u32 cmd3;
    u32 lightColor[4];
    u32 cmd4;
    MtxFx33 prmBaseRot;
    VecFx32 prmBaseTrans;
    VecFx32 prmBaseScale;
    u32 prmTexImageParam;
    u32 flag;
} NNSG3dGlb;

#define NNS_G3D_GLB_FLAG_INVBASE_UPTODATE 0x00000004
#define NNS_G3D_GLB_FLAG_INVPROJ_UPTODATE 0x00000010
#define NNS_G3D_GLB_FLAG_INVVP_UPTODATE 0x00000040
#define NNS_G3D_GLB_FLAG_INVBASECAMERA_UPTODATE 0x00000020
#define NNS_G3D_GLB_FLAG_BASECAMERA_UPTODATE 0x00000080

extern NNSG3dGlb NNS_G3dGlb;

void NNS_G3dGlbSetBaseTrans(const VecFx32 *trans);
void NNS_G3dGlbSetBaseScale(const VecFx32 *scale);

static inline void NNS_G3dGlbSetBaseRot(const MtxFx33 *rot) {
    MI_Copy36B(rot, &NNS_G3dGlb.prmBaseRot);
    NNS_G3dGlb.flag &= ~(NNS_G3D_GLB_FLAG_BASECAMERA_UPTODATE | NNS_G3D_GLB_FLAG_INVBASE_UPTODATE |
                         NNS_G3D_GLB_FLAG_INVBASECAMERA_UPTODATE);
}

static inline void NNS_G3dGlbSetProjectionMtx(const MtxFx44 *mtx) {
    sys_memcpy32_fast(mtx, &NNS_G3dGlb.projMtx, sizeof(MtxFx44));
    NNS_G3dGlb.flag &= ~(NNS_G3D_GLB_FLAG_INVPROJ_UPTODATE | NNS_G3D_GLB_FLAG_INVVP_UPTODATE);
}

// Sends the geometry commands that are waiting in a buffer
void NNS_G3DWaitFIFO(void);
void NNS_G3DFlushRenderState(void);

// NitroSystem's geometry command buffer (NNS_G3dGeBufferOP_N), and its inline wrappers
void NNS_G3DExecOp(u32 op, const void *args, u32 count);

#define G3OP_MTX_PUSH 0x11
#define G3OP_MTX_POP 0x12
#define G3OP_MTX_IDENTITY 0x15
#define G3OP_MTX_LOAD_4x3 0x17
#define G3OP_MTX_MULT_4x3 0x19
#define G3OP_MTX_SCALE 0x1b
#define G3OP_MTX_TRANS 0x1c
#define G3OP_POLYGON_ATTR 0x29
#define G3OP_BEGIN 0x40
#define G3OP_END 0x41
#define G3OP_BOX_TEST 0x70

static inline void NNS_G3dGePushMtx(void) {
    NNS_G3DExecOp(G3OP_MTX_PUSH, NULL, 0);
}

static inline void NNS_G3dGePopMtx(int num) {
    s32 param = num;

    NNS_G3DExecOp(G3OP_MTX_POP, &param, 1);
}

static inline void NNS_G3dGeIdentity(void) {
    NNS_G3DExecOp(G3OP_MTX_IDENTITY, NULL, 0);
}

static inline void NNS_G3dGeLoadMtx43(const MtxFx43 *mtx) {
    NNS_G3DExecOp(G3OP_MTX_LOAD_4x3, mtx, 12);
}

static inline void NNS_G3dGeMultMtx43(const MtxFx43 *mtx) {
    NNS_G3DExecOp(G3OP_MTX_MULT_4x3, mtx, 12);
}

static inline void NNS_G3dGeScaleVec(const VecFx32 *scale) {
    NNS_G3DExecOp(G3OP_MTX_SCALE, scale, 3);
}

static inline void NNS_G3dGeTranslateVec(const VecFx32 *trans) {
    NNS_G3DExecOp(G3OP_MTX_TRANS, trans, 3);
}

static inline void NNS_G3dGePolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc) {
    u32 param = GX_PACK_POLYGONATTR_PARAM(light, polyMode, cullMode, polygonID, alpha, misc);

    NNS_G3DExecOp(G3OP_POLYGON_ATTR, &param, 1);
}

static inline void NNS_G3dGeBegin(int primitive) {
    u32 param = primitive;

    NNS_G3DExecOp(G3OP_BEGIN, &param, 1);
}

static inline void NNS_G3dGeEnd(void) {
    NNS_G3DExecOp(G3OP_END, NULL, 0);
}

static inline void NNS_G3dGeBoxTest(const GXBoxTestParam *box) {
    NNS_G3DExecOp(G3OP_BOX_TEST, box, 3);
}

// A model resource file's blocks, from NitroSystem's headers
typedef struct {
    u32 kind;
    u32 size;
} NNSG3dResDataBlockHeader;

typedef struct {
    u8 revision;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 dummy_;
    u16 ofsEntry;
} NNSG3dResDict;

typedef struct {
    u16 sizeUnit;
    u16 sizeEntry;
    u8 data[4];
} NNSG3dResDictEntryHeader;

typedef struct {
    NNSG3dResDataBlockHeader header;
    NNSG3dResDict dict;
} NNSG3dResMdlSet;

typedef struct {
    u32 offset;
} NNSG3dResDictMdlSetData;

typedef struct NNSG3dResTex NNSG3dResTex;

static inline void *NNS_G3dGetResDataByIdx(const NNSG3dResDict *dict, u32 idx) {
    if (dict != NULL && idx < dict->numEntry) {
        const NNSG3dResDictEntryHeader *header = (const NNSG3dResDictEntryHeader *)((const u8 *)dict + dict->ofsEntry);

        return (void *)((const u8 *)&header->data[0] + header->sizeUnit * idx);
    }
    return NULL;
}

static inline NNSG3dResMdl *NNS_G3dGetMdlByIdx(const NNSG3dResMdlSet *mdlSet, u32 idx) {
    const NNSG3dResDictMdlSetData *data = NNS_G3dGetResDataByIdx(&mdlSet->dict, idx);

    if (data != NULL) {
        return (NNSG3dResMdl *)((u8 *)mdlSet + data->offset);
    }
    return NULL;
}

// NNS_G3dGetMdlSet and NNS_G3dGetTex
NNSG3dResMdlSet *NNS_G3DResGetMdlBlock(void *file);
NNSG3dResTex *NNS_G3DResGetTexBlock(void *file);
// NNS_G3dBindMdlTex and NNS_G3dBindMdlPltt
BOOL func_020653fc(NNSG3dResMdl *mdl, const NNSG3dResTex *tex);
BOOL func_02065524(NNSG3dResMdl *mdl, const NNSG3dResTex *tex);
// NNS_G3dRenderObjInit
void NNS_G3DModelAttachResource(NNSG3dRenderObj *obj, NNSG3dResMdl *mdl);
void *GFL_G3DResGetResData(void *resource);
void GFL_G3DSysDispatchDraw(NNSG3dRenderObj *obj);
// NitroSystem's VRAM managers, which return a key for the VRAM, or 0
extern u32 (*g_TexVRAMAllocFunc)(u32 size, BOOL is4x4Comp, u32 opt);
extern int (*g_TexVRAMFreeFunc)(u32 key);
extern u32 (*g_PltVRAMAllocFunc)(u32 size, BOOL is4Pltt, u32 opt);
extern int (*g_PltVRAMFreeFunc)(u32 key);

// The alpha of a material of a model resource, from 0 to 31
u32 NNS_G3DResMdlGetMatAlpha(const NNSG3dResMdl *mdl, u32 matId);
void NNS_G3DResMdlSetMatAlpha(NNSG3dResMdl *mdl, u32 matId, u32 alpha);

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
u32 GFL_G3DCurveGetFrameCount(G3DCurve *curve);
// The curve's values at a frame. They return FALSE when they give no value
BOOL GFL_G3DCurveGetNowTranslationLoop(G3DCurve *curve, VecFx32 *translation, u32 frame);
BOOL GFL_G3DCurveGetNowRotationLoop(G3DCurve *curve, VecFx32 *rotation, u32 frame);
BOOL GFL_G3DCurveGetNowScaleLoop(G3DCurve *curve, VecFx32 *scale, u32 frame);
void GFL_G3DCurveApplyCamera(G3DCamera *camera, G3DCurve *curve);
void GFL_G3DSysResetGeometryCounter(void);

#endif // POKEBW2_GFL_G3D_H
