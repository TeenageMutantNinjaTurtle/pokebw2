#include "types.h"
#include "field/field_script.h"
#include "save/save_control.h"
#include "system/game_data.h"

extern void *func_0200ec2c(SaveControl *save);
extern u32 func_0200ed90(void *survey, u16 question, int answer);
extern u32 func_0200ed48(void *survey, u16 question, int answer);
extern int GetSurveyAnswerMsgIDCount(u16 question);
extern u16 GetSurveyAnswerMsgID(u16 question, int answer);

BOOL s0201_SurveyGetPopularOptionMsgID(VM *vm, FieldScriptEnv *env);

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
