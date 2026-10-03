#include "field/field_effects.h"
#include "field/trial_house.h"
#include "gfl/heap.h"
#include "gfl/std.h"
#include "save/save_control.h"
#include "save/trial_house.h"
#include "system/game_data.h"
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

struct TrialHouseSave {
    u8 flag0;
    u8 pad1[0x13];
    u8 flag14;
    u8 pad15[0x13];
    u8 bits[16];
};

u32 func_ov033_0217b32c(GameSystem *gsys) {
    TrialHouseSave *save;

    save = func_0200f1b8(GameData_GetSaveControl(GSYS_GetGameData(gsys)));
    if (save->flag0) {
        if (save->flag14) {
            return 3;
        }
        return 1;
    }
    if (save->flag14) {
        return 2;
    }
    return 0;
}

u8 func_ov033_0217b35c(void *savePtr, u32 index) {
    TrialHouseSave *save;
    u8 byte;
    u8 bit;

    save = savePtr;
    if (index < 128) {
        byte = save->bits[(u8)(index >> 3)];
        bit = index & 7;
        return (byte >> bit) & 1;
    }
    return TRUE;
}

void func_ov033_0217b384(void *savePtr, u32 index) {
    TrialHouseSave *save;
    u8 byteIndex;
    u8 bit;
    u8 mask;

    save = savePtr;
    if (index < 128) {
        byteIndex = index >> 3;
        bit = index & 7;
        mask = 1 << bit;
        save->bits[byteIndex] |= mask;
    }
}

GameEventReturnCode func_ov033_0217b3ac(GameEvent *event, u32 *state, void *arg) {
    TrialHouseEffectEvent *data;
    GameData *gameData;
    SaveControl *save;
    void *extraSave;

    data = arg;
    gameData = GSYS_GetGameData(data->gsys);
    save = GameData_GetSaveControl(gameData);
    switch (*state) {
    case 0:
        data->buffer = GFL_HeapAllocate(0x8004, 0x800, FALSE, data_ov033_0217c630, 0x34c);
        func_02007560(save, 5, 0x8004, data->buffer, 0x800);
        extraSave = getAddressOfExtraSaveBlk(save, 5, 0);
        if (data->mode == 1) {
            func_0200ef1c(extraSave);
        } else {
            sys_memset(extraSave, 0, func_0200ee20());
        }
        func_020178c4(gameData, 5);
        (*state)++;
        break;
    case 1:
        if (func_020178f4(gameData, 5) == 2) {
            freeIntermediateSaveExtraBlksAfterLoad2(save, 5);
            GFL_HeapFree(data->buffer);
            func_ov036_021c6d3c(data->effect);
            func_ov036_021c6cf8(data->effect);
            return GAMEEVENT_DONE;
        }
        break;
    }
    return GAMEEVENT_CONTINUE;
}
