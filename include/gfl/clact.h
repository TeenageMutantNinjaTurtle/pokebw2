#ifndef POKEBW2_GFL_CLACT_H
#define POKEBW2_GFL_CLACT_H

#include "types.h"
#include "gfl/arc.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"

// Cell actors, the OAM sprites of the 2D engines

// Holds cell actors, 0xe4 bytes each
typedef struct ClActUnit ClActUnit;
typedef struct ClActor ClActor;

typedef struct {
    s16 x;
    s16 y;
    u16 unk4;
    u8 unk6;
    u8 unk7;
} ClActorSetup;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u32 unkC;
    // For ClActVRAMManager_Init
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
} ClActSysSetup;

// The setup that most apps create the system with, the same as the intro's copy
extern const ClActSysSetup data_02093f08;

void ClActSys_Create(const ClActSysSetup *setup, const BGSysVRAMConfig *vramConfig, HeapID heapId);
void func_0204b758(void);
void func_0204b794(void);
void func_0204b7c8(void);
ClActUnit *func_0204bf1c(u16 count, u8 a1, HeapID heapId);
void func_0204bf98(ClActUnit *unit);
void func_0204c028(ClActUnit *unit);

// Load characters (NCGR), a palette (NCLR), and cells with their animations (NCER and NANR) from an archive, and
// return their resource indices
u32 func_0204b81c(ArcTool *arc, u32 fileId, u32 a2, u32 a3, HeapID heapId);
u32 func_0204bba0(ArcTool *arc, u32 fileId, u32 a2, u32 a3, HeapID heapId);
// func_0204bba0 with a4 and a5 0
u32 func_0204bbb8(ArcTool *arc, u32 fileId, u32 a2, u32 a3, u32 a4, u32 a5, HeapID heapId);
u32 func_0204bde0(ArcTool *arc, u32 cellFileId, u32 animFileId, HeapID heapId);
void func_0204b98c(u32 chars);
void func_0204bcd0(u32 palette);
void func_0204be64(u32 cellAnims);
ClActor *func_0204c040(ClActUnit *unit, u32 chars, u32 palette, u32 cellAnims, const ClActorSetup *setup, u16 a5,
                       HeapID heapId);
void func_0204c108(ClActor *actor);
typedef struct {
    s16 x;
    s16 y;
} ClActorPos;

void func_0204c140(ClActor *actor, const ClActorPos *pos, u32 a2);
void func_0204c178(ClActor *actor, ClActorPos *pos, u32 a2);
void func_0204c124(ClActor *actor, BOOL visible);
// The actor's OBJ mode, GX_OAM_MODE_*
void func_0204c318(ClActor *actor, u32 mode);
u32 func_0204c370(ClActor *actor);
void func_0204c520(ClActor *actor, BOOL a1);
// Act on the actor's animation controller
void func_0204c504(ClActor *actor, u32 a1);
BOOL func_0204c560(ClActor *actor);

#endif // POKEBW2_GFL_CLACT_H
