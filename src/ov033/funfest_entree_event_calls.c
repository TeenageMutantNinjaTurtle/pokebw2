#include "field/entree_scripts.h"
#include "field/event_funfest_mission.h"
#include "field/event_mapchange.h"
#include "field/field_script.h"
#include "field/funfest_scripts.h"

BOOL s0274_FunfestMissionStart(VM *vm, FieldScriptEnv *env) {
    ScriptWork *scriptWork = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);

    ScriptWork_CallEvent(scriptWork, func_ov033_02176d88(gsys));
    return TRUE;
}

BOOL s028B_CallEntralinkWarpOut(VM *vm, FieldScriptEnv *env) {
    ScriptWork *scriptWork = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);

    ScriptWork_CallEvent(scriptWork, EventEntralinkWarp_CreateOut(gsys));
    return TRUE;
}
