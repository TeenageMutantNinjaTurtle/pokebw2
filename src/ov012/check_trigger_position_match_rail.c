#include "field/zone.h"

BOOL CheckTriggerPositionMatchRail(const ZoneTrigger *trigger, const RailPosition *position) {
    const u16 *values;

    if (trigger->isRail == 0) {
        return FALSE;
    }
    values = &trigger->pos.rail.componentId;
    if (values[0] == position->componentId && values[1] <= position->posFront &&
        values[1] + values[3] > position->posFront && ((const s16 *)values)[2] <= position->posSide &&
        ((const s16 *)values)[2] + values[4] > position->posSide) {
        return TRUE;
    }
    return FALSE;
}
