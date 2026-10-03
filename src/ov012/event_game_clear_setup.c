#include "field/event_game_clear.h"
#include "save/config.h"
#include "save/save_control.h"
#include "system/game_data.h"

void SetGameClearGameData(GameClearWork *work) {
    work->party = GameData_GetParty(work->gameData);
    work->playerInfo = GetGameDataPlayerInfo(work->gameData);
    work->unk24 = func_02017a40(work->gameData);
}

void func_ov012_0215a50c(GameClearWork *work) {
    u32 value;

    work->unk28 = work->unk08 == 1;
    work->unk30 = GetGameDataPlayerInfo(work->gameData);
    value = func_02008a84(getTrainerDataBlkAddress(GameData_GetSaveControl(work->gameData)));
    work->unk2C = value;
    work->unk34 = value;
}
