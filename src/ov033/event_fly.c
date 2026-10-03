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

struct FlyEventWork {
    GameSystem *gsys;
    u32 unk4;
    u32 zoneId;
    ZoneSpawnInfo spawn;
    u32 musicOut;
    u32 musicIn;
};

GameEvent *func_ov033_02178908(GameSystem *gsys, void *unused, u32 zoneId) {
    GameEvent *event;
    FlyEventWork *work;

    event = GameEvent_Create(gsys, NULL, EventFly_Callback, sizeof(FlyEventWork));
    work = GameEvent_GetData(event);
    sys_memset(work, 0, sizeof(FlyEventWork));
    work->gsys = gsys;
    work->zoneId = zoneId;
    if (getTrainerGender(GetGameDataPlayerInfo(GSYS_GetGameData(gsys))) == 0) {
        work->musicOut = 11;
        work->musicIn = 12;
    } else {
        work->musicOut = 31;
        work->musicIn = 32;
    }
    LoadZoneSpawnInfoCheckRail(&work->spawn, zoneId);
    return event;
}

GameEventReturnCode func_ov033_02178c6c(GameEvent *event, u32 *state, void *data) {
    GameSystem *gsys;

    gsys = GameEvent_GetGameSystem(event);
    GSYS_GetField(gsys);
    switch (*state) {
    case 0:
        GFL_FadeSet(3, 16, 0, 0);
        ++*state;
        break;
    case 1:
        if (!GFL_FadeIsRunning()) {
            return GAMEEVENT_DONE;
        }
        break;
    }
    return GAMEEVENT_CONTINUE;
}
