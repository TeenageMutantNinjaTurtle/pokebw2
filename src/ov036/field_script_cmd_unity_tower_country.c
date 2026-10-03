#include "field/field_script.h"
#include "field/unity_tower.h"
#include "system/game_data.h"
#include "system/game_system.h"

BOOL func_ov036_021c9d24(VM *vm, FieldScriptEnv *env) {
    u16 *result;
    GameSystem *gsys;

    result = ScriptReadVar(vm, env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    *result = UnityTowerVisitor_GetCountry(GetGameDataPlayerInfo(GSYS_GetGameData(gsys))) != 0;
    return FALSE;
}
