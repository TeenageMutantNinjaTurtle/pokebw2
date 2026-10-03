#include "types.h"
#include "field/black_tower_gimmick.h"
#include "field/event_save.h"
#include "gfl/std.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"

GameEvent *EventSave_Create(GameSystem *gsys, Field *field, u16 code, u32 arg3, EventSaveArgs *args, u32 *result) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventSave_Callback, sizeof(EventSaveWork));
    EventSaveWork *work = GameEvent_GetData(event);
    GameData *gameData;

    sys_memset(work, 0, sizeof(EventSaveWork));
    work->arg3 = arg3;
    work->code = code;
    work->gameSystem = gsys;
    work->field = field;
    gameData = GSYS_GetGameData(gsys);
    work->save = GameData_GetSaveControl(gameData);
    work->args = args;
    work->result = result;
    return event;
}

GameEventReturnCode EventSave_Callback(GameEvent *event, u32 *state, void *data) {
    EventSaveWork *work = data;
    u32 result = EventSave_Update(work);

    switch (result) {
    case 0:
        *work->result = 1;
        return GAMEEVENT_DONE;
    case 1:
        *work->result = 0;
        return GAMEEVENT_DONE;
    default:
        return GAMEEVENT_CONTINUE;
    }
}

void func_ov012_0215c574(EventSaveWork *work) {
    EventSaveArgs *args = work->args;
    GameEvent *event = func_ov127_021f1c80(args->gameSystem, args->field, args->unkC, &work->code);
    GameEvent_ChainNext((GameEvent *)work->result, event);
}
