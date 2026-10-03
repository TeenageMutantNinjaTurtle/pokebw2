#include "field/field.h"
#include "field/field_exp_obj_gimmick_ov104.h"
#include "save/event_work.h"
#include "system/game_data.h"

struct FieldExpObjGimmickOv104ResEntry *func_ov104_021ef180(FieldExpObjGimmickOv104Work *work) {
    u16 zone;
    EventWork *eventWork;
    s32 i;
    s32 offset;
    BOOL flag;
    BOOL zoneMatch;

    zone = Field_GetPlayerStateZoneID(work->field);
    eventWork = GameData_GetEventWork(work->gameData);
    if (work->resList == 0) {
        return 0;
    }
    for (i = 0; i < work->resCount; i++) {
        offset = i * 0x24;
        flag = EventWork_FlagGet(eventWork, (u16) * (u32 *)((u8 *)work->resList + offset + 4));
        zoneMatch = func_ov104_021f0334((struct FieldExpObjGimmickOv104ResEntry *)((u8 *)work->resList + offset), zone);
        if (func_ov104_021f037c((struct FieldExpObjGimmickOv104ResEntry *)((u8 *)work->resList + offset)) && flag &&
            zoneMatch) {
            return (struct FieldExpObjGimmickOv104ResEntry *)((u8 *)work->resList + offset);
        }
    }
    return 0;
}

struct FieldExpObjGimmickOv104ResEntry *func_ov104_021ef204(FieldExpObjGimmickOv104Work *work) {
    u16 zone;
    EventWork *eventWork;
    s32 i;
    s32 offset;
    struct FieldExpObjGimmickOv104ResEntry *entry;
    BOOL flag;
    BOOL zoneMatch;

    zone = Field_GetPlayerStateZoneID(work->field);
    eventWork = GameData_GetEventWork(work->gameData);
    if (work->resList == 0) {
        return 0;
    }
    for (i = 0; i < work->resCount; i++) {
        offset = i * 0x24;
        flag = EventWork_FlagGet(eventWork, (u16) * (u32 *)((u8 *)work->resList + offset + 4));
        zoneMatch = func_ov104_021f0334((struct FieldExpObjGimmickOv104ResEntry *)((u8 *)work->resList + offset), zone);
        if (flag && zoneMatch) {
            entry = (struct FieldExpObjGimmickOv104ResEntry *)((u8 *)work->resList + offset);
            if (*(u32 *)((u8 *)entry + 0x10) == 2) {
                return entry;
            }
        }
    }
    return 0;
}

u32 func_ov104_021ef278(FieldExpObjGimmickOv104Work *work) {
    if (func_ov104_021ef180(work) != 0) {
        return 1;
    }
    return 0;
}
