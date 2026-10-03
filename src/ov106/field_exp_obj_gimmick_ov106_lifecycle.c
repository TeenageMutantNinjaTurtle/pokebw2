#include "field/field.h"
#include "field/field_exp_obj_gimmick.h"

void func_ov106_021eec80(Field *field) {
    u16 heapId;
    FieldExpObjGimmickWork *work;

    heapId = Field_GetHeapID(field);
    work = Field_AllocGimmickWorkBlock(field, 1, heapId, sizeof(FieldExpObjGimmickWork));
    work->heapId = heapId;
    func_ov106_021eedfc(work, field);
    func_ov106_021eee50(work, field);
}

void func_ov106_021eecac(Field *field) {
    FieldExpObjGimmickWork *work;

    work = Field_GetGimmickWorkBlock(field, 1);
    func_ov106_021eee54(work, field);
    Field_DeleteGimmickWorkBlock(field, 1);
}
