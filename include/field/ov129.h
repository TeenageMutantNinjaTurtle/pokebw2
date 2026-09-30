#ifndef POKEBW2_FIELD_OV129_H
#define POKEBW2_FIELD_OV129_H

#include "types.h"
#include "struct_decls.h"

// The gimmick of zones 53 and 614 (overlay 129), which script plugin 16 drives

void func_ov129_021ef078(Field *field, u16 a1);
BOOL func_ov129_021ef104(Field *field);
void func_ov129_021ef120(Field *field);
GameEvent *func_ov129_021ef3c4(GameSystem *gsys);
void func_ov129_021ef3dc(GameSystem *gsys);

#endif // POKEBW2_FIELD_OV129_H
