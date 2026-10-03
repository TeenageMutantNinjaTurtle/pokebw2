#include "constants/pokemon.h"
#include "field/event_game_clear.h"
#include "gfl/std.h"
#include "pml/poke_party.h"
#include "save/medal_box.h"
#include "system/game_data.h"
#include "system/game_system.h"

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
