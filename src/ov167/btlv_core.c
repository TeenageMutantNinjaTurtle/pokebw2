#include "types.h"
#include "battle/btlv.h"
#include "battle/tr_ai.h"
#include "gfl/bmpwin.h"
#include "gfl/clact.h"
#include "gfl/g3d.h"
#include "gfl/graphics.h"
#include "gfl/msg.h"
#include "gfl/net.h"
#include "gfl/overlay.h"
#include "nitro/gx.h"
#include "nitro/hw.h"

void func_ov167_021ce604(HeapID heapId) {
    func_ov167_021ce678(heapId);
    GFL_OvlLoad(OVERLAY_ID(168));
    gfxSetLCDCBanks(0x80);
    GFL_OvlLoad(OVERLAY_ID(169));
    if (!func_02042b20()) {
        GFL_OvlLoad(OVERLAY_TR_AI);
    }
}

void func_ov167_021ce638(void) {
    func_ov167_021ce748();
    GFL_OvlUnload(OVERLAY_ID(168));
    GFL_OvlUnload(OVERLAY_ID(169));
    if (!func_02042b20()) {
        GFL_OvlUnload(OVERLAY_TR_AI);
    }
}

void func_ov167_021ce668(HeapID heapId) {
    func_ov167_021ce748();
    func_ov167_021ce678(heapId);
}

void func_ov167_021ce678(HeapID heapId) {
    GFL_BGSysCreate(heapId);
    BmpWin_InitAllocator(heapId);
    func_020232d0();
    GFL_BGSysSetVRAMBanks(&data_ov167_021da900);
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB);
    GFL_BGSysSetLCDConfig(&data_ov167_021da8d4);
    GFL_G3DSysCreate(FALSE, 2, 0, 1, 0, heapId, NULL);
    GFL_G3DSysSetSwapBufferParams(1, 0);
    G3X_AlphaBlend(TRUE);
    G3X_EdgeMarking(FALSE);
    G3X_AntiAlias(TRUE);
    gfxSetFog(FALSE, 0, 0, 0);
    G2_SetBG0Priority(1);
    gfxRegSetAlphaBlend(REG_BLDCNT_ADDR, GX_BLEND_PLANEMASK_BG1,
                        GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 |
                            GX_BLEND_PLANEMASK_OBJ | GX_BLEND_PLANEMASK_BD,
                        0x1f, 3);
    ClActSys_Create(&data_ov167_021da8e4, &data_ov167_021da900, heapId);
}

void func_ov167_021ce748(void) {
    func_ov168_021df138();
    func_0204b758();
    BmpWin_FreeAllocator();
    GFL_BGSysFree();
    GFL_G3DSysFree();
}

// Function names from swan.
void Btlv_StringParam_Setup(BtlvStringParam *param, u32 type, u16 message) {
    u32 i;

    for (i = 0; i < 9; i++) {
        param->args[i] = 0;
    }
    param->count = 0;
    param->message = message;
    param->type = type;
    param->mode = 0x50;
}

void Btlv_StringParam_AddArg(BtlvStringParam *param, u32 arg) {
    u8 count;

    count = param->count;
    if (count < 9) {
        param->count = count + 1;
        param->args[count] = arg;
    }
}
