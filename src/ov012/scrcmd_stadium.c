#include "types.h"
#include "field/event_data.h"
#include "field/field_actor.h"
#include "field/field_script.h"
#include "field/stadium_script.h"
#include "field/trainer_script.h"
#include "gfl/arc.h"
#include "gfl/heap.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/vm.h"

BOOL s01E1_StadiumLoadTrainerTable(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    void *trainers = GFL_ArcSysReadHeapNewLZ(0xce, 0, 0, HEAPID_TAIL(4));
    ScriptWork_SetStadiumTrainers(work, trainers);
    return FALSE;
}

BOOL s01E2_StadiumFreeTrainerTable(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    void *trainers = ScriptWork_GetStadiumTrainers(work);
    if (trainers != NULL) {
        GFL_HeapFree(trainers);
        ScriptWork_SetStadiumTrainers(work, NULL);
    }
    return FALSE;
}

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

u32 FindStadiumTrainerIndex(StadiumTrainerEntry *trainers, u16 a, u16 b) {
    s32 i;
    for (i = 0; i < 0x84; i++) {
        if (trainers[i].unk00 == a && trainers[i].unk02 == b) {
            return i;
        }
    }
    return 0;
}
