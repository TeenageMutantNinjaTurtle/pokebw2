#include "constants/pokemon.h"
#include "field/day_care.h"
#include "field/field_script.h"
#include "pml/poke_party.h"
#include "system/game_system.h"

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
