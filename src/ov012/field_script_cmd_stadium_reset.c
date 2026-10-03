#include "field/field_script.h"
#include "field/stadium_script.h"
#include "field/trainer_script.h"
#include "system/game_data.h"
#include "system/game_system.h"

BOOL s01E5_StadiumResetTrainerFlags(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    EventWork *eventWork;
    s32 i;
    StadiumTrainerEntry *trainers;

    work = FieldScriptEnv_GetScriptWork(env);
    eventWork = GameData_GetEventWork(GSYS_GetGameData(ScriptWork_GetGameSystem(work)));
    trainers = ScriptWork_GetStadiumTrainers(work);
    i = 0;
    while (i != 0x84) {
        clearTrainerBattleFlag(eventWork, trainers[i].trainerId);
        ++i;
    }
    return FALSE;
}
