#include "field/event_dive.h"
#include "field/event_mapchange.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "field/field_map.h"
#include "field/field_player.h"
#include "field/field_task.h"
#include "gfl/sound.h"

GameEventReturnCode EventDiveIn_Callback(GameEvent *event, u32 *state, void *eventData) {
    DiveEventData *data = eventData;
    FieldTaskManager *taskManager;
    FieldTask *task;
    FieldPlayer *player;
    VecFx32 offset;
    u16 zoneId;

    switch (*state) {
    case 0:
        taskManager = Field_GetTaskManager(data->field);
        offset.x = 0;
        offset.y = -0x40000;
        offset.z = 0;
        task = FieldActorMoveTask_CreatePlayer(data->field, 0x28, &offset);
        FieldTaskManager_AddTask(taskManager, task, 0);
        data->timer = 8;
        (*state)++;
        break;
    case 1:
        if (--data->timer > 0) {
            break;
        }
        GFL_SndSEPlay(0x63c);
        (*state)++;
        break;
    case 2:
        if (GFL_SndPlayerIsActive(GFL_SndSeqGetPlayerIndex(0x63c))) {
            break;
        }
        player = Field_GetPlayer(data->field);
        FieldPlayer_GetActor(player);
        FieldPlayer_SetSpecialState(player, 3);
        GetAbyssalRuinsDiveZoneID(data->field, &zoneId);
        GameEvent_ChainNext(event, EventMapChangeDiveIn_Create(data->gsys, zoneId));
        (*state)++;
        break;
    case 3:
        FldAct_SetAcmd(FieldPlayer_GetActor(Field_GetPlayer(data->field)), 8);
        (*state)++;
        break;
    case 4:
        if (func_ov012_02166ecc(FieldPlayer_GetActor(Field_GetPlayer(data->field)))) {
            return GAMEEVENT_DONE;
        }
        break;
    }
    return GAMEEVENT_CONTINUE;
}
