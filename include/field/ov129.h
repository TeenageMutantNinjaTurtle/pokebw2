#ifndef POKEBW2_FIELD_OV129_H
#define POKEBW2_FIELD_OV129_H

#include "types.h"
#include "nitro/fx.h"
#include "struct_decls.h"

// The gimmick of zones 53 and 614 (overlay 129), which script plugin 16 drives

void func_ov129_021ef078(Field *field, u16 a1);
BOOL func_ov129_021ef104(Field *field);
void func_ov129_021ef120(Field *field);
GameEvent *func_ov129_021ef3c4(GameSystem *gsys);
void func_ov129_021ef3dc(GameSystem *gsys);
// The events of the special Pokémon, which overlay 12's scrcmd_sp_poke_gimmick.c runs
GameEvent *func_ov129_021ef834(GameSystem *gsys, u16 mode, const VecFx32 *start, const VecFx32 *end, fx32 height,
                               u16 a5);
void func_ov129_021ef91c(GameSystem *gsys, u16 a1, const VecFx32 *pos);
GameEvent *func_ov129_021ef9bc(GameSystem *gsys, u16 a1);
GameEvent *func_ov129_021ef9e4(GameSystem *gsys, u16 a1);

#endif // POKEBW2_FIELD_OV129_H
