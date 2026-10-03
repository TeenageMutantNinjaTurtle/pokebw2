#include "field/zone.h"

void GetTriggerCenterPos_(const ZoneTrigger *trigger, VecFx32 *position) {
    const u16 *values;
    fx32 y;
    fx32 x;
    fx32 z;

    values = &trigger->pos.grid.x;
    z = (values[1] << 16) + FX_Div(values[3] << 16, 2 << 12);
    y = ((const s16 *)values)[4] << 12;
    x = (values[0] << 16) + FX_Div(values[2] << 16, 2 << 12);
    position->z = z;
    position->x = x;
    position->y = y;
}

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