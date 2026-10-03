#include "field/field_prop.h"
#include "gfl/g3d.h"

void FieldPropResInstance_AnmSetPlayInv(FieldPropResInstance *instance, u32 animation) {
    FieldPropResAnmHeader *header;
    s32 count;
    s32 i;
    u32 offset;
    u32 index;
    FieldPropResInstance *stateBase;
    void *animationObj;
    void *renderObj;
    fx32 frame;

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
        animationObj = GFL_G3DActorGetAnm(instance->actor, index);
        renderObj = GFL_G3DAnmGetRenderObj(animationObj);
        frame = *(u16 *)((u8 *)*(void **)((u8 *)renderObj + 8) + 4) << 12;
        GFL_G3DActorSetAnmFrame(instance->actor, index, &frame);
        stateBase->animationState[i] = 4;
        i++;
    } while (i < header->ambientAnimationCount);
}
