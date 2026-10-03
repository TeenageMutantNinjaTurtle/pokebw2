#ifndef POKEBW2_FIELD_PLAYER_ACTION_H
#define POKEBW2_FIELD_PLAYER_ACTION_H

#include "types.h"
#include "struct_decls.h"

struct PlayerActionPerms {
    u8 data[0x20];
};

struct PlayerActionPossibilities {
    u8 data[0x14];
};

void PlayerActionPerms_Create(PlayerActionPerms *perms, GameSystem *gsys, Field *field);
void CalcPlayerActionPossibilities(Field *field, PlayerActionPossibilities *action);

#endif // POKEBW2_FIELD_PLAYER_ACTION_H
