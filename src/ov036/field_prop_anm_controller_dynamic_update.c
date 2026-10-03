#include "field/field_prop.h"
#include "gfl/g3d.h"

void FieldPropAnmController_Dynamic_Update(FieldPropSystem *system, FieldPropResInstance *instance) {
    fx32 step;
    s32 i;

    step = FX32_ONE;
    i = 0;
    for (; i < 4; i++) {
        switch (instance->animationState[i]) {
        case 0:
        case 2:
            break;
        case 3:
            if (!GFL_G3DActorStepAnmFrame(instance->actor, i, step)) {
                instance->animationState[i] = 2;
            }
            break;
        case 4:
            if (!GFL_G3DActorStepAnmFrame(instance->actor, i, -step)) {
                GFL_G3DActorSetAnmFrame(instance->actor, i, 0);
                instance->animationState[i] = 2;
            }
            break;
        case 1:
            GFL_G3DActorStepAnmFrameLoop(instance->actor, i, step);
            break;
        }
    }
}
