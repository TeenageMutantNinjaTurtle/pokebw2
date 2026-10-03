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
    u32 unk0;
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

struct FieldPropSystem {
    u16 heapId;
    u8 unk2[0x16];
    FieldPropResBundle *resBundle;
    u8 resIdToIndex[0x200];
    u32 resInfoCount;
    u8 unk220[0x20];
    void *textureResource;
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

extern const u8 FIELD_PROP_ANM_IDX_FOR_DAY_PART[];

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
void FieldPropRTCState_Init(FieldPropRTCState *state, u8 season);
void FieldPropRTCState_Update(FieldPropRTCState *state);
BOOL FieldPropRTCState_HasDayPartChanged(FieldPropRTCState *state);
u8 FieldPropRTCState_GetPlayAnmIndex(FieldPropRTCState *state);

FieldPropSystem *FieldG3DMapper_GetBMSystem(G3DMapper *mapper);
void FieldPropHandle_CallAnmCmd(FieldPropHandle *handle, u32 animation, u32 command);
BOOL FieldPropHandle_IsAnmIdle(FieldPropHandle *handle, u32 animation);
BOOL FieldPropHandle_IsAnmFinished(FieldPropHandle *handle);
void FieldPropHandle_Free(FieldPropHandle *handle);
void FieldChunkPropHolder_CallAnmCmd(FieldPropSystem *system, FieldChunkPropHolder *prop, u32 animation, u32 command);
FieldPropHandle *FieldPropSystem_CreateHandleNew(FieldPropSystem *system, u32 propId, FieldPropTransform *transform);
FieldPropHandle *FieldPropSystem_CreateHandleFromExisting(FieldPropSystem *system, FieldChunkPropHolder *prop);
FieldChunkPropHolder *FieldPropSystem_FindProp(FieldPropSystem *system, u32 propId, const FieldPropAreaBounds *bounds);
FieldChunkPropHolder **FieldPropSystem_FindPropsInArea(FieldPropSystem *system, const FieldPropAreaBounds *bounds,
                                                       u32 filter, u32 *count);
void FieldChunkPropHolder_GetPosAbs(FieldChunkPropHolder *prop, VecFx32 *position);

#endif // POKEBW2_FIELD_FIELD_PROP_H
