#include "field/event_data.h"

void *GetZoneProxiesAndCount(EventData *data, u32 *restrict count) {
    *count = data->entityCount;
    return data->entityPtr;
}
