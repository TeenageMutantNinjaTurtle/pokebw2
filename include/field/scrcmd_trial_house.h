#ifndef POKEBW2_FIELD_SCRCMD_TRIAL_HOUSE_H
#define POKEBW2_FIELD_SCRCMD_TRIAL_HOUSE_H

// Overlay 12's scrcmd_trial_house.c (a descriptive name): the Trial House's script commands, 0x1E6 to 0x1F5. Names from
// swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"
#include "system/vm.h"

BOOL s01E6_TrialHouseWorkInit(VM *vm, FieldScriptEnv *env);
BOOL s01E7_TrialHouseWorkDelete(VM *vm, FieldScriptEnv *env);
BOOL s01E8_TrialHousePrepareParty(VM *vm, FieldScriptEnv *env);
BOOL s01E9_TrialHouseCallTeamSelect(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_02164564(VM *vm, FieldScriptEnv *env);
BOOL s01EB_TrialHouseMsgDisp(VM *vm, FieldScriptEnv *env);
BOOL s01EC_TrialHouseStartBattle(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_0216462c(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_0216465c(VM *vm, FieldScriptEnv *env);
BOOL s01EF_TrialHouseGetBattleTestRank(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_021646cc(VM *vm, FieldScriptEnv *env);
BOOL s01F1_TrialHouseCalcPointsStars(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_0216474c(VM *vm, FieldScriptEnv *env);
BOOL s01F3_TrialHouseSaveData(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_021647c4(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_0216480c(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_SCRCMD_TRIAL_HOUSE_H
