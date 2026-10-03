#include "field/field_exp_obj_gimmick_ov104.h"
#include "save/event_work.h"
#include "system/game_data.h"

void func_ov104_021ef28c(FieldExpObjGimmickOv104Work *work, u32 message, u32 kind, void *arg) {
    func_ov104_021efc6c(work->state, (FieldExpObjGimmickOv104MessageArg *)message);
    if (kind == 8) {
        func_ov104_021ef02c(work, kind, *(u32 *)((u8 *)arg + 4));
    } else {
        func_ov104_021ef02c(work, kind, 0);
    }
    if (kind == 8 && *(u32 *)((u8 *)arg + 8) == 1) {
        EventWork_FlagReset(GameData_GetEventWork(work->gameData), (u16)*(u32 *)((u8 *)arg + 4));
    }
}

void func_ov104_021ef2cc(FieldExpObjGimmickOv104Work *work) {
    if (func_ov104_021ef04c(work) == 1) {
        func_ov104_021ef344(work);
        return;
    }
    if (func_ov104_021ef278(work) != 0) {
        func_ov104_021ef380(work);
        return;
    }
    func_ov104_021ef2fc(work);
}

void func_ov104_021ef2fc(FieldExpObjGimmickOv104Work *work) {
    if (!func_ov104_021efcf8(work->state) && work->substate && work->substate->enabled) {
        func_ov104_021ef5ac(work);
        func_ov104_021ef3c0(work);
        func_ov104_021ef43c(work);
        func_ov104_021ef658(work);
        func_ov104_021ef6dc(work);
        func_ov104_021ef760(work);
        func_ov104_021ef7e4(work);
    }
}
