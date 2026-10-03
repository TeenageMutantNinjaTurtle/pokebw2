#include "field/app_call.h"
#include "field/player_action.h"
#include "gfl/std.h"
#include "system/game_event.h"

GameEvent *EventFieldAppCall_Create(FieldAppCallInput *input, u16 code) {
    GameEvent *event = GameEvent_Create(input->gameSystem, input->parent, EventFieldAppCall_Callback, sizeof(FieldAppCallWork));
    FieldAppCallWork *work = GameEvent_GetData(event);

    sys_memset(work, 0, sizeof(FieldAppCallWork));
    work->code = code;
    work->input = input;
    work->unk10 = 4;
    work->event = event;
    work->callback04 = input->context;
    work->callback08 = input->context;
    work->callback0C = input->context;
    work->flag68 = 0;
    work->value6A = 0;
    work->unk70 = 0;
    func_ov012_0215b76c(&work->params, work->input, work->input->canRetry, work->input->callback1,
                          work->input->callback2, work->input->arg);
    PlayerActionPerms_Create(&work->perms, work->input->gameSystem, work->input->field);
    CalcPlayerActionPossibilities(work->input->field, &work->action);
    return event;
}
