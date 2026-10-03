#include "field/event_data.h"
#include "field/field_actor.h"

ZoneNPC *GetZoneNPCs(EventData *data) {
    return data->ptr20;
}

u32 GetZoneNPCsCount(EventData *data) {
    return data->count14;
}
