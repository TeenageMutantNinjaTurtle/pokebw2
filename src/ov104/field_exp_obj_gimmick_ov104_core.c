#include "field/field.h"
#include "field/field_exp_obj.h"
#include "field/field_exp_obj_gimmick_ov104.h"
#include "field/field_map.h"
#include "gfl/arc.h"
#include "gfl/heap.h"
#include "gfl/std.h"
#include "save/event_work.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/version.h"

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

void func_ov104_021eed78(FieldExpObjGimmickOv104Work *work) {
    struct FieldExpObjGimmickOv104SaveData *data;

    data = func_ov104_021eed58(work->field);
    data->value = work->value;
    data->stateValue = func_ov104_021efcf0(work->state) >> 12;
    data->flag = work->flag;
    data->payload = work->payload;
}

void func_ov104_021eedb0(FieldExpObjGimmickOv104Work *work) {
    struct FieldExpObjGimmickOv104SaveData *data;

    data = func_ov104_021eed58(work->field);
    work->value = data->value;
    work->stateValue = data->stateValue;
    work->flag = data->flag;
}

void func_ov104_021eedcc(FieldExpObjGimmickOv104Work *work) {
    SaveControl *save;
    TrainerCardSave *card;

    save = GameData_GetSaveControl(work->gameData);
    card = (TrainerCardSave *)getTrainerGameInfoAddress(save);
    func_0200cb08(card, work->flag);
}

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

void func_ov104_021eeea0(FieldExpObjGimmickOv104Work *work) {
    if (work != 0) {
        func_ov104_021eef84(work);
        func_ov104_021ef168(work);
        Field_DeleteGimmickWorkBlock(work->field, 0);
    }
}

void func_ov104_021eeebc(FieldExpObjGimmickOv104Work *work) {
    SaveControl *save;
    TrainerCardSave *card;

    if (work->value == 0) {
        save = GameData_GetSaveControl_(work->gameData);
        card = getTrainerCardData_wrapper(save);
        work->flag = func_0200cb00(card);
        work->value = 1;
    }
}

void func_ov104_021eeee0(FieldExpObjGimmickOv104Work *work) {
    struct FieldExpObjGimmickOv104Substate temp;
    u32 i;
    u32 count;
    u32 zone;

    if (work->substate != 0) {
        return;
    }
    zone = Field_GetPlayerStateZoneID(work->field);
    work->substate = GFL_HeapAllocate(work->heapId, sizeof(struct FieldExpObjGimmickOv104Substate), FALSE,
                                      data_ov104_021f078c, 0x39b);
    count = GFL_ArcSysGetDataMax(0xac);
    if (count == 0) {
        return;
    }
    i = 0;
    do {
        func_ov104_021f0150(&temp, 0xac, i);
        if (temp.zoneId != zone) {
            goto next;
        }
        if (temp.version != 0 && temp.version != getGameVersion()) {
            goto next;
        }
        if (zone == 0x177 || zone == 0x17b) {
            switch (func_02017220(work->gameData)) {
            case 0:
                func_ov104_021f0150(&temp, 0xac, i + 1);
                break;
            case 1:
                break;
            }
        }
        *work->substate = temp;
        return;
    next:
        i++;
    } while (i < count);
}

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

void func_ov104_021ef02c(FieldExpObjGimmickOv104Work *work, u32 kind, u32 flag) {
    u8 *data;
    s32 count;

    data = (u8 *)&work->payload;
    count = data[0];
    if (count < 7) {
        *(u32 *)(data + 4 + count * 4) = kind;
        *(u32 *)(data + 0x20 + count * 4) = flag;
        data[0] = count + 1;
    }
}

u32 func_ov104_021ef04c(FieldExpObjGimmickOv104Work *work) {
    if (func_ov104_021ef068(work) == 1 && work->flag != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov104_021ef068(FieldExpObjGimmickOv104Work *work) {
    EventWork *eventWork;

    eventWork = GameData_GetEventWork(work->gameData);
    if (EventWork_FlagGet(eventWork, 0x960) == 1) {
        return 1;
    }
    return 0;
}