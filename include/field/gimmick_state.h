#ifndef POKEBW2_FIELD_GIMMICK_STATE_H
#define POKEBW2_FIELD_GIMMICK_STATE_H

#include "types.h"
#include "struct_decls.h"

void func_ov090_021eec80(GameSystem *gsys, u16 value);
void func_ov090_021eec98(GameSystem *gsys);
void func_ov090_021eecc0(GameSystem *gsys, BOOL first, BOOL second);

void func_ov093_021eec80(Field *field);
void func_ov093_021eecb4(Field *field);
void func_ov093_021eecc0(Field *field);

void func_ov095_021eec80(Field *field);
void func_ov095_021eecac(Field *field);
void func_ov095_021eecb8(Field *field);

#endif // POKEBW2_FIELD_GIMMICK_STATE_H
