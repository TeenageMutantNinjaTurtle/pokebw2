#include "constants/pokemon.h"
#include "field/field_script.h"
#include "pml/poke_party.h"
#include "system/game_data.h"

BOOL s0118_PokePartyFindBySpecies(VM *vm, FieldScriptEnv *env) {
    u16 species = ScriptReadAny(vm, env);
    u16 *found = ScriptReadVar(vm, env);
    u16 *indexOut = ScriptReadVar(vm, env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    u16 count = PokeParty_GetPkmCount(party);
    int i;

    if (species != 0 && species <= SPECIES_EGG - 1) {
        for (i = 0; i < count; i++) {
            PartyPkm *pkm = PokeParty_GetPkm(party, i);
            if (pkm != NULL && PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == 0) {
                u16 pkmSpecies = (u16)PokeParty_GetParam(pkm, PKM_PARAM_SPECIES, NULL);
                if (pkmSpecies == species) {
                    break;
                }
            }
        }
        if (i < count) {
            *found = TRUE;
            *indexOut = i;
        } else {
            *found = FALSE;
        }
    } else {
        *found = FALSE;
    }
    return FALSE;
}
