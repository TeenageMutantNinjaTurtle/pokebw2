#include "field/event_data.h"
#include "field/field_actor.h"

void SetZoneNPCMdlID(EventData *data, u16 npcId, u16 modelId) {
    if (npcId < data->count14) {
        ((ZoneNPC *)data->ptr20)[npcId].modelId = modelId;
    }
}

void SetZoneNPCSCRID(EventData *data, u16 npcId, u16 scrId) {
    if (npcId < data->count14) {
        ((ZoneNPC *)data->ptr20)[npcId].scrId = scrId;
    }
}
