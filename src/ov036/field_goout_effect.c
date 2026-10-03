#include "types.h"
#include "field/field.h"
#include "field/field_exp_obj.h"
#include "field/field_lens_flare.h"
#include "field/field_map.h"
#include "field/zone.h"
#include "gfl/g3d.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "system/game_data.h"

void FieldLensFlare_Free(FieldLensFlare *lensFlare) {
    if (lensFlare->effectId != 8) {
        FieldExpObj_FreeScene(lensFlare->expObjSys, 3);
    }
    FieldLensFlareData_Free(lensFlare->ownedData);
    GFL_HeapFree(lensFlare);
}

void FieldLensFlare_RequestStart(FieldLensFlare *lensFlare) {
    if (lensFlare->available != FALSE && lensFlare->effectId != 8) {
        lensFlare->requested = TRUE;
        lensFlare->active = FALSE;
        lensFlare->state = 0;
    }
}

void FieldLensFlare_GreenlightStart(FieldLensFlare *lensFlare) {
    if (lensFlare->available != FALSE) {
        lensFlare->active = TRUE;
    }
}

void FieldLensFlare_Cancel(FieldLensFlare *lensFlare) {
    if (lensFlare->requested != FALSE) {
        FieldExpObj_SetActorHidden(lensFlare->expObjSys, 3, 0, TRUE);
        lensFlare->requested = FALSE;
        lensFlare->active = FALSE;
        lensFlare->state = 0;
    }
}

void FieldLensFlare_DecideForZoneTransit(FieldLensFlare *lensFlare, u16 zoneId, u16 prevZoneId, u32 fog) {
    BOOL useEntry;
    BOOL applicable;
    u32 weather;
    u32 index;

    useEntry = TRUE;
    FieldLensFlareData_BytesToEntryCount(lensFlare->ownedData);
    weather = GetWeatherAll(lensFlare->gameSystem, zoneId);
    if (weather != 0 && weather != 0xffff) {
        useEntry = FALSE;
    }
    if (fog != 0x0fffffff) {
        useEntry = FALSE;
    }
    applicable = FALSE;
    if (FieldLensFlare_IsApplicable(lensFlare->gameData, zoneId)) {
        applicable = TRUE;
    }
    if (!applicable) {
        useEntry = FALSE;
    }
    index = FieldLensFlareData_GetIdxForZoneTransit(lensFlare->ownedData, zoneId, prevZoneId);
    if (useEntry == FALSE) {
        index = FieldLensFlareData_BytesToEntryCount(lensFlare->ownedData);
    }
    GameData_SetLensFlareEntryIdx(lensFlare->gameData, index);
}

void FieldLensFlare_CalcPos(FieldLensFlare *lensFlare, G3DCamera *camera) {
    VecFx32 position;
    VecFx32 up;
    VecFx32 target;
    VecFx32 offset;
    SRTMatrix *matrix;

    GFL_G3DCameraGetLookatPos(camera, &position);
    GFL_G3DCameraGetLookatUpVector(camera, &up);
    GFL_G3DCameraGetLookatTarget(camera, &target);
    VEC_Subtract(&target, &position, &offset);
    vecfx_normalize(&offset, &offset);
    vecfx_muladd(0x3c000, &offset, &position, &offset);
    matrix = FieldExpObj_GetActorMatrixPtr(lensFlare->expObjSys, 3, 0);
    matrix->translation = offset;
}

void FieldLensFlare_Load(FieldExpObjSystem *expObjSys, FieldLensFlareData *data, u16 effectId) {
    G3DSceneSetup scene = { 0 };
    G3DSceneResourceSetup resources[5] = { 0 };
    G3DSceneActorSetup actor = { 0 };
    G3DSceneAnimationSetup animations[4] = { 0 };
    u32 resourceIndices[5] = { 0 };
    u32 resourceCount;
    s32 index;
    u32 animationIndex;
    u16 resourceId;

    resourceCount = 0;
    for (index = 0; index < 5; index++) {
        resourceId = FieldLensFlareData_GetResDatID(data, effectId, index);
        if (resourceId != 0xffff) {
            resources[resourceCount].arcId = 0xe8;
            resources[resourceCount].fileId = resourceId;
            resources[resourceCount].unk8 = 0;
            resourceIndices[resourceCount] = index;
            resourceCount++;
        }
    }
    for (animationIndex = 0; animationIndex < resourceCount - 1; animationIndex++) {
        animations[animationIndex].resource = resourceIndices[animationIndex + 1];
        animations[animationIndex].index = 0;
    }
    actor.modelResource = 0;
    actor.unk2 = 0;
    actor.unk4 = 0;
    actor.animations = animations;
    actor.animationCount = resourceCount - 1;
    scene.resources = resources;
    scene.resourceCount = resourceCount;
    scene.actors = &actor;
    scene.actorCount = 1;
    FieldExpObj_AddScene(expObjSys, &scene, 3);
    FieldExpObj_SetActorHidden(expObjSys, 3, 0, TRUE);
}

BOOL FieldLensFlare_IsApplicable(GameData *gameData, u16 zoneId) {
    return GetZoneFlagsEnableFlyFrom(zoneId);
}

u8 FieldLensFlare_GetSubIndexForDayPeriod(u32 period) {
    switch (period) {
    case 0:
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
    case 4:
        return 2;
    default:
        return 0;
    }
}
