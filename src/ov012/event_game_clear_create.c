#include "field/encounter.h"
#include "field/event_game_clear.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"

GameEvent *EventGameClear_Create(GameSystem *gsys, void *param) {
    GameData *gameData = GSYS_GetGameData(gsys);
    GameEvent *event = GameEvent_Create(gsys, NULL, EventGameClear_Callback, sizeof(GameClearWork));
    GameClearWork *work = GameEvent_GetData(event);

    work->gameSystem = gsys;
    work->gameData = gameData;
    work->unk08 = (u32)param;
    work->unk10 = GetGameDataPlayerInfo(gameData);
    work->unkC4 = 0;
    work->unk14 = gsys;
    work->unk18 = param;
    func_ov012_02159220(gameData);
    SetGameClearGameData(work);
    func_ov012_0215a50c(work);
    work->unk3C = gameData;
    work->unk38 = 0;
#ifdef BLACK2
    work->unk40 = 1;
#else
    work->unk40 = 0;
#endif
    SetGameClearStatusSequence(work);
    return event;
}
