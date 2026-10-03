#include "field/field.h"
#include "field/field_exp_obj.h"
#include "field/field_exp_obj_gimmick_ov104.h"
#include "gfl/heap.h"

void func_ov104_021eef84(FieldExpObjGimmickOv104Work *work) {
    if (work->substate != 0) {
        GFL_HeapFree(work->substate);
        work->substate = 0;
    }
}

void func_ov104_021eef98(FieldExpObjGimmickOv104Work *work) {
    FieldExpObjSystem *system;
    u32 anm;

    system = Field_GetExpObjSystem(work->field);
    anm = work->substate->anmIndex;
    FieldExpObj_SetAnm(system, 1, 0, data_ov104_021f066c[anm], TRUE);
}

void func_ov104_021eefc0(FieldExpObjGimmickOv104Work *work) {
    FieldExpObjSystem *system;
    SRTMatrix *matrix;
    struct FieldExpObjGimmickOv104Substate *state;
    u32 angle;

    system = Field_GetExpObjSystem(work->field);
    matrix = FieldExpObj_GetActorMatrixPtr(system, 1, 0);
    state = work->substate;
    matrix->translation.x = state->x << 12;
    matrix->translation.y = state->y << 12;
    matrix->translation.z = state->z << 12;
    switch (state->direction) {
    case 1:
        angle = 0;
        break;
    case 3:
        angle = 90;
        break;
    case 0:
        angle = 180;
        break;
    case 2:
        angle = 270;
        break;
    default:
        angle = 0;
        break;
    }
    MAT3_RotationEulerZYX(0, (u16)(angle * 182), 0, &matrix->rotation);
}
