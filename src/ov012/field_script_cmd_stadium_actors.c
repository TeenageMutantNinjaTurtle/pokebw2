#include "field/field_actor.h"
#include "field/field_script.h"
#include "field/stadium_script.h"
#include "field/trainer_script.h"
#include "system/game_data.h"

BOOL s01E3_StadiumSetupActorSingle(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    u16 a = ScriptReadAny(vm, env);
    u16 b = ScriptReadAny(vm, env);
    u16 c = ScriptReadAny(vm, env);
    EventData *eventData = GameData_GetEventData(FieldScriptEnv_GetGameData(env));
    StadiumTrainerEntry *trainers = ScriptWork_GetStadiumTrainers(work);
    u16 idx = FindStadiumTrainerIndex(trainers, a, c);
    u16 trainerId = trainers[idx].trainerId;
    u16 scriptId = GetNormalSCRIDFromTrainerID(trainerId);
    SetZoneNPCSCRID(eventData, b, scriptId);
    return FALSE;
}

BOOL s01E0_StadiumSetupActorsDouble(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    u16 a = ScriptReadAny(vm, env);
    u16 b = ScriptReadAny(vm, env);
    u16 c = ScriptReadAny(vm, env);
    u16 d = ScriptReadAny(vm, env);
    EventData *eventData = GameData_GetEventData(FieldScriptEnv_GetGameData(env));
    StadiumTrainerEntry *trainers = ScriptWork_GetStadiumTrainers(work);
    u16 idx = FindStadiumTrainerIndex(trainers, a, d);
    SetZoneNPCSCRID(eventData, b, GetNormalSCRIDFromTrainerID(trainers[idx].trainerId));
    SetZoneNPCSCRID(eventData, c, GetPairMember2SCRIDFromTrainerID(trainers[idx].trainerId));
    return FALSE;
}

BOOL s01E0_StadiumSetupActorsTriple(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    u16 npc1 = ScriptReadAny(vm, env);
    u16 npc2 = ScriptReadAny(vm, env);
    u16 npc3 = ScriptReadAny(vm, env);
    u16 idx1 = ScriptReadAny(vm, env);
    u16 idx2 = ScriptReadAny(vm, env);
    u16 idx3 = ScriptReadAny(vm, env);
    EventData *eventData = GameData_GetEventData(FieldScriptEnv_GetGameData(env));
    StadiumTrainerEntry *trainers = ScriptWork_GetStadiumTrainers(work);

    SetZoneNPCMdlID(eventData, npc1, trainers[idx1].objCode);
    SetZoneNPCMdlID(eventData, npc2, trainers[idx2].objCode);
    SetZoneNPCMdlID(eventData, npc3, trainers[idx3].objCode);
    SetZoneNPCSCRID(eventData, npc1, GetNormalSCRIDFromTrainerID(trainers[idx1].trainerId));
    SetZoneNPCSCRID(eventData, npc2, GetNormalSCRIDFromTrainerID(trainers[idx2].trainerId));
    SetZoneNPCSCRID(eventData, npc3, GetNormalSCRIDFromTrainerID(trainers[idx3].trainerId));
    return FALSE;
}
