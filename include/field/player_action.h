#ifndef POKEBW2_FIELD_PLAYER_ACTION_H
#define POKEBW2_FIELD_PLAYER_ACTION_H

#include "types.h"
#include "nitro/fx.h"
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

// Overlay 12: whether an actor is a Strength boulder, and whether a boulder at the position stays where it was pushed
BOOL IsNPCStrengthRock(u16 objCode);
BOOL func_ov012_0216820c(MMSys *actorSystem, const VecFx32 *position);

void PlayerActionPerms_Create(PlayerActionPerms *perms, GameSystem *gsys, Field *field);
u8 PlayerActionPerms_IsActionBlocked(PlayerActionPerms *perms, u32 action);
void CalcPlayerActionPossibilities(Field *field, PlayerActionPossibilities *action);

#endif // POKEBW2_FIELD_PLAYER_ACTION_H
