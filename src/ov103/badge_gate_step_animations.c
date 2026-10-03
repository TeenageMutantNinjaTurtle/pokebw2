#include "field/badge_gate.h"
#include "field/field.h"
#include "field/field_exp_obj.h"

void func_ov103_021ef010(Field *field) {
    void *work;

    work = Field_GetGimmickWorkBlock(field, 0);
    FieldExpObj_StepAllAnimations(*(FieldExpObjSystem **)((u8 *)work + 4));
}
