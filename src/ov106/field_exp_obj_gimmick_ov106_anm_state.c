#include "field/field.h"
#include "field/field_exp_obj.h"
#include "field/field_exp_obj_gimmick.h"

void func_ov106_021eed04(Field *field) {
    FieldExpObj_SetAnm(Field_GetExpObjSystem(field), 0, 0, 0, FALSE);
}

BOOL func_ov106_021eed18(Field *field) {
    s32 i;
    FieldExpObjSystem *system;
    FieldExpObjAnm *anm;

    system = Field_GetExpObjSystem(field);
    for (i = 0; i < 1; i++) {
        anm = FieldExpObj_GetAnmInfo(system, 0, 0, i);
        if (!FieldExpObjAnm_IsPlaybackFinished(anm)) {
            return FALSE;
        }
    }
    return TRUE;
}

void func_ov106_021eed48(Field *field) {
    s32 i;
    FieldExpObjSystem *system;

    system = Field_GetExpObjSystem(field);
    FieldExpObj_SetActorHidden(system, 0, 1, TRUE);
    for (i = 0; i < 2; i++) {
        FieldExpObj_SetAnm(system, 0, 1, i, FALSE);
    }
}
