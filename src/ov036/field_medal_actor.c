#include "field/field.h"
#include "field/field_actor.h"
#include "field/medal.h"
#include "system/game_data.h"

FieldActor *GetMrMedalActorIndex(Field *field) {
    MMSys *actorSystem;
    u32 index;
    FieldActor *actor;

    index = 0;
    actorSystem = Field_GetActorSystem(field);
    if (NextActor(actorSystem, &actor, &index) == TRUE) {
        do {
            if (FldAct_GetSCRID(actor) == 0x298e) {
                return actor;
            }
        } while (NextActor(actorSystem, &actor, &index) == TRUE);
    }
    return NULL;
}

u32 GetMrMedalActorUID(GameData *gameData) {
    EventData *eventData;
    ZoneNPC *npcs;
    s32 count;
    s32 i;

    eventData = GameData_GetEventData(gameData);
    npcs = GetZoneNPCs(eventData);
    count = GetZoneNPCsCount(eventData);
    if (npcs == NULL || count == 0) {
        return -1;
    }
    for (i = 0; i < count; i++) {
        if (npcs[i].scrId == 0x298e) {
            return *(u16 *)((u8 *)npcs + i * sizeof(ZoneNPC));
        }
    }
    return -1;
}