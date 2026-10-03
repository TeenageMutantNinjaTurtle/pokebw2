#ifndef POKEBW2_FIELD_FIELD_EXP_OBJ_GIMMICK_OV104_H
#define POKEBW2_FIELD_FIELD_EXP_OBJ_GIMMICK_OV104_H

#include "types.h"
#include "struct_decls.h"

struct FieldExpObjGimmickOv104Substate {
    u8 unk00[0x14];
    u32 value;
};

struct FieldExpObjGimmickOv104Payload {
    u32 words[15];
};

struct FieldExpObjGimmickOv104SaveData {
    u32 value;
    u32 stateValue;
    u16 flag;
    u16 padding;
    struct FieldExpObjGimmickOv104Payload payload;
};

struct FieldExpObjGimmickOv104Work {
    u32 unk00;
    Field *field;
    GameData *gameData;
    u32 unk0c;
    u32 value;
    void *state;
    u32 stateValue;
    struct FieldExpObjGimmickOv104Substate *substate;
    u8 unk20[8];
    struct FieldExpObjGimmickOv104Payload payload;
    u16 flag;
};

void func_ov104_021eed78(FieldExpObjGimmickOv104Work *work);
void func_ov104_021eedb0(FieldExpObjGimmickOv104Work *work);
void func_ov104_021eedcc(FieldExpObjGimmickOv104Work *work);
void func_ov104_021efc8c(void *state);
void func_ov104_021eeea0(FieldExpObjGimmickOv104Work *work);
void func_ov104_021efcc4(void *state, u32 value);
s32 func_ov104_021efcf0(void *state);

void func_ov104_021eed00(Field *field);
void func_ov104_021eed20(Field *field);
u32 func_ov104_021eed44(Field *field);
void *func_ov104_021eed58(Field *field);

extern u32 data_ov104_021f0620;

#endif // POKEBW2_FIELD_FIELD_EXP_OBJ_GIMMICK_OV104_H
