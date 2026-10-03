#include "field/badge_gate.h"
#include "save/event_work.h"

BOOL func_ov103_021eefbc(u32 badge, EventWork *work) {
    u16 *value;

    value = EventWork_GetWkPtr(work, data_ov103_021ef854[badge]);
    return *value == 2;
}
