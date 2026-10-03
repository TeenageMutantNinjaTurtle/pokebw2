#include "field/battle_facility.h"
#include "field/trial_house.h"
#include "gfl/input.h"
#include "gfl/net.h"
#include "save/trial_house.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/version.h"

u32 func_ov033_0217aed0(TrialHouseWork *work) {
    return func_ov012_02162b38(*(u16 *)((u8 *)work + 4));
}

GameEvent *func_ov033_0217aedc(GameSystem *gsys, TrialHouseWork *work, u32 actorId, u32 messageId) {
    return func_ov012_02161e6c(gsys, work, actorId, (u16)messageId);
}

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

GameEventReturnCode func_ov033_0217af5c(GameEvent *event, u32 *state, void *arg) {
    TrialHouseEventData *data;
    GameSystem *gsys;
    GameData *gameData;
    void *save;
    void *saveBuffer;
    u32 a;
    u32 b;
    u32 c;

    data = arg;
    gsys = data->gsys;
    switch (*state) {
    case 0:
        data->subwork = func_ov012_02152990(data);
        if (func_ov012_02152b64(data->subwork) == 0) {
            *data->result = 0;
            *state = 4;
        } else {
            *state = 1;
        }
        break;
    case 1:
        if (GCTX_HIDGetPressedKeys() == 2) {
            *data->result = 3;
            *state = 4;
            break;
        }
        func_ov012_02152bec(data->subwork);
        data->timeout++;
        if (data->timeout > 120) {
            *state = 2;
        }
        break;
    case 2:
        if (GCTX_HIDGetPressedKeys() == 2) {
            *data->result = 3;
            *state = 4;
            break;
        }
        func_ov012_02152bec(data->subwork);
        if (func_ov012_02152bb4(data->subwork)) {
            *state = 3;
        } else {
            *data->result = 0;
            *state = 4;
        }
        break;
    case 3:
        if (GCTX_HIDGetPressedKeys() == 2) {
            *data->result = 3;
            *state = 4;
            break;
        }
        func_ov012_02152bec(data->subwork);
        if (!func_ov012_02152bd4(data->subwork)) {
            break;
        }
        gameData = GSYS_GetGameData(gsys);
        save = func_0200f1b8(GameData_GetSaveControl(gameData));
        saveBuffer = data->work->saveBuffer;
        a = func_0200ee7c(saveBuffer);
        b = func_0200ee38(saveBuffer);
        c = func_ov033_0217b35c(save, a);
        if (b != 0 && (c == 0 || a == 0)) {
            func_ov033_0217b384(save, a);
            func_0200eea0(gameData, data->work->saveBuffer, 0x8004);
            *data->result = 1;
        } else if (c != 0) {
            *data->result = 2;
        } else {
            *data->result = 0;
        }
        *state = 4;
        break;
    case 4:
        func_ov012_02152bfc(data->subwork);
        *state = 5;
        break;
    case 5:
        if (func_02042ab8()) {
            *state = 6;
        }
        break;
    case 6:
        func_ov033_0217acd4(gsys, data->work);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}