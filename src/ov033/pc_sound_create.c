#include "field/pc_sound.h"

GameEvent *CreatePCSoundCallEvent(GameEvent *parent, GameSystem *gsys, Field *field) {
    GameEvent *event = GameEvent_Create(gsys, parent, pcEntrySound, sizeof(struct PCSoundEventData));
    struct PCSoundEventData *data = GameEvent_GetData(event);

    data->gameSystem = gsys;
    data->field = field;
    data->pcProp = NULL;
    return event;
}
