#include "field/trial_house.h"
#include "save/trial_house.h"
#include "system/game_event.h"
#include "system/version.h"

GameEvent *func_ov033_0217aee8(GameSystem *gsys, TrialHouseWork *work, u32 arg) {
    GameEvent *event;
    struct TrialHouseEventData *data;

    event = GameEvent_Create(gsys, NULL, func_ov033_0217af5c, sizeof(struct TrialHouseEventData));
    data = GameEvent_GetData(event);
    data->gsys = gsys;
    data->result = (u16 *)arg;
    data->work = work;
    data->timeout = 0;
    data->code = 0x2e;
    data->size = func_0200ee20();
    data->saveBuffer = work->saveBuffer;
    data->region = region;
#ifdef BLACK2
    data->mask = 0x800000;
#else
    data->mask = 0x400000;
#endif
    data->active = 1;
    data->flag4 = 0;
    data->id = 0x8015;
    return event;
}
