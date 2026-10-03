#ifndef POKEBW2_FIELD_GIMMICK_STATE_H
#define POKEBW2_FIELD_GIMMICK_STATE_H

#include "types.h"
#include "struct_decls.h"

// Overlay 90, which sets up the saved state of some gimmicks
void func_ov090_021eec80(GameSystem *gsys, u16 value);
void func_ov090_021eec98(GameSystem *gsys);
void func_ov090_021eecc0(GameSystem *gsys, BOOL first, BOOL second);

#endif // POKEBW2_FIELD_GIMMICK_STATE_H
