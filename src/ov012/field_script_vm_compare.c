#include "field/field_script.h"
#include "system/vm.h"

u8 VMCmp(u32 left, u32 right) {
    if (left < right) {
        return 0;
    }
    if (left == right) {
        return 1;
    }
    return 2;
}

BOOL s0017_VMRegCmp8(VM *vm, FieldScriptEnv *env) {
    u8 left = vm->work[VM_Read8(vm)];
    u8 right = vm->work[VM_Read8(vm)];

    vm->cmpResult = VMCmp(left, right);
    return FALSE;
}

BOOL s0018_VMRegCmpConst8(VM *vm, FieldScriptEnv *env) {
    u8 left = vm->work[VM_Read8(vm)];
    u8 right = VM_Read8(vm);

    vm->cmpResult = VMCmp(left, right);
    return FALSE;
}

BOOL s0019_WorkCmpConst(VM *vm, FieldScriptEnv *env) {
    u16 left = *ScriptReadVar(vm, env);
    u16 right = VM_Read16(vm);

    vm->cmpResult = VMCmp(left, right);
    return FALSE;
}

BOOL s001A_WorkCmpWork(VM *vm, FieldScriptEnv *env) {
    u16 *left = ScriptReadVar(vm, env);
    u16 *right = ScriptReadVar(vm, env);

    vm->cmpResult = VMCmp(*left, *right);
    return FALSE;
}
