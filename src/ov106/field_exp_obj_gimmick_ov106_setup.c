#include "field/field.h"
#include "field/field_exp_obj.h"
#include "field/field_exp_obj_gimmick.h"

void func_ov106_021eedfc(FieldExpObjGimmickWork *work, Field *field) {
    FieldExpObjSystem *system;
    SRTMatrix *matrix;
    s32 i;

    system = Field_GetExpObjSystem(field);
    LoadFieldExpandObjData(system, &data_ov106_021eee64, 0);
    for (i = 0; i < 2; i++) {
        matrix = FieldExpObj_GetActorMatrixPtr(system, 0, i);
        matrix->translation.x = data_ov106_021eee74[i].x;
        matrix->translation.y = data_ov106_021eee74[i].y;
        matrix->translation.z = data_ov106_021eee74[i].z;
    }
    func_ov106_021eed04(field);
    func_ov106_021eed48(field);
}
