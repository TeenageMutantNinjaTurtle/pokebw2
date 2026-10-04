#ifndef POKEBW2_GFL_GRAPHICS_H
#define POKEBW2_GFL_GRAPHICS_H

#include "types.h"
#include "nitro/fx.h"
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

// The BG system's setups. Names and layouts from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

// BG sizes in pixels
#define BGRES_128x128 0
#define BGRES_256x256 1
#define BGRES_256x512 2
#define BGRES_512x256 3
#define BGRES_512x512 4
#define BGRES_1024x1024 5

#define BGMODE_TEXT 0
#define BGMODE_AFFINE 1
#define BGMODE_EXTENDED 2

#define BG_MOVE_SET_X 0
#define BG_MOVE_RIGHT 1
#define BG_MOVE_LEFT 2
#define BG_MOVE_SET_Y 3
#define BG_MOVE_DOWN 4
#define BG_MOVE_UP 5

typedef struct {
    u32 x;
    u32 y;
    u32 screenSize;
    u32 screenOffset;
    u8 resolution;
    u8 colorMode;
    u8 screenBase;
    u8 charBase;
    u32 charSize;
    u8 extPaletteSlot;
    u8 priority;
    u8 areaOverflow;
    u32 mosaic;
} BGSetup;

typedef struct {
    u32 displayMode;
    u32 bgModeMain;
    u32 bgModeSub;
    BOOL bg0Is3D;
} BGSysLCDConfig;

enum {
    BGSYS_ENGINE_MAIN,
    BGSYS_ENGINE_SUB,
};

typedef struct {
    u32 bgMain;
    u32 bgExtPaletteMain;
    u32 bgSub;
    u32 bgExtPaletteSub;
    u32 objMain;
    u32 objExtPaletteMain;
    u32 objSub;
    u32 objExtPaletteSub;
    u32 texture;
    u32 texturePalette;
    u32 objMappingMain;
    u32 objMappingSub;
} BGSysVRAMConfig;

BOOL G3DTextDraw_CreateResource(void *texture, const char *texName, u32 a2, const char *plName, const StrBuf *text, u16 a5,
                                u16 a6, u32 a7, HeapID heapId, G3DTextDrawResource *resource);
void GFL_BGSysClearBG(u8 bg);
void GFL_BGSysClearScr(u8 bg);
void GFL_BGSysCreate(HeapID heapId);
void GFL_BGSysCreateBG(u8 bg, const BGSetup *setup, u8 mode);
void GFL_BGSysDisableAllA(void);
void GFL_BGSysDisableAllB(void);
void GFL_BGSysEnableEngines(void);
// Fills tileCount tiles from offset of a BG's characters with a color index
void GFL_BGSysFillChar(u8 bg, u32 fillIndex, u32 tileCount, u32 offset);
void GFL_BGSysFreeFilledChar(u8 bg, u32 fillIndex, u32 offset);
void GFL_BGSysFillScrArea(u8 bg, u16 tile, u8 x, u8 y, u8 width, u8 height, u8 palette);
// Fills a BG's whole screen with a map entry, sent at the next update
void GFL_BGSysFillScrAsync(u8 bg, u16 map);
void GFL_BGSysFree(void);
u32 GFL_BGSysGetEnabledBGsA(void);
u32 GFL_BGSysGetEnabledBGsB(void);
void GFL_BGSysInitVRAM(u32 banks);
// Load a BG's characters and screen from a file of an archive
void GFL_BGSysLoadArcNCGRStatic(ArcTool *arc, u32 fileId, u8 bg, u32 offset, u32 size, BOOL compressed, HeapID heapId);
void loadBGScrToVramByFileNoReserveNegAlign(ArcTool *arc, u32 fileId, u8 bg, u32 offset, u32 size, BOOL compressed,
                                            HeapID heapId);
// The same from a file of an archive by its ID
void GFL_BGSysLoadNCGRStatic(u32 arcId, u32 fileId, u8 bg, u32 offset, s32 size, BOOL compressed, HeapID heapId);
void loadBGScrToVramByNarcNoReserveNegAlign(u32 arcId, u32 fileId, u8 bg, u32 offset, s32 size, BOOL compressed,
                                            HeapID heapId);
void GFL_BGSysLoadChar(u32 bg, void *data, u32 size, u32 offset);
// Loads a palette file of an archive to an offset in BG palette memory
void GFL_BGSysLoadNCLRDefault(u32 arcId, u32 fileId, u32 type, u32 offset, s32 size, HeapID heapId);
void GFL_BGSysLoadScr(u8 bg);
void GFL_BGSysLoadScrArea(u8 bg, u8 x, u8 y, u8 width, u8 height, const u16 *src, u8 srcX, u8 srcY, u8 srcWidth,
                          u8 srcHeight);
void GFL_BGSysLoadScrAreaLarge(u8 bg, u8 x, u8 y, u8 width, u8 height, const u16 *src, u8 srcX, u8 srcY, u8 srcWidth,
                               u8 srcHeight);
void GFL_BGSysLoadScrCore(u32 bg, void *data, u32 size, u32 offset);
void GFL_BGSysQueueScrLoad(u32 bg);
void GFL_BGSysMoveBGReq(u8 bg, u32 type, u32 value);
void GFL_BGSysReleaseBG(u8 bg);
// Allocates characters of a BG, returning their position, and frees them
u16 GFL_BGSysAllocChar(u32 bg, u32 size, u32 dir);
void GFL_BGSysFreeCharMemory(u32 bg, u16 pos, u16 size);
// Fills a screen's standard palette with a color, 0 for the main screen and 4 for the sub screen
void GFL_BGSysResetStdPalette(u32 type, GXRgb color);
// Enables BG 0 of the main engine, where the 3D is drawn, and sets its priority
void GFL_BGSysSet3DBGPriority(u16 priority);
void GFL_BGSysSetBGEnabled(u8 bg, u8 enabled);
// Enables or disables the planes of GX_PLANEMASK on the main or sub engine
void GFL_BGSysSetBGEnabledA(u32 planes, BOOL enabled);
void GFL_BGSysSetBGEnabledB(u32 planes, BOOL enabled);
void GFL_BGSysSetBGPriority(u32 bg, u32 priority);
void GFL_BGSysSetDisplayLayout(u32 layout);
void GFL_BGSysSetEnabledBGsA(u32 enabled);
void GFL_BGSysSetEnabledBGsB(u32 enabled);
void GFL_BGSysSetLCDConfig(const BGSysLCDConfig *config);
// Sets only the modes of one engine from a config: the display mode, main BG mode and BG 0 of the main engine, or the
// BG mode of the sub engine
void GFL_BGSysSetLCDConfigForEngine(const BGSysLCDConfig *config, u32 engine);
void GFL_BGSysSetVRAMBanks(const BGSysVRAMConfig *config);
void GFL_BGSysSetScrPaletteNo(u8 bg, u8 x, u8 y, u8 width, u8 height, u8 palette);
void GFL_BGSysUpdate(void);
void GFL_BGSysUploadStdPalette(u32 bg, void *data, u32 size, u32 offset);
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
s32 gfxRegGetMasterBrightness(u32 reg);
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
void gfxRegSetBGTransform(vu16 *reg, const MtxFx22 *mtx, fx32 centerX, fx32 centerY, fx32 scrollX, fx32 scrollY);
void gfxSetEdgeColorTable(const GXRgb *table);
void gfxSetFogTable(const u32 *table);

#endif // POKEBW2_GFL_GRAPHICS_H
