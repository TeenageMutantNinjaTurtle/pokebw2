#ifndef POKEBW2_FIELD_OV133_H
#define POKEBW2_FIELD_OV133_H

#include "types.h"
#include "struct_decls.h"

// The gimmick of overlay 133, whose state is gimmick 0x20's user data. Script commands 0x23B to 0x23D of overlay 12's
// scrcmd_sp_poke.c drive it

void func_ov133_021eee1c(Field *field);
GameEvent *func_ov133_021eee7c(GameSystem *gsys);

#endif // POKEBW2_FIELD_OV133_H
