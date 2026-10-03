#include "field/event_battle_lose.h"
#include "field/pleasure_boat.h"
#include "field/zone.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"

GameEvent *EventBattleLose_Create(GameSystem *gsys) {
    GameData *gameData = GSYS_GetGameData(gsys);
    GameEvent *event = GameEvent_Create(gsys, NULL, EventBattleLose_Callback, 12);
    BattleLoseData *data = GameEvent_GetData(event);
    data->gsys = gsys;
    data->returnNonLeague = IsReturnLocationNonLeaguePokeCen(gameData);
    data->playerInfo = GetGameDataPlayerInfo(gameData);
    PleasureBoat_Free(GameData_GetPleasureBoatPtr(gameData));
    func_02016b24(gsys, 0);
    return event;
}
