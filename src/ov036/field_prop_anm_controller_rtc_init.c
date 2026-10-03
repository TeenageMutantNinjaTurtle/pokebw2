#include "field/field_prop.h"
#include "gfl/g3d.h"

void FieldPropAnmController_RTC_Init(FieldPropSystem *system, FieldPropResInstance *instance) {
    u32 animation;
    s32 i;
    u32 stopped;

    FieldPropResInfo_GetAnmHeader(*instance->resInfoRef);
    animation = FieldPropRTCState_GetPlayAnmIndex(&system->rtcState);
    i = 0;
    stopped = 0;
    for (; i < 4; i++) {
        if (i != animation) {
            instance->animationState[i] = stopped;
        } else {
            GFL_G3DActorBindAnm(instance->actor, i);
            GFL_G3DActorResetAnmFrame(instance->actor, i);
            instance->animationState[i] = 1;
        }
    }
}
