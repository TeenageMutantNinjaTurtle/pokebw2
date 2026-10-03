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
    u32 enabled;
};

struct FieldExpObjGimmickOv104Payload {
    u8 count;
    u8 padding[3];
    u32 kinds[7];
    u32 flags[7];
};

struct FieldExpObjGimmickOv104MessageArg {
    u16 kind;
    u16 padding;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
    u32 unk10;
    u32 unk14;
    struct WordSet *wordSet;
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

struct FieldExpObjGimmickOv104ResEntry {
    u32 unk00;
    u32 flagId;
    u8 unk08[8];
    u32 type;
    u8 unk14[0x10];
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
    struct FieldExpObjGimmickOv104ResEntry *resList;
    u8 resCount;
    u8 unk25[3];
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
void func_ov104_021ef114(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef168(FieldExpObjGimmickOv104Work *work);
struct FieldExpObjGimmickOv104ResEntry *func_ov104_021ef180(FieldExpObjGimmickOv104Work *work);
struct FieldExpObjGimmickOv104ResEntry *func_ov104_021ef204(FieldExpObjGimmickOv104Work *work);
u32 func_ov104_021ef278(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef28c(FieldExpObjGimmickOv104Work *work, u32 unused, u32 kind, void *arg);
void func_ov104_021ef2cc(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef2fc(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef344(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef380(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef3c0(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef43c(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef5ac(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef658(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef6dc(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef760(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef7e4(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef868(FieldExpObjGimmickOv104Work *work);
void func_ov104_021ef924(FieldExpObjGimmickOv104Work *work);
void func_ov104_021f0324(struct FieldExpObjGimmickOv104ResEntry *entry, u32 arc, u32 index);
BOOL func_ov104_021f0334(struct FieldExpObjGimmickOv104ResEntry *entry, u16 zone);
BOOL func_ov104_021f037c(struct FieldExpObjGimmickOv104ResEntry *entry);
void func_ov104_021ef168(FieldExpObjGimmickOv104Work *work);
void func_ov104_021efc8c(void *state);
void func_ov104_021eeea0(FieldExpObjGimmickOv104Work *work);
void func_ov104_021efcc4(void *state, u32 value);
s32 func_ov104_021efcf0(void *state);
void func_ov104_021efcfc(void *state, s32 value);
void func_ov104_021efc6c(void *state);
BOOL func_ov104_021efcf8(void *state);
void *func_ov104_021efbd8(const FieldExpObjGimmickOv104StateInit *init);

void func_ov104_021eed00(Field *field);
void func_ov104_021eed20(Field *field);
u32 func_ov104_021eed44(Field *field);
void *func_ov104_021eed58(Field *field);

extern u32 data_ov104_021f0620;
extern const u16 data_ov104_021f066c[];
extern const char data_ov104_021f078c[];

#endif // POKEBW2_FIELD_FIELD_EXP_OBJ_GIMMICK_OV104_H
