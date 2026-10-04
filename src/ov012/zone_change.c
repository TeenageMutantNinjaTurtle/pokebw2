#include "types.h"
#include "field/encounter.h"
#include "field/event_data.h"
#include "field/field_actor.h"
#include "field/field_status.h"
#include "field/zone.h"
#include "field/zone_change.h"
#include "save/event_work.h"
#include "save/save_control.h"
#include "system/game_data.h"

void func_ov012_0215ee10(GameData *gameData, Field *field) {
    SaveControl_GetEncountSave(GameData_GetSaveControl(gameData));
    func_ov012_021591f4(gameData);
    EventWork_FlagReset(GameData_GetEventWork(gameData), 0x964);
    func_ov012_0215917c(gameData, field);
}

void func_ov012_0215ee40(GameData *gameData, u16 zoneId) {
    FieldStatus *status = GameData_GetFieldStatus(gameData);
    EventWork *eventWork;

    if (!(GetZoneFlashFlags(zoneId) & 3)) {
        FieldStatus_SetFlashUsed(status, FALSE);
    }
    eventWork = GameData_GetEventWork(gameData);
    EventWork_FlagReset(eventWork, 0x964);
    TryClearRepeatableHiddenItemFlags(eventWork);
    if (IsZoneAbyssalRuinsInside(zoneId) == FALSE) {
        PlayerSave_SetAbyssalRuinsStepCounter(SaveControl_GetPlayerSave(GameData_GetSaveControl(gameData)), 0);
    }
}

void func_ov012_0215ee94(GameData *gameData, u16 zoneId) {
    func_ov012_021591b4(gameData);
    func_ov012_0215ef2c(GameData_GetMMSys(gameData));
    PlayerSave_EndStepCounter(SaveControl_GetPlayerSave(GameData_GetSaveControl(gameData)));
}

void func_ov012_0215eeb8(GameData *gameData, u16 zoneId) {
    func_ov012_021591b4(gameData);
    func_ov012_0215ef2c(GameData_GetMMSys(gameData));
    PlayerSave_EndStepCounter(SaveControl_GetPlayerSave(GameData_GetSaveControl(gameData)));
}

void func_ov012_0215eedc(GameData *gameData, u16 zoneId) {
    func_ov012_021591b4(gameData);
    func_ov012_0215ef2c(GameData_GetMMSys(gameData));
    PlayerSave_EndStepCounter(SaveControl_GetPlayerSave(GameData_GetSaveControl(gameData)));
}

void func_ov012_0215ef00(GameData *gameData, u16 zoneId) {
    func_ov012_021591b4(gameData);
    func_ov012_0215ef2c(GameData_GetMMSys(gameData));
    PlayerSave_EndStepCounter(SaveControl_GetPlayerSave(GameData_GetSaveControl(gameData)));
}

void func_ov012_0215ef24(GameData *gameData, u16 zoneId) {
}

void func_ov012_0215ef28(GameData *gameData, u16 zoneId) {
}

void func_ov012_0215ef2c(MMSys *system) {
    func_ov012_02168258(system, 0x1e5, 0);
    func_ov012_02168258(system, 0x1e5, 1);
    func_ov012_02168258(system, 0x1e5, 2);
    func_ov012_02168258(system, 0x1e5, 3);
}
