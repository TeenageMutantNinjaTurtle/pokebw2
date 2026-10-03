#include "field/field_exp_obj_gimmick_ov104.h"

void func_ov104_021ef994(FieldExpObjGimmickOv104Work *work) {
    s32 index;
    struct FieldExpObjGimmickOv104ResEntry *entry;

    index = 0;
    entry = func_ov104_021ef204(work);
    while (entry && index < 3) {
        func_ov104_021ef94c(work, entry, data_ov104_021f03a4[index++]);
        entry = func_ov104_021ef204(work);
    }
}
