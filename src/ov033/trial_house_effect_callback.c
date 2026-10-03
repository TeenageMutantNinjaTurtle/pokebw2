#include "field/field_effects.h"
#include "field/trial_house.h"
#include "gfl/heap.h"
#include "gfl/std.h"
#include "save/save_control.h"
#include "save/trial_house.h"
#include "system/game_data.h"
#include "system/game_system.h"

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
