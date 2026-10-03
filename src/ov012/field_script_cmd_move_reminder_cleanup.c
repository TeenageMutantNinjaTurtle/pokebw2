#include "field/field_script.h"
#include "gfl/heap.h"
#include "pml/move_reminder.h"

void func_ov012_02157728(ScriptOverlayWork *work) {
    MoveReminderProcessData *data;
    u16 result;

    data = work->resource;
    switch (data->status) {
    case 0:
    default:
        result = FALSE;
        break;
    case 1:
        result = TRUE;
        break;
    }
    *(u16 *)work->data = result;
    GFL_HeapFree(((MoveReminderProcessData *)work->resource)->moves);
    func_ov012_02169ca4(work->resource);
}
