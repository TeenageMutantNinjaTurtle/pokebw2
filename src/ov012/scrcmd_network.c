#include "types.h"
#include "battle/battle_result.h"
#include "battle/trainer_data.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "field/app_call.h"
#include "field/black_tower_gimmick.h"
#include "field/day_care.h"
#include "field/encounter.h"
#include "field/event_3d_demo.h"
#include "field/event_action_call.h"
#include "field/event_actor_move.h"
#include "field/event_battle_lose.h"
#include "field/event_battle_video.h"
#include "field/event_chatot.h"
#include "field/event_data.h"
#include "field/event_fly.h"
#include "field/event_game_clear.h"
#include "field/event_irc.h"
#include "field/event_mapchange.h"
#include "field/event_save.h"
#include "field/event_sound.h"
#include "field/event_sweet_scent.h"
#include "field/event_wifibattlematch.h"
#include "field/field.h"
#include "field/field_acmd.h"
#include "field/field_actor.h"
#include "field/field_chunk.h"
#include "field/field_event.h"
#include "field/field_map.h"
#include "field/field_menu.h"
#include "field/field_player.h"
#include "field/field_script.h"
#include "field/field_script_event.h"
#include "field/field_script_plugin.h"
#include "field/field_script_supervisor.h"
#include "field/field_sound.h"
#include "field/field_status.h"
#include "field/field_visuals.h"
#include "field/hidden_event.h"
#include "field/item_use_block.h"
#include "field/player_action.h"
#include "field/player_state.h"
#include "field/pleasure_boat.h"
#include "field/script_network.h"
#include "field/shortcut_menu.h"
#include "field/skill_map_effect.h"
#include "field/stadium_script.h"
#include "field/subscreen.h"
#include "field/trainer_script.h"
#include "field/zone.h"
#include "gfl/arc.h"
#include "gfl/g3d.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/input.h"
#include "gfl/msg.h"
#include "gfl/overlay.h"
#include "gfl/random.h"
#include "gfl/sound.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "nitro/fx.h"
#include "nitro/os.h"
#include "nitro/rtc.h"
#include "pml/item.h"
#include "pml/move_reminder.h"
#include "pml/personal.h"
#include "pml/poke_party.h"
#include "save/bag.h"
#include "save/box.h"
#include "save/config.h"
#include "save/encounter.h"
#include "save/event_work.h"
#include "save/medal_box.h"
#include "save/player_info.h"
#include "save/pokedex.h"
#include "save/save_control.h"
#include "save/shortcut.h"
#include "save/trainer_card.h"
#include "system/dsi.h"
#include "system/game_comm.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/season.h"
#include "system/version.h"
#include "system/vm.h"

BOOL func_ov012_02159bc0(VM *vm, void *arg) {
    FieldScriptEnv *env = arg;
    GameSystem *gsys;
    ScriptWork *work;
    GameCommSys *commSys;
    void *data;

    gsys = FieldScriptEnv_GetGameSystem(env);
    work = FieldScriptEnv_GetScriptWork(env);
    commSys = GSYS_GetGameCommSystem(gsys);
    GSYS_GetField(gsys);
    data = *ScriptWork_GetUserHeapPtr(work);
    switch (func_ov036_02180fc0(commSys)) {
    case 0:
        return FALSE;
    case 1:
        GFL_HeapFree(data);
        return TRUE;
    case 2:
        **(u16 **)data = 2;
        GFL_HeapFree(data);
        return TRUE;
    }
    return FALSE;
}

BOOL s0139_GameCommDisconnect(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    void **slot;
    u16 *result;
    void *memory;

    work = FieldScriptEnv_GetScriptWork(env);
    slot = ScriptWork_GetUserHeapPtr(work);
    result = ScriptReadVar(vm, env);
    memory = GFL_HeapAllocate(4, 4, TRUE, "scrcmd_network.c", 0x63);
    *slot = memory;
    *(u16 **)memory = result;
    *result = 0;
    VM_SetNativeCallback(vm, func_ov012_02159bc0);
    return TRUE;
}

BOOL s013B_GameCommCheckDSiWiFi(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    *result = func_02035318();
    return FALSE;
}

BOOL func_ov012_02159c80(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;

    gsys = FieldScriptEnv_GetGameSystem(env);
    GSYS_TryBootGameComm(gsys);
    return TRUE;
}

BOOL func_ov012_02159c90(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    GameCommSys *commSys;

    gsys = FieldScriptEnv_GetGameSystem(env);
    commSys = GSYS_GetGameCommSystem(gsys);
    switch (GameCommSys_BootCheck(commSys)) {
    case 0:
    case 3:
    case 4:
        break;
    case 1:
    case 2:
    case 5:
        GameCommSys_ExitReq(commSys);
        break;
    }
    func_02016b24(gsys, 1);
    FieldScriptSubEvent_Register(11);
    return TRUE;
}

BOOL func_ov012_02159cd8(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;

    gsys = FieldScriptEnv_GetGameSystem(env);
    func_02016b24(gsys, 0);
    GSYS_TryBootGameComm(gsys);
    FieldScriptSubEvent_Unregister(11);
    return TRUE;
}

BOOL func_ov012_02159cf8(GameSystem **gsysPtr) {
    GameSystem *gsys;

    gsys = *gsysPtr;
    func_02016b24(gsys, 0);
    GSYS_TryBootGameComm(gsys);
    return TRUE;
}

BOOL func_ov012_02159d10(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    u16 *value;

    gsys = FieldScriptEnv_GetGameSystem(env);
    value = ScriptReadVar(vm, env);
    *value = func_02016b34(gsys);
    return FALSE;
}

BOOL s024B_FieldSubscreenDisable(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    func_02016b40(gsys, 0);
    func_0201740c(GSYS_GetGameData(gsys), 0);
    return FALSE;
}
