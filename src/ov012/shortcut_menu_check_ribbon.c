#include "constants/pokemon.h"
#include "field/shortcut_menu.h"
#include "pml/poke_party.h"
#include "system/game_data.h"
#include "system/game_system.h"

BOOL CheckAnyRibbon(ShortcutMenuWork *work) {
    GameData *gameData = GSYS_GetGameData(work->gameSystem);
    PokeParty *party = GameData_GetParty(gameData);
    int i;

    for (i = 0; i < PokeParty_GetPkmCount(party); i++) {
        PartyPkm *pkm = PokeParty_GetPkm(party, i);

        if (PokeParty_GetParam(pkm, PKM_PARAM_SPECIES_VALID, NULL) != 0 && PokeParty_CheckAnyRibbon(pkm) != 0) {
            return TRUE;
        }
    }
    return FALSE;
}
