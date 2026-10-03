#include "field/event_data.h"
#include "gfl/std.h"

void EventData_Clear(EventData *data) {
    data->prevEntityCount = 0;
    data->prevCount14 = 0;
    data->prevWarpCount = 0;
    data->prevCount18 = 0;
    data->entityCount = 0;
    data->count14 = 0;
    data->warpCount = 0;
    data->count18 = 0;
    data->entityPtr = NULL;
    data->ptr20 = NULL;
    data->warpPtr = NULL;
    data->ptr28 = NULL;
    sys_memset(data->cache, 0, sizeof(data->cache));
}

void *GetEncountData(EventData *data) {
    return data->encData;
}
