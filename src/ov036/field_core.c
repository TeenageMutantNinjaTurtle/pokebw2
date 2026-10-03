#include "constants/sound.h"
#include "field/day_care.h"
#include "field/festival.h"
#include "field/field_async_proc.h"
#include "field/field_controller.h"
#include "field/field_effects.h"
#include "field/field_environment.h"
#include "field/field_internal.h"
#include "field/field_lifecycle.h"
#include "field/field_map.h"
#include "field/field_player.h"
#include "field/field_visuals.h"
#include "gfl/sound.h"
#include "save/records.h"
#include "system/game_data.h"

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

static const u8 sResolvedControllerTypes[4] = { 0, 1, 2, 0 };

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
