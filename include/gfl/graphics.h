#ifndef POKEBW2_GFL_GRAPHICS_H
#define POKEBW2_GFL_GRAPHICS_H

#include "types.h"
#include "nitro/fx.h"
#include "gfl/heap.h"
#include "nitro/gx.h"
#include "nnsys/g2d.h"
#include "struct_decls.h"

struct G3DTextDrawResource {
    u16 unk0;
    u16 unk2;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
};

BOOL G3DTextDraw_CreateResource(void *texture, const char *texName, u32 a2, const char *plName, const StrBuf *text, u16 a5,
                                u16 a6, u32 a7, HeapID heapId, G3DTextDrawResource *resource);
void GFXRegSetMasterBrightness(u32 reg, s32 brightness);
s32 gfxRegGetMasterBrightness(u32 reg);
// Loaded with part of a palette file, stepped each frame and reset. Unnamed, as what it does is not known
void *func_02035024(u32 a0, u32 a1, u32 a2, HeapID heapId);
void func_02035104(void *a0, ArcTool *arc, u32 fileId, u32 a3, u32 a4);
void func_02035178(void *a0);
void func_02035198(void *a0);
void func_020352b0(void *a0);
void gfxClearColor(GXRgb color, u8 alpha, s16 depth, u8 polygonId, BOOL fog);
void gfxDisableLCDCBanks(void);
void gfxRegSetAlphaBlend(u32 reg, u32 plane1, u32 plane2, s32 alpha1, s32 alpha2);
void gfxRegSetBrightnessBlend(u32 reg, u32 plane, s32 brightness);
void gfxRegSetBlend(u32 reg, u32 plane1, u32 plane2, s32 alpha1, s32 alpha2, u32 all);
void gfxRegAdjustBrightnessBlend(u32 reg, s32 brightness);
void gfxSetFog(u8 enabled, u16 alphaMode, u16 depthShift, u16 offset);
void gfxSetLCDCBanks(u32 banks);
void gfxUploadAsync(u32 type, u32 dest, const void *src, u32 size);
// Set up for the move forgetting screen of overlay 287 and updated at every VBlank; what they do is not known yet
void *func_02026dc0(HeapID heapId);
void func_02026de8(void *a0);
void func_02026e04(void *a0, u32 bg, u32 a2, HeapID heapId);
void func_02026e48(void *a0, u32 bg);
// Loads a palette from an archive into the fade's buffers
void func_02026ee8(void *a0, u32 arcId, u32 fileId, HeapID heapId, u32 type, u32 size, u16 offset);
void func_0202778c(void *a0, u32 a1);
void func_020275f8(void *a0);
void gfxSetEdgeColorTable(const GXRgb *table);
void gfxSetFogTable(const u32 *table);

#endif // POKEBW2_GFL_GRAPHICS_H
