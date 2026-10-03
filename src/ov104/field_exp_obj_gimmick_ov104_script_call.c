#include "field/field_exp_obj_gimmick_ov104.h"
#include "field/field_script.h"
#include "gfl/sound.h"
#include "system/game_system.h"

BOOL func_ov104_021efb90(VM *vm, FieldScriptEnv *env) {
    ScriptWork *scriptWork;
    GameSystem *gsys;
    Field *field;
    u32 id;
    GameEvent *event;

    scriptWork = FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    field = GSYS_GetField(gsys);
    id = ScriptReadAny(vm, env);
    GFL_SndSEPlay(0x547);
    event = func_ov104_021f02fc(gsys, field, id);
    ScriptWork_CallEvent(scriptWork, event);
    return TRUE;
}
