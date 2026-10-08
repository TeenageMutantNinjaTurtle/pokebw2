#ifndef POKEBW2_FIELD_GIMMICK_LEAGUE_MARSHAL_H
#define POKEBW2_FIELD_GIMMICK_LEAGUE_MARSHAL_H

#include "types.h"
#include "struct_decls.h"

// The gimmick of Marshal's room in the Pokémon League, zone 142 (overlay 124): its models, and the platform that
// lowers the player with a shake of the camera. The name is a guess: the ROM has no string for it. Its sound uses
// Marshal's Japanese name, SEQ_SE_SW_RENBU_04

// Overlay 36's gimmick table calls these
void func_ov124_021eec80(Field *field);
void func_ov124_021eecc8(Field *field);
void func_ov124_021eece0(Field *field);

// The League's script plugin (overlay 52) calls these
// Plays the two animations of model 0
void func_ov124_021eecf0(GameSystem *gsys);
// Plays one of model 3's two animations, the first when which is 0, and pauses the other
void func_ov124_021eed20(GameSystem *gsys, u16 which);
// Plays the three animations of model 1
void func_ov124_021eed40(GameSystem *gsys);
// The event that lowers the platform with the player on it
GameEvent *func_ov124_021eed6c(GameSystem *gsys);

#endif // POKEBW2_FIELD_GIMMICK_LEAGUE_MARSHAL_H
