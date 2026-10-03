#include "field/festival.h"
#include "field/field_event.h"
#include "field/field_script.h"
#include "field/funfest_scripts.h"
#include "system/game_system.h"

BOOL s0279_FunfestBGMReturn(VM *vm, FieldScriptEnv *env) {
    ScriptWork *scriptWork = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    void *gimmick = Field_GetFesGimmick(GSYS_GetField(gsys));
    LinkFestival *festival = GSYS_GetLinkFestival(gsys);
    u32 bgm;

    if (getStatusOfFesMission(festival) == 0) {
        return TRUE;
    }
    func_ov036_021b6690(gimmick);
    bgm = LinkFestival_GetNormalChangeBGMID(festival);
    if (bgm != (u32)-1) {
        ScriptWork_CallEvent(scriptWork, EventBGMPlay_Create(gsys, bgm));
    }
    return TRUE;
}

BOOL s0276_FunfestMissionBroadcast(VM *vm, FieldScriptEnv *env) {
    u8 type;
    u16 value;

    FieldScriptEnv_GetScriptWork(env);
    FieldScriptEnv_GetGameSystem(env);
    type = ScriptReadAny(vm, env);
    value = ScriptReadAny(vm, env);
    func_ov012_0216063c(type, value);
    return TRUE;
}
