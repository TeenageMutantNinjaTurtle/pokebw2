#ifndef POKEBW2_GFL_GRAPHICS_H
#define POKEBW2_GFL_GRAPHICS_H

#include "types.h"
#include "gfl/heap.h"
#include "nitro/g2d.h"
#include "nitro/gx.h"
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
// Load a BG's characters and screen from a file of an archive
void GFL_BGSysLoadArcNCGRStatic(ArcTool *arc, u32 fileId, u8 bg, u32 offset, u32 size, BOOL compressed, HeapID heapId);
void loadBGScrToVramByFileNoReserveNegAlign(ArcTool *arc, u32 fileId, u8 bg, u32 offset, u32 size, BOOL compressed,
                                            HeapID heapId);
// The same from a file of an archive by its ID
void GFL_BGSysLoadNCGRStatic(u32 arcId, u32 fileId, u8 bg, u32 offset, s32 size, BOOL compressed, HeapID heapId);
void loadBGScrToVramByNarcNoReserveNegAlign(u32 arcId, u32 fileId, u8 bg, u32 offset, s32 size, BOOL compressed,
                                            HeapID heapId);
// Loads a palette file of an archive to an offset in BG palette memory
void GFL_BGSysLoadNCLRDefault(u32 arcId, u32 fileId, u32 type, u32 offset, s32 size, HeapID heapId);
// Loads a palette file of an archive to palette memory
void GFL_G2DIOLoadArcNCLRDefault(ArcTool *arc, u32 fileId, u32 type, u32 offset, u32 size, HeapID heapId);
void GFL_G2DIOLoadNCLR(u32 bg, u32 paletteId, u32 a2, u32 a3, u32 a4, u32 size, u32 heapId);
// Read a character or palette file of an archive, and return the file for GFL_HeapFree
void *GFL_G2DIOReadOBJNCGR(u32 arcId, u32 fileId, BOOL compressed, NNSG2dCharacterData **character, HeapID heapId);
void *GFL_G2DIOReadNCLR(u32 arcId, u32 fileId, NNSG2dPaletteData **palette, HeapID heapId);
// Reads a screen file of an archive, and returns the file for GFL_HeapFree
void *GFL_G2DIOReadNSCRArc(ArcTool *arc, u32 fileId, BOOL compressed, NNSG2dScreenData **screen, HeapID heapId);
// The same from an open archive, the characters for OBJ
void *GFL_G2DIOReadOBJNCGRArc(ArcTool *arc, u32 fileId, BOOL compressed, NNSG2dCharacterData **character,
                              HeapID heapId);
void *GFL_G2DIOReadNCLRArc(ArcTool *arc, u32 fileId, NNSG2dPaletteData **palette, HeapID heapId);
// Loads a screen file of an archive to a BG's screen
void GFL_G2DIOLoadNSCRSync(ArcTool *arc, u32 fileId, u8 bg, u32 offset, u32 a4, u32 a5, BOOL compressed, HeapID heapId);
void GFXRegSetMasterBrightness(u32 reg, s32 brightness);
// Called with the offset of BG 1 of the main engine whenever it is set. Unnamed, as what it does is not known
void func_02042ee0(int x, int y);
// Loaded with part of a palette file, stepped each frame and reset. Unnamed, as what it does is not known
void *func_02035024(u32 a0, u32 a1, u32 a2, HeapID heapId);
void func_02035104(void *a0, ArcTool *arc, u32 fileId, u32 a3, u32 a4);
void func_02035178(void *a0);
void func_02035198(void *a0);
void func_020352b0(void *a0);
BOOL NNS_G2DPrepareBGChar(void *file, NNSG2dCharacterData **character);
BOOL NNS_G2DPrepareScreen(void *file, NNSG2dScreenData **screen);
BOOL RelocatePaletteResGetDataPtr(void *file, NNSG2dPaletteData **palette);
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
void func_0202778c(void *a0, u32 a1);
void func_020275f8(void *a0);

#endif // POKEBW2_GFL_GRAPHICS_H
