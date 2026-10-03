#include "field/field_effects.h"
#include "field/trial_house.h"
#include "system/game_event.h"
#include "system/game_system.h"

u32 func_ov033_0217b2e4(u32 unused, TrialHouseWork *work) {
    return work->initState;
}

GameEvent *func_ov033_0217b2ec(GameSystem *gsys, u32 unused, u32 mode) {
    GameEvent *event;
    TrialHouseEffectEvent *data;

    event = GameEvent_Create(gsys, NULL, func_ov033_0217b3ac, sizeof(TrialHouseEffectEvent));
    data = GameEvent_GetData(event);
    data->gsys = gsys;
    data->buffer = NULL;
    data->mode = mode;
    data->effect = func_ov036_021c6cc8(0x8015, GSYS_GetField(gsys));
    func_ov036_021c6d14(data->effect);
    return event;
}
