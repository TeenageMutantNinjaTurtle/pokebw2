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

struct PCSubprocessEventData {
    GameSystem *gsys;
    Field *field;
    GameData *gameData;
    u16 option;
    u16 selection;
    u16 *result;
};

GameEvent *func_ov033_02179868(GameSystem *gsys, u16 option, u16 *result) {
    GameEvent *event;
    PCSubprocessEventData *data;

    event = GameEvent_Create(gsys, NULL, func_ov033_021798a0, sizeof(PCSubprocessEventData));
    data = GameEvent_GetData(event);
    data->gsys = gsys;
    data->field = GSYS_GetField(gsys);
    data->result = result;
    data->gameData = GSYS_GetGameData(gsys);
    data->option = option;
    return event;
}

GameEventReturnCode func_ov033_021798a0(GameEvent *event, u32 *state, void *eventData) {
    PCSubprocessEventData *data;
    GameEvent *next;

    data = eventData;
    switch (*state) {
    case 0:
        next = EventFieldSubprocessTransition_Create(data->gsys, data->field, OVERLAY_ID(256), &data_ov182_021bd8e4,
                                                     &data->gameData);
        GameEvent_ChainNext(event, next);
        (*state)++;
        break;
    case 1:
        switch (data->selection) {
        case 0:
            *data->result = 0;
            break;
        case 1:
            *data->result = 1;
            break;
        }
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEventReturnCode pcEntrySound(GameEvent *event, u32 *state, void *eventData) {
    struct PCSoundEventData *data = eventData;
    VecFx32 position;
    FieldPropAreaBounds bounds;
    FieldPropSystem *propSystem;
    FieldChunkPropHolder *prop;

    switch (*state) {
    case 0:
        GFL_SndSEPlay(0x55b);
        FieldPlayer_GetWPos(Field_GetPlayer(data->field), &position);
        bounds.minZ = position.z - (1 << 16);
        bounds.maxZ = position.z + (1 << 16);
        bounds.minX = position.x - (1 << 16);
        bounds.maxX = position.x + (1 << 16);
        propSystem = FieldG3DMapper_GetBMSystem(Field_GetG3DMapper(data->field));
        prop = FieldPropSystem_FindProp(propSystem, 4, &bounds);
        if (prop != NULL) {
            data->pcProp = prop;
            FieldChunkPropHolder_CallAnmCmd(propSystem, prop, 0, 0);
        }
        (*state)++;
        break;
    case 1:
        if (GFL_SndPlayerIsActive(GFL_SndSeqGetPlayerIndex(0x55b))) {
            break;
        }
        (*state)++;
        break;
    case 2:
        GFL_SndSEPlay(0x55c);
        if (data->pcProp != NULL) {
            FieldChunkPropHolder_CallAnmCmd(FieldG3DMapper_GetBMSystem(Field_GetG3DMapper(data->field)), data->pcProp,
                                            1, 2);
        }
        (*state)++;
        break;
    case 3:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *CreatePCSoundCallEvent(GameEvent *parent, GameSystem *gsys, Field *field) {
    GameEvent *event = GameEvent_Create(gsys, parent, pcEntrySound, sizeof(struct PCSoundEventData));
    struct PCSoundEventData *data = GameEvent_GetData(event);

    data->gameSystem = gsys;
    data->field = field;
    data->pcProp = NULL;
    return event;
}

GameEventReturnCode func_ov033_021799e8(GameEvent *event, u32 *state, void *eventData) {
    struct PCSoundEventData *data;
    VecFx32 position;
    FieldPropAreaBounds bounds;
    FieldPropSystem *propSystem;
    FieldChunkPropHolder *prop;

    data = eventData;
    switch (*state) {
    case 0:
        FieldPlayer_GetWPos(Field_GetPlayer(data->field), &position);
        bounds.minZ = position.z - (1 << 16);
        bounds.maxZ = position.z + (1 << 16);
        bounds.minX = position.x - (1 << 16);
        bounds.maxX = position.x + (1 << 16);
        propSystem = FieldG3DMapper_GetBMSystem(Field_GetG3DMapper(data->field));
        prop = FieldPropSystem_FindProp(propSystem, 4, &bounds);
        if (prop != NULL) {
            data->pcProp = prop;
            FieldChunkPropHolder_CallAnmCmd(propSystem, prop, 1, 2);
        }
        (*state)++;
        break;
    case 1:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *func_ov033_02179a58(GameEvent *parent, GameSystem *gsys, Field *field) {
    GameEvent *event;
    struct PCSoundEventData *data;

    event = GameEvent_Create(gsys, parent, func_ov033_021799e8, sizeof(struct PCSoundEventData));
    data = GameEvent_GetData(event);
    data->gameSystem = gsys;
    data->field = field;
    data->pcProp = NULL;
    return event;
}

GameEventReturnCode pcLogOffSound(GameEvent *event, u32 *state, void *eventData) {
    struct PCSoundEventData *data = eventData;
    VecFx32 position;
    FieldPropAreaBounds bounds;
    FieldPropSystem *propSystem;
    FieldChunkPropHolder *prop;
    u32 currentState = *state;

    switch (currentState) {
    case 0:
        if (data->skipSound == 0) {
            GFL_SndSEPlay(0x55d);
        }
        FieldPlayer_GetWPos(Field_GetPlayer(data->field), &position);
        bounds.minZ = position.z - (1 << 16);
        bounds.maxZ = position.z + (1 << 16);
        bounds.minX = position.x - (1 << 16);
        bounds.maxX = position.x + (1 << 16);
        propSystem = FieldG3DMapper_GetBMSystem(Field_GetG3DMapper(data->field));
        prop = FieldPropSystem_FindProp(propSystem, 4, &bounds);
        if (prop != NULL) {
            data->pcProp = prop;
            FieldChunkPropHolder_CallAnmCmd(propSystem, prop, 2, 0);
        }
        (*state)++;
        break;
    case 1:
        if (data->skipSound == 0) {
            if (GFL_SndPlayerIsActive(GFL_SndSeqGetPlayerIndex(0x55d))) {
                break;
            }
            (*state)++;
        } else {
            *state = currentState + 1;
        }
        break;
    case 2:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *func_ov033_02179b24(GameEvent *parent, GameSystem *gsys, Field *field, u32 skipSound) {
    GameEvent *event;
    struct PCSoundEventData *data;

    event = GameEvent_Create(gsys, parent, pcLogOffSound, sizeof(struct PCSoundEventData));
    data = GameEvent_GetData(event);
    data->gameSystem = gsys;
    data->field = field;
    data->pcProp = NULL;
    data->skipSound = skipSound;
    return event;
}
