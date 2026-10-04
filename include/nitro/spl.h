#ifndef POKEBW2_NITRO_SPL_H
#define POKEBW2_NITRO_SPL_H

#include "types.h"
#include "nitro/fx.h"
#include "nitro/gx.h"

// Nintendo's SPL particle library, under the names pret's Platinum decompilation gives it: a manager of emitters
// made from a resource file's particle definitions. Only what the game's own code touches is laid out here

// The library's doubly linked lists, of emitters and of particles, which start with these links
typedef struct SPLNode {
    struct SPLNode *next;
    struct SPLNode *prev;
} SPLNode;

typedef struct {
    SPLNode *first;
    int count;
    SPLNode *last;
} SPLList;

void SPLList_PushFront(SPLList *list, SPLNode *node);
SPLNode *SPLList_PopFront(SPLList *list);
SPLNode *SPLList_Erase(SPLList *list, SPLNode *node);

typedef void *(*SPLAllocFunc)(u32 size);
typedef u32 (*SPLTexVRAMAllocFunc)(u32 size, BOOL is4x4comp);
typedef u32 (*SPLPalVRAMAllocFunc)(u32 size, BOOL is4pltt);

typedef struct SPLEmitter SPLEmitter;

typedef struct SPLParticle {
    struct SPLParticle *next;
    struct SPLParticle *prev;
    // Relative to the emitter, which was at emitterPos when the particle was emitted
    VecFx32 position;
    VecFx32 velocity;
    u16 rotation;
    s16 angularVelocity;
    u16 lifeTime;
    u16 age;
    // 0x10000 over the loop and life times, to map ages to [0, 255]
    u16 loopTimeFactor;
    u16 lifeTimeFactor;
    u8 texture;
    // Added to the life rate of a looping particle, so that particles emitted together do not animate together
    u8 lifeRateOffset;
    u16 baseAlpha : 5;
    u16 animAlpha : 5;
    u16 polygonId : 6;
    fx32 baseScale;
    fx16 animScale;
    GXRgb color;
    VecFx32 emitterPos;
} SPLParticle;

typedef void (*SPLEmitterCallback)(SPLEmitter *emitter);
typedef void (*SPLEmitterUpdateCallback)(SPLEmitter *emitter, u32 type);
typedef void (*SPLBehaviorFunc)(const void *behavior, SPLParticle *particle, VecFx32 *acc, SPLEmitter *emitter);

typedef struct {
    u32 flags;
    VecFx32 emitterBasePos;
} SPLResourceHeader;

// A force on an emitter's particles: the function applying it, and its parameters
typedef struct {
    SPLBehaviorFunc applyFunc;
    void *object;
} SPLBehavior;

typedef struct {
    SPLResourceHeader *header;
    u8 unk4[0x14];
    SPLBehavior *behaviors;
    u16 behaviorCount;
} SPLResource;

typedef struct {
    VecFx16 magnitude;
    u16 padding;
} SPLGravityBehavior;

// Every applyInterval frames, a random force of up to magnitude either way
typedef struct {
    VecFx16 magnitude;
    u16 applyInterval;
} SPLRandomBehavior;

typedef struct {
    VecFx32 target;
    fx16 force;
    u16 padding;
} SPLMagnetBehavior;

typedef struct {
    u16 angle;
    u16 axis;
} SPLSpinBehavior;

// A plane at height y that particles crossing it die at or bounce off
typedef struct {
    fx32 y;
    fx16 elasticity;
    u16 type : 2;
} SPLCollisionPlaneBehavior;

enum {
    SPL_COLLISION_KILL,
    SPL_COLLISION_BOUNCE,
};

// Pulls particles' positions straight towards the target
typedef struct {
    VecFx32 target;
    fx16 force;
    u16 padding;
} SPLConvergenceBehavior;

struct SPLEmitter {
    SPLEmitter *next;
    SPLEmitter *prev;
    SPLList particles;
    SPLList childParticles;
    SPLResource *resource;
    u32 state;
    VecFx32 position;
    VecFx32 velocity;
    VecFx32 particleInitVelocity;
    u16 age;
    fx16 emissionCountFractional;
    VecFx16 axis;
    u16 initAngle;
    fx32 emissionCount;
    fx32 radius;
    fx32 length;
    fx32 initVelPositionAmplifier;
    fx32 initVelAxisAmplifier;
    fx32 baseScale;
    u16 particleLifeTime;
    GXRgb color;
    // Overrides the collision plane behavior's height, unless FX32_MIN
    fx32 collisionPlaneHeight;
    fx16 textureS;
    fx16 textureT;
    fx16 childTextureS;
    fx16 childTextureT;
    u32 emissionInterval : 8;
    u32 baseAlpha : 8;
    u32 updateCycle : 3;
    u32 : 13;
    VecFx16 crossAxis1;
    VecFx16 crossAxis2;
    SPLEmitterUpdateCallback updateCallback;
    void *userDataPtr;
};

typedef struct {
    SPLEmitter *first;
    int count;
    SPLEmitter *last;
} SPLEmitterList;

typedef struct {
    SPLAllocFunc alloc;
    SPLEmitterList activeEmitters;
} SPLManager;

// The behaviors' functions, which tell a behavior's kind
void SPLBehavior_ApplyGravity(const void *behavior, SPLParticle *particle, VecFx32 *acc, SPLEmitter *emitter);
void SPLBehavior_ApplyRandom(const void *behavior, SPLParticle *particle, VecFx32 *acc, SPLEmitter *emitter);
void SPLBehavior_ApplyMagnet(const void *behavior, SPLParticle *particle, VecFx32 *acc, SPLEmitter *emitter);
void SPLBehavior_ApplySpin(const void *behavior, SPLParticle *particle, VecFx32 *acc, SPLEmitter *emitter);
void SPLBehavior_ApplyCollisionPlane(const void *behavior, SPLParticle *particle, VecFx32 *acc, SPLEmitter *emitter);
void SPLBehavior_ApplyConvergence(const void *behavior, SPLParticle *particle, VecFx32 *acc, SPLEmitter *emitter);

SPLManager *SPLManager_New(SPLAllocFunc alloc, u16 maxEmitters, u16 maxParticles, u16 fixPolyID, u16 minPolyID,
                           u16 maxPolyID);
void SPLManager_LoadResources(SPLManager *mgr, const void *data);
// Upload the resource's textures and palettes to VRAM, with the default VRAM managers or the given allocators
BOOL SPLManager_UploadTextures(SPLManager *mgr);
BOOL SPLManager_UploadTexturesEx(SPLManager *mgr, SPLTexVRAMAllocFunc vramAlloc);
BOOL SPLManager_UploadPalettes(SPLManager *mgr);
BOOL SPLManager_UploadPalettesEx(SPLManager *mgr, SPLPalVRAMAllocFunc vramAlloc);
void SPLManager_Update(SPLManager *mgr);
void SPLManager_Draw(SPLManager *mgr, const MtxFx43 *viewMatrix);
SPLEmitter *SPLManager_CreateEmitter(SPLManager *mgr, int resourceID, const VecFx32 *pos);
SPLEmitter *SPLManager_CreateEmitterWithCallback(SPLManager *mgr, int resourceID, SPLEmitterCallback initCallback);
void SPLManager_DeleteEmitter(SPLManager *mgr, SPLEmitter *emitter);
void SPLManager_DeleteAllEmitters(SPLManager *mgr);

#endif // POKEBW2_NITRO_SPL_H
