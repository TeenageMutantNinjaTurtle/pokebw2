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
    u8 unused02[2];
    GameSystem *gameSystem;
    GameData *gameData;
    Field *field;
    void *msgBGSys;
    void *window;
    MsgData *message;
    WordSet *wordSet;
};

u16 detectLengthSinceLastSession(SaveControl *save);
void *func_0200ec2c(SaveControl *save);
void func_0200ca84(TrainerGameInfoSave *info, u8 value);
void func_0200ca94(TrainerGameInfoSave *info, u8 index, u8 value);
void func_0200caa8(TrainerGameInfoSave *info, u8 index, u16 value);
void func_0202c22c(u32 value);
void *func_0200ec38(void *survey);
void func_0200ec80(void *survey, u8 question, u32 answer);
void func_0202d0a0(void *survey);
u16 func_ov012_02165330(SaveControl *save);
u16 func_ov012_021653d8(SaveControl *save, u8 index);
u32 func_ov012_02165310(u16 index);
u32 func_ov012_021652dc(u16 index);
void func_ov012_021652ec(u16 index, u8 *answers);
u32 func_ov012_02165480(void *survey, u8 answer);
u32 func_ov012_02165320(u8 index);
u32 func_ov012_021652cc(u16 value);
u16 func_ov027_02170758(SaveControl *save);
u16 func_ov027_021707b8(SaveControl *save);
GameEvent *func_ov027_02170860(GameSystem *gsys);
void func_ov027_02170884(SurveyTextWork *work, GameSystem *gsys);
u32 func_0200ed90(void *survey, u16 question, int answer);
u32 func_0200ed48(void *survey, u16 question, int answer);
int GetSurveyAnswerMsgIDCount(u16 question);
u16 GetSurveyAnswerMsgID(u16 question, int answer);

void probabilityLoop(SurveyProbabilityState *state);
void insideProbabilityLoop(SurveyProbabilityState *state, u32 selection);
void getSurveyText(SurveyTextWork *work);
void func_ov027_021708d0(SurveyTextWork *work);
void func_ov027_021708e0(SurveyTextWork *work);
void func_ov027_02170934(SurveyTextWork *work);
void func_ov027_02170944(SurveyTextWork *work);
void func_ov027_02170954(SurveyTextWork *work);
void func_ov027_02170964(SurveyTextWork *work);
void func_ov027_02170a1c(SurveyTextWork *work);
u32 func_ov027_02170a38(SurveyTextWork *work);
u32 func_ov027_02170a4c(SurveyTextWork *work);
u32 func_ov027_02170a60(SurveyTextWork *work);
void func_0202d0d8(u8 value);
BOOL func_ov027_021703a8(VM *vm, FieldScriptEnv *env);
BOOL func_ov027_021703dc(VM *vm, FieldScriptEnv *env);
BOOL s01FF_SurveyGetCurrentQuestionID(VM *vm, FieldScriptEnv *env);
BOOL s0200_SurveyGetCurrentAnswerIDs(VM *vm, FieldScriptEnv *env);
BOOL s0204_SurveyGetTime(VM *vm, FieldScriptEnv *env);
BOOL func_ov027_021704e0(VM *vm, FieldScriptEnv *env);
BOOL func_ov027_02170580(VM *vm, FieldScriptEnv *env);
BOOL s0201_SurveyGetPopularOptionMsgID(VM *vm, FieldScriptEnv *env);
BOOL func_ov027_02170650(VM *vm, FieldScriptEnv *env);
BOOL func_ov027_02170698(VM *vm, FieldScriptEnv *env);
BOOL func_ov027_021706bc(VM *vm, FieldScriptEnv *env);
BOOL func_ov027_0217070c(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_SURVEY_H
