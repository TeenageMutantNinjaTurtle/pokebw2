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
#include "field/pdw_postman.h"
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

BOOL ScriptNative_SurfTCBWait(VM *vm, void *env) {
    void *tcb;

    tcb = FieldScriptEnv_GetPlayerGridEventTCB(env);
    if (FieldSurfTCB_CheckEnd(tcb) == TRUE) {
        FieldSurfTCB_Free(tcb);
        return TRUE;
    }
    return FALSE;
}

BOOL s00C5_CallSurf(VM *vm, FieldScriptEnv *env) {
    VecFx32 position;
    Field *field;
    FieldPlayer *player;
    G3DMapper *mapper;
    u32 direction;
    HeapID heapId;
    u32 tileType;
    void *tcb;

    field = GSYS_GetField(FieldScriptEnv_GetGameSystem(env));
    player = Field_GetPlayer(field);
    direction = GetActorFaceDir(FieldPlayer_GetActor(player));
    mapper = Field_GetG3DMapper(field);
    heapId = FieldScriptEnv_GetHeapID(env);
    FieldPlayer_GetWPosInDir(player, direction, &position);
    tileType = GetTileTypeAtPos(mapper, &position);
    tcb = FieldSurfTCB_Create(player, direction, tileType, heapId);
    FieldScriptEnv_SetPlayerGridEventTCB(env, tcb);
    VM_SetNativeCallback(vm, ScriptNative_SurfTCBWait);
    return TRUE;
}

BOOL ScriptNative_WaterfallTCBWait(VM *vm, void *env) {
    void *tcb;

    tcb = FieldScriptEnv_GetPlayerGridEventTCB(env);
    if (FieldWaterfallTCB_CheckEnd(tcb) == TRUE) {
        FieldWaterfallTCB_Free(tcb);
        return TRUE;
    }
    return FALSE;
}

BOOL s00C6_CallWaterfall(VM *vm, FieldScriptEnv *env) {
    FieldPlayer *player;
    HeapID heapId;
    u32 direction;
    u32 param;
    void *tcb;

    heapId = FieldScriptEnv_GetHeapID(env);
    player = Field_GetPlayer(GSYS_GetField(FieldScriptEnv_GetGameSystem(env)));
    direction = FieldPlayer_GetFaceDir(player);
    param = ScriptReadAny(vm, env);
    tcb = FieldWaterfallTCB_Create(player, direction, param, heapId);
    FieldScriptEnv_SetPlayerGridEventTCB(env, tcb);
    VM_SetNativeCallback(vm, ScriptNative_WaterfallTCBWait);
    return TRUE;
}

BOOL s00C7_CallCut(VM *vm, FieldScriptEnv *env) {
    Field *field;
    FieldActor *actor;

    field = GSYS_GetField(FieldScriptEnv_GetGameSystem(env));
    actor = FieldPlayer_GetActor(Field_GetPlayer(field));
    func_ov036_021c2e70(actor, Field_GetFieldEffects(field));
    return FALSE;
}
