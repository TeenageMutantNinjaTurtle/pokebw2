#include "battle/trainer_data.h"
#include "field/field_map.h"
#include "field/field_script.h"
#include "field/trainer_script.h"
#include "field/zone.h"
#include "gfl/arc.h"
#include "gfl/heap.h"
#include "nitro/os.h"
#include "save/event_work.h"
#include "system/game_data.h"
#include "system/game_system.h"

u32 GetChunkCoordOfWorld(s32 coordinate) {
    return ((coordinate / 0x1000) / 16) / 32;
}

MapReplace *MapReplace_Create(HeapID heapId, GameSystem *gsys) {
    MapReplace *replace = GFL_HeapAllocate(heapId, sizeof(MapReplace), TRUE, data_ov012_0216e1d4, 0x77);

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

BOOL RangeCheckTeleportZone(s32 index) {
    if (index <= 0 || (u32)index > 0x52) {
        return FALSE;
    }
    return TRUE;
}

u16 GetRespawnZoneMainZone(u16 index) {
    return RESPAWN_ZONE_INFO[GetActualRespawnZoneIdx(index)].mainZoneId;
}

void SetupTeleportZoneChange(u16 index, ZoneSpawnInfo *spawn) {
    u32 actualIndex = GetActualRespawnZoneIdx(index);
    const RespawnZoneInfo *info = &RESPAWN_ZONE_INFO[actualIndex];

    CreateRespawnZoneChangeData(spawn, RESPAWN_ZONE_INFO[actualIndex].zoneId, 0, info->x, info->z);
}

u32 GetRespawnLocationIndexForRespawnZone(s32 zoneId) {
    u32 i;

    for (i = 0; i < 0x52; i++) {
        const RespawnZoneInfo *info = &RESPAWN_ZONE_INFO[i];

        if (zoneId == info->zoneId && info->canReturnHere) {
            return i + 1;
        }
    }
    return 0;
}

void SetTeleportZoneDiscover(GameData *gameData, s32 respawnZoneId) {
    u32 i;

    for (i = 0; i < 0x52; i++) {
        const RespawnZoneInfo *info = &RESPAWN_ZONE_INFO[i];

        if (respawnZoneId == info->mainZoneId && info->discoverOnVisit) {
            EventWork_FlagSet(GameData_GetEventWork(gameData), info->discoveryFlagId);
            return;
        }
    }
}

void CreateRespawnZoneChangeData(ZoneSpawnInfo *spawn, u16 zoneId, u32 unused, u16 x, u16 z) {
    CreateZoneChangeData(spawn, zoneId, 1, x << 16, 0, z << 16);
}

u32 GetActualRespawnZoneIdx(u32 index) {
    if (!RangeCheckTeleportZone(index)) {
        index = GetLeaguePokeCenReturnLocationIdx();
    }
    return index - 1;
}

void SetupTrainerClashSlot(GameEvent *event, int index, const TrainerClashSlot *slot) {
    ScriptWork *work = EventScriptCall_GetWork(event);
    TrainerClashSlot *dst = ScriptWork_GetTrainerState(work, index);

    dst->payload = slot->payload;
    dst->result = 0;
}

u16 GetNPCTrainerIDFromSCRID(u32 scriptId) {
    if (scriptId < 0x1388) {
        return scriptId - 0xbb8;
    }
    return scriptId - 0x1388;
}

u16 GetNormalSCRIDFromTrainerID(u32 trainerId) {
    return trainerId + 0xbb8;
}

u16 GetPairMember2SCRIDFromTrainerID(u32 trainerId) {
    return trainerId + 0x1388;
}

BOOL isTrainerScrIdDoublePair2(u32 scriptId) {
    return scriptId >= 0x1388;
}

BOOL isDoubleBattle(u32 trainerId) {
    return TrainerData_GetParam(trainerId, 2) == 1;
}

u8 getBattleType(u32 trainerId) {
    return TrainerData_GetParam(trainerId, 2);
}

BOOL TrainerFlagGet(EventWork *eventWork, u16 trainerId) {
    return EventWork_FlagGet(eventWork, (u16)(trainerId + 0x5f0));
}

void setTrainerBattleFlag(EventWork *eventWork, u16 trainerId) {
    EventWork_FlagSet(eventWork, (u16)(trainerId + 0x5f0));
}

void clearTrainerBattleFlag(EventWork *eventWork, u16 trainerId) {
    EventWork_FlagReset(eventWork, (u16)(trainerId + 0x5f0));
}

void resetRebattleTrainers(EventWork *eventWork) {
    int i;

    clock();
    for (i = 0; i < 12; i++) {
        EventWork_FlagReset(eventWork, (u16)(data_ov012_0216c9a8[i] + 0x5f0));
    }
    clock();
}

ScriptSubwork *InitScriptSubwork(ScriptWork *work, HeapID heapId) {
    ScriptSubwork *subwork = GFL_HeapAllocate(heapId, sizeof(ScriptSubwork), TRUE, data_ov012_0216e1e4, 0x7b);

    subwork->work = work;
    subwork->gsys = ScriptWork_GetGameSystem(work);
    subwork->gameData = GSYS_GetGameData(subwork->gsys);
    subwork->mmSys = GameData_GetMMSys(subwork->gameData);
    subwork->actorMsgPosActual = 7;
    return subwork;
}

void func_ov012_021550e4(void *subwork) {
    GFL_HeapFree(subwork);
}
