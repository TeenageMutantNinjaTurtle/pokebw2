#ifndef POKEBW2_FIELD_PLAYER_ACTION_H
#define POKEBW2_FIELD_PLAYER_ACTION_H

#include "types.h"
#include "struct_decls.h"

struct PlayerActionPerms {
    u8 data[0x20];
};

// What the player can do where they stand, which the hidden moves check
struct PlayerActionPossibilities {
    u16 zoneId;
    u16 flags;
    u32 exState;
    GameSystem *gsys;
    FieldActor *actorInFront;
    Field *field;
};

void PlayerActionPerms_Create(PlayerActionPerms *perms, GameSystem *gsys, Field *field);
void CalcPlayerActionPossibilities(Field *field, PlayerActionPossibilities *action);

#endif // POKEBW2_FIELD_PLAYER_ACTION_H
