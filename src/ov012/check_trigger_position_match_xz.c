#include "field/zone.h"

BOOL CheckTriggerPositionMatchXZ(const ZoneTrigger *trigger, const VecFx32 *position) {
    s32 x;
    s32 z;
    const u16 *values;

    if (trigger->isRail == 1) {
        return FALSE;
    }
    values = &trigger->pos.grid.x;
    x = (position->x >> 4) / 4096;
    z = (position->z >> 4) / 4096;
    if (values[0] <= x && values[0] + values[2] > x && values[1] <= z && values[1] + values[3] > z) {
        return TRUE;
    }
    return FALSE;
}
