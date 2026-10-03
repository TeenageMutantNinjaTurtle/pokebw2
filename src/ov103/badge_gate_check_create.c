#include "field/badge_gate.h"
#include "field/field.h"
#include "gfl/std.h"
#include "system/game_event.h"
#include "system/game_system.h"

GameEvent *BadgeGate_CreateCheckEvent(GameSystem *gsys, u8 badge) {
    Field *field;
    GameEvent *event;
    BadgeGateCheckEventData *data;

    field = GSYS_GetField(gsys);
    event = GameEvent_Create(gsys, NULL, BadgeGate_CheckEvent, sizeof(BadgeGateCheckEventData));
    data = GameEvent_GetData(event);
    GSYS_GetGameData(gsys);
    sys_memset(data, 0, sizeof(BadgeGateCheckEventData));
    data->badge = badge;
    data->state = 0;
    data->gimmickWork = Field_GetGimmickWorkBlock(field, 0);
    return event;
}
