#ifndef POKEBW2_FIELD_OV132_H
#define POKEBW2_FIELD_OV132_H

#include "types.h"
#include "nitro/fx.h"
#include "struct_decls.h"

// The gimmick of zone 213 (overlay 132), which script plugin 14 drives

GameEvent *func_ov132_021eed78(GameSystem *gsys);
GameEvent *func_ov132_021eef30(GameSystem *gsys, const VecFx32 *from, const VecFx32 *to, fx32 a3, u16 a4);
void func_ov132_021ef004(GameSystem *gsys, const VecFx32 *pos);
GameEvent *func_ov132_021ef080(GameSystem *gsys);
GameEvent *func_ov132_021ef09c(GameSystem *gsys);

#endif // POKEBW2_FIELD_OV132_H
