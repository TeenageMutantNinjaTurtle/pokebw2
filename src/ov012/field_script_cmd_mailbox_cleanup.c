#include "field/field_script.h"
#include "gfl/heap.h"

struct MailboxProcessData {
    u32 unk00;
    u32 result;
};

void func_ov012_0215767c(ScriptOverlayWork *work) {
    MailboxProcessData *mailbox = work->resource;

    if (mailbox->result == 1) {
        *(u16 *)work->data = TRUE;
    } else {
        *(u16 *)work->data = FALSE;
    }
    GFL_HeapFree(work->resource);
}
