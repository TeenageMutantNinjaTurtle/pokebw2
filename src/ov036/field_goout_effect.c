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
    *(u16 *)&scene.resourceCount = resourceCount;
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
