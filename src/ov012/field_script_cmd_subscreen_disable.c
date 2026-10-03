#include "field/field_script.h"
#include "system/game_data.h"
#include "system/game_system.h"

BOOL s024B_FieldSubscreenDisable(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    func_02016b40(gsys, 0);
    func_0201740c(GSYS_GetGameData(gsys), 0);
    return FALSE;
}
