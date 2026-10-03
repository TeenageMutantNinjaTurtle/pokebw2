#include "field/field.h"
#include "field/field_money_window.h"
#include "gfl/bg_sys.h"
#include "gfl/bmpwin.h"
#include "gfl/graphics.h"
#include "gfl/msg.h"
#include "gfl/str.h"

void func_ov033_02177a60(FieldMoneyWindow *work) {
    MsgData *messages;
    s32 i;
    u32 y;
    s32 offset;

    messages = GFL_MsgSysLoadData(FALSE, 2, 0x40, (work->heapId & 0x7fff) | 0x8000);
    for (i = 0; i < (s32)work->unk20; i++) {
        offset = i << 2;
        GFL_MsgDataLoadStrbuf(messages, *(u16 *)((u8 *)work->unk24 + offset), work->first);
        y = 14 * i;
        func_ov036_02187c4c(work->window, 0, (u16)y, work->first);
        GFL_MsgDataLoadStrbuf(work->messages, 5, work->first);
        WordSetNumber(work->wordSet, 0, *(u16 *)((u8 *)work->unk24 + offset + 2), 2, 1, 1);
        GFL_WordSetFormatStrbuf(work->wordSet, work->second, work->first);
        func_ov036_02187c4c(work->window, 0x6c, (u16)y, work->second);
    }
    GFL_MsgDataFree(messages);
    GFL_BGSysLoadScr(BmpWin_GetBGIndex(func_ov036_02187c9c(work->window)));
}
