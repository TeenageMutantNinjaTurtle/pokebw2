#include "field/field_prop.h"
#include "gfl/g3d.h"

void FieldPropAnmController_RTC_Update(FieldPropSystem *system, FieldPropResInstance *instance) {
    u32 animation;

    animation = FieldPropRTCState_GetPlayAnmIndex(&system->rtcState);
    if (FieldPropRTCState_HasDayPartChanged(&system->rtcState)) {
        FieldPropResInstance_AnmStopAll(instance);
        GFL_G3DActorBindAnm(instance->actor, animation);
        GFL_G3DActorResetAnmFrame(instance->actor, animation);
        instance->animationState[animation] = 1;
    } else {
        GFL_G3DActorStepAnmFrameLoop(instance->actor, animation, FX32_ONE);
    }
}
