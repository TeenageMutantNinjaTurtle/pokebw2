#include "field/field.h"
#include "field/field_money_window.h"
#include "gfl/bg_sys.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "gfl/str.h"

FieldMoneyWindow *func_ov033_02177998(Field *field, u32 value, u32 lines) {
    u16 heapId;
    FieldMoneyWindow *work;
    s32 height;

    heapId = Field_GetHeapID(field);
    work = GFL_HeapAllocate(heapId, sizeof(FieldMoneyWindow), TRUE, data_ov033_0217c600, 0x73);
    work->heapId = heapId;
    work->field = field;
    work->unk24 = value;
    work->unk20 = lines;
    work->messages = GFL_MsgSysLoadData(FALSE, 3, 0x1e0, heapId);
    work->wordSet = GFL_WordSetSystemCreateDefault(heapId);
    work->first = GFL_StrBufCreate(0x80, heapId);
    work->second = GFL_StrBufCreate(0x80, heapId);
    height = ((14 * (s32)lines + 7) & ~7) / 8;
    work->window = FieldMsgBG_CreateMoneyWin(Field_GetMsgBGSys(field), (u32)work->messages, 1, 1, 0x15, height);
    return work;
}

void func_ov033_02177a28(FieldMoneyWindow *work) {
    func_ov036_02187c7c(work->window);
    func_ov036_02187c1c(work->window);
    GFL_BGSysLoadScr(1);
    GFL_StrBufFree(work->first);
    GFL_StrBufFree(work->second);
    GFL_WordSetSystemFree(work->wordSet);
    GFL_MsgDataFree(work->messages);
    GFL_HeapFree(work);
}