#include "field/field_script_supervisor.h"
#include "field/player_state.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/vm.h"

FieldScriptSupervisor *FieldScriptSupervisor_Create(HeapID heapId) {
    FieldScriptSupervisor *supervisor;

    supervisor = GFL_HeapAllocate(heapId, sizeof(FieldScriptSupervisor), TRUE, data_ov012_0216e190, 0xf1);
    supervisor->heapId = heapId;
    return supervisor;
}

void FieldScriptSupervisor_Free(FieldScriptSupervisor *supervisor) {
    GFL_HeapFree(supervisor);
}

BOOL FieldScriptSupervisor_Update(FieldScriptSupervisor *supervisor) {
    int i;
    VM *vm;

    for (i = 0; i < 3; i++) {
        vm = supervisor->vms[i];
        if (vm != NULL && !VM_Run(vm)) {
            supervisor->vms[i] = NULL;
            supervisor->vmCount--;
            FieldScript_FreeVM(vm);
        }
    }
    return supervisor->vmCount != 0;
}

int FieldScriptSupervisor_AddVM(FieldScriptSupervisor *supervisor, VM *vm) {
    int i;

    for (i = 0; i < 3; i++) {
        if (supervisor->vms[i] == NULL) {
            supervisor->vms[i] = vm;
            supervisor->vmCount++;
            return i;
        }
    }
    return 3;
}

VM *FieldScriptSupervisor_GetVM(FieldScriptSupervisor *supervisor, int index) {
    return supervisor->vms[index];
}

void FieldScriptTerminator_ReplaceEvent(GameEvent *event, void *arg) {
    GameEvent_Replace(event, arg);
}

void FieldScriptSupervisor_SetPostEvent(FieldScriptSupervisor *supervisor, GameEvent *event) {
    supervisor->postFunc = FieldScriptTerminator_ReplaceEvent;
    supervisor->postArg = event;
}

void FieldScriptSupervisor_CallPostFunc(FieldScriptSupervisor *supervisor, GameEvent *event) {
    supervisor->postFunc(event, supervisor->postArg);
}

BOOL FieldScriptSupervisor_HasPostFunc(FieldScriptSupervisor *supervisor) {
    return supervisor->postFunc != NULL;
}

u16 FieldScript_GetZoneIDFromGSys(GameSystem *gsys) {
    return PlayerState_GetZoneID(GSYS_GetPlayerState(gsys));
}