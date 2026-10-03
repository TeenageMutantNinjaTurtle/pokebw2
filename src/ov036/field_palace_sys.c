#include "types.h"
#include "field/field_palace.h"
#include "field/zone.h"
#include "gfl/heap.h"
#include "save/event_work.h"
#include "system/game_data.h"

FieldPalaceSys *FieldPalaceSys_Create(HeapID heapId, u32 a1, u32 a2, u32 a3) {
    FieldPalaceSys *sys;

    sys = GFL_HeapAllocate(heapId, sizeof(FieldPalaceSys), TRUE, "field_palace_sys.c", 67);
    sys->unk00 = a1;
    sys->unk04 = a2;
    sys->luminanceTable = NULL;
    FieldPalaceSys_InitPostFX(sys, a3, heapId);
    return sys;
}

void FieldPalaceSys_Free(FieldPalaceSys *sys) {
    if (sys->luminanceTable != NULL) {
        GFL_HeapFree(sys->luminanceTable);
    }
    GFL_HeapFree(sys);
}

void *FieldPalaceSys_GetLuminanceTable(FieldPalaceSys *sys) {
    return sys->luminanceTable;
}

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
