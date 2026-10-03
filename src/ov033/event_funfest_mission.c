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

struct FestMissionConfig {
    u32 words[11];
};

struct FestMissionEventArgs {
    FestMissionConfig config;
    u32 unk2C;
    u32 unk30;
};

GameEvent *func_ov033_02176d88(GameSystem *gsys) {
    return GameEvent_Create(gsys, NULL, func_ov033_02176d9c, 4);
}

GameEventReturnCode func_ov033_02176d9c(GameEvent *event, u32 *state, void *data) {
    GameSystem *gsys;
    Field *field;
    GameCommSys *commSys;
    LinkFestival *festival;
    FestMissionEventArgs args;
    VecFx32 position;
    s32 *positionPtr;
    GameData *gameData;
    PlayerState *playerState;
    GameEvent *next;
    s32 i;
    s32 *counter;

    counter = data;
    gsys = GameEvent_GetGameSystem(event);
    field = GSYS_GetField(gsys);
    commSys = GSYS_GetGameCommSystem(gsys);
    festival = GSYS_GetLinkFestival(gsys);
    switch (*state) {
    case 0:
        DisableAllActorsMovement(Field_GetActorSystem(field));
        sys_memset(&args, 0, sizeof(args));
        args.config = *(FestMissionConfig *)GetFestMissionCfg(festival);
        args.unk2C = 0;
        next = GameEvent_CreateOverlayDelegate(gsys, OVERLAY_FUNFEST_MISSION, func_ov157_021f59e0, &args);
        GameEvent_ChainNext(event, next);
        ++*state;
        break;
    case 1:
        func_ov130_021eed98(gsys);
        if (GameCommSys_BootCheck(commSys) != 2) {
            gameData = GSYS_GetGameData(gsys);
            positionPtr = (s32 *)&position;
            positionPtr[0] = 0;
            positionPtr[1] = 0;
            positionPtr[2] = 0;
            for (i = 0; i < 3; i++) {
                playerState = func_020171e8(gameData, i);
                PlayerState_SetWPos(playerState, (VecFx32 *)positionPtr);
            }
        }
        ++*state;
        break;
    case 2:
        if (Field_CheckMapLoadFinished(GSYS_GetField(gsys)) == 1) {
            *state = 3;
        }
        break;
    case 3:
        if ((*counter)++ >= 70) {
            func_ov130_021eedb4(gsys);
            *counter = 0;
            ++*state;
        }
        break;
    case 4:
        if ((*counter)++ >= 30) {
            next = EventEntralinkWarp_CreateOut(gsys);
            GameEvent_ChainNext(event, next);
            ++*state;
        }
        break;
    case 5:
        func_02014774(festival, 0);
        EnableAllActorsMovement(Field_GetActorSystem(field));
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}
