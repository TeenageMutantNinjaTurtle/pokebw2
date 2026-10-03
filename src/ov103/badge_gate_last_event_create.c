#include "field/badge_gate.h"
#include "field/field.h"
#include "field/field_camera.h"
#include "gfl/std.h"
#include "system/game_event.h"
#include "system/game_system.h"

GameEvent *BadgeGate_CreateLastGateEvent(GameSystem *gsys) {
    Field *field;
    GameEvent *event;
    BadgeGateLastEventData *data;

    field = GSYS_GetField(gsys);
    event = GameEvent_Create(gsys, NULL, BadgeGate_LastGateEvent, sizeof(BadgeGateLastEventData));
    data = GameEvent_GetData(event);
    GSYS_GetGameData(gsys);
    sys_memset(data, 0, sizeof(BadgeGateLastEventData));
    data->gimmickWork = Field_GetGimmickWorkBlock(field, 0);
    data->camera = Field_GetCameraSystem(field);
    data->field = field;
    data->state = 0;
    FieldCamera_CoordsGetEyeOffset(data->camera, &data->eyeOffset);
    FieldCamera_CoordsGetTargetOffset(data->camera, &data->targetOffset);
    return event;
}