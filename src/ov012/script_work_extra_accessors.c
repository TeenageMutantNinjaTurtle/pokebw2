#include "field/field_script.h"

void ScriptWork_SetActorAnmProc(ScriptWork *work, FieldActorAnmProc *proc) {
    work->actorAnmProc = proc;
}

FieldActorAnmProc *ScriptWork_GetActorAnmProc(ScriptWork *work) {
    return work->actorAnmProc;
}

void ScriptWork_SetStadiumTrainers(ScriptWork *work, void *trainers) {
    work->stadiumTrainers = trainers;
}

void *ScriptWork_GetStadiumTrainers(ScriptWork *work) {
    return work->stadiumTrainers;
}

void *ScriptWork_GetTrainerState(ScriptWork *work, int index) {
    return work->trainerState[index];
}
