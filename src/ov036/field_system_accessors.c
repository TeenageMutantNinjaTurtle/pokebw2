#include "field/day_care.h"
#include "field/festival.h"
#include "field/field_async_proc.h"
#include "field/field_controller.h"
#include "field/field_internal.h"

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
