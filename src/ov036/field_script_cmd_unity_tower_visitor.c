#include "field/field_script.h"
#include "field/unity_tower.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/vm.h"

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
