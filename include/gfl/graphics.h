#ifndef POKEBW2_GFL_GRAPHICS_H
#define POKEBW2_GFL_GRAPHICS_H

#include "types.h"
#include "gfl/heap.h"
#include "nitro/g2d.h"
#include "struct_decls.h"

struct G3DTextDrawResource {
    u16 unk0;
    u16 unk2;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
};

BOOL G3DTextDraw_CreateResource(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 a5, u16 a6, u32 a7, HeapID heapId,
                                G3DTextDrawResource *resource);
void GFL_BGSysClearBG(u32 bg);
void GFL_BGSysCreate(HeapID heapId);
void GFL_BGSysCreateBG(u32 bg, const void *setup, u32 mode);
void GFL_BGSysFree(void);
u32 GFL_BGSysGetEnabledBGsA(void);
void GFL_BGSysLoadChar(u32 bg, void *data, u32 size, u32 offset);
void GFL_BGSysLoadScrCore(u32 bg, void *data, u32 size, u32 offset);
void GFL_BGSysReleaseBG(u32 bg);
void GFL_BGSysSetBGEnabled(u32 bg, BOOL enabled);
void GFL_BGSysSetBGPriority(u32 bg, u32 priority);
void GFL_BGSysSetEnabledBGsA(u32 enabled);
void GFL_BGSysSetLCDConfig(const void *config);
void GFL_BGSysSetVRAMBanks(const void *config);
void GFL_BGSysUploadStdPalette(u32 bg, void *data, u32 size, u32 offset);
void GFXRegSetMasterBrightness(u32 reg, s32 brightness);
BOOL NNS_G2DPrepareBGChar(void *file, NNSG2dCharacterData **character);
BOOL NNS_G2DPrepareScreen(void *file, NNSG2dScreenData **screen);
BOOL RelocatePaletteResGetDataPtr(void *file, NNSG2dPaletteData **palette);
void gfxDisableLCDCBanks(void);
void gfxRegSetAlphaBlend(u32 reg, u32 plane1, u32 plane2, s32 alpha1, s32 alpha2);
void gfxRegSetBrightnessBlend(u32 reg, u32 plane, s32 brightness);
void gfxSetLCDCBanks(u32 banks);
void gfxUploadAsync(u32 type, u32 dest, const void *src, u32 size);

#endif // POKEBW2_GFL_GRAPHICS_H
