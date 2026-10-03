#include "field/field_event.h"
#include "field/pc_sound.h"
#include "gfl/overlay.h"
#include "system/game_system.h"

struct PCSubprocessEventData {
    GameSystem *gsys;
    Field *field;
    GameData *gameData;
    u16 option;
    u16 selection;
    u16 *result;
};

GameEvent *func_ov033_02179868(GameSystem *gsys, u16 option, u16 *result) {
    GameEvent *event;
    struct PCSubprocessEventData *data;

    event = GameEvent_Create(gsys, NULL, func_ov033_021798a0, sizeof(struct PCSubprocessEventData));
    data = GameEvent_GetData(event);
    data->gsys = gsys;
    data->field = GSYS_GetField(gsys);
    data->result = result;
    data->gameData = GSYS_GetGameData(gsys);
    data->option = option;
    return event;
}

GameEventReturnCode func_ov033_021798a0(GameEvent *event, u32 *state, void *eventData) {
    struct PCSubprocessEventData *data;
    GameEvent *next;

    data = eventData;
    switch (*state) {
    case 0:
        next = EventFieldSubprocessTransition_Create(data->gsys, data->field, OVERLAY_ID(256), &data_ov182_021bd8e4,
                                                     &data->gameData);
        GameEvent_ChainNext(event, next);
        (*state)++;
        break;
    case 1:
        switch (data->selection) {
        case 0:
            *data->result = 0;
            break;
        case 1:
            *data->result = 1;
            break;
        }
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}
