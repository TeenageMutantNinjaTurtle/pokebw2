#ifndef POKEBW2_FIELD_MYSTERY_GIFT_DELIVERY_H
#define POKEBW2_FIELD_MYSTERY_GIFT_DELIVERY_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"

u16 GetActorIDOfMysteryGiftDeliveryMan(Field *field, GameData *gameData);
u16 IsMysteryGiftDeliveryManActorAvailable(Field *field);
FieldActor *FindMysteryGiftDeliveryManActor(Field *field);
s32 FindMysteryGiftDeliveryManNPCID(GameData *gameData);

#endif // POKEBW2_FIELD_MYSTERY_GIFT_DELIVERY_H
