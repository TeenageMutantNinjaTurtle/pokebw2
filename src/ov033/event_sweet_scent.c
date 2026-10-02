#include "field/event_sweet_scent.h"
#include "field/field.h"
#include "gfl/std.h"
#include "system/game_data.h"
#include "system/game_system.h"

typedef struct SweetScentEventData {
    u8 partySlot;
    u8 padding[3];
    GameSystem *gsys;
    GameData *gameData;
    Field *field;
    FieldPlayer *player;
} SweetScentEventData;

GameEvent *EventSweetScent_Create(Field *field, GameSystem *gsys) {
    return func_ov033_021785d4(gsys, field, 0xff);
}

GameEvent *func_ov033_021785d4(GameSystem *gsys, Field *field, u8 partySlot) {
    GameEvent *event;
    SweetScentEventData *data;

    event = GameEvent_Create(gsys, NULL, EventSweetScent_Callback, sizeof(SweetScentEventData));
    data = GameEvent_GetData(event);
    sys_memset(data, 0, sizeof(SweetScentEventData));
    data->partySlot = partySlot;
    data->gsys = gsys;
    data->field = field;
    data->player = Field_GetPlayer(field);
    data->gameData = GSYS_GetGameData(gsys);
    return event;
}
