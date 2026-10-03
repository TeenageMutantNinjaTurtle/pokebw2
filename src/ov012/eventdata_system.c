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

EventData *EventData_Create(HeapID heapId) {
    EventData *data;

    data = GFL_HeapAllocate(heapId, sizeof(EventData), TRUE, "eventdata_system.c", 0xae);
    data->entityArc = GFL_ArcSysCreateFileHandle(0x7e, heapId);
    data->encArc = GFL_ArcSysCreateFileHandle(0x7f, heapId);
    data->otherArc = GFL_ArcSysCreateFileHandle(0x38, heapId);
    return data;
}

void EventData_Free(EventData *data) {
    GFL_ArcToolFree(data->entityArc);
    GFL_ArcToolFree(data->encArc);
    GFL_ArcToolFree(data->otherArc);
    GFL_HeapFree(data);
}

void EventData_Reset(EventData *data) {
    EventData_Clear(data);
    // Past the end of the 0xaa8 bytes of EventData, until LoadZoneEntities points it into the entities
    data->initScript = (u8 *)data + 0x2328;
    data->encLoaded = 0;
    data->encDataFlags.high = 0;
}

void EventData_LoadZone(EventData *data, u16 zoneId, u8 season) {
    EventData_Reset(data);
    EventData_LoadEntities(data, zoneId, season);
    EventData_LoadEncData(data, zoneId, season);
}

void EventData_LoadEntities(EventData *data, u16 zoneId, u8 season) {
    data->zoneId = zoneId;
    LoadZoneEntities(data, zoneId, season);
}

void EventData_LoadEncData(EventData *data, u16 zoneId, u8 season) {
    EncData_Load(data->encData, data->encArc, zoneId, season);
    data->encLoaded = 1;
}

void *GetZoneInitScrPointer(EventData *data) {
    return data->initScript;
}

u32 IsEncountDataLoaded(EventData *data) {
    return data->encLoaded;
}

void EventData_Clear(EventData *data) {
    data->prevEntityCount = 0;
    data->prevNpcCount = 0;
    data->prevWarpCount = 0;
    data->prevTriggerCount = 0;
    data->entityCount = 0;
    data->npcCount = 0;
    data->warpCount = 0;
    data->triggerCount = 0;
    data->entities = NULL;
    data->npcs = NULL;
    data->warps = NULL;
    data->triggers = NULL;
    sys_memset(data->cache, 0, sizeof(data->cache));
}

void *GetEncountData(EventData *data) {
    return data->encData;
}

s32 GetWarpAtPosition(EventData *data, const VecFx32 *position) {
    s32 index;
    ZoneWarp *warp = data->warps;

    for (index = 0; index < data->warpCount; index++, warp++) {
        if (CheckWarpPositionMatch(warp, position)) {
            return index;
        }
    }
    return 0xffff;
}

s32 GetWarpIDByPlayerPos(EventData *data, const VecFx32 *position, u16 direction) {
    VecFx32 front = *position;
    s32 index;
    ZoneWarp *warp = data->warps;

    ExpandVecInGridDir(direction, &front, 0x10000);
    for (index = 0; index < data->warpCount; index++, warp++) {
        if (warp->transitionType == 1) {
            if (!IsWarpZoneOrWarpID0xFFFF(warp) && CheckWarpPositionMatch(warp, position) == TRUE) {
                return index;
            }
        } else {
            if (CheckWarpDirectionMatch(warp, direction) == TRUE && CheckWarpPositionMatch(warp, &front) == TRUE) {
                return 1;
            }
        }
    }
    return 0xffff;
}

s32 GetWarpIDByPlayerPosRail(EventData *data, const RailPosition *position) {
    s32 index;
    ZoneWarp *warp = data->warps;

    for (index = 0; index < data->warpCount; index++, warp++) {
        if (CheckWarpPositionMatchRail(warp, position)) {
            return index;
        }
    }
    return 0xffff;
}

ZoneWarp *GetZoneWarpByID(EventData *data, u16 warpId) {
    ZoneWarp *warps = data->warps;

    if (warps == NULL) {
        return NULL;
    }
    if (warpId >= data->warpCount) {
        return NULL;
    }
    return &warps[warpId];
}

BOOL IsWarpDestId256(ZoneWarp *warp) {
    return warp->destId == 0x100;
}

void SetupWarpParamByWarp(ZoneWarp *warp, ZoneSpawnInfo *spawn, u32 direction) {
    SetupZoneSpawnInfoWarp(spawn, warp->unk0, warp->destId, direction);
}

u16 ZoneWarp_CalcPosWeightBitsGrid(ZoneWarp *warp, const VecFx32 *position) {
    return ZoneWarp_CalcPosWeightBitsGrid_(warp, position);
}

u16 func_ov012_0215d104(ZoneWarp *warp, const RailPosition *position) {
    return func_ov012_0215d654(warp, position);
}

BOOL CheckWarpDirectionMatch(const ZoneWarp *warp, u16 direction) {
    if ((direction == 0 && warp->unk4 == 2) || (direction == 1 && warp->unk4 == 1) ||
        (direction == 2 && warp->unk4 == 4) || (direction == 3 && warp->unk4 == 3)) {
        return TRUE;
    }
    return FALSE;
}

u32 GetWarpTransitionType(ZoneWarp *warp) {
    return warp->transitionType;
}

BOOL IsWarpZoneOrWarpID0xFFFF(const ZoneWarp *warp) {
    return warp->unk0 == 0xffff || warp->destId == 0xffff;
}

void SetZoneWarpLocation(EventData *data, u16 warpId, u16 x, u16 y, u16 z) {
    ZoneWarp *warps;
    ZoneWarpGridPosition *pos;

    if (data->warpCount < warpId) {
        return;
    }
    warps = data->warps;
    if (warps == NULL) {
        return;
    }
    warps = &warps[warpId];
    if (warps->isRail != 0) {
        return;
    }
    pos = &warps->pos.grid;
    pos->x = x * 16 + 8;
    pos->y = y * 16;
    pos->z = z * 16 + 8;
}

ZoneNPC *GetZoneNPCs(EventData *data) {
    return data->npcs;
}

u32 GetZoneNPCsCount(EventData *data) {
    return data->npcCount;
}

void SetZoneNPCLocation(EventData *data, u32 npcId, u16 direction, u16 x, s32 y, u16 z) {
    ZoneNPC *npc;
    ZoneNPCGridPosition *pos;

    if (npcId >= data->npcCount) {
        return;
    }
    npc = &data->npcs[npcId];
    if (npc->isRail != 0) {
        return;
    }
    pos = &npc->pos.grid;
    npc->direction = direction;
    pos->x = x;
    pos->y = y;
    pos->z = z;
}

void SetZoneNPCMdlID(EventData *data, u16 npcId, u16 modelId) {
    if (npcId < data->npcCount) {
        data->npcs[npcId].modelId = modelId;
    }
}

void SetZoneNPCSCRID(EventData *data, u16 npcId, u16 scrId) {
    if (npcId < data->npcCount) {
        data->npcs[npcId].scrId = scrId;
    }
}

u32 ConvDirToTriggerDir(u32 dir) {
    switch (dir) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 4;
    default:
        return 0;
    }
}

ZoneTrigger *FindTriggerAtPosGrid(EventData *data, EventWork *eventWork, const VecFx32 *position, u32 direction) {
    ZoneTrigger *trigger;
    u32 triggerDirection;
    u16 count;
    u16 i;
    u16 *work;

    trigger = data->triggers;
    if (trigger != NULL) {
        triggerDirection = ConvDirToTriggerDir(direction);
        i = 0;
        count = data->triggerCount;
        if (i < count) {
            do {
                if (CheckTriggerPositionMatchXYZ(trigger, position)) {
                    if (trigger->type < 5) {
                        if (direction == 8 || trigger->type == triggerDirection) {
                            if (trigger->workId == 0) {
                                return trigger;
                            }
                            work = EventWork_GetWkPtr(eventWork, trigger->workId);
                            if (*work == trigger->workValue) {
                                return trigger;
                            }
                        }
                    }
                }
                i++;
                trigger++;
            } while (i < count);
        }
    }
    return NULL;
}

ZoneTrigger *FindQuicksandTrigger(EventData *data, EventWork *eventWork, const VecFx32 *position, u32 direction) {
    ZoneTrigger *trigger;
    u32 triggerDirection;
    u16 count;
    u16 i;
    u16 *work;

    trigger = data->triggers;
    if (trigger != NULL) {
        triggerDirection = ConvDirToTriggerDir(direction);
        i = 0;
        count = data->triggerCount;
        if (i < count) {
            do {
                if (CheckTriggerPositionMatchXZ(trigger, position)) {
                    if (trigger->type == triggerDirection) {
                        if (trigger->workId == 0) {
                            return trigger;
                        }
                        work = EventWork_GetWkPtr(eventWork, trigger->workId);
                        if (*work == trigger->workValue) {
                            return trigger;
                        }
                    }
                }
                i++;
                trigger++;
            } while (i < count);
        }
    }
    return NULL;
}

ZoneTrigger *FindCollidingZoneTriggerAtLocation(EventData *data, EventWork *eventWork, const VecFx32 *position) {
    ZoneTrigger *trigger;
    u16 count;
    u16 i;
    u16 *work;

    trigger = data->triggers;
    if (trigger != NULL) {
        count = data->triggerCount;
        for (i = 0; i < count; i++, trigger++) {
        if (CheckTriggerPositionMatchXYZ(trigger, position)) {
            if (trigger->type == 6) {
                if (trigger->workId == 0) {
                    return trigger;
                }
                work = EventWork_GetWkPtr(eventWork, trigger->workId);
                if (*work == trigger->workValue) {
                    return trigger;
                }
            }
        }
        }
    }
    return NULL;
}

ZoneTrigger *FindTriggerAtPosRail(EventData *data, EventWork *eventWork, const RailPosition *position) {
    ZoneTrigger *trigger;
    u16 count;
    u16 i;
    u16 *work;

    trigger = data->triggers;
    if (trigger != NULL) {
        count = data->triggerCount;
        for (i = 0; i < count; i++, trigger++) {
        if (CheckTriggerPositionMatchRail(trigger, position)) {
            work = EventWork_GetWkPtr(eventWork, trigger->workId);
            if (*work == trigger->workValue) {
                return trigger;
            }
        }
        }
    }
    return NULL;
}

u32 GetTriggerSCRIDAtPosGrid(EventData *data, EventWork *eventWork, const VecFx32 *position, u32 direction) {
    ZoneTrigger *trigger = FindTriggerAtPosGrid(data, eventWork, position, direction);
    return trigger != NULL ? trigger->scrId : 0xffff;
}

u32 GetSCRIDOfCollidingTriggerAtLocation(EventData *data, EventWork *eventWork, const VecFx32 *position) {
    ZoneTrigger *trigger = FindCollidingZoneTriggerAtLocation(data, eventWork, position);
    return trigger != NULL ? trigger->scrId : 0xffff;
}

u32 GetTriggerSCRIDAtPosRail(EventData *data, EventWork *eventWork, const RailPosition *position) {
    ZoneTrigger *trigger = FindTriggerAtPosRail(data, eventWork, position);
    return trigger != NULL ? trigger->scrId : 0xffff;
}

void *GetZoneProxiesAndCount(EventData *data, u32 *restrict count) {
    *count = data->entityCount;
    return data->entities;
}

s32 CheckProxyEntityEvent(EventData *data, EventWork *eventWork, const void *position, u16 direction) {
    ZoneBGEntity *entity;
    u16 alternateDirection;
    u16 count;
    u16 i;
    u16 flag;

    entity = data->entities;
    if (entity != NULL) {
        count = data->entityCount;
        alternateDirection = direction - 2;
        for (i = 0; i < count; i++, entity++) {
            if (entity->condition >= 3) {
                continue;
            }
            if (entity->isRail == 0) {
                if (!CheckBGPositionMatchGrid(entity, position)) {
                    continue;
                }
            } else if (!CheckBGPositionMatchRail(entity, position)) {
                continue;
            }
            if (entity->condition == 2) {
                flag = GetHiddenItemEventFlagNoBySCRID(entity->scrId);
                if (EventWork_FlagGet(eventWork, flag)) {
                    continue;
                }
                return entity->scrId;
            }
            switch (entity->direction) {
            case 0:
                if (direction == 0) {
                        return entity->scrId;
                    }
                break;
            case 1:
                if (direction == 3) {
                        return entity->scrId;
                    }
                break;
            case 2:
                if (direction == 2) {
                        return entity->scrId;
                    }
                break;
            case 3:
                if (direction == 1) {
                        return entity->scrId;
                    }
                break;
            case 4:
                return entity->scrId;
            case 5:
                if (alternateDirection <= 1) {
                        return entity->scrId;
                    }
                break;
            case 6:
                if (direction <= 1) {
                        return entity->scrId;
                    }
                break;
            }
        }
    }
    return 0xffff;
}

s32 CheckProxyEntityEventGrid(EventData *data, EventWork *eventWork, const VecFx32 *position, u16 direction) {
    return CheckProxyEntityEvent(data, eventWork, position, direction);
}

s32 CheckProxyEntityEventRail(EventData *data, EventWork *eventWork, const RailPosition *position, u16 direction) {
    return CheckProxyEntityEvent(data, eventWork, position, direction);
}

void func_ov012_0215d4d0(const ZoneBGEntity *entity, VecFx32 *position) {
    func_ov012_0215d88c(entity, position);
    position->x += 0x8000;
    position->z += 0x8000;
}

void func_ov012_0215d4ec(const ZoneBGEntity *entity, RailPosition *position) {
    func_ov012_0215d8fc(entity, position);
}

void GetTriggerCenterPos(const ZoneTrigger *trigger, VecFx32 *position) {
    GetTriggerCenterPos_(trigger, position);
}

void SetBGEntityLocation(EventData *data, u32 index, s32 x, s32 z, u16 y) {
    ZoneBGEntity *entities;
    ZoneBGEntity *entity;
    s32 *coords;

    if (data->entityCount >= index && data->entities != NULL) {
        entities = data->entities;
        entity = &entities[index];
        if (entity->isRail == 0) {
            coords = &entity->pos.grid.x;
            coords[0] = x;
            coords[1] = y;
            coords[2] = z << 4;
        }
    }
}

u16 ZoneWarp_CalcPosWeightBitsGrid_(ZoneWarp *warp, const VecFx32 *position) {
    ZoneWarpGridPosition *grid;
    u32 direction;

    direction = ZoneWarp_GetDirection(warp);
    grid = &warp->pos.grid;
    if (grid->width > 1) {
        return ((grid->width << 4) | (((position->x >> 12) - (s16)grid->x) / 16)) | (direction << 8);
    }
    if (grid->height > 1) {
        return ((grid->height << 4) | (((position->z >> 12) - (s16)grid->z) / 16)) | (direction << 8);
    }
    return (direction << 8) | 0x10;
}

u16 func_ov012_0215d654(ZoneWarp *warp, const RailPosition *position) {
    const ZoneWarpRailPosition *rail;
    u32 direction;
    BOOL frontFlip;
    BOOL sideFlip;
    s32 offset;

    rail = &warp->pos.rail;
    frontFlip = FALSE;
    sideFlip = FALSE;
    direction = ZoneWarp_GetDirection(warp);
    switch (rail->param) {
    case 0:
        frontFlip = TRUE;
        break;
    case 1:
        sideFlip = TRUE;
        break;
    case 2:
        frontFlip = TRUE;
        sideFlip = TRUE;
        break;
    case 3:
        break;
    }
    if (rail->sideSpan > 1) {
        offset = position->posSide - rail->posSide;
        if (sideFlip) {
            offset = (rail->sideSpan - 1) - offset;
        }
        return ((rail->sideSpan << 4) | offset) | (direction << 8);
    }
    if (rail->frontSpan > 1) {
        offset = position->posFront - rail->posFront;
        if (frontFlip) {
            offset = (rail->frontSpan - 1) - offset;
        }
        return ((rail->frontSpan << 4) | offset) | (direction << 8);
    }
    return (direction << 8) | 0x10;
}

u32 ZoneWarp_GetDirection(const ZoneWarp *warp) {
    switch (warp->unk4) {
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 3;
    default:
        return 1;
    }
}

void GetGridWarpOutPos(ZoneWarp *warp, u32 direction, VecFx32 *position) {
    ZoneWarpGridPosition *grid = &warp->pos.grid;
    u32 warpDirection = ZoneWarp_GetDirection(warp);

    position->x = (s16)grid->x << 12;
    position->y = (s16)grid->y << 12;
    position->z = (s16)grid->z << 12;
    if (grid->width > 1) {
        position->x += CalcWarpTransferAddend(direction, warpDirection, 0, 0, grid->width) << 16;
    } else if (grid->height > 1) {
        position->z += CalcWarpTransferAddend(direction, warpDirection, 0, 0, grid->height) << 16;
    }
}

BOOL CheckWarpPositionMatch(const ZoneWarp *warp, const VecFx32 *position) {
    s32 x;
    s32 y;
    s32 z;
    const ZoneWarpGridPosition *grid;
    s32 warpX;
    s32 warpY;
    s32 warpZ;
    if (warp->isRail == 1) {
        return FALSE;
    }
    grid = &warp->pos.grid;
    x = position->x >> 12;
    y = position->y >> 12;
    z = position->z >> 12;
    warpX = (s16)grid->x;
    if (warpX <= x) {
        if (warpX + ((grid->width - 1) << 4) >= x) {
            warpY = (s16)grid->y;
            if (warpY - 2 <= y) {
                if (warpY + 2 >= y) {
                    warpZ = (s16)grid->z;
                    if (warpZ <= z) {
                        if (warpZ + ((grid->height - 1) << 4) >= z) {
                            return TRUE;
                        }
                    }
                }
            }
        }
    }
    return FALSE;
}

void GetRailWarpOutPos(ZoneWarp *warp, u32 direction, RailPosition *position) {
    ZoneWarpRailPosition *rail = &warp->pos.rail;
    u32 warpDirection = ZoneWarp_GetDirection(warp);

    position->componentId = rail->componentId;
    position->componentIsLine = 1;
    position->railDirection = ConvDirToRailDir(warpDirection);
    position->posSide = rail->posSide;
    position->posFront = rail->posFront;
    if (rail->sideSpan > 1) {
        position->posSide += (s16)CalcWarpTransferAddend(direction, warpDirection, 1, rail->param, rail->sideSpan);
    } else if (rail->frontSpan > 1) {
        position->posFront += CalcWarpTransferAddend(direction, warpDirection, 1, rail->param, rail->frontSpan);
    }
}

BOOL CheckWarpPositionMatchRail(const ZoneWarp *warp, const RailPosition *position) {
    const ZoneWarpRailPosition *rail;

    if (warp->isRail == 0) {
        return FALSE;
    }
    rail = &warp->pos.rail;
    if (rail->componentId == position->componentId && rail->posFront <= position->posFront &&
        rail->posFront + rail->frontSpan > position->posFront && rail->posSide <= position->posSide &&
        rail->posSide + rail->sideSpan > position->posSide) {
        return TRUE;
    }
    return FALSE;
}

void func_ov012_0215d88c(const ZoneBGEntity *entity, VecFx32 *position) {
    const s32 *coords;
    s32 x;
    s32 y;
    s32 z;

    coords = &entity->pos.grid.x;
    z = coords[1] << 16;
    x = coords[0] << 16;
    y = coords[2] << 12;
    position->x = x;
    position->y = y;
    position->z = z;
}

BOOL CheckBGPositionMatchGrid(const ZoneBGEntity *entity, const VecFx32 *position) {
    const s32 *coords;
    s32 zRaw;
    s32 x;
    s32 y;
    s32 z;

    if (entity->isRail == 1) {
        return FALSE;
    }
    zRaw = position->z;
    coords = &entity->pos.grid.x;
    z = (zRaw >> 4) / 4096;
    x = (position->x >> 4) / 4096;
    y = position->y >> 12;
    if (coords[0] == x && coords[1] == z && coords[2] - 2 <= y && coords[2] + 2 > y) {
        return TRUE;
    }
    return FALSE;
}

void func_ov012_0215d8fc(const ZoneBGEntity *entity, RailPosition *position) {
    u32 direction;
    const u16 *values;

    values = (const u16 *)&entity->pos.rail;
    switch (entity->direction) {
    case 0:
        direction = 1;
        break;
    case 1:
        direction = 2;
        break;
    case 2:
        direction = 3;
        break;
    case 3:
        direction = 0;
        break;
    default:
        direction = 0;
        break;
    }
    position->componentId = values[0];
    position->componentIsLine = 1;
    position->railDirection = ConvDirToRailDir(direction);
    position->posSide = ((const s16 *)values)[2];
    position->posFront = values[1];
}

BOOL CheckBGPositionMatchRail(const ZoneBGEntity *entity, const RailPosition *position) {
    const u16 *values;

    if (entity->isRail == 0) {
        return FALSE;
    }
    values = (const u16 *)&entity->pos.rail;
    if (values[0] == position->componentId && values[1] == position->posFront && (s16)values[2] == position->posSide) {
        return TRUE;
    }
    return FALSE;
}

void GetTriggerCenterPos_(const ZoneTrigger *trigger, VecFx32 *position) {
    const u16 *values;
    fx32 y;
    fx32 x;
    fx32 z;

    values = &trigger->pos.grid.x;
    z = (values[1] << 16) + FX_Div(values[3] << 16, 2 << 12);
    y = ((const s16 *)values)[4] << 12;
    x = (values[0] << 16) + FX_Div(values[2] << 16, 2 << 12);
    position->z = z;
    position->x = x;
    position->y = y;
}

BOOL CheckTriggerPositionMatchXYZ(const ZoneTrigger *trigger, const VecFx32 *position) {
    const u16 *values;
    s32 x;
    s32 y;
    s32 z;

    if (trigger->isRail == 1) {
        return FALSE;
    }
    values = &trigger->pos.grid.x;
    x = (position->x >> 4) / 4096;
    z = (position->z >> 4) / 4096;
    y = position->y >> 12;
    if (values[0] <= x && values[0] + values[2] > x && values[1] <= z && values[1] + values[3] > z &&
        ((const s16 *)values)[4] - 2 <= y && ((const s16 *)values)[4] + 2 > y) {
        return TRUE;
    }
    return FALSE;
}

BOOL CheckTriggerPositionMatchXZ(const ZoneTrigger *trigger, const VecFx32 *position) {
    s32 x;
    s32 z;
    const u16 *values;

    if (trigger->isRail == 1) {
        return FALSE;
    }
    values = &trigger->pos.grid.x;
    x = (position->x >> 4) / 4096;
    z = (position->z >> 4) / 4096;
    if (values[0] <= x && values[0] + values[2] > x && values[1] <= z && values[1] + values[3] > z) {
        return TRUE;
    }
    return FALSE;
}

BOOL CheckTriggerPositionMatchRail(const ZoneTrigger *trigger, const RailPosition *position) {
    const u16 *values;

    if (trigger->isRail == 0) {
        return FALSE;
    }
    values = &trigger->pos.rail.componentId;
    if (values[0] == position->componentId && values[1] <= position->posFront &&
        values[1] + values[3] > position->posFront && ((const s16 *)values)[2] <= position->posSide &&
        ((const s16 *)values)[2] + values[4] > position->posSide) {
        return TRUE;
    }
    return FALSE;
}
