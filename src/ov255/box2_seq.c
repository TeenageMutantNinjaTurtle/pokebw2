#include "types.h"
#include "app/box2_seq.h"
#include "app/box2_bgwfrm.h"
#include "app/box2_bmp.h"
#include "app/box2_main.h"
#include "app/box2_obj.h"
#include "app/box2_ui.h"
#include "app/ov139.h"
#include "constants/arc.h"
#include "constants/sound.h"
#include "gfl/arc.h"
#include "gfl/graphics.h"
#include "gfl/gx_layers.h"
#include "gfl/heap.h"
#include "gfl/key.h"
#include "gfl/net.h"
#include "gfl/overlay.h"
#include "gfl/sound.h"
#include "gfl/touchpanel.h"
#include "gfl/ui.h"
#include "gfl/wipe.h"
#include "nitro/gx.h"
#include "nitro/math.h"
#include "constants/pokemon.h"
#include "pml/poke_party.h"
#include "system/app_taskmenu.h"
#include "system/cursor_move.h"
#include "system/printsys.h"

// The PC box's sequences: one function per state of the box, run each frame by Box2Seq_Main, each returning the
// next state. Names are ours

typedef int (*Box2SeqFunc)(Box2SysWork *syswk);

// What the yes/no menu's answers run, by the question asked
typedef struct {
    Box2SeqFunc yes;
    Box2SeqFunc no;
} Box2YesNoFuncs;

// The sub procs, with the state after each
typedef struct {
    Box2SeqFunc call;
    Box2SeqFunc exit;
    int nextSeq;
} Box2SubProc;

static int Box2Seq_Init(Box2SysWork *syswk);
static int Box2Seq_Release(Box2SysWork *syswk);
static int Box2Seq_Wipe(Box2SysWork *syswk);
static int Box2Seq_PaletteFade(Box2SysWork *syswk);
static int Box2Seq_Wait(Box2SysWork *syswk);
static int Box2Seq_VFunc(Box2SysWork *syswk);
static int Box2Seq_TrgWait(Box2SysWork *syswk);
static int Box2Seq_YesNo(Box2SysWork *syswk);
static int Box2Seq_ButtonAnm(Box2SysWork *syswk);
static int Box2Seq_SubProcCall(Box2SysWork *syswk);
static int Box2Seq_SubProcMain(Box2SysWork *syswk);
static int Box2Seq_Start(Box2SysWork *syswk);
static int Box2Seq_StartWait(Box2SysWork *syswk);
static int func_ov255_021c2d6c(Box2SysWork *syswk);
static int func_ov255_021c2dc0(Box2SysWork *syswk);
static int func_ov255_021c2f78(Box2SysWork *syswk);
static int func_ov255_021c30f0(Box2SysWork *syswk);
static int func_ov255_021c30f8(Box2SysWork *syswk);
static int func_ov255_021c366c(Box2SysWork *syswk);
static int func_ov255_021c36c0(Box2SysWork *syswk);
static int func_ov255_021c3700(Box2SysWork *syswk);
static int func_ov255_021c385c(Box2SysWork *syswk);
static int func_ov255_021c3ec8(Box2SysWork *syswk);
static int func_ov255_021c3fc0(Box2SysWork *syswk);
static int func_ov255_021c41e8(Box2SysWork *syswk);
static int func_ov255_021c4258(Box2SysWork *syswk);
static int func_ov255_021c4328(Box2SysWork *syswk);
static int func_ov255_021c445c(Box2SysWork *syswk);
static int func_ov255_021c4da4(Box2SysWork *syswk);
static int func_ov255_021c4ea0(Box2SysWork *syswk);
static int func_ov255_021c50d0(Box2SysWork *syswk);
static int func_ov255_021c5140(Box2SysWork *syswk);
static int func_ov255_021c522c(Box2SysWork *syswk);
static int func_ov255_021c53f4(Box2SysWork *syswk);
static int func_ov255_021c5d9c(Box2SysWork *syswk);
static int func_ov255_021c5ef4(Box2SysWork *syswk);
static int func_ov255_021c5f94(Box2SysWork *syswk);
static int func_ov255_021c6058(Box2SysWork *syswk);
static int func_ov255_021c64fc(Box2SysWork *syswk);
static int func_ov255_021c65a4(Box2SysWork *syswk);
static int func_ov255_021c65e4(Box2SysWork *syswk);
static int func_ov255_021c6644(Box2SysWork *syswk);
static int func_ov255_021c686c(Box2SysWork *syswk);
static int func_ov255_021c6de0(Box2SysWork *syswk);
static int func_ov255_021c6f34(Box2SysWork *syswk);
static int func_ov255_021c6fd4(Box2SysWork *syswk);
static int func_ov255_021c74fc(Box2SysWork *syswk);
static int func_ov255_021c7554(Box2SysWork *syswk);
static int func_ov255_021c7594(Box2SysWork *syswk);
static int func_ov255_021c762c(Box2SysWork *syswk);
static int func_ov255_021c7a88(Box2SysWork *syswk);
static int func_ov255_021c7b0c(Box2SysWork *syswk);
static int func_ov255_021c7b4c(Box2SysWork *syswk);
static int func_ov255_021c7b98(Box2SysWork *syswk);
static int func_ov255_021c7c10(Box2SysWork *syswk);
static int func_ov255_021c8024(Box2SysWork *syswk);
static int func_ov255_021c8060(Box2SysWork *syswk);
static int func_ov255_021c80ec(Box2SysWork *syswk);
static int func_ov255_021c81d8(Box2SysWork *syswk);
static int func_ov255_021c8238(Box2SysWork *syswk);
static int func_ov255_021c8594(Box2SysWork *syswk);
static int func_ov255_021c85d0(Box2SysWork *syswk);
static int func_ov255_021c8608(Box2SysWork *syswk);
static int func_ov255_021c8798(Box2SysWork *syswk);
static int func_ov255_021c8920(Box2SysWork *syswk);
static int func_ov255_021c8a9c(Box2SysWork *syswk);
static int func_ov255_021c8ad0(Box2SysWork *syswk);
static int func_ov255_021c8b38(Box2SysWork *syswk);
static int func_ov255_021c8fc4(Box2SysWork *syswk);
static int func_ov255_021c9004(Box2SysWork *syswk);
static int func_ov255_021c907c(Box2SysWork *syswk);
static int func_ov255_021c90b8(Box2SysWork *syswk);
static int func_ov255_021c9120(Box2SysWork *syswk);
static int func_ov255_021c9160(Box2SysWork *syswk);
static int func_ov255_021c9338(Box2SysWork *syswk);
static int func_ov255_021c96b8(Box2SysWork *syswk);
static int func_ov255_021c97c8(Box2SysWork *syswk);
static int func_ov255_021c99a8(Box2SysWork *syswk);
static int func_ov255_021c9a44(Box2SysWork *syswk);
static int func_ov255_021c9a70(Box2SysWork *syswk);
static int func_ov255_021c9c34(Box2SysWork *syswk);
static int func_ov255_021c9ffc(Box2SysWork *syswk);
static int func_ov255_021ca03c(Box2SysWork *syswk);
static int func_ov255_021ca194(Box2SysWork *syswk);
static int func_ov255_021ca314(Box2SysWork *syswk);
static int func_ov255_021ca3b4(Box2SysWork *syswk);
static int func_ov255_021ca6c8(Box2SysWork *syswk);
static int func_ov255_021ca6d8(Box2SysWork *syswk);
static int func_ov255_021ca79c(Box2SysWork *syswk);
static int func_ov255_021ca7d8(Box2SysWork *syswk);
static int func_ov255_021ca7e4(Box2SysWork *syswk);
static int func_ov255_021ca9a4(Box2SysWork *syswk);
static int func_ov255_021ca9b0(Box2SysWork *syswk);
static int func_ov255_021caa30(Box2SysWork *syswk);
static int func_ov255_021caadc(Box2SysWork *syswk);
static int func_ov255_021cab14(Box2SysWork *syswk);
static int func_ov255_021cab94(Box2SysWork *syswk);
static int func_ov255_021cabbc(Box2SysWork *syswk);
static int func_ov255_021cacac(Box2SysWork *syswk);
static int func_ov255_021cadcc(Box2SysWork *syswk);
static int func_ov255_021cae74(Box2SysWork *syswk);
static int func_ov255_021cae84(Box2SysWork *syswk);
static int func_ov255_021cb020(Box2SysWork *syswk);
static int func_ov255_021cb068(Box2SysWork *syswk);
static int func_ov255_021cb1d8(Box2SysWork *syswk);
static int func_ov255_021cb258(Box2SysWork *syswk);
static int func_ov255_021cb3a0(Box2SysWork *syswk);
static int func_ov255_021cb488(Box2SysWork *syswk);
static int func_ov255_021cb5b0(Box2SysWork *syswk);
static int func_ov255_021cb67c(Box2SysWork *syswk);
static int func_ov255_021cb82c(Box2SysWork *syswk);
static int func_ov255_021cb960(Box2SysWork *syswk);
static int func_ov255_021cb97c(Box2SysWork *syswk);
static int func_ov255_021cbb00(Box2SysWork *syswk);
static int func_ov255_021cbd2c(Box2SysWork *syswk);
static int func_ov255_021cbe1c(Box2SysWork *syswk);
static int func_ov255_021cbe28(Box2SysWork *syswk);
static int func_ov255_021cbf18(Box2SysWork *syswk);
static int func_ov255_021cbfe8(Box2SysWork *syswk);
static int func_ov255_021cc040(Box2SysWork *syswk);
static int func_ov255_021cc0b4(Box2SysWork *syswk);
static int func_ov255_021cc198(Box2SysWork *syswk);
static int func_ov255_021cc1bc(Box2SysWork *syswk);
static int func_ov255_021cc308(Box2SysWork *syswk);
static int func_ov255_021cc330(Box2SysWork *syswk);
static int func_ov255_021cc380(Box2SysWork *syswk);


static int func_ov255_021cbe58(Box2SysWork *syswk, int seq);
static int func_ov255_021cbed8(Box2SysWork *syswk, int seq);
static int func_ov255_021cbee8(Box2SysWork *syswk, int seq);
static int func_ov255_021cc3b0(Box2SysWork *syswk, u32 a1, int seq);
static int func_ov255_021cc460(Box2SysWork *syswk, u32 a1, u32 a2, int seq);
static int func_ov255_021ccf1c(Box2SysWork *syswk, u32 a1, int seq);
static int func_ov255_021ccf68(Box2SysWork *syswk, u32 a1, int seq);
static int func_ov255_021ccfb4(Box2SysWork *syswk, u32 pos);
static int func_ov255_021cd128(Box2SysWork *syswk, u32 pos, int seq);
static int func_ov255_021cd458(Box2SysWork *syswk, u32 pos);
static void func_ov255_021cd5d8(Box2SysWork *syswk);
static int func_ov255_021cdc38(Box2SysWork *syswk, int seq);
static int func_ov255_021cddf0(Box2SysWork *syswk, int seq);
static int func_ov255_021cde88(Box2SysWork *syswk, int seq);

static int func_ov255_021cd32c(Box2SysWork *syswk, u32 pos, int seq);
static int func_ov255_021cd4b8(Box2SysWork *syswk, u32 pos, int seq);
static int func_ov255_021cdba4(Box2SysWork *syswk, int seq);
static void func_ov255_021cdc04(Box2SysWork *syswk);
static int func_ov255_021cdc54(Box2SysWork *syswk, int seq);
static int func_ov255_021cd390(Box2SysWork *syswk, int seq);
static int func_ov255_021cd494(Box2SysWork *syswk, u32 pos, int seq);
static int func_ov255_021cd52c(Box2SysWork *syswk, u32 pos, int seq);
static void func_ov255_021cded4(Box2SysWork *syswk);
static void func_ov255_021cdef8(Box2SysWork *syswk);
static const Box2MenuItem sMenu70cc[] = { { 83, 0 }, { 80, 1 } };
static const Box2MenuItem sMenu70f8[] = { { 82, 0 }, { 74, 0 }, { 75, 0 }, { 80, 1 } };
static const Box2MenuItem sMenu7130[] = { { 79, 0 }, { 74, 0 }, { 76, 0 }, { 77, 0 }, { 80, 1 } };
static const Box2MenuItem sMenu7194[] = { { 78, 0 }, { 74, 0 }, { 76, 0 }, { 77, 0 }, { 80, 1 } };
static const Box2MenuItem sMenu71f0[] = { { 81, 0 }, { 74, 0 }, { 75, 0 }, { 76, 0 }, { 77, 0 }, { 80, 1 } };

static const Box2SubProc sSubProcs[] = {
    { Box2Main_PokeStatusCall, Box2Main_PokeStatusExit, 92 },
    { Box2Main_BagCall, Box2Main_BagExit, 94 },
    { Box2Main_NameInCall, Box2Main_NameInExit, 93 },
    { Box2Main_BoxSearchCall, Box2Main_BoxSearchExit, 95 },
};

static const Box2SeqFunc sMainSeq[] = {
    Box2Seq_Init, Box2Seq_Release, Box2Seq_Wipe,
    Box2Seq_PaletteFade, Box2Seq_Wait, Box2Seq_VFunc,
    Box2Seq_TrgWait, Box2Seq_YesNo, Box2Seq_ButtonAnm,
    Box2Seq_SubProcCall, Box2Seq_SubProcMain, Box2Seq_Start,
    Box2Seq_StartWait, func_ov255_021c2d6c, func_ov255_021c2dc0,
    func_ov255_021c2f78, func_ov255_021c30f0, func_ov255_021c30f8,
    func_ov255_021c366c, func_ov255_021c36c0, func_ov255_021c3700,
    func_ov255_021c385c, func_ov255_021c3ec8, func_ov255_021c3fc0,
    func_ov255_021c41e8, func_ov255_021c4258, func_ov255_021c5f94,
    func_ov255_021c6058, func_ov255_021c64fc, func_ov255_021c65a4,
    func_ov255_021c65e4, func_ov255_021c6644, func_ov255_021c686c,
    func_ov255_021c6de0, func_ov255_021c6f34, func_ov255_021c4328,
    func_ov255_021c445c, func_ov255_021c4da4, func_ov255_021c4ea0,
    func_ov255_021c50d0, func_ov255_021c5140, func_ov255_021c522c,
    func_ov255_021c53f4, func_ov255_021c5d9c, func_ov255_021c5ef4,
    func_ov255_021c6fd4, func_ov255_021c74fc, func_ov255_021c7554,
    func_ov255_021c7594, func_ov255_021c762c, func_ov255_021c7a88,
    func_ov255_021c7b0c, func_ov255_021c7b4c, func_ov255_021c7b98,
    func_ov255_021c7c10, func_ov255_021c8024, func_ov255_021c8060,
    func_ov255_021c80ec, func_ov255_021c81d8, func_ov255_021c8238,
    func_ov255_021c8594, func_ov255_021c85d0, func_ov255_021c8608,
    func_ov255_021c8798, func_ov255_021c8920, func_ov255_021c8a9c,
    func_ov255_021c8ad0, func_ov255_021c8b38, func_ov255_021c8fc4,
    func_ov255_021c9004, func_ov255_021c907c, func_ov255_021c90b8,
    func_ov255_021c9120, func_ov255_021c9160, func_ov255_021c9338,
    func_ov255_021c96b8, func_ov255_021c97c8, func_ov255_021c99a8,
    func_ov255_021c9a44, func_ov255_021c9a70, func_ov255_021c9c34,
    func_ov255_021c9ffc, func_ov255_021ca03c, func_ov255_021ca194,
    func_ov255_021ca314, func_ov255_021ca3b4, func_ov255_021ca6c8,
    func_ov255_021ca6d8, func_ov255_021ca79c, func_ov255_021ca7d8,
    func_ov255_021ca7e4, func_ov255_021ca9a4, func_ov255_021ca9b0,
    func_ov255_021caa30, func_ov255_021caadc, func_ov255_021cab14,
    func_ov255_021cab94, func_ov255_021cabbc, func_ov255_021cacac,
    func_ov255_021cadcc, func_ov255_021cae74, func_ov255_021cae84,
    func_ov255_021cb020, func_ov255_021cb068, func_ov255_021cb1d8,
    func_ov255_021cb258, func_ov255_021cb3a0, func_ov255_021cb488,
    func_ov255_021cb5b0, func_ov255_021cb67c, func_ov255_021cb82c,
    func_ov255_021cb960, func_ov255_021cb97c, func_ov255_021cbb00,
    func_ov255_021cbd2c, func_ov255_021cbe1c, func_ov255_021cbe28,
};

static const Box2YesNoFuncs sYesNoFuncs[] = {
    { func_ov255_021cbf18, func_ov255_021cc380 },
    { func_ov255_021cbfe8, func_ov255_021cc040 },
    { func_ov255_021cc0b4, func_ov255_021cc380 },
    { func_ov255_021cc198, func_ov255_021cc1bc },
    { func_ov255_021cc1bc, func_ov255_021cc198 },
    { func_ov255_021cc308, func_ov255_021cc330 },
};

BOOL Box2Seq_Main(Box2SysWork *syswk, u32 *seq) {
    if (syswk->app == NULL || syswk->app->printQueue == NULL || func_02021c0c(syswk->app->printQueue) != FALSE) {
        if (syswk->app != NULL) {
            func_ov255_021ced6c(syswk);
        }
        *seq = sMainSeq[*seq](syswk);
    }
    if (*seq == BOX2SEQ_END) {
        return FALSE;
    }
    if (syswk->app != NULL) {
        func_ov255_021cdfe8(syswk->app);
        func_ov255_021cf5b0(syswk->app);
        func_ov255_021d1e38(syswk);
    }
    return TRUE;
}

static int Box2Seq_Init(Box2SysWork *syswk) {
    GFL_OvlLoad(OVERLAY_139);
    GFL_BGSysSetEnabledBGsA(0);
    GFL_BGSysSetEnabledBGsB(0);
    G2_BlendNone();
    G2S_BlendNone();
    GFL_BGSysSetDisplayLayout(0);
    GFL_HeapCreateChild(HEAPID_USER, HEAPID_BOX2_APP, 0x80000);
    syswk->app = GFL_HeapAllocate(HEAPID_BOX2_APP, sizeof(Box2AppWork), TRUE, "box2_seq.c", 737);
    syswk->app->pokeIconArc = GFL_ArcSysCreateFileHandle(ARCID_POKEICON, HEAPID_BOX2_APP);
    GCTX_HIDGetRepeat(&syswk->app->keyRepeatWait, &syswk->app->keyRepeatStart);
    setKeypressFramecounts(6, 6);
    Box2Main_InitVramBanks();
    Box2Main_InitBg(syswk);
    Box2Main_InitPaletteFade(syswk);
    Box2Main_LoadBgGraphics(syswk);
    Box2Main_InitMsg(syswk);
    Box2Main_InitDexData(syswk);
    func_ov255_021cdf18(syswk);
    func_ov255_021cf3c0(syswk);
    func_ov255_021cfc74(syswk);
    func_ov255_021cfc90(syswk);
    Box2Main_WallPaperSet(syswk, Box2Main_GetWallPaperNumber(syswk, syswk->tray), BOX2_TRAY_SCROLL_NONE);
    func_ov255_021d364c(syswk);
    func_ov255_021ce140(syswk);
    func_ov255_021ce198(syswk);
    func_ov255_021d15dc(syswk);
    func_ov255_021d23d8(syswk);
    Box2Main_InitYesNo(syswk);
    Box2Main_SetBlendAlpha(TRUE);
    func_02042ba8(TRUE, HEAPID_BOX2_APP);
    Box2Main_InitVBlank(syswk);
    return syswk->nextSeq;
}

static int Box2Seq_Release(Box2SysWork *syswk) {
    Box2Main_ExitVBlank(syswk);
    Box2Main_ExitYesNo(syswk);
    func_ov255_021d24e0(syswk);
    func_ov255_021d36e8(syswk->app);
    func_ov255_021cf414(syswk->app);
    func_ov255_021cdf5c(syswk);
    Box2Main_ExitDexData(syswk);
    Box2Main_ExitMsg(syswk);
    Box2Main_ExitPaletteFade(syswk);
    Box2Main_ExitBg(syswk);
    setKeypressFramecounts(syswk->app->keyRepeatWait, syswk->app->keyRepeatStart);
    GFL_ArcToolFree(syswk->app->pokeIconArc);
    GFL_HeapFree(syswk->app);
    GFL_HeapDelete(HEAPID_BOX2_APP);
    syswk->app = NULL;
    G2_BlendNone();
    G2S_BlendNone();
    GFL_BGSysSetEnabledBGsA(0);
    GFL_BGSysSetEnabledBGsB(0);
    GFL_OvlUnload(OVERLAY_139);
    return syswk->nextSeq;
}

static int Box2Seq_Wipe(Box2SysWork *syswk) {
    if (GFL_WipeIsFinished() == TRUE) {
        return syswk->app->wipeSeq;
    }
    return BOX2SEQ_WIPE;
}

static int Box2Seq_PaletteFade(Box2SysWork *syswk) {
    if (func_02027780(syswk->app->palFade) == FALSE) {
        return syswk->nextSeq;
    }
    return BOX2SEQ_PALETTE_FADE;
}

static int Box2Seq_Wait(Box2SysWork *syswk) {
    if (syswk->app->wait == 0) {
        return syswk->nextSeq;
    }
    syswk->app->wait--;
    return BOX2SEQ_WAIT;
}

static int Box2Seq_VFunc(Box2SysWork *syswk) {
    if (syswk->app->vfunk.func != NULL && syswk->app->vfunk.func(syswk) == FALSE) {
        syswk->app->vfunk.func = NULL;
        return syswk->app->vfuncNextSeq;
    }
    return BOX2SEQ_VFUNC;
}

static int Box2Seq_TrgWait(Box2SysWork *syswk) {
    if (func_0203da48() == TRUE) {
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        func_0203d564(TRUE);
        return syswk->nextSeq;
    }
    if (GCTX_HIDGetPressedKeys() & (PAD_BUTTON_A | PAD_BUTTON_B)) {
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        func_0203d564(FALSE);
        return syswk->nextSeq;
    }
    return BOX2SEQ_TRGWAIT;
}

static int Box2Seq_YesNo(Box2SysWork *syswk) {
    u32 sel;

    func_0202db70(syswk->app->yesNoMenu);
    if (func_0202dbe4(syswk->app->yesNoMenu) == TRUE) {
        sel = func_0202dc00(syswk->app->yesNoMenu);
        func_0202da54(syswk->app->yesNoMenu);
        setKeypressFramecounts(6, 6);
        if (sel == 0) {
            return sYesNoFuncs[syswk->app->ynID].yes(syswk);
        }
        return sYesNoFuncs[syswk->app->ynID].no(syswk);
    }
    return BOX2SEQ_YESNO;
}

static int Box2Seq_ButtonAnm(Box2SysWork *syswk) {
    if (Box2Main_ButtonAnmMain(syswk) == FALSE) {
        return syswk->nextSeq;
    }
    return BOX2SEQ_BUTTON_ANM;
}

static int Box2Seq_SubProcCall(Box2SysWork *syswk) {
    sSubProcs[syswk->subProcType].call(syswk);
    return BOX2SEQ_SUBPROC_MAIN;
}

static int Box2Seq_SubProcMain(Box2SysWork *syswk) {
    if (syswk->procMgrResult != TRUE) {
        sSubProcs[syswk->subProcType].exit(syswk);
        syswk->nextSeq = sSubProcs[syswk->subProcType].nextSeq;
        return BOX2SEQ_INIT;
    }
    return BOX2SEQ_SUBPROC_MAIN;
}

static int Box2Seq_Start(Box2SysWork *syswk) {
    GFL_SndSEPlay(SEQ_SE_PC_LOGIN);
    switch (syswk->param->mode) {
    case 0:
        func_ov255_021cdb90(syswk);
        func_ov255_021d1348(syswk->app, 0);
        func_ov255_021d0310(syswk, 1, 1);
        Box2Main_PokeInfoPut(syswk, BOX2_PARTY_POS);
        syswk->app->msgNextSeq = 59;
        break;
    case 1:
        Box2Main_PokeInfoPut(syswk, 0);
        syswk->app->msgNextSeq = 54;
        break;
    case 2:
        Box2Main_PokeInfoPut(syswk, 0);
        func_ov255_021d3a48(syswk->app);
        syswk->app->msgNextSeq = 17;
        break;
    case 3:
        func_ov255_021d0310(syswk, 0x81, 1);
        Box2Main_PokeInfoPut(syswk, 0);
        func_ov255_021d3a48(syswk->app);
        syswk->app->msgNextSeq = 67;
        break;
    case 4:
        if (PokeParty_GetPkmCount(syswk->param->party) == 0) {
            func_ov255_021d3a48(syswk->app);
            Box2Main_PokeInfoPut(syswk, 0);
            func_ov255_021d2478(syswk, 13, 0);
            syswk->app->msgNextSeq = 45;
        } else {
            func_ov255_021cdb90(syswk);
            func_ov255_021d1348(syswk->app, 0);
            func_ov255_021d0310(syswk, 1, 1);
            func_ov255_021d3a64(syswk->app);
            Box2Main_PokeInfoPut(syswk, BOX2_PARTY_POS);
            func_ov255_021d2478(syswk, 14, 0);
            syswk->app->msgNextSeq = 49;
        }
        break;
    case 5:
        Box2Main_PokeInfoPut(syswk, 0);
        func_ov255_021d0310(syswk, 0x81, 1);
        func_ov255_021d1af8(syswk, 0, 1, 1, 1);
        syswk->app->msgNextSeq = 85;
        break;
    }
    return Box2Seq_StartWait(syswk);
}

static int Box2Seq_StartWait(Box2SysWork *syswk) {
    if (func_02021c0c(syswk->app->printQueue) == FALSE) {
        return BOX2SEQ_START_WAIT;
    }
    return func_ov255_021cbe68(syswk, syswk->app->msgNextSeq);
}

static int func_ov255_021c2d6c(Box2SysWork *syswk) {
    GFL_HeapFree(syswk->app->vfunk.work);
    if (syswk->app->unkA552 == 1) {
        if (syswk->param->mode == 3) {
            if (syswk->app->getItem == 0) {
                func_ov255_021cf208(syswk, 0, 24);
            } else {
                func_ov255_021cf208(syswk, 1, 24);
            }
        } else {
            func_ov255_021cf1ac(syswk, syswk->pos, 1, 24);
        }
        syswk->app->unkA552 = 0;
    }
    return syswk->nextSeq;
}

static int func_ov255_021c2dc0(Box2SysWork *syswk) {
    switch (syswk->app->subSeq) {
    case 0:
        switch (syswk->param->mode) {
        case 1:
            func_ov255_021ceed0(syswk, sMenu7194, 5);
            break;
        case 0:
            func_ov255_021ceed0(syswk, sMenu7130, 5);
            break;
        case 2:
            func_ov255_021ceed0(syswk, sMenu71f0, 6);
            break;
        case 3:
            func_ov255_021cdc74(syswk, syswk->app->getItem);
            break;
        case 4:
            func_ov255_021ceed0(syswk, sMenu70f8, 4);
            break;
        case 5:
            func_ov255_021cefa4(syswk->app, 27);
            func_ov255_021ceed0(syswk, sMenu70cc, 2);
            break;
        }
        if (syswk->app->unkA550 == 1) {
            syswk->app->unkA550 = 0;
            if (syswk->param->mode == 3) {
                if (syswk->pos >= BOX2_PARTY_POS) {
                    func_ov255_021d0310(syswk, 0x82, 0);
                } else {
                    func_ov255_021d1348(syswk->app, 1);
                    func_ov255_021d0310(syswk, 0x81, 0);
                }
            } else if (syswk->pos >= BOX2_PARTY_POS) {
                func_ov255_021d0310(syswk, 2, 0);
            } else {
                func_ov255_021d1348(syswk->app, 1);
                func_ov255_021d0310(syswk, 1, 0);
            }
        }
        func_ov255_021d390c(syswk->app->bgWinFrame);
        syswk->app->subSeq++;
        return func_ov255_021cbec8(syswk, Box2Main_VFuncFrameMove, 14);
    case 1:
        syswk->app->subSeq = 0;
        func_ov255_021d101c(syswk, 1);
        func_ov255_021d0f88(syswk, 9, 1);
        switch (syswk->param->mode) {
        case 1:
            func_ov255_021cf1ac(syswk, syswk->pos, 1, 24);
            return 54;
        case 0:
            func_ov255_021cf1ac(syswk, syswk->pos, 1, 24);
            return 59;
        case 2:
            func_ov255_021cf1ac(syswk, syswk->pos, 1, 24);
            if (syswk->pos < BOX2_PARTY_POS) {
                return 17;
            }
            return 27;
        case 3:
            if (syswk->app->getItem == 0) {
                func_ov255_021cf208(syswk, 0, 24);
            } else {
                func_ov255_021cf208(syswk, 1, 24);
            }
            if (syswk->pos < BOX2_PARTY_POS) {
                return 67;
            }
            return 80;
        case 4:
            func_ov255_021cf1ac(syswk, syswk->pos, 1, 24);
            if (syswk->pos < BOX2_PARTY_POS) {
                return 45;
            }
            return 49;
        case 5:
            func_ov255_021cf1ac(syswk, syswk->pos, 1, 24);
            return 85;
        }
    }
    return 14;
}

// Scrolls the box list by touch
static int func_ov255_021c2f78(Box2SysWork *syswk) {
    u32 x, y;
    Box2BoxListDrag *work;
    u32 oldY;
    int diff;

    if (func_ov255_021d357c(&x, &y) == FALSE) {
        int pos;

        GFL_HeapFree(syswk->app->subWork);
        pos = func_ov255_021d35a4(syswk->app->tpx, syswk->app->tpy);
        if (pos >= 0) {
            func_ov255_021d1ac8(syswk, pos, 1);
        }
        return syswk->nextSeq;
    }
    work = syswk->app->subWork;
    oldY = syswk->app->tpy;
    syswk->app->tpy = y;
    diff = oldY - y;
    if (MATH_ABS(diff) >= 3) {
        work->cnt = MATH_ABS(diff) / 8;
        if (y < oldY) {
            work->dir = 1;
            func_ov255_021bc09c(syswk, 1);
            GFL_SndSEPlay(SEQ_SE_SELECT1);
            if (syswk->nextSeq == 21) {
                return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxListScrollLeft, 15);
            }
            return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxMoveScrollLeft, 15);
        }
        if (y > oldY) {
            work->dir = -1;
            func_ov255_021bc09c(syswk, -1);
            GFL_SndSEPlay(SEQ_SE_SELECT1);
            if (syswk->nextSeq == 21) {
                return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxListScrollRight, 15);
            }
            return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxMoveScrollRight, 15);
        }
    }
    if (work->cnt != 0) {
        work->cnt--;
        if (work->dir == 1) {
            func_ov255_021bc09c(syswk, 1);
            GFL_SndSEPlay(SEQ_SE_SELECT1);
            if (syswk->nextSeq == 21) {
                return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxListScrollLeft, 15);
            }
            return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxMoveScrollLeft, 15);
        }
        if (work->dir == -1) {
            func_ov255_021bc09c(syswk, -1);
            GFL_SndSEPlay(SEQ_SE_SELECT1);
            if (syswk->nextSeq == 21) {
                return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxListScrollRight, 15);
            }
            return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxMoveScrollRight, 15);
        }
    }
    return 15;
}

static int func_ov255_021c30f0(Box2SysWork *syswk) {
    return func_ov255_021cc198(syswk);
}

// The arrangement's main state: waits for a touch or for the cursor to pick something
static int func_ov255_021c30f8(Box2SysWork *syswk) {
    u32 res;

    if (GCTX_HIDGetPressedKeys() & PAD_BUTTON_SELECT) {
        syswk->unk1B = 0;
        return func_ov255_021cddf0(syswk, 20);
    }
    if ((GCTX_HIDGetPressedKeys() & PAD_BUTTON_START) && func_ov255_021d39c0(syswk->app->bgWinFrame) == FALSE) {
        syswk->getTray = syswk->tray;
        syswk->pos = func_0202ba60(syswk->app->cursorMove);
        syswk->unk13 = 2;
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        Box2Main_ShowCursor(syswk);
        return func_ov255_021cc460(syswk, 30, 1, 91);
    }

    res = func_ov255_021d34d0();
    if (res != 0xffffffff) {
        func_0202ba74(syswk->app->cursorMove, FALSE);
        if (Box2Main_GetPokeParam(syswk, res, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) != 0) {
            GFL_SndSEPlay(SEQ_SE_SYS_39);
            func_0203dac8(&syswk->app->tpx, &syswk->app->tpy);
            if (func_ov255_021d39c0(syswk->app->bgWinFrame) == FALSE) {
                func_ov255_021ceed0(syswk, sMenu71f0, 6);
            }
            Box2Main_PokeInfoPut(syswk, res);
            return func_ov255_021ccfb4(syswk, res);
        }
        func_0202ba64(syswk->app->cursorMove, res);
        func_ov255_021d24f8(syswk, res);
        Box2Main_PokeInfoOff(syswk);
        if (func_ov255_021d39c0(syswk->app->bgWinFrame) == TRUE) {
            func_ov255_021d3954(syswk->app->bgWinFrame);
            func_ov255_021d11a4(syswk, 0);
            func_ov255_021cefa4(syswk->app, 24);
            func_ov255_021bc018(syswk);
            func_ov255_021d3a48(syswk->app);
            return func_ov255_021cbec8(syswk, Box2Main_VFuncFrameMove, 17);
        }
        return 17;
    }

    res = func_ov255_021d2770(syswk);
    switch (res) {
    case 30:
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        Box2Main_PokeInfoOff(syswk);
        return func_ov255_021cbe58(syswk, 105);
    case 31:
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        Box2Main_PokeSelectOff(syswk);
        func_0202ba64(syswk->app->cursorMove, 30);
        syswk->app->oldCurPos = 30;
        func_ov255_021d24f8(syswk, 30);
        return func_ov255_021ccf1c(syswk, 1, 17);
    case 32:
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        Box2Main_PokeSelectOff(syswk);
        func_0202ba64(syswk->app->cursorMove, 30);
        syswk->app->oldCurPos = 30;
        func_ov255_021d24f8(syswk, 30);
        return func_ov255_021ccf68(syswk, 1, 17);
    case 33:
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cc3b0(syswk, 10, func_ov255_021cbe58(syswk, 26));
    case 34:
        GFL_SndSEPlay(SEQ_SE_CLOSE1);
        syswk->param->unk28 = 1;
        return func_ov255_021cc460(syswk, 7, 8, 16);
    case 35:
        GFL_SndSEPlay(SEQ_SE_CANCEL1);
        syswk->param->unk28 = 0;
        return func_ov255_021cc460(syswk, 6, 9, 116);
    case 36:
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        syswk->unk1B = 0;
        syswk->moveMode = 0;
        return func_ov255_021cc3b0(syswk, 0, func_ov255_021cbe58(syswk, 20));
    case 37:
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        syswk->unk13 = 0;
        syswk->getTray = syswk->tray;
        syswk->curRcvPos = 37;
        return func_ov255_021cc3b0(syswk, 1, 89);
    case 38:
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        syswk->unk13 = 0;
        syswk->curRcvPos = 38;
        return func_ov255_021cc3b0(syswk, 2, func_ov255_021cbe58(syswk, 90));
    case 39:
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cc3b0(syswk, 3, func_ov255_021cbe58(syswk, 97));
    case 40:
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cc3b0(syswk, 4, func_ov255_021cbe58(syswk, 101));
    case 41: {
        u8 pos;

        GFL_SndSEPlay(SEQ_SE_CANCEL1);
        pos = syswk->pos;
        func_ov255_021d32d4(syswk->app, pos, func_0202ba60(syswk->app->cursorMove));
        func_0202ba64(syswk->app->cursorMove, pos);
        syswk->app->oldCurPos = pos;
        return func_ov255_021cc3b0(syswk, 5, 19);
    }
    case 42:
        break;
    case 43:
        syswk->unk1B = 0;
        syswk->moveMode = 1;
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cde88(syswk, 20);
    case 44:
        syswk->unk1B = 0;
        syswk->moveMode = 2;
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cde88(syswk, 35);
    case 45:
        syswk->getTray = syswk->tray;
        syswk->pos = func_0202ba60(syswk->app->cursorMove);
        syswk->unk13 = 2;
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cc460(syswk, 30, 1, 91);
    case CURSORMOVE_SCROLL_L:
        if (func_0202ba60(syswk->app->cursorMove) == 30) {
            GFL_SndSEPlay(SEQ_SE_SELECT1);
            Box2Main_PokeSelectOff(syswk);
            return func_ov255_021ccf1c(syswk, 1, 17);
        }
        break;
    case CURSORMOVE_SCROLL_R:
        if (func_0202ba60(syswk->app->cursorMove) == 30) {
            GFL_SndSEPlay(SEQ_SE_SELECT1);
            Box2Main_PokeSelectOff(syswk);
            return func_ov255_021ccf68(syswk, 1, 17);
        }
        break;
    case CURSORMOVE_CURSOR_MOVE: {
        u8 pos = func_0202ba60(syswk->app->cursorMove);

        if (pos < BOX2_PARTY_POS) {
            Box2Main_PokeInfoPut(syswk, pos);
        } else if (pos != 36 && pos != 37 && pos != 38 && pos != 39 && pos != 40 && pos != 41) {
            Box2Main_PokeInfoOff(syswk);
        }
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        return func_ov255_021cbed8(syswk, func_ov255_021cbee8(syswk, 17));
    }
    case CURSORMOVE_CANCEL:
        GFL_SndSEPlay(SEQ_SE_CANCEL1);
        if (func_ov255_021d39c0(syswk->app->bgWinFrame) == TRUE) {
            u8 pos = syswk->pos;

            func_ov255_021d32d4(syswk->app, pos, func_0202ba60(syswk->app->cursorMove));
            func_0202ba64(syswk->app->cursorMove, pos);
            syswk->app->oldCurPos = pos;
            return func_ov255_021cc3b0(syswk, 5, 19);
        }
        syswk->param->unk28 = 0;
        return func_ov255_021cc460(syswk, 6, 9, 116);
    case CURSORMOVE_CURSOR_ON:
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        break;
    case CURSORMOVE_NONE:
    case CURSORMOVE_UNK_7:
    case CURSORMOVE_UNK_8:
        break;
    default:
        if (Box2Main_GetPokeParam(syswk, res, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) != 0) {
            GFL_SndSEPlay(SEQ_SE_DECIDE1);
            func_ov255_021ceed0(syswk, sMenu71f0, 6);
            Box2Main_PokeInfoPut(syswk, res);
            func_ov255_021d32d4(syswk->app, BOX2_BOXLIST_POS, func_0202ba60(syswk->app->cursorMove));
            func_0202ba64(syswk->app->cursorMove, BOX2_BOXLIST_POS);
            syswk->app->oldCurPos = BOX2_BOXLIST_POS;
            return func_ov255_021cd128(syswk, res, 17);
        }
        break;
    }
    return 17;
}

static int func_ov255_021c366c(Box2SysWork *syswk) {
    Box2Main_PokeDataMove(syswk);
    func_ov255_021cd5d8(syswk);
    func_0202ba64(syswk->app->cursorMove, BOX2_BOXLIST_POS);
    syswk->app->oldCurPos = BOX2_BOXLIST_POS;
    func_ov255_021d24f8(syswk, BOX2_BOXLIST_POS);
    func_ov255_021d101c(syswk, 1);
    func_ov255_021d1af8(syswk, 0, 0, 1, 0);
    func_ov255_021cf1ac(syswk, syswk->pos, 1, 24);
    return 17;
}

static int func_ov255_021c36c0(Box2SysWork *syswk) {
    func_ov255_021d3954(syswk->app->bgWinFrame);
    func_ov255_021d11a4(syswk, 0);
    func_ov255_021cefa4(syswk->app, 24);
    func_ov255_021bc018(syswk);
    func_ov255_021d3a48(syswk->app);
    return func_ov255_021cbec8(syswk, Box2Main_VFuncCursorMoveFrame, func_ov255_021cbee8(syswk, 17));
}

static int func_ov255_021c3700(Box2SysWork *syswk) {
    switch (syswk->app->subSeq) {
    case 0:
        if (func_ov255_021d3b48(syswk->app->bgWinFrame) == FALSE) {
            syswk->trayScroll = syswk->tray;
        }
        if (syswk->moveMode == 1 && syswk->unk1C_4 == 0) {
            syswk->getTray = BOX2_GET_NONE;
            syswk->pos = func_0202ba60(syswk->app->cursorMove);
            if (syswk->pos >= BOX2_PARTY_POS) {
                syswk->pos = 0;
                Box2Main_PokeInfoPut(syswk, syswk->pos);
            }
        } else {
            syswk->getTray = syswk->tray;
            func_ov255_021cefa4(syswk->app, 24);
            func_ov255_021bc018(syswk);
            func_ov255_021d3a48(syswk->app);
            func_ov255_021d0374(syswk, syswk->pos, 1, 1);
        }
        func_ov255_021d101c(syswk, 0);
        func_ov255_021d3954(syswk->app->bgWinFrame);
        syswk->app->subSeq++;
        return func_ov255_021cbec8(syswk, Box2Main_VFuncFrameMove, 20);
    case 1:
        syswk->app->subSeq++;
        if (func_ov255_021d3b48(syswk->app->bgWinFrame) == FALSE) {
            GFL_SndSEPlay(SEQ_SE_SYS_42);
            return func_ov255_021cdc38(syswk, 20);
        }
    case 2:
        func_ov255_021d2478(syswk, 4, syswk->pos);
        func_ov255_021d0ff8(syswk, 6);
        syswk->app->oldCurPos = syswk->pos;
        syswk->app->subSeq = 0;
        if (syswk->moveMode == 1) {
            if (syswk->unk1C_4 == 0) {
                if (Box2Main_GetPokeParam(syswk, syswk->pos, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) == 0) {
                    func_ov255_021d1af8(syswk, 0, 1, 2, 0);
                } else {
                    func_ov255_021d1af8(syswk, 0, 1, 0, 0);
                }
                func_ov255_021d0f88(syswk, 10, 1);
                return 21;
            }
            func_ov255_021d0f88(syswk, 10, 1);
        } else {
            func_ov255_021d0f88(syswk, 9, 1);
        }
        return func_ov255_021cd458(syswk, syswk->pos);
    }
    return 20;
}

// Moving Pokémon: waits for a touch or for the cursor to pick one
static int func_ov255_021c385c(Box2SysWork *syswk) {
    u32 x, y;
    u32 res;

    if (syswk->unk1C_6 == 1) {
        syswk->moveMode = 0;
        syswk->unk1C_6 = 0;
        return func_ov255_021cbe58(syswk, 22);
    }
    if ((GCTX_HIDGetPressedKeys() & PAD_BUTTON_SELECT) && syswk->moveMode != 0 && syswk->unk18 == 0) {
        Box2Main_ShowCursor(syswk);
        syswk->moveMode = 2;
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cbe58(syswk, 22);
    }
    if (GCTX_HIDGetPressedKeys() & PAD_BUTTON_START) {
        if (syswk->unk18 == 0) {
            syswk->pos = func_0202ba60(syswk->app->cursorMove);
            syswk->getTray = syswk->tray;
            syswk->unk13 = 2;
        } else {
            syswk->unk13 = 3;
            syswk->unk1D = func_0202ba60(syswk->app->cursorMove);
        }
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        Box2Main_ShowCursor(syswk);
        return func_ov255_021cc460(syswk, 30, 1, 91);
    }
    if (syswk->unk18 == 0) {
        res = func_ov255_021d34d0();
        if (res != 0xffffffff) {
            func_0202ba74(syswk->app->cursorMove, FALSE);
            func_ov255_021d1ac8(syswk, 0, 0);
            if (Box2Main_GetPokeParam(syswk, res, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) != 0) {
                GFL_SndSEPlay(SEQ_SE_SYS_39);
                func_0203dac8(&syswk->app->tpx, &syswk->app->tpy);
                Box2Main_PokeInfoPut(syswk, res);
                func_0202ba64(syswk->app->cursorMove, res);
                return func_ov255_021cd32c(syswk, res, 21);
            }
            func_0202ba64(syswk->app->cursorMove, res);
            func_ov255_021d28c4(syswk, res);
            syswk->app->oldCurPos = res;
            func_ov255_021d24f8(syswk, res);
            Box2Main_PokeInfoOff(syswk);
            return 21;
        }
    }
    if (func_ov255_021d3554(&x, &y) == TRUE) {
        syswk->app->tpx = x;
        syswk->app->tpy = y;
        syswk->nextSeq = 21;
        func_ov255_021cdc04(syswk);
        return 15;
    }

    res = func_ov255_021d29e8(syswk);
    switch (res) {
    case 30:
        func_ov255_021d1ac8(syswk, 0, 0);
        if (syswk->unk18 != 0) {
            break;
        }
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        Box2Main_PokeInfoOff(syswk);
        return func_ov255_021cbe58(syswk, 105);
    case 31:
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        func_ov255_021d1ac8(syswk, 0, 0);
        func_0202ba64(syswk->app->cursorMove, 30);
        func_ov255_021d24f8(syswk, 30);
        func_ov255_021d28c4(syswk, 30);
        syswk->app->oldCurPos = 30;
        if (syswk->unk18 == 0) {
            Box2Main_PokeSelectOff(syswk);
        } else {
            func_ov255_021d052c(syswk);
        }
        return func_ov255_021ccf1c(syswk, 0, 21);
    case 32:
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        func_ov255_021d1ac8(syswk, 0, 0);
        func_0202ba64(syswk->app->cursorMove, 30);
        func_ov255_021d24f8(syswk, 30);
        func_ov255_021d28c4(syswk, 30);
        syswk->app->oldCurPos = 30;
        if (syswk->unk18 == 0) {
            Box2Main_PokeSelectOff(syswk);
        } else {
            func_ov255_021d052c(syswk);
        }
        return func_ov255_021ccf68(syswk, 0, 21);
    case 39:
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        if (syswk->unk18 == 0) {
            Box2Main_PokeInfoOff(syswk);
        }
        return func_ov255_021cc3b0(syswk, 10, func_ov255_021cbe58(syswk, 25));
    case 40:
        if (syswk->unk18 == 0) {
            u8 pos = func_0202ba60(syswk->app->cursorMove);

            if (pos >= BOX2_PARTY_POS
                || Box2Main_GetPokeParam(syswk, pos, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) == 0) {
                break;
            }
            syswk->pos = pos;
            syswk->getTray = syswk->tray;
            syswk->unk13 = 2;
        } else {
            syswk->unk13 = 3;
            syswk->unk1D = func_0202ba60(syswk->app->cursorMove);
        }
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cc460(syswk, 8, 1, 89);
    case 41:
        if (syswk->unk18 != 0) {
            break;
        }
        GFL_SndSEPlay(SEQ_SE_CANCEL1);
        syswk->moveMode = 0;
        return func_ov255_021cc460(syswk, 6, 9, func_ov255_021cbe58(syswk, 22));
    case 42:
        if (syswk->moveMode == 0 || syswk->unk18 != 0) {
            break;
        }
        syswk->moveMode = 0;
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cbe58(syswk, 22);
    case 43:
        break;
    case 44:
        if (syswk->moveMode == 0 || syswk->unk18 != 0) {
            break;
        }
        syswk->moveMode = 2;
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cbe58(syswk, 22);
    case 45:
        if (syswk->unk18 == 0) {
            syswk->pos = func_0202ba60(syswk->app->cursorMove);
            syswk->getTray = syswk->tray;
            syswk->unk13 = 2;
        } else {
            syswk->unk13 = 3;
            syswk->unk1D = func_0202ba60(syswk->app->cursorMove);
        }
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cc460(syswk, 30, 1, 91);
    case CURSORMOVE_CANCEL:
        if (syswk->unk18 == 1) {
            return func_ov255_021cd4b8(syswk, BOX2_GET_NONE, 21);
        }
        GFL_SndSEPlay(SEQ_SE_CANCEL1);
        syswk->moveMode = 0;
        return func_ov255_021cc460(syswk, 6, 9, func_ov255_021cbe58(syswk, 22));
    case CURSORMOVE_UNK_8:
        if (func_0202ba60(syswk->app->cursorMove) == 34) {
            GFL_SndSEPlay(SEQ_SE_SELECT1);
            func_ov255_021bc09c(syswk, -1);
            return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxListScrollRight, 21);
        }
        break;
    case CURSORMOVE_UNK_7:
        if (func_0202ba60(syswk->app->cursorMove) == 37) {
            GFL_SndSEPlay(SEQ_SE_SELECT1);
            func_ov255_021bc09c(syswk, 1);
            return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxListScrollLeft, 21);
        }
        break;
    case CURSORMOVE_SCROLL_L:
        if (func_0202ba60(syswk->app->cursorMove) == 30) {
            GFL_SndSEPlay(SEQ_SE_SELECT1);
            return func_ov255_021ccf1c(syswk, 0, 21);
        }
        break;
    case CURSORMOVE_SCROLL_R:
        if (func_0202ba60(syswk->app->cursorMove) == 30) {
            GFL_SndSEPlay(SEQ_SE_SELECT1);
            return func_ov255_021ccf68(syswk, 0, 21);
        }
        break;
    case CURSORMOVE_CURSOR_MOVE: {
        u8 pos;

        GFL_SndSEPlay(SEQ_SE_SELECT1);
        pos = func_0202ba60(syswk->app->cursorMove);
        if (syswk->unk18 == 0) {
            if (pos < BOX2_PARTY_POS) {
                Box2Main_PokeInfoPut(syswk, pos);
            } else {
                Box2Main_PokeInfoOff(syswk);
            }
        }
        if (pos >= 34 && pos <= 37) {
            func_ov255_021d1ac8(syswk, pos - 34, 1);
        } else {
            func_ov255_021d1ac8(syswk, 0, 0);
        }
        return func_ov255_021cbed8(syswk, func_ov255_021cbee8(syswk, 21));
    }
    case CURSORMOVE_CURSOR_ON:
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        break;
    case 33:
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        func_ov255_021bc09c(syswk, -1);
        return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxListScrollRight, 21);
    case 38:
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        func_ov255_021bc09c(syswk, 1);
        return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxListScrollLeft, 21);
    case 34:
    case 35:
    case 36:
    case 37:
        func_ov255_021d1ac8(syswk, res - 34, 1);
        if (syswk->unk18 == 1) {
            return func_ov255_021cd4b8(syswk, res + 2, 21);
        }
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        Box2Main_PokeInfoOff(syswk);
        syswk->app->unkA55F = syswk->trayScroll + res - 34;
        if (syswk->app->unkA55F >= syswk->trayMax) {
            syswk->app->unkA55F -= syswk->trayMax;
        }
        if (syswk->app->unkA55F != syswk->tray) {
            return func_ov255_021cdba4(syswk, 21);
        }
        break;
    case CURSORMOVE_NONE:
        break;
    default:
        func_ov255_021d1ac8(syswk, 0, 0);
        if (syswk->unk18 == 1) {
            return func_ov255_021cd4b8(syswk, res, 21);
        }
        if (Box2Main_GetPokeParam(syswk, res, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) != 0) {
            syswk->pos = res;
            syswk->getTray = syswk->tray;
            func_ov255_021d0374(syswk, syswk->pos, 1, 1);
            return func_ov255_021cd458(syswk, syswk->pos);
        }
        break;
    }
    return 21;
}

static int func_ov255_021c3ec8(Box2SysWork *syswk) {
    u8 pos;

    switch (syswk->app->subSeq) {
    case 0:
        func_ov255_021d101c(syswk, 0);
        func_ov255_021d1ac8(syswk, 0, 0);
        if (func_0202ba60(syswk->app->cursorMove) >= BOX2_PARTY_POS) {
            Box2Main_PokeInfoOff(syswk);
        }
        if (syswk->moveMode != 2) {
            func_ov255_021d1af8(syswk, 0, 0, 1, 0);
            GFL_SndSEPlay(SEQ_SE_SYS_42);
            syswk->app->subSeq++;
            return func_ov255_021cdc54(syswk, 22);
        }
        return 35;
    case 1:
        if (syswk->unk1B == 1) {
            func_ov255_021d3734(syswk->app->bgWinFrame);
            func_ov255_021d3744(syswk->app->bgWinFrame);
            syswk->app->subSeq++;
            return func_ov255_021cbec8(syswk, Box2Main_VFuncPartyFrameMove, 22);
        }
        pos = func_0202ba60(syswk->app->cursorMove);
        if (pos >= BOX2_PARTY_POS) {
            pos = 0;
        }
        func_ov255_021d2478(syswk, 3, pos);
        func_ov255_021d0ff8(syswk, 6);
        Box2Main_PokeInfoPut(syswk, pos);
        syswk->app->subSeq = 0;
        func_ov255_021d0f88(syswk, 9, 1);
        return 17;
    case 2:
        func_ov255_021d3a64(syswk->app);
        syswk->app->subSeq = 0;
        return 33;
    }
    return 22;
}

// After a move: puts the cursor back, and says why a move failed
static int func_ov255_021c3fc0(Box2SysWork *syswk) {
    u8 pos;
    u8 n;

    Box2Main_PokeDataMove(syswk);
    syswk->unk18 = 0;
    syswk->getTray = BOX2_GET_NONE;
    if (syswk->app->moveErr == BOX2_MOVE_ERR_NONE) {
        pos = func_0202ba60(syswk->app->cursorMove);
    } else {
        func_0202ba64(syswk->app->cursorMove, syswk->pos);
        func_ov255_021d24f8(syswk, syswk->pos);
        func_ov255_021d101c(syswk, 1);
        pos = syswk->pos;
    }
    syswk->app->oldCurPos = pos;
    func_ov255_021cd5d8(syswk);
    if (func_ov255_021d3b48(syswk->app->bgWinFrame) == TRUE) {
        if (syswk->nextSeq == 32) {
            func_ov255_021d2478(syswk, 4, pos);
            Box2Main_PokeInfoPut(syswk, pos);
            syswk->nextSeq = 21;
            n = 0;
            if (Box2Main_GetPokeParam(syswk, pos, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) == 0) {
                n = 2;
            }
        } else if (pos < BOX2_PARTY_POS
                   && Box2Main_GetPokeParam(syswk, pos, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) != 0) {
            Box2Main_PokeInfoPut(syswk, pos);
            n = 0;
        } else {
            Box2Main_PokeInfoOff(syswk);
            n = 2;
        }
    } else if (func_ov255_021d3834(syswk->app->bgWinFrame) == TRUE) {
        if (syswk->nextSeq == 21) {
            pos = func_0202ba60(syswk->app->cursorMove);
            if (pos > 32) {
                pos = syswk->pos;
            }
            func_ov255_021d2478(syswk, 6, pos);
            Box2Main_PokeInfoPut(syswk, pos);
            syswk->nextSeq = 32;
            n = 0;
            if (Box2Main_GetPokeParam(syswk, pos, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) == 0) {
                n = 2;
            }
        } else if (pos < BOX2_BOXLIST_POS
                   && Box2Main_GetPokeParam(syswk, pos, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) != 0) {
            Box2Main_PokeInfoPut(syswk, pos);
            n = 0;
        } else {
            Box2Main_PokeInfoOff(syswk);
            n = 2;
        }
    } else if (pos < BOX2_BOXLIST_POS
               && Box2Main_GetPokeParam(syswk, pos, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) != 0) {
        Box2Main_PokeInfoPut(syswk, pos);
        n = 0;
    } else {
        Box2Main_PokeInfoOff(syswk);
        n = 2;
    }
    if (syswk->moveMode == 0) {
        syswk->unk1C_6 = 1;
        n = syswk->unk21;
    }
    func_ov255_021d1af8(syswk, 0, 1, n, 0);
    switch (syswk->app->moveErr) {
    case BOX2_MOVE_ERR_MAIL:
        GFL_SndSEPlay(SEQ_SE_BEEP);
        func_ov255_021d101c(syswk, 0);
        func_ov255_021cf270(syswk, 2, 24);
        return 24;
    case BOX2_MOVE_ERR_LAST_BATTLER:
        GFL_SndSEPlay(SEQ_SE_BEEP);
        func_ov255_021d101c(syswk, 0);
        func_ov255_021cf270(syswk, 3, 24);
        return 24;
    case 4:
        GFL_SndSEPlay(SEQ_SE_BEEP);
        func_ov255_021d101c(syswk, 0);
        func_ov255_021cf270(syswk, 4, 24);
        return 24;
    case 5:
        GFL_SndSEPlay(SEQ_SE_BEEP);
        func_ov255_021d101c(syswk, 0);
        func_ov255_021cf2cc(syswk, 0);
        return 24;
    }
    if (syswk->param->mode == 2) {
        if (func_ov255_021d3b48(syswk->app->bgWinFrame) == TRUE) {
            func_ov255_021d3a48(syswk->app);
        } else {
            func_ov255_021d3a64(syswk->app);
        }
    }
    return syswk->nextSeq;
}

// Closes the message about a move that failed
static int func_ov255_021c41e8(Box2SysWork *syswk) {
    if (Box2Seq_TrgWait(syswk) == BOX2SEQ_TRGWAIT) {
        return 24;
    }
    if (func_0202ba70(syswk->app->cursorMove) == TRUE) {
        func_ov255_021cf63c(syswk->app, BOX2_ACTOR_CURSOR, TRUE);
    }
    func_ov255_021cefa4(syswk->app, syswk->app->moveErr == 5 ? 27 : 24);
    func_ov255_021bc018(syswk);
    if (syswk->param->mode == 2) {
        if (func_ov255_021d3b48(syswk->app->bgWinFrame) == TRUE) {
            func_ov255_021d3a48(syswk->app);
        } else {
            func_ov255_021d3a64(syswk->app);
        }
    }
    syswk->app->moveErr = BOX2_MOVE_ERR_NONE;
    return syswk->nextSeq;
}

static int func_ov255_021c4258(Box2SysWork *syswk) {
    switch (syswk->app->subSeq) {
    case 0:
        func_ov255_021cf63c(syswk->app, BOX2_ACTOR_CURSOR, FALSE);
        func_ov255_021d1ac8(syswk, 0, 0);
        GFL_SndSEPlay(SEQ_SE_SYS_42);
        syswk->app->subSeq++;
        return func_ov255_021cdc54(syswk, 25);
    case 1:
        func_ov255_021d3734(syswk->app->bgWinFrame);
        func_ov255_021d3744(syswk->app->bgWinFrame);
        if (syswk->unk18 == 1) {
            func_ov255_021cfd34(syswk, 1);
        } else {
            func_ov255_021cfd34(syswk, 0);
        }
        GFL_SndSEPlay(SEQ_SE_SYS_42);
        syswk->app->subSeq++;
        return func_ov255_021cbec8(syswk, Box2Main_VFuncPartyFrameMove, 25);
    case 2:
        func_ov255_021d2478(syswk, 6, BOX2_PARTY_POS);
        func_ov255_021d28c4(syswk, BOX2_PARTY_POS);
        if (syswk->unk18 == 0) {
            Box2Main_PokeInfoPut(syswk, BOX2_PARTY_POS);
        }
        func_ov255_021d3a64(syswk->app);
        syswk->app->oldCurPos = BOX2_PARTY_POS;
        syswk->app->subSeq = 0;
        return 32;
    }
    return 25;
}

// Starts picking a range
static int func_ov255_021c4328(Box2SysWork *syswk) {
    switch (syswk->app->subSeq) {
    case 0:
        syswk->unk1C_4 = 0;
        if (func_ov255_021d3b48(syswk->app->bgWinFrame) == FALSE) {
            syswk->trayScroll = syswk->tray;
        }
        syswk->getTray = BOX2_GET_NONE;
        syswk->pos = func_0202ba60(syswk->app->cursorMove);
        if (syswk->pos >= BOX2_PARTY_POS) {
            syswk->pos = 0;
            Box2Main_PokeInfoPut(syswk, syswk->pos);
        }
        func_ov255_021d101c(syswk, 0);
        syswk->app->subSeq++;
        if (func_ov255_021d39c0(syswk->app->bgWinFrame) == TRUE) {
            func_ov255_021d11a4(syswk, 0);
            func_ov255_021cefa4(syswk->app, 24);
            func_ov255_021bc018(syswk);
            func_ov255_021d3a48(syswk->app);
            func_ov255_021d3954(syswk->app->bgWinFrame);
            return func_ov255_021cbec8(syswk, Box2Main_VFuncFrameMove, 35);
        }
    case 1:
        syswk->app->subSeq++;
        if (func_ov255_021d3b48(syswk->app->bgWinFrame) == FALSE) {
            GFL_SndSEPlay(SEQ_SE_SYS_42);
            return func_ov255_021cdc38(syswk, 35);
        }
    case 2:
        func_ov255_021d2478(syswk, 4, syswk->pos);
        func_ov255_021d0ff8(syswk, 6);
        syswk->app->oldCurPos = syswk->pos;
        syswk->app->subSeq = 0;
        if (Box2Main_GetPokeParam(syswk, syswk->pos, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) == 0) {
            func_ov255_021d1af8(syswk, 0, 1, 2, 0);
        } else {
            func_ov255_021d1af8(syswk, 0, 1, 0, 0);
        }
        func_ov255_021d0f88(syswk, 11, 1);
        return 36;
    }
    return 35;
}

// Picking a range: waits for a touch or for the cursor to pick or drop one
static int func_ov255_021c445c(Box2SysWork *syswk) {
    u32 x, y;
    u32 res;

    if ((GCTX_HIDGetPressedKeys() & PAD_BUTTON_SELECT) && syswk->moveMode != 0 && syswk->unk18 == 0) {
        Box2Main_ShowCursor(syswk);
        syswk->moveMode = 0;
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cbe58(syswk, 37);
    }
    if ((GCTX_HIDGetPressedKeys() & PAD_BUTTON_START) && syswk->unk18 == 0) {
        syswk->pos = func_0202ba60(syswk->app->cursorMove);
        syswk->getTray = syswk->tray;
        syswk->unk13 = 2;
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        Box2Main_ShowCursor(syswk);
        return func_ov255_021cc460(syswk, 30, 1, 91);
    }

    if (syswk->unk18 == 0) {
        res = func_ov255_021d34d0();
        if (res != 0xffffffff) {
            Box2Main_PokeInfoPut(syswk, res);
            func_0202ba74(syswk->app->cursorMove, FALSE);
            func_ov255_021d1ac8(syswk, 0, 0);
            func_ov255_021d1e2c(syswk, 1);
            func_ov255_021d208c(syswk, res, res, 0);
            syswk->app->rangeSelect.startPos = res;
            syswk->app->rangeSelect.endPos = res;
            syswk->app->unkA5B4 = FALSE;
            syswk->unk18 = 3;
            syswk->getTray = syswk->tray;
            func_ov255_021d28c4(syswk, res);
            return 36;
        }
    } else if (syswk->unk18 == 3) {
        if (func_0203da2c() == TRUE) {
            res = func_ov255_021d34e0();
            if (res != 0xffffffff) {
                func_ov255_021d208c(syswk, syswk->app->rangeSelect.startPos, res, 0);
                syswk->app->rangeSelect.endPos = res;
            }
        } else {
            u32 width, height;

            func_ov255_021cdef8(syswk);
            syswk->pos = func_ov255_021d21ec(syswk->app->rangeSelect.startPos, syswk->app->rangeSelect.endPos);
            func_0202ba64(syswk->app->cursorMove, syswk->pos);
            func_ov255_021d24f8(syswk, syswk->pos);
            func_ov255_021d208c(syswk, syswk->app->rangeSelect.startPos, syswk->app->rangeSelect.endPos, 0);
            func_ov255_021d21a4(syswk->app->rangeSelect.startPos, syswk->app->rangeSelect.endPos, &width, &height);
            syswk->app->rangeWidth = width;
            syswk->app->rangeHeight = height;
            Box2Main_SetRangeFlags(syswk);
            if (Box2Main_GetRangeCount(syswk->app) != 0) {
                func_ov255_021d0374(syswk, syswk->pos, width, height);
                func_ov255_021d2238(syswk->app, syswk->pos, width, height, 0);
                func_ov255_021cf2e8(syswk);
                syswk->unk18 = 2;
                syswk->app->oldCurPos = syswk->pos;
            } else {
                func_ov255_021cded4(syswk);
            }
        }
        return 36;
    } else if (syswk->unk18 == 2 && syswk->app->unkA5B4 == FALSE) {
        res = func_ov255_021d34d0();
        if (res != 0xffffffff) {
            // The touch position's y doubles as the row counter
            for (y = 0; y < syswk->app->rangeHeight; y++) {
                if (res >= syswk->pos + y * 6 && res < syswk->app->rangeWidth + (syswk->pos + y * 6)) {
                    GFL_SndSEPlay(SEQ_SE_SYS_39);
                    func_0203dac8(&syswk->app->tpx, &syswk->app->tpy);
                    func_0202ba64(syswk->app->cursorMove, syswk->pos);
                    Box2Main_PokeInfoPut(syswk, syswk->pos);
                    syswk->app->unkA5B4 = TRUE;
                    return func_ov255_021cd390(syswk, 36);
                }
            }
        }
    }

    if (func_ov255_021d3554(&x, &y) == TRUE) {
        syswk->app->tpx = x;
        syswk->app->tpy = y;
        syswk->nextSeq = 36;
        func_ov255_021cdc04(syswk);
        return 15;
    }

    res = func_ov255_021d29e8(syswk);
    if (res != CURSORMOVE_NONE) {
        syswk->app->unkA5B4 = TRUE;
    }
    switch (res) {
    case 30:
        func_ov255_021d1ac8(syswk, 0, 0);
        if (syswk->unk18 == 0) {
            GFL_SndSEPlay(SEQ_SE_DECIDE1);
            Box2Main_PokeInfoOff(syswk);
            return func_ov255_021cbe58(syswk, 105);
        }
        if (syswk->unk18 == 1) {
            func_ov255_021cded4(syswk);
            Box2Main_PokeInfoOff(syswk);
        }
        break;
    case 31:
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        func_ov255_021d1ac8(syswk, 0, 0);
        func_0202ba64(syswk->app->cursorMove, 30);
        func_ov255_021d24f8(syswk, 30);
        func_ov255_021d28c4(syswk, 30);
        syswk->app->oldCurPos = 30;
        if (syswk->unk18 == 0) {
            Box2Main_PokeSelectOff(syswk);
        } else if (syswk->unk18 == 1) {
            Box2Main_PokeSelectOff(syswk);
            func_ov255_021cded4(syswk);
        } else {
            func_ov255_021d052c(syswk);
        }
        return func_ov255_021ccf1c(syswk, 0, 36);
    case 32:
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        func_ov255_021d1ac8(syswk, 0, 0);
        func_0202ba64(syswk->app->cursorMove, 30);
        func_ov255_021d24f8(syswk, 30);
        func_ov255_021d28c4(syswk, 30);
        syswk->app->oldCurPos = 30;
        if (syswk->unk18 == 0) {
            Box2Main_PokeSelectOff(syswk);
        } else if (syswk->unk18 == 1) {
            Box2Main_PokeSelectOff(syswk);
            func_ov255_021cded4(syswk);
        } else {
            func_ov255_021d052c(syswk);
        }
        return func_ov255_021ccf68(syswk, 0, 36);
    case 39:
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        if (syswk->unk18 == 0) {
            Box2Main_PokeInfoOff(syswk);
        } else if (syswk->unk18 == 1) {
            func_ov255_021cded4(syswk);
            Box2Main_PokeInfoOff(syswk);
        }
        return func_ov255_021cc3b0(syswk, 10, func_ov255_021cbe58(syswk, 40));
    case 40: {
        u8 pos;

        if (syswk->unk18 != 0) {
            break;
        }
        pos = func_0202ba60(syswk->app->cursorMove);
        if (pos >= BOX2_PARTY_POS
            || Box2Main_GetPokeParam(syswk, pos, syswk->tray, PKM_PARAM_SPECIES_VALID, NULL) == 0) {
            break;
        }
        syswk->pos = pos;
        syswk->getTray = syswk->tray;
        syswk->unk13 = 2;
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cc460(syswk, 8, 1, 89);
    }
    case 41:
        if (syswk->unk18 != 0) {
            break;
        }
        GFL_SndSEPlay(SEQ_SE_CANCEL1);
        syswk->moveMode = 0;
        return func_ov255_021cc460(syswk, 6, 9, func_ov255_021cbe58(syswk, 37));
    case 42:
        if (syswk->unk18 != 0) {
            break;
        }
        syswk->moveMode = 0;
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cbe58(syswk, 37);
    case 43:
        if (syswk->unk18 != 0) {
            break;
        }
        syswk->moveMode = 1;
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cbe58(syswk, 37);
    case 44:
        break;
    case 45:
        if (syswk->unk18 != 0) {
            break;
        }
        syswk->pos = func_0202ba60(syswk->app->cursorMove);
        syswk->getTray = syswk->tray;
        syswk->unk13 = 2;
        GFL_SndSEPlay(SEQ_SE_DECIDE1);
        return func_ov255_021cc460(syswk, 30, 1, 91);
    case CURSORMOVE_CANCEL:
        if (syswk->unk18 == 1) {
            u8 pos = func_0202ba60(syswk->app->cursorMove);

            if (pos < BOX2_PARTY_POS) {
                Box2Main_PokeInfoPut(syswk, pos);
            } else {
                Box2Main_PokeInfoOff(syswk);
            }
            func_ov255_021cded4(syswk);
            break;
        }
        if (syswk->unk18 != 0) {
            func_ov255_021d1e2c(syswk, 0);
            return func_ov255_021cd52c(syswk, BOX2_GET_NONE, 36);
        }
        GFL_SndSEPlay(SEQ_SE_CANCEL1);
        syswk->moveMode = 0;
        return func_ov255_021cc460(syswk, 6, 9, func_ov255_021cbe58(syswk, 37));
    case CURSORMOVE_UNK_8:
        if (func_0202ba60(syswk->app->cursorMove) == 34) {
            if (syswk->unk18 == 1) {
                Box2Main_PokeSelectOff(syswk);
                func_ov255_021cded4(syswk);
            }
            GFL_SndSEPlay(SEQ_SE_SELECT1);
            func_ov255_021bc09c(syswk, -1);
            return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxListScrollRight, 36);
        }
        break;
    case CURSORMOVE_UNK_7:
        if (func_0202ba60(syswk->app->cursorMove) == 37) {
            if (syswk->unk18 == 1) {
                Box2Main_PokeSelectOff(syswk);
                func_ov255_021cded4(syswk);
            }
            GFL_SndSEPlay(SEQ_SE_SELECT1);
            func_ov255_021bc09c(syswk, 1);
            return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxListScrollLeft, 36);
        }
        break;
    case CURSORMOVE_SCROLL_L:
        if (func_0202ba60(syswk->app->cursorMove) == 30) {
            if (syswk->unk18 == 1) {
                func_ov255_021cded4(syswk);
            }
            GFL_SndSEPlay(SEQ_SE_SELECT1);
            return func_ov255_021ccf1c(syswk, 0, 36);
        }
        break;
    case CURSORMOVE_SCROLL_R:
        if (func_0202ba60(syswk->app->cursorMove) == 30) {
            if (syswk->unk18 == 1) {
                func_ov255_021cded4(syswk);
            }
            GFL_SndSEPlay(SEQ_SE_SELECT1);
            return func_ov255_021ccf68(syswk, 0, 36);
        }
        break;
    case CURSORMOVE_CURSOR_MOVE: {
        u8 pos;

        GFL_SndSEPlay(SEQ_SE_SELECT1);
        pos = func_0202ba60(syswk->app->cursorMove);
        if (syswk->unk18 == 0) {
            if (pos < BOX2_PARTY_POS) {
                Box2Main_PokeInfoPut(syswk, pos);
            } else {
                Box2Main_PokeInfoOff(syswk);
            }
        } else if (syswk->unk18 == 1 && pos < BOX2_PARTY_POS) {
            func_ov255_021d208c(syswk, syswk->app->rangeSelect.startPos, pos, 0);
        }
        if (pos >= 34 && pos <= 37) {
            func_ov255_021d1ac8(syswk, pos - 34, 1);
        } else {
            func_ov255_021d1ac8(syswk, 0, 0);
        }
        return func_ov255_021cbed8(syswk, func_ov255_021cbee8(syswk, 36));
    }
    case CURSORMOVE_CURSOR_ON:
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        break;
    case 33:
        if (syswk->unk18 == 1) {
            func_ov255_021cded4(syswk);
        }
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        func_ov255_021bc09c(syswk, -1);
        return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxListScrollRight, 36);
    case 38:
        if (syswk->unk18 == 1) {
            func_ov255_021cded4(syswk);
        }
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        func_ov255_021bc09c(syswk, 1);
        return func_ov255_021cbec8(syswk, Box2Main_VFuncBoxListScrollLeft, 36);
    case 34:
    case 35:
    case 36:
    case 37:
        res -= 34;
        func_ov255_021d1ac8(syswk, res, 1);
        if (syswk->unk18 == 2) {
            return func_ov255_021cd52c(syswk, res + 36, 36);
        }
        if (syswk->unk18 == 1) {
            func_ov255_021cded4(syswk);
        }
        GFL_SndSEPlay(SEQ_SE_SELECT1);
        Box2Main_PokeInfoOff(syswk);
        syswk->app->unkA55F = syswk->trayScroll + res;
        if (syswk->app->unkA55F >= syswk->trayMax) {
            syswk->app->unkA55F -= syswk->trayMax;
        }
        if (syswk->app->unkA55F != syswk->tray) {
            return func_ov255_021cdba4(syswk, 36);
        }
        break;
    case CURSORMOVE_NONE:
        break;
    default:
        func_ov255_021d1ac8(syswk, 0, 0);
        if (syswk->unk18 == 1) {
            u32 width, height;

            syswk->app->rangeSelect.endPos = res;
            func_ov255_021cdef8(syswk);
            syswk->pos = func_ov255_021d21ec(syswk->app->rangeSelect.startPos, syswk->app->rangeSelect.endPos);
            func_0202ba64(syswk->app->cursorMove, syswk->pos);
            func_ov255_021d24f8(syswk, syswk->pos);
            func_ov255_021d208c(syswk, syswk->app->rangeSelect.startPos, syswk->app->rangeSelect.endPos, 0);
            func_ov255_021d21a4(syswk->app->rangeSelect.startPos, syswk->app->rangeSelect.endPos, &width, &height);
            syswk->app->rangeWidth = width;
            syswk->app->rangeHeight = height;
            Box2Main_SetRangeFlags(syswk);
            if (Box2Main_GetRangeCount(syswk->app) != 0) {
                func_ov255_021d0374(syswk, syswk->pos, width, height);
                func_ov255_021d2238(syswk->app, syswk->pos, width, height, 0);
                func_ov255_021cf2e8(syswk);
                syswk->unk18 = 2;
                syswk->app->oldCurPos = syswk->pos;
                return func_ov255_021cd494(syswk, syswk->pos, 36);
            }
            func_ov255_021cded4(syswk);
        } else if (syswk->unk18 == 2) {
            if (Box2Main_RangePutCheck(syswk, syswk->tray, res) != FALSE) {
                func_ov255_021d1e2c(syswk, 0);
                return func_ov255_021cd52c(syswk, res, 36);
            }
            GFL_SndSEPlay(SEQ_SE_BEEP);
        } else {
            syswk->getTray = syswk->tray;
            syswk->pos = res;
            syswk->app->rangeSelect.startPos = res;
            syswk->app->rangeSelect.endPos = res;
            syswk->app->unkA5B4 = TRUE;
            func_ov255_021d208c(syswk, res, res, 0);
            func_ov255_021d1e2c(syswk, 1);
            syswk->unk18 = 1;
            syswk->app->rangeWidth = 1;
            syswk->app->rangeHeight = 1;
            func_ov255_021d28c4(syswk, res);
        }
        break;
    }
    return 36;
}
