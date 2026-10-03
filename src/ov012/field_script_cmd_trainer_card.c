#include "field/field_script.h"
#include "field/player_state.h"
#include "nitro/rtc.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "system/game_data.h"

BOOL s00D4_TrainerCardGetBirthDate(VM *vm, FieldScriptEnv *env) {
    u16 *month;
    u16 *day;
    u8 date[0x58];

    month = ScriptReadVar(vm, env);
    day = ScriptReadVar(vm, env);
    func_0207c3bc(date);
    *month = date[2];
    *day = date[3];
    return FALSE;
}

BOOL s00E1_TrainerCardGetSex(VM *vm, FieldScriptEnv *env) {
    u16 *value;
    GameData *gameData;
    PlayerState *state;

    value = ScriptReadVar(vm, env);
    gameData = FieldScriptEnv_GetGameData(env);
    state = GameData_GetPlayerState(gameData);
    *value = getTrainerGender(&state->playerInfo);
    return FALSE;
}

BOOL s00D5_TrainerCardHasBadge(VM *vm, FieldScriptEnv *env) {
    u16 *value;
    u16 badgeId;
    GameData *gameData;
    TrainerCardSave *card;

    value = ScriptReadVar(vm, env);
    badgeId = ScriptReadAny(vm, env);
    gameData = FieldScriptEnv_GetGameData(env);
    card = getTrainerCardDataBlkAddress(gameData);
    *value = isBadgeObtained(card, badgeId);
    return FALSE;
}

BOOL s00D6_TrainerCardAddBadge(VM *vm, FieldScriptEnv *env) {
    u16 badgeId;
    GameData *gameData;
    TrainerCardSave *card;
    RTCDate date;
    void *timeSig;

    badgeId = ScriptReadAny(vm, env);
    gameData = FieldScriptEnv_GetGameData(env);
    card = getTrainerCardDataBlkAddress(gameData);
    addBadge(card, badgeId);
    RTC_GetCachedDate(&date);
    timeSig = getTimeSigSaveBlock(gameData);
    setBadgeGetSecondsTime(timeSig, badgeId, date.year, date.month, date.day);
    return FALSE;
}

BOOL s00D7_TrainerCardGetBadgeCount(VM *vm, FieldScriptEnv *env) {
    u16 *value;
    GameData *gameData;
    TrainerCardSave *card;

    value = ScriptReadVar(vm, env);
    gameData = FieldScriptEnv_GetGameData(env);
    card = getTrainerCardDataBlkAddress(gameData);
    *value = getBadgeCount(card);
    return FALSE;
}
