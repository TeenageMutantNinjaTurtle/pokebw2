#ifndef POKEBW2_SYSTEM_MCSS_H
#define POKEBW2_SYSTEM_MCSS_H

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "nitro/gx.h"
#include "nnsys/g2d.h"
#include "struct_decls.h"

// MCSS, the system that draws Pokémon and trainer sprites from multi-cell animations. It is mcss.c in the main module

typedef struct MCSSSystem MCSSSystem;
typedef struct MCSS MCSS;

// The archive and files of a sprite's graphics, as SetupPokemonLoaderFSTool fills it in
typedef struct {
    u32 arcId;
    u32 character;
    u32 palette;
    u32 cells;
    u32 cellAnime;
    u32 multiCells;
    u32 multiCellAnime;
    u32 bin;
    u32 unk20;
} MCSSLoadInfo;

// Called with the callback's parameter and the animation's frame
typedef void (*MCSSAnimationCallback)(u32 param, fx32 frame);

MCSSSystem *MCSSSys_Create(u32 capacity, HeapID heapId);
void MCSSSys_Free(MCSSSystem *system);
// Steps the animation of every sprite that is not paused
void MCSSSys_Update(MCSSSystem *system);
void MCSSSys_Draw(MCSSSystem *system);
MCSS *MCSSSys_Add(MCSSSystem *system, fx32 x, fx32 y, fx32 z, const MCSSLoadInfo *info);
void MCSSSys_Remove(MCSSSystem *system, MCSS *mcss);
void func_0201aacc(MCSSSystem *system);
// Where the sprites' character and palette data go: each sprite's is at these offsets plus 0x4000 and 0x20 bytes per
// slot
void func_0201aefc(MCSSSystem *system, u32 characterOffset);
void func_0201af00(MCSSSystem *system, u32 paletteOffset);

void MCSS_GetPosition(MCSS *mcss, VecFx32 *position);
void MCSS_SetPosition(MCSS *mcss, const VecFx32 *position);
void MCSS_SetScale(MCSS *mcss, const VecFx32 *scale);
void func_0201ac8c(MCSS *mcss);
void func_0201ac9c(MCSS *mcss);
void MCSS_PauseAnimation(MCSS *mcss);
void MCSS_ResumeAnimation(MCSS *mcss);
void MCSS_Hide(MCSS *mcss);
void MCSS_Show(MCSS *mcss);
// Sets the callback that runs when the sprite's animation reaches its last frame
void MCSS_SetAnimationEndCallback(MCSS *mcss, u32 param, MCSSAnimationCallback callback, u32 unused);
// Alpha from 0 to 31
void MCSS_SetAlpha(MCSS *mcss, u8 alpha);
void MCSS_SetAnimation(MCSS *mcss, u32 animation);
void MCSS_RestartAnimation(MCSS *mcss);
// Alpha from 0 to 31
u8 func_0201ae88(MCSS *mcss);
// Fades the palette between two levels of a color, and whether the fade is running
void func_0201ae2c(MCSS *mcss, u8 startLevel, u8 endLevel, s32 wait, GXRgb color);
BOOL func_0201aee8(MCSS *mcss);
void func_0201aecc(MCSS *mcss, u32 a1);
void func_0201ab54(MCSS *mcss, const VecFx32 *a1);
u16 func_0201ade8(MCSS *mcss);
s16 func_0201adf0(MCSS *mcss);
s16 func_0201adf8(MCSS *mcss);
// The sprite's animation controller, which NNS_G2dSetAnimCtrlCallBackFunctor takes
NNSG2dAnimController *func_0201adc4(MCSS *mcss);
void func_020618c0(NNSG2dAnimController *controller);
void func_0201c290(MCSS *mcss);
// Adds the sprite of a party Pokémon
MCSS *func_0201c14c(MCSSSystem *system, PartyPkm *pkm, u32 a2, fx32 x, fx32 y, fx32 z);

// SetupPokemonLoaderByBoxData for a party Pokémon
void func_0201bfdc(PartyPkm *pkm, MCSSLoadInfo *info, u32 a2);

#endif // POKEBW2_SYSTEM_MCSS_H
