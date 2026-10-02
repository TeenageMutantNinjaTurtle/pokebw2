#include "field/field_script.h"
#include "system/vm.h"

BOOL s0014_VMRegSet8(VM *vm, FieldScriptEnv *env) {
    u8 index = VM_Read8(vm);
    u8 value = VM_Read8(vm);

    vm->work[index] = value;
    return FALSE;
}

BOOL s0015_VMRegSet32(VM *vm, FieldScriptEnv *env) {
    u8 index = VM_Read8(vm);
    u32 value = VM_Read32(vm);

    vm->work[index] = value;
    return FALSE;
}

BOOL s0016_VMRegMov(VM *vm, FieldScriptEnv *env) {
    u8 dst = VM_Read8(vm);
    u8 src = VM_Read8(vm);

    vm->work[dst] = vm->work[src];
    return FALSE;
}
