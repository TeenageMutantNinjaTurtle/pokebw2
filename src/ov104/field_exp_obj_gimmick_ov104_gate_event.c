#include "field/field_exp_obj_gimmick_ov104.h"

GameEvent *func_ov104_021f02fc(GameSystem *gsys, Field *field, u32 id) {
    GameEvent *event;
    struct FieldExpObjGimmickOv104GateEventData *data;

    event = GameEvent_Create(gsys, 0, func_ov104_021f0160, sizeof(struct FieldExpObjGimmickOv104GateEventData));
    data = GameEvent_GetData(event);
    data->gameSystem = gsys;
    data->field = field;
    data->id = id;
    return event;
}
