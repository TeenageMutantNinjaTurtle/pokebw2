#include "types.h"
#include "constants/arc.h"
#include "constants/sound.h"
#include "demo/intro.h"
#include "gfl/msg.h"
#include "gfl/std.h"

// The intro's process. ov294 has no file name for this file, which is named after the others (intro_cmd.c and so on)

typedef struct {
    HeapID heapId;
    IntroParam *param;
    IntroGraphic *graphic;
    Font *font;
    MsgData *msgData;
    IntroCmd *cmd;
    IntroMcss *mcss;
    IntroG3d *g3d;
    IntroParticle *particle;
} IntroWork;

BOOL IntroProc_Init(GameProc *proc, u32 *state, void *param, void *work);
BOOL IntroProc_Main(GameProc *proc, u32 *state, void *param, void *work);
BOOL IntroProc_Exit(GameProc *proc, u32 *state, void *param, void *work);

const u32 INTRO_SOUNDS[] = {
    SEQ_SE_NAGERU, SEQ_SE_BOWA2, SEQ_SE_OPEN2, SEQ_SE_KON, SEQ_SE_TOUJOU_INTRO, SEQ_BGM_STARTING, SEQ_BGM_STARTING2,
};

const GameProcFunctions INTRO_PROC_FUNCTIONS = { IntroProc_Init, IntroProc_Main, IntroProc_Exit };

const u32 INTRO_SOUND_COUNT = NELEMS(INTRO_SOUNDS);

BOOL IntroProc_Init(GameProc *proc, u32 *state, void *param, void *work) {
    IntroWork *wk;

    GFL_OvlLoad(OVERLAY_ID(139));
    GFL_HeapCreateChild(HEAPID_USER, HEAPID_INTRO, 0x100000);
    wk = GFL_ProcInitSubsystem(proc, sizeof(IntroWork), HEAPID_INTRO);
    sys_memset(wk, 0, sizeof(IntroWork));
    wk->heapId = HEAPID_INTRO;
    wk->param = param;
    wk->graphic = func_ov294_021a1cf8(1, wk->param->unk8, wk->heapId);
    wk->font = GFL_FontCreate(ARCID_FONT, 0, 0, 0, wk->heapId);
    wk->msgData = GFL_MsgSysLoadData(FALSE, ARCID_SYSTEM_MESSAGE, 85, wk->heapId);
    wk->mcss = func_ov294_021a355c(wk->heapId, wk->param->unk8);
    wk->g3d = func_ov294_021a38a8(wk->graphic, wk->param->unk8, wk->heapId);
    wk->particle = func_ov294_021a3bf8(wk->graphic, wk->heapId);
    wk->cmd = func_ov294_021a2ee8(wk->g3d, wk->particle, wk->mcss, wk->param, wk->graphic, wk->heapId);
    return TRUE;
}

BOOL IntroProc_Exit(GameProc *proc, u32 *state, void *param, void *work) {
    IntroWork *wk = work;
    HeapID heapId;

    func_ov294_021a3ca4(wk->particle);
    func_ov294_021a35ac(wk->mcss);
    func_ov294_021a39a4(wk->g3d);
    GFL_MsgDataFree(wk->msgData);
    GFL_FontFree(wk->font);
    func_ov294_021a2f3c(wk->cmd);
    func_ov294_021a1dd4(wk->graphic);
    heapId = wk->heapId;
    GFL_ProcReleaseSubsystem(proc);
    GFL_HeapDelete(heapId);
    GFL_OvlUnload(OVERLAY_ID(139));
    return TRUE;
}

BOOL IntroProc_Main(GameProc *proc, u32 *state, void *param, void *work) {
    IntroWork *wk = work;

    if (!func_ov294_021a2f50(wk->cmd)) {
        return TRUE;
    }
    func_ov294_021a1e30(wk->graphic);
    func_ov294_021a1e44(wk->graphic);
    func_ov294_021a3864(wk->mcss);
    func_ov294_021a35dc(wk->mcss);
    func_ov294_021a3cb4(wk->particle);
    func_ov294_021a39d0(wk->g3d);
    func_ov294_021a1e50(wk->graphic);
    return FALSE;
}
