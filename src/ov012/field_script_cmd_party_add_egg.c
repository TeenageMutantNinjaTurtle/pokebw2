#include "constants/pokemon.h"
#include "field/field_script.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "gfl/str.h"
#include "pml/personal.h"
#include "pml/poke_party.h"
#include "system/game_data.h"

BOOL s010F_PokePartyAddEgg(VM *vm, FieldScriptEnv *env) {
    GameData *gameData;
    HeapID heapId;
    PokeParty *party;
    PlayerInfo *playerInfo;
    u16 *result;
    u16 species;
    u16 form;
    PartyPkm *pkm;
    StrBuf *name;
    void *personal;
    u32 cycles;

    FieldScriptEnv_GetGameSystem(env);
    gameData = FieldScriptEnv_GetGameData(env);
    heapId = FieldScriptEnv_GetHeapID(env);
    party = GameData_GetParty(gameData);
    playerInfo = GetGameDataPlayerInfo(gameData);
    result = ScriptReadVar(vm, env);
    species = ScriptReadAny(vm, env);
    form = ScriptReadAny(vm, env);
    if (PokeParty_GetCapacity(party) <= PokeParty_GetPkmCount(party)) {
        *result = FALSE;
        return FALSE;
    }
    pkm = PokeParty_NewTempPkm(species, 1, (u64)-1, heapId);
    PokeParty_SetParam(pkm, PKM_PARAM_FORM, form);
    name = copyTrainerNameToNewStrbuf((const u16 *)GetGameDataPlayerInfo(gameData), heapId);
    PokeParty_SetParam(pkm, PKM_PARAM_OT_NAME, (u32)name);
    GFL_StrBufFree(name);
    personal = PML_PersonalLoad(PokeParty_GetParam(pkm, PKM_PARAM_SPECIES, NULL),
                                PokeParty_GetParam(pkm, PKM_PARAM_FORM, NULL), heapId);
    cycles = PML_PersonalGetParam(personal, PERSONAL_HATCH_CYCLES);
    PML_PersonalFree(personal);
    PokeParty_SetParam(pkm, PKM_PARAM_HAPPINESS, cycles);
    PokeParty_SetParam(pkm, PKM_PARAM_IS_EGG, 1);
    name = GFL_MsgDataLoadStrbufNew(g_PMLSpeciesNamesResident, SPECIES_EGG);
    PokeParty_SetParam(pkm, PKM_PARAM_NICKNAME, (u32)name);
    GFL_StrBufFree(name);
    PokeParty_RecalcStats(pkm);
    PokeParty_SetupMetData(pkm, 5, playerInfo, 0xea63, heapId);
    PokeParty_AddPkm(party, pkm);
    GFL_HeapFree(pkm);
    *result = TRUE;
    return FALSE;
}
