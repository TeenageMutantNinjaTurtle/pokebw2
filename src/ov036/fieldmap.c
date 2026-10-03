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

static const u8 sResolvedControllerTypes[4] = { 0, 1, 2, 0 };

struct ZoneMapTypeData {
    u8 bytes[0x14];
    u16 width;
    u16 height;
    u32 count;
    u32 *chunkIDs;
    u32 unk20;
    u32 unk24;
    u32 texSetId;
    u32 srtAnmId;
    u32 patAnmId;
    u8 tail[8];
};

void Field_RequestClose(Field *field) {
    field->routineState = 2;
    field->routineID = 4;
}

BOOL Field_CheckMapLoadFinished(Field *field) {
    return field->routineState == 1;
}

BOOL Field_ToggleCycling(Field *field) {
    BOOL changed = FALSE;
    u32 exState = FieldPlayer_GetExState(field->player);

    if (exState == 1) {
        FieldPlayer_SetSpecialSeq(field->player, 1);
        changed = TRUE;
    } else if (exState == 0) {
        changed = TRUE;
        GFL_SndSEPlay(SEQ_SE_BICYCLE);
        FieldPlayer_SetSpecialSeq(field->player, 2);
        RecordAddOne(GameData_GetRecords(field->gameData), 3);
    }

    if (changed == TRUE) {
        func_ov036_0219a580(field->player);
    }
    return changed;
}

void *Field_GetMsgBGSys(Field *field) {
    return field->msgBGSys;
}

FieldCamera *Field_GetCameraSystem(Field *field) {
    return field->cameraSystem;
}

NoGridMapper *Field_GetNoGridMapper(Field *field) {
    return field->noGridMapper;
}

void *Field_GetLightSystem(Field *field) {
    return field->lightSystem;
}

FieldFog *Field_GetFog(Field *field) {
    return field->fog;
}

void *Field_GetFogCtrl(Field *field) {
    return field->fogCtrl;
}

void *Field_GetWeatherSystem(Field *field) {
    return field->weatherSystem;
}

u32 Field_GetWeatherForZone(Field *field, u16 zoneId) {
    return GetWeatherAll(field->gameSystem, zoneId);
}

MMSys *Field_GetActorSystem(Field *field) {
    return field->actorSystem;
}

GameSystem *Field_GetGameSystem(Field *field) {
    return field->gameSystem;
}

u16 Field_GetHeapID(Field *field) {
    return field->heapId;
}

void *Field_GetEffectBlAct(Field *field) {
    return field->effectBlAct;
}

void *Field_GetWildEffectBlAct(Field *field) {
    return field->wildEffectBlAct;
}

G3DMapper *Field_GetG3DMapper(Field *field) {
    return field->g3DMapper;
}

u16 Field_GetPlayerStateZoneID(Field *field) {
    return field->playerStateZoneId;
}

void *Field_GetController(Field *field) {
    return field->controller;
}

void Field_SetController(Field *field, void *controller) {
    field->controller = controller;
}

FieldPlayer *Field_GetPlayer(Field *field) {
    return field->player;
}

BOOL Field_HasPlayer(Field *field) {
    return field->player != NULL;
}

FieldSubscreen *Field_GetSubscreen(Field *field) {
    return field->subscreen;
}

void *Field_GetFieldEffects(Field *field) {
    return field->fieldEffects;
}

void *Field_GetG3DObjSys(Field *field) {
    return field->g3DObjSystem;
}

void *func_ov036_0218051c(Field *field) {
    return field->unkA0;
}

EncountSystem *Field_GetEncountSystem(Field *field) {
    return field->encountSystem;
}

u32 Field_GetControllerTypeID(Field *field) {
    return *field->controllerTypeID;
}

u32 Field_GetResolvedControllerTypeID(Field *field) {
    u32 type = sResolvedControllerTypes[*field->controllerTypeID];
    if (type == 2) {
        type = FieldmapCtrlHybrid_GetActiveTypeID(field->controller);
    }
    return type;
}

PlaceName *Field_GetPlaceName(Field *field) {
    return field->placeName;
}

void *Field_GetFesGimmick(Field *field) {
    return field->fesGimmick;
}

FieldAsyncProcManager *Field_GetAsyncProcMgr(Field *field) {
    return field->asyncProcManager;
}

FieldExpObjSystem *Field_GetExpObjSystem(Field *field) {
    return field->expObjSystem;
}

TCBManager *Field_GetTCBMgr(Field *field) {
    return field->tcbManager;
}

FieldTaskManager *Field_GetTaskManager(Field *field) {
    return field->taskManager;
}

void Field_SetPlayerPosPtr(Field *field, VecFx32 *position) {
    field->playerPosPtr = position;
}

void *Field_GetMoneyWin(Field *field) {
    return field->moneyWin;
}

void Field_SetMoneyWin(Field *field, void *moneyWin) {
    field->moneyWin = moneyWin;
}

DayCareSave *Field_GetDayCare(Field *field) {
    return field->dayCare;
}

AreaData *Field_GetAreaData(Field *field) {
    return field->areaData;
}

void FieldRenderPhase2_FieldEffect(Field *field) {
    gfxClearColor(0, 0, 0x7fff, 0, FALSE);
    func_ov036_021bb674();
    Fld3DCi_Draw(field->g3dCi);
}

void FieldRenderPhase2_EncountEffect(Field *field) {
    gfxClearColor(0x4210, 31, 0x7fff, 0, FALSE);
    EncEff_CallRenderFunc(field->encEff);
}

u32 Field_GetRenderMode(Field *field) {
    return field->renderMode;
}

void Field_SetRenderMode(Field *field, u32 mode) {
    field->renderMode = mode;
}

void *Field_Get3DCi(Field *field) {
    return field->g3dCi;
}

EncEff *Field_GetEncEff(Field *field) {
    return field->encEff;
}

void *Field_GetSkillMapEff(Field *field) {
    return field->skillMapEff;
}

void *Field_GetSceneArea(Field *field) {
    return field->sceneArea;
}

void Field_SetFadeFlag(Field *field, BOOL flag) {
    field->fadeFlag = flag;
}

BOOL Field_GetFadeFlag(Field *field) {
    return field->fadeFlag;
}

BOOL Field_IsEventRunning(Field *field) {
    return GSYS_GetEventRunningFlag(field->gameSystem);
}

u16 Field_GetDayPeriod(Field *field) {
    return GetRealTimeDayPeriod(GameData_GetSeason(field->gameData));
}

BOOL Field_GetSeasonBannerOverdrawFlag(Field *field) {
    return field->seasonBannerOverdrawFlag;
}

void Field_SetSeasonBannerOverdrawFlag(Field *field, BOOL flag) {
    field->seasonBannerOverdrawFlag = flag;
}

void Field_SetEffectRunningFlag(Field *field, BOOL flag) {
    field->effectRunningFlag = flag;
}

void *Field_GetNDemoDataHandle(Field *field) {
    return field->nDemoDataHandle;
}

void Field_SetCasteliaRush(Field *field, BOOL flag) {
    field->casteliaRush = flag;
}

BOOL Field_GetCasteliaRush(Field *field) {
    return field->casteliaRush;
}

FieldLensFlare *Field_GetLensFlare(Field *field) {
    return field->lensFlare;
}

void *Field_GetColorPostFX(Field *field) {
    return field->colorPostFX;
}

fx32 func_ov036_02181324(Field *field) {
    return field->actorYOffset;
}

u32 GetZoneFogIndexAll(Field *field, u16 zoneId) {
    if (zoneId == 0x78 && !func_ov011_02154e70(field->gameData, 0)) {
        return 0xfffffff;
    }
    return GetZoneFogIndex(zoneId);
}

u32 GetObjectProjectionMatrixOffset(u16 zoneId) {
    if (ZoneData_GetObjectProjectionMatrixType(zoneId) == 1) {
        return 0x1ee;
    }
    return 0x136;
}

BOOL func_ov036_021813b8(u16 zoneId) {
    if (zoneId == 0x249) {
        return FALSE;
    }
    if (IsZone150Or151(zoneId) == TRUE) {
        return FALSE;
    }
    if (zoneId == 0xf1) {
        return FALSE;
    }
    if (zoneId == 0xf2) {
        return FALSE;
    }
    if (zoneId == 0xf3) {
        return FALSE;
    }
    if (zoneId == 0xf4) {
        return FALSE;
    }
    return TRUE;
}

BOOL IsZoneTwoPassLoad(u16 zoneId) {
    if (zoneId == 0x6c)
        return TRUE;
    if (zoneId == 0x249)
        return TRUE;
    if (zoneId == 0x8f)
        return TRUE;
    return FALSE;
}

BOOL func_ov036_0218141c(u16 zoneId) {
    if (zoneId == 0x1de) {
        goto match;
    }
    if (zoneId != 0x1df) {
        goto noMatch;
    }
match:
    return TRUE;
noMatch:
    return FALSE;
}

u32 GetZoneMapType2(u16 zoneId) {
    return GetZoneMapType(zoneId);
}

void SetupLoadZoneMapTypeData(u16 zoneId, AreaData *area, struct ZoneMapTypeData *out, MapMatrix *matrix) {
    u32 type;
    const u8 *src;

    type = GetZoneMapType2(zoneId);
    src = MAP_CONFIGS + 0x48 * type;
    *out = *(const struct ZoneMapTypeData *)src;
    if (*(const u32 *)(data_ov036_021ca05c + 0x48 * type) != 0) {
        out->width = GetMapMatrixWidth(matrix);
        out->height = GetMapMatrixHeight(matrix);
        out->count = GetMapMatrixChunkIDCount(matrix);
        out->chunkIDs = GetMapMatrixChunkIDs(matrix);
    }
    out->unk20 = 1;
    out->unk24 = 14;
    out->texSetId = AreaData_GetTexSetID(area);
    out->srtAnmId = AreaData_GetSRTAnmID(area);
    out->patAnmId = AreaData_GetPatAnmID(area);
}

void *GetZoneFieldmapCtrlVTable(u16 zoneId) {
    return *(void *const *)(data_ov036_021ca058 + 0x48 * GetZoneMapType2(zoneId));
}

u32 GetFieldmapZoneHeapSize(u16 zoneId) {
    return *(const u32 *)(data_ov036_021ca060 + 0x48 * GetZoneMapType2(zoneId));
}
