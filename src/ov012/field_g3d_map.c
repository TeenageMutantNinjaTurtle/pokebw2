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

void FieldChunk_SetActive(FieldChunk *chunk, u16 active) {
    *(u16 *)chunk = active;
}

u16 FieldChunk_IsActive(FieldChunk *chunk) {
    return *(u16 *)chunk;
}

void FieldChunk_SetWorldPos(FieldChunk *chunk, const VecFx32 *position) {
    *(VecFx32 *)((u8 *)chunk + 4) = *position;
}

void FieldChunk_GetWorldPos(FieldChunk *chunk, VecFx32 *position) {
    *position = *(VecFx32 *)((u8 *)chunk + 4);
}

void FieldChunk_GetLoaderHandle(FieldChunk *chunk, void **handle) {
    *handle = (u8 *)chunk + 0xb0;
}

void GetChunkRawDataContainer(FieldChunk *chunk, void **container) {
    *container = *(void **)((u8 *)chunk + 0xd4);
}

void FieldChunk_GetDatID(FieldChunk *chunk, u32 *datID) {
    *datID = *(u32 *)((u8 *)chunk + 0x14);
}

void FieldChunk_GetRawDataLength(FieldChunk *chunk, u32 *length) {
    *length = *(u32 *)((u8 *)chunk + 0xbc);
}

void FieldChunk_BindModel(FieldChunk *chunk, void *model) {
    GFL_G3DResBindData(*(void **)((u8 *)chunk + 0x84), 1, model);
}

void FieldChunk_UnbindModel(FieldChunk *chunk) {
    GFL_G3DResBindData(*(void **)((u8 *)chunk + 0x84), 1, NULL);
}

void *FieldChunk_GetModelResource(FieldChunk *chunk) {
    return *(void **)((u8 *)chunk + 0x84);
}

void FieldChunk_FreeTexRsc(FieldChunk *chunk) {
    GFL_G3DResBindData(*(void **)((u8 *)chunk + 0x88), 2, NULL);
}

void *FieldChunk_GetUsedTexRsc(FieldChunk *chunk) {
    return FieldChunk_GetUsedTexRscCore(chunk);
}

void FieldChunk_SetupModel(FieldChunk *chunk) {
    void *texture = FieldChunk_GetUsedTexRscCore(chunk);
    FieldChunk_LinkMdlTex(*(void **)((u8 *)chunk + 0x2c), *(void **)((u8 *)chunk + 0x84), texture);
}

void *FieldChunk_GetModel(FieldChunk *chunk) {
    return *(void **)((u8 *)chunk + 0x2c);
}

void FieldChunk_ResetStreamer(FieldChunk *chunk) {
    *(u32 *)((u8 *)chunk + 0xb4) = 0;
    *(u32 *)((u8 *)chunk + 0xc0) = 0;
    *(u32 *)((u8 *)chunk + 0xc8) = 0;
    *(u32 *)((u8 *)chunk + 0xcc) = 0;
    *(u32 *)((u8 *)chunk + 0xd0) = 0;
}
