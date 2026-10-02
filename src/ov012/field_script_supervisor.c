#include "field/field_script_supervisor.h"
#include "system/vm.h"

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
