#include "field/field.h"
#include "field/field_exp_obj_gimmick_ov104.h"
#include "gfl/arc.h"
#include "gfl/heap.h"
#include "system/game_data.h"
#include "system/version.h"

void func_ov104_021eeee0(FieldExpObjGimmickOv104Work *work) {
    struct FieldExpObjGimmickOv104Substate temp;
    u32 i;
    u32 count;
    u32 zone;

    if (work->substate != 0) {
        return;
    }
    zone = Field_GetPlayerStateZoneID(work->field);
    work->substate = GFL_HeapAllocate(work->heapId, sizeof(struct FieldExpObjGimmickOv104Substate), FALSE,
                                      data_ov104_021f078c, 0x39b);
    count = GFL_ArcSysGetDataMax(0xac);
    if (count == 0) {
        return;
    }
    i = 0;
    do {
        func_ov104_021f0150(&temp, 0xac, i);
        if (temp.zoneId != zone) {
            goto next;
        }
        if (temp.version != 0 && temp.version != getGameVersion()) {
            goto next;
        }
        if (zone == 0x177 || zone == 0x17b) {
            switch (func_02017220(work->gameData)) {
            case 0:
                func_ov104_021f0150(&temp, 0xac, i + 1);
                break;
            case 1:
                break;
            }
        }
        *work->substate = temp;
        return;
    next:
        i++;
    } while (i < count);
}
