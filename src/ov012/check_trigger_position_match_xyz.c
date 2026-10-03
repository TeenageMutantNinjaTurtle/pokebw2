#include "field/zone.h"

BOOL CheckTriggerPositionMatchXYZ(const ZoneTrigger *trigger, const VecFx32 *position) {
    const u16 *values;
    s32 x;
    s32 y;
    s32 z;

    if (trigger->isRail == 1) {
        return FALSE;
    }
    values = &trigger->pos.grid.x;
    x = (position->x >> 4) / 4096;
    z = (position->z >> 4) / 4096;
    y = position->y >> 12;
    if (values[0] <= x && values[0] + values[2] > x && values[1] <= z && values[1] + values[3] > z &&
        ((const s16 *)values)[4] - 2 <= y && ((const s16 *)values)[4] + 2 > y) {
        return TRUE;
    }
    return FALSE;
}
