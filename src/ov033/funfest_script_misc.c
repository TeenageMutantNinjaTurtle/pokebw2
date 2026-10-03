#include "field/festival.h"
#include "field/field_script.h"
#include "field/funfest_scripts.h"
#include "save/high_link.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_system.h"

BOOL func_ov033_021772c8(VM *vm, FieldScriptEnv *env) {
    u16 *result;
    void *missionCfg;

    result = ScriptReadVar(vm, env);
    missionCfg = GetFestMissionCfg(GSYS_GetLinkFestival(FieldScriptEnv_GetGameSystem(env)));
    if (isFesMissionAvailable(missionCfg)) {
        *result = 2;
    } else {
        *result = 0;
    }
    return FALSE;
}

BOOL func_ov033_021772f4(VM *vm, FieldScriptEnv *env) {
    u16 *result;
    HighLinkSave *save;

    result = ScriptReadVar(vm, env);
    save = getHighLinkBlockAddress(GameData_GetSaveControl(GSYS_GetGameData(FieldScriptEnv_GetGameSystem(env))));
    if (func_0200c678(save, 0) != 0x30) {
        *result = 1;
    } else {
        *result = 0;
    }
    return FALSE;
}
