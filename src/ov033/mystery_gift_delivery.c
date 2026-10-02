#include "field/mystery_gift_delivery.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "system/game_data.h"

#define MYSTERY_GIFT_DELIVERY_MAN_OBJ_CODE 0x46

u16 GetActorIDOfMysteryGiftDeliveryMan(Field *field, GameData *gameData) {
    FieldActor *actor = FindMysteryGiftDeliveryManActor(field);
    if (actor != NULL) {
        return GetActorUID(actor);
    }

    s32 npcID = FindMysteryGiftDeliveryManNPCID(gameData);
    if (npcID >= 0) {
        return npcID;
    }
    return 0;
}

u16 IsMysteryGiftDeliveryManActorAvailable(Field *field) {
    return FindMysteryGiftDeliveryManActor(field) != NULL;
}

FieldActor *FindMysteryGiftDeliveryManActor(Field *field) {
    u32 index = 0;
    FieldActor *actor;
    MMSys *actorSystem = Field_GetActorSystem(field);

    while (NextActor(actorSystem, &actor, &index) == TRUE) {
        if (FldAct_GetObjCode(actor) == MYSTERY_GIFT_DELIVERY_MAN_OBJ_CODE) {
            return actor;
        }
    }
    return NULL;
}

s32 FindMysteryGiftDeliveryManNPCID(GameData *gameData) {
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
        if (npcs[i].modelId == MYSTERY_GIFT_DELIVERY_MAN_OBJ_CODE) {
            return *(u16 *)((u8 *)npcs + i * sizeof(ZoneNPC));
        }
    }
    return -1;
}
