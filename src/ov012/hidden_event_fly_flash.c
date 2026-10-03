#include "field/event_fly.h"
#include "field/event_sweet_scent.h"
#include "field/hidden_event.h"
#include "system/game_event.h"

u32 func_ov012_02159644(HiddenEventContext *context) {
    switch (func_ov012_02159b5c(context, 8)) {
    default:
        return FALSE;
    case 0:
        return TRUE;
    }
}

GameEvent *func_ov012_02159658(HiddenEventArgs *args, HiddenEventContext *context) {
    return func_ov033_021785d4(context->gsys, context->field, (u8)args->x);
}

GameEvent *EventFly_Create(HiddenEventArgs *args, HiddenEventContext *context) {
    func_ov012_0216002c(0x13);
    return func_ov033_02178908(context->gsys, context->field, (u32)args->gsys);
}

u32 EventFly_Check(HiddenEventContext *context) {
    if (func_ov012_02159b5c(context, 4) != 0) {
        if (func_ov012_02159440(context) != 0) {
            return 3;
        }
        return 0;
    }
    return 1;
}

u32 EventFlash_Check(HiddenEventContext *context) {
    switch (func_ov012_02159b5c(context, 5)) {
    default:
        return FALSE;
    case 0:
        return TRUE;
    }
}

GameEvent *EventFlash_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;

    event = GameEvent_Create(context->gsys, NULL, EventFlash_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}
