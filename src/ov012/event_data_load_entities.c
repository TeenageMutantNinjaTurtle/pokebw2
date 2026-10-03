#include "field/event_data.h"

void EventData_LoadEntities(EventData *data, u16 zoneId, u8 season) {
    data->zoneId = zoneId;
    LoadZoneEntities(data, zoneId, season);
}
