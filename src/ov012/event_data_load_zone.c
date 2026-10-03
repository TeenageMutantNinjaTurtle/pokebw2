#include "field/event_data.h"

void EventData_LoadZone(EventData *data, u16 zoneId, u8 season) {
    EventData_Reset(data);
    EventData_LoadEntities(data, zoneId, season);
    EventData_LoadEncData(data, zoneId, season);
}
