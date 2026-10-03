#include "field/badge_gate.h"
#include "field/field.h"
#include "field/field_exp_obj.h"

void func_ov103_021eefe0(Field *field) {
    BadgeGateWork *work;

    work = Field_GetGimmickWorkBlock(field, 0);
    FieldExpObj_FreeScene(work->expObj, 1);
    FieldExpObj_FreeScene(work->expObj, 2);
    FieldExpObj_FreeScene(work->expObj, 0);
    Field_DeleteGimmickWorkBlock(field, 0);
}
