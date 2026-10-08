#ifndef POKEBW2_FIELD_GIMMICK_UNDERGROUND_RUINS_H
#define POKEBW2_FIELD_GIMMICK_UNDERGROUND_RUINS_H

#include "types.h"
#include "struct_decls.h"

// The gimmick of the Underground Ruins (zone 565), overlay 114. Overlay 36's gimmick table calls the first three, and
// script plugin 16 (overlay 68) the others. The file's name is a guess

void func_ov114_021eec80(Field *field);
void func_ov114_021eecb0(Field *field);
void func_ov114_021eecc8(Field *field);
// Shows model a1 + 1 of the four that follow the first, hiding the others
void func_ov114_021eecd8(GameSystem *gsys, u8 a1);
// Puts the first model's animation at its end when a1 is 1, else at its start
void func_ov114_021eed34(GameSystem *gsys, u16 a1);
// Plays the first model's animation forward when a1 is 1, else backward
void func_ov114_021eeda0(GameSystem *gsys, u16 a1);

#endif // POKEBW2_FIELD_GIMMICK_UNDERGROUND_RUINS_H
