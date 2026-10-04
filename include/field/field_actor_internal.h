#ifndef POKEBW2_FIELD_FIELD_ACTOR_INTERNAL_H
#define POKEBW2_FIELD_FIELD_ACTOR_INTERNAL_H

// The layouts of the actors and their system. Names and layouts from swan's FieldActor and FieldActorSystem
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/heap.h"
#include "gfl/tcb.h"
#include "nitro/fx.h"
#include "field/field_actor.h"
#include "struct_decls.h"

// The UID of the player's actor
#define ACTOR_UID_PLAYER 0xff

// A position on the grid
typedef struct {
    s16 x;
    s16 y;
    s16 z;
} GPosXYZ;

struct FieldActor {
    u32 flags;
    u32 movementFlags;
    u16 uid;
    u16 zoneId;
    u16 modelId;
    u16 moveCode;
    u16 evType;
    u16 spawnFlag;
    u16 scrId;
    u16 defaultDir;
    u16 faceDir;
    u16 motionDir;
    u16 lastFaceDir;
    u16 lastMotionDir;
    u16 param0;
    u16 param1;
    u16 param2;
    u16 nextAcmd;
    s16 unk28;
    u16 unk2A;
    s16 areaW;
    s16 areaH;
    GPosXYZ defaultGPos;
    // The position before the last move
    GPosXYZ initGPos;
    GPosXYZ gPos;
    s16 unk42;
    VecFx32 wPos;
    VecFx32 wPosOffset;
    u32 unk5C;
    u32 unk60;
    u32 unk64;
    VecFx32 unk68;
    u32 currentTileUnder;
    u32 currentTileUnderOrigY;
    u8 collisionWidth;
    u8 collisionHeight;
    s8 modelPosOffsetX;
    s8 modelPosOffsetY;
    s8 modelPosOffsetZ;
    u8 shadowGroup;
    u16 padShadowGroup;
    TCB *tcb;
    MMSys *actorSystem;
    const FieldActorMoveCode *moveCodeVTable;
    void *sceneNodeVTable;
    ActorPositionRail defaultRailPos;
    u8 unkA0[0x44];
    FieldActorConfig config;
};

struct MMSys {
    u32 flags;
    u16 actorCapacity;
    u16 actorCount;
    HeapID heapId;
    HeapID fieldHeapId;
    u16 unkC;
    u16 unkE;
    u32 unk10;
    ArcTool *dataArc;
    ArcTool *actorConfigArc;
    FieldActor *actorHeap;
    void *tcbMgrHeap;
    void *tcbMgr;
    void *fieldBlAct;
    void *actorG3DSystem;
    void *mmodelSave;
    GameData *gameData;
    FieldG3DMapper *g3dMapper;
    NoGridMapper *noGridMapper;
    Field *field;
    void *unk44;
    void *colorPostFx;
    void *actorConfigCache;
};

#endif // POKEBW2_FIELD_FIELD_ACTOR_INTERNAL_H
