#include "field/pc_sound.h"

GameEvent *func_ov033_02179b24(GameEvent *parent, GameSystem *gsys, Field *field, u32 skipSound) {
    GameEvent *event;
    struct PCSoundEventData *data;

    event = GameEvent_Create(gsys, parent, pcLogOffSound, sizeof(struct PCSoundEventData));
    data = GameEvent_GetData(event);
    data->gameSystem = gsys;
    data->field = field;
    data->pcProp = NULL;
    data->skipSound = skipSound;
    return event;
}
