#include "constants/pokemon.h"
#include "field/event_irc.h"
#include "gfl/heap.h"
#include "pml/poke_party.h"
#include "save/box.h"
#include "system/game_data.h"
#include "system/game_system.h"

// Fields used here are reconstructed from the game code.
struct IRCPartyWork {
    GameSystem *gsys;
    u8 unk04[0x34];
    PokeParty *party;
    u8 unk3C[0x10];
    SaveControl *save;
};

void setPartyLv50(PokeParty *party) {
    int i;

    for (i = 0; i < PokeParty_GetPkmCount(party); i++) {
        setLevel(PokeParty_GetPkm(party, i), 50);
    }
}

void battleBoxToLv50Party(BOOL useBattleBox, IRCPartyWork *work) {
    int i;
    BattleBoxSave *battleBox;
    PartyPkm *pkm;
    PokeParty *party;

    battleBox = getBattleBox(work->save);
    if (!useBattleBox) {
        party = GameData_GetParty(GSYS_GetGameData(work->gsys));
        for (i = 0; i < PokeParty_GetPkmCount(party); i++) {
            pkm = PokeParty_GetPkm(party, i);
            if (!PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL)) {
                PokeParty_AddPkm(work->party, pkm);
            }
        }
    } else {
        party = convertBoxedPokeSetToParty(battleBox, HEAPID_GAMEEVENT);
        PokeParty_Copy(party, work->party);
        GFL_HeapFree(party);
    }
    PokeParty_RecoverAll(work->party);
    setPartyLv50(work->party);
}
