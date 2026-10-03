#include "field/field_prop.h"
#include "gfl/g3d.h"

void FieldPropAnmController_Ambient_Init(FieldPropSystem *system, FieldPropResInstance *instance) {
    FieldPropResAnmHeader *header;
    u32 count;
    s32 i;
    u32 playing;

    header = FieldPropResInfo_GetAnmHeader(*instance->resInfoRef);
    count = header->ambientAnimationCount;
    i = 0;
    playing = 1;
    for (; i < 4 && (u32)i < count; i++) {
        GFL_G3DActorBindAnm(instance->actor, i);
        GFL_G3DActorResetAnmFrame(instance->actor, i);
        instance->animationState[i] = playing;
    }
    for (; i < 4; i++) {
        instance->animationState[i] = 0;
    }
}
