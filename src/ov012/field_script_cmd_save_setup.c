#include "field/field_script.h"
#include "save/config.h"
#include "save/event_work.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_system.h"

BOOL s00E2_SaveDataCheckRequired(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    GameData *gameData = GSYS_GetGameData(gsys);
    SaveControl *save = GameData_GetSaveControl(gameData);
    TrainerDataSave *config = getTrainerDataBlkAddress(save);
    u16 *value = ScriptReadVar(vm, env);

    switch (func_02008ac8(config)) {
    case 0:
        *value = 0;
        break;
    case 1:
        *value = 1;
        break;
    }
    return FALSE;
}

BOOL s00E3_GiveRunningShoes(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    EventWork_FlagSet(GameData_GetEventWork(gameData), 0x963);
    return FALSE;
}
