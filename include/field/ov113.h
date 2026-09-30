#ifndef POKEBW2_FIELD_OV113_H
#define POKEBW2_FIELD_OV113_H

#include "types.h"
#include "struct_decls.h"

// The gimmick of zones 463, 465 and 474 (overlay 113), which script plugin 15 drives

// Shows an effect object at a position given in whole units, and plays SE 0x8d7
void func_ov113_021eecd8(GameSystem *gsys, u16 x, u16 y, u16 z);
// Moves an actor from the effect object's place to a grid position
GameEvent *func_ov113_021eed38(GameSystem *gsys, u16 actorId, u16 x, u16 z, u16 a4);

#endif // POKEBW2_FIELD_OV113_H
