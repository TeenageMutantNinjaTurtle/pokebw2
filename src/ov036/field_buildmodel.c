#include "types.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/sound.h"
#include "constants/species.h"
#include "field/day_care.h"
#include "field/encounter_effect.h"
#include "field/festival.h"
#include "field/field.h"
#include "field/field_3d_ci.h"
#include "field/field_actor.h"
#include "field/field_async_proc.h"
#include "field/field_controller.h"
#include "field/field_display_control.h"
#include "field/field_effects.h"
#include "field/field_environment.h"
#include "field/field_exp_obj.h"
#include "field/field_internal.h"
#include "field/field_lens_flare.h"
#include "field/field_lifecycle.h"
#include "field/field_map.h"
#include "field/field_palace.h"
#include "field/field_player.h"
#include "field/field_pokemon_form.h"
#include "field/field_prop.h"
#include "field/field_render.h"
#include "field/field_script.h"
#include "field/field_state.h"
#include "field/field_visuals.h"
#include "field/hidden_hollow.h"
#include "field/medal.h"
#include "field/skill_map_effect.h"
#include "field/unity_tower.h"
#include "field/zone.h"
#include "field/zone_data.h"
#include "gfl/arc.h"
#include "gfl/g3d.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/sound.h"
#include "gfl/std.h"
#include "nitro/fx.h"
#include "nitro/hw.h"
#include "pml/poke_party.h"
#include "save/event_work.h"
#include "save/medal_box.h"
#include "save/records.h"
#include "save/save_control.h"
#include "system/aeabi.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/rtc.h"
#include "system/vm.h"

struct FieldPropDoorResInfo {
    u8 pad[4];
    u16 id;
    s16 x;
    s16 y;
    s16 z;
};

struct FieldPropSourceInfo {
    s32 x;
    s32 y;
    s32 z;
    u16 unkC;
    u8 highResId;
    u8 lowResId;
};

void FieldPropSystem_Free(FieldPropSystem *system) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (system->handles[i] != NULL) {
            FieldPropHandle_Free(system->handles[i]);
        }
    }
    FieldPropSystem_FreeResInstances(system, system->unk220);
    FieldPropSystem_FreeResources(system);
    FieldPropSystem_FreeResBundle(system);
    FieldPropSystem_FreeTextures(system);
    GFL_HeapFree(system);
}

void FieldPropSystem_Update(FieldPropSystem *system) {
    s32 i;
    u32 j;

    FieldPropRTCState_Update(&system->rtcState);
    for (i = 0; i < 7; i++) {
        if (system->handles[i] != NULL) {
            FieldPropSystem_UpdateResInstance(system, &system->handles[i]->instance);
        }
    }
    for (j = 0; j < system->resInstanceCount; j++) {
        FieldPropSystem_UpdateResInstance(system, &system->resInstances[j]);
    }
}

void FieldPropSystem_DrawAllHandles(FieldPropSystem *system) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (system->handles[i] != NULL) {
            FieldPropHandle_Draw(system->handles[i]);
        }
    }
}

void *FieldPropSystem_FindResInfo(FieldPropSystem *system, u32 resId) {
    u32 index = FieldPropSystem_ConvResIDToIndex(system, resId);
    return FieldPropResBundle_GetResInfo(system->resBundle, index);
}

void *FieldPropSystem_GetResInfo(FieldPropSystem *system, u32 index) {
    return FieldPropResBundle_GetResInfo(system->resBundle, index);
}

BOOL FieldPropSystem_CheckCreateDoorReq(FieldPropSystem *system, u32 resId, VecFx32 *position, u32 *resIndex) {
    struct FieldPropDoorResInfo *info;
    s32 x;
    s32 y;
    s32 z;

    info = FieldPropSystem_FindResInfo(system, resId);
    if (info->id == 0xffff) {
        return FALSE;
    }
    *resIndex = FieldPropSystem_ConvResIDToIndex(system, info->id);
    x = info->x << 12;
    z = info->z << 12;
    y = info->y << 12;
    position->x = x;
    position->y = y;
    position->z = z;
    return TRUE;
}

s32 FieldPropSystem_InstantiateProps(FieldPropSystem *system, FieldChunk *chunk, const FieldPropSourceInfo *infos,
                                     s32 count) {
    FieldPropInstance instance;
    s32 i;
    s32 n;
    u16 resId;

    i = 0;
    n = 0;
    while (i < count) {
        FieldPropSystem_InstantiateFromInfo(system, chunk, &infos[i], n);
        resId = infos[i].lowResId + (infos[i].highResId << 8);
        if (FieldPropSystem_CheckCreateDoorReq(system, resId, &instance.pos.position, &instance.resIndex) == TRUE) {
            instance.pos.rotationY = infos[i].unkC;
            n++;
            instance.pos.position.x += infos[i].x;
            instance.pos.position.y += infos[i].y;
            instance.pos.position.z -= infos[i].z;
            FieldPropSystem_LinkPropToChunk(system, chunk, &instance, n);
        }
        n++;
        i++;
    }
    return n;
}

void FieldPropSystem_UnlinkChunk(FieldPropSystem *system, FieldChunk *chunk) {
    FieldPropSystem_ReleaseChunkPropHolders(system, chunk);
}

void FieldPropSystem_InstantiateFromInfo(FieldPropSystem *system, FieldChunk *chunk, const struct FieldPropSourceInfo *info,
                                         u32 propIndex) {
    FieldPropInstance instance;
    u16 resId;
    s32 x, y, z;

    resId = info->lowResId + (info->highResId << 8);
    instance.resIndex = FieldPropSystem_ConvResIDToIndex(system, resId);
    x = info->x;
    z = -info->z;
    y = info->y;
    instance.pos.position.x = x;
    instance.pos.position.y = y;
    instance.pos.position.z = z;
    instance.pos.rotationY = info->unkC;
    FieldPropSystem_LinkPropToChunk(system, chunk, &instance, propIndex);
}

void FieldPropSystem_DeleteHandle(FieldPropSystem *system, FieldPropHandle *handle) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (system->handles[i] == handle) {
            system->handles[i] = NULL;
            return;
        }
    }
}

void FieldPropSystem_RegistHandle(FieldPropSystem *system, FieldPropHandle *handle) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (system->handles[i] == NULL) {
            system->handles[i] = handle;
            return;
        }
    }
}

FieldPropHandle *FieldPropSystem_FindHandleByID(FieldPropSystem *system, u32 id) {
    u16 index;
    u16 marker;

    index = id & 0xffff000f;
    marker = id & 0xfff0;
    if (marker != 0xfff0) {
        return NULL;
    }
    if (index >= 7) {
        return NULL;
    }
    return system->handles[index];
}

u16 FieldPropSystem_GetHandleID(FieldPropSystem *system, FieldPropHandle *handle) {
    s32 i;

    if (handle == NULL) {
        return 0;
    }
    for (i = 0; i < 7; i++) {
        if (system->handles[i] == handle) {
            return 0xfff0 | i;
        }
    }
    return 0;
}

void *FieldPropSystem_GetResBank(FieldPropSystem *system) {
    return system->unk220;
}

void FieldPropSystem_LoadResBundle(FieldPropSystem *system, u32 arcId, u32 fileId) {
    ArcTool *arc;
    u32 count;

    arc = GFL_ArcSysCreateFileHandle(arcId, HEAPID_TAIL(system->heapId));
    if (GFL_ArcToolGetDataMax(arc) <= fileId) {
        fileId = 0;
    }
    system->resBundle = GFL_ArcToolReadHeapNew(arc, fileId, system->heapId);
    count = (u32)system->resBundle->countFlags >> 1;
    system->resInfoCount = count;
    if (count > 0x200) {
        system->resInfoCount = 0x80;
    }
    GFL_ArcToolFree(arc);
}

void FieldPropSystem_FreeResBundle(FieldPropSystem *system) {
    GFL_HeapFree(system->resBundle);
    system->resInfoCount = 0;
}

void FieldPropSystem_BuildResIDLUT(FieldPropSystem *system, u32 defaultResId) {
    u8 i;
    u8 defaultIndex;
    s32 j;
    FieldPropResInfo *info;

    sys_memset(system->resIdToIndex, 0x80, 0x200);
    for (i = 0; i < system->resInfoCount; i++) {
        info = FieldPropSystem_GetResInfo(system, i);
        system->resIdToIndex[info->resId] = i;
    }
    defaultIndex = system->resIdToIndex[defaultResId];
    for (j = 0; j < 0x200; j++) {
        if (system->resIdToIndex[j] == 0x80) {
            system->resIdToIndex[j] = defaultIndex;
        }
    }
}

u32 FieldPropSystem_ConvResIDToIndex(const FieldPropSystem *system, u32 resId) {
    u8 index;

    if (resId >= 0x200) {
        resId = 0;
    }
    index = ((const u8 *)system + resId)[0x1c];
    if (index >= 0x80 || index >= system->resInfoCount) {
        index = 0;
    }
    return index;
}

void *FieldPropResBundle_GetResInfo(FieldPropResBundle *bundle, u32 index) {
    return (u8 *)bundle + bundle->offsets[index];
}

void *FieldPropResBundle_GetModelData(FieldPropResBundle *bundle, u32 index) {
    u32 count;

    count = (u32)bundle->countFlags >> 1;
    return (u8 *)bundle + bundle->offsets[count + index];
}

void *FieldPropResAnmHeader_GetAnmData(FieldPropResAnmHeader *header, u32 index) {
    return (u8 *)header + header->animationIds[index];
}

void FieldPropSystem_FreeTextures(FieldPropSystem *system) {
    if (system->textureResource != NULL) {
        GFL_G3DResFreeTexData(system->textureResource);
        GFL_G3DResFree(system->textureResource);
        system->textureResource = NULL;
    }
}

u32 FieldPropResAnmHeader_GetAnmCount(const FieldPropResAnmHeader *header) {
    u32 i = 0;
    u32 count = 0;

    for (; i < 4; i++) {
        if (header->animationIds[i] != 0xffffffff) {
            count++;
        }
    }
    return count;
}

FieldPropResAnmHeader *FieldPropResInfo_GetAnmHeader(FieldPropResInfo *resInfo) {
    return &resInfo->animationHeader;
}

u8 FieldPropResInfo_GetTypeConv(const FieldPropResInfo *resInfo) {
    const u8 lut[16] = { 0, 1, 1, 1, 2, 0, 3, 4, 5, 6, 7, 8, 9, 1, 1, 1 };
    u16 type = resInfo->type;

    if (type >= 16) {
        return 0;
    }
    return lut[type];
}

void FieldPropRTCState_Init(FieldPropRTCState *state, u8 season) {
    state->dayPeriod = 5;
    state->season = season;
    FieldPropRTCState_Update(state);
}

void FieldPropRTCState_Update(FieldPropRTCState *state) {
    state->previousDayPeriod = state->dayPeriod;
    state->dayPeriod = GetRealTimeDayPeriod(state->season);
    state->dayPartChanged = state->dayPeriod != state->previousDayPeriod;
    state->playAnmIndex = FIELD_PROP_ANM_IDX_FOR_DAY_PART[state->dayPeriod];
}

BOOL FieldPropRTCState_HasDayPartChanged(FieldPropRTCState *state) {
    return state->dayPartChanged;
}

u8 FieldPropRTCState_GetPlayAnmIndex(FieldPropRTCState *state) {
    return state->playAnmIndex;
}

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

    header = FieldPropResInfo_GetAnmHeader(instance->resource->info);
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

    FieldPropResInfo_GetAnmHeader(instance->resource->info);
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
        instance->resource = NULL;
        GFL_G3DMdlFree(model);
    }
}

void FieldPropSystem_UpdateResInstance(FieldPropSystem *system, FieldPropResInstance *instance) {
    FieldPropResAnmHeader *header;
    u32 type;

    header = FieldPropResInfo_GetAnmHeader(instance->resource->info);
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

    header = FieldPropResInfo_GetAnmHeader(instance->resource->info);
    count = header->ambientAnimationCount;
    offset = count * animation;
    i = 0;
    if (count <= 0) {
        return;
    }
    do {
        index = offset + i;
        GFL_G3DActorBindAnm(instance->actor, index);
        GFL_G3DActorResetAnmFrame(instance->actor, index);
        instance->animationState[offset + i] = 3;
        i++;
    } while (i < header->ambientAnimationCount);
}

void FieldPropResInstance_AnmSetPlayLoop(FieldPropResInstance *instance, u32 animation) {
    FieldPropResAnmHeader *header;
    s32 count;
    s32 i;
    u32 offset;
    u32 index;

    header = FieldPropResInfo_GetAnmHeader(instance->resource->info);
    count = header->ambientAnimationCount;
    offset = count * animation;
    i = 0;
    if (count <= 0) {
        return;
    }
    do {
        index = offset + i;
        GFL_G3DActorBindAnm(instance->actor, index);
        GFL_G3DActorResetAnmFrame(instance->actor, index);
        instance->animationState[offset + i] = 1;
        i++;
    } while (i < header->ambientAnimationCount);
}

void FieldPropResInstance_AnmSetPlayInv(FieldPropResInstance *instance, u32 animation) {
    FieldPropResAnmHeader *header;
    s32 count;
    s32 i;
    u32 offset;
    u32 index;
    void *animationObj;
    NNSG3dAnmObj *renderObj;
    fx32 frame;

    header = FieldPropResInfo_GetAnmHeader(instance->resource->info);
    count = header->ambientAnimationCount;
    offset = count * animation;
    i = 0;
    if (count <= 0) {
        return;
    }
    do {
        index = offset + i;
        GFL_G3DActorBindAnm(instance->actor, index);
        animationObj = GFL_G3DActorGetAnm(instance->actor, index);
        renderObj = GFL_G3DAnmGetRenderObj(animationObj);
        frame = renderObj->resAnm->numFrame << 12;
        GFL_G3DActorSetAnmFrame(instance->actor, index, &frame);
        instance->animationState[offset + i] = 4;
        i++;
    } while (i < header->ambientAnimationCount);
}

void FieldPropResInstance_AnmSetPause(FieldPropResInstance *instance, u32 animation) {
    FieldPropResAnmHeader *header;
    s32 count;
    s32 i;
    u32 offset;

    header = FieldPropResInfo_GetAnmHeader(instance->resource->info);
    count = header->ambientAnimationCount;
    offset = count * animation;
    i = 0;
    if (count <= 0) {
        return;
    }
    do {
        if (instance->animationState[offset + i] != 0) {
            instance->animationState[offset + i] = 2;
        }
        i++;
    } while (i < header->ambientAnimationCount);
}

void FieldPropResInstance_AnmStopAll(FieldPropResInstance *instance) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (instance->animationState[i] != 0) {
            GFL_G3DActorUnbindAnm(instance->actor, i);
            instance->animationState[i] = 0;
        }
    }
}

void FieldPropResInstance_CallAnmCmd(FieldPropResInstance *instance, u32 animation, u32 command) {
    FieldPropResAnmHeader *header;
    u8 index;
    u32 type;

    header = FieldPropResInfo_GetAnmHeader(instance->resource->info);
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

void FieldChunkPropHolder_Release(FieldPropSystem *system, FieldChunkPropHolder *holder) {
    holder->chunk = NULL;
    holder->savedResIndex = 0xffffffff;
    holder->propIndex = 0;
    holder->visible = 0;
    holder->instance = NULL;
}

FieldChunkPropHolder *FieldPropSystem_LinkPropToChunk(FieldPropSystem *system, FieldChunk *chunk,
                                                      FieldPropInstance *instance, u32 propIndex) {
    FieldChunkPropHolder *holder;
    u32 i;

    for (i = 0; i < 0x120; i++) {
        holder = &system->chunkPropHolders[i];
        if (holder->chunk != NULL) {
            continue;
        }
        FieldPropSystem_InstantiateProp(chunk, instance, propIndex);
        holder->chunk = chunk;
        holder->savedResIndex = -1;
        holder->propIndex = propIndex;
        holder->visible = TRUE;
        holder->instance = FieldChunk_GetPropInstance(chunk, propIndex);
        return holder;
    }
    return NULL;
}

void FieldPropSystem_ReleaseChunkPropHolders(FieldPropSystem *system, FieldChunk *chunk) {
    FieldChunkPropHolder *holders;
    s32 i;

    i = 0;
    holders = system->chunkPropHolders;
    for (; i < 0x120; i++) {
        if (holders[i].chunk == chunk) {
            FieldPropSystem_ReleaseChunkPropHolder(system, &holders[i]);
        }
    }
}

void FieldPropSystem_ReleaseChunkPropHolder(FieldPropSystem *system, FieldChunkPropHolder *holder) {
    FieldChunk_ReleasePropInstance(holder->chunk, holder->propIndex);
    FieldChunkPropHolder_Release(system, holder);
}

u8 FieldChunkPropHolder_GetResIndex(FieldChunkPropHolder *holder) {
    if (holder->instance->resIndex == 0xffffffff) {
        return holder->savedResIndex;
    }
    return holder->instance->resIndex;
}

void FieldChunkPropHolder_SetVisible(FieldChunkPropHolder *holder, BOOL visible) {
    if (visible) {
        holder->instance->resIndex = holder->savedResIndex;
        holder->savedResIndex = 0xffffffff;
        holder->visible = 1;
    } else {
        holder->savedResIndex = holder->instance->resIndex;
        holder->instance->resIndex = 0xffffffff;
        holder->visible = 0;
    }
}

void FieldChunkPropHolder_ChangeResID(FieldPropSystem *system, FieldChunkPropHolder *holder, u32 resId) {
    holder->instance->resIndex = FieldPropSystem_ConvResIDToIndex(system, resId);
}

FieldChunkPropHolder *FieldPropSystem_FindProp(FieldPropSystem *system, u32 propId, const FieldPropAreaBounds *bounds) {
    u32 count;
    FieldChunkPropHolder **holders;
    FieldChunkPropHolder *holder;

    holders = FieldPropSystem_FindPropsInArea(system, bounds, propId, &count);
    holder = holders[0];
    GFL_HeapFree(holders);
    return holder;
}

FieldChunkPropHolder *FieldPropSystem_FindPropAtPos(FieldPropSystem *system, u32 propId, const VecFx32 *position) {
    FieldPropAreaBounds bounds;

    FieldPropSearchArea_Set(&bounds, position);
    return FieldPropSystem_FindProp(system, propId, &bounds);
}

u8 FieldChunkPropHolder_GetPropType(FieldPropSystem *system, FieldChunkPropHolder *holder) {
    u32 index = FieldChunkPropHolder_GetResIndex(holder);
    if (index >= 0x80 || index >= system->resInfoCount) {
        index = 0;
    }
    return FieldPropResInfo_GetTypeConv(FieldPropSystem_GetResInfo(system, index));
}

void FieldChunkPropHolder_CallAnmCmd(FieldPropSystem *system, FieldChunkPropHolder *holder, u32 animation,
                                     u32 command) {
    u32 index = FieldChunkPropHolder_GetResIndex(holder);
    if (index >= 0x80 || index >= system->resInfoCount) {
        index = 0;
    }
    FieldPropResInstance_CallAnmCmd(&system->resInstances[index], animation, command);
}

void FieldChunkPropHolder_GetPosAbs(FieldChunkPropHolder *holder, VecFx32 *position) {
    VecFx32 chunkPos;
    FieldChunk_GetWorldPos(holder->chunk, &chunkPos);
    VEC_Add(&holder->instance->pos.position, &chunkPos, position);
}

FieldPropHandle *FieldPropSystem_CreateHandleAtPos(FieldPropSystem *system, u32 propId, const VecFx32 *position) {
    FieldChunkPropHolder *holder;

    holder = FieldPropSystem_FindPropAtPos(system, propId, position);
    if (holder == NULL) {
        return NULL;
    }
    return FieldPropSystem_CreateHandleFromExisting(system, holder);
}

FieldPropHandle *FieldPropSystem_CreateHandleNew(FieldPropSystem *system, u32 propId, SRTMatrix *transform) {
    FieldPropHandle *handle;
    u32 index;

    handle = GFL_HeapAllocate(system->heapId, sizeof(FieldPropHandle), FALSE, "field_buildmodel.c", 0x812);
    handle->system = system;
    handle->holder = NULL;
    handle->animation = 0xffff;
    handle->transform = *transform;
    index = FieldPropSystem_ConvResIDToIndex(system, propId);
    FieldPropResInstance_Init(system, &handle->instance, &system->resources[index]);
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
    return handle->instance.resource->info->type;
}

void FieldPropHandle_Draw(FieldPropHandle *handle) {
    if (handle != NULL) {
        GFL_G3DSysDrawObjBBoxCull(handle->instance.actor, &handle->transform);
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

void FieldPropSearchArea_Set(FieldPropAreaBounds *bounds, const VecFx32 *position) {
    bounds->minZ = position->z - (3 << 16);
    bounds->maxZ = position->z + (3 << 16);
    bounds->minX = position->x - (2 << 16);
    bounds->maxX = position->x + (2 << 16);
}
