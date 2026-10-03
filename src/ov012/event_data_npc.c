#include "field/event_data.h"
#include "field/field_actor.h"

ZoneNPC *GetZoneNPCs(EventData *data) {
    return data->ptr20;
}

u32 GetZoneNPCsCount(EventData *data) {
    return data->count14;
}

void SetZoneNPCLocation(EventData *data, u32 npcId, u16 direction, u16 x, s32 y, u16 z) {
    ZoneNPC *npc;
    u16 *coords;
    u8 *base;

    if (npcId >= data->count14) {
        return;
    }
    npcId = npcId * sizeof(ZoneNPC);
    base = data->ptr20;
    npc = (ZoneNPC *)(base + npcId);
    if (npc->isRail != 0) {
        return;
    }
    coords = &npc->pos.grid.x;
    npc->direction = direction;
    coords[0] = x;
    *(s32 *)&coords[2] = y;
    coords[1] = z;
}

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
