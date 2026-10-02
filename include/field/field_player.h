#ifndef POKEBW2_FIELD_FIELD_PLAYER_H
#define POKEBW2_FIELD_FIELD_PLAYER_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"

BOOL Field_HasPlayer(Field *field);
BOOL Field_ToggleCycling(Field *field);
u32 FieldPlayer_GetExState(FieldPlayer *player);
void FieldPlayer_SetSpecialSeq(FieldPlayer *player, u32 seq);
void func_ov036_0219a580(FieldPlayer *player);

#endif // POKEBW2_FIELD_FIELD_PLAYER_H
