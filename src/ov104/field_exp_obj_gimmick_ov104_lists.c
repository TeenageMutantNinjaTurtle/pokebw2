#include "field/field_environment.h"
#include "field/field_exp_obj_gimmick_ov104.h"

void func_ov104_021ef994(FieldExpObjGimmickOv104Work *work) {
    s32 index;
    struct FieldExpObjGimmickOv104ResEntry *entry;

    index = 0;
    entry = func_ov104_021ef204(work);
    while (entry && index < 3) {
        func_ov104_021ef94c(work, entry, data_ov104_021f03a4[index++]);
        entry = func_ov104_021ef204(work);
    }
}

s32 func_ov104_021ef9c8(const FieldExpObjGimmickOv104ZoneList *list) {
    s32 index;
    s32 count;

    count = 0;
    for (index = 0; index < 4; index++) {
        if (list->zones[index] != 0x267 && list->weather[index] != 0xffff) {
            count++;
        }
    }
    return count;
}

void func_ov104_021ef9f8(FieldExpObjGimmickOv104ZoneList *list) {
    s32 index;

    for (index = 0; index < 4; index++) {
        list->zones[index] = 0x267;
        list->weather[index] = 0xff;
    }
}

void func_ov104_021efa18(FieldExpObjGimmickOv104Work *work, FieldExpObjGimmickOv104ZoneList *out) {
    FieldExpObjGimmickOv104ZoneList second;
    FieldExpObjGimmickOv104ZoneList first;
    s32 count;
    s32 i;
    struct FieldExpObjGimmickOv104Substate *substate;

    count = 0;
    func_ov104_021ef9f8(out);
    func_ov104_021efad0(work, &second);
    func_ov104_021efb30(work, &first);
    for (i = 0; i < 4; i++) {
        if (first.zones[i] == 0x267 || first.weather[i] == 0xffff || count >= 2) {
            break;
        }
        out->zones[count] = first.zones[i];
        out->weather[count] = first.weather[i];
        count++;
    }
    for (i = 0; i < 4; i++) {
        if (second.zones[i] == 0x267 || second.weather[i] == 0xffff || count >= 2) {
            break;
        }
        out->zones[count] = second.zones[i];
        out->weather[count] = second.weather[i];
        count++;
    }
    if (count == 0) {
        substate = work->substate;
        out->zones[0] = substate->fallbackZones[0];
        out->zones[1] = substate->fallbackZones[1];
        out->zones[2] = substate->fallbackZones[2];
        out->zones[3] = substate->fallbackZones[3];
    }
    for (i = 0; i < 4; i++) {
        out->weather[i] = Field_GetWeatherForZone(work->field, out->zones[i]);
    }
}