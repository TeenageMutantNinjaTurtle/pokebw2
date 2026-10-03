#include "field/encounter.h"
#include "field/event_data.h"

void EventData_LoadEncData(EventData *data, u16 zoneId, u8 season) {
    EncData_Load(data->encData, data->encArc, zoneId, season);
    data->encLoaded = 1;
}

void *GetZoneInitScrPointer(EventData *data) {
    return data->initScript;
}

u32 IsEncountDataLoaded(EventData *data) {
    return data->encLoaded;
}
