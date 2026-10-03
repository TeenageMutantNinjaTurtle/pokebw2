#ifndef POKEBW2_FIELD_FIELD_PROP_H
#define POKEBW2_FIELD_FIELD_PROP_H

#include "types.h"
#include "nitro/fx.h"
#include "struct_decls.h"

struct FieldPropTransform {
    VecFx32 position;
    VecFx32 scale;
    MtxFx33 rotation;
};

struct FieldPropAreaBounds {
    fx32 minZ;
    fx32 maxZ;
    fx32 minX;
    fx32 maxX;
};

// Partial resource layouts inferred from the Swan-named overlay 36 helpers.
struct FieldPropResAnmHeader {
    u8 unk0[2];
    u8 ambientAnimationCount;
    u8 unk3;
    u32 animationIds[4];
};

struct FieldPropResBundle {
    u8 unk0[2];
    u8 countFlags;
    u8 unk3;
    u32 offsets[1];
};

struct FieldPropResInfo {
    u16 resId;
    u16 type;
    u8 unk4[0xc];
    FieldPropResAnmHeader animationHeader;
};

struct FieldChunkPropHolder {
    void *chunk;
    u32 savedResIndex;
    u16 propIndex;
    u16 visible;
    u32 *instance;
};

// Layout inferred from the Swan-named FieldPropRTCState helpers in overlay 36.
struct FieldPropRTCState {
    u32 dayPeriod;
    u32 previousDayPeriod;
    BOOL dayPartChanged;
    u8 playAnmIndex;
    u8 season;
    u8 padding[2];
};

struct FieldPropSystem {
    u16 heapId;
    u8 unk2[6];
    FieldPropRTCState rtcState;
    FieldPropResBundle *resBundle;
    u8 resIdToIndex[0x200];
    u32 resInfoCount;
    u8 unk220[0x1c];
    void *resInfoArray;
    void *textureResource;
    u32 resInstanceCount;
    void *resInstances;
    FieldPropHandle *handles[7];
    FieldChunkPropHolder chunkPropHolders[0x120];
};

struct FieldPropResInstance {
    void *actor;
    FieldPropResInfo **resInfoRef;
    u32 animationState[4];
};

struct FieldPropHandle {
    FieldPropSystem *system;
    u32 animation;
    FieldChunkPropHolder *holder;
    struct {
        void *drawObject;
        FieldPropResInfo **resInfoRef;
        u8 unk8[0x10];
    } instance;
    FieldPropTransform transform;
};

extern const u8 FIELD_PROP_ANM_IDX_FOR_DAY_PART[];
extern const u16 DOOR_SOUND_ID_LUT[][5];
extern const u8 data_ov036_021ca8e6[];
extern const char data_ov036_021d4b2c[];

u32 FieldPropResAnmHeader_GetAnmCount(const FieldPropResAnmHeader *header);
FieldPropResAnmHeader *FieldPropResInfo_GetAnmHeader(FieldPropResInfo *resInfo);
u8 FieldPropResInfo_GetTypeConv(const FieldPropResInfo *resInfo);
u32 FieldPropSystem_ConvResIDToIndex(const FieldPropSystem *system, u32 resId);
void *FieldPropResBundle_GetResInfo(FieldPropResBundle *bundle, u32 index);
void *FieldPropResBundle_GetModelData(FieldPropResBundle *bundle, u32 index);
void *FieldPropResAnmHeader_GetAnmData(FieldPropResAnmHeader *header, u32 index);
void *FieldPropSystem_FindResInfo(FieldPropSystem *system, u32 resId);
void *FieldPropSystem_GetResInfo(FieldPropSystem *system, u32 index);
void *FieldPropSystem_GetResBank(FieldPropSystem *system);
void FieldPropSystem_LoadResBundle(FieldPropSystem *system, u32 arcId, u32 fileId);
void FieldPropSystem_FreeResBundle(FieldPropSystem *system);
void FieldPropSystem_BuildResIDLUT(FieldPropSystem *system, u32 defaultResId);
void FieldPropSystem_FreeTextures(FieldPropSystem *system);
void FieldChunk_ReleasePropInstance(void *chunk, u16 propIndex);
void FieldChunk_GetWorldPos(void *chunk, VecFx32 *position);
void FieldPropResInstance_CallAnmCmd(void *instance, u32 animation, u32 command);
BOOL FieldPropResInstance_IsAnmIdle(void *instance, u32 animation);
void FieldPropResInstance_Free(void *instance);
void FieldPropResInstance_Init(FieldPropSystem *system, void *instance, void *resInfo);
void FieldPropSystem_DeleteHandle(FieldPropSystem *system, FieldPropHandle *handle);
void FieldPropSystem_RegistHandle(FieldPropSystem *system, FieldPropHandle *handle);
u16 FieldPropSystem_GetHandleID(FieldPropSystem *system, FieldPropHandle *handle);
void FieldPropSystem_UpdateResInstance(FieldPropSystem *system, void *instance);
void FieldPropSystem_Update(FieldPropSystem *system);
void FieldPropSystem_DrawAllHandles(FieldPropSystem *system);
void FieldPropSystem_UnlinkChunk(FieldPropSystem *system, void *chunk);
void FieldPropSystem_FreeResInstances(FieldPropSystem *system, void *resourceState);
void FieldPropSystem_FreeResources(FieldPropSystem *system);
void FieldPropSystem_Free(FieldPropSystem *system);
void FieldChunkPropHolder_Release(FieldPropSystem *system, FieldChunkPropHolder *holder);
void FieldPropSystem_ReleaseChunkPropHolders(FieldPropSystem *system, void *chunk);
void FieldPropSystem_ReleaseChunkPropHolder(FieldPropSystem *system, FieldChunkPropHolder *holder);
u8 FieldChunkPropHolder_GetResIndex(FieldChunkPropHolder *holder);
u8 FieldChunkPropHolder_GetPropType(FieldPropSystem *system, FieldChunkPropHolder *holder);
void FieldChunkPropHolder_SetVisible(FieldChunkPropHolder *holder, BOOL visible);
void FieldChunkPropHolder_ChangeResID(FieldPropSystem *system, FieldChunkPropHolder *holder, u32 resId);
void FieldPropRTCState_Init(FieldPropRTCState *state, u8 season);
void FieldPropAnmController_Static_Update(void *controller);
void FieldPropAnmController_Static_Init(FieldPropSystem *system, FieldPropResInstance *instance);
void FieldPropAnmController_Ambient_Init(FieldPropSystem *system, FieldPropResInstance *instance);
void FieldPropAnmController_RTC_Init(FieldPropSystem *system, FieldPropResInstance *instance);
void FieldPropAnmController_Static_ExecCommand(void *controller, u32 command);
void FieldPropAnmController_Ambient_Update(void *controller, void *instance);
void FieldPropAnmController_RTC_Update(FieldPropSystem *system, FieldPropResInstance *instance);
void FieldPropResInstance_AnmStopAll(FieldPropResInstance *instance);
void FieldPropRTCState_Update(FieldPropRTCState *state);
BOOL FieldPropRTCState_HasDayPartChanged(FieldPropRTCState *state);
u8 FieldPropRTCState_GetPlayAnmIndex(FieldPropRTCState *state);

FieldPropSystem *FieldG3DMapper_GetBMSystem(G3DMapper *mapper);
void FieldPropHandle_CallAnmCmd(FieldPropHandle *handle, u32 animation, u32 command);
void FieldPropHandle_CallAnmCmdSilent(FieldPropHandle *handle, u32 command);
BOOL FieldPropHandle_IsAnmIdle(FieldPropHandle *handle, u32 animation);
BOOL FieldPropHandle_IsCurrentAnmIdle(FieldPropHandle *handle);
BOOL FieldPropHandle_IsAnmFinished(FieldPropHandle *handle);
u16 FieldPropHandle_GetPropType(FieldPropHandle *handle);
void FieldPropHandle_Draw(FieldPropHandle *handle);
BOOL FieldPropHandle_GetAnimSoundIDCore(FieldPropHandle *handle, u32 animation, u16 *soundId);
BOOL FieldPropHandle_GetAnimSoundID(FieldPropHandle *handle, u16 *soundId);
void FieldPropHandle_Free(FieldPropHandle *handle);
void FieldChunkPropHolder_CallAnmCmd(FieldPropSystem *system, FieldChunkPropHolder *prop, u32 animation, u32 command);
FieldPropHandle *FieldPropSystem_CreateHandleNew(FieldPropSystem *system, u32 propId, FieldPropTransform *transform);
FieldPropHandle *FieldPropSystem_CreateHandleFromExisting(FieldPropSystem *system, FieldChunkPropHolder *prop);
FieldPropHandle *FieldPropSystem_CreateHandleAtPos(FieldPropSystem *system, u32 propId, const VecFx32 *position);
FieldChunkPropHolder *FieldPropSystem_FindProp(FieldPropSystem *system, u32 propId, const FieldPropAreaBounds *bounds);
FieldChunkPropHolder *FieldPropSystem_FindPropAtPos(FieldPropSystem *system, u32 propId, const VecFx32 *position);
FieldChunkPropHolder **FieldPropSystem_FindPropsInArea(FieldPropSystem *system, const FieldPropAreaBounds *bounds,
                                                       u32 filter, u32 *count);
void FieldPropSearchArea_Set(FieldPropAreaBounds *bounds, const VecFx32 *position);
void FieldChunkPropHolder_GetPosAbs(FieldChunkPropHolder *prop, VecFx32 *position);

#endif // POKEBW2_FIELD_FIELD_PROP_H
