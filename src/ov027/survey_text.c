#include "types.h"
#include "field/field.h"
#include "field/festival.h"
#include "field/survey.h"
#include "gfl/bmpwin.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "gfl/str.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "system/game_data.h"

void getSurveyText(SurveyTextWork *work) {
    work->message = GFL_MsgSysLoadData(FALSE, 3, 0x33, work->heapId);
}

void func_ov027_021708d0(SurveyTextWork *work) {
    GFL_MsgDataFree(work->message);
    work->message = NULL;
}

void func_ov027_021708e0(SurveyTextWork *work) {
    u32 first;
    u32 second;
    u32 third;
    u32 mode = func_ov027_02170a38(work);

    switch (mode) {
    case 0:
        first = 1;
        second = 30;
        third = 4;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        first = 1;
        second = 30;
        third = 8;
        break;
    }
    work->window = FieldMsgBG_CreateMoneyWin(work->msgBGSys, (u32)work->message, first, first, second, third);
}

void func_ov027_02170934(SurveyTextWork *work) {
    func_ov036_02187c1c(work->window);
    work->window = NULL;
}

void func_ov027_02170944(SurveyTextWork *work) {
    work->wordSet = GFL_WordSetSystemCreateDefault(work->heapId);
}

void func_ov027_02170954(SurveyTextWork *work) {
    GFL_WordSetSystemFree(work->wordSet);
    work->wordSet = NULL;
}

void func_ov027_02170964(SurveyTextWork *work) {
    StrBuf *source;
    StrBuf *formatted;
    u32 kind;
    u32 num1;
    u32 num2;
    u32 msgId;
    PlayerInfo *player;
    BmpWin *window;

    source = GFL_StrBufCreate(256, work->heapId);
    formatted = GFL_StrBufCreate(256, work->heapId);
    kind = func_ov027_02170a38(work);
    num1 = func_ov027_02170a4c(work);
    num2 = func_ov027_02170a60(work);
    msgId = GetTrainerCardTextMSGID(kind);
    player = GetGameDataPlayerInfo(work->gameData);
    copyVarForText(work->wordSet, 0, player);
    WordSetNumber(work->wordSet, 1, num1, 5, 1, 1);
    WordSetNumber(work->wordSet, 2, num2, 5, 1, 1);
    GFL_MsgDataLoadStrbuf(work->message, msgId, source);
    GFL_WordSetFormatStrbuf(work->wordSet, formatted, source);
    GFL_WordSetClearAll(work->wordSet);
    func_ov036_02187c4c(work->window, 8, 0, formatted);
    window = func_ov036_02187c9c(work->window);
    GFL_BGSysLoadScr(BmpWin_GetBGIndex(window));
    GFL_StrBufFree(source);
    GFL_StrBufFree(formatted);
}

void func_ov027_02170a1c(SurveyTextWork *work) {
    func_ov036_02187c7c(work->window);
    GFL_BGSysLoadScr(BmpWin_GetBGIndex(func_ov036_02187c9c(work->window)));
}

u32 func_ov027_02170a38(SurveyTextWork *work) {
    return func_0200c96c(getTrainerCardData_wrapper(GameData_GetSaveControl_(work->gameData)));
}

u32 func_ov027_02170a4c(SurveyTextWork *work) {
    return func_0200c924(getTrainerCardData_wrapper(GameData_GetSaveControl_(work->gameData)));
}

u32 func_ov027_02170a60(SurveyTextWork *work) {
    return func_0200c90c(getTrainerCardData_wrapper(GameData_GetSaveControl_(work->gameData)));
}
