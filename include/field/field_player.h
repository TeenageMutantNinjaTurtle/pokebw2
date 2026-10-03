#ifndef POKEBW2_FIELD_FIELD_PLAYER_H
#define POKEBW2_FIELD_FIELD_PLAYER_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "nitro/fx.h"
#include "struct_decls.h"

BOOL Field_HasPlayer(Field *field);
BOOL Field_ToggleCycling(Field *field);
void FieldPlayer_GetWPosInDir(FieldPlayer *player, u32 direction, VecFx32 *position);
u32 FieldPlayer_GetExState(FieldPlayer *player);
u32 FieldPlayer_DeriveExState(FieldPlayer *player);
void FieldPlayer_SetSpecialState(FieldPlayer *player, u32 state);
void FieldPlayer_SetSpecialSeq(FieldPlayer *player, u32 seq);
BOOL func_ov036_0219a580(FieldPlayer *player);
u32 FieldPlayer_GetTileTypeUnder(FieldPlayer *player);

#endif // POKEBW2_FIELD_FIELD_PLAYER_H
