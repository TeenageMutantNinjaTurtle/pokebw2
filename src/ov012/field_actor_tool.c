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

BOOL GetTerrainAtPosByActor(FieldActor *actor, const VecFx32 *position, FieldTerrain *terrain) {
    MMSys *system;
    G3DMapper *mapper;

    system = GetActorMModelSystem(actor);
    mapper = GetMMSysG3DMapper(system);
    return FieldG3DMapper_GetTerrain(mapper, position, terrain);
}

s16 GetDirectionVectorCompX(u32 direction) {
    return DIRECTION_VEC_X[direction];
}

s16 GetDirectionVectorCompZ(u32 direction) {
    return DIRECTION_VEC_Z[direction];
}

void ExpandVecInGridDir(u16 direction, VecFx32 *position, fx32 amount) {
    switch (direction) {
    case 0:
        position->z -= amount;
        break;
    case 1:
        position->z += amount;
        break;
    case 2:
        position->x -= amount;
        break;
    case 3:
        position->x += amount;
        break;
    }
}

void AdjusGridXZByDir(u32 direction, s16 *x, s16 *z, s16 amount) {
    switch (direction) {
    case 0:
        *z = (s16)(*z - amount);
        break;
    case 1:
        *z = (s16)(*z + amount);
        break;
    case 2:
        *x = (s16)(*x - amount);
        break;
    case 3:
        *x = (s16)(*x + amount);
        break;
    }
}

void ConvGXZToVector(u32 x, u32 z, VecFx32 *position) {
    position->x = (x << 16) + 0x8000;
    position->z = (z << 16) + 0x8000;
}

void VecGPosToWPos(s32 x, s32 y, s32 z, VecFx32 *position) {
    position->x = x << 16;
    position->y = y << 16;
    position->z = z << 16;
}

u16 GetInverseDirection(u32 direction) {
    return INV_DIR_TABLE[direction];
}

u16 GetDirFromPosToPos(s32 x1, s32 z1, s32 x2, s32 z2) {
    s32 direction;

    if (x1 > x2) {
        return 2;
    }
    if (x1 < x2) {
        return 3;
    }
    direction = 1;
    if (z1 > z2) {
        direction = 0;
    }
    return direction;
}

u32 func_ov012_0215ed38(u32 direction, u16 angle) {
    u32 index;

    index = data_ov012_0216cd68[((u32)(data_ov012_0216cd60[direction] + angle) << 16) >> 28];
    return data_ov012_0216cdc9[index << 2];
}
