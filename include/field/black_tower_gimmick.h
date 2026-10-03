#ifndef POKEBW2_FIELD_BLACK_TOWER_GIMMICK_H
#define POKEBW2_FIELD_BLACK_TOWER_GIMMICK_H

#include "types.h"
#include "struct_decls.h"

// The gimmick of the Black Tower and White Treehollow (overlay 127), which their script plugin (overlay 61) drives

typedef struct {
    u8 unk0;
    u8 unk1[0x17];
} BlackTowerGimmickUnk18;

typedef struct {
    BlackTowerGimmickUnk18 unk0[16];
} BlackTowerGimmickUnk180;

typedef struct {
    u8 unk0[0x150];
    BlackTowerGimmickUnk180 unk150[6];
    u8 unkA50[0xa];
    u8 unkA5A;
    u8 unkA5B;
    u8 unkA5C[2];
    u16 unkA5E;
    u8 unkA60;
} BlackTowerGimmick;

BlackTowerGimmick *func_ov127_021ef010(Field *field);
GameEvent *func_ov127_021ef01c(GameSystem *gsys, Field *field, u16 a2, u16 a3);
GameEvent *func_ov127_021ef050(GameSystem *gsys, Field *field);
GameEvent *func_ov127_021ef254(GameSystem *gsys, Field *field);
void func_ov127_021ef664(ScriptWork *work, GameSystem *gsys, BlackTowerGimmick *gimmick, u16 a3, u8 a4, u8 a5);
void func_ov127_021ef6ac(ScriptWork *work, GameSystem *gsys, BlackTowerGimmick *gimmick, u16 a3);
void func_ov127_021efd60(GameSystem *gsys, BlackTowerGimmick *gimmick);
GameEvent *func_ov127_021efeec(GameSystem *gsys, Field *field, u8 a2);
u8 func_ov127_021f02e0(BlackTowerGimmick *gimmick);
u16 func_ov127_021f0358(KeyDataSave *keyData, BlackTowerGimmick *gimmick, u16 objCode, u8 a3);
u16 func_ov127_021f03dc(KeyDataSave *keyData, BlackTowerGimmick *gimmick, u16 objCode, u16 a3);
u32 func_ov127_021f08b4(BlackTowerGimmick *gimmick, u16 a1);
u16 func_ov127_021f08e8(BlackTowerGimmick *gimmick);
u16 func_ov127_021f093c(BlackTowerGimmick *gimmick, u8 a1, u8 a2);
u16 func_ov127_021f0a9c(u8 a0);
u16 func_ov127_021f0db4(BlackTowerGimmick *gimmick, u8 a1, u8 a2);
u32 func_ov127_021f0dd8(BlackTowerGimmick *gimmick);
u16 func_ov127_021f0e70(BlackTowerGimmick *gimmick, u8 a1, u8 a2);
GameEvent *func_ov127_021f1c80(GameSystem *gsys, Field *field, u32 arg2, u32 *result);

#endif // POKEBW2_FIELD_BLACK_TOWER_GIMMICK_H
