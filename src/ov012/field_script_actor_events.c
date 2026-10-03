#include "field/event_sound.h"
#include "field/field_script.h"
#include "field/field_sound.h"
#include "system/game_data.h"
#include "system/game_system.h"

BOOL s002E_ActorsPauseAll(VM *vm, FieldScriptEnv *env) {
    return PauseEventMModels(vm, env);
}

BOOL s002F_ActorsUnpauseAll(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    GameData *gameData = GSYS_GetGameData(gsys);
    BOOL wait = FALSE;

    EnableAllActorsMovementScr(env);
    if (FieldSnd_BGMGetStackIndex(GameData_GetFieldSoundSystem(gameData)) != 0) {
        ScriptWork_CallEvent(work, EventBGMPopAll_Create(gsys, 0));
        wait = TRUE;
    }
    return wait;
}

BOOL s0030_FinishAllEvents(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameEvent *event;

    FieldScriptEnv_GetGameSystem(env);
    event = EventFinishScriptSubEvents_Create(env);
    if (event == NULL) {
        return TRUE;
    }
    ScriptWork_CallEvent(work, event);
    return TRUE;
}
