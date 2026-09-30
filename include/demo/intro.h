#ifndef POKEBW2_DEMO_INTRO_H
#define POKEBW2_DEMO_INTRO_H

#include "types.h"
#include "gfl/clact.h"
#include "gfl/heap.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"
#include "system/mcss.h"

// The intro of a new game, overlay 294, which ov162 runs before and after the name entry
#define OVERLAY_INTRO OVERLAY_ID(294)

// Which part of the intro runs, as the number of the script it starts from: ov162 runs the intro, then the player's
// name entry, the intro again, the rival's name entry, and the intro once more
#define INTRO_MODE_START 1
#define INTRO_MODE_PLAYER_NAMED 7
#define INTRO_MODE_RIVAL_NAMED 10

// What ov162 does once the intro ends: runs the name entry that the intro asked for, the rival's name entry, or starts
// the game
#define INTRO_RESULT_DONE 0
#define INTRO_RESULT_ENTER_NAME 1
#define INTRO_RESULT_ENTER_RIVAL_NAME 2

typedef struct {
    PlayerInfo *playerInfo;
    void *unk4;
    // INTRO_MODE_*
    u32 mode;
    // ov162's creation of the save data, which runs while the intro does
    void *saveTask;
    // The Pokémon's cry
    void *pokeVoice;
    const u16 *rivalName;
    // INTRO_RESULT_*
    u32 result;
} IntroParam;

typedef struct IntroGraphic IntroGraphic;
typedef struct IntroCmd IntroCmd;
typedef struct IntroMcss IntroMcss;
typedef struct IntroG3d IntroG3d;
typedef struct IntroParticle IntroParticle;

extern const GameProcFunctions INTRO_PROC_FUNCTIONS;
// The sound sequences that the intro plays, which ov162 loads before it
extern const u32 INTRO_SOUND_COUNT;
extern const u32 INTRO_SOUNDS[];

// intro_graphic.c
IntroGraphic *IntroGraphic_Create(u32 layout, u32 mode, HeapID heapId);
void IntroGraphic_Free(IntroGraphic *graphic);
void IntroGraphic_Update(IntroGraphic *graphic);
void IntroGraphic_Begin3D(IntroGraphic *graphic);
void IntroGraphic_End3D(IntroGraphic *graphic);
ClActUnit *IntroGraphic_GetClActUnit(IntroGraphic *graphic);

// intro_cmd.c
IntroCmd *func_ov294_021a2ee8(IntroG3d *g3d, IntroParticle *particle, IntroMcss *mcss, IntroParam *param,
                              IntroGraphic *graphic, HeapID heapId);
void func_ov294_021a2f3c(IntroCmd *cmd);
BOOL func_ov294_021a2f50(IntroCmd *cmd);

// intro_mcss.c
IntroMcss *IntroMcss_Create(HeapID heapId, u32 mode);
void IntroMcss_Free(IntroMcss *mcss);
void IntroMcss_Draw(IntroMcss *mcss);
void IntroMcss_Add(IntroMcss *mcss, fx32 x, fx32 y, fx32 z, const MCSSLoadInfo *info, u8 index);
void IntroMcss_AddPokemon(IntroMcss *mcss, fx32 x, fx32 y, fx32 z, u32 species, u8 index);
void IntroMcss_SetVisible(IntroMcss *mcss, BOOL visible, u8 index);
void IntroMcss_SetAnimation(IntroMcss *mcss, u8 index, u32 animation, BOOL restartAtEnd);
BOOL IntroMcss_IsAnimationEnded(IntroMcss *mcss, u8 index);
void IntroMcss_ClearAnimationEnded(IntroMcss *mcss, u8 index);
void IntroMcss_SetAlpha(IntroMcss *mcss, u8 index, u32 alpha);
void func_ov294_021a3798(IntroMcss *mcss, u8 index, BOOL a2);
BOOL IntroMcss_MoveX(IntroMcss *mcss, u8 index, fx32 step, fx32 target);
BOOL IntroMcss_DecreaseY(IntroMcss *mcss, fx32 step, fx32 min);
void IntroMcss_Update(IntroMcss *mcss);

// intro_g3d.c
IntroG3d *IntroG3d_Create(IntroGraphic *graphic, u32 mode, HeapID heapId);
void IntroG3d_Free(IntroG3d *g3d);
void IntroG3d_Draw(IntroG3d *g3d);
BOOL IntroG3d_Open(IntroG3d *g3d);
void IntroG3d_SetVisible(IntroG3d *g3d, BOOL visible);
void IntroG3d_SetMode(IntroG3d *g3d, u32 mode);
BOOL IntroG3d_Animate(IntroG3d *g3d);
BOOL IntroG3d_AnimateBack(IntroG3d *g3d);
void IntroG3d_SetFrame(IntroG3d *g3d, u32 frame);

// intro_particle.c
IntroParticle *IntroParticle_Create(IntroGraphic *graphic, HeapID heapId);
void IntroParticle_Free(IntroParticle *particle);
void IntroParticle_Update(IntroParticle *particle);

#endif // POKEBW2_DEMO_INTRO_H
