#include "field/field_script.h"
#include "field/unity_tower.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/vm.h"

BOOL s02DE_UnityTowerSetHobby(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    u8 hobby;
    UnityTowerSurveySave *save;

    FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    hobby = ScriptReadAny(vm, env);
    save = getUnityTower_SurveySaveBlkAddrress(GameData_GetSaveControl(GSYS_GetGameData(gsys)));
    setPlayerSurveys(save, hobby);
    return FALSE;
}

BOOL s02DF_UnityTowerGetHobby(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    u16 *result;
    UnityTowerSurveySave *save;

    FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    result = ScriptReadVar(vm, env);
    save = getUnityTower_SurveySaveBlkAddrress(GameData_GetSaveControl(GSYS_GetGameData(gsys)));
    *result = getPlayerSurveys(save);
    return FALSE;
}

BOOL s02DB_UnityTowerSetFloor(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    u16 floor;
    u16 value;

    FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    floor = ScriptReadAny(vm, env);
    value = ScriptReadAny(vm, env);
    func_ov033_0217aa1c(gsys, floor, value);
    return FALSE;
}

BOOL s02DC_UnityTowerInitVisitorMessage(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    GameSystem *gsys;
    u8 *save;
    WordSet *wordSet;
    u16 index;
    u16 param;
    u16 *result;

    work = FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    save = GameData_GetUnityTowerSave(GSYS_GetGameData(gsys));
    wordSet = ScriptWork_GetWordSet(work);
    index = ScriptReadAny(vm, env);
    param = VM_Read16(vm);
    result = ScriptReadVar(vm, env);
    *result = func_ov033_0217aad8(wordSet, gsys, save, index, param);
    return FALSE;
}

BOOL func_ov036_021c9d24(VM *vm, FieldScriptEnv *env) {
    u16 *result;
    GameSystem *gsys;

    result = ScriptReadVar(vm, env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    *result = UnityTowerVisitor_GetCountry(GetGameDataPlayerInfo(GSYS_GetGameData(gsys))) != 0;
    return FALSE;
}
