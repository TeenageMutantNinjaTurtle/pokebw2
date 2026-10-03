#ifndef POKEBW2_FIELD_RAIL_SLIPDOWN_H
#define POKEBW2_FIELD_RAIL_SLIPDOWN_H

#include "types.h"
#include "struct_decls.h"

// Sliding down a rail, overlay 131 (rail_slipdown.c)
void *func_ov131_021eec80(GameSystem *gsys, Field *field, FieldActor *actor, BOOL stopPlayer);
void func_ov131_021eed18(void *work);
BOOL func_ov131_021eed2c(void *work);

#endif // POKEBW2_FIELD_RAIL_SLIPDOWN_H
