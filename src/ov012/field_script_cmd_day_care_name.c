#include "constants/pokemon.h"
#include "constants/species.h"
#include "field/day_care.h"
#include "field/field_script.h"
#include "pml/poke_party.h"
#include "system/game_system.h"

BOOL s023E_DayCareGetSexForNamePrint(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    u16 *result = ScriptReadVar(vm, env);
    u16 showSex = ScriptReadAny(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    PartyPkm *pkm = DayCare_GetPkm(dayCare, slot);
    if (showSex == 0) {
        *result = getNameGenderStatus(pkm);
    } else {
        *result = 0;
    }
    return FALSE;
}

u32 getNameGenderStatus(PartyPkm *pkm) {
    u32 species = PokeParty_GetParam(pkm, PKM_PARAM_SPECIES, NULL);
    u32 sex = PokeParty_GetParam(pkm, PKM_PARAM_SEX, NULL);
    if (species == SPECIES_NIDORAN_M || species == SPECIES_NIDORAN_F) {
        if (PokeParty_GetParam(pkm, 0x75, NULL) == 0) {
            return 0;
        }
    }
    switch (sex) {
    case 0:
        goto male;
    case 1:
        goto female;
    case 2:
        break;
    }
    return 0;
male:
    return 1;
female:
    return 2;
}
