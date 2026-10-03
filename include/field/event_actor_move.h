#ifndef POKEBW2_FIELD_EVENT_ACTOR_MOVE_H
#define POKEBW2_FIELD_EVENT_ACTOR_MOVE_H

// Names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "nitro/fx.h"
#include "struct_decls.h"
#include "system/game_event.h"

struct EventActorJumpWork {
    void *effects;
    Field *field;
    u32 unk8;
    VecFx32 start;
    VecFx32 displacement;
};

GameEventReturnCode EventActorJump_Callback(GameEvent *event, u32 *state, void *data);
GameEvent *EventActorJump_Create(GameSystem *gsys, Field *field, const VecFx32 *start, const VecFx32 *end);

#endif // POKEBW2_FIELD_EVENT_ACTOR_MOVE_H
