#include "field/day_care.h"
#include "field/field_script.h"
#include "system/game_data.h"
#include "system/game_system.h"

BOOL s00EB_DayCareCheckSpawnFlag(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    *result = DayCare_CheckSpawnFlag(dayCare);
    return FALSE;
}

BOOL s00EC_DayCareBreed(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_Breed(dayCare, party);
    return FALSE;
}

BOOL s00ED_DayCareResetSeed(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    DayCare_CheckResetSeed(dayCare);
    return FALSE;
}
