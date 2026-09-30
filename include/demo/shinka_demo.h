#ifndef POKEBW2_DEMO_SHINKA_DEMO_H
#define POKEBW2_DEMO_SHINKA_DEMO_H

#include "types.h"
#include "gfl/clact.h"
#include "gfl/heap.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// The evolution demo
#define OVERLAY_SHINKA_DEMO OVERLAY_ID(284)

typedef struct {
    GameData *gameData;
    PokeParty *party;
    u16 partyIndex;
    u8 unkA;
    u8 unkB;
    u32 unkC;
    u32 unk10;
} ShinkaDemoParam;

extern const GameProcFunctions SHINKA_DEMO_PROC_FUNCTIONS;

typedef struct ShinkaDemoGraphic ShinkaDemoGraphic;
typedef struct ShinkaDemoEffect ShinkaDemoEffect;

// shinka_demo_graphic.c
ShinkaDemoGraphic *ShinkaDemoGraphic_Create(u32 layout, HeapID heapId);
void ShinkaDemoGraphic_Free(ShinkaDemoGraphic *graphic);
void ShinkaDemoGraphic_Update(ShinkaDemoGraphic *graphic);
void ShinkaDemoGraphic_Begin3D(ShinkaDemoGraphic *graphic);
void ShinkaDemoGraphic_End3D(ShinkaDemoGraphic *graphic);
ClActUnit *ShinkaDemoGraphic_GetClActUnit(ShinkaDemoGraphic *graphic);
// Creates and frees the BGs of the sub screen
void ShinkaDemoGraphic_InitSubBG(void);
void ShinkaDemoGraphic_FreeSubBG(void);

// shinka_demo_effect.c: the particles and 3D model around the evolving Pokémon
ShinkaDemoEffect *ShinkaDemoEffect_Create(HeapID heapId, BOOL played);
void ShinkaDemoEffect_Free(ShinkaDemoEffect *effect);
void ShinkaDemoEffect_Update(ShinkaDemoEffect *effect);
void ShinkaDemoEffect_Draw(ShinkaDemoEffect *effect);
void ShinkaDemoEffect_Cancel(ShinkaDemoEffect *effect);
// Starts the particles
void ShinkaDemoEffect_Start(ShinkaDemoEffect *effect);
// Plays the 3D model once the particles have started
void ShinkaDemoEffect_Start3D(ShinkaDemoEffect *effect);
BOOL ShinkaDemoEffect_Is3DHeld(ShinkaDemoEffect *effect);
BOOL ShinkaDemoEffect_Is3DReversing(ShinkaDemoEffect *effect);

#endif // POKEBW2_DEMO_SHINKA_DEMO_H
