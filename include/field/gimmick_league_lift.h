#ifndef POKEBW2_FIELD_GIMMICK_LEAGUE_LIFT_H
#define POKEBW2_FIELD_GIMMICK_LEAGUE_LIFT_H

#include "types.h"
#include "struct_decls.h"

// The lift gimmick of the Pokémon League, overlay 106. Overlay 36's gimmick table calls these
void func_ov106_021eec80(Field *field);
void func_ov106_021eecac(Field *field);
void func_ov106_021eecc8(Field *field);
// The lift's arrival, which overlay 12's event_league_lift.c runs
void func_ov106_021eecd4(Field *field);
void func_ov106_021eed04(Field *field);
BOOL func_ov106_021eed18(Field *field);
void func_ov106_021eed48(Field *field);
void func_ov106_021eed78(Field *field);
BOOL func_ov106_021eedc8(Field *field);

#endif // POKEBW2_FIELD_GIMMICK_LEAGUE_LIFT_H
