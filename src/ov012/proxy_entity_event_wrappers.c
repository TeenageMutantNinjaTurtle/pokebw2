#include "field/event_data.h"
#include "field/zone.h"

s32 CheckProxyEntityEventGrid(EventData *data, EventWork *eventWork, const VecFx32 *position, u16 direction) {
    return CheckProxyEntityEvent(data, eventWork, position, direction);
}

s32 CheckProxyEntityEventRail(EventData *data, EventWork *eventWork, const RailPosition *position, u16 direction) {
    return CheckProxyEntityEvent(data, eventWork, position, direction);
}
