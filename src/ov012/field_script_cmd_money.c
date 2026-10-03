#include "field/field_script.h"
#include "save/save_control.h"
#include "system/game_data.h"

BOOL s00F9_MoneyAdd(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    GameData_GetPlayerState(gameData);
    u32 amount = ScriptReadAny(vm, env);
    TrainerGameInfoSave *info = getTrainerCardDataBlkAddress(gameData);
    addCashToTotal(info, amount);
    return FALSE;
}

BOOL s00FA_MoneySub(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    GameData_GetPlayerState(gameData);
    u32 amount = ScriptReadAny(vm, env);
    TrainerGameInfoSave *info = getTrainerCardDataBlkAddress(gameData);
    subCashFromTotal(info, amount);
    return FALSE;
}

BOOL s00FB_MoneyCheck(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u32 amount = ScriptReadAny(vm, env);
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    GameData_GetPlayerState(gameData);
    TrainerGameInfoSave *info = getTrainerCardDataBlkAddress(gameData);
    *result = amount <= getCash(info);
    return FALSE;
}
