#include "types.h"
#include "constants/zones.h"
#include "field/hidden_hollow.h"
#include "field/rival_select.h"
#include "field/townmap_util.h"
#include "field/unity_tower.h"
#include "field/zone.h"
#include "save/event_work.h"
#include "save/key_info.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "system/game_data.h"

// The work that says which way the Pokémon World Tournament's hall faces
#define WORK_PWT_HALL 0x4044

// The pseudo flags the town map asks about
#define TOWNMAP_FLAG_ONE_SHOT_DR 0xf000
#define TOWNMAP_FLAG_UNITY_TOWER_VISITED 0xf001
#define TOWNMAP_FLAG_PWT_HALL 0xf002

// The Union Room, the Pokémon World Tournament (0x228), the Hidden Grottoes (0x206) and the Black City or White Forest
// gates (0x1de) show on the map where the player entered them, or by the game state
u16 func_ov012_02160eb4(GameData *gameData, u16 zoneId) {
    u16 parent = GetZoneParentZone(zoneId);

    if (parent == ZONE_UNION_ROOM) {
        return GetZoneParentZone(GameData_GetNextZone(gameData)->zoneId);
    }
    if (parent == 0x228) {
        switch (*EventWork_GetWkPtr(GameData_GetEventWork(gameData), WORK_PWT_HALL)) {
        default:
        case 0:
            return 0xbf;
        case 1:
            return 0x1cf;
        case 2:
            return 0xe6;
        case 3:
            return 0x228;
        }
    }
    if (parent == 0x206) {
        return GetZoneParentZone(GetHiddenHollowEntranceParam(
            getHollowNum(getHollow_RivalData(GameData_GetSaveControl(gameData))), 0));
    }
    if (parent == 0x1de || IsZoneBlackCityOrWhiteForestLobby(parent)) {
#ifdef BLACK2
        if (KeyInfo_GetCityKey(getKeyInfoSaveBlk(GameData_GetSaveControl(gameData))) == 0) {
            return 0;
        }
        return 0x1a8;
#else
        if (KeyInfo_GetCityKey(getKeyInfoSaveBlk(GameData_GetSaveControl(gameData))) == 0) {
            return 0x1a8;
        }
        return 0;
#endif
    }
    return parent;
}

BOOL func_ov012_02160f74(GameData *gameData, u16 flag) {
    EventWork *eventWork = GameData_GetEventWork(gameData);
    TrainerCardSave *trainerCard = getTrainerCardDataBlkAddress(gameData);
    PlayerInfo *info = GetGameDataPlayerInfo(gameData);
    UnityTowerSurveySave *survey = getUnityTower_SurveySaveBlkAddrress(GameData_GetSaveControl(gameData));
    BOOL result;

    switch (flag) {
    case TOWNMAP_FLAG_ONE_SHOT_DR:
        return isOneShotDRObtained(trainerCard, 1, info);
    case TOWNMAP_FLAG_UNITY_TOWER_VISITED:
        result = FALSE;
        if (func_02009cac(survey, info, 0) >= 1) {
            result = TRUE;
        }
        return result;
    case TOWNMAP_FLAG_PWT_HALL:
        if (*EventWork_GetWkPtr(eventWork, WORK_PWT_HALL) == 3) {
            return TRUE;
        }
        return FALSE;
    }
    return EventWork_FlagGet(eventWork, flag);
}
