#include "field/field.h"
#include "field/field_exp_obj_gimmick_ov104.h"

void func_ov104_021eeea0(FieldExpObjGimmickOv104Work *work) {
    if (work != 0) {
        func_ov104_021eef84(work);
        func_ov104_021ef168(work);
        Field_DeleteGimmickWorkBlock(work->field, 0);
    }
}
