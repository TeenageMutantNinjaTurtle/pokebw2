#include "field/event_game_clear.h"
#include "constants/pokemon.h"
#include "field/encounter.h"
#include "gfl/std.h"
#include "pml/poke_party.h"
#include "save/config.h"
#include "save/medal_box.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/version.h"

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

void SetGameClearStatusSequence(GameClearWork *work) {
    u32 index = 0;

    work->states[1] = 2;
    work->states[2] = 3;
    work->states[3] = 4;
    work->states[4] = 5;
    work->states[5] = 6;
    work->states[0] = index;
    index += 6;
    if (work->unk08 == 0) {
        work->states[index++] = 11;
        work->states[index++] = 13;
    }
    work->states[index + 0] = 10;
    work->states[index + 1] = 12;
    work->states[index + 2] = 13;
    work->states[index + 3] = 19;
    work->states[index + 4] = 15;
    work->states[index + 5] = 21;
    work->states[index + 6] = 17;
    work->states[index + 7] = 4;
    work->states[index + 8] = 7;
    work->states[index + 9] = 8;
    work->states[index + 10] = 19;
    work->states[index + 11] = 16;
    work->states[index + 12] = 18;
    work->states[index + 13] = 23;
    work->states[index + 14] = 24;
    work->states[index + 15] = 4;
    work->states[index + 16] = 22;
    work->states[index + 17] = 14;
    work->states[index + 18] = 25;
    work->current = work->states[0];
}

u32 EventGameClear_Get3DDemoID(void) {
    u32 version = getGameVersion();

    if (version == 0x16) {
        goto seven;
    }
    if (version == 0x17) {
        goto six;
    }
seven:
    return 7;
six:
    return 6;
}

void EventGameClear_NextState(GameClearWork *work, u32 *state) {
    ++*state;
    work->current = work->states[*state];
}

void func_ov012_0215a670(GameClearWork *work) {
    func_0200cb08(getTrainerCardDataBlkAddress(work->gameData), 0x5a0);
}

void EventGameClear_GiveMonotypeMedals(GameClearWork *work) {
    GameData *gameData = GSYS_GetGameData(work->gameSystem);
    SaveControl *save = GameData_GetSaveControl(gameData);
    MedalBox *box = SaveControl_GetMedalBox(save);
    PokeParty *party;
    int count;
    int eligible;
    int i;
    u32 typeCounts[17];

    MedalBox_DiscoverMedal(box, 0x56);
    MedalBox_DiscoverMedal(box, 0x5a);
    party = GameData_GetParty(gameData);
    count = PokeParty_GetPkmCount(party);
    eligible = 0;
    u16 medalIds[17] = { 236, 242, 245, 243, 244, 248, 247, 249, 252, 237, 238, 240, 239, 246, 241, 250, 251 };
    sys_memset(typeCounts, 0, sizeof(typeCounts));
    for (i = 0; i < count; i++) {
        PartyPkm *pkm = PokeParty_GetPkm(party, i);
        u32 type1;
        u32 type2;
        if (PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == 1) {
            continue;
        }
        type1 = PokeParty_GetParam(pkm, PKM_PARAM_TYPE1, NULL);
        typeCounts[type1]++;
        type2 = PokeParty_GetParam(pkm, PKM_PARAM_TYPE2, NULL);
        if (type1 != type2) {
            typeCounts[type2]++;
        }
        eligible++;
    }
    for (i = 0; i < 17; i++) {
        if (eligible == typeCounts[i]) {
            MedalBox_GiveMedal(box, medalIds[i]);
        }
    }
}