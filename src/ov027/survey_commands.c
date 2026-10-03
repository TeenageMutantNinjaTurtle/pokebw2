#include "types.h"
#include "field/field_script.h"
#include "field/survey.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "system/game_data.h"
#include "system/rtc.h"

BOOL func_ov027_021703a8(VM *vm, FieldScriptEnv *env) {
    TrainerGameInfoSave *info;
    u16 *out;

    FieldScriptEnv_GetScriptWork(env);
    info = getTrainerGameInfoAddress(GameData_GetSaveControl(FieldScriptEnv_GetGameData(env)));
    out = ScriptReadVar(vm, env);
    *out = func_0200c96c(info);
    return FALSE;
}

BOOL func_ov027_021703dc(VM *vm, FieldScriptEnv *env) {
    TrainerGameInfoSave *info;
    int count;

    FieldScriptEnv_GetScriptWork(env);
    info = getTrainerGameInfoAddress(GameData_GetSaveControl(FieldScriptEnv_GetGameData(env)));
    count = func_0200c96c(info);
    if (count >= 5) {
        return FALSE;
    }
    func_0200c974(info, count + 1);
    func_0202d0d8((u8)(count + 1));
    return FALSE;
}

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

BOOL func_ov027_021704e0(VM *vm, FieldScriptEnv *env) {
    SaveControl *save;
    TrainerGameInfoSave *info;
    u16 values[3];
    u16 first;
    int i;

    FieldScriptEnv_GetScriptWork(env);
    save = GameData_GetSaveControl(FieldScriptEnv_GetGameData(env));
    info = getTrainerGameInfoAddress(save);
    func_0200ec2c(save);
    first = ScriptReadAny(vm, env);
    values[0] = ScriptReadAny(vm, env);
    values[1] = ScriptReadAny(vm, env);
    values[2] = ScriptReadAny(vm, env);
    func_0200ca84(info, first);
    for (i = 0; i < 3; i++) {
        func_0200ca94(info, i, values[i]);
        func_0200caa8(info, i, 0);
    }
    // The original call passes the value already in r0 without setting up a new argument.
    setSecondsCurrentTimeInTrainerCard(info, ((s64 (*)(void))RTC_ConvertSecondsCached)());
    return FALSE;
}

BOOL func_ov027_02170580(VM *vm, FieldScriptEnv *env) {
    SaveControl *save;
    TrainerGameInfoSave *info;
    int i;

    FieldScriptEnv_GetScriptWork(env);
    save = GameData_GetSaveControl(FieldScriptEnv_GetGameData(env));
    info = getTrainerGameInfoAddress(save);
    func_0200ec2c(save);
    func_0200ca84(info, 0);
    for (i = 0; i < 3; i++) {
        func_0200ca94(info, i, 0xff);
    }
    func_0202c22c(0);
    return FALSE;
}

BOOL s0201_SurveyGetPopularOptionMsgID(VM *vm, FieldScriptEnv *env) {
    int i;
    u16 question;
    u16 *out;
    int best;
    u16 msgId;
    SaveControl *save;
    void *survey;
    int count;

    FieldScriptEnv_GetScriptWork(env);
    save = GameData_GetSaveControl(FieldScriptEnv_GetGameData(env));
    survey = func_0200ec2c(save);
    question = ScriptReadAny(vm, env);
    out = ScriptReadVar(vm, env);
    count = GetSurveyAnswerMsgIDCount(question);
    best = -1;
    for (i = 0; i < count; i++) {
        int total = func_0200ed90(survey, question, i + 1);
        total += func_0200ed48(survey, question, i + 1);
        if (best < total) {
            best = total;
            msgId = GetSurveyAnswerMsgID(question, i);
        }
    }
    *out = msgId;
    return FALSE;
}

BOOL func_ov027_02170650(VM *vm, FieldScriptEnv *env) {
    void *survey;
    u32 question;
    u32 answer;

    FieldScriptEnv_GetScriptWork(env);
    survey = func_0200ec38(func_0200ec2c(GameData_GetSaveControl(FieldScriptEnv_GetGameData(env))));
    question = ScriptReadAny(vm, env);
    answer = ScriptReadAny(vm, env);
    func_0200ec80(survey, question, answer);
    func_0202d0a0(survey);
    return FALSE;
}

BOOL func_ov027_02170698(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    GameEvent *event;

    work = FieldScriptEnv_GetScriptWork(env);
    event = func_ov027_02170860(FieldScriptEnv_GetGameSystem(env));
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

BOOL func_ov027_021706bc(VM *vm, FieldScriptEnv *env) {
    SaveControl *save;
    TrainerCardSave *card;
    u8 index;
    u16 *out;

    save = GameData_GetSaveControl(FieldScriptEnv_GetGameData(env));
    card = getTrainerCardData_wrapper(save);
    index = ScriptReadAny(vm, env);
    out = ScriptReadVar(vm, env);
    if (index == func_0200ca7c(card)) {
        *out = func_ov012_02165330(save);
    } else {
        *out = func_ov012_021653d8(save, index);
    }
    return FALSE;
}

BOOL func_ov027_0217070c(VM *vm, FieldScriptEnv *env) {
    SaveControl *save;
    TrainerCardSave *card;
    u16 *out;
    u32 kind;
    u16 result;

    save = GameData_GetSaveControl(FieldScriptEnv_GetGameData(env));
    card = getTrainerCardData_wrapper(save);
    out = ScriptReadVar(vm, env);
    kind = (u8)func_ov012_021652cc(func_0200ca7c(card));
    if (kind == 0) goto zero;
    if (kind != 1) goto done;
    result = func_ov027_021707b8(save);
    goto done;
zero:
    result = func_ov027_02170758(save);
done:
    *out = result;
    return FALSE;
}

u16 func_ov027_02170758(SaveControl *save) {
    void *survey;
    u16 index;
    u32 maximum;
    u8 count;
    u8 answers[4];
    s32 i;
    u32 minimum;

    survey = func_0200ec2c(save);
    index = func_0200ca7c(getTrainerCardData_wrapper(save));
    maximum = func_ov012_02165310(index);
    count = (u8)func_ov012_021652dc(index);
    func_ov012_021652ec(index, answers);
    minimum = 0xf694e;
    for (i = 0; i < count; i++) {
        u32 value = func_ov012_02165480(survey, answers[i]);
        if (value < minimum) minimum = value;
    }
    return maximum - minimum;
}

u16 func_ov027_021707b8(SaveControl *save) {
    u16 index;
    u16 length;
    s32 result;

    func_0200ec2c(save);
    index = func_0200ca7c(getTrainerCardData_wrapper(save));
    length = detectLengthSinceLastSession(save);
    result = func_ov012_02165320((u8)index) - length;
    if (result < 0) result = 0;
    return result;
}
