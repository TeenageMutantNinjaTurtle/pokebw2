#include "field/event_dive.h"
#include "field/field.h"
#include "field/ov131.h"
#include "gfl/overlay.h"

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

GameEvent *func_ov033_0217a0f4(GameSystem *gsys, Field *field, u32 direction) {
    GameEvent *event;
    void **data;
    FieldPlayer *player;
    FieldActor *actor;

    event = GameEvent_Create(gsys, NULL, func_ov033_0217a184, sizeof(void *));
    data = GameEvent_GetData(event);
    GFL_OvlLoad(OVERLAY_ID(131));
    player = Field_GetPlayer(field);
    actor = FieldPlayer_GetActor(player);
    FieldPlayer_SetDirection(player, direction);
    *data = func_ov131_021eec80(gsys, field, actor, TRUE);
    return event;
}

GameEvent *func_ov033_0217a148(GameSystem *gsys, Field *field, FieldActor *actor) {
    GameEvent *event;
    void **data;

    event = GameEvent_Create(gsys, NULL, func_ov033_0217a184, sizeof(void *));
    data = GameEvent_GetData(event);
    GFL_OvlLoad(OVERLAY_ID(131));
    *data = func_ov131_021eec80(gsys, field, actor, FALSE);
    return event;
}

GameEventReturnCode func_ov033_0217a184(GameEvent *event, u32 *state, void *data) {
    void **work = GameEvent_GetData(event);

    if (func_ov131_021eed2c(*work)) {
        func_ov131_021eed18(*work);
        GFL_OvlUnload(OVERLAY_ID(131));
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}
