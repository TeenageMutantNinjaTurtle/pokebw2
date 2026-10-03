#include "field/hidden_event.h"
#include "field/zone.h"

HiddenCheckFunc GetHidenEventCheckFunc(HiddenEventContext *context, u32 kind) {
    if ((s32)kind >= 11) {
        return NULL;
    }
    if (IsZoneAbyssalRuinsInside(context->unk00)) {
        return HIDEN_EVENTS_RUINS[kind].check;
    }
    return HIDEN_EVENTS_NORMAL[kind].check;
}

HiddenCtorFunc GetHidenEventCtorFunc(HiddenEventContext *context, u32 kind) {
    if ((s32)kind >= 11) {
        return NULL;
    }
    if (IsZoneAbyssalRuinsInside(context->unk00)) {
        return HIDEN_EVENTS_RUINS[kind].create;
    }
    return HIDEN_EVENTS_NORMAL[kind].create;
}
