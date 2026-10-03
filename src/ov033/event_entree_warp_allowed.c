#include "field/field.h"
#include "field/field_actor.h"
#include "field/field_event.h"
#include "field/field_player.h"
#include "field/zone.h"
#include "system/game_data.h"
#include "system/game_system.h"

typedef struct {
    u16 x;
    u16 z;
    s32 y;
} NPCGridPosition;

typedef struct {
    u16 railIndex;
    u16 frontPos;
    s16 sidePos;
} NPCRailPosition;

BOOL EventEntralinkWarpIn_CheckAllowed(GameSystem *gsys) {
    GameData *gameData;
    EventData *eventData;
    ZoneNPC *npcs;
    Field *field;
    MMSys *actorSystem;
    NPCGridPosition *npcPosition;
    s32 npcCount;
    NPCRailPosition *npcRail;
    FieldPlayer *player;
    u32 zoneId;
    EventWork *eventWork;
    FieldActor *playerActor;
    VecFx32 worldPosition;
    s16 playerX;
    s16 playerY;
    s16 playerZ;
    RailPosition railPosition;
    u8 modelInfo[28];
    s32 i;
    ZoneNPC *npc;

    gameData = GSYS_GetGameData(gsys);
    eventData = GameData_GetEventData(gameData);
    npcs = GetZoneNPCs(eventData);
    npcCount = GetZoneNPCsCount(eventData);
    field = GSYS_GetField(gsys);
    actorSystem = Field_GetActorSystem(field);
    player = Field_GetPlayer(field);
    zoneId = Field_GetPlayerStateZoneID(field);
    if (!GetZoneFlagsEnableEntralinkWarp(zoneId)) {
        return FALSE;
    }
    if ((u32)(FieldPlayer_GetExState(player) - 2) <= 1) {
        return FALSE;
    }
    if (Field_GetResolvedControllerTypeID(field) == 0) {
        playerActor = FieldPlayer_GetActor(player);
        eventWork = GameData_GetEventWork(gameData);
        CopyActorWPos(playerActor, &worldPosition);
        if (FindCollidingZoneTriggerAtLocation(eventData, eventWork, &worldPosition)) {
            return FALSE;
        }
    }
    if ((npcs == NULL || npcCount == 0) && zoneId != 0 && zoneId != 0x1a8) {
        return TRUE;
    }
    for (i = 0; i < npcCount; i++) {
        npc = &npcs[i];
        if (npc->isRail == FALSE) {
            npcPosition = (NPCGridPosition *)&npc->pos.grid;
            GetNPCMdlInfoForOBJCODE(actorSystem, npc->modelId, modelInfo);
            FieldPlayer_GetGPos(player, &playerX, &playerY, &playerZ);
            if (npcPosition->x <= playerX && playerX < npcPosition->x + modelInfo[11] &&
                npcPosition->z - modelInfo[12] < playerZ && playerZ <= npcPosition->z) {
                return FALSE;
            }
        } else if (npc->isRail == TRUE) {
            npcRail = (NPCRailPosition *)&npc->pos.rail;
            if (Field_GetResolvedControllerTypeID(field) == 1) {
                func_ov036_0219ad24(player, &railPosition);
                if (npcRail->railIndex == railPosition.componentId && npcRail->frontPos == railPosition.posFront &&
                    npcRail->sidePos == railPosition.posSide) {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}
