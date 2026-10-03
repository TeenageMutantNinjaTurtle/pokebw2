#include "types.h"
#include "app/funfest_mission.h"
#include "app/name_entry.h"
#include "battle/btl_setup.h"
#include "demo/shinka_demo.h"
#include "field/battle_facility.h"
#include "field/bsubway_scr.h"
#include "field/encounter.h"
#include "field/encounter_effect.h"
#include "field/entree_forest.h"
#include "field/entree_scripts.h"
#include "field/event_abyssal_ruins.h"
#include "field/event_cgear_shutdown.h"
#include "field/event_chatot.h"
#include "field/event_dendou_machine.h"
#include "field/event_dive.h"
#include "field/event_field_trade.h"
#include "field/event_fishing.h"
#include "field/event_fly.h"
#include "field/event_funfest_mission.h"
#include "field/event_game_manual.h"
#include "field/event_mapchange.h"
#include "field/event_phrase_input.h"
#include "field/event_pokemon_center.h"
#include "field/event_sound.h"
#include "field/event_sweet_scent.h"
#include "field/event_wild_battle.h"
#include "field/festival.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "field/field_actor_animation.h"
#include "field/field_display_control.h"
#include "field/field_effects.h"
#include "field/field_environment.h"
#include "field/field_event.h"
#include "field/field_fog.h"
#include "field/field_lifecycle.h"
#include "field/field_map.h"
#include "field/field_money_window.h"
#include "field/field_move_scripts.h"
#include "field/field_move_tcb.h"
#include "field/field_party.h"
#include "field/field_player.h"
#include "field/field_prop.h"
#include "field/field_script.h"
#include "field/field_script_event.h"
#include "field/field_surf.h"
#include "field/field_task.h"
#include "field/field_visuals.h"
#include "field/fld_trade.h"
#include "field/funfest_scripts.h"
#include "field/mystery_gift_delivery.h"
#include "field/mystery_gift_script.h"
#include "field/ov131.h"
#include "field/pc_sound.h"
#include "field/player_state.h"
#include "field/subscreen.h"
#include "field/trial_house.h"
#include "field/unity_tower.h"
#include "field/zone.h"
#include "gfl/arc.h"
#include "gfl/bmpwin.h"
#include "gfl/fade.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/input.h"
#include "gfl/msg.h"
#include "gfl/net.h"
#include "gfl/overlay.h"
#include "gfl/random.h"
#include "gfl/sound.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "pml/evolution.h"
#include "pml/poke_graphic.h"
#include "pml/poke_party.h"
#include "save/bag.h"
#include "save/box.h"
#include "save/bsubway_save.h"
#include "save/chatter.h"
#include "save/dream_world.h"
#include "save/high_link.h"
#include "save/join_avenue.h"
#include "save/mystery_gift.h"
#include "save/player_info.h"
#include "save/pokedex.h"
#include "save/records.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "save/trial_house.h"
#include "struct_decls.h"
#include "system/aeabi.h"
#include "system/game_comm.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/version.h"
#include "system/vm.h"

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

BOOL s0277_FunfestActorDelete(VM *vm, FieldScriptEnv *env) {
    ScriptWork *scriptWork = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    Field *field = GSYS_GetField(gsys);
    u16 zoneId = GetScriptEnvZoneID(env);
    u8 actorIndex = GetActorUID(ScriptWork_GetParentActor(scriptWork)) - 0xec;
    void *gimmick = Field_GetFesGimmick(field);

    if (!FesGimmick_IsCurrent(gimmick, 5)) {
        return TRUE;
    }
    DeleteFunfestActor(Field_GetFesGimmick(field), zoneId, actorIndex);
    return TRUE;
}

BOOL s027A_FunfestGetGenericInfo(VM *vm, FieldScriptEnv *env) {
    ScriptWork *scriptWork = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    void *gimmick = Field_GetFesGimmick(GSYS_GetField(gsys));
    u16 param = ScriptReadAny(vm, env);
    u16 *result = ScriptReadVar(vm, env);

    if (!FesGimmick_IsCurrent(gimmick, 5)) {
        *result = 0;
        return TRUE;
    }
    *result = GetActorUserParam(ScriptWork_GetParentActor(scriptWork), param);
    return TRUE;
}

BOOL s027B_FunfestGetItemExchangeInfo(VM *vm, FieldScriptEnv *env) {
    ScriptWork *scriptWork = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    void *gimmick = Field_GetFesGimmick(GSYS_GetField(gsys));
    u16 arg0 = ScriptReadAny(vm, env);
    u16 arg1 = ScriptReadAny(vm, env);
    u16 *out0 = ScriptReadVar(vm, env);
    u16 *out1 = ScriptReadVar(vm, env);

    if (!FesGimmick_IsCurrent(gimmick, 5)) {
        *(volatile u16 *)out1 = 0x11;
        *out0 = *(volatile u16 *)out1;
        return TRUE;
    }
    func_ov072_021e8d08(gimmick, ScriptWork_GetParentActor(scriptWork), arg0, arg1, out0, out1);
    return TRUE;
}

BOOL s027C_FunfestGetItemSaleInfo(VM *vm, FieldScriptEnv *env) {
    ScriptWork *scriptWork = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    void *gimmick = Field_GetFesGimmick(GSYS_GetField(gsys));
    u16 *out0 = ScriptReadVar(vm, env);
    u16 *out1 = ScriptReadVar(vm, env);

    if (!FesGimmick_IsCurrent(gimmick, 5)) {
        *out0 = 0x11;
        *out1 = 0x270f;
        return TRUE;
    }
    func_ov072_021e8d70(gimmick, ScriptWork_GetParentActor(scriptWork), out0, out1);
    return TRUE;
}

BOOL s027D_FunfestGetPokemonQuizInfo(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    void *gimmick;
    u16 *out0;
    u16 *out1;
    u16 *out2;

    FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    gimmick = Field_GetFesGimmick(GSYS_GetField(gsys));
    out0 = ScriptReadVar(vm, env);
    out1 = ScriptReadVar(vm, env);
    out2 = ScriptReadVar(vm, env);

    if (!FesGimmick_IsCurrent(gimmick, 5)) {
        *out0 = 1;
        *(volatile u16 *)out2 = 0;
        *out1 = *(volatile u16 *)out2;
        return TRUE;
    }
    func_ov072_021e8ddc(gimmick, out0, out1, out2);
    return TRUE;
}

BOOL s027E_FunfestGetPokemonQuizSpecies(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    void *gimmick;
    u16 index;
    u16 *result;

    FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    gimmick = Field_GetFesGimmick(GSYS_GetField(gsys));
    index = ScriptReadAny(vm, env);
    result = ScriptReadVar(vm, env);

    if (!FesGimmick_IsCurrent(gimmick, 5)) {
        *result = 0x1f8 + index;
        return TRUE;
    }
    *result = func_ov072_021e8ee8(gimmick, (u8)index);
    return TRUE;
}

BOOL s027F_FunfestGetPokemonQuizBogusSpecies(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    void *gimmick;
    u16 index;
    u16 *result;

    FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    gimmick = Field_GetFesGimmick(GSYS_GetField(gsys));
    index = ScriptReadAny(vm, env);
    result = ScriptReadVar(vm, env);

    if (!FesGimmick_IsCurrent(gimmick, 5)) {
        *result = 0x1f8 + index;
        return TRUE;
    }
    *result = func_ov072_021e8ef4(gimmick, (u8)index);
    return TRUE;
}

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
