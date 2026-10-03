#include "types.h"
#include "field/field_script.h"
#include "field/survey.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "system/game_data.h"

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
