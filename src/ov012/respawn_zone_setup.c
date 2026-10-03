#include "field/zone.h"
#include "save/event_work.h"
#include "system/game_data.h"

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
