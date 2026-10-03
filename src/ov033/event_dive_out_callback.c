#include "field/event_dive.h"
#include "field/event_mapchange.h"
#include "field/field.h"
#include "field/field_fog.h"
#include "field/field_player.h"
#include "field/field_task.h"
#include "gfl/sound.h"

GameEventReturnCode EventDiveOut_Callback(GameEvent *event, u32 *state, void *eventData) {
    DiveEventData *data = eventData;
    FieldTaskManager *taskManager = Field_GetTaskManager(data->field);
    FieldFog *fog;
    FieldTask *accelTask;
    FieldTask *spinTask;

    switch (*state) {
    case 0:
        GFL_SndSEPlay(0x63c);
        data->timer = 0x18;
        if (data->param != 0) {
            fog = Field_GetFog(data->field);
            accelTask = FieldActorSpinTask_CreatePlayerAccel(data->field, 0x14, 3);
            spinTask = FieldActorSpinTask_CreatePlayer(data->field, 0xc, 3);
            FieldTaskManager_AddTask(taskManager, accelTask, 0);
            FieldTaskManager_AddTask(taskManager, spinTask, (u32)accelTask);
            FieldFog_Animate(fog, 0x7f0f, FieldFog_GetDepthShift(fog), 0x1a);
        }
        (*state)++;
        break;
    case 1:
        FieldPlayer_SetSpecialState(Field_GetPlayer(data->field), 2);
        (*state)++;
        break;
    case 2:
        if (--data->timer > 0) {
            break;
        }
        GameEvent_ChainNext(event, EventMapChangeDiveOut_Create(data->gsys));
        (*state)++;
        break;
    case 3:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}
