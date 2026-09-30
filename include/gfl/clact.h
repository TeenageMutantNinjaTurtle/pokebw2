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

void ClActSys_Create(const ClActSysSetup *setup, const BGSysVRAMConfig *vramConfig, HeapID heapId);
void func_0204b758(void);
void func_0204b794(void);
void func_0204b7c8(void);
ClActUnit *func_0204bf1c(u16 count, u8 a1, HeapID heapId);
void func_0204bf98(ClActUnit *unit);
void func_0204c028(ClActUnit *unit);

// Load a palette, cells and cell animations from an archive, and return their resource indices
u32 func_0204b81c(ArcTool *arc, u32 fileId, u32 a2, u32 a3, HeapID heapId);
u32 func_0204bba0(ArcTool *arc, u32 fileId, u32 a2, u32 a3, HeapID heapId);
u32 func_0204bde0(ArcTool *arc, u32 fileId, u32 a2, HeapID heapId);
void func_0204b98c(u32 palette);
void func_0204bcd0(u32 cells);
void func_0204be64(u32 animations);
ClActor *func_0204c040(ClActUnit *unit, u32 palette, u32 cells, u32 animations, const ClActorSetup *setup, u16 a5,
                       HeapID heapId);
void func_0204c108(ClActor *actor);
void func_0204c124(ClActor *actor, BOOL visible);
// The actor's OBJ mode, GX_OAM_MODE_*
void func_0204c318(ClActor *actor, u32 mode);
u32 func_0204c370(ClActor *actor);

#endif // POKEBW2_GFL_CLACT_H
