#include "field/field_prop.h"
#include "gfl/g3d.h"

void FieldPropAnmController_Static_Init(FieldPropSystem *system, FieldPropResInstance *instance) {
    s32 i;
    u32 state;

    i = 0;
    state = 0;
    for (; i < 4; i++) {
        instance->animationState[i] = state;
    }
}

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

void FieldPropResInstance_Free(void *argument) {
    FieldPropResInstance *instance;
    G3DModel *model;
    void *animation;
    s32 count;
    s32 i;

    instance = argument;
    if (instance->actor != NULL) {
        count = GFL_G3DActorGetAnmCount(instance->actor);
        for (i = 0; i < count; i++) {
            animation = GFL_G3DActorGetAnm(instance->actor, i);
            if (animation != NULL) {
                GFL_G3DAnmFree(animation);
            }
        }
        model = GFL_G3DActorGetMdl(instance->actor);
        GFL_G3DActorFree(instance->actor);
        instance->actor = NULL;
        instance->resInfoRef = NULL;
        GFL_G3DMdlFree(model);
    }
}

void FieldPropSystem_UpdateResInstance(FieldPropSystem *system, void *argument) {
    FieldPropResInstance *instance;
    FieldPropResAnmHeader *header;
    u32 type;

    instance = argument;
    header = FieldPropResInfo_GetAnmHeader(*instance->resInfoRef);
    type = header->controllerType;
    if (instance->actor != NULL) {
        data_ov036_021ca8b8[type].update(system, instance);
    }
}

void FieldPropAnmController_Static_Update(void *controller) {
}

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

void FieldPropAnmController_Ambient_Update(void *controller, void *instance) {
    s32 i;

    for (i = 0; i < 4; i++) {
        GFL_G3DActorStepAnmFrameLoop(*(G3DActor **)instance, i, FX32_ONE);
    }
}

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

void FieldPropResInstance_AnmSetPlayLoop(FieldPropResInstance *instance, u32 animation) {
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
        stateBase->animationState[i] = 1;
        i++;
    } while (i < header->ambientAnimationCount);
}

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

void FieldPropResInstance_CallAnmCmd(void *argument, u32 animation, u32 command) {
    FieldPropResInstance *instance;
    FieldPropResAnmHeader *header;
    u8 index;
    u32 type;

    instance = argument;
    header = FieldPropResInfo_GetAnmHeader(*instance->resInfoRef);
    type = header->controllerType;
    index = animation;
    if (index >= 4) {
        index = 0;
    }
    data_ov036_021ca8bc[type].command(instance, index, command);
}

void FieldPropAnmController_Dynamic_ExecCommand(FieldPropResInstance *instance, u32 animation, u32 command) {
    switch (command) {
    case 0:
        FieldPropResInstance_AnmStopAll(instance);
        FieldPropResInstance_AnmSetPlay(instance, animation);
        break;
    case 1:
        FieldPropResInstance_AnmStopAll(instance);
        FieldPropResInstance_AnmSetPlayInv(instance, animation);
        break;
    case 2:
        FieldPropResInstance_AnmStopAll(instance);
        FieldPropResInstance_AnmSetPlayLoop(instance, animation);
        break;
    case 3:
        FieldPropResInstance_AnmSetPause(instance, animation);
        break;
    case 4:
        FieldPropResInstance_AnmStopAll(instance);
        break;
    }
}

void FieldPropAnmController_Static_ExecCommand(void *controller, u32 command) {
}

BOOL FieldPropResInstance_IsAnmIdle(void *argument, u32 animation) {
    FieldPropResInstance *instance;
    u8 index;

    instance = argument;
    index = animation;
    if (index >= 4) {
        index = 0;
    }
    switch (instance->animationState[index]) {
    case 0:
        return TRUE;
    case 1:
        return FALSE;
    case 2:
        return TRUE;
    case 3:
    case 4:
        return FALSE;
    default:
        break;
    }
    return FALSE;
}
