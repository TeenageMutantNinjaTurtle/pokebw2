#include "field/day_care.h"
#include "field/field_script.h"
#include "save/box.h"
#include "system/game_data.h"
#include "system/game_system.h"

BOOL s00F7_DayCareCallPokeSelect(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    u16 *result = ScriptReadVar(vm, env);
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    Field *field = GSYS_GetField(gsys);
    GameData_GetParty(gameData);
    getDaycareBlockAddress(GameData_GetSaveControl(gameData));
    ScriptWork_CallEvent(work, EventDayCarePokeSelect_Create(gsys, field, result));
    return TRUE;
}

BOOL s00F0_DayCareDeposit(VM *vm, FieldScriptEnv *env) {
    u16 slot = ScriptReadAny(vm, env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_AddPkm(dayCare, party, slot);
    return FALSE;
}

BOOL s00F1_DayCareWithdraw(VM *vm, FieldScriptEnv *env) {
    u16 slot = ScriptReadAny(vm, env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_RemovePkm(dayCare, slot, party);
    return FALSE;
}
