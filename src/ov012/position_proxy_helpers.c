#include "field/event_data.h"
#include "field/zone.h"

s32 CheckProxyEntityEventGrid(EventData *data, EventWork *eventWork, const VecFx32 *position, u16 direction) {
    return CheckProxyEntityEvent(data, eventWork, position, direction);
}

s32 CheckProxyEntityEventRail(EventData *data, EventWork *eventWork, const RailPosition *position, u16 direction) {
    return CheckProxyEntityEvent(data, eventWork, position, direction);
}

void func_ov012_0215d4d0(const ZoneBGEntity *entity, VecFx32 *position) {
    func_ov012_0215d88c(entity, position);
    position->x += 0x8000;
    position->z += 0x8000;
}
