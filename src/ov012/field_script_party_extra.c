#include "constants/pokemon.h"
#include "field/field_script.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "gfl/str.h"
#include "pml/personal.h"
#include "pml/poke_party.h"
#include "pml/species_names.h"
#include "save/pokedex.h"
#include "system/game_data.h"
#include "system/game_system.h"

BOOL s0117_PokePartySetForme(VM *vm, FieldScriptEnv *env) {
    u16 index = ScriptReadAny(vm, env);
    u16 forme = ScriptReadAny(vm, env);
    FieldScriptEnv_GetScriptWork(env);
    GameData *gameData = GSYS_GetGameData(FieldScriptEnv_GetGameSystem(env));
    PartyPkm *pkm = PokeParty_GetPkm(GameData_GetParty(gameData), index);
    PokeParty_ChangeForme(pkm, forme);
    PokeDex_RegistPkm(GameData_GetPokedex(gameData), pkm);
    return FALSE;
}

BOOL s011C_PokePartyChangeRotomForme(VM *vm, FieldScriptEnv *env) {
    u16 index = ScriptReadAny(vm, env);
    u16 forme = ScriptReadAny(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    FieldScriptEnv_GetScriptWork(env);
    GameData *gameData = GSYS_GetGameData(FieldScriptEnv_GetGameSystem(env));
    PartyPkm *pkm = PokeParty_GetPkm(GameData_GetParty(gameData), index);
    PML_PkmChangeRotomForme(pkm, slot, forme);
    PokeDex_RegistPkm(GameData_GetPokedex(gameData), pkm);
    return FALSE;
}

BOOL s01D5_MoveReminderCheckPkm(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    HeapID heapId = FieldScriptEnv_GetHeapID(env);
    PartyPkm *pkm;
    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        u16 *moves = PokeParty_GetRememberableMoves(pkm, heapId);
        *result = doesPkmHaveLevelMoveToLearn(moves);
        GFL_HeapFree(moves);
    }
    return FALSE;
}

BOOL s0119_PokePartyIsFromWhiteForest(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    u16 city = ScriptReadAny(vm, env);
    u16 metLocation = GetScrPokeStat(env, index, 0x95);
    if (metLocation == data_ov012_0216ca04[city]) {
        *result = TRUE;
    } else {
        *result = FALSE;
    }
    return FALSE;
}

BOOL s011A_PokePartyGetMetDate(VM *vm, FieldScriptEnv *env) {
    u16 *year = ScriptReadVar(vm, env);
    u16 *month = ScriptReadVar(vm, env);
    u16 *day = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;

    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        *year = PokeParty_GetParam(pkm, 0x92, NULL);
        *month = PokeParty_GetParam(pkm, 0x93, NULL);
        *day = PokeParty_GetParam(pkm, 0x94, NULL);
    } else {
        *year = 0;
        *month = 0;
        *day = 0;
    }
    return FALSE;
}

BOOL s0111_PokePartySetIV(VM *vm, FieldScriptEnv *env) {
    u16 index = ScriptReadAny(vm, env);
    u16 param = ScriptReadAny(vm, env);
    u16 value = ScriptReadAny(vm, env);
    u32 i;

    for (i = 0; i < 6; i++) {
        if (param == data_ov012_0216ca1a[2 * i]) {
            if (value <= data_ov012_0216ca1c[2 * i]) {
                PartyPkm *pkm;
                if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
                    PokeParty_SetParam(pkm, param, value);
                    PokeParty_RecalcStats(pkm);
                }
            }
            return FALSE;
        }
    }
    return FALSE;
}

BOOL s0110_PokePartyGetParam(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    u16 param = ScriptReadAny(vm, env);
    u32 i;

    for (i = 0; i < 20; i++) {
        if (param == data_ov012_0216ca06[i]) {
            *result = GetScrPokeStat(env, index, param);
            return FALSE;
        }
    }
    *result = 0;
    return FALSE;
}

BOOL s0122_BoxAdd(VM *vm, FieldScriptEnv *env) {
    GameData *gameData;
    HeapID heapId;
    u16 *result;
    u16 species;
    u16 level;
    u16 paramC;
    BoxPkmCreateParams params;

    FieldScriptEnv_GetGameSystem(env);
    gameData = FieldScriptEnv_GetGameData(env);
    heapId = FieldScriptEnv_GetHeapID(env);
    GameData_GetParty(gameData);
    GetGameDataPlayerInfo(gameData);
    result = ScriptReadVar(vm, env);
    species = ScriptReadAny(vm, env);
    level = ScriptReadAny(vm, env);
    paramC = ScriptReadAny(vm, env);
    params.heapId = heapId;
    params.species = species;
    params.level = level;
    params.paramC = paramC;
    params.param10 = 0;
    params.param14 = 2;
    params.param18 = 2;
    params.param1C = 2;
    params.param20 = 4;
    *result = GameData_AddBoxPkm(gameData, &params);
    return FALSE;
}

BOOL s0123_BoxAddEx(VM *vm, FieldScriptEnv *env) {
    GameData *gameData;
    HeapID heapId;
    u16 *result;
    u16 species;
    u16 level;
    u16 paramC;
    u16 param14;
    u16 param18;
    u16 param1C;
    u16 param10;
    u16 param20;
    BoxPkmCreateParams params;

    FieldScriptEnv_GetGameSystem(env);
    gameData = FieldScriptEnv_GetGameData(env);
    heapId = FieldScriptEnv_GetHeapID(env);
    GameData_GetParty(gameData);
    GetGameDataPlayerInfo(gameData);
    result = ScriptReadVar(vm, env);
    species = ScriptReadAny(vm, env);
    level = ScriptReadAny(vm, env);
    paramC = ScriptReadAny(vm, env);
    param14 = ScriptReadAny(vm, env);
    param18 = ScriptReadAny(vm, env);
    param1C = ScriptReadAny(vm, env);
    param10 = ScriptReadAny(vm, env);
    param20 = ScriptReadAny(vm, env);
    params.heapId = heapId;
    params.species = species;
    params.level = level;
    params.paramC = paramC;
    params.param10 = param10;
    params.param14 = param14;
    if (params.param14 >= 3)
        params.param14 = 2;
    params.param18 = param18;
    if (params.param18 >= 3)
        params.param18 = 2;
    params.param1C = param1C;
    if (params.param1C >= 3)
        params.param1C = 2;
    params.param20 = param20;
    *result = GameData_AddBoxPkm(gameData, &params);
    return FALSE;
}

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