#include "field/event_actor_move.h"
#include "field/field_visuals.h"
#include "gfl/sound.h"
#include "nitro/fx.h"
#include "system/game_event.h"
#include "system/game_system.h"

GameEvent *EventActorJump_Create(GameSystem *gsys, Field *field, const VecFx32 *start, const VecFx32 *end) {
    GameEvent *event = GameEvent_Create(gsys, NULL, EventActorJump_Callback, sizeof(EventActorJumpWork));
    EventActorJumpWork *work = GameEvent_GetData(event);
    work->field = field;
    work->effects = Field_GetFieldEffects(GSYS_GetField(gsys));
    work->start = *start;
    VEC_Subtract(end, start, &work->displacement);
    GFL_SndSEPlay(0x55e);
    return event;
}
