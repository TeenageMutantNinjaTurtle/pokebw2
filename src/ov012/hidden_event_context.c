#include "field/hidden_event.h"

void func_ov012_02159b40(HiddenEventData *data, HiddenEventArgs *param, HiddenEventContext *context) {
    u32 packedCoords;
    u32 extra;

    data->unk00 = (void *)0x19740205;
    data->unk04 = *(u32 *)&context->unk0C;
    packedCoords = *(u32 *)param;
    extra = (u32)param->gsys;
    data->unk10 = extra;
    *(u32 *)&data->unk0C = packedCoords;
    data->gsys = context->gsys;
}

u32 func_ov012_02159b5c(HiddenEventContext *context, u32 value) {
    u16 flags = context->flags;
    u32 mask = 1 << value;
    return (flags & mask) ? TRUE : FALSE;
}
