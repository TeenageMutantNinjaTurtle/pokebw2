#include "field/field_event.h"
#include "field/field_script.h"
#include "pml/poke_party.h"
#include "system/game_data.h"

BOOL s02D2_FieldOpenRestoreLCD(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    ScriptWork_CallEvent(work, EventFieldOpenRestoreLCD_Create(gsys));
    return TRUE;
}

BOOL CheckGetPartyPokemon(FieldScriptEnv *env, u32 index, PartyPkm **pkm) {
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    BOOL found;

    if (index < PokeParty_GetPkmCount(party)) {
        found = TRUE;
    } else {
        found = FALSE;
        index = 0;
    }
    *pkm = PokeParty_GetPkm(party, index);
    return found;
}

u32 GetScrPokeStat(FieldScriptEnv *env, u32 index, u32 param) {
    PartyPkm *pkm;

    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        return PokeParty_GetParam(pkm, param, NULL);
    }
    return 0;
}
