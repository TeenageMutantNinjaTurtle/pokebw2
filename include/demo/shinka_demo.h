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
    // The species to evolve into
    u16 species;
    u8 partyIndex;
    // EVO_METHOD_*
    u8 method;
    // Set, the demo pushes and brings back the music that was playing, and picks a move to forget on overlay 207's
    // screen instead of overlay 287's
    u32 unkC;
    // Whether B stops the evolution. The demo clears it for an evolution by item
    BOOL canCancel;
} ShinkaDemoParam;

extern const GameProcFunctions SHINKA_DEMO_PROC_FUNCTIONS;

typedef struct ShinkaDemoGraphic ShinkaDemoGraphic;
typedef struct ShinkaDemoEffect ShinkaDemoEffect;
typedef struct ShinkaDemoView ShinkaDemoView;

// shinka_demo_graphic.c
ShinkaDemoGraphic *ShinkaDemoGraphic_Create(u32 layout, HeapID heapId);
void ShinkaDemoGraphic_Free(ShinkaDemoGraphic *graphic);
void ShinkaDemoGraphic_Update(ShinkaDemoGraphic *graphic);
void ShinkaDemoGraphic_Begin3D(ShinkaDemoGraphic *graphic);
void ShinkaDemoGraphic_End3D(ShinkaDemoGraphic *graphic);
ClActUnit *ShinkaDemoGraphic_GetClActUnit(ShinkaDemoGraphic *graphic);
// Creates and frees the BGs of the sub screen
void ShinkaDemoGraphic_InitSubBG(ShinkaDemoGraphic *graphic);
void ShinkaDemoGraphic_FreeSubBG(ShinkaDemoGraphic *graphic);

// shinka_demo_view.c: the evolving Pokémon. played creates it after the evolution has been shown, with the evolved
// Pokémon
ShinkaDemoView *ShinkaDemoView_Create(HeapID heapId, BOOL played, PartyPkm *pkm, u16 species);
void ShinkaDemoView_Free(ShinkaDemoView *view);
void ShinkaDemoView_Update(ShinkaDemoView *view);
void ShinkaDemoView_Draw(ShinkaDemoView *view);
// Plays the Pokémon's cry
void ShinkaDemoView_Start(ShinkaDemoView *view);
BOOL ShinkaDemoView_IsCryDone(ShinkaDemoView *view);
// Turns the sprite white and breaks it into pieces
void ShinkaDemoView_Evolve(ShinkaDemoView *view);
BOOL ShinkaDemoView_HavePiecesReturned(ShinkaDemoView *view);
// Shows the evolved sprite, still white
void ShinkaDemoView_Reveal(ShinkaDemoView *view);
// Fades the sprite in from white, then plays its cry
void ShinkaDemoView_FadeIn(ShinkaDemoView *view);
BOOL ShinkaDemoView_IsDone(ShinkaDemoView *view);
BOOL ShinkaDemoView_HavePiecesStarted(ShinkaDemoView *view);
// Set with HavePiecesReturned
BOOL ShinkaDemoView_GetUnk3C(ShinkaDemoView *view);
// Stops the evolution while the pieces are moving, and returns whether it did
BOOL ShinkaDemoView_Cancel(ShinkaDemoView *view);

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
