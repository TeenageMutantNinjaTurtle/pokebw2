#include "types.h"
#include "app/ov139.h"
#include "app/pokemon_trade_local.h"
#include "constants/pokemon.h"
#include "constants/sound.h"
#include "constants/species.h"
#include "gfl/arc.h"
#include "gfl/arc_util.h"
#include "gfl/bg_sys.h"
#include "gfl/bmp.h"
#include "gfl/bmpwin.h"
#include "gfl/clact.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/key.h"
#include "gfl/msg.h"
#include "gfl/std.h"
#include "gfl/ui.h"
#include "nitro/gx.h"
#include "pml/personal.h"
#include "pml/poke_party.h"
#include "save/box.h"
#include "system/app_common.h"
#include "system/gf_font.h"
#include "system/printsys.h"

// The trade's 2D: the backgrounds of both screens, the strip of boxes on the lower screen with the Pokémon icons in
// it, the touch bar, and the sprites of the panels

// The strip: the party's two columns of three, then each box's six columns of five, each column 24 pixels wide. On
// the background, the party takes 12 tiles and each box 20
#define PARTY_COLUMNS 2
#define BOX_COLUMNS 6
#define COLUMN_ROWS 5
#define PARTY_TILES 12
#define BOX_TILES 20
// The most boxes there can be
#define MAX_BOXES 24
// The columns of icons that are set up at once, enough to cover the screen
#define ICON_COLUMNS 12

// The screen files of the strip's backgrounds: where the cells start, after the file's, the block's and the screen's
// headers, and the screens' width, in tiles
#define SCREEN_CELLS (0x24 / 2)
#define SCREEN_WIDTH 32

static u8 func_ov194_021c2b08(BoxPkm *pkm, HeapID heapId);
static void func_ov194_021c2b8c(PokemonTradeWork *wk, int box, u8 *colors);
static void func_ov194_021c2bc0(PokemonTradeWork *wk, PokeParty *party, u8 *colors);
static u16 func_ov194_021c2fa4(int x, int y, PokemonTradeWork *wk, BOOL marked);
static BOOL func_ov194_021c3020(PokemonTradeWork *wk, int x, int y);
static void func_ov194_021c3128(PokemonTradeWork *wk, u32 chars);
static void func_ov194_021c31e0(PokemonTradeWork *wk);
static void func_ov194_021c3614(PokemonTradeWork *wk, int index);
static void func_ov194_021c3770(int column, int row, ClActorPos *pos);
static BoxPkm *func_ov194_021c3788(BoxSaveAccessor *boxes, int column, int row, PokemonTradeWork *wk, BOOL *isParty);
static TradeBoxEntry *func_ov194_021c37e0(int column, int row, PokemonTradeWork *wk);
static BOOL func_ov194_021c3888(PokemonTradeWork *wk, int species);
static void func_ov194_021c38d4(PokemonTradeWork *wk, int column, int row, BoxPkm *pkm, BOOL isParty, int index);
static void func_ov194_021c3904(PokemonTradeWork *wk, BoxSaveAccessor *boxes, int column, int index, BOOL async);
static void func_ov194_021c3d2c(PokemonTradeWork *wk);
static int func_ov194_021c3f5c(int column);
static void func_ov194_021c3f68(PokemonTradeWork *wk);

// The cell actor systems of the trade, and of the trade demo, which has only a few sprites
static const ClActSysSetup sClActSetup = { 0, 0, 0, 512, 4, 124, 4, 124, 0, 128, 128, 128, 128, 16, 16 };
static const ClActSysSetup sDemoClActSetup = { 0, 0, 0, 512, 4, 124, 4, 124, 0, 5, 5, 5, 5, 16, 16 };

static const BGSysVRAMConfig sVRAMConfig = {
    GX_VRAM_BG_64_E,   GX_VRAM_BGEXTPLTT_NONE,  GX_VRAM_SUB_BG_128_C,        GX_VRAM_SUB_BGEXTPLTT_0123_H,
    GX_VRAM_OBJ_16_G,  GX_VRAM_OBJEXTPLTT_NONE, GX_VRAM_SUB_OBJ_128_D,       GX_VRAM_SUB_OBJEXTPLTT_NONE,
    GX_VRAM_TEX_01_AB, GX_VRAM_TEXPLTT_0_F,     GX_OBJVRAMMODE_CHAR_1D_128K, GX_OBJVRAMMODE_CHAR_1D_128K,
};

// The initial of each species' English name, from 0 for A, which the search by initial looks for. The two after the
// last species are the egg's
static u8 sSpeciesInitials[] = {
    0xff, 0x01, 0x08, 0x15, 0x02, 0x02, 0x02, 0x12, 0x16, 0x01, 0x02, 0x0c, 0x01, 0x16, 0x0a, 0x01, 0x0f, 0x0f, 0x0f,
    0x11, 0x11, 0x12, 0x05, 0x04, 0x00, 0x0f, 0x11, 0x12, 0x12, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x02, 0x02, 0x15,
    0x0d, 0x09, 0x16, 0x19, 0x06, 0x0e, 0x06, 0x15, 0x0f, 0x0f, 0x15, 0x15, 0x03, 0x03, 0x0c, 0x0f, 0x0f, 0x06, 0x0c,
    0x0f, 0x06, 0x00, 0x0f, 0x0f, 0x0f, 0x00, 0x0a, 0x00, 0x0c, 0x0c, 0x0c, 0x01, 0x16, 0x15, 0x13, 0x13, 0x06, 0x06,
    0x06, 0x0f, 0x11, 0x12, 0x12, 0x0c, 0x0c, 0x05, 0x03, 0x03, 0x12, 0x03, 0x06, 0x0c, 0x12, 0x02, 0x06, 0x07, 0x06,
    0x0e, 0x03, 0x07, 0x0a, 0x0a, 0x15, 0x04, 0x04, 0x04, 0x02, 0x0c, 0x07, 0x07, 0x0b, 0x0a, 0x16, 0x11, 0x11, 0x02,
    0x13, 0x0a, 0x07, 0x12, 0x06, 0x12, 0x12, 0x12, 0x0c, 0x12, 0x09, 0x04, 0x0c, 0x0f, 0x13, 0x0c, 0x06, 0x0b, 0x03,
    0x04, 0x15, 0x09, 0x05, 0x0f, 0x0e, 0x0e, 0x0a, 0x0a, 0x00, 0x12, 0x00, 0x19, 0x0c, 0x03, 0x03, 0x03, 0x0c, 0x0c,
    0x02, 0x01, 0x0c, 0x02, 0x10, 0x13, 0x13, 0x02, 0x05, 0x12, 0x05, 0x07, 0x0d, 0x0b, 0x0b, 0x12, 0x00, 0x02, 0x02,
    0x0b, 0x0f, 0x02, 0x08, 0x13, 0x13, 0x0d, 0x17, 0x0c, 0x05, 0x00, 0x01, 0x0c, 0x00, 0x12, 0x0f, 0x07, 0x12, 0x09,
    0x00, 0x12, 0x12, 0x18, 0x16, 0x10, 0x04, 0x14, 0x0c, 0x12, 0x0c, 0x14, 0x16, 0x06, 0x0f, 0x05, 0x03, 0x06, 0x12,
    0x12, 0x06, 0x10, 0x12, 0x12, 0x07, 0x12, 0x13, 0x14, 0x12, 0x0c, 0x12, 0x0f, 0x02, 0x11, 0x0e, 0x03, 0x0c, 0x12,
    0x07, 0x07, 0x0a, 0x0f, 0x03, 0x0f, 0x12, 0x12, 0x13, 0x07, 0x12, 0x04, 0x0c, 0x0c, 0x01, 0x11, 0x04, 0x12, 0x0b,
    0x0f, 0x13, 0x0b, 0x07, 0x02, 0x13, 0x06, 0x12, 0x13, 0x02, 0x01, 0x0c, 0x0c, 0x12, 0x0f, 0x0c, 0x19, 0x0b, 0x16,
    0x12, 0x01, 0x02, 0x03, 0x0b, 0x0b, 0x0b, 0x12, 0x0d, 0x12, 0x13, 0x12, 0x16, 0x0f, 0x11, 0x0a, 0x06, 0x12, 0x0c,
    0x12, 0x01, 0x12, 0x15, 0x12, 0x0d, 0x0d, 0x12, 0x16, 0x0b, 0x04, 0x0c, 0x07, 0x00, 0x0d, 0x12, 0x03, 0x12, 0x0c,
    0x00, 0x0b, 0x00, 0x0c, 0x0c, 0x04, 0x0c, 0x0f, 0x0c, 0x15, 0x08, 0x11, 0x06, 0x12, 0x02, 0x12, 0x16, 0x16, 0x0d,
    0x02, 0x13, 0x12, 0x06, 0x12, 0x13, 0x15, 0x05, 0x02, 0x02, 0x12, 0x00, 0x19, 0x12, 0x0b, 0x12, 0x01, 0x16, 0x02,
    0x02, 0x01, 0x02, 0x0b, 0x02, 0x00, 0x00, 0x05, 0x0c, 0x02, 0x0a, 0x12, 0x01, 0x03, 0x03, 0x13, 0x02, 0x00, 0x16,
    0x12, 0x06, 0x12, 0x12, 0x16, 0x02, 0x07, 0x06, 0x11, 0x0b, 0x01, 0x12, 0x12, 0x01, 0x0c, 0x0c, 0x11, 0x11, 0x11,
    0x0b, 0x0b, 0x0a, 0x06, 0x11, 0x09, 0x03, 0x13, 0x06, 0x13, 0x02, 0x0c, 0x08, 0x0f, 0x0f, 0x04, 0x12, 0x12, 0x12,
    0x01, 0x01, 0x0a, 0x0a, 0x12, 0x0b, 0x0b, 0x01, 0x11, 0x02, 0x11, 0x12, 0x01, 0x01, 0x16, 0x0c, 0x02, 0x15, 0x0f,
    0x01, 0x05, 0x02, 0x02, 0x12, 0x06, 0x00, 0x03, 0x03, 0x01, 0x0b, 0x0c, 0x07, 0x06, 0x0f, 0x02, 0x12, 0x12, 0x01,
    0x01, 0x01, 0x0c, 0x07, 0x02, 0x12, 0x06, 0x06, 0x06, 0x0c, 0x11, 0x0b, 0x07, 0x07, 0x12, 0x03, 0x02, 0x13, 0x02,
    0x05, 0x0b, 0x0c, 0x12, 0x00, 0x16, 0x0c, 0x0b, 0x11, 0x13, 0x04, 0x0c, 0x13, 0x18, 0x0b, 0x06, 0x06, 0x0c, 0x0f,
    0x06, 0x0f, 0x03, 0x05, 0x11, 0x14, 0x0c, 0x00, 0x03, 0x0f, 0x07, 0x11, 0x06, 0x02, 0x0f, 0x0c, 0x03, 0x12, 0x00,
    0x15, 0x12, 0x12, 0x12, 0x13, 0x0f, 0x04, 0x0e, 0x03, 0x12, 0x0f, 0x16, 0x0b, 0x07, 0x12, 0x0f, 0x0b, 0x0f, 0x12,
    0x0f, 0x12, 0x0f, 0x12, 0x0c, 0x0c, 0x0f, 0x13, 0x14, 0x01, 0x19, 0x11, 0x01, 0x06, 0x16, 0x12, 0x03, 0x04, 0x00,
    0x13, 0x06, 0x02, 0x13, 0x0f, 0x12, 0x13, 0x12, 0x12, 0x12, 0x0b, 0x15, 0x16, 0x12, 0x02, 0x16, 0x0f, 0x0b, 0x01,
    0x12, 0x0a, 0x0a, 0x03, 0x03, 0x0c, 0x03, 0x02, 0x12, 0x12, 0x12, 0x18, 0x02, 0x13, 0x02, 0x00, 0x00, 0x13, 0x06,
    0x19, 0x19, 0x0c, 0x02, 0x06, 0x06, 0x06, 0x12, 0x03, 0x11, 0x03, 0x12, 0x15, 0x15, 0x15, 0x03, 0x12, 0x04, 0x0a,
    0x04, 0x05, 0x00, 0x05, 0x09, 0x00, 0x09, 0x06, 0x05, 0x05, 0x0a, 0x0a, 0x0a, 0x13, 0x04, 0x04, 0x04, 0x01, 0x0b,
    0x0b, 0x02, 0x00, 0x05, 0x07, 0x02, 0x01, 0x02, 0x12, 0x00, 0x12, 0x0c, 0x0c, 0x03, 0x06, 0x06, 0x0f, 0x01, 0x01,
    0x11, 0x01, 0x15, 0x0c, 0x07, 0x03, 0x03, 0x19, 0x07, 0x0b, 0x15, 0x02, 0x13, 0x15, 0x13, 0x13, 0x11, 0x19, 0x0b,
    0x0a, 0x0a, 0x0c, 0x06, 0x04, 0x01,
};

void func_ov194_021c2a24(PokemonTradeWork *wk) {
    TouchBarItem items[] = {
        { 1, 232, 168 },
        { TOUCHBAR_ICON_CUSTOM, 28, 168 },
        { TOUCHBAR_ICON_CUSTOM + 1, 204, 168 },
        { TOUCHBAR_ICON_CUSTOM + 2, 48, 168 },
    };
    TouchBarSetup setup;

    sys_memset(&setup, 0, sizeof(setup));
    setup.items = items;
    setup.count = NELEMS(items);
    setup.unit = wk->clactUnit;
    setup.unk1C = TRUE;
    setup.bgPltt = 7;
    setup.objPltt = 0;
    setup.mapping = 2;
    setup.bgFrame = 4;

    items[1].charRes = wk->objRes[TRADE_OBJRES_CHAR_SUB];
    items[1].plttRes = wk->objRes[TRADE_OBJRES_PLTT_SUB];
    items[1].cellRes = wk->objRes[TRADE_OBJRES_CELL_SUB];
    items[1].anims[0] = 6;
    items[1].anims[1] = 5;
    items[1].anims[2] = 4;
    items[1].key = 0;
    items[1].se = SEQ_SE_DECIDE1;

    items[2].charRes = wk->objRes[TRADE_OBJRES_CHAR_SUB];
    items[2].plttRes = wk->objRes[TRADE_OBJRES_PLTT_SUB];
    items[2].cellRes = wk->objRes[TRADE_OBJRES_CELL_SUB];
    items[2].anims[0] = 9;
    items[2].anims[1] = 8;
    items[2].anims[2] = 7;
    items[2].key = PAD_BUTTON_START;
    items[2].se = SEQ_SE_DECIDE1;

    items[3].charRes = wk->objRes[TRADE_OBJRES_CHAR_SUB];
    items[3].plttRes = wk->objRes[TRADE_OBJRES_PLTT_SUB];
    items[3].cellRes = wk->objRes[TRADE_OBJRES_CELL_SUB];
    items[3].anims[0] = 22;
    items[3].anims[1] = 21;
    items[3].anims[2] = 20;
    items[3].key = PAD_KEY_RIGHT | PAD_KEY_LEFT;
    items[3].se = SEQ_SE_DECIDE1;

    wk->touchBar = func_ov139_02199aa0(&setup, wk->heapId);
    func_ov139_02199d18(wk->touchBar, TOUCHBAR_ICON_CUSTOM + 2, FALSE);
    func_ov139_02199d18(wk->touchBar, TOUCHBAR_ICON_CUSTOM + 1, FALSE);
    func_ov139_02199ce0(wk->touchBar, 2);
}

// The colour of a Pokémon's slot, an index into the box palette: none for an empty slot, the species' colour, or the
// colour of an egg, Manaphy's being different
static u8 func_ov194_021c2b08(BoxPkm *pkm, HeapID heapId) {
    u16 color = 0;
    BOOL encrypted = PML_PkmDecrypt(pkm);
    u32 species = PML_PkmGetParam(pkm, PKM_PARAM_SPECIES, NULL);

    if (PML_PkmGetParam(pkm, PKM_PARAM_SPECIES_VALID, NULL)) {
        if (!PML_PkmGetParam(pkm, PKM_PARAM_IS_EGG, NULL)) {
            u16 form = PML_PkmGetParam(pkm, PKM_PARAM_FORM, NULL);
            void *personal = PML_PersonalLoad(species, form, heapId);
            color = PML_PersonalGetParam(personal, 33);
            PML_PersonalFree(personal);
        } else {
            color = 1;
            if (species != SPECIES_MANAPHY) {
                color = 8;
            }
        }
        color++;
    }
    PML_PkmReEncrypt(pkm, encrypted);
    return color;
}

static void func_ov194_021c2b8c(PokemonTradeWork *wk, int box, u8 *colors) {
    u8 i;

    for (i = 0; i < 30; i++) {
        colors[i] = func_ov194_021c2b08(BoxSaveAccessor_GetPkm(wk->boxes, box, i), wk->heapId);
    }
}

static void func_ov194_021c2bc0(PokemonTradeWork *wk, PokeParty *party, u8 *colors) {
    int count = PokeParty_GetPkmCount(party);
    u8 i;

    for (i = 0; i < 6; i++) {
        if (count > i) {
            colors[i] = func_ov194_021c2b08(func_0201d620(PokeParty_GetPkm(party, i)), wk->heapId);
        } else {
            colors[i] = 0;
        }
    }
}

// Works out the colours of this machine's box, one a frame, and the party's after the last box; TRUE when that is
// done
BOOL func_ov194_021c2c04(PokemonTradeWork *wk, int box) {
    while (box < wk->boxCount + 1) {
        if (box == wk->boxCount) {
            func_ov194_021c2bc0(wk, wk->party, wk->boxColors[0].party);
            return TRUE;
        }
        func_ov194_021c2b8c(wk, box, wk->boxColors[0].boxes[box]);
        break;
    }
    return FALSE;
}

void func_ov194_021c2c44(PokemonTradeWork *wk) {
    ClActSys_Create(&sDemoClActSetup, &sVRAMConfig, wk->heapId);
}

void func_ov194_021c2c64(PokemonTradeWork *wk) {
    ClActSys_Create(&sClActSetup, &sVRAMConfig, wk->heapId);
}

void func_ov194_021c2c84(PokemonTradeWork *wk) {
    ArcTool *arc = GFL_ArcSysCreateFileHandle(0x67, wk->heapId);
    int screen;

    if (PokemonTrade_IsNegoType(wk)) {
        screen = 4;
    } else {
        screen = 11;
    }
    GFL_G2DIOLoadArcNCLRDefault(arc, 9, 0, 0, 0, wk->heapId);
    if (wk->bg2Chars == 0) {
        wk->bg2Chars = GFL_BGSysLoadArcNCGRDynamic(arc, 10, 2, 0, FALSE, wk->heapId);
    }
    GFL_G2DIOLoadNSCRSync(arc, screen, 2, 0, CHAR_POS(wk->bg2Chars), 0, FALSE, wk->heapId);
    GFL_ArcToolFree(arc);
}

void func_ov194_021c2d0c(PokemonTradeWork *wk) {
    if (wk->bg2Chars != 0) {
        GFL_BGSysFreeCharMemory(2, CHAR_POS(wk->bg2Chars), CHAR_SIZE(wk->bg2Chars));
    }
    wk->bg2Chars = 0;
}

void func_ov194_021c2d34(PokemonTradeWork *wk) {
    ArcTool *arc = GFL_ArcSysCreateFileHandle(0x67, wk->heapId);

    GFL_G2DIOLoadNSCRSync(arc, 12, 4, 0, CHAR_POS(wk->bg5Chars), 0, FALSE, wk->heapId);
    GFL_ArcToolFree(arc);
}

void func_ov194_021c2d74(PokemonTradeWork *wk) {
}

void func_ov194_021c2d78(PokemonTradeWork *wk) {
    ArcTool *arc = GFL_ArcSysCreateFileHandle(0x67, wk->heapId);

    GFL_G2DIOLoadArcNCLRDefault(arc, 17, 4, 0, 0xc0, wk->heapId);
    wk->bg7Chars = GFL_BGSysLoadArcNCGRDynamic(arc, 13, 7, 0, FALSE, wk->heapId);
    wk->bg5Chars = GFL_BGSysLoadArcNCGRDynamic(arc, 13, 5, 0, FALSE, wk->heapId);
    GFL_ArcToolFree(arc);
    func_ov194_021c3128(wk, wk->bg7Chars);
}

void func_ov194_021c2de8(PokemonTradeWork *wk) {
    wk->cursorImage = LoadCursorImageEndOfHeap(6, 15, 0, wk->heapId);
}

void func_ov194_021c2e04(PokemonTradeWork *wk) {
    func_ov194_021c31e0(wk);
    if (wk->bg5Chars != 0) {
        GFL_BGSysFreeCharMemory(5, CHAR_POS(wk->bg5Chars), CHAR_SIZE(wk->bg5Chars));
        wk->bg5Chars = 0;
    }
    if (wk->bg7Chars != 0) {
        GFL_BGSysFreeCharMemory(7, CHAR_POS(wk->bg7Chars), CHAR_SIZE(wk->bg7Chars));
        wk->bg7Chars = 0;
    }
    if (wk->cursorImage != 0) {
        GFL_BGSysFreeCharMemory(6, CHAR_POS(wk->cursorImage), CHAR_SIZE(wk->cursorImage));
        wk->cursorImage = 0;
    }
}

// Loads the common UI sprites once
void func_ov194_021c2e6c(PokemonTradeWork *wk) {
    if (wk->objRes[TRADE_OBJRES_PLTT_COMMON] == 0) {
        ArcTool *arc = GFL_ArcSysCreateFileHandle(getUINarcIdx(), wk->heapId);

        wk->objRes[TRADE_OBJRES_CHAR_COMMON] = func_0204b81c(arc, func_0202d814(), FALSE, CLACT_VRAM_SUB, wk->heapId);
        wk->objRes[TRADE_OBJRES_PLTT_COMMON] = func_0204bbb8(arc, func_0202d810(), CLACT_VRAM_SUB, 0, 0, 3, wk->heapId);
        wk->objRes[TRADE_OBJRES_CELL_COMMON] = func_0204bde0(arc, func_0202d818(2), func_0202d81c(2), wk->heapId);
        GFL_ArcToolFree(arc);
    }
}

void func_ov194_021c2ef0(PokemonTradeWork *wk, int side, int page) {
    u32 screens[] = { 27, 28 };
    ArcTool *arc = GFL_ArcSysCreateFileHandle(0x67, wk->heapId);

    GFL_G2DIOLoadNSCRSync(arc, screens[page], 4, 0, CHAR_POS(wk->bg5Chars), 0, FALSE, wk->heapId);
    if (side) {
        GFL_BGSysMoveBG(4, 0, 128);
    } else {
        GFL_BGSysMoveBG(4, 0, 0);
    }
    func_0204c124(wk->actors[2], FALSE);
    GFL_ArcToolFree(arc);
    GFL_BGSysSetBGEnabled(4, TRUE);
}

void func_ov194_021c2f78(PokemonTradeWork *wk) {
    GFL_BGSysSetBGEnabled(4, FALSE);
    GFL_BGSysMoveBG(4, 0, 0);
    func_ov194_021c5504(wk);
    GFL_BGSysClearScr(4);
    GFL_BGSysQueueScrLoad(4);
}

// The cell of the strip's background at a tile, the strip repeating every stripTileWidth tiles
static u16 func_ov194_021c2fa4(int x, int y, PokemonTradeWork *wk, BOOL marked) {
    if (x >= wk->stripTileWidth) {
        x -= wk->stripTileWidth;
    }
    if (x < PARTY_TILES) {
        if (marked) {
            return wk->stripScreens[3][SCREEN_CELLS + y * SCREEN_WIDTH + x];
        }
        return wk->stripScreens[1][SCREEN_CELLS + y * SCREEN_WIDTH + x];
    }
    x = (x - PARTY_TILES) % BOX_TILES;
    if (marked) {
        return wk->stripScreens[2][SCREEN_CELLS + y * SCREEN_WIDTH + x];
    }
    return wk->stripScreens[0][SCREEN_CELLS + y * SCREEN_WIDTH + x];
}

// Whether a tile of the screen is under a marked icon
static BOOL func_ov194_021c3020(PokemonTradeWork *wk, int x, int y) {
    int i, j;

    for (i = 0; i < ICON_COLUMNS; i++) {
        for (j = 0; j < COLUMN_ROWS; j++) {
            if (wk->iconMarked[i][j]) {
                int left = wk->iconPos[i][j].x - 5;
                int top = wk->iconPos[i][j].y - 8;

                if (left < 0) {
                    left -= 8;
                }
                left /= 8;
                top /= 8;
                if (left <= x && left + 3 > x && top <= y && top + 3 > y) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

// Draws the strip's background at its scroll, with the marked icons' slots lit
void func_ov194_021c30b8(PokemonTradeWork *wk) {
    int scroll = wk->scrollX / 8;
    int x, y;

    func_ov194_021c3bc0(wk);
    for (y = 0; y < 24; y++) {
        for (x = 0; x < 52; x++) {
            GFL_BGSysSetScrTile(7, x, y, func_ov194_021c2fa4(scroll + x, y, wk, func_ov194_021c3020(wk, x, y)));
        }
    }
    wk->unk108C = wk->scrollX % 8;
    wk->unk1084 = 1;
    GFL_BGSysQueueScrLoad(7);
}

// Reads the strip's screens and moves their cells to the characters where they were loaded
static void func_ov194_021c3128(PokemonTradeWork *wk, u32 chars) {
    int i;

    wk->stripScreens[0] = GFL_ArcSysReadHeapNew(0x67, 14, wk->heapId);
    wk->stripScreens[1] = GFL_ArcSysReadHeapNew(0x67, 15, wk->heapId);
    wk->stripScreens[2] = GFL_ArcSysReadHeapNew(0x67, 25, wk->heapId);
    wk->stripScreens[3] = GFL_ArcSysReadHeapNew(0x67, 26, wk->heapId);
    for (i = 0; i < SCREEN_WIDTH * 24; i++) {
        wk->stripScreens[0][SCREEN_CELLS + i] += CHAR_POS(chars);
        wk->stripScreens[1][SCREEN_CELLS + i] += CHAR_POS(chars);
        wk->stripScreens[2][SCREEN_CELLS + i] += CHAR_POS(chars);
        wk->stripScreens[3][SCREEN_CELLS + i] += CHAR_POS(chars);
    }
    wk->scrollX = wk->stripWidth - 80;
    func_ov194_021c30b8(wk);
}

static void func_ov194_021c31e0(PokemonTradeWork *wk) {
    if (wk->stripScreens[0] != NULL) {
        GFL_HeapFree(wk->stripScreens[0]);
        wk->stripScreens[0] = NULL;
        GFL_HeapFree(wk->stripScreens[1]);
        wk->stripScreens[1] = NULL;
        GFL_HeapFree(wk->stripScreens[2]);
        wk->stripScreens[2] = NULL;
        GFL_HeapFree(wk->stripScreens[3]);
        wk->stripScreens[3] = NULL;
    }
}

// Draws the names of the boxes, and the party's, into their windows
void func_ov194_021c3224(PokemonTradeWork *wk) {
    int i;

    GFL_BGSysLoadNCLRDefault(0x17, 5, 4, 0x1c0, 0x20, wk->heapId);
    for (i = 0; i < wk->boxCount + 1; i++) {
        if (wk->boxNameWindows[i] == NULL) {
            wk->boxNameWindows[i] = BmpWin_CreateDynamic(5, 0, 0, 15, 2, 14, 0);
        }
        if (i == wk->boxCount) {
            GFL_MsgDataLoadStrbuf(wk->msgData, 16, wk->drawStr);
        } else {
            loadBoxNameToStrbuf(wk->boxes, i, wk->drawStr);
        }
        GFL_TextRndUpdateColorIndexLUT(15, 2, 0);
        GFL_BitmapFill(BmpWin_GetBitmap(wk->boxNameWindows[i]), 0);
        GFL_TextRendererDrawToBitmap(BmpWin_GetBitmap(wk->boxNameWindows[i]), 0, 1, wk->drawStr, wk->font);
        BmpWin_FlushChar(wk->boxNameWindows[i]);
        BmpWin_SetPosY(wk->boxNameWindows[i], 0);
    }
}

void func_ov194_021c3374(PokemonTradeWork *wk) {
    int i;

    for (i = 0; i < MAX_BOXES + 1; i++) {
        if (wk->boxNameWindows[i] != NULL) {
            BmpWin_Free(wk->boxNameWindows[i]);
            wk->boxNameWindows[i] = NULL;
        }
    }
}

// Puts the names of the boxes on screen over the strip at its scroll
void func_ov194_021c339c(PokemonTradeWork *wk) {
    int scroll = wk->scrollX / 8;
    int x, y, i, box;

    for (y = 0; y < 2; y++) {
        for (x = 0; x < 64; x++) {
            GFL_BGSysSetScrTile(5, x, y, 0);
        }
    }
    if (wk->scrollX < 96) {
        box = wk->boxCount;
    } else {
        box = (wk->scrollX - 96) / 160;
    }
    for (i = 0; i < 3; i++) {
        int name = box + i;

        if (name > wk->boxCount) {
            name = name - wk->boxCount - 1;
        } else if (name < 0) {
            name = name + wk->boxCount + 1;
        }
        if (name == wk->boxCount) {
            x = wk->stripTileWidth - scroll;
            if (scroll > x) {
                scroll -= wk->stripTileWidth;
            } else {
                x = -scroll;
            }
        } else {
            x = name * BOX_TILES + PARTY_TILES - scroll;
        }
        if (x >= -10 && x <= 33) {
            BmpWin_SetPosX(wk->boxNameWindows[name], x + 1);
            BmpWin_FlushMap(wk->boxNameWindows[name]);
        }
    }
    GFL_BGSysQueueScrLoad(5);
}

// Loads the icons' palette and cells, and sets up the icons of the strip's columns with their cursors, all hidden
void func_ov194_021c3480(PokemonTradeWork *wk) {
    ClActorSetup setup;
    int i, j;
    ArcTool *arc = GFL_ArcSysCreateFileHandle(7, wk->heapId);

    wk->objRes[TRADE_OBJRES_PLTT_ICON] = func_0204bc48(arc, func_02021114(), CLACT_VRAM_SUB, 0x60, wk->heapId);
    wk->objRes[TRADE_OBJRES_CELL_ICON] = func_0204bde0(arc, func_02021154(), getOBJTileMapping_MainEng(), wk->heapId);
    for (i = 0; i < ICON_COLUMNS; i++) {
        for (j = 0; j < COLUMN_ROWS; j++) {
            setup.x = 0;
            setup.y = 0;
            setup.sequence = 1;
            setup.priority = 16;
            setup.bgPriority = 3;
            wk->iconChars[i][j] = func_0204b81c(arc, 0x55e, FALSE, CLACT_VRAM_SUB, wk->heapId);
            wk->icons[i][j] = func_0204c040(wk->clactUnit, wk->iconChars[i][j], wk->objRes[TRADE_OBJRES_PLTT_ICON],
                                            wk->objRes[TRADE_OBJRES_CELL_ICON], &setup, CLACT_VRAM_SUB, wk->heapId);
            setup.sequence = 0;
            setup.priority = 15;
            wk->iconCursors[i][j] =
                func_0204c040(wk->clactUnit, wk->objRes[TRADE_OBJRES_CHAR_SUB], wk->objRes[TRADE_OBJRES_PLTT_SUB],
                              wk->objRes[TRADE_OBJRES_CELL_SUB], &setup, CLACT_VRAM_SUB, wk->heapId);
            func_0204c520(wk->icons[i][j], FALSE);
            func_0204c124(wk->icons[i][j], FALSE);
            func_0204c124(wk->iconCursors[i][j], FALSE);
            func_0204c520(wk->iconCursors[i][j], TRUE);
        }
    }
    GFL_ArcToolFree(arc);
}

static void func_ov194_021c3614(PokemonTradeWork *wk, int index) {
    int i;

    for (i = 0; i < COLUMN_ROWS; i++) {
        if (wk->icons[index][i] != NULL) {
            func_0204c108(wk->icons[index][i]);
            wk->icons[index][i] = NULL;
        }
        if (wk->iconCursors[index][i] != NULL) {
            func_0204c108(wk->iconCursors[index][i]);
            wk->iconCursors[index][i] = NULL;
        }
        if (wk->iconChars[index][i] != 0) {
            func_0204b98c(wk->iconChars[index][i]);
            wk->iconChars[index][i] = 0;
        }
    }
}

void func_ov194_021c368c(PokemonTradeWork *wk) {
    int i;

    func_ov194_021c57a8(wk);
    for (i = 0; i < ICON_COLUMNS; i++) {
        func_ov194_021c3614(wk, i);
    }
    if (wk->objRes[TRADE_OBJRES_PLTT_ICON] != 0) {
        func_0204bcd0(wk->objRes[TRADE_OBJRES_PLTT_ICON]);
        wk->objRes[TRADE_OBJRES_PLTT_ICON] = 0;
    }
    if (wk->objRes[TRADE_OBJRES_CELL_ICON] != 0) {
        func_0204be64(wk->objRes[TRADE_OBJRES_CELL_ICON]);
        wk->objRes[TRADE_OBJRES_CELL_ICON] = 0;
    }
    if (wk->iconCharData != NULL) {
        GFL_HeapFree(wk->iconCharData);
    }
    wk->iconCharData = NULL;
}

void func_ov194_021c36e4(PokemonTradeWork *wk) {
    int i;

    func_ov194_021c5e5c(wk);
    func_ov194_021c0aac(wk);
    for (i = 0; i < 10; i++) {
        if (wk->actors[i] != NULL) {
            func_0204c108(wk->actors[i]);
            wk->actors[i] = NULL;
        }
    }
    for (i = TRADE_OBJRES_PLTT; i < TRADE_OBJRES_CHAR; i++) {
        if (wk->objRes[i] != 0) {
            func_0204bcd0(wk->objRes[i]);
            wk->objRes[i] = 0;
        }
    }
    for (; i < TRADE_OBJRES_CELL; i++) {
        if (wk->objRes[i] != 0) {
            func_0204b98c(wk->objRes[i]);
            wk->objRes[i] = 0;
        }
    }
    for (; i < TRADE_OBJRES_COUNT; i++) {
        if (wk->objRes[i] != 0) {
            func_0204be64(wk->objRes[i]);
            wk->objRes[i] = 0;
        }
    }
}

static void func_ov194_021c3770(int column, int row, ClActorPos *pos) {
    pos->x = (column + 1) * 24;
    pos->y = row * 24 + 72;
}

// The Pokémon in a column's row of the strip, and whether it is in the party
static BoxPkm *func_ov194_021c3788(BoxSaveAccessor *boxes, int column, int row, PokemonTradeWork *wk, BOOL *isParty) {
    if (column >= PARTY_COLUMNS) {
        int box = PokemonTrade_GetColumnBox(column, wk);
        int slot = PokemonTrade_GetColumnSlot(column, row);

        *isParty = FALSE;
        return PokemonTrade_GetBoxPkm(boxes, box, slot, wk);
    }
    if (row < 3) {
        *isParty = TRUE;
        return PokemonTrade_GetBoxPkm(boxes, wk->boxCount, column + row * 2, wk);
    }
    return NULL;
}

static TradeBoxEntry *func_ov194_021c37e0(int column, int row, PokemonTradeWork *wk) {
    if (column >= PARTY_COLUMNS) {
        int box = PokemonTrade_GetColumnBox(column, wk);

        return PokemonTrade_GetBoxEntry(box, PokemonTrade_GetColumnSlot(column, row), wk);
    }
    if (row < 3) {
        return PokemonTrade_GetBoxEntry(wk->boxCount, column + row * 2, wk);
    }
    return NULL;
}

// Takes the place of the cursor shown under an icon as where the stylus is
void func_ov194_021c3820(PokemonTradeWork *wk) {
    int i, j;

    for (i = 0; i < COLUMN_ROWS; i++) {
        for (j = 0; j < ICON_COLUMNS; j++) {
            if (func_0204c138(wk->iconCursors[j][i])) {
                ClActorPos pos;

                func_0204c178(wk->iconCursors[j][i], &pos, CLACT_VRAM_SUB);
                wk->touchX = pos.x;
                wk->touchY = pos.y;
            }
        }
    }
}

// Whether a species has the initial searched for
static BOOL func_ov194_021c3888(PokemonTradeWork *wk, int species) {
    if (wk->unk800 != 0 && wk->unk800 - 1 == sSpeciesInitials[species]) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov194_021c38a8(u32 species, u32 initial) {
    if (initial == sSpeciesInitials[species]) {
        return TRUE;
    }
    return FALSE;
}

// Greys an icon out or not
void func_ov194_021c38bc(PokemonTradeWork *wk, ClActor *icon, BOOL grey) {
    func_0204c318(icon, grey ? 1 : 0);
}

static void func_ov194_021c38d4(PokemonTradeWork *wk, int column, int row, BoxPkm *pkm, BOOL isParty, int index) {
    BOOL grey = FALSE;

    if (func_ov194_021be3bc(wk, column, row)) {
        grey = TRUE;
    }
    func_ov194_021c38bc(wk, wk->icons[index][row], grey);
}

// Sets up the icons of a column of the strip in the icon column at an index, loading the characters of the ones that
// changed, in the V-blank if asked and the icon is on screen
static void func_ov194_021c3904(PokemonTradeWork *wk, BoxSaveAccessor *boxes, int column, int index, BOOL async) {
    int i;
    BoxPkm *pkm;
    TradeBoxEntry *entry;
    BOOL isParty;
    NNSG2dImageProxy proxy;
    ClActorPos pos;
    ClActorPos screenPos;

    if (column == wk->cursorColumn && !func_0203d554()) {
        func_0204c124(wk->iconCursors[index][wk->cursorRow], TRUE);
    }
    for (i = 0; i < COLUMN_ROWS; i++) {
        int species, form, sex;

        pkm = func_ov194_021c3788(boxes, column, i, wk, &isParty);
        entry = func_ov194_021c37e0(column, i, wk);
        if (entry == NULL) {
            wk->iconColumns[index][i] = 0xff;
            continue;
        }
        if (entry->species == SPECIES_NONE) {
            wk->iconColumns[index][i] = 0xff;
            continue;
        }
        wk->iconColumns[index][i] = column;
        form = entry->form;
        species = entry->species;
        sex = entry->sex;
        if (species == wk->iconSpecies[index][i] && form == wk->iconForms[index][i] && sex == wk->iconSexes[index][i]) {
            func_0204c124(wk->icons[index][i], TRUE);
            func_ov194_021c38d4(wk, column, i, pkm, isParty, index);
        } else if (species != wk->iconSpecies[index][i] ||
                   (species == wk->iconSpecies[index][i] && form != wk->iconForms[index][i]) ||
                   (species == wk->iconSpecies[index][i] && sex != wk->iconSexes[index][i])) {
            int box, slot;

            wk->iconSpecies[index][i] = species;
            wk->iconForms[index][i] = form;
            wk->iconSexes[index][i] = sex;
            func_ov194_021c3770(column, i, &pos);
            func_0204c40c(wk->icons[index][i], &proxy);
            box = PokemonTrade_GetColumnBox(column, wk);
            slot = PokemonTrade_GetColumnSlot(column, i);
            slot += box * 30;
            func_0204c178(wk->icons[index][i], &screenPos, CLACT_VRAM_SUB);
            if (async == TRUE && screenPos.x >= -16 && screenPos.x <= 272) {
                if (!gfxUploadAsync(35, proxy.vramLocation.baseAddrOfVram[NNS_G2D_VRAM_TYPE_2DSUB],
                                    wk->iconCharData + slot * 0x200, 0x200)) {
                    sys_memcpy(wk->iconCharData + slot * 0x200,
                               (void *)(HW_DB_OBJ_VRAM + proxy.vramLocation.baseAddrOfVram[NNS_G2D_VRAM_TYPE_2DSUB]),
                               0x200);
                }
            } else {
                sys_memcpy(wk->iconCharData + slot * 0x200,
                           (void *)(HW_DB_OBJ_VRAM + proxy.vramLocation.baseAddrOfVram[NNS_G2D_VRAM_TYPE_2DSUB]),
                           0x200);
            }
            func_ov194_021c38d4(wk, column, i, pkm, isParty, index);
            func_0204c378(wk->icons[index][i], func_020210c0(pkm), CLACT_VRAM_SUB);
            func_0204c520(wk->icons[index][i], FALSE);
            func_0204c124(wk->icons[index][i], TRUE);
        }
        if (!PML_PkmGetParam(pkm, PKM_PARAM_IS_EGG, NULL) && func_ov194_021c3888(wk, species)) {
            wk->iconMarked[index][i] = TRUE;
        }
    }
}

// The column of the strip at the left edge of the screen
int func_ov194_021c3bc0(PokemonTradeWork *wk) {
    int x = wk->scrollX;
    int column;

    if (x < 48) {
        column = 0;
    } else if (x < 96) {
        column = 1;
    } else {
        int box, offset;
        int boxesX = x - 96;

        box = boxesX / 160;
        offset = boxesX - box * 160;
        column = box * BOX_COLUMNS + PARTY_COLUMNS;
        if (offset >= 8) {
            if (offset >= 152) {
                column += BOX_COLUMNS - 1;
            } else {
                column += (offset - 8) / 24;
            }
        }
    }
    return column;
}

// Whether the cursor's column is on screen, and the third column on screen, where the cursor goes if not
BOOL func_ov194_021c3c10(PokemonTradeWork *wk, int *column) {
    int first = func_ov194_021c3bc0(wk);
    int last = first + 10;

    *column = first + 2;
    if (first + 2 >= wk->columnCount) {
        *column = first + 2 - wk->columnCount;
    }
    if (last >= wk->columnCount) {
        int cursor = wk->cursorColumn;

        if (cursor < 20) {
            cursor = cursor + 1 + wk->columnCount;
        }
        if (first <= cursor && cursor <= last) {
            return TRUE;
        }
    } else if (first <= wk->cursorColumn && wk->cursorColumn <= last) {
        return TRUE;
    }
    return FALSE;
}

// Sets up the icons for the strip's scroll when the columns on screen changed, and places them
void func_ov194_021c3c68(BoxSaveAccessor *boxes, PokemonTradeWork *wk, BOOL async) {
    int i, j;
    int column = func_ov194_021c3bc0(wk);

    if (wk->firstColumn != column) {
        wk->firstColumn = column;
        for (i = 0; i < ICON_COLUMNS; i++) {
            for (j = 0; j < COLUMN_ROWS; j++) {
                func_0204c124(wk->iconCursors[i][j], FALSE);
                wk->iconMarked[i][j] = FALSE;
            }
        }
        wk->unk1090 = column;
        func_ov194_021c3f68(wk);
        for (i = 0; i < ICON_COLUMNS; i++) {
            func_ov194_021c3904(wk, boxes, column, func_ov194_021c3f5c(wk->firstColumn + i), async);
            column++;
            if (column >= wk->columnCount) {
                column = 0;
            }
        }
    }
    func_ov194_021c3d2c(wk);
}

// Places the icons and their cursors where their columns are at the strip's scroll, lifting the one the cursor is on
static void func_ov194_021c3d2c(PokemonTradeWork *wk) {
    int i, j;
    int wrap = 0;
    int column = wk->firstColumn;

    for (i = 0; i < ICON_COLUMNS; i++) {
        int index = func_ov194_021c3f5c(wk->firstColumn + i);

        if (column >= wk->columnCount) {
            column -= wk->columnCount;
            wrap = wk->stripWidth;
        }
        for (j = 0; j < COLUMN_ROWS; j++) {
            int y = j * 24 + 32;
            int x;
            ClActorPos pos, markPos;

            if (column == 0) {
                x = 28;
            } else if (column == 1) {
                x = 60;
            } else {
                x = (column - PARTY_COLUMNS) / BOX_COLUMNS * 160;
                x += (column - PARTY_COLUMNS) % BOX_COLUMNS * 24 + 20;
                x += 96;
            }
            pos.x = wrap + (x - wk->scrollX);
            pos.y = y;
            markPos = pos;
            if (func_ov194_021be45c(wk, column, j) && func_0203d554() == TRUE) {
                pos.y -= 8;
                func_0204c438(wk->icons[index][j], 11);
            } else {
                func_0204c438(wk->icons[index][j], 28 - i);
            }
            func_0204c140(wk->icons[index][j], &pos, CLACT_VRAM_SUB);
            if (wk->iconMarked[index][j]) {
                wk->iconPos[index][j] = markPos;
            }
            pos.y = y + 3;
            func_0204c140(wk->iconCursors[index][j], &pos, CLACT_VRAM_SUB);
        }
        column++;
    }
}
