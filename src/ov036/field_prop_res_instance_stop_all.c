#include "field/field_prop.h"
#include "gfl/g3d.h"

void FieldPropResInstance_AnmStopAll(FieldPropResInstance *instance) {
    s32 i;
    u32 stopped;

    i = 0;
    stopped = 0;
    for (; i < 4; i++) {
        if (instance->animationState[i] != 0) {
            GFL_G3DActorUnbindAnm(instance->actor, i);
            instance->animationState[i] = stopped;
        }
    }
}
