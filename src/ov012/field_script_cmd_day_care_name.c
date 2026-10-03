#include "field/day_care.h"
#include "field/field_script.h"
#include "system/game_system.h"

BOOL s023E_DayCareGetSexForNamePrint(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    DayCareSave *dayCare = Field_GetDayCare(GSYS_GetField(gsys));
    u16 *result = ScriptReadVar(vm, env);
    u16 showSex = ScriptReadAny(vm, env);
    u16 slot = ScriptReadAny(vm, env);
    PartyPkm *pkm = DayCare_GetPkm(dayCare, slot);
    if (showSex == 0) {
        *result = getNameGenderStatus(pkm);
    } else {
        *result = 0;
    }
    return FALSE;
}
