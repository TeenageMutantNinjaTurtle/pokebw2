#include "field/field.h"
#include "field/field_exp_obj.h"
#include "field/field_exp_obj_gimmick_ov104.h"
#include "gfl/std.h"
#include "save/event_work.h"
#include "system/game_data.h"
#include "system/game_system.h"

void func_ov104_021eede4(FieldExpObjGimmickOv104Work *work) {
    EventWork *eventWork;
    s32 i;
    u8 *data;
    u32 *entry;

    eventWork = GameData_GetEventWork(work->gameData);
    data = (u8 *)&((struct FieldExpObjGimmickOv104SaveData *)func_ov104_021eed58(work->field))->payload;
    for (i = 0; i < data[0]; i++) {
        entry = (u32 *)(data + 4 * i);
        if (entry[1] == 8) {
            EventWork_FlagSet(eventWork, (u16)entry[8]);
        }
    }
}

void func_ov104_021eee24(FieldExpObjGimmickOv104Work *work) {
    func_ov104_021efcfc(work->state, work->stateValue << 12);
}

FieldExpObjGimmickOv104Work *func_ov104_021eee34(Field *field) {
    u16 heapId;
    FieldExpObjSystem *system;
    FieldExpObjGimmickOv104Work *work;
    FieldExpObjGimmickOv104StateInit init;

    heapId = Field_GetHeapID(field);
    system = Field_GetExpObjSystem(field);
    work = Field_AllocGimmickWorkBlock(field, 0, heapId, sizeof(FieldExpObjGimmickOv104Work));
    sys_memset(work, 0, sizeof(FieldExpObjGimmickOv104Work));
    work->heapId = heapId;
    work->field = field;
    work->gameSystem = Field_GetGameSystem(field);
    work->gameData = GSYS_GetGameData(work->gameSystem);
    work->value = 0;
    init.heapId = heapId;
    init.a = 7;
    init.b = 8;
    init.c = 3;
    init.actor = FieldExpObj_GetActor(system, 1, 0);
    work->state = func_ov104_021efbd8(&init);
    return work;
}
