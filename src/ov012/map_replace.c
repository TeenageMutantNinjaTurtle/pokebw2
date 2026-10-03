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

MapReplace *MapReplace_Create(HeapID heapId, GameSystem *gsys) {
    MapReplace *replace = GFL_HeapAllocate(heapId, sizeof(MapReplace), TRUE, "map_replace.c", 0x77);

    replace->heapId = heapId;
    replace->arc = GFL_ArcSysCreateFileHandle(10, heapId);
    replace->entryCount = (u32)(u16)GFL_ArcToolGetDataLength(replace->arc, 0) >> 4;
    MapReplace_LoadVariables(replace->variables, gsys);
    return replace;
}

s32 MapReplace_GetEntryCount(MapReplace *replace) {
    return replace->entryCount;
}

s32 MapReplace_LoadEntry(MapReplace *replace, u32 index) {
    GFL_ArcToolReadRange(replace->arc, 0, index * 16, 16, replace->entry);
    return *(u16 *)replace->entry;
}

void MapReplace_Free(MapReplace *replace) {
    GFL_ArcToolFree(replace->arc);
    GFL_HeapFree(replace);
}

u32 MapReplace_ResolvePatch(MapReplace *replace, u32 *oldValue, u32 *newValue) {
    const u8 *entry = replace->entry;
    const u8 *variables = replace->variables;
    u32 originalValue = *(const u16 *)(entry + 4);
    u32 index;
    u32 replacementValue;

    switch (entry[3]) {
    case 0:
        index = variables[0];
        break;
    case 1:
        index = variables[1];
        break;
    case 2:
        index = variables[2];
        break;
    default:
        index = (&variables[MapReplace_GetEventByCond(entry[3])])[3];
        break;
    }
    replacementValue = *(const u16 *)(entry + 4 + index * 2);
    *oldValue = originalValue;
    *newValue = replacementValue;
    if (originalValue == replacementValue) {
        return 0;
    }
    if (entry[2] == 1) {
        return 2;
    }
    if (entry[2] == 0) {
        return 1;
    }
    return 0;
}

int MapReplace_GetEventByCond(u8 condition) {
    u32 i;

    for (i = 0; i < 10; i++) {
        if (condition == EVENT_MAP_REPLACE_TABLE[i].condition) {
            return i;
        }
    }
    return -1;
}

void MapReplace_LoadVariables(u8 *variables, GameSystem *gsys) {
    EventWork *eventWork = GameData_GetEventWork(GSYS_GetGameData(gsys));
    GameCommSys *commSys = GSYS_GetGameCommSystem(gsys);
    u8 season = GameSystem_GetSeason(gsys);
    s32 i;

    variables[0] = season;
    if (getGameOrigin(commSys) == 0x15 || getGameOrigin(commSys) == 0x17) {
        variables[1] = 0;
    } else {
        variables[1] = 1;
    }
    if (variables[1] == 0) {
        variables[2] = 0;
    } else {
        variables[2] = season + 1;
    }
    for (i = 0; i < 10; i++) {
        u16 value = *EventWork_GetWkPtr(eventWork, EVENT_MAP_REPLACE_TABLE[i].workId);

        if (value == EVENT_MAP_REPLACE_TABLE[i].expectedValue) {
            variables[i + 3] = 1;
        } else {
            variables[i + 3] = 0;
        }
    }
}

const MapReplaceEvent *MapReplace_GetEventByUID(GameData *gameData, u16 uid) {
    u32 i;

    for (i = 0; i < 10; i++) {
        u8 eventUid = EVENT_MAP_REPLACE_TABLE[i].uid;

        if (eventUid == uid) {
            return &EVENT_MAP_REPLACE_TABLE[i];
        }
    }
    return NULL;
}

void GameData_SetEventMapReplace(GameData *gameData, u16 uid, BOOL set) {
    const MapReplaceEvent *event = MapReplace_GetEventByUID(gameData, uid);
    u16 *work;

    if (event != NULL) {
        work = EventWork_GetWkPtr(GameData_GetEventWork(gameData), event->workId);
        if (set != 0) {
            *work = event->expectedValue;
        } else {
            *work = 0;
        }
    }
}

BOOL GameData_IsMapReplaceEventSet(GameData *gameData, u16 uid) {
    const MapReplaceEvent *event = MapReplace_GetEventByUID(gameData, uid);

    if (event != NULL) {
        if (event->expectedValue == *EventWork_GetWkPtr(GameData_GetEventWork(gameData), event->workId)) {
            return TRUE;
        }
        return FALSE;
    }
    return FALSE;
}

u32 GetLeaguePokeCenReturnLocationIdx(void) {
    return 1;
}
