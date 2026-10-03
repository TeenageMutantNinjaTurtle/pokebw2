#include "field/field.h"
#include "field/field_money_window.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "gfl/str.h"

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
