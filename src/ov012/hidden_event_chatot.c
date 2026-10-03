#include "field/event_chatot.h"
#include "field/hidden_event.h"

u32 func_ov012_02159984(HiddenEventContext *context) {
    switch (func_ov012_02159b5c(context, 9)) {
    default:
        return FALSE;
    case 0:
        return TRUE;
    }
}

GameEvent *func_ov012_02159998(HiddenEventArgs *args, HiddenEventContext *context) {
    func_ov012_0216002c(0x1c0);
    return func_ov033_02178ca8(context->gsys, context->field, (u8)args->x);
}
