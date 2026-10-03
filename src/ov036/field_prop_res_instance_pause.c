#include "field/field_prop.h"

void FieldPropResInstance_AnmSetPause(FieldPropResInstance *instance, u32 animation) {
    FieldPropResAnmHeader *header;
    s32 count;
    s32 i;
    u32 offset;
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
        if (stateBase->animationState[i] != 0) {
            stateBase->animationState[i] = 2;
        }
        i++;
    } while (i < header->ambientAnimationCount);
}
