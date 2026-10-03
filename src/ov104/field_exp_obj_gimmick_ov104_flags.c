#include "field/field_exp_obj_gimmick_ov104.h"
#include "save/event_work.h"
#include "system/game_data.h"

void func_ov104_021ef02c(FieldExpObjGimmickOv104Work *work, u32 kind, u32 flag) {
    u8 *data;
    s32 count;

    data = (u8 *)&work->payload;
    count = data[0];
    if (count < 7) {
        *(u32 *)(data + 4 + count * 4) = kind;
        *(u32 *)(data + 0x20 + count * 4) = flag;
        data[0] = count + 1;
    }
}

u32 func_ov104_021ef04c(FieldExpObjGimmickOv104Work *work) {
    if (func_ov104_021ef068(work) == 1 && work->flag != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov104_021ef068(FieldExpObjGimmickOv104Work *work) {
    EventWork *eventWork;

    eventWork = GameData_GetEventWork(work->gameData);
    if (EventWork_FlagGet(eventWork, 0x960) == 1) {
        return 1;
    }
    return 0;
}
