#include "field/field_script.h"
#include "save/config.h"
#include "save/save_control.h"
#include "system/game_data.h"

BOOL s00E0_GameGetVersion(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);
#if defined(BLACK2)
    *value = 23;
#else
    *value = 22;
#endif
    return FALSE;
}

BOOL func_ov012_02155608(VM *vm, FieldScriptEnv *env) {
    GameData *gameData;
    SaveControl *save;
    TrainerDataSave *trainerData;
    u32 mode;

    gameData = FieldScriptEnv_GetGameData(env);
    save = GameData_GetSaveControl(gameData);
    trainerData = getTrainerDataBlkAddress(save);
    mode = func_02008a84(trainerData);
    if (mode == 0) {
        mode = 1;
    } else if (mode == 1) {
        mode = 0;
    }
    func_02008a8c((Config *)trainerData, mode);
    return FALSE;
}

BOOL func_ov012_02155638(VM *vm, FieldScriptEnv *env) {
    GameData *gameData;
    SaveControl *save;
    TrainerDataSave *trainerData;
    u16 *value;

    gameData = FieldScriptEnv_GetGameData(env);
    save = GameData_GetSaveControl(gameData);
    trainerData = getTrainerDataBlkAddress(save);
    value = ScriptReadVar(vm, env);
    *value = func_02008a84(trainerData);
    return FALSE;
}
