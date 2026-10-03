#include "constants/pokemon.h"
#include "field/field_event.h"
#include "field/field_script.h"
#include "field/player_state.h"
#include "field/zone.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "gfl/str.h"
#include "pml/item.h"
#include "pml/personal.h"
#include "pml/poke_party.h"
#include "save/box.h"
#include "save/player_info.h"
#include "save/pokedex.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/vm.h"

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

PartyPkm *GameData_MakeBoxPkm(GameData *gameData, BoxPkmCreateParams *params) {
    PlayerInfo *playerInfo;
    u32 trainerId;
    u32 pid;
    PartyPkm *pkm;
    u16 zoneId;
    u16 placeName;

    playerInfo = GetGameDataPlayerInfo(gameData);
    trainerId = getIDAsUInt(GetGameDataPlayerInfo(gameData));
    pid = PML_GenPID(trainerId, (u16)params->species, (u16)params->level, params->param18, params->param14,
                     params->param1C);
    pkm = PokeParty_NewPkm((u16)params->species, (u16)params->paramC, trainerId, 0, -1, pid, params->heapId);
    PokeParty_ChangeForme(pkm, (u16)params->level);
    PokeParty_SetParam(pkm, 6, params->param10);
    if (params->param24 != 0) {
        PokeParty_SetHiddenAbil(pkm, params->species, params->level);
    }
    if (GetItemParam((u16)params->param20, 15, params->heapId) == 4) {
        PokeParty_SetParam(pkm, 0x98, PML_ItemGetMonsBallID((u16)params->param20));
    }
    zoneId = PlayerState_GetZoneID(GameData_GetPlayerState(gameData));
    placeName = ZoneData_GetPlaceNameID(zoneId);
    PokeParty_SetupMetData(pkm, 0, playerInfo, placeName, params->heapId);
    PokeParty_RecalcStats(pkm);
    return pkm;
}

BOOL GameData_AddBoxPkm(GameData *gameData, BoxPkmCreateParams *params) {
    BoxSaveAccessor *boxes;
    PartyPkm *pkm;
    BoxPkm *boxPkm;
    PokeDexSave *dex;

    boxes = GameData_GetBoxSaveAccessor(gameData);
    if ((int)howManyTotalPokesAreInBoxes(boxes) >= 720) {
        return FALSE;
    }
    pkm = GameData_MakeBoxPkm(gameData, params);
    boxPkm = func_0201d624(pkm);
    BoxSaveAccessor_InsertPkm(boxes, boxPkm);
    dex = GameData_GetPokedex(gameData);
    addPkmToDex(dex, pkm);
    GFL_HeapFree(pkm);
    return TRUE;
}

BOOL addPkmToParty(GameData *gameData, BoxPkmCreateParams *params) {
    PokeParty *party;
    int capacity;
    PartyPkm *pkm;
    PokeDexSave *dex;

    party = GameData_GetParty(gameData);
    capacity = PokeParty_GetCapacity(party);
    if (capacity <= PokeParty_GetPkmCount(party)) {
        return FALSE;
    }
    pkm = GameData_MakeBoxPkm(gameData, params);
    PokeParty_AddPkm(party, pkm);
    dex = GameData_GetPokedex(gameData);
    addPkmToDex(dex, pkm);
    GFL_HeapFree(pkm);
    return TRUE;
}

BOOL s00F9_MoneyAdd(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    GameData_GetPlayerState(gameData);
    u32 amount = ScriptReadAny(vm, env);
    TrainerGameInfoSave *info = getTrainerCardDataBlkAddress(gameData);
    addCashToTotal(info, amount);
    return FALSE;
}

BOOL s00FA_MoneySub(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    GameData_GetPlayerState(gameData);
    u32 amount = ScriptReadAny(vm, env);
    TrainerGameInfoSave *info = getTrainerCardDataBlkAddress(gameData);
    subCashFromTotal(info, amount);
    return FALSE;
}

BOOL s00FB_MoneyCheck(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u32 amount = ScriptReadAny(vm, env);
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    GameData_GetPlayerState(gameData);
    TrainerGameInfoSave *info = getTrainerCardDataBlkAddress(gameData);
    *result = amount <= getCash(info);
    return FALSE;
}

BOOL s014A_FieldOpen(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    ScriptWork_CallEvent(work, EventFieldOpen_CreateHeadless(gsys));
    return TRUE;
}

BOOL s014B_FieldClose(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    Field *field = GSYS_GetField(gsys);
    ScriptWork_CallEvent(work, CreateFieldCloseEvent(gsys, field));
    return TRUE;
}

void CreateScrCmdOverlayProcess(VM *vm, FieldScriptEnv *env, s32 overlayId, const GameProcFunctions *functions,
                                void *resource, void (*cleanup)(ScriptOverlayWork *), void *data) {
    GameSystem *gsys;
    ScriptWork *scriptWork;
    void **heapPtr;
    ScriptOverlayWork *work;

    gsys = FieldScriptEnv_GetGameSystem(env);
    scriptWork = FieldScriptEnv_GetScriptWork(env);
    heapPtr = ScriptWork_GetUserHeapPtr(scriptWork);
    work = GFL_HeapAllocate(4, sizeof(ScriptOverlayWork), TRUE, data_ov012_0216e208, 0x8b);
    work->resource = resource;
    work->data = data;
    work->cleanup = cleanup;
    GSYS_QueueProc(gsys, overlayId, functions, resource);
    *heapPtr = work;
    VM_SetNativeCallback(vm, (VMCommand)func_ov012_02157554);
}

BOOL func_ov012_02157554(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    ScriptWork *scriptWork;
    ScriptOverlayWork *work;

    gsys = FieldScriptEnv_GetGameSystem(env);
    scriptWork = FieldScriptEnv_GetScriptWork(env);
    work = ScriptWork_GetUserHeap(scriptWork);
    if (GSYS_GetProcMgrState(gsys) != 0) {
        return FALSE;
    }
    if (work->cleanup != NULL) {
        work->cleanup(work);
    } else {
        if (work->resource != NULL) {
            GFL_HeapFree(work->resource);
        }
        if (work->data != NULL) {
            GFL_HeapFree(work->data);
        }
    }
    ScriptWork_FreeUserHeap(scriptWork);
    return TRUE;
}

BOOL s014C_RTFreeUserHeap(VM *vm, FieldScriptEnv *env) {
    ScriptWork_FreeUserHeap(FieldScriptEnv_GetScriptWork(env));
    return TRUE;
}

struct BagScriptResult {
    u16 *hasSelection;
    u16 *item;
};

struct BagProcessData {
    u8 padding[0x44];
    void *selection;
    u32 item;
};

void func_ov012_021575b8(ScriptOverlayWork *work) {
    BagProcessData *bag = work->resource;
    BagScriptResult *result = work->data;
    if (bag->selection == NULL) {
        *result->hasSelection = FALSE;
    } else {
        *result->hasSelection = TRUE;
    }
    *result->item = bag->item;
    GFL_HeapFree(work->data);
    GFL_HeapFree(work->resource);
}
