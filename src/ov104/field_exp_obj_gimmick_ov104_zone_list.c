#include "field/field_exp_obj_gimmick_ov104.h"

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
