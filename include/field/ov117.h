#ifndef POKEBW2_FIELD_OV117_H
#define POKEBW2_FIELD_OV117_H

#include "types.h"
#include "struct_decls.h"

// The gimmick of zones 561 and 564 of the Plasma Frigate (overlay 117), which the frigate's script plugin drives

GameEvent *func_ov117_021eed00(GameSystem *gsys, u16 a1);
void func_ov117_021eed24(GameSystem *gsys, u16 a1, BOOL a2);
void func_ov117_021eed64(GameSystem *gsys, u16 a1);
void func_ov117_021eed88(GameSystem *gsys, u16 a1);

#endif // POKEBW2_FIELD_OV117_H
