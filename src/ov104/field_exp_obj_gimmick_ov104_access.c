#include "field/field.h"
#include "field/field_exp_obj.h"
#include "field/field_exp_obj_gimmick_ov104.h"
#include "field/field_map.h"
#include "system/game_data.h"
#include "system/game_system.h"

void func_ov104_021eed00(Field *field) {
    FieldExpObjGimmickOv104Work *work;

    work = Field_GetGimmickWorkBlock(field, 0);
    func_ov104_021eed78(work);
    if (work->state != 0) {
        func_ov104_021efc8c(work->state);
    }
    func_ov104_021eeea0(work);
}

void func_ov104_021eed20(Field *field) {
    FieldExpObjGimmickOv104Work *work;

    work = Field_GetGimmickWorkBlock(field, 0);
    func_ov104_021efcc4(work->state, data_ov104_021f0620);
    FieldExpObj_StepAllAnimations(Field_GetExpObjSystem(field));
}

u32 func_ov104_021eed44(Field *field) {
    FieldExpObjGimmickOv104Work *work;
    struct FieldExpObjGimmickOv104Substate *substate;

    work = Field_GetGimmickWorkBlock(field, 0);
    substate = work->substate;
    return (u8)substate->direction;
}

void *func_ov104_021eed58(Field *field) {
    GimmickState *state;
    u32 id;

    state = GameData_GetGimmickState(GSYS_GetGameData(Field_GetGameSystem(field)));
    id = GimmickState_GetID(state);
    return GimmickState_GetUserData(state, id);
}
