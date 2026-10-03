#include "field/field_script.h"
#include "system/game_data.h"

BOOL s00CD_RTCGetDayPart(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    u16 *value = ScriptReadVar(vm, env);
    *value = GameData_GetDayPeriod(gameData);
    return FALSE;
}

BOOL s00CF_RTCGetWeekDay(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    u16 *value = ScriptReadVar(vm, env);
    *value = getCurrentDayOfWeek(gameData);
    return FALSE;
}

BOOL s00D0_RTCGetDate(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    u16 *month = ScriptReadVar(vm, env);
    u16 *day = ScriptReadVar(vm, env);
    *month = GameData_GetMonth(gameData);
    *day = GameData_GetDay(gameData);
    return FALSE;
}

BOOL s00D1_RTCGetTime(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    u16 *hour = ScriptReadVar(vm, env);
    u16 *minute = ScriptReadVar(vm, env);
    *hour = getCurrentHour(gameData);
    *minute = getCurrentMinute(gameData);
    return FALSE;
}

BOOL s00D2_RTCGetSeason(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    *value = GameData_GetSeason(gameData);
    return FALSE;
}
