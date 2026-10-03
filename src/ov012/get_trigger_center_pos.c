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
