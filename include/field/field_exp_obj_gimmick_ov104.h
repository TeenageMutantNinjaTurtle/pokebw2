#ifndef POKEBW2_FIELD_FIELD_EXP_OBJ_GIMMICK_OV104_H
#define POKEBW2_FIELD_FIELD_EXP_OBJ_GIMMICK_OV104_H

#include "types.h"
#include "gfl/g3d.h"
#include "struct_decls.h"

struct FieldExpObjGimmickOv104Substate {
    u8 unk00[8];
    u32 x;
    u32 y;
    u32 z;
    u32 direction;
    u8 unk18[0x5c];
    u32 anmIndex;
};

struct FieldExpObjGimmickOv104Payload {
    u8 count;
    u8 padding[3];
    u32 kinds[7];
    u32 flags[7];
};

struct FieldExpObjGimmickOv104SaveData {
    u32 value;
    u32 stateValue;
    u16 flag;
    u16 padding;
    struct FieldExpObjGimmickOv104Payload payload;
};

struct FieldExpObjGimmickOv104StateInit {
    u16 heapId;
    u8 a;
    u8 b;
    u8 c;
    u8 padding[3];
    G3DActor *actor;
};

struct FieldExpObjGimmickOv104Work {
    u16 heapId;
    u16 pad02;
    Field *field;
    GameData *gameData;
    GameSystem *gameSystem;
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
void func_ov104_021eede4(FieldExpObjGimmickOv104Work *work);
void func_ov104_021eee24(FieldExpObjGimmickOv104Work *work);
FieldExpObjGimmickOv104Work *func_ov104_021eee34(Field *field);
void func_ov104_021eeebc(FieldExpObjGimmickOv104Work *work);
void func_ov104_021eef84(FieldExpObjGimmickOv104Work *work);
void func_ov104_021eef98(FieldExpObjGimmickOv104Work *work);
void func_ov104_021eefc0(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef02c(FieldExpObjGimmickOv104Work *work, u32 kind, u32 flag);
u32 func_ov104_021ef04c(FieldExpObjGimmickOv104Work *work);
u32 func_ov104_021ef068(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef168(FieldExpObjGimmickOv104Work *work);
void func_ov104_021efc8c(void *state);
void func_ov104_021eeea0(FieldExpObjGimmickOv104Work *work);
void func_ov104_021efcc4(void *state, u32 value);
s32 func_ov104_021efcf0(void *state);
void func_ov104_021efcfc(void *state, s32 value);
void *func_ov104_021efbd8(const FieldExpObjGimmickOv104StateInit *init);

void func_ov104_021eed00(Field *field);
void func_ov104_021eed20(Field *field);
u32 func_ov104_021eed44(Field *field);
void *func_ov104_021eed58(Field *field);

extern u32 data_ov104_021f0620;
extern const u16 data_ov104_021f066c[];

#endif // POKEBW2_FIELD_FIELD_EXP_OBJ_GIMMICK_OV104_H
