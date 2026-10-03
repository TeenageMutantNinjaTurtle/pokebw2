#ifndef POKEBW2_FIELD_SURVEY_H
#define POKEBW2_FIELD_SURVEY_H

// Survey function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0).

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

struct SurveyProbabilityState {
    u8 selection[6];
    u8 probability[6];
    u16 score;
    u16 bonus;
};

struct SurveyProbabilityEntry {
    u8 selection;
    u8 requiredScore;
    u8 probability;
    u8 flags;
};

struct SurveyTextWork {
    HeapID heapId;
    u8 unused[0x16];
    MsgData *message;
};

extern const SurveyProbabilityEntry data_ov027_02170e40[];

u16 detectLengthSinceLastSession(SaveControl *save);
void *func_0200ec2c(SaveControl *save);
u32 func_0200ed90(void *survey, u16 question, int answer);
u32 func_0200ed48(void *survey, u16 question, int answer);
int GetSurveyAnswerMsgIDCount(u16 question);
u16 GetSurveyAnswerMsgID(u16 question, int answer);

void probabilityLoop(SurveyProbabilityState *state);
void insideProbabilityLoop(SurveyProbabilityState *state, u32 selection);
void getSurveyText(SurveyTextWork *work);
void func_0202d0d8(u8 value);
BOOL func_ov027_021703a8(VM *vm, FieldScriptEnv *env);
BOOL func_ov027_021703dc(VM *vm, FieldScriptEnv *env);
BOOL s01FF_SurveyGetCurrentQuestionID(VM *vm, FieldScriptEnv *env);
BOOL s0200_SurveyGetCurrentAnswerIDs(VM *vm, FieldScriptEnv *env);
BOOL s0204_SurveyGetTime(VM *vm, FieldScriptEnv *env);
BOOL s0201_SurveyGetPopularOptionMsgID(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_SURVEY_H
