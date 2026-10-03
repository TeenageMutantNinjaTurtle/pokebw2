#include "types.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "field/day_care.h"
#include "field/field_script.h"
#include "pml/poke_party.h"
#include "save/box.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/vm.h"

BOOL s00EB_DayCareCheckSpawnFlag(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    *result = DayCare_CheckSpawnFlag(dayCare);
    return FALSE;
}

BOOL s00EC_DayCareBreed(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_Breed(dayCare, party);
    return FALSE;
}

BOOL s00ED_DayCareResetSeed(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_CheckResetSeed(dayCare);
    return FALSE;
}

BOOL s00F7_DayCareCallPokeSelect(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    u16 *result = ScriptReadVar(vm, env);
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    Field *field = GSYS_GetField(gsys);
    GameData_GetParty(gameData);
    getDaycareBlockAddress(GameData_GetSaveControl(gameData));
    ScriptWork_CallEvent(work, EventDayCarePokeSelect_Create(gsys, field, result));
    return TRUE;
}

BOOL s00F0_DayCareDeposit(VM *vm, FieldScriptEnv *env) {
    u16 slot = ScriptReadAny(vm, env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_AddPkm(dayCare, party, slot);
    return FALSE;
}

BOOL s00F1_DayCareWithdraw(VM *vm, FieldScriptEnv *env) {
    u16 slot = ScriptReadAny(vm, env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_RemovePkm(dayCare, slot, party);
    return FALSE;
}

BOOL s00EE_DayCareGetPkmCount(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    *result = DayCare_GetPkmCount(dayCare);
    return FALSE;
}

BOOL s00EF_DayCareCalcEggSpawnChance(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    *result = DayCare_CalcEggSpawnChance(dayCare);
    return FALSE;
}

BOOL s00F2_DayCareGetSpecies(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    PartyPkm *pkm = DayCare_GetPkm(dayCare, slot);
    *result = PokeParty_GetParam(pkm, PKM_PARAM_SPECIES, NULL);
    return FALSE;
}

BOOL s00F3_DayCareGetForme(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    PartyPkm *pkm = DayCare_GetPkm(dayCare, slot);
    *result = PokeParty_GetParam(pkm, PKM_PARAM_FORM, NULL);
    return FALSE;
}

BOOL s00F8_DayCareGetSex(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    PartyPkm *pkm = DayCare_GetPkm(dayCare, slot);
    *result = PokeParty_GetParam(pkm, PKM_PARAM_SEX, NULL);
    return FALSE;
}

BOOL s00F4_DayCareCalcNewLevel(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    *result = DayCare_CalcNewLevel(dayCare, slot);
    return FALSE;
}

BOOL s00F5_DayCareCalcLevelGain(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_GetPkm(dayCare, slot);
    *result = DayCare_CalcLevelGain(dayCare, slot);
    return FALSE;
}

BOOL s00F6_DayCareCalcWithdrawCost(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_GetPkm(dayCare, slot);
    *result = DayCare_CalcWithdrawCost(dayCare, slot);
    return FALSE;
}

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
    case 2:
    default:
        return 0;
    case 0:
        return 1;
    case 1:
        return 2;
    }
}

