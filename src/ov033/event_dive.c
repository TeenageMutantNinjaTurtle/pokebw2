#include "field/event_dive.h"

typedef struct DiveEventData {
    GameSystem *gsys;
    Field *field;
    u32 param;
    u32 unkC;
} DiveEventData;

GameEvent *EventDiveIn_Create(GameSystem *gsys, Field *field) {
    GameEvent *event;
    DiveEventData *data;

    event = GameEvent_Create(gsys, NULL, EventDiveIn_Callback, sizeof(DiveEventData));
    data = GameEvent_GetData(event);
    data->gsys = gsys;
    data->field = field;
    data->param = 0;
    return event;
}

GameEvent *CreateDiveOutEvent(GameSystem *gsys, Field *field, u32 param) {
    GameEvent *event;
    DiveEventData *data;

    event = GameEvent_Create(gsys, NULL, EventDiveOut_Callback, sizeof(DiveEventData));
    data = GameEvent_GetData(event);
    data->gsys = gsys;
    data->field = field;
    data->param = param;
    return event;
}
