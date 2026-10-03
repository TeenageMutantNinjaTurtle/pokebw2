#include "field/el_scoreboard.h"
#include "field/field_exp_obj_gimmick_ov104.h"

void func_ov104_021f00bc(FieldExpObjGimmickOv104State *state, FieldExpObjGimmickOv104Message *message, u32 amount) {
    s32 next;

    if (message->active == 1) {
        ElScoreboard_Update(message->scoreboard);
        GFL_G3DActorStepAnmFrame(message->actor, message->animation, amount);
        message->elapsed += amount;
        if (message->triggerTime < message->elapsed && message->pending != 1) {
            next = (message->index + 1) % state->count;
            state->flags[next] = 1;
            message->pending = 1;
        }
        if (message->duration < message->elapsed) {
            func_ov104_021f0130(message);
        }
    } else if (state->flags[message->index] == 1) {
        func_ov104_021f0094(message);
        state->flags[message->index] = 0;
    }
}
