#include "types.h"
#include "field/field_script.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/vm.h"

BOOL s02EE_MusicalIsPropOwned(VM *vm, FieldScriptEnv *env) {
    u16 prop = ScriptReadAny(vm, env);
    u16 *result = ScriptReadVar(vm, env);
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    MusicalSave *save = getMusicalInfoBlkAddress(gameData);
    *result = func_0200ad60(save, prop);
    return FALSE;
}

BOOL s02EF_MusicalGetOwnedPropCount(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    MusicalSave *save = getMusicalInfoBlkAddress(gameData);
    *result = func_0200ae58(save);
    return FALSE;
}
