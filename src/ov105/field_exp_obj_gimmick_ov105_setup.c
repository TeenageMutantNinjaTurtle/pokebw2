#include "field/field.h"
#include "field/field_exp_obj.h"
#include "field/field_exp_obj_gimmick.h"
#include "save/event_work.h"
#include "system/game_data.h"
#include "system/game_system.h"

void func_ov105_021eecd4(FieldExpObjGimmickWork *work, Field *field) {
    EventWork *eventWork;
    FieldExpObjSystem *system;
    SRTMatrix *matrix;
    s32 flags[4];
    s32 i;

    eventWork = GameData_GetEventWork(GSYS_GetGameData(Field_GetGameSystem(field)));
    flags[0] = EventWork_FlagGet(eventWork, 0x969);
    flags[1] = EventWork_FlagGet(eventWork, 0x968);
    flags[2] = EventWork_FlagGet(eventWork, 0x967);
    flags[3] = EventWork_FlagGet(eventWork, 0x96a);
    system = Field_GetExpObjSystem(field);
    LoadFieldExpandObjData(system, &data_ov105_021eee54, 0);
    for (i = 0; i < 6; i++) {
        matrix = FieldExpObj_GetActorMatrixPtr(system, 0, i);
        matrix->translation.x = data_ov105_021eee64[i].x;
        matrix->translation.y = data_ov105_021eee64[i].y;
        matrix->translation.z = data_ov105_021eee64[i].z;
    }
    if (flags[0] && flags[1] && flags[2] && flags[3]) {
        FieldExpObj_SetAnm(system, 0, 0, 0, TRUE);
        FieldExpObj_SetAnm(system, 0, 1, 0, TRUE);
    }
    if (flags[0]) {
        FieldExpObj_SetAnm(system, 0, 2, 1, TRUE);
    } else {
        FieldExpObj_SetAnm(system, 0, 2, 0, TRUE);
    }
    if (flags[1]) {
        FieldExpObj_SetAnm(system, 0, 3, 1, TRUE);
    } else {
        FieldExpObj_SetAnm(system, 0, 3, 0, TRUE);
    }
    if (flags[2]) {
        FieldExpObj_SetAnm(system, 0, 4, 1, TRUE);
    } else {
        FieldExpObj_SetAnm(system, 0, 4, 0, TRUE);
    }
    if (flags[3]) {
        FieldExpObj_SetAnm(system, 0, 5, 1, TRUE);
    } else {
        FieldExpObj_SetAnm(system, 0, 5, 0, TRUE);
    }
}
