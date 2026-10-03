#include "field/event_battle_video.h"
#include "field/event_wifibattlematch.h"
#include "field/field_script.h"
#include "gfl/overlay.h"
#include "system/game_event.h"
#include "system/game_system.h"

BOOL func_ov012_02157a78(VM *vm, FieldScriptEnv *env) {
    FieldScriptEnv_GetScriptWork(env);
    FieldScriptEnv_GetGameSystem(env);
    return TRUE;
}

BOOL s0160_NetConnectWiFiBattle(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    GameSystem *gsys;
    u16 battleType;
    u16 mode;
    u32 type;
    u32 option;
    EventWifiBattleMatchArgs args;
    GameEvent *event;

    work = FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    battleType = ScriptReadAny(vm, env);
    mode = ScriptReadAny(vm, env);
    switch (battleType) {
    case 15:
        type = 0;
        break;
    case 16:
        type = 1;
        break;
    case 17:
        type = 2;
        break;
    case 18:
        type = 3;
        break;
    case 19:
        type = 4;
        break;
    }
    switch (mode) {
    case 0:
        option = 0;
        break;
    case 1:
        option = 1;
        break;
    }
    args.field = GSYS_GetField(gsys);
    args.unk4 = 1;
    args.unk8 = option;
    args.unkC = type;
    event = GameEvent_CreateOverlayDelegate(gsys, OVERLAY_ID(2), EventWifiBattleMatch_CreateFromArgs, &args);
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

BOOL s0161_NetConnectBattleVideo(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    GameSystem *gsys;
    u16 mode;
    EventBattleVideoArgs args;
    GameEvent *event;

    work = FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    mode = ScriptReadAny(vm, env);
    if (mode == 0) {
        mode = 1;
    } else {
        mode = 2;
    }
    args.field = GSYS_GetField(gsys);
    args.mode = mode;
    event = GameEvent_CreateOverlayDelegate(gsys, OVERLAY_ID(3), EventBattleVideo_CreateFromArgs, &args);
    ScriptWork_CallEvent(work, event);
    return TRUE;
}
