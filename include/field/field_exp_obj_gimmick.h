#ifndef POKEBW2_FIELD_FIELD_EXP_OBJ_GIMMICK_H
#define POKEBW2_FIELD_FIELD_EXP_OBJ_GIMMICK_H

#include "types.h"
#include "gfl/g3d.h"
#include "struct_decls.h"

struct FieldExpObjGimmickWork {
    u16 heapId;
};

void func_ov105_021eec80(Field *field);
void func_ov105_021eecac(Field *field);
void func_ov105_021eecc8(Field *field);
void func_ov105_021eecd4(FieldExpObjGimmickWork *work, Field *field);
void func_ov105_021eee24(FieldExpObjGimmickWork *work, Field *field);
void func_ov105_021eee28(FieldExpObjGimmickWork *work, Field *field);

void func_ov106_021eec80(Field *field);
void func_ov106_021eecac(Field *field);
void func_ov106_021eecc8(Field *field);
void func_ov106_021eecd4(Field *field);
void func_ov106_021eed04(Field *field);
BOOL func_ov106_021eed18(Field *field);
void func_ov106_021eed48(Field *field);
void func_ov106_021eed78(Field *field);
BOOL func_ov106_021eedc8(Field *field);
void func_ov106_021eedfc(FieldExpObjGimmickWork *work, Field *field);
void func_ov106_021eee50(FieldExpObjGimmickWork *work, Field *field);
void func_ov106_021eee54(FieldExpObjGimmickWork *work, Field *field);

extern const G3DSceneSetup data_ov106_021eee64;
extern const VecFx32 data_ov106_021eee74[2];

#endif // POKEBW2_FIELD_FIELD_EXP_OBJ_GIMMICK_H
