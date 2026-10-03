#include "field/field_map.h"
#include "field/zone.h"
#include "save/event_work.h"
#include "system/game_data.h"
#include "system/game_system.h"

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
