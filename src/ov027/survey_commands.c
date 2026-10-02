#include "types.h"
#include "field/field_script.h"
#include "field/survey.h"
#include "save/save_control.h"
#include "system/game_data.h"

BOOL s01FF_SurveyGetCurrentQuestionID(VM *vm, FieldScriptEnv *env) {
    TrainerGameInfoSave *info;
    u16 *out;

    FieldScriptEnv_GetScriptWork(env);
    info = getTrainerGameInfoAddress(GameData_GetSaveControl(FieldScriptEnv_GetGameData(env)));
    out = ScriptReadVar(vm, env);
    *out = func_0200ca7c(info);
    return FALSE;
}

BOOL s0200_SurveyGetCurrentAnswerIDs(VM *vm, FieldScriptEnv *env) {
    TrainerGameInfoSave *info;
    u16 *first;
    u16 *second;
    u16 *third;

    FieldScriptEnv_GetScriptWork(env);
    info = getTrainerGameInfoAddress(GameData_GetSaveControl(FieldScriptEnv_GetGameData(env)));
    first = ScriptReadVar(vm, env);
    second = ScriptReadVar(vm, env);
    third = ScriptReadVar(vm, env);
    *first = func_0200ca8c(info, 0);
    *second = func_0200ca8c(info, 1);
    *third = func_0200ca8c(info, 2);
    return FALSE;
}

BOOL s0204_SurveyGetTime(VM *vm, FieldScriptEnv *env) {
    SaveControl *save;
    u16 *out;

    FieldScriptEnv_GetScriptWork(env);
    save = GameData_GetSaveControl(FieldScriptEnv_GetGameData(env));
    out = ScriptReadVar(vm, env);
    *out = detectLengthSinceLastSession(save);
    return FALSE;
}
