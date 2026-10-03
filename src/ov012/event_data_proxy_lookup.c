#include "field/event_data.h"
#include "field/zone.h"

u32 GetTriggerSCRIDAtPosGrid(EventData *data, EventWork *eventWork, const VecFx32 *position, u32 direction) {
    u16 *trigger = FindTriggerAtPosGrid(data, eventWork, position, direction);
    return trigger != NULL ? *trigger : 0xffff;
}

u32 GetSCRIDOfCollidingTriggerAtLocation(EventData *data, EventWork *eventWork, const VecFx32 *position) {
    u16 *trigger = FindCollidingZoneTriggerAtLocation(data, eventWork, position);
    return trigger != NULL ? *trigger : 0xffff;
}

u32 GetTriggerSCRIDAtPosRail(EventData *data, EventWork *eventWork, const RailPosition *position) {
    u16 *trigger = FindTriggerAtPosRail(data, eventWork, position);
    return trigger != NULL ? *trigger : 0xffff;
}

void *GetZoneProxiesAndCount(EventData *data, u32 *restrict count) {
    *count = data->entityCount;
    return data->entityPtr;
}
