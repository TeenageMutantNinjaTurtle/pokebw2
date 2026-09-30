#ifndef POKEBW2_FIELD_OV134_H
#define POKEBW2_FIELD_OV134_H

#include "types.h"
#include "field/wbt.h"
#include "gfl/str.h"
#include "struct_decls.h"

// The gimmick of the Pokémon World Tournament's stadium (zone 193, overlay 134, which names wbt_battle.c), which
// script plugin 7 drives

void func_ov134_021eecf0(Field *field, u8 a1, StrBuf *a2, StrBuf *a3, u32 a4, u32 a5);
void func_ov134_021eeda0(Field *field, u8 a1);
void func_ov134_021eedfc(Field *field, u8 a1, u8 a2);
void func_ov134_021eef78(Field *field);
void func_ov134_021eefdc(Field *field, u8 a1, u8 a2);
void func_ov134_021ef034(Field *field, u8 a1);
void func_ov134_021efc60(WbtSystem *sys);
void func_ov134_021efd14(WbtSystem *sys);
void func_ov134_021efd48(WbtSystem *sys, u32 index, u8 value);
void func_ov134_021efd54(WbtSystem *sys, u32 a1);
u8 func_ov134_021efdbc(WbtSystem *sys, u32 index);
void *func_ov134_021efdc8(FieldScriptEnv *env, WbtSystem *sys);
void func_ov134_021efe24(void *work);
void func_ov134_021efeec(void *work);
void func_ov134_021eff04(void *work);
void func_ov134_021f03cc(WbtSystem *sys, GameSystem *gsys, WbtEntrant *opponent);
u8 func_ov134_021f062c(WbtSystem *sys, u16 round);
// The player's opponent in the current round
WbtEntrant *func_ov134_021f0724(WbtSystem *sys);
u32 func_ov134_021f0738(WbtSystem *sys);
u16 func_ov134_021f0748(WbtSystem *sys);
// The opponent's name
void func_ov134_021f0754(WbtSystem *sys, StrBuf *strbuf);
void func_ov134_021f08b8(WbtSystem *sys, u32 a1, StrBuf *strbuf);

#endif // POKEBW2_FIELD_OV134_H
