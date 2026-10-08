#ifndef POKEBW2_FIELD_GIMMICK_LEAGUE_CENTER_H
#define POKEBW2_FIELD_GIMMICK_LEAGUE_CENTER_H

#include "types.h"
#include "struct_decls.h"

// The gimmick of the Pokémon League's central room once the Elite Four are beaten, zone 139 (overlay 115). The name
// is a guess: the ROM has no string for it. Overlay 36's gimmick table calls these
void func_ov115_021eec80(Field *field);
void func_ov115_021eecc8(Field *field);
void func_ov115_021eece8(Field *field);
// Starts the model's three animations, which script plugin 14 (overlay 66) runs
void func_ov115_021eed08(GameSystem *gsys);

#endif // POKEBW2_FIELD_GIMMICK_LEAGUE_CENTER_H
