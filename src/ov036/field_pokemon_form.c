#include "field/field_pokemon_form.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "pml/poke_party.h"
#include "system/game_data.h"
#include "system/game_system.h"

void CheckResetKeldeoOrdinaryForme(GameSystem *gsys) {
    GameData *gameData;
    PokeParty *party;
    PartyPkm *pkm;
    s32 count;
    s32 index;
    s32 moveIndex;
    u32 species;
    u32 move;

    gameData = GSYS_GetGameData(gsys);
    party = GameData_GetParty(gameData);
    count = PokeParty_GetPkmCount(party);
    index = 0;
    while (index < count) {
        pkm = PokeParty_GetPkm(party, index);
        move = PokeParty_GetParam(pkm, (PkmField)PKM_PARAM_SPECIES, NULL);
        species = (u16)move;
        if (PokeParty_GetParam(pkm, (PkmField)PKM_PARAM_IS_EGG, NULL) == 0 && species == SPECIES_KELDEO &&
            PokeParty_GetParam(pkm, (PkmField)PKM_PARAM_FORM, NULL) == 1) {
            for (moveIndex = 0; moveIndex < 4; moveIndex++) {
                if (PokeParty_GetParam(pkm, (PkmField)(PKM_PARAM_MOVE1 + moveIndex), NULL) == MOVE_SECRET_SWORD) {
                    break;
                }
            }
            if (moveIndex == 4) {
                PokeParty_ChangeForme(pkm, 0);
            }
        }
        if (species > SPECIES_GENESECT) {
            ((u8 *)pkm)[0x1e] = 0xff;
            ((u8 *)pkm)[0x1f] = 0xff;
        }
        index++;
    }
}
