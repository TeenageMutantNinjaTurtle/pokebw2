#include "types.h"
#include "field/field.h"
#include "field/field_script.h"
#include "field/gimmick_underground_ruins.h"
#include "field/ov129.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/vm.h"

// Script plugin 16 (overlay 68), commands from 1000. The first three drive zone 565's gimmick (overlay 114), the
// others the gimmick of zones 53 and 614 (overlay 129)

typedef struct {
    Field *field;
} Plugin16WaitData;

static BOOL func_ov068_021e5800(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);

    func_ov114_021eecd8(gsys, ScriptReadAny(vm, env));
    return FALSE;
}

static BOOL func_ov068_021e582c(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);

    func_ov114_021eed34(gsys, ScriptReadAny(vm, env));
    return FALSE;
}

static BOOL func_ov068_021e5854(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);

    func_ov114_021eeda0(gsys, ScriptReadAny(vm, env));
    return FALSE;
}

static BOOL func_ov068_021e587c(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameEvent *event = func_ov129_021ef3c4(FieldScriptEnv_GetGameSystem(env));

    if (event == NULL) {
        return FALSE;
    }
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

static BOOL func_ov068_021e58a4(VM *vm, FieldScriptEnv *env) {
    func_ov129_021ef3dc(FieldScriptEnv_GetGameSystem(env));
    return FALSE;
}

static BOOL func_ov068_021e58b4(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    Field *field = GSYS_GetField(FieldScriptEnv_GetGameSystem(env));
    FieldPlayer *player = Field_GetPlayer(field);

    func_ov129_021ef078(field, ScriptReadAny(vm, env));
    return FALSE;
}

// Waits for func_ov129_021ef104 to return TRUE
static GameEventReturnCode func_ov068_021e58e4(GameEvent *event, u32 *state, void *data) {
    Plugin16WaitData *wait = data;

    if (func_ov129_021ef104(wait->field) == TRUE) {
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

static BOOL func_ov068_021e58f8(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    Field *field = GSYS_GetField(gsys);
    GameEvent *event = GameEvent_Create(gsys, NULL, func_ov068_021e58e4, sizeof(Plugin16WaitData));
    Plugin16WaitData *wait = GameEvent_GetData(event);

    wait->field = field;
    if (event == NULL) {
        return FALSE;
    }
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

static BOOL func_ov068_021e5940(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);

    func_ov129_021ef120(GSYS_GetField(FieldScriptEnv_GetGameSystem(env)));
    return FALSE;
}

const FieldScriptCommand PLUGIN_16_SCRIPT_COMMANDS[] = {
    func_ov068_021e5800, func_ov068_021e582c, func_ov068_021e5854,
    func_ov068_021e587c, func_ov068_021e58a4, func_ov068_021e58b4,
    func_ov068_021e58f8, func_ov068_021e5940, (FieldScriptCommand)0xFFFFFFFF,
};
