#include "app/name_entry.h"
#include "field/event_phrase_input.h"
#include "field/field_event.h"
#include "gfl/overlay.h"
#include "gfl/str.h"
#include "save/player_info.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_system.h"

GameEvent *EventPhraseInput_Create(GameSystem *gsys, Field *field, GameEvent *parent, u32 mode, u32 arg4) {
    GameEvent *event;
    struct EventPhraseInputData *data;
    SaveControl *save;
    const u16 *name;

    event = GameEvent_Create(gsys, parent, EventPhraseInput_Callback, sizeof(struct EventPhraseInputData));
    data = GameEvent_GetData(event);
    data->gsys = gsys;
    data->gameData = GSYS_GetGameData(gsys);
    data->field = field;
    data->unk1C = arg4;
    data->mode = mode;
    data->heapId = 4;
    save = GameData_GetSaveControl(data->gameData);
    data->trainerInfo = getTrainerGameInfoAddress(save);
    save = GameData_GetSaveControl(data->gameData);
    data->saveBlock = func_020114f0(save);
    data->playerInfo = GetGameDataPlayerInfo(data->gameData);
    data->unk18 = func_020174d4(data->gameData);
    data->nameMode = mode;
    data->nameGender = getTrainerGender(data->playerInfo);
    data->trainerInfoForName = data->trainerInfo;
    data->saveBlockForName = data->saveBlock;
    if (mode == 14 || mode == 15) {
        data->maxLength = 8;
    } else {
        data->maxLength = data_ov033_0217c400[mode - 5];
    }
    data->input = GFL_StrBufCreate(data->maxLength + 1, data->heapId);
    data->unk4C = 0;
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        goto done;
    case 5:
        name = func_0200c93c(data->trainerInfo);
        break;
    case 6:
        name = func_0200c954(data->trainerInfo);
        break;
    case 15:
        name = func_0201150c(data->saveBlock);
        break;
    default:
        goto done;
    }
    GFL_StrBufLoadString(data->input, name);
done:
    return event;
}

GameEventReturnCode EventPhraseInput_Callback(GameEvent *event, u32 *state, void *eventData) {
    struct EventPhraseInputData *data = eventData;

    switch (*state) {
    case 0:
        GameEvent_ChainNext(event, EventFieldSubprocessTransition_Create(data->gsys, data->field, OVERLAY_ID(280),
                                                                         &NAME_ENTRY_PROC_FUNCTIONS, &data->nameMode));
        (*state)++;
        break;
    case 1:
        func_ov033_02177734(data, &data->nameMode);
        GFL_StrBufFree(data->input);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}