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

MapMatrix *InitMapMatrix(HeapID heapId) {
    MapMatrix *matrix = GFL_HeapAllocate(heapId, sizeof(MapMatrix), TRUE, "map_matrix.c", 0x4c);

    matrix->heapId = heapId;
    sys_memset32((u32)-1, matrix->chunkIds, sizeof(matrix->chunkIds));
    sys_memset32(0xffff, matrix->zoneIds, sizeof(matrix->zoneIds));
    return matrix;
}

void MapMatrix_Load(MapMatrix *matrix, u16 matrixId, u16 zoneId, HeapID heapId) {
    void *data = GFL_ArcSysReadHeapNew(9, matrixId, heapId);

    ProcessMapMatrix(matrix, data, matrixId, zoneId);
    GFL_HeapFree(data);
}

void FreeMapMatrix(MapMatrix *matrix) {
    GFL_HeapFree(matrix);
}

u16 GetZoneIDAtMatrixXZ(MapMatrix *matrix, s32 x, s32 z) {
    return matrix->zoneIds[z * matrix->width + x];
}

u16 GetZoneIDAtMatrixXZWorld(MapMatrix *matrix, s32 x, s32 z) {
    return GetZoneIDAtMatrixXZ(matrix, GetChunkCoordOfWorld(x), GetChunkCoordOfWorld(z));
}

u16 GetMapMatrixWidth(MapMatrix *matrix) {
    return matrix->width;
}

u16 GetMapMatrixHeight(MapMatrix *matrix) {
    return matrix->height;
}

u32 GetMapMatrixChunkIDCount(MapMatrix *matrix) {
    return matrix->chunkIdCount;
}

u32 *GetMapMatrixChunkIDs(MapMatrix *matrix) {
    return matrix->chunkIds;
}

BOOL RangeCheckChunkCoordinate(MapMatrix *matrix, s32 x, s32 z) {
    return z >= 0 && z < matrix->height && x >= 0 && x < matrix->width;
}

BOOL RangeCheckChunkCoordinateWorld(MapMatrix *matrix, s32 x, s32 z) {
    return RangeCheckChunkCoordinate(matrix, GetChunkCoordOfWorld(x), GetChunkCoordOfWorld(z));
}

void MapReplace_Patch(MapMatrix *matrix, MapReplace *replace, HeapID heapId) {
    u32 oldValue;
    u32 newValue;
    u32 result = MapReplace_ResolvePatch(replace, &oldValue, &newValue);
    u32 i;

    switch (result) {
    case 2:
        MapMatrix_Load(matrix, (u16)newValue, matrix->zoneId, heapId);
        return;
    case 1:
        for (i = 0; i < matrix->chunkIdCount; i++) {
            if (matrix->chunkIds[i] == oldValue) {
                matrix->chunkIds[i] = newValue;
            }
        }
        break;
    case 0:
        break;
    }
}

void MapMatrix_Patch(MapMatrix *matrix, GameSystem *gsys, HeapID heapId) {
    MapReplace *replace = MapReplace_Create(heapId, gsys);
    s32 count = MapReplace_GetEntryCount(replace);
    s32 i;

    for (i = 0; i < count; i++) {
        s32 entryId = MapReplace_LoadEntry(replace, i);

        if (entryId == matrix->matrixId) {
            MapReplace_Patch(matrix, replace, heapId);
        }
    }
    MapReplace_Free(replace);
}

u32 GetChunkCoordOfWorld(s32 coordinate) {
    return ((coordinate / 0x1000) / 16) / 32;
}
