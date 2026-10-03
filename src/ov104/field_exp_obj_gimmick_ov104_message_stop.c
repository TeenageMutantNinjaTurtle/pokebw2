#include "field/field_exp_obj_gimmick_ov104.h"

void func_ov104_021f0130(FieldExpObjGimmickOv104Message *message) {
    if (message->active == 1) {
        message->active = 0;
        GFL_G3DActorUnbindAnm(message->actor, message->animation);
        GFL_G3DActorResetAnmFrame(message->actor, message->animation);
    }
}
