#include "field/el_scoreboard.h"
#include "field/field_exp_obj_gimmick_ov104.h"
#include "gfl/heap.h"

void func_ov104_021f0080(FieldExpObjGimmickOv104Message *message) {
    ElScoreboard_Free(message->scoreboard);
    GFL_HeapFree(message);
}

void func_ov104_021f0094(FieldExpObjGimmickOv104Message *message) {
    if (message->active != 1) {
        message->active = 1;
        message->pending = 0;
        message->elapsed = 0;
        GFL_G3DActorBindAnm(message->actor, message->animation);
        GFL_G3DActorResetAnmFrame(message->actor, message->animation);
    }
}
