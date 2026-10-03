#include "field/trial_house.h"
#include "system/game_event.h"
#include "system/version.h"

struct TrialHouseEventData {
    u32 code;
    u8 flag4;
    u8 pad5;
    u16 id;
    u32 size;
    void *saveBuffer;
    u32 region;
    u32 mask;
    u8 pad18[0x60];
    u32 active;
    u32 unk7c;
    GameSystem *gsys;
    TrialHouseWork *work;
    u32 arg;
    u32 zero;
};

GameEvent *func_ov033_0217aee8(GameSystem *gsys, TrialHouseWork *work, u32 arg) {
    GameEvent *event;
    struct TrialHouseEventData *data;

    event = GameEvent_Create(gsys, NULL, func_ov033_0217af5c, sizeof(struct TrialHouseEventData));
    data = GameEvent_GetData(event);
    data->gsys = gsys;
    data->arg = arg;
    data->work = work;
    data->zero = 0;
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
