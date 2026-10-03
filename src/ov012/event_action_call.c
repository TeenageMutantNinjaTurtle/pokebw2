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

struct PrepareResidentActorsWork {
    GameSystem *gameSystem;
    Field *field;
    GameData *gameData;
    u32 unkC;
};

GameEvent *CallEventPrepareResidentActorsForZoneChange(GameSystem *gsys, Field *field) {
    GameEvent *event = GameEvent_Create(gsys, NULL, func_ov012_0215c59c, sizeof(PrepareResidentActorsWork));
    PrepareResidentActorsWork *work = GameEvent_GetData(event);
    work->gameSystem = gsys;
    work->field = field;
    work->gameData = GSYS_GetGameData(gsys);
    return event;
}

GameEventReturnCode EventActionCall_Callback(GameEvent *event, u32 *state, void *data) {
    EventActionCallWork *work = data;
    MMSys *mmSys = Field_GetActorSystem(work->field);
    switch (*state) {
    case 0: {
        FieldActor *actor = EventActionCall_FindActor(mmSys, work->actorId);
        if (actor == NULL) {
            return GAMEEVENT_DONE;
        }
        FieldAcmdTCB *task = FieldAcmdTCB_Create(actor, work->action);
        EventActionCall_AddTCB(work, task);
        (*state)++;
        break;
    }
    case 1:
        if (!EventActionCall_UpdateTCBs(work)) {
            return GAMEEVENT_DONE;
        }
        break;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *EventActionCall_Create(GameSystem *gsys, Field *field, u16 actorId, const u32 *action) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventActionCall_Callback, sizeof(EventActionCallWork));
    EventActionCallWork *work = GameEvent_GetData(event);
    EventActionCall_ClearTCBs(work);
    work->gameSystem = gsys;
    work->field = field;
    work->gameData = GSYS_GetGameData(gsys);
    work->actorId = actorId;
    work->action = action;
    return event;
}

GameEvent *CallMoveOneTileFrontEvent(GameSystem *gsys, Field *field) {
    u32 direction = GetActorFaceDir(FieldPlayer_GetActor(Field_GetPlayer(field)));
    const u32 *queue;
    switch (direction) {
    case 0: queue = ACMD_QUEUE_WALK_N_8F; break;
    case 1: queue = ACMD_QUEUE_WALK_S_8F; break;
    case 2: queue = ACMD_QUEUE_WALK_W_8F; break;
    case 3: queue = ACMD_QUEUE_WALK_E_8F; break;
    }
    return EventActionCall_Create(gsys, field, 0xff, queue);
}

FieldActor *EventActionCall_FindActor(MMSys *mmSys, u16 actorId) {
    if (actorId == 0xf2) {
        return FindActorByMoveCode(mmSys, 0x30);
    }
    if (actorId != 0xf1) {
        return FindFieldActor(mmSys, actorId);
    }
    return (FieldActor *)mmSys;
}

void EventActionCall_ClearTCBs(EventActionCallWork *work) {
    int i;
    for (i = 0; i < 8; i++) {
        work->tasks[i] = NULL;
    }
}

void EventActionCall_AddTCB(EventActionCallWork *work, FieldAcmdTCB *task) {
    int i;
    for (i = 0; i < 8; i++) {
        if (work->tasks[i] == NULL) {
            work->tasks[i] = task;
            return;
        }
    }
}

BOOL EventActionCall_UpdateTCBs(EventActionCallWork *work) {
    int i;
    BOOL active = 0;
    for (i = 0; i < 8; i++) {
        if (work->tasks[i] != NULL) {
            if (FieldAcmdTCB_CheckEnded(work->tasks[i]) == TRUE) {
                FieldAcmdTCB_Remove(work->tasks[i]);
                work->tasks[i] = NULL;
            } else {
                active = 1;
            }
        }
    }
    return active;
}

GameEvent *EventActorJump_Create(GameSystem *gsys, Field *field, const VecFx32 *start, const VecFx32 *end) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventActorJump_Callback, sizeof(EventActorJumpWork));
    EventActorJumpWork *work = GameEvent_GetData(event);
    work->field = field;
    work->effects = Field_GetFieldEffects(GSYS_GetField(gsys));
    work->start = *start;
    VEC_Subtract(end, start, &work->displacement);
    GFL_SndSEPlay(0x55e);
    return event;
}

FieldAcmdTCB *FieldAcmdTCB_CreateWalkOneTile(FieldActor *actor, u32 direction) {
    const u32 *queue;
    switch (direction) {
    case 0: queue = ACMD_QUEUE_WALK_N_8F; break;
    case 1: queue = ACMD_QUEUE_WALK_S_8F; break;
    case 2: queue = ACMD_QUEUE_WALK_W_8F; break;
    case 3: queue = ACMD_QUEUE_WALK_E_8F; break;
    }
    func_ov012_02166f2c(actor);
    return FieldAcmdTCB_Create(actor, queue);
}
