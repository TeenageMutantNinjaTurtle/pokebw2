#include "field/field.h"
#include "field/field_exp_obj_gimmick.h"

void func_ov105_021eec80(Field *field) {
    u16 heapId;
    FieldExpObjGimmickWork *work;

    heapId = Field_GetHeapID(field);
    work = Field_AllocGimmickWorkBlock(field, 0, heapId, sizeof(FieldExpObjGimmickWork));
    work->heapId = heapId;
    func_ov105_021eecd4(work, field);
    func_ov105_021eee24(work, field);
}

void func_ov105_021eecac(Field *field) {
    FieldExpObjGimmickWork *work;

    work = Field_GetGimmickWorkBlock(field, 0);
    func_ov105_021eee28(work, field);
    Field_DeleteGimmickWorkBlock(field, 0);
}
