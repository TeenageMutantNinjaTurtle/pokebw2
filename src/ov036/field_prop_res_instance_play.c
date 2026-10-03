#include "field/field_prop.h"
#include "gfl/g3d.h"

void FieldPropResInstance_AnmSetPlay(FieldPropResInstance *instance, u32 animation) {
    FieldPropResAnmHeader *header;
    s32 count;
    s32 i;
    u32 offset;
    u32 index;
    FieldPropResInstance *stateBase;

    header = FieldPropResInfo_GetAnmHeader(*instance->resInfoRef);
    count = header->ambientAnimationCount;
    offset = count * animation;
    i = 0;
    if (count <= 0) {
        return;
    }
    stateBase = (FieldPropResInstance *)((u8 *)instance + offset * 4);
    do {
        index = offset + i;
        GFL_G3DActorBindAnm(instance->actor, index);
        GFL_G3DActorResetAnmFrame(instance->actor, index);
        stateBase->animationState[i] = 3;
        i++;
    } while (i < header->ambientAnimationCount);
}
