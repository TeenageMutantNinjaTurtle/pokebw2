#include "field/field_palace.h"
#include "field/zone.h"
#include "save/event_work.h"
#include "system/game_data.h"

BOOL FieldPalaceSys_CheckEventFlag(GameData *gameData, u16 zoneId) {
    EventWork *eventWork;
    u32 index;

    eventWork = GameData_GetEventWork(gameData);
    if (GetZoneIsEntralinkAny(zoneId) == TRUE) {
        for (index = 0; index < 25; index++) {
            if (zoneId == *(const u16 *)((const u8 *)ENTRALINK_WORLD_ZONES + index * 4)) {
                if (EventWork_FlagGet(eventWork, *(const u16 *)((const u8 *)data_ov036_021d4706 + index * 4)) == TRUE) {
                    return TRUE;
                }
                return FALSE;
            }
        }
    }
    return TRUE;
}
