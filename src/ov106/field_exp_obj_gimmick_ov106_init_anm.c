#include "field/field.h"
#include "field/field_exp_obj.h"
#include "field/field_exp_obj_gimmick.h"

void func_ov106_021eecd4(Field *field) {
    FieldExpObjSystem *system;
    FieldExpObjAnm *anm;

    system = Field_GetExpObjSystem(field);
    FieldExpObj_SetAnm(system, 0, 0, 0, TRUE);
    anm = FieldExpObj_GetAnmInfo(system, 0, 0, 0);
    FieldExpObjAnm_SetLooped(anm, FALSE);
}
