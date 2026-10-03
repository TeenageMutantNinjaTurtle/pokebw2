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
