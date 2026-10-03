#include "constants/pokemon.h"
#include "field/field_script.h"
#include "pml/poke_party.h"
#include "system/game_data.h"

BOOL s0114_PokePartyGetCountBySpecies(VM *vm, FieldScriptEnv *env) {
    u16 species = ScriptReadAny(vm, env);
    u16 *result = ScriptReadVar(vm, env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    u16 partyCount = PokeParty_GetPkmCount(party);
    u16 count = 0;
    int i;

    if (species != 0 && species <= SPECIES_EGG - 1) {
        for (i = 0; i < partyCount; i++) {
            PartyPkm *pkm = PokeParty_GetPkm(party, i);
            if (pkm != NULL && PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == 0) {
                u16 foundSpecies = (u16)PokeParty_GetParam(pkm, PKM_PARAM_SPECIES, NULL);
                if (foundSpecies == species) {
                    count++;
                }
            }
        }
        *result = count;
    } else {
        *result = 0;
    }
    return FALSE;
}
