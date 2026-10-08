#ifndef POKEBW2_FIELD_GIMMICK_HUMILAU_H
#define POKEBW2_FIELD_GIMMICK_HUMILAU_H

#include "types.h"
#include "struct_decls.h"

// The gimmick of Route 21, Humilau City and Route 22 (zones 463, 465 and 474, gimmick 54), overlay 113

// Overlay 36's gimmick table calls these
void func_ov113_021eec80(Field *field);
void func_ov113_021eecb0(Field *field);
void func_ov113_021eecc8(Field *field);

// Script plugin 15 calls these. Shows the splash at a position given in grid squares, and plays its sound
void func_ov113_021eecd8(GameSystem *gsys, u16 x, u16 y, u16 z);
// Makes an actor jump out of the water and land on a grid square. a4 is not used
GameEvent *func_ov113_021eed38(GameSystem *gsys, u16 actorId, u16 x, u16 z, u16 a4);

#endif // POKEBW2_FIELD_GIMMICK_HUMILAU_H
