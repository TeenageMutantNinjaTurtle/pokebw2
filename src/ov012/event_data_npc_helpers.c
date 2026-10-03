#include "field/event_data.h"
#include "field/field_actor.h"
#include "field/zone.h"

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

u32 ConvDirToTriggerDir(u32 dir) {
    switch (dir) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 4;
    default:
        return 0;
    }
}
