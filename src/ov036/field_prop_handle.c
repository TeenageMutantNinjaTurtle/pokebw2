#include "field/field_prop.h"
#include "gfl/g3d.h"
#include "gfl/heap.h"
#include "gfl/sound.h"

FieldPropHandle *FieldPropSystem_CreateHandleAtPos(FieldPropSystem *system, u32 propId, const VecFx32 *position) {
    FieldChunkPropHolder *holder;

    holder = FieldPropSystem_FindPropAtPos(system, propId, position);
    if (holder == NULL) {
        return NULL;
    }
    return FieldPropSystem_CreateHandleFromExisting(system, holder);
}

FieldPropHandle *FieldPropSystem_CreateHandleNew(FieldPropSystem *system, u32 propId, FieldPropTransform *transform) {
    FieldPropHandle *handle;
    u32 index;

    handle = GFL_HeapAllocate(system->heapId, sizeof(FieldPropHandle), FALSE, data_ov036_021d4b2c, 0x812);
    handle->system = system;
    handle->holder = NULL;
    handle->animation = 0xffff;
    handle->transform = *transform;
    index = FieldPropSystem_ConvResIDToIndex(system, propId);
    FieldPropResInstance_Init(system, &handle->instance, (u8 *)system->resInfoArray + 0x18 * index);
    FieldPropSystem_RegistHandle(system, handle);
    return handle;
}

void FieldPropHandle_Free(FieldPropHandle *handle) {
    if (handle != NULL) {
        FieldPropSystem_DeleteHandle(handle->system, handle);
        FieldPropResInstance_Free(&handle->instance);
        if (handle->holder != NULL) {
            FieldChunkPropHolder_SetVisible(handle->holder, TRUE);
        }
        GFL_HeapFree(handle);
    }
}

void FieldPropHandle_CallAnmCmd(FieldPropHandle *handle, u32 animation, u32 command) {
    if (handle != NULL) {
        handle->animation = animation;
        FieldPropResInstance_CallAnmCmd(&handle->instance, animation, command);
    }
}

void FieldPropHandle_CallAnmCmdSilent(FieldPropHandle *handle, u32 command) {
    if (handle != NULL) {
        FieldPropResInstance_CallAnmCmd(&handle->instance, handle->animation, command);
    }
}

BOOL FieldPropHandle_IsAnmFinished(FieldPropHandle *handle) {
    if (handle == NULL) {
        return TRUE;
    }
    if (FieldPropHandle_IsCurrentAnmIdle(handle) == TRUE) {
        FieldPropHandle_CallAnmCmdSilent(handle, 3);
        return TRUE;
    }
    return FALSE;
}

BOOL FieldPropHandle_IsAnmIdle(FieldPropHandle *handle, u32 animation) {
    if (handle == NULL) {
        return FALSE;
    }
    return FieldPropResInstance_IsAnmIdle(&handle->instance, animation);
}

BOOL FieldPropHandle_IsCurrentAnmIdle(FieldPropHandle *handle) {
    if (handle == NULL) {
        return FALSE;
    }
    return FieldPropResInstance_IsAnmIdle(&handle->instance, handle->animation);
}

u16 FieldPropHandle_GetPropType(FieldPropHandle *handle) {
    if (handle == NULL) {
        return 0;
    }
    return (*handle->instance.resInfoRef)->type;
}

void FieldPropHandle_Draw(FieldPropHandle *handle) {
    if (handle != NULL) {
        GFL_G3DSysDrawObjBBoxCull(handle->instance.drawObject, (SRTMatrix *)&handle->transform);
    }
}

BOOL FieldPropHandle_GetAnimSoundIDCore(FieldPropHandle *handle, u32 animation, u16 *soundId) {
    u32 type;
    u32 i;

    if (handle == NULL) {
        return FALSE;
    }
    type = FieldPropHandle_GetPropType(handle);
    *soundId = 0;
    if (animation >= 4) {
        return FALSE;
    }
    for (i = 0; i < 6; i++) {
        if (type == DOOR_SOUND_ID_LUT[i][0]) {
            *soundId = *(const u16 *)(data_ov036_021ca8e6 + i * 10 + animation * 2);
            return TRUE;
        }
    }
    return FALSE;
}

BOOL FieldPropHandle_GetAnimSoundID(FieldPropHandle *handle, u16 *soundId) {
    if (handle == NULL) {
        return FALSE;
    }
    return FieldPropHandle_GetAnimSoundIDCore(handle, handle->animation, soundId);
}

BOOL FieldPropHandle_IsAnimSoundFinished(FieldPropHandle *handle) {
    u16 soundId;

    if (FieldPropHandle_GetAnimSoundID(handle, &soundId) == FALSE) {
        return FALSE;
    }
    return GFL_SndPlayerIsActive(GFL_SndSeqGetPlayerIndex(soundId));
}
