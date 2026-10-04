#include "types.h"
#include "app/bag.h"
#include "app/box2_bgwfrm.h"
#include "app/box2_bmp.h"
#include "app/box2_main.h"
#include "app/box2_obj.h"
#include "app/box2_ui.h"
#include "app/box_search.h"
#include "app/name_entry.h"
#include "app/ov207.h"
#include "constants/arc.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "gfl/arc.h"
#include "gfl/arc_util.h"
#include "gfl/bg_sys.h"
#include "gfl/bmpwin.h"
#include "gfl/clact.h"
#include "gfl/graphics.h"
#include "gfl/gx_layers.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "gfl/tcb.h"
#include "gfl/ui.h"
#include "nitro/gx.h"
#include "nitro/hw.h"
#include "nitro/math.h"
#include "nitro/os.h"
#include "pml/item.h"
#include "pml/personal.h"
#include "pml/poke_party.h"
#include "save/box.h"
#include "save/chatter.h"
#include "save/dream_world.h"
#include "save/pokedex.h"
#include "save/save_control.h"
#include "system/app_common.h"
#include "system/app_taskmenu.h"
#include "system/bgwinfrm.h"
#include "system/cursor_move.h"
#include "system/game_data.h"
#include "system/gf_font.h"
#include "system/printsys.h"
#include "system/wordset.h"

// The PC box's graphics setup, the moves of Pokémon between the boxes and the party, and the frames and buttons that
// slide in and out. Names are ours

static void Box2Main_VBlank(TCB *tcb, void *data);
static void PokeDataSwapBoxParty(Box2SysWork *syswk, Box2PokeMoveData *box, Box2PokeMoveData *party);
static void PokeDataMoveBoxToParty(Box2SysWork *syswk, Box2PokeMoveData *box);
static void PokeDataMovePartyToBox(Box2SysWork *syswk, Box2PokeMoveData *party);
static void PokeDataSwapParty(Box2SysWork *syswk, Box2PokeMoveData *party);
static void PokeDataMoveParty(Box2SysWork *syswk, Box2PokeMoveData *party);
static void PokeDataSortParty(Box2SysWork *syswk, Box2PokeMoveWork *work);
static u32 PokeDataMoveToTray(Box2SysWork *syswk, u32 tray, u32 pos, u32 dstTray);
static void PokeDataRangeMoveToTray(Box2SysWork *syswk, u32 tray, u32 pos, u32 dstTray);
static void PokeDataPartyMoveToTray(Box2SysWork *syswk, u32 pos, u32 dstTray);
static void PokeChangeForme(Box2SysWork *syswk, BoxPkm *pkm, u32 forme);
static void PokeFormChangeShaymin(Box2SysWork *syswk, u32 putPos, u32 getPos, u32 tray);
static void PokeIconRangeMove(Box2SysWork *syswk, Box2PokeMoveData *data, u32 cnt, u32 x, u32 y, u32 width);
static inline u8 PokeIconMoveEnd(Box2SysWork *syswk, u32 iconPos, u32 pos);
static BOOL Box2Main_VFuncRangePokeMove(Box2SysWork *syswk);
static BOOL Box2Main_VFuncGetPokeMove(Box2SysWork *syswk);
static BOOL Box2Main_VFuncPokeMoveParty(Box2SysWork *syswk);
static BOOL Box2Main_IsEggFree(Box2SysWork *syswk, u32 pos, u32 tray);
static BOOL Box2Main_PokeMoveCheck(Box2SysWork *syswk, u32 getPos, u32 putPos);
static BOOL Box2Main_PartyOutCheck(Box2SysWork *syswk, u32 pos, u32 putPos);
static inline void PokeIconMoveVector(Box2PokeMoveData *data, s16 *x, s16 *y);
static void PokeIconMoveParamMake(Box2SysWork *syswk, Box2PokeMoveData *data);
static void PokeIconChgParamMake(Box2SysWork *syswk, Box2PokeMoveData *data);
static void PokeIconMoveSubParamMake(Box2SysWork *syswk, Box2PokeMoveData *data);
static BOOL func_ov255_021c276c(Box2SysWork *syswk, u32 index);
static void PokeIconChgDataMake(Box2SysWork *syswk, u32 getPos, u32 putPos);
static BOOL PokeIconMoveDataMake(Box2SysWork *syswk, u32 getPos, u32 putPos);
static void PokeIconPartyOutDataMake(Box2SysWork *syswk, u32 getPos, u32 putPos);
static void PokeIconPartyInDataMake(Box2SysWork *syswk, u32 getPos, u32 putPos);
static u32 Box2Main_GetPokeMoveDest(Box2SysWork *syswk, u32 iconPos);
static void PokeIconFreeDataMake(Box2SysWork *syswk, u32 pos);
static void PokeIconBufPosChange(Box2SysWork *syswk, Box2PokeMoveWork *work);
static void PokeIconBufPosChangeRange(Box2SysWork *syswk, Box2PokeMoveWork *work);
static void PokeIconBufPosChangeAll(Box2SysWork *syswk, Box2PokeMoveWork *work);
static int PokeFreeWazaCheck(u16 move);
static void ItemIconMoveMakeCore(Box2SysWork *syswk, u32 setPos, u32 putPos, u32 mvMode, BOOL hand);
static void Box2Main_ItemIconMoveMakeScroll(Box2SysWork *syswk, u32 mvMode);
static void Box2Main_ItemIconMoveMakeHand(Box2SysWork *syswk, u32 setPos, u32 putPos, u32 mvMode);
static void Box2Main_ItemIconMoveMake(Box2SysWork *syswk, u32 putPos, u32 mvMode);
static BOOL ItemIconMoveMain(Box2SysWork *syswk, BOOL hand);
static BOOL Box2Main_VFuncItemIconMoveHand(Box2SysWork *syswk);
static BOOL Box2Main_VFuncItemIconMove(Box2SysWork *syswk);
static void WallCharLoad(Box2SysWork *syswk, u32 wallpaper, u32 offset);
static void WallPaletteLoad(Box2SysWork *syswk, u32 wallpaper, u32 palette);
static void WallScreenLoad(Box2SysWork *syswk, u32 wallpaper, u32 x, u32 charOffset, u32 palette);
static void WallGraSet(Box2SysWork *syswk, u32 wallpaper, u32 x, u32 charOffset, u32 palette);
static Box2PokeInfo *PokeInfoDataMake(BoxPkm *pkm);
static void PokeInfoDataFree(Box2PokeInfo *info);
static void PokeInfoPutModeNormal(Box2SysWork *syswk, Box2PokeInfo *info);
static void MarkingPut(Box2SysWork *syswk, u32 base, u32 mark);
static void Box2Main_MarkingOff(Box2AppWork *app);
static void PokeInfoIconPut(Box2AppWork *app, Box2PokeInfo *info);
static BOOL AreaCheck(int x, int y, const Box2Area *area);
static u32 TrayPokePutAreaCheck(s16 x, s16 y);
static u32 PartyPokePutAreaCheck(s16 x, s16 y, const Box2Area *areas);
static u32 BoxMovePutAreaCheck(Box2SysWork *syswk, s16 x, s16 y);
static void PokeIconRangeTouchMove(Box2SysWork *syswk, u32 x, u32 y);
static void func_ov255_021c265c(Box2SysWork *syswk, u32 getPos, u32 putPos);

// Where the tray's Pokémon are on the lower screen
static const Box2Area sTrayPokeArea = { 8, 159, 40, 159 };

static const BGSysVRAMConfig sVramBanks = {
    GX_VRAM_BG_128_A,  GX_VRAM_BGEXTPLTT_NONE,  GX_VRAM_SUB_BG_128_C,        GX_VRAM_SUB_BGEXTPLTT_NONE,
    GX_VRAM_OBJ_128_B, GX_VRAM_OBJEXTPLTT_NONE, GX_VRAM_SUB_OBJ_128_D,       GX_VRAM_SUB_OBJEXTPLTT_NONE,
    GX_VRAM_TEX_NONE,  GX_VRAM_TEXPLTT_NONE,    GX_OBJVRAMMODE_CHAR_1D_128K, GX_OBJVRAMMODE_CHAR_1D_128K,
};

void Box2Main_InitVBlank(Box2SysWork *syswk) {
    syswk->app->vtask = GFL_VBlankTCBAdd(Box2Main_VBlank, syswk, 0);
}

void Box2Main_ExitVBlank(Box2SysWork *syswk) {
    GFL_TCBRemove(syswk->app->vtask);
}

static void Box2Main_VBlank(TCB *tcb, void *data) {
    Box2SysWork *syswk = data;

    func_ov255_021cdf9c(syswk->app);
    GFL_BGSysUpdate();
    func_0204b7c8();
    func_020275f8(syswk->app->palFade);
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

void Box2Main_VFuncSet(Box2AppWork *app, Box2VFunc func) {
    app->vfunk.seq = 0;
    app->vfunk.cnt = 0;
    app->vfunk.func = func;
    app->vfunk.freq = NULL;
}

void Box2Main_VFuncReq(Box2AppWork *app, Box2VFunc func) {
    app->vfunk.freq = func;
}

void Box2Main_VFuncReqSet(Box2AppWork *app) {
    Box2Main_VFuncSet(app, app->vfunk.freq);
}

void Box2Main_InitVramBanks(void) {
    GFL_BGSysInitVRAM(0);
    GFL_BGSysSetVRAMBanks(&sVramBanks);
}

const BGSysVRAMConfig *Box2Main_GetVramBanks(void) {
    return &sVramBanks;
}

void Box2Main_InitBg(Box2SysWork *syswk) {
    GFL_BGSysCreate(HEAPID_BOX2_APP);

    {
        BGSysLCDConfig config = { GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BGMODE_0, GX_BG0_AS_2D };
        GFL_BGSysSetLCDConfig(&config);
    }

    // Main screen
    {
        BGSetup setup = {
            0,
            0,
            0x800,
            0,
            BGRES_256x256,
            GX_BG_COLORMODE_16,
            GX_BG_SCRBASE(0xf800),
            GX_BG_CHARBASE(0x18000),
            0x8000,
            GX_BG_EXTPLTT_01,
            0,
            GX_BG_AREAOVER_XLU,
            FALSE,
        };
        GFL_BGSysCreateBG(0, &setup, BGMODE_TEXT);
    }
    {
        BGSetup setup = {
            0,
            0,
            0x800,
            0,
            BGRES_256x256,
            GX_BG_COLORMODE_16,
            GX_BG_SCRBASE(0xf000),
            GX_BG_CHARBASE(0x10000),
            0x8000,
            GX_BG_EXTPLTT_01,
            1,
            GX_BG_AREAOVER_XLU,
            FALSE,
        };
        GFL_BGSysCreateBG(1, &setup, BGMODE_TEXT);
        GFL_BGSysClearScr(1);
        GFL_BGSysClearCharCore(1, 0x20, 0, HEAPID_BOX2_APP);
    }
    {
        BGSetup setup = {
            0,
            0,
            0x800,
            0,
            BGRES_256x256,
            GX_BG_COLORMODE_16,
            GX_BG_SCRBASE(0xe800),
            GX_BG_CHARBASE(0x08000),
            0x8000,
            GX_BG_EXTPLTT_01,
            2,
            GX_BG_AREAOVER_XLU,
            FALSE,
        };
        GFL_BGSysCreateBG(2, &setup, BGMODE_TEXT);
    }
    {
        BGSetup setup = {
            0,
            0,
            0x1000,
            0,
            BGRES_512x256,
            GX_BG_COLORMODE_16,
            GX_BG_SCRBASE(0xd800),
            GX_BG_CHARBASE(0x00000),
            0x8000,
            GX_BG_EXTPLTT_01,
            3,
            GX_BG_AREAOVER_XLU,
            FALSE,
        };
        GFL_BGSysCreateBG(3, &setup, BGMODE_TEXT);
    }

    // Sub screen
    {
        BGSetup setup = {
            0,
            0,
            0x800,
            0,
            BGRES_256x256,
            GX_BG_COLORMODE_16,
            GX_BG_SCRBASE(0xf800),
            GX_BG_CHARBASE(0x10000),
            0x8000,
            GX_BG_EXTPLTT_01,
            1,
            GX_BG_AREAOVER_XLU,
            FALSE,
        };
        GFL_BGSysCreateBG(4, &setup, BGMODE_TEXT);
        GFL_BGSysClearScr(4);
        GFL_BGSysClearCharCore(4, 0x20, 0, HEAPID_BOX2_APP);
    }
    {
        BGSetup setup = {
            0,
            0,
            0x1000,
            0,
            BGRES_256x512,
            GX_BG_COLORMODE_16,
            GX_BG_SCRBASE(0xe800),
            GX_BG_CHARBASE(0x00000),
            0x8000,
            GX_BG_EXTPLTT_01,
            2,
            GX_BG_AREAOVER_XLU,
            FALSE,
        };
        GFL_BGSysCreateBG(5, &setup, BGMODE_TEXT);
    }
    {
        BGSetup setup = {
            0,
            0,
            0x800,
            0,
            BGRES_256x256,
            GX_BG_COLORMODE_16,
            GX_BG_SCRBASE(0xe000),
            GX_BG_CHARBASE(0x18000),
            0x8000,
            GX_BG_EXTPLTT_01,
            0,
            GX_BG_AREAOVER_XLU,
            FALSE,
        };
        GFL_BGSysCreateBG(6, &setup, BGMODE_TEXT);
        GFL_BGSysClearScr(6);
        GFL_BGSysClearCharCore(6, 0x20, 0, HEAPID_BOX2_APP);
    }

    GFL_BGSysSetBGEnabledA(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3, TRUE);
    GFL_BGSysSetBGEnabledB(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2, TRUE);
}

void Box2Main_ExitBg(Box2SysWork *syswk) {
    GFL_BGSysSetBGEnabledA(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3, FALSE);
    GFL_BGSysSetBGEnabledB(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2, FALSE);
    GFL_BGSysReleaseBG(6);
    GFL_BGSysReleaseBG(5);
    GFL_BGSysReleaseBG(4);
    GFL_BGSysReleaseBG(3);
    GFL_BGSysReleaseBG(2);
    GFL_BGSysReleaseBG(1);
    GFL_BGSysReleaseBG(0);
    GFL_BGSysFree();
}

void Box2Main_LoadBgGraphics(Box2SysWork *syswk) {
    ArcTool *arc;
    ArcTool *uiArc;
    u32 charOffset;
    u16 *src;
    u16 *dst;
    u32 i;

    arc = GFL_ArcSysCreateFileHandle(ARCID_BOX2, HEAPID_BOX2_APP);
    GFL_BGSysLoadArcNCGRStatic(arc, 12, 1, 0, 0, TRUE, HEAPID_BOX2_APP);
    GFL_BGSysLoadArcNCGRDynamic(arc, 3, 2, 0, TRUE, HEAPID_BOX2_APP);
    loadBGScrToVramByFileNoReserveNegAlign(arc, 2, 2, 0, 0, TRUE, HEAPID_BOX2_APP);
    GFL_BGSysLoadArcNCGRStatic(arc, 1, 3, 0, 0, TRUE, HEAPID_BOX2_APP);
    loadBGScrToVramByFileNoReserveNegAlign(arc, 0, 3, 0, 0, TRUE, HEAPID_BOX2_APP);
    GFL_G2DIOLoadArcNCLRDefault(arc, 4, 0, 0, 0x80, HEAPID_BOX2_APP);
    GFL_BGSysLoadArcNCGRStatic(arc, 62, 1, 0x3e8, 0x300, TRUE, HEAPID_BOX2_APP);
    GFL_G2DIOLoadArcNCLRDefault(arc, 63, 0, 0x180, 0x40, HEAPID_BOX2_APP);

    {
        NNSG2dPaletteData *palette;
        void *buf = GFL_G2DIOReadNCLR(getUINarcIdx(), 31, &palette, HEAPID_TAIL(HEAPID_BOX2_APP));
        u8 *colors = palette->rawData;
        u32 offset = 0x194;

        GFL_BGSysUploadStdPalette(0, colors + 0x34, 4, offset);
        colors += 0x14;
        offset += 0x20;
        GFL_BGSysUploadStdPalette(0, colors, 4, offset);
        GFL_HeapFree(buf);
    }

    GFL_BGSysLoadArcNCGRStatic(arc, 6, 5, 0, 0, TRUE, HEAPID_BOX2_APP);
    loadBGScrToVramByFileNoReserveNegAlign(arc, 5, 5, 0, 0, TRUE, HEAPID_BOX2_APP);
    GFL_BGSysLoadArcNCGRStatic(arc, 6, 6, 0, 0, TRUE, HEAPID_BOX2_APP);
    GFL_G2DIOLoadArcNCLRDefault(arc, 7, 4, 0, 0, HEAPID_BOX2_APP);
    GFL_ArcToolFree(arc);

    // The bar at the bottom of the main screen, which BG 2 copies
    uiArc = GFL_ArcSysCreateFileHandle(getUINarcIdx(), HEAPID_BOX2_APP);
    GFL_BGSysLoadArcNCGRDynamic(uiArc, func_0202d824(), 0, 0, FALSE, HEAPID_BOX2_APP);
    GFL_G2DIOLoadArcNCLRDefault(uiArc, func_0202d820(), 0, 0xe0, 0x20, HEAPID_BOX2_APP);
    loadBGScrToVramByFileNoReserveNegAlign(uiArc, func_0202d828(), 0, 0, 0, FALSE, HEAPID_BOX2_APP);
    GFL_BGSysSetScrPaletteNo(0, 0, 21, 32, 3, 7);
    GFL_BGSysQueueScrLoad(0);
    charOffset = GFL_BGSysLoadArcNCGRDynamic(uiArc, func_0202d824(), 2, 0, FALSE, HEAPID_BOX2_APP);
    GFL_ArcToolFree(uiArc);

    src = GFL_BGSysIsScrHeapExists(0);
    dst = GFL_BGSysIsScrHeapExists(2);
    for (i = 0; i < 32 * 3; i++) {
        dst[21 * 32 + i] = src[21 * 32 + i] + charOffset;
    }
    GFL_BGSysQueueScrLoad(2);

    syswk->app->cursorChars = LoadCursorImageEndOfHeap(0, 10, 0, HEAPID_BOX2_APP);
    GFL_BGSysLoadNCLRDefault(ARCID_FONT, 5, 0, 0x160, 0x20, HEAPID_BOX2_APP);
    GFL_BGSysLoadNCLRDefault(ARCID_FONT, 5, 4, 0x1e0, 0x20, HEAPID_BOX2_APP);
}

void Box2Main_InitPaletteFade(Box2SysWork *syswk) {
    syswk->app->palFade = func_02026dc0(HEAPID_BOX2_APP);
    func_02026e04(syswk->app->palFade, 0, 0x200, HEAPID_BOX2_APP);
}

void Box2Main_ExitPaletteFade(Box2SysWork *syswk) {
    func_02026e48(syswk->app->palFade, 0);
    func_02026de8(syswk->app->palFade);
}

void Box2Main_SetBlendAlpha(BOOL enabled) {
    if (enabled == TRUE) {
        gfxRegSetAlphaBlend(REG_BLDCNT_ADDR, GX_BLEND_PLANEMASK_NONE,
                            GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_BD, 6, 10);
    } else {
        G2_BlendNone();
    }
}

void Box2Main_InitMsg(Box2SysWork *syswk) {
    syswk->app->msgData = GFL_MsgSysLoadData(FALSE, ARCID_SYSTEM_MESSAGE, 13, HEAPID_BOX2_APP);
    syswk->app->font = GFL_FontCreate(ARCID_FONT, 0, 1, FALSE, HEAPID_BOX2_APP);
    syswk->app->smallFont = GFL_FontCreate(ARCID_FONT, 3, 0, FALSE, HEAPID_BOX2_APP);
    syswk->app->wordSet = GFL_WordSetSystemCreateDefault(HEAPID_BOX2_APP);
    syswk->app->printQueue = func_020219a8(0x800, HEAPID_BOX2_APP);
    syswk->app->expandBuf = GFL_StrBufCreate(0x400, HEAPID_BOX2_APP);
}

void Box2Main_ExitMsg(Box2SysWork *syswk) {
    GFL_StrBufFree(syswk->app->expandBuf);
    func_02021a18(syswk->app->printQueue);
    GFL_WordSetSystemFree(syswk->app->wordSet);
    GFL_FontFree(syswk->app->smallFont);
    GFL_FontFree(syswk->app->font);
    GFL_MsgDataFree(syswk->app->msgData);
}

void Box2Main_InitYesNo(Box2SysWork *syswk) {
    syswk->app->yesNoItems[0].str = GFL_MsgDataLoadStrbufNew(syswk->app->msgData, 110);
    syswk->app->yesNoItems[0].color = 0x39e3;
    syswk->app->yesNoItems[0].type = 0;
    syswk->app->yesNoItems[1].str = GFL_MsgDataLoadStrbufNew(syswk->app->msgData, 111);
    syswk->app->yesNoItems[1].color = 0x39e3;
    syswk->app->yesNoItems[1].type = 0;
    syswk->app->yesNoRes = func_0202e168(0, 8, syswk->app->font, syswk->app->printQueue, HEAPID_BOX2_APP);
}

void Box2Main_ExitYesNo(Box2SysWork *syswk) {
    func_0202e1dc(syswk->app->yesNoRes);
    GFL_StrBufFree(syswk->app->yesNoItems[1].str);
    GFL_StrBufFree(syswk->app->yesNoItems[0].str);
}

void Box2Main_OpenYesNo(Box2SysWork *syswk, u32 pos) {
    AppTaskMenuParam param;

    param.heapId = HEAPID_BOX2_APP;
    param.itemCount = 2;
    param.items = syswk->app->yesNoItems;
    param.posType = 1;
    param.x = 32;
    param.y = 18;
    param.width = 8;
    param.height = 3;
    if (func_0202ba70(syswk->app->cursorMove) == TRUE) {
        func_0203d564(FALSE);
    } else {
        func_0203d564(TRUE);
    }
    syswk->app->yesNoMenu = func_0202d974(&param, syswk->app->yesNoRes);
    func_0202def8(syswk->app->yesNoMenu, pos);
}

BOOL Box2Main_ButtonAnmMain(Box2SysWork *syswk) {
    Box2ButtonAnm *bawk = &syswk->app->bawk;

    switch (bawk->seq) {
    case 0:
        if (bawk->mode == BOX2_BTN_ANM_MODE_OBJ) {
            func_ov255_021cf608(syswk->app, bawk->id, bawk->pal1);
        } else {
            GFL_BGSysSetScrPaletteNo(bawk->id, bawk->px, bawk->py, bawk->sx, bawk->sy, bawk->pal1);
            GFL_BGSysQueueScrLoad(bawk->id);
        }
        bawk->seq++;
        break;
    case 1:
        if (bawk->mode == BOX2_BTN_ANM_MODE_OBJ) {
            if (func_ov255_021cf628(syswk->app, bawk->id) == FALSE) {
                return FALSE;
            }
        } else {
            bawk->cnt++;
            if (bawk->cnt == 4) {
                GFL_BGSysSetScrPaletteNo(bawk->id, bawk->px, bawk->py, bawk->sx, bawk->sy, bawk->pal2);
                GFL_BGSysQueueScrLoad(bawk->id);
                bawk->cnt = 0;
                bawk->seq++;
            }
        }
        break;
    case 2:
        bawk->cnt++;
        if (bawk->cnt == 2) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

void Box2Main_SetFrameButtonAnm(Box2SysWork *syswk, u32 frame) {
    s8 px, py;
    u16 sx, sy;

    func_020336a0(syswk->app->bgWinFrame, frame, &px, &py);
    func_020336c8(syswk->app->bgWinFrame, frame, &sx, &sy);
    syswk->app->bawk.mode = BOX2_BTN_ANM_MODE_BG;
    syswk->app->bawk.id = func_02033694(syswk->app->bgWinFrame, frame);
    syswk->app->bawk.pal1 = 13;
    syswk->app->bawk.pal2 = 12;
    syswk->app->bawk.seq = 0;
    syswk->app->bawk.cnt = 0;
    syswk->app->bawk.px = px;
    syswk->app->bawk.py = py;
    syswk->app->bawk.sx = sx;
    syswk->app->bawk.sy = sy;
}

void Box2Main_InitSettings(Box2SysWork *syswk) {
    syswk->unk20 = 0;
    syswk->unk1F = 0;
    syswk->unk21 = 1;
    if (syswk->param->mode == 2 || syswk->param->mode == 4) {
        syswk->unk22 = 0;
    } else {
        syswk->unk22 = 1;
    }
}

void func_ov255_021bc018(Box2SysWork *syswk) {
    func_ov255_021d1af8(syswk, syswk->unk1F, syswk->unk20, syswk->unk21, syswk->unk22);
    func_ov255_021d3a38(syswk->app->bgWinFrame);
}

void Box2Main_ScrollTray(Box2SysWork *syswk, BOOL right) {
    if (right == FALSE) {
        if (syswk->tray == 0) {
            syswk->tray = syswk->trayMax - 1;
        } else {
            syswk->tray = syswk->tray - 1;
        }
        func_ov255_021cf5e4(syswk->app, 0, 2);
    } else {
        if (syswk->tray == syswk->trayMax - 1) {
            syswk->tray = 0;
        } else {
            syswk->tray = syswk->tray + 1;
        }
        func_ov255_021cf5e4(syswk->app, 1, 4);
    }
    func_ov255_021cf9c8(syswk, syswk->tray);
    Box2Main_WallPaperSet(syswk, Box2Main_GetWallPaperNumber(syswk, syswk->tray), right);
}

void func_ov255_021bc09c(Box2SysWork *syswk, u32 a1) {
    syswk->trayScroll = Box2Main_GetTrayScroll(syswk, a1);
    func_ov255_021d198c(syswk, a1);
    func_ov255_021d1ac8(syswk, 0, 0);
}

void func_ov255_021bc0c0(Box2SysWork *syswk) {
    func_ov255_021d13c4(syswk);
    func_ov255_021d1474(syswk->app);
    func_ov255_021d1a1c(syswk);
    func_ov255_021ced8c(syswk, 0);
    func_ov255_021d3b10(syswk->app->bgWinFrame);
}

// Whether the way from one tray to another is shorter going right
BOOL Box2Main_IsTrayScrollRight(Box2SysWork *syswk, u32 from, u32 to) {
    u32 diff = MATH_ABS((s32)(from - to));

    if (from > to) {
        if (diff < syswk->trayMax / 2) {
            return FALSE;
        }
        return TRUE;
    }
    if (diff >= syswk->trayMax / 2) {
        return FALSE;
    }
    return TRUE;
}

void Box2Main_ShowCursor(Box2SysWork *syswk) {
    func_0203d564(FALSE);
    if (func_0202ba70(syswk->app->cursorMove) == FALSE) {
        func_0202ba74(syswk->app->cursorMove, TRUE);
    }
}

u32 Box2Main_GetPokeParam(Box2SysWork *syswk, u16 pos, u16 tray, u32 param, void *buf) {
    if (pos >= BOX2_PARTY_POS) {
        if (pos >= BOX2_PARTY_POS) {
            pos -= BOX2_PARTY_POS;
        }
        if (PokeParty_GetPkmCount(syswk->param->party) > pos) {
            return PokeParty_GetParam(PokeParty_GetPkm(syswk->param->party, pos), param, buf);
        }
    } else if (pos != BOX2_GET_NONE) {
        BoxPkm *pkm = BoxSaveAccessor_GetPkm(syswk->param->boxes, tray, pos);
        if (pkm != NULL) {
            return PML_PkmGetParam(pkm, param, buf);
        }
    }
    return 0;
}

void Box2Main_SetPokeParam(Box2SysWork *syswk, u32 pos, u32 tray, u32 param, u32 value) {
    BoxPkm *pkm = Box2Main_GetBoxPkm(syswk, tray, pos);

    if (pkm != NULL) {
        PML_PkmSetParam(pkm, param, value);
    }
}

BoxPkm *Box2Main_GetBoxPkm(Box2SysWork *syswk, u32 tray, u32 pos) {
    if (tray == BOX2_GET_NONE || pos >= BOX2_PARTY_POS) {
        if (pos >= BOX2_PARTY_POS) {
            pos -= BOX2_PARTY_POS;
        }
        if (PokeParty_GetPkmCount(syswk->param->party) > pos) {
            return func_0201d620(PokeParty_GetPkm(syswk->param->party, pos));
        }
    } else if (pos != BOX2_GET_NONE) {
        return BoxSaveAccessor_GetPkm(syswk->param->boxes, tray, pos);
    }
    return NULL;
}

void Box2Main_ClearPokeData(Box2SysWork *syswk, u32 tray, u32 pos) {
    if (pos < BOX2_PARTY_POS) {
        BoxSaveAccessor_ClearPkm(syswk->param->boxes, tray, pos);
    } else {
        PokeParty_RemovePkm(syswk->param->party, pos - BOX2_PARTY_POS);
    }
}

static void PokeDataSwapBoxParty(Box2SysWork *syswk, Box2PokeMoveData *box, Box2PokeMoveData *party) {
    u32 tray;
    PartyPkm *pkm;
    u16 index;

    if (box->iconPos == BOX2_BOXLIST_POS) {
        tray = syswk->getTray;
    } else {
        tray = syswk->tray;
    }
    pkm = boxPkmRegenToPartyPkm(Box2Main_GetBoxPkm(syswk, tray, box->dfPos), HEAPID_TAIL(HEAPID_BOX2_APP));
    index = party->dfPos - BOX2_PARTY_POS;
    BoxSaveAccessor_SetPkm(syswk->param->boxes, tray, box->dfPos,
                           func_0201d624(PokeParty_GetPkm(syswk->param->party, index)));
    copyPkmIntoPartyBlk(syswk->param->party, index, pkm);
    GFL_HeapFree(pkm);
    func_ov255_021d1570(syswk, tray);
}

static void PokeDataMoveBoxToParty(Box2SysWork *syswk, Box2PokeMoveData *box) {
    PartyPkm *pkm;
    int x, y;
    u32 pos;
    u32 base;

    if (syswk->app->rangeWidth == 1 && syswk->app->rangeHeight == 1) {
        pkm =
            boxPkmRegenToPartyPkm(Box2Main_GetBoxPkm(syswk, syswk->getTray, box->dfPos), HEAPID_TAIL(HEAPID_BOX2_APP));
        PokeParty_AddPkm(syswk->param->party, pkm);
        Box2Main_ClearPokeData(syswk, syswk->getTray, box->dfPos);
        GFL_HeapFree(pkm);
    } else {
        for (y = 0; y < syswk->app->rangeHeight; y++) {
            for (x = 0; x < syswk->app->rangeWidth; x++) {
                if (syswk->app->rangeFlags[y * 6 + x] == 1) {
                    base = box->dfPos - (x + y * 6);
                    break;
                }
            }
            if (x != syswk->app->rangeWidth) {
                break;
            }
        }
        for (y = 0; y < syswk->app->rangeHeight; y++) {
            for (x = 0; x < syswk->app->rangeWidth; x++) {
                pos = x + y * 6;
                if (syswk->app->rangeFlags[pos] != 0) {
                    pkm = boxPkmRegenToPartyPkm(Box2Main_GetBoxPkm(syswk, syswk->getTray, base + pos),
                                                HEAPID_TAIL(HEAPID_BOX2_APP));
                    PokeParty_AddPkm(syswk->param->party, pkm);
                    Box2Main_ClearPokeData(syswk, syswk->getTray, base + pos);
                    GFL_HeapFree(pkm);
                }
            }
        }
    }
    func_ov255_021d1570(syswk, syswk->getTray);
}

static void PokeDataMovePartyToBox(Box2SysWork *syswk, Box2PokeMoveData *party) {
    u16 count;
    u8 moved;
    u16 x, y;
    u16 index;
    u16 i;

    count = PokeParty_GetPkmCount(syswk->param->party);
    moved = 0;
    for (y = 0; y < syswk->app->rangeHeight; y++) {
        for (x = 0; x < syswk->app->rangeWidth; x++) {
            index = x + (party->dfPos - BOX2_PARTY_POS + y * 2);
            if (index < count) {
                BoxSaveAccessor_SetPkm(syswk->param->boxes, syswk->tray, x + (party->mvPos + y * 6),
                                       func_0201d624(PokeParty_GetPkm(syswk->param->party, index)));
                moved |= 1 << index;
            }
        }
    }
    for (i = 0; i < 6; i++) {
        index = 5 - i;
        if (moved & (1 << index)) {
            Box2Main_ClearPokeData(syswk, syswk->tray, index + BOX2_PARTY_POS);
        }
    }
    func_ov255_021d1570(syswk, syswk->tray);
}

static void PokeDataSwapParty(Box2SysWork *syswk, Box2PokeMoveData *party) {
    PokeParty_SwapPkms(syswk->param->party, party->dfPos - BOX2_PARTY_POS, party->mvPos - BOX2_PARTY_POS,
                       HEAPID_BOX2_APP);
}

static void PokeDataMoveParty(Box2SysWork *syswk, Box2PokeMoveData *party) {
    u32 index;

    for (index = party->dfPos - BOX2_PARTY_POS; index < PokeParty_GetPkmCount(syswk->param->party) - 1; index++) {
        PokeParty_SwapPkms(syswk->param->party, index, index + 1, HEAPID_BOX2_APP);
    }
}

static void PokeDataSortParty(Box2SysWork *syswk, Box2PokeMoveWork *work) {
    u32 order[6];
    u32 i;

    for (i = 0; i < 6; i++) {
        order[i] = 0xff;
    }
    for (i = 0; i < 12; i++) {
        Box2PokeMoveData *data = &work->data[i];
        if (data->dfPos >= BOX2_PARTY_POS && data->dfPos < BOX2_BOXLIST_POS) {
            order[data->mvPos - BOX2_PARTY_POS] = data->dfPos - BOX2_PARTY_POS;
        }
    }
    for (i = 0; i < 6; i++) {
        if (order[i] == 0xff) {
            order[i] = i;
        }
    }
    func_0201fff8(syswk->param->party, order, HEAPID_TAIL(HEAPID_BOX2_APP));
}

static u32 PokeDataMoveToTray(Box2SysWork *syswk, u32 tray, u32 pos, u32 dstTray) {
    BoxPkm *pkm = Box2Main_GetBoxPkm(syswk, tray, pos);
    u32 box = Box2Main_GetScrolledTray(syswk, dstTray);

    BoxSaveAccessor_InsertPkmCore(syswk->param->boxes, box, pkm);
    BoxSaveAccessor_ClearPkm(syswk->param->boxes, tray, pos);
    return box;
}

static void PokeDataRangeMoveToTray(Box2SysWork *syswk, u32 tray, u32 pos, u32 dstTray) {
    u32 box = 0xffffffff;
    int x, y;
    u32 index;

    if (syswk->app->rangeWidth == 1 && syswk->app->rangeHeight == 1) {
        box = PokeDataMoveToTray(syswk, tray, pos, dstTray);
    } else {
        for (y = 0; y < syswk->app->rangeHeight; y++) {
            for (x = 0; x < syswk->app->rangeWidth; x++) {
                index = x + y * 6;
                if (syswk->app->rangeFlags[index] == 1) {
                    box = PokeDataMoveToTray(syswk, tray, pos + index, dstTray);
                }
            }
        }
    }
    func_ov255_021d1570(syswk, tray);
    func_ov255_021d15f4(syswk, tray);
    func_ov255_021d1570(syswk, box);
    func_ov255_021d15f4(syswk, box);
}

static void PokeDataPartyMoveToTray(Box2SysWork *syswk, u32 pos, u32 dstTray) {
    u32 box;
    u32 count;
    u8 start;
    u8 moved[6];
    u16 i, j;
    u16 x, y;
    PartyPkm *pkm;

    box = Box2Main_GetScrolledTray(syswk, dstTray);
    count = PokeParty_GetPkmCount(syswk->param->party);
    start = pos - BOX2_PARTY_POS;
    for (i = 0; i < 6; i++) {
        moved[i] = 0;
    }
    for (y = 0; y < syswk->app->rangeHeight; y++) {
        for (x = 0; x < syswk->app->rangeWidth; x++) {
            if (x + (start + y * 2) < count) {
                moved[start + y * 2 + x] = 1;
            }
        }
    }

    for (i = 0; i < count; i++) {
        if (moved[i]) {
            pkm = PokeParty_GetPkm(syswk->param->party, i);
            // Shaymin goes back to its Land Forme in the box
            if (PokeParty_GetParam(pkm, PKM_PARAM_SPECIES, NULL) == SPECIES_SHAYMIN) {
                PokeParty_ChangeForme(pkm, 0);
                Box2Main_RecalcPartyStats(syswk, i + BOX2_PARTY_POS);
                PokeDex_RegistPkm(GameData_GetPokedex(syswk->param->gameData), pkm);
            }
            BoxSaveAccessor_InsertPkmCore(syswk->param->boxes, box, func_0201d624(pkm));
        }
    }

    // Remove the moved Pokémon from the party, from the first, as the party closes up behind each
    while (TRUE) {
        for (i = 0; i < 6; i++) {
            if (moved[i] == 1) {
                break;
            }
        }
        if (i == 6) {
            break;
        }
        Box2Main_ClearPokeData(syswk, syswk->tray, i + BOX2_PARTY_POS);
        moved[i] = 0;
        for (j = i + 1; j < 6; j++) {
            if (moved[j] == 1) {
                moved[j - 1] = 1;
                moved[j] = 0;
            }
        }
    }
    func_ov255_021d1570(syswk, box);
    func_ov255_021d15f4(syswk, box);
}

void Box2Main_PokeDataMove(Box2SysWork *syswk) {
    Box2PokeMoveWork *work = syswk->app->vfunk.work;
    u16 count;
    u32 getPos, putPos;
    u16 x, y;

    if (work->getPos != BOX2_GET_NONE) {
        count = PokeParty_GetPkmCount(syswk->param->party);
        putPos = work->putPos;
        getPos = work->getPos;

        if (putPos >= BOX2_BOXLIST_POS) {
            if (getPos < BOX2_PARTY_POS) {
                PokeDataRangeMoveToTray(syswk, syswk->getTray, getPos, putPos - BOX2_BOXLIST_POS);
            } else {
                PokeDataPartyMoveToTray(syswk, getPos, putPos - BOX2_BOXLIST_POS);
            }
            return;
        }

        if (getPos < BOX2_PARTY_POS) {
            if (putPos < BOX2_PARTY_POS) {
                if (syswk->moveMode != 2) {
                    BoxSaveAccessor_SwapPkms(syswk->param->boxes, syswk->getTray, getPos, syswk->tray, putPos);
                } else {
                    func_ov255_021c265c(syswk, getPos, putPos);
                }
                func_ov255_021d1570(syswk, syswk->tray);
                func_ov255_021d15f4(syswk, syswk->tray);
                if (syswk->tray == syswk->getTray) {
                    return;
                }
                func_ov255_021d1570(syswk, syswk->getTray);
                func_ov255_021d15f4(syswk, syswk->getTray);
                return;
            }
            if (putPos - BOX2_PARTY_POS < count) {
                PokeDataSwapBoxParty(syswk, &work->data[0], &work->data[1]);
                PokeFormChangeShaymin(syswk, work->putPos, work->getPos, syswk->getTray);
            } else {
                PokeDataMoveBoxToParty(syswk, &work->data[0]);
            }
            return;
        }

        if (putPos < BOX2_PARTY_POS) {
            if (Box2Main_GetPokeParam(syswk, putPos, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) != 0) {
                PokeDataSwapBoxParty(syswk, &work->data[1], &work->data[0]);
                PokeFormChangeShaymin(syswk, work->putPos, work->getPos, syswk->tray);
                return;
            }
            if (syswk->moveMode != 2) {
                PokeDataMovePartyToBox(syswk, &work->data[work->getPos - BOX2_PARTY_POS]);
                PokeFormChangeShaymin(syswk, work->putPos, work->getPos, syswk->tray);
                return;
            }
            PokeDataMovePartyToBox(syswk, &work->data[0]);
            for (y = 0; y < syswk->app->rangeHeight; y++) {
                for (x = 0; x < syswk->app->rangeWidth; x++) {
                    if (syswk->app->rangeFlags[y * 2 + x]) {
                        PokeFormChangeShaymin(syswk, x + (work->putPos + y * 6), work->getPos, syswk->tray);
                    }
                }
            }
            return;
        }

        if (putPos - BOX2_PARTY_POS < count) {
            PokeDataSwapParty(syswk, &work->data[0]);
            return;
        }
        if (syswk->moveMode != 2) {
            PokeDataMoveParty(syswk, &work->data[getPos - BOX2_PARTY_POS]);
        } else {
            PokeDataSortParty(syswk, work);
        }
    }
}

u32 Box2Main_GetScrolledTray(Box2SysWork *syswk, u32 tray) {
    tray += syswk->trayScroll;
    if (tray >= syswk->trayMax) {
        tray -= syswk->trayMax;
    }
    return tray;
}

// Whether the party keeps a Pokémon that can battle besides the one at pos, or those of the range picked from pos
BOOL Box2Main_BattlePokeCheck(Box2SysWork *syswk, u32 pos) {
    u32 i;
    PartyPkm *pkm;

    if (syswk->moveMode == 2) {
        int x = pos & 1;
        int y = pos >> 1;

        for (i = 0; i < PokeParty_GetPkmCount(syswk->param->party); i++) {
            int col = i & 1;
            int row = i >> 1;

            if (col < x || col >= x + syswk->app->rangeWidth || row < y || row >= y + syswk->app->rangeHeight) {
                pkm = PokeParty_GetPkm(syswk->param->party, i);
                if (PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == 0 &&
                    PokeParty_GetParam(pkm, PKM_PARAM_HP, NULL) != 0) {
                    return TRUE;
                }
            }
        }
    } else {
        for (i = 0; i < PokeParty_GetPkmCount(syswk->param->party); i++) {
            if (i != pos) {
                pkm = PokeParty_GetPkm(syswk->param->party, i);
                if (PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == 0 &&
                    PokeParty_GetParam(pkm, PKM_PARAM_HP, NULL) != 0) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

// Changes a Pokémon's forme, and records the new forme as seen
static void PokeChangeForme(Box2SysWork *syswk, BoxPkm *pkm, u32 forme) {
    PartyPkm *partyPkm;

    PML_PkmChangeForme(pkm, forme);
    partyPkm = boxPkmRegenToPartyPkm(pkm, HEAPID_BOX2_APP);
    PokeDex_RegistPkm(GameData_GetPokedex(syswk->param->gameData), partyPkm);
    GFL_HeapFree(partyPkm);
}

// Changes the forme of Arceus, Genesect and Giratina to the one their item gives, and returns whether it changed
BOOL Box2Main_PokeItemFormChange(Box2SysWork *syswk, BoxPkm *pkm) {
    u16 species = PML_PkmGetParam(pkm, PKM_PARAM_SPECIES, NULL);
    u16 item;
    u16 form;
    u16 newForm;

    if (species == SPECIES_ARCEUS) {
        item = PML_PkmGetParam(pkm, PKM_PARAM_ITEM, NULL);
        form = PML_PkmGetParam(pkm, PKM_PARAM_FORM, NULL);
        newForm = _getTypeForPlate(item);
        if (form != newForm) {
            PokeChangeForme(syswk, pkm, newForm);
        }
        if (form != newForm) {
            return TRUE;
        }
    } else if (species == SPECIES_GENESECT) {
        item = PML_PkmGetParam(pkm, PKM_PARAM_ITEM, NULL);
        form = PML_PkmGetParam(pkm, PKM_PARAM_FORM, NULL);
        newForm = func_0201ef8c(item);
        if (form != newForm) {
            PokeChangeForme(syswk, pkm, newForm);
        }
        if (form != newForm) {
            return TRUE;
        }
    } else if (species == SPECIES_GIRATINA) {
        item = PML_PkmGetParam(pkm, PKM_PARAM_ITEM, NULL);
        form = PML_PkmGetParam(pkm, PKM_PARAM_FORM, NULL);
        newForm = form;
        if (form == 0) {
            if (item == ITEM_GRISEOUS_ORB) {
                PokeChangeForme(syswk, pkm, 1);
                newForm = 1;
            }
        } else if (item != ITEM_GRISEOUS_ORB) {
            PokeChangeForme(syswk, pkm, 0);
            newForm = 0;
        }
        if (form != newForm) {
            return TRUE;
        }
    }
    return FALSE;
}

// Shaymin changes back to its Land Forme when it moves between the party and a box
static void PokeFormChangeShaymin(Box2SysWork *syswk, u32 putPos, u32 getPos, u32 tray) {
    if (putPos < BOX2_PARTY_POS && getPos < BOX2_PARTY_POS) {
        return;
    }
    if (putPos >= BOX2_PARTY_POS && getPos >= BOX2_PARTY_POS) {
        return;
    }
    if (putPos >= BOX2_PARTY_POS) {
        putPos = getPos;
    }
    if (Box2Main_GetPokeParam(syswk, putPos, tray, PKM_PARAM_SPECIES, NULL) == SPECIES_SHAYMIN &&
        Box2Main_GetPokeParam(syswk, putPos, tray, PKM_PARAM_FORM, NULL) != 0) {
        PokeChangeForme(syswk, Box2Main_GetBoxPkm(syswk, tray, putPos), 0);
        Box2Main_RecalcPartyStats(syswk, putPos);
        if (tray == syswk->tray) {
            func_ov255_021cfc20(syswk, tray, putPos, syswk->app->pokeIconId[putPos]);
        }
        if (syswk->pos == putPos) {
            Box2Main_PokeInfoPut(syswk, putPos);
        }
    }
}

void Box2Main_RecalcPartyStats(Box2SysWork *syswk, u32 pos) {
    PartyPkm *pkm;
    BOOL encrypted;

    if (pos >= BOX2_PARTY_POS) {
        pkm = PokeParty_GetPkm(syswk->param->party, pos - BOX2_PARTY_POS);
        encrypted = PokeParty_DecryptPkm(pkm);
        PokeParty_RecalcStats(pkm);
        PokeParty_EncryptPkm(pkm, encrypted);
    }
}

void Box2Main_InitDexData(Box2SysWork *syswk) {
    syswk->app->regionalDex = PML_PersonalLoadRegionalDexTable(HEAPID_BOX2_APP, 0);
    syswk->app->nationalDex = PokeDex_IsNationalObtained(GameData_GetPokedex(syswk->param->gameData));
}

void Box2Main_ExitDexData(Box2SysWork *syswk) {
    GFL_HeapFree(syswk->app->regionalDex);
}

BOOL Box2Main_IsSpeciesFlagged(Box2SysWork *syswk, u32 pos) {
    u16 species = Box2Main_GetPokeParam(syswk, pos, syswk->tray, PKM_PARAM_SPECIES, NULL);

    return func_020099b4(syswk->param->unk20, species);
}

// Puts an icon of a range where it is after cnt steps of its move
static void PokeIconRangeMove(Box2SysWork *syswk, Box2PokeMoveData *data, u32 cnt, u32 x, u32 y, u32 width) {
    s16 px = x * 24 + (data->dx + ((data->mx * cnt) >> 16) * data->vx);
    s16 py = y * 24 + (data->dy + ((data->my * cnt) >> 16) * data->vy);

    func_ov255_021cf6c8(syswk->app, syswk->app->pokeIconId[x + (data->iconPos + y * width)], px, py, 0);
    func_ov255_021cff58(syswk->app, x + (data->iconPos + y * width), 0);
    if (x + (data->iconPos + y * width) == BOX2_BOXLIST_POS) {
        func_ov255_021d22fc(syswk->app, px, py + 8);
    }
}

// Puts a moved icon at its new position, and returns its actor
static inline u8 PokeIconMoveEnd(Box2SysWork *syswk, u32 iconPos, u32 pos) {
    s16 x, y;
    u8 id;

    func_ov255_021cffa8(syswk->app, iconPos, pos, TRUE);
    id = syswk->app->pokeIconId[iconPos];
    if (pos < BOX2_PARTY_POS) {
        func_ov255_021cfcdc(pos, &x, &y, syswk->unk1A);
    } else if (pos < BOX2_BOXLIST_POS) {
        func_ov255_021cfcdc(pos, &x, &y, syswk->unk1A);
        if (syswk->unk1A == 2 && func_ov255_021d387c(syswk->app->bgWinFrame) == FALSE) {
            y += 192;
        }
    } else {
        if (iconPos >= BOX2_PARTY_POS) {
            func_ov255_021cfcdc(65, &x, &y, syswk->unk1A);
            if (syswk->unk1A == 2 && func_ov255_021d387c(syswk->app->bgWinFrame) == FALSE) {
                y += 192;
            }
        } else {
            func_ov255_021cfcdc(iconPos, &x, &y, syswk->unk1A);
        }
        func_ov255_021cf63c(syswk->app, id, FALSE);
    }
    func_ov255_021cf6c8(syswk->app, id, x, y, 0);
    return id;
}

static BOOL Box2Main_VFuncRangePokeMove(Box2SysWork *syswk) {
    Box2PokeMoveWork *work = syswk->app->vfunk.work;
    u16 i;
    u16 x, y;
    u16 width;
    u16 posWidth;
    u8 id;

    if (work->cnt < 8) {
        work->cnt++;
        if (work->mode == 1) {
            for (i = 0; i < 12; i++) {
                if (work->data[i].flag != 0) {
                    PokeIconRangeMove(syswk, &work->data[i], work->cnt, 0, 0, syswk->app->rangeWidth);
                }
            }
        } else {
            for (y = 0; y < syswk->app->rangeHeight; y++) {
                for (x = 0; x < syswk->app->rangeWidth; x++) {
                    PokeIconRangeMove(syswk, &work->data[0], work->cnt, x, y, syswk->app->rangeWidth);
                }
            }
        }
        return TRUE;
    }
    if (work->cnt != 8) {
        return TRUE;
    }

    if (work->mode == 1) {
        for (i = 0; i < 12; i++) {
            Box2PokeMoveData *data = &work->data[i];
            if (data->flag != 0) {
                id = PokeIconMoveEnd(syswk, data->iconPos, data->mvPos);
                if (data->flag == 2) {
                    func_ov255_021cf63c(syswk->app, id, FALSE);
                }
            }
        }
    } else {
        width = syswk->app->rangeWidth;
        posWidth = func_ov255_021c27f8(syswk, work->data[0].mvPos);
        for (y = 0; y < syswk->app->rangeHeight; y++) {
            for (x = 0; x < syswk->app->rangeWidth; x++) {
                u16 iconPos = work->data[0].iconPos + width * y + x;
                u16 pos = work->data[0].mvPos + posWidth * y + x;
                PokeIconMoveEnd(syswk, iconPos, pos);
            }
        }
    }
    func_ov255_021d22e0(syswk->app, 0);
    return FALSE;
}

static BOOL Box2Main_VFuncGetPokeMove(Box2SysWork *syswk) {
    Box2PokeMoveWork *work = syswk->app->vfunk.work;
    u32 i;
    int x, y;
    u8 id;

    if (syswk->moveMode == 2) {
        return Box2Main_VFuncRangePokeMove(syswk);
    }
    if (work->cnt < 8) {
        work->cnt++;
        for (i = 0; i < 12; i++) {
            Box2PokeMoveData *data = &work->data[i];
            if (data->flag != 0) {
                for (y = 0; y < syswk->app->rangeHeight; y++) {
                    for (x = 0; x < syswk->app->rangeWidth; x++) {
                        PokeIconRangeMove(syswk, data, work->cnt, x, y, syswk->app->rangeWidth);
                    }
                }
            }
        }
        func_ov255_021d121c(syswk, syswk->pos);
        func_ov255_021d1284(syswk->app, BOX2_BOXLIST_POS);
        return TRUE;
    }
    if (work->cnt != 8) {
        return TRUE;
    }
    for (i = 0; i < 12; i++) {
        Box2PokeMoveData *data = &work->data[i];
        if (data->flag != 0) {
            id = PokeIconMoveEnd(syswk, data->iconPos, data->mvPos);
            if (data->flag == 2) {
                func_ov255_021cf63c(syswk->app, id, FALSE);
            }
        }
    }
    func_ov255_021d121c(syswk, syswk->pos);
    func_ov255_021d1284(syswk->app, BOX2_BOXLIST_POS);
    return FALSE;
}

static BOOL Box2Main_VFuncPokeMoveParty(Box2SysWork *syswk) {
    Box2PokeMoveWork *work = syswk->app->vfunk.work;
    Box2PokeMoveData *data;
    u32 i;
    s16 x, y;
    u8 id;

    if (work->cnt == 8) {
        for (i = 0; i < 12; i++) {
            data = &work->data[i];
            if (data->flag != 0) {
                id = syswk->app->pokeIconId[data->iconPos];
                func_ov255_021cfcdc(data->mvPos, &x, &y, syswk->unk1A);
                if (data->mvPos >= BOX2_PARTY_POS) {
                    y += 144;
                }
                func_ov255_021cf6c8(syswk->app, id, x, y, 0);
            }
        }
        func_ov255_021d1284(syswk->app, BOX2_BOXLIST_POS);
        return FALSE;
    }
    work->cnt++;
    for (i = 0; i < 12; i++) {
        data = &work->data[i];
        if (data->flag != 0) {
            id = syswk->app->pokeIconId[data->iconPos];
            x = data->dx + ((data->mx * work->cnt) >> 16) * data->vx;
            y = data->dy + ((data->my * work->cnt) >> 16) * data->vy;
            func_ov255_021cf6c8(syswk->app, id, x, y, 0);
            func_ov255_021cff58(syswk->app, data->iconPos, 0);
            break;
        }
    }
    func_ov255_021d121c(syswk, syswk->pos);
    func_ov255_021d1284(syswk->app, BOX2_BOXLIST_POS);
    return TRUE;
}

// Whether no Pokémon at pos, or in the range picked from it, is an egg
static BOOL Box2Main_IsEggFree(Box2SysWork *syswk, u32 pos, u32 tray) {
    u16 x, y;

    if (func_ov255_021c23e4(syswk->app) == FALSE) {
        if (Box2Main_GetPokeParam(syswk, pos, tray, PKM_PARAM_IS_EGG, NULL) != 0) {
            return FALSE;
        }
    } else {
        for (y = 0; y < syswk->app->rangeHeight; y++) {
            for (x = 0; x < syswk->app->rangeWidth; x++) {
                if (syswk->app->rangeFlags[y * 6 + x] != 0 &&
                    Box2Main_GetPokeParam(syswk, x + (pos + y * 6), tray, PKM_PARAM_IS_EGG, NULL) != 0) {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}

// Whether the held Pokémon can be put at putPos, with the reason it can't in moveErr
static BOOL Box2Main_PokeMoveCheck(Box2SysWork *syswk, u32 getPos, u32 putPos) {
    u32 box;
    u32 count;
    u32 exists;

    if (putPos >= BOX2_BOXLIST_POS) {
        box = Box2Main_GetScrolledTray(syswk, putPos - BOX2_BOXLIST_POS);
        if (syswk->moveMode == 2) {
            count = howManyPokesInGeneralAreInBox(syswk->param->boxes, box) + func_ov255_021c23e4(syswk->app);
        } else {
            count = howManyPokesInGeneralAreInBox(syswk->param->boxes, box) + 1;
        }
        if (box == syswk->tray || count > BOX2_TRAY_POKE_MAX) {
            syswk->app->moveErr = BOX2_MOVE_ERR_BOX_FULL;
            return FALSE;
        }
        if (getPos >= BOX2_PARTY_POS) {
            if (Box2Main_BattlePokeCheck(syswk, getPos - BOX2_PARTY_POS) == FALSE) {
                syswk->app->moveErr = BOX2_MOVE_ERR_LAST_BATTLER;
                return FALSE;
            }
            if (func_ov255_021c276c(syswk, getPos - BOX2_PARTY_POS) == TRUE) {
                syswk->app->moveErr = BOX2_MOVE_ERR_MAIL;
                return FALSE;
            }
        }
        exists = 0;
    } else {
        exists = Box2Main_GetPokeParam(syswk, putPos, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL);
    }

    if (syswk->param->mode == 4) {
        if (syswk->param->unk14 == 1) {
            syswk->app->moveErr = 5;
            return FALSE;
        }
        if (getPos < BOX2_PARTY_POS && putPos >= BOX2_PARTY_POS && putPos < BOX2_BOXLIST_POS &&
            Box2Main_IsEggFree(syswk, getPos, syswk->getTray) == FALSE) {
            syswk->app->moveErr = 4;
            return FALSE;
        }
        if (getPos >= BOX2_PARTY_POS && getPos < BOX2_BOXLIST_POS && putPos < BOX2_PARTY_POS && exists != 0 &&
            Box2Main_IsEggFree(syswk, putPos, syswk->tray) == FALSE) {
            syswk->app->moveErr = 4;
            return FALSE;
        }
    }

    if (getPos >= BOX2_PARTY_POS) {
        if (Box2Main_BattlePokeCheck(syswk, getPos - BOX2_PARTY_POS) == FALSE) {
            if (exists == 0) {
                if ((putPos < BOX2_PARTY_POS || putPos >= BOX2_BOXLIST_POS) && syswk->param->mode != 4) {
                    syswk->app->moveErr = BOX2_MOVE_ERR_LAST_BATTLER;
                    return FALSE;
                }
            } else if (Box2Main_GetPokeParam(syswk, putPos, syswk->tray, PKM_PARAM_IS_EGG, NULL) != 0 &&
                       putPos < BOX2_PARTY_POS && syswk->param->mode != 4) {
                syswk->app->moveErr = BOX2_MOVE_ERR_LAST_BATTLER;
                return FALSE;
            }
        }
        if (putPos < BOX2_PARTY_POS && func_ov255_021c276c(syswk, getPos - BOX2_PARTY_POS) == TRUE) {
            syswk->app->moveErr = BOX2_MOVE_ERR_MAIL;
            return FALSE;
        }
    } else if (putPos >= BOX2_PARTY_POS && exists != 0) {
        if (syswk->moveMode == 2) {
            syswk->app->moveErr = 7;
            return FALSE;
        }
        if (PML_ItemIsMail(PokeParty_GetParam(PokeParty_GetPkm(syswk->param->party, putPos - BOX2_PARTY_POS),
                                              PKM_PARAM_ITEM, NULL)) == TRUE) {
            syswk->app->moveErr = BOX2_MOVE_ERR_MAIL;
            return FALSE;
        }
        if (Box2Main_GetPokeParam(syswk, getPos, syswk->getTray, PKM_PARAM_IS_EGG, NULL) != 0 &&
            Box2Main_BattlePokeCheck(syswk, putPos - BOX2_PARTY_POS) == FALSE && syswk->param->mode != 4) {
            syswk->app->moveErr = BOX2_MOVE_ERR_LAST_BATTLER;
            return FALSE;
        }
    }

    if (syswk->moveMode == 2 && putPos < BOX2_BOXLIST_POS) {
        if (func_ov255_021c2408(syswk, syswk->tray, putPos) == FALSE) {
            syswk->app->moveErr = 7;
            return FALSE;
        }
        if (putPos >= BOX2_PARTY_POS && exists == TRUE) {
            syswk->app->moveErr = 7;
            return FALSE;
        }
    }
    syswk->app->moveErr = BOX2_MOVE_ERR_NONE;
    return TRUE;
}

// Whether the party Pokémon at pos can go to the current box
static BOOL Box2Main_PartyOutCheck(Box2SysWork *syswk, u32 pos, u32 putPos) {
    if (countEmptySlotsInBox(syswk->param->boxes, syswk->tray) == 0) {
        return FALSE;
    }
    if (Box2Main_BattlePokeCheck(syswk, pos - BOX2_PARTY_POS) == FALSE) {
        return FALSE;
    }
    return PML_ItemIsMail(PokeParty_GetParam(PokeParty_GetPkm(syswk->param->party, pos - BOX2_PARTY_POS),
                                             PKM_PARAM_ITEM, NULL)) == TRUE
               ? FALSE
               : TRUE;
}

// Whether the items of the Pokémon at getPos and putPos can be swapped
BOOL Box2Main_PokeItemMoveCheck(Box2SysWork *syswk, u32 getPos, u32 putPos) {
    if (Box2Main_GetPokeParam(syswk, putPos, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) == 0) {
        return FALSE;
    }
    if (Box2Main_GetPokeParam(syswk, putPos, syswk->tray, PKM_PARAM_IS_EGG, NULL) != 0) {
        return FALSE;
    }
    if (PML_ItemIsMail(Box2Main_GetPokeParam(syswk, getPos, syswk->tray, PKM_PARAM_ITEM, NULL)) == TRUE) {
        return FALSE;
    }
    return PML_ItemIsMail(Box2Main_GetPokeParam(syswk, putPos, syswk->tray, PKM_PARAM_ITEM, NULL)) == TRUE ? FALSE
                                                                                                           : TRUE;
}

// Sets the steps that move an icon from where it is to (x, y) in BOX2_POKEMOVE_CNT frames
static inline void PokeIconMoveVector(Box2PokeMoveData *data, s16 *x, s16 *y) {
    int diff;

    if (data->dx <= *x) {
        data->vx = 1;
        diff = *x - data->dx;
    } else {
        data->vx = -1;
        diff = data->dx - *x;
    }
    data->mx = (diff << 16) / BOX2_POKEMOVE_CNT;
    if (data->dy <= *y) {
        data->vy = 1;
        diff = *y - data->dy;
    } else {
        data->vy = -1;
        diff = data->dy - *y;
    }
    data->my = (diff << 16) / BOX2_POKEMOVE_CNT;
}

static void PokeIconMoveParamMake(Box2SysWork *syswk, Box2PokeMoveData *data) {
    s16 x, y;

    func_ov255_021cf6ec(syswk->app, syswk->app->pokeIconId[data->iconPos], &data->dx, &data->dy, 0);
    if (data->flag != 2) {
        if (data->mvPos < BOX2_BOXLIST_POS) {
            func_ov255_021cfcdc(data->mvPos, &x, &y, syswk->unk1A);
        } else {
            func_ov255_021d1530(syswk->app, data->mvPos - BOX2_BOXLIST_POS, &x, &y);
        }
    } else if (syswk->tray > syswk->getTray) {
        func_ov255_021cf6ec(syswk->app, 0, &x, &y, 0);
    } else {
        func_ov255_021cf6ec(syswk->app, 1, &x, &y, 0);
    }
    PokeIconMoveVector(data, &x, &y);
}

static void PokeIconChgParamMake(Box2SysWork *syswk, Box2PokeMoveData *data) {
    u8 id = syswk->app->pokeIconId[data->mvPos];
    s16 x, y;

    func_ov255_021cf6ec(syswk->app, syswk->app->pokeIconId[data->iconPos], &data->dx, &data->dy, 0);
    func_ov255_021cf6ec(syswk->app, id, &x, &y, 0);
    PokeIconMoveVector(data, &x, &y);
}

static void PokeIconMoveSubParamMake(Box2SysWork *syswk, Box2PokeMoveData *data) {
    s16 x, y;

    func_ov255_021cf6ec(syswk->app, syswk->app->pokeIconId[data->iconPos], &data->dx, &data->dy, 0);
    func_ov255_021cfcdc(data->mvPos, &x, &y, syswk->unk1A);
    y += 192;
    PokeIconMoveVector(data, &x, &y);
}

// Swaps two icons
static void PokeIconChgDataMake(Box2SysWork *syswk, u32 getPos, u32 putPos) {
    Box2PokeMoveWork *work = syswk->app->vfunk.work;

    work->data[0].iconPos = BOX2_BOXLIST_POS;
    work->data[0].mvPos = putPos;
    work->data[0].dfPos = getPos;
    work->data[0].flag = 1;
    PokeIconMoveParamMake(syswk, &work->data[0]);
    work->data[1].iconPos = work->data[1].dfPos = putPos;
    work->data[1].mvPos = getPos;
    work->data[1].flag = 1;
    PokeIconMoveParamMake(syswk, &work->data[1]);
}

// Sets up the moves of the icons when the held Pokémon is dropped at putPos, and returns whether the drop moves it
static BOOL PokeIconMoveDataMake(Box2SysWork *syswk, u32 getPos, u32 putPos) {
    Box2PokeMoveWork *work = syswk->app->vfunk.work;
    u32 count;
    u16 x, y;
    u16 i, j;
    u8 n;
    u8 mask;
    u16 start;

    work->mode = 0;
    sys_memset(work->data, 0, sizeof(work->data));
    work->setPos = putPos;

    if (putPos == BOX2_GET_NONE) {
        work->getPos = BOX2_GET_NONE;
        work->putPos = BOX2_GET_NONE;
        if (syswk->moveMode == 2 && getPos >= BOX2_PARTY_POS) {
            work->mode = 1;
            for (y = 0; y < syswk->app->rangeHeight; y++) {
                for (x = 0; x < syswk->app->rangeWidth; x++) {
                    work->data[x + y * syswk->app->rangeWidth].iconPos =
                        x + (y * syswk->app->rangeWidth + BOX2_BOXLIST_POS);
                    work->data[x + y * syswk->app->rangeWidth].mvPos =
                        work->data[x + y * syswk->app->rangeWidth].dfPos = x + (getPos + y * 2);
                    work->data[x + y * syswk->app->rangeWidth].flag = 1;
                    PokeIconMoveParamMake(syswk, &work->data[x + y * syswk->app->rangeWidth]);
                }
            }
        } else {
            work->data[0].iconPos = BOX2_BOXLIST_POS;
            work->data[0].mvPos = work->data[0].dfPos = getPos;
            work->data[0].flag = 1;
            if (syswk->tray == syswk->getTray) {
                work->data[1].iconPos = work->data[1].mvPos = work->data[1].dfPos = getPos;
                work->data[1].flag = 1;
            }
            PokeIconMoveParamMake(syswk, &work->data[0]);
        }
        return FALSE;
    }

    if ((getPos == putPos && (getPos >= BOX2_PARTY_POS || syswk->tray == syswk->getTray)) ||
        Box2Main_PokeMoveCheck(syswk, getPos, putPos) == FALSE) {
        work->getPos = BOX2_GET_NONE;
        work->putPos = BOX2_GET_NONE;
        if (syswk->moveMode == 2 && getPos >= BOX2_PARTY_POS) {
            work->mode = 1;
            for (y = 0; y < syswk->app->rangeHeight; y++) {
                for (x = 0; x < syswk->app->rangeWidth; x++) {
                    work->data[x + y * syswk->app->rangeWidth].iconPos =
                        x + (y * syswk->app->rangeWidth + BOX2_BOXLIST_POS);
                    work->data[x + y * syswk->app->rangeWidth].mvPos =
                        work->data[x + y * syswk->app->rangeWidth].dfPos = x + (getPos + y * 2);
                    work->data[x + y * syswk->app->rangeWidth].flag = 1;
                    PokeIconMoveParamMake(syswk, &work->data[x + y * syswk->app->rangeWidth]);
                }
            }
        } else {
            work->data[0].iconPos = BOX2_BOXLIST_POS;
            work->data[0].mvPos = work->data[0].dfPos = getPos;
            work->data[0].flag = 1;
            work->data[1].iconPos = work->data[1].mvPos = work->data[1].dfPos = getPos;
            work->data[1].flag = 1;
            PokeIconMoveParamMake(syswk, &work->data[0]);
        }
        return FALSE;
    }

    work->getPos = getPos;
    work->putPos = putPos;
    count = PokeParty_GetPkmCount(syswk->param->party);

    // To a box of the box list
    if (putPos >= BOX2_BOXLIST_POS) {
        if (syswk->moveMode == 2) {
            if (getPos >= BOX2_PARTY_POS) {
                work->mode = 1;
                start = getPos - BOX2_PARTY_POS;
                n = 0;
                for (y = 0; y < syswk->app->rangeHeight; y++) {
                    for (x = 0; x < syswk->app->rangeWidth; x++) {
                        if (x + (start + y * 2) < count) {
                            work->data[n].iconPos = x + (y * syswk->app->rangeWidth + BOX2_BOXLIST_POS);
                            work->data[n].mvPos = putPos;
                            work->data[n].dfPos = x + (getPos + y * 2);
                            work->data[n].flag = 1;
                            PokeIconMoveParamMake(syswk, &work->data[n]);
                            n++;
                        }
                    }
                }
                // The Pokémon after the range close up
                mask = 0;
                for (i = 0; i < count; i++) {
                    mask |= 1 << i;
                }
                for (i = 0; i < count; i++) {
                    for (y = 0; y < syswk->app->rangeHeight; y++) {
                        u32 row = start + y * 2;
                        if (i >= row && i < row + syswk->app->rangeWidth) {
                            mask ^= 1 << i;
                        }
                    }
                }
                for (i = start + 1; i < count; i++) {
                    for (y = 0; y < syswk->app->rangeHeight; y++) {
                        u32 row = start + y * 2;
                        if (i >= row && i < row + syswk->app->rangeWidth) {
                            break;
                        }
                    }
                    if (y == syswk->app->rangeHeight) {
                        Box2PokeMoveData *data;

                        mask ^= 1 << i;
                        data = &work->data[n];
                        data->iconPos = data->dfPos = i + BOX2_PARTY_POS;
                        for (j = 0; j < i; j++) {
                            if (!(mask & (1 << j))) {
                                data->mvPos = j + BOX2_PARTY_POS;
                                mask |= 1 << j;
                                break;
                            }
                        }
                        data->flag = 1;
                        PokeIconMoveSubParamMake(syswk, data);
                        n++;
                    }
                }
            } else {
                work->data[0].iconPos = BOX2_BOXLIST_POS;
                work->data[0].mvPos = putPos;
                work->data[0].dfPos = BOX2_BOXLIST_POS;
                work->data[0].flag = 1;
                PokeIconMoveParamMake(syswk, &work->data[0]);
            }
        } else {
            work->data[0].iconPos = BOX2_BOXLIST_POS;
            work->data[0].mvPos = putPos;
            work->data[0].dfPos = BOX2_BOXLIST_POS;
            work->data[0].flag = 1;
            PokeIconMoveParamMake(syswk, &work->data[0]);
            if (getPos >= BOX2_PARTY_POS) {
                for (i = getPos - BOX2_PARTY_POS + 1; i < count; i++) {
                    work->data[i].iconPos = i + BOX2_PARTY_POS;
                    work->data[i].mvPos = i + BOX2_PARTY_POS - 1;
                    work->data[i].dfPos = i + BOX2_PARTY_POS;
                    work->data[i].flag = 1;
                    PokeIconMoveSubParamMake(syswk, &work->data[i]);
                }
                work->data[count].iconPos = getPos;
                work->data[count].mvPos = count + BOX2_PARTY_POS - 1;
                work->data[count].dfPos = getPos;
                work->data[count].flag = 1;
                PokeIconMoveSubParamMake(syswk, &work->data[count]);
            }
        }
        return TRUE;
    }

    // From a box that isn't shown
    if (syswk->tray != syswk->getTray && getPos < BOX2_PARTY_POS) {
        if (putPos >= BOX2_PARTY_POS && putPos > count + BOX2_PARTY_POS) {
            putPos = count + BOX2_PARTY_POS;
        }
        work->data[0].iconPos = BOX2_BOXLIST_POS;
        work->data[0].mvPos = putPos;
        work->data[0].dfPos = getPos;
        work->data[0].flag = 1;
        work->data[1].iconPos = work->data[1].mvPos = work->data[1].dfPos = putPos;
        work->data[1].flag = 2;
        PokeIconMoveParamMake(syswk, &work->data[0]);
        PokeIconMoveParamMake(syswk, &work->data[1]);
        return TRUE;
    }

    if (getPos < BOX2_PARTY_POS) {
        if (putPos < BOX2_PARTY_POS || putPos - BOX2_PARTY_POS < count) {
            PokeIconChgDataMake(syswk, getPos, putPos);
        } else if (syswk->moveMode != 2) {
            PokeIconChgDataMake(syswk, getPos, count + BOX2_PARTY_POS);
        } else {
            // A range of the box goes to the end of the party
            n = 0;
            work->mode = 1;
            for (y = 0; y < syswk->app->rangeHeight; y++) {
                for (x = 0; x < syswk->app->rangeWidth; x++) {
                    if (syswk->app->rangeFlags[y * 6 + x] != 0) {
                        work->data[n].iconPos = x + (y * syswk->app->rangeWidth + BOX2_BOXLIST_POS);
                        work->data[n].mvPos = count + BOX2_PARTY_POS + n;
                        work->data[n].dfPos = x + (getPos + y * 6);
                        work->data[n].flag = 1;
                        PokeIconMoveParamMake(syswk, &work->data[n]);
                        n++;
                    }
                }
            }
        }
        return TRUE;
    }

    if (putPos < BOX2_PARTY_POS) {
        n = 0;
        if (Box2Main_GetPokeParam(syswk, putPos, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) != 0) {
            PokeIconChgDataMake(syswk, getPos, putPos);
        } else if (syswk->moveMode != 2) {
            // The party closes up behind the Pokémon that leaves it
            for (i = getPos - BOX2_PARTY_POS + 1; i < count; i++) {
                work->data[i].iconPos = i + BOX2_PARTY_POS;
                work->data[i].mvPos = i + BOX2_PARTY_POS - 1;
                work->data[i].dfPos = i + BOX2_PARTY_POS;
                work->data[i].flag = 1;
                PokeIconMoveParamMake(syswk, &work->data[i]);
            }
            work->data[getPos - BOX2_PARTY_POS].iconPos = BOX2_BOXLIST_POS;
            work->data[getPos - BOX2_PARTY_POS].mvPos = putPos;
            work->data[getPos - BOX2_PARTY_POS].dfPos = getPos;
            work->data[getPos - BOX2_PARTY_POS].flag = 1;
            PokeIconMoveParamMake(syswk, &work->data[getPos - BOX2_PARTY_POS]);
            work->data[count].iconPos = putPos;
            work->data[count].mvPos = count + BOX2_PARTY_POS - 1;
            work->data[count].dfPos = putPos;
            work->data[count].flag = 1;
            PokeIconMoveParamMake(syswk, &work->data[count]);
        } else {
            // A range of the party goes to the box
            u8 col, row;

            work->mode = 1;
            start = getPos - BOX2_PARTY_POS;
            for (row = n; row < syswk->app->rangeHeight; row++) {
                for (col = 0; col < syswk->app->rangeWidth; col++) {
                    if (col + (start + row * 2) < count) {
                        work->data[n].iconPos = col + (row * syswk->app->rangeWidth + BOX2_BOXLIST_POS);
                        work->data[n].mvPos = col + (putPos + row * 6);
                        work->data[n].dfPos = col + (getPos + row * 2);
                        work->data[n].flag = 1;
                        PokeIconMoveParamMake(syswk, &work->data[n]);
                        n++;
                    }
                }
            }
            mask = 0;
            for (i = 0; i < count; i++) {
                mask |= 1 << i;
            }
            for (i = 0; i < count; i++) {
                for (row = 0; row < syswk->app->rangeHeight; row++) {
                    u32 first = start + row * 2;
                    if (i >= first && i < first + syswk->app->rangeWidth) {
                        mask ^= 1 << i;
                    }
                }
            }
            for (i = start + 1; i < count; i++) {
                for (row = 0; row < syswk->app->rangeHeight; row++) {
                    u32 first = start + row * 2;
                    if (i >= first && i < first + syswk->app->rangeWidth) {
                        break;
                    }
                }
                if (row == syswk->app->rangeHeight) {
                    Box2PokeMoveData *data;
                    u8 k;

                    mask ^= 1 << i;
                    data = &work->data[n];
                    data->iconPos = data->dfPos = i + BOX2_PARTY_POS;
                    for (k = 0; k < i; k++) {
                        if (!(mask & (1 << k))) {
                            data->mvPos = k + BOX2_PARTY_POS;
                            mask |= 1 << k;
                            break;
                        }
                    }
                    data->flag = 1;
                    PokeIconMoveParamMake(syswk, data);
                    n++;
                }
            }
        }
        return TRUE;
    }

    // Within the party
    if (putPos - BOX2_PARTY_POS < count) {
        PokeIconChgDataMake(syswk, getPos, putPos);
    } else if (syswk->moveMode != 2) {
        for (i = getPos - BOX2_PARTY_POS + 1; i < count; i++) {
            work->data[i].iconPos = i + BOX2_PARTY_POS;
            work->data[i].mvPos = i + BOX2_PARTY_POS - 1;
            work->data[i].dfPos = i + BOX2_PARTY_POS;
            work->data[i].flag = 1;
            PokeIconMoveParamMake(syswk, &work->data[i]);
        }
        work->data[getPos - BOX2_PARTY_POS].iconPos = BOX2_BOXLIST_POS;
        work->data[getPos - BOX2_PARTY_POS].mvPos = count + BOX2_PARTY_POS - 1;
        work->data[getPos - BOX2_PARTY_POS].dfPos = getPos;
        work->data[getPos - BOX2_PARTY_POS].flag = 1;
        PokeIconMoveParamMake(syswk, &work->data[getPos - BOX2_PARTY_POS]);
    } else {
        // A range of the party goes to its end
        work->mode = 1;
        start = getPos - BOX2_PARTY_POS;
        mask = 0;
        n = 0;
        for (i = 0; i < count; i++) {
            mask |= 1 << i;
        }
        for (i = 0; i < count; i++) {
            for (y = 0; y < syswk->app->rangeHeight; y++) {
                u32 row = start + y * 2;
                if (i >= row && i < row + syswk->app->rangeWidth) {
                    mask ^= 1 << i;
                }
            }
        }
        for (i = start + 1; i < count; i++) {
            for (y = 0; y < syswk->app->rangeHeight; y++) {
                u32 row = start + y * 2;
                if (i >= row && i < row + syswk->app->rangeWidth) {
                    break;
                }
            }
            if (y == syswk->app->rangeHeight) {
                Box2PokeMoveData *data;

                mask ^= 1 << i;
                data = &work->data[n];
                data->iconPos = data->dfPos = i + BOX2_PARTY_POS;
                for (j = 0; j < i; j++) {
                    if (!(mask & (1 << j))) {
                        data->mvPos = j + BOX2_PARTY_POS;
                        mask |= 1 << j;
                        break;
                    }
                }
                data->flag = 1;
                PokeIconMoveParamMake(syswk, data);
                n++;
            }
        }
        for (y = 0; y < syswk->app->rangeHeight; y++) {
            for (x = 0; x < syswk->app->rangeWidth; x++) {
                if (x + (start + y * 2) < count) {
                    Box2PokeMoveData *data = &work->data[n];
                    u8 k;

                    data->iconPos = x + (y * syswk->app->rangeWidth + BOX2_BOXLIST_POS);
                    data->dfPos = x + (getPos + y * 2);
                    for (k = 0; k < count; k++) {
                        if (!(mask & (1 << k))) {
                            data->mvPos = k + BOX2_PARTY_POS;
                            data->flag = 1;
                            mask ^= 1 << k;
                            break;
                        }
                    }
                    PokeIconMoveParamMake(syswk, data);
                    n++;
                }
            }
        }
    }
    return TRUE;
}

// Sets up the moves of the icons when a party Pokémon is dropped into the box
static void PokeIconPartyOutDataMake(Box2SysWork *syswk, u32 getPos, u32 putPos) {
    Box2PokeMoveWork *work = syswk->app->vfunk.work;
    u32 count;
    u32 i;
    u32 index;

    work->mode = 0;
    sys_memset(work->data, 0, sizeof(work->data));
    if (putPos == BOX2_GET_NONE || Box2Main_PartyOutCheck(syswk, getPos, putPos) == FALSE) {
        work->getPos = BOX2_GET_NONE;
        work->putPos = BOX2_GET_NONE;
        work->data[0].iconPos = BOX2_BOXLIST_POS;
        work->data[0].mvPos = work->data[0].dfPos = getPos;
        work->data[0].flag = 1;
        work->data[1].iconPos = work->data[1].mvPos = work->data[1].dfPos = getPos;
        work->data[1].flag = 1;
        PokeIconMoveParamMake(syswk, &work->data[0]);
        return;
    }
    // A Pokémon dropped on another goes to the first free slot
    if (Box2Main_GetPokeParam(syswk, putPos, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) != 0) {
        u32 tray = syswk->tray;
        u32 slot = 0;

        BoxSaveAccessor_GetNextFreeBoxSlot(syswk->param->boxes, &tray, &slot);
        putPos = slot;
    }
    work->getPos = getPos;
    work->putPos = putPos;
    count = PokeParty_GetPkmCount(syswk->param->party);
    if (putPos < BOX2_PARTY_POS) {
        index = getPos - BOX2_PARTY_POS;
        for (i = index + 1; i < count; i++) {
            work->data[i].iconPos = i + BOX2_PARTY_POS;
            work->data[i].mvPos = i + BOX2_PARTY_POS - 1;
            work->data[i].dfPos = i + BOX2_PARTY_POS;
            work->data[i].flag = 1;
            PokeIconChgParamMake(syswk, &work->data[i]);
        }
        work->data[index].iconPos = BOX2_BOXLIST_POS;
        work->data[index].mvPos = putPos;
        work->data[index].dfPos = getPos;
        work->data[index].flag = 1;
        PokeIconChgParamMake(syswk, &work->data[index]);
        work->data[count].iconPos = putPos;
        work->data[count].mvPos = count + BOX2_PARTY_POS - 1;
        work->data[count].dfPos = putPos;
        work->data[count].flag = 1;
        PokeIconChgParamMake(syswk, &work->data[count]);
    }
}

// Sets up the moves of the icons when a box Pokémon is dropped into the party
static void PokeIconPartyInDataMake(Box2SysWork *syswk, u32 getPos, u32 putPos) {
    Box2PokeMoveWork *work = syswk->app->vfunk.work;
    u32 count;

    work->mode = 0;
    sys_memset(work->data, 0, sizeof(work->data));
    count = PokeParty_GetPkmCount(syswk->param->party);
    if (putPos == BOX2_GET_NONE || count == 6) {
        work->getPos = BOX2_GET_NONE;
        work->putPos = BOX2_GET_NONE;
        work->data[0].iconPos = BOX2_BOXLIST_POS;
        work->data[0].mvPos = work->data[0].dfPos = getPos;
        work->data[0].flag = 1;
        work->data[1].iconPos = work->data[1].mvPos = work->data[1].dfPos = getPos;
        work->data[1].flag = 1;
        PokeIconMoveParamMake(syswk, &work->data[0]);
        return;
    }
    if (putPos <= count + BOX2_PARTY_POS - 1) {
        putPos = count + BOX2_PARTY_POS;
    }
    work->getPos = getPos;
    work->putPos = putPos;
    PokeIconChgDataMake(syswk, getPos, count + BOX2_PARTY_POS);
}

// Where the icon at iconPos is going, or the cursor's position if it doesn't move
static u32 Box2Main_GetPokeMoveDest(Box2SysWork *syswk, u32 iconPos) {
    Box2PokeMoveWork *work = syswk->app->vfunk.work;
    u32 i;

    for (i = 0; i < 12; i++) {
        if (work->data[i].flag != 0 && iconPos == work->data[i].iconPos) {
            return work->data[i].mvPos;
        }
    }
    return syswk->pos;
}

// Sets up the moves of the icons of the party when the Pokémon at pos is released
static void PokeIconFreeDataMake(Box2SysWork *syswk, u32 pos) {
    Box2PokeMoveWork *work = syswk->app->vfunk.work;
    u32 index = pos - BOX2_PARTY_POS;
    u32 i;

    work->mode = 0;
    sys_memset(work->data, 0, sizeof(work->data));
    for (i = 0; i < 6; i++) {
        work->data[i].iconPos = work->data[i].mvPos = work->data[i].dfPos = i + BOX2_PARTY_POS;
        work->data[i].flag = 0;
    }
    work->data[i].flag = 0;
    for (i = index + 1; i < 6; i++) {
        work->data[i].mvPos = i + BOX2_PARTY_POS - 1;
        work->data[i].flag = 1;
        PokeIconMoveParamMake(syswk, &work->data[i]);
    }
    work->data[index].mvPos = BOX2_PARTY_POS + 5;
    work->data[index].flag = 1;
    PokeIconMoveParamMake(syswk, &work->data[index]);
}

// Moves the actors of the moved icons to their new positions in pokeIconId
static void PokeIconBufPosChange(Box2SysWork *syswk, Box2PokeMoveWork *work) {
    u8 ids[12];
    u16 heldPos = 0xffff;
    u16 i;

    for (i = 0; i < 12; i++) {
        if (work->data[i].flag != 0) {
            ids[i] = syswk->app->pokeIconId[work->data[i].dfPos];
        }
    }
    for (i = 0; i < 12; i++) {
        Box2PokeMoveData *data = &work->data[i];
        if (data->flag != 0) {
            if (data->mvPos <= BOX2_BOXLIST_POS) {
                syswk->app->pokeIconId[data->mvPos] = ids[i];
                if (data->iconPos == BOX2_BOXLIST_POS) {
                    heldPos = data->mvPos;
                }
            } else {
                syswk->app->pokeIconId[BOX2_BOXLIST_POS] = ids[i];
                if (data->iconPos == BOX2_BOXLIST_POS) {
                    heldPos = BOX2_BOXLIST_POS;
                }
            }
        }
    }
    if (heldPos != 0xffff) {
        func_ov255_021d045c(syswk->app, heldPos, syswk->app->rangeWidth, syswk->app->rangeHeight);
    }
    for (i = 0; i < BOX2_BOXLIST_POS; i++) {
        func_ov255_021cff58(syswk->app, i, TRUE);
    }
}

static void PokeIconBufPosChangeRange(Box2SysWork *syswk, Box2PokeMoveWork *work) {
    s16 i;
    s16 x, y;
    u32 width;
    u8 id;

    if (work->mode == 1) {
        for (i = 0; i < 12; i++) {
            Box2PokeMoveData *data = &work->data[i];
            if (data->flag != 0 && data->mvPos < BOX2_BOXLIST_POS) {
                id = syswk->app->pokeIconId[data->mvPos];
                syswk->app->pokeIconId[data->mvPos] = syswk->app->pokeIconId[data->iconPos];
                syswk->app->pokeIconId[data->iconPos] = id;
            }
        }
    } else {
        if (work->data[0].mvPos < BOX2_BOXLIST_POS) {
            width = (u16)func_ov255_021c27f8(syswk, work->data[0].mvPos);
        } else {
            width = syswk->app->rangeWidth;
        }
        if (work->data[0].mvPos < BOX2_BOXLIST_POS) {
            for (y = 0; y < syswk->app->rangeHeight; y++) {
                for (x = 0; x < syswk->app->rangeWidth; x++) {
                    if (syswk->app->rangeFlags[y * 6 + x] != 0) {
                        id = syswk->app->pokeIconId[work->data[0].iconPos + x + y * syswk->app->rangeWidth];
                        syswk->app->pokeIconId[work->data[0].iconPos + x + y * syswk->app->rangeWidth] =
                            syswk->app->pokeIconId[work->data[0].mvPos + (y * width + x)];
                        syswk->app->pokeIconId[work->data[0].mvPos + (y * width + x)] = id;
                    }
                }
            }
        }
    }
    for (i = 0; i < BOX2_BOXLIST_POS; i++) {
        func_ov255_021cff58(syswk->app, i, TRUE);
    }
}

static void PokeIconBufPosChangeAll(Box2SysWork *syswk, Box2PokeMoveWork *work) {
    if (syswk->moveMode == 2) {
        PokeIconBufPosChangeRange(syswk, work);
    } else {
        PokeIconBufPosChange(syswk, work);
    }
}

// The index of a move among the field moves that keep a Pokémon from being released; none in this game
static int PokeFreeWazaCheck(u16 move) {
    return -1;
}

void Box2Main_PokeFreeCreate(Box2SysWork *syswk) {
    Box2PokeFreeWork *work;
    BoxPkm *pkm;
    u32 i;

    syswk->app->pokeFree =
        GFL_HeapAllocate(HEAPID_TAIL(HEAPID_BOX2_APP), sizeof(Box2PokeFreeWork), FALSE, "box2_main.c", 3460);
    work = syswk->app->pokeFree;
    work->cap = syswk->app->actors[syswk->app->pokeIconId[syswk->pos]];
    work->checkCnt = 0;
    work->checkFlag = 0;
    pkm = Box2Main_GetBoxPkm(syswk, syswk->tray, syswk->pos);
    for (i = 0; i < 4; i++) {
        int waza = PokeFreeWazaCheck(PML_PkmGetParam(pkm, PKM_PARAM_MOVE1 + i, NULL));
        if (waza != -1) {
            work->checkFlag |= 1 << waza;
            return;
        }
    }
}

void Box2Main_PokeFreeExit(Box2SysWork *syswk) {
    GFL_HeapFree(syswk->app->pokeFree);
}

// Checks some Pokémon of the boxes and the party for the field moves of the one being released; FALSE once all are
// checked
BOOL Box2Main_PokeFreeWazaCheck(Box2SysWork *syswk) {
    Box2PokeFreeWork *work = syswk->app->pokeFree;
    u16 pos = work->checkCnt;
    u32 n;
    u32 i;
    BoxPkm *pkm;

    if (pos == BOX2_TRAY_MAX * BOX2_TRAY_POKE_MAX + 6) {
        return FALSE;
    }
    for (n = 0; n < 15; n++) {
        if (pos < BOX2_TRAY_MAX * BOX2_TRAY_POKE_MAX) {
            int tray = pos / BOX2_TRAY_POKE_MAX;
            int slot = pos % BOX2_TRAY_POKE_MAX;

            if (tray == syswk->tray && slot == syswk->pos) {
                pkm = NULL;
            } else {
                pkm = Box2Main_GetBoxPkm(syswk, tray, slot);
            }
        } else if (pos - BOX2_TRAY_MAX * BOX2_TRAY_POKE_MAX == syswk->pos - BOX2_PARTY_POS) {
            pkm = NULL;
        } else {
            pkm = Box2Main_GetBoxPkm(syswk, BOX2_GET_NONE, pos - BOX2_TRAY_MAX * BOX2_TRAY_POKE_MAX);
        }
        if (pkm != NULL && PML_PkmGetParam(pkm, PKM_PARAM_SPECIES_VALID, NULL) != 0) {
            for (i = 0; i < 4; i++) {
                int waza = PokeFreeWazaCheck(PML_PkmGetParam(pkm, PKM_PARAM_MOVE1 + i, NULL));
                if (waza != -1) {
                    work->checkFlag = work->checkFlag & (0xff ^ (1 << waza));
                }
            }
        }
        work->checkCnt++;
        pos = work->checkCnt;
        if (pos == BOX2_TRAY_MAX * BOX2_TRAY_POKE_MAX + 6) {
            return FALSE;
        }
    }
    return TRUE;
}

// Records whether Chatot is still in the party, which keeps its recorded cry
void Box2Main_UpdateChatter(Box2SysWork *syswk) {
    Box2Param *param = syswk->param;

    if (param->mode == 4 || param->mode == 5) {
        return;
    }
    checkChatotInParty(getChatterDataAddress(param->gameData), param->party);
}

// Starts moving the item icon to the position pos, from where it is
static void ItemIconMoveMakeCore(Box2SysWork *syswk, u32 setPos, u32 putPos, u32 mvMode, BOOL hand) {
    Box2ItemMoveWork *work = syswk->app->vfunk.work;
    s16 cx, cy;
    s16 px, py;
    int diff;

    func_ov255_021cf6ec(syswk->app, BOX2_ACTOR_ITEM_ICON, &cx, &cy, 0);
    func_ov255_021cfcdc(putPos, &px, &py, mvMode);
    if (hand == TRUE) {
        px += 8;
        py += 8;
    } else {
        py += 4;
    }
    work->putPos = putPos;
    work->setPos = setPos;
    work->cnt = 0;
    work->mvMode = mvMode;
    if (cx > px) {
        work->mvX = 1;
        diff = cx - px;
    } else {
        work->mvX = 0;
        diff = px - cx;
    }
    work->mx = (diff << 8) / BOX2_ITEMMOVE_CNT;
    if (cy > py) {
        work->mvY = 1;
        diff = cy - py;
    } else {
        work->mvY = 0;
        diff = py - cy;
    }
    work->my = (diff << 8) / BOX2_ITEMMOVE_CNT;
    work->nowX = cx << 8;
    work->nowY = cy << 8;
}

// Starts moving the item icon to the tray scroll arrow
static void Box2Main_ItemIconMoveMakeScroll(Box2SysWork *syswk, u32 mvMode) {
    Box2ItemMoveWork *work = syswk->app->vfunk.work;
    s16 cx, cy;
    s16 px, py;
    int diff;

    func_ov255_021cf6ec(syswk->app, BOX2_ACTOR_ITEM_ICON, &cx, &cy, 0);
    if (syswk->tray > syswk->getTray) {
        func_ov255_021cf6ec(syswk->app, 0, &px, &py, 0);
    } else {
        func_ov255_021cf6ec(syswk->app, 1, &px, &py, 0);
    }
    work->putPos = BOX2_GET_NONE;
    work->setPos = BOX2_GET_NONE;
    work->cnt = 0;
    work->mvMode = mvMode;
    if (cx > px) {
        work->mvX = 1;
        diff = cx - px;
    } else {
        work->mvX = 0;
        diff = px - cx;
    }
    work->mx = (diff << 8) / BOX2_ITEMMOVE_CNT;
    if (cy > py) {
        work->mvY = 1;
        diff = cy - py;
    } else {
        work->mvY = 0;
        diff = py - cy;
    }
    work->my = (diff << 8) / BOX2_ITEMMOVE_CNT;
    work->nowX = cx << 8;
    work->nowY = cy << 8;
}

static void Box2Main_ItemIconMoveMakeHand(Box2SysWork *syswk, u32 setPos, u32 putPos, u32 mvMode) {
    ItemIconMoveMakeCore(syswk, setPos, putPos, mvMode, TRUE);
}

static void Box2Main_ItemIconMoveMake(Box2SysWork *syswk, u32 putPos, u32 mvMode) {
    ItemIconMoveMakeCore(syswk, syswk->app->unkA55E, putPos, mvMode, FALSE);
}

static BOOL ItemIconMoveMain(Box2SysWork *syswk, BOOL hand) {
    Box2ItemMoveWork *work = syswk->app->vfunk.work;

    if (work->cnt == BOX2_ITEMMOVE_CNT) {
        if (work->putPos != BOX2_GET_NONE) {
            if (hand == TRUE) {
                func_ov255_021d0b64(syswk->app, work->putPos, work->mvMode);
            } else {
                func_ov255_021d0b98(syswk->app, work->putPos, work->mvMode);
            }
        }
        func_ov255_021d0d10(syswk->app);
        return FALSE;
    }
    if (work->mvX == 0) {
        work->nowX += work->mx;
    } else {
        work->nowX -= work->mx;
    }
    if (work->mvY == 0) {
        work->nowY += work->my;
    } else {
        work->nowY -= work->my;
    }
    func_ov255_021d0b4c(syswk->app, (s16)(work->nowX >> 8), (s16)(work->nowY >> 8));
    func_ov255_021d0d10(syswk->app);
    work->cnt++;
    return TRUE;
}

static BOOL Box2Main_VFuncItemIconMoveHand(Box2SysWork *syswk) {
    return ItemIconMoveMain(syswk, TRUE);
}

static BOOL Box2Main_VFuncItemIconMove(Box2SysWork *syswk) {
    return ItemIconMoveMain(syswk, FALSE);
}

// Moves the box list's scroll by mv boxes, around the boxes that are open
u8 Box2Main_GetTrayScroll(Box2SysWork *syswk, s8 mv) {
    s8 pos = (s8)syswk->trayScroll + mv;

    if (pos < 0) {
        pos = pos + (s8)syswk->trayMax;
    } else if (pos >= syswk->trayMax) {
        pos = pos - (s8)syswk->trayMax;
    }
    return pos;
}

static void WallCharLoad(Box2SysWork *syswk, u32 wallpaper, u32 offset) {
    NNSG2dCharacterData *chr;
    void *buf = GFL_G2DIOReadBGNCGR(ARCID_BOX2, wallpaper + 14, TRUE, &chr, HEAPID_BOX2_APP);

    GFL_BGSysLoadChar(3, chr->rawData, chr->size, offset);
    GFL_HeapFree(buf);
}

static void WallPaletteLoad(Box2SysWork *syswk, u32 wallpaper, u32 palette) {
    GFL_BGSysLoadNCLRDefault(ARCID_BOX2, wallpaper + 38, 0, palette * 32, 0x20, HEAPID_BOX2_APP);
}

static void WallScreenLoad(Box2SysWork *syswk, u32 wallpaper, u32 x, u32 charOffset, u32 palette) {
    NNSG2dScreenData *scr;
    void *buf;
    u16 *raw;
    u32 px;
    u8 y, i;
    u16 tile;

    buf = GFL_G2DIOReadNSCR(ARCID_BOX2, 13, TRUE, &scr, HEAPID_BOX2_APP);
    raw = (u16 *)scr->rawData;
    for (y = 0; y < 20; y++) {
        u16 *row = &raw[y * 21];
        px = x;
        for (i = 0; i < 21; i++) {
            tile = charOffset + ((palette << 12) + (row[i] & 0xfff));
            GFL_BGSysLoadScrAreaAll(3, &tile, px, y + 1, 1, 1);
            px++;
            if (px >= 64) {
                px = 0;
            }
        }
    }
    GFL_HeapFree(buf);
    GFL_BGSysFillScrArea(3, 0xe287, px, 0, 2, 20, 17);
    GFL_BGSysFillScrArea(3, 0xe287 + 41, px, 5, 2, 1, 17);
}

static void WallGraSet(Box2SysWork *syswk, u32 wallpaper, u32 x, u32 charOffset, u32 palette) {
    WallCharLoad(syswk, wallpaper, charOffset);
    WallPaletteLoad(syswk, wallpaper, palette);
    WallScreenLoad(syswk, wallpaper, x, charOffset, palette);
    GFL_BGSysQueueScrLoad(3);
}

// Puts a box's wallpaper on the other half of BG 3, which then scrolls to it
void Box2Main_WallPaperSet(Box2SysWork *syswk, u32 wallpaper, u32 dir) {
    u32 charOffset;
    u32 palette;
    u32 frame;

    if (dir == BOX2_TRAY_SCROLL_L) {
        syswk->app->wallPx -= 23;
        if (syswk->app->wallPx < 0) {
            syswk->app->wallPx += 64;
        }
    } else if (dir == BOX2_TRAY_SCROLL_R) {
        syswk->app->wallPx += 23;
        if (syswk->app->wallPx >= 64) {
            syswk->app->wallPx -= 64;
        }
    }
    if (syswk->app->wallArea == 0) {
        charOffset = 0x25c;
        palette = 14;
    } else {
        charOffset = 0xb8;
        palette = 15;
    }
    syswk->app->wallArea ^= 1;
    WallGraSet(syswk, wallpaper, syswk->app->wallPx, charOffset, palette);
    if (dir == BOX2_TRAY_SCROLL_NONE) {
        func_ov255_021ced54(syswk, syswk->tray, 7);
        func_ov255_021d1d68(syswk->app, 8, FALSE);
    } else {
        frame = 7;
        if (func_ov255_021d1d78(syswk->app, 7) == TRUE) {
            frame = 8;
        }
        func_ov255_021ced54(syswk, syswk->tray, frame);
        func_ov255_021d1d88(syswk->app, frame, dir);
        func_ov255_021d1d68(syswk->app, frame, TRUE);
    }
}

// Changes the shown box's wallpaper, with its palette faded in
void Box2Main_WallPaperChange(Box2SysWork *syswk, u32 wallpaper) {
    u32 charOffset;
    u32 palette;

    if (syswk->app->wallArea == 0) {
        charOffset = 0x25c;
        palette = 14;
    } else {
        charOffset = 0xb8;
        palette = 15;
    }
    syswk->app->wallArea ^= 1;
    WallCharLoad(syswk, wallpaper, charOffset);
    func_02026ee8(syswk->app->palFade, ARCID_BOX2, wallpaper + 38, HEAPID_BOX2_APP, 0, 0x20, palette << 4);
    WallScreenLoad(syswk, wallpaper, syswk->app->wallPx, charOffset, palette);
    GFL_BGSysQueueScrLoad(3);
}

u32 Box2Main_GetWallPaperNumber(Box2SysWork *syswk, u32 tray) {
    return getBoxNumFromIdx(syswk->param->boxes, tray);
}

// Reads the data of a Pokémon that the upper screen shows; NULL if there is none
static Box2PokeInfo *PokeInfoDataMake(BoxPkm *pkm) {
    Box2PokeInfo *info;
    u32 i;

    if (PML_PkmGetParam(pkm, PKM_PARAM_SPECIES_VALID, NULL) != 0) {
        info = GFL_HeapAllocate(HEAPID_BOX2_APP, sizeof(Box2PokeInfo), FALSE, "box2_main.c", 4070);
        info->pkm = pkm;
        info->species = PML_PkmGetParam(pkm, PKM_PARAM_SPECIES, NULL);
        info->item = PML_PkmGetParam(pkm, PKM_PARAM_ITEM, NULL);
        info->pid = PML_PkmGetParam(pkm, PKM_PARAM_PID, NULL);
        info->type1 = PML_PkmGetParam(pkm, PKM_PARAM_TYPE1, NULL);
        info->type2 = PML_PkmGetParam(pkm, PKM_PARAM_TYPE2, NULL);
        info->ability = PML_PkmGetParam(pkm, PKM_PARAM_ABILITY, NULL);
        info->nature = PML_PkmGetNature(pkm);
        info->mark = PML_PkmGetParam(pkm, PKM_PARAM_MARKINGS, NULL);
        info->level = PML_PkmGetParam(pkm, PKM_PARAM_LEVEL, NULL);
        info->egg = PML_PkmGetParam(pkm, PKM_PARAM_IS_EGG, NULL);
        if (info->egg == 0) {
            info->sex = PML_PkmGetSex(pkm);
        } else {
            info->sex = 0;
        }
        if (PML_PkmIsRare(pkm) == TRUE) {
            info->rare = 1;
        } else {
            info->rare = 0;
        }
        if (doesPokerusHaveDuration(pkm) == TRUE) {
            info->pokerus = 1;
        } else if (doesPokeHavePokerus(pkm) == TRUE) {
            info->pokerus = 2;
        } else {
            info->pokerus = 0;
        }
        // Nidoran's names already say their sex
        if (info->species != SPECIES_NIDORAN_F && info->species != SPECIES_NIDORAN_M && info->egg == 0) {
            info->sexPut = 1;
        } else {
            info->sexPut = 0;
        }
        for (i = 0; i < 4; i++) {
            info->waza[i] = PML_PkmGetParam(pkm, PKM_PARAM_MOVE1 + i, NULL);
        }
    } else {
        info = NULL;
    }
    return info;
}

static void PokeInfoDataFree(Box2PokeInfo *info) {
    GFL_HeapFree(info);
}

static void PokeInfoPutModeNormal(Box2SysWork *syswk, Box2PokeInfo *info) {
    func_ov255_021d06a4(syswk, info, 13);
    func_ov255_021d0a28(syswk->app, info);
    func_ov255_021ce798(syswk, info);
    Box2Main_MarkingPutSub(syswk, info->mark);
    PokeInfoIconPut(syswk->app, info);
    GFL_BGSysMoveBGReq(5, BG_MOVE_SET_Y, 0);
}

// Shows the Pokémon at a position on the upper screen; FALSE if there is none
BOOL Box2Main_PokeInfoPutCore(Box2SysWork *syswk, u32 tray, u32 pos) {
    BoxPkm *pkm = Box2Main_GetBoxPkm(syswk, tray, pos);
    BOOL encrypted;
    Box2PokeInfo *info;

    if (pkm != NULL) {
        encrypted = PML_PkmDecrypt(pkm);
        info = PokeInfoDataMake(pkm);
        if (info != NULL) {
            PokeInfoPutModeNormal(syswk, info);
            PokeInfoDataFree(info);
            PML_PkmReEncrypt(pkm, encrypted);
        } else {
            Box2Main_PokeInfoOff(syswk);
            PML_PkmReEncrypt(pkm, encrypted);
            return FALSE;
        }
    } else {
        Box2Main_PokeInfoOff(syswk);
        return FALSE;
    }
    return TRUE;
}

BOOL Box2Main_PokeInfoPut(Box2SysWork *syswk, u32 pos) {
    return Box2Main_PokeInfoPutCore(syswk, syswk->tray, pos);
}

// Redraws the upper screen's Pokémon, as after its item changed
void Box2Main_PokeInfoRewrite(Box2SysWork *syswk, u32 pos) {
    BoxPkm *pkm = Box2Main_GetBoxPkm(syswk, syswk->tray, pos);
    BOOL encrypted = PML_PkmDecrypt(pkm);
    Box2PokeInfo *info = PokeInfoDataMake(pkm);

    func_ov255_021d06a4(syswk, info, 13);
    func_ov255_021d0a28(syswk->app, info);
    func_ov255_021ce798(syswk, info);
    PokeInfoDataFree(info);
    PML_PkmReEncrypt(pkm, encrypted);
}

void Box2Main_PokeInfoOff(Box2SysWork *syswk) {
    u32 i;

    if (syswk->app->actors[13] != NULL) {
        func_ov255_021cf63c(syswk->app, 13, FALSE);
    }
    if (syswk->app->actors[14] != NULL) {
        func_ov255_021cf63c(syswk->app, 14, FALSE);
    }
    for (i = 32; i < 49; i++) {
        func_ov255_021cf63c(syswk->app, i, FALSE);
    }
    func_ov255_021ce81c(syswk->app);
    Box2Main_MarkingOff(syswk->app);
    func_ov255_021cf63c(syswk->app, 27, FALSE);
    func_ov255_021cf63c(syswk->app, 28, FALSE);
    func_ov255_021cf63c(syswk->app, 29, FALSE);
    GFL_BGSysMoveBGReq(5, BG_MOVE_SET_Y, 192);
}

void Box2Main_PokeSelectOff(Box2SysWork *syswk) {
    Box2Main_PokeInfoOff(syswk);
    func_ov255_021d11a4(syswk, 0);
    syswk->pos = BOX2_GET_NONE;
}

// Shows the six marks of a Pokémon from actor base on, each lit if it is set
static void MarkingPut(Box2SysWork *syswk, u32 base, u32 mark) {
    u16 i;
    u16 anim;

    for (i = 0; i < 6; i++) {
        if (mark & (1 << i)) {
            anim = i * 2 + 1;
        } else {
            anim = i * 2;
        }
        func_ov255_021cf5e4(syswk->app, base + i, anim);
        func_ov255_021cf63c(syswk->app, base + i, TRUE);
    }
}

void Box2Main_MarkingPutMain(Box2SysWork *syswk, u32 mark) {
    MarkingPut(syswk, 15, mark);
}

void Box2Main_MarkingPutSub(Box2SysWork *syswk, u32 mark) {
    MarkingPut(syswk, 21, mark);
}

static void Box2Main_MarkingOff(Box2AppWork *app) {
    u32 i;

    for (i = 0; i < 6; i++) {
        func_ov255_021cf63c(app, i + 21, FALSE);
    }
}

// Shows the shiny star and the Pokérus marks of the upper screen's Pokémon
static void PokeInfoIconPut(Box2AppWork *app, Box2PokeInfo *info) {
    if (info->rare == 0 || info->egg == 1) {
        func_ov255_021cf63c(app, 27, FALSE);
    } else {
        func_ov255_021cf63c(app, 27, TRUE);
    }
    if (info->pokerus == 0) {
        func_ov255_021cf63c(app, 28, FALSE);
        func_ov255_021cf63c(app, 29, FALSE);
    } else if (info->pokerus == 1) {
        func_ov255_021cf63c(app, 28, FALSE);
        func_ov255_021cf63c(app, 29, TRUE);
    } else {
        func_ov255_021cf63c(app, 28, TRUE);
        func_ov255_021cf63c(app, 29, FALSE);
    }
}

static BOOL AreaCheck(int x, int y, const Box2Area *area) {
    if (x >= area->left && x <= area->right && y >= area->top && y < area->bottom) {
        return TRUE;
    }
    return FALSE;
}

// The tray position at (x, y), or BOX2_GET_NONE
static u32 TrayPokePutAreaCheck(s16 x, s16 y) {
    s16 col, row;

    if (AreaCheck(x, y, &sTrayPokeArea) == TRUE) {
        if (x < 12) {
            col = 0;
        } else if (x >= 156) {
            col = 5;
        } else {
            col = (x - 12) / 24;
        }
        row = (y - 40) / 24;
        return col + row * 6;
    }
    return BOX2_GET_NONE;
}

// The party position at (x, y), or BOX2_GET_NONE
static u32 PartyPokePutAreaCheck(s16 x, s16 y, const Box2Area *areas) {
    u32 i;

    for (i = 0; i < 6; i++) {
        if (AreaCheck(x, y, &areas[i]) == TRUE) {
            return i + BOX2_PARTY_POS;
        }
    }
    return BOX2_GET_NONE;
}

// The box of the box list under the touch, or BOX2_GET_NONE for none or the shown box
static u32 BoxMovePutAreaCheck(Box2SysWork *syswk, s16 x, s16 y) {
    u32 pos = func_ov255_021d35c4(syswk->app->tpx, syswk->app->tpy);
    u32 tray;

    if (pos != BOX2_GET_NONE) {
        tray = pos - BOX2_BOXLIST_POS + syswk->trayScroll;
        if (tray >= syswk->trayMax) {
            tray -= syswk->trayMax;
        }
        if (tray == syswk->tray) {
            pos = BOX2_GET_NONE;
        }
    }
    return pos;
}

int Box2Main_PokeStatusCall(Box2SysWork *syswk) {
    Ov207Param *param = GFL_HeapAllocate(HEAPID_BOX2, sizeof(Ov207Param), FALSE, "box2_main.c", 4544);

    if (syswk->pos < BOX2_PARTY_POS) {
        param->party = (PokeParty *)Box2Main_GetBoxPkm(syswk, syswk->getTray, 0);
        param->unkC = 2;
        param->partyCount = BOX2_TRAY_POKE_MAX;
        param->partyIndex = syswk->pos;
    } else {
        param->party = syswk->param->party;
        param->unkC = 1;
        param->partyCount = PokeParty_GetPkmCount(syswk->param->party);
        param->partyIndex = syswk->pos - BOX2_PARTY_POS;
    }
    param->unk10 = 0;
    param->gameData = syswk->param->gameData;
    param->trainerData = syswk->param->trainerData;
    param->isNationalDex = syswk->param->unk1C;
    if (syswk->param->unk14 == 1) {
        param->unkD = 6;
    } else {
        param->unkD = 0;
    }
    QueueGameProc(syswk->procManager, OVERLAY_ID(207), &data_ov207_021bb6a0, param);
    syswk->subProcWork = param;
    return 0;
}

int Box2Main_PokeStatusExit(Box2SysWork *syswk) {
    Ov207Param *param = syswk->subProcWork;

    if (syswk->unk18 == 0) {
        if (syswk->pos < BOX2_PARTY_POS) {
            syswk->pos = param->partyIndex;
        } else {
            syswk->pos = param->partyIndex + BOX2_PARTY_POS;
        }
    }
    GFL_HeapFree(syswk->subProcWork);
    return 0;
}

int Box2Main_BagCall(Box2SysWork *syswk) {
    BagProcessData *bag = func_02034ad0(syswk->param->gameData, NULL, 2, HEAPID_BOX2);

    QueueGameProc(syswk->procManager, OVERLAY_BAG, &data_ov142_021a0910, bag);
    syswk->subProcWork = bag;
    return 0;
}

int Box2Main_BagExit(Box2SysWork *syswk) {
    BagProcessData *bag = syswk->subProcWork;

    syswk->subRet = bag->item;
    GFL_HeapFree(bag);
    return 0;
}

int Box2Main_NameInCall(Box2SysWork *syswk) {
    TrainerGameInfoSave *gameInfo = getTrainerGameInfoAddress(GameData_GetSaveControl(syswk->param->gameData));
    Box2NameInWork *work = GFL_HeapAllocate(HEAPID_BOX2, sizeof(Box2NameInWork), TRUE, "box2_main.c", 4659);

    work->name = GFL_StrBufCreate(20, HEAPID_BOX2);
    loadBoxNameToStrbuf(syswk->param->boxes, syswk->tray, work->name);
    work->param = setupNameEntry(HEAPID_BOX2, 2, 0, 0, 8, work->name, gameInfo);
    work->param->unk2C = 1;
    QueueGameProc(syswk->procManager, OVERLAY_ID(280), &NAME_ENTRY_PROC_FUNCTIONS, work->param);
    syswk->subProcWork = work;
    return 0;
}

int Box2Main_NameInExit(Box2SysWork *syswk) {
    Box2NameInWork *work = syswk->subProcWork;

    if (work->param->unk1C == 0) {
        getBoxNameFromStrbuf(syswk->param->boxes, syswk->tray, work->param->name);
    }
    syswk->subRet = work->param->unk1C;
    func_ov012_02165ae8(work->param);
    GFL_StrBufFree(work->name);
    GFL_HeapFree(syswk->subProcWork);
    Box2Main_InitSettings(syswk);
    return 0;
}

int Box2Main_BoxSearchCall(Box2SysWork *syswk) {
    BoxSearchParam *param = GFL_HeapAllocate(HEAPID_BOX2, sizeof(BoxSearchParam), TRUE, "box2_main.c", 4716);

    param->syswk = syswk;
    param->param = syswk->param;
    QueueGameProc(syswk->procManager, 0, &BOX_SEARCH_PROC_FUNCTIONS, param);
    syswk->subProcWork = param;
    return 0;
}

int Box2Main_BoxSearchExit(Box2SysWork *syswk) {
    syswk->subRet = 0;
    GFL_HeapFree(syswk->subProcWork);
    return 0;
}

// Moves the icons of the held range to follow the touch at (x, y)
static void PokeIconRangeTouchMove(Box2SysWork *syswk, u32 x, u32 y) {
    s16 row, col;

    for (row = 0; row < syswk->app->rangeHeight; row++) {
        s16 py = (s16)y - 8 + row * 24;
        for (col = 0; col < syswk->app->rangeWidth; col++) {
            func_ov255_021cf6c8(syswk->app,
                                syswk->app->pokeIconId[BOX2_BOXLIST_POS + row * syswk->app->rangeWidth + col],
                                (s16)x + col * 24, py, 0);
        }
    }
    func_ov255_021d22fc(syswk->app, x, y);
    func_ov255_021d1284(syswk->app, BOX2_BOXLIST_POS);
    syswk->app->tpx = x;
    syswk->app->tpy = y;
}
